#ifndef EDK_TYPEVEC2_H
#define EDK_TYPEVEC2_H

/*
Library C++ typeVec2 - 2D vectors used in Edk Game Engine
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
#warning "Inside TypesVec2"
#endif

#pragma once
#include "TypeVars.h"

#ifdef printMessages
#warning "    Compiling TypesVec2"
#endif

namespace edk{
    //	//vec2i8
	class vec2i8{
		//
		public:
			int8 x,y;

			//CONSTRUTOR
			vec2i8(){
				//zera as variaveis
				this->x=this->y=0;
			}
			vec2i8(int8 x,int8 y){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
			}
			vec2i8(int16 x,int16 y){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
			}
			vec2i8(int32 x,int32 y){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
			}
			vec2i8(int64 x,int64 y){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
			}
			vec2i8(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
			}
			vec2i8(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
			}
			vec2i8(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
			}
			vec2i8(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(int8)x;
				this->y=(int8)y;
			}
			//operators

			//=
            vec2i8 operator=(vec2i8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2i8 operator=(int8 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
                return *this;
			}
            vec2i8 operator=(int16 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
                return *this;
			}
            vec2i8 operator=(int32 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
                return *this;
			}
            vec2i8 operator=(int64 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
                return *this;
			}
            vec2i8 operator=(uint8 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
                return *this;
			}
            vec2i8 operator=(uint16 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
                return *this;
			}
            vec2i8 operator=(uint32 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
                return *this;
			}
            vec2i8 operator=(uint64 n){
				//
				this->x=(int8)n;
				this->y=(int8)n;
                return *this;
			}

			//==
			bool operator==(vec2i8 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2i8 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2i8 operator+(vec2i8 vec){
				//
				vec2i8 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2i8 operator+(int8 n){
				//
				vec2i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				return ret;
			}
			vec2i8 operator+(int16 n){
				//
				vec2i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				return ret;
			}
			vec2i8 operator+(int32 n){
				//
				vec2i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				return ret;
			}
			vec2i8 operator+(int64 n){
				//
				vec2i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				return ret;
			}
			vec2i8 operator+(uint8 n){
				//
				vec2i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				return ret;
			}
			vec2i8 operator+(uint16 n){
				//
				vec2i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				return ret;
			}
			vec2i8 operator+(uint32 n){
				//
				vec2i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				return ret;
			}
			vec2i8 operator+(uint64 n){
				//
				vec2i8 ret;
				ret.x=this->x+(int8)n;
				ret.y=this->y+(int8)n;
				return ret;
			}

            //+=
			void operator+=(vec2i8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(int8 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(int8)n;
				this->y+=(int8)n;
			}

			//-
			vec2i8 operator-(vec2i8 vec){
				//
				vec2i8 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2i8 operator-(int8 n){
				//
				vec2i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				return ret;
			}
			vec2i8 operator-(int16 n){
				//
				vec2i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				return ret;
			}
			vec2i8 operator-(int32 n){
				//
				vec2i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				return ret;
			}
			vec2i8 operator-(int64 n){
				//
				vec2i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				return ret;
			}
			vec2i8 operator-(uint8 n){
				//
				vec2i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				return ret;
			}
			vec2i8 operator-(uint16 n){
				//
				vec2i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				return ret;
			}
			vec2i8 operator-(uint32 n){
				//
				vec2i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				return ret;
			}
			vec2i8 operator-(uint64 n){
				//
				vec2i8 ret;
				ret.x=this->x-(int8)n;
				ret.y=this->y-(int8)n;
				return ret;
			}

			//-=
			void operator-=(vec2i8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(int8 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(int8)n;
				this->y-=(int8)n;
			}

			//*
			vec2i8 operator*(vec2i8 vec){
				//
				vec2i8 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2i8 operator*(int8 n){
				//
				vec2i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				return ret;
			}
			vec2i8 operator*(int16 n){
				//
				vec2i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				return ret;
			}
			vec2i8 operator*(int32 n){
				//
				vec2i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				return ret;
			}
			vec2i8 operator*(int64 n){
				//
				vec2i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				return ret;
			}
			vec2i8 operator*(uint8 n){
				//
				vec2i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				return ret;
			}
			vec2i8 operator*(uint16 n){
				//
				vec2i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				return ret;
			}
			vec2i8 operator*(uint32 n){
				//
				vec2i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				return ret;
			}
			vec2i8 operator*(uint64 n){
				//
				vec2i8 ret;
				ret.x=this->x*(int8)n;
				ret.y=this->y*(int8)n;
				return ret;
			}

			//*=
			void operator*=(vec2i8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(int8 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(int8)n;
				this->y*=(int8)n;
			}

			//++
			vec2i8 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2i8(this->x,this->y);
			}
            vec2i8 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2i8(this->x,this->y);
			}

			//--
			vec2i8 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2i8(this->x,this->y);
			}
            vec2i8 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2i8(this->x,this->y);
			}

			//
			vec2i8 operator()(int8 x,int8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i8((int8)this->x,(int8)this->y);
			}
			vec2i8 operator()(int16 x,int16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i8((int8)this->x,(int8)this->y);
			}
			vec2i8 operator()(int32 x,int32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i8((int8)this->x,(int8)this->y);
			}
			vec2i8 operator()(int64 x,int64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i8((int8)this->x,(int8)this->y);
			}
			vec2i8 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i8((int8)this->x,(int8)this->y);
			}
			vec2i8 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i8((int8)this->x,(int8)this->y);
			}
			vec2i8 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i8((int8)this->x,(int8)this->y);
			}
			vec2i8 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i8((int8)this->x,(int8)this->y);
			}
	};

	//vec2i16
	class vec2i16{
		//
		public:
			int16 x,y;

			//CONSTRUTOR
			vec2i16(){
				//zera as variaveis
				this->x=this->y=0;
			}
			vec2i16(int8 x,int8 y){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
			}
			vec2i16(int16 x,int16 y){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
			}
			vec2i16(int32 x,int32 y){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
			}
			vec2i16(int64 x,int64 y){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
			}
			vec2i16(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
			}
			vec2i16(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
			}
			vec2i16(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
			}
			vec2i16(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(int16)x;
				this->y=(int16)y;
			}
			//operators

			//=
            vec2i16 operator=(vec2i8 vec){
				//
				this->x=(int16)vec.x;
				this->y=(int16)vec.y;
                return *this;
			}
            vec2i16 operator=(vec2i16 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2i16 operator=(int8 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
                return *this;
			}
            vec2i16 operator=(int16 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
                return *this;
			}
            vec2i16 operator=(int32 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
                return *this;
			}
            vec2i16 operator=(int64 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
                return *this;
			}
            vec2i16 operator=(uint8 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
                return *this;
			}
            vec2i16 operator=(uint16 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
                return *this;
			}
            vec2i16 operator=(uint32 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
                return *this;
			}
            vec2i16 operator=(uint64 n){
				//
				this->x=(int16)n;
				this->y=(int16)n;
                return *this;
			}

			//==
			bool operator==(vec2i8 vec){
				//
				return (this->x==(int16)vec.x&&this->y==(int16)vec.y);
			}
			bool operator==(vec2i16 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2i8 vec){
				//
				return (this->x!=(int16)vec.x&&this->y!=(int16)vec.y);
			}
			bool operator!=(vec2i16 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2i16 operator+(vec2i8 vec){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)vec.x;
				ret.y=this->y+(int16)vec.y;
				return ret;
			}
			vec2i16 operator+(vec2i16 vec){
				//
				vec2i16 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2i16 operator+(int8 n){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				return ret;
			}
			vec2i16 operator+(int16 n){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				return ret;
			}
			vec2i16 operator+(int32 n){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				return ret;
			}
			vec2i16 operator+(int64 n){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				return ret;
			}
			vec2i16 operator+(uint8 n){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				return ret;
			}
			vec2i16 operator+(uint16 n){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				return ret;
			}
			vec2i16 operator+(uint32 n){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				return ret;
			}
			vec2i16 operator+(uint64 n){
				//
				vec2i16 ret;
				ret.x=this->x+(int16)n;
				ret.y=this->y+(int16)n;
				return ret;
			}

            //+=
			void operator+=(vec2i8 vec){
				//
				this->x+=(int16)vec.x;
				this->y+=(int16)vec.y;
			}
			void operator+=(vec2i16 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(int8 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(int16)n;
				this->y+=(int16)n;
			}

			//-
			vec2i16 operator-(vec2i8 vec){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)vec.x;
				ret.y=this->y-(int16)vec.y;
				return ret;
			}
			vec2i16 operator-(vec2i16 vec){
				//
				vec2i16 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2i16 operator-(int8 n){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				return ret;
			}
			vec2i16 operator-(int16 n){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				return ret;
			}
			vec2i16 operator-(int32 n){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				return ret;
			}
			vec2i16 operator-(int64 n){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				return ret;
			}
			vec2i16 operator-(uint8 n){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				return ret;
			}
			vec2i16 operator-(uint16 n){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				return ret;
			}
			vec2i16 operator-(uint32 n){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				return ret;
			}
			vec2i16 operator-(uint64 n){
				//
				vec2i16 ret;
				ret.x=this->x-(int16)n;
				ret.y=this->y-(int16)n;
				return ret;
			}

			//-=
			void operator-=(vec2i8 vec){
				//
				this->x-=(int16)vec.x;
				this->y-=(int16)vec.y;
			}
			void operator-=(vec2i16 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(int8 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(int16)n;
				this->y-=(int16)n;
			}

			//*
			vec2i16 operator*(vec2i8 vec){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)vec.x;
				ret.y=this->y*(int16)vec.y;
				return ret;
			}
			vec2i16 operator*(vec2i16 vec){
				//
				vec2i16 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2i16 operator*(int8 n){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				return ret;
			}
			vec2i16 operator*(int16 n){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				return ret;
			}
			vec2i16 operator*(int32 n){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				return ret;
			}
			vec2i16 operator*(int64 n){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				return ret;
			}
			vec2i16 operator*(uint8 n){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				return ret;
			}
			vec2i16 operator*(uint16 n){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				return ret;
			}
			vec2i16 operator*(uint32 n){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				return ret;
			}
			vec2i16 operator*(uint64 n){
				//
				vec2i16 ret;
				ret.x=this->x*(int16)n;
				ret.y=this->y*(int16)n;
				return ret;
			}

			//*=
			void operator*=(vec2i8 vec){
				//
				this->x*=(int16)vec.x;
				this->y*=(int16)vec.y;
			}
			void operator*=(vec2i16 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(int8 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(int16)n;
				this->y*=(int16)n;
			}

			//++
			vec2i16 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2i16(this->x,this->y);
			}
            vec2i16 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2i16(this->x,this->y);
			}

			//--
			vec2i16 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2i16(this->x,this->y);
			}
            vec2i16 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2i16(this->x,this->y);
			}

			//
			vec2i16 operator()(int8 x,int8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i16((int16)this->x,(int16)this->y);
			}
			vec2i16 operator()(int16 x,int16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i16((int16)this->x,(int16)this->y);
			}
			vec2i16 operator()(int32 x,int32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i16((int16)this->x,(int16)this->y);
			}
			vec2i16 operator()(int64 x,int64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i16((int16)this->x,(int16)this->y);
			}
			vec2i16 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i16((int16)this->x,(int16)this->y);
			}
			vec2i16 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i16((int16)this->x,(int16)this->y);
			}
			vec2i16 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i16((int16)this->x,(int16)this->y);
			}
			vec2i16 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i16((int16)this->x,(int16)this->y);
			}
	};

	//vec2i32
	class vec2i32{
		//
		public:
			int32 x,y;

			//CONSTRUTOR
			vec2i32(){
				//zera as variaveis
				this->x=this->y=0;
			}
			vec2i32(int8 x,int8 y){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
			}
			vec2i32(int16 x,int16 y){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
			}
			vec2i32(int32 x,int32 y){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
			}
			vec2i32(int64 x,int64 y){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
			}
			vec2i32(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
			}
			vec2i32(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
			}
			vec2i32(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
			}
			vec2i32(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(int32)x;
				this->y=(int32)y;
			}
			//operators

			//=
            vec2i32 operator=(vec2i8 vec){
				//
				this->x=(int32)vec.x;
				this->y=(int32)vec.y;
                return *this;
			}
            vec2i32 operator=(vec2i16 vec){
				//
				this->x=(int32)vec.x;
				this->y=(int32)vec.y;
                return *this;
			}
            vec2i32 operator=(vec2i32 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2i32 operator=(int8 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
                return *this;
			}
            vec2i32 operator=(int16 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
                return *this;
			}
            vec2i32 operator=(int32 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
                return *this;
			}
            vec2i32 operator=(int64 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
                return *this;
			}
            vec2i32 operator=(uint8 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
                return *this;
			}
            vec2i32 operator=(uint16 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
                return *this;
			}
            vec2i32 operator=(uint32 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
                return *this;
			}
            vec2i32 operator=(uint64 n){
				//
				this->x=(int32)n;
				this->y=(int32)n;
                return *this;
			}

			//==
			bool operator==(vec2i8 vec){
				//
				return (this->x==(int32)vec.x&&this->y==(int32)vec.y);
			}
			bool operator==(vec2i16 vec){
				//
				return (this->x==(int32)vec.x&&this->y==(int32)vec.y);
			}
			bool operator==(vec2i32 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2i8 vec){
				//
				return (this->x!=(int32)vec.x&&this->y!=(int32)vec.y);
			}
			bool operator!=(vec2i16 vec){
				//
				return (this->x!=(int32)vec.x&&this->y!=(int32)vec.y);
			}
			bool operator!=(vec2i32 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2i32 operator+(vec2i8 vec){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)vec.x;
				ret.y=this->y+(int32)vec.y;
				return ret;
			}
			vec2i32 operator+(vec2i16 vec){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)vec.x;
				ret.y=this->y+(int32)vec.y;
				return ret;
			}
			vec2i32 operator+(vec2i32 vec){
				//
				vec2i32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2i32 operator+(int8 n){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				return ret;
			}
			vec2i32 operator+(int16 n){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				return ret;
			}
			vec2i32 operator+(int32 n){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				return ret;
			}
			vec2i32 operator+(int64 n){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				return ret;
			}
			vec2i32 operator+(uint8 n){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				return ret;
			}
			vec2i32 operator+(uint16 n){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				return ret;
			}
			vec2i32 operator+(uint32 n){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				return ret;
			}
			vec2i32 operator+(uint64 n){
				//
				vec2i32 ret;
				ret.x=this->x+(int32)n;
				ret.y=this->y+(int32)n;
				return ret;
			}

            //+=
			void operator+=(vec2i8 vec){
				//
				this->x+=(int32)vec.x;
				this->y+=(int32)vec.y;
			}
			void operator+=(vec2i16 vec){
				//
				this->x+=(int32)vec.x;
				this->y+=(int32)vec.y;
			}
			void operator+=(vec2i32 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(int8 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(int32)n;
				this->y+=(int32)n;
			}

			//-
			vec2i32 operator-(vec2i8 vec){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)vec.x;
				ret.y=this->y-(int32)vec.y;
				return ret;
			}
			vec2i32 operator-(vec2i16 vec){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)vec.x;
				ret.y=this->y-(int32)vec.y;
				return ret;
			}
			vec2i32 operator-(vec2i32 vec){
				//
				vec2i32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2i32 operator-(int8 n){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				return ret;
			}
			vec2i32 operator-(int16 n){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				return ret;
			}
			vec2i32 operator-(int32 n){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				return ret;
			}
			vec2i32 operator-(int64 n){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				return ret;
			}
			vec2i32 operator-(uint8 n){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				return ret;
			}
			vec2i32 operator-(uint16 n){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				return ret;
			}
			vec2i32 operator-(uint32 n){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				return ret;
			}
			vec2i32 operator-(uint64 n){
				//
				vec2i32 ret;
				ret.x=this->x-(int32)n;
				ret.y=this->y-(int32)n;
				return ret;
			}

			//-=
			void operator-=(vec2i8 vec){
				//
				this->x-=(int32)vec.x;
				this->y-=(int32)vec.y;
			}
			void operator-=(vec2i16 vec){
				//
				this->x-=(int32)vec.x;
				this->y-=(int32)vec.y;
			}
			void operator-=(vec2i32 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(int8 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(int32)n;
				this->y-=(int32)n;
			}

			//*
			vec2i32 operator*(vec2i8 vec){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)vec.x;
				ret.y=this->y*(int32)vec.y;
				return ret;
			}
			vec2i32 operator*(vec2i16 vec){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)vec.x;
				ret.y=this->y*(int32)vec.y;
				return ret;
			}
			vec2i32 operator*(vec2i32 vec){
				//
				vec2i32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2i32 operator*(int8 n){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				return ret;
			}
			vec2i32 operator*(int16 n){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				return ret;
			}
			vec2i32 operator*(int32 n){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				return ret;
			}
			vec2i32 operator*(int64 n){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				return ret;
			}
			vec2i32 operator*(uint8 n){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				return ret;
			}
			vec2i32 operator*(uint16 n){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				return ret;
			}
			vec2i32 operator*(uint32 n){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				return ret;
			}
			vec2i32 operator*(uint64 n){
				//
				vec2i32 ret;
				ret.x=this->x*(int32)n;
				ret.y=this->y*(int32)n;
				return ret;
			}

			//*=
			void operator*=(vec2i8 vec){
				//
				this->x*=(int32)vec.x;
				this->y*=(int32)vec.y;
			}
			void operator*=(vec2i16 vec){
				//
				this->x*=(int32)vec.x;
				this->y*=(int32)vec.y;
			}
			void operator*=(vec2i32 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(int8 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(int32)n;
				this->y*=(int32)n;
			}

			//++
			vec2i32 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2i32(this->x,this->y);
			}
            vec2i32 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2i32(this->x,this->y);
			}

			//--
			vec2i32 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2i32(this->x,this->y);
			}
            vec2i32 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2i32(this->x,this->y);
			}

			//
			vec2i32 operator()(int8 x,int8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i32((int32)this->x,(int32)this->y);
			}
			vec2i32 operator()(int16 x,int16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i32((int32)this->x,(int32)this->y);
			}
			vec2i32 operator()(int32 x,int32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i32((int32)this->x,(int32)this->y);
			}
			vec2i32 operator()(int64 x,int64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i32((int32)this->x,(int32)this->y);
			}
			vec2i32 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i32((int32)this->x,(int32)this->y);
			}
			vec2i32 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i32((int32)this->x,(int32)this->y);
			}
			vec2i32 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i32((int32)this->x,(int32)this->y);
			}
			vec2i32 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i32((int32)this->x,(int32)this->y);
			}
	};

	//vec2i64
	class vec2i64{
		//
		public:
			int64 x,y;

			//CONSTRUTOR
			vec2i64(){
				//zera as variaveis
				this->x=this->y=0;
			}
			vec2i64(int8 x,int8 y){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
			}
			vec2i64(int16 x,int16 y){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
			}
			vec2i64(int32 x,int32 y){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
			}
			vec2i64(int64 x,int64 y){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
			}
			vec2i64(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
			}
			vec2i64(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
			}
			vec2i64(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
			}
			vec2i64(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(int64)x;
				this->y=(int64)y;
			}
			//operators

			//=
            vec2i64 operator=(vec2i8 vec){
				//
				this->x=(int64)vec.x;
				this->y=(int64)vec.y;
                return *this;
			}
            vec2i64 operator=(vec2i16 vec){
				//
				this->x=(int64)vec.x;
				this->y=(int64)vec.y;
                return *this;
			}
            vec2i64 operator=(vec2i32 vec){
				//
				this->x=(int64)vec.x;
				this->y=(int64)vec.y;
                return *this;
			}
            vec2i64 operator=(vec2i64 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2i64 operator=(int8 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
                return *this;
			}
            vec2i64 operator=(int16 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
                return *this;
			}
            vec2i64 operator=(int32 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
                return *this;
			}
            vec2i64 operator=(int64 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
                return *this;
			}
            vec2i64 operator=(uint8 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
                return *this;
			}
            vec2i64 operator=(uint16 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
                return *this;
			}
            vec2i64 operator=(uint32 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
                return *this;
			}
            vec2i64 operator=(uint64 n){
				//
				this->x=(int64)n;
				this->y=(int64)n;
                return *this;
			}

			//==
			bool operator==(vec2i8 vec){
				//
				return (this->x==(int64)vec.x&&this->y==(int64)vec.y);
			}
			bool operator==(vec2i16 vec){
				//
				return (this->x==(int64)vec.x&&this->y==(int64)vec.y);
			}
			bool operator==(vec2i32 vec){
				//
				return (this->x==(int64)vec.x&&this->y==(int64)vec.y);
			}
			bool operator==(vec2i64 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2i8 vec){
				//
				return (this->x!=(int64)vec.x&&this->y!=(int64)vec.y);
			}
			bool operator!=(vec2i16 vec){
				//
				return (this->x!=(int64)vec.x&&this->y!=(int64)vec.y);
			}
			bool operator!=(vec2i32 vec){
				//
				return (this->x!=(int64)vec.x&&this->y!=(int64)vec.y);
			}
			bool operator!=(vec2i64 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2i64 operator+(vec2i8 vec){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)vec.x;
				ret.y=this->y+(int64)vec.y;
				return ret;
			}
			vec2i64 operator+(vec2i16 vec){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)vec.x;
				ret.y=this->y+(int64)vec.y;
				return ret;
			}
			vec2i64 operator+(vec2i32 vec){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)vec.x;
				ret.y=this->y+(int64)vec.y;
				return ret;
			}
			vec2i64 operator+(vec2i64 vec){
				//
				vec2i64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2i64 operator+(int8 n){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				return ret;
			}
			vec2i64 operator+(int16 n){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				return ret;
			}
			vec2i64 operator+(int32 n){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				return ret;
			}
			vec2i64 operator+(int64 n){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				return ret;
			}
			vec2i64 operator+(uint8 n){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				return ret;
			}
			vec2i64 operator+(uint16 n){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				return ret;
			}
			vec2i64 operator+(uint32 n){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				return ret;
			}
			vec2i64 operator+(uint64 n){
				//
				vec2i64 ret;
				ret.x=this->x+(int64)n;
				ret.y=this->y+(int64)n;
				return ret;
			}

            //+=
			void operator+=(vec2i8 vec){
				//
				this->x+=(int64)vec.x;
				this->y+=(int64)vec.y;
			}
			void operator+=(vec2i16 vec){
				//
				this->x+=(int64)vec.x;
				this->y+=(int64)vec.y;
			}
			void operator+=(vec2i32 vec){
				//
				this->x+=(int64)vec.x;
				this->y+=(int64)vec.y;
			}
			void operator+=(vec2i64 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(int8 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(int64)n;
				this->y+=(int64)n;
			}

			//-
			vec2i64 operator-(vec2i8 vec){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)vec.x;
				ret.y=this->y-(int64)vec.y;
				return ret;
			}
			vec2i64 operator-(vec2i16 vec){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)vec.x;
				ret.y=this->y-(int64)vec.y;
				return ret;
			}
			vec2i64 operator-(vec2i32 vec){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)vec.x;
				ret.y=this->y-(int64)vec.y;
				return ret;
			}
			vec2i64 operator-(vec2i64 vec){
				//
				vec2i64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2i64 operator-(int8 n){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				return ret;
			}
			vec2i64 operator-(int16 n){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				return ret;
			}
			vec2i64 operator-(int32 n){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				return ret;
			}
			vec2i64 operator-(int64 n){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				return ret;
			}
			vec2i64 operator-(uint8 n){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				return ret;
			}
			vec2i64 operator-(uint16 n){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				return ret;
			}
			vec2i64 operator-(uint32 n){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				return ret;
			}
			vec2i64 operator-(uint64 n){
				//
				vec2i64 ret;
				ret.x=this->x-(int64)n;
				ret.y=this->y-(int64)n;
				return ret;
			}

			//-=
			void operator-=(vec2i8 vec){
				//
				this->x-=(int64)vec.x;
				this->y-=(int64)vec.y;
			}
			void operator-=(vec2i16 vec){
				//
				this->x-=(int64)vec.x;
				this->y-=(int64)vec.y;
			}
			void operator-=(vec2i32 vec){
				//
				this->x-=(int64)vec.x;
				this->y-=(int64)vec.y;
			}
			void operator-=(vec2i64 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(int8 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(int64)n;
				this->y-=(int64)n;
			}

			//*
			vec2i64 operator*(vec2i8 vec){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)vec.x;
				ret.y=this->y*(int64)vec.y;
				return ret;
			}
			vec2i64 operator*(vec2i16 vec){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)vec.x;
				ret.y=this->y*(int64)vec.y;
				return ret;
			}
			vec2i64 operator*(vec2i32 vec){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)vec.x;
				ret.y=this->y*(int64)vec.y;
				return ret;
			}
			vec2i64 operator*(vec2i64 vec){
				//
				vec2i64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2i64 operator*(int8 n){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				return ret;
			}
			vec2i64 operator*(int16 n){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				return ret;
			}
			vec2i64 operator*(int32 n){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				return ret;
			}
			vec2i64 operator*(int64 n){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				return ret;
			}
			vec2i64 operator*(uint8 n){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				return ret;
			}
			vec2i64 operator*(uint16 n){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				return ret;
			}
			vec2i64 operator*(uint32 n){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				return ret;
			}
			vec2i64 operator*(uint64 n){
				//
				vec2i64 ret;
				ret.x=this->x*(int64)n;
				ret.y=this->y*(int64)n;
				return ret;
			}

			//*=
			void operator*=(vec2i8 vec){
				//
				this->x*=(int64)vec.x;
				this->y*=(int64)vec.y;
			}
			void operator*=(vec2i16 vec){
				//
				this->x*=(int64)vec.x;
				this->y*=(int64)vec.y;
			}
			void operator*=(vec2i32 vec){
				//
				this->x*=(int64)vec.x;
				this->y*=(int64)vec.y;
			}
			void operator*=(vec2i64 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(int8 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(int64)n;
				this->y*=(int64)n;
			}

			//++
			vec2i64 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2i64(this->x,this->y);
			}
            vec2i64 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2i64(this->x,this->y);
			}

			//--
			vec2i64 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2i64(this->x,this->y);
			}
            vec2i64 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2i64(this->x,this->y);
			}

			//
			vec2i64 operator()(int8 x,int8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i64((int64)this->x,(int64)this->y);
			}
			vec2i64 operator()(int16 x,int16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i64((int64)this->x,(int64)this->y);
			}
			vec2i64 operator()(int32 x,int32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i64((int64)this->x,(int64)this->y);
			}
			vec2i64 operator()(int64 x,int64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i64((int64)this->x,(int64)this->y);
			}
			vec2i64 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i64((int64)this->x,(int64)this->y);
			}
			vec2i64 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i64((int64)this->x,(int64)this->y);
			}
			vec2i64 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i64((int64)this->x,(int64)this->y);
			}
			vec2i64 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2i64((int64)this->x,(int64)this->y);
			}
	};

	//vec2ui8
	class vec2ui8{
		//
		public:
			uint8 x,y;

			//CONSTRUTOR
			vec2ui8(){
				//zera as variaveis
				this->x=this->y=0;
			}
			vec2ui8(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(uint8)x;
				this->y=(uint8)y;
			}
			vec2ui8(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(uint8)x;
				this->y=(uint8)y;
			}
			vec2ui8(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(uint8)x;
				this->y=(uint8)y;
			}
			vec2ui8(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(uint8)x;
				this->y=(uint8)y;
			}
			//operators

			//=
            vec2ui8 operator=(vec2ui8 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2ui8 operator=(uint8 n){
				//
				this->x=(uint8)n;
				this->y=(uint8)n;
                return *this;
			}
            vec2ui8 operator=(uint16 n){
				//
				this->x=(uint8)n;
				this->y=(uint8)n;
                return *this;
			}
            vec2ui8 operator=(uint32 n){
				//
				this->x=(uint8)n;
				this->y=(uint8)n;
                return *this;
			}
            vec2ui8 operator=(uint64 n){
				//
				this->x=(uint8)n;
				this->y=(uint8)n;
                return *this;
			}

			//==
			bool operator==(vec2ui8 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2ui8 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2ui8 operator+(vec2ui8 vec){
				//
				vec2ui8 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2ui8 operator+(uint8 n){
				//
				vec2ui8 ret;
				ret.x=this->x+(uint8)n;
				ret.y=this->y+(uint8)n;
				return ret;
			}
			vec2ui8 operator+(uint16 n){
				//
				vec2ui8 ret;
				ret.x=this->x+(uint8)n;
				ret.y=this->y+(uint8)n;
				return ret;
			}
			vec2ui8 operator+(uint32 n){
				//
				vec2ui8 ret;
				ret.x=this->x+(uint8)n;
				ret.y=this->y+(uint8)n;
				return ret;
			}
			vec2ui8 operator+(uint64 n){
				//
				vec2ui8 ret;
				ret.x=this->x+(uint8)n;
				ret.y=this->y+(uint8)n;
				return ret;
			}

            //+=
			void operator+=(vec2ui8 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(uint8 n){
				//
				this->x+=(uint8)n;
				this->y+=(uint8)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(uint8)n;
				this->y+=(uint8)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(uint8)n;
				this->y+=(uint8)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(uint8)n;
				this->y+=(uint8)n;
			}

			//-
			vec2ui8 operator-(vec2ui8 vec){
				//
				vec2ui8 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2ui8 operator-(uint8 n){
				//
				vec2ui8 ret;
				ret.x=this->x-(uint8)n;
				ret.y=this->y-(uint8)n;
				return ret;
			}
			vec2ui8 operator-(uint16 n){
				//
				vec2ui8 ret;
				ret.x=this->x-(uint8)n;
				ret.y=this->y-(uint8)n;
				return ret;
			}
			vec2ui8 operator-(uint32 n){
				//
				vec2ui8 ret;
				ret.x=this->x-(uint8)n;
				ret.y=this->y-(uint8)n;
				return ret;
			}
			vec2ui8 operator-(uint64 n){
				//
				vec2ui8 ret;
				ret.x=this->x-(uint8)n;
				ret.y=this->y-(uint8)n;
				return ret;
			}

			//-=
			void operator-=(vec2ui8 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(uint8 n){
				//
				this->x-=(uint8)n;
				this->y-=(uint8)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(uint8)n;
				this->y-=(uint8)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(uint8)n;
				this->y-=(uint8)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(uint8)n;
				this->y-=(uint8)n;
			}

			//*
			vec2ui8 operator*(vec2ui8 vec){
				//
				vec2ui8 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2ui8 operator*(uint8 n){
				//
				vec2ui8 ret;
				ret.x=this->x*(uint8)n;
				ret.y=this->y*(uint8)n;
				return ret;
			}
			vec2ui8 operator*(uint16 n){
				//
				vec2ui8 ret;
				ret.x=this->x*(uint8)n;
				ret.y=this->y*(uint8)n;
				return ret;
			}
			vec2ui8 operator*(uint32 n){
				//
				vec2ui8 ret;
				ret.x=this->x*(uint8)n;
				ret.y=this->y*(uint8)n;
				return ret;
			}
			vec2ui8 operator*(uint64 n){
				//
				vec2ui8 ret;
				ret.x=this->x*(uint8)n;
				ret.y=this->y*(uint8)n;
				return ret;
			}

			//*=
			void operator*=(vec2ui8 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(uint8 n){
				//
				this->x*=(uint8)n;
				this->y*=(uint8)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(uint8)n;
				this->y*=(uint8)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(uint8)n;
				this->y*=(uint8)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(uint8)n;
				this->y*=(uint8)n;
			}

			//++
			vec2ui8 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2ui8(this->x,this->y);
			}
            vec2ui8 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2ui8(this->x,this->y);
			}

			//--
			vec2ui8 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2ui8(this->x,this->y);
			}
            vec2ui8 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2ui8(this->x,this->y);
			}

			//
			vec2ui8 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui8((uint8)this->x,(uint8)this->y);
			}
			vec2ui8 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui8((uint8)this->x,(uint8)this->y);
			}
			vec2ui8 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui8((uint8)this->x,(uint8)this->y);
			}
			vec2ui8 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui8((uint8)this->x,(uint8)this->y);
			}
	};

	//vec2ui16
	class vec2ui16{
		//
		public:
			uint16 x,y;

			//CONSTRUTOR
			vec2ui16(){
				//zera as variaveis
				this->x=this->y=0;
			}
			vec2ui16(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(uint16)x;
				this->y=(uint16)y;
			}
			vec2ui16(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(uint16)x;
				this->y=(uint16)y;
			}
			vec2ui16(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(uint16)x;
				this->y=(uint16)y;
			}
			vec2ui16(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(uint16)x;
				this->y=(uint16)y;
			}
			//operators

			//=
            vec2ui16 operator=(vec2ui8 vec){
				//
				this->x=(uint16)vec.x;
				this->y=(uint16)vec.y;
                return *this;
			}
            vec2ui16 operator=(vec2ui16 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2ui16 operator=(uint8 n){
				//
				this->x=(uint16)n;
				this->y=(uint16)n;
                return *this;
			}
            vec2ui16 operator=(uint16 n){
				//
				this->x=(uint16)n;
				this->y=(uint16)n;
                return *this;
			}
            vec2ui16 operator=(uint32 n){
				//
				this->x=(uint16)n;
				this->y=(uint16)n;
                return *this;
			}
            vec2ui16 operator=(uint64 n){
				//
				this->x=(uint16)n;
				this->y=(uint16)n;
                return *this;
			}

			//==
			bool operator==(vec2ui8 vec){
				//
				return (this->x==(uint16)vec.x&&this->y==(uint16)vec.y);
			}
			bool operator==(vec2ui16 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2ui8 vec){
				//
				return (this->x!=(uint16)vec.x||this->y!=(uint16)vec.y);
			}
			bool operator!=(vec2ui16 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2ui16 operator+(vec2ui8 vec){
				//
				vec2ui16 ret;
				ret.x=this->x+(uint16)vec.x;
				ret.y=this->y+(uint16)vec.y;
				return ret;
			}
			vec2ui16 operator+(vec2ui16 vec){
				//
				vec2ui16 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2ui16 operator+(uint8 n){
				//
				vec2ui16 ret;
				ret.x=this->x+(uint16)n;
				ret.y=this->y+(uint16)n;
				return ret;
			}
			vec2ui16 operator+(uint16 n){
				//
				vec2ui16 ret;
				ret.x=this->x+(uint16)n;
				ret.y=this->y+(uint16)n;
				return ret;
			}
			vec2ui16 operator+(uint32 n){
				//
				vec2ui16 ret;
				ret.x=this->x+(uint16)n;
				ret.y=this->y+(uint16)n;
				return ret;
			}
			vec2ui16 operator+(uint64 n){
				//
				vec2ui16 ret;
				ret.x=this->x+(uint16)n;
				ret.y=this->y+(uint16)n;
				return ret;
			}

            //+=
			void operator+=(vec2ui8 vec){
				//
				this->x+=(uint16)vec.x;
				this->y+=(uint16)vec.y;
			}
			void operator+=(vec2ui16 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(uint8 n){
				//
				this->x+=(uint16)n;
				this->y+=(uint16)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(uint16)n;
				this->y+=(uint16)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(uint16)n;
				this->y+=(uint16)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(uint16)n;
				this->y+=(uint16)n;
			}

			//-
			vec2ui16 operator-(vec2ui8 vec){
				//
				vec2ui16 ret;
				ret.x=this->x-(uint16)vec.x;
				ret.y=this->y-(uint16)vec.y;
				return ret;
			}
			vec2ui16 operator-(vec2ui16 vec){
				//
				vec2ui16 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2ui16 operator-(uint8 n){
				//
				vec2ui16 ret;
				ret.x=this->x-(uint16)n;
				ret.y=this->y-(uint16)n;
				return ret;
			}
			vec2ui16 operator-(uint16 n){
				//
				vec2ui16 ret;
				ret.x=this->x-(uint16)n;
				ret.y=this->y-(uint16)n;
				return ret;
			}
			vec2ui16 operator-(uint32 n){
				//
				vec2ui16 ret;
				ret.x=this->x-(uint16)n;
				ret.y=this->y-(uint16)n;
				return ret;
			}
			vec2ui16 operator-(uint64 n){
				//
				vec2ui16 ret;
				ret.x=this->x-(uint16)n;
				ret.y=this->y-(uint16)n;
				return ret;
			}

			//-=
			void operator-=(vec2ui8 vec){
				//
				this->x-=(uint16)vec.x;
				this->y-=(uint16)vec.y;
			}
			void operator-=(vec2ui16 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(uint8 n){
				//
				this->x-=(uint16)n;
				this->y-=(uint16)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(uint16)n;
				this->y-=(uint16)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(uint16)n;
				this->y-=(uint16)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(uint16)n;
				this->y-=(uint16)n;
			}

			//*
			vec2ui16 operator*(vec2ui8 vec){
				//
				vec2ui16 ret;
				ret.x=this->x*(uint16)vec.x;
				ret.y=this->y*(uint16)vec.y;
				return ret;
			}
			vec2ui16 operator*(vec2ui16 vec){
				//
				vec2ui16 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2ui16 operator*(uint8 n){
				//
				vec2ui16 ret;
				ret.x=this->x*(uint16)n;
				ret.y=this->y*(uint16)n;
				return ret;
			}
			vec2ui16 operator*(uint16 n){
				//
				vec2ui16 ret;
				ret.x=this->x*(uint16)n;
				ret.y=this->y*(uint16)n;
				return ret;
			}
			vec2ui16 operator*(uint32 n){
				//
				vec2ui16 ret;
				ret.x=this->x*(uint16)n;
				ret.y=this->y*(uint16)n;
				return ret;
			}
			vec2ui16 operator*(uint64 n){
				//
				vec2ui16 ret;
				ret.x=this->x*(uint16)n;
				ret.y=this->y*(uint16)n;
				return ret;
			}

			//*=
			void operator*=(vec2ui8 vec){
				//
				this->x*=(uint16)vec.x;
				this->y*=(uint16)vec.y;
			}
			void operator*=(vec2ui16 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(uint8 n){
				//
				this->x*=(uint16)n;
				this->y*=(uint16)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(uint16)n;
				this->y*=(uint16)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(uint16)n;
				this->y*=(uint16)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(uint16)n;
				this->y*=(uint16)n;
			}

			//++
			vec2ui16 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2ui16(this->x,this->y);
			}
            vec2ui16 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2ui16(this->x,this->y);
			}

			//--
			vec2ui16 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2ui16(this->x,this->y);
			}
            vec2ui16 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2ui16(this->x,this->y);
			}

			//
			vec2ui16 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui16((uint16)this->x,(uint16)this->y);
			}
			vec2ui16 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui16((uint16)this->x,(uint16)this->y);
			}
			vec2ui16 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui16((uint16)this->x,(uint16)this->y);
			}
			vec2ui16 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui16((uint16)this->x,(uint16)this->y);
			}
	};

	//vec2ui32
	class vec2ui32{
		//
		public:
			uint32 x,y;

			//CONSTRUTOR
			vec2ui32(){
				//zera as variaveis
				this->x=this->y=0;
			}
			vec2ui32(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(uint32)x;
				this->y=(uint32)y;
			}
			vec2ui32(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(uint32)x;
				this->y=(uint32)y;
			}
			vec2ui32(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(uint32)x;
				this->y=(uint32)y;
			}
			vec2ui32(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(uint32)x;
				this->y=(uint32)y;
			}
			//operators

			//=
            vec2ui32 operator=(vec2ui8 vec){
				//
				this->x=(uint32)vec.x;
                this->y=(uint32)vec.y;
                return *this;
			}
            vec2ui32 operator=(vec2ui16 vec){
				//
				this->x=(uint32)vec.x;
                this->y=(uint32)vec.y;
                return *this;
			}
            vec2ui32 operator=(vec2ui32 vec){
				//
				this->x=vec.x;
                this->y=vec.y;
                return *this;
			}
            vec2ui32 operator=(uint8 n){
				//
				this->x=(uint32)n;
                this->y=(uint32)n;
                return *this;
			}
            vec2ui32 operator=(uint16 n){
				//
				this->x=(uint32)n;
                this->y=(uint32)n;
                return *this;
			}
            vec2ui32 operator=(uint32 n){
				//
				this->x=(uint32)n;
                this->y=(uint32)n;
                return *this;
			}
            vec2ui32 operator=(uint64 n){
				//
				this->x=(uint32)n;
				this->y=(uint32)n;
                return *this;
			}

			//==
			bool operator==(vec2ui8 vec){
				//
				return (this->x==(uint32)vec.x&&this->y==(uint32)vec.y);
			}
			bool operator==(vec2ui16 vec){
				//
				return (this->x==(uint32)vec.x&&this->y==(uint32)vec.y);
			}
			bool operator==(vec2ui32 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2ui8 vec){
				//
				return (this->x!=(uint32)vec.x||this->y!=(uint32)vec.y);
			}
			bool operator!=(vec2ui16 vec){
				//
				return (this->x!=(uint32)vec.x||this->y!=(uint32)vec.y);
			}
			bool operator!=(vec2ui32 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2ui32 operator+(vec2ui8 vec){
				//
				vec2ui32 ret;
				ret.x=this->x+(uint32)vec.x;
				ret.y=this->y+(uint32)vec.y;
				return ret;
			}
			vec2ui32 operator+(vec2ui16 vec){
				//
				vec2ui32 ret;
				ret.x=this->x+(uint32)vec.x;
				ret.y=this->y+(uint32)vec.y;
				return ret;
			}
			vec2ui32 operator+(vec2ui32 vec){
				//
				vec2ui32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2ui32 operator+(uint8 n){
				//
				vec2ui32 ret;
				ret.x=this->x+(uint32)n;
				ret.y=this->y+(uint32)n;
				return ret;
			}
			vec2ui32 operator+(uint16 n){
				//
				vec2ui32 ret;
				ret.x=this->x+(uint32)n;
				ret.y=this->y+(uint32)n;
				return ret;
			}
			vec2ui32 operator+(uint32 n){
				//
				vec2ui32 ret;
				ret.x=this->x+(uint32)n;
				ret.y=this->y+(uint32)n;
				return ret;
			}
			vec2ui32 operator+(uint64 n){
				//
				vec2ui32 ret;
				ret.x=this->x+(uint32)n;
				ret.y=this->y+(uint32)n;
				return ret;
			}

            //+=
			void operator+=(vec2ui8 vec){
				//
				this->x+=(uint32)vec.x;
				this->y+=(uint32)vec.y;
			}
			void operator+=(vec2ui16 vec){
				//
				this->x+=(uint32)vec.x;
				this->y+=(uint32)vec.y;
			}
			void operator+=(vec2ui32 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(uint8 n){
				//
				this->x+=(uint32)n;
				this->y+=(uint32)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(uint32)n;
				this->y+=(uint32)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(uint32)n;
				this->y+=(uint32)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(uint32)n;
				this->y+=(uint32)n;
			}

			//-
			vec2ui32 operator-(vec2ui8 vec){
				//
				vec2ui32 ret;
				ret.x=this->x-(uint32)vec.x;
				ret.y=this->y-(uint32)vec.y;
				return ret;
			}
			vec2ui32 operator-(vec2ui16 vec){
				//
				vec2ui32 ret;
				ret.x=this->x-(uint32)vec.x;
				ret.y=this->y-(uint32)vec.y;
				return ret;
			}
			vec2ui32 operator-(vec2ui32 vec){
				//
				vec2ui32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2ui32 operator-(uint8 n){
				//
				vec2ui32 ret;
				ret.x=this->x-(uint32)n;
				ret.y=this->y-(uint32)n;
				return ret;
			}
			vec2ui32 operator-(uint16 n){
				//
				vec2ui32 ret;
				ret.x=this->x-(uint32)n;
				ret.y=this->y-(uint32)n;
				return ret;
			}
			vec2ui32 operator-(uint32 n){
				//
				vec2ui32 ret;
				ret.x=this->x-(uint32)n;
				ret.y=this->y-(uint32)n;
				return ret;
			}
			vec2ui32 operator-(uint64 n){
				//
				vec2ui32 ret;
				ret.x=this->x-(uint32)n;
				ret.y=this->y-(uint32)n;
				return ret;
			}

			//-=
			void operator-=(vec2ui8 vec){
				//
				this->x-=(uint32)vec.x;
				this->y-=(uint32)vec.y;
			}
			void operator-=(vec2ui16 vec){
				//
				this->x-=(uint32)vec.x;
				this->y-=(uint32)vec.y;
			}
			void operator-=(vec2ui32 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(uint8 n){
				//
				this->x-=(uint32)n;
				this->y-=(uint32)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(uint32)n;
				this->y-=(uint32)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(uint32)n;
				this->y-=(uint32)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(uint32)n;
				this->y-=(uint32)n;
			}

			//*
			vec2ui32 operator*(vec2ui8 vec){
				//
				vec2ui32 ret;
				ret.x=this->x*(uint32)vec.x;
				ret.y=this->y*(uint32)vec.y;
				return ret;
			}
			vec2ui32 operator*(vec2ui16 vec){
				//
				vec2ui32 ret;
				ret.x=this->x*(uint32)vec.x;
				ret.y=this->y*(uint32)vec.y;
				return ret;
			}
			vec2ui32 operator*(vec2ui32 vec){
				//
				vec2ui32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2ui32 operator*(uint8 n){
				//
				vec2ui32 ret;
				ret.x=this->x*(uint32)n;
				ret.y=this->y*(uint32)n;
				return ret;
			}
			vec2ui32 operator*(uint16 n){
				//
				vec2ui32 ret;
				ret.x=this->x*(uint32)n;
				ret.y=this->y*(uint32)n;
				return ret;
			}
			vec2ui32 operator*(uint32 n){
				//
				vec2ui32 ret;
				ret.x=this->x*(uint32)n;
				ret.y=this->y*(uint32)n;
				return ret;
			}
			vec2ui32 operator*(uint64 n){
				//
				vec2ui32 ret;
				ret.x=this->x*(uint32)n;
				ret.y=this->y*(uint32)n;
				return ret;
			}

			//*=
			void operator*=(vec2ui8 vec){
				//
				this->x*=(uint32)vec.x;
				this->y*=(uint32)vec.y;
			}
			void operator*=(vec2ui16 vec){
				//
				this->x*=(uint32)vec.x;
				this->y*=(uint32)vec.y;
			}
			void operator*=(vec2ui32 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(uint8 n){
				//
				this->x*=(uint32)n;
				this->y*=(uint32)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(uint32)n;
				this->y*=(uint32)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(uint32)n;
				this->y*=(uint32)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(uint32)n;
				this->y*=(uint32)n;
			}

			//++
			vec2ui32 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2ui32(this->x,this->y);
			}
            vec2ui32 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2ui32(this->x,this->y);
			}

			//--
			vec2ui32 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2ui32(this->x,this->y);
			}
            vec2ui32 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2ui32(this->x,this->y);
			}

			//
			vec2ui32 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui32((uint32)this->x,(uint32)this->y);
			}
			vec2ui32 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui32((uint32)this->x,(uint32)this->y);
			}
			vec2ui32 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui32((uint32)this->x,(uint32)this->y);
			}
			vec2ui32 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui32((uint32)this->x,(uint32)this->y);
			}
	};

	//vec2ui64
	class vec2ui64{
		//
		public:
			uint64 x,y;

			//CONSTRUTOR
			vec2ui64(){
				//zera as variaveis
				this->x=this->y=0;
			}
			vec2ui64(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(uint64)x;
				this->y=(uint64)y;
			}
			vec2ui64(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(uint64)x;
				this->y=(uint64)y;
			}
			vec2ui64(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(uint64)x;
				this->y=(uint64)y;
			}
			vec2ui64(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(uint64)x;
				this->y=(uint64)y;
			}
			//operators

			//=
            vec2ui64 operator=(vec2ui8 vec){
				//
				this->x=(uint64)vec.x;
				this->y=(uint64)vec.y;
                return *this;
			}
            vec2ui64 operator=(vec2ui16 vec){
				//
				this->x=(uint64)vec.x;
				this->y=(uint64)vec.y;
                return *this;
			}
            vec2ui64 operator=(vec2ui32 vec){
				//
				this->x=(uint64)vec.x;
				this->y=(uint64)vec.y;
                return *this;
			}
            vec2ui64 operator=(vec2ui64 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2ui64 operator=(uint8 n){
				//
				this->x=(uint64)n;
				this->y=(uint64)n;
                return *this;
			}
            vec2ui64 operator=(uint16 n){
				//
				this->x=(uint64)n;
				this->y=(uint64)n;
                return *this;
			}
            vec2ui64 operator=(uint32 n){
				//
				this->x=(uint64)n;
				this->y=(uint64)n;
                return *this;
			}
            vec2ui64 operator=(uint64 n){
				//
				this->x=(uint64)n;
				this->y=(uint64)n;
                return *this;
			}

			//==
			bool operator==(vec2ui8 vec){
				//
				return (this->x==(uint64)vec.x&&this->y==(uint64)vec.y);
			}
			bool operator==(vec2ui16 vec){
				//
				return (this->x==(uint64)vec.x&&this->y==(uint64)vec.y);
			}
			bool operator==(vec2ui32 vec){
				//
				return (this->x==(uint64)vec.x&&this->y==(uint64)vec.y);
			}
			bool operator==(vec2ui64 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2ui8 vec){
				//
				return (this->x!=(uint64)vec.x||this->y!=(uint64)vec.y);
			}
			bool operator!=(vec2ui16 vec){
				//
				return (this->x!=(uint64)vec.x||this->y!=(uint64)vec.y);
			}
			bool operator!=(vec2ui32 vec){
				//
				return (this->x!=(uint64)vec.x||this->y!=(uint64)vec.y);
			}
			bool operator!=(vec2ui64 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2ui64 operator+(vec2ui8 vec){
				//
				vec2ui64 ret;
				ret.x=this->x+(uint64)vec.x;
				ret.y=this->y+(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator+(vec2ui16 vec){
				//
				vec2ui64 ret;
				ret.x=this->x+(uint64)vec.x;
				ret.y=this->y+(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator+(vec2ui32 vec){
				//
				vec2ui64 ret;
				ret.x=this->x+(uint64)vec.x;
				ret.y=this->y+(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator+(vec2ui64 vec){
				//
				vec2ui64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2ui64 operator+(uint8 n){
				//
				vec2ui64 ret;
				ret.x=this->x+(uint64)n;
				ret.y=this->y+(uint64)n;
				return ret;
			}
			vec2ui64 operator+(uint16 n){
				//
				vec2ui64 ret;
				ret.x=this->x+(uint64)n;
				ret.y=this->y+(uint64)n;
				return ret;
			}
			vec2ui64 operator+(uint32 n){
				//
				vec2ui64 ret;
				ret.x=this->x+(uint64)n;
				ret.y=this->y+(uint64)n;
				return ret;
			}
			vec2ui64 operator+(uint64 n){
				//
				vec2ui64 ret;
				ret.x=this->x+(uint64)n;
				ret.y=this->y+(uint64)n;
				return ret;
			}

            //+=
			void operator+=(vec2ui8 vec){
				//
				this->x+=(uint64)vec.x;
				this->y+=(uint64)vec.y;
			}
			void operator+=(vec2ui16 vec){
				//
				this->x+=(uint64)vec.x;
				this->y+=(uint64)vec.y;
			}
			void operator+=(vec2ui32 vec){
				//
				this->x+=(uint64)vec.x;
				this->y+=(uint64)vec.y;
			}
			void operator+=(vec2ui64 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(uint8 n){
				//
				this->x+=(uint64)n;
				this->y+=(uint64)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(uint64)n;
				this->y+=(uint64)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(uint64)n;
				this->y+=(uint64)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(uint64)n;
				this->y+=(uint64)n;
			}

			//-
			vec2ui64 operator-(vec2ui8 vec){
				//
				vec2ui64 ret;
				ret.x=this->x-(uint64)vec.x;
				ret.y=this->y-(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator-(vec2ui16 vec){
				//
				vec2ui64 ret;
				ret.x=this->x-(uint64)vec.x;
				ret.y=this->y-(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator-(vec2ui32 vec){
				//
				vec2ui64 ret;
				ret.x=this->x-(uint64)vec.x;
				ret.y=this->y-(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator-(vec2ui64 vec){
				//
				vec2ui64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2ui64 operator-(uint8 n){
				//
				vec2ui64 ret;
				ret.x=this->x-(uint64)n;
				ret.y=this->y-(uint64)n;
				return ret;
			}
			vec2ui64 operator-(uint16 n){
				//
				vec2ui64 ret;
				ret.x=this->x-(uint64)n;
				ret.y=this->y-(uint64)n;
				return ret;
			}
			vec2ui64 operator-(uint32 n){
				//
				vec2ui64 ret;
				ret.x=this->x-(uint64)n;
				ret.y=this->y-(uint64)n;
				return ret;
			}
			vec2ui64 operator-(uint64 n){
				//
				vec2ui64 ret;
				ret.x=this->x-(uint64)n;
				ret.y=this->y-(uint64)n;
				return ret;
			}

			//-=
			void operator-=(vec2ui8 vec){
				//
				this->x-=(uint64)vec.x;
				this->y-=(uint64)vec.y;
			}
			void operator-=(vec2ui16 vec){
				//
				this->x-=(uint64)vec.x;
				this->y-=(uint64)vec.y;
			}
			void operator-=(vec2ui32 vec){
				//
				this->x-=(uint64)vec.x;
				this->y-=(uint64)vec.y;
			}
			void operator-=(vec2ui64 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(uint8 n){
				//
				this->x-=(uint64)n;
				this->y-=(uint64)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(uint64)n;
				this->y-=(uint64)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(uint64)n;
				this->y-=(uint64)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(uint64)n;
				this->y-=(uint64)n;
			}

			//*
			vec2ui64 operator*(vec2ui8 vec){
				//
				vec2ui64 ret;
				ret.x=this->x*(uint64)vec.x;
				ret.y=this->y*(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator*(vec2ui16 vec){
				//
				vec2ui64 ret;
				ret.x=this->x*(uint64)vec.x;
				ret.y=this->y*(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator*(vec2ui32 vec){
				//
				vec2ui64 ret;
				ret.x=this->x*(uint64)vec.x;
				ret.y=this->y*(uint64)vec.y;
				return ret;
			}
			vec2ui64 operator*(vec2ui64 vec){
				//
				vec2ui64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2ui64 operator*(uint8 n){
				//
				vec2ui64 ret;
				ret.x=this->x*(uint64)n;
				ret.y=this->y*(uint64)n;
				return ret;
			}
			vec2ui64 operator*(uint16 n){
				//
				vec2ui64 ret;
				ret.x=this->x*(uint64)n;
				ret.y=this->y*(uint64)n;
				return ret;
			}
			vec2ui64 operator*(uint32 n){
				//
				vec2ui64 ret;
				ret.x=this->x*(uint64)n;
				ret.y=this->y*(uint64)n;
				return ret;
			}
			vec2ui64 operator*(uint64 n){
				//
				vec2ui64 ret;
				ret.x=this->x*(uint64)n;
				ret.y=this->y*(uint64)n;
				return ret;
			}

			//*=
			void operator*=(vec2ui8 vec){
				//
				this->x*=(uint64)vec.x;
				this->y*=(uint64)vec.y;
			}
			void operator*=(vec2ui16 vec){
				//
				this->x*=(uint64)vec.x;
				this->y*=(uint64)vec.y;
			}
			void operator*=(vec2ui32 vec){
				//
				this->x*=(uint64)vec.x;
				this->y*=(uint64)vec.y;
			}
			void operator*=(vec2ui64 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(uint8 n){
				//
				this->x*=(uint64)n;
				this->y*=(uint64)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(uint64)n;
				this->y*=(uint64)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(uint64)n;
				this->y*=(uint64)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(uint64)n;
				this->y*=(uint64)n;
			}

			//++
			vec2ui64 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2ui64(this->x,this->y);
			}
            vec2ui64 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2ui64(this->x,this->y);
			}

			//--
			vec2ui64 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2ui64(this->x,this->y);
			}
            vec2ui64 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2ui64(this->x,this->y);
			}

			//
			vec2ui64 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui64((uint64)this->x,(uint64)this->y);
			}
			vec2ui64 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui64((uint64)this->x,(uint64)this->y);
			}
			vec2ui64 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui64((uint64)this->x,(uint64)this->y);
			}
			vec2ui64 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2ui64((uint64)this->x,(uint64)this->y);
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
				this->x=this->y=0;
			}
			vec2f32(edk::float32 x,edk::float32 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(edk::float64 x,edk::float64 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(int8 x,int8 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(int16 x,int16 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(int32 x,int32 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(int64 x,int64 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			vec2f32(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(edk::float32)x;
				this->y=(edk::float32)y;
			}
			//operators

			//=
            vec2f32 operator=(vec2f32 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2f32 operator=(edk::float32 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(edk::float64 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(int8 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(int16 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(int32 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(int64 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(uint8 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(uint16 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(uint32 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}
            vec2f32 operator=(uint64 n){
				//
				this->x=(edk::float32)n;
				this->y=(edk::float32)n;
                return *this;
			}

			//==
			bool operator==(vec2f32 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2f32 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2f32 operator+(vec2f32 vec){
				//
				vec2f32 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2f32 operator+(edk::float32 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(edk::float64 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(int8 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(int16 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(int32 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(int64 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(uint8 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(uint16 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(uint32 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}
			vec2f32 operator+(uint64 n){
				//
				vec2f32 ret;
				ret.x=this->x+(edk::float32)n;
				ret.y=this->y+(edk::float32)n;
				return ret;
			}

            //+=
			void operator+=(vec2f32 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(edk::float32 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(edk::float64 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(int8 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(edk::float32)n;
				this->y+=(edk::float32)n;
			}

			//-
			vec2f32 operator-(vec2f32 vec){
				//
				vec2f32 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2f32 operator-(edk::float32 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(edk::float64 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(int8 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(int16 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(int32 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(int64 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(uint8 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(uint16 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(uint32 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}
			vec2f32 operator-(uint64 n){
				//
				vec2f32 ret;
				ret.x=this->x-(edk::float32)n;
				ret.y=this->y-(edk::float32)n;
				return ret;
			}

			//-=
			void operator-=(vec2f32 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(edk::float32 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(edk::float64 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(int8 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(edk::float32)n;
				this->y-=(edk::float32)n;
			}

			//*
			vec2f32 operator*(vec2f32 vec){
				//
				vec2f32 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2f32 operator*(edk::float32 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(edk::float64 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(int8 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(int16 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(int32 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(int64 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(uint8 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(uint16 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(uint32 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}
			vec2f32 operator*(uint64 n){
				//
				vec2f32 ret;
				ret.x=this->x*(edk::float32)n;
				ret.y=this->y*(edk::float32)n;
				return ret;
			}

			//*=
			void operator*=(vec2f32 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(edk::float32 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(edk::float64 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(int8 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(edk::float32)n;
				this->y*=(edk::float32)n;
			}

			// /
			vec2f32 operator/(vec2f32 vec){
				//
				vec2f32 ret;
				ret.x=this->x/vec.x;
				ret.y=this->y/vec.y;
				return ret;
			}
			vec2f32 operator/(edk::float32 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(edk::float64 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(int8 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(int16 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(int32 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(int64 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(uint8 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(uint16 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(uint32 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}
			vec2f32 operator/(uint64 n){
				//
				vec2f32 ret;
				ret.x=this->x/(edk::float32)n;
				ret.y=this->y/(edk::float32)n;
				return ret;
			}

			// /=

			void operator/=(vec2f32 vec){
				//
				this->x/=vec.x;
				this->y/=vec.y;
			}
			void operator/=(edk::float32 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(edk::float64 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(int8 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(int16 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(int32 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(int64 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(uint8 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(uint16 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(uint32 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}
			void operator/=(uint64 n){
				//
				this->x/=(edk::float32)n;
				this->y/=(edk::float32)n;
			}

			//++
			vec2f32 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2f32(this->x,this->y);
			}
            vec2f32 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2f32(this->x,this->y);
			}

			//--
			vec2f32 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2f32(this->x,this->y);
			}
            vec2f32 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2f32(this->x,this->y);
			}

			//
			vec2f32 operator()(edk::float32 x,edk::float32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(edk::float64 x,edk::float64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(int8 x,int8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(int16 x,int16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(int32 x,int32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(int64 x,int64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
			}
			vec2f32 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f32((edk::float32)this->x,(edk::float32)this->y);
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
				this->x=this->y=0;
			}
			vec2f64(edk::float32 x,edk::float32 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(edk::float64 x,edk::float64 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(int8 x,int8 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(int16 x,int16 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(int32 x,int32 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(int64 x,int64 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(uint8 x,uint8 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(uint16 x,uint16 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(uint32 x,uint32 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			vec2f64(uint64 x,uint64 y){
				//zera as variaveis
				this->x=(edk::float64)x;
				this->y=(edk::float64)y;
			}
			//operators

			//=
            vec2f64 operator=(vec2f64 vec){
				//
				this->x=vec.x;
				this->y=vec.y;
                return *this;
			}
            vec2f64 operator=(edk::float32 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(edk::float64 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(int8 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(int16 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(int32 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(int64 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(uint8 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(uint16 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(uint32 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}
            vec2f64 operator=(uint64 n){
				//
				this->x=(edk::float64)n;
				this->y=(edk::float64)n;
                return *this;
			}

			//==
			bool operator==(vec2f64 vec){
				//
				return (this->x==vec.x&&this->y==vec.y);
			}
			//!=
			bool operator!=(vec2f64 vec){
				//
				return (this->x!=vec.x||this->y!=vec.y);
			}

			//+
			vec2f64 operator+(vec2f64 vec){
				//
				vec2f64 ret;
				ret.x=this->x+vec.x;
				ret.y=this->y+vec.y;
				return ret;
			}
			vec2f64 operator+(edk::float32 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(edk::float64 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(int8 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(int16 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(int32 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(int64 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(uint8 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(uint16 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(uint32 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}
			vec2f64 operator+(uint64 n){
				//
				vec2f64 ret;
				ret.x=this->x+(edk::float64)n;
				ret.y=this->y+(edk::float64)n;
				return ret;
			}

            //+=
			void operator+=(vec2f64 vec){
				//
				this->x+=vec.x;
				this->y+=vec.y;
			}
			void operator+=(edk::float32 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(edk::float64 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(int8 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(int16 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(int32 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(int64 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(uint8 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(uint16 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(uint32 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}
			void operator+=(uint64 n){
				//
				this->x+=(edk::float64)n;
				this->y+=(edk::float64)n;
			}

			//-
			vec2f64 operator-(vec2f64 vec){
				//
				vec2f64 ret;
				ret.x=this->x-vec.x;
				ret.y=this->y-vec.y;
				return ret;
			}
			vec2f64 operator-(edk::float32 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(edk::float64 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(int8 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(int16 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(int32 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(int64 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(uint8 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(uint16 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(uint32 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}
			vec2f64 operator-(uint64 n){
				//
				vec2f64 ret;
				ret.x=this->x-(edk::float64)n;
				ret.y=this->y-(edk::float64)n;
				return ret;
			}

			//-=
			void operator-=(vec2f64 vec){
				//
				this->x-=vec.x;
				this->y-=vec.y;
			}
			void operator-=(edk::float32 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(edk::float64 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(int8 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(int16 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(int32 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(int64 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(uint8 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(uint16 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(uint32 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}
			void operator-=(uint64 n){
				//
				this->x-=(edk::float64)n;
				this->y-=(edk::float64)n;
			}

			//*
			vec2f64 operator*(vec2f64 vec){
				//
				vec2f64 ret;
				ret.x=this->x*vec.x;
				ret.y=this->y*vec.y;
				return ret;
			}
			vec2f64 operator*(edk::float32 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(edk::float64 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(int8 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(int16 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(int32 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(int64 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(uint8 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(uint16 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(uint32 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}
			vec2f64 operator*(uint64 n){
				//
				vec2f64 ret;
				ret.x=this->x*(edk::float64)n;
				ret.y=this->y*(edk::float64)n;
				return ret;
			}

			//*=
			void operator*=(vec2f64 vec){
				//
				this->x*=vec.x;
				this->y*=vec.y;
			}
			void operator*=(edk::float32 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(edk::float64 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(int8 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(int16 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(int32 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(int64 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(uint8 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(uint16 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(uint32 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}
			void operator*=(uint64 n){
				//
				this->x*=(edk::float64)n;
				this->y*=(edk::float64)n;
			}

			// /
			vec2f64 operator/(vec2f64 vec){
				//
				vec2f64 ret;
				ret.x=this->x/vec.x;
				ret.y=this->y/vec.y;
				return ret;
			}
			vec2f64 operator/(edk::float32 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(edk::float64 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(int8 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(int16 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(int32 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(int64 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(uint8 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(uint16 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(uint32 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}
			vec2f64 operator/(uint64 n){
				//
				vec2f64 ret;
				ret.x=this->x/(edk::float64)n;
				ret.y=this->y/(edk::float64)n;
				return ret;
			}

			// /=

			void operator/=(vec2f64 vec){
				//
				this->x/=vec.x;
				this->y/=vec.y;
			}
			void operator/=(edk::float32 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(edk::float64 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(int8 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(int16 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(int32 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(int64 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(uint8 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(uint16 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(uint32 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}
			void operator/=(uint64 n){
				//
				this->x/=(edk::float64)n;
				this->y/=(edk::float64)n;
			}

			//++
			vec2f64 operator++(){
			    //
			    ++this->x;
			    ++this->y;
			    return vec2f64(this->x,this->y);
			}
            vec2f64 operator++(edk::int32){
			    //
			    this->x++;
			    this->y++;
			    return vec2f64(this->x,this->y);
			}

			//--
			vec2f64 operator--(){
			    //
			    --this->x;
			    --this->y;
			    return vec2f64(this->x,this->y);
			}
            vec2f64 operator--(edk::int32){
			    //
			    this->x--;
			    this->y--;
			    return vec2f64(this->x,this->y);
			}

			//
			vec2f64 operator()(edk::float32 x,edk::float32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(edk::float64 x,edk::float64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(int8 x,int8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(int16 x,int16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(int32 x,int32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(int64 x,int64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(uint8 x,uint8 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(uint16 x,uint16 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(uint32 x,uint32 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
			vec2f64 operator()(uint64 x,uint64 y){
			    //
			    this->x=x;
			    this->y=y;
			    return vec2f64((edk::float64)this->x,(edk::float64)this->y);
			}
	};

}//end namespace

#endif // TYPEVEC2_H
