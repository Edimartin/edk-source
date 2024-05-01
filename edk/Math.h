#ifndef EDK_MATH_H
#define EDK_MATH_H

/*
Library Math - Math functions to Edk Engine
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
#pragma message "Inside Math"
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
#include "TypeSize2.h"
#include "TypeSize3.h"
#include "TypeRect.h"
#include "TypeColor.h"
#include "vector/Matrix.h"

#ifdef printMessages
#pragma message "    Compiling Math"
#endif

#define EDK_MATH_EVEN(n) ((n<<((sizeof(n)*8u)-1u))==0u)

namespace edk{
class Math{
public:
    Math();
    virtual ~Math();

    void Constructor(bool runFather=true);

    //equal comparison
    static inline bool isEqual(edk::char8 n1 ,edk::char8 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::int8 n1 ,edk::int8 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::int16 n1,edk::int16 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::int32 n1,edk::int32 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::int64 n1,edk::int64 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::uint8 n1 ,edk::uint8 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::uint16 n1,edk::uint16 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::uint32 n1,edk::uint32 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::uint64 n1,edk::uint64 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool isEqual(edk::float32 n1,edk::float32 n2){
        return (n1>=n2-0.0001f && n1<=n2+0.0001f);edkEnd();
    }
    static inline bool isEqual(edk::float64 n1,edk::float64 n2){
        return (n1>=n2-0.000001f && n1<=n2+0.000001f);edkEnd();
    }
    static inline bool isEqual(edk::float32 n1,edk::float32 n2,edk::float32 distance){
        return (n1>=n2-distance && n1<=n2+distance);edkEnd();
    }
    static inline bool isEqual(edk::float64 n1,edk::float64 n2,edk::float64 distance){
        return (n1>=n2-distance && n1<=n2+distance);edkEnd();
    }
    static inline bool equal(edk::char8 n1 ,edk::char8 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::int8 n1 ,edk::int8 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::int16 n1,edk::int16 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::int32 n1,edk::int32 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::int64 n1,edk::int64 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::uint8 n1 ,edk::uint8 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::uint16 n1,edk::uint16 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::uint32 n1,edk::uint32 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::uint64 n1,edk::uint64 n2){
        return (n1==n2);edkEnd();
    }
    static inline bool equal(edk::float32 n1,edk::float32 n2){
        return (n1>=n2-0.0001f && n1<=n2+0.0001f);edkEnd();
    }
    static inline bool equal(edk::float64 n1,edk::float64 n2){
        return (n1>=n2-0.000001f && n1<=n2+0.000001f);edkEnd();
    }
    static inline bool equal(edk::float32 n1,edk::float32 n2,edk::float32 distance){
        return (n1>=n2-distance && n1<=n2+distance);edkEnd();
    }
    static inline bool equal(edk::float64 n1,edk::float64 n2,edk::float64 distance){
        return (n1>=n2-distance && n1<=n2+distance);edkEnd();
    }

    static inline bool isEven(edk::char8  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool isEven(edk::int8   n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool isEven(edk::int16  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool isEven(edk::int32  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool isEven(edk::int64  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool isEven(edk::uint8  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool isEven(edk::uint16 n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool isEven(edk::uint32 n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool isEven(edk::uint64 n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::char8  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::int8   n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::int16  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::int32  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::int64  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::uint8  n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::uint16 n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::uint32 n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }
    static inline bool even(  edk::uint64 n){
        if(EDK_MATH_EVEN(n)){
            return  true;edkEnd();
        }
        return false;
    }

    static inline bool isOdd( edk::char8  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool isOdd( edk::int8   n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool isOdd( edk::int16  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool isOdd( edk::int32  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool isOdd( edk::int64  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool isOdd( edk::uint8  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool isOdd( edk::uint16 n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool isOdd( edk::uint32 n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool isOdd( edk::uint64 n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::char8  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::int8   n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::int16  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::int32  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::int64  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::uint8  n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::uint16 n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::uint32 n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }
    static inline bool odd(   edk::uint64 n){
        if(EDK_MATH_EVEN(n)){
            return false;
        }
        return  true;edkEnd();
    }


    //SquareRoot of the number
    static edk::float32 squareRoot(edk::float32 n);
    static edk::float32 squareRoot(edk::int8 n);
    static edk::float32 squareRoot(edk::int16 n);
    static edk::float32 squareRoot(edk::int32 n);
    static edk::float32 squareRoot(edk::int64 n);
    static edk::float32 squareRoot(edk::uint8 n);
    static edk::float32 squareRoot(edk::uint16 n);
    static edk::float32 squareRoot(edk::uint32 n);
    static edk::float32 squareRoot(edk::uint64 n);

    //Normalise a vector changing it to have distance equal 1.f
    static edk::vec2f32 normalise(edk::float32 x,edk::float32 y);
    static edk::vec2f32 normalise(edk::vec2f32 vec);
    static edk::vec3f32 normalise(edk::float32 x,edk::float32 y,edk::float32 z);
    static edk::vec3f32 normalise(edk::vec3f32 vec);
    static edk::vec4f32 normalise(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    static edk::vec4f32 normalise(edk::vec4f32 vec);

    //DotProduct - Dot Product of two vectors - Scalar Product of two vector (in portuguese)
    static edk::float32 dotProduct(edk::float32 x1,edk::float32 y1,
                                   edk::float32 x2,edk::float32 y2
                                   );
    static edk::float32 dotProduct(edk::vec2f32 vec1,edk::vec2f32 vec2);
    static edk::float32 dotProduct(edk::float32 x1,edk::float32 y1,edk::float32 z1,
                                   edk::float32 x2,edk::float32 y2,edk::float32 z2
                                   );
    static edk::float32 dotProduct(edk::vec3f32 vec1,edk::vec3f32 vec2);
    static edk::float32 dotProduct(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 w1,
                                   edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 w2
                                   );
    static edk::float32 dotProduct(edk::vec4f32 vec1,edk::vec4f32 vec2);

    //CROSS PRODUCT (calculate the normal of 2 vectors)
    static edk::vec3f32 crossProduct(edk::float32 x1,
                                     edk::float32 y1,
                                     edk::float32 z1,
                                     edk::float32 x2,
                                     edk::float32 y2,
                                     edk::float32 z2
                                     );
    static edk::vec3f32 crossProduct(edk::vec3f32 vec1,edk::vec3f32 vec2);

    //The square function return the square of the number (n*n)
    static edk::float32 square(edk::float32 n);
    static edk::float32 square(edk::float64 n);
    static edk::int8 square(edk::int8 n);
    static edk::int16 square(edk::int16 n);
    static edk::int32 square(edk::int32 n);
    static edk::int64 square(edk::int64 n);
    static edk::uint8 square(edk::uint8 n);
    static edk::uint16 square(edk::uint16 n);
    static edk::uint32 square(edk::uint32 n);
    static edk::uint64 square(edk::uint64 n);
    //VEC2
    static edk::vec2f32 square(edk::float32 n1,edk::float32 n2);
    static edk::vec2f32 square(edk::vec2f32 vec);
    static edk::vec2i8 square(edk::int8 n1, edk::int8 n2);
    static edk::vec2i8 square(edk::vec2i8 vec);
    static edk::vec2i16 square(edk::int16 n1,edk::int16 n2);
    static edk::vec2i16 square(edk::vec2i16 vec);
    static edk::vec2i32 square(edk::int32 n1,edk::int32 n2);
    static edk::vec2i32 square(edk::vec2i32 vec);
    static edk::vec2i64 square(edk::int64 n1,edk::int64 n2);
    static edk::vec2i64 square(edk::vec2i64 vec);
    static edk::vec2ui8 square(edk::uint8 n1,edk::uint8 n2);
    static edk::vec2ui8 square(edk::vec2ui8 vec);
    static edk::vec2ui16 square(edk::uint16 n1,edk::uint16 n2);
    static edk::vec2ui16 square(edk::vec2ui16 vec);
    static edk::vec2ui32 square(edk::uint32 n1,edk::uint32 n2);
    static edk::vec2ui32 square(edk::vec2ui32 vec);
    static edk::vec2ui64 square(edk::uint64 n1,edk::uint64 n2);
    static edk::vec2ui64 square(edk::vec2ui64 vec);
    //VEC3
    static edk::vec3f32 square(edk::float32 n1,edk::float32 n2,edk::float32 n3);
    static edk::vec3f32 square(edk::vec3f32 vec);
    static edk::vec3i8 square(edk::int8 n1, edk::int8 n2, edk::int8 n3);
    static edk::vec3i8 square(edk::vec3i8 vec);
    static edk::vec3i16 square(edk::int16 n1,edk::int16 n2,edk::int16 n3);
    static edk::vec3i16 square(edk::vec3i16 vec);
    static edk::vec3i32 square(edk::int32 n1,edk::int32 n2,edk::int32 n3);
    static edk::vec3i32 square(edk::vec3i32 vec);
    static edk::vec3i64 square(edk::int64 n1,edk::int64 n2,edk::int64 n3);
    static edk::vec3i64 square(edk::vec3i64 vec);
    static edk::vec3ui8 square(edk::uint8 n1,edk::uint8 n2,edk::uint8 n3);
    static edk::vec3ui8 square(edk::vec3ui8 vec);
    static edk::vec3ui16 square(edk::uint16 n1,edk::uint16 n2,edk::uint16 n3);
    static edk::vec3ui16 square(edk::vec3ui16 vec);
    static edk::vec3ui32 square(edk::uint32 n1,edk::uint32 n2,edk::uint32 n3);
    static edk::vec3ui32 square(edk::vec3ui32 vec);
    static edk::vec3ui64 square(edk::uint64 n1,edk::uint64 n2,edk::uint64 n3);
    static edk::vec3ui64 square(edk::vec3ui64 vec);
    //VEC4
    static edk::vec4f32 square(edk::float32 n1,edk::float32 n2,edk::float32 n3,edk::float32 n4);
    static edk::vec4f32 square(edk::vec4f32 vec);
    static edk::vec4i8 square(edk::int8 n1, edk::int8 n2, edk::int8 n3, edk::int8 n4);
    static edk::vec4i8 square(edk::vec4i8 vec);
    static edk::vec4i16 square(edk::int16 n1,edk::int16 n2,edk::int16 n3,edk::int16 n4);
    static edk::vec4i16 square(edk::vec4i16 vec);
    static edk::vec4i32 square(edk::int32 n1,edk::int32 n2,edk::int32 n3,edk::int32 n4);
    static edk::vec4i32 square(edk::vec4i32 vec);
    static edk::vec4i64 square(edk::int64 n1,edk::int64 n2,edk::int64 n3,edk::int64 n4);
    static edk::vec4i64 square(edk::vec4i64 vec);
    static edk::vec4ui8 square(edk::uint8 n1,edk::uint8 n2,edk::uint8 n3,edk::uint8 n4);
    static edk::vec4ui8 square(edk::vec4ui8 vec);
    static edk::vec4ui16 square(edk::uint16 n1,edk::uint16 n2,edk::uint16 n3,edk::uint16 n4);
    static edk::vec4ui16 square(edk::vec4ui16 vec);
    static edk::vec4ui32 square(edk::uint32 n1,edk::uint32 n2,edk::uint32 n3,edk::uint32 n4);
    static edk::vec4ui32 square(edk::vec4ui32 vec);
    static edk::vec4ui64 square(edk::uint64 n1,edk::uint64 n2,edk::uint64 n3,edk::uint64 n4);
    static edk::vec4ui64 square(edk::vec4ui64 vec);

    //MODULE OF A NUMBER Aways return the positive version of the number
    static edk::float32 module(edk::float32 n);
    static edk::int8 module(edk::int8 n);
    static edk::int16 module(edk::int16 n);
    static edk::int32 module(edk::int32 n);
    static edk::int64 module(edk::int64 n);
    //VEC2
    static edk::vec2f32 module(edk::float32 n1,edk::float32 n2);
    static edk::vec2f32 module(edk::vec2f32 vec);
    static edk::vec2i8 module(edk::int8 n1,edk::int8 n2);
    static edk::vec2i8 module(edk::vec2i8 vec);
    static edk::vec2i16 module(edk::int16 n1,edk::int16 n2);
    static edk::vec2i16 module(edk::vec2i16 vec);
    static edk::vec2i32 module(edk::int32 n1,edk::int32 n2);
    static edk::vec2i32 module(edk::vec2i32 vec);
    static edk::vec2i64 module(edk::int64 n1,edk::int64 n2);
    static edk::vec2i64 module(edk::vec2i64 vec);
    //VEC3
    static edk::vec3f32 module(edk::float32 n1,edk::float32 n2,edk::float32 n3);
    static edk::vec3f32 module(edk::vec3f32 vec);
    static edk::vec3i8 module(edk::int8 n1,edk::int8 n2,edk::int8 n3);
    static edk::vec3i8 module(edk::vec3i8 vec);
    static edk::vec3i16 module(edk::int16 n1,edk::int16 n2,edk::int16 n3);
    static edk::vec3i16 module(edk::vec3i16 vec);
    static edk::vec3i32 module(edk::int32 n1,edk::int32 n2,edk::int32 n3);
    static edk::vec3i32 module(edk::vec3i32 vec);
    static edk::vec3i64 module(edk::int64 n1,edk::int64 n2,edk::int64 n3);
    static edk::vec3i64 module(edk::vec3i64 vec);
    //VEC4
    static edk::vec4f32 module(edk::float32 n1,edk::float32 n2,edk::float32 n3,edk::float32 n4);
    static edk::vec4f32 module(edk::vec4f32 vec);
    static edk::vec4i8 module(edk::int8 n1,edk::int8 n2,edk::int8 n3,edk::int8 n4);
    static edk::vec4i8 module(edk::vec4i8 vec);
    static edk::vec4i16 module(edk::int16 n1,edk::int16 n2,edk::int16 n3,edk::int16 n4);
    static edk::vec4i16 module(edk::vec4i16 vec);
    static edk::vec4i32 module(edk::int32 n1,edk::int32 n2,edk::int32 n3,edk::int32 n4);
    static edk::vec4i32 module(edk::vec4i32 vec);
    static edk::vec4i64 module(edk::int64 n1,edk::int64 n2,edk::int64 n3,edk::int64 n4);
    static edk::vec4i64 module(edk::vec4i64 vec);

    //Function pythagoras return de distance from 0,0,0,0 axis to X Y Z W
    //FLOAT32
    static edk::float32 pythagoras(edk::float32 x,edk::float32 y);
    static edk::float32 pythagoras(edk::vec2f32 vec);
    static edk::float32 pythagoras(edk::float32 x,edk::float32 y,edk::float32 z);
    static edk::float32 pythagoras(edk::vec3f32 vec);
    static edk::float32 pythagoras(edk::float32 x,edk::float32 y,edk::float32 z, edk::float32 w);
    static edk::float32 pythagoras(edk::vec4f32 vec);
    //FLOAT64
    static edk::float64 pythagoras(edk::float64 x,edk::float64 y);
    static edk::float64 pythagoras(edk::vec2f64 vec);
    static edk::float64 pythagoras(edk::float64 x,edk::float64 y,edk::float64 z);
    static edk::float64 pythagoras(edk::vec3f64 vec);
    static edk::float64 pythagoras(edk::float64 x,edk::float64 y,edk::float64 z, edk::float64 w);
    static edk::float64 pythagoras(edk::vec4f64 vec);
    //INT8
    static edk::float32 pythagoras(edk::int8 x,edk::int8 y);
    static edk::float32 pythagoras(edk::vec2i8 vec);
    static edk::float32 pythagoras(edk::int8 x,edk::int8 y,edk::int8 z);
    static edk::float32 pythagoras(edk::vec3i8 vec);
    static edk::float32 pythagoras(edk::int8 x,edk::int8 y,edk::int8 z, edk::int8 w);
    static edk::float32 pythagoras(edk::vec4i8 vec);
    //INT16
    static edk::float32 pythagoras(edk::int16 x,edk::int16 y);
    static edk::float32 pythagoras(edk::vec2i16 vec);
    static edk::float32 pythagoras(edk::int16 x,edk::int16 y,edk::int16 z);
    static edk::float32 pythagoras(edk::vec3i16 vec);
    static edk::float32 pythagoras(edk::int16 x,edk::int16 y,edk::int16 z, edk::int16 w);
    static edk::float32 pythagoras(edk::vec4i16 vec);
    //INT32
    static edk::float32 pythagoras(edk::int32 x,edk::int32 y);
    static edk::float32 pythagoras(edk::vec2i32 vec);
    static edk::float32 pythagoras(edk::int32 x,edk::int32 y,edk::int32 z);
    static edk::float32 pythagoras(edk::vec3i32 vec);
    static edk::float32 pythagoras(edk::int32 x,edk::int32 y,edk::int32 z, edk::int32 w);
    static edk::float32 pythagoras(edk::vec4i32 vec);
    //INT64
    static edk::float32 pythagoras(edk::int64 x,edk::int64 y);
    static edk::float32 pythagoras(edk::vec2i64 vec);
    static edk::float32 pythagoras(edk::int64 x,edk::int64 y,edk::int64 z);
    static edk::float32 pythagoras(edk::vec3i64 vec);
    static edk::float32 pythagoras(edk::int64 x,edk::int64 y,edk::int64 z, edk::int64 w);
    static edk::float32 pythagoras(edk::vec4i64 vec);
    //UINT8
    static edk::float32 pythagoras(edk::uint8 x,edk::uint8 y);
    static edk::float32 pythagoras(edk::vec2ui8 vec);
    static edk::float32 pythagoras(edk::uint8 x,edk::uint8 y,edk::uint8 z);
    static edk::float32 pythagoras(edk::vec3ui8 vec);
    static edk::float32 pythagoras(edk::uint8 x,edk::uint8 y,edk::uint8 z, edk::uint8 w);
    static edk::float32 pythagoras(edk::vec4ui8 vec);
    //UINT16
    static edk::float32 pythagoras(edk::uint16 x,edk::uint16 y);
    static edk::float32 pythagoras(edk::vec2ui16 vec);
    static edk::float32 pythagoras(edk::uint16 x,edk::uint16 y,edk::uint16 z);
    static edk::float32 pythagoras(edk::vec3ui16 vec);
    static edk::float32 pythagoras(edk::uint16 x,edk::uint16 y,edk::uint16 z, edk::uint16 w);
    static edk::float32 pythagoras(edk::vec4ui16 vec);
    //UINT32
    static edk::float32 pythagoras(edk::uint32 x,edk::uint32 y);
    static edk::float32 pythagoras(edk::vec2ui32 vec);
    static edk::float32 pythagoras(edk::uint32 x,edk::uint32 y,edk::uint32 z);
    static edk::float32 pythagoras(edk::vec3ui32 vec);
    static edk::float32 pythagoras(edk::uint32 x,edk::uint32 y,edk::uint32 z, edk::uint32 w);
    static edk::float32 pythagoras(edk::vec4ui32 vec);
    //UINT64
    static edk::float32 pythagoras(edk::uint64 x,edk::uint64 y);
    static edk::float32 pythagoras(edk::vec2ui64 vec);
    static edk::float32 pythagoras(edk::uint64 x,edk::uint64 y,edk::uint64 z);
    static edk::float32 pythagoras(edk::vec3ui64 vec);
    static edk::float32 pythagoras(edk::uint64 x,edk::uint64 y,edk::uint64 z, edk::uint64 w);
    static edk::float32 pythagoras(edk::vec4ui64 vec);

    //Return sin and cosin of angle.
    static edk::float32 getSin(edk::float32 angle);
    static edk::float32 getCosin(edk::float32 angle);
    static edk::float32 getSin(edk::int8 angle);
    static edk::float32 getCosin(edk::int8 angle);
    static edk::float32 getSin(edk::int16 angle);
    static edk::float32 getCosin(edk::int16 angle);
    static edk::float32 getSin(edk::int32 angle);
    static edk::float32 getCosin(edk::int32 angle);
    static edk::float32 getSin(edk::int64 angle);
    static edk::float32 getCosin(edk::int64 angle);
    static edk::float32 getSin(edk::uint8 angle);
    static edk::float32 getCosin(edk::uint8 angle);
    static edk::float32 getSin(edk::uint16 angle);
    static edk::float32 getCosin(edk::uint16 angle);
    static edk::float32 getSin(edk::uint32 angle);
    static edk::float32 getCosin(edk::uint32 angle);
    static edk::float32 getSin(edk::uint64 angle);
    static edk::float32 getCosin(edk::uint64 angle);

    //Return asin and acosin of angle.
    static edk::float32 arcSin(edk::float32 radius,edk::float32 y);
    static edk::float32 arcSin(edk::float32 y);
    static edk::float32 arcCosin(edk::float32 radius,edk::float32 x);
    static edk::float32 arcCosin(edk::float32 x);

    //return the 2D angle of a vector
    static edk::float32 getAngle(edk::float32 x,edk::float32 y);
    static edk::float32 getAngle(edk::vec2f32 vec);
    //Return the 2D Angle between 2 vectors
    static edk::float32 getAngleDistanceModule(edk::float32 x1,edk::float32 y1,
                                               edk::float32 x2,edk::float32 y2
                                               );
    static edk::float32 getAngleDistanceModule(edk::vec2f32 vec1,edk::vec2f32 vec2);
    static edk::float32 getAngleDistanceModule(edk::float32 x1,edk::float32 y1,edk::float32 z1,
                                               edk::float32 x2,edk::float32 y2,edk::float32 z2
                                               );
    static edk::float32 getAngleDistanceModule(edk::vec3f32 vec1,edk::vec3f32 vec2);
    static edk::float32 getAngleDistanceModule(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 w1,
                                               edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 w2
                                               );
    static edk::float32 getAngleDistanceModule(edk::vec4f32 vec1,edk::vec4f32 vec2);

    //RightHand to find if the point is on the right or left
    static edk::float32 getAngleDistance(edk::float32 x1,edk::float32 y1,
                                         edk::float32 x2,edk::float32 y2
                                         );
    static edk::float32 getAngleDistance(edk::vec2f32 vec1,edk::vec2f32 vec2);

    //get strait 1D Position
    static inline edk::uint8 straightPosition(edk::uint8 p1,edk::uint8 p2,edk::float32 percent){
        return (edk::uint8)((p2-p1*percent)+p1);
    }
    static inline edk::uint16 straightPosition(edk::uint16 p1,edk::uint16 p2,edk::float32 percent){
        return (edk::uint16)((p2-p1*percent)+p1);
    }
    static inline edk::uint32 straightPosition(edk::uint32 p1,edk::uint32 p2,edk::float32 percent){
        return (edk::uint32)((p2-p1*percent)+p1);
    }
    static inline edk::uint64 straightPosition(edk::uint64 p1,edk::uint64 p2,edk::float32 percent){
        return (edk::uint64)((p2-p1*percent)+p1);
    }
    static inline edk::int8 straightPosition(edk::int8 p1,edk::int8 p2,edk::float32 percent){
        return (edk::int8)((p2-p1*percent)+p1);
    }
    static inline edk::int16 straightPosition(edk::int16 p1,edk::int16 p2,edk::float32 percent){
        return (edk::int16)((p2-p1*percent)+p1);
    }
    static inline edk::int32 straightPosition(edk::int32 p1,edk::int32 p2,edk::float32 percent){
        return (edk::int32)((p2-p1*percent)+p1);
    }
    static inline edk::int64 straightPosition(edk::int64 p1,edk::int64 p2,edk::float32 percent){
        return (edk::int64)((p2-p1*percent)+p1);
    }
    static inline edk::float32 straightPosition(edk::float32 p1,edk::float32 p2,edk::float32 percent){
        return (p2-p1*percent)+p1;
    }
    static inline edk::float64 straightPosition(edk::float64 p1,edk::float64 p2,edk::float64 percent){
        return (p2-p1*percent)+p1;
    }
    static inline edk::float64 straightPosition(edk::float64 p1,edk::float64 p2,edk::float32 percent){
        return (p2-p1*percent)+p1;
    }
    //
    static inline edk::uint8 getStraightPosition(edk::uint8 p1,edk::uint8 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::uint16 getStraightPosition(edk::uint16 p1,edk::uint16 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::uint32 getStraightPosition(edk::uint32 p1,edk::uint32 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::uint64 getStraightPosition(edk::uint64 p1,edk::uint64 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::int8 getStraightPosition(edk::int8 p1,edk::int8 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::int16 getStraightPosition(edk::int16 p1,edk::int16 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::int32 getStraightPosition(edk::int32 p1,edk::int32 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::int64 getStraightPosition(edk::int64 p1,edk::int64 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::float32 getStraightPosition(edk::float32 p1,edk::float32 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::float64 getStraightPosition(edk::float64 p1,edk::float64 p2,edk::float64 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    static inline edk::float64 getStraightPosition(edk::float64 p1,edk::float64 p2,edk::float32 percent){
        return edk::Math::straightPosition(p1,p2,percent);
    }
    //get straight 2D position
    static inline edk::vec2ui8 straightPosition(edk::vec2ui8 p1,edk::vec2ui8 p2,edk::float32 percent){
        return edk::vec2ui8(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2ui16 straightPosition(edk::vec2ui16 p1,edk::vec2ui16 p2,edk::float32 percent){
        return edk::vec2ui16(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent)
                             );
    }
    static inline edk::vec2ui32 straightPosition(edk::vec2ui32 p1,edk::vec2ui32 p2,edk::float32 percent){
        return edk::vec2ui32(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent)
                             );
    }
    static inline edk::vec2ui64 straightPosition(edk::vec2ui64 p1,edk::vec2ui64 p2,edk::float32 percent){
        return edk::vec2ui64(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent)
                             );
    }
    static inline edk::vec2i8 straightPosition(edk::vec2i8 p1,edk::vec2i8 p2,edk::float32 percent){
        return edk::vec2i8(edk::Math::straightPosition(p1.x,p2.x,percent),
                           edk::Math::straightPosition(p1.y,p2.y,percent)
                           );
    }
    static inline edk::vec2i16 straightPosition(edk::vec2i16 p1,edk::vec2i16 p2,edk::float32 percent){
        return edk::vec2i16(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2i32 straightPosition(edk::vec2i32 p1,edk::vec2i32 p2,edk::float32 percent){
        return edk::vec2i32(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2i64 straightPosition(edk::vec2i64 p1,edk::vec2i64 p2,edk::float32 percent){
        return edk::vec2i64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2f32 straightPosition(edk::vec2f32 p1,edk::vec2f32 p2,edk::float32 percent){
        return edk::vec2f32(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2f64 straightPosition(edk::vec2f64 p1,edk::vec2f64 p2,edk::float64 percent){
        return edk::vec2f64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2f64 straightPosition(edk::vec2f64 p1,edk::vec2f64 p2,edk::float32 percent){
        return edk::vec2f64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2ui8 getStraightPosition(edk::vec2ui8 p1,edk::vec2ui8 p2,edk::float32 percent){
        return edk::vec2ui8(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2ui16 getStraightPosition(edk::vec2ui16 p1,edk::vec2ui16 p2,edk::float32 percent){
        return edk::vec2ui16(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent)
                             );
    }
    static inline edk::vec2ui32 getStraightPosition(edk::vec2ui32 p1,edk::vec2ui32 p2,edk::float32 percent){
        return edk::vec2ui32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent)
                             );
    }
    static inline edk::vec2ui64 getStraightPosition(edk::vec2ui64 p1,edk::vec2ui64 p2,edk::float32 percent){
        return edk::vec2ui64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent)
                             );
    }
    static inline edk::vec2i8 getStraightPosition(edk::vec2i8 p1,edk::vec2i8 p2,edk::float32 percent){
        return edk::vec2i8(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                           edk::Math::getStraightPosition(p1.y,p2.y,percent)
                           );
    }
    static inline edk::vec2i16 getStraightPosition(edk::vec2i16 p1,edk::vec2i16 p2,edk::float32 percent){
        return edk::vec2i16(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2i32 getStraightPosition(edk::vec2i32 p1,edk::vec2i32 p2,edk::float32 percent){
        return edk::vec2i32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2i64 getStraightPosition(edk::vec2i64 p1,edk::vec2i64 p2,edk::float32 percent){
        return edk::vec2i64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2f32 getStraightPosition(edk::vec2f32 p1,edk::vec2f32 p2,edk::float32 percent){
        return edk::vec2f32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2f64 getStraightPosition(edk::vec2f64 p1,edk::vec2f64 p2,edk::float64 percent){
        return edk::vec2f64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent)
                            );
    }
    static inline edk::vec2f64 getStraightPosition(edk::vec2f64 p1,edk::vec2f64 p2,edk::float32 percent){
        return edk::vec2f64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent)
                            );
    }
    //get straight 3D position
    static inline edk::vec3ui8 straightPosition(edk::vec3ui8 p1,edk::vec3ui8 p2,edk::float32 percent){
        return edk::vec3ui8(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3ui16 straightPosition(edk::vec3ui16 p1,edk::vec3ui16 p2,edk::float32 percent){
        return edk::vec3ui16(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent),
                             edk::Math::straightPosition(p1.z,p2.z,percent)
                             );
    }
    static inline edk::vec3ui32 straightPosition(edk::vec3ui32 p1,edk::vec3ui32 p2,edk::float32 percent){
        return edk::vec3ui32(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent),
                             edk::Math::straightPosition(p1.z,p2.z,percent)
                             );
    }
    static inline edk::vec3ui64 straightPosition(edk::vec3ui64 p1,edk::vec3ui64 p2,edk::float32 percent){
        return edk::vec3ui64(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent),
                             edk::Math::straightPosition(p1.z,p2.z,percent)
                             );
    }
    static inline edk::vec3i8 straightPosition(edk::vec3i8 p1,edk::vec3i8 p2,edk::float32 percent){
        return edk::vec3i8(edk::Math::straightPosition(p1.x,p2.x,percent),
                           edk::Math::straightPosition(p1.y,p2.y,percent),
                           edk::Math::straightPosition(p1.z,p2.z,percent)
                           );
    }
    static inline edk::vec3i16 straightPosition(edk::vec3i16 p1,edk::vec3i16 p2,edk::float32 percent){
        return edk::vec3i16(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3i32 straightPosition(edk::vec3i32 p1,edk::vec3i32 p2,edk::float32 percent){
        return edk::vec3i32(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3i64 straightPosition(edk::vec3i64 p1,edk::vec3i64 p2,edk::float32 percent){
        return edk::vec3i64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3f32 straightPosition(edk::vec3f32 p1,edk::vec3f32 p2,edk::float32 percent){
        return edk::vec3f32(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3f64 straightPosition(edk::vec3f64 p1,edk::vec3f64 p2,edk::float64 percent){
        return edk::vec3f64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3f64 straightPosition(edk::vec3f64 p1,edk::vec3f64 p2,edk::float32 percent){
        return edk::vec3f64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3ui8 getStraightPosition(edk::vec3ui8 p1,edk::vec3ui8 p2,edk::float32 percent){
        return edk::vec3ui8(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3ui16 getStraightPosition(edk::vec3ui16 p1,edk::vec3ui16 p2,edk::float32 percent){
        return edk::vec3ui16(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent),
                             edk::Math::getStraightPosition(p1.z,p2.z,percent)
                             );
    }
    static inline edk::vec3ui32 getStraightPosition(edk::vec3ui32 p1,edk::vec3ui32 p2,edk::float32 percent){
        return edk::vec3ui32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent),
                             edk::Math::getStraightPosition(p1.z,p2.z,percent)
                             );
    }
    static inline edk::vec3ui64 getStraightPosition(edk::vec3ui64 p1,edk::vec3ui64 p2,edk::float32 percent){
        return edk::vec3ui64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent),
                             edk::Math::getStraightPosition(p1.z,p2.z,percent)
                             );
    }
    static inline edk::vec3i8 getStraightPosition(edk::vec3i8 p1,edk::vec3i8 p2,edk::float32 percent){
        return edk::vec3i8(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                           edk::Math::getStraightPosition(p1.y,p2.y,percent),
                           edk::Math::getStraightPosition(p1.z,p2.z,percent)
                           );
    }
    static inline edk::vec3i16 getStraightPosition(edk::vec3i16 p1,edk::vec3i16 p2,edk::float32 percent){
        return edk::vec3i16(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3i32 getStraightPosition(edk::vec3i32 p1,edk::vec3i32 p2,edk::float32 percent){
        return edk::vec3i32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3i64 getStraightPosition(edk::vec3i64 p1,edk::vec3i64 p2,edk::float32 percent){
        return edk::vec3i64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3f32 getStraightPosition(edk::vec3f32 p1,edk::vec3f32 p2,edk::float32 percent){
        return edk::vec3f32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3f64 getStraightPosition(edk::vec3f64 p1,edk::vec3f64 p2,edk::float64 percent){
        return edk::vec3f64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent)
                            );
    }
    static inline edk::vec3f64 getStraightPosition(edk::vec3f64 p1,edk::vec3f64 p2,edk::float32 percent){
        return edk::vec3f64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent)
                            );
    }
    //get straight 4D position
    static inline edk::vec4ui8 straightPosition(edk::vec4ui8 p1,edk::vec4ui8 p2,edk::float32 percent){
        return edk::vec4ui8(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent),
                            edk::Math::straightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4ui16 straightPosition(edk::vec4ui16 p1,edk::vec4ui16 p2,edk::float32 percent){
        return edk::vec4ui16(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent),
                             edk::Math::straightPosition(p1.z,p2.z,percent),
                             edk::Math::straightPosition(p1.w,p2.w,percent)
                             );
    }
    static inline edk::vec4ui32 straightPosition(edk::vec4ui32 p1,edk::vec4ui32 p2,edk::float32 percent){
        return edk::vec4ui32(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent),
                             edk::Math::straightPosition(p1.z,p2.z,percent),
                             edk::Math::straightPosition(p1.w,p2.w,percent)
                             );
    }
    static inline edk::vec4ui64 straightPosition(edk::vec4ui64 p1,edk::vec4ui64 p2,edk::float32 percent){
        return edk::vec4ui64(edk::Math::straightPosition(p1.x,p2.x,percent),
                             edk::Math::straightPosition(p1.y,p2.y,percent),
                             edk::Math::straightPosition(p1.z,p2.z,percent),
                             edk::Math::straightPosition(p1.w,p2.w,percent)
                             );
    }
    static inline edk::vec4i8 straightPosition(edk::vec4i8 p1,edk::vec4i8 p2,edk::float32 percent){
        return edk::vec4i8(edk::Math::straightPosition(p1.x,p2.x,percent),
                           edk::Math::straightPosition(p1.y,p2.y,percent),
                           edk::Math::straightPosition(p1.z,p2.z,percent),
                           edk::Math::straightPosition(p1.w,p2.w,percent)
                           );
    }
    static inline edk::vec4i16 straightPosition(edk::vec4i16 p1,edk::vec4i16 p2,edk::float32 percent){
        return edk::vec4i16(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent),
                            edk::Math::straightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4i32 straightPosition(edk::vec4i32 p1,edk::vec4i32 p2,edk::float32 percent){
        return edk::vec4i32(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent),
                            edk::Math::straightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4i64 straightPosition(edk::vec4i64 p1,edk::vec4i64 p2,edk::float32 percent){
        return edk::vec4i64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent),
                            edk::Math::straightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4f32 straightPosition(edk::vec4f32 p1,edk::vec4f32 p2,edk::float32 percent){
        return edk::vec4f32(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent),
                            edk::Math::straightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4f64 straightPosition(edk::vec4f64 p1,edk::vec4f64 p2,edk::float64 percent){
        return edk::vec4f64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent),
                            edk::Math::straightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4f64 straightPosition(edk::vec4f64 p1,edk::vec4f64 p2,edk::float32 percent){
        return edk::vec4f64(edk::Math::straightPosition(p1.x,p2.x,percent),
                            edk::Math::straightPosition(p1.y,p2.y,percent),
                            edk::Math::straightPosition(p1.z,p2.z,percent),
                            edk::Math::straightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4ui8 getStraightPosition(edk::vec4ui8 p1,edk::vec4ui8 p2,edk::float32 percent){
        return edk::vec4ui8(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent),
                            edk::Math::getStraightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4ui16 getStraightPosition(edk::vec4ui16 p1,edk::vec4ui16 p2,edk::float32 percent){
        return edk::vec4ui16(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent),
                             edk::Math::getStraightPosition(p1.z,p2.z,percent),
                             edk::Math::getStraightPosition(p1.w,p2.w,percent)
                             );
    }
    static inline edk::vec4ui32 getStraightPosition(edk::vec4ui32 p1,edk::vec4ui32 p2,edk::float32 percent){
        return edk::vec4ui32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent),
                             edk::Math::getStraightPosition(p1.z,p2.z,percent),
                             edk::Math::getStraightPosition(p1.w,p2.w,percent)
                             );
    }
    static inline edk::vec4ui64 getStraightPosition(edk::vec4ui64 p1,edk::vec4ui64 p2,edk::float32 percent){
        return edk::vec4ui64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                             edk::Math::getStraightPosition(p1.y,p2.y,percent),
                             edk::Math::getStraightPosition(p1.z,p2.z,percent),
                             edk::Math::getStraightPosition(p1.w,p2.w,percent)
                             );
    }
    static inline edk::vec4i8 getStraightPosition(edk::vec4i8 p1,edk::vec4i8 p2,edk::float32 percent){
        return edk::vec4i8(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                           edk::Math::getStraightPosition(p1.y,p2.y,percent),
                           edk::Math::getStraightPosition(p1.z,p2.z,percent),
                           edk::Math::getStraightPosition(p1.w,p2.w,percent)
                           );
    }
    static inline edk::vec4i16 getStraightPosition(edk::vec4i16 p1,edk::vec4i16 p2,edk::float32 percent){
        return edk::vec4i16(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent),
                            edk::Math::getStraightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4i32 getStraightPosition(edk::vec4i32 p1,edk::vec4i32 p2,edk::float32 percent){
        return edk::vec4i32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent),
                            edk::Math::getStraightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4i64 getStraightPosition(edk::vec4i64 p1,edk::vec4i64 p2,edk::float32 percent){
        return edk::vec4i64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent),
                            edk::Math::getStraightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4f32 getStraightPosition(edk::vec4f32 p1,edk::vec4f32 p2,edk::float32 percent){
        return edk::vec4f32(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent),
                            edk::Math::getStraightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4f64 getStraightPosition(edk::vec4f64 p1,edk::vec4f64 p2,edk::float64 percent){
        return edk::vec4f64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent),
                            edk::Math::getStraightPosition(p1.w,p2.w,percent)
                            );
    }
    static inline edk::vec4f64 getStraightPosition(edk::vec4f64 p1,edk::vec4f64 p2,edk::float32 percent){
        return edk::vec4f64(edk::Math::getStraightPosition(p1.x,p2.x,percent),
                            edk::Math::getStraightPosition(p1.y,p2.y,percent),
                            edk::Math::getStraightPosition(p1.z,p2.z,percent),
                            edk::Math::getStraightPosition(p1.w,p2.w,percent)
                            );
    }
    //get straight RGB
    static inline edk::color3ui8 straightPosition(edk::color3ui8 p1,edk::color3ui8 p2,edk::float32 percent){
        return edk::color3ui8(edk::Math::straightPosition(p1.r,p2.r,percent),
                              edk::Math::straightPosition(p1.g,p2.g,percent),
                              edk::Math::straightPosition(p1.b,p2.b,percent)
                              );
    }
    static inline edk::color3f32 straightPosition(edk::color3f32 p1,edk::color3f32 p2,edk::float32 percent){
        return edk::color3f32(edk::Math::straightPosition(p1.r,p2.r,percent),
                              edk::Math::straightPosition(p1.g,p2.g,percent),
                              edk::Math::straightPosition(p1.b,p2.b,percent)
                              );
    }
    static inline edk::color3f64 straightPosition(edk::color3f64 p1,edk::color3f64 p2,edk::float64 percent){
        return edk::color3f64(edk::Math::straightPosition(p1.r,p2.r,percent),
                              edk::Math::straightPosition(p1.g,p2.g,percent),
                              edk::Math::straightPosition(p1.b,p2.b,percent)
                              );
    }
    static inline edk::color3f64 straightPosition(edk::color3f64 p1,edk::color3f64 p2,edk::float32 percent){
        return edk::color3f64(edk::Math::straightPosition(p1.r,p2.r,percent),
                              edk::Math::straightPosition(p1.g,p2.g,percent),
                              edk::Math::straightPosition(p1.b,p2.b,percent)
                              );
    }
    static inline edk::color3ui8 getStraightPosition(edk::color3ui8 p1,edk::color3ui8 p2,edk::float32 percent){
        return edk::color3ui8(edk::Math::getStraightPosition(p1.r,p2.r,percent),
                              edk::Math::getStraightPosition(p1.g,p2.g,percent),
                              edk::Math::getStraightPosition(p1.b,p2.b,percent)
                              );
    }
    static inline edk::color3f32 getStraightPosition(edk::color3f32 p1,edk::color3f32 p2,edk::float32 percent){
        return edk::color3f32(edk::Math::getStraightPosition(p1.r,p2.r,percent),
                              edk::Math::getStraightPosition(p1.g,p2.g,percent),
                              edk::Math::getStraightPosition(p1.b,p2.b,percent)
                              );
    }
    static inline edk::color3f64 getStraightPosition(edk::color3f64 p1,edk::color3f64 p2,edk::float64 percent){
        return edk::color3f64(edk::Math::getStraightPosition(p1.r,p2.r,percent),
                              edk::Math::getStraightPosition(p1.g,p2.g,percent),
                              edk::Math::getStraightPosition(p1.b,p2.b,percent)
                              );
    }
    static inline edk::color3f64 getStraightPosition(edk::color3f64 p1,edk::color3f64 p2,edk::float32 percent){
        return edk::color3f64(edk::Math::getStraightPosition(p1.r,p2.r,percent),
                              edk::Math::getStraightPosition(p1.g,p2.g,percent),
                              edk::Math::getStraightPosition(p1.b,p2.b,percent)
                              );
    }
    //get straight RGBA
    static inline edk::color4ui8 straightPosition(edk::color4ui8 p1,edk::color4ui8 p2,edk::float32 percent){
        return edk::color4ui8(edk::Math::straightPosition(p1.r,p2.r,percent),
                              edk::Math::straightPosition(p1.g,p2.g,percent),
                              edk::Math::straightPosition(p1.b,p2.b,percent),
                              edk::Math::straightPosition(p1.a,p2.a,percent)
                              );
    }
    static inline edk::color4f32 straightPosition(edk::color4f32 p1,edk::color4f32 p2,edk::float32 percent){
        return edk::color4f32(edk::Math::straightPosition(p1.r,p2.r,percent),
                              edk::Math::straightPosition(p1.g,p2.g,percent),
                              edk::Math::straightPosition(p1.b,p2.b,percent),
                              edk::Math::straightPosition(p1.a,p2.a,percent)
                              );
    }
    static inline edk::color4f64 straightPosition(edk::color4f64 p1,edk::color4f64 p2,edk::float64 percent){
        return edk::color4f64(edk::Math::straightPosition(p1.r,p2.r,percent),
                              edk::Math::straightPosition(p1.g,p2.g,percent),
                              edk::Math::straightPosition(p1.b,p2.b,percent),
                              edk::Math::straightPosition(p1.a,p2.a,percent)
                              );
    }
    static inline edk::color4f64 straightPosition(edk::color4f64 p1,edk::color4f64 p2,edk::float32 percent){
        return edk::color4f64(edk::Math::straightPosition(p1.r,p2.r,percent),
                              edk::Math::straightPosition(p1.g,p2.g,percent),
                              edk::Math::straightPosition(p1.b,p2.b,percent),
                              edk::Math::straightPosition(p1.a,p2.a,percent)
                              );
    }
    static inline edk::color4ui8 getStraightPosition(edk::color4ui8 p1,edk::color4ui8 p2,edk::float32 percent){
        return edk::color4ui8(edk::Math::getStraightPosition(p1.r,p2.r,percent),
                              edk::Math::getStraightPosition(p1.g,p2.g,percent),
                              edk::Math::getStraightPosition(p1.b,p2.b,percent),
                              edk::Math::getStraightPosition(p1.a,p2.a,percent)
                              );
    }
    static inline edk::color4f32 getStraightPosition(edk::color4f32 p1,edk::color4f32 p2,edk::float32 percent){
        return edk::color4f32(edk::Math::getStraightPosition(p1.r,p2.r,percent),
                              edk::Math::getStraightPosition(p1.g,p2.g,percent),
                              edk::Math::getStraightPosition(p1.b,p2.b,percent),
                              edk::Math::getStraightPosition(p1.a,p2.a,percent)
                              );
    }
    static inline edk::color4f64 getStraightPosition(edk::color4f64 p1,edk::color4f64 p2,edk::float64 percent){
        return edk::color4f64(edk::Math::getStraightPosition(p1.r,p2.r,percent),
                              edk::Math::getStraightPosition(p1.g,p2.g,percent),
                              edk::Math::getStraightPosition(p1.b,p2.b,percent),
                              edk::Math::getStraightPosition(p1.a,p2.a,percent)
                              );
    }
    static inline edk::color4f64 getStraightPosition(edk::color4f64 p1,edk::color4f64 p2,edk::float32 percent){
        return edk::color4f64(edk::Math::getStraightPosition(p1.r,p2.r,percent),
                              edk::Math::getStraightPosition(p1.g,p2.g,percent),
                              edk::Math::getStraightPosition(p1.b,p2.b,percent),
                              edk::Math::getStraightPosition(p1.a,p2.a,percent)
                              );
    }

    //generate matrices
    //2D
    //translate matrix
    static bool generateTranslateMatrix(edk::vec2f32 position,edk::vector::Matrixf32<3u,3u>* dest);
    static inline bool generateTranslateMatrix2D(edk::float32 x,edk::float32 y,edk::vector::Matrixf32<3u,3u>* dest){
        return edk::Math::generateTranslateMatrix(edk::vec2f32(x,y),dest);
    }
    //rotate matrix
    static bool generateRotateMatrixX(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest);
    static inline bool generateRotateMatrix2DX(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest){
        return edk::Math::generateRotateMatrixX(angle,dest);
    }
    static bool generateRotateMatrixY(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest);
    static inline bool generateRotateMatrix2DY(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest){
        return edk::Math::generateRotateMatrixY(angle,dest);
    }
    static bool generateRotateMatrixZ(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest);
    static inline bool generateRotateMatrix2DZ(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest){
        return edk::Math::generateRotateMatrixZ(angle,dest);
    }
    //scale matrix
    static bool generateScaleMatrix(edk::size2f32 size,edk::vector::Matrixf32<3u,3u>* dest);
    static inline bool generateScaleMatrix2D(edk::float32 width,edk::float32 height,edk::vector::Matrixf32<3u,3u>* dest){
        return edk::Math::generateScaleMatrix(edk::size2f32(width,height),dest);
    }
    //3D
    //translate matrix
    static bool generateTranslateMatrix(edk::vec3f32 position,edk::vector::Matrixf32<3u,3u>* dest);
    static bool generateTranslateMatrix(edk::vec3f32 position,edk::vector::Matrixf32<4u,4u>* dest);
    static inline bool generateTranslateMatrix3D(edk::float32 x,edk::float32 y,edk::float32 z,edk::vector::Matrixf32<3u,3u>* dest){
        return edk::Math::generateTranslateMatrix(edk::vec3f32(x,y,z),dest);
    }
    static inline bool generateTranslateMatrix3D(edk::float32 x,edk::float32 y,edk::float32 z,edk::vector::Matrixf32<4u,4u>* dest){
        return edk::Math::generateTranslateMatrix(edk::vec3f32(x,y,z),dest);
    }
    //rotate matrix
    static bool generateRotateMatrixX(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest);
    static inline bool generateRotateMatrix3DX(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest){
        return edk::Math::generateRotateMatrixX(angle,dest);
    }
    static bool generateRotateMatrixY(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest);
    static inline bool generateRotateMatrix3DY(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest){
        return edk::Math::generateRotateMatrixY(angle,dest);
    }
    static bool generateRotateMatrixZ(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest);
    static inline bool generateRotateMatrix3DZ(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest){
        return edk::Math::generateRotateMatrixZ(angle,dest);
    }
    //scale matrix
    static bool generateScaleMatrix(edk::size3f32 size,edk::vector::Matrixf32<3u,3u>* dest);
    static bool generateScaleMatrix(edk::size3f32 size,edk::vector::Matrixf32<4u,4u>* dest);
    static inline bool generateScaleMatrix3D(edk::float32 width,edk::float32 height,edk::float32 lenght,edk::vector::Matrixf32<3u,3u>* dest){
        return edk::Math::generateScaleMatrix(edk::size3f32(width,height,lenght),dest);
    }
    static inline bool generateScaleMatrix3D(edk::float32 width,edk::float32 height,edk::float32 lenght,edk::vector::Matrixf32<4u,4u>* dest){
        return edk::Math::generateScaleMatrix(edk::size3f32(width,height,lenght),dest);
    }

    //Rotate de vectors
    static edk::float32 rotateX(edk::float32 radius, edk::float32 angle);
    static edk::float32 rotateY(edk::float32 radius, edk::float32 angle);
    static edk::vec2f32 rotate(edk::float32 x,edk::float32 y,edk::float32 angle);
    static edk::vec2f32 rotate(edk::vec2f32 vec,edk::float32 angle);
    static edk::vec2f32 rotatePlus(edk::float32 x,edk::float32 y,edk::float32 angle);
    static edk::vec2f32 rotatePlus(edk::vec2f32 vec,edk::float32 angle);

    //Normal of the triangle
    static edk::vec3f32 normalTriangle(edk::float32 x1,edk::float32 y1,edk::float32 z1,
                                       edk::float32 x2,edk::float32 y2,edk::float32 z2,
                                       edk::float32 x3,edk::float32 y3,edk::float32 z3
                                       );
    static edk::vec3f32 normalTriangle(edk::vec3f32 vec1,edk::vec3f32 vec2,edk::vec3f32 vec3);

    //QUATERION
    static edk::vec3f32 quaternionToAngle(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    static edk::vec3f32 quaternionToAngle(edk::vec4f32 vec);
    static edk::vec4f32 angleToQuaternion(edk::float32 x,edk::float32 y,edk::float32 z);
    static edk::vec4f32 angleToQuaternion(edk::vec3f32 vec);

    //RADIAN
    static edk::float32 angleToRad(edk::float32 angle);
    static edk::float32 radToAngle(edk::float32 rad);

    //fill a size inside a size
    static edk::rectf32 fitInside(edk::size2f32 fill,edk::size2f32 inside);
    static edk::rectf32 fitInside(edk::float32 fillWidth,edk::float32 fillHeight,
                                  edk::float32 insideWidth,edk::float32 insideHeight
                                  );
    static inline edk::rectf32 aspectRatioCorrect(edk::size2f32 fill,edk::size2f32 inside){
        return edk::Math::fitInside(fill,inside);
    }
    static inline edk::rectf32 aspectRatioCorrect(edk::float32 fillWidth,edk::float32 fillHeight,
                                                  edk::float32 insideWidth,edk::float32 insideHeight
                                                  ){
        return edk::Math::fitInside(fillWidth,fillHeight,
                                    insideWidth,insideHeight
                                    );
    }
    //fill a size inside a rectangle
    static edk::rectf32 fitInside(edk::rectf32 fill,edk::size2f32 inside);
    static edk::rectf32 fitInside(edk::vec2f32 fillOrigin,edk::size2f32 fillSize,edk::size2f32 insideSize);
    static edk::rectf32 fitInside(edk::float32 fillOriginX,edk::float32 fillOriginY,edk::float32 fillSizeWidth,edk::float32 fillSizeHeight,
                                  edk::float32 insideSizeWidth,edk::float32 insideSizeHeight
                                  );
    static inline edk::rectf32 aspectRatioCorrect(edk::rectf32 fill,edk::size2f32 inside){
        return edk::Math::fitInside(fill,inside);
    }
    static inline edk::rectf32 aspectRatioCorrect(edk::vec2f32 fillOrigin,edk::size2f32 fillSize,edk::size2f32 insideSize){
        return edk::Math::fitInside(fillOrigin,fillSize,insideSize);
    }
    static inline edk::rectf32 aspectRatioCorrect(edk::float32 fillOriginX,edk::float32 fillOriginY,edk::float32 fillSizeWidth,edk::float32 fillSizeHeight,
                                                  edk::float32 insideSizeWidth,edk::float32 insideSizeHeight
                                                  ){
        return edk::Math::fitInside(fillOriginX,fillOriginY,fillSizeWidth,fillSizeHeight,
                                    insideSizeWidth,insideSizeHeight
                                    );
    }
private:
    edk::classID classThis;
};
}//end namespace

#endif // MATH_H
