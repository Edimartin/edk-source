#include "Math.h"

/*
Library Math - Math functions to Edk Engine
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
#warning "            Inside Math.cpp"
#endif

edk::Math::Math()
{
    //ctor
}

edk::Math::~Math()
{
    //dtor
}

//SquareRoot
edk::float32 edk::Math::squareRootFloat(edk::float32 n){return sqrt(n);}
edk::float32 edk::Math::squareRootInt8(edk::int8 n){return sqrt(n);}
edk::float32 edk::Math::squareRootInt16(edk::int16 n){return sqrt(n);}
edk::float32 edk::Math::squareRootInt32(edk::int32 n){return sqrt(n);}
edk::float32 edk::Math::squareRootInt64(edk::int64 n){return sqrt(n);}
edk::float32 edk::Math::squareRootUint8(edk::uint8 n){return sqrt(n);}
edk::float32 edk::Math::squareRootUint16(edk::uint16 n){return sqrt(n);}
edk::float32 edk::Math::squareRootUint32(edk::uint32 n){return sqrt(n);}
edk::float32 edk::Math::squareRootUint64(edk::uint64 n){return sqrt(n);}

//Normalise
edk::vec2f32  edk::Math::normalise2f(edk::float32 x,edk::float32 y){return edk::Math::normalise2f(edk::vec2f32(x,y));}
edk::vec2f32  edk::Math::normalise2f(edk::vec2f32 vec){
    //get the vectorDist
    edk::float32 dist = edk::Math::pythagoras2f(vec);
    //then normalize
    if(dist!=0.0f){
        //
        vec/=dist;
    }
    else{
        //else clean the vector
        vec=0.0f;
    }
    //return the vector
    return vec;
}
edk::vec3f32  edk::Math::normalise3f(edk::float32 x,edk::float32 y,edk::float32 z){return edk::Math::normalise3f(edk::vec3f32(x,y,z));}
edk::vec3f32  edk::Math::normalise3f(edk::vec3f32 vec){
    //get the vectorDist
    edk::float32 dist = edk::Math::pythagoras3f(vec);
    //then normalize
    if(dist!=0.0f){
        //
        vec/=dist;
    }
    else{
        //else clean the vector
        vec=0.0f;
    }
    //return the vector
    return vec;
}
edk::vec4f32  edk::Math::normalise4f(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){return edk::Math::normalise4f(edk::vec4f32(x,y,z,w));}
edk::vec4f32  edk::Math::normalise4f(edk::vec4f32 vec){
    //get the vectorDist
    edk::float32 dist = edk::Math::pythagoras4f(vec);
    //then normalize
    if(dist!=0.0f){
        //
        vec/=dist;
    }
    else{
        //else clean the vector
        vec=0.0f;
    }
    //return the vector
    return vec;
}

//Scalar
edk::float32 edk::Math::scalar2f(edk::vec2f32 vec1,edk::vec2f32 vec2){
    //
    return (vec1.x*vec2.x) + (vec1.y*vec2.y);
}
edk::float32 edk::Math::scalar3f(edk::vec3f32 vec1,edk::vec3f32 vec2){
    //
    return (vec1.x*vec2.x) + (vec1.y*vec2.y) + (vec1.z*vec2.z);
}
edk::float32 edk::Math::scalar4f(edk::vec4f32 vec1,edk::vec4f32 vec2){
    //
    return (vec1.x*vec2.x) + (vec1.y*vec2.y) + (vec1.z*vec2.z) + (vec1.w*vec2.w);
}

//The square function return the square of the number
edk::float32 edk::Math::squareFloat32(edk::float32 n){ return n*n; }
edk::float32 edk::Math::squareFloat64(edk::float64 n){ return n*n; }
edk::int8 edk::Math::squareInt8(edk::int8 n){ return n*n; }
edk::int16 edk::Math::squareInt16(edk::int16 n){ return n*n; }
edk::int32 edk::Math::squareInt32(edk::int32 n){ return n*n; }
edk::int64 edk::Math::squareInt64(edk::int64 n){ return n*n; }
edk::uint8 edk::Math::squareUint8(edk::uint8 n){ return n*n; }
edk::uint16 edk::Math::squareUint16(edk::uint16 n){ return n*n; }
edk::uint32 edk::Math::squareUint32(edk::uint32 n){ return n*n; }
edk::uint64 edk::Math::squareUint64(edk::uint64 n){ return n*n; }
//VEC2
edk::vec2f32 edk::Math::squarevec2f32(edk::float32 n1,edk::float32 n2){ return edk::Math::squarevec2f32(edk::vec2f32(n1,n2)); }
edk::vec2f32 edk::Math::squarevec2f32(edk::vec2f32 vec){ return vec*vec; }
edk::vec2i8 edk::Math::squareVec2i8(edk::int8 n1, edk::int8 n2){ return edk::Math::squareVec2i8(edk::vec2i8(n1,n2)); }
edk::vec2i8 edk::Math::squareVec2i8(edk::vec2i8 vec){ return vec*vec; }
edk::vec2i16 edk::Math::squareVec2i16(edk::int16 n1,edk::int16 n2){ return edk::Math::squareVec2i16(edk::vec2i16(n1,n2)); }
edk::vec2i16 edk::Math::squareVec2i16(edk::vec2i16 vec){ return vec*vec; }
edk::vec2i32 edk::Math::squareVec2i32(edk::int32 n1,edk::int32 n2){ return edk::Math::squareVec2i32(edk::vec2i32(n1,n2)); }
edk::vec2i32 edk::Math::squareVec2i32(edk::vec2i32 vec){ return vec*vec; }
edk::vec2i64 edk::Math::squareVec2i64(edk::int64 n1,edk::int64 n2){ return edk::Math::squareVec2i64(edk::vec2i64(n1,n2)); }
edk::vec2i64 edk::Math::squareVec2i64(edk::vec2i64 vec){ return vec*vec; }
edk::vec2ui8 edk::Math::squareVec2ui8(edk::uint8 n1,edk::uint8 n2){ return edk::Math::squareVec2ui8(edk::vec2ui8(n1,n2)); }
edk::vec2ui8 edk::Math::squareVec2ui8(edk::vec2ui8 vec){ return vec*vec; }
edk::vec2ui16 edk::Math::squareVec2ui1(edk::uint16 n1,edk::uint16 n2){ return edk::Math::squareVec2ui1(edk::vec2ui16(n1,n2)); }
edk::vec2ui16 edk::Math::squareVec2ui1(edk::vec2ui16 vec){ return vec*vec; }
edk::vec2ui32 edk::Math::squareVec2ui32(edk::uint32 n1,edk::uint32 n2){ return edk::Math::squareVec2ui32(edk::vec2ui32(n1,n2)); }
edk::vec2ui32 edk::Math::squareVec2ui32(edk::vec2ui32 vec){ return vec*vec; }
edk::vec2ui64 edk::Math::squareVec2ui64(edk::uint64 n1,edk::uint64 n2){ return edk::Math::squareVec2ui64(edk::vec2ui64(n1,n2)); }
edk::vec2ui64 edk::Math::squareVec2ui64(edk::vec2ui64 vec){ return vec*vec; }
//VEC3
edk::vec3f32 edk::Math::squarevec3f32(edk::float32 n1,edk::float32 n2,edk::float32 n3){ return edk::Math::squarevec3f32(edk::vec3f32(n1,n2,n3)); }
edk::vec3f32 edk::Math::squarevec3f32(edk::vec3f32 vec){ return vec*vec; }
edk::vec3i8 edk::Math::squareVec3i8(edk::int8 n1,edk::int8 n2,edk::int8 n3){ return edk::Math::squareVec3i8(edk::vec3i8(n1,n2,n3)); }
edk::vec3i8 edk::Math::squareVec3i8(edk::vec3i8 vec){ return vec*vec; }
edk::vec3i16 edk::Math::squareVec3i16(edk::int16 n1,edk::int16 n2,edk::int16 n3){ return edk::Math::squareVec3i16(edk::vec3i16(n1,n2,n3)); }
edk::vec3i16 edk::Math::squareVec3i16(edk::vec3i16 vec){ return vec*vec; }
edk::vec3i32 edk::Math::squareVec3i32(edk::int32 n1,edk::int32 n2,edk::int32 n3){ return edk::Math::squareVec3i32(edk::vec3i32(n1,n2,n3)); }
edk::vec3i32 edk::Math::squareVec3i32(edk::vec3i32 vec){ return vec*vec; }
edk::vec3i64 edk::Math::squareVec3i64(edk::int64 n1,edk::int64 n2,edk::int64 n3){ return edk::Math::squareVec3i64(edk::vec3i64(n1,n2,n3)); }
edk::vec3i64 edk::Math::squareVec3i64(edk::vec3i64 vec){ return vec*vec; }
edk::vec3ui8 edk::Math::squareVec3ui8(edk::uint8 n1,edk::uint8 n2,edk::uint8 n3){ return edk::Math::squareVec3ui8(edk::vec3ui8(n1,n2,n3)); }
edk::vec3ui8 edk::Math::squareVec3ui8(edk::vec3ui8 vec){ return vec*vec; }
edk::vec3ui16 edk::Math::squareVec3ui1(edk::uint16 n1,edk::uint16 n2,edk::uint16 n3){ return edk::Math::squareVec3ui1(edk::vec3ui16(n1,n2,n3)); }
edk::vec3ui16 edk::Math::squareVec3ui1(edk::vec3ui16 vec){ return vec*vec; }
edk::vec3ui32 edk::Math::squareVec3ui32(edk::uint32 n1,edk::uint32 n2,edk::uint32 n3){ return edk::Math::squareVec3ui32(edk::vec3ui32(n1,n2,n3)); }
edk::vec3ui32 edk::Math::squareVec3ui32(edk::vec3ui32 vec){ return vec*vec; }
edk::vec3ui64 edk::Math::squareVec3ui64(edk::uint64 n1,edk::uint64 n2,edk::uint64 n3){ return edk::Math::squareVec3ui64(edk::vec3ui64(n1,n2,n3)); }
edk::vec3ui64 edk::Math::squareVec3ui64(edk::vec3ui64 vec){ return vec*vec; }
//VEC4
edk::vec4f32 edk::Math::squarevec4f32(edk::float32 n1,edk::float32 n2,edk::float32 n3,edk::float32 n4){ return edk::Math::squarevec4f32(edk::vec4f32(n1,n2,n3,n4)); }
edk::vec4f32 edk::Math::squarevec4f32(edk::vec4f32 vec){ return vec*vec; }
edk::vec4i8 edk::Math::squareVec4i8(edk::int8 n1,edk::int8 n2,edk::int8 n3,edk::int8 n4){ return edk::Math::squareVec4i8(edk::vec4i8(n1,n2,n3,n4)); }
edk::vec4i8 edk::Math::squareVec4i8(edk::vec4i8 vec){ return vec*vec; }
edk::vec4i16 edk::Math::squareVec4i16(edk::int16 n1,edk::int16 n2,edk::int16 n3,edk::int16 n4){ return edk::Math::squareVec4i16(edk::vec4i16(n1,n2,n3,n4)); }
edk::vec4i16 edk::Math::squareVec4i16(edk::vec4i16 vec){ return vec*vec; }
edk::vec4i32 edk::Math::squareVec4i32(edk::int32 n1,edk::int32 n2,edk::int32 n3,edk::int32 n4){ return edk::Math::squareVec4i32(edk::vec4i32(n1,n2,n3,n4)); }
edk::vec4i32 edk::Math::squareVec4i32(edk::vec4i32 vec){ return vec*vec; }
edk::vec4i64 edk::Math::squareVec4i64(edk::int64 n1,edk::int64 n2,edk::int64 n3,edk::int64 n4){ return edk::Math::squareVec4i64(edk::vec4i64(n1,n2,n3,n4)); }
edk::vec4i64 edk::Math::squareVec4i64(edk::vec4i64 vec){ return vec*vec; }
edk::vec4ui8 edk::Math::squareVec4ui8(edk::uint8 n1,edk::uint8 n2,edk::uint8 n3,edk::uint8 n4){ return edk::Math::squareVec4ui8(edk::vec4ui8(n1,n2,n3,n4)); }
edk::vec4ui8 edk::Math::squareVec4ui8(edk::vec4ui8 vec){ return vec*vec; }
edk::vec4ui16 edk::Math::squareVec4ui1(edk::uint16 n1,edk::uint16 n2,edk::uint16 n3,edk::uint16 n4){ return edk::Math::squareVec4ui1(edk::vec4ui16(n1,n2,n3,n4)); }
edk::vec4ui16 edk::Math::squareVec4ui1(edk::vec4ui16 vec){ return vec*vec; }
edk::vec4ui32 edk::Math::squareVec4ui32(edk::uint32 n1,edk::uint32 n2,edk::uint32 n3,edk::uint32 n4){ return edk::Math::squareVec4ui32(edk::vec4ui32(n1,n2,n3,n4)); }
edk::vec4ui32 edk::Math::squareVec4ui32(edk::vec4ui32 vec){ return vec*vec; }
edk::vec4ui64 edk::Math::squareVec4ui64(edk::uint64 n1,edk::uint64 n2,edk::uint64 n3,edk::uint64 n4){ return edk::Math::squareVec4ui64(edk::vec4ui64(n1,n2,n3,n4)); }
edk::vec4ui64 edk::Math::squareVec4ui64(edk::vec4ui64 vec){ return vec*vec; }

//MODULE OF A NUMBER
edk::float32 edk::Math::moduleFloat(edk::float32 n){ if(n<0) return n*-1; else return n; }
edk::int8 edk::Math::moduleInt8(edk::int8 n){ if(n<0) return n*-1; else return n; }
edk::int16 edk::Math::moduleInt16(edk::int16 n){ if(n<0) return n*-1; else return n; }
edk::int32 edk::Math::moduleInt32(edk::int32 n){ if(n<0) return n*-1; else return n; }
edk::int64 edk::Math::moduleInt64(edk::int64 n){ if(n<0) return n*-1; else return n; }
//VEC2
edk::vec2f32 edk::Math::modulevec2f32(edk::float32 n1,edk::float32 n2){return edk::Math::modulevec2f32(edk::vec2f32(n1,n2));}
edk::vec2f32 edk::Math::modulevec2f32(edk::vec2f32 vec){vec.x=edk::Math::moduleFloat(vec.x);vec.y=edk::Math::moduleFloat(vec.y); return vec;}
edk::vec2i8 edk::Math::moduleVec2i8(edk::int8 n1,edk::int8 n2){return edk::Math::moduleVec2i8(edk::vec2i8(n1,n2));}
edk::vec2i8 edk::Math::moduleVec2i8(edk::vec2i8 vec){vec.x=edk::Math::moduleInt8(vec.x);vec.y=edk::Math::moduleInt8(vec.y); return vec;}
edk::vec2i16 edk::Math::moduleVec2i16(edk::int16 n1,edk::int16 n2){return edk::Math::moduleVec2i16(edk::vec2i16(n1,n2));}
edk::vec2i16 edk::Math::moduleVec2i16(edk::vec2i16 vec){vec.x=edk::Math::moduleInt16(vec.x);vec.y=edk::Math::moduleInt16(vec.y); return vec;}
edk::vec2i32 edk::Math::moduleVec2i32(edk::int32 n1,edk::int32 n2){return edk::Math::moduleVec2i32(edk::vec2i32(n1,n2));}
edk::vec2i32 edk::Math::moduleVec2i32(edk::vec2i32 vec){vec.x=edk::Math::moduleInt32(vec.x);vec.y=edk::Math::moduleInt32(vec.y); return vec;}
edk::vec2i64 edk::Math::moduleVec2i64(edk::int64 n1,edk::int64 n2){return edk::Math::moduleVec2i64(edk::vec2i64(n1,n2));}
edk::vec2i64 edk::Math::moduleVec2i64(edk::vec2i64 vec){vec.x=edk::Math::moduleInt64(vec.x);vec.y=edk::Math::moduleInt64(vec.y); return vec;}
//VEC3
edk::vec3f32 edk::Math::modulevec3f32(edk::float32 n1,edk::float32 n2,edk::float32 n3){return edk::Math::modulevec3f32(edk::vec3f32(n1,n2,n3));}
edk::vec3f32 edk::Math::modulevec3f32(edk::vec3f32 vec){vec.x=edk::Math::moduleFloat(vec.x);vec.y=edk::Math::moduleFloat(vec.y); return vec;}
edk::vec3i8 edk::Math::moduleVec3i8(edk::int8 n1,edk::int8 n2,edk::int8 n3){return edk::Math::moduleVec3i8(edk::vec3i8(n1,n2,n3));}
edk::vec3i8 edk::Math::moduleVec3i8(edk::vec3i8 vec){vec.x=edk::Math::moduleInt8(vec.x);vec.y=edk::Math::moduleInt8(vec.y); return vec;}
edk::vec3i16 edk::Math::moduleVec3i16(edk::int16 n1,edk::int16 n2,edk::int16 n3){return edk::Math::moduleVec3i16(edk::vec3i16(n1,n2,n3));}
edk::vec3i16 edk::Math::moduleVec3i16(edk::vec3i16 vec){vec.x=edk::Math::moduleInt16(vec.x);vec.y=edk::Math::moduleInt16(vec.y); return vec;}
edk::vec3i32 edk::Math::moduleVec3i32(edk::int32 n1,edk::int32 n2,edk::int32 n3){return edk::Math::moduleVec3i32(edk::vec3i32(n1,n2,n3));}
edk::vec3i32 edk::Math::moduleVec3i32(edk::vec3i32 vec){vec.x=edk::Math::moduleInt32(vec.x);vec.y=edk::Math::moduleInt32(vec.y); return vec;}
edk::vec3i64 edk::Math::moduleVec3i64(edk::int64 n1,edk::int64 n2,edk::int64 n3){return edk::Math::moduleVec3i64(edk::vec3i64(n1,n2,n3));}
edk::vec3i64 edk::Math::moduleVec3i64(edk::vec3i64 vec){vec.x=edk::Math::moduleInt64(vec.x);vec.y=edk::Math::moduleInt64(vec.y); return vec;}
//VEC4
edk::vec4f32 edk::Math::modulevec4f32(edk::float32 n1,edk::float32 n2,edk::float32 n3,edk::float32 n4){return edk::Math::modulevec4f32(edk::vec4f32(n1,n2,n3,n4));}
edk::vec4f32 edk::Math::modulevec4f32(edk::vec4f32 vec){vec.x=edk::Math::moduleFloat(vec.x);vec.y=edk::Math::moduleFloat(vec.y); return vec;}
edk::vec4i8 edk::Math::moduleVec4i8(edk::int8 n1,edk::int8 n2,edk::int8 n3,edk::int8 n4){return edk::Math::moduleVec4i8(edk::vec4i8(n1,n2,n3,n4));}
edk::vec4i8 edk::Math::moduleVec4i8(edk::vec4i8 vec){vec.x=edk::Math::moduleInt8(vec.x);vec.y=edk::Math::moduleInt8(vec.y); return vec;}
edk::vec4i16 edk::Math::moduleVec4i16(edk::int16 n1,edk::int16 n2,edk::int16 n3,edk::int16 n4){return edk::Math::moduleVec4i16(edk::vec4i16(n1,n2,n3,n4));}
edk::vec4i16 edk::Math::moduleVec4i16(edk::vec4i16 vec){vec.x=edk::Math::moduleInt16(vec.x);vec.y=edk::Math::moduleInt16(vec.y); return vec;}
edk::vec4i32 edk::Math::moduleVec4i32(edk::int32 n1,edk::int32 n2,edk::int32 n3,edk::int32 n4){return edk::Math::moduleVec4i32(edk::vec4i32(n1,n2,n3,n4));}
edk::vec4i32 edk::Math::moduleVec4i32(edk::vec4i32 vec){vec.x=edk::Math::moduleInt32(vec.x);vec.y=edk::Math::moduleInt32(vec.y); return vec;}
edk::vec4i64 edk::Math::moduleVec4i64(edk::int64 n1,edk::int64 n2,edk::int64 n3,edk::int64 n4){return edk::Math::moduleVec4i64(edk::vec4i64(n1,n2,n3,n4));}
edk::vec4i64 edk::Math::moduleVec4i64(edk::vec4i64 vec){vec.x=edk::Math::moduleInt64(vec.x);vec.y=edk::Math::moduleInt64(vec.y); return vec;}

//Function pythagoras return de distance from 0,0,0 axis to X Y Z W
//FLOAT
edk::float32 edk::Math::pythagoras2f(edk::float32 x,edk::float32 y){return edk::Math::pythagoras2f(edk::vec2f32(x,y));}
edk::float32 edk::Math::pythagoras2f(edk::vec2f32 vec){return (edk::float32)edk::Math::squareRootFloat(edk::Math::squareFloat32(vec.x)+edk::Math::squareFloat32(vec.y));}
edk::float32 edk::Math::pythagoras3f(edk::float32 x,edk::float32 y,edk::float32 z){return edk::Math::pythagoras3f(edk::vec3f32(x,y,z));}
edk::float32 edk::Math::pythagoras3f(edk::vec3f32 vec){return (edk::float32)edk::Math::squareRootFloat(edk::Math::squareFloat32(vec.x)+edk::Math::squareFloat32(vec.y)+
                                                                                       edk::Math::squareFloat32(vec.z));}
edk::float32 edk::Math::pythagoras4f(edk::float32 x,edk::float32 y,edk::float32 z, edk::float32 w){return edk::Math::pythagoras4f(edk::vec4f32(x,y,z,w));}
edk::float32 edk::Math::pythagoras4f(edk::vec4f32 vec){return (edk::float32)edk::Math::squareRootFloat(edk::Math::squareFloat32(vec.x)+edk::Math::squareFloat32(vec.y)+
                                                                                       edk::Math::squareFloat32(vec.z)+edk::Math::squareFloat32(vec.w));}
//INT8
edk::float32 edk::Math::pythagoras2i8(edk::int8 x,edk::int8 y){return edk::Math::pythagoras2i8(edk::vec2i8(x,y));}
edk::float32 edk::Math::pythagoras2i8(edk::vec2i8 vec){return (edk::float32)edk::Math::squareRootInt8(edk::Math::squareInt8(vec.x)+edk::Math::squareInt8(vec.y));}
edk::float32 edk::Math::pythagoras3i8(edk::int8 x,edk::int8 y,edk::int8 z){return edk::Math::pythagoras3i8(edk::vec3i8(x,y,z));}
edk::float32 edk::Math::pythagoras3i8(edk::vec3i8 vec){return (edk::float32)edk::Math::squareRootInt8(edk::Math::squareInt8(vec.x)+edk::Math::squareInt8(vec.y)+
                                                                                       edk::Math::squareInt8(vec.z));}
edk::float32 edk::Math::pythagoras4i8(edk::int8 x,edk::int8 y,edk::int8 z, edk::int8 w){return edk::Math::pythagoras4i8(edk::vec4i8(x,y,z,w));}
edk::float32 edk::Math::pythagoras4i8(edk::vec4i8 vec){return (edk::float32)edk::Math::squareRootInt8(edk::Math::squareInt8(vec.x)+edk::Math::squareInt8(vec.y)+
                                                                                       edk::Math::squareInt8(vec.z)+edk::Math::squareInt8(vec.w));}
//INT16
edk::float32 edk::Math::pythagoras2i16(edk::int16 x,edk::int16 y){return edk::Math::pythagoras2i16(edk::vec2i16(x,y));}
edk::float32 edk::Math::pythagoras2i16(edk::vec2i16 vec){return (edk::float32)edk::Math::squareRootInt16(edk::Math::squareInt16(vec.x)+edk::Math::squareInt16(vec.y));}
edk::float32 edk::Math::pythagoras3i16(edk::int16 x,edk::int16 y,edk::int16 z){return edk::Math::pythagoras3i16(edk::vec3i16(x,y,z));}
edk::float32 edk::Math::pythagoras3i16(edk::vec3i16 vec){return (edk::float32)edk::Math::squareRootInt16(edk::Math::squareInt16(vec.x)+edk::Math::squareInt16(vec.y)+
                                                                                       edk::Math::squareInt16(vec.z));}
edk::float32 edk::Math::pythagoras4i16(edk::int16 x,edk::int16 y,edk::int16 z, edk::int16 w){return edk::Math::pythagoras4i16(edk::vec4i16(x,y,z,w));}
edk::float32 edk::Math::pythagoras4i16(edk::vec4i16 vec){return (edk::float32)edk::Math::squareRootInt16(edk::Math::squareInt16(vec.x)+edk::Math::squareInt16(vec.y)+
                                                                                       edk::Math::squareInt16(vec.z)+edk::Math::squareInt16(vec.w));}
//INT32
edk::float32 edk::Math::pythagoras2i32(edk::int32 x,edk::int32 y){return edk::Math::pythagoras2i32(edk::vec2i32(x,y));}
edk::float32 edk::Math::pythagoras2i32(edk::vec2i32 vec){return (edk::float32)edk::Math::squareRootInt32(edk::Math::squareInt32(vec.x)+edk::Math::squareInt32(vec.y));}
edk::float32 edk::Math::pythagoras3i32(edk::int32 x,edk::int32 y,edk::int32 z){return edk::Math::pythagoras3i32(edk::vec3i32(x,y,z));}
edk::float32 edk::Math::pythagoras3i32(edk::vec3i32 vec){return (edk::float32)edk::Math::squareRootInt32(edk::Math::squareInt32(vec.x)+edk::Math::squareInt32(vec.y)+
                                                                                       edk::Math::squareInt32(vec.z));}
edk::float32 edk::Math::pythagoras4i32(edk::int32 x,edk::int32 y,edk::int32 z, edk::int32 w){return edk::Math::pythagoras4i32(edk::vec4i32(x,y,z,w));}
edk::float32 edk::Math::pythagoras4i32(edk::vec4i32 vec){return (edk::float32)edk::Math::squareRootInt32(edk::Math::squareInt32(vec.x)+edk::Math::squareInt32(vec.y)+
                                                                                       edk::Math::squareInt32(vec.z)+edk::Math::squareInt32(vec.w));}
//INT64
edk::float32 edk::Math::pythagoras2i64(edk::int64 x,edk::int64 y){return edk::Math::pythagoras2i64(edk::vec2i64(x,y));}
edk::float32 edk::Math::pythagoras2i64(edk::vec2i64 vec){return (edk::float32)edk::Math::squareRootInt64(edk::Math::squareInt64(vec.x)+edk::Math::squareInt64(vec.y));}
edk::float32 edk::Math::pythagoras3i64(edk::int64 x,edk::int64 y,edk::int64 z){return edk::Math::pythagoras3i64(edk::vec3i64(x,y,z));}
edk::float32 edk::Math::pythagoras3i64(edk::vec3i64 vec){return (edk::float32)edk::Math::squareRootInt64(edk::Math::squareInt64(vec.x)+edk::Math::squareInt64(vec.y)+
                                                                                       edk::Math::squareInt64(vec.z));}
edk::float32 edk::Math::pythagoras4i64(edk::int64 x,edk::int64 y,edk::int64 z, edk::int64 w){return edk::Math::pythagoras4i64(edk::vec4i64(x,y,z,w));}
edk::float32 edk::Math::pythagoras4i64(edk::vec4i64 vec){return (edk::float32)edk::Math::squareRootInt64(edk::Math::squareInt64(vec.x)+edk::Math::squareInt64(vec.y)+
                                                                                       edk::Math::squareInt64(vec.z)+edk::Math::squareInt64(vec.w));}
//UINT8
edk::float32 edk::Math::pythagoras2ui8(edk::uint8 x,edk::uint8 y){return edk::Math::pythagoras2ui8(edk::vec2ui8(x,y));}
edk::float32 edk::Math::pythagoras2ui8(edk::vec2ui8 vec){return (edk::float32)edk::Math::squareRootInt8(edk::Math::squareUint8(vec.x)+edk::Math::squareUint8(vec.y));}
edk::float32 edk::Math::pythagoras3ui8(edk::uint8 x,edk::uint8 y,edk::uint8 z){return edk::Math::pythagoras3ui8(edk::vec3ui8(x,y,z));}
edk::float32 edk::Math::pythagoras3ui8(edk::vec3ui8 vec){return (edk::float32)edk::Math::squareRootInt8(edk::Math::squareUint8(vec.x)+edk::Math::squareUint8(vec.y)+
                                                                                       edk::Math::squareUint8(vec.z));}
edk::float32 edk::Math::pythagoras4ui8(edk::uint8 x,edk::uint8 y,edk::uint8 z, edk::uint8 w){return edk::Math::pythagoras4ui8(edk::vec4ui8(x,y,z,w));}
edk::float32 edk::Math::pythagoras4ui8(edk::vec4ui8 vec){return (edk::float32)edk::Math::squareRootInt8(edk::Math::squareUint8(vec.x)+edk::Math::squareUint8(vec.y)+
                                                                                       edk::Math::squareUint8(vec.z)+edk::Math::squareUint8(vec.w));}
//UINT16
edk::float32 edk::Math::pythagoras2ui16(edk::uint16 x,edk::uint16 y){return edk::Math::pythagoras2ui16(edk::vec2ui16(x,y));}
edk::float32 edk::Math::pythagoras2ui16(edk::vec2ui16 vec){return (edk::float32)edk::Math::squareRootInt16(edk::Math::squareUint16(vec.x)+edk::Math::squareUint16(vec.y));}
edk::float32 edk::Math::pythagoras3ui16(edk::uint16 x,edk::uint16 y,edk::uint16 z){return edk::Math::pythagoras3ui16(edk::vec3ui16(x,y,z));}
edk::float32 edk::Math::pythagoras3ui16(edk::vec3ui16 vec){return (edk::float32)edk::Math::squareRootInt16(edk::Math::squareUint16(vec.x)+edk::Math::squareUint16(vec.y)+
                                                                                       edk::Math::squareUint16(vec.z));}
edk::float32 edk::Math::pythagoras4ui16(edk::uint16 x,edk::uint16 y,edk::uint16 z, edk::uint16 w){return edk::Math::pythagoras4ui16(edk::vec4ui16(x,y,z,w));}
edk::float32 edk::Math::pythagoras4ui16(edk::vec4ui16 vec){return (edk::float32)edk::Math::squareRootInt16(edk::Math::squareUint16(vec.x)+edk::Math::squareUint16(vec.y)+
                                                                                       edk::Math::squareUint16(vec.z)+edk::Math::squareUint16(vec.w));}
//UINT32
edk::float32 edk::Math::pythagoras2ui32(edk::uint32 x,edk::uint32 y){return edk::Math::pythagoras2ui32(edk::vec2ui32(x,y));}
edk::float32 edk::Math::pythagoras2ui32(edk::vec2ui32 vec){return (edk::float32)edk::Math::squareRootInt32(edk::Math::squareUint32(vec.x)+edk::Math::squareUint32(vec.y));}
edk::float32 edk::Math::pythagoras3ui32(edk::uint32 x,edk::uint32 y,edk::uint32 z){return edk::Math::pythagoras3ui32(edk::vec3ui32(x,y,z));}
edk::float32 edk::Math::pythagoras3ui32(edk::vec3ui32 vec){return (edk::float32)edk::Math::squareRootInt32(edk::Math::squareUint32(vec.x)+edk::Math::squareUint32(vec.y)+
                                                                                       edk::Math::squareUint32(vec.z));}
edk::float32 edk::Math::pythagoras4ui32(edk::uint32 x,edk::uint32 y,edk::uint32 z, edk::uint32 w){return edk::Math::pythagoras4ui32(edk::vec4ui32(x,y,z,w));}
edk::float32 edk::Math::pythagoras4ui32(edk::vec4ui32 vec){return (edk::float32)edk::Math::squareRootInt32(edk::Math::squareUint32(vec.x)+edk::Math::squareUint32(vec.y)+
                                                                                       edk::Math::squareUint32(vec.z)+edk::Math::squareUint32(vec.w));}
//UINT64
edk::float32 edk::Math::pythagoras2ui64(edk::uint64 x,edk::uint64 y){return edk::Math::pythagoras2ui64(edk::vec2ui64(x,y));}
edk::float32 edk::Math::pythagoras2ui64(edk::vec2ui64 vec){return (edk::float32)edk::Math::squareRootInt64(edk::Math::squareUint64(vec.x)+edk::Math::squareUint64(vec.y));}
edk::float32 edk::Math::pythagoras3ui64(edk::uint64 x,edk::uint64 y,edk::uint64 z){return edk::Math::pythagoras3ui64(edk::vec3ui64(x,y,z));}
edk::float32 edk::Math::pythagoras3ui64(edk::vec3ui64 vec){return (edk::float32)edk::Math::squareRootInt64(edk::Math::squareUint64(vec.x)+edk::Math::squareUint64(vec.y)+
                                                                                       edk::Math::squareUint64(vec.z));}
edk::float32 edk::Math::pythagoras4ui64(edk::uint64 x,edk::uint64 y,edk::uint64 z, edk::uint64 w){return edk::Math::pythagoras4ui64(edk::vec4ui64(x,y,z,w));}
edk::float32 edk::Math::pythagoras4ui64(edk::vec4ui64 vec){return (edk::float32)edk::Math::squareRootInt64(edk::Math::squareUint64(vec.x)+edk::Math::squareUint64(vec.y)+
                                                                                       edk::Math::squareUint64(vec.z)+edk::Math::squareUint64(vec.w));}

//Return sin and cosin of angle.
edk::float32 edk::Math::getSinFloat(edk::float32 angle){if (angle == 180)return 0;else	return sin(angle*PI/180.f);}
edk::float32 edk::Math::getCosinFloat(edk::float32 angle){if (angle == 90 || angle == 270)return 0;else return cos(angle*PI/180.f);}
edk::float32 edk::Math::getSinInt8(edk::int8 angle){/*if (angle == 180)return 0;else	*/return sin((angle*PI)/180.f);}
edk::float32 edk::Math::getCosinInt8(edk::int8 angle){if (angle == 90/* || angle == 270*/)return 0;else return cos(angle*PI/180.f);}
edk::float32 edk::Math::getSinInt16(edk::int16 angle){if (angle == 180)return 0;else	return sin(angle*PI/180.f);}
edk::float32 edk::Math::getCosinInt16(edk::int16 angle){if (angle == 90 || angle == 270)return 0;else return cos(angle*PI/180.f);}
edk::float32 edk::Math::getSinInt32(edk::int32 angle){if (angle == 180)return 0;else	return sin((angle*PI)/180.f);}
edk::float32 edk::Math::getCosinInt32(edk::int32 angle){if (angle == 90 || angle == 270)return 0;else return cos(angle*PI/180.f);}
edk::float32 edk::Math::getSinInt64(edk::int64 angle){if (angle == 180)return 0;else	return sin(angle*PI/180.f);}
edk::float32 edk::Math::getCosinInt64(edk::int64 angle){if (angle == 90 || angle == 270)return 0;else return cos(angle*PI/180.f);}
edk::float32 edk::Math::getSinUint8(edk::uint8 angle){if (angle == 180)return 0;else	return sin(angle*PI/180.f);}
edk::float32 edk::Math::getCosinUint8(edk::uint8 angle){if (angle == 90/* || angle == 270*/)return 0;else return cos(angle*PI/180.f);}
edk::float32 edk::Math::getSinUint16(edk::uint16 angle){if (angle == 180)return 0;else	return sin(angle*PI/180.f);}
edk::float32 edk::Math::getCosinUint16(edk::uint16 angle){if (angle == 90 || angle == 270)return 0;else return cos(angle*PI/180.f);}
edk::float32 edk::Math::getSinUint32(edk::uint32 angle){if (angle == 180)return 0;else	return sin(angle*PI/180.f);}
edk::float32 edk::Math::getCosinUint32(edk::uint32 angle){if (angle == 90 || angle == 270)return 0;else return cos(angle*PI/180.f);}
edk::float32 edk::Math::getSinUint64(edk::uint64 angle){if (angle == 180)return 0;else	return sin(angle*PI/180.f);}
edk::float32 edk::Math::getCosinUint64(edk::uint64 angle){if (angle == 90 || angle == 270)return 0;else return cos(angle*PI/180.f);}

