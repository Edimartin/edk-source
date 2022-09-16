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

#define EDK_MATH_EVEN(n) ((n<<((sizeof(n)*8u)-1u))==0u)

namespace edk{
class Math{
public:
    Math();
    virtual ~Math();

    //equal comparison
    static inline bool isEqual(edk::char8 n1 ,edk::char8 n2){return (n1==n2);}
    static inline bool isEqual(edk::int8 n1 ,edk::int8 n2){return (n1==n2);}
    static inline bool isEqual(edk::int16 n1,edk::int16 n2){return (n1==n2);}
    static inline bool isEqual(edk::int32 n1,edk::int32 n2){return (n1==n2);}
    static inline bool isEqual(edk::int64 n1,edk::int64 n2){return (n1==n2);}
    static inline bool isEqual(edk::uint8 n1 ,edk::uint8 n2){return (n1==n2);}
    static inline bool isEqual(edk::uint16 n1,edk::uint16 n2){return (n1==n2);}
    static inline bool isEqual(edk::uint32 n1,edk::uint32 n2){return (n1==n2);}
    static inline bool isEqual(edk::uint64 n1,edk::uint64 n2){return (n1==n2);}
    static inline bool isEqual(edk::float32 n1,edk::float32 n2){return (n1>=n2-0.0001f && n1<=n2+0.0001f);}
    static inline bool isEqual(edk::float64 n1,edk::float64 n2){return (n1>=n2-0.000001f && n1<=n2+0.000001f);}
    static inline bool equal(edk::char8 n1 ,edk::char8 n2){return (n1==n2);}
    static inline bool equal(edk::int8 n1 ,edk::int8 n2){return (n1==n2);}
    static inline bool equal(edk::int16 n1,edk::int16 n2){return (n1==n2);}
    static inline bool equal(edk::int32 n1,edk::int32 n2){return (n1==n2);}
    static inline bool equal(edk::int64 n1,edk::int64 n2){return (n1==n2);}
    static inline bool equal(edk::uint8 n1 ,edk::uint8 n2){return (n1==n2);}
    static inline bool equal(edk::uint16 n1,edk::uint16 n2){return (n1==n2);}
    static inline bool equal(edk::uint32 n1,edk::uint32 n2){return (n1==n2);}
    static inline bool equal(edk::uint64 n1,edk::uint64 n2){return (n1==n2);}
    static inline bool equal(edk::float32 n1,edk::float32 n2){return (n1>=n2-0.0001f && n1<=n2+0.0001f);}
    static inline bool equal(edk::float64 n1,edk::float64 n2){return (n1>=n2-0.000001f && n1<=n2+0.000001f);}

    static inline bool isEven(edk::char8  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool isEven(edk::int8   n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool isEven(edk::int16  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool isEven(edk::int32  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool isEven(edk::int64  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool isEven(edk::uint8  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool isEven(edk::uint16 n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool isEven(edk::uint32 n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool isEven(edk::uint64 n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::char8  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::int8   n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::int16  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::int32  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::int64  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::uint8  n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::uint16 n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::uint32 n){if(EDK_MATH_EVEN(n))return true;return false;}
    static inline bool even(  edk::uint64 n){if(EDK_MATH_EVEN(n))return true;return false;}

    static inline bool isOdd( edk::char8  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool isOdd( edk::int8   n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool isOdd( edk::int16  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool isOdd( edk::int32  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool isOdd( edk::int64  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool isOdd( edk::uint8  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool isOdd( edk::uint16 n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool isOdd( edk::uint32 n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool isOdd( edk::uint64 n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::char8  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::int8   n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::int16  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::int32  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::int64  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::uint8  n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::uint16 n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::uint32 n){if(EDK_MATH_EVEN(n))return false;return true;}
    static inline bool odd(   edk::uint64 n){if(EDK_MATH_EVEN(n))return false;return true;}


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
    //FLOAT
    static edk::float32 pythagoras(edk::float32 x,edk::float32 y);
    static edk::float32 pythagoras(edk::vec2f32 vec);
    static edk::float32 pythagoras(edk::float32 x,edk::float32 y,edk::float32 z);
    static edk::float32 pythagoras(edk::vec3f32 vec);
    static edk::float32 pythagoras(edk::float32 x,edk::float32 y,edk::float32 z, edk::float32 w);
    static edk::float32 pythagoras(edk::vec4f32 vec);
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
    static edk::float32 getAngleDist(edk::float32 x1,edk::float32 y1,
                                     edk::float32 x2,edk::float32 y2
                                     );
    static edk::float32 getAngleDist(edk::vec2f32 vec1,edk::vec2f32 vec2);
    static edk::float32 getAngleDist(edk::float32 x1,edk::float32 y1,edk::float32 z1,
                                     edk::float32 x2,edk::float32 y2,edk::float32 z2
                                     );
    static edk::float32 getAngleDist(edk::vec3f32 vec1,edk::vec3f32 vec2);
    static edk::float32 getAngleDist(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 w1,
                                     edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 w2
                                     );
    static edk::float32 getAngleDist(edk::vec4f32 vec1,edk::vec4f32 vec2);

    //RightHand to find if the point is on the right or left
    static edk::float32 getAngleDistance(edk::float32 x1,edk::float32 y1,
                                         edk::float32 x2,edk::float32 y2
                                         );
    static edk::float32 getAngleDistance(edk::vec2f32 vec1,edk::vec2f32 vec2);

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
protected:
private:
};
}//end namespace

#endif // MATH_H
