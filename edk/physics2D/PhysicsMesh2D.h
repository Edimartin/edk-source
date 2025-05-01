#ifndef PHYSICSMESH2D_H
#define PHYSICSMESH2D_H

/*
Library PhysicMesh - Mesh for box2D in EDK
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
#pragma message "Inside PhysicsMesh2D"
#endif

#pragma once
#include "../shape/Polygon2DList.h"

#ifdef printMessages
#pragma message "    Compiling PhysicsMesh2D"
#endif

namespace edk{
namespace physics2D{
class vec3f32Color4f32{
public:
    edk::vec3f32 position;
    edk::color4f32 color;



    //CONSTRUTOR
    vec3f32Color4f32(){
        //zera as variaveis
        this->position.x=this->position.y=this->position.z=0; 
        this->color.r=this->color.g=this->color.b=0; 
    }
    vec3f32Color4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(int8 x,int8 y,int8 z,int8 r,int8 g,int8 b,int8 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(int16 x,int16 y,int16 z,int16 r,int16 g,int16 b,int16 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(int32 x,int32 y,int32 z,int32 r,int32 g,int32 b,int32 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(int64 x,int64 y,int64 z,int64 r,int64 g,int64 b,int64 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(uint8 x,uint8 y,uint8 z,uint8 r,uint8 g,uint8 b,uint8 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(uint16 x,uint16 y,uint16 z,uint16 r,uint16 g,uint16 b,uint16 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(uint32 x,uint32 y,uint32 z,uint32 r,uint32 g,uint32 b,uint32 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    vec3f32Color4f32(uint64 x,uint64 y,uint64 z,uint64 r,uint64 g,uint64 b,uint64 a){
        //zera as variaveis
        this->position.x=(edk::float32)x; 
        this->position.y=(edk::float32)y; 
        this->position.z=(edk::float32)z; 
        this->color.r = (edk::float32)r; 
        this->color.g = (edk::float32)g; 
        this->color.b = (edk::float32)b; 
        this->color.a = (edk::float32)a; 
    }
    //operators

    //=
    vec3f32Color4f32 operator=(vec3f32Color4f32 vec){
        this->position.x=vec.position.x; 
        this->position.y=vec.position.y; 
        this->position.z=vec.position.z; 
        this->color.r=vec.color.r; 
        this->color.g=vec.color.g; 
        this->color.b=vec.color.b; 
        this->color.a=vec.color.a; 
        return *this; 
    }
    vec3f32Color4f32 operator=(vec3f32 vec){
        this->position.x=vec.x; 
        this->position.y=vec.y; 
        this->position.z=vec.z; 
        return *this; 
    }
    vec3f32Color4f32 operator=(vec2f32 vec){
        this->position.x=vec.x; 
        this->position.y=vec.y; 
        this->position.z=0.f; 
        return *this; 
    }
    vec3f32Color4f32 operator=(vec2i8 vec){
        this->position.x=vec.x; 
        this->position.y=vec.y; 
        this->position.z=(edk::float32)0; 
        return *this; 
    }
    vec3f32Color4f32 operator=(edk::float32 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(edk::float64 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(int8 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(int16 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(int32 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(int64 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(uint8 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(uint16 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(uint32 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }
    vec3f32Color4f32 operator=(uint64 n){
        this->position.x=(edk::float32)n; 
        this->position.y=(edk::float32)n; 
        this->position.z=(edk::float32)n; 
        return *this; 
    }

    vec3f32Color4f32 operator=(color4f32 color){
        this->color.r=color.r; 
        this->color.g=color.g; 
        this->color.b=color.b; 
        this->color.a=color.a; 
        return *this; 
    }
    vec3f32Color4f32 operator=(color3f32 color){
        this->color.r=color.r; 
        this->color.g=color.g; 
        this->color.b=color.b; 
        this->color.a=1.f; 
        return *this; 
    }

    //==
    inline bool operator==(vec3f32 vec){
        return (this->position.x==vec.x&&this->position.y==vec.y&&this->position.z==vec.z); 
    }
    inline bool operator==(color4f32 color){
        return (this->color.r==color.r&&this->color.g==color.g&&this->color.b==color.b&&this->color.a==color.a); 
    }
    inline bool operator==(vec3f32Color4f32 vec){
        return (this->position.x==vec.position.x&&this->position.y==vec.position.y&&this->position.z==vec.position.z&&
                this->color.r==vec.color.r&&this->color.g==vec.color.g&&this->color.b==vec.color.b&&this->color.a==vec.color.a
                ); 
    }
    //!=
    inline bool operator!=(vec3f32 vec){
        return (this->position.x!=vec.x||this->position.y!=vec.y||this->position.z!=vec.z); 
    }
    inline bool operator!=(color4f32 color){
        return (this->color.r!=color.r||this->color.g!=color.g||this->color.b!=color.b||this->color.a!=color.a); 
    }
    inline bool operator!=(vec3f32Color4f32 vec){
        return (this->position.x!=vec.position.x||this->position.y!=vec.position.y||this->position.z!=vec.position.z||
                this->color.r!=vec.color.r||this->color.g!=vec.color.g||this->color.b!=vec.color.b||this->color.a!=vec.color.a
                ); 
    }

    //+
    vec3f32Color4f32 operator+(vec3f32Color4f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+vec.position.x; 
        ret.position.y=this->position.y+vec.position.y; 
        ret.position.z=this->position.z+vec.position.z; 
        ret.color.r=this->color.r+vec.color.r; 
        ret.color.g=this->color.g+vec.color.g; 
        ret.color.b=this->color.b+vec.color.b; 
        ret.color.a=this->color.a+vec.color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(vec3f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+vec.x; 
        ret.position.y=this->position.y+vec.y; 
        ret.position.z=this->position.z+vec.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(vec2f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+vec.x; 
        ret.position.y=this->position.y+vec.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(vec2i8 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+vec.x; 
        ret.position.y=this->position.y+vec.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(edk::float32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(edk::float64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(int8 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(int16 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(int32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(int64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(uint8 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(uint16 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(uint32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(uint64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x+n; 
        ret.position.y=this->position.y+n; 
        ret.position.z=this->position.z+n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(color4f32 color){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x; 
        ret.position.y=this->position.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r+color.r; 
        ret.color.g=this->color.g+color.g; 
        ret.color.b=this->color.b+color.b; 
        ret.color.a=this->color.a+color.a; 
        return ret;
    }
    vec3f32Color4f32 operator+(color3f32 color){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x; 
        ret.position.y=this->position.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r+color.r; 
        ret.color.g=this->color.g+color.g; 
        ret.color.b=this->color.b+color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }

    //+=
    inline void operator+=(vec3f32Color4f32 vec){
        this->position.x+=vec.position.x; 
        this->position.y+=vec.position.y; 
        this->position.z+=vec.position.z; 
    }
    inline void operator+=(vec3f32 vec){
        this->position.x+=vec.x; 
        this->position.y+=vec.y; 
        this->position.z+=vec.z; 
    }
    inline void operator+=(vec2f32 vec){
        this->position.x+=vec.x; 
        this->position.y+=vec.y; 
    }
    inline void operator+=(vec2i8 vec){
        this->position.x+=vec.x; 
        this->position.y+=vec.y; 
    }
    inline void operator+=(edk::float32 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(edk::float64 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(int8 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(int16 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(int32 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(int64 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(uint8 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(uint16 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(uint32 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(uint64 n){
        this->position.x+=(edk::float32)n; 
        this->position.y+=(edk::float32)n; 
        this->position.z+=(edk::float32)n; 
    }
    inline void operator+=(color4f32 color){
        this->color.r+=color.r; 
        this->color.g+=color.g; 
        this->color.b+=color.b; 
        this->color.a+=color.a; 
    }
    inline void operator+=(color3f32 color){
        this->color.r+=color.r; 
        this->color.g+=color.g; 
        this->color.b+=color.b; 
    }

    //-
    vec3f32Color4f32 operator-(vec3f32Color4f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-vec.position.x; 
        ret.position.y=this->position.y-vec.position.y; 
        ret.position.z=this->position.z-vec.position.z; 
        ret.color.r=this->color.r-vec.color.r; 
        ret.color.g=this->color.g-vec.color.g; 
        ret.color.b=this->color.b-vec.color.b; 
        ret.color.a=this->color.a-vec.color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(vec3f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-vec.x; 
        ret.position.y=this->position.y-vec.y; 
        ret.position.z=this->position.z-vec.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(vec2f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-vec.x; 
        ret.position.y=this->position.y-vec.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(vec2i8 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-vec.x; 
        ret.position.y=this->position.y-vec.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(edk::float32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(edk::float64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(int8 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(int16 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(int32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(int64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(uint8 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(uint16 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(uint32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(uint64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x-n; 
        ret.position.y=this->position.y-n; 
        ret.position.z=this->position.z-n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(color4f32 color){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x; 
        ret.position.y=this->position.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r-color.r; 
        ret.color.g=this->color.g-color.g; 
        ret.color.b=this->color.b-color.b; 
        ret.color.a=this->color.a-color.a; 
        return ret;
    }
    vec3f32Color4f32 operator-(color3f32 color){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x; 
        ret.position.y=this->position.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r-color.r; 
        ret.color.g=this->color.g-color.g; 
        ret.color.b=this->color.b-color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }

    //-=
    inline void operator-=(vec3f32Color4f32 vec){
        this->position.x-=vec.position.x; 
        this->position.y-=vec.position.y; 
        this->position.z-=vec.position.z; 
    }
    inline void operator-=(vec3f32 vec){
        this->position.x-=vec.x; 
        this->position.y-=vec.y; 
        this->position.z-=vec.z; 
    }
    inline void operator-=(vec2f32 vec){
        this->position.x-=vec.x; 
        this->position.y-=vec.y; 
    }
    inline void operator-=(vec2i8 vec){
        this->position.x-=vec.x; 
        this->position.y-=vec.y; 
    }
    inline void operator-=(edk::float32 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(edk::float64 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(int8 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(int16 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(int32 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(int64 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(uint8 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(uint16 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(uint32 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(uint64 n){
        this->position.x-=(edk::float32)n; 
        this->position.y-=(edk::float32)n; 
        this->position.z-=(edk::float32)n; 
    }
    inline void operator-=(color4f32 color){
        this->color.r-=color.r; 
        this->color.g-=color.g; 
        this->color.b-=color.b; 
        this->color.a-=color.a; 
    }
    inline void operator-=(color3f32 color){
        this->color.r-=color.r; 
        this->color.g-=color.g; 
        this->color.b-=color.b; 
    }

    //*
    vec3f32Color4f32 operator*(vec3f32Color4f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*vec.position.x; 
        ret.position.y=this->position.y*vec.position.y; 
        ret.position.z=this->position.z*vec.position.z; 
        ret.color.r=this->color.r*vec.color.r; 
        ret.color.g=this->color.g*vec.color.g; 
        ret.color.b=this->color.b*vec.color.b; 
        ret.color.a=this->color.a*vec.color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(vec3f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*vec.x; 
        ret.position.y=this->position.y*vec.y; 
        ret.position.z=this->position.z*vec.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(vec2f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*vec.x; 
        ret.position.y=this->position.y*vec.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(vec2i8 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*vec.x; 
        ret.position.y=this->position.y*vec.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(edk::float32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(edk::float64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(int8 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(int16 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(int32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(int64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(uint8 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(uint16 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(uint32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(uint64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x*n; 
        ret.position.y=this->position.y*n; 
        ret.position.z=this->position.z*n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(color4f32 color){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x; 
        ret.position.y=this->position.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r*color.r; 
        ret.color.g=this->color.g*color.g; 
        ret.color.b=this->color.b*color.b; 
        ret.color.a=this->color.a*color.a; 
        return ret;
    }
    vec3f32Color4f32 operator*(color3f32 color){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x; 
        ret.position.y=this->position.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r*color.r; 
        ret.color.g=this->color.g*color.g; 
        ret.color.b=this->color.b*color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }

    //*=
    inline void operator*=(vec3f32Color4f32 vec){
        this->position.x*=vec.position.x; 
        this->position.y*=vec.position.y; 
        this->position.z*=vec.position.z; 
    }
    inline void operator*=(vec3f32 vec){
        this->position.x*=vec.x; 
        this->position.y*=vec.y; 
        this->position.z*=vec.z; 
    }
    inline void operator*=(vec2f32 vec){
        this->position.x*=vec.x; 
        this->position.y*=vec.y; 
    }
    inline void operator*=(vec2i8 vec){
        this->position.x*=vec.x; 
        this->position.y*=vec.y; 
    }
    inline void operator*=(edk::float32 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(edk::float64 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(int8 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(int16 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(int32 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(int64 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(uint8 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(uint16 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(uint32 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(uint64 n){
        this->position.x*=(edk::float32)n; 
        this->position.y*=(edk::float32)n; 
        this->position.z*=(edk::float32)n; 
    }
    inline void operator*=(color4f32 color){
        this->color.r*=color.r; 
        this->color.g*=color.g; 
        this->color.b*=color.b; 
        this->color.a*=color.a; 
    }
    inline void operator*=(color3f32 color){
        this->color.r*=color.r; 
        this->color.g*=color.g; 
        this->color.b*=color.b; 
    }

    // /
    vec3f32Color4f32 operator/(vec3f32Color4f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/vec.position.x; 
        ret.position.y=this->position.y/vec.position.y; 
        ret.position.z=this->position.z/vec.position.z; 
        ret.color.r=this->color.r/vec.color.r; 
        ret.color.g=this->color.g/vec.color.g; 
        ret.color.b=this->color.b/vec.color.b; 
        ret.color.a=this->color.a/vec.color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(vec3f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/vec.x; 
        ret.position.y=this->position.y/vec.y; 
        ret.position.z=this->position.z/vec.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(vec2f32 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/vec.x; 
        ret.position.y=this->position.y/vec.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(vec2i8 vec){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/vec.x; 
        ret.position.y=this->position.y/vec.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(edk::float32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(edk::float64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(int8 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(int16 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(int32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(int64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(uint8 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(uint16 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(uint32 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(uint64 n){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x/n; 
        ret.position.y=this->position.y/n; 
        ret.position.z=this->position.z/n; 
        ret.color.r=this->color.r; 
        ret.color.g=this->color.g; 
        ret.color.b=this->color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(color4f32 color){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x; 
        ret.position.y=this->position.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r/color.r; 
        ret.color.g=this->color.g/color.g; 
        ret.color.b=this->color.b/color.b; 
        ret.color.a=this->color.a/color.a; 
        return ret;
    }
    vec3f32Color4f32 operator/(color3f32 color){
        vec3f32Color4f32 ret; 
        ret.position.x=this->position.x; 
        ret.position.y=this->position.y; 
        ret.position.z=this->position.z; 
        ret.color.r=this->color.r/color.r; 
        ret.color.g=this->color.g/color.g; 
        ret.color.b=this->color.b/color.b; 
        ret.color.a=this->color.a; 
        return ret;
    }

    // /=
    inline void operator/=(vec3f32Color4f32 vec){
        this->position.x/=vec.position.x; 
        this->position.y/=vec.position.y; 
        this->position.z/=vec.position.z; 
    }
    inline void operator/=(vec3f32 vec){
        this->position.x/=vec.x; 
        this->position.y/=vec.y; 
        this->position.z/=vec.z; 
    }
    inline void operator/=(vec2f32 vec){
        this->position.x/=vec.x; 
        this->position.y/=vec.y; 
    }
    inline void operator/=(vec2i8 vec){
        this->position.x/=vec.x; 
        this->position.y/=vec.y; 
    }
    inline void operator/=(edk::float32 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(edk::float64 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(int8 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(int16 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(int32 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(int64 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(uint8 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(uint16 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(uint32 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(uint64 n){
        this->position.x/=(edk::float32)n; 
        this->position.y/=(edk::float32)n; 
        this->position.z/=(edk::float32)n; 
    }
    inline void operator/=(color4f32 color){
        this->color.r/=color.r; 
        this->color.g/=color.g; 
        this->color.b/=color.b; 
        this->color.a/=color.a; 
    }
    inline void operator/=(color3f32 color){
        this->color.r/=color.r; 
        this->color.g/=color.g; 
        this->color.b/=color.b; 
    }

    //++
    vec3f32Color4f32 operator++(){
        ++this->position.x; 
        ++this->position.y; 
        ++this->position.z; 
        ++this->color.r; 
        ++this->color.g; 
        ++this->color.b; 
        ++this->color.a; 
        return vec3f32Color4f32(this->position.x,this->position.y,this->position.z,this->color.r,this->color.g,this->color.b,this->color.a); 
    }
    vec3f32Color4f32 operator++(edk::int32){
        this->position.x++; 
        this->position.y++; 
        this->position.z++; 
        this->color.r++; 
        this->color.g++; 
        this->color.b++; 
        this->color.a++; 
        return vec3f32Color4f32(this->position.x,this->position.y,this->position.z,this->color.r,this->color.g,this->color.b,this->color.a); 
    }

    //--
    vec3f32Color4f32 operator--(){
        --this->position.x; 
        --this->position.y; 
        --this->position.z; 
        --this->color.r; 
        --this->color.g; 
        --this->color.b; 
        --this->color.a; 
        return vec3f32Color4f32(this->position.x,this->position.y,this->position.z,this->color.r,this->color.g,this->color.b,this->color.a); 
    }
    vec3f32Color4f32 operator--(edk::int32){
        this->position.x--; 
        this->position.y--; 
        this->position.z--; 
        this->color.r--; 
        this->color.g--; 
        this->color.b--; 
        this->color.a--; 
        return vec3f32Color4f32(this->position.x,this->position.y,this->position.z,this->color.r,this->color.g,this->color.b,this->color.a); 
    }

    //
    vec3f32Color4f32 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(int8 x,int8 y,int8 z,int8 r,int8 g,int8 b,int8 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(int16 x,int16 y,int16 z,int16 r,int16 g,int16 b,int16 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(int32 x,int32 y,int32 z,int32 r,int32 g,int32 b,int32 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(int64 x,int64 y,int64 z,int64 r,int64 g,int64 b,int64 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(uint8 x,uint8 y,uint8 z,uint8 r,uint8 g,uint8 b,uint8 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(uint16 x,uint16 y,uint16 z,uint16 r,uint16 g,uint16 b,uint16 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(uint32 x,uint32 y,uint32 z,uint32 r,uint32 g,uint32 b,uint32 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
    vec3f32Color4f32 operator()(uint64 x,uint64 y,uint64 z,uint64 r,uint64 g,uint64 b,uint64 a){
        this->position.x=x; 
        this->position.y=y; 
        this->position.z=z; 
        this->color.r=r; 
        this->color.g=g; 
        this->color.b=b; 
        this->color.a=a; 
        return vec3f32Color4f32((edk::float32)this->position.x,(edk::float32)this->position.y,(edk::float32)this->position.z,
                                (edk::float32)this->color.r,(edk::float32)this->color.g,(edk::float32)this->color.b,(edk::float32)this->color.a
                                ); 
    }
};
class PhysicsMesh2D : public edk::shape::Polygon2DList{
public:
    PhysicsMesh2D();
    ~PhysicsMesh2D();

    void Constructor();
    void Destructor();

    //ADD
    //add a polygon to the phisics mesh
    edk::uint32 addPolygon(edk::shape::Polygon2D polygon);

private:
    //tree to sabe the vertex in convex order
    class ConvexTree:public edk::vector::BinaryTree<edk::physics2D::vec3f32Color4f32*>{
    public:
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::physics2D::vec3f32Color4f32* first,edk::physics2D::vec3f32Color4f32* second){
            if(first->position.z>second->position.z){
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::physics2D::vec3f32Color4f32* first,edk::physics2D::vec3f32Color4f32* second){
            if(first->position.x==second->position.x
                    &&
                    first->position.y==second->position.y
                    &&
                    first->position.z==second->position.z
                    ){
                return true;
            }
            return false;
        }
    };
private:
    edk::classID classThis;
};
}
}

#endif // PHYSICSMESH_H