//Return asin and acosin of angle.
//edk::float32 edk::Math::arcSinFloat(edk::float32 radius,edk::float32 y){if(radius==0)radius=0.000001f;return edk::Math::arcSinFloat((edk::float32)y/radius);}
//edk::float32 edk::Math::arcCosinFloat(edk::float32 radius,edk::float32 x){if(radius==0)radius=0.000001f;return edk::Math::arcCosinFloat((edk::float32)x/radius);}
edk::float32 edk::Math::arcSinFloat(edk::float32 radius,edk::float32 y){if(radius==0)radius=0.000001f;return asin((edk::float32)y/radius)* 180.f / PI;}
edk::float32 edk::Math::arcSinFloat(edk::float32 y){return asin(y)* 180.f / PI;}
edk::float32 edk::Math::arcCosinFloat(edk::float32 radius,edk::float32 x){if(radius==0)radius=0.000001f;return acos((edk::float32)x/radius)* 180.f / PI;}
edk::float32 edk::Math::arcCosinFloat(edk::float32 x){return acos((edk::float32)x)* 180.f / PI;}

//return the 2D angle
edk::float32 edk::Math::getAngle2f(edk::float32 x,edk::float32 y){
    //
    return edk::Math::getAngle2f(edk::vec2f32(x,y));
}
edk::float32 edk::Math::getAngle2f(edk::vec2f32 vec){
    //
    vec=edk::Math::normalise2f(vec);
   //calcula o quadrante
   if(vec.x>=0.0f){
      // + X
      if(vec.y>=0.0f){
         // + Y
         //1º
         return asin (vec.y) * 180.0f / PI;
      }
      else if(vec.y<=0.0f){
         // - Y
         //4º
         return 360.0f+((asin (vec.y) * 180.0f / PI));
      }
   }
   else if(vec.x<=0.0f){
      // - X
      if(vec.y>0.0f){
         // + Y
         //2º
         return 180.0f+((asin (vec.y) * 180.0f / PI)*-1.0f);
      }
      else if(vec.y<=0.0f){
         // - Y
         //3º
         return 180.0f+((asin (vec.y) * 180.0f / PI)*-1.0f);
      }
   }
   return 0.0f;
}
//Return the 2D Angle between 2 vectors
edk::float32 edk::Math::getAngleDist2f(edk::vec2f32 vec1,edk::vec2f32 vec2){
    //
    if(vec1==vec2)
        return 0.f;
    return edk::Math::arcCosinFloat(( edk::Math::pythagoras2f(vec1) * edk::Math::pythagoras2f(vec2)),edk::Math::scalar2f(vec1,vec2));
}
edk::float32 edk::Math::getAngleDist3f(edk::vec3f32 vec1,edk::vec3f32 vec2){
    //
    if(vec1==vec2)
        return 0.f;
    return edk::Math::arcCosinFloat(( edk::Math::pythagoras3f(vec1) * edk::Math::pythagoras3f(vec2)),edk::Math::scalar3f(vec1,vec2));
}
edk::float32 edk::Math::getAngleDist4f(edk::vec4f32 vec1,edk::vec4f32 vec2){
    //
    if(vec1==vec2)
        return 0.f;
    return edk::Math::arcCosinFloat(( edk::Math::pythagoras4f(vec1) * edk::Math::pythagoras4f(vec2)),edk::Math::scalar4f(vec1,vec2));
}

