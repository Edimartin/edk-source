#ifndef EDK_TYPECOLOR_H
#define EDK_TYPECOLOR_H

/*
Library C++ TypeColor - Color types used by EDK Game Engine
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
#warning "Inside TypeColor"
#endif

#pragma once
#include "TypeVars.h"
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
			uint8 r,g,b;

			//CONSTRUTOR
            color3ui8(){
				//zera as variaveis
                this->r=this->g=this->b=255;
            }
            color3ui8(uint8 r,uint8 g,uint8 b){
                //zera as variaveis
                this->r=(uint8)r;
                this->g=(uint8)g;
                this->b=(uint8)b;
            }
            color3ui8(uint16 r,uint16 g,uint16 b){
                if(r>=256u) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256u) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256u) this->b=(uint8)255u;
                else this->b=(uint8)b;
            }
            color3ui8(uint32 r,uint32 g,uint32 b){
                if(r>=256u) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256u) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256u) this->b=(uint8)255u;
                else this->b=(uint8)b;
            }
            color3ui8(uint64 r,uint64 g,uint64 b){
                if(r>=256u) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256u) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256u) this->b=(uint8)255u;
                else this->b=(uint8)b;
            }
            color3ui8(int8 r,int8 g,int8 b){
                //zera as variaveis
                this->r=(uint8)r;
                this->g=(uint8)g;
                this->b=(uint8)b;
            }
            color3ui8(int16 r,int16 g,int16 b){
                if(r>=256) this->r=(uint8)255;
                else this->r=(uint8)r;
                if(g>=256) this->g=(uint8)255;
                else this->g=(uint8)g;
                if(b>=256) this->b=(uint8)255;
                else this->b=(uint8)b;
            }
            color3ui8(int32 r,int32 g,int32 b){
                if(r>=256) this->r=(uint8)255;
                else this->r=(uint8)r;
                if(g>=256) this->g=(uint8)255;
                else this->g=(uint8)g;
                if(b>=256) this->b=(uint8)255;
                else this->b=(uint8)b;
            }
            color3ui8(int64 r,int64 g,int64 b){
                if(r>=256) this->r=(uint8)255;
                else this->r=(uint8)r;
                if(g>=256) this->g=(uint8)255;
                else this->g=(uint8)g;
                if(b>=256) this->b=(uint8)255;
                else this->b=(uint8)b;
            }
			//operators

			//=
            color3ui8 operator=(color3ui8 color){
				//
				this->r=color.r;
				this->g=color.g;
				this->b=color.b;
                return *this;
			}
            color3ui8 operator=(vec3i8 color){
				//
				this->r=color.x;
				this->g=color.y;
				this->b=color.z;
                return *this;
            }
            color3ui8 operator=(uint8 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                return *this;
            }
            color3ui8 operator=(uint16 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                return *this;
            }
            color3ui8 operator=(uint32 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                return *this;
            }
            color3ui8 operator=(uint64 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                return *this;
            }
            color3ui8 operator=(int8 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                return *this;
            }
            color3ui8 operator=(int16 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                return *this;
            }
            color3ui8 operator=(int32 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                return *this;
            }
            color3ui8 operator=(int64 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                return *this;
            }

			//==
            bool operator==(color3ui8 color){
				//
				return (this->r==color.r&&this->g==color.g&&this->b==color.b);
			}
			//!=
            bool operator!=(color3ui8 color){
				//
				return (this->r!=color.r||this->g!=color.g||this->b!=color.b);
			}

			//+
            color3ui8 operator+(color3ui8 color){
				//
                color3ui8 ret;
				ret.r=this->r+color.r;
				ret.g=this->g+color.g;
				ret.b=this->b+color.b;
				return ret;
			}
            color3ui8 operator+(vec3i8 color){
				//
                color3ui8 ret;
				ret.r=this->r+color.x;
				ret.g=this->g+color.y;
				ret.b=this->b+color.z;
				return ret;
            }
            color3ui8 operator+(uint8 n){
                //
                color3ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                return ret;
            }
            color3ui8 operator+(uint16 n){
                //
                color3ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                return ret;
            }
            color3ui8 operator+(uint32 n){
                //
                color3ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                return ret;
            }
            color3ui8 operator+(uint64 n){
                //
                color3ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                return ret;
            }
            color3ui8 operator+(int8 n){
                //
                color3ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                return ret;
            }
            color3ui8 operator+(int16 n){
                //
                color3ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                return ret;
            }
            color3ui8 operator+(int32 n){
                //
                color3ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                return ret;
            }
            color3ui8 operator+(int64 n){
                //
                color3ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                return ret;
            }

            //+=
            void operator+=(color3ui8 color){
				//
				this->r+=color.r;
				this->g+=color.g;
				this->b+=color.b;
			}
			void operator+=(vec3i8 color){
				//
				this->r+=color.x;
				this->g+=color.y;
				this->b+=color.z;
            }
            void operator+=(uint8 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
            }
            void operator+=(uint16 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
            }
            void operator+=(uint32 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
            }
            void operator+=(uint64 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
            }
            void operator+=(int8 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
            }
            void operator+=(int16 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
            }
            void operator+=(int32 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
            }
            void operator+=(int64 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
            }

			//-
            color3ui8 operator-(color3ui8 color){
				//
                color3ui8 ret;
				ret.r=this->r-color.r;
				ret.g=this->g-color.g;
				ret.b=this->b-color.b;
				return ret;
			}
            color3ui8 operator-(vec3i8 color){
				//
                color3ui8 ret;
				ret.r=this->r-color.x;
				ret.g=this->g-color.y;
				ret.b=this->b-color.z;
				return ret;
            }
            color3ui8 operator-(uint8 n){
                //
                color3ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                return ret;
            }
            color3ui8 operator-(uint16 n){
                //
                color3ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                return ret;
            }
            color3ui8 operator-(uint32 n){
                //
                color3ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                return ret;
            }
            color3ui8 operator-(uint64 n){
                //
                color3ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                return ret;
            }
            color3ui8 operator-(int8 n){
                //
                color3ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                return ret;
            }
            color3ui8 operator-(int16 n){
                //
                color3ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                return ret;
            }
            color3ui8 operator-(int32 n){
                //
                color3ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                return ret;
            }
            color3ui8 operator-(int64 n){
                //
                color3ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                return ret;
            }

			//-=
            void operator-=(color3ui8 color){
				//
				this->r-=color.r;
				this->g-=color.g;
				this->b-=color.b;
			}
			void operator-=(vec3i8 color){
				//
				this->r-=color.x;
				this->g-=color.y;
				this->b-=color.z;
            }
            void operator-=(uint8 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
            }
            void operator-=(uint16 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
            }
            void operator-=(uint32 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
            }
            void operator-=(uint64 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
            }
            void operator-=(int8 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
            }
            void operator-=(int16 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
            }
            void operator-=(int32 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
            }
            void operator-=(int64 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
            }

			//*
            color3ui8 operator*(color3ui8 color){
				//
                color3ui8 ret;
				ret.r=this->r*color.r;
				ret.g=this->g*color.g;
				ret.b=this->b*color.b;
				return ret;
			}
            color3ui8 operator*(vec3i8 color){
				//
                color3ui8 ret;
				ret.r=this->r*color.x;
				ret.g=this->g*color.y;
				ret.b=this->b*color.z;
				return ret;
            }
            color3ui8 operator*(uint8 n){
                //
                color3ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                return ret;
            }
            color3ui8 operator*(uint16 n){
                //
                color3ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                return ret;
            }
            color3ui8 operator*(uint32 n){
                //
                color3ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                return ret;
            }
            color3ui8 operator*(uint64 n){
                //
                color3ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                return ret;
            }
            color3ui8 operator*(int8 n){
                //
                color3ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                return ret;
            }
            color3ui8 operator*(int16 n){
                //
                color3ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                return ret;
            }
            color3ui8 operator*(int32 n){
                //
                color3ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                return ret;
            }
            color3ui8 operator*(int64 n){
                //
                color3ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                return ret;
            }

			//*=
            void operator*=(color3ui8 color){
				//
				this->r*=color.r;
				this->g*=color.g;
				this->b*=color.b;
			}
			void operator*=(vec3i8 color){
				//
				this->r*=color.x;
				this->g*=color.y;
				this->b*=color.z;
            }
            void operator*=(uint8 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
            }
            void operator*=(uint16 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
            }
            void operator*=(uint32 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
            }
            void operator*=(uint64 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
            }
            void operator*=(int8 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
            }
            void operator*=(int16 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
            }
            void operator*=(int32 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
            }
            void operator*=(int64 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
            }

			//++
            color3ui8 operator++(){
			    //
			    ++this->r;
			    ++this->g;
			    ++this->b;
                return color3ui8(this->r,this->g,this->b);
			}
            color3ui8 operator++(edk::int32){
			    //
			    this->r++;
			    this->g++;
			    this->b++;
                return color3ui8(this->r,this->g,this->b);
			}

			//--
            color3ui8 operator--(){
			    //
			    --this->r;
			    --this->g;
			    --this->b;
                return color3ui8(this->r,this->g,this->b);
			}
            color3ui8 operator--(edk::int32){
			    //
			    this->r--;
			    this->g--;
			    this->b--;
                return color3ui8(this->r,this->g,this->b);
			}

            //
            color3ui8 operator()(uint8 r,uint8 g,uint8 b){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                return color3ui8((uint8)this->r,(uint8)this->g,(uint8)this->b);
            }
            color3ui8 operator()(uint16 r,uint16 g,uint16 b){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                return color3ui8((uint8)this->r,(uint8)this->g,(uint8)this->b);
            }
            color3ui8 operator()(uint32 r,uint32 g,uint32 b){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                return color3ui8((uint8)this->r,(uint8)this->g,(uint8)this->b);
            }
            color3ui8 operator()(uint64 r,uint64 g,uint64 b){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                return color3ui8((uint8)this->r,(uint8)this->g,(uint8)this->b);
            }
            color3ui8 operator()(int8 r,int8 g,int8 b){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                return color3ui8((uint8)this->r,(uint8)this->g,(uint8)this->b);
            }
            color3ui8 operator()(int16 r,int16 g,int16 b){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                return color3ui8((uint8)this->r,(uint8)this->g,(uint8)this->b);
            }
            color3ui8 operator()(int32 r,int32 g,int32 b){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                return color3ui8((uint8)this->r,(uint8)this->g,(uint8)this->b);
            }
            color3ui8 operator()(int64 r,int64 g,int64 b){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                return color3ui8((uint8)this->r,(uint8)this->g,(uint8)this->b);
            }
	};

    //color4ui8
    class color4ui8{
		//
		public:
			uint8 r,g,b,a;

			//CONSTRUTOR
            color4ui8(){
				//zera as variaveis
                this->r=this->g=this->b=this->a=255;
            }
            color4ui8(uint8 r,uint8 g,uint8 b,uint8 a){
                //zera as variaveis
                this->r=(uint8)r;
                this->g=(uint8)g;
                this->b=(uint8)b;
                this->a=(uint8)a;
            }
            color4ui8(uint16 r,uint16 g,uint16 b,uint16 a){
                if(r>=256u) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256u) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256u) this->b=(uint8)255u;
                else this->b=(uint8)b;
                if(a>=256u) this->a=(uint8)255u;
                else this->a=(uint8)a;
            }
            color4ui8(uint32 r,uint32 g,uint32 b,uint32 a){
                if(r>=256u) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256u) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256u) this->b=(uint8)255u;
                else this->b=(uint8)b;
                if(a>=256u) this->a=(uint8)255u;
                else this->a=(uint8)a;
            }
            color4ui8(uint64 r,uint64 g,uint64 b,uint64 a){
                if(r>=256u) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256u) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256u) this->b=(uint8)255u;
                else this->b=(uint8)b;
                if(a>=256u) this->a=(uint8)255u;
                else this->a=(uint8)a;
            }
            color4ui8(int8 r,int8 g,int8 b,int8 a){
                //zera as variaveis
                this->r=(uint8)r;
                this->g=(uint8)g;
                this->b=(uint8)b;
                this->a=(uint8)a;
            }
            color4ui8(int16 r,int16 g,int16 b,int16 a){
                if(r>=256) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256) this->b=(uint8)255u;
                else this->b=(uint8)b;
                if(a>=256) this->a=(uint8)255u;
                else this->a=(uint8)a;
            }
            color4ui8(int32 r,int32 g,int32 b,int32 a){
                if(r>=256) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256) this->b=(uint8)255u;
                else this->b=(uint8)b;
                if(a>=256) this->a=(uint8)255u;
                else this->a=(uint8)a;
            }
            color4ui8(int64 r,int64 g,int64 b,int64 a){
                if(r>=256) this->r=(uint8)255u;
                else this->r=(uint8)r;
                if(g>=256) this->g=(uint8)255u;
                else this->g=(uint8)g;
                if(b>=256) this->b=(uint8)255u;
                else this->b=(uint8)b;
                if(a>=256) this->a=(uint8)255u;
                else this->a=(uint8)a;
            }
			//operators

			//=
            color4ui8 operator=(color4ui8 color){
				//
				this->r=color.r;
				this->g=color.g;
				this->b=color.b;
				this->a=color.a;
                return *this;
			}
            color4ui8 operator=(vec4i8 color){
				//
				this->r=color.x;
				this->g=color.y;
				this->b=color.z;
				this->a=color.w;
                return *this;
            }
            color4ui8 operator=(uint8 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                this->a=(uint8)n;
                return *this;
            }
            color4ui8 operator=(uint16 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                this->a=(uint8)n;
                return *this;
            }
            color4ui8 operator=(uint32 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                this->a=(uint8)n;
                return *this;
            }
            color4ui8 operator=(uint64 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                this->a=(uint8)n;
                return *this;
            }
            color4ui8 operator=(int8 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                this->a=(uint8)n;
                return *this;
            }
            color4ui8 operator=(int16 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                this->a=(uint8)n;
                return *this;
            }
            color4ui8 operator=(int32 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                this->a=(uint8)n;
                return *this;
            }
            color4ui8 operator=(int64 n){
                //
                this->r=(uint8)n;
                this->g=(uint8)n;
                this->b=(uint8)n;
                this->a=(uint8)n;
                return *this;
            }

			//==
            bool operator==(color4ui8 color){
				//
				return (this->r==color.r&&this->g==color.g&&this->b==color.b&&this->a==color.a);
			}
			//!=
            bool operator!=(color4ui8 color){
				//
				return (this->r!=color.r||this->g!=color.g||this->b!=color.b||this->a!=color.a);
			}

			//+
            color4ui8 operator+(color4ui8 color){
				//
                color4ui8 ret;
				ret.r=this->r+color.r;
				ret.g=this->g+color.g;
				ret.b=this->b+color.b;
				ret.a=this->a+color.a;
				return ret;
			}
            color4ui8 operator+(vec4i8 color){
				//
                color4ui8 ret;
				ret.r=this->r+color.x;
				ret.g=this->g+color.y;
				ret.b=this->b+color.z;
				ret.a=this->a+color.w;
				return ret;
            }
            color4ui8 operator+(uint8 n){
                //
                color4ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                ret.a=this->a+(uint8)n;
                return ret;
            }
            color4ui8 operator+(uint16 n){
                //
                color4ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                ret.a=this->a+(uint8)n;
                return ret;
            }
            color4ui8 operator+(uint32 n){
                //
                color4ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                ret.a=this->a+(uint8)n;
                return ret;
            }
            color4ui8 operator+(uint64 n){
                //
                color4ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                ret.a=this->a+(uint8)n;
                return ret;
            }
            color4ui8 operator+(int8 n){
                //
                color4ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                ret.a=this->a+(uint8)n;
                return ret;
            }
            color4ui8 operator+(int16 n){
                //
                color4ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                ret.a=this->a+(uint8)n;
                return ret;
            }
            color4ui8 operator+(int32 n){
                //
                color4ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                ret.a=this->a+(uint8)n;
                return ret;
            }
            color4ui8 operator+(int64 n){
                //
                color4ui8 ret;
                ret.r=this->r+(uint8)n;
                ret.g=this->g+(uint8)n;
                ret.b=this->b+(uint8)n;
                ret.a=this->a+(uint8)n;
                return ret;
            }

            //+=
            void operator+=(color4ui8 color){
				//
				this->r+=color.r;
				this->g+=color.g;
				this->b+=color.b;
				this->a+=color.a;
			}
			void operator+=(vec4i8 color){
				//
				this->r+=color.x;
				this->g+=color.y;
				this->b+=color.z;
				this->a+=color.w;
            }
            void operator+=(uint8 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
                this->a+=(uint8)n;
            }
            void operator+=(uint16 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
                this->a+=(uint8)n;
            }
            void operator+=(uint32 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
                this->a+=(uint8)n;
            }
            void operator+=(uint64 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
                this->a+=(uint8)n;
            }
            void operator+=(int8 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
                this->a+=(uint8)n;
            }
            void operator+=(int16 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
                this->a+=(uint8)n;
            }
            void operator+=(int32 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
                this->a+=(uint8)n;
            }
            void operator+=(int64 n){
                //
                this->r+=(uint8)n;
                this->g+=(uint8)n;
                this->b+=(uint8)n;
                this->a+=(uint8)n;
            }

			//-
            color4ui8 operator-(color4ui8 color){
				//
                color4ui8 ret;
				ret.r=this->r-color.r;
				ret.g=this->g-color.g;
				ret.b=this->b-color.b;
				ret.a=this->a-color.a;
				return ret;
			}
            color4ui8 operator-(vec4i8 color){
				//
                color4ui8 ret;
				ret.r=this->r-color.x;
				ret.g=this->g-color.y;
				ret.b=this->b-color.z;
				ret.a=this->a-color.w;
				return ret;
            }
            color4ui8 operator-(uint8 n){
                //
                color4ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                ret.a=this->a-(uint8)n;
                return ret;
            }
            color4ui8 operator-(uint16 n){
                //
                color4ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                ret.a=this->a-(uint8)n;
                return ret;
            }
            color4ui8 operator-(uint32 n){
                //
                color4ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                ret.a=this->a-(uint8)n;
                return ret;
            }
            color4ui8 operator-(uint64 n){
                //
                color4ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                ret.a=this->a-(uint8)n;
                return ret;
            }
            color4ui8 operator-(int8 n){
                //
                color4ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                ret.a=this->a-(uint8)n;
                return ret;
            }
            color4ui8 operator-(int16 n){
                //
                color4ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                ret.a=this->a-(uint8)n;
                return ret;
            }
            color4ui8 operator-(int32 n){
                //
                color4ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                ret.a=this->a-(uint8)n;
                return ret;
            }
            color4ui8 operator-(int64 n){
                //
                color4ui8 ret;
                ret.r=this->r-(uint8)n;
                ret.g=this->g-(uint8)n;
                ret.b=this->b-(uint8)n;
                ret.a=this->a-(uint8)n;
                return ret;
            }

			//-=
            void operator-=(color4ui8 color){
				//
				this->r-=color.r;
				this->g-=color.g;
				this->b-=color.b;
				this->a-=color.a;
			}
			void operator-=(vec4i8 color){
				//
				this->r-=color.x;
				this->g-=color.y;
				this->b-=color.z;
				this->a-=color.w;
            }
            void operator-=(uint8 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
                this->a-=(uint8)n;
            }
            void operator-=(uint16 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
                this->a-=(uint8)n;
            }
            void operator-=(uint32 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
                this->a-=(uint8)n;
            }
            void operator-=(uint64 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
                this->a-=(uint8)n;
            }
            void operator-=(int8 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
                this->a-=(uint8)n;
            }
            void operator-=(int16 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
                this->a-=(uint8)n;
            }
            void operator-=(int32 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
                this->a-=(uint8)n;
            }
            void operator-=(int64 n){
                //
                this->r-=(uint8)n;
                this->g-=(uint8)n;
                this->b-=(uint8)n;
                this->a-=(uint8)n;
            }

			//*
            color4ui8 operator*(color4ui8 color){
				//
                color4ui8 ret;
				ret.r=this->r*color.r;
				ret.g=this->g*color.g;
				ret.b=this->b*color.b;
				ret.a=this->a*color.a;
				return ret;
			}
            color4ui8 operator*(vec4i8 color){
				//
                color4ui8 ret;
				ret.r=this->r*color.x;
				ret.g=this->g*color.y;
				ret.b=this->b*color.z;
				ret.a=this->a*color.w;
				return ret;
            }
            color4ui8 operator*(uint8 n){
                //
                color4ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                ret.a=this->a*(uint8)n;
                return ret;
            }
            color4ui8 operator*(uint16 n){
                //
                color4ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                ret.a=this->a*(uint8)n;
                return ret;
            }
            color4ui8 operator*(uint32 n){
                //
                color4ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                ret.a=this->a*(uint8)n;
                return ret;
            }
            color4ui8 operator*(uint64 n){
                //
                color4ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                ret.a=this->a*(uint8)n;
                return ret;
            }
            color4ui8 operator*(int8 n){
                //
                color4ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                ret.a=this->a*(uint8)n;
                return ret;
            }
            color4ui8 operator*(int16 n){
                //
                color4ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                ret.a=this->a*(uint8)n;
                return ret;
            }
            color4ui8 operator*(int32 n){
                //
                color4ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                ret.a=this->a*(uint8)n;
                return ret;
            }
            color4ui8 operator*(int64 n){
                //
                color4ui8 ret;
                ret.r=this->r*(uint8)n;
                ret.g=this->g*(uint8)n;
                ret.b=this->b*(uint8)n;
                ret.a=this->a*(uint8)n;
                return ret;
            }

			//*=
            void operator*=(color4ui8 color){
				//
				this->r*=color.r;
				this->g*=color.g;
				this->b*=color.b;
				this->a*=color.a;
			}
			void operator*=(vec4i8 color){
				//
				this->r*=color.x;
				this->g*=color.y;
				this->b*=color.z;
				this->a*=color.w;
            }
            void operator*=(uint8 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
                this->a*=(uint8)n;
            }
            void operator*=(uint16 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
                this->a*=(uint8)n;
            }
            void operator*=(uint32 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
                this->a*=(uint8)n;
            }
            void operator*=(uint64 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
                this->a*=(uint8)n;
            }
            void operator*=(int8 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
                this->a*=(uint8)n;
            }
            void operator*=(int16 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
                this->a*=(uint8)n;
            }
            void operator*=(int32 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
                this->a*=(uint8)n;
            }
            void operator*=(int64 n){
                //
                this->r*=(uint8)n;
                this->g*=(uint8)n;
                this->b*=(uint8)n;
                this->a*=(uint8)n;
            }

			//++
            color4ui8 operator++(){
			    //
			    ++this->r;
			    ++this->g;
			    ++this->b;
			    ++this->a;
                return color4ui8(this->r,this->g,this->b,this->a);
			}
            color4ui8 operator++(int32){
			    //
			    this->r++;
			    this->g++;
			    this->b++;
			    this->a++;
                return color4ui8(this->r,this->g,this->b,this->a);
			}

			//--
            color4ui8 operator--(){
			    //
			    --this->r;
			    --this->g;
			    --this->b;
			    --this->a;
                return color4ui8(this->r,this->g,this->b,this->a);
			}
            color4ui8 operator--(int32){
			    //
			    this->r--;
			    this->g--;
			    this->b--;
			    this->a--;
                return color4ui8(this->r,this->g,this->b,this->a);
			}

            //
            color4ui8 operator()(uint8 r,uint8 g,uint8 b,uint8 a){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                this->a=a;
                return color4ui8((uint8)this->r,(uint8)this->g,(uint8)this->b,(uint8)this->a);
            }
            color4ui8 operator()(uint16 r,uint16 g,uint16 b,uint16 a){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                this->a=a;
                return color4ui8((uint8)this->r,(uint8)this->g,(uint8)this->b,(uint8)this->a);
            }
            color4ui8 operator()(uint32 r,uint32 g,uint32 b,uint32 a){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                this->a=a;
                return color4ui8((uint8)this->r,(uint8)this->g,(uint8)this->b,(uint8)this->a);
            }
            color4ui8 operator()(uint64 r,uint64 g,uint64 b,uint64 a){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                this->a=a;
                return color4ui8((uint8)this->r,(uint8)this->g,(uint8)this->b,(uint8)this->a);
            }
            color4ui8 operator()(int8 r,int8 g,int8 b,int8 a){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                this->a=a;
                return color4ui8((uint8)this->r,(uint8)this->g,(uint8)this->b,(uint8)this->a);
            }
            color4ui8 operator()(int16 r,int16 g,int16 b,int16 a){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                this->a=a;
                return color4ui8((uint8)this->r,(uint8)this->g,(uint8)this->b,(uint8)this->a);
            }
            color4ui8 operator()(int32 r,int32 g,int32 b,int32 a){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                this->a=a;
                return color4ui8((uint8)this->r,(uint8)this->g,(uint8)this->b,(uint8)this->a);
            }
            color4ui8 operator()(int64 r,int64 g,int64 b,int64 a){
                //
                this->r=r;
                this->g=g;
                this->b=b;
                this->a=a;
                return color4ui8((uint8)this->r,(uint8)this->g,(uint8)this->b,(uint8)this->a);
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
                this->r=this->g=this->b=1.0f;
			}
			color3f32(edk::float32 r,edk::float32 g,edk::float32 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(edk::float64 r,edk::float64 g,edk::float64 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(int8 r,int8 g,int8 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(int16 r,int16 g,int16 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(int32 r,int32 g,int32 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(int64 r,int64 g,int64 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(uint8 r,uint8 g,uint8 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(uint16 r,uint16 g,uint16 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(uint32 r,uint32 g,uint32 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
			color3f32(uint64 r,uint64 g,uint64 b){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
			}
            //color3ui8
            color3f32(edk::color3ui8 color){
                //bera as variaveis
                this->r=(edk::float32)color.r/255.f;
                this->g=(edk::float32)color.g/255.f;
                this->b=(edk::float32)color.b/255.f;
            }
			//operators

			//=
            color3f32 operator=(edk::color3ui8 color){
                //bera as variaveis
                this->r=((edk::float32)color.r/255.f);
                this->g=((edk::float32)color.g/255.f);
                this->b=((edk::float32)color.b/255.f);
                return *this;
            }
            color3f32 operator=(color3f32 color){
				//
				this->r=color.r;
				this->g=color.g;
				this->b=color.b;
                return *this;
            }
            color3f32 operator=(vec2i8 color){
                //
                this->r=color.x;
                this->g=color.y;
                this->b=(edk::float32)0;
                return *this;
            }
            color3f32 operator=(edk::float32 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(edk::float64 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(int8 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(int16 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(int32 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(int64 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(uint8 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(uint16 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(uint32 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}
            color3f32 operator=(uint64 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
                return *this;
			}

            //==
			bool operator==(color3f32 color){
				//
				return (this->r==color.r&&this->g==color.g&&this->b==color.b);
			}
			//!=
			bool operator!=(color3f32 color){
				//
				return (this->r!=color.r||this->g!=color.g||this->b!=color.b);
			}

			//+
            color3f32 operator+(edk::color3ui8 color){
                //bera as variaveis
                color3f32 ret;
                ret.r=this->r+((edk::float32)color.r/255.f);
                ret.g=this->g+((edk::float32)color.g/255.f);
                ret.b=this->b+((edk::float32)color.b/255.f);
                return ret;
            }
			color3f32 operator+(color3f32 color){
				//
				color3f32 ret;
				ret.r=this->r+color.r;
				ret.g=this->g+color.g;
				ret.b=this->b+color.b;
				return ret;
			}
			color3f32 operator+(vec2i8 color){
				//
				color3f32 ret;
				ret.r=this->r+color.x;
				ret.g=this->g+color.y;
				return ret;
			}
			color3f32 operator+(edk::float32 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(edk::float64 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(int8 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(int16 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(int32 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(int64 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(uint8 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(uint16 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(uint32 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}
			color3f32 operator+(uint64 n){
				//
				color3f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				return ret;
			}

            //+=
            void operator+=(edk::color3ui8 color){
                //bera as variaveis
                this->r+=((edk::float32)color.r/255.f);
                this->g+=((edk::float32)color.g/255.f);
                this->b+=((edk::float32)color.b/255.f);
            }
			void operator+=(color3f32 color){
				//
				this->r+=color.r;
				this->g+=color.g;
				this->b+=color.b;
			}
			void operator+=(vec2i8 color){
				//
				this->r+=color.x;
				this->g+=color.y;
			}
			void operator+=(edk::float32 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(edk::float64 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(int8 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(int16 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(int32 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(int64 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(uint8 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(uint16 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(uint32 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}
			void operator+=(uint64 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
			}

			//-
            color3f32 operator-(edk::color3ui8 color){
                //bera as variaveis
                color3f32 ret;
                ret.r=this->r-((edk::float32)color.r/255.f);
                ret.g=this->g-((edk::float32)color.g/255.f);
                ret.b=this->b-((edk::float32)color.b/255.f);
                return ret;
            }
			color3f32 operator-(color3f32 color){
				//
				color3f32 ret;
				ret.r=this->r-color.r;
				ret.g=this->g-color.g;
				ret.b=this->b-color.b;
				return ret;
			}
			color3f32 operator-(vec2i8 color){
				//
				color3f32 ret;
				ret.r=this->r-color.x;
				ret.g=this->g-color.y;
				return ret;
			}
			color3f32 operator-(edk::float32 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(edk::float64 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(int8 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(int16 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(int32 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(int64 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(uint8 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(uint16 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(uint32 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}
			color3f32 operator-(uint64 n){
				//
				color3f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				return ret;
			}

			//-=
            void operator-=(edk::color3ui8 color){
                //bera as variaveis
                this->r-=((edk::float32)color.r/255.f);
                this->g-=((edk::float32)color.g/255.f);
                this->b-=((edk::float32)color.b/255.f);
            }
			void operator-=(color3f32 color){
				//
				this->r-=color.r;
				this->g-=color.g;
				this->b-=color.b;
			}
			void operator-=(vec2i8 color){
				//
				this->r-=color.x;
				this->g-=color.y;
			}
			void operator-=(edk::float32 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(edk::float64 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(int8 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(int16 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(int32 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(int64 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(uint8 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(uint16 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(uint32 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}
			void operator-=(uint64 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
			}

			//*
            color3f32 operator*(edk::color3ui8 color){
                //bera as variaveis
                color3f32 ret;
                ret.r=this->r*((edk::float32)color.r/255.f);
                ret.g=this->g*((edk::float32)color.g/255.f);
                ret.b=this->b*((edk::float32)color.b/255.f);
                return ret;
            }
			color3f32 operator*(color3f32 color){
				//
				color3f32 ret;
				ret.r=this->r*color.r;
				ret.g=this->g*color.g;
				ret.b=this->b*color.b;
				return ret;
			}
			color3f32 operator*(vec2i8 color){
				//
				color3f32 ret;
				ret.r=this->r*color.x;
				ret.g=this->g*color.y;
				return ret;
			}
			color3f32 operator*(edk::float32 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(edk::float64 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(int8 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(int16 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(int32 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(int64 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(uint8 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(uint16 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(uint32 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}
			color3f32 operator*(uint64 n){
				//
				color3f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				return ret;
			}

			//*=
            void operator*=(edk::color3ui8 color){
                //bera as variaveis
                this->r*=((edk::float32)color.r/255.f);
                this->g*=((edk::float32)color.g/255.f);
                this->b*=((edk::float32)color.b/255.f);
            }
			void operator*=(color3f32 color){
				//
				this->r*=color.r;
				this->g*=color.g;
				this->b*=color.b;
			}
			void operator*=(vec2i8 color){
				//
				this->r*=color.x;
				this->g*=color.y;
			}
			void operator*=(edk::float32 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(edk::float64 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(int8 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(int16 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(int32 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(int64 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(uint8 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(uint16 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(uint32 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}
			void operator*=(uint64 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
			}

			// /
            color3f32 operator/(edk::color3ui8 color){
                //bera as variaveis
                color3f32 ret;
                ret.r=this->r/((edk::float32)color.r/255.f);
                ret.g=this->g/((edk::float32)color.g/255.f);
                ret.b=this->b/((edk::float32)color.b/255.f);
                return ret;
            }
			color3f32 operator/(color3f32 color){
				//
				color3f32 ret;
				ret.r=this->r/color.r;
				ret.g=this->g/color.g;
				ret.b=this->b/color.b;
				return ret;
			}
			color3f32 operator/(vec2i8 color){
				//
				color3f32 ret;
				ret.r=this->r/color.x;
				ret.g=this->g/color.y;
				return ret;
			}
			color3f32 operator/(edk::float32 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(edk::float64 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(int8 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(int16 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(int32 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(int64 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(uint8 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(uint16 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(uint32 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}
			color3f32 operator/(uint64 n){
				//
				color3f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				return ret;
			}

			// /=
            void operator/=(edk::color3ui8 color){
                //bera as variaveis
                this->r/=((edk::float32)color.r/255.f);
                this->g/=((edk::float32)color.g/255.f);
                this->b/=((edk::float32)color.b/255.f);
            }
			void operator/=(color3f32 color){
				//
				this->r/=color.r;
				this->g/=color.g;
				this->b/=color.b;
			}
			void operator/=(vec2i8 color){
				//
				this->r/=color.x;
				this->g/=color.y;
			}
			void operator/=(edk::float32 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(edk::float64 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(int8 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(int16 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(int32 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(int64 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(uint8 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(uint16 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(uint32 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}
			void operator/=(uint64 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
			}

			//++
			color3f32 operator++(){
			    //
			    ++this->r;
			    ++this->g;
			    ++this->b;
			    return color3f32(this->r,this->g,this->b);
			}
            color3f32 operator++(int32){
			    //
			    this->r++;
			    this->g++;
			    this->b++;
			    return color3f32(this->r,this->g,this->b);
			}

			//--
			color3f32 operator--(){
			    //
			    --this->r;
			    --this->g;
			    --this->b;
			    return color3f32(this->r,this->g,this->b);
			}
            color3f32 operator--(int32){
			    //
			    this->r--;
			    this->g--;
			    this->b--;
			    return color3f32(this->r,this->g,this->b);
			}

			//
			color3f32 operator()(edk::float32 r,edk::float32 g,edk::float32 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(edk::float64 r,edk::float64 g,edk::float64 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(int8 r,int8 g,int8 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(int16 r,int16 g,int16 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(int32 r,int32 g,int32 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(int64 r,int64 g,int64 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(uint8 r,uint8 g,uint8 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(uint16 r,uint16 g,uint16 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(uint32 r,uint32 g,uint32 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
			}
			color3f32 operator()(uint64 r,uint64 g,uint64 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b);
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
                this->r=this->g=this->b=1.0f;
			}
			color3f64(edk::float32 r,edk::float32 g,edk::float32 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(edk::float64 r,edk::float64 g,edk::float64 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(int8 r,int8 g,int8 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(int16 r,int16 g,int16 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(int32 r,int32 g,int32 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(int64 r,int64 g,int64 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(uint8 r,uint8 g,uint8 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(uint16 r,uint16 g,uint16 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(uint32 r,uint32 g,uint32 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
			color3f64(uint64 r,uint64 g,uint64 b){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
			}
            //color3ui8
            color3f64(edk::color3ui8 color){
                //bera as variaveis
                this->r=(edk::float64)color.r/255.f;
                this->g=(edk::float64)color.g/255.f;
                this->b=(edk::float64)color.b/255.f;
            }

			//operators

			//=
            color3f64 operator=(edk::color3ui8 color){
                //bera as variaveis
                this->r=((edk::float64)color.r/255.f);
                this->g=((edk::float64)color.g/255.f);
                this->b=((edk::float64)color.b/255.f);
                return *this;
            }
            color3f64 operator=(color3f64 color){
				//
				this->r=color.r;
				this->g=color.g;
				this->b=color.b;
                return *this;
			}
            color3f64 operator=(vec2i8 color){
				//
				this->r=color.x;
				this->g=color.y;
				this->b=(edk::float64)0;
                return *this;
			}
            color3f64 operator=(edk::float32 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(edk::float64 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(int8 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(int16 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(int32 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(int64 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(uint8 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(uint16 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(uint32 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}
            color3f64 operator=(uint64 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
                return *this;
			}

			//==
			bool operator==(color3f64 color){
				//
				return (this->r==color.r&&this->g==color.g&&this->b==color.b);
			}
			//!=
			bool operator!=(color3f64 color){
				//
				return (this->r!=color.r||this->g!=color.g||this->b!=color.b);
			}

			//+
            color3f64 operator+(edk::color3ui8 color){
                //bera as variaveis
                color3f64 ret;
                ret.r=this->r+((edk::float64)color.r/255.f);
                ret.g=this->g+((edk::float64)color.g/255.f);
                ret.b=this->b+((edk::float64)color.b/255.f);
                return ret;
            }
			color3f64 operator+(color3f64 color){
				//
				color3f64 ret;
				ret.r=this->r+color.r;
				ret.g=this->g+color.g;
				ret.b=this->b+color.b;
				return ret;
			}
			color3f64 operator+(vec2i8 color){
				//
				color3f64 ret;
				ret.r=this->r+color.x;
				ret.g=this->g+color.y;
				return ret;
			}
			color3f64 operator+(edk::float32 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(edk::float64 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(int8 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(int16 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(int32 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(int64 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(uint8 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(uint16 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(uint32 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}
			color3f64 operator+(uint64 n){
				//
				color3f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				return ret;
			}

            //+=
            void operator+=(edk::color3ui8 color){
                //bera as variaveis
                this->r+=((edk::float64)color.r/255.f);
                this->g+=((edk::float64)color.g/255.f);
                this->b+=((edk::float64)color.b/255.f);
            }
			void operator+=(color3f64 color){
				//
				this->r+=color.r;
				this->g+=color.g;
				this->b+=color.b;
			}
			void operator+=(vec2i8 color){
				//
				this->r+=color.x;
				this->g+=color.y;
			}
			void operator+=(edk::float32 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(edk::float64 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(int8 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(int16 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(int32 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(int64 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(uint8 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(uint16 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(uint32 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}
			void operator+=(uint64 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
			}

			//-
            color3f64 operator-(edk::color3ui8 color){
                //bera as variaveis
                color3f64 ret;
                ret.r=this->r-((edk::float64)color.r/255.f);
                ret.g=this->g-((edk::float64)color.g/255.f);
                ret.b=this->b-((edk::float64)color.b/255.f);
                return ret;
            }
			color3f64 operator-(color3f64 color){
				//
				color3f64 ret;
				ret.r=this->r-color.r;
				ret.g=this->g-color.g;
				ret.b=this->b-color.b;
				return ret;
			}
			color3f64 operator-(vec2i8 color){
				//
				color3f64 ret;
				ret.r=this->r-color.x;
				ret.g=this->g-color.y;
				return ret;
			}
			color3f64 operator-(edk::float32 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(edk::float64 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(int8 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(int16 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(int32 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(int64 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(uint8 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(uint16 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(uint32 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}
			color3f64 operator-(uint64 n){
				//
				color3f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				return ret;
			}

			//-=
            void operator-=(edk::color3ui8 color){
                //bera as variaveis
                this->r-=((edk::float64)color.r/255.f);
                this->g-=((edk::float64)color.g/255.f);
                this->b-=((edk::float64)color.b/255.f);
            }
			void operator-=(color3f64 color){
				//
				this->r-=color.r;
				this->g-=color.g;
				this->b-=color.b;
			}
			void operator-=(vec2i8 color){
				//
				this->r-=color.x;
				this->g-=color.y;
			}
			void operator-=(edk::float32 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(edk::float64 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(int8 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(int16 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(int32 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(int64 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(uint8 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(uint16 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(uint32 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}
			void operator-=(uint64 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
			}

			//*
            color3f64 operator*(edk::color3ui8 color){
                //bera as variaveis
                color3f64 ret;
                ret.r=this->r*((edk::float64)color.r/255.f);
                ret.g=this->g*((edk::float64)color.g/255.f);
                ret.b=this->b*((edk::float64)color.b/255.f);
                return ret;
            }
			color3f64 operator*(color3f64 color){
				//
				color3f64 ret;
				ret.r=this->r*color.r;
				ret.g=this->g*color.g;
				ret.b=this->b*color.b;
				return ret;
			}
			color3f64 operator*(vec2i8 color){
				//
				color3f64 ret;
				ret.r=this->r*color.x;
				ret.g=this->g*color.y;
				return ret;
			}
			color3f64 operator*(edk::float32 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(edk::float64 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(int8 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(int16 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(int32 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(int64 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(uint8 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(uint16 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(uint32 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}
			color3f64 operator*(uint64 n){
				//
				color3f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				return ret;
			}

			//*=
            void operator*=(edk::color3ui8 color){
                //bera as variaveis
                this->r*=((edk::float64)color.r/255.f);
                this->g*=((edk::float64)color.g/255.f);
                this->b*=((edk::float64)color.b/255.f);
            }
			void operator*=(color3f64 color){
				//
				this->r*=color.r;
				this->g*=color.g;
				this->b*=color.b;
			}
			void operator*=(vec2i8 color){
				//
				this->r*=color.x;
				this->g*=color.y;
			}
			void operator*=(edk::float32 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(edk::float64 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(int8 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(int16 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(int32 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(int64 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(uint8 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(uint16 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(uint32 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}
			void operator*=(uint64 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
			}

			// /
            color3f64 operator/(edk::color3ui8 color){
                //bera as variaveis
                color3f64 ret;
                ret.r=this->r/((edk::float64)color.r/255.f);
                ret.g=this->g/((edk::float64)color.g/255.f);
                ret.b=this->b/((edk::float64)color.b/255.f);
                return ret;
            }
			color3f64 operator/(color3f64 color){
				//
				color3f64 ret;
				ret.r=this->r/color.r;
				ret.g=this->g/color.g;
				ret.b=this->b/color.b;
				return ret;
			}
			color3f64 operator/(vec2i8 color){
				//
				color3f64 ret;
				ret.r=this->r/color.x;
				ret.g=this->g/color.y;
				return ret;
			}
			color3f64 operator/(edk::float32 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(edk::float64 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(int8 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(int16 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(int32 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(int64 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(uint8 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(uint16 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(uint32 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}
			color3f64 operator/(uint64 n){
				//
				color3f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				return ret;
			}

			// /=
            void operator/=(edk::color3ui8 color){
                //bera as variaveis
                this->r/=((edk::float64)color.r/255.f);
                this->g/=((edk::float64)color.g/255.f);
                this->b/=((edk::float64)color.b/255.f);
            }
			void operator/=(color3f64 color){
				//
				this->r/=color.r;
				this->g/=color.g;
				this->b/=color.b;
			}
			void operator/=(vec2i8 color){
				//
				this->r/=color.x;
				this->g/=color.y;
			}
			void operator/=(edk::float32 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(edk::float64 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(int8 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(int16 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(int32 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(int64 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(uint8 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(uint16 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(uint32 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}
			void operator/=(uint64 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
			}

			//++
			color3f64 operator++(){
			    //
			    ++this->r;
			    ++this->g;
			    ++this->b;
			    return color3f64(this->r,this->g,this->b);
			}
            color3f64 operator++(int32){
			    //
			    this->r++;
			    this->g++;
			    this->b++;
			    return color3f64(this->r,this->g,this->b);
			}

			//--
			color3f64 operator--(){
			    //
			    --this->r;
			    --this->g;
			    --this->b;
			    return color3f64(this->r,this->g,this->b);
			}
            color3f64 operator--(int32){
			    //
			    this->r--;
			    this->g--;
			    this->b--;
			    return color3f64(this->r,this->g,this->b);
			}

			//
			color3f64 operator()(edk::float32 r,edk::float32 g,edk::float32 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(edk::float64 r,edk::float64 g,edk::float64 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(int8 r,int8 g,int8 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(int16 r,int16 g,int16 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(int32 r,int32 g,int32 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(int64 r,int64 g,int64 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(uint8 r,uint8 g,uint8 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(uint16 r,uint16 g,uint16 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(uint32 r,uint32 g,uint32 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
			}
			color3f64 operator()(uint64 r,uint64 g,uint64 b){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    return color3f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b);
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
                this->r=this->g=this->b=this->a=1.f;
			}
			color4f32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
			}
			color4f32(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
			}
			color4f32(int8 r,int8 g,int8 b,int8 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
			}
			color4f32(int16 r,int16 g,int16 b,int16 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
			}
			color4f32(int32 r,int32 g,int32 b,int32 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
			}
			color4f32(int64 r,int64 g,int64 b,int64 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
			}
			color4f32(uint8 r,uint8 g,uint8 b,uint8 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
			}
			color4f32(uint16 r,uint16 g,uint16 b,uint16 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
			}
			color4f32(uint32 r,uint32 g,uint32 b,uint32 a){
				//bera as variaveis
				this->r=(edk::float32)r;
				this->g=(edk::float32)g;
				this->b=(edk::float32)b;
				this->a=(edk::float32)a;
            }
            color4f32(uint64 r,uint64 g,uint64 b,uint64 a){
                //bera as variaveis
                this->r=(edk::float32)r;
                this->g=(edk::float32)g;
                this->b=(edk::float32)b;
                this->a=(edk::float32)a;
            }
            color4f32(edk::color3ui8 color){
                //bera as variaveis
                this->r=((edk::float32)color.r/255.f);
                this->g=((edk::float32)color.g/255.f);
                this->b=((edk::float32)color.b/255.f);
                this->a=((edk::float32)1.f);
            }
            color4f32(edk::color4ui8 color){
                //bera as variaveis
                this->r=((edk::float32)color.r/255.f);
                this->g=((edk::float32)color.g/255.f);
                this->b=((edk::float32)color.b/255.f);
                this->a=((edk::float32)color.a/255.f);
            }
			//operators

            //=
            color4f32 operator=(edk::color3ui8 color){
                //bera as variaveis
                this->r=((edk::float32)color.r/255.f);
                this->g=((edk::float32)color.g/255.f);
                this->b=((edk::float32)color.b/255.f);
                this->a=1.f;
                return *this;
            }
            color4f32 operator=(edk::color4ui8 color){
                //bera as variaveis
                this->r=((edk::float32)color.r/255.f);
                this->g=((edk::float32)color.g/255.f);
                this->b=((edk::float32)color.b/255.f);
                this->a=((edk::float32)color.a/255.f);
                return *this;
            }
            color4f32 operator=(color4f32 color){
                //
                this->r=color.r;
                this->g=color.g;
                this->b=color.b;
                this->a=color.a;
                return *this;
            }
            color4f32 operator=(color3f32 color){
                //
                this->r=color.r;
                this->g=color.g;
                this->b=color.b;
                return *this;
            }
            color4f32 operator=(vec3i8 color){
				//
				this->r=color.x;
				this->g=color.y;
				this->b=color.z;
				this->a=0;
                return *this;
			}
            color4f32 operator=(vec2i8 color){
				//
				this->r=color.x;
				this->g=color.y;
				this->b=0;
				this->a=0;
                return *this;
			}
            color4f32 operator=(edk::float32 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(edk::float64 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(int8 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(int16 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(int32 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(int64 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(uint8 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(uint16 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(uint32 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}
            color4f32 operator=(uint64 n){
				//
				this->r=(edk::float32)n;
				this->g=(edk::float32)n;
				this->b=(edk::float32)n;
				this->a=(edk::float32)n;
                return *this;
			}

            //==
            bool operator==(color4f32 color){
				//
				return (this->r==color.r&&this->g==color.g&&this->b==color.b&&this->a==color.a);
			}
			//!=
			bool operator!=(color4f32 color){
				//
				return (this->r!=color.r||this->g!=color.g||this->b!=color.b||this->a!=color.a);
			}

            //+
            color4f32 operator+(edk::color3ui8 color){
                //bera as variaveis
                color4f32 ret;
                ret.r=this->r+((edk::float32)color.r/255.f);
                ret.g=this->g+((edk::float32)color.g/255.f);
                ret.b=this->b+((edk::float32)color.b/255.f);
                return ret;
            }
            color4f32 operator+(edk::color4ui8 color){
                //bera as variaveis
                color4f32 ret;
                ret.r=this->r+((edk::float32)color.r/255.f);
                ret.g=this->g+((edk::float32)color.g/255.f);
                ret.b=this->b+((edk::float32)color.b/255.f);
                ret.a=this->a+((edk::float32)color.a/255.f);
                return ret;
            }
			color4f32 operator+(color4f32 color){
				//
				color4f32 ret;
				ret.r=this->r+color.r;
				ret.g=this->g+color.g;
				ret.b=this->b+color.b;
				ret.a=this->a+color.a;
				return ret;
			}
			color4f32 operator+(vec3i8 color){
				//
				color4f32 ret;
				ret.r=this->r+color.x;
				ret.g=this->g+color.y;
				ret.b=this->b+color.z;
				return ret;
			}
			color4f32 operator+(vec2i8 color){
				//
				color4f32 ret;
				ret.r=this->r+color.x;
				ret.g=this->g+color.y;
				return ret;
			}
			color4f32 operator+(edk::float32 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(edk::float64 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(int8 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(int16 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(int32 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(int64 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(uint8 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(uint16 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(uint32 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}
			color4f32 operator+(uint64 n){
				//
				color4f32 ret;
				ret.r=this->r+(edk::float32)n;
				ret.g=this->g+(edk::float32)n;
				ret.b=this->b+(edk::float32)n;
				ret.a=this->a+(edk::float32)n;
				return ret;
			}

            //+=
            void operator+=(edk::color3ui8 color){
                //bera as variaveis
                this->r+=((edk::float32)color.r/255.f);
                this->g+=((edk::float32)color.g/255.f);
                this->b+=((edk::float32)color.b/255.f);
            }
            void operator+=(edk::color4ui8 color){
                //bera as variaveis
                this->r+=((edk::float32)color.r/255.f);
                this->g+=((edk::float32)color.g/255.f);
                this->b+=((edk::float32)color.b/255.f);
                this->a+=((edk::float32)color.a/255.f);
            }
			void operator+=(color4f32 color){
				//
				this->r+=color.r;
				this->g+=color.g;
				this->b+=color.b;
				this->a+=color.a;
			}
			void operator+=(vec3i8 color){
				//
				this->r+=color.x;
				this->g+=color.y;
				this->b+=color.z;
			}
			void operator+=(vec2i8 color){
				//
				this->r+=color.x;
				this->g+=color.y;
			}
			void operator+=(edk::float32 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(edk::float64 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(int8 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(int16 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(int32 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(int64 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(uint8 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(uint16 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(uint32 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}
			void operator+=(uint64 n){
				//
				this->r+=(edk::float32)n;
				this->g+=(edk::float32)n;
				this->b+=(edk::float32)n;
				this->a+=(edk::float32)n;
			}

			//-
            color4f32 operator-(edk::color3ui8 color){
                //bera as variaveis
                color4f32 ret;
                ret.r=this->r-((edk::float32)color.r/255.f);
                ret.g=this->g-((edk::float32)color.g/255.f);
                ret.b=this->b-((edk::float32)color.b/255.f);
                return ret;
            }
            color4f32 operator-(edk::color4ui8 color){
                //bera as variaveis
                color4f32 ret;
                ret.r=this->r-((edk::float32)color.r/255.f);
                ret.g=this->g-((edk::float32)color.g/255.f);
                ret.b=this->b-((edk::float32)color.b/255.f);
                ret.a=this->a-((edk::float32)color.a/255.f);
                return ret;
            }
			color4f32 operator-(color4f32 color){
				//
				color4f32 ret;
				ret.r=this->r-color.r;
				ret.g=this->g-color.g;
				ret.b=this->b-color.b;
				ret.a=this->a-color.a;
				return ret;
			}
			color4f32 operator-(vec3i8 color){
				//
				color4f32 ret;
				ret.r=this->r-color.x;
				ret.g=this->g-color.y;
				ret.b=this->b-color.z;
				return ret;
			}
			color4f32 operator-(vec2i8 color){
				//
				color4f32 ret;
				ret.r=this->r-color.x;
				ret.g=this->g-color.y;
				return ret;
			}
			color4f32 operator-(edk::float32 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(edk::float64 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(int8 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(int16 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(int32 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(int64 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(uint8 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(uint16 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(uint32 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}
			color4f32 operator-(uint64 n){
				//
				color4f32 ret;
				ret.r=this->r-(edk::float32)n;
				ret.g=this->g-(edk::float32)n;
				ret.b=this->b-(edk::float32)n;
				ret.a=this->a-(edk::float32)n;
				return ret;
			}

			//-=
            void operator-=(edk::color3ui8 color){
                //bera as variaveis
                this->r+=((edk::float32)color.r/255.f);
                this->g+=((edk::float32)color.g/255.f);
                this->b+=((edk::float32)color.b/255.f);
            }
            void operator-=(edk::color4ui8 color){
                //bera as variaveis
                this->r+=((edk::float32)color.r/255.f);
                this->g+=((edk::float32)color.g/255.f);
                this->b+=((edk::float32)color.b/255.f);
                this->a+=((edk::float32)color.a/255.f);
            }
			void operator-=(color4f32 color){
				//
				this->r-=color.r;
				this->g-=color.g;
				this->b-=color.b;
				this->a-=color.a;
			}
			void operator-=(vec3i8 color){
				//
				this->r-=color.x;
				this->g-=color.y;
				this->b-=color.z;
			}
			void operator-=(vec2i8 color){
				//
				this->r-=color.x;
				this->g-=color.y;
			}
			void operator-=(edk::float32 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(edk::float64 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(int8 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(int16 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(int32 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(int64 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(uint8 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(uint16 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(uint32 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}
			void operator-=(uint64 n){
				//
				this->r-=(edk::float32)n;
				this->g-=(edk::float32)n;
				this->b-=(edk::float32)n;
				this->a-=(edk::float32)n;
			}

			//*
            color4f32 operator*(edk::color3ui8 color){
                //bera as variaveis
                color4f32 ret;
                ret.r=this->r*((edk::float32)color.r/255.f);
                ret.g=this->g*((edk::float32)color.g/255.f);
                ret.b=this->b*((edk::float32)color.b/255.f);
                return ret;
            }
            color4f32 operator*(edk::color4ui8 color){
                //bera as variaveis
                color4f32 ret;
                ret.r=this->r*((edk::float32)color.r/255.f);
                ret.g=this->g*((edk::float32)color.g/255.f);
                ret.b=this->b*((edk::float32)color.b/255.f);
                ret.a=this->a*((edk::float32)color.a/255.f);
                return ret;
            }
			color4f32 operator*(color4f32 color){
				//
				color4f32 ret;
				ret.r=this->r*color.r;
				ret.g=this->g*color.g;
				ret.b=this->b*color.b;
				ret.a=this->a*color.a;
				return ret;
			}
			color4f32 operator*(vec3i8 color){
				//
				color4f32 ret;
				ret.r=this->r*color.x;
				ret.g=this->g*color.y;
				ret.b=this->b*color.z;
				return ret;
			}
			color4f32 operator*(vec2i8 color){
				//
				color4f32 ret;
				ret.r=this->r*color.x;
				ret.g=this->g*color.y;
				return ret;
			}
			color4f32 operator*(edk::float32 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(edk::float64 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(int8 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(int16 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(int32 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(int64 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(uint8 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(uint16 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(uint32 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}
			color4f32 operator*(uint64 n){
				//
				color4f32 ret;
				ret.r=this->r*(edk::float32)n;
				ret.g=this->g*(edk::float32)n;
				ret.b=this->b*(edk::float32)n;
				ret.a=this->a*(edk::float32)n;
				return ret;
			}

			//*=
            void operator*=(edk::color3ui8 color){
                //bera as variaveis
                this->r*=((edk::float32)color.r/255.f);
                this->g*=((edk::float32)color.g/255.f);
                this->b*=((edk::float32)color.b/255.f);
            }
            void operator*=(edk::color4ui8 color){
                //bera as variaveis
                this->r*=((edk::float32)color.r/255.f);
                this->g*=((edk::float32)color.g/255.f);
                this->b*=((edk::float32)color.b/255.f);
                this->a*=((edk::float32)color.a/255.f);
            }
			void operator*=(color4f32 color){
				//
				this->r*=color.r;
				this->g*=color.g;
				this->b*=color.b;
				this->a*=color.a;
			}
			void operator*=(vec3i8 color){
				//
				this->r*=color.x;
				this->g*=color.y;
				this->b*=color.z;
			}
			void operator*=(vec2i8 color){
				//
				this->r*=color.x;
				this->g*=color.y;
			}
			void operator*=(edk::float32 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(edk::float64 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(int8 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(int16 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(int32 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(int64 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(uint8 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(uint16 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(uint32 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}
			void operator*=(uint64 n){
				//
				this->r*=(edk::float32)n;
				this->g*=(edk::float32)n;
				this->b*=(edk::float32)n;
				this->a*=(edk::float32)n;
			}

			// /
            color4f32 operator/(edk::color3ui8 color){
                //bera as variaveis
                color4f32 ret;
                ret.r=this->r/((edk::float32)color.r/255.f);
                ret.g=this->g/((edk::float32)color.g/255.f);
                ret.b=this->b/((edk::float32)color.b/255.f);
                return ret;
            }
            color4f32 operator/(edk::color4ui8 color){
                //bera as variaveis
                color4f32 ret;
                ret.r=this->r/((edk::float32)color.r/255.f);
                ret.g=this->g/((edk::float32)color.g/255.f);
                ret.b=this->b/((edk::float32)color.b/255.f);
                ret.a=this->a/((edk::float32)color.a/255.f);
                return ret;
            }
			color4f32 operator/(color4f32 color){
				//
				color4f32 ret;
				ret.r=this->r/color.r;
				ret.g=this->g/color.g;
				ret.b=this->b/color.b;
				ret.a=this->a/color.a;
				return ret;
			}
			color4f32 operator/(vec3i8 color){
				//
				color4f32 ret;
				ret.r=this->r/color.x;
				ret.g=this->g/color.y;
				ret.b=this->b/color.z;
				return ret;
			}
			color4f32 operator/(vec2i8 color){
				//
				color4f32 ret;
				ret.r=this->r/color.x;
				ret.g=this->g/color.y;
				return ret;
			}
			color4f32 operator/(edk::float32 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(edk::float64 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(int8 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(int16 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(int32 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(int64 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(uint8 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(uint16 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(uint32 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}
			color4f32 operator/(uint64 n){
				//
				color4f32 ret;
				ret.r=this->r/(edk::float32)n;
				ret.g=this->g/(edk::float32)n;
				ret.b=this->b/(edk::float32)n;
				ret.a=this->a/(edk::float32)n;
				return ret;
			}

			// /=
            void operator/=(edk::color3ui8 color){
                //bera as variaveis
                this->r*=((edk::float32)color.r/255.f);
                this->g*=((edk::float32)color.g/255.f);
                this->b*=((edk::float32)color.b/255.f);
            }
            void operator/=(edk::color4ui8 color){
                //bera as variaveis
                this->r/=((edk::float32)color.r/255.f);
                this->g/=((edk::float32)color.g/255.f);
                this->b/=((edk::float32)color.b/255.f);
                this->a/=((edk::float32)color.a/255.f);
            }
			void operator/=(color4f32 color){
				//
				this->r/=color.r;
				this->g/=color.g;
				this->b/=color.b;
				this->a/=color.a;
			}
			void operator/=(vec3i8 color){
				//
				this->r/=color.x;
				this->g/=color.y;
				this->b/=color.z;
			}
			void operator/=(vec2i8 color){
				//
				this->r/=color.x;
				this->g/=color.y;
			}
			void operator/=(edk::float32 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(edk::float64 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(int8 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(int16 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(int32 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(int64 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(uint8 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(uint16 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(uint32 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}
			void operator/=(uint64 n){
				//
				this->r/=(edk::float32)n;
				this->g/=(edk::float32)n;
				this->b/=(edk::float32)n;
				this->a/=(edk::float32)n;
			}

			//++
			color4f32 operator++(){
			    //
			    ++this->r;
			    ++this->g;
			    ++this->b;
			    ++this->a;
			    return color4f32(this->r,this->g,this->b,this->a);
			}
            color4f32 operator++(int32){
			    //
			    this->r++;
			    this->g++;
			    this->b++;
			    this->a++;
			    return color4f32(this->r,this->g,this->b,this->a);
			}

			//--
			color4f32 operator--(){
			    //
			    --this->r;
			    --this->g;
			    --this->b;
			    --this->a;
			    return color4f32(this->r,this->g,this->b,this->a);
			}
            color4f32 operator--(int32){
			    //
			    this->r--;
			    this->g--;
			    this->b--;
			    this->a--;
			    return color4f32(this->r,this->g,this->b,this->a);
			}

			//
			color4f32 operator()(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(int8 r,int8 g,int8 b,int8 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(int16 r,int16 g,int16 b,int16 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(int32 r,int32 g,int32 b,int32 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(int64 r,int64 g,int64 b,int64 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(uint8 r,uint8 g,uint8 b,uint8 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(uint16 r,uint16 g,uint16 b,uint16 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(uint32 r,uint32 g,uint32 b,uint32 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
			}
			color4f32 operator()(uint64 r,uint64 g,uint64 b,uint64 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f32((edk::float32)this->r,(edk::float32)this->g,(edk::float32)this->b,(edk::float32)this->a);
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
                this->r=this->g=this->b=this->a=1.0f;
			}
			color4f64(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(int8 r,int8 g,int8 b,int8 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(int16 r,int16 g,int16 b,int16 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(int32 r,int32 g,int32 b,int32 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(int64 r,int64 g,int64 b,int64 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(uint8 r,uint8 g,uint8 b,uint8 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(uint16 r,uint16 g,uint16 b,uint16 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(uint32 r,uint32 g,uint32 b,uint32 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
			color4f64(uint64 r,uint64 g,uint64 b,uint64 a){
				//bera as variaveis
				this->r=(edk::float64)r;
				this->g=(edk::float64)g;
				this->b=(edk::float64)b;
				this->a=(edk::float64)a;
			}
            color4f64(edk::color3ui8 color){
                //bera as variaveis
                this->r=(edk::float64)color.r/255.f;
                this->g=(edk::float64)color.g/255.f;
                this->b=(edk::float64)color.b/255.f;
                this->a=(edk::float64)1.f;
            }
            color4f64(edk::color4ui8 color){
                //bera as variaveis
                this->r=(edk::float64)color.r/255.f;
                this->g=(edk::float64)color.g/255.f;
                this->b=(edk::float64)color.b/255.f;
                this->a=(edk::float64)color.a/255.f;
            }
			//operators
			//=
            color4f64 operator=(edk::color3ui8 color){
                //bera as variaveis
                this->r=(edk::float64)color.r/255.f;
                this->g=(edk::float64)color.g/255.f;
                this->b=(edk::float64)color.b/255.f;
                this->a=(edk::float64)1.f;
                return *this;
            }
            color4f64 operator=(edk::color4ui8 color){
                //bera as variaveis
                this->r=(edk::float64)color.r/255.f;
                this->g=(edk::float64)color.g/255.f;
                this->b=(edk::float64)color.b/255.f;
                this->a=(edk::float64)color.a/255.f;
                return *this;
            }
            color4f64 operator=(color4f64 color){
				//
				this->r=color.r;
				this->g=color.g;
				this->b=color.b;
				this->a=color.a;
                return *this;
			}
            color4f64 operator=(vec3i8 color){
				//
				this->r=color.x;
				this->g=color.y;
				this->b=color.z;
				this->a=0;
                return *this;
			}
            color4f64 operator=(vec2i8 color){
				//
				this->r=color.x;
				this->g=color.y;
				this->b=0;
				this->a=0;
                return *this;
			}
            color4f64 operator=(edk::float32 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(edk::float64 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(int8 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(int16 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(int32 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(int64 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(uint8 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(uint16 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(uint32 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}
            color4f64 operator=(uint64 n){
				//
				this->r=(edk::float64)n;
				this->g=(edk::float64)n;
				this->b=(edk::float64)n;
				this->a=(edk::float64)n;
                return *this;
			}

			//==
			bool operator==(color4f64 color){
				//
				return (this->r==color.r&&this->g==color.g&&this->b==color.b&&this->a==color.a);
			}
			//!=
			bool operator!=(color4f64 color){
				//
				return (this->r!=color.r||this->g!=color.g||this->b!=color.b||this->a!=color.a);
			}

			//+
            color4f64 operator+(edk::color3ui8 color){
                //bera as variaveis
                color4f64 ret;
                ret.r=this->r+((edk::float64)color.r/255.f);
                ret.g=this->g+((edk::float64)color.g/255.f);
                ret.b=this->b+((edk::float64)color.b/255.f);
                return ret;
            }
            color4f64 operator+(edk::color4ui8 color){
                //bera as variaveis
                color4f64 ret;
                ret.r=this->r+((edk::float64)color.r/255.f);
                ret.g=this->g+((edk::float64)color.g/255.f);
                ret.b=this->b+((edk::float64)color.b/255.f);
                ret.a=this->a+((edk::float64)color.a/255.f);
                return ret;
            }
			color4f64 operator+(color4f64 color){
				//
				color4f64 ret;
				ret.r=this->r+color.r;
				ret.g=this->g+color.g;
				ret.b=this->b+color.b;
				ret.a=this->a+color.a;
				return ret;
			}
			color4f64 operator+(vec3i8 color){
				//
				color4f64 ret;
				ret.r=this->r+color.x;
				ret.g=this->g+color.y;
				ret.b=this->b+color.z;
				return ret;
			}
			color4f64 operator+(vec2i8 color){
				//
				color4f64 ret;
				ret.r=this->r+color.x;
				ret.g=this->g+color.y;
				return ret;
			}
			color4f64 operator+(edk::float32 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(edk::float64 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(int8 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(int16 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(int32 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(int64 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(uint8 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(uint16 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(uint32 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}
			color4f64 operator+(uint64 n){
				//
				color4f64 ret;
				ret.r=this->r+(edk::float64)n;
				ret.g=this->g+(edk::float64)n;
				ret.b=this->b+(edk::float64)n;
				ret.a=this->a+(edk::float64)n;
				return ret;
			}

            //+=
            void operator+=(edk::color3ui8 color){
                //bera as variaveis
                this->r+=((edk::float64)color.r/255.f);
                this->g+=((edk::float64)color.g/255.f);
                this->b+=((edk::float64)color.b/255.f);
            }
            void operator+=(edk::color4ui8 color){
                //bera as variaveis
                this->r+=((edk::float64)color.r/255.f);
                this->g+=((edk::float64)color.g/255.f);
                this->b+=((edk::float64)color.b/255.f);
                this->a+=((edk::float64)color.a/255.f);
            }
			void operator+=(color4f64 color){
				//
				this->r+=color.r;
				this->g+=color.g;
				this->b+=color.b;
				this->a+=color.a;
			}
			void operator+=(vec3i8 color){
				//
				this->r+=color.x;
				this->g+=color.y;
				this->b+=color.z;
			}
			void operator+=(vec2i8 color){
				//
				this->r+=color.x;
				this->g+=color.y;
			}
			void operator+=(edk::float32 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(edk::float64 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(int8 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(int16 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(int32 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(int64 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(uint8 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(uint16 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(uint32 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}
			void operator+=(uint64 n){
				//
				this->r+=(edk::float64)n;
				this->g+=(edk::float64)n;
				this->b+=(edk::float64)n;
				this->a+=(edk::float64)n;
			}

			//-
            color4f64 operator-(edk::color3ui8 color){
                //bera as variaveis
                color4f64 ret;
                ret.r=this->r+((edk::float64)color.r/255.f);
                ret.g=this->g+((edk::float64)color.g/255.f);
                ret.b=this->b+((edk::float64)color.b/255.f);
                return ret;
            }
            color4f64 operator-(edk::color4ui8 color){
                //bera as variaveis
                color4f64 ret;
                ret.r=this->r+((edk::float64)color.r/255.f);
                ret.g=this->g+((edk::float64)color.g/255.f);
                ret.b=this->b+((edk::float64)color.b/255.f);
                ret.a=this->a+((edk::float64)color.a/255.f);
                return ret;
            }
			color4f64 operator-(color4f64 color){
				//
				color4f64 ret;
				ret.r=this->r-color.r;
				ret.g=this->g-color.g;
				ret.b=this->b-color.b;
				ret.a=this->a-color.a;
				return ret;
			}
			color4f64 operator-(vec3i8 color){
				//
				color4f64 ret;
				ret.r=this->r-color.x;
				ret.g=this->g-color.y;
				ret.b=this->b-color.z;
				return ret;
			}
			color4f64 operator-(vec2i8 color){
				//
				color4f64 ret;
				ret.r=this->r-color.x;
				ret.g=this->g-color.y;
				return ret;
			}
			color4f64 operator-(edk::float32 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(edk::float64 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(int8 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(int16 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(int32 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(int64 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(uint8 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(uint16 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(uint32 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}
			color4f64 operator-(uint64 n){
				//
				color4f64 ret;
				ret.r=this->r-(edk::float64)n;
				ret.g=this->g-(edk::float64)n;
				ret.b=this->b-(edk::float64)n;
				ret.a=this->a-(edk::float64)n;
				return ret;
			}

			//-=
            void operator-=(edk::color3ui8 color){
                //bera as variaveis
                this->r-=((edk::float64)color.r/255.f);
                this->g-=((edk::float64)color.g/255.f);
                this->b-=((edk::float64)color.b/255.f);
            }
            void operator-=(edk::color4ui8 color){
                //bera as variaveis
                this->r-=((edk::float64)color.r/255.f);
                this->g-=((edk::float64)color.g/255.f);
                this->b-=((edk::float64)color.b/255.f);
                this->a-=((edk::float64)color.a/255.f);
            }
			void operator-=(color4f64 color){
				//
				this->r-=color.r;
				this->g-=color.g;
				this->b-=color.b;
				this->a-=color.a;
			}
			void operator-=(vec3i8 color){
				//
				this->r-=color.x;
				this->g-=color.y;
				this->b-=color.z;
			}
			void operator-=(vec2i8 color){
				//
				this->r-=color.x;
				this->g-=color.y;
			}
			void operator-=(edk::float32 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(edk::float64 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(int8 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(int16 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(int32 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(int64 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(uint8 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(uint16 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(uint32 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}
			void operator-=(uint64 n){
				//
				this->r-=(edk::float64)n;
				this->g-=(edk::float64)n;
				this->b-=(edk::float64)n;
				this->a-=(edk::float64)n;
			}

			//*
            color4f64 operator*(edk::color3ui8 color){
                //bera as variaveis
                color4f64 ret;
                ret.r=this->r*((edk::float64)color.r/255.f);
                ret.g=this->g*((edk::float64)color.g/255.f);
                ret.b=this->b*((edk::float64)color.b/255.f);
                return ret;
            }
            color4f64 operator*(edk::color4ui8 color){
                //bera as variaveis
                color4f64 ret;
                ret.r=this->r*((edk::float64)color.r/255.f);
                ret.g=this->g*((edk::float64)color.g/255.f);
                ret.b=this->b*((edk::float64)color.b/255.f);
                ret.a=this->a*((edk::float64)color.a/255.f);
                return ret;
            }
			color4f64 operator*(color4f64 color){
				//
				color4f64 ret;
				ret.r=this->r*color.r;
				ret.g=this->g*color.g;
				ret.b=this->b*color.b;
				ret.a=this->a*color.a;
				return ret;
			}
			color4f64 operator*(vec3i8 color){
				//
				color4f64 ret;
				ret.r=this->r*color.x;
				ret.g=this->g*color.y;
				ret.b=this->b*color.z;
				return ret;
			}
			color4f64 operator*(vec2i8 color){
				//
				color4f64 ret;
				ret.r=this->r*color.x;
				ret.g=this->g*color.y;
				return ret;
			}
			color4f64 operator*(edk::float32 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(edk::float64 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(int8 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(int16 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(int32 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(int64 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(uint8 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(uint16 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(uint32 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}
			color4f64 operator*(uint64 n){
				//
				color4f64 ret;
				ret.r=this->r*(edk::float64)n;
				ret.g=this->g*(edk::float64)n;
				ret.b=this->b*(edk::float64)n;
				ret.a=this->a*(edk::float64)n;
				return ret;
			}

			//*=
            void operator*=(edk::color3ui8 color){
                //bera as variaveis
                this->r*=((edk::float64)color.r/255.f);
                this->g*=((edk::float64)color.g/255.f);
                this->b*=((edk::float64)color.b/255.f);
            }
            void operator*=(edk::color4ui8 color){
                //bera as variaveis
                this->r*=((edk::float64)color.r/255.f);
                this->g*=((edk::float64)color.g/255.f);
                this->b*=((edk::float64)color.b/255.f);
                this->a*=((edk::float64)color.a/255.f);
            }
			void operator*=(color4f64 color){
				//
				this->r*=color.r;
				this->g*=color.g;
				this->b*=color.b;
				this->a*=color.a;
			}
			void operator*=(vec3i8 color){
				//
				this->r*=color.x;
				this->g*=color.y;
				this->b*=color.z;
			}
			void operator*=(vec2i8 color){
				//
				this->r*=color.x;
				this->g*=color.y;
			}
			void operator*=(edk::float32 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(edk::float64 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(int8 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(int16 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(int32 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(int64 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(uint8 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(uint16 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(uint32 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}
			void operator*=(uint64 n){
				//
				this->r*=(edk::float64)n;
				this->g*=(edk::float64)n;
				this->b*=(edk::float64)n;
				this->a*=(edk::float64)n;
			}

			// /
            color4f64 operator/(edk::color3ui8 color){
                //bera as variaveis
                color4f64 ret;
                ret.r=this->r/((edk::float64)color.r/255.f);
                ret.g=this->g/((edk::float64)color.g/255.f);
                ret.b=this->b/((edk::float64)color.b/255.f);
                return ret;
            }
            color4f64 operator/(edk::color4ui8 color){
                //bera as variaveis
                color4f64 ret;
                ret.r=this->r/((edk::float64)color.r/255.f);
                ret.g=this->g/((edk::float64)color.g/255.f);
                ret.b=this->b/((edk::float64)color.b/255.f);
                ret.a=this->a/((edk::float64)color.a/255.f);
                return ret;
            }
			color4f64 operator/(color4f64 color){
				//
				color4f64 ret;
				ret.r=this->r/color.r;
				ret.g=this->g/color.g;
				ret.b=this->b/color.b;
				ret.a=this->a/color.a;
				return ret;
			}
			color4f64 operator/(vec3i8 color){
				//
				color4f64 ret;
				ret.r=this->r/color.x;
				ret.g=this->g/color.y;
				ret.b=this->b/color.z;
				return ret;
			}
			color4f64 operator/(vec2i8 color){
				//
				color4f64 ret;
				ret.r=this->r/color.x;
				ret.g=this->g/color.y;
				return ret;
			}
			color4f64 operator/(edk::float32 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(edk::float64 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(int8 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(int16 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(int32 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(int64 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(uint8 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(uint16 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(uint32 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}
			color4f64 operator/(uint64 n){
				//
				color4f64 ret;
				ret.r=this->r/(edk::float64)n;
				ret.g=this->g/(edk::float64)n;
				ret.b=this->b/(edk::float64)n;
				ret.a=this->a/(edk::float64)n;
				return ret;
			}

			// /=
            void operator/=(edk::color3ui8 color){
                //bera as variaveis
                this->r/=((edk::float64)color.r/255.f);
                this->g/=((edk::float64)color.g/255.f);
                this->b/=((edk::float64)color.b/255.f);
            }
            void operator/=(edk::color4ui8 color){
                //bera as variaveis
                this->r/=((edk::float64)color.r/255.f);
                this->g/=((edk::float64)color.g/255.f);
                this->b/=((edk::float64)color.b/255.f);
                this->a/=((edk::float64)color.a/255.f);
            }
			void operator/=(color4f64 color){
				//
				this->r/=color.r;
				this->g/=color.g;
				this->b/=color.b;
				this->a/=color.a;
			}
			void operator/=(vec3i8 color){
				//
				this->r/=color.x;
				this->g/=color.y;
				this->b/=color.z;
			}
			void operator/=(vec2i8 color){
				//
				this->r/=color.x;
				this->g/=color.y;
			}
			void operator/=(edk::float32 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(edk::float64 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(int8 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(int16 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(int32 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(int64 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(uint8 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(uint16 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(uint32 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}
			void operator/=(uint64 n){
				//
				this->r/=(edk::float64)n;
				this->g/=(edk::float64)n;
				this->b/=(edk::float64)n;
				this->a/=(edk::float64)n;
			}

			//++
			color4f64 operator++(){
			    //
			    ++this->r;
			    ++this->g;
			    ++this->b;
			    ++this->a;
			    return color4f64(this->r,this->g,this->b,this->a);
			}
            color4f64 operator++(int32){
			    //
			    this->r++;
			    this->g++;
			    this->b++;
			    this->a++;
			    return color4f64(this->r,this->g,this->b,this->a);
			}

			//--
			color4f64 operator--(){
			    //
			    --this->r;
			    --this->g;
			    --this->b;
			    --this->a;
			    return color4f64(this->r,this->g,this->b,this->a);
			}
            color4f64 operator--(int32){
			    //
			    this->r--;
			    this->g--;
			    this->b--;
			    this->a--;
			    return color4f64(this->r,this->g,this->b,this->a);
			}

			//
			color4f64 operator()(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(int8 r,int8 g,int8 b,int8 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(int16 r,int16 g,int16 b,int16 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(int32 r,int32 g,int32 b,int32 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(int64 r,int64 g,int64 b,int64 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(uint8 r,uint8 g,uint8 b,uint8 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(uint16 r,uint16 g,uint16 b,uint16 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(uint32 r,uint32 g,uint32 b,uint32 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
			color4f64 operator()(uint64 r,uint64 g,uint64 b,uint64 a){
			    //
			    this->r=r;
			    this->g=g;
			    this->b=b;
			    this->a=a;
			    return color4f64((edk::float64)this->r,(edk::float64)this->g,(edk::float64)this->b,(edk::float64)this->a);
			}
	};

}

#endif // TYPECOLOR_H
