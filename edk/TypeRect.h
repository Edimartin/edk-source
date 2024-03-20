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
#pragma message "Inside TypeRect"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeVec2.h"
#include "TypeSize2.h"

#ifdef printMessages
#pragma message "    Compiling TypeRect"
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
    recti8(edk::vec2i8 origin,edk::size2i8 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
    }
    recti8(edk::vec2i16 origin,edk::size2i16 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
    }
    recti8(edk::vec2i32 origin,edk::size2i32 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
    }
    recti8(edk::vec2i64 origin,edk::size2i64 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
    }
    recti8(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
    }
    recti8(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
    }
    recti8(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
    }
    recti8(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
    }

    //operators
    inline edk::recti8 operator=(edk::recti8 rect){
        //
        this->origin.x=(edk::int8)rect.origin.x;
        this->origin.y=(edk::int8)rect.origin.y;
        this->size.width=(edk::int8)rect.size.width;
        this->size.height=(edk::int8)rect.size.height;
        return *this;
    }
    inline edk::recti8 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    inline edk::recti8 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    inline edk::recti8 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    inline edk::recti8 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    inline edk::recti8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    inline edk::recti8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    inline edk::recti8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    inline edk::recti8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }

    inline bool operator==(edk::recti8 rect){
        //
        return (this->origin.x==(edk::int8)rect.origin.x
                &&this->origin.y==(edk::int8)rect.origin.y
                &&this->size.width==(edk::int8)rect.size.width
                &&this->size.height==(edk::int8)rect.size.height
                );
    }
    inline bool operator!=(edk::recti8 rect){
        //
        return (this->origin.x!=(edk::int8)rect.origin.x
                ||this->origin.y!=(edk::int8)rect.origin.y
                ||this->size.width!=(edk::int8)rect.size.width
                ||this->size.height!=(edk::int8)rect.size.height
                );
    }
    //Operator >
    inline bool operator>(edk::recti8 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::recti8 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::recti8 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::recti8 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::recti8 operator+(edk::recti8 rect){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int8)rect.origin.y;
        ret.size.width=this->size.width+(edk::int8)rect.size.width;
        ret.size.height=this->size.height+(edk::int8)rect.size.height;
        return ret;
    }
    inline edk::recti8 operator+(edk::int8 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator+(edk::int32 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator+(edk::int16 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator+(edk::int64 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator+(edk::uint8 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator+(edk::uint32 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator+(edk::uint16 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator+(edk::uint64 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
   inline void operator+=(edk::recti8 rect){
        //
        this->origin.x+=(edk::int8)rect.origin.x;
        this->origin.y+=(edk::int8)rect.origin.y;
        this->size.width+=(edk::int8)rect.size.width;
        this->size.height+=(edk::int8)rect.size.height;
    }
   inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
   inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
   inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
   inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    inline edk::recti8 operator-(edk::recti8 rect){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int8)rect.origin.y;
        ret.size.width=this->size.width-(edk::int8)rect.size.width;
        ret.size.height=this->size.height-(edk::int8)rect.size.height;
        return ret;
    }
    inline edk::recti8 operator-(edk::int8 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator-(edk::int32 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator-(edk::int16 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator-(edk::int64 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator-(edk::uint8 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator-(edk::uint32 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator-(edk::uint16 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator-(edk::uint64 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
   inline void operator-=(edk::recti8 vec){
        //
        this->origin.x-=(edk::int8)vec.origin.x;
        this->origin.y-=(edk::int8)vec.origin.y;
        this->size.width-=(edk::int8)vec.size.width;
        this->size.height-=(edk::int8)vec.size.height;
    }
   inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
   inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
   inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
   inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    inline edk::recti8 operator*(edk::recti8 rect){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int8)rect.origin.y;
        ret.size.width=this->size.width*(edk::int8)rect.size.width;
        ret.size.height=this->size.height*(edk::int8)rect.size.height;
        return ret;
    }
    inline edk::recti8 operator*(edk::int8 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator*(edk::int32 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator*(edk::int16 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator*(edk::int64 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator*(edk::uint8 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator*(edk::uint32 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator*(edk::uint16 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    inline edk::recti8 operator*(edk::uint64 n){
        //
        edk::recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
   inline void operator*=(edk::recti8 rect){
        //
        this->origin.x*=(edk::int8)rect.origin.x;
        this->origin.y*=(edk::int8)rect.origin.y;
        this->size.width*=(edk::int8)rect.size.width;
        this->size.height*=(edk::int8)rect.size.height;
    }
   inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
   inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
   inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
   inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    //
    inline edk::recti8 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti8 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti8 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti8 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti8 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    inline edk::recti8 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return edk::recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    inline edk::recti8 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return edk::recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    inline edk::recti8 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return edk::recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    inline edk::recti8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    inline edk::recti8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return edk::recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    inline edk::recti8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return edk::recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    inline edk::recti8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return edk::recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::recti8 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2i8 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2i8 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    recti16(edk::vec2i8 origin,edk::size2i8 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
    }
    recti16(edk::vec2i16 origin,edk::size2i16 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
    }
    recti16(edk::vec2i32 origin,edk::size2i32 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
    }
    recti16(edk::vec2i64 origin,edk::size2i64 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
    }
    recti16(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
    }
    recti16(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
    }
    recti16(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
    }
    recti16(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
    }

    //operators
    inline edk::recti16 operator=(edk::recti8 rect){
        //
        this->origin.x=(edk::int16)rect.origin.x;
        this->origin.y=(edk::int16)rect.origin.y;
        this->size.width=(edk::int16)rect.size.width;
        this->size.height=(edk::int16)rect.size.height;
        return *this;
    }
    inline edk::recti16 operator=(edk::recti16 rect){
        //
        this->origin.x=(edk::int16)rect.origin.x;
        this->origin.y=(edk::int16)rect.origin.y;
        this->size.width=(edk::int16)rect.size.width;
        this->size.height=(edk::int16)rect.size.height;
        return *this;
    }
    inline edk::recti16 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    inline edk::recti16 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    inline edk::recti16 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    inline edk::recti16 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    inline edk::recti16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    inline edk::recti16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    inline edk::recti16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    inline edk::recti16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }

    inline bool operator==(edk::recti8 rect){
        //
        return (this->origin.x==(edk::int16)rect.origin.x
                &&this->origin.y==(edk::int16)rect.origin.y
                &&this->size.width==(edk::int16)rect.size.width
                &&this->size.height==(edk::int16)rect.size.height
                );
    }
    inline bool operator==(edk::recti16 rect){
        //
        return (this->origin.x==(edk::int16)rect.origin.x
                &&this->origin.y==(edk::int16)rect.origin.y
                &&this->size.width==(edk::int16)rect.size.width
                &&this->size.height==(edk::int16)rect.size.height
                );
    }
    inline bool operator!=(edk::recti8 rect){
        //
        return (this->origin.x!=(edk::int16)rect.origin.x
                ||this->origin.y!=(edk::int16)rect.origin.y
                ||this->size.width!=(edk::int16)rect.size.width
                ||this->size.height!=(edk::int16)rect.size.height
                );
    }
    inline bool operator!=(edk::recti16 rect){
        //
        return (this->origin.x!=(edk::int16)rect.origin.x
                ||this->origin.y!=(edk::int16)rect.origin.y
                ||this->size.width!=(edk::int16)rect.size.width
                ||this->size.height!=(edk::int16)rect.size.height
                );
    }
    //Operator >
    inline bool operator>(edk::recti16 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::recti16 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::recti16 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::recti16 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::recti16 operator+(edk::recti8 rect){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int16)rect.origin.y;
        ret.size.width=this->size.width+(edk::int16)rect.size.width;
        ret.size.height=this->size.height+(edk::int16)rect.size.height;
        return ret;
    }
    inline edk::recti16 operator+(edk::recti16 rect){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int16)rect.origin.y;
        ret.size.width=this->size.width+(edk::int16)rect.size.width;
        ret.size.height=this->size.height+(edk::int16)rect.size.height;
        return ret;
    }
    inline edk::recti16 operator+(edk::int8 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator+(edk::int32 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator+(edk::int16 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator+(edk::int64 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator+(edk::uint8 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator+(edk::uint32 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator+(edk::uint16 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator+(edk::uint64 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
   inline void operator+=(edk::recti8 rect){
        //
        this->origin.x+=(edk::int16)rect.origin.x;
        this->origin.y+=(edk::int16)rect.origin.y;
        this->size.width+=(edk::int16)rect.size.width;
        this->size.height+=(edk::int16)rect.size.height;
    }
   inline void operator+=(edk::recti16 rect){
        //
        this->origin.x+=(edk::int16)rect.origin.x;
        this->origin.y+=(edk::int16)rect.origin.y;
        this->size.width+=(edk::int16)rect.size.width;
        this->size.height+=(edk::int16)rect.size.height;
    }
   inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
   inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
   inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
   inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    inline edk::recti16 operator-(edk::recti8 rect){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int16)rect.origin.y;
        ret.size.width=this->size.width-(edk::int16)rect.size.width;
        ret.size.height=this->size.height-(edk::int16)rect.size.height;
        return ret;
    }
    inline edk::recti16 operator-(edk::recti16 rect){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int16)rect.origin.y;
        ret.size.width=this->size.width-(edk::int16)rect.size.width;
        ret.size.height=this->size.height-(edk::int16)rect.size.height;
        return ret;
    }
    inline edk::recti16 operator-(edk::int8 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator-(edk::int32 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator-(edk::int16 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator-(edk::int64 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator-(edk::uint8 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator-(edk::uint32 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator-(edk::uint16 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator-(edk::uint64 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
   inline void operator-=(edk::recti8 vec){
        //
        this->origin.x-=(edk::int16)vec.origin.x;
        this->origin.y-=(edk::int16)vec.origin.y;
        this->size.width-=(edk::int16)vec.size.width;
        this->size.height-=(edk::int16)vec.size.height;
    }
   inline void operator-=(edk::recti16 vec){
        //
        this->origin.x-=(edk::int16)vec.origin.x;
        this->origin.y-=(edk::int16)vec.origin.y;
        this->size.width-=(edk::int16)vec.size.width;
        this->size.height-=(edk::int16)vec.size.height;
    }
   inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
   inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
   inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
   inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    inline edk::recti16 operator*(edk::recti8 rect){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int16)rect.origin.y;
        ret.size.width=this->size.width*(edk::int16)rect.size.width;
        ret.size.height=this->size.height*(edk::int16)rect.size.height;
        return ret;
    }
    inline edk::recti16 operator*(edk::recti16 rect){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int16)rect.origin.y;
        ret.size.width=this->size.width*(edk::int16)rect.size.width;
        ret.size.height=this->size.height*(edk::int16)rect.size.height;
        return ret;
    }
    inline edk::recti16 operator*(edk::int8 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator*(edk::int32 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator*(edk::int16 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator*(edk::int64 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator*(edk::uint8 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator*(edk::uint32 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator*(edk::uint16 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    inline edk::recti16 operator*(edk::uint64 n){
        //
        edk::recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
   inline void operator*=(edk::recti8 rect){
        //
        this->origin.x*=(edk::int16)rect.origin.x;
        this->origin.y*=(edk::int16)rect.origin.y;
        this->size.width*=(edk::int16)rect.size.width;
        this->size.height*=(edk::int16)rect.size.height;
    }
   inline void operator*=(edk::recti16 rect){
        //
        this->origin.x*=(edk::int16)rect.origin.x;
        this->origin.y*=(edk::int16)rect.origin.y;
        this->size.width*=(edk::int16)rect.size.width;
        this->size.height*=(edk::int16)rect.size.height;
    }
   inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
   inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
   inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
   inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    //
    inline edk::recti16 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti16 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti16 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti16 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti16 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    inline edk::recti16 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return edk::recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    inline edk::recti16 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return edk::recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    inline edk::recti16 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return edk::recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    inline edk::recti16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    inline edk::recti16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return edk::recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    inline edk::recti16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return edk::recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    inline edk::recti16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return edk::recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::recti8 rect){
        if(this->origin.x > (edk::int16)rect.origin.x)this->origin.x = (edk::int16)rect.origin.x;
        if(this->origin.y > (edk::int16)rect.origin.y)this->origin.y = (edk::int16)rect.origin.y;
        if(this->size.width < (edk::int16)rect.size.width)this->size.width = (edk::int16)rect.size.width;
        if(this->size.height < (edk::int16)rect.size.height)this->size.height = (edk::int16)rect.size.height;
    }
    void merge(edk::recti16 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2i8 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2i16 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2i8 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2i16 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    recti32(edk::vec2i8 origin,edk::size2i8 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
    }
    recti32(edk::vec2i16 origin,edk::size2i16 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
    }
    recti32(edk::vec2i32 origin,edk::size2i32 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
    }
    recti32(edk::vec2i64 origin,edk::size2i64 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
    }
    recti32(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
    }
    recti32(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
    }
    recti32(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
    }
    recti32(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
    }

    //operators
    inline edk::recti32 operator=(edk::recti8 rect){
        //
        this->origin.x=(edk::int32)rect.origin.x;
        this->origin.y=(edk::int32)rect.origin.y;
        this->size.width=(edk::int32)rect.size.width;
        this->size.height=(edk::int32)rect.size.height;
        return *this;
    }
    inline edk::recti32 operator=(edk::recti16 rect){
        //
        this->origin.x=(edk::int32)rect.origin.x;
        this->origin.y=(edk::int32)rect.origin.y;
        this->size.width=(edk::int32)rect.size.width;
        this->size.height=(edk::int32)rect.size.height;
        return *this;
    }
    inline edk::recti32 operator=(edk::recti32 rect){
        //
        this->origin.x=(edk::int32)rect.origin.x;
        this->origin.y=(edk::int32)rect.origin.y;
        this->size.width=(edk::int32)rect.size.width;
        this->size.height=(edk::int32)rect.size.height;
        return *this;
    }
    inline edk::recti32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    inline edk::recti32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    inline edk::recti32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    inline edk::recti32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    inline edk::recti32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    inline edk::recti32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    inline edk::recti32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    inline edk::recti32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }

    inline bool operator==(edk::recti8 rect){
        //
        return (this->origin.x==(edk::int32)rect.origin.x
                &&this->origin.y==(edk::int32)rect.origin.y
                &&this->size.width==(edk::int32)rect.size.width
                &&this->size.height==(edk::int32)rect.size.height
                );
    }
    inline bool operator==(edk::recti16 rect){
        //
        return (this->origin.x==(edk::int32)rect.origin.x
                &&this->origin.y==(edk::int32)rect.origin.y
                &&this->size.width==(edk::int32)rect.size.width
                &&this->size.height==(edk::int32)rect.size.height
                );
    }
    inline bool operator==(edk::recti32 rect){
        //
        return (this->origin.x==(edk::int32)rect.origin.x
                &&this->origin.y==(edk::int32)rect.origin.y
                &&this->size.width==(edk::int32)rect.size.width
                &&this->size.height==(edk::int32)rect.size.height
                );
    }
    inline bool operator!=(edk::recti8 rect){
        //
        return (this->origin.x!=(edk::int32)rect.origin.x
                ||this->origin.y!=(edk::int32)rect.origin.y
                ||this->size.width!=(edk::int32)rect.size.width
                ||this->size.height!=(edk::int32)rect.size.height
                );
    }
    inline bool operator!=(edk::recti16 rect){
        //
        return (this->origin.x!=(edk::int32)rect.origin.x
                ||this->origin.y!=(edk::int32)rect.origin.y
                ||this->size.width!=(edk::int32)rect.size.width
                ||this->size.height!=(edk::int32)rect.size.height
                );
    }
    inline bool operator!=(edk::recti32 rect){
        //
        return (this->origin.x!=(edk::int32)rect.origin.x
                ||this->origin.y!=(edk::int32)rect.origin.y
                ||this->size.width!=(edk::int32)rect.size.width
                ||this->size.height!=(edk::int32)rect.size.height
                );
    }
    //Operator >
    inline bool operator>(edk::recti32 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::recti32 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::recti32 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::recti32 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::recti32 operator+(edk::recti8 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int32)rect.origin.y;
        ret.size.width=this->size.width+(edk::int32)rect.size.width;
        ret.size.height=this->size.height+(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator+(edk::recti16 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int32)rect.origin.y;
        ret.size.width=this->size.width+(edk::int32)rect.size.width;
        ret.size.height=this->size.height+(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator+(edk::recti32 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int32)rect.origin.y;
        ret.size.width=this->size.width+(edk::int32)rect.size.width;
        ret.size.height=this->size.height+(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator+(edk::int8 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator+(edk::int32 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator+(edk::int16 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator+(edk::int64 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator+(edk::uint8 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator+(edk::uint32 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator+(edk::uint16 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator+(edk::uint64 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
   inline void operator+=(edk::recti8 rect){
        //
        this->origin.x+=(edk::int32)rect.origin.x;
        this->origin.y+=(edk::int32)rect.origin.y;
        this->size.width+=(edk::int32)rect.size.width;
        this->size.height+=(edk::int32)rect.size.height;
    }
   inline void operator+=(edk::recti16 rect){
        //
        this->origin.x+=(edk::int32)rect.origin.x;
        this->origin.y+=(edk::int32)rect.origin.y;
        this->size.width+=(edk::int32)rect.size.width;
        this->size.height+=(edk::int32)rect.size.height;
    }
   inline void operator+=(edk::recti32 rect){
        //
        this->origin.x+=(edk::int32)rect.origin.x;
        this->origin.y+=(edk::int32)rect.origin.y;
        this->size.width+=(edk::int32)rect.size.width;
        this->size.height+=(edk::int32)rect.size.height;
    }
   inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
   inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
   inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
   inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    inline edk::recti32 operator-(edk::recti8 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int32)rect.origin.y;
        ret.size.width=this->size.width-(edk::int32)rect.size.width;
        ret.size.height=this->size.height-(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator-(edk::recti16 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int32)rect.origin.y;
        ret.size.width=this->size.width-(edk::int32)rect.size.width;
        ret.size.height=this->size.height-(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator-(edk::recti32 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int32)rect.origin.y;
        ret.size.width=this->size.width-(edk::int32)rect.size.width;
        ret.size.height=this->size.height-(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator-(edk::int8 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator-(edk::int32 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator-(edk::int16 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator-(edk::int64 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator-(edk::uint8 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator-(edk::uint32 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator-(edk::uint16 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator-(edk::uint64 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
   inline void operator-=(edk::recti8 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;
        this->origin.y-=(edk::int32)vec.origin.y;
        this->size.width-=(edk::int32)vec.size.width;
        this->size.height-=(edk::int32)vec.size.height;
    }
   inline void operator-=(edk::recti16 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;
        this->origin.y-=(edk::int32)vec.origin.y;
        this->size.width-=(edk::int32)vec.size.width;
        this->size.height-=(edk::int32)vec.size.height;
    }
   inline void operator-=(edk::recti32 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;
        this->origin.y-=(edk::int32)vec.origin.y;
        this->size.width-=(edk::int32)vec.size.width;
        this->size.height-=(edk::int32)vec.size.height;
    }
   inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
   inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
   inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
   inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    inline edk::recti32 operator*(edk::recti8 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int32)rect.origin.y;
        ret.size.width=this->size.width*(edk::int32)rect.size.width;
        ret.size.height=this->size.height*(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator*(edk::recti16 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int32)rect.origin.y;
        ret.size.width=this->size.width*(edk::int32)rect.size.width;
        ret.size.height=this->size.height*(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator*(edk::recti32 rect){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int32)rect.origin.y;
        ret.size.width=this->size.width*(edk::int32)rect.size.width;
        ret.size.height=this->size.height*(edk::int32)rect.size.height;
        return ret;
    }
    inline edk::recti32 operator*(edk::int8 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator*(edk::int32 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator*(edk::int16 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator*(edk::int64 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator*(edk::uint8 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator*(edk::uint32 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator*(edk::uint16 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    inline edk::recti32 operator*(edk::uint64 n){
        //
        edk::recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
   inline void operator*=(edk::recti8 rect){
        //
        this->origin.x*=(edk::int32)rect.origin.x;
        this->origin.y*=(edk::int32)rect.origin.y;
        this->size.width*=(edk::int32)rect.size.width;
        this->size.height*=(edk::int32)rect.size.height;
    }
   inline void operator*=(edk::recti16 rect){
        //
        this->origin.x*=(edk::int32)rect.origin.x;
        this->origin.y*=(edk::int32)rect.origin.y;
        this->size.width*=(edk::int32)rect.size.width;
        this->size.height*=(edk::int32)rect.size.height;
    }
   inline void operator*=(edk::recti32 rect){
        //
        this->origin.x*=(edk::int32)rect.origin.x;
        this->origin.y*=(edk::int32)rect.origin.y;
        this->size.width*=(edk::int32)rect.size.width;
        this->size.height*=(edk::int32)rect.size.height;
    }
   inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
   inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
   inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
   inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    //
    inline edk::recti32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti32 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    inline edk::recti32 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return edk::recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    inline edk::recti32 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return edk::recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    inline edk::recti32 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return edk::recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    inline edk::recti32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    inline edk::recti32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return edk::recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    inline edk::recti32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return edk::recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    inline edk::recti32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return edk::recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::recti8 rect){
        if(this->origin.x > (edk::int32)rect.origin.x)this->origin.x = (edk::int32)rect.origin.x;
        if(this->origin.y > (edk::int32)rect.origin.y)this->origin.y = (edk::int32)rect.origin.y;
        if(this->size.width < (edk::int32)rect.size.width)this->size.width = (edk::int32)rect.size.width;
        if(this->size.height < (edk::int32)rect.size.height)this->size.height = (edk::int32)rect.size.height;
    }
    void merge(edk::recti16 rect){
        if(this->origin.x > (edk::int32)rect.origin.x)this->origin.x = (edk::int32)rect.origin.x;
        if(this->origin.y > (edk::int32)rect.origin.y)this->origin.y = (edk::int32)rect.origin.y;
        if(this->size.width < (edk::int32)rect.size.width)this->size.width = (edk::int32)rect.size.width;
        if(this->size.height < (edk::int32)rect.size.height)this->size.height = (edk::int32)rect.size.height;
    }
    void merge(edk::recti32 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2i8 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2i16 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2i32 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2i8 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2i16 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2i32 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    recti64(edk::vec2i8 origin,edk::size2i8 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
    }
    recti64(edk::vec2i16 origin,edk::size2i16 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
    }
    recti64(edk::vec2i32 origin,edk::size2i32 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
    }
    recti64(edk::vec2i64 origin,edk::size2i64 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
    }
    recti64(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
    }
    recti64(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
    }
    recti64(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
    }
    recti64(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
    }

    //operators
    inline edk::recti64 operator=(edk::recti8 rect){
        //
        this->origin.x=(edk::int64)rect.origin.x;
        this->origin.y=(edk::int64)rect.origin.y;
        this->size.width=(edk::int64)rect.size.width;
        this->size.height=(edk::int64)rect.size.height;
        return *this;
    }
    inline edk::recti64 operator=(edk::recti16 rect){
        //
        this->origin.x=(edk::int64)rect.origin.x;
        this->origin.y=(edk::int64)rect.origin.y;
        this->size.width=(edk::int64)rect.size.width;
        this->size.height=(edk::int64)rect.size.height;
        return *this;
    }
    inline edk::recti64 operator=(edk::recti32 rect){
        //
        this->origin.x=(edk::int64)rect.origin.x;
        this->origin.y=(edk::int64)rect.origin.y;
        this->size.width=(edk::int64)rect.size.width;
        this->size.height=(edk::int64)rect.size.height;
        return *this;
    }
    inline edk::recti64 operator=(edk::recti64 rect){
        //
        this->origin.x=(edk::int64)rect.origin.x;
        this->origin.y=(edk::int64)rect.origin.y;
        this->size.width=(edk::int64)rect.size.width;
        this->size.height=(edk::int64)rect.size.height;
        return *this;
    }
    inline edk::recti64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    inline edk::recti64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    inline edk::recti64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    inline edk::recti64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    inline edk::recti64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    inline edk::recti64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    inline edk::recti64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    inline edk::recti64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }

    inline bool operator==(edk::recti8 rect){
        //
        return (this->origin.x==(edk::int64)rect.origin.x
                &&this->origin.y==(edk::int64)rect.origin.y
                &&this->size.width==(edk::int64)rect.size.width
                &&this->size.height==(edk::int64)rect.size.height
                );
    }
    inline bool operator==(edk::recti16 rect){
        //
        return (this->origin.x==(edk::int64)rect.origin.x
                &&this->origin.y==(edk::int64)rect.origin.y
                &&this->size.width==(edk::int64)rect.size.width
                &&this->size.height==(edk::int64)rect.size.height
                );
    }
    inline bool operator==(edk::recti32 rect){
        //
        return (this->origin.x==(edk::int64)rect.origin.x
                &&this->origin.y==(edk::int64)rect.origin.y
                &&this->size.width==(edk::int64)rect.size.width
                &&this->size.height==(edk::int64)rect.size.height
                );
    }
    inline bool operator==(edk::recti64 rect){
        //
        return (this->origin.x==(edk::int64)rect.origin.x
                &&this->origin.y==(edk::int64)rect.origin.y
                &&this->size.width==(edk::int64)rect.size.width
                &&this->size.height==(edk::int64)rect.size.height
                );
    }
    inline bool operator!=(edk::recti8 rect){
        //
        return (this->origin.x!=(edk::int64)rect.origin.x
                ||this->origin.y!=(edk::int64)rect.origin.y
                ||this->size.width!=(edk::int64)rect.size.width
                ||this->size.height!=(edk::int64)rect.size.height
                );
    }
    inline bool operator!=(edk::recti16 rect){
        //
        return (this->origin.x!=(edk::int64)rect.origin.x
                ||this->origin.y!=(edk::int64)rect.origin.y
                ||this->size.width!=(edk::int64)rect.size.width
                ||this->size.height!=(edk::int64)rect.size.height
                );
    }
    inline bool operator!=(edk::recti32 rect){
        //
        return (this->origin.x!=(edk::int64)rect.origin.x
                ||this->origin.y!=(edk::int64)rect.origin.y
                ||this->size.width!=(edk::int64)rect.size.width
                ||this->size.height!=(edk::int64)rect.size.height
                );
    }
    inline bool operator!=(edk::recti64 rect){
        //
        return (this->origin.x!=(edk::int64)rect.origin.x
                ||this->origin.y!=(edk::int64)rect.origin.y
                ||this->size.width!=(edk::int64)rect.size.width
                ||this->size.height!=(edk::int64)rect.size.height
                );
    }
    //Operator >
    inline bool operator>(edk::recti64 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::recti64 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::recti64 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::recti64 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::recti64 operator+(edk::recti8 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)rect.origin.y;
        ret.size.width=this->size.width+(edk::int64)rect.size.width;
        ret.size.height=this->size.height+(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator+(edk::recti16 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)rect.origin.y;
        ret.size.width=this->size.width+(edk::int64)rect.size.width;
        ret.size.height=this->size.height+(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator+(edk::recti32 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)rect.origin.y;
        ret.size.width=this->size.width+(edk::int64)rect.size.width;
        ret.size.height=this->size.height+(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator+(edk::recti64 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)rect.origin.y;
        ret.size.width=this->size.width+(edk::int64)rect.size.width;
        ret.size.height=this->size.height+(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator+(edk::int8 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator+(edk::int32 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator+(edk::int16 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator+(edk::int64 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator+(edk::uint8 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator+(edk::uint32 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator+(edk::uint16 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator+(edk::uint64 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
   inline void operator+=(edk::recti8 rect){
        //
        this->origin.x+=(edk::int64)rect.origin.x;
        this->origin.y+=(edk::int64)rect.origin.y;
        this->size.width+=(edk::int64)rect.size.width;
        this->size.height+=(edk::int64)rect.size.height;
    }
   inline void operator+=(edk::recti16 rect){
        //
        this->origin.x+=(edk::int64)rect.origin.x;
        this->origin.y+=(edk::int64)rect.origin.y;
        this->size.width+=(edk::int64)rect.size.width;
        this->size.height+=(edk::int64)rect.size.height;
    }
   inline void operator+=(edk::recti32 rect){
        //
        this->origin.x+=(edk::int64)rect.origin.x;
        this->origin.y+=(edk::int64)rect.origin.y;
        this->size.width+=(edk::int64)rect.size.width;
        this->size.height+=(edk::int64)rect.size.height;
    }
   inline void operator+=(edk::recti64 rect){
        //
        this->origin.x+=(edk::int64)rect.origin.x;
        this->origin.y+=(edk::int64)rect.origin.y;
        this->size.width+=(edk::int64)rect.size.width;
        this->size.height+=(edk::int64)rect.size.height;
    }
   inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
   inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
   inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
   inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    inline edk::recti64 operator-(edk::recti8 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)rect.origin.y;
        ret.size.width=this->size.width-(edk::int64)rect.size.width;
        ret.size.height=this->size.height-(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator-(edk::recti16 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)rect.origin.y;
        ret.size.width=this->size.width-(edk::int64)rect.size.width;
        ret.size.height=this->size.height-(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator-(edk::recti32 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)rect.origin.y;
        ret.size.width=this->size.width-(edk::int64)rect.size.width;
        ret.size.height=this->size.height-(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator-(edk::recti64 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)rect.origin.y;
        ret.size.width=this->size.width-(edk::int64)rect.size.width;
        ret.size.height=this->size.height-(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator-(edk::int8 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator-(edk::int32 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator-(edk::int16 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator-(edk::int64 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator-(edk::uint8 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator-(edk::uint32 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator-(edk::uint16 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator-(edk::uint64 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
   inline void operator-=(edk::recti8 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
    }
   inline void operator-=(edk::recti16 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
    }
   inline void operator-=(edk::recti32 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
    }
   inline void operator-=(edk::recti64 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
    }
   inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
   inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
   inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
   inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    inline edk::recti64 operator*(edk::recti8 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)rect.origin.y;
        ret.size.width=this->size.width*(edk::int64)rect.size.width;
        ret.size.height=this->size.height*(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator*(edk::recti16 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)rect.origin.y;
        ret.size.width=this->size.width*(edk::int64)rect.size.width;
        ret.size.height=this->size.height*(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator*(edk::recti32 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)rect.origin.y;
        ret.size.width=this->size.width*(edk::int64)rect.size.width;
        ret.size.height=this->size.height*(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator*(edk::recti64 rect){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)rect.origin.y;
        ret.size.width=this->size.width*(edk::int64)rect.size.width;
        ret.size.height=this->size.height*(edk::int64)rect.size.height;
        return ret;
    }
    inline edk::recti64 operator*(edk::int8 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator*(edk::int32 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator*(edk::int16 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator*(edk::int64 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator*(edk::uint8 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator*(edk::uint32 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator*(edk::uint16 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    inline edk::recti64 operator*(edk::uint64 n){
        //
        edk::recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
   inline void operator*=(edk::recti8 rect){
        //
        this->origin.x*=(edk::int64)rect.origin.x;
        this->origin.y*=(edk::int64)rect.origin.y;
        this->size.width*=(edk::int64)rect.size.width;
        this->size.height*=(edk::int64)rect.size.height;
    }
   inline void operator*=(edk::recti16 rect){
        //
        this->origin.x*=(edk::int64)rect.origin.x;
        this->origin.y*=(edk::int64)rect.origin.y;
        this->size.width*=(edk::int64)rect.size.width;
        this->size.height*=(edk::int64)rect.size.height;
    }
   inline void operator*=(edk::recti32 rect){
        //
        this->origin.x*=(edk::int64)rect.origin.x;
        this->origin.y*=(edk::int64)rect.origin.y;
        this->size.width*=(edk::int64)rect.size.width;
        this->size.height*=(edk::int64)rect.size.height;
    }
   inline void operator*=(edk::recti64 rect){
        //
        this->origin.x*=(edk::int64)rect.origin.x;
        this->origin.y*=(edk::int64)rect.origin.y;
        this->size.width*=(edk::int64)rect.size.width;
        this->size.height*=(edk::int64)rect.size.height;
    }
   inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
   inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
   inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
   inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    //
    inline edk::recti64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::recti64 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    inline edk::recti64 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return edk::recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    inline edk::recti64 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return edk::recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    inline edk::recti64 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return edk::recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    inline edk::recti64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    inline edk::recti64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return edk::recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    inline edk::recti64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return edk::recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    inline edk::recti64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return edk::recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::recti8 rect){
        if(this->origin.x > (edk::int64)rect.origin.x)this->origin.x = (edk::int64)rect.origin.x;
        if(this->origin.y > (edk::int64)rect.origin.y)this->origin.y = (edk::int64)rect.origin.y;
        if(this->size.width < (edk::int64)rect.size.width)this->size.width = (edk::int64)rect.size.width;
        if(this->size.height < (edk::int64)rect.size.height)this->size.height = (edk::int64)rect.size.height;
    }
    void merge(edk::recti16 rect){
        if(this->origin.x > (edk::int64)rect.origin.x)this->origin.x = (edk::int64)rect.origin.x;
        if(this->origin.y > (edk::int64)rect.origin.y)this->origin.y = (edk::int64)rect.origin.y;
        if(this->size.width < (edk::int64)rect.size.width)this->size.width = (edk::int64)rect.size.width;
        if(this->size.height < (edk::int64)rect.size.height)this->size.height = (edk::int64)rect.size.height;
    }
    void merge(edk::recti32 rect){
        if(this->origin.x > (edk::int64)rect.origin.x)this->origin.x = (edk::int64)rect.origin.x;
        if(this->origin.y > (edk::int64)rect.origin.y)this->origin.y = (edk::int64)rect.origin.y;
        if(this->size.width < (edk::int64)rect.size.width)this->size.width = (edk::int64)rect.size.width;
        if(this->size.height < (edk::int64)rect.size.height)this->size.height = (edk::int64)rect.size.height;
    }
    void merge(edk::recti64 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2i8 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2i16 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2i32 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2i64 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2i8 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2i16 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2i32 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2i64 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    rectui8(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::uint8)origin.x;
        this->origin.y=(edk::uint8)origin.y;
        this->size.width=(edk::uint8)size.width;
        this->size.height=(edk::uint8)size.height;
    }
    rectui8(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::uint8)origin.x;
        this->origin.y=(edk::uint8)origin.y;
        this->size.width=(edk::uint8)size.width;
        this->size.height=(edk::uint8)size.height;
    }
    rectui8(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::uint8)origin.x;
        this->origin.y=(edk::uint8)origin.y;
        this->size.width=(edk::uint8)size.width;
        this->size.height=(edk::uint8)size.height;
    }
    rectui8(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::uint8)origin.x;
        this->origin.y=(edk::uint8)origin.y;
        this->size.width=(edk::uint8)size.width;
        this->size.height=(edk::uint8)size.height;
    }

    //operators
    inline edk::rectui8 operator=(edk::rectui8 rect){
        //
        this->origin.x=(edk::uint8)rect.origin.x;
        this->origin.y=(edk::uint8)rect.origin.y;
        this->size.width=(edk::uint8)rect.size.width;
        this->size.height=(edk::uint8)rect.size.height;
        return *this;
    }
    inline edk::rectui8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        return *this;
    }
    inline edk::rectui8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        return *this;
    }
    inline edk::rectui8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        return *this;
    }
    inline edk::rectui8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        return *this;
    }

    inline bool operator==(edk::rectui8 rect){
        //
        return (this->origin.x==(edk::uint8)rect.origin.x
                &&this->origin.y==(edk::uint8)rect.origin.y
                &&this->size.width==(edk::uint8)rect.size.width
                &&this->size.height==(edk::uint8)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui8 rect){
        //
        return (this->origin.x!=(edk::uint8)rect.origin.x
                ||this->origin.y!=(edk::uint8)rect.origin.y
                ||this->size.width!=(edk::uint8)rect.size.width
                ||this->size.height!=(edk::uint8)rect.size.height
                );
    }
    //Operator >
    inline bool operator>(edk::rectui8 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::rectui8 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::rectui8 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::rectui8 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::rectui8 operator+(edk::rectui8 rect){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint8)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint8)rect.size.width;
        ret.size.height=this->size.height+(edk::uint8)rect.size.height;
        return ret;
    }
    inline edk::rectui8 operator+(edk::uint8 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator+(edk::uint32 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator+(edk::uint16 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator+(edk::uint64 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        return ret;
    }
   inline void operator+=(edk::rectui8 rect){
        //
        this->origin.x+=(edk::uint8)rect.origin.x;
        this->origin.y+=(edk::uint8)rect.origin.y;
        this->size.width+=(edk::uint8)rect.size.width;
        this->size.height+=(edk::uint8)rect.size.height;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
    }
    inline edk::rectui8 operator-(edk::rectui8 rect){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint8)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint8)rect.size.width;
        ret.size.height=this->size.height-(edk::uint8)rect.size.height;
        return ret;
    }
    inline edk::rectui8 operator-(edk::uint8 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator-(edk::uint32 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator-(edk::uint16 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator-(edk::uint64 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        return ret;
    }
   inline void operator-=(edk::rectui8 vec){
        //
        this->origin.x-=(edk::uint8)vec.origin.x;
        this->origin.y-=(edk::uint8)vec.origin.y;
        this->size.width-=(edk::uint8)vec.size.width;
        this->size.height-=(edk::uint8)vec.size.height;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
    }
    inline edk::rectui8 operator*(edk::rectui8 rect){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint8)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint8)rect.size.width;
        ret.size.height=this->size.height*(edk::uint8)rect.size.height;
        return ret;
    }
    inline edk::rectui8 operator*(edk::uint8 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator*(edk::uint32 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator*(edk::uint16 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        return ret;
    }
    inline edk::rectui8 operator*(edk::uint64 n){
        //
        edk::rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        return ret;
    }
   inline void operator*=(edk::rectui8 rect){
        //
        this->origin.x*=(edk::uint8)rect.origin.x;
        this->origin.y*=(edk::uint8)rect.origin.y;
        this->size.width*=(edk::uint8)rect.size.width;
        this->size.height*=(edk::uint8)rect.size.height;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
    }
    //
    inline edk::rectui8 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui8 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui8 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui8 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->size.width,(edk::uint8)this->size.height);
    }
    inline edk::rectui8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        return edk::rectui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->size.width,(edk::uint8)this->size.height);
    }
    inline edk::rectui8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        return edk::rectui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->size.width,(edk::uint8)this->size.height);
    }
    inline edk::rectui8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        return edk::rectui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->size.width,(edk::uint8)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::rectui8 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2ui8 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2ui8 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    rectui16(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::uint16)origin.x;
        this->origin.y=(edk::uint16)origin.y;
        this->size.width=(edk::uint16)size.width;
        this->size.height=(edk::uint16)size.height;
    }
    rectui16(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::uint16)origin.x;
        this->origin.y=(edk::uint16)origin.y;
        this->size.width=(edk::uint16)size.width;
        this->size.height=(edk::uint16)size.height;
    }
    rectui16(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::uint16)origin.x;
        this->origin.y=(edk::uint16)origin.y;
        this->size.width=(edk::uint16)size.width;
        this->size.height=(edk::uint16)size.height;
    }
    rectui16(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::uint16)origin.x;
        this->origin.y=(edk::uint16)origin.y;
        this->size.width=(edk::uint16)size.width;
        this->size.height=(edk::uint16)size.height;
    }

    //operators
    inline edk::rectui16 operator=(edk::rectui8 rect){
        //
        this->origin.x=(edk::uint16)rect.origin.x;
        this->origin.y=(edk::uint16)rect.origin.y;
        this->size.width=(edk::uint16)rect.size.width;
        this->size.height=(edk::uint16)rect.size.height;
        return *this;
    }
    inline edk::rectui16 operator=(edk::rectui16 rect){
        //
        this->origin.x=(edk::uint16)rect.origin.x;
        this->origin.y=(edk::uint16)rect.origin.y;
        this->size.width=(edk::uint16)rect.size.width;
        this->size.height=(edk::uint16)rect.size.height;
        return *this;
    }
    inline edk::rectui16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        return *this;
    }
    inline edk::rectui16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        return *this;
    }
    inline edk::rectui16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        return *this;
    }
    inline edk::rectui16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        return *this;
    }

    inline bool operator==(edk::rectui8 rect){
        //
        return (this->origin.x==(edk::uint16)rect.origin.x
                &&this->origin.y==(edk::uint16)rect.origin.y
                &&this->size.width==(edk::uint16)rect.size.width
                &&this->size.height==(edk::uint16)rect.size.height
                );
    }
    inline bool operator==(edk::rectui16 rect){
        //
        return (this->origin.x==(edk::uint16)rect.origin.x
                &&this->origin.y==(edk::uint16)rect.origin.y
                &&this->size.width==(edk::uint16)rect.size.width
                &&this->size.height==(edk::uint16)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui8 rect){
        //
        return (this->origin.x!=(edk::uint16)rect.origin.x
                ||this->origin.y!=(edk::uint16)rect.origin.y
                ||this->size.width!=(edk::uint16)rect.size.width
                ||this->size.height!=(edk::uint16)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui16 rect){
        //
        return (this->origin.x!=(edk::uint16)rect.origin.x
                ||this->origin.y!=(edk::uint16)rect.origin.y
                ||this->size.width!=(edk::uint16)rect.size.width
                ||this->size.height!=(edk::uint16)rect.size.height
                );
    }
    //Operator >
    inline bool operator>(edk::rectui16 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::rectui16 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::rectui16 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::rectui16 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::rectui16 operator+(edk::rectui8 rect){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint16)rect.size.width;
        ret.size.height=this->size.height+(edk::uint16)rect.size.height;
        return ret;
    }
    inline edk::rectui16 operator+(edk::rectui16 rect){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint16)rect.size.width;
        ret.size.height=this->size.height+(edk::uint16)rect.size.height;
        return ret;
    }
    inline edk::rectui16 operator+(edk::uint8 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator+(edk::uint32 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator+(edk::uint16 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator+(edk::uint64 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        return ret;
    }
   inline void operator+=(edk::rectui8 rect){
        //
        this->origin.x+=(edk::uint16)rect.origin.x;
        this->origin.y+=(edk::uint16)rect.origin.y;
        this->size.width+=(edk::uint16)rect.size.width;
        this->size.height+=(edk::uint16)rect.size.height;
    }
   inline void operator+=(edk::rectui16 rect){
        //
        this->origin.x+=(edk::uint16)rect.origin.x;
        this->origin.y+=(edk::uint16)rect.origin.y;
        this->size.width+=(edk::uint16)rect.size.width;
        this->size.height+=(edk::uint16)rect.size.height;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
    }
    inline edk::rectui16 operator-(edk::rectui8 rect){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint16)rect.size.width;
        ret.size.height=this->size.height-(edk::uint16)rect.size.height;
        return ret;
    }
    inline edk::rectui16 operator-(edk::rectui16 rect){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint16)rect.size.width;
        ret.size.height=this->size.height-(edk::uint16)rect.size.height;
        return ret;
    }
    inline edk::rectui16 operator-(edk::uint8 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator-(edk::uint32 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator-(edk::uint16 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator-(edk::uint64 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        return ret;
    }
   inline void operator-=(edk::rectui8 vec){
        //
        this->origin.x-=(edk::uint16)vec.origin.x;
        this->origin.y-=(edk::uint16)vec.origin.y;
        this->size.width-=(edk::uint16)vec.size.width;
        this->size.height-=(edk::uint16)vec.size.height;
    }
   inline void operator-=(edk::rectui16 vec){
        //
        this->origin.x-=(edk::uint16)vec.origin.x;
        this->origin.y-=(edk::uint16)vec.origin.y;
        this->size.width-=(edk::uint16)vec.size.width;
        this->size.height-=(edk::uint16)vec.size.height;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
    }
    inline edk::rectui16 operator*(edk::rectui8 rect){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint16)rect.size.width;
        ret.size.height=this->size.height*(edk::uint16)rect.size.height;
        return ret;
    }
    inline edk::rectui16 operator*(edk::rectui16 rect){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint16)rect.size.width;
        ret.size.height=this->size.height*(edk::uint16)rect.size.height;
        return ret;
    }
    inline edk::rectui16 operator*(edk::uint8 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator*(edk::uint32 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator*(edk::uint16 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        return ret;
    }
    inline edk::rectui16 operator*(edk::uint64 n){
        //
        edk::rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        return ret;
    }
   inline void operator*=(edk::rectui8 rect){
        //
        this->origin.x*=(edk::uint16)rect.origin.x;
        this->origin.y*=(edk::uint16)rect.origin.y;
        this->size.width*=(edk::uint16)rect.size.width;
        this->size.height*=(edk::uint16)rect.size.height;
    }
   inline void operator*=(edk::rectui16 rect){
        //
        this->origin.x*=(edk::uint16)rect.origin.x;
        this->origin.y*=(edk::uint16)rect.origin.y;
        this->size.width*=(edk::uint16)rect.size.width;
        this->size.height*=(edk::uint16)rect.size.height;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
    }
    //
    inline edk::rectui16 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui16 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui16 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui16 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->size.width,(edk::uint16)this->size.height);
    }
    inline edk::rectui16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        return edk::rectui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->size.width,(edk::uint16)this->size.height);
    }
    inline edk::rectui16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        return edk::rectui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->size.width,(edk::uint16)this->size.height);
    }
    inline edk::rectui16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        return edk::rectui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->size.width,(edk::uint16)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::rectui8 rect){
        if(this->origin.x > (edk::uint16)rect.origin.x)this->origin.x = (edk::uint16)rect.origin.x;
        if(this->origin.y > (edk::uint16)rect.origin.y)this->origin.y = (edk::uint16)rect.origin.y;
        if(this->size.width < (edk::uint16)rect.size.width)this->size.width = (edk::uint16)rect.size.width;
        if(this->size.height < (edk::uint16)rect.size.height)this->size.height = (edk::uint16)rect.size.height;
    }
    void merge(edk::rectui16 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2ui8 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2ui16 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2ui8 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2ui16 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    rectui32(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::uint32)origin.x;
        this->origin.y=(edk::uint32)origin.y;
        this->size.width=(edk::uint32)size.width;
        this->size.height=(edk::uint32)size.height;
    }
    rectui32(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::uint32)origin.x;
        this->origin.y=(edk::uint32)origin.y;
        this->size.width=(edk::uint32)size.width;
        this->size.height=(edk::uint32)size.height;
    }
    rectui32(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::uint32)origin.x;
        this->origin.y=(edk::uint32)origin.y;
        this->size.width=(edk::uint32)size.width;
        this->size.height=(edk::uint32)size.height;
    }
    rectui32(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::uint32)origin.x;
        this->origin.y=(edk::uint32)origin.y;
        this->size.width=(edk::uint32)size.width;
        this->size.height=(edk::uint32)size.height;
    }

    //operators
    inline edk::rectui32 operator=(edk::rectui8 rect){
        //
        this->origin.x=(edk::uint32)rect.origin.x;
        this->origin.y=(edk::uint32)rect.origin.y;
        this->size.width=(edk::uint32)rect.size.width;
        this->size.height=(edk::uint32)rect.size.height;
        return *this;
    }
    inline edk::rectui32 operator=(edk::rectui16 rect){
        //
        this->origin.x=(edk::uint32)rect.origin.x;
        this->origin.y=(edk::uint32)rect.origin.y;
        this->size.width=(edk::uint32)rect.size.width;
        this->size.height=(edk::uint32)rect.size.height;
        return *this;
    }
    inline edk::rectui32 operator=(edk::rectui32 rect){
        //
        this->origin.x=(edk::uint32)rect.origin.x;
        this->origin.y=(edk::uint32)rect.origin.y;
        this->size.width=(edk::uint32)rect.size.width;
        this->size.height=(edk::uint32)rect.size.height;
        return *this;
    }
    inline edk::rectui32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        return *this;
    }
    inline edk::rectui32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        return *this;
    }
    inline edk::rectui32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        return *this;
    }
    inline edk::rectui32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        return *this;
    }

    inline bool operator==(edk::rectui8 rect){
        //
        return (this->origin.x==(edk::uint32)rect.origin.x
                &&this->origin.y==(edk::uint32)rect.origin.y
                &&this->size.width==(edk::uint32)rect.size.width
                &&this->size.height==(edk::uint32)rect.size.height
                );
    }
    inline bool operator==(edk::rectui16 rect){
        //
        return (this->origin.x==(edk::uint32)rect.origin.x
                &&this->origin.y==(edk::uint32)rect.origin.y
                &&this->size.width==(edk::uint32)rect.size.width
                &&this->size.height==(edk::uint32)rect.size.height
                );
    }
    inline bool operator==(edk::rectui32 rect){
        //
        return (this->origin.x==(edk::uint32)rect.origin.x
                &&this->origin.y==(edk::uint32)rect.origin.y
                &&this->size.width==(edk::uint32)rect.size.width
                &&this->size.height==(edk::uint32)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui8 rect){
        //
        return (this->origin.x!=(edk::uint32)rect.origin.x
                ||this->origin.y!=(edk::uint32)rect.origin.y
                ||this->size.width!=(edk::uint32)rect.size.width
                ||this->size.height!=(edk::uint32)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui16 rect){
        //
        return (this->origin.x!=(edk::uint32)rect.origin.x
                ||this->origin.y!=(edk::uint32)rect.origin.y
                ||this->size.width!=(edk::uint32)rect.size.width
                ||this->size.height!=(edk::uint32)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui32 rect){
        //
        return (this->origin.x!=(edk::uint32)rect.origin.x
                ||this->origin.y!=(edk::uint32)rect.origin.y
                ||this->size.width!=(edk::uint32)rect.size.width
                ||this->size.height!=(edk::uint32)rect.size.height
                );
    }
    //Operator >
    inline bool operator>(edk::rectui32 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::rectui32 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::rectui32 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::rectui32 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::rectui32 operator+(edk::rectui8 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint32)rect.size.width;
        ret.size.height=this->size.height+(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator+(edk::rectui16 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint32)rect.size.width;
        ret.size.height=this->size.height+(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator+(edk::rectui32 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint32)rect.size.width;
        ret.size.height=this->size.height+(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator+(edk::uint8 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator+(edk::uint32 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator+(edk::uint16 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator+(edk::uint64 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        return ret;
    }
   inline void operator+=(edk::rectui8 rect){
        //
        this->origin.x+=(edk::uint32)rect.origin.x;
        this->origin.y+=(edk::uint32)rect.origin.y;
        this->size.width+=(edk::uint32)rect.size.width;
        this->size.height+=(edk::uint32)rect.size.height;
    }
   inline void operator+=(edk::rectui16 rect){
        //
        this->origin.x+=(edk::uint32)rect.origin.x;
        this->origin.y+=(edk::uint32)rect.origin.y;
        this->size.width+=(edk::uint32)rect.size.width;
        this->size.height+=(edk::uint32)rect.size.height;
    }
   inline void operator+=(edk::rectui32 rect){
        //
        this->origin.x+=(edk::uint32)rect.origin.x;
        this->origin.y+=(edk::uint32)rect.origin.y;
        this->size.width+=(edk::uint32)rect.size.width;
        this->size.height+=(edk::uint32)rect.size.height;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
    }
    inline edk::rectui32 operator-(edk::rectui8 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint32)rect.size.width;
        ret.size.height=this->size.height-(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator-(edk::rectui16 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint32)rect.size.width;
        ret.size.height=this->size.height-(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator-(edk::rectui32 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint32)rect.size.width;
        ret.size.height=this->size.height-(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator-(edk::uint8 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator-(edk::uint32 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator-(edk::uint16 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator-(edk::uint64 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        return ret;
    }
   inline void operator-=(edk::rectui8 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;
        this->origin.y-=(edk::uint32)vec.origin.y;
        this->size.width-=(edk::uint32)vec.size.width;
        this->size.height-=(edk::uint32)vec.size.height;
    }
   inline void operator-=(edk::rectui16 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;
        this->origin.y-=(edk::uint32)vec.origin.y;
        this->size.width-=(edk::uint32)vec.size.width;
        this->size.height-=(edk::uint32)vec.size.height;
    }
   inline void operator-=(edk::rectui32 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;
        this->origin.y-=(edk::uint32)vec.origin.y;
        this->size.width-=(edk::uint32)vec.size.width;
        this->size.height-=(edk::uint32)vec.size.height;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
    }
    inline edk::rectui32 operator*(edk::rectui8 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint32)rect.size.width;
        ret.size.height=this->size.height*(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator*(edk::rectui16 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint32)rect.size.width;
        ret.size.height=this->size.height*(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator*(edk::rectui32 rect){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint32)rect.size.width;
        ret.size.height=this->size.height*(edk::uint32)rect.size.height;
        return ret;
    }
    inline edk::rectui32 operator*(edk::uint8 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator*(edk::uint32 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator*(edk::uint16 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        return ret;
    }
    inline edk::rectui32 operator*(edk::uint64 n){
        //
        edk::rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        return ret;
    }
   inline void operator*=(edk::rectui8 rect){
        //
        this->origin.x*=(edk::uint32)rect.origin.x;
        this->origin.y*=(edk::uint32)rect.origin.y;
        this->size.width*=(edk::uint32)rect.size.width;
        this->size.height*=(edk::uint32)rect.size.height;
    }
   inline void operator*=(edk::rectui16 rect){
        //
        this->origin.x*=(edk::uint32)rect.origin.x;
        this->origin.y*=(edk::uint32)rect.origin.y;
        this->size.width*=(edk::uint32)rect.size.width;
        this->size.height*=(edk::uint32)rect.size.height;
    }
   inline void operator*=(edk::rectui32 rect){
        //
        this->origin.x*=(edk::uint32)rect.origin.x;
        this->origin.y*=(edk::uint32)rect.origin.y;
        this->size.width*=(edk::uint32)rect.size.width;
        this->size.height*=(edk::uint32)rect.size.height;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
    }
    //
    inline edk::rectui32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->size.width,(edk::uint32)this->size.height);
    }
    inline edk::rectui32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        return edk::rectui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->size.width,(edk::uint32)this->size.height);
    }
    inline edk::rectui32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        return edk::rectui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->size.width,(edk::uint32)this->size.height);
    }
    inline edk::rectui32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        return edk::rectui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->size.width,(edk::uint32)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::rectui8 rect){
        if(this->origin.x > (edk::uint32)rect.origin.x)this->origin.x = (edk::uint32)rect.origin.x;
        if(this->origin.y > (edk::uint32)rect.origin.y)this->origin.y = (edk::uint32)rect.origin.y;
        if(this->size.width < (edk::uint32)rect.size.width)this->size.width = (edk::uint32)rect.size.width;
        if(this->size.height < (edk::uint32)rect.size.height)this->size.height = (edk::uint32)rect.size.height;
    }
    void merge(edk::rectui16 rect){
        if(this->origin.x > (edk::uint32)rect.origin.x)this->origin.x = (edk::uint32)rect.origin.x;
        if(this->origin.y > (edk::uint32)rect.origin.y)this->origin.y = (edk::uint32)rect.origin.y;
        if(this->size.width < (edk::uint32)rect.size.width)this->size.width = (edk::uint32)rect.size.width;
        if(this->size.height < (edk::uint32)rect.size.height)this->size.height = (edk::uint32)rect.size.height;
    }
    void merge(edk::rectui32 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2ui8 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2ui16 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2ui32 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2ui8 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2ui16 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2ui32 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    rectui64(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::uint64)origin.x;
        this->origin.y=(edk::uint64)origin.y;
        this->size.width=(edk::uint64)size.width;
        this->size.height=(edk::uint64)size.height;
    }
    rectui64(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::uint64)origin.x;
        this->origin.y=(edk::uint64)origin.y;
        this->size.width=(edk::uint64)size.width;
        this->size.height=(edk::uint64)size.height;
    }
    rectui64(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::uint64)origin.x;
        this->origin.y=(edk::uint64)origin.y;
        this->size.width=(edk::uint64)size.width;
        this->size.height=(edk::uint64)size.height;
    }
    rectui64(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::uint64)origin.x;
        this->origin.y=(edk::uint64)origin.y;
        this->size.width=(edk::uint64)size.width;
        this->size.height=(edk::uint64)size.height;
    }

    //operators
    inline edk::rectui64 operator=(edk::rectui8 rect){
        //
        this->origin.x=(edk::uint64)rect.origin.x;
        this->origin.y=(edk::uint64)rect.origin.y;
        this->size.width=(edk::uint64)rect.size.width;
        this->size.height=(edk::uint64)rect.size.height;
        return *this;
    }
    inline edk::rectui64 operator=(edk::rectui16 rect){
        //
        this->origin.x=(edk::uint64)rect.origin.x;
        this->origin.y=(edk::uint64)rect.origin.y;
        this->size.width=(edk::uint64)rect.size.width;
        this->size.height=(edk::uint64)rect.size.height;
        return *this;
    }
    inline edk::rectui64 operator=(edk::rectui32 rect){
        //
        this->origin.x=(edk::uint64)rect.origin.x;
        this->origin.y=(edk::uint64)rect.origin.y;
        this->size.width=(edk::uint64)rect.size.width;
        this->size.height=(edk::uint64)rect.size.height;
        return *this;
    }
    inline edk::rectui64 operator=(edk::rectui64 rect){
        //
        this->origin.x=(edk::uint64)rect.origin.x;
        this->origin.y=(edk::uint64)rect.origin.y;
        this->size.width=(edk::uint64)rect.size.width;
        this->size.height=(edk::uint64)rect.size.height;
        return *this;
    }
    inline edk::rectui64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        return *this;
    }
    inline edk::rectui64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        return *this;
    }
    inline edk::rectui64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        return *this;
    }
    inline edk::rectui64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        return *this;
    }

    inline bool operator==(edk::rectui8 rect){
        //
        return (this->origin.x==(edk::uint64)rect.origin.x
                &&this->origin.y==(edk::uint64)rect.origin.y
                &&this->size.width==(edk::uint64)rect.size.width
                &&this->size.height==(edk::uint64)rect.size.height
                );
    }
    inline bool operator==(edk::rectui16 rect){
        //
        return (this->origin.x==(edk::uint64)rect.origin.x
                &&this->origin.y==(edk::uint64)rect.origin.y
                &&this->size.width==(edk::uint64)rect.size.width
                &&this->size.height==(edk::uint64)rect.size.height
                );
    }
    inline bool operator==(edk::rectui32 rect){
        //
        return (this->origin.x==(edk::uint64)rect.origin.x
                &&this->origin.y==(edk::uint64)rect.origin.y
                &&this->size.width==(edk::uint64)rect.size.width
                &&this->size.height==(edk::uint64)rect.size.height
                );
    }
    inline bool operator==(edk::rectui64 rect){
        //
        return (this->origin.x==(edk::uint64)rect.origin.x
                &&this->origin.y==(edk::uint64)rect.origin.y
                &&this->size.width==(edk::uint64)rect.size.width
                &&this->size.height==(edk::uint64)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui8 rect){
        //
        return (this->origin.x!=(edk::uint64)rect.origin.x
                ||this->origin.y!=(edk::uint64)rect.origin.y
                ||this->size.width!=(edk::uint64)rect.size.width
                ||this->size.height!=(edk::uint64)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui16 rect){
        //
        return (this->origin.x!=(edk::uint64)rect.origin.x
                ||this->origin.y!=(edk::uint64)rect.origin.y
                ||this->size.width!=(edk::uint64)rect.size.width
                ||this->size.height!=(edk::uint64)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui32 rect){
        //
        return (this->origin.x!=(edk::uint64)rect.origin.x
                ||this->origin.y!=(edk::uint64)rect.origin.y
                ||this->size.width!=(edk::uint64)rect.size.width
                ||this->size.height!=(edk::uint64)rect.size.height
                );
    }
    inline bool operator!=(edk::rectui64 rect){
        //
        return (this->origin.x!=(edk::uint64)rect.origin.x
                ||this->origin.y!=(edk::uint64)rect.origin.y
                ||this->size.width!=(edk::uint64)rect.size.width
                ||this->size.height!=(edk::uint64)rect.size.height
                );
    }
    //Operator >
    inline bool operator>(edk::rectui64 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::rectui64 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::rectui64 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::rectui64 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::rectui64 operator+(edk::rectui8 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint64)rect.size.width;
        ret.size.height=this->size.height+(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator+(edk::rectui16 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint64)rect.size.width;
        ret.size.height=this->size.height+(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator+(edk::rectui32 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint64)rect.size.width;
        ret.size.height=this->size.height+(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator+(edk::rectui64 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint64)rect.size.width;
        ret.size.height=this->size.height+(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator+(edk::uint8 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator+(edk::uint32 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator+(edk::uint16 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator+(edk::uint64 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        return ret;
    }
   inline void operator+=(edk::rectui8 rect){
        //
        this->origin.x+=(edk::uint64)rect.origin.x;
        this->origin.y+=(edk::uint64)rect.origin.y;
        this->size.width+=(edk::uint64)rect.size.width;
        this->size.height+=(edk::uint64)rect.size.height;
    }
   inline void operator+=(edk::rectui16 rect){
        //
        this->origin.x+=(edk::uint64)rect.origin.x;
        this->origin.y+=(edk::uint64)rect.origin.y;
        this->size.width+=(edk::uint64)rect.size.width;
        this->size.height+=(edk::uint64)rect.size.height;
    }
   inline void operator+=(edk::rectui32 rect){
        //
        this->origin.x+=(edk::uint64)rect.origin.x;
        this->origin.y+=(edk::uint64)rect.origin.y;
        this->size.width+=(edk::uint64)rect.size.width;
        this->size.height+=(edk::uint64)rect.size.height;
    }
   inline void operator+=(edk::rectui64 rect){
        //
        this->origin.x+=(edk::uint64)rect.origin.x;
        this->origin.y+=(edk::uint64)rect.origin.y;
        this->size.width+=(edk::uint64)rect.size.width;
        this->size.height+=(edk::uint64)rect.size.height;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
    }
    inline edk::rectui64 operator-(edk::rectui8 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint64)rect.size.width;
        ret.size.height=this->size.height-(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator-(edk::rectui16 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint64)rect.size.width;
        ret.size.height=this->size.height-(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator-(edk::rectui32 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint64)rect.size.width;
        ret.size.height=this->size.height-(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator-(edk::rectui64 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint64)rect.size.width;
        ret.size.height=this->size.height-(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator-(edk::uint8 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator-(edk::uint32 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator-(edk::uint16 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator-(edk::uint64 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        return ret;
    }
   inline void operator-=(edk::rectui8 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
    }
   inline void operator-=(edk::rectui16 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
    }
   inline void operator-=(edk::rectui32 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
    }
   inline void operator-=(edk::rectui64 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
    }
    inline edk::rectui64 operator*(edk::rectui8 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint64)rect.size.width;
        ret.size.height=this->size.height*(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator*(edk::rectui16 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint64)rect.size.width;
        ret.size.height=this->size.height*(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator*(edk::rectui32 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint64)rect.size.width;
        ret.size.height=this->size.height*(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator*(edk::rectui64 rect){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint64)rect.size.width;
        ret.size.height=this->size.height*(edk::uint64)rect.size.height;
        return ret;
    }
    inline edk::rectui64 operator*(edk::uint8 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator*(edk::uint32 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator*(edk::uint16 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        return ret;
    }
    inline edk::rectui64 operator*(edk::uint64 n){
        //
        edk::rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        return ret;
    }
   inline void operator*=(edk::rectui8 rect){
        //
        this->origin.x*=(edk::uint64)rect.origin.x;
        this->origin.y*=(edk::uint64)rect.origin.y;
        this->size.width*=(edk::uint64)rect.size.width;
        this->size.height*=(edk::uint64)rect.size.height;
    }
   inline void operator*=(edk::rectui16 rect){
        //
        this->origin.x*=(edk::uint64)rect.origin.x;
        this->origin.y*=(edk::uint64)rect.origin.y;
        this->size.width*=(edk::uint64)rect.size.width;
        this->size.height*=(edk::uint64)rect.size.height;
    }
   inline void operator*=(edk::rectui32 rect){
        //
        this->origin.x*=(edk::uint64)rect.origin.x;
        this->origin.y*=(edk::uint64)rect.origin.y;
        this->size.width*=(edk::uint64)rect.size.width;
        this->size.height*=(edk::uint64)rect.size.height;
    }
   inline void operator*=(edk::rectui64 rect){
        //
        this->origin.x*=(edk::uint64)rect.origin.x;
        this->origin.y*=(edk::uint64)rect.origin.y;
        this->size.width*=(edk::uint64)rect.size.width;
        this->size.height*=(edk::uint64)rect.size.height;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
    }
    //
    inline edk::rectui64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectui64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->size.width,(edk::uint64)this->size.height);
    }
    inline edk::rectui64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        return edk::rectui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->size.width,(edk::uint64)this->size.height);
    }
    inline edk::rectui64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        return edk::rectui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->size.width,(edk::uint64)this->size.height);
    }
    inline edk::rectui64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        return edk::rectui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->size.width,(edk::uint64)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::rectui8 rect){
        if(this->origin.x > (edk::uint64)rect.origin.x)this->origin.x = (edk::uint64)rect.origin.x;
        if(this->origin.y > (edk::uint64)rect.origin.y)this->origin.y = (edk::uint64)rect.origin.y;
        if(this->size.width < (edk::uint64)rect.size.width)this->size.width = (edk::uint64)rect.size.width;
        if(this->size.height < (edk::uint64)rect.size.height)this->size.height = (edk::uint64)rect.size.height;
    }
    void merge(edk::rectui16 rect){
        if(this->origin.x > (edk::uint64)rect.origin.x)this->origin.x = (edk::uint64)rect.origin.x;
        if(this->origin.y > (edk::uint64)rect.origin.y)this->origin.y = (edk::uint64)rect.origin.y;
        if(this->size.width < (edk::uint64)rect.size.width)this->size.width = (edk::uint64)rect.size.width;
        if(this->size.height < (edk::uint64)rect.size.height)this->size.height = (edk::uint64)rect.size.height;
    }
    void merge(edk::rectui32 rect){
        if(this->origin.x > (edk::uint64)rect.origin.x)this->origin.x = (edk::uint64)rect.origin.x;
        if(this->origin.y > (edk::uint64)rect.origin.y)this->origin.y = (edk::uint64)rect.origin.y;
        if(this->size.width < (edk::uint64)rect.size.width)this->size.width = (edk::uint64)rect.size.width;
        if(this->size.height < (edk::uint64)rect.size.height)this->size.height = (edk::uint64)rect.size.height;
    }
    void merge(edk::rectui64 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2ui8 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2ui16 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2ui32 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2ui64 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2ui8 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2ui16 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2ui32 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    void merge(edk::size2ui64 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    rectf32(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2i8 origin,edk::size2i8 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2i16 origin,edk::size2i16 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2i32 origin,edk::size2i32 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2i64 origin,edk::size2i64 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2f32 origin,edk::size2f32 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }
    rectf32(edk::vec2f64 origin,edk::size2f64 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
    }

    //operators
    inline edk::rectf32 operator=(edk::rectf32 rect){
        //
        this->origin.x=(edk::float32)rect.origin.x;
        this->origin.y=(edk::float32)rect.origin.y;
        this->size.width=(edk::float32)rect.size.width;
        this->size.height=(edk::float32)rect.size.height;
        return *this;
    }
    inline edk::rectf32 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    inline edk::rectf32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }

    inline bool operator==(edk::rectf32 rect){
        //
        return (this->origin.x>rect.origin.x-0.0001f && this->origin.x<rect.origin.x+0.0001f
                && this->origin.y>rect.origin.y-0.0001f && this->origin.y<rect.origin.y+0.0001f
                && this->size.width>rect.size.width-0.0001f && this->size.width<rect.size.width+0.0001f
                && this->size.height>rect.size.height-0.0001f && this->size.height<rect.size.height+0.0001f
                );
    }
    inline bool operator!=(edk::rectf32 rect){
        //
        return ((this->origin.x<rect.origin.x-0.0001f || this->origin.x>rect.origin.x+0.0001f)
                || (this->origin.y<rect.origin.y-0.0001f || this->origin.y>rect.origin.y+0.0001f)
                || (this->size.width<rect.size.width-0.0001f || this->size.width>rect.size.width+0.0001f)
                || (this->size.height<rect.size.height-0.0001f || this->size.height>rect.size.height+0.0001f)
                );
    }
    //Operator >
    inline bool operator>(edk::rectf32 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::rectf32 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::rectf32 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::rectf32 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::rectf32 operator+(edk::rectf32 rect){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::float32)rect.origin.y;
        ret.size.width=this->size.width+(edk::float32)rect.size.width;
        ret.size.height=this->size.height+(edk::float32)rect.size.height;
        return ret;
    }
    inline edk::rectf32 operator+(edk::float32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::float64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::int8 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::int32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::int16 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::int64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::uint8 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::uint32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::uint16 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator+(edk::uint64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
   inline void operator+=(edk::rectf32 rect){
        //
        this->origin.x+=(edk::float32)rect.origin.x;
        this->origin.y+=(edk::float32)rect.origin.y;
        this->size.width+=(edk::float32)rect.size.width;
        this->size.height+=(edk::float32)rect.size.height;
    }
   inline void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    inline edk::rectf32 operator-(edk::rectf32 rect){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::float32)rect.origin.y;
        ret.size.width=this->size.width-(edk::float32)rect.size.width;
        ret.size.height=this->size.height-(edk::float32)rect.size.height;
        return ret;
    }
    inline edk::rectf32 operator-(edk::float32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::float64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::int8 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::int32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::int16 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::int64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::uint8 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::uint32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::uint16 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator-(edk::uint64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
   inline void operator-=(edk::rectf32 vec){
        //
        this->origin.x-=(edk::float32)vec.origin.x;
        this->origin.y-=(edk::float32)vec.origin.y;
        this->size.width-=(edk::float32)vec.size.width;
        this->size.height-=(edk::float32)vec.size.height;
    }
   inline void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    inline edk::rectf32 operator*(edk::rectf32 rect){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::float32)rect.origin.y;
        ret.size.width=this->size.width*(edk::float32)rect.size.width;
        ret.size.height=this->size.height*(edk::float32)rect.size.height;
        return ret;
    }
    inline edk::rectf32 operator*(edk::float32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::float64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::int8 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::int32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::int16 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::int64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::uint8 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::uint32 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::uint16 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    inline edk::rectf32 operator*(edk::uint64 n){
        //
        edk::rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
   inline void operator*=(edk::rectf32 rect){
        //
        this->origin.x*=(edk::float32)rect.origin.x;
        this->origin.y*=(edk::float32)rect.origin.y;
        this->size.width*=(edk::float32)rect.size.width;
        this->size.height*=(edk::float32)rect.size.height;
    }
   inline void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    //
    inline edk::rectf32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::rectf32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectf32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::rectf32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectf32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::rectf32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectf32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::rectf32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectf32 operator()(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::float64 x,edk::float64 y,edk::float64 width,edk::float64 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    inline edk::rectf32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return edk::rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::rectf32 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2f32 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2f32 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
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
    rectf64(edk::vec2ui8 origin,edk::size2ui8 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2ui16 origin,edk::size2ui16 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2ui32 origin,edk::size2ui32 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2ui64 origin,edk::size2ui64 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2i8 origin,edk::size2i8 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2i16 origin,edk::size2i16 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2i32 origin,edk::size2i32 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2i64 origin,edk::size2i64 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2f32 origin,edk::size2f32 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }
    rectf64(edk::vec2f64 origin,edk::size2f64 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
    }

    //operators
    inline edk::rectf64 operator=(edk::rectf64 rect){
        //
        this->origin.x=(edk::float64)rect.origin.x;
        this->origin.y=(edk::float64)rect.origin.y;
        this->size.width=(edk::float64)rect.size.width;
        this->size.height=(edk::float64)rect.size.height;
        return *this;
    }
    inline edk::rectf64 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    inline edk::rectf64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }

    inline bool operator==(edk::rectf64 rect){
        //
        return (this->origin.x>rect.origin.x-0.000001f && this->origin.x<rect.origin.x+0.000001f
                && this->origin.y>rect.origin.y-0.000001f && this->origin.y<rect.origin.y+0.000001f
                && this->size.width>rect.size.width-0.000001f && this->size.width<rect.size.width+0.000001f
                && this->size.height>rect.size.height-0.000001f && this->size.height<rect.size.height+0.000001f
                );
    }
    inline bool operator!=(edk::rectf64 rect){
        //
        return ((this->origin.x<rect.origin.x-0.000001f || this->origin.x>rect.origin.x+0.000001f)
                || (this->origin.y<rect.origin.y-0.000001f || this->origin.y>rect.origin.y+0.000001f)
                || (this->size.width<rect.size.width-0.000001f || this->size.width>rect.size.width+0.000001f)
                || (this->size.height<rect.size.height-0.000001f || this->size.height>rect.size.height+0.000001f)
                );
    }
    //Operator >
    inline bool operator>(edk::rectf64 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator >=
    inline bool operator>=(edk::rectf64 rect){
        if(this->origin.x>rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y>=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width>=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height>=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <
    inline bool operator<(edk::rectf64 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Operator <=
    inline bool operator<=(edk::rectf64 rect){
        if(this->origin.x<rect.origin.x){
            return true;
        }
        else if(this->origin.x==rect.origin.x){
            if(this->origin.y<=rect.origin.y){
                return true;
            }
            else if(this->origin.y==rect.origin.y){
                if(this->size.width<=rect.size.width){
                    return true;
                }
                else if(this->size.width==rect.size.width){
                    if(this->size.height<=rect.size.height){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    inline edk::rectf64 operator+(edk::rectf64 rect){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::float64)rect.origin.y;
        ret.size.width=this->size.width+(edk::float64)rect.size.width;
        ret.size.height=this->size.height+(edk::float64)rect.size.height;
        return ret;
    }
    inline edk::rectf64 operator+(edk::float32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::float64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::int8 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::int32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::int16 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::int64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::uint8 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::uint32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::uint16 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator+(edk::uint64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
   inline void operator+=(edk::rectf64 rect){
        //
        this->origin.x+=(edk::float64)rect.origin.x;
        this->origin.y+=(edk::float64)rect.origin.y;
        this->size.width+=(edk::float64)rect.size.width;
        this->size.height+=(edk::float64)rect.size.height;
    }
   inline void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
   inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    inline edk::rectf64 operator-(edk::rectf64 rect){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::float64)rect.origin.y;
        ret.size.width=this->size.width-(edk::float64)rect.size.width;
        ret.size.height=this->size.height-(edk::float64)rect.size.height;
        return ret;
    }
    inline edk::rectf64 operator-(edk::float32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::float64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::int8 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::int32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::int16 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::int64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::uint8 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::uint32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::uint16 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator-(edk::uint64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
   inline void operator-=(edk::rectf64 vec){
        //
        this->origin.x-=(edk::float64)vec.origin.x;
        this->origin.y-=(edk::float64)vec.origin.y;
        this->size.width-=(edk::float64)vec.size.width;
        this->size.height-=(edk::float64)vec.size.height;
    }
   inline void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
   inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    inline edk::rectf64 operator*(edk::rectf64 rect){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::float64)rect.origin.y;
        ret.size.width=this->size.width*(edk::float64)rect.size.width;
        ret.size.height=this->size.height*(edk::float64)rect.size.height;
        return ret;
    }
    inline edk::rectf64 operator*(edk::float32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::float64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::int8 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::int32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::int16 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::int64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::uint8 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::uint32 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::uint16 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    inline edk::rectf64 operator*(edk::uint64 n){
        //
        edk::rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
   inline void operator*=(edk::rectf64 rect){
        //
        this->origin.x*=(edk::float64)rect.origin.x;
        this->origin.y*=(edk::float64)rect.origin.y;
        this->size.width*=(edk::float64)rect.size.width;
        this->size.height*=(edk::float64)rect.size.height;
    }
   inline void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
   inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    //
    inline edk::rectf64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return edk::rectf64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectf64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return edk::rectf64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectf64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return edk::rectf64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectf64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return edk::rectf64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    inline edk::rectf64 operator()(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::float64 x,edk::float64 y,edk::float64 width,edk::float64 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    inline edk::rectf64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return edk::rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    //function to merge the rect with another rect
    void merge(edk::rectf32 rect){
        if(this->origin.x > (edk::float64)rect.origin.x)this->origin.x = (edk::float64)rect.origin.x;
        if(this->origin.y > (edk::float64)rect.origin.y)this->origin.y = (edk::float64)rect.origin.y;
        if(this->size.width < (edk::float64)rect.size.width)this->size.width = (edk::float64)rect.size.width;
        if(this->size.height < (edk::float64)rect.size.height)this->size.height = (edk::float64)rect.size.height;
    }
    void merge(edk::rectf64 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
    }
    //function to merge the rect with another point
    void merge(edk::vec2f32 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    void merge(edk::vec2f64 point){
        if(this->origin.x > point.x)this->origin.x = point.x;
        if(this->origin.y > point.y)this->origin.y = point.y;
        if(this->size.width < point.x)this->size.width = point.x;
        if(this->size.height < point.y)this->size.height = point.y;
    }
    //function to merge the rect with another size
    void merge(edk::size2f64 point){
        if(this->origin.x > point.width)this->origin.x = point.width;
        if(this->origin.y > point.height)this->origin.y = point.height;
        if(this->size.width < point.width)this->size.width = point.width;
        if(this->size.height < point.height)this->size.height = point.height;
    }
    //convert the rect values
    void convertIntoPoints(){
        this->origin.x-=this->size.width*0.5f;
        this->origin.y-=this->size.height*0.5f;
        this->size.width+=this->origin.x;
        this->size.height+=this->origin.y;
    }
    void convertIntoPositionAndSize(){
        this->size.width-=this->origin.x;
        this->size.height-=this->origin.y;
        this->origin.x+=this->size.width*0.5f;
        this->origin.y+=this->size.height*0.5f;
    }
};

}//end namespace

#endif // TYPERECT_H