//RightHand to find if the point is on the right or left
edk::float32 edk::Math::getAngleDistance(edk::vec2f32 vec1,edk::vec2f32 vec2){
    //fload the angles
    edk::float32 ret = edk::Math::getAngle2f(vec2) - edk::Math::getAngle2f(vec1);

    //test if the angle is > 180
    if(ret>180.f){
        //then remove 360 from the angle
        ret = (360.0-ret)*-1.f;
    }
    if(ret<-180){
        //
        ret = (360.0+ret);
    }
    //else return zero
    return ret;
}

//Rotate de vector
edk::float32 edk::Math::rotateXFloat(edk::float32 radius, edk::float32 angle){
    //
    return edk::Math::getCosinFloat(angle)*radius;
}
edk::float32 edk::Math::rotateYFloat(edk::float32 radius, edk::float32 angle){
    //
    return edk::Math::getSinFloat(angle)*radius;
}
edk::vec2f32 edk::Math::rotate2f(edk::vec2f32 vec,edk::float32 angle){
    //get the radius of the vector
    edk::float32 radius = edk::Math::pythagoras2f(vec);
    return edk::vec2f32( edk::Math::rotateXFloat(radius,angle),edk::Math::rotateYFloat(radius,angle));
}
edk::vec2f32 edk::Math::rotatePlus2f(edk::vec2f32 vec,edk::float32 angle){
    //find the angle
    angle += edk::Math::getAngle2f(vec);
    //filter the angle
    if(angle>360.0)angle-=360.f;
    if(angle<0)angle+=360.f;
    //
    return edk::Math::rotate2f(vec,angle);
}

