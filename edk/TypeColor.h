#ifndef EDK_TYPECOLOR_H
#define EDK_TYPECOLOR_H

/*
Library C++ TypeColor - Color types used by EDK Game Engine
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
#warning "Inside TypeColor"
#endif

#pragma once
#include "TypeVars.h"
#include "DebugFile.h"
#include "TypeVec2.h"
#include "TypeVec3.h"
#include "TypeVec4.h"

#ifdef printMessages
#warning "    Compiling TypeColor"
#endif


namespace edk{
//
//color3ui8
class color3ui8{
    //
public:
    edk::uint8 r,g,b;

    //CONSTRUTOR
    color3ui8(){
        //zera as variaveis
        this->r=this->g=this->b=255;edkEnd();
    }
    color3ui8(edk::uint8 r,edk::uint8 g,edk::uint8 b){
        //zera as variaveis
        this->r=(edk::uint8)r;edkEnd();
        this->g=(edk::uint8)g;edkEnd();
        this->b=(edk::uint8)b;edkEnd();
    }
    color3ui8(edk::uint16 r,edk::uint16 g,edk::uint16 b){
        if(r>=256u){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256u){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256u){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
    }
    color3ui8(edk::uint32 r,edk::uint32 g,edk::uint32 b){
        if(r>=256u){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256u){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256u){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
    }
    color3ui8(edk::uint64 r,edk::uint64 g,edk::uint64 b){
        if(r>=256u){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256u){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256u){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
    }
    color3ui8(edk::int8 r,edk::int8 g,edk::int8 b){
        //zera as variaveis
        this->r=(edk::uint8)r;edkEnd();
        this->g=(edk::uint8)g;edkEnd();
        this->b=(edk::uint8)b;edkEnd();
    }
    color3ui8(edk::int16 r,edk::int16 g,edk::int16 b){
        if(r>=256){
            this->r=(edk::uint8)255;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256){
            this->g=(edk::uint8)255;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256){
            this->b=(edk::uint8)255;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
    }
    color3ui8(edk::int32 r,edk::int32 g,edk::int32 b){
        if(r>=256){
            this->r=(edk::uint8)255;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256){
            this->g=(edk::uint8)255;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256){
            this->b=(edk::uint8)255;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
    }
    color3ui8(edk::int64 r,edk::int64 g,edk::int64 b){
        if(r>=256){
            this->r=(edk::uint8)255;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256){
            this->g=(edk::uint8)255;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256){
            this->b=(edk::uint8)255;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
    }
    //operators

    //=
    edk::color3ui8 operator=(edk::color3ui8 color){
        //
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(vec3i8 color){
        //
        this->r=color.x;edkEnd();
        this->g=color.y;edkEnd();
        this->b=color.z;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(edk::uint8 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(edk::uint16 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(edk::uint32 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(edk::uint64 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(edk::int8 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(edk::int16 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(edk::int32 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3ui8 operator=(edk::int64 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::color3ui8 color){
        //
        return (this->r==color.r&&this->g==color.g&&this->b==color.b);edkEnd();
    }
    //!=
    bool operator!=(edk::color3ui8 color){
        //
        return (this->r!=color.r||this->g!=color.g||this->b!=color.b);edkEnd();
    }

    //+
    edk::color3ui8 operator+(edk::color3ui8 color){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+color.r;edkEnd();
        ret.g=this->g+color.g;edkEnd();
        ret.b=this->b+color.b;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(vec3i8 color){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+color.x;edkEnd();
        ret.g=this->g+color.y;edkEnd();
        ret.b=this->b+color.z;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(edk::uint8 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(edk::uint16 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(edk::uint32 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(edk::uint64 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(edk::int8 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(edk::int16 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(edk::int32 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator+(edk::int64 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::color3ui8 color){
        //
        this->r+=color.r;edkEnd();
        this->g+=color.g;edkEnd();
        this->b+=color.b;edkEnd();
    }
    void operator+=(vec3i8 color){
        //
        this->r+=color.x;edkEnd();
        this->g+=color.y;edkEnd();
        this->b+=color.z;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
    }

    //-
    edk::color3ui8 operator-(edk::color3ui8 color){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-color.r;edkEnd();
        ret.g=this->g-color.g;edkEnd();
        ret.b=this->b-color.b;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(vec3i8 color){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-color.x;edkEnd();
        ret.g=this->g-color.y;edkEnd();
        ret.b=this->b-color.z;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(edk::uint8 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(edk::uint16 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(edk::uint32 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(edk::uint64 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(edk::int8 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(edk::int16 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(edk::int32 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator-(edk::int64 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::color3ui8 color){
        //
        this->r-=color.r;edkEnd();
        this->g-=color.g;edkEnd();
        this->b-=color.b;edkEnd();
    }
    void operator-=(vec3i8 color){
        //
        this->r-=color.x;edkEnd();
        this->g-=color.y;edkEnd();
        this->b-=color.z;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
    }

    //*
    edk::color3ui8 operator*(edk::color3ui8 color){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*color.r;edkEnd();
        ret.g=this->g*color.g;edkEnd();
        ret.b=this->b*color.b;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(vec3i8 color){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*color.x;edkEnd();
        ret.g=this->g*color.y;edkEnd();
        ret.b=this->b*color.z;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(edk::uint8 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(edk::uint16 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(edk::uint32 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(edk::uint64 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(edk::int8 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(edk::int16 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(edk::int32 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color3ui8 operator*(edk::int64 n){
        //
        edk::color3ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::color3ui8 color){
        //
        this->r*=color.r;edkEnd();
        this->g*=color.g;edkEnd();
        this->b*=color.b;edkEnd();
    }
    void operator*=(vec3i8 color){
        //
        this->r*=color.x;edkEnd();
        this->g*=color.y;edkEnd();
        this->b*=color.z;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
    }

    //++
    edk::color3ui8 operator++(){
        //
        ++this->r;edkEnd();
        ++this->g;edkEnd();
        ++this->b;edkEnd();
        return color3ui8(this->r,this->g,this->b);edkEnd();
    }
    edk::color3ui8 operator++(edk::int32){
        //
        this->r++;edkEnd();
        this->g++;edkEnd();
        this->b++;edkEnd();
        return color3ui8(this->r,this->g,this->b);edkEnd();
    }

    //--
    edk::color3ui8 operator--(){
        //
        --this->r;edkEnd();
        --this->g;edkEnd();
        --this->b;edkEnd();
        return color3ui8(this->r,this->g,this->b);edkEnd();
    }
    edk::color3ui8 operator--(edk::int32){
        //
        this->r--;edkEnd();
        this->g--;edkEnd();
        this->b--;edkEnd();
        return color3ui8(this->r,this->g,this->b);edkEnd();
    }

    //
    edk::color3ui8 operator()(edk::uint8 r,edk::uint8 g,edk::uint8 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b);edkEnd();
    }
    edk::color3ui8 operator()(edk::uint16 r,edk::uint16 g,edk::uint16 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b);edkEnd();
    }
    edk::color3ui8 operator()(edk::uint32 r,edk::uint32 g,edk::uint32 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b);edkEnd();
    }
    edk::color3ui8 operator()(edk::uint64 r,edk::uint64 g,edk::uint64 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b);edkEnd();
    }
    edk::color3ui8 operator()(edk::int8 r,edk::int8 g,edk::int8 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b);edkEnd();
    }
    edk::color3ui8 operator()(edk::int16 r,edk::int16 g,edk::int16 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b);edkEnd();
    }
    edk::color3ui8 operator()(edk::int32 r,edk::int32 g,edk::int32 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b);edkEnd();
    }
    edk::color3ui8 operator()(edk::int64 r,edk::int64 g,edk::int64 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b);edkEnd();
    }
};

//color4ui8
class color4ui8{
    //
public:
    edk::uint8 r,g,b,a;

    //CONSTRUTOR
    color4ui8(){
        //zera as variaveis
        this->r=this->g=this->b=this->a=255;edkEnd();
    }
    color4ui8(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
        //zera as variaveis
        this->r=(edk::uint8)r;edkEnd();
        this->g=(edk::uint8)g;edkEnd();
        this->b=(edk::uint8)b;edkEnd();
        this->a=(edk::uint8)a;edkEnd();
    }
    color4ui8(edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a){
        if(r>=256u){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256u){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256u){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
        if(a>=256u){
            this->a=(edk::uint8)255u;edkEnd();
        }
        else{
            this->a=(edk::uint8)a;edkEnd();
        }
    }
    color4ui8(edk::uint32 r,edk::uint32 g,edk::uint32 b,edk::uint32 a){
        if(r>=256u){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256u){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256u){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
        if(a>=256u){
            this->a=(edk::uint8)255u;edkEnd();
        }
        else{
            this->a=(edk::uint8)a;edkEnd();
        }

    }
    color4ui8(edk::uint64 r,edk::uint64 g,edk::uint64 b,edk::uint64 a){
        if(r>=256u){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256u){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256u){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
        if(a>=256u){
            this->a=(edk::uint8)255u;edkEnd();
        }
        else{
            this->a=(edk::uint8)a;edkEnd();
        }
    }
    color4ui8(edk::int8 r,edk::int8 g,edk::int8 b,edk::int8 a){
        //zera as variaveis
        this->r=(edk::uint8)r;edkEnd();
        this->g=(edk::uint8)g;edkEnd();
        this->b=(edk::uint8)b;edkEnd();
        this->a=(edk::uint8)a;edkEnd();
    }
    color4ui8(edk::int16 r,edk::int16 g,edk::int16 b,edk::int16 a){
        if(r>=256){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
        if(a>=256){
            this->a=(edk::uint8)255u;edkEnd();
        }
        else{
            this->a=(edk::uint8)a;edkEnd();
        }
    }
    color4ui8(edk::int32 r,edk::int32 g,edk::int32 b,edk::int32 a){
        if(r>=256){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
        if(a>=256){
            this->a=(edk::uint8)255u;edkEnd();
        }
        else{
            this->a=(edk::uint8)a;edkEnd();
        }
    }
    color4ui8(edk::int64 r,edk::int64 g,edk::int64 b,edk::int64 a){
        if(r>=256){
            this->r=(edk::uint8)255u;edkEnd();
        }
        else{
            this->r=(edk::uint8)r;edkEnd();
        }
        if(g>=256){
            this->g=(edk::uint8)255u;edkEnd();
        }
        else{
            this->g=(edk::uint8)g;edkEnd();
        }
        if(b>=256){
            this->b=(edk::uint8)255u;edkEnd();
        }
        else{
            this->b=(edk::uint8)b;edkEnd();
        }
        if(a>=256){
            this->a=(edk::uint8)255u;edkEnd();
        }
        else{
            this->a=(edk::uint8)a;edkEnd();
        }
    }
    //operators

    //=
    edk::color4ui8 operator=(edk::color4ui8 color){
        //
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        this->a=color.a;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(vec4i8 color){
        //
        this->r=color.x;edkEnd();
        this->g=color.y;edkEnd();
        this->b=color.z;edkEnd();
        this->a=color.w;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(edk::uint8 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        this->a=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(edk::uint16 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        this->a=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(edk::uint32 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        this->a=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(edk::uint64 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        this->a=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(edk::int8 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        this->a=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(edk::int16 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        this->a=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(edk::int32 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        this->a=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4ui8 operator=(edk::int64 n){
        //
        this->r=(edk::uint8)n;edkEnd();
        this->g=(edk::uint8)n;edkEnd();
        this->b=(edk::uint8)n;edkEnd();
        this->a=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::color4ui8 color){
        //
        return (this->r==color.r&&this->g==color.g&&this->b==color.b&&this->a==color.a);edkEnd();
    }
    //!=
    bool operator!=(edk::color4ui8 color){
        //
        return (this->r!=color.r||this->g!=color.g||this->b!=color.b||this->a!=color.a);edkEnd();
    }

    //+
    edk::color4ui8 operator+(edk::color4ui8 color){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+color.r;edkEnd();
        ret.g=this->g+color.g;edkEnd();
        ret.b=this->b+color.b;edkEnd();
        ret.a=this->a+color.a;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(vec4i8 color){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+color.x;edkEnd();
        ret.g=this->g+color.y;edkEnd();
        ret.b=this->b+color.z;edkEnd();
        ret.a=this->a+color.w;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(edk::uint8 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        ret.a=this->a+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(edk::uint16 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        ret.a=this->a+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(edk::uint32 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        ret.a=this->a+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(edk::uint64 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        ret.a=this->a+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(edk::int8 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        ret.a=this->a+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(edk::int16 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        ret.a=this->a+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(edk::int32 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        ret.a=this->a+(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator+(edk::int64 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r+(edk::uint8)n;edkEnd();
        ret.g=this->g+(edk::uint8)n;edkEnd();
        ret.b=this->b+(edk::uint8)n;edkEnd();
        ret.a=this->a+(edk::uint8)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::color4ui8 color){
        //
        this->r+=color.r;edkEnd();
        this->g+=color.g;edkEnd();
        this->b+=color.b;edkEnd();
        this->a+=color.a;edkEnd();
    }
    void operator+=(vec4i8 color){
        //
        this->r+=color.x;edkEnd();
        this->g+=color.y;edkEnd();
        this->b+=color.z;edkEnd();
        this->a+=color.w;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
        this->a+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
        this->a+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
        this->a+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
        this->a+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
        this->a+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
        this->a+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
        this->a+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->r+=(edk::uint8)n;edkEnd();
        this->g+=(edk::uint8)n;edkEnd();
        this->b+=(edk::uint8)n;edkEnd();
        this->a+=(edk::uint8)n;edkEnd();
    }

    //-
    edk::color4ui8 operator-(edk::color4ui8 color){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-color.r;edkEnd();
        ret.g=this->g-color.g;edkEnd();
        ret.b=this->b-color.b;edkEnd();
        ret.a=this->a-color.a;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(vec4i8 color){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-color.x;edkEnd();
        ret.g=this->g-color.y;edkEnd();
        ret.b=this->b-color.z;edkEnd();
        ret.a=this->a-color.w;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(edk::uint8 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        ret.a=this->a-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(edk::uint16 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        ret.a=this->a-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(edk::uint32 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        ret.a=this->a-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(edk::uint64 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        ret.a=this->a-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(edk::int8 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        ret.a=this->a-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(edk::int16 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        ret.a=this->a-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(edk::int32 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        ret.a=this->a-(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator-(edk::int64 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r-(edk::uint8)n;edkEnd();
        ret.g=this->g-(edk::uint8)n;edkEnd();
        ret.b=this->b-(edk::uint8)n;edkEnd();
        ret.a=this->a-(edk::uint8)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::color4ui8 color){
        //
        this->r-=color.r;edkEnd();
        this->g-=color.g;edkEnd();
        this->b-=color.b;edkEnd();
        this->a-=color.a;edkEnd();
    }
    void operator-=(vec4i8 color){
        //
        this->r-=color.x;edkEnd();
        this->g-=color.y;edkEnd();
        this->b-=color.z;edkEnd();
        this->a-=color.w;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
        this->a-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
        this->a-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
        this->a-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
        this->a-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
        this->a-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
        this->a-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
        this->a-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->r-=(edk::uint8)n;edkEnd();
        this->g-=(edk::uint8)n;edkEnd();
        this->b-=(edk::uint8)n;edkEnd();
        this->a-=(edk::uint8)n;edkEnd();
    }

    //*
    edk::color4ui8 operator*(edk::color4ui8 color){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*color.r;edkEnd();
        ret.g=this->g*color.g;edkEnd();
        ret.b=this->b*color.b;edkEnd();
        ret.a=this->a*color.a;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(vec4i8 color){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*color.x;edkEnd();
        ret.g=this->g*color.y;edkEnd();
        ret.b=this->b*color.z;edkEnd();
        ret.a=this->a*color.w;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(edk::uint8 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        ret.a=this->a*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(edk::uint16 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        ret.a=this->a*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(edk::uint32 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        ret.a=this->a*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(edk::uint64 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        ret.a=this->a*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(edk::int8 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        ret.a=this->a*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(edk::int16 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        ret.a=this->a*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(edk::int32 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        ret.a=this->a*(edk::uint8)n;edkEnd();
        return ret;
    }
    edk::color4ui8 operator*(edk::int64 n){
        //
        edk::color4ui8 ret;edkEnd();
        ret.r=this->r*(edk::uint8)n;edkEnd();
        ret.g=this->g*(edk::uint8)n;edkEnd();
        ret.b=this->b*(edk::uint8)n;edkEnd();
        ret.a=this->a*(edk::uint8)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::color4ui8 color){
        //
        this->r*=color.r;edkEnd();
        this->g*=color.g;edkEnd();
        this->b*=color.b;edkEnd();
        this->a*=color.a;edkEnd();
    }
    void operator*=(vec4i8 color){
        //
        this->r*=color.x;edkEnd();
        this->g*=color.y;edkEnd();
        this->b*=color.z;edkEnd();
        this->a*=color.w;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
        this->a*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
        this->a*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
        this->a*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
        this->a*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
        this->a*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
        this->a*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
        this->a*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->r*=(edk::uint8)n;edkEnd();
        this->g*=(edk::uint8)n;edkEnd();
        this->b*=(edk::uint8)n;edkEnd();
        this->a*=(edk::uint8)n;edkEnd();
    }

    //++
    edk::color4ui8 operator++(){
        //
        ++this->r;edkEnd();
        ++this->g;edkEnd();
        ++this->b;edkEnd();
        ++this->a;edkEnd();
        return color4ui8(this->r,this->g,this->b,this->a);edkEnd();
    }
    edk::color4ui8 operator++(edk::int32){
        //
        this->r++;edkEnd();
        this->g++;edkEnd();
        this->b++;edkEnd();
        this->a++;edkEnd();
        return color4ui8(this->r,this->g,this->b,this->a);edkEnd();
    }

    //--
    edk::color4ui8 operator--(){
        //
        --this->r;edkEnd();
        --this->g;edkEnd();
        --this->b;edkEnd();
        --this->a;edkEnd();
        return color4ui8(this->r,this->g,this->b,this->a);edkEnd();
    }
    edk::color4ui8 operator--(edk::int32){
        //
        this->r--;edkEnd();
        this->g--;edkEnd();
        this->b--;edkEnd();
        this->a--;edkEnd();
        return color4ui8(this->r,this->g,this->b,this->a);edkEnd();
    }

    //
    edk::color4ui8 operator()(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b,(edk::uint8)this->a);edkEnd();
    }
    edk::color4ui8 operator()(edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b,(edk::uint8)this->a);edkEnd();
    }
    edk::color4ui8 operator()(edk::uint32 r,edk::uint32 g,edk::uint32 b,edk::uint32 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b,(edk::uint8)this->a);edkEnd();
    }
    edk::color4ui8 operator()(edk::uint64 r,edk::uint64 g,edk::uint64 b,edk::uint64 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b,(edk::uint8)this->a);edkEnd();
    }
    edk::color4ui8 operator()(edk::int8 r,edk::int8 g,edk::int8 b,edk::int8 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b,(edk::uint8)this->a);edkEnd();
    }
    edk::color4ui8 operator()(edk::int16 r,edk::int16 g,edk::int16 b,edk::int16 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b,(edk::uint8)this->a);edkEnd();
    }
    edk::color4ui8 operator()(edk::int32 r,edk::int32 g,edk::int32 b,edk::int32 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b,(edk::uint8)this->a);edkEnd();
    }
    edk::color4ui8 operator()(edk::int64 r,edk::int64 g,edk::int64 b,edk::int64 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4ui8((edk::uint8)this->r,(edk::uint8)this->g,(edk::uint8)this->b,(edk::uint8)this->a);edkEnd();
    }
};


//color3f32
class color3f32{
    //
public:
    edk::float32 r,g,b;

    //CONSTRUTOR
    color3f32(){
        //bera as variaveis
        this->r=this->g=this->b=1.0f;edkEnd();
    }
    color3f32(edk::float32 r,edk::float32 g,edk::float32 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::float64 r,edk::float64 g,edk::float64 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::int8 r,edk::int8 g,edk::int8 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::int16 r,edk::int16 g,edk::int16 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::int32 r,edk::int32 g,edk::int32 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::int64 r,edk::int64 g,edk::int64 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::uint8 r,edk::uint8 g,edk::uint8 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::uint16 r,edk::uint16 g,edk::uint16 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::uint32 r,edk::uint32 g,edk::uint32 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    color3f32(edk::uint64 r,edk::uint64 g,edk::uint64 b){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
    }
    //color3ui8
    color3f32(edk::color3ui8 color){
        //bera as variaveis
        this->r=(edk::float32)color.r/255.f;edkEnd();
        this->g=(edk::float32)color.g/255.f;edkEnd();
        this->b=(edk::float32)color.b/255.f;edkEnd();
    }
    //operators

    //=
    edk::color3f32 operator=(edk::color3ui8 color){
        //bera as variaveis
        this->r=((edk::float32)color.r/255.f);edkEnd();
        this->g=((edk::float32)color.g/255.f);edkEnd();
        this->b=((edk::float32)color.b/255.f);edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::color3f32 color){
        //
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(vec2i8 color){
        //
        this->r=color.x;edkEnd();
        this->g=color.y;edkEnd();
        this->b=(edk::float32)0;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::float32 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::float64 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::int8 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::int16 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::int32 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::int64 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::uint8 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::uint16 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::uint32 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f32 operator=(edk::uint64 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::color3f32 color){
        //
        return (this->r==color.r&&this->g==color.g&&this->b==color.b);edkEnd();
    }
    //!=
    bool operator!=(edk::color3f32 color){
        //
        return (this->r!=color.r||this->g!=color.g||this->b!=color.b);edkEnd();
    }

    //+
    edk::color3f32 operator+(edk::color3ui8 color){
        //bera as variaveis
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g+((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b+((edk::float32)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::color3f32 color){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+color.r;edkEnd();
        ret.g=this->g+color.g;edkEnd();
        ret.b=this->b+color.b;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(vec2i8 color){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+color.x;edkEnd();
        ret.g=this->g+color.y;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::float32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::float64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::int8 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::int16 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::int32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::int64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::uint8 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::uint16 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::uint32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator+(edk::uint64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::color3ui8 color){
        //bera as variaveis
        this->r+=((edk::float32)color.r/255.f);edkEnd();
        this->g+=((edk::float32)color.g/255.f);edkEnd();
        this->b+=((edk::float32)color.b/255.f);edkEnd();
    }
    void operator+=(edk::color3f32 color){
        //
        this->r+=color.r;edkEnd();
        this->g+=color.g;edkEnd();
        this->b+=color.b;edkEnd();
    }
    void operator+=(vec2i8 color){
        //
        this->r+=color.x;edkEnd();
        this->g+=color.y;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
    }

    //-
    edk::color3f32 operator-(edk::color3ui8 color){
        //bera as variaveis
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g-((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b-((edk::float32)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::color3f32 color){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-color.r;edkEnd();
        ret.g=this->g-color.g;edkEnd();
        ret.b=this->b-color.b;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(vec2i8 color){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-color.x;edkEnd();
        ret.g=this->g-color.y;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::float32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::float64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::int8 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::int16 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::int32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::int64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::uint8 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::uint16 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::uint32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator-(edk::uint64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::color3ui8 color){
        //bera as variaveis
        this->r-=((edk::float32)color.r/255.f);edkEnd();
        this->g-=((edk::float32)color.g/255.f);edkEnd();
        this->b-=((edk::float32)color.b/255.f);edkEnd();
    }
    void operator-=(edk::color3f32 color){
        //
        this->r-=color.r;edkEnd();
        this->g-=color.g;edkEnd();
        this->b-=color.b;edkEnd();
    }
    void operator-=(vec2i8 color){
        //
        this->r-=color.x;edkEnd();
        this->g-=color.y;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
    }

    //*
    edk::color3f32 operator*(edk::color3ui8 color){
        //bera as variaveis
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g*((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b*((edk::float32)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::color3f32 color){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*color.r;edkEnd();
        ret.g=this->g*color.g;edkEnd();
        ret.b=this->b*color.b;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(vec2i8 color){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*color.x;edkEnd();
        ret.g=this->g*color.y;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::float32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::float64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::int8 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::int16 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::int32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::int64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::uint8 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::uint16 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::uint32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator*(edk::uint64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::color3ui8 color){
        //bera as variaveis
        this->r*=((edk::float32)color.r/255.f);edkEnd();
        this->g*=((edk::float32)color.g/255.f);edkEnd();
        this->b*=((edk::float32)color.b/255.f);edkEnd();
    }
    void operator*=(edk::color3f32 color){
        //
        this->r*=color.r;edkEnd();
        this->g*=color.g;edkEnd();
        this->b*=color.b;edkEnd();
    }
    void operator*=(vec2i8 color){
        //
        this->r*=color.x;edkEnd();
        this->g*=color.y;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
    }

    // /
    edk::color3f32 operator/(edk::color3ui8 color){
        //bera as variaveis
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g/((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b/((edk::float32)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::color3f32 color){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/color.r;edkEnd();
        ret.g=this->g/color.g;edkEnd();
        ret.b=this->b/color.b;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(vec2i8 color){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/color.x;edkEnd();
        ret.g=this->g/color.y;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::float32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::float64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::int8 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::int16 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::int32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::int64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::uint8 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::uint16 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::uint32 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color3f32 operator/(edk::uint64 n){
        //
        edk::color3f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        return ret;
    }

    // /=
    void operator/=(edk::color3ui8 color){
        //bera as variaveis
        this->r/=((edk::float32)color.r/255.f);edkEnd();
        this->g/=((edk::float32)color.g/255.f);edkEnd();
        this->b/=((edk::float32)color.b/255.f);edkEnd();
    }
    void operator/=(edk::color3f32 color){
        //
        this->r/=color.r;edkEnd();
        this->g/=color.g;edkEnd();
        this->b/=color.b;edkEnd();
    }
    void operator/=(vec2i8 color){
        //
        this->r/=color.x;edkEnd();
        this->g/=color.y;edkEnd();
    }
    void operator/=(edk::float32 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::float64 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int8 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int16 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int32 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int64 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint8 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint16 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint32 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint64 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
    }

    //++
    edk::color3f32 operator++(){
        //
        ++this->r;edkEnd();
        ++this->g;edkEnd();
        ++this->b;edkEnd();
        return color3f32(this->r,this->g,this->b);edkEnd();
    }
    edk::color3f32 operator++(edk::int32){
        //
        this->r++;edkEnd();
        this->g++;edkEnd();
        this->b++;edkEnd();
        return color3f32(this->r,this->g,this->b);edkEnd();
    }

    //--
    edk::color3f32 operator--(){
        //
        --this->r;edkEnd();
        --this->g;edkEnd();
        --this->b;edkEnd();
        return color3f32(this->r,this->g,this->b);edkEnd();
    }
    edk::color3f32 operator--(edk::int32){
        //
        this->r--;edkEnd();
        this->g--;edkEnd();
        this->b--;edkEnd();
        return color3f32(this->r,this->g,this->b);edkEnd();
    }

    //
    edk::color3f32 operator()(edk::float32 r,edk::float32 g,edk::float32 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::float64 r,edk::float64 g,edk::float64 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::int8 r,edk::int8 g,edk::int8 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::int16 r,edk::int16 g,edk::int16 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::int32 r,edk::int32 g,edk::int32 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::int64 r,edk::int64 g,edk::int64 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::uint8 r,edk::uint8 g,edk::uint8 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::uint16 r,edk::uint16 g,edk::uint16 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::uint32 r,edk::uint32 g,edk::uint32 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
    edk::color3f32 operator()(edk::uint64 r,edk::uint64 g,edk::uint64 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);edkEnd();
    }
};

//color3f64
class color3f64{
    //
public:
    edk::float64 r,g,b;

    //CONSTRUTOR
    color3f64(){
        //bera as variaveis
        this->r=this->g=this->b=1.0f;edkEnd();
    }
    color3f64(edk::float32 r,edk::float32 g,edk::float32 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::float64 r,edk::float64 g,edk::float64 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::int8 r,edk::int8 g,edk::int8 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::int16 r,edk::int16 g,edk::int16 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::int32 r,edk::int32 g,edk::int32 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::int64 r,edk::int64 g,edk::int64 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::uint8 r,edk::uint8 g,edk::uint8 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::uint16 r,edk::uint16 g,edk::uint16 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::uint32 r,edk::uint32 g,edk::uint32 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    color3f64(edk::uint64 r,edk::uint64 g,edk::uint64 b){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
    }
    //color3ui8
    color3f64(edk::color3ui8 color){
        //bera as variaveis
        this->r=(edk::float64)color.r/255.f;edkEnd();
        this->g=(edk::float64)color.g/255.f;edkEnd();
        this->b=(edk::float64)color.b/255.f;edkEnd();
    }

    //operators

    //=
    edk::color3f64 operator=(edk::color3ui8 color){
        //bera as variaveis
        this->r=((edk::float64)color.r/255.f);edkEnd();
        this->g=((edk::float64)color.g/255.f);edkEnd();
        this->b=((edk::float64)color.b/255.f);edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::color3f64 color){
        //
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(vec2i8 color){
        //
        this->r=color.x;edkEnd();
        this->g=color.y;edkEnd();
        this->b=(edk::float64)0;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::float32 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::float64 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::int8 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::int16 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::int32 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::int64 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::uint8 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::uint16 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::uint32 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color3f64 operator=(edk::uint64 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::color3f64 color){
        //
        return (this->r==color.r&&this->g==color.g&&this->b==color.b);edkEnd();
    }
    //!=
    bool operator!=(edk::color3f64 color){
        //
        return (this->r!=color.r||this->g!=color.g||this->b!=color.b);edkEnd();
    }

    //+
    edk::color3f64 operator+(edk::color3ui8 color){
        //bera as variaveis
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g+((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b+((edk::float64)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::color3f64 color){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+color.r;edkEnd();
        ret.g=this->g+color.g;edkEnd();
        ret.b=this->b+color.b;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(vec2i8 color){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+color.x;edkEnd();
        ret.g=this->g+color.y;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::float32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::float64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::int8 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::int16 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::int32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::int64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::uint8 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::uint16 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::uint32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator+(edk::uint64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::color3ui8 color){
        //bera as variaveis
        this->r+=((edk::float64)color.r/255.f);edkEnd();
        this->g+=((edk::float64)color.g/255.f);edkEnd();
        this->b+=((edk::float64)color.b/255.f);edkEnd();
    }
    void operator+=(edk::color3f64 color){
        //
        this->r+=color.r;edkEnd();
        this->g+=color.g;edkEnd();
        this->b+=color.b;edkEnd();
    }
    void operator+=(vec2i8 color){
        //
        this->r+=color.x;edkEnd();
        this->g+=color.y;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
    }

    //-
    edk::color3f64 operator-(edk::color3ui8 color){
        //bera as variaveis
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g-((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b-((edk::float64)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::color3f64 color){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-color.r;edkEnd();
        ret.g=this->g-color.g;edkEnd();
        ret.b=this->b-color.b;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(vec2i8 color){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-color.x;edkEnd();
        ret.g=this->g-color.y;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::float32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::float64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::int8 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::int16 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::int32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::int64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::uint8 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::uint16 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::uint32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator-(edk::uint64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::color3ui8 color){
        //bera as variaveis
        this->r-=((edk::float64)color.r/255.f);edkEnd();
        this->g-=((edk::float64)color.g/255.f);edkEnd();
        this->b-=((edk::float64)color.b/255.f);edkEnd();
    }
    void operator-=(edk::color3f64 color){
        //
        this->r-=color.r;edkEnd();
        this->g-=color.g;edkEnd();
        this->b-=color.b;edkEnd();
    }
    void operator-=(vec2i8 color){
        //
        this->r-=color.x;edkEnd();
        this->g-=color.y;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
    }

    //*
    edk::color3f64 operator*(edk::color3ui8 color){
        //bera as variaveis
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g*((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b*((edk::float64)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::color3f64 color){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*color.r;edkEnd();
        ret.g=this->g*color.g;edkEnd();
        ret.b=this->b*color.b;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(vec2i8 color){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*color.x;edkEnd();
        ret.g=this->g*color.y;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::float32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::float64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::int8 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::int16 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::int32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::int64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::uint8 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::uint16 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::uint32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator*(edk::uint64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::color3ui8 color){
        //bera as variaveis
        this->r*=((edk::float64)color.r/255.f);edkEnd();
        this->g*=((edk::float64)color.g/255.f);edkEnd();
        this->b*=((edk::float64)color.b/255.f);edkEnd();
    }
    void operator*=(edk::color3f64 color){
        //
        this->r*=color.r;edkEnd();
        this->g*=color.g;edkEnd();
        this->b*=color.b;edkEnd();
    }
    void operator*=(vec2i8 color){
        //
        this->r*=color.x;edkEnd();
        this->g*=color.y;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
    }

    // /
    edk::color3f64 operator/(edk::color3ui8 color){
        //bera as variaveis
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g/((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b/((edk::float64)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::color3f64 color){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/color.r;edkEnd();
        ret.g=this->g/color.g;edkEnd();
        ret.b=this->b/color.b;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(vec2i8 color){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/color.x;edkEnd();
        ret.g=this->g/color.y;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::float32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::float64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::int8 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::int16 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::int32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::int64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::uint8 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::uint16 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::uint32 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color3f64 operator/(edk::uint64 n){
        //
        edk::color3f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        return ret;
    }

    // /=
    void operator/=(edk::color3ui8 color){
        //bera as variaveis
        this->r/=((edk::float64)color.r/255.f);edkEnd();
        this->g/=((edk::float64)color.g/255.f);edkEnd();
        this->b/=((edk::float64)color.b/255.f);edkEnd();
    }
    void operator/=(edk::color3f64 color){
        //
        this->r/=color.r;edkEnd();
        this->g/=color.g;edkEnd();
        this->b/=color.b;edkEnd();
    }
    void operator/=(vec2i8 color){
        //
        this->r/=color.x;edkEnd();
        this->g/=color.y;edkEnd();
    }
    void operator/=(edk::float32 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::float64 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int8 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int16 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int32 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int64 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint8 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint16 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint32 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint64 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
    }

    //++
    edk::color3f64 operator++(){
        //
        ++this->r;edkEnd();
        ++this->g;edkEnd();
        ++this->b;edkEnd();
        return color3f64(this->r,this->g,this->b);edkEnd();
    }
    edk::color3f64 operator++(edk::int32){
        //
        this->r++;edkEnd();
        this->g++;edkEnd();
        this->b++;edkEnd();
        return color3f64(this->r,this->g,this->b);edkEnd();
    }

    //--
    edk::color3f64 operator--(){
        //
        --this->r;edkEnd();
        --this->g;edkEnd();
        --this->b;edkEnd();
        return color3f64(this->r,this->g,this->b);edkEnd();
    }
    edk::color3f64 operator--(edk::int32){
        //
        this->r--;edkEnd();
        this->g--;edkEnd();
        this->b--;edkEnd();
        return color3f64(this->r,this->g,this->b);edkEnd();
    }

    //
    edk::color3f64 operator()(edk::float32 r,edk::float32 g,edk::float32 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::float64 r,edk::float64 g,edk::float64 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::int8 r,edk::int8 g,edk::int8 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::int16 r,edk::int16 g,edk::int16 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::int32 r,edk::int32 g,edk::int32 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::int64 r,edk::int64 g,edk::int64 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::uint8 r,edk::uint8 g,edk::uint8 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::uint16 r,edk::uint16 g,edk::uint16 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::uint32 r,edk::uint32 g,edk::uint32 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
    edk::color3f64 operator()(edk::uint64 r,edk::uint64 g,edk::uint64 b){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);edkEnd();
    }
};

//color4f32
class color4f32{
    //
public:
    edk::float32 r,g,b,a;

    //CONSTRUTOR
    color4f32(){
        //bera as variaveis
        this->r=this->g=this->b=this->a=1.f;edkEnd();
    }
    color4f32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::int8 r,edk::int8 g,edk::int8 b,edk::int8 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::int16 r,edk::int16 g,edk::int16 b,edk::int16 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::int32 r,edk::int32 g,edk::int32 b,edk::int32 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::int64 r,edk::int64 g,edk::int64 b,edk::int64 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::uint32 r,edk::uint32 g,edk::uint32 b,edk::uint32 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::uint64 r,edk::uint64 g,edk::uint64 b,edk::uint64 a){
        //bera as variaveis
        this->r=(edk::float32)r;edkEnd();
        this->g=(edk::float32)g;edkEnd();
        this->b=(edk::float32)b;edkEnd();
        this->a=(edk::float32)a;edkEnd();
    }
    color4f32(edk::color3ui8 color){
        //bera as variaveis
        this->r=((edk::float32)color.r/255.f);edkEnd();
        this->g=((edk::float32)color.g/255.f);edkEnd();
        this->b=((edk::float32)color.b/255.f);edkEnd();
        this->a=((edk::float32)1.f);edkEnd();
    }
    color4f32(edk::color4ui8 color){
        //bera as variaveis
        this->r=((edk::float32)color.r/255.f);edkEnd();
        this->g=((edk::float32)color.g/255.f);edkEnd();
        this->b=((edk::float32)color.b/255.f);edkEnd();
        this->a=((edk::float32)color.a/255.f);edkEnd();
    }
    //operators

    //=
    edk::color4f32 operator=(edk::color3ui8 color){
        //bera as variaveis
        this->r=((edk::float32)color.r/255.f);edkEnd();
        this->g=((edk::float32)color.g/255.f);edkEnd();
        this->b=((edk::float32)color.b/255.f);edkEnd();
        this->a=1.f;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::color4ui8 color){
        //bera as variaveis
        this->r=((edk::float32)color.r/255.f);edkEnd();
        this->g=((edk::float32)color.g/255.f);edkEnd();
        this->b=((edk::float32)color.b/255.f);edkEnd();
        this->a=((edk::float32)color.a/255.f);edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::color4f32 color){
        //
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        this->a=color.a;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::color3f32 color){
        //
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(vec3i8 color){
        //
        this->r=color.x;edkEnd();
        this->g=color.y;edkEnd();
        this->b=color.z;edkEnd();
        this->a=0;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(vec2i8 color){
        //
        this->r=color.x;edkEnd();
        this->g=color.y;edkEnd();
        this->b=0;edkEnd();
        this->a=0;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::float32 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::float64 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::int8 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::int16 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::int32 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::int64 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::uint8 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::uint16 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::uint32 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f32 operator=(edk::uint64 n){
        //
        this->r=(edk::float32)n;edkEnd();
        this->g=(edk::float32)n;edkEnd();
        this->b=(edk::float32)n;edkEnd();
        this->a=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::color4f32 color){
        //
        return (this->r==color.r&&this->g==color.g&&this->b==color.b&&this->a==color.a);edkEnd();
    }
    //!=
    bool operator!=(edk::color4f32 color){
        //
        return (this->r!=color.r||this->g!=color.g||this->b!=color.b||this->a!=color.a);edkEnd();
    }

    //+
    edk::color4f32 operator+(edk::color3ui8 color){
        //bera as variaveis
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g+((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b+((edk::float32)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::color4ui8 color){
        //bera as variaveis
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g+((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b+((edk::float32)color.b/255.f);edkEnd();
        ret.a=this->a+((edk::float32)color.a/255.f);edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::color4f32 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+color.r;edkEnd();
        ret.g=this->g+color.g;edkEnd();
        ret.b=this->b+color.b;edkEnd();
        ret.a=this->a+color.a;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(vec3i8 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+color.x;edkEnd();
        ret.g=this->g+color.y;edkEnd();
        ret.b=this->b+color.z;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(vec2i8 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+color.x;edkEnd();
        ret.g=this->g+color.y;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::float32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::float64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::int8 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::int16 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::int32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::int64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::uint8 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::uint16 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::uint32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator+(edk::uint64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r+(edk::float32)n;edkEnd();
        ret.g=this->g+(edk::float32)n;edkEnd();
        ret.b=this->b+(edk::float32)n;edkEnd();
        ret.a=this->a+(edk::float32)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::color3ui8 color){
        //bera as variaveis
        this->r+=((edk::float32)color.r/255.f);edkEnd();
        this->g+=((edk::float32)color.g/255.f);edkEnd();
        this->b+=((edk::float32)color.b/255.f);edkEnd();
    }
    void operator+=(edk::color4ui8 color){
        //bera as variaveis
        this->r+=((edk::float32)color.r/255.f);edkEnd();
        this->g+=((edk::float32)color.g/255.f);edkEnd();
        this->b+=((edk::float32)color.b/255.f);edkEnd();
        this->a+=((edk::float32)color.a/255.f);edkEnd();
    }
    void operator+=(edk::color4f32 color){
        //
        this->r+=color.r;edkEnd();
        this->g+=color.g;edkEnd();
        this->b+=color.b;edkEnd();
        this->a+=color.a;edkEnd();
    }
    void operator+=(vec3i8 color){
        //
        this->r+=color.x;edkEnd();
        this->g+=color.y;edkEnd();
        this->b+=color.z;edkEnd();
    }
    void operator+=(vec2i8 color){
        //
        this->r+=color.x;edkEnd();
        this->g+=color.y;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->r+=(edk::float32)n;edkEnd();
        this->g+=(edk::float32)n;edkEnd();
        this->b+=(edk::float32)n;edkEnd();
        this->a+=(edk::float32)n;edkEnd();
    }

    //-
    edk::color4f32 operator-(edk::color3ui8 color){
        //bera as variaveis
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g-((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b-((edk::float32)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::color4ui8 color){
        //bera as variaveis
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g-((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b-((edk::float32)color.b/255.f);edkEnd();
        ret.a=this->a-((edk::float32)color.a/255.f);edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::color4f32 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-color.r;edkEnd();
        ret.g=this->g-color.g;edkEnd();
        ret.b=this->b-color.b;edkEnd();
        ret.a=this->a-color.a;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(vec3i8 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-color.x;edkEnd();
        ret.g=this->g-color.y;edkEnd();
        ret.b=this->b-color.z;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(vec2i8 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-color.x;edkEnd();
        ret.g=this->g-color.y;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::float32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::float64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::int8 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::int16 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::int32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::int64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::uint8 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::uint16 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::uint32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator-(edk::uint64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r-(edk::float32)n;edkEnd();
        ret.g=this->g-(edk::float32)n;edkEnd();
        ret.b=this->b-(edk::float32)n;edkEnd();
        ret.a=this->a-(edk::float32)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::color3ui8 color){
        //bera as variaveis
        this->r+=((edk::float32)color.r/255.f);edkEnd();
        this->g+=((edk::float32)color.g/255.f);edkEnd();
        this->b+=((edk::float32)color.b/255.f);edkEnd();
    }
    void operator-=(edk::color4ui8 color){
        //bera as variaveis
        this->r+=((edk::float32)color.r/255.f);edkEnd();
        this->g+=((edk::float32)color.g/255.f);edkEnd();
        this->b+=((edk::float32)color.b/255.f);edkEnd();
        this->a+=((edk::float32)color.a/255.f);edkEnd();
    }
    void operator-=(edk::color4f32 color){
        //
        this->r-=color.r;edkEnd();
        this->g-=color.g;edkEnd();
        this->b-=color.b;edkEnd();
        this->a-=color.a;edkEnd();
    }
    void operator-=(vec3i8 color){
        //
        this->r-=color.x;edkEnd();
        this->g-=color.y;edkEnd();
        this->b-=color.z;edkEnd();
    }
    void operator-=(vec2i8 color){
        //
        this->r-=color.x;edkEnd();
        this->g-=color.y;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->r-=(edk::float32)n;edkEnd();
        this->g-=(edk::float32)n;edkEnd();
        this->b-=(edk::float32)n;edkEnd();
        this->a-=(edk::float32)n;edkEnd();
    }

    //*
    edk::color4f32 operator*(edk::color3ui8 color){
        //bera as variaveis
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g*((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b*((edk::float32)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::color4ui8 color){
        //bera as variaveis
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g*((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b*((edk::float32)color.b/255.f);edkEnd();
        ret.a=this->a*((edk::float32)color.a/255.f);edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::color4f32 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*color.r;edkEnd();
        ret.g=this->g*color.g;edkEnd();
        ret.b=this->b*color.b;edkEnd();
        ret.a=this->a*color.a;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(vec3i8 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*color.x;edkEnd();
        ret.g=this->g*color.y;edkEnd();
        ret.b=this->b*color.z;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(vec2i8 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*color.x;edkEnd();
        ret.g=this->g*color.y;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::float32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::float64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::int8 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::int16 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::int32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::int64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::uint8 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::uint16 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::uint32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator*(edk::uint64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r*(edk::float32)n;edkEnd();
        ret.g=this->g*(edk::float32)n;edkEnd();
        ret.b=this->b*(edk::float32)n;edkEnd();
        ret.a=this->a*(edk::float32)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::color3ui8 color){
        //bera as variaveis
        this->r*=((edk::float32)color.r/255.f);edkEnd();
        this->g*=((edk::float32)color.g/255.f);edkEnd();
        this->b*=((edk::float32)color.b/255.f);edkEnd();
    }
    void operator*=(edk::color4ui8 color){
        //bera as variaveis
        this->r*=((edk::float32)color.r/255.f);edkEnd();
        this->g*=((edk::float32)color.g/255.f);edkEnd();
        this->b*=((edk::float32)color.b/255.f);edkEnd();
        this->a*=((edk::float32)color.a/255.f);edkEnd();
    }
    void operator*=(edk::color4f32 color){
        //
        this->r*=color.r;edkEnd();
        this->g*=color.g;edkEnd();
        this->b*=color.b;edkEnd();
        this->a*=color.a;edkEnd();
    }
    void operator*=(vec3i8 color){
        //
        this->r*=color.x;edkEnd();
        this->g*=color.y;edkEnd();
        this->b*=color.z;edkEnd();
    }
    void operator*=(vec2i8 color){
        //
        this->r*=color.x;edkEnd();
        this->g*=color.y;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->r*=(edk::float32)n;edkEnd();
        this->g*=(edk::float32)n;edkEnd();
        this->b*=(edk::float32)n;edkEnd();
        this->a*=(edk::float32)n;edkEnd();
    }

    // /
    edk::color4f32 operator/(edk::color3ui8 color){
        //bera as variaveis
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g/((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b/((edk::float32)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::color4ui8 color){
        //bera as variaveis
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/((edk::float32)color.r/255.f);edkEnd();
        ret.g=this->g/((edk::float32)color.g/255.f);edkEnd();
        ret.b=this->b/((edk::float32)color.b/255.f);edkEnd();
        ret.a=this->a/((edk::float32)color.a/255.f);edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::color4f32 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/color.r;edkEnd();
        ret.g=this->g/color.g;edkEnd();
        ret.b=this->b/color.b;edkEnd();
        ret.a=this->a/color.a;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(vec3i8 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/color.x;edkEnd();
        ret.g=this->g/color.y;edkEnd();
        ret.b=this->b/color.z;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(vec2i8 color){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/color.x;edkEnd();
        ret.g=this->g/color.y;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::float32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::float64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::int8 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::int16 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::int32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::int64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::uint8 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::uint16 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::uint32 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }
    edk::color4f32 operator/(edk::uint64 n){
        //
        edk::color4f32 ret;edkEnd();
        ret.r=this->r/(edk::float32)n;edkEnd();
        ret.g=this->g/(edk::float32)n;edkEnd();
        ret.b=this->b/(edk::float32)n;edkEnd();
        ret.a=this->a/(edk::float32)n;edkEnd();
        return ret;
    }

    // /=
    void operator/=(edk::color3ui8 color){
        //bera as variaveis
        this->r*=((edk::float32)color.r/255.f);edkEnd();
        this->g*=((edk::float32)color.g/255.f);edkEnd();
        this->b*=((edk::float32)color.b/255.f);edkEnd();
    }
    void operator/=(edk::color4ui8 color){
        //bera as variaveis
        this->r/=((edk::float32)color.r/255.f);edkEnd();
        this->g/=((edk::float32)color.g/255.f);edkEnd();
        this->b/=((edk::float32)color.b/255.f);edkEnd();
        this->a/=((edk::float32)color.a/255.f);edkEnd();
    }
    void operator/=(edk::color4f32 color){
        //
        this->r/=color.r;edkEnd();
        this->g/=color.g;edkEnd();
        this->b/=color.b;edkEnd();
        this->a/=color.a;edkEnd();
    }
    void operator/=(vec3i8 color){
        //
        this->r/=color.x;edkEnd();
        this->g/=color.y;edkEnd();
        this->b/=color.z;edkEnd();
    }
    void operator/=(vec2i8 color){
        //
        this->r/=color.x;edkEnd();
        this->g/=color.y;edkEnd();
    }
    void operator/=(edk::float32 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::float64 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int8 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int16 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int32 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int64 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint8 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint16 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint32 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint64 n){
        //
        this->r/=(edk::float32)n;edkEnd();
        this->g/=(edk::float32)n;edkEnd();
        this->b/=(edk::float32)n;edkEnd();
        this->a/=(edk::float32)n;edkEnd();
    }

    //++
    edk::color4f32 operator++(){
        //
        ++this->r;edkEnd();
        ++this->g;edkEnd();
        ++this->b;edkEnd();
        ++this->a;edkEnd();
        return color4f32(this->r,this->g,this->b,this->a);edkEnd();
    }
    edk::color4f32 operator++(edk::int32){
        //
        this->r++;edkEnd();
        this->g++;edkEnd();
        this->b++;edkEnd();
        this->a++;edkEnd();
        return color4f32(this->r,this->g,this->b,this->a);edkEnd();
    }

    //--
    edk::color4f32 operator--(){
        //
        --this->r;edkEnd();
        --this->g;edkEnd();
        --this->b;edkEnd();
        --this->a;edkEnd();
        return color4f32(this->r,this->g,this->b,this->a);edkEnd();
    }
    edk::color4f32 operator--(edk::int32){
        //
        this->r--;edkEnd();
        this->g--;edkEnd();
        this->b--;edkEnd();
        this->a--;edkEnd();
        return color4f32(this->r,this->g,this->b,this->a);edkEnd();
    }

    //
    edk::color4f32 operator()(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::int8 r,edk::int8 g,edk::int8 b,edk::int8 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::int16 r,edk::int16 g,edk::int16 b,edk::int16 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::int32 r,edk::int32 g,edk::int32 b,edk::int32 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::int64 r,edk::int64 g,edk::int64 b,edk::int64 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::uint32 r,edk::uint32 g,edk::uint32 b,edk::uint32 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
    edk::color4f32 operator()(edk::uint64 r,edk::uint64 g,edk::uint64 b,edk::uint64 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);edkEnd();
    }
};

//color4f64
class color4f64{
    //
public:
    edk::float64 r,g,b,a;

    //CONSTRUTOR
    color4f64(){
        //bera as variaveis
        this->r=this->g=this->b=this->a=1.0f;edkEnd();
    }
    color4f64(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::int8 r,edk::int8 g,edk::int8 b,edk::int8 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::int16 r,edk::int16 g,edk::int16 b,edk::int16 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::int32 r,edk::int32 g,edk::int32 b,edk::int32 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::int64 r,edk::int64 g,edk::int64 b,edk::int64 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::uint32 r,edk::uint32 g,edk::uint32 b,edk::uint32 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::uint64 r,edk::uint64 g,edk::uint64 b,edk::uint64 a){
        //bera as variaveis
        this->r=(edk::float64)r;edkEnd();
        this->g=(edk::float64)g;edkEnd();
        this->b=(edk::float64)b;edkEnd();
        this->a=(edk::float64)a;edkEnd();
    }
    color4f64(edk::color3ui8 color){
        //bera as variaveis
        this->r=(edk::float64)color.r/255.f;edkEnd();
        this->g=(edk::float64)color.g/255.f;edkEnd();
        this->b=(edk::float64)color.b/255.f;edkEnd();
        this->a=(edk::float64)1.f;edkEnd();
    }
    color4f64(edk::color4ui8 color){
        //bera as variaveis
        this->r=(edk::float64)color.r/255.f;edkEnd();
        this->g=(edk::float64)color.g/255.f;edkEnd();
        this->b=(edk::float64)color.b/255.f;edkEnd();
        this->a=(edk::float64)color.a/255.f;edkEnd();
    }
    //operators
    //=
    edk::color4f64 operator=(edk::color3ui8 color){
        //bera as variaveis
        this->r=(edk::float64)color.r/255.f;edkEnd();
        this->g=(edk::float64)color.g/255.f;edkEnd();
        this->b=(edk::float64)color.b/255.f;edkEnd();
        this->a=(edk::float64)1.f;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::color4ui8 color){
        //bera as variaveis
        this->r=(edk::float64)color.r/255.f;edkEnd();
        this->g=(edk::float64)color.g/255.f;edkEnd();
        this->b=(edk::float64)color.b/255.f;edkEnd();
        this->a=(edk::float64)color.a/255.f;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::color4f64 color){
        //
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        this->a=color.a;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(vec3i8 color){
        //
        this->r=color.x;edkEnd();
        this->g=color.y;edkEnd();
        this->b=color.z;edkEnd();
        this->a=0;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(vec2i8 color){
        //
        this->r=color.x;edkEnd();
        this->g=color.y;edkEnd();
        this->b=0;edkEnd();
        this->a=0;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::float32 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::float64 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::int8 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::int16 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::int32 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::int64 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::uint8 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::uint16 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::uint32 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    edk::color4f64 operator=(edk::uint64 n){
        //
        this->r=(edk::float64)n;edkEnd();
        this->g=(edk::float64)n;edkEnd();
        this->b=(edk::float64)n;edkEnd();
        this->a=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::color4f64 color){
        //
        return (this->r==color.r&&this->g==color.g&&this->b==color.b&&this->a==color.a);edkEnd();
    }
    //!=
    bool operator!=(edk::color4f64 color){
        //
        return (this->r!=color.r||this->g!=color.g||this->b!=color.b||this->a!=color.a);edkEnd();
    }

    //+
    edk::color4f64 operator+(edk::color3ui8 color){
        //bera as variaveis
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g+((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b+((edk::float64)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::color4ui8 color){
        //bera as variaveis
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g+((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b+((edk::float64)color.b/255.f);edkEnd();
        ret.a=this->a+((edk::float64)color.a/255.f);edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::color4f64 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+color.r;edkEnd();
        ret.g=this->g+color.g;edkEnd();
        ret.b=this->b+color.b;edkEnd();
        ret.a=this->a+color.a;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(vec3i8 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+color.x;edkEnd();
        ret.g=this->g+color.y;edkEnd();
        ret.b=this->b+color.z;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(vec2i8 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+color.x;edkEnd();
        ret.g=this->g+color.y;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::float32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::float64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::int8 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::int16 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::int32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::int64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::uint8 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::uint16 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::uint32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator+(edk::uint64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+(edk::float64)n;edkEnd();
        ret.g=this->g+(edk::float64)n;edkEnd();
        ret.b=this->b+(edk::float64)n;edkEnd();
        ret.a=this->a+(edk::float64)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::color3ui8 color){
        //bera as variaveis
        this->r+=((edk::float64)color.r/255.f);edkEnd();
        this->g+=((edk::float64)color.g/255.f);edkEnd();
        this->b+=((edk::float64)color.b/255.f);edkEnd();
    }
    void operator+=(edk::color4ui8 color){
        //bera as variaveis
        this->r+=((edk::float64)color.r/255.f);edkEnd();
        this->g+=((edk::float64)color.g/255.f);edkEnd();
        this->b+=((edk::float64)color.b/255.f);edkEnd();
        this->a+=((edk::float64)color.a/255.f);edkEnd();
    }
    void operator+=(edk::color4f64 color){
        //
        this->r+=color.r;edkEnd();
        this->g+=color.g;edkEnd();
        this->b+=color.b;edkEnd();
        this->a+=color.a;edkEnd();
    }
    void operator+=(vec3i8 color){
        //
        this->r+=color.x;edkEnd();
        this->g+=color.y;edkEnd();
        this->b+=color.z;edkEnd();
    }
    void operator+=(vec2i8 color){
        //
        this->r+=color.x;edkEnd();
        this->g+=color.y;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->r+=(edk::float64)n;edkEnd();
        this->g+=(edk::float64)n;edkEnd();
        this->b+=(edk::float64)n;edkEnd();
        this->a+=(edk::float64)n;edkEnd();
    }

    //-
    edk::color4f64 operator-(edk::color3ui8 color){
        //bera as variaveis
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g+((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b+((edk::float64)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::color4ui8 color){
        //bera as variaveis
        edk::color4f64 ret;edkEnd();
        ret.r=this->r+((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g+((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b+((edk::float64)color.b/255.f);edkEnd();
        ret.a=this->a+((edk::float64)color.a/255.f);edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::color4f64 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-color.r;edkEnd();
        ret.g=this->g-color.g;edkEnd();
        ret.b=this->b-color.b;edkEnd();
        ret.a=this->a-color.a;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(vec3i8 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-color.x;edkEnd();
        ret.g=this->g-color.y;edkEnd();
        ret.b=this->b-color.z;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(vec2i8 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-color.x;edkEnd();
        ret.g=this->g-color.y;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::float32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::float64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::int8 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::int16 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::int32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::int64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::uint8 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::uint16 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::uint32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator-(edk::uint64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r-(edk::float64)n;edkEnd();
        ret.g=this->g-(edk::float64)n;edkEnd();
        ret.b=this->b-(edk::float64)n;edkEnd();
        ret.a=this->a-(edk::float64)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::color3ui8 color){
        //bera as variaveis
        this->r-=((edk::float64)color.r/255.f);edkEnd();
        this->g-=((edk::float64)color.g/255.f);edkEnd();
        this->b-=((edk::float64)color.b/255.f);edkEnd();
    }
    void operator-=(edk::color4ui8 color){
        //bera as variaveis
        this->r-=((edk::float64)color.r/255.f);edkEnd();
        this->g-=((edk::float64)color.g/255.f);edkEnd();
        this->b-=((edk::float64)color.b/255.f);edkEnd();
        this->a-=((edk::float64)color.a/255.f);edkEnd();
    }
    void operator-=(edk::color4f64 color){
        //
        this->r-=color.r;edkEnd();
        this->g-=color.g;edkEnd();
        this->b-=color.b;edkEnd();
        this->a-=color.a;edkEnd();
    }
    void operator-=(vec3i8 color){
        //
        this->r-=color.x;edkEnd();
        this->g-=color.y;edkEnd();
        this->b-=color.z;edkEnd();
    }
    void operator-=(vec2i8 color){
        //
        this->r-=color.x;edkEnd();
        this->g-=color.y;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->r-=(edk::float64)n;edkEnd();
        this->g-=(edk::float64)n;edkEnd();
        this->b-=(edk::float64)n;edkEnd();
        this->a-=(edk::float64)n;edkEnd();
    }

    //*
    edk::color4f64 operator*(edk::color3ui8 color){
        //bera as variaveis
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g*((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b*((edk::float64)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::color4ui8 color){
        //bera as variaveis
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g*((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b*((edk::float64)color.b/255.f);edkEnd();
        ret.a=this->a*((edk::float64)color.a/255.f);edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::color4f64 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*color.r;edkEnd();
        ret.g=this->g*color.g;edkEnd();
        ret.b=this->b*color.b;edkEnd();
        ret.a=this->a*color.a;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(vec3i8 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*color.x;edkEnd();
        ret.g=this->g*color.y;edkEnd();
        ret.b=this->b*color.z;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(vec2i8 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*color.x;edkEnd();
        ret.g=this->g*color.y;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::float32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::float64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::int8 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::int16 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::int32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::int64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::uint8 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::uint16 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::uint32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator*(edk::uint64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r*(edk::float64)n;edkEnd();
        ret.g=this->g*(edk::float64)n;edkEnd();
        ret.b=this->b*(edk::float64)n;edkEnd();
        ret.a=this->a*(edk::float64)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::color3ui8 color){
        //bera as variaveis
        this->r*=((edk::float64)color.r/255.f);edkEnd();
        this->g*=((edk::float64)color.g/255.f);edkEnd();
        this->b*=((edk::float64)color.b/255.f);edkEnd();
    }
    void operator*=(edk::color4ui8 color){
        //bera as variaveis
        this->r*=((edk::float64)color.r/255.f);edkEnd();
        this->g*=((edk::float64)color.g/255.f);edkEnd();
        this->b*=((edk::float64)color.b/255.f);edkEnd();
        this->a*=((edk::float64)color.a/255.f);edkEnd();
    }
    void operator*=(edk::color4f64 color){
        //
        this->r*=color.r;edkEnd();
        this->g*=color.g;edkEnd();
        this->b*=color.b;edkEnd();
        this->a*=color.a;edkEnd();
    }
    void operator*=(vec3i8 color){
        //
        this->r*=color.x;edkEnd();
        this->g*=color.y;edkEnd();
        this->b*=color.z;edkEnd();
    }
    void operator*=(vec2i8 color){
        //
        this->r*=color.x;edkEnd();
        this->g*=color.y;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->r*=(edk::float64)n;edkEnd();
        this->g*=(edk::float64)n;edkEnd();
        this->b*=(edk::float64)n;edkEnd();
        this->a*=(edk::float64)n;edkEnd();
    }

    // /
    edk::color4f64 operator/(edk::color3ui8 color){
        //bera as variaveis
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g/((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b/((edk::float64)color.b/255.f);edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::color4ui8 color){
        //bera as variaveis
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/((edk::float64)color.r/255.f);edkEnd();
        ret.g=this->g/((edk::float64)color.g/255.f);edkEnd();
        ret.b=this->b/((edk::float64)color.b/255.f);edkEnd();
        ret.a=this->a/((edk::float64)color.a/255.f);edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::color4f64 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/color.r;edkEnd();
        ret.g=this->g/color.g;edkEnd();
        ret.b=this->b/color.b;edkEnd();
        ret.a=this->a/color.a;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(vec3i8 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/color.x;edkEnd();
        ret.g=this->g/color.y;edkEnd();
        ret.b=this->b/color.z;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(vec2i8 color){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/color.x;edkEnd();
        ret.g=this->g/color.y;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::float32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::float64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::int8 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::int16 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::int32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::int64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::uint8 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::uint16 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::uint32 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }
    edk::color4f64 operator/(edk::uint64 n){
        //
        edk::color4f64 ret;edkEnd();
        ret.r=this->r/(edk::float64)n;edkEnd();
        ret.g=this->g/(edk::float64)n;edkEnd();
        ret.b=this->b/(edk::float64)n;edkEnd();
        ret.a=this->a/(edk::float64)n;edkEnd();
        return ret;
    }

    // /=
    void operator/=(edk::color3ui8 color){
        //bera as variaveis
        this->r/=((edk::float64)color.r/255.f);edkEnd();
        this->g/=((edk::float64)color.g/255.f);edkEnd();
        this->b/=((edk::float64)color.b/255.f);edkEnd();
    }
    void operator/=(edk::color4ui8 color){
        //bera as variaveis
        this->r/=((edk::float64)color.r/255.f);edkEnd();
        this->g/=((edk::float64)color.g/255.f);edkEnd();
        this->b/=((edk::float64)color.b/255.f);edkEnd();
        this->a/=((edk::float64)color.a/255.f);edkEnd();
    }
    void operator/=(edk::color4f64 color){
        //
        this->r/=color.r;edkEnd();
        this->g/=color.g;edkEnd();
        this->b/=color.b;edkEnd();
        this->a/=color.a;edkEnd();
    }
    void operator/=(vec3i8 color){
        //
        this->r/=color.x;edkEnd();
        this->g/=color.y;edkEnd();
        this->b/=color.z;edkEnd();
    }
    void operator/=(vec2i8 color){
        //
        this->r/=color.x;edkEnd();
        this->g/=color.y;edkEnd();
    }
    void operator/=(edk::float32 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::float64 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int8 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int16 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int32 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int64 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint8 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint16 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint32 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint64 n){
        //
        this->r/=(edk::float64)n;edkEnd();
        this->g/=(edk::float64)n;edkEnd();
        this->b/=(edk::float64)n;edkEnd();
        this->a/=(edk::float64)n;edkEnd();
    }

    //++
    edk::color4f64 operator++(){
        //
        ++this->r;edkEnd();
        ++this->g;edkEnd();
        ++this->b;edkEnd();
        ++this->a;edkEnd();
        return color4f64(this->r,this->g,this->b,this->a);edkEnd();
    }
    edk::color4f64 operator++(edk::int32){
        //
        this->r++;edkEnd();
        this->g++;edkEnd();
        this->b++;edkEnd();
        this->a++;edkEnd();
        return color4f64(this->r,this->g,this->b,this->a);edkEnd();
    }

    //--
    edk::color4f64 operator--(){
        //
        --this->r;edkEnd();
        --this->g;edkEnd();
        --this->b;edkEnd();
        --this->a;edkEnd();
        return color4f64(this->r,this->g,this->b,this->a);edkEnd();
    }
    edk::color4f64 operator--(edk::int32){
        //
        this->r--;edkEnd();
        this->g--;edkEnd();
        this->b--;edkEnd();
        this->a--;edkEnd();
        return color4f64(this->r,this->g,this->b,this->a);edkEnd();
    }

    //
    edk::color4f64 operator()(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::int8 r,edk::int8 g,edk::int8 b,edk::int8 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::int16 r,edk::int16 g,edk::int16 b,edk::int16 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::int32 r,edk::int32 g,edk::int32 b,edk::int32 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::int64 r,edk::int64 g,edk::int64 b,edk::int64 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::uint32 r,edk::uint32 g,edk::uint32 b,edk::uint32 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
    edk::color4f64 operator()(edk::uint64 r,edk::uint64 g,edk::uint64 b,edk::uint64 a){
        //
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
        return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);edkEnd();
    }
};

}

#endif // TYPECOLOR_H
