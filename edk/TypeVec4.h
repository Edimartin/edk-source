#ifndef EDK_TYPEVEC4_H
#define EDK_TYPEVEC4_H

/*
Library C++ typeVec4 - 4D vectors used in Edk Game Engine
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
#warning "Inside TypesVec4"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeVec2.h"
#include "TypeVec3.h"

#ifdef printMessages
#warning "    Compiling TypesVec4"
#endif

namespace edk{
    //
	//vec4i8
	class vec4i8{
		//
		public:
			int8 x,y,z,w;

			//CONSTRUTOR
			vec4i8(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4i8(int8 x,int8 y,int8 z,int8 w){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
				this->z=(int8)z;
				this->w=(int8)w;
			}
			vec4i8(int16 x,int16 y,int16 z,int16 w){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
				this->z=(int8)z;
				this->w=(int8)w;
			}
			vec4i8(int32 x,int32 y,int32 z,int32 w){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
				this->z=(int8)z;
				this->w=(int8)w;
			}
			vec4i8(int64 x,int64 y,int64 z,int64 w){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
				this->z=(int8)z;
				this->w=(int8)w;
			}
			vec4i8(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
				this->z=(int8)z;
				this->w=(int8)w;
			}
			vec4i8(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
				this->z=(int8)z;
				this->w=(int8)w;
			}
			vec4i8(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
				this->z=(int8)z;
				this->w=(int8)w;
			}
			vec4i8(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
				this->z=(int8)z;
				this->w=(int8)w;
			}
			//operators

			//=
            vec4i8 operator=(vec4i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4i8 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4i8 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4i8 operator=(int8 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
				this->z=(int8)n;
				this->w=(int8)n;
                return *this;
			}
            vec4i8 operator=(int16 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
				this->z=(int8)n;
				this->w=(int8)n;
                return *this;
			}
            vec4i8 operator=(int32 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
				this->z=(int8)n;
				this->w=(int8)n;
                return *this;
			}
            vec4i8 operator=(int64 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
				this->z=(int8)n;
				this->w=(int8)n;
                return *this;
			}
            vec4i8 operator=(uint8 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
				this->z=(int8)n;
				this->w=(int8)n;
                return *this;
			}
            vec4i8 operator=(uint16 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
				this->z=(int8)n;
				this->w=(int8)n;
                return *this;
			}
            vec4i8 operator=(uint32 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
				this->z=(int8)n;
				this->w=(int8)n;
                return *this;
			}
            vec4i8 operator=(uint64 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
				this->z=(int8)n;
				this->w=(int8)n;
                return *this;
			}

			//==
			bool operator==(vec4i8 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4i8 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4i8 operator+(vec4i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i8 operator+(vec3i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4i8 operator+(vec2i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4i8 operator+(int8 n){
				//
				vec4i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				ret.z=this->z+(int8)n;
				ret.w=this->w+(int8)n;
				return ret;
			}
			vec4i8 operator+(int16 n){
				//
				vec4i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				ret.z=this->z+(int8)n;
				ret.w=this->w+(int8)n;
				return ret;
			}
			vec4i8 operator+(int32 n){
				//
				vec4i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				ret.z=this->z+(int8)n;
				ret.w=this->w+(int8)n;
				return ret;
			}
			vec4i8 operator+(int64 n){
				//
				vec4i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				ret.z=this->z+(int8)n;
				ret.w=this->w+(int8)n;
				return ret;
			}
			vec4i8 operator+(uint8 n){
				//
				vec4i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				ret.z=this->z+(int8)n;
				ret.w=this->w+(int8)n;
				return ret;
			}
			vec4i8 operator+(uint16 n){
				//
				vec4i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				ret.z=this->z+(int8)n;
				ret.w=this->w+(int8)n;
				return ret;
			}
			vec4i8 operator+(uint32 n){
				//
				vec4i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				ret.z=this->z+(int8)n;
				ret.w=this->w+(int8)n;
				return ret;
			}
			vec4i8 operator+(uint64 n){
				//
				vec4i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				ret.z=this->z+(int8)n;
				ret.w=this->w+(int8)n;
				return ret;
			}

            //+=
			void operator+=(vec4i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(int8 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
				this->z+=(int8)n;
				this->w+=(int8)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
				this->z+=(int8)n;
				this->w+=(int8)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
				this->z+=(int8)n;
				this->w+=(int8)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
				this->z+=(int8)n;
				this->w+=(int8)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
				this->z+=(int8)n;
				this->w+=(int8)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
				this->z+=(int8)n;
				this->w+=(int8)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
				this->z+=(int8)n;
				this->w+=(int8)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
				this->z+=(int8)n;
				this->w+=(int8)n;
			}

			//-
			vec4i8 operator-(vec4i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i8 operator-(vec3i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4i8 operator-(vec2i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4i8 operator-(int8 n){
				//
				vec4i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				ret.z=this->z-(int8)n;
				ret.w=this->w-(int8)n;
				return ret;
			}
			vec4i8 operator-(int16 n){
				//
				vec4i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				ret.z=this->z-(int8)n;
				ret.w=this->w-(int8)n;
				return ret;
			}
			vec4i8 operator-(int32 n){
				//
				vec4i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				ret.z=this->z-(int8)n;
				ret.w=this->w-(int8)n;
				return ret;
			}
			vec4i8 operator-(int64 n){
				//
				vec4i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				ret.z=this->z-(int8)n;
				ret.w=this->w-(int8)n;
				return ret;
			}
			vec4i8 operator-(uint8 n){
				//
				vec4i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				ret.z=this->z-(int8)n;
				ret.w=this->w-(int8)n;
				return ret;
			}
			vec4i8 operator-(uint16 n){
				//
				vec4i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				ret.z=this->z-(int8)n;
				ret.w=this->w-(int8)n;
				return ret;
			}
			vec4i8 operator-(uint32 n){
				//
				vec4i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				ret.z=this->z-(int8)n;
				ret.w=this->w-(int8)n;
				return ret;
			}
			vec4i8 operator-(uint64 n){
				//
				vec4i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				ret.z=this->z-(int8)n;
				ret.w=this->w-(int8)n;
				return ret;
			}

			//-=
			void operator-=(vec4i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(int8 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
				this->z-=(int8)n;
				this->w-=(int8)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
				this->z-=(int8)n;
				this->w-=(int8)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
				this->z-=(int8)n;
				this->w-=(int8)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
				this->z-=(int8)n;
				this->w-=(int8)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
				this->z-=(int8)n;
				this->w-=(int8)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
				this->z-=(int8)n;
				this->w-=(int8)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
				this->z-=(int8)n;
				this->w-=(int8)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
				this->z-=(int8)n;
				this->w-=(int8)n;
			}

			//*
			vec4i8 operator*(vec4i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i8 operator*(vec3i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4i8 operator*(vec2i8 vec){
				//
				vec4i8 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4i8 operator*(int8 n){
				//
				vec4i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				ret.z=this->z*(int8)n;
				ret.w=this->w*(int8)n;
				return ret;
			}
			vec4i8 operator*(int16 n){
				//
				vec4i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				ret.z=this->z*(int8)n;
				ret.w=this->w*(int8)n;
				return ret;
			}
			vec4i8 operator*(int32 n){
				//
				vec4i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				ret.z=this->z*(int8)n;
				ret.w=this->w*(int8)n;
				return ret;
			}
			vec4i8 operator*(int64 n){
				//
				vec4i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				ret.z=this->z*(int8)n;
				ret.w=this->w*(int8)n;
				return ret;
			}
			vec4i8 operator*(uint8 n){
				//
				vec4i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				ret.z=this->z*(int8)n;
				ret.w=this->w*(int8)n;
				return ret;
			}
			vec4i8 operator*(uint16 n){
				//
				vec4i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				ret.z=this->z*(int8)n;
				ret.w=this->w*(int8)n;
				return ret;
			}
			vec4i8 operator*(uint32 n){
				//
				vec4i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				ret.z=this->z*(int8)n;
				ret.w=this->w*(int8)n;
				return ret;
			}
			vec4i8 operator*(uint64 n){
				//
				vec4i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				ret.z=this->z*(int8)n;
				ret.w=this->w*(int8)n;
				return ret;
			}

			//*=
			void operator*=(vec4i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(int8 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
				this->z*=(int8)n;
				this->w*=(int8)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
				this->z*=(int8)n;
				this->w*=(int8)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
				this->z*=(int8)n;
				this->w*=(int8)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
				this->z*=(int8)n;
				this->w*=(int8)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
				this->z*=(int8)n;
				this->w*=(int8)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
				this->z*=(int8)n;
				this->w*=(int8)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
				this->z*=(int8)n;
				this->w*=(int8)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
				this->z*=(int8)n;
				this->w*=(int8)n;
			}

			//++
			vec4i8 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4i8(this->x,this->y,this->z,this->w);
			}
			vec4i8 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4i8(this->x,this->y,this->z,this->w);
			}

			//--
			vec4i8 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4i8(this->x,this->y,this->z,this->w);
			}
			vec4i8 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4i8(this->x,this->y,this->z,this->w);
			}

			//
			vec4i8 operator()(int8 x,int8 y,int8 z,int8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i8((int8)this->x,(int8)this->y,(int8)this->z,(int8)this->w);
			}
			vec4i8 operator()(int16 x,int16 y,int16 z,int16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i8((int8)this->x,(int8)this->y,(int8)this->z,(int8)this->w);
			}
			vec4i8 operator()(int32 x,int32 y,int32 z,int32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i8((int8)this->x,(int8)this->y,(int8)this->z,(int8)this->w);
			}
			vec4i8 operator()(int64 x,int64 y,int64 z,int64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i8((int8)this->x,(int8)this->y,(int8)this->z,(int8)this->w);
			}
			vec4i8 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i8((int8)this->x,(int8)this->y,(int8)this->z,(int8)this->w);
			}
			vec4i8 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i8((int8)this->x,(int8)this->y,(int8)this->z,(int8)this->w);
			}
			vec4i8 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i8((int8)this->x,(int8)this->y,(int8)this->z,(int8)this->w);
			}
			vec4i8 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i8((int8)this->x,(int8)this->y,(int8)this->z,(int8)this->w);
			}
	};

	//vec4i16
	class vec4i16{
		//
		public:
			int16 x,y,z,w;

			//CONSTRUTOR
			vec4i16(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4i16(int8 x,int8 y,int8 z,int8 w){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
				this->z=(int16)z;
				this->w=(int16)w;
			}
			vec4i16(int16 x,int16 y,int16 z,int16 w){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
				this->z=(int16)z;
				this->w=(int16)w;
			}
			vec4i16(int32 x,int32 y,int32 z,int32 w){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
				this->z=(int16)z;
				this->w=(int16)w;
			}
			vec4i16(int64 x,int64 y,int64 z,int64 w){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
				this->z=(int16)z;
				this->w=(int16)w;
			}
			vec4i16(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
				this->z=(int16)z;
				this->w=(int16)w;
			}
			vec4i16(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
				this->z=(int16)z;
				this->w=(int16)w;
			}
			vec4i16(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
				this->z=(int16)z;
				this->w=(int16)w;
			}
			vec4i16(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
				this->z=(int16)z;
				this->w=(int16)w;
			}
			//operators

			//=
            vec4i16 operator=(vec4i8 vec){
				//
				this->x=(int16)vec.x;
				this->y=(int16)vec.y;
				this->z=(int16)vec.z;
				this->w=(int16)vec.w;
                return *this;
			}
            vec4i16 operator=(vec4i16 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4i16 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4i16 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4i16 operator=(int8 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
				this->z=(int16)n;
				this->w=(int16)n;
                return *this;
			}
            vec4i16 operator=(int16 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
				this->z=(int16)n;
				this->w=(int16)n;
                return *this;
			}
            vec4i16 operator=(int32 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
				this->z=(int16)n;
				this->w=(int16)n;
                return *this;
			}
            vec4i16 operator=(int64 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
				this->z=(int16)n;
				this->w=(int16)n;
                return *this;
			}
            vec4i16 operator=(uint8 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
				this->z=(int16)n;
				this->w=(int16)n;
                return *this;
			}
            vec4i16 operator=(uint16 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
				this->z=(int16)n;
				this->w=(int16)n;
                return *this;
			}
            vec4i16 operator=(uint32 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
				this->z=(int16)n;
				this->w=(int16)n;
                return *this;
			}
            vec4i16 operator=(uint64 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
				this->z=(int16)n;
				this->w=(int16)n;
                return *this;
			}

			//==
			bool operator==(vec4i8 vec){
				//
				return (this->x==(int16)vec.x&&this->y==(int16)vec.y&&this->z==(int16)vec.z&&this->w==(int16)vec.w);
			}
			bool operator==(vec4i16 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4i8 vec){
				//
				return (this->x!=(int16)vec.x||this->y!=(int16)vec.y||this->z!=(int16)vec.z||this->w!=(int16)vec.w);
			}
			bool operator!=(vec4i16 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4i16 operator+(vec4i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)vec.x;
				ret.y=this->y+(int16)vec.y;
				ret.z=this->z+(int16)vec.z;
				ret.w=this->w+(int16)vec.w;
				return ret;
			}
			vec4i16 operator+(vec4i16 vec){
				//
				vec4i16 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i16 operator+(vec3i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4i16 operator+(vec2i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4i16 operator+(int8 n){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				ret.z=this->z+(int16)n;
				ret.w=this->w+(int16)n;
				return ret;
			}
			vec4i16 operator+(int16 n){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				ret.z=this->z+(int16)n;
				ret.w=this->w+(int16)n;
				return ret;
			}
			vec4i16 operator+(int32 n){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				ret.z=this->z+(int16)n;
				ret.w=this->w+(int16)n;
				return ret;
			}
			vec4i16 operator+(int64 n){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				ret.z=this->z+(int16)n;
				ret.w=this->w+(int16)n;
				return ret;
			}
			vec4i16 operator+(uint8 n){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				ret.z=this->z+(int16)n;
				ret.w=this->w+(int16)n;
				return ret;
			}
			vec4i16 operator+(uint16 n){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				ret.z=this->z+(int16)n;
				ret.w=this->w+(int16)n;
				return ret;
			}
			vec4i16 operator+(uint32 n){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				ret.z=this->z+(int16)n;
				ret.w=this->w+(int16)n;
				return ret;
			}
			vec4i16 operator+(uint64 n){
				//
				vec4i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				ret.z=this->z+(int16)n;
				ret.w=this->w+(int16)n;
				return ret;
			}

            //+=
			void operator+=(vec4i8 vec){
				//
				this->x+=(int16)vec.x;
				this->y+=(int16)vec.y;
				this->z+=(int16)vec.z;
				this->w+=(int16)vec.w;
			}
			void operator+=(vec4i16 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(int8 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
				this->z+=(int16)n;
				this->w+=(int16)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
				this->z+=(int16)n;
				this->w+=(int16)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
				this->z+=(int16)n;
				this->w+=(int16)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
				this->z+=(int16)n;
				this->w+=(int16)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
				this->z+=(int16)n;
				this->w+=(int16)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
				this->z+=(int16)n;
				this->w+=(int16)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
				this->z+=(int16)n;
				this->w+=(int16)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
				this->z+=(int16)n;
				this->w+=(int16)n;
			}

			//-
			vec4i16 operator-(vec4i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)vec.x;
				ret.y=this->y-(int16)vec.y;
				ret.z=this->z-(int16)vec.z;
				ret.w=this->w-(int16)vec.w;
				return ret;
			}
			vec4i16 operator-(vec4i16 vec){
				//
				vec4i16 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i16 operator-(vec3i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4i16 operator-(vec2i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4i16 operator-(int8 n){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				ret.z=this->z-(int16)n;
				ret.w=this->w-(int16)n;
				return ret;
			}
			vec4i16 operator-(int16 n){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				ret.z=this->z-(int16)n;
				ret.w=this->w-(int16)n;
				return ret;
			}
			vec4i16 operator-(int32 n){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				ret.z=this->z-(int16)n;
				ret.w=this->w-(int16)n;
				return ret;
			}
			vec4i16 operator-(int64 n){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				ret.z=this->z-(int16)n;
				ret.w=this->w-(int16)n;
				return ret;
			}
			vec4i16 operator-(uint8 n){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				ret.z=this->z-(int16)n;
				ret.w=this->w-(int16)n;
				return ret;
			}
			vec4i16 operator-(uint16 n){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				ret.z=this->z-(int16)n;
				ret.w=this->w-(int16)n;
				return ret;
			}
			vec4i16 operator-(uint32 n){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				ret.z=this->z-(int16)n;
				ret.w=this->w-(int16)n;
				return ret;
			}
			vec4i16 operator-(uint64 n){
				//
				vec4i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				ret.z=this->z-(int16)n;
				ret.w=this->w-(int16)n;
				return ret;
			}

			//-=
			void operator-=(vec4i8 vec){
				//
				this->x-=(int16)vec.x;
				this->y-=(int16)vec.y;
				this->z-=(int16)vec.z;
				this->w-=(int16)vec.w;
			}
			void operator-=(vec4i16 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(int8 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
				this->z-=(int16)n;
				this->w-=(int16)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
				this->z-=(int16)n;
				this->w-=(int16)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
				this->z-=(int16)n;
				this->w-=(int16)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
				this->z-=(int16)n;
				this->w-=(int16)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
				this->z-=(int16)n;
				this->w-=(int16)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
				this->z-=(int16)n;
				this->w-=(int16)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
				this->z-=(int16)n;
				this->w-=(int16)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
				this->z-=(int16)n;
				this->w-=(int16)n;
			}

			//*
			vec4i16 operator*(vec4i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)vec.x;
				ret.y=this->y*(int16)vec.y;
				ret.z=this->z*(int16)vec.z;
				ret.w=this->w*(int16)vec.w;
				return ret;
			}
			vec4i16 operator*(vec4i16 vec){
				//
				vec4i16 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i16 operator*(vec3i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4i16 operator*(vec2i8 vec){
				//
				vec4i16 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4i16 operator*(int8 n){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				ret.z=this->z*(int16)n;
				ret.w=this->w*(int16)n;
				return ret;
			}
			vec4i16 operator*(int16 n){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				ret.z=this->z*(int16)n;
				ret.w=this->w*(int16)n;
				return ret;
			}
			vec4i16 operator*(int32 n){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				ret.z=this->z*(int16)n;
				ret.w=this->w*(int16)n;
				return ret;
			}
			vec4i16 operator*(int64 n){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				ret.z=this->z*(int16)n;
				ret.w=this->w*(int16)n;
				return ret;
			}
			vec4i16 operator*(uint8 n){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				ret.z=this->z*(int16)n;
				ret.w=this->w*(int16)n;
				return ret;
			}
			vec4i16 operator*(uint16 n){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				ret.z=this->z*(int16)n;
				ret.w=this->w*(int16)n;
				return ret;
			}
			vec4i16 operator*(uint32 n){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				ret.z=this->z*(int16)n;
				ret.w=this->w*(int16)n;
				return ret;
			}
			vec4i16 operator*(uint64 n){
				//
				vec4i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				ret.z=this->z*(int16)n;
				ret.w=this->w*(int16)n;
				return ret;
			}

			//*=
			void operator*=(vec4i8 vec){
				//
				this->x*=(int16)vec.x;
				this->y*=(int16)vec.y;
				this->z*=(int16)vec.z;
				this->w*=(int16)vec.w;
			}
			void operator*=(vec4i16 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(int8 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
				this->z*=(int16)n;
				this->w*=(int16)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
				this->z*=(int16)n;
				this->w*=(int16)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
				this->z*=(int16)n;
				this->w*=(int16)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
				this->z*=(int16)n;
				this->w*=(int16)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
				this->z*=(int16)n;
				this->w*=(int16)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
				this->z*=(int16)n;
				this->w*=(int16)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
				this->z*=(int16)n;
				this->w*=(int16)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
				this->z*=(int16)n;
				this->w*=(int16)n;
			}

			//++
			vec4i16 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4i16(this->x,this->y,this->z,this->w);
			}
			vec4i16 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4i16(this->x,this->y,this->z,this->w);
			}

			//--
			vec4i16 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4i16(this->x,this->y,this->z,this->w);
			}
			vec4i16 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4i16(this->x,this->y,this->z,this->w);
			}

			//
			vec4i16 operator()(int8 x,int8 y,int8 z,int8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i16((int16)this->x,(int16)this->y,(int16)this->z,(int16)this->w);
			}
			vec4i16 operator()(int16 x,int16 y,int16 z,int16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i16((int16)this->x,(int16)this->y,(int16)this->z,(int16)this->w);
			}
			vec4i16 operator()(int32 x,int32 y,int32 z,int32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i16((int16)this->x,(int16)this->y,(int16)this->z,(int16)this->w);
			}
			vec4i16 operator()(int64 x,int64 y,int64 z,int64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i16((int16)this->x,(int16)this->y,(int16)this->z,(int16)this->w);
			}
			vec4i16 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i16((int16)this->x,(int16)this->y,(int16)this->z,(int16)this->w);
			}
			vec4i16 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i16((int16)this->x,(int16)this->y,(int16)this->z,(int16)this->w);
			}
			vec4i16 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i16((int16)this->x,(int16)this->y,(int16)this->z,(int16)this->w);
			}
			vec4i16 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i16((int16)this->x,(int16)this->y,(int16)this->z,(int16)this->w);
			}
	};

	//vec4i32
	class vec4i32{
		//
		public:
			int32 x,y,z,w;

			//CONSTRUTOR
			vec4i32(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4i32(int8 x,int8 y,int8 z,int8 w){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
				this->z=(int32)z;
				this->w=(int32)w;
			}
			vec4i32(int16 x,int16 y,int16 z,int16 w){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
				this->z=(int32)z;
				this->w=(int32)w;
			}
			vec4i32(int32 x,int32 y,int32 z,int32 w){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
				this->z=(int32)z;
				this->w=(int32)w;
			}
			vec4i32(int64 x,int64 y,int64 z,int64 w){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
				this->z=(int32)z;
				this->w=(int32)w;
			}
			vec4i32(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
				this->z=(int32)z;
				this->w=(int32)w;
			}
			vec4i32(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
				this->z=(int32)z;
				this->w=(int32)w;
			}
			vec4i32(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
				this->z=(int32)z;
				this->w=(int32)w;
			}
			vec4i32(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
				this->z=(int32)z;
				this->w=(int32)w;
			}
			//operators

			//=
            vec4i32 operator=(vec4i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4i32 operator=(vec4i16 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4i32 operator=(vec4i32 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4i32 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4i32 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4i32 operator=(int8 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
				this->z=(int32)n;
				this->w=(int32)n;
                return *this;
			}
            vec4i32 operator=(int16 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
				this->z=(int32)n;
				this->w=(int32)n;
                return *this;
			}
            vec4i32 operator=(int32 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
				this->z=(int32)n;
				this->w=(int32)n;
                return *this;
			}
            vec4i32 operator=(int64 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
				this->z=(int32)n;
				this->w=(int32)n;
                return *this;
			}
            vec4i32 operator=(uint8 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
				this->z=(int32)n;
				this->w=(int32)n;
                return *this;
			}
            vec4i32 operator=(uint16 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
				this->z=(int32)n;
				this->w=(int32)n;
                return *this;
			}
            vec4i32 operator=(uint32 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
				this->z=(int32)n;
				this->w=(int32)n;
                return *this;
			}
            vec4i32 operator=(uint64 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
				this->z=(int32)n;
				this->w=(int32)n;
                return *this;
			}

			//==
			bool operator==(vec4i8 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4i16 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4i32 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4i8 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4i16 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4i32 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4i32 operator+(vec4i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i32 operator+(vec4i16 vec){
				//
				vec4i32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i32 operator+(vec4i32 vec){
				//
				vec4i32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i32 operator+(vec3i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4i32 operator+(vec2i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4i32 operator+(int8 n){
				//
				vec4i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				ret.z=this->z+(int32)n;
				ret.w=this->w+(int32)n;
				return ret;
			}
			vec4i32 operator+(int16 n){
				//
				vec4i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				ret.z=this->z+(int32)n;
				ret.w=this->w+(int32)n;
				return ret;
			}
			vec4i32 operator+(int32 n){
				//
				vec4i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				ret.z=this->z+(int32)n;
				ret.w=this->w+(int32)n;
				return ret;
			}
			vec4i32 operator+(int64 n){
				//
				vec4i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				ret.z=this->z+(int32)n;
				ret.w=this->w+(int32)n;
				return ret;
			}
			vec4i32 operator+(uint8 n){
				//
				vec4i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				ret.z=this->z+(int32)n;
				ret.w=this->w+(int32)n;
				return ret;
			}
			vec4i32 operator+(uint16 n){
				//
				vec4i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				ret.z=this->z+(int32)n;
				ret.w=this->w+(int32)n;
				return ret;
			}
			vec4i32 operator+(uint32 n){
				//
				vec4i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				ret.z=this->z+(int32)n;
				ret.w=this->w+(int32)n;
				return ret;
			}
			vec4i32 operator+(uint64 n){
				//
				vec4i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				ret.z=this->z+(int32)n;
				ret.w=this->w+(int32)n;
				return ret;
			}

            //+=
			void operator+=(vec4i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4i16 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4i32 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(int8 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
				this->z+=(int32)n;
				this->w+=(int32)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
				this->z+=(int32)n;
				this->w+=(int32)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
				this->z+=(int32)n;
				this->w+=(int32)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
				this->z+=(int32)n;
				this->w+=(int32)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
				this->z+=(int32)n;
				this->w+=(int32)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
				this->z+=(int32)n;
				this->w+=(int32)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
				this->z+=(int32)n;
				this->w+=(int32)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
				this->z+=(int32)n;
				this->w+=(int32)n;
			}

			//-
			vec4i32 operator-(vec4i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i32 operator-(vec4i16 vec){
				//
				vec4i32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i32 operator-(vec4i32 vec){
				//
				vec4i32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i32 operator-(vec3i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4i32 operator-(vec2i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4i32 operator-(int8 n){
				//
				vec4i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				ret.z=this->z-(int32)n;
				ret.w=this->w-(int32)n;
				return ret;
			}
			vec4i32 operator-(int16 n){
				//
				vec4i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				ret.z=this->z-(int32)n;
				ret.w=this->w-(int32)n;
				return ret;
			}
			vec4i32 operator-(int32 n){
				//
				vec4i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				ret.z=this->z-(int32)n;
				ret.w=this->w-(int32)n;
				return ret;
			}
			vec4i32 operator-(int64 n){
				//
				vec4i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				ret.z=this->z-(int32)n;
				ret.w=this->w-(int32)n;
				return ret;
			}
			vec4i32 operator-(uint8 n){
				//
				vec4i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				ret.z=this->z-(int32)n;
				ret.w=this->w-(int32)n;
				return ret;
			}
			vec4i32 operator-(uint16 n){
				//
				vec4i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				ret.z=this->z-(int32)n;
				ret.w=this->w-(int32)n;
				return ret;
			}
			vec4i32 operator-(uint32 n){
				//
				vec4i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				ret.z=this->z-(int32)n;
				ret.w=this->w-(int32)n;
				return ret;
			}
			vec4i32 operator-(uint64 n){
				//
				vec4i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				ret.z=this->z-(int32)n;
				ret.w=this->w-(int32)n;
				return ret;
			}

			//-=
			void operator-=(vec4i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4i16 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4i32 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(int8 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
				this->z-=(int32)n;
				this->w-=(int32)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
				this->z-=(int32)n;
				this->w-=(int32)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
				this->z-=(int32)n;
				this->w-=(int32)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
				this->z-=(int32)n;
				this->w-=(int32)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
				this->z-=(int32)n;
				this->w-=(int32)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
				this->z-=(int32)n;
				this->w-=(int32)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
				this->z-=(int32)n;
				this->w-=(int32)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
				this->z-=(int32)n;
				this->w-=(int32)n;
			}

			//*
			vec4i32 operator*(vec4i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i32 operator*(vec4i16 vec){
				//
				vec4i32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i32 operator*(vec4i32 vec){
				//
				vec4i32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i32 operator*(vec3i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4i32 operator*(vec2i8 vec){
				//
				vec4i32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4i32 operator*(int8 n){
				//
				vec4i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				ret.z=this->z*(int32)n;
				ret.w=this->w*(int32)n;
				return ret;
			}
			vec4i32 operator*(int16 n){
				//
				vec4i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				ret.z=this->z*(int32)n;
				ret.w=this->w*(int32)n;
				return ret;
			}
			vec4i32 operator*(int32 n){
				//
				vec4i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				ret.z=this->z*(int32)n;
				ret.w=this->w*(int32)n;
				return ret;
			}
			vec4i32 operator*(int64 n){
				//
				vec4i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				ret.z=this->z*(int32)n;
				ret.w=this->w*(int32)n;
				return ret;
			}
			vec4i32 operator*(uint8 n){
				//
				vec4i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				ret.z=this->z*(int32)n;
				ret.w=this->w*(int32)n;
				return ret;
			}
			vec4i32 operator*(uint16 n){
				//
				vec4i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				ret.z=this->z*(int32)n;
				ret.w=this->w*(int32)n;
				return ret;
			}
			vec4i32 operator*(uint32 n){
				//
				vec4i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				ret.z=this->z*(int32)n;
				ret.w=this->w*(int32)n;
				return ret;
			}
			vec4i32 operator*(uint64 n){
				//
				vec4i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				ret.z=this->z*(int32)n;
				ret.w=this->w*(int32)n;
				return ret;
			}

			//*=
			void operator*=(vec4i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4i16 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4i32 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(int8 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
				this->z*=(int32)n;
				this->w*=(int32)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
				this->z*=(int32)n;
				this->w*=(int32)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
				this->z*=(int32)n;
				this->w*=(int32)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
				this->z*=(int32)n;
				this->w*=(int32)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
				this->z*=(int32)n;
				this->w*=(int32)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
				this->z*=(int32)n;
				this->w*=(int32)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
				this->z*=(int32)n;
				this->w*=(int32)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
				this->z*=(int32)n;
				this->w*=(int32)n;
			}

			//++
			vec4i32 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4i32(this->x,this->y,this->z,this->w);
			}
			vec4i32 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4i32(this->x,this->y,this->z,this->w);
			}

			//--
			vec4i32 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4i32(this->x,this->y,this->z,this->w);
			}
			vec4i32 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4i32(this->x,this->y,this->z,this->w);
			}

			//
			vec4i32 operator()(int8 x,int8 y,int8 z,int8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i32((int32)this->x,(int32)this->y,(int32)this->z,(int32)this->w);
			}
			vec4i32 operator()(int16 x,int16 y,int16 z,int16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i32((int32)this->x,(int32)this->y,(int32)this->z,(int32)this->w);
			}
			vec4i32 operator()(int32 x,int32 y,int32 z,int32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i32((int32)this->x,(int32)this->y,(int32)this->z,(int32)this->w);
			}
			vec4i32 operator()(int64 x,int64 y,int64 z,int64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i32((int32)this->x,(int32)this->y,(int32)this->z,(int32)this->w);
			}
			vec4i32 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i32((int32)this->x,(int32)this->y,(int32)this->z,(int32)this->w);
			}
			vec4i32 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i32((int32)this->x,(int32)this->y,(int32)this->z,(int32)this->w);
			}
			vec4i32 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i32((int32)this->x,(int32)this->y,(int32)this->z,(int32)this->w);
			}
			vec4i32 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i32((int32)this->x,(int32)this->y,(int32)this->z,(int32)this->w);
			}
	};

	//vec4i64
	class vec4i64{
		//
		public:
			int64 x,y,z,w;

			//CONSTRUTOR
			vec4i64(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4i64(int8 x,int8 y,int8 z,int8 w){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
				this->z=(int64)z;
				this->w=(int64)w;
			}
			vec4i64(int16 x,int16 y,int16 z,int16 w){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
				this->z=(int64)z;
				this->w=(int64)w;
			}
			vec4i64(int32 x,int32 y,int32 z,int32 w){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
				this->z=(int64)z;
				this->w=(int64)w;
			}
			vec4i64(int64 x,int64 y,int64 z,int64 w){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
				this->z=(int64)z;
				this->w=(int64)w;
			}
			vec4i64(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
				this->z=(int64)z;
				this->w=(int64)w;
			}
			vec4i64(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
				this->z=(int64)z;
				this->w=(int64)w;
			}
			vec4i64(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
				this->z=(int64)z;
				this->w=(int64)w;
			}
			vec4i64(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
				this->z=(int64)z;
				this->w=(int64)w;
			}
			//operators

			//=
            vec4i64 operator=(vec4i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4i64 operator=(vec4i16 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
                this->w=vec.w;
                return *this;
			}
            vec4i64 operator=(vec4i32 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4i64 operator=(vec4i64 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4i64 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4i64 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4i64 operator=(int8 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
				this->z=(int64)n;
				this->w=(int64)n;
                return *this;
			}
            vec4i64 operator=(int16 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
				this->z=(int64)n;
				this->w=(int64)n;
                return *this;
			}
            vec4i64 operator=(int32 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
				this->z=(int64)n;
				this->w=(int64)n;
                return *this;
			}
            vec4i64 operator=(int64 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
				this->z=(int64)n;
				this->w=(int64)n;
                return *this;
			}
            vec4i64 operator=(uint8 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
				this->z=(int64)n;
				this->w=(int64)n;
                return *this;
			}
            vec4i64 operator=(uint16 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
				this->z=(int64)n;
				this->w=(int64)n;
                return *this;
			}
            vec4i64 operator=(uint32 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
				this->z=(int64)n;
				this->w=(int64)n;
                return *this;
			}
            vec4i64 operator=(uint64 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
				this->z=(int64)n;
				this->w=(int64)n;
                return *this;
			}

			//==
			bool operator==(vec4i8 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4i16 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4i32 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4i64 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4i8 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4i16 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4i32 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4i64 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4i64 operator+(vec4i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i64 operator+(vec4i16 vec){
				//
				vec4i64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i64 operator+(vec4i32 vec){
				//
				vec4i64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i64 operator+(vec4i64 vec){
				//
				vec4i64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4i64 operator+(vec3i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4i64 operator+(vec2i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4i64 operator+(int8 n){
				//
				vec4i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				ret.z=this->z+(int64)n;
				ret.w=this->w+(int64)n;
				return ret;
			}
			vec4i64 operator+(int16 n){
				//
				vec4i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				ret.z=this->z+(int64)n;
				ret.w=this->w+(int64)n;
				return ret;
			}
			vec4i64 operator+(int32 n){
				//
				vec4i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				ret.z=this->z+(int64)n;
				ret.w=this->w+(int64)n;
				return ret;
			}
			vec4i64 operator+(int64 n){
				//
				vec4i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				ret.z=this->z+(int64)n;
				ret.w=this->w+(int64)n;
				return ret;
			}
			vec4i64 operator+(uint8 n){
				//
				vec4i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				ret.z=this->z+(int64)n;
				ret.w=this->w+(int64)n;
				return ret;
			}
			vec4i64 operator+(uint16 n){
				//
				vec4i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				ret.z=this->z+(int64)n;
				ret.w=this->w+(int64)n;
				return ret;
			}
			vec4i64 operator+(uint32 n){
				//
				vec4i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				ret.z=this->z+(int64)n;
				ret.w=this->w+(int64)n;
				return ret;
			}
			vec4i64 operator+(uint64 n){
				//
				vec4i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				ret.z=this->z+(int64)n;
				ret.w=this->w+(int64)n;
				return ret;
			}

            //+=
			void operator+=(vec4i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4i16 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4i32 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4i64 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(int8 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
				this->z+=(int64)n;
				this->w+=(int64)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
				this->z+=(int64)n;
				this->w+=(int64)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
				this->z+=(int64)n;
				this->w+=(int64)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
				this->z+=(int64)n;
				this->w+=(int64)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
				this->z+=(int64)n;
				this->w+=(int64)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
				this->z+=(int64)n;
				this->w+=(int64)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
				this->z+=(int64)n;
				this->w+=(int64)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
				this->z+=(int64)n;
				this->w+=(int64)n;
			}

			//-
			vec4i64 operator-(vec4i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i64 operator-(vec4i16 vec){
				//
				vec4i64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i64 operator-(vec4i32 vec){
				//
				vec4i64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i64 operator-(vec4i64 vec){
				//
				vec4i64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4i64 operator-(vec3i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4i64 operator-(vec2i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4i64 operator-(int8 n){
				//
				vec4i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				ret.z=this->z-(int64)n;
				ret.w=this->w-(int64)n;
				return ret;
			}
			vec4i64 operator-(int16 n){
				//
				vec4i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				ret.z=this->z-(int64)n;
				ret.w=this->w-(int64)n;
				return ret;
			}
			vec4i64 operator-(int32 n){
				//
				vec4i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				ret.z=this->z-(int64)n;
				ret.w=this->w-(int64)n;
				return ret;
			}
			vec4i64 operator-(int64 n){
				//
				vec4i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				ret.z=this->z-(int64)n;
				ret.w=this->w-(int64)n;
				return ret;
			}
			vec4i64 operator-(uint8 n){
				//
				vec4i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				ret.z=this->z-(int64)n;
				ret.w=this->w-(int64)n;
				return ret;
			}
			vec4i64 operator-(uint16 n){
				//
				vec4i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				ret.z=this->z-(int64)n;
				ret.w=this->w-(int64)n;
				return ret;
			}
			vec4i64 operator-(uint32 n){
				//
				vec4i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				ret.z=this->z-(int64)n;
				ret.w=this->w-(int64)n;
				return ret;
			}
			vec4i64 operator-(uint64 n){
				//
				vec4i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				ret.z=this->z-(int64)n;
				ret.w=this->w-(int64)n;
				return ret;
			}

			//-=
			void operator-=(vec4i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4i16 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4i32 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4i64 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(int8 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
				this->z-=(int64)n;
				this->w-=(int64)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
				this->z-=(int64)n;
				this->w-=(int64)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
				this->z-=(int64)n;
				this->w-=(int64)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
				this->z-=(int64)n;
				this->w-=(int64)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
				this->z-=(int64)n;
				this->w-=(int64)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
				this->z-=(int64)n;
				this->w-=(int64)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
				this->z-=(int64)n;
				this->w-=(int64)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
				this->z-=(int64)n;
				this->w-=(int64)n;
			}

			//*
			vec4i64 operator*(vec4i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i64 operator*(vec4i16 vec){
				//
				vec4i64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i64 operator*(vec4i32 vec){
				//
				vec4i64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i64 operator*(vec4i64 vec){
				//
				vec4i64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4i64 operator*(vec3i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4i64 operator*(vec2i8 vec){
				//
				vec4i64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4i64 operator*(int8 n){
				//
				vec4i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				ret.z=this->z*(int64)n;
				ret.w=this->w*(int64)n;
				return ret;
			}
			vec4i64 operator*(int16 n){
				//
				vec4i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				ret.z=this->z*(int64)n;
				ret.w=this->w*(int64)n;
				return ret;
			}
			vec4i64 operator*(int32 n){
				//
				vec4i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				ret.z=this->z*(int64)n;
				ret.w=this->w*(int64)n;
				return ret;
			}
			vec4i64 operator*(int64 n){
				//
				vec4i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				ret.z=this->z*(int64)n;
				ret.w=this->w*(int64)n;
				return ret;
			}
			vec4i64 operator*(uint8 n){
				//
				vec4i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				ret.z=this->z*(int64)n;
				ret.w=this->w*(int64)n;
				return ret;
			}
			vec4i64 operator*(uint16 n){
				//
				vec4i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				ret.z=this->z*(int64)n;
				ret.w=this->w*(int64)n;
				return ret;
			}
			vec4i64 operator*(uint32 n){
				//
				vec4i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				ret.z=this->z*(int64)n;
				ret.w=this->w*(int64)n;
				return ret;
			}
			vec4i64 operator*(uint64 n){
				//
				vec4i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				ret.z=this->z*(int64)n;
				ret.w=this->w*(int64)n;
				return ret;
			}

			//*=
			void operator*=(vec4i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4i16 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4i32 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4i64 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(int8 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
				this->z*=(int64)n;
				this->w*=(int64)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
				this->z*=(int64)n;
				this->w*=(int64)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
				this->z*=(int64)n;
				this->w*=(int64)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
				this->z*=(int64)n;
				this->w*=(int64)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
				this->z*=(int64)n;
				this->w*=(int64)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
				this->z*=(int64)n;
				this->w*=(int64)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
				this->z*=(int64)n;
				this->w*=(int64)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
				this->z*=(int64)n;
				this->w*=(int64)n;
			}

			//++
			vec4i64 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4i64(this->x,this->y,this->z,this->w);
			}
			vec4i64 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4i64(this->x,this->y,this->z,this->w);
			}

			//--
			vec4i64 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4i64(this->x,this->y,this->z,this->w);
			}
			vec4i64 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4i64(this->x,this->y,this->z,this->w);
			}

			//
			vec4i64 operator()(int8 x,int8 y,int8 z,int8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i64((int64)this->x,(int64)this->y,(int64)this->z,(int64)this->w);
			}
			vec4i64 operator()(int16 x,int16 y,int16 z,int16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i64((int64)this->x,(int64)this->y,(int64)this->z,(int64)this->w);
			}
			vec4i64 operator()(int32 x,int32 y,int32 z,int32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i64((int64)this->x,(int64)this->y,(int64)this->z,(int64)this->w);
			}
			vec4i64 operator()(int64 x,int64 y,int64 z,int64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i64((int64)this->x,(int64)this->y,(int64)this->z,(int64)this->w);
			}
			vec4i64 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i64((int64)this->x,(int64)this->y,(int64)this->z,(int64)this->w);
			}
			vec4i64 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i64((int64)this->x,(int64)this->y,(int64)this->z,(int64)this->w);
			}
			vec4i64 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i64((int64)this->x,(int64)this->y,(int64)this->z,(int64)this->w);
			}
			vec4i64 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4i64((int64)this->x,(int64)this->y,(int64)this->z,(int64)this->w);
			}
	};

	//vec4ui8
	class vec4ui8{
		//
		public:
			uint8 x,y,z,w;

			//CONSTRUTOR
			vec4ui8(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4ui8(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(uint8)x;
				this->y=(uint8)y;
				this->z=(uint8)z;
				this->w=(uint8)w;
			}
			vec4ui8(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(uint8)x;
				this->y=(uint8)y;
				this->z=(uint8)z;
				this->w=(uint8)w;
			}
			vec4ui8(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(uint8)x;
				this->y=(uint8)y;
				this->z=(uint8)z;
				this->w=(uint8)w;
			}
			vec4ui8(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(uint8)x;
				this->y=(uint8)y;
				this->z=(uint8)z;
				this->w=(uint8)w;
			}
			//operators

			//=
            vec4ui8 operator=(vec4ui8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui8 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4ui8 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4ui8 operator=(uint8 n){
				//
				this->x=(uint8)n;
				this->y=(uint8)n;
				this->z=(uint8)n;
				this->w=(uint8)n;
                return *this;
			}
            vec4ui8 operator=(uint16 n){
				//
				this->x=(uint8)n;
				this->y=(uint8)n;
				this->z=(uint8)n;
				this->w=(uint8)n;
                return *this;
			}
            vec4ui8 operator=(uint32 n){
				//
				this->x=(uint8)n;
				this->y=(uint8)n;
				this->z=(uint8)n;
				this->w=(uint8)n;
                return *this;
			}
            vec4ui8 operator=(uint64 n){
				//
				this->x=(uint8)n;
				this->y=(uint8)n;
				this->z=(uint8)n;
				this->w=(uint8)n;
                return *this;
			}

			//==
			bool operator==(vec4ui8 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4ui8 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4ui8 operator+(vec4ui8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui8 operator+(vec3i8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4ui8 operator+(vec2i8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4ui8 operator+(uint8 n){
				//
				vec4ui8 ret;
				ret.x=this->x+(uint8)n;
				ret.y=this->y+(uint8)n;
				ret.z=this->z+(uint8)n;
				ret.w=this->w+(uint8)n;
				return ret;
			}
			vec4ui8 operator+(uint16 n){
				//
				vec4ui8 ret;
				ret.x=this->x+(uint8)n;
				ret.y=this->y+(uint8)n;
				ret.z=this->z+(uint8)n;
				ret.w=this->w+(uint8)n;
				return ret;
			}
			vec4ui8 operator+(uint32 n){
				//
				vec4ui8 ret;
				ret.x=this->x+(uint8)n;
				ret.y=this->y+(uint8)n;
				ret.z=this->z+(uint8)n;
				ret.w=this->w+(uint8)n;
				return ret;
			}
			vec4ui8 operator+(uint64 n){
				//
				vec4ui8 ret;
				ret.x=this->x+(uint8)n;
				ret.y=this->y+(uint8)n;
				ret.z=this->z+(uint8)n;
				ret.w=this->w+(uint8)n;
				return ret;
			}

            //+=
			void operator+=(vec4ui8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(uint8 n){
				//
				this->x+=(uint8)n;
				this->y+=(uint8)n;
				this->z+=(uint8)n;
				this->w+=(uint8)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(uint8)n;
				this->y+=(uint8)n;
				this->z+=(uint8)n;
				this->w+=(uint8)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(uint8)n;
				this->y+=(uint8)n;
				this->z+=(uint8)n;
				this->w+=(uint8)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(uint8)n;
				this->y+=(uint8)n;
				this->z+=(uint8)n;
				this->w+=(uint8)n;
			}

			//-
			vec4ui8 operator-(vec4ui8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui8 operator-(vec3i8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4ui8 operator-(vec2i8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4ui8 operator-(uint8 n){
				//
				vec4ui8 ret;
				ret.x=this->x-(uint8)n;
				ret.y=this->y-(uint8)n;
				ret.z=this->z-(uint8)n;
				ret.w=this->w-(uint8)n;
				return ret;
			}
			vec4ui8 operator-(uint16 n){
				//
				vec4ui8 ret;
				ret.x=this->x-(uint8)n;
				ret.y=this->y-(uint8)n;
				ret.z=this->z-(uint8)n;
				ret.w=this->w-(uint8)n;
				return ret;
			}
			vec4ui8 operator-(uint32 n){
				//
				vec4ui8 ret;
				ret.x=this->x-(uint8)n;
				ret.y=this->y-(uint8)n;
				ret.z=this->z-(uint8)n;
				ret.w=this->w-(uint8)n;
				return ret;
			}
			vec4ui8 operator-(uint64 n){
				//
				vec4ui8 ret;
				ret.x=this->x-(uint8)n;
				ret.y=this->y-(uint8)n;
				ret.z=this->z-(uint8)n;
				ret.w=this->w-(uint8)n;
				return ret;
			}

			//-=
			void operator-=(vec4ui8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(uint8 n){
				//
				this->x-=(uint8)n;
				this->y-=(uint8)n;
				this->z-=(uint8)n;
				this->w-=(uint8)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(uint8)n;
				this->y-=(uint8)n;
				this->z-=(uint8)n;
				this->w-=(uint8)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(uint8)n;
				this->y-=(uint8)n;
				this->z-=(uint8)n;
				this->w-=(uint8)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(uint8)n;
				this->y-=(uint8)n;
				this->z-=(uint8)n;
				this->w-=(uint8)n;
			}

			//*
			vec4ui8 operator*(vec4ui8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui8 operator*(vec3i8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4ui8 operator*(vec2i8 vec){
				//
				vec4ui8 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4ui8 operator*(uint8 n){
				//
				vec4ui8 ret;
				ret.x=this->x*(uint8)n;
				ret.y=this->y*(uint8)n;
				ret.z=this->z*(uint8)n;
				ret.w=this->w*(uint8)n;
				return ret;
			}
			vec4ui8 operator*(uint16 n){
				//
				vec4ui8 ret;
				ret.x=this->x*(uint8)n;
				ret.y=this->y*(uint8)n;
				ret.z=this->z*(uint8)n;
				ret.w=this->w*(uint8)n;
				return ret;
			}
			vec4ui8 operator*(uint32 n){
				//
				vec4ui8 ret;
				ret.x=this->x*(uint8)n;
				ret.y=this->y*(uint8)n;
				ret.z=this->z*(uint8)n;
				ret.w=this->w*(uint8)n;
				return ret;
			}
			vec4ui8 operator*(uint64 n){
				//
				vec4ui8 ret;
				ret.x=this->x*(uint8)n;
				ret.y=this->y*(uint8)n;
				ret.z=this->z*(uint8)n;
				ret.w=this->w*(uint8)n;
				return ret;
			}

			//*=
			void operator*=(vec4ui8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(uint8 n){
				//
				this->x*=(uint8)n;
				this->y*=(uint8)n;
				this->z*=(uint8)n;
				this->w*=(uint8)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(uint8)n;
				this->y*=(uint8)n;
				this->z*=(uint8)n;
				this->w*=(uint8)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(uint8)n;
				this->y*=(uint8)n;
				this->z*=(uint8)n;
				this->w*=(uint8)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(uint8)n;
				this->y*=(uint8)n;
				this->z*=(uint8)n;
				this->w*=(uint8)n;
			}

			//++
			vec4ui8 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4ui8(this->x,this->y,this->z,this->w);
			}
			vec4ui8 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4ui8(this->x,this->y,this->z,this->w);
			}

			//--
			vec4ui8 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4ui8(this->x,this->y,this->z,this->w);
			}
			vec4ui8 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4ui8(this->x,this->y,this->z,this->w);
			}

			//
			vec4ui8 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui8((uint8)this->x,(uint8)this->y,(uint8)this->z,(uint8)this->w);
			}
			vec4ui8 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui8((uint8)this->x,(uint8)this->y,(uint8)this->z,(uint8)this->w);
			}
			vec4ui8 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui8((uint8)this->x,(uint8)this->y,(uint8)this->z,(uint8)this->w);
			}
			vec4ui8 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui8((uint8)this->x,(uint8)this->y,(uint8)this->z,(uint8)this->w);
			}
	};

	//vec4ui16
	class vec4ui16{
		//
		public:
			uint16 x,y,z,w;

			//CONSTRUTOR
			vec4ui16(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4ui16(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(uint16)x;
				this->y=(uint16)y;
				this->z=(uint16)z;
				this->w=(uint16)w;
			}
			vec4ui16(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(uint16)x;
				this->y=(uint16)y;
				this->z=(uint16)z;
				this->w=(uint16)w;
			}
			vec4ui16(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(uint16)x;
				this->y=(uint16)y;
				this->z=(uint16)z;
				this->w=(uint16)w;
			}
			vec4ui16(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(uint16)x;
				this->y=(uint16)y;
				this->z=(uint16)z;
				this->w=(uint16)w;
			}
			//operators

			//=
            vec4ui16 operator=(vec4ui8 vec){
				//
				this->x=(uint16)vec.x;
				this->y=(uint16)vec.y;
				this->z=(uint16)vec.z;
				this->w=(uint16)vec.w;
                return *this;
			}
            vec4ui16 operator=(vec4ui16 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui16 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4ui16 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4ui16 operator=(uint8 n){
				//
				this->x=(uint16)n;
				this->y=(uint16)n;
				this->z=(uint16)n;
				this->w=(uint16)n;
                return *this;
			}
            vec4ui16 operator=(uint16 n){
				//
				this->x=(uint16)n;
				this->y=(uint16)n;
				this->z=(uint16)n;
				this->w=(uint16)n;
                return *this;
			}
            vec4ui16 operator=(uint32 n){
				//
				this->x=(uint16)n;
				this->y=(uint16)n;
				this->z=(uint16)n;
				this->w=(uint16)n;
                return *this;
			}
            vec4ui16 operator=(uint64 n){
				//
				this->x=(uint16)n;
				this->y=(uint16)n;
				this->z=(uint16)n;
				this->w=(uint16)n;
                return *this;
			}

			//==
			bool operator==(vec4ui8 vec){
				//
				return (this->x==(uint16)vec.x&&this->y==(uint16)vec.y&&this->z==(uint16)vec.z&&this->w==(uint16)vec.w);
			}
			bool operator==(vec4ui16 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4ui8 vec){
				//
				return (this->x!=(uint16)vec.x||this->y!=(uint16)vec.y||this->z!=(uint16)vec.z||this->w!=(uint16)vec.w);
			}
			bool operator!=(vec4ui16 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4ui16 operator+(vec4ui8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x+(uint16)vec.x;
				ret.y=this->y+(uint16)vec.y;
				ret.z=this->z+(uint16)vec.z;
				ret.w=this->w+(uint16)vec.w;
				return ret;
			}
			vec4ui16 operator+(vec4ui16 vec){
				//
				vec4ui16 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui16 operator+(vec3i8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4ui16 operator+(vec2i8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4ui16 operator+(uint8 n){
				//
				vec4ui16 ret;
				ret.x=this->x+(uint16)n;
				ret.y=this->y+(uint16)n;
				ret.z=this->z+(uint16)n;
				ret.w=this->w+(uint16)n;
				return ret;
			}
			vec4ui16 operator+(uint16 n){
				//
				vec4ui16 ret;
				ret.x=this->x+(uint16)n;
				ret.y=this->y+(uint16)n;
				ret.z=this->z+(uint16)n;
				ret.w=this->w+(uint16)n;
				return ret;
			}
			vec4ui16 operator+(uint32 n){
				//
				vec4ui16 ret;
				ret.x=this->x+(uint16)n;
				ret.y=this->y+(uint16)n;
				ret.z=this->z+(uint16)n;
				ret.w=this->w+(uint16)n;
				return ret;
			}
			vec4ui16 operator+(uint64 n){
				//
				vec4ui16 ret;
				ret.x=this->x+(uint16)n;
				ret.y=this->y+(uint16)n;
				ret.z=this->z+(uint16)n;
				ret.w=this->w+(uint16)n;
				return ret;
			}

            //+=
			void operator+=(vec4ui8 vec){
				//
				this->x+=(uint16)vec.x;
				this->y+=(uint16)vec.y;
				this->z+=(uint16)vec.z;
				this->w+=(uint16)vec.w;
			}
			void operator+=(vec4ui16 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(uint8 n){
				//
				this->x+=(uint16)n;
				this->y+=(uint16)n;
				this->z+=(uint16)n;
				this->w+=(uint16)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(uint16)n;
				this->y+=(uint16)n;
				this->z+=(uint16)n;
				this->w+=(uint16)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(uint16)n;
				this->y+=(uint16)n;
				this->z+=(uint16)n;
				this->w+=(uint16)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(uint16)n;
				this->y+=(uint16)n;
				this->z+=(uint16)n;
				this->w+=(uint16)n;
			}

			//-
			vec4ui16 operator-(vec4ui8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x-(uint16)vec.x;
				ret.y=this->y-(uint16)vec.y;
				ret.z=this->z-(uint16)vec.z;
				ret.w=this->w-(uint16)vec.w;
				return ret;
			}
			vec4ui16 operator-(vec4ui16 vec){
				//
				vec4ui16 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui16 operator-(vec3i8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4ui16 operator-(vec2i8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4ui16 operator-(uint8 n){
				//
				vec4ui16 ret;
				ret.x=this->x-(uint16)n;
				ret.y=this->y-(uint16)n;
				ret.z=this->z-(uint16)n;
				ret.w=this->w-(uint16)n;
				return ret;
			}
			vec4ui16 operator-(uint16 n){
				//
				vec4ui16 ret;
				ret.x=this->x-(uint16)n;
				ret.y=this->y-(uint16)n;
				ret.z=this->z-(uint16)n;
				ret.w=this->w-(uint16)n;
				return ret;
			}
			vec4ui16 operator-(uint32 n){
				//
				vec4ui16 ret;
				ret.x=this->x-(uint16)n;
				ret.y=this->y-(uint16)n;
				ret.z=this->z-(uint16)n;
				ret.w=this->w-(uint16)n;
				return ret;
			}
			vec4ui16 operator-(uint64 n){
				//
				vec4ui16 ret;
				ret.x=this->x-(uint16)n;
				ret.y=this->y-(uint16)n;
				ret.z=this->z-(uint16)n;
				ret.w=this->w-(uint16)n;
				return ret;
			}

			//-=
			void operator-=(vec4ui8 vec){
				//
				this->x-=(uint16)vec.x;
				this->y-=(uint16)vec.y;
				this->z-=(uint16)vec.z;
				this->w-=(uint16)vec.w;
			}
			void operator-=(vec4ui16 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(uint8 n){
				//
				this->x-=(uint16)n;
				this->y-=(uint16)n;
				this->z-=(uint16)n;
				this->w-=(uint16)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(uint16)n;
				this->y-=(uint16)n;
				this->z-=(uint16)n;
				this->w-=(uint16)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(uint16)n;
				this->y-=(uint16)n;
				this->z-=(uint16)n;
				this->w-=(uint16)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(uint16)n;
				this->y-=(uint16)n;
				this->z-=(uint16)n;
				this->w-=(uint16)n;
			}

			//*
			vec4ui16 operator*(vec4ui8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x*(uint16)vec.x;
				ret.y=this->y*(uint16)vec.y;
				ret.z=this->z*(uint16)vec.z;
				ret.w=this->w*(uint16)vec.w;
				return ret;
			}
			vec4ui16 operator*(vec4ui16 vec){
				//
				vec4ui16 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui16 operator*(vec3i8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4ui16 operator*(vec2i8 vec){
				//
				vec4ui16 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4ui16 operator*(uint8 n){
				//
				vec4ui16 ret;
				ret.x=this->x*(uint16)n;
				ret.y=this->y*(uint16)n;
				ret.z=this->z*(uint16)n;
				ret.w=this->w*(uint16)n;
				return ret;
			}
			vec4ui16 operator*(uint16 n){
				//
				vec4ui16 ret;
				ret.x=this->x*(uint16)n;
				ret.y=this->y*(uint16)n;
				ret.z=this->z*(uint16)n;
				ret.w=this->w*(uint16)n;
				return ret;
			}
			vec4ui16 operator*(uint32 n){
				//
				vec4ui16 ret;
				ret.x=this->x*(uint16)n;
				ret.y=this->y*(uint16)n;
				ret.z=this->z*(uint16)n;
				ret.w=this->w*(uint16)n;
				return ret;
			}
			vec4ui16 operator*(uint64 n){
				//
				vec4ui16 ret;
				ret.x=this->x*(uint16)n;
				ret.y=this->y*(uint16)n;
				ret.z=this->z*(uint16)n;
				ret.w=this->w*(uint16)n;
				return ret;
			}

			//*=
			void operator*=(vec4ui8 vec){
				//
				this->x*=(uint16)vec.x;
				this->y*=(uint16)vec.y;
				this->z*=(uint16)vec.z;
				this->w*=(uint16)vec.w;
			}
			void operator*=(vec4ui16 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(uint8 n){
				//
				this->x*=(uint16)n;
				this->y*=(uint16)n;
				this->z*=(uint16)n;
				this->w*=(uint16)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(uint16)n;
				this->y*=(uint16)n;
				this->z*=(uint16)n;
				this->w*=(uint16)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(uint16)n;
				this->y*=(uint16)n;
				this->z*=(uint16)n;
				this->w*=(uint16)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(uint16)n;
				this->y*=(uint16)n;
				this->z*=(uint16)n;
				this->w*=(uint16)n;
			}

			//++
			vec4ui16 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4ui16(this->x,this->y,this->z,this->w);
			}
			vec4ui16 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4ui16(this->x,this->y,this->z,this->w);
			}

			//--
			vec4ui16 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4ui16(this->x,this->y,this->z,this->w);
			}
			vec4ui16 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4ui16(this->x,this->y,this->z,this->w);
			}

			//
			vec4ui16 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui16((uint16)this->x,(uint16)this->y,(uint16)this->z,(uint16)this->w);
			}
			vec4ui16 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui16((uint16)this->x,(uint16)this->y,(uint16)this->z,(uint16)this->w);
			}
			vec4ui16 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui16((uint16)this->x,(uint16)this->y,(uint16)this->z,(uint16)this->w);
			}
			vec4ui16 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui16((uint16)this->x,(uint16)this->y,(uint16)this->z,(uint16)this->w);
			}
	};

	//vec4ui32
	class vec4ui32{
		//
		public:
			uint32 x,y,z,w;

			//CONSTRUTOR
			vec4ui32(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4ui32(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(uint32)x;
				this->y=(uint32)y;
				this->z=(uint32)z;
				this->w=(uint32)w;
			}
			vec4ui32(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(uint32)x;
				this->y=(uint32)y;
				this->z=(uint32)z;
				this->w=(uint32)w;
			}
			vec4ui32(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(uint32)x;
				this->y=(uint32)y;
				this->z=(uint32)z;
				this->w=(uint32)w;
			}
			vec4ui32(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(uint32)x;
				this->y=(uint32)y;
				this->z=(uint32)z;
				this->w=(uint32)w;
			}
			//operators

			//=
            vec4ui32 operator=(vec4ui8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui32 operator=(vec4ui16 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui32 operator=(vec4ui32 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui32 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4ui32 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4ui32 operator=(uint8 n){
				//
				this->x=(uint32)n;
				this->y=(uint32)n;
				this->z=(uint32)n;
				this->w=(uint32)n;
                return *this;
			}
            vec4ui32 operator=(uint16 n){
				//
				this->x=(uint32)n;
				this->y=(uint32)n;
				this->z=(uint32)n;
				this->w=(uint32)n;
                return *this;
			}
            vec4ui32 operator=(uint32 n){
				//
				this->x=(uint32)n;
				this->y=(uint32)n;
				this->z=(uint32)n;
				this->w=(uint32)n;
                return *this;
			}
            vec4ui32 operator=(uint64 n){
				//
				this->x=(uint32)n;
				this->y=(uint32)n;
				this->z=(uint32)n;
				this->w=(uint32)n;
                return *this;
			}

			//==
			bool operator==(vec4ui8 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4ui16 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4ui32 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4ui8 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4ui16 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4ui32 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4ui32 operator+(vec4ui8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui32 operator+(vec4ui16 vec){
				//
				vec4ui32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui32 operator+(vec4ui32 vec){
				//
				vec4ui32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui32 operator+(vec3i8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4ui32 operator+(vec2i8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4ui32 operator+(uint8 n){
				//
				vec4ui32 ret;
				ret.x=this->x+(uint32)n;
				ret.y=this->y+(uint32)n;
				ret.z=this->z+(uint32)n;
				ret.w=this->w+(uint32)n;
				return ret;
			}
			vec4ui32 operator+(uint16 n){
				//
				vec4ui32 ret;
				ret.x=this->x+(uint32)n;
				ret.y=this->y+(uint32)n;
				ret.z=this->z+(uint32)n;
				ret.w=this->w+(uint32)n;
				return ret;
			}
			vec4ui32 operator+(uint32 n){
				//
				vec4ui32 ret;
				ret.x=this->x+(uint32)n;
				ret.y=this->y+(uint32)n;
				ret.z=this->z+(uint32)n;
				ret.w=this->w+(uint32)n;
				return ret;
			}
			vec4ui32 operator+(uint64 n){
				//
				vec4ui32 ret;
				ret.x=this->x+(uint32)n;
				ret.y=this->y+(uint32)n;
				ret.z=this->z+(uint32)n;
				ret.w=this->w+(uint32)n;
				return ret;
			}

            //+=
			void operator+=(vec4ui8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4ui16 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4ui32 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(uint8 n){
				//
				this->x+=(uint32)n;
				this->y+=(uint32)n;
				this->z+=(uint32)n;
				this->w+=(uint32)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(uint32)n;
				this->y+=(uint32)n;
				this->z+=(uint32)n;
				this->w+=(uint32)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(uint32)n;
				this->y+=(uint32)n;
				this->z+=(uint32)n;
				this->w+=(uint32)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(uint32)n;
				this->y+=(uint32)n;
				this->z+=(uint32)n;
				this->w+=(uint32)n;
			}

			//-
			vec4ui32 operator-(vec4ui8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui32 operator-(vec4ui16 vec){
				//
				vec4ui32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui32 operator-(vec4ui32 vec){
				//
				vec4ui32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui32 operator-(vec3i8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4ui32 operator-(vec2i8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4ui32 operator-(uint8 n){
				//
				vec4ui32 ret;
				ret.x=this->x-(uint32)n;
				ret.y=this->y-(uint32)n;
				ret.z=this->z-(uint32)n;
				ret.w=this->w-(uint32)n;
				return ret;
			}
			vec4ui32 operator-(uint16 n){
				//
				vec4ui32 ret;
				ret.x=this->x-(uint32)n;
				ret.y=this->y-(uint32)n;
				ret.z=this->z-(uint32)n;
				ret.w=this->w-(uint32)n;
				return ret;
			}
			vec4ui32 operator-(uint32 n){
				//
				vec4ui32 ret;
				ret.x=this->x-(uint32)n;
				ret.y=this->y-(uint32)n;
				ret.z=this->z-(uint32)n;
				ret.w=this->w-(uint32)n;
				return ret;
			}
			vec4ui32 operator-(uint64 n){
				//
				vec4ui32 ret;
				ret.x=this->x-(uint32)n;
				ret.y=this->y-(uint32)n;
				ret.z=this->z-(uint32)n;
				ret.w=this->w-(uint32)n;
				return ret;
			}

			//-=
			void operator-=(vec4ui8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4ui16 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4ui32 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(uint8 n){
				//
				this->x-=(uint32)n;
				this->y-=(uint32)n;
				this->z-=(uint32)n;
				this->w-=(uint32)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(uint32)n;
				this->y-=(uint32)n;
				this->z-=(uint32)n;
				this->w-=(uint32)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(uint32)n;
				this->y-=(uint32)n;
				this->z-=(uint32)n;
				this->w-=(uint32)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(uint32)n;
				this->y-=(uint32)n;
				this->z-=(uint32)n;
				this->w-=(uint32)n;
			}

			//*
			vec4ui32 operator*(vec4ui8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui32 operator*(vec4ui16 vec){
				//
				vec4ui32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui32 operator*(vec4ui32 vec){
				//
				vec4ui32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui32 operator*(vec3i8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4ui32 operator*(vec2i8 vec){
				//
				vec4ui32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4ui32 operator*(uint8 n){
				//
				vec4ui32 ret;
				ret.x=this->x*(uint32)n;
				ret.y=this->y*(uint32)n;
				ret.z=this->z*(uint32)n;
				ret.w=this->w*(uint32)n;
				return ret;
			}
			vec4ui32 operator*(uint16 n){
				//
				vec4ui32 ret;
				ret.x=this->x*(uint32)n;
				ret.y=this->y*(uint32)n;
				ret.z=this->z*(uint32)n;
				ret.w=this->w*(uint32)n;
				return ret;
			}
			vec4ui32 operator*(uint32 n){
				//
				vec4ui32 ret;
				ret.x=this->x*(uint32)n;
				ret.y=this->y*(uint32)n;
				ret.z=this->z*(uint32)n;
				ret.w=this->w*(uint32)n;
				return ret;
			}
			vec4ui32 operator*(uint64 n){
				//
				vec4ui32 ret;
				ret.x=this->x*(uint32)n;
				ret.y=this->y*(uint32)n;
				ret.z=this->z*(uint32)n;
				ret.w=this->w*(uint32)n;
				return ret;
			}

			//*=
			void operator*=(vec4ui8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4ui16 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4ui32 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(uint8 n){
				//
				this->x*=(uint32)n;
				this->y*=(uint32)n;
				this->z*=(uint32)n;
				this->w*=(uint32)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(uint32)n;
				this->y*=(uint32)n;
				this->z*=(uint32)n;
				this->w*=(uint32)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(uint32)n;
				this->y*=(uint32)n;
				this->z*=(uint32)n;
				this->w*=(uint32)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(uint32)n;
				this->y*=(uint32)n;
				this->z*=(uint32)n;
				this->w*=(uint32)n;
			}

			//++
			vec4ui32 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4ui32(this->x,this->y,this->z,this->w);
			}
			vec4ui32 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4ui32(this->x,this->y,this->z,this->w);
			}

			//--
			vec4ui32 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4ui32(this->x,this->y,this->z,this->w);
			}
			vec4ui32 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4ui32(this->x,this->y,this->z,this->w);
			}

			//
			vec4ui32 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui32((uint32)this->x,(uint32)this->y,(uint32)this->z,(uint32)this->w);
			}
			vec4ui32 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui32((uint32)this->x,(uint32)this->y,(uint32)this->z,(uint32)this->w);
			}
			vec4ui32 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui32((uint32)this->x,(uint32)this->y,(uint32)this->z,(uint32)this->w);
			}
			vec4ui32 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui32((uint32)this->x,(uint32)this->y,(uint32)this->z,(uint32)this->w);
			}
	};

	//vec4ui64
	class vec4ui64{
		//
		public:
			uint64 x,y,z,w;

			//CONSTRUTOR
			vec4ui64(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4ui64(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(uint64)x;
				this->y=(uint64)y;
				this->z=(uint64)z;
				this->w=(uint64)w;
			}
			vec4ui64(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(uint64)x;
				this->y=(uint64)y;
				this->z=(uint64)z;
				this->w=(uint64)w;
			}
			vec4ui64(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(uint64)x;
				this->y=(uint64)y;
				this->z=(uint64)z;
				this->w=(uint64)w;
			}
			vec4ui64(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(uint64)x;
				this->y=(uint64)y;
				this->z=(uint64)z;
				this->w=(uint64)w;
			}
			//operators

			//=
            vec4ui64 operator=(vec4ui8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui64 operator=(vec4ui16 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui64 operator=(vec4ui32 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui64 operator=(vec4ui64 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4ui64 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4ui64 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4ui64 operator=(uint8 n){
				//
				this->x=(uint64)n;
				this->y=(uint64)n;
				this->z=(uint64)n;
				this->w=(uint64)n;
                return *this;
			}
            vec4ui64 operator=(uint16 n){
				//
				this->x=(uint64)n;
				this->y=(uint64)n;
				this->z=(uint64)n;
				this->w=(uint64)n;
                return *this;
			}
            vec4ui64 operator=(uint32 n){
				//
				this->x=(uint64)n;
				this->y=(uint64)n;
				this->z=(uint64)n;
				this->w=(uint64)n;
                return *this;
			}
            vec4ui64 operator=(uint64 n){
				//
				this->x=(uint64)n;
				this->y=(uint64)n;
				this->z=(uint64)n;
				this->w=(uint64)n;
                return *this;
			}

			//==
			bool operator==(vec4ui8 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4ui16 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4ui32 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			bool operator==(vec4ui64 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4ui8 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4ui16 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4ui32 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}
			bool operator!=(vec4ui64 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4ui64 operator+(vec4ui8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui64 operator+(vec4ui16 vec){
				//
				vec4ui64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui64 operator+(vec4ui32 vec){
				//
				vec4ui64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui64 operator+(vec4ui64 vec){
				//
				vec4ui64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4ui64 operator+(vec3i8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4ui64 operator+(vec2i8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4ui64 operator+(uint8 n){
				//
				vec4ui64 ret;
				ret.x=this->x+(uint64)n;
				ret.y=this->y+(uint64)n;
				ret.z=this->z+(uint64)n;
				ret.w=this->w+(uint64)n;
				return ret;
			}
			vec4ui64 operator+(uint16 n){
				//
				vec4ui64 ret;
				ret.x=this->x+(uint64)n;
				ret.y=this->y+(uint64)n;
				ret.z=this->z+(uint64)n;
				ret.w=this->w+(uint64)n;
				return ret;
			}
			vec4ui64 operator+(uint32 n){
				//
				vec4ui64 ret;
				ret.x=this->x+(uint64)n;
				ret.y=this->y+(uint64)n;
				ret.z=this->z+(uint64)n;
				ret.w=this->w+(uint64)n;
				return ret;
			}
			vec4ui64 operator+(uint64 n){
				//
				vec4ui64 ret;
				ret.x=this->x+(uint64)n;
				ret.y=this->y+(uint64)n;
				ret.z=this->z+(uint64)n;
				ret.w=this->w+(uint64)n;
				return ret;
			}

            //+=
			void operator+=(vec4ui8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4ui16 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4ui32 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec4ui64 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(uint8 n){
				//
				this->x+=(uint64)n;
				this->y+=(uint64)n;
				this->z+=(uint64)n;
				this->w+=(uint64)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(uint64)n;
				this->y+=(uint64)n;
				this->z+=(uint64)n;
				this->w+=(uint64)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(uint64)n;
				this->y+=(uint64)n;
				this->z+=(uint64)n;
				this->w+=(uint64)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(uint64)n;
				this->y+=(uint64)n;
				this->z+=(uint64)n;
				this->w+=(uint64)n;
			}

			//-
			vec4ui64 operator-(vec4ui8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui64 operator-(vec4ui16 vec){
				//
				vec4ui64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui64 operator-(vec4ui32 vec){
				//
				vec4ui64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui64 operator-(vec4ui64 vec){
				//
				vec4ui64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4ui64 operator-(vec3i8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4ui64 operator-(vec2i8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4ui64 operator-(uint8 n){
				//
				vec4ui64 ret;
				ret.x=this->x-(uint64)n;
				ret.y=this->y-(uint64)n;
				ret.z=this->z-(uint64)n;
				ret.w=this->w-(uint64)n;
				return ret;
			}
			vec4ui64 operator-(uint16 n){
				//
				vec4ui64 ret;
				ret.x=this->x-(uint64)n;
				ret.y=this->y-(uint64)n;
				ret.z=this->z-(uint64)n;
				ret.w=this->w-(uint64)n;
				return ret;
			}
			vec4ui64 operator-(uint32 n){
				//
				vec4ui64 ret;
				ret.x=this->x-(uint64)n;
				ret.y=this->y-(uint64)n;
				ret.z=this->z-(uint64)n;
				ret.w=this->w-(uint64)n;
				return ret;
			}
			vec4ui64 operator-(uint64 n){
				//
				vec4ui64 ret;
				ret.x=this->x-(uint64)n;
				ret.y=this->y-(uint64)n;
				ret.z=this->z-(uint64)n;
				ret.w=this->w-(uint64)n;
				return ret;
			}

			//-=
			void operator-=(vec4ui8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4ui16 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4ui32 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec4ui64 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(uint8 n){
				//
				this->x-=(uint64)n;
				this->y-=(uint64)n;
				this->z-=(uint64)n;
				this->w-=(uint64)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(uint64)n;
				this->y-=(uint64)n;
				this->z-=(uint64)n;
				this->w-=(uint64)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(uint64)n;
				this->y-=(uint64)n;
				this->z-=(uint64)n;
				this->w-=(uint64)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(uint64)n;
				this->y-=(uint64)n;
				this->z-=(uint64)n;
				this->w-=(uint64)n;
			}

			//*
			vec4ui64 operator*(vec4ui8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui64 operator*(vec4ui16 vec){
				//
				vec4ui64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui64 operator*(vec4ui32 vec){
				//
				vec4ui64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui64 operator*(vec4ui64 vec){
				//
				vec4ui64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4ui64 operator*(vec3i8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4ui64 operator*(vec2i8 vec){
				//
				vec4ui64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4ui64 operator*(uint8 n){
				//
				vec4ui64 ret;
				ret.x=this->x*(uint64)n;
				ret.y=this->y*(uint64)n;
				ret.z=this->z*(uint64)n;
				ret.w=this->w*(uint64)n;
				return ret;
			}
			vec4ui64 operator*(uint16 n){
				//
				vec4ui64 ret;
				ret.x=this->x*(uint64)n;
				ret.y=this->y*(uint64)n;
				ret.z=this->z*(uint64)n;
				ret.w=this->w*(uint64)n;
				return ret;
			}
			vec4ui64 operator*(uint32 n){
				//
				vec4ui64 ret;
				ret.x=this->x*(uint64)n;
				ret.y=this->y*(uint64)n;
				ret.z=this->z*(uint64)n;
				ret.w=this->w*(uint64)n;
				return ret;
			}
			vec4ui64 operator*(uint64 n){
				//
				vec4ui64 ret;
				ret.x=this->x*(uint64)n;
				ret.y=this->y*(uint64)n;
				ret.z=this->z*(uint64)n;
				ret.w=this->w*(uint64)n;
				return ret;
			}

			//*=
			void operator*=(vec4ui8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4ui16 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4ui32 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec4ui64 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(uint8 n){
				//
				this->x*=(uint64)n;
				this->y*=(uint64)n;
				this->z*=(uint64)n;
				this->w*=(uint64)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(uint64)n;
				this->y*=(uint64)n;
				this->z*=(uint64)n;
				this->w*=(uint64)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(uint64)n;
				this->y*=(uint64)n;
				this->z*=(uint64)n;
				this->w*=(uint64)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(uint64)n;
				this->y*=(uint64)n;
				this->z*=(uint64)n;
				this->w*=(uint64)n;
			}

			//++
			vec4ui64 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4ui64(this->x,this->y,this->z,this->w);
			}
			vec4ui64 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4ui64(this->x,this->y,this->z,this->w);
			}

			//--
			vec4ui64 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4ui64(this->x,this->y,this->z,this->w);
			}
			vec4ui64 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4ui64(this->x,this->y,this->z,this->w);
			}

			//
			vec4ui64 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui64((uint64)this->x,(uint64)this->y,(uint64)this->z,(uint64)this->w);
			}
			vec4ui64 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui64((uint64)this->x,(uint64)this->y,(uint64)this->z,(uint64)this->w);
			}
			vec4ui64 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui64((uint64)this->x,(uint64)this->y,(uint64)this->z,(uint64)this->w);
			}
			vec4ui64 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4ui64((uint64)this->x,(uint64)this->y,(uint64)this->z,(uint64)this->w);
			}
	};

	//vec4f32
	class vec4f32{
		//
		public:
			edk::float32 x,y,z,w;

			//CONSTRUTOR
			vec4f32(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(int8 x,int8 y,int8 z,int8 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(int16 x,int16 y,int16 z,int16 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(int32 x,int32 y,int32 z,int32 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(int64 x,int64 y,int64 z,int64 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			vec4f32(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
				this->z=(edk::float32)z;
				this->w=(edk::float32)w;
			}
			//operators

			//=
            vec4f32 operator=(vec4f32 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4f32 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4f32 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4f32 operator=(edk::float32 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(edk::float64 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(int8 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(int16 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(int32 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(int64 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(uint8 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(uint16 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(uint32 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}
            vec4f32 operator=(uint64 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
				this->z=(edk::float32)n;
				this->w=(edk::float32)n;
                return *this;
			}

			//==
			bool operator==(vec4f32 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4f32 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4f32 operator+(vec4f32 vec){
				//
				vec4f32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4f32 operator+(vec3i8 vec){
				//
				vec4f32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4f32 operator+(vec2i8 vec){
				//
				vec4f32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4f32 operator+(edk::float32 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(edk::float64 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(int8 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(int16 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(int32 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(int64 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(uint8 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(uint16 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(uint32 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}
			vec4f32 operator+(uint64 n){
				//
				vec4f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				ret.z=this->z+(edk::float32)n;
				ret.w=this->w+(edk::float32)n;
				return ret;
			}

            //+=
			void operator+=(vec4f32 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(edk::float32 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(edk::float64 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(int8 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
				this->z+=(edk::float32)n;
				this->w+=(edk::float32)n;
			}

			//-
			vec4f32 operator-(vec4f32 vec){
				//
				vec4f32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4f32 operator-(vec3i8 vec){
				//
				vec4f32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4f32 operator-(vec2i8 vec){
				//
				vec4f32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4f32 operator-(edk::float32 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(edk::float64 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(int8 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(int16 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(int32 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(int64 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(uint8 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(uint16 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(uint32 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}
			vec4f32 operator-(uint64 n){
				//
				vec4f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				ret.z=this->z-(edk::float32)n;
				ret.w=this->w-(edk::float32)n;
				return ret;
			}

			//-=
			void operator-=(vec4f32 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(edk::float32 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(edk::float64 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(int8 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
				this->z-=(edk::float32)n;
				this->w-=(edk::float32)n;
			}

			//*
			vec4f32 operator*(vec4f32 vec){
				//
				vec4f32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4f32 operator*(vec3i8 vec){
				//
				vec4f32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4f32 operator*(vec2i8 vec){
				//
				vec4f32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4f32 operator*(edk::float32 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(edk::float64 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(int8 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(int16 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(int32 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(int64 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(uint8 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(uint16 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(uint32 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}
			vec4f32 operator*(uint64 n){
				//
				vec4f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				ret.z=this->z*(edk::float32)n;
				ret.w=this->w*(edk::float32)n;
				return ret;
			}

			//*=
			void operator*=(vec4f32 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(edk::float32 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(edk::float64 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(int8 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
				this->z*=(edk::float32)n;
				this->w*=(edk::float32)n;
			}

			// /
			vec4f32 operator/(vec4f32 vec){
				//
				vec4f32 ret;
				ret.x=this->x/vec.x;
				ret.y=this->y/vec.y;
				ret.z=this->z/vec.z;
				ret.w=this->w/vec.w;
				return ret;
			}
			vec4f32 operator/(vec3i8 vec){
				//
				vec4f32 ret;
				ret.x=this->x/vec.x;
				ret.y=this->y/vec.y;
				ret.z=this->z/vec.z;
				return ret;
			}
			vec4f32 operator/(vec2i8 vec){
				//
				vec4f32 ret;
				ret.x=this->x/vec.x;
				ret.y=this->y/vec.y;
				return ret;
			}
			vec4f32 operator/(edk::float32 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(edk::float64 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(int8 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(int16 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(int32 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(int64 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(uint8 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(uint16 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(uint32 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}
			vec4f32 operator/(uint64 n){
				//
				vec4f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				ret.z=this->z/(edk::float32)n;
				ret.w=this->w/(edk::float32)n;
				return ret;
			}

			// /=
			void operator/=(vec4f32 vec){
				//
				this->x/=vec.x;
				this->y/=vec.y;
				this->z/=vec.z;
				this->w/=vec.w;
			}
			void operator/=(vec3i8 vec){
				//
				this->x/=vec.x;
				this->y/=vec.y;
				this->z/=vec.z;
			}
			void operator/=(vec2i8 vec){
				//
				this->x/=vec.x;
				this->y/=vec.y;
			}
			void operator/=(edk::float32 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(edk::float64 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(int8 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(int16 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(int32 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(int64 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(uint8 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(uint16 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(uint32 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}
			void operator/=(uint64 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
				this->z/=(edk::float32)n;
				this->w/=(edk::float32)n;
			}

			//++
			vec4f32 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4f32(this->x,this->y,this->z,this->w);
			}
			vec4f32 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4f32(this->x,this->y,this->z,this->w);
			}

			//--
			vec4f32 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4f32(this->x,this->y,this->z,this->w);
			}
			vec4f32 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4f32(this->x,this->y,this->z,this->w);
			}

			//
			vec4f32 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(int8 x,int8 y,int8 z,int8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(int16 x,int16 y,int16 z,int16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(int32 x,int32 y,int32 z,int32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(int64 x,int64 y,int64 z,int64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
			vec4f32 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f32((edk::float32)this->x,(edk::float32)this->y,(edk::float32)this->z,(edk::float32)this->w);
			}
	};

	//vec4f64
	class vec4f64{
		//
		public:
			edk::float64 x,y,z,w;

			//CONSTRUTOR
			vec4f64(){
				//zera as variaveis
				this->x=this->y=this->z=this->w=0;
			}
			vec4f64(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(int8 x,int8 y,int8 z,int8 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(int16 x,int16 y,int16 z,int16 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(int32 x,int32 y,int32 z,int32 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(int64 x,int64 y,int64 z,int64 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(uint8 x,uint8 y,uint8 z,uint8 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(uint16 x,uint16 y,uint16 z,uint16 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(uint32 x,uint32 y,uint32 z,uint32 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			vec4f64(uint64 x,uint64 y,uint64 z,uint64 w){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
				this->z=(edk::float64)z;
				this->w=(edk::float64)w;
			}
			//operators

			//=
            vec4f64 operator=(vec4f64 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=vec.w;
                return *this;
			}
            vec4f64 operator=(vec3i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=vec.z;
				this->w=0;
                return *this;
			}
            vec4f64 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
				this->z=0;
				this->w=0;
                return *this;
			}
            vec4f64 operator=(edk::float32 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(edk::float64 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(int8 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(int16 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(int32 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(int64 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(uint8 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(uint16 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(uint32 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}
            vec4f64 operator=(uint64 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
				this->z=(edk::float64)n;
				this->w=(edk::float64)n;
                return *this;
			}

			//==
			bool operator==(vec4f64 vec){
				//
				return (this->x==vec.x&&this->y==vec.y&&this->z==vec.z&&this->w==vec.w);
			}
			//!=
			bool operator!=(vec4f64 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y||this->z!=vec.z||this->w!=vec.w);
			}

			//+
			vec4f64 operator+(vec4f64 vec){
				//
				vec4f64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				ret.w=this->w+vec.w;
				return ret;
			}
			vec4f64 operator+(vec3i8 vec){
				//
				vec4f64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				ret.z=this->z+vec.z;
				return ret;
			}
			vec4f64 operator+(vec2i8 vec){
				//
				vec4f64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec4f64 operator+(edk::float32 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(edk::float64 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(int8 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(int16 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(int32 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(int64 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(uint8 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(uint16 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(uint32 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}
			vec4f64 operator+(uint64 n){
				//
				vec4f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				ret.z=this->z+(edk::float64)n;
				ret.w=this->w+(edk::float64)n;
				return ret;
			}

            //+=
			void operator+=(vec4f64 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
				this->w+=vec.w;
			}
			void operator+=(vec3i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
				this->z+=vec.z;
			}
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(edk::float32 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(edk::float64 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(int8 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
				this->z+=(edk::float64)n;
				this->w+=(edk::float64)n;
			}

			//-
			vec4f64 operator-(vec4f64 vec){
				//
				vec4f64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				ret.w=this->w-vec.w;
				return ret;
			}
			vec4f64 operator-(vec3i8 vec){
				//
				vec4f64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				ret.z=this->z-vec.z;
				return ret;
			}
			vec4f64 operator-(vec2i8 vec){
				//
				vec4f64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec4f64 operator-(edk::float32 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(edk::float64 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(int8 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(int16 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(int32 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(int64 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(uint8 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(uint16 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(uint32 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}
			vec4f64 operator-(uint64 n){
				//
				vec4f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				ret.z=this->z-(edk::float64)n;
				ret.w=this->w-(edk::float64)n;
				return ret;
			}

			//-=
			void operator-=(vec4f64 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
				this->w-=vec.w;
			}
			void operator-=(vec3i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
				this->z-=vec.z;
			}
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(edk::float32 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(edk::float64 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(int8 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
				this->z-=(edk::float64)n;
				this->w-=(edk::float64)n;
			}

			//*
			vec4f64 operator*(vec4f64 vec){
				//
				vec4f64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				ret.w=this->w*vec.w;
				return ret;
			}
			vec4f64 operator*(vec3i8 vec){
				//
				vec4f64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				ret.z=this->z*vec.z;
				return ret;
			}
			vec4f64 operator*(vec2i8 vec){
				//
				vec4f64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec4f64 operator*(edk::float32 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(edk::float64 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(int8 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(int16 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(int32 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(int64 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(uint8 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(uint16 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(uint32 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}
			vec4f64 operator*(uint64 n){
				//
				vec4f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				ret.z=this->z*(edk::float64)n;
				ret.w=this->w*(edk::float64)n;
				return ret;
			}

			//*=
			void operator*=(vec4f64 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
				this->w*=vec.w;
			}
			void operator*=(vec3i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
				this->z*=vec.z;
			}
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(edk::float32 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(edk::float64 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(int8 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
				this->z*=(edk::float64)n;
				this->w*=(edk::float64)n;
			}

			// /
			vec4f64 operator/(vec4f64 vec){
				//
				vec4f64 ret;
				ret.x=this->x/vec.x;
				ret.y=this->y/vec.y;
				ret.z=this->z/vec.z;
				ret.w=this->w/vec.w;
				return ret;
			}
			vec4f64 operator/(vec3i8 vec){
				//
				vec4f64 ret;
				ret.x=this->x/vec.x;
				ret.y=this->y/vec.y;
				ret.z=this->z/vec.z;
				return ret;
			}
			vec4f64 operator/(vec2i8 vec){
				//
				vec4f64 ret;
				ret.x=this->x/vec.x;
				ret.y=this->y/vec.y;
				return ret;
			}
			vec4f64 operator/(edk::float32 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(edk::float64 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(int8 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(int16 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(int32 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(int64 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(uint8 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(uint16 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(uint32 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}
			vec4f64 operator/(uint64 n){
				//
				vec4f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				ret.z=this->z/(edk::float64)n;
				ret.w=this->w/(edk::float64)n;
				return ret;
			}

			// /=
			void operator/=(vec4f64 vec){
				//
				this->x/=vec.x;
				this->y/=vec.y;
				this->z/=vec.z;
				this->w/=vec.w;
			}
			void operator/=(vec3i8 vec){
				//
				this->x/=vec.x;
				this->y/=vec.y;
				this->z/=vec.z;
			}
			void operator/=(vec2i8 vec){
				//
				this->x/=vec.x;
				this->y/=vec.y;
			}
			void operator/=(edk::float32 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(edk::float64 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(int8 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(int16 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(int32 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(int64 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(uint8 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(uint16 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(uint32 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}
			void operator/=(uint64 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
				this->z/=(edk::float64)n;
				this->w/=(edk::float64)n;
			}

			//++
			vec4f64 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    ++this->z;
			    ++this->w;
			    return vec4f64(this->x,this->y,this->z,this->w);
			}
			vec4f64 operator++(int){
			    //
			    this->x++;
			    this->y++;
			    this->z++;
			    this->w++;
			    return vec4f64(this->x,this->y,this->z,this->w);
			}

			//--
			vec4f64 operator--(){
			    //
			    --this->x;
			    --this->y;
			    --this->z;
			    --this->w;
			    return vec4f64(this->x,this->y,this->z,this->w);
			}
			vec4f64 operator--(int){
			    //
			    this->x--;
			    this->y--;
			    this->z--;
			    this->w--;
			    return vec4f64(this->x,this->y,this->z,this->w);
			}

			//
			vec4f64 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(int8 x,int8 y,int8 z,int8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(int16 x,int16 y,int16 z,int16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(int32 x,int32 y,int32 z,int32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(int64 x,int64 y,int64 z,int64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(uint8 x,uint8 y,uint8 z,uint8 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(uint16 x,uint16 y,uint16 z,uint16 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(uint32 x,uint32 y,uint32 z,uint32 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
			vec4f64 operator()(uint64 x,uint64 y,uint64 z,uint64 w){
			    //
			    this->x=x;
			    this->y=y;
			    this->z=z;
			    this->w=w;
			    return vec4f64((edk::float64)this->x,(edk::float64)this->y,(edk::float64)this->z,(edk::float64)this->w);
			}
	};

}//end namespace

#endif // TYPEVEC4_H