//Normal of the vector
edk::vec3f32 edk::Math::normal3f(edk::vec3f32 vec1,edk::vec3f32 vec2,edk::vec3f32 vec3){


/*

 Point3D v1, v2;
    double len;

    // Encountra vetor v1
    v1.x = p2.x - p1.x;
    v1.y = p2.y - p1.y;
    v1.z = p2.z - p1.z;

    // Encountra vetor v2
    v2.x = p3.x - p1.x;
    v2.y = p3.y - p1.y;
    v2.z = p3.z - p1.z;

    // Calculo do produto vetorial de v1 e v2
    n->x = (v1.y * v2.z) - (v1.z * v2.y);
    n->y = (v1.z * v2.x) - (v1.x * v2.z);
    n->z = (v1.x * v2.y) - (v1.y * v2.x);

    // normalizecao de n
    len = sqrt(n->x*n->x + n->y*n->y + n->z*n->z)
    n->x /= len;
    n->y /= len;
    n->z /= len;

*/
    //
    //Aqui ele calculo o vetor normal do poligono
   edk::vec3f32 vT1,vT2;
   edk::vec3f32 v1,v2;
   double len;

   //Primeiro ele encountra o centro do triangle
   edk::vec3f32 bigger;
   edk::vec3f32 smaller;
   bigger=vec1;

   smaller=vec1;

   if(smaller.x>vec2.x)
      smaller.x=vec2.x;
   if(smaller.y>vec2.y)
      smaller.y=vec2.y;
   if(smaller.z>vec2.z)
      smaller.z=vec2.z;

   if(smaller.x>vec3.x)
      smaller.x=vec3.x;
   if(smaller.y>vec3.y)
      smaller.y=vec3.y;
   if(smaller.z>vec3.z)
      smaller.z=vec3.z;

   if(bigger.x<vec2.x)
      bigger.x=vec2.x;
   if(bigger.y<vec2.y)
      bigger.y=vec2.y;
   if(bigger.z<vec2.z)
      bigger.z=vec2.z;

   if(bigger.x<vec3.x)
      bigger.x=vec3.x;
   if(bigger.y<vec3.y)
      bigger.y=vec3.y;
   if(bigger.z<vec3.z)
      bigger.z=vec3.z;

   v2.x=smaller.x+0.5f*(bigger.x-smaller.x);
   v2.y=smaller.y+0.5f*(bigger.y-smaller.y);
   v2.z=smaller.z+0.5f*(bigger.z-smaller.z);


   //Depois ele faz o calculo da Normal

   // Encountra vetor v1
   vT1.x = vec2.x - vec1.x;
   vT1.y = vec2.y - vec1.y;
   vT1.z = vec2.z - vec1.z;

   // Encountra vetor v2
   vT2.x = vec3.x - vec1.x;
   vT2.y = vec3.y - vec1.y;
   vT2.z = vec3.z - vec1.z;

   // Calculo do produto vetorial de v1 e v2
   v1.x = (vT1.y * vT2.z) - (vT1.z * vT2.y);
   v1.y = (vT1.z * vT2.x) - (vT1.x * vT2.z);
   v1.z = (vT1.x * vT2.y) - (vT1.y * vT2.x);

   // normalizecao de n
   len = sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z);
   v1.x /= (edk::float32)len;
   v1.y /= (edk::float32)len;
   v1.z /= (edk::float32)len;

   //E no final ele translada o vetor normal para o centro do triangle
   v1.x=v1.x+v2.x;
   v1.y=v1.y+v2.y;
   v1.z=v1.z+v2.z;

   return v1;
}

 //QUATERION
 edk::vec3f32  edk::Math::quaternionToAngle(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
     //
     return edk::Math::quaternionToAngle(edk::vec4f32(x,y,z,w));
 }
 edk::vec3f32  edk::Math::quaternionToAngle(edk::vec4f32 vec){
     ////Conver quaternions to angle
   edk::float32 sqw = vec.w*vec.w;
   edk::float32 sqx = vec.x*vec.x;
   edk::float32 sqy = vec.y*vec.y;
   edk::float32 sqz = vec.z*vec.z;

   edk::vec3f32 v1;

   v1.z = atan2f(2.f * (vec.x*vec.y + vec.z*vec.w), sqx - sqy - sqz + sqw);

   edk::float32 tempY=(-2.f * (vec.x*vec.z - vec.y*vec.w));

   if( tempY > 1.0f || tempY < -1.0f  ){
      //
      v1.x=v1.y=v1.z=0.0;
      //printf("\nFalse");
      return v1;
   }
   v1.y = asinf(-2.f * (vec.x*vec.z - vec.y*vec.w));
   v1.x = atan2f(2.f * (vec.y*vec.z + vec.x*vec.w), -sqx - sqy + sqz + sqw);

   //convert to angle
   v1.x=v1.x*(180.0f/PI);
   v1.y=v1.y*(180.0f/PI);
   v1.z=v1.z*(180.0f/PI);

   return v1;
 }
