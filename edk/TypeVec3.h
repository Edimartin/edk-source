#ifndef EDK_TYPEVEC3_H
#define EDK_TYPEVEC3_H

/*
Library C++ typeVec3 - 3D vectors used in Edk Game Engine
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
#warning "Inside TypesVec3"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeVec2.h"

#ifdef printMessages
#warning "    Compiling TypesVec3"
#endif

namespace edk{
//
//vec3i8
class vec3i8{
    //
public:
    edk::int8 x,y,z;

    //CONSTRUTOR
    vec3i8(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3i8(edk::int8 x,edk::int8 y,edk::int8 z){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
        this->z=(edk::int8)z;edkEnd();
    }
    vec3i8(edk::int16 x,edk::int16 y,edk::int16 z){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
        this->z=(edk::int8)z;edkEnd();
    }
    vec3i8(edk::int32 x,edk::int32 y,edk::int32 z){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
        this->z=(edk::int8)z;edkEnd();
    }
    vec3i8(edk::int64 x,edk::int64 y,edk::int64 z){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
        this->z=(edk::int8)z;edkEnd();
    }
    vec3i8(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
        this->z=(edk::int8)z;edkEnd();
    }
    vec3i8(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
        this->z=(edk::int8)z;edkEnd();
    }
    vec3i8(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
        this->z=(edk::int8)z;edkEnd();
    }
    vec3i8(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
        this->z=(edk::int8)z;edkEnd();
    }
    //operators

    //=
    vec3i8 operator=(vec3i8 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(vec2i8 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=(edk::int8)0;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(edk::int8 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        this->z=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(edk::int16 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        this->z=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(edk::int32 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        this->z=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(edk::int64 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        this->z=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(edk::uint8 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        this->z=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(edk::uint16 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        this->z=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(edk::uint32 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        this->z=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i8 operator=(edk::uint64 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        this->z=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3i8 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3i8 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3i8 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3i8 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3i8 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3i8 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3i8 operator+(vec3i8 vec){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3i8 operator+(vec2i8 vec){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec3i8 operator+(edk::int8 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        ret.z=this->z+(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator+(edk::int16 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        ret.z=this->z+(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator+(edk::int32 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        ret.z=this->z+(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator+(edk::int64 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        ret.z=this->z+(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator+(edk::uint8 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        ret.z=this->z+(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator+(edk::uint16 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        ret.z=this->z+(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator+(edk::uint32 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        ret.z=this->z+(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator+(edk::uint64 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        ret.z=this->z+(edk::int8)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3i8 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
        this->z+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
        this->z+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
        this->z+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
        this->z+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
        this->z+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
        this->z+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
        this->z+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
        this->z+=(edk::int8)n;edkEnd();
    }

    //-
    vec3i8 operator-(vec3i8 vec){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3i8 operator-(vec2i8 vec){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec3i8 operator-(edk::int8 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        ret.z=this->z-(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator-(edk::int16 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        ret.z=this->z-(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator-(edk::int32 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        ret.z=this->z-(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator-(edk::int64 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        ret.z=this->z-(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator-(edk::uint8 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        ret.z=this->z-(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator-(edk::uint16 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        ret.z=this->z-(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator-(edk::uint32 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        ret.z=this->z-(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator-(edk::uint64 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        ret.z=this->z-(edk::int8)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3i8 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
        this->z-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
        this->z-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
        this->z-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
        this->z-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
        this->z-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
        this->z-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
        this->z-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
        this->z-=(edk::int8)n;edkEnd();
    }

    //*
    vec3i8 operator*(vec3i8 vec){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3i8 operator*(vec2i8 vec){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec3i8 operator*(edk::int8 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        ret.z=this->z*(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator*(edk::int16 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        ret.z=this->z*(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator*(edk::int32 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        ret.z=this->z*(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator*(edk::int64 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        ret.z=this->z*(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator*(edk::uint8 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        ret.z=this->z*(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator*(edk::uint16 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        ret.z=this->z*(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator*(edk::uint32 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        ret.z=this->z*(edk::int8)n;edkEnd();
        return ret;
    }
    vec3i8 operator*(edk::uint64 n){
        //
        vec3i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        ret.z=this->z*(edk::int8)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3i8 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
        this->z*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
        this->z*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
        this->z*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
        this->z*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
        this->z*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
        this->z*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
        this->z*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
        this->z*=(edk::int8)n;edkEnd();
    }

    //++
    vec3i8 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3i8(this->x,this->y,this->z);edkEnd();
    }
    vec3i8 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3i8(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3i8 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3i8(this->x,this->y,this->z);edkEnd();
    }
    vec3i8 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3i8(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3i8 operator()(edk::int8 x,edk::int8 y,edk::int8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i8((edk::int8)this->x,(edk::int8)this->y,(edk::int8)this->z);edkEnd();
    }
    vec3i8 operator()(edk::int16 x,edk::int16 y,edk::int16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i8((edk::int8)this->x,(edk::int8)this->y,(edk::int8)this->z);edkEnd();
    }
    vec3i8 operator()(edk::int32 x,edk::int32 y,edk::int32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i8((edk::int8)this->x,(edk::int8)this->y,(edk::int8)this->z);edkEnd();
    }
    vec3i8 operator()(edk::int64 x,edk::int64 y,edk::int64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i8((edk::int8)this->x,(edk::int8)this->y,(edk::int8)this->z);edkEnd();
    }
    vec3i8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i8((edk::int8)this->x,(edk::int8)this->y,(edk::int8)this->z);edkEnd();
    }
    vec3i8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i8((edk::int8)this->x,(edk::int8)this->y,(edk::int8)this->z);edkEnd();
    }
    vec3i8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i8((edk::int8)this->x,(edk::int8)this->y,(edk::int8)this->z);edkEnd();
    }
    vec3i8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i8((edk::int8)this->x,(edk::int8)this->y,(edk::int8)this->z);edkEnd();
    }
};

//vec3i16
class vec3i16{
    //
public:
    edk::int16 x,y,z;

    //CONSTRUTOR
    vec3i16(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3i16(edk::int8 x,edk::int8 y,edk::int8 z){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
        this->z=(edk::int16)z;edkEnd();
    }
    vec3i16(edk::int16 x,edk::int16 y,edk::int16 z){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
        this->z=(edk::int16)z;edkEnd();
    }
    vec3i16(edk::int32 x,edk::int32 y,edk::int32 z){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
        this->z=(edk::int16)z;edkEnd();
    }
    vec3i16(edk::int64 x,edk::int64 y,edk::int64 z){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
        this->z=(edk::int16)z;edkEnd();
    }
    vec3i16(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
        this->z=(edk::int16)z;edkEnd();
    }
    vec3i16(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
        this->z=(edk::int16)z;edkEnd();
    }
    vec3i16(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
        this->z=(edk::int16)z;edkEnd();
    }
    vec3i16(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
        this->z=(edk::int16)z;edkEnd();
    }
    //operators

    //=
    vec3i16 operator=(vec3i8 vec){
        //
        this->x=(edk::int16)vec.x;edkEnd();
        this->y=(edk::int16)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(vec3i16 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(vec2i8 vec){
        //
        this->x=(edk::int16)vec.x;edkEnd();
        this->y=(edk::int16)vec.y;edkEnd();
        this->z=(edk::int16)0;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(edk::int8 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        this->z=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(edk::int16 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        this->z=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(edk::int32 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        this->z=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(edk::int64 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        this->z=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(edk::uint8 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        this->z=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(edk::uint16 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        this->z=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(edk::uint32 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        this->z=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i16 operator=(edk::uint64 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        this->z=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3i8 vec){
        //
        return (this->x==(edk::int16)vec.x&&this->y==(edk::int16)vec.y&&this->z==(edk::int16)vec.z);edkEnd();
    }
    bool operator==(vec3i16 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3i8 vec){
        //
        return (this->x!=(edk::int16)vec.x||this->y!=(edk::int16)vec.y||this->z!=(edk::int16)vec.z);edkEnd();
    }
    bool operator!=(vec3i16 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3i8 vec){
        if(this->x>(edk::int16)vec.x){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y>(edk::int16)vec.y){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y==(edk::int16)vec.y && this->z>(edk::int16)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3i16 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3i8 vec){
        if(this->x>(edk::int16)vec.x){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y>(edk::int16)vec.y){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y==(edk::int16)vec.y && this->z>=(edk::int16)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3i16 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3i8 vec){
        if(this->x<(edk::int16)vec.x){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y<(edk::int16)vec.y){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y==(edk::int16)vec.y && this->z<(edk::int16)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3i16 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3i8 vec){
        if(this->x<(edk::int16)vec.x){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y<(edk::int16)vec.y){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y==(edk::int16)vec.y && this->z<=(edk::int16)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3i16 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3i16 operator+(vec3i8 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)vec.x;edkEnd();
        ret.y=this->y+(edk::int16)vec.y;edkEnd();
        ret.z=this->z+(edk::int16)vec.z;edkEnd();
        return ret;
    }
    vec3i16 operator+(vec3i16 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3i16 operator+(vec2i8 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)vec.x;edkEnd();
        ret.y=this->y+(edk::int16)vec.y;edkEnd();
        return ret;
    }
    vec3i16 operator+(edk::int8 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        ret.z=this->z+(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator+(edk::int16 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        ret.z=this->z+(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator+(edk::int32 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        ret.z=this->z+(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator+(edk::int64 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        ret.z=this->z+(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator+(edk::uint8 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        ret.z=this->z+(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator+(edk::uint16 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        ret.z=this->z+(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator+(edk::uint32 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        ret.z=this->z+(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator+(edk::uint64 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        ret.z=this->z+(edk::int16)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3i8 vec){
        //
        this->x+=(edk::int16)vec.x;edkEnd();
        this->y+=(edk::int16)vec.y;edkEnd();
        this->z+=(edk::int16)vec.z;edkEnd();
    }
    void operator+=(vec3i16 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=(edk::int16)vec.x;edkEnd();
        this->y+=(edk::int16)vec.y;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
        this->z+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
        this->z+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
        this->z+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
        this->z+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
        this->z+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
        this->z+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
        this->z+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
        this->z+=(edk::int16)n;edkEnd();
    }

    //-
    vec3i16 operator-(vec3i8 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)vec.x;edkEnd();
        ret.y=this->y-(edk::int16)vec.y;edkEnd();
        ret.z=this->z-(edk::int16)vec.z;edkEnd();
        return ret;
    }
    vec3i16 operator-(vec3i16 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3i16 operator-(vec2i8 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)vec.x;edkEnd();
        ret.y=this->y-(edk::int16)vec.y;edkEnd();
        return ret;
    }
    vec3i16 operator-(edk::int8 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        ret.z=this->z-(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator-(edk::int16 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        ret.z=this->z-(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator-(edk::int32 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        ret.z=this->z-(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator-(edk::int64 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        ret.z=this->z-(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator-(edk::uint8 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        ret.z=this->z-(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator-(edk::uint16 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        ret.z=this->z-(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator-(edk::uint32 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        ret.z=this->z-(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator-(edk::uint64 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        ret.z=this->z-(edk::int16)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3i8 vec){
        //
        this->x-=(edk::int16)vec.x;edkEnd();
        this->y-=(edk::int16)vec.y;edkEnd();
        this->z-=(edk::int16)vec.z;edkEnd();
    }
    void operator-=(vec3i16 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=(edk::int16)vec.x;edkEnd();
        this->y-=(edk::int16)vec.y;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
        this->z-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
        this->z-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
        this->z-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
        this->z-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
        this->z-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
        this->z-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
        this->z-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
        this->z-=(edk::int16)n;edkEnd();
    }

    //*
    vec3i16 operator*(vec3i8 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)vec.x;edkEnd();
        ret.y=this->y*(edk::int16)vec.y;edkEnd();
        ret.z=this->z*(edk::int16)vec.z;edkEnd();
        return ret;
    }
    vec3i16 operator*(vec3i16 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3i16 operator*(vec2i8 vec){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)vec.x;edkEnd();
        ret.y=this->y*(edk::int16)vec.y;edkEnd();
        return ret;
    }
    vec3i16 operator*(edk::int8 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        ret.z=this->z*(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator*(edk::int16 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        ret.z=this->z*(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator*(edk::int32 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        ret.z=this->z*(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator*(edk::int64 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        ret.z=this->z*(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator*(edk::uint8 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        ret.z=this->z*(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator*(edk::uint16 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        ret.z=this->z*(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator*(edk::uint32 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        ret.z=this->z*(edk::int16)n;edkEnd();
        return ret;
    }
    vec3i16 operator*(edk::uint64 n){
        //
        vec3i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        ret.z=this->z*(edk::int16)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3i8 vec){
        //
        this->x*=(edk::int16)vec.x;edkEnd();
        this->y*=(edk::int16)vec.y;edkEnd();
        this->z*=(edk::int16)vec.z;edkEnd();
    }
    void operator*=(vec3i16 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=(edk::int16)vec.x;edkEnd();
        this->y*=(edk::int16)vec.y;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
        this->z*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
        this->z*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
        this->z*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
        this->z*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
        this->z*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
        this->z*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
        this->z*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
        this->z*=(edk::int16)n;edkEnd();
    }

    //++
    vec3i16 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3i16(this->x,this->y,this->z);edkEnd();
    }
    vec3i16 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3i16(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3i16 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3i16(this->x,this->y,this->z);edkEnd();
    }
    vec3i16 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3i16(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3i16 operator()(edk::int8 x,edk::int8 y,edk::int8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i16((edk::int16)this->x,(edk::int16)this->y,(edk::int16)this->z);edkEnd();
    }
    vec3i16 operator()(edk::int16 x,edk::int16 y,edk::int16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i16((edk::int16)this->x,(edk::int16)this->y,(edk::int16)this->z);edkEnd();
    }
    vec3i16 operator()(edk::int32 x,edk::int32 y,edk::int32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i16((edk::int16)this->x,(edk::int16)this->y,(edk::int16)this->z);edkEnd();
    }
    vec3i16 operator()(edk::int64 x,edk::int64 y,edk::int64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i16((edk::int16)this->x,(edk::int16)this->y,(edk::int16)this->z);edkEnd();
    }
    vec3i16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i16((edk::int16)this->x,(edk::int16)this->y,(edk::int16)this->z);edkEnd();
    }
    vec3i16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i16((edk::int16)this->x,(edk::int16)this->y,(edk::int16)this->z);edkEnd();
    }
    vec3i16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i16((edk::int16)this->x,(edk::int16)this->y,(edk::int16)this->z);edkEnd();
    }
    vec3i16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i16((edk::int16)this->x,(edk::int16)this->y,(edk::int16)this->z);edkEnd();
    }
};

//vec3i32
class vec3i32{
    //
public:
    edk::int32 x,y,z;

    //CONSTRUTOR
    vec3i32(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3i32(edk::int8 x,edk::int8 y,edk::int8 z){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
        this->z=(edk::int32)z;edkEnd();
    }
    vec3i32(edk::int16 x,edk::int16 y,edk::int16 z){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
        this->z=(edk::int32)z;edkEnd();
    }
    vec3i32(edk::int32 x,edk::int32 y,edk::int32 z){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
        this->z=(edk::int32)z;edkEnd();
    }
    vec3i32(edk::int64 x,edk::int64 y,edk::int64 z){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
        this->z=(edk::int32)z;edkEnd();
    }
    vec3i32(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
        this->z=(edk::int32)z;edkEnd();
    }
    vec3i32(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
        this->z=(edk::int32)z;edkEnd();
    }
    vec3i32(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
        this->z=(edk::int32)z;edkEnd();
    }
    vec3i32(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
        this->z=(edk::int32)z;edkEnd();
    }
    //operators

    //=
    vec3i32 operator=(vec3i8 vec){
        //
        this->x=(edk::int32)vec.x;edkEnd();
        this->y=(edk::int32)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(vec3i16 vec){
        //
        this->x=(edk::int32)vec.x;edkEnd();
        this->y=(edk::int32)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(vec3i32 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(vec2i8 vec){
        //
        this->x=(edk::int32)vec.x;edkEnd();
        this->y=(edk::int32)vec.y;edkEnd();
        this->z=(edk::int32)0;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(edk::int8 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        this->z=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(edk::int16 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        this->z=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(edk::int32 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        this->z=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(edk::int64 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        this->z=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(edk::uint8 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        this->z=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(edk::uint16 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        this->z=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(edk::uint32 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        this->z=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i32 operator=(edk::uint64 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        this->z=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3i8 vec){
        //
        return (this->x==(edk::int32)vec.x&&this->y==(edk::int32)vec.y&&this->z==(edk::int32)vec.z);edkEnd();
    }
    bool operator==(vec3i16 vec){
        //
        return (this->x==(edk::int32)vec.x&&this->y==(edk::int32)vec.y&&this->z==(edk::int32)vec.z);edkEnd();
    }
    bool operator==(vec3i32 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3i8 vec){
        //
        return (this->x!=(edk::int32)vec.x||this->y!=(edk::int32)vec.y||this->z!=(edk::int32)vec.z);edkEnd();
    }
    bool operator!=(vec3i16 vec){
        //
        return (this->x!=(edk::int32)vec.x||this->y!=(edk::int32)vec.y||this->z!=(edk::int32)vec.z);edkEnd();
    }
    bool operator!=(vec3i32 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3i8 vec){
        if(this->x>(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y>(edk::int32)vec.y){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y==(edk::int32)vec.y && this->z>(edk::int32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3i16 vec){
        if(this->x>(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y>(edk::int32)vec.y){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y==(edk::int32)vec.y && this->z>(edk::int32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3i32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3i8 vec){
        if(this->x>(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y>(edk::int32)vec.y){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y==(edk::int32)vec.y && this->z>=(edk::int32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3i16 vec){
        if(this->x>(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y>(edk::int32)vec.y){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y==(edk::int32)vec.y && this->z>=(edk::int32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3i32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3i8 vec){
        if(this->x<(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y<(edk::int32)vec.y){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y==(edk::int32)vec.y && this->z<(edk::int32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3i16 vec){
        if(this->x<(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y<(edk::int32)vec.y){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y==(edk::int32)vec.y && this->z<(edk::int32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3i32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3i8 vec){
        if(this->x<(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y<(edk::int32)vec.y){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y==(edk::int32)vec.y && this->z<=(edk::int32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3i16 vec){
        if(this->x<(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y<(edk::int32)vec.y){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y==(edk::int32)vec.y && this->z<=(edk::int32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3i32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3i32 operator+(vec3i8 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)vec.x;edkEnd();
        ret.y=this->y+(edk::int32)vec.y;edkEnd();
        ret.z=this->z+(edk::int32)vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator+(vec3i16 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)vec.x;edkEnd();
        ret.y=this->y+(edk::int32)vec.y;edkEnd();
        ret.z=this->z+(edk::int32)vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator+(vec3i32 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator+(vec2i8 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)vec.x;edkEnd();
        ret.y=this->y+(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec3i32 operator+(edk::int8 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        ret.z=this->z+(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator+(edk::int16 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        ret.z=this->z+(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator+(edk::int32 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        ret.z=this->z+(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator+(edk::int64 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        ret.z=this->z+(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator+(edk::uint8 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        ret.z=this->z+(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator+(edk::uint16 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        ret.z=this->z+(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator+(edk::uint32 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        ret.z=this->z+(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator+(edk::uint64 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        ret.z=this->z+(edk::int32)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3i8 vec){
        //
        this->x+=(edk::int32)vec.x;edkEnd();
        this->y+=(edk::int32)vec.y;edkEnd();
        this->z+=(edk::int32)vec.z;edkEnd();
    }
    void operator+=(vec3i16 vec){
        //
        this->x+=(edk::int32)vec.x;edkEnd();
        this->y+=(edk::int32)vec.y;edkEnd();
        this->z+=(edk::int32)vec.z;edkEnd();
    }
    void operator+=(vec3i32 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=(edk::int32)vec.x;edkEnd();
        this->y+=(edk::int32)vec.y;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
        this->z+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
        this->z+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
        this->z+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
        this->z+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
        this->z+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
        this->z+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
        this->z+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
        this->z+=(edk::int32)n;edkEnd();
    }

    //-
    vec3i32 operator-(vec3i8 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)vec.x;edkEnd();
        ret.y=this->y-(edk::int32)vec.y;edkEnd();
        ret.z=this->z-(edk::int32)vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator-(vec3i16 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)vec.x;edkEnd();
        ret.y=this->y-(edk::int32)vec.y;edkEnd();
        ret.z=this->z-(edk::int32)vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator-(vec3i32 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator-(vec2i8 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)vec.x;edkEnd();
        ret.y=this->y-(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec3i32 operator-(edk::int8 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        ret.z=this->z-(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator-(edk::int16 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        ret.z=this->z-(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator-(edk::int32 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        ret.z=this->z-(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator-(edk::int64 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        ret.z=this->z-(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator-(edk::uint8 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        ret.z=this->z-(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator-(edk::uint16 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        ret.z=this->z-(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator-(edk::uint32 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        ret.z=this->z-(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator-(edk::uint64 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        ret.z=this->z-(edk::int32)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3i8 vec){
        //
        this->x-=(edk::int32)vec.x;edkEnd();
        this->y-=(edk::int32)vec.y;edkEnd();
        this->z-=(edk::int32)vec.z;edkEnd();
    }
    void operator-=(vec3i16 vec){
        //
        this->x-=(edk::int32)vec.x;edkEnd();
        this->y-=(edk::int32)vec.y;edkEnd();
        this->z-=(edk::int32)vec.z;edkEnd();
    }
    void operator-=(vec3i32 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=(edk::int32)vec.x;edkEnd();
        this->y-=(edk::int32)vec.y;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
        this->z-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
        this->z-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
        this->z-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
        this->z-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
        this->z-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
        this->z-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
        this->z-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
        this->z-=(edk::int32)n;edkEnd();
    }

    //*
    vec3i32 operator*(vec3i8 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)vec.x;edkEnd();
        ret.y=this->y*(edk::int32)vec.y;edkEnd();
        ret.z=this->z*(edk::int32)vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator*(vec3i16 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)vec.x;edkEnd();
        ret.y=this->y*(edk::int32)vec.y;edkEnd();
        ret.z=this->z*(edk::int32)vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator*(vec3i32 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3i32 operator*(vec2i8 vec){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)vec.x;edkEnd();
        ret.y=this->y*(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec3i32 operator*(edk::int8 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        ret.z=this->z*(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator*(edk::int16 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        ret.z=this->z*(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator*(edk::int32 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        ret.z=this->z*(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator*(edk::int64 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        ret.z=this->z*(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator*(edk::uint8 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        ret.z=this->z*(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator*(edk::uint16 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        ret.z=this->z*(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator*(edk::uint32 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        ret.z=this->z*(edk::int32)n;edkEnd();
        return ret;
    }
    vec3i32 operator*(edk::uint64 n){
        //
        vec3i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        ret.z=this->z*(edk::int32)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3i8 vec){
        //
        this->x*=(edk::int32)vec.x;edkEnd();
        this->y*=(edk::int32)vec.y;edkEnd();
        this->z*=(edk::int32)vec.z;edkEnd();
    }
    void operator*=(vec3i16 vec){
        //
        this->x*=(edk::int32)vec.x;edkEnd();
        this->y*=(edk::int32)vec.y;edkEnd();
        this->z*=(edk::int32)vec.z;edkEnd();
    }
    void operator*=(vec3i32 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=(edk::int32)vec.x;edkEnd();
        this->y*=(edk::int32)vec.y;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
        this->z*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
        this->z*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
        this->z*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
        this->z*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
        this->z*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
        this->z*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
        this->z*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
        this->z*=(edk::int32)n;edkEnd();
    }

    //++
    vec3i32 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3i32(this->x,this->y,this->z);edkEnd();
    }
    vec3i32 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3i32(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3i32 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3i32(this->x,this->y,this->z);edkEnd();
    }
    vec3i32 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3i32(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3i32 operator()(edk::int8 x,edk::int8 y,edk::int8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i32((edk::int32)this->x,(edk::int32)this->y,(edk::int32)this->z);edkEnd();
    }
    vec3i32 operator()(edk::int16 x,edk::int16 y,edk::int16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i32((edk::int32)this->x,(edk::int32)this->y,(edk::int32)this->z);edkEnd();
    }
    vec3i32 operator()(edk::int32 x,edk::int32 y,edk::int32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i32((edk::int32)this->x,(edk::int32)this->y,(edk::int32)this->z);edkEnd();
    }
    vec3i32 operator()(edk::int64 x,edk::int64 y,edk::int64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i32((edk::int32)this->x,(edk::int32)this->y,(edk::int32)this->z);edkEnd();
    }
    vec3i32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i32((edk::int32)this->x,(edk::int32)this->y,(edk::int32)this->z);edkEnd();
    }
    vec3i32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i32((edk::int32)this->x,(edk::int32)this->y,(edk::int32)this->z);edkEnd();
    }
    vec3i32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i32((edk::int32)this->x,(edk::int32)this->y,(edk::int32)this->z);edkEnd();
    }
    vec3i32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i32((edk::int32)this->x,(edk::int32)this->y,(edk::int32)this->z);edkEnd();
    }
};

//vec3i64
class vec3i64{
    //
public:
    edk::int64 x,y,z;

    //CONSTRUTOR
    vec3i64(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3i64(edk::int8 x,edk::int8 y,edk::int8 z){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
        this->z=(edk::int64)z;edkEnd();
    }
    vec3i64(edk::int16 x,edk::int16 y,edk::int16 z){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
        this->z=(edk::int64)z;edkEnd();
    }
    vec3i64(edk::int32 x,edk::int32 y,edk::int32 z){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
        this->z=(edk::int64)z;edkEnd();
    }
    vec3i64(edk::int64 x,edk::int64 y,edk::int64 z){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
        this->z=(edk::int64)z;edkEnd();
    }
    vec3i64(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
        this->z=(edk::int64)z;edkEnd();
    }
    vec3i64(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
        this->z=(edk::int64)z;edkEnd();
    }
    vec3i64(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
        this->z=(edk::int64)z;edkEnd();
    }
    vec3i64(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
        this->z=(edk::int64)z;edkEnd();
    }
    //operators

    //=
    vec3i64 operator=(vec3i8 vec){
        //
        this->x=(edk::int64)vec.x;edkEnd();
        this->y=(edk::int64)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(vec3i16 vec){
        //
        this->x=(edk::int64)vec.x;edkEnd();
        this->y=(edk::int64)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(vec3i32 vec){
        //
        this->x=(edk::int64)vec.x;edkEnd();
        this->y=(edk::int64)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(vec3i64 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(vec2i8 vec){
        //
        this->x=(edk::int64)vec.x;edkEnd();
        this->y=(edk::int64)vec.y;edkEnd();
        this->z=(edk::int64)0;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(edk::int8 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        this->z=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(edk::int16 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        this->z=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(edk::int32 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        this->z=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(edk::int64 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        this->z=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(edk::uint8 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        this->z=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(edk::uint16 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        this->z=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(edk::uint32 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        this->z=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3i64 operator=(edk::uint64 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        this->z=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3i8 vec){
        //
        return (this->x==(edk::int64)vec.x&&this->y==(edk::int64)vec.y&&this->z==(edk::int64)vec.z);edkEnd();
    }
    bool operator==(vec3i16 vec){
        //
        return (this->x==(edk::int64)vec.x&&this->y==(edk::int64)vec.y&&this->z==(edk::int64)vec.z);edkEnd();
    }
    bool operator==(vec3i32 vec){
        //
        return (this->x==(edk::int64)vec.x&&this->y==(edk::int64)vec.y&&this->z==(edk::int64)vec.z);edkEnd();
    }
    bool operator==(vec3i64 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3i8 vec){
        //
        return (this->x!=(edk::int64)vec.x||this->y!=(edk::int64)vec.y||this->z!=(edk::int64)vec.z);edkEnd();
    }
    bool operator!=(vec3i16 vec){
        //
        return (this->x!=(edk::int64)vec.x||this->y!=(edk::int64)vec.y||this->z!=(edk::int64)vec.z);edkEnd();
    }
    bool operator!=(vec3i32 vec){
        //
        return (this->x!=(edk::int64)vec.x||this->y!=(edk::int64)vec.y||this->z!=(edk::int64)vec.z);edkEnd();
    }
    bool operator!=(vec3i64 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3i8 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z>(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3i16 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z>(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3i32 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z>(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3i64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3i8 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z>=(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3i16 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z>=(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3i32 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z>=(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3i64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3i8 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z<(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3i16 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z<(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3i32 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z<(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3i64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3i8 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z<=(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3i16 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z<=(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3i32 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y==(edk::int64)vec.y && this->z<=(edk::int64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3i64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3i64 operator+(vec3i8 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)vec.x;edkEnd();
        ret.y=this->y+(edk::int64)vec.y;edkEnd();
        ret.z=this->z+(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator+(vec3i16 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)vec.x;edkEnd();
        ret.y=this->y+(edk::int64)vec.y;edkEnd();
        ret.z=this->z+(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator+(vec3i32 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)vec.x;edkEnd();
        ret.y=this->y+(edk::int64)vec.y;edkEnd();
        ret.z=this->z+(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator+(vec3i64 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator+(vec2i8 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)vec.x;edkEnd();
        ret.y=this->y+(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec3i64 operator+(edk::int8 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        ret.z=this->z+(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator+(edk::int16 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        ret.z=this->z+(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator+(edk::int32 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        ret.z=this->z+(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator+(edk::int64 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        ret.z=this->z+(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator+(edk::uint8 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        ret.z=this->z+(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator+(edk::uint16 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        ret.z=this->z+(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator+(edk::uint32 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        ret.z=this->z+(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator+(edk::uint64 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        ret.z=this->z+(edk::int64)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3i8 vec){
        //
        this->x+=(edk::int64)vec.x;edkEnd();
        this->y+=(edk::int64)vec.y;edkEnd();
        this->z+=(edk::int64)vec.z;edkEnd();
    }
    void operator+=(vec3i16 vec){
        //
        this->x+=(edk::int64)vec.x;edkEnd();
        this->y+=(edk::int64)vec.y;edkEnd();
        this->z+=(edk::int64)vec.z;edkEnd();
    }
    void operator+=(vec3i32 vec){
        //
        this->x+=(edk::int64)vec.x;edkEnd();
        this->y+=(edk::int64)vec.y;edkEnd();
        this->z+=(edk::int64)vec.z;edkEnd();
    }
    void operator+=(vec3i64 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=(edk::int64)vec.x;edkEnd();
        this->y+=(edk::int64)vec.y;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
        this->z+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
        this->z+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
        this->z+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
        this->z+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
        this->z+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
        this->z+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
        this->z+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
        this->z+=(edk::int64)n;edkEnd();
    }

    //-
    vec3i64 operator-(vec3i8 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)vec.x;edkEnd();
        ret.y=this->y-(edk::int64)vec.y;edkEnd();
        ret.z=this->z-(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator-(vec3i16 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)vec.x;edkEnd();
        ret.y=this->y-(edk::int64)vec.y;edkEnd();
        ret.z=this->z-(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator-(vec3i32 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)vec.x;edkEnd();
        ret.y=this->y-(edk::int64)vec.y;edkEnd();
        ret.z=this->z-(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator-(vec3i64 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator-(vec2i8 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)vec.x;edkEnd();
        ret.y=this->y-(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec3i64 operator-(edk::int8 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        ret.z=this->z-(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator-(edk::int16 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        ret.z=this->z-(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator-(edk::int32 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        ret.z=this->z-(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator-(edk::int64 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        ret.z=this->z-(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator-(edk::uint8 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        ret.z=this->z-(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator-(edk::uint16 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        ret.z=this->z-(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator-(edk::uint32 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        ret.z=this->z-(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator-(edk::uint64 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        ret.z=this->z-(edk::int64)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3i8 vec){
        //
        this->x-=(edk::int64)vec.x;edkEnd();
        this->y-=(edk::int64)vec.y;edkEnd();
        this->z-=(edk::int64)vec.z;edkEnd();
    }
    void operator-=(vec3i16 vec){
        //
        this->x-=(edk::int64)vec.x;edkEnd();
        this->y-=(edk::int64)vec.y;edkEnd();
        this->z-=(edk::int64)vec.z;edkEnd();
    }
    void operator-=(vec3i32 vec){
        //
        this->x-=(edk::int64)vec.x;edkEnd();
        this->y-=(edk::int64)vec.y;edkEnd();
        this->z-=(edk::int64)vec.z;edkEnd();
    }
    void operator-=(vec3i64 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=(edk::int64)vec.x;edkEnd();
        this->y-=(edk::int64)vec.y;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
        this->z-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
        this->z-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
        this->z-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
        this->z-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
        this->z-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
        this->z-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
        this->z-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
        this->z-=(edk::int64)n;edkEnd();
    }

    //*
    vec3i64 operator*(vec3i8 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)vec.x;edkEnd();
        ret.y=this->y*(edk::int64)vec.y;edkEnd();
        ret.z=this->z*(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator*(vec3i16 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)vec.x;edkEnd();
        ret.y=this->y*(edk::int64)vec.y;edkEnd();
        ret.z=this->z*(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator*(vec3i32 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)vec.x;edkEnd();
        ret.y=this->y*(edk::int64)vec.y;edkEnd();
        ret.z=this->z*(edk::int64)vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator*(vec3i64 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3i64 operator*(vec2i8 vec){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)vec.x;edkEnd();
        ret.y=this->y*(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec3i64 operator*(edk::int8 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        ret.z=this->z*(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator*(edk::int16 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        ret.z=this->z*(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator*(edk::int32 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        ret.z=this->z*(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator*(edk::int64 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        ret.z=this->z*(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator*(edk::uint8 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        ret.z=this->z*(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator*(edk::uint16 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        ret.z=this->z*(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator*(edk::uint32 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        ret.z=this->z*(edk::int64)n;edkEnd();
        return ret;
    }
    vec3i64 operator*(edk::uint64 n){
        //
        vec3i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        ret.z=this->z*(edk::int64)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3i8 vec){
        //
        this->x*=(edk::int64)vec.x;edkEnd();
        this->y*=(edk::int64)vec.y;edkEnd();
        this->z*=(edk::int64)vec.z;edkEnd();
    }
    void operator*=(vec3i16 vec){
        //
        this->x*=(edk::int64)vec.x;edkEnd();
        this->y*=(edk::int64)vec.y;edkEnd();
        this->z*=(edk::int64)vec.z;edkEnd();
    }
    void operator*=(vec3i32 vec){
        //
        this->x*=(edk::int64)vec.x;edkEnd();
        this->y*=(edk::int64)vec.y;edkEnd();
        this->z*=(edk::int64)vec.z;edkEnd();
    }
    void operator*=(vec3i64 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=(edk::int64)vec.x;edkEnd();
        this->y*=(edk::int64)vec.y;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
        this->z*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
        this->z*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
        this->z*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
        this->z*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
        this->z*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
        this->z*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
        this->z*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
        this->z*=(edk::int64)n;edkEnd();
    }

    //++
    vec3i64 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3i64(this->x,this->y,this->z);edkEnd();
    }
    vec3i64 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3i64(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3i64 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3i64(this->x,this->y,this->z);edkEnd();
    }
    vec3i64 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3i64(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3i64 operator()(edk::int8 x,edk::int8 y,edk::int8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i64((edk::int64)this->x,(edk::int64)this->y,(edk::int64)this->z);edkEnd();
    }
    vec3i64 operator()(edk::int16 x,edk::int16 y,edk::int16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i64((edk::int64)this->x,(edk::int64)this->y,(edk::int64)this->z);edkEnd();
    }
    vec3i64 operator()(edk::int32 x,edk::int32 y,edk::int32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i64((edk::int64)this->x,(edk::int64)this->y,(edk::int64)this->z);edkEnd();
    }
    vec3i64 operator()(edk::int64 x,edk::int64 y,edk::int64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i64((edk::int64)this->x,(edk::int64)this->y,(edk::int64)this->z);edkEnd();
    }
    vec3i64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i64((edk::int64)this->x,(edk::int64)this->y,(edk::int64)this->z);edkEnd();
    }
    vec3i64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i64((edk::int64)this->x,(edk::int64)this->y,(edk::int64)this->z);edkEnd();
    }
    vec3i64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i64((edk::int64)this->x,(edk::int64)this->y,(edk::int64)this->z);edkEnd();
    }
    vec3i64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3i64((edk::int64)this->x,(edk::int64)this->y,(edk::int64)this->z);edkEnd();
    }
};

//vec3ui8
class vec3ui8{
    //
public:
    edk::uint8 x,y,z;

    //CONSTRUTOR
    vec3ui8(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3ui8(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::uint8)x;edkEnd();
        this->y=(edk::uint8)y;edkEnd();
        this->z=(edk::uint8)z;edkEnd();
    }
    vec3ui8(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::uint8)x;edkEnd();
        this->y=(edk::uint8)y;edkEnd();
        this->z=(edk::uint8)z;edkEnd();
    }
    vec3ui8(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::uint8)x;edkEnd();
        this->y=(edk::uint8)y;edkEnd();
        this->z=(edk::uint8)z;edkEnd();
    }
    vec3ui8(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::uint8)x;edkEnd();
        this->y=(edk::uint8)y;edkEnd();
        this->z=(edk::uint8)z;edkEnd();
    }
    //operators

    //=
    vec3ui8 operator=(vec3ui8 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui8 operator=(vec2i8 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=(edk::uint8)0;edkEnd();
        return *this;edkEnd();
    }
    vec3ui8 operator=(edk::uint8 n){
        //
        this->x=(edk::uint8)n;edkEnd();
        this->y=(edk::uint8)n;edkEnd();
        this->z=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui8 operator=(edk::uint16 n){
        //
        this->x=(edk::uint8)n;edkEnd();
        this->y=(edk::uint8)n;edkEnd();
        this->z=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui8 operator=(edk::uint32 n){
        //
        this->x=(edk::uint8)n;edkEnd();
        this->y=(edk::uint8)n;edkEnd();
        this->z=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui8 operator=(edk::uint64 n){
        //
        this->x=(edk::uint8)n;edkEnd();
        this->y=(edk::uint8)n;edkEnd();
        this->z=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3ui8 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3ui8 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3ui8 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3ui8 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3ui8 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3ui8 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3ui8 operator+(vec3ui8 vec){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3ui8 operator+(vec2i8 vec){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec3ui8 operator+(edk::uint8 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x+(edk::uint8)n;edkEnd();
        ret.y=this->y+(edk::uint8)n;edkEnd();
        ret.z=this->z+(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator+(edk::uint16 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x+(edk::uint8)n;edkEnd();
        ret.y=this->y+(edk::uint8)n;edkEnd();
        ret.z=this->z+(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator+(edk::uint32 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x+(edk::uint8)n;edkEnd();
        ret.y=this->y+(edk::uint8)n;edkEnd();
        ret.z=this->z+(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator+(edk::uint64 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x+(edk::uint8)n;edkEnd();
        ret.y=this->y+(edk::uint8)n;edkEnd();
        ret.z=this->z+(edk::uint8)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3ui8 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::uint8)n;edkEnd();
        this->y+=(edk::uint8)n;edkEnd();
        this->z+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::uint8)n;edkEnd();
        this->y+=(edk::uint8)n;edkEnd();
        this->z+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::uint8)n;edkEnd();
        this->y+=(edk::uint8)n;edkEnd();
        this->z+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::uint8)n;edkEnd();
        this->y+=(edk::uint8)n;edkEnd();
        this->z+=(edk::uint8)n;edkEnd();
    }

    //-
    vec3ui8 operator-(vec3ui8 vec){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3ui8 operator-(vec2i8 vec){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec3ui8 operator-(edk::uint8 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x-(edk::uint8)n;edkEnd();
        ret.y=this->y-(edk::uint8)n;edkEnd();
        ret.z=this->z-(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator-(edk::uint16 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x-(edk::uint8)n;edkEnd();
        ret.y=this->y-(edk::uint8)n;edkEnd();
        ret.z=this->z-(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator-(edk::uint32 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x-(edk::uint8)n;edkEnd();
        ret.y=this->y-(edk::uint8)n;edkEnd();
        ret.z=this->z-(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator-(edk::uint64 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x-(edk::uint8)n;edkEnd();
        ret.y=this->y-(edk::uint8)n;edkEnd();
        ret.z=this->z-(edk::uint8)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3ui8 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::uint8)n;edkEnd();
        this->y-=(edk::uint8)n;edkEnd();
        this->z-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::uint8)n;edkEnd();
        this->y-=(edk::uint8)n;edkEnd();
        this->z-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::uint8)n;edkEnd();
        this->y-=(edk::uint8)n;edkEnd();
        this->z-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::uint8)n;edkEnd();
        this->y-=(edk::uint8)n;edkEnd();
        this->z-=(edk::uint8)n;edkEnd();
    }

    //*
    vec3ui8 operator*(vec3ui8 vec){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3ui8 operator*(vec2i8 vec){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec3ui8 operator*(edk::uint8 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x*(edk::uint8)n;edkEnd();
        ret.y=this->y*(edk::uint8)n;edkEnd();
        ret.z=this->z*(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator*(edk::uint16 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x*(edk::uint8)n;edkEnd();
        ret.y=this->y*(edk::uint8)n;edkEnd();
        ret.z=this->z*(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator*(edk::uint32 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x*(edk::uint8)n;edkEnd();
        ret.y=this->y*(edk::uint8)n;edkEnd();
        ret.z=this->z*(edk::uint8)n;edkEnd();
        return ret;
    }
    vec3ui8 operator*(edk::uint64 n){
        //
        vec3ui8 ret;edkEnd();
        ret.x=this->x*(edk::uint8)n;edkEnd();
        ret.y=this->y*(edk::uint8)n;edkEnd();
        ret.z=this->z*(edk::uint8)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3ui8 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::uint8)n;edkEnd();
        this->y*=(edk::uint8)n;edkEnd();
        this->z*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::uint8)n;edkEnd();
        this->y*=(edk::uint8)n;edkEnd();
        this->z*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::uint8)n;edkEnd();
        this->y*=(edk::uint8)n;edkEnd();
        this->z*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::uint8)n;edkEnd();
        this->y*=(edk::uint8)n;edkEnd();
        this->z*=(edk::uint8)n;edkEnd();
    }

    //++
    vec3ui8 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3ui8(this->x,this->y,this->z);edkEnd();
    }
    vec3ui8 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3ui8(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3ui8 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3ui8(this->x,this->y,this->z);edkEnd();
    }
    vec3ui8 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3ui8(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3ui8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui8((edk::uint8)this->x,(edk::uint8)this->y,(edk::uint8)this->z);edkEnd();
    }
    vec3ui8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui8((edk::uint8)this->x,(edk::uint8)this->y,(edk::uint8)this->z);edkEnd();
    }
    vec3ui8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui8((edk::uint8)this->x,(edk::uint8)this->y,(edk::uint8)this->z);edkEnd();
    }
    vec3ui8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui8((edk::uint8)this->x,(edk::uint8)this->y,(edk::uint8)this->z);edkEnd();
    }
};

//vec3ui16
class vec3ui16{
    //
public:
    edk::uint16 x,y,z;

    //CONSTRUTOR
    vec3ui16(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3ui16(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::uint16)x;edkEnd();
        this->y=(edk::uint16)y;edkEnd();
        this->z=(edk::uint16)z;edkEnd();
    }
    vec3ui16(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::uint16)x;edkEnd();
        this->y=(edk::uint16)y;edkEnd();
        this->z=(edk::uint16)z;edkEnd();
    }
    vec3ui16(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::uint16)x;edkEnd();
        this->y=(edk::uint16)y;edkEnd();
        this->z=(edk::uint16)z;edkEnd();
    }
    vec3ui16(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::uint16)x;edkEnd();
        this->y=(edk::uint16)y;edkEnd();
        this->z=(edk::uint16)z;edkEnd();
    }
    //operators

    //=
    vec3ui16 operator=(vec3ui8 vec){
        //
        this->x=(edk::uint16)vec.x;edkEnd();
        this->y=(edk::uint16)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui16 operator=(vec3ui16 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui16 operator=(vec2i8 vec){
        //
        this->x=(edk::uint16)vec.x;edkEnd();
        this->y=(edk::uint16)vec.y;edkEnd();
        this->z=(edk::uint16)0;edkEnd();
        return *this;edkEnd();
    }
    vec3ui16 operator=(edk::uint8 n){
        //
        this->x=(edk::uint16)n;edkEnd();
        this->y=(edk::uint16)n;edkEnd();
        this->z=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui16 operator=(edk::uint16 n){
        //
        this->x=(edk::uint16)n;edkEnd();
        this->y=(edk::uint16)n;edkEnd();
        this->z=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui16 operator=(edk::uint32 n){
        //
        this->x=(edk::uint16)n;edkEnd();
        this->y=(edk::uint16)n;edkEnd();
        this->z=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui16 operator=(edk::uint64 n){
        //
        this->x=(edk::uint16)n;edkEnd();
        this->y=(edk::uint16)n;edkEnd();
        this->z=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3ui8 vec){
        //
        return (this->x==(edk::uint16)vec.x&&this->y==(edk::uint16)vec.y&&this->z==(edk::uint16)vec.z);edkEnd();
    }
    bool operator==(vec3ui16 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3ui8 vec){
        //
        return (this->x!=(edk::uint16)vec.x||this->y!=(edk::uint16)vec.y||this->z!=(edk::uint16)vec.z);edkEnd();
    }
    bool operator!=(vec3ui16 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3ui8 vec){
        if(this->x>(edk::uint16)vec.x){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y>(edk::uint16)vec.y){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y==(edk::uint16)vec.y && this->z>(edk::uint16)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3ui16 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3ui8 vec){
        if(this->x>(edk::uint16)vec.x){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y>(edk::uint16)vec.y){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y==(edk::uint16)vec.y && this->z>=(edk::uint16)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3ui16 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3ui8 vec){
        if(this->x<(edk::uint16)vec.x){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y<(edk::uint16)vec.y){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y==(edk::uint16)vec.y && this->z<(edk::uint16)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3ui16 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3ui8 vec){
        if(this->x<(edk::uint16)vec.x){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y<(edk::uint16)vec.y){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y==(edk::uint16)vec.y && this->z<=(edk::uint16)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3ui16 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3ui16 operator+(vec3ui8 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)vec.x;edkEnd();
        ret.y=this->y+(edk::uint16)vec.y;edkEnd();
        ret.z=this->z+(edk::uint16)vec.z;edkEnd();
        return ret;
    }
    vec3ui16 operator+(vec3ui16 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3ui16 operator+(vec2i8 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)vec.x;edkEnd();
        ret.y=this->y+(edk::uint16)vec.y;edkEnd();
        return ret;
    }
    vec3ui16 operator+(edk::uint8 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)n;edkEnd();
        ret.y=this->y+(edk::uint16)n;edkEnd();
        ret.z=this->z+(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator+(edk::uint16 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)n;edkEnd();
        ret.y=this->y+(edk::uint16)n;edkEnd();
        ret.z=this->z+(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator+(edk::uint32 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)n;edkEnd();
        ret.y=this->y+(edk::uint16)n;edkEnd();
        ret.z=this->z+(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator+(edk::uint64 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)n;edkEnd();
        ret.y=this->y+(edk::uint16)n;edkEnd();
        ret.z=this->z+(edk::uint16)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3ui8 vec){
        //
        this->x+=(edk::uint16)vec.x;edkEnd();
        this->y+=(edk::uint16)vec.y;edkEnd();
        this->z+=(edk::uint16)vec.z;edkEnd();
    }
    void operator+=(vec3ui16 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=(edk::uint16)vec.x;edkEnd();
        this->y+=(edk::uint16)vec.y;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::uint16)n;edkEnd();
        this->y+=(edk::uint16)n;edkEnd();
        this->z+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::uint16)n;edkEnd();
        this->y+=(edk::uint16)n;edkEnd();
        this->z+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::uint16)n;edkEnd();
        this->y+=(edk::uint16)n;edkEnd();
        this->z+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::uint16)n;edkEnd();
        this->y+=(edk::uint16)n;edkEnd();
        this->z+=(edk::uint16)n;edkEnd();
    }

    //-
    vec3ui16 operator-(vec3ui8 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)vec.x;edkEnd();
        ret.y=this->y-(edk::uint16)vec.y;edkEnd();
        ret.z=this->z-(edk::uint16)vec.z;edkEnd();
        return ret;
    }
    vec3ui16 operator-(vec3ui16 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3ui16 operator-(vec2i8 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)vec.x;edkEnd();
        ret.y=this->y-(edk::uint16)vec.y;edkEnd();
        return ret;
    }
    vec3ui16 operator-(edk::uint8 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)n;edkEnd();
        ret.y=this->y-(edk::uint16)n;edkEnd();
        ret.z=this->z-(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator-(edk::uint16 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)n;edkEnd();
        ret.y=this->y-(edk::uint16)n;edkEnd();
        ret.z=this->z-(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator-(edk::uint32 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)n;edkEnd();
        ret.y=this->y-(edk::uint16)n;edkEnd();
        ret.z=this->z-(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator-(edk::uint64 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)n;edkEnd();
        ret.y=this->y-(edk::uint16)n;edkEnd();
        ret.z=this->z-(edk::uint16)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3ui8 vec){
        //
        this->x-=(edk::uint16)vec.x;edkEnd();
        this->y-=(edk::uint16)vec.y;edkEnd();
        this->z-=(edk::uint16)vec.z;edkEnd();
    }
    void operator-=(vec3ui16 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=(edk::uint16)vec.x;edkEnd();
        this->y-=(edk::uint16)vec.y;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::uint16)n;edkEnd();
        this->y-=(edk::uint16)n;edkEnd();
        this->z-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::uint16)n;edkEnd();
        this->y-=(edk::uint16)n;edkEnd();
        this->z-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::uint16)n;edkEnd();
        this->y-=(edk::uint16)n;edkEnd();
        this->z-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::uint16)n;edkEnd();
        this->y-=(edk::uint16)n;edkEnd();
        this->z-=(edk::uint16)n;edkEnd();
    }

    //*
    vec3ui16 operator*(vec3ui8 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)vec.x;edkEnd();
        ret.y=this->y*(edk::uint16)vec.y;edkEnd();
        ret.z=this->z*(edk::uint16)vec.z;edkEnd();
        return ret;
    }
    vec3ui16 operator*(vec3ui16 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3ui16 operator*(vec2i8 vec){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)vec.x;edkEnd();
        ret.y=this->y*(edk::uint16)vec.y;edkEnd();
        return ret;
    }
    vec3ui16 operator*(edk::uint8 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)n;edkEnd();
        ret.y=this->y*(edk::uint16)n;edkEnd();
        ret.z=this->z*(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator*(edk::uint16 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)n;edkEnd();
        ret.y=this->y*(edk::uint16)n;edkEnd();
        ret.z=this->z*(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator*(edk::uint32 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)n;edkEnd();
        ret.y=this->y*(edk::uint16)n;edkEnd();
        ret.z=this->z*(edk::uint16)n;edkEnd();
        return ret;
    }
    vec3ui16 operator*(edk::uint64 n){
        //
        vec3ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)n;edkEnd();
        ret.y=this->y*(edk::uint16)n;edkEnd();
        ret.z=this->z*(edk::uint16)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3ui8 vec){
        //
        this->x*=(edk::uint16)vec.x;edkEnd();
        this->y*=(edk::uint16)vec.y;edkEnd();
        this->z*=(edk::uint16)vec.z;edkEnd();
    }
    void operator*=(vec3ui16 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=(edk::uint16)vec.x;edkEnd();
        this->y*=(edk::uint16)vec.y;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::uint16)n;edkEnd();
        this->y*=(edk::uint16)n;edkEnd();
        this->z*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::uint16)n;edkEnd();
        this->y*=(edk::uint16)n;edkEnd();
        this->z*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::uint16)n;edkEnd();
        this->y*=(edk::uint16)n;edkEnd();
        this->z*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::uint16)n;edkEnd();
        this->y*=(edk::uint16)n;edkEnd();
        this->z*=(edk::uint16)n;edkEnd();
    }

    //++
    vec3ui16 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3ui16(this->x,this->y,this->z);edkEnd();
    }
    vec3ui16 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3ui16(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3ui16 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3ui16(this->x,this->y,this->z);edkEnd();
    }
    vec3ui16 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3ui16(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3ui16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui16((edk::uint16)this->x,(edk::uint16)this->y,(edk::uint16)this->z);edkEnd();
    }
    vec3ui16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui16((edk::uint16)this->x,(edk::uint16)this->y,(edk::uint16)this->z);edkEnd();
    }
    vec3ui16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui16((edk::uint16)this->x,(edk::uint16)this->y,(edk::uint16)this->z);edkEnd();
    }
    vec3ui16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui16((edk::uint16)this->x,(edk::uint16)this->y,(edk::uint16)this->z);edkEnd();
    }
};

//vec3ui32
class vec3ui32{
    //
public:
    edk::uint32 x,y,z;

    //CONSTRUTOR
    vec3ui32(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3ui32(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::uint32)x;edkEnd();
        this->y=(edk::uint32)y;edkEnd();
        this->z=(edk::uint32)z;edkEnd();
    }
    vec3ui32(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::uint32)x;edkEnd();
        this->y=(edk::uint32)y;edkEnd();
        this->z=(edk::uint32)z;edkEnd();
    }
    vec3ui32(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::uint32)x;edkEnd();
        this->y=(edk::uint32)y;edkEnd();
        this->z=(edk::uint32)z;edkEnd();
    }
    vec3ui32(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::uint32)x;edkEnd();
        this->y=(edk::uint32)y;edkEnd();
        this->z=(edk::uint32)z;edkEnd();
    }
    //operators

    //=
    vec3ui32 operator=(vec3ui8 vec){
        //
        this->x=(edk::uint32)vec.x;edkEnd();
        this->y=(edk::uint32)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui32 operator=(vec3ui16 vec){
        //
        this->x=(edk::uint32)vec.x;edkEnd();
        this->y=(edk::uint32)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui32 operator=(vec3ui32 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui32 operator=(vec2i8 vec){
        //
        this->x=(edk::uint32)vec.x;edkEnd();
        this->y=(edk::uint32)vec.y;edkEnd();
        this->z=(edk::uint32)0;edkEnd();
        return *this;edkEnd();
    }
    vec3ui32 operator=(edk::uint8 n){
        //
        this->x=(edk::uint32)n;edkEnd();
        this->y=(edk::uint32)n;edkEnd();
        this->z=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui32 operator=(edk::uint16 n){
        //
        this->x=(edk::uint32)n;edkEnd();
        this->y=(edk::uint32)n;edkEnd();
        this->z=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui32 operator=(edk::uint32 n){
        //
        this->x=(edk::uint32)n;edkEnd();
        this->y=(edk::uint32)n;edkEnd();
        this->z=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui32 operator=(edk::uint64 n){
        //
        this->x=(edk::uint32)n;edkEnd();
        this->y=(edk::uint32)n;edkEnd();
        this->z=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3ui8 vec){
        //
        return (this->x==(edk::uint32)vec.x&&this->y==(edk::uint32)vec.y&&this->z==(edk::uint32)vec.z);edkEnd();
    }
    bool operator==(vec3ui16 vec){
        //
        return (this->x==(edk::uint32)vec.x&&this->y==(edk::uint32)vec.y&&this->z==(edk::uint32)vec.z);edkEnd();
    }
    bool operator==(vec3ui32 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3ui8 vec){
        //
        return (this->x!=(edk::uint32)vec.x||this->y!=(edk::uint32)vec.y||this->z!=(edk::uint32)vec.z);edkEnd();
    }
    bool operator!=(vec3ui16 vec){
        //
        return (this->x!=(edk::uint32)vec.x||this->y!=(edk::uint32)vec.y||this->z!=(edk::uint32)vec.z);edkEnd();
    }
    bool operator!=(vec3ui32 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3ui8 vec){
        if(this->x>(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y>(edk::uint32)vec.y){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y==(edk::uint32)vec.y && this->z>(edk::uint32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3ui16 vec){
        if(this->x>(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y>(edk::uint32)vec.y){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y==(edk::uint32)vec.y && this->z>(edk::uint32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3ui32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3ui8 vec){
        if(this->x>(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y>(edk::uint32)vec.y){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y==(edk::uint32)vec.y && this->z>=(edk::uint32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3ui16 vec){
        if(this->x>(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y>(edk::uint32)vec.y){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y==(edk::uint32)vec.y && this->z>=(edk::uint32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3ui32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3ui8 vec){
        if(this->x<(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y<(edk::uint32)vec.y){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y==(edk::uint32)vec.y && this->z<(edk::uint32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3ui16 vec){
        if(this->x<(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y<(edk::uint32)vec.y){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y==(edk::uint32)vec.y && this->z<(edk::uint32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3ui32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3ui8 vec){
        if(this->x<(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y<(edk::uint32)vec.y){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y==(edk::uint32)vec.y && this->z<=(edk::uint32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3ui16 vec){
        if(this->x<(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y<(edk::uint32)vec.y){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y==(edk::uint32)vec.y && this->z<=(edk::uint32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3ui32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3ui32 operator+(vec3ui8 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)vec.x;edkEnd();
        ret.y=this->y+(edk::uint32)vec.y;edkEnd();
        ret.z=this->z+(edk::uint32)vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator+(vec3ui16 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)vec.x;edkEnd();
        ret.y=this->y+(edk::uint32)vec.y;edkEnd();
        ret.z=this->z+(edk::uint32)vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator+(vec3ui32 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator+(vec2i8 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)vec.x;edkEnd();
        ret.y=this->y+(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec3ui32 operator+(edk::uint8 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)n;edkEnd();
        ret.y=this->y+(edk::uint32)n;edkEnd();
        ret.z=this->z+(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator+(edk::uint16 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)n;edkEnd();
        ret.y=this->y+(edk::uint32)n;edkEnd();
        ret.z=this->z+(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator+(edk::uint32 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)n;edkEnd();
        ret.y=this->y+(edk::uint32)n;edkEnd();
        ret.z=this->z+(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator+(edk::uint64 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)n;edkEnd();
        ret.y=this->y+(edk::uint32)n;edkEnd();
        ret.z=this->z+(edk::uint32)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3ui8 vec){
        //
        this->x+=(edk::uint32)vec.x;edkEnd();
        this->y+=(edk::uint32)vec.y;edkEnd();
        this->z+=(edk::uint32)vec.z;edkEnd();
    }
    void operator+=(vec3ui16 vec){
        //
        this->x+=(edk::uint32)vec.x;edkEnd();
        this->y+=(edk::uint32)vec.y;edkEnd();
        this->z+=(edk::uint32)vec.z;edkEnd();
    }
    void operator+=(vec3ui32 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=(edk::uint32)vec.x;edkEnd();
        this->y+=(edk::uint32)vec.y;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::uint32)n;edkEnd();
        this->y+=(edk::uint32)n;edkEnd();
        this->z+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::uint32)n;edkEnd();
        this->y+=(edk::uint32)n;edkEnd();
        this->z+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::uint32)n;edkEnd();
        this->y+=(edk::uint32)n;edkEnd();
        this->z+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::uint32)n;edkEnd();
        this->y+=(edk::uint32)n;edkEnd();
        this->z+=(edk::uint32)n;edkEnd();
    }

    //-
    vec3ui32 operator-(vec3ui8 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)vec.x;edkEnd();
        ret.y=this->y-(edk::uint32)vec.y;edkEnd();
        ret.z=this->z-(edk::uint32)vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator-(vec3ui16 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)vec.x;edkEnd();
        ret.y=this->y-(edk::uint32)vec.y;edkEnd();
        ret.z=this->z-(edk::uint32)vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator-(vec3ui32 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator-(vec2i8 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)vec.x;edkEnd();
        ret.y=this->y-(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec3ui32 operator-(edk::uint8 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)n;edkEnd();
        ret.y=this->y-(edk::uint32)n;edkEnd();
        ret.z=this->z-(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator-(edk::uint16 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)n;edkEnd();
        ret.y=this->y-(edk::uint32)n;edkEnd();
        ret.z=this->z-(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator-(edk::uint32 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)n;edkEnd();
        ret.y=this->y-(edk::uint32)n;edkEnd();
        ret.z=this->z-(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator-(edk::uint64 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)n;edkEnd();
        ret.y=this->y-(edk::uint32)n;edkEnd();
        ret.z=this->z-(edk::uint32)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3ui8 vec){
        //
        this->x-=(edk::uint32)vec.x;edkEnd();
        this->y-=(edk::uint32)vec.y;edkEnd();
        this->z-=(edk::uint32)vec.z;edkEnd();
    }
    void operator-=(vec3ui16 vec){
        //
        this->x-=(edk::uint32)vec.x;edkEnd();
        this->y-=(edk::uint32)vec.y;edkEnd();
        this->z-=(edk::uint32)vec.z;edkEnd();
    }
    void operator-=(vec3ui32 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=(edk::uint32)vec.x;edkEnd();
        this->y-=(edk::uint32)vec.y;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::uint32)n;edkEnd();
        this->y-=(edk::uint32)n;edkEnd();
        this->z-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::uint32)n;edkEnd();
        this->y-=(edk::uint32)n;edkEnd();
        this->z-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::uint32)n;edkEnd();
        this->y-=(edk::uint32)n;edkEnd();
        this->z-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::uint32)n;edkEnd();
        this->y-=(edk::uint32)n;edkEnd();
        this->z-=(edk::uint32)n;edkEnd();
    }

    //*
    vec3ui32 operator*(vec3ui8 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)vec.x;edkEnd();
        ret.y=this->y*(edk::uint32)vec.y;edkEnd();
        ret.z=this->z*(edk::uint32)vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator*(vec3ui16 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)vec.x;edkEnd();
        ret.y=this->y*(edk::uint32)vec.y;edkEnd();
        ret.z=this->z*(edk::uint32)vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator*(vec3ui32 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3ui32 operator*(vec2i8 vec){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)vec.x;edkEnd();
        ret.y=this->y*(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec3ui32 operator*(edk::uint8 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)n;edkEnd();
        ret.y=this->y*(edk::uint32)n;edkEnd();
        ret.z=this->z*(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator*(edk::uint16 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)n;edkEnd();
        ret.y=this->y*(edk::uint32)n;edkEnd();
        ret.z=this->z*(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator*(edk::uint32 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)n;edkEnd();
        ret.y=this->y*(edk::uint32)n;edkEnd();
        ret.z=this->z*(edk::uint32)n;edkEnd();
        return ret;
    }
    vec3ui32 operator*(edk::uint64 n){
        //
        vec3ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)n;edkEnd();
        ret.y=this->y*(edk::uint32)n;edkEnd();
        ret.z=this->z*(edk::uint32)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3ui8 vec){
        //
        this->x*=(edk::uint32)vec.x;edkEnd();
        this->y*=(edk::uint32)vec.y;edkEnd();
        this->z*=(edk::uint32)vec.z;edkEnd();
    }
    void operator*=(vec3ui16 vec){
        //
        this->x*=(edk::uint32)vec.x;edkEnd();
        this->y*=(edk::uint32)vec.y;edkEnd();
        this->z*=(edk::uint32)vec.z;edkEnd();
    }
    void operator*=(vec3ui32 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=(edk::uint32)vec.x;edkEnd();
        this->y*=(edk::uint32)vec.y;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::uint32)n;edkEnd();
        this->y*=(edk::uint32)n;edkEnd();
        this->z*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::uint32)n;edkEnd();
        this->y*=(edk::uint32)n;edkEnd();
        this->z*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::uint32)n;edkEnd();
        this->y*=(edk::uint32)n;edkEnd();
        this->z*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::uint32)n;edkEnd();
        this->y*=(edk::uint32)n;edkEnd();
        this->z*=(edk::uint32)n;edkEnd();
    }

    //++
    vec3ui32 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3ui32(this->x,this->y,this->z);edkEnd();
    }
    vec3ui32 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3ui32(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3ui32 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3ui32(this->x,this->y,this->z);edkEnd();
    }
    vec3ui32 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3ui32(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3ui32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui32((edk::uint32)this->x,(edk::uint32)this->y,(edk::uint32)this->z);edkEnd();
    }
    vec3ui32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui32((edk::uint32)this->x,(edk::uint32)this->y,(edk::uint32)this->z);edkEnd();
    }
    vec3ui32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui32((edk::uint32)this->x,(edk::uint32)this->y,(edk::uint32)this->z);edkEnd();
    }
    vec3ui32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui32((edk::uint32)this->x,(edk::uint32)this->y,(edk::uint32)this->z);edkEnd();
    }
};

//vec3ui64
class vec3ui64{
    //
public:
    edk::uint64 x,y,z;

    //CONSTRUTOR
    vec3ui64(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3ui64(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::uint64)x;edkEnd();
        this->y=(edk::uint64)y;edkEnd();
        this->z=(edk::uint64)z;edkEnd();
    }
    vec3ui64(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::uint64)x;edkEnd();
        this->y=(edk::uint64)y;edkEnd();
        this->z=(edk::uint64)z;edkEnd();
    }
    vec3ui64(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::uint64)x;edkEnd();
        this->y=(edk::uint64)y;edkEnd();
        this->z=(edk::uint64)z;edkEnd();
    }
    vec3ui64(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::uint64)x;edkEnd();
        this->y=(edk::uint64)y;edkEnd();
        this->z=(edk::uint64)z;edkEnd();
    }
    //operators

    //=
    vec3ui64 operator=(vec3ui8 vec){
        //
        this->x=(edk::uint64)vec.x;edkEnd();
        this->y=(edk::uint64)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui64 operator=(vec3ui16 vec){
        //
        this->x=(edk::uint64)vec.x;edkEnd();
        this->y=(edk::uint64)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui64 operator=(vec3ui32 vec){
        //
        this->x=(edk::uint64)vec.x;edkEnd();
        this->y=(edk::uint64)vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui64 operator=(vec3ui64 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3ui64 operator=(vec2i8 vec){
        //
        this->x=(edk::uint64)vec.x;edkEnd();
        this->y=(edk::uint64)vec.y;edkEnd();
        this->z=(edk::uint64)0;edkEnd();
        return *this;edkEnd();
    }
    vec3ui64 operator=(edk::uint8 n){
        //
        this->x=(edk::uint64)n;edkEnd();
        this->y=(edk::uint64)n;edkEnd();
        this->z=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui64 operator=(edk::uint16 n){
        //
        this->x=(edk::uint64)n;edkEnd();
        this->y=(edk::uint64)n;edkEnd();
        this->z=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui64 operator=(edk::uint32 n){
        //
        this->x=(edk::uint64)n;edkEnd();
        this->y=(edk::uint64)n;edkEnd();
        this->z=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3ui64 operator=(edk::uint64 n){
        //
        this->x=(edk::uint64)n;edkEnd();
        this->y=(edk::uint64)n;edkEnd();
        this->z=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3ui8 vec){
        //
        return (this->x==(edk::uint64)vec.x&&this->y==(edk::uint64)vec.y&&this->z==(edk::uint64)vec.z);edkEnd();
    }
    bool operator==(vec3ui16 vec){
        //
        return (this->x==(edk::uint64)vec.x&&this->y==(edk::uint64)vec.y&&this->z==(edk::uint64)vec.z);edkEnd();
    }
    bool operator==(vec3ui32 vec){
        //
        return (this->x==(edk::uint64)vec.x&&this->y==(edk::uint64)vec.y&&this->z==(edk::uint64)vec.z);edkEnd();
    }
    bool operator==(vec3ui64 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3ui8 vec){
        //
        return (this->x!=(edk::uint64)vec.x||this->y!=(edk::uint64)vec.y||this->z!=(edk::uint64)vec.z);edkEnd();
    }
    bool operator!=(vec3ui16 vec){
        //
        return (this->x!=(edk::uint64)vec.x||this->y!=(edk::uint64)vec.y||this->z!=(edk::uint64)vec.z);edkEnd();
    }
    bool operator!=(vec3ui32 vec){
        //
        return (this->x!=(edk::uint64)vec.x||this->y!=(edk::uint64)vec.y||this->z!=(edk::uint64)vec.z);edkEnd();
    }
    bool operator!=(vec3ui64 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3ui8 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z>(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3ui16 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z>(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3ui32 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z>(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3ui64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3ui8 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z>=(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3ui16 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z>=(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3ui32 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z>=(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3ui64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3ui8 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z<(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3ui16 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z<(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3ui32 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z<(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3ui64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3ui8 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z<=(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3ui16 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z<=(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3ui32 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y==(edk::uint64)vec.y && this->z<=(edk::uint64)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3ui64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3ui64 operator+(vec3ui8 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)vec.x;edkEnd();
        ret.y=this->y+(edk::uint64)vec.y;edkEnd();
        ret.z=this->z+(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator+(vec3ui16 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)vec.x;edkEnd();
        ret.y=this->y+(edk::uint64)vec.y;edkEnd();
        ret.z=this->z+(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator+(vec3ui32 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)vec.x;edkEnd();
        ret.y=this->y+(edk::uint64)vec.y;edkEnd();
        ret.z=this->z+(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator+(vec3ui64 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator+(vec2i8 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)vec.x;edkEnd();
        ret.y=this->y+(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec3ui64 operator+(edk::uint8 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)n;edkEnd();
        ret.y=this->y+(edk::uint64)n;edkEnd();
        ret.z=this->z+(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator+(edk::uint16 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)n;edkEnd();
        ret.y=this->y+(edk::uint64)n;edkEnd();
        ret.z=this->z+(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator+(edk::uint32 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)n;edkEnd();
        ret.y=this->y+(edk::uint64)n;edkEnd();
        ret.z=this->z+(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator+(edk::uint64 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)n;edkEnd();
        ret.y=this->y+(edk::uint64)n;edkEnd();
        ret.z=this->z+(edk::uint64)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3ui8 vec){
        //
        this->x+=(edk::uint64)vec.x;edkEnd();
        this->y+=(edk::uint64)vec.y;edkEnd();
        this->z+=(edk::uint64)vec.z;edkEnd();
    }
    void operator+=(vec3ui16 vec){
        //
        this->x+=(edk::uint64)vec.x;edkEnd();
        this->y+=(edk::uint64)vec.y;edkEnd();
        this->z+=(edk::uint64)vec.z;edkEnd();
    }
    void operator+=(vec3ui32 vec){
        //
        this->x+=(edk::uint64)vec.x;edkEnd();
        this->y+=(edk::uint64)vec.y;edkEnd();
        this->z+=(edk::uint64)vec.z;edkEnd();
    }
    void operator+=(vec3ui64 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=(edk::uint64)vec.x;edkEnd();
        this->y+=(edk::uint64)vec.y;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::uint64)n;edkEnd();
        this->y+=(edk::uint64)n;edkEnd();
        this->z+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::uint64)n;edkEnd();
        this->y+=(edk::uint64)n;edkEnd();
        this->z+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::uint64)n;edkEnd();
        this->y+=(edk::uint64)n;edkEnd();
        this->z+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::uint64)n;edkEnd();
        this->y+=(edk::uint64)n;edkEnd();
        this->z+=(edk::uint64)n;edkEnd();
    }

    //-
    vec3ui64 operator-(vec3ui8 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)vec.x;edkEnd();
        ret.y=this->y-(edk::uint64)vec.y;edkEnd();
        ret.z=this->z-(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator-(vec3ui16 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)vec.x;edkEnd();
        ret.y=this->y-(edk::uint64)vec.y;edkEnd();
        ret.z=this->z-(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator-(vec3ui32 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)vec.x;edkEnd();
        ret.y=this->y-(edk::uint64)vec.y;edkEnd();
        ret.z=this->z-(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator-(vec3ui64 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator-(vec2i8 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)vec.x;edkEnd();
        ret.y=this->y-(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec3ui64 operator-(edk::uint8 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)n;edkEnd();
        ret.y=this->y-(edk::uint64)n;edkEnd();
        ret.z=this->z-(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator-(edk::uint16 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)n;edkEnd();
        ret.y=this->y-(edk::uint64)n;edkEnd();
        ret.z=this->z-(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator-(edk::uint32 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)n;edkEnd();
        ret.y=this->y-(edk::uint64)n;edkEnd();
        ret.z=this->z-(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator-(edk::uint64 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)n;edkEnd();
        ret.y=this->y-(edk::uint64)n;edkEnd();
        ret.z=this->z-(edk::uint64)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3ui8 vec){
        //
        this->x-=(edk::uint64)vec.x;edkEnd();
        this->y-=(edk::uint64)vec.y;edkEnd();
        this->z-=(edk::uint64)vec.z;edkEnd();
    }
    void operator-=(vec3ui16 vec){
        //
        this->x-=(edk::uint64)vec.x;edkEnd();
        this->y-=(edk::uint64)vec.y;edkEnd();
        this->z-=(edk::uint64)vec.z;edkEnd();
    }
    void operator-=(vec3ui32 vec){
        //
        this->x-=(edk::uint64)vec.x;edkEnd();
        this->y-=(edk::uint64)vec.y;edkEnd();
        this->z-=(edk::uint64)vec.z;edkEnd();
    }
    void operator-=(vec3ui64 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=(edk::uint64)vec.x;edkEnd();
        this->y-=(edk::uint64)vec.y;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::uint64)n;edkEnd();
        this->y-=(edk::uint64)n;edkEnd();
        this->z-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::uint64)n;edkEnd();
        this->y-=(edk::uint64)n;edkEnd();
        this->z-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::uint64)n;edkEnd();
        this->y-=(edk::uint64)n;edkEnd();
        this->z-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::uint64)n;edkEnd();
        this->y-=(edk::uint64)n;edkEnd();
        this->z-=(edk::uint64)n;edkEnd();
    }

    //*
    vec3ui64 operator*(vec3ui8 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)vec.x;edkEnd();
        ret.y=this->y*(edk::uint64)vec.y;edkEnd();
        ret.z=this->z*(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator*(vec3ui16 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)vec.x;edkEnd();
        ret.y=this->y*(edk::uint64)vec.y;edkEnd();
        ret.z=this->z*(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator*(vec3ui32 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)vec.x;edkEnd();
        ret.y=this->y*(edk::uint64)vec.y;edkEnd();
        ret.z=this->z*(edk::uint64)vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator*(vec3ui64 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3ui64 operator*(vec2i8 vec){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)vec.x;edkEnd();
        ret.y=this->y*(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec3ui64 operator*(edk::uint8 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)n;edkEnd();
        ret.y=this->y*(edk::uint64)n;edkEnd();
        ret.z=this->z*(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator*(edk::uint16 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)n;edkEnd();
        ret.y=this->y*(edk::uint64)n;edkEnd();
        ret.z=this->z*(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator*(edk::uint32 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)n;edkEnd();
        ret.y=this->y*(edk::uint64)n;edkEnd();
        ret.z=this->z*(edk::uint64)n;edkEnd();
        return ret;
    }
    vec3ui64 operator*(edk::uint64 n){
        //
        vec3ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)n;edkEnd();
        ret.y=this->y*(edk::uint64)n;edkEnd();
        ret.z=this->z*(edk::uint64)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3ui8 vec){
        //
        this->x*=(edk::uint64)vec.x;edkEnd();
        this->y*=(edk::uint64)vec.y;edkEnd();
        this->z*=(edk::uint64)vec.z;edkEnd();
    }
    void operator*=(vec3ui16 vec){
        //
        this->x*=(edk::uint64)vec.x;edkEnd();
        this->y*=(edk::uint64)vec.y;edkEnd();
        this->z*=(edk::uint64)vec.z;edkEnd();
    }
    void operator*=(vec3ui32 vec){
        //
        this->x*=(edk::uint64)vec.x;edkEnd();
        this->y*=(edk::uint64)vec.y;edkEnd();
        this->z*=(edk::uint64)vec.z;edkEnd();
    }
    void operator*=(vec3ui64 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=(edk::uint64)vec.x;edkEnd();
        this->y*=(edk::uint64)vec.y;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::uint64)n;edkEnd();
        this->y*=(edk::uint64)n;edkEnd();
        this->z*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::uint64)n;edkEnd();
        this->y*=(edk::uint64)n;edkEnd();
        this->z*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::uint64)n;edkEnd();
        this->y*=(edk::uint64)n;edkEnd();
        this->z*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::uint64)n;edkEnd();
        this->y*=(edk::uint64)n;edkEnd();
        this->z*=(edk::uint64)n;edkEnd();
    }

    //++
    vec3ui64 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3ui64(this->x,this->y,this->z);edkEnd();
    }
    vec3ui64 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3ui64(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3ui64 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3ui64(this->x,this->y,this->z);edkEnd();
    }
    vec3ui64 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3ui64(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3ui64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui64((edk::uint64)this->x,(edk::uint64)this->y,(edk::uint64)this->z);edkEnd();
    }
    vec3ui64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui64((edk::uint64)this->x,(edk::uint64)this->y,(edk::uint64)this->z);edkEnd();
    }
    vec3ui64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui64((edk::uint64)this->x,(edk::uint64)this->y,(edk::uint64)this->z);edkEnd();
    }
    vec3ui64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3ui64((edk::uint64)this->x,(edk::uint64)this->y,(edk::uint64)this->z);edkEnd();
    }
};

//vec3f32
class vec3f32{
    //
public:
    edk::float32 x,y,z;

    //CONSTRUTOR
    vec3f32(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3f32(edk::float32 x,edk::float32 y,edk::float32 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::float64 x,edk::float64 y,edk::float64 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::int8 x,edk::int8 y,edk::int8 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::int16 x,edk::int16 y,edk::int16 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::int32 x,edk::int32 y,edk::int32 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::int64 x,edk::int64 y,edk::int64 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    vec3f32(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
        this->z=(edk::float32)z;edkEnd();
    }
    //operators

    //=
    vec3f32 operator=(vec3f32 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(vec2i8 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=(edk::float32)0;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::float32 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::float64 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::int8 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::int16 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::int32 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::int64 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::uint8 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::uint16 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::uint32 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f32 operator=(edk::uint64 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        this->z=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3f32 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3f32 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3f32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3f32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3f32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3f32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3f32 operator+(vec3f32 vec){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3f32 operator+(vec2i8 vec){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::float32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::float64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::int8 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::int16 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::int32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::int64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::uint8 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::uint16 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::uint32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator+(edk::uint64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        ret.z=this->z+(edk::float32)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3f32 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
        this->z+=(edk::float32)n;edkEnd();
    }

    //-
    vec3f32 operator-(vec3f32 vec){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3f32 operator-(vec2i8 vec){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::float32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::float64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::int8 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::int16 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::int32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::int64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::uint8 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::uint16 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::uint32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator-(edk::uint64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        ret.z=this->z-(edk::float32)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3f32 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
        this->z-=(edk::float32)n;edkEnd();
    }

    //*
    vec3f32 operator*(vec3f32 vec){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3f32 operator*(vec2i8 vec){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::float32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::float64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::int8 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::int16 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::int32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::int64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::uint8 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::uint16 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::uint32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator*(edk::uint64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        ret.z=this->z*(edk::float32)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3f32 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
        this->z*=(edk::float32)n;edkEnd();
    }

    // /
    vec3f32 operator/(vec3f32 vec){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/vec.x;edkEnd();
        ret.y=this->y/vec.y;edkEnd();
        ret.z=this->z/vec.z;edkEnd();
        return ret;
    }
    vec3f32 operator/(vec2i8 vec){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/vec.x;edkEnd();
        ret.y=this->y/vec.y;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::float32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::float64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::int8 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::int16 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::int32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::int64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::uint8 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::uint16 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::uint32 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }
    vec3f32 operator/(edk::uint64 n){
        //
        vec3f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        ret.z=this->z/(edk::float32)n;edkEnd();
        return ret;
    }

    // /=
    void operator/=(vec3f32 vec){
        //
        this->x/=vec.x;edkEnd();
        this->y/=vec.y;edkEnd();
        this->z/=vec.z;edkEnd();
    }
    void operator/=(vec2i8 vec){
        //
        this->x/=vec.x;edkEnd();
        this->y/=vec.y;edkEnd();
    }
    void operator/=(edk::float32 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::float64 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int8 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int16 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int32 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int64 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint8 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint16 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint32 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint64 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
        this->z/=(edk::float32)n;edkEnd();
    }

    //++
    vec3f32 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3f32(this->x,this->y,this->z);edkEnd();
    }
    vec3f32 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3f32(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3f32 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3f32(this->x,this->y,this->z);edkEnd();
    }
    vec3f32 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3f32(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3f32 operator()(edk::float32 x,edk::float32 y,edk::float32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::float64 x,edk::float64 y,edk::float64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::int8 x,edk::int8 y,edk::int8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::int16 x,edk::int16 y,edk::int16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::int32 x,edk::int32 y,edk::int32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::int64 x,edk::int64 y,edk::int64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
    vec3f32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z);edkEnd();
    }
};

//vec3f64
class vec3f64{
    //
public:
    edk::float64 x,y,z;

    //CONSTRUTOR
    vec3f64(){
        //zera as variaveis
        this->x=this->y=this->z=0;edkEnd();
    }
    vec3f64(edk::float32 x,edk::float32 y,edk::float32 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::float64 x,edk::float64 y,edk::float64 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::int8 x,edk::int8 y,edk::int8 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::int16 x,edk::int16 y,edk::int16 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::int32 x,edk::int32 y,edk::int32 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::int64 x,edk::int64 y,edk::int64 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    vec3f64(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
        this->z=(edk::float64)z;edkEnd();
    }
    //operators

    //=
    vec3f64 operator=(vec3f64 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=vec.z;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(vec2i8 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        this->z=(edk::float64)0;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::float32 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::float64 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::int8 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::int16 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::int32 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::int64 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::uint8 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::uint16 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::uint32 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec3f64 operator=(edk::uint64 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        this->z=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(vec3f64 vec){
        //
        return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z);edkEnd();
    }
    //!=
    bool operator!=(vec3f64 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z);edkEnd();
    }

    //Operator >
    bool operator>(vec3f32 vec){
        if(this->x>(float32)vec.x){
            return true;
        }
        else if(this->x==(float32)vec.x && this->y>(float32)vec.y){
            return true;
        }
        else if(this->x==(float32)vec.x && this->y==(float32)vec.y && this->z>(float32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>(vec3f64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>vec.z){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(vec3f32 vec){
        if(this->x>(float32)vec.x){
            return true;
        }
        else if(this->x==(float32)vec.x && this->y>(float32)vec.y){
            return true;
        }
        else if(this->x==(float32)vec.x && this->y==(float32)vec.y && this->z>=(float32)vec.z){
            return true;
        }
        return false;
    }
    bool operator>=(vec3f64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z>=vec.z){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(vec3f32 vec){
        if(this->x<(float32)vec.x){
            return true;
        }
        else if(this->x==(float32)vec.x && this->y<(float32)vec.y){
            return true;
        }
        else if(this->x==(float32)vec.x && this->y==(float32)vec.y && this->z<(float32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<(vec3f64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<vec.z){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(vec3f32 vec){
        if(this->x<(float32)vec.x){
            return true;
        }
        else if(this->x==(float32)vec.x && this->y<(float32)vec.y){
            return true;
        }
        else if(this->x==(float32)vec.x && this->y==(float32)vec.y && this->z<=(float32)vec.z){
            return true;
        }
        return false;
    }
    bool operator<=(vec3f64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        else if(this->x==vec.x && this->y==vec.y && this->z<=vec.z){
            return true;
        }
        return false;
    }

    //+
    vec3f64 operator+(vec3f64 vec){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        ret.z=this->z+vec.z;edkEnd();
        return ret;
    }
    vec3f64 operator+(vec2i8 vec){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::float32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::float64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::int8 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::int16 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::int32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::int64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::uint8 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::uint16 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::uint32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator+(edk::uint64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        ret.z=this->z+(edk::float64)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(vec3f64 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
        this->z+=vec.z;edkEnd();
    }
    void operator+=(vec2i8 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
        this->z+=(edk::float64)n;edkEnd();
    }

    //-
    vec3f64 operator-(vec3f64 vec){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        ret.z=this->z-vec.z;edkEnd();
        return ret;
    }
    vec3f64 operator-(vec2i8 vec){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::float32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::float64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::int8 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::int16 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::int32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::int64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::uint8 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::uint16 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::uint32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator-(edk::uint64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        ret.z=this->z-(edk::float64)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(vec3f64 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
        this->z-=vec.z;edkEnd();
    }
    void operator-=(vec2i8 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
        this->z-=(edk::float64)n;edkEnd();
    }

    //*
    vec3f64 operator*(vec3f64 vec){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        ret.z=this->z*vec.z;edkEnd();
        return ret;
    }
    vec3f64 operator*(vec2i8 vec){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::float32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::float64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::int8 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::int16 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::int32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::int64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::uint8 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::uint16 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::uint32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator*(edk::uint64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        ret.z=this->z*(edk::float64)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(vec3f64 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
        this->z*=vec.z;edkEnd();
    }
    void operator*=(vec2i8 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
        this->z*=(edk::float64)n;edkEnd();
    }

    // /
    vec3f64 operator/(vec3f64 vec){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/vec.x;edkEnd();
        ret.y=this->y/vec.y;edkEnd();
        ret.z=this->z/vec.z;edkEnd();
        return ret;
    }
    vec3f64 operator/(vec2i8 vec){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/vec.x;edkEnd();
        ret.y=this->y/vec.y;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::float32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::float64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::int8 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::int16 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::int32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::int64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::uint8 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::uint16 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::uint32 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }
    vec3f64 operator/(edk::uint64 n){
        //
        vec3f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        ret.z=this->z/(edk::float64)n;edkEnd();
        return ret;
    }

    // /=
    void operator/=(vec3f64 vec){
        //
        this->x/=vec.x;edkEnd();
        this->y/=vec.y;edkEnd();
        this->z/=vec.z;edkEnd();
    }
    void operator/=(vec2i8 vec){
        //
        this->x/=vec.x;edkEnd();
        this->y/=vec.y;edkEnd();
    }
    void operator/=(edk::float32 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::float64 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int8 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int16 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int32 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int64 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint8 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint16 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint32 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint64 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
        this->z/=(edk::float64)n;edkEnd();
    }

    //++
    vec3f64 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        ++this->z;edkEnd();
        return vec3f64(this->x,this->y,this->z);edkEnd();
    }
    vec3f64 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        this->z++;edkEnd();
        return vec3f64(this->x,this->y,this->z);edkEnd();
    }

    //--
    vec3f64 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        --this->z;edkEnd();
        return vec3f64(this->x,this->y,this->z);edkEnd();
    }
    vec3f64 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        this->z--;edkEnd();
        return vec3f64(this->x,this->y,this->z);edkEnd();
    }

    //
    vec3f64 operator()(edk::float32 x,edk::float32 y,edk::float32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::float64 x,edk::float64 y,edk::float64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::int8 x,edk::int8 y,edk::int8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::int16 x,edk::int16 y,edk::int16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::int32 x,edk::int32 y,edk::int32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::int64 x,edk::int64 y,edk::int64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
    vec3f64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        return vec3f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z);edkEnd();
    }
};

}//endnamespace

#endif // TYPEVEC3_H
