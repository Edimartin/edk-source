#ifndef EDK_MATH_H
#define EDK_MATH_H

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
#warning "Inside Math"
#endif

#include<math.h>
//definicao do numero PI
#define PI 3.1415926535897932384626433832795f

//Include the types
#pragma once
#include "TypeVars.h"
#include "TypeVec2.h"
#include "TypeVec3.h"
#include "TypeVec4.h"

#ifdef printMessages
#warning "    Compiling Math"
#endif

namespace edk{
class Math{
    public:
        Math();
        virtual ~Math();

        //SquareRoot
        static edk::float32 squareRootFloat(edk::float32 n);
        static edk::float32 squareRootInt8(edk::int8 n);
        static edk::float32 squareRootInt16(edk::int16 n);
        static edk::float32 squareRootInt32(edk::int32 n);
        static edk::float32 squareRootInt64(edk::int64 n);
        static edk::float32 squareRootUint8(edk::uint8 n);
        static edk::float32 squareRootUint16(edk::uint16 n);
        static edk::float32 squareRootUint32(edk::uint32 n);
        static edk::float32 squareRootUint64(edk::uint64 n);

        //Normalise
        static edk::vec2f32 normalise2f(edk::float32 x,edk::float32 y);
        static edk::vec2f32 normalise2f(edk::vec2f32 vec);
        static edk::vec3f32 normalise3f(edk::float32 x,edk::float32 y,edk::float32 z);
        static edk::vec3f32 normalise3f(edk::vec3f32 vec);
        static edk::vec4f32 normalise4f(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
        static edk::vec4f32 normalise4f(edk::vec4f32 vec);

        //Scalar
        static edk::float32 scalar2f(edk::vec2f32 vec1,edk::vec2f32 vec2);
        static edk::float32 scalar3f(edk::vec3f32 vec1,edk::vec3f32 vec2);
        static edk::float32 scalar4f(edk::vec4f32 vec1,edk::vec4f32 vec2);

        //The square function return the square of the number
        static edk::float32 squareFloat32(edk::float32 n);
        static edk::float32 squareFloat64(edk::float64 n);
        static edk::int8 squareInt8(edk::int8 n);
        static edk::int16 squareInt16(edk::int16 n);
        static edk::int32 squareInt32(edk::int32 n);
        static edk::int64 squareInt64(edk::int64 n);
        static edk::uint8 squareUint8(edk::uint8 n);
        static edk::uint16 squareUint16(edk::uint16 n);
        static edk::uint32 squareUint32(edk::uint32 n);
        static edk::uint64 squareUint64(edk::uint64 n);
        //VEC2
        static edk::vec2f32 squareVec2f32(edk::float32 n1,edk::float32 n2);
        static edk::vec2f32 squareVec2f32(edk::vec2f32 vec);
        static edk::vec2i8 squareVec2i8(edk::int8 n1, edk::int8 n2);
        static edk::vec2i8 squareVec2i8(edk::vec2i8 vec);
        static edk::vec2i16 squareVec2i16(edk::int16 n1,edk::int16 n2);
        static edk::vec2i16 squareVec2i16(edk::vec2i16 vec);
        static edk::vec2i32 squareVec2i32(edk::int32 n1,edk::int32 n2);
        static edk::vec2i32 squareVec2i32(edk::vec2i32 vec);
        static edk::vec2i64 squareVec2i64(edk::int64 n1,edk::int64 n2);
        static edk::vec2i64 squareVec2i64(edk::vec2i64 vec);
        static edk::vec2ui8 squareVec2ui8(edk::uint8 n1,edk::uint8 n2);
        static edk::vec2ui8 squareVec2ui8(edk::vec2ui8 vec);
        static edk::vec2ui16 squareVec2ui1(edk::uint16 n1,edk::uint16 n2);
        static edk::vec2ui16 squareVec2ui1(edk::vec2ui16 vec);
        static edk::vec2ui32 squareVec2ui32(edk::uint32 n1,edk::uint32 n2);
        static edk::vec2ui32 squareVec2ui32(edk::vec2ui32 vec);
        static edk::vec2ui64 squareVec2ui64(edk::uint64 n1,edk::uint64 n2);
        static edk::vec2ui64 squareVec2ui64(edk::vec2ui64 vec);
        //VEC3
        static edk::vec3f32 squareVec3f32(edk::float32 n1,edk::float32 n2,edk::float32 n3);
        static edk::vec3f32 squareVec3f32(edk::vec3f32 vec);
        static edk::vec3i8 squareVec3i8(edk::int8 n1, edk::int8 n2, edk::int8 n3);
        static edk::vec3i8 squareVec3i8(edk::vec3i8 vec);
        static edk::vec3i16 squareVec3i16(edk::int16 n1,edk::int16 n2,edk::int16 n3);
        static edk::vec3i16 squareVec3i16(edk::vec3i16 vec);
        static edk::vec3i32 squareVec3i32(edk::int32 n1,edk::int32 n2,edk::int32 n3);
        static edk::vec3i32 squareVec3i32(edk::vec3i32 vec);
        static edk::vec3i64 squareVec3i64(edk::int64 n1,edk::int64 n2,edk::int64 n3);
        static edk::vec3i64 squareVec3i64(edk::vec3i64 vec);
        static edk::vec3ui8 squareVec3ui8(edk::uint8 n1,edk::uint8 n2,edk::uint8 n3);
        static edk::vec3ui8 squareVec3ui8(edk::vec3ui8 vec);
        static edk::vec3ui16 squareVec3ui1(edk::uint16 n1,edk::uint16 n2,edk::uint16 n3);
        static edk::vec3ui16 squareVec3ui1(edk::vec3ui16 vec);
        static edk::vec3ui32 squareVec3ui32(edk::uint32 n1,edk::uint32 n2,edk::uint32 n3);
        static edk::vec3ui32 squareVec3ui32(edk::vec3ui32 vec);
        static edk::vec3ui64 squareVec3ui64(edk::uint64 n1,edk::uint64 n2,edk::uint64 n3);
        static edk::vec3ui64 squareVec3ui64(edk::vec3ui64 vec);
        //VEC4
        static edk::vec4f32 squareVec4f32(edk::float32 n1,edk::float32 n2,edk::float32 n3,edk::float32 n4);
        static edk::vec4f32 squareVec4f32(edk::vec4f32 vec);
        static edk::vec4i8 squareVec4i8(edk::int8 n1, edk::int8 n2, edk::int8 n3, edk::int8 n4);
        static edk::vec4i8 squareVec4i8(edk::vec4i8 vec);
        static edk::vec4i16 squareVec4i16(edk::int16 n1,edk::int16 n2,edk::int16 n3,edk::int16 n4);
        static edk::vec4i16 squareVec4i16(edk::vec4i16 vec);
        static edk::vec4i32 squareVec4i32(edk::int32 n1,edk::int32 n2,edk::int32 n3,edk::int32 n4);
        static edk::vec4i32 squareVec4i32(edk::vec4i32 vec);
        static edk::vec4i64 squareVec4i64(edk::int64 n1,edk::int64 n2,edk::int64 n3,edk::int64 n4);
        static edk::vec4i64 squareVec4i64(edk::vec4i64 vec);
        static edk::vec4ui8 squareVec4ui8(edk::uint8 n1,edk::uint8 n2,edk::uint8 n3,edk::uint8 n4);
        static edk::vec4ui8 squareVec4ui8(edk::vec4ui8 vec);
        static edk::vec4ui16 squareVec4ui1(edk::uint16 n1,edk::uint16 n2,edk::uint16 n3,edk::uint16 n4);
        static edk::vec4ui16 squareVec4ui1(edk::vec4ui16 vec);
        static edk::vec4ui32 squareVec4ui32(edk::uint32 n1,edk::uint32 n2,edk::uint32 n3,edk::uint32 n4);
        static edk::vec4ui32 squareVec4ui32(edk::vec4ui32 vec);
        static edk::vec4ui64 squareVec4ui64(edk::uint64 n1,edk::uint64 n2,edk::uint64 n3,edk::uint64 n4);
        static edk::vec4ui64 squareVec4ui64(edk::vec4ui64 vec);

        //MODULE OF A NUMBER
        static edk::float32 moduleFloat(edk::float32 n);
        static edk::int8 moduleInt8(edk::int8 n);
        static edk::int16 moduleInt16(edk::int16 n);
        static edk::int32 moduleInt32(edk::int32 n);
        static edk::int64 moduleInt64(edk::int64 n);
        //VEC2
        static edk::vec2f32 modulevec2f32(edk::float32 n1,edk::float32 n2);
        static edk::vec2f32 modulevec2f32(edk::vec2f32 vec);
        static edk::vec2i8 moduleVec2i8(edk::int8 n1,edk::int8 n2);
        static edk::vec2i8 moduleVec2i8(edk::vec2i8 vec);
        static edk::vec2i16 moduleVec2i16(edk::int16 n1,edk::int16 n2);
        static edk::vec2i16 moduleVec2i16(edk::vec2i16 vec);
        static edk::vec2i32 moduleVec2i32(edk::int32 n1,edk::int32 n2);
        static edk::vec2i32 moduleVec2i32(edk::vec2i32 vec);
        static edk::vec2i64 moduleVec2i64(edk::int64 n1,edk::int64 n2);
        static edk::vec2i64 moduleVec2i64(edk::vec2i64 vec);
        //VEC3
        static edk::vec3f32 modulevec3f32(edk::float32 n1,edk::float32 n2,edk::float32 n3);
        static edk::vec3f32 modulevec3f32(edk::vec3f32 vec);
        static edk::vec3i8 moduleVec3i8(edk::int8 n1,edk::int8 n2,edk::int8 n3);
        static edk::vec3i8 moduleVec3i8(edk::vec3i8 vec);
        static edk::vec3i16 moduleVec3i16(edk::int16 n1,edk::int16 n2,edk::int16 n3);
        static edk::vec3i16 moduleVec3i16(edk::vec3i16 vec);
        static edk::vec3i32 moduleVec3i32(edk::int32 n1,edk::int32 n2,edk::int32 n3);
        static edk::vec3i32 moduleVec3i32(edk::vec3i32 vec);
        static edk::vec3i64 moduleVec3i64(edk::int64 n1,edk::int64 n2,edk::int64 n3);
        static edk::vec3i64 moduleVec3i64(edk::vec3i64 vec);
        //VEC4
        static edk::vec4f32 modulevec4f32(edk::float32 n1,edk::float32 n2,edk::float32 n3,edk::float32 n4);
        static edk::vec4f32 modulevec4f32(edk::vec4f32 vec);
        static edk::vec4i8 moduleVec4i8(edk::int8 n1,edk::int8 n2,edk::int8 n3,edk::int8 n4);
        static edk::vec4i8 moduleVec4i8(edk::vec4i8 vec);
        static edk::vec4i16 moduleVec4i16(edk::int16 n1,edk::int16 n2,edk::int16 n3,edk::int16 n4);
        static edk::vec4i16 moduleVec4i16(edk::vec4i16 vec);
        static edk::vec4i32 moduleVec4i32(edk::int32 n1,edk::int32 n2,edk::int32 n3,edk::int32 n4);
        static edk::vec4i32 moduleVec4i32(edk::vec4i32 vec);
        static edk::vec4i64 moduleVec4i64(edk::int64 n1,edk::int64 n2,edk::int64 n3,edk::int64 n4);
        static edk::vec4i64 moduleVec4i64(edk::vec4i64 vec);

        //Function pythagoras return de distance from 0,0,0,0 axis to X Y Z W
        //FLOAT
        static edk::float32 pythagoras2f(edk::float32 x,edk::float32 y);
        static edk::float32 pythagoras2f(edk::vec2f32 vec);
        static edk::float32 pythagoras3f(edk::float32 x,edk::float32 y,edk::float32 z);
        static edk::float32 pythagoras3f(edk::vec3f32 vec);
        static edk::float32 pythagoras4f(edk::float32 x,edk::float32 y,edk::float32 z, edk::float32 w);
        static edk::float32 pythagoras4f(edk::vec4f32 vec);
        //INT8
        static edk::float32 pythagoras2i8(edk::int8 x,edk::int8 y);
        static edk::float32 pythagoras2i8(edk::vec2i8 vec);
        static edk::float32 pythagoras3i8(edk::int8 x,edk::int8 y,edk::int8 z);
        static edk::float32 pythagoras3i8(edk::vec3i8 vec);
        static edk::float32 pythagoras4i8(edk::int8 x,edk::int8 y,edk::int8 z, edk::int8 w);
        static edk::float32 pythagoras4i8(edk::vec4i8 vec);
        //INT16
        static edk::float32 pythagoras2i16(edk::int16 x,edk::int16 y);
        static edk::float32 pythagoras2i16(edk::vec2i16 vec);
        static edk::float32 pythagoras3i16(edk::int16 x,edk::int16 y,edk::int16 z);
        static edk::float32 pythagoras3i16(edk::vec3i16 vec);
        static edk::float32 pythagoras4i16(edk::int16 x,edk::int16 y,edk::int16 z, edk::int16 w);
        static edk::float32 pythagoras4i16(edk::vec4i16 vec);
        //INT32
        static edk::float32 pythagoras2i32(edk::int32 x,edk::int32 y);
        static edk::float32 pythagoras2i32(edk::vec2i32 vec);
        static edk::float32 pythagoras3i32(edk::int32 x,edk::int32 y,edk::int32 z);
        static edk::float32 pythagoras3i32(edk::vec3i32 vec);
        static edk::float32 pythagoras4i32(edk::int32 x,edk::int32 y,edk::int32 z, edk::int32 w);
        static edk::float32 pythagoras4i32(edk::vec4i32 vec);
        //INT64
        static edk::float32 pythagoras2i64(edk::int64 x,edk::int64 y);
        static edk::float32 pythagoras2i64(edk::vec2i64 vec);
        static edk::float32 pythagoras3i64(edk::int64 x,edk::int64 y,edk::int64 z);
        static edk::float32 pythagoras3i64(edk::vec3i64 vec);
        static edk::float32 pythagoras4i64(edk::int64 x,edk::int64 y,edk::int64 z, edk::int64 w);
        static edk::float32 pythagoras4i64(edk::vec4i64 vec);
        //UINT8
        static edk::float32 pythagoras2ui8(edk::uint8 x,edk::uint8 y);
        static edk::float32 pythagoras2ui8(edk::vec2ui8 vec);
        static edk::float32 pythagoras3ui8(edk::uint8 x,edk::uint8 y,edk::uint8 z);
        static edk::float32 pythagoras3ui8(edk::vec3ui8 vec);
        static edk::float32 pythagoras4ui8(edk::uint8 x,edk::uint8 y,edk::uint8 z, edk::uint8 w);
        static edk::float32 pythagoras4ui8(edk::vec4ui8 vec);
        //UINT16
        static edk::float32 pythagoras2ui16(edk::uint16 x,edk::uint16 y);
        static edk::float32 pythagoras2ui16(edk::vec2ui16 vec);
        static edk::float32 pythagoras3ui16(edk::uint16 x,edk::uint16 y,edk::uint16 z);
        static edk::float32 pythagoras3ui16(edk::vec3ui16 vec);
        static edk::float32 pythagoras4ui16(edk::uint16 x,edk::uint16 y,edk::uint16 z, edk::uint16 w);
        static edk::float32 pythagoras4ui16(edk::vec4ui16 vec);
        //UINT32
        static edk::float32 pythagoras2ui32(edk::uint32 x,edk::uint32 y);
        static edk::float32 pythagoras2ui32(edk::vec2ui32 vec);
        static edk::float32 pythagoras3ui32(edk::uint32 x,edk::uint32 y,edk::uint32 z);
        static edk::float32 pythagoras3ui32(edk::vec3ui32 vec);
        static edk::float32 pythagoras4ui32(edk::uint32 x,edk::uint32 y,edk::uint32 z, edk::uint32 w);
        static edk::float32 pythagoras4ui32(edk::vec4ui32 vec);
        //UINT64
        static edk::float32 pythagoras2ui64(edk::uint64 x,edk::uint64 y);
        static edk::float32 pythagoras2ui64(edk::vec2ui64 vec);
        static edk::float32 pythagoras3ui64(edk::uint64 x,edk::uint64 y,edk::uint64 z);
        static edk::float32 pythagoras3ui64(edk::vec3ui64 vec);
        static edk::float32 pythagoras4ui64(edk::uint64 x,edk::uint64 y,edk::uint64 z, edk::uint64 w);
        static edk::float32 pythagoras4ui64(edk::vec4ui64 vec);

        //Return sin and cosin of angle.
        static edk::float32 getSinFloat(edk::float32 angle);
        static edk::float32 getCosinFloat(edk::float32 angle);
        static edk::float32 getSinInt8(edk::int8 angle);
        static edk::float32 getCosinInt8(edk::int8 angle);
        static edk::float32 getSinInt16(edk::int16 angle);
        static edk::float32 getCosinInt16(edk::int16 angle);
        static edk::float32 getSinInt32(edk::int32 angle);
        static edk::float32 getCosinInt32(edk::int32 angle);
        static edk::float32 getSinInt64(edk::int64 angle);
        static edk::float32 getCosinInt64(edk::int64 angle);
        static edk::float32 getSinUint8(edk::uint8 angle);
        static edk::float32 getCosinUint8(edk::uint8 angle);
        static edk::float32 getSinUint16(edk::uint16 angle);
        static edk::float32 getCosinUint16(edk::uint16 angle);
        static edk::float32 getSinUint32(edk::uint32 angle);
        static edk::float32 getCosinUint32(edk::uint32 angle);
        static edk::float32 getSinUint64(edk::uint64 angle);
        static edk::float32 getCosinUint64(edk::uint64 angle);

        //Return asin and acosin of angle.
        static edk::float32 arcSinFloat(edk::float32 radius,edk::float32 y);
        static edk::float32 arcSinFloat(edk::float32 y);
        static edk::float32 arcCosinFloat(edk::float32 radius,edk::float32 x);
        static edk::float32 arcCosinFloat(edk::float32 x);

        //return the 2D angle of a vector
        static edk::float32 getAngle2f(edk::float32 x,edk::float32 y);
        static edk::float32 getAngle2f(edk::vec2f32 vec);
        //Return the 2D Angle between 2 vectors
        static edk::float32 getAngleDist2f(edk::vec2f32 vec1,edk::vec2f32 vec2);
        static edk::float32 getAngleDist3f(edk::vec3f32 vec1,edk::vec3f32 vec2);
        static edk::float32 getAngleDist4f(edk::vec4f32 vec1,edk::vec4f32 vec2);

        //RightHand to find if the point is on the right or left
        static edk::float32 getAngleDistance(edk::vec2f32 vec1,edk::vec2f32 vec2);

        //Rotate de vector
        static edk::float32 rotateXFloat(edk::float32 radius, edk::float32 angle);
        static edk::float32 rotateYFloat(edk::float32 radius, edk::float32 angle);
        static edk::vec2f32 rotate2f(edk::vec2f32 vec,edk::float32 angle);
        static edk::vec2f32 rotatePlus2f(edk::vec2f32 vec,edk::float32 angle);

        //Normal of the vector
        static edk::vec3f32 normal3f(edk::vec3f32 vec1,edk::vec3f32 vec2,edk::vec3f32 vec3);

        //QUATERION
        static edk::vec3f32 quaternionToAngle(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
        static edk::vec3f32 quaternionToAngle(edk::vec4f32 vec);
        static edk::vec4f32 angleToQuaternion(edk::float32 x,edk::float32 y,edk::float32 z);
        static edk::vec4f32 angleToQuaternion(edk::vec3f32 vec);

        //RADIAN
        static edk::float32 angleToRadFloat(edk::float32 angle);
        static edk::float32 radToAngleFloat(edk::float32 rad);

        //CROSS PRODUCT (calculate the normal of 2 vectors)
        static edk::vec3f32 crossProduct(edk::float32 x1,
                                         edk::float32 y1,
                                         edk::float32 z1,
                                         edk::float32 x2,
                                         edk::float32 y2,
                                         edk::float32 z2
                                         );
        static edk::vec3f32 crossProduct(edk::vec3f32 vec1,edk::vec3f32 vec2);
    protected:
    private:
};
}//end namespace

#endif // MATH_H