edk::vec4f32 edk::Math::angleToQuaternion(edk::float32 x,edk::float32 y,edk::float32 z){
    //
    return edk::Math::angleToQuaternion(edk::vec3f32(x,y,z));
}
edk::vec4f32 edk::Math::angleToQuaternion(edk::vec3f32 vec){
    //convert to Rad
    vec.x=vec.x/(180.0f/PI);
    vec.y=vec.y/(180.0f/PI);
    vec.z=vec.z/(180.0f/PI);

    edk::float32 cos_z_2 = cosf(0.5f*vec.z);
    edk::float32 cos_y_2 = cosf(0.5f*vec.y);
    edk::float32 cos_x_2 = cosf(0.5f*vec.x);

    edk::float32 sin_z_2 = sinf(0.5f*vec.z);
    edk::float32 sin_y_2 = sinf(0.5f*vec.y);
    edk::float32 sin_x_2 = sinf(0.5f*vec.x);

    edk::vec4f32 quat1;

    // and now compute quaternion
    quat1.w = cos_z_2*cos_y_2*cos_x_2 + sin_z_2*sin_y_2*sin_x_2;
    quat1.x = cos_z_2*cos_y_2*sin_x_2 - sin_z_2*sin_y_2*cos_x_2;
    quat1.y = cos_z_2*sin_y_2*cos_x_2 + sin_z_2*cos_y_2*sin_x_2;
    quat1.z = sin_z_2*cos_y_2*cos_x_2 - cos_z_2*sin_y_2*sin_x_2;
    return quat1;
}

//RADIAN
edk::float32 edk::Math::angleToRadFloat(edk::float32 angle){
    //
    return (angle * PI) / 180.0f;
}
edk::float32 edk::Math::radToAngleFloat(edk::float32 rad){
    //
    return (rad * 180.0f) / PI;
}
