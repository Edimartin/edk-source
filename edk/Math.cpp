#include "Math.h"

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
#pragma message "            Inside Math.cpp"
#endif

edk::Math::Math(){
    this->classThis=NULL;
    this->Constructor();
}

edk::Math::~Math(){
    this->Destructor();
}

void edk::Math::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::Math::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

//SquareRoot
edk::float32 edk::Math::squareRoot(edk::float32 n){return sqrt(n); }
edk::float32 edk::Math::squareRoot(edk::int8 n){return sqrt(n); }
edk::float32 edk::Math::squareRoot(edk::int16 n){return sqrt(n); }
edk::float32 edk::Math::squareRoot(edk::int32 n){return sqrt(n); }
edk::float32 edk::Math::squareRoot(edk::int64 n){return sqrt(n); }
edk::float32 edk::Math::squareRoot(edk::uint8 n){return sqrt(n); }
edk::float32 edk::Math::squareRoot(edk::uint16 n){return sqrt(n); }
edk::float32 edk::Math::squareRoot(edk::uint32 n){return sqrt(n); }
edk::float32 edk::Math::squareRoot(edk::uint64 n){return sqrt(n); }

//Normalise
edk::vec2f32  edk::Math::normalise(edk::float32 x,edk::float32 y){return edk::Math::normalise(edk::vec2f32(x,y)); }
edk::vec2f32  edk::Math::normalise(edk::vec2f32 vec){
    //get the vectorDist
    edk::float32 dist = edk::Math::pythagoras(vec);
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
edk::vec3f32  edk::Math::normalise(edk::float32 x,edk::float32 y,edk::float32 z){return edk::Math::normalise(edk::vec3f32(x,y,z)); }
edk::vec3f32  edk::Math::normalise(edk::vec3f32 vec){
    //get the vectorDist
    edk::float32 dist = edk::Math::pythagoras(vec);
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
edk::vec4f32  edk::Math::normalise(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){return edk::Math::normalise(edk::vec4f32(x,y,z,w)); }
edk::vec4f32  edk::Math::normalise(edk::vec4f32 vec){
    //get the vectorDist
    edk::float32 dist = edk::Math::pythagoras(vec);
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

//ScalarProduct
edk::float32 edk::Math::dotProduct(edk::float32 x1,edk::float32 y1,
                                   edk::float32 x2,edk::float32 y2
                                   ){
    return edk::Math::dotProduct(edk::vec2f32(x1,y1),edk::vec2f32(x2,y2));
}
edk::float32 edk::Math::dotProduct(edk::vec2f32 vec1,edk::vec2f32 vec2){
    //
    return (vec1.x*vec2.x) + (vec1.y*vec2.y);
}
edk::float32 edk::Math::dotProduct(edk::float32 x1,edk::float32 y1,edk::float32 z1,
                                   edk::float32 x2,edk::float32 y2,edk::float32 z2
                                   ){
    return edk::Math::dotProduct(edk::vec3f32(x1,y1,z1),edk::vec3f32(x2,y2,z2));
}
edk::float32 edk::Math::dotProduct(edk::vec3f32 vec1,edk::vec3f32 vec2){
    //
    return (vec1.x*vec2.x) + (vec1.y*vec2.y) + (vec1.z*vec2.z);
}
edk::float32 edk::Math::dotProduct(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 w1,
                                   edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 w2
                                   ){
    return edk::Math::dotProduct(edk::vec4f32(x1,y1,z1,w1),edk::vec4f32(x2,y2,z2,w2));
}
edk::float32 edk::Math::dotProduct(edk::vec4f32 vec1,edk::vec4f32 vec2){
    //
    return (vec1.x*vec2.x) + (vec1.y*vec2.y) + (vec1.z*vec2.z) + (vec1.w*vec2.w);
}

//CROSS PRODUCT (calculate the normal of 2 vectors)
edk::vec3f32 edk::Math::crossProduct(edk::float32 x1,
                                     edk::float32 y1,
                                     edk::float32 z1,
                                     edk::float32 x2,
                                     edk::float32 y2,
                                     edk::float32 z2
                                     ){
    return edk::Math::crossProduct(edk::vec3f32(x1,y1,z1),edk::vec3f32(x2,y2,z2));
}
edk::vec3f32 edk::Math::crossProduct(edk::vec3f32 vec1,edk::vec3f32 vec2){
    edk::vec3f32 ret;

    ret.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
    ret.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
    ret.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);

    return ret;
}

//The square function return the square of the number
edk::float32 edk::Math::square(edk::float32 n){ return n*n;  }
edk::float32 edk::Math::square(edk::float64 n){ return n*n;  }
edk::int8 edk::Math::square(edk::int8 n){ return n*n;  }
edk::int16 edk::Math::square(edk::int16 n){ return n*n;  }
edk::int32 edk::Math::square(edk::int32 n){ return n*n;  }
edk::int64 edk::Math::square(edk::int64 n){ return n*n;  }
edk::uint8 edk::Math::square(edk::uint8 n){ return n*n;  }
edk::uint16 edk::Math::square(edk::uint16 n){ return n*n;  }
edk::uint32 edk::Math::square(edk::uint32 n){ return n*n;  }
edk::uint64 edk::Math::square(edk::uint64 n){ return n*n;  }
//VEC2
edk::vec2f32 edk::Math::square(edk::float32 n1,edk::float32 n2){ return edk::Math::square(edk::vec2f32(n1,n2));  }
edk::vec2f32 edk::Math::square(edk::vec2f32 vec){ return vec*vec;  }
edk::vec2i8 edk::Math::square(edk::int8 n1, edk::int8 n2){ return edk::Math::square(edk::vec2i8(n1,n2));  }
edk::vec2i8 edk::Math::square(edk::vec2i8 vec){ return vec*vec;  }
edk::vec2i16 edk::Math::square(edk::int16 n1,edk::int16 n2){ return edk::Math::square(edk::vec2i16(n1,n2));  }
edk::vec2i16 edk::Math::square(edk::vec2i16 vec){ return vec*vec;  }
edk::vec2i32 edk::Math::square(edk::int32 n1,edk::int32 n2){ return edk::Math::square(edk::vec2i32(n1,n2));  }
edk::vec2i32 edk::Math::square(edk::vec2i32 vec){ return vec*vec;  }
edk::vec2i64 edk::Math::square(edk::int64 n1,edk::int64 n2){ return edk::Math::square(edk::vec2i64(n1,n2));  }
edk::vec2i64 edk::Math::square(edk::vec2i64 vec){ return vec*vec;  }
edk::vec2ui8 edk::Math::square(edk::uint8 n1,edk::uint8 n2){ return edk::Math::square(edk::vec2ui8(n1,n2));  }
edk::vec2ui8 edk::Math::square(edk::vec2ui8 vec){ return vec*vec;  }
edk::vec2ui16 edk::Math::square(edk::uint16 n1,edk::uint16 n2){ return edk::Math::square(edk::vec2ui16(n1,n2));  }
edk::vec2ui16 edk::Math::square(edk::vec2ui16 vec){ return vec*vec;  }
edk::vec2ui32 edk::Math::square(edk::uint32 n1,edk::uint32 n2){ return edk::Math::square(edk::vec2ui32(n1,n2));  }
edk::vec2ui32 edk::Math::square(edk::vec2ui32 vec){ return vec*vec;  }
edk::vec2ui64 edk::Math::square(edk::uint64 n1,edk::uint64 n2){ return edk::Math::square(edk::vec2ui64(n1,n2));  }
edk::vec2ui64 edk::Math::square(edk::vec2ui64 vec){ return vec*vec;  }
//VEC3
edk::vec3f32 edk::Math::square(edk::float32 n1,edk::float32 n2,edk::float32 n3){ return edk::Math::square(edk::vec3f32(n1,n2,n3));  }
edk::vec3f32 edk::Math::square(edk::vec3f32 vec){ return vec*vec;  }
edk::vec3i8 edk::Math::square(edk::int8 n1,edk::int8 n2,edk::int8 n3){ return edk::Math::square(edk::vec3i8(n1,n2,n3));  }
edk::vec3i8 edk::Math::square(edk::vec3i8 vec){ return vec*vec;  }
edk::vec3i16 edk::Math::square(edk::int16 n1,edk::int16 n2,edk::int16 n3){ return edk::Math::square(edk::vec3i16(n1,n2,n3));  }
edk::vec3i16 edk::Math::square(edk::vec3i16 vec){ return vec*vec;  }
edk::vec3i32 edk::Math::square(edk::int32 n1,edk::int32 n2,edk::int32 n3){ return edk::Math::square(edk::vec3i32(n1,n2,n3));  }
edk::vec3i32 edk::Math::square(edk::vec3i32 vec){ return vec*vec;  }
edk::vec3i64 edk::Math::square(edk::int64 n1,edk::int64 n2,edk::int64 n3){ return edk::Math::square(edk::vec3i64(n1,n2,n3));  }
edk::vec3i64 edk::Math::square(edk::vec3i64 vec){ return vec*vec;  }
edk::vec3ui8 edk::Math::square(edk::uint8 n1,edk::uint8 n2,edk::uint8 n3){ return edk::Math::square(edk::vec3ui8(n1,n2,n3));  }
edk::vec3ui8 edk::Math::square(edk::vec3ui8 vec){ return vec*vec;  }
edk::vec3ui16 edk::Math::square(edk::uint16 n1,edk::uint16 n2,edk::uint16 n3){ return edk::Math::square(edk::vec3ui16(n1,n2,n3));  }
edk::vec3ui16 edk::Math::square(edk::vec3ui16 vec){ return vec*vec;  }
edk::vec3ui32 edk::Math::square(edk::uint32 n1,edk::uint32 n2,edk::uint32 n3){ return edk::Math::square(edk::vec3ui32(n1,n2,n3));  }
edk::vec3ui32 edk::Math::square(edk::vec3ui32 vec){ return vec*vec;  }
edk::vec3ui64 edk::Math::square(edk::uint64 n1,edk::uint64 n2,edk::uint64 n3){ return edk::Math::square(edk::vec3ui64(n1,n2,n3));  }
edk::vec3ui64 edk::Math::square(edk::vec3ui64 vec){ return vec*vec;  }
//VEC4
edk::vec4f32 edk::Math::square(edk::float32 n1,edk::float32 n2,edk::float32 n3,edk::float32 n4){ return edk::Math::square(edk::vec4f32(n1,n2,n3,n4));  }
edk::vec4f32 edk::Math::square(edk::vec4f32 vec){ return vec*vec;  }
edk::vec4i8 edk::Math::square(edk::int8 n1,edk::int8 n2,edk::int8 n3,edk::int8 n4){ return edk::Math::square(edk::vec4i8(n1,n2,n3,n4));  }
edk::vec4i8 edk::Math::square(edk::vec4i8 vec){ return vec*vec;  }
edk::vec4i16 edk::Math::square(edk::int16 n1,edk::int16 n2,edk::int16 n3,edk::int16 n4){ return edk::Math::square(edk::vec4i16(n1,n2,n3,n4));  }
edk::vec4i16 edk::Math::square(edk::vec4i16 vec){ return vec*vec;  }
edk::vec4i32 edk::Math::square(edk::int32 n1,edk::int32 n2,edk::int32 n3,edk::int32 n4){ return edk::Math::square(edk::vec4i32(n1,n2,n3,n4));  }
edk::vec4i32 edk::Math::square(edk::vec4i32 vec){ return vec*vec;  }
edk::vec4i64 edk::Math::square(edk::int64 n1,edk::int64 n2,edk::int64 n3,edk::int64 n4){ return edk::Math::square(edk::vec4i64(n1,n2,n3,n4));  }
edk::vec4i64 edk::Math::square(edk::vec4i64 vec){ return vec*vec;  }
edk::vec4ui8 edk::Math::square(edk::uint8 n1,edk::uint8 n2,edk::uint8 n3,edk::uint8 n4){ return edk::Math::square(edk::vec4ui8(n1,n2,n3,n4));  }
edk::vec4ui8 edk::Math::square(edk::vec4ui8 vec){ return vec*vec;  }
edk::vec4ui16 edk::Math::square(edk::uint16 n1,edk::uint16 n2,edk::uint16 n3,edk::uint16 n4){ return edk::Math::square(edk::vec4ui16(n1,n2,n3,n4));  }
edk::vec4ui16 edk::Math::square(edk::vec4ui16 vec){ return vec*vec;  }
edk::vec4ui32 edk::Math::square(edk::uint32 n1,edk::uint32 n2,edk::uint32 n3,edk::uint32 n4){ return edk::Math::square(edk::vec4ui32(n1,n2,n3,n4));  }
edk::vec4ui32 edk::Math::square(edk::vec4ui32 vec){ return vec*vec;  }
edk::vec4ui64 edk::Math::square(edk::uint64 n1,edk::uint64 n2,edk::uint64 n3,edk::uint64 n4){ return edk::Math::square(edk::vec4ui64(n1,n2,n3,n4));  }
edk::vec4ui64 edk::Math::square(edk::vec4ui64 vec){ return vec*vec;  }

//MODULE OF A NUMBER
edk::float32 edk::Math::module(edk::float32 n){
    if(n<0.f){
        return n*-1.f;
    }
    else{
        return n;
    }
}
edk::int8 edk::Math::module(edk::int8 n){
    if(n<0){
        return n*-1;
    }
    else{
        return n;
    }
}
edk::int16 edk::Math::module(edk::int16 n){
    if(n<0){
        return n*-1;
    }
    else{
        return n;
    }
}
edk::int32 edk::Math::module(edk::int32 n){
    if(n<0){
        return n*-1;
    }
    else{
        return n;
    }
}
edk::int64 edk::Math::module(edk::int64 n){
    if(n<0){
        return n*-1;
    }
    else{
        return n;
    }
}
//VEC2
edk::vec2f32 edk::Math::module(edk::float32 n1,edk::float32 n2){return edk::Math::module(edk::vec2f32(n1,n2)); }
edk::vec2f32 edk::Math::module(edk::vec2f32 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec2i8 edk::Math::module(edk::int8 n1,edk::int8 n2){return edk::Math::module(edk::vec2i8(n1,n2)); }
edk::vec2i8 edk::Math::module(edk::vec2i8 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec2i16 edk::Math::module(edk::int16 n1,edk::int16 n2){return edk::Math::module(edk::vec2i16(n1,n2)); }
edk::vec2i16 edk::Math::module(edk::vec2i16 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec2i32 edk::Math::module(edk::int32 n1,edk::int32 n2){return edk::Math::module(edk::vec2i32(n1,n2)); }
edk::vec2i32 edk::Math::module(edk::vec2i32 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec2i64 edk::Math::module(edk::int64 n1,edk::int64 n2){return edk::Math::module(edk::vec2i64(n1,n2)); }
edk::vec2i64 edk::Math::module(edk::vec2i64 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
//VEC3
edk::vec3f32 edk::Math::module(edk::float32 n1,edk::float32 n2,edk::float32 n3){return edk::Math::module(edk::vec3f32(n1,n2,n3)); }
edk::vec3f32 edk::Math::module(edk::vec3f32 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec3i8 edk::Math::module(edk::int8 n1,edk::int8 n2,edk::int8 n3){return edk::Math::module(edk::vec3i8(n1,n2,n3)); }
edk::vec3i8 edk::Math::module(edk::vec3i8 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec3i16 edk::Math::module(edk::int16 n1,edk::int16 n2,edk::int16 n3){return edk::Math::module(edk::vec3i16(n1,n2,n3)); }
edk::vec3i16 edk::Math::module(edk::vec3i16 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec3i32 edk::Math::module(edk::int32 n1,edk::int32 n2,edk::int32 n3){return edk::Math::module(edk::vec3i32(n1,n2,n3)); }
edk::vec3i32 edk::Math::module(edk::vec3i32 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec3i64 edk::Math::module(edk::int64 n1,edk::int64 n2,edk::int64 n3){return edk::Math::module(edk::vec3i64(n1,n2,n3)); }
edk::vec3i64 edk::Math::module(edk::vec3i64 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
//VEC4
edk::vec4f32 edk::Math::module(edk::float32 n1,edk::float32 n2,edk::float32 n3,edk::float32 n4){return edk::Math::module(edk::vec4f32(n1,n2,n3,n4)); }
edk::vec4f32 edk::Math::module(edk::vec4f32 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec4i8 edk::Math::module(edk::int8 n1,edk::int8 n2,edk::int8 n3,edk::int8 n4){return edk::Math::module(edk::vec4i8(n1,n2,n3,n4)); }
edk::vec4i8 edk::Math::module(edk::vec4i8 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec4i16 edk::Math::module(edk::int16 n1,edk::int16 n2,edk::int16 n3,edk::int16 n4){return edk::Math::module(edk::vec4i16(n1,n2,n3,n4)); }
edk::vec4i16 edk::Math::module(edk::vec4i16 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec4i32 edk::Math::module(edk::int32 n1,edk::int32 n2,edk::int32 n3,edk::int32 n4){return edk::Math::module(edk::vec4i32(n1,n2,n3,n4)); }
edk::vec4i32 edk::Math::module(edk::vec4i32 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }
edk::vec4i64 edk::Math::module(edk::int64 n1,edk::int64 n2,edk::int64 n3,edk::int64 n4){return edk::Math::module(edk::vec4i64(n1,n2,n3,n4)); }
edk::vec4i64 edk::Math::module(edk::vec4i64 vec){vec.x=edk::Math::module(vec.x); vec.y=edk::Math::module(vec.y);  return vec; }

//Function pythagoras return de distance from 0,0,0 axis to X Y Z W
//FLOAT32
edk::float32 edk::Math::pythagoras(edk::float32 x,edk::float32 y){return edk::Math::pythagoras(edk::vec2f32(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2f32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::float32 x,edk::float32 y,edk::float32 z){return edk::Math::pythagoras(edk::vec3f32(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3f32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::float32 x,edk::float32 y,edk::float32 z, edk::float32 w){return edk::Math::pythagoras(edk::vec4f32(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4f32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//FLOAT64
edk::float64 edk::Math::pythagoras(edk::float64 x,edk::float64 y){return edk::Math::pythagoras(edk::vec2f64(x,y)); }
edk::float64 edk::Math::pythagoras(edk::vec2f64 vec){return (edk::float64)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float64 edk::Math::pythagoras(edk::float64 x,edk::float64 y,edk::float64 z){return edk::Math::pythagoras(edk::vec3f64(x,y,z)); }
edk::float64 edk::Math::pythagoras(edk::vec3f64 vec){return (edk::float64)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)); }
edk::float64 edk::Math::pythagoras(edk::float64 x,edk::float64 y,edk::float64 z, edk::float64 w){return edk::Math::pythagoras(edk::vec4f64(x,y,z,w)); }
edk::float64 edk::Math::pythagoras(edk::vec4f64 vec){return (edk::float64)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//INT8
edk::float32 edk::Math::pythagoras(edk::int8 x,edk::int8 y){return edk::Math::pythagoras(edk::vec2i8(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2i8 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::int8 x,edk::int8 y,edk::int8 z){return edk::Math::pythagoras(edk::vec3i8(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3i8 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                               edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::int8 x,edk::int8 y,edk::int8 z, edk::int8 w){return edk::Math::pythagoras(edk::vec4i8(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4i8 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                               edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//INT16
edk::float32 edk::Math::pythagoras(edk::int16 x,edk::int16 y){return edk::Math::pythagoras(edk::vec2i16(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2i16 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::int16 x,edk::int16 y,edk::int16 z){return edk::Math::pythagoras(edk::vec3i16(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3i16 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::int16 x,edk::int16 y,edk::int16 z, edk::int16 w){return edk::Math::pythagoras(edk::vec4i16(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4i16 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//INT32
edk::float32 edk::Math::pythagoras(edk::int32 x,edk::int32 y){return edk::Math::pythagoras(edk::vec2i32(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2i32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::int32 x,edk::int32 y,edk::int32 z){return edk::Math::pythagoras(edk::vec3i32(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3i32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::int32 x,edk::int32 y,edk::int32 z, edk::int32 w){return edk::Math::pythagoras(edk::vec4i32(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4i32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//INT64
edk::float32 edk::Math::pythagoras(edk::int64 x,edk::int64 y){return edk::Math::pythagoras(edk::vec2i64(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2i64 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::int64 x,edk::int64 y,edk::int64 z){return edk::Math::pythagoras(edk::vec3i64(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3i64 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::int64 x,edk::int64 y,edk::int64 z, edk::int64 w){return edk::Math::pythagoras(edk::vec4i64(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4i64 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//UINT8
edk::float32 edk::Math::pythagoras(edk::uint8 x,edk::uint8 y){return edk::Math::pythagoras(edk::vec2ui8(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2ui8 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::uint8 x,edk::uint8 y,edk::uint8 z){return edk::Math::pythagoras(edk::vec3ui8(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3ui8 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::uint8 x,edk::uint8 y,edk::uint8 z, edk::uint8 w){return edk::Math::pythagoras(edk::vec4ui8(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4ui8 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//UINT16
edk::float32 edk::Math::pythagoras(edk::uint16 x,edk::uint16 y){return edk::Math::pythagoras(edk::vec2ui16(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2ui16 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::uint16 x,edk::uint16 y,edk::uint16 z){return edk::Math::pythagoras(edk::vec3ui16(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3ui16 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                 edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::uint16 x,edk::uint16 y,edk::uint16 z, edk::uint16 w){return edk::Math::pythagoras(edk::vec4ui16(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4ui16 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                 edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//UINT32
edk::float32 edk::Math::pythagoras(edk::uint32 x,edk::uint32 y){return edk::Math::pythagoras(edk::vec2ui32(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2ui32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::uint32 x,edk::uint32 y,edk::uint32 z){return edk::Math::pythagoras(edk::vec3ui32(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3ui32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                 edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::uint32 x,edk::uint32 y,edk::uint32 z, edk::uint32 w){return edk::Math::pythagoras(edk::vec4ui32(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4ui32 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                 edk::Math::square(vec.z)+edk::Math::square(vec.w)); }
//UINT64
edk::float32 edk::Math::pythagoras(edk::uint64 x,edk::uint64 y){return edk::Math::pythagoras(edk::vec2ui64(x,y)); }
edk::float32 edk::Math::pythagoras(edk::vec2ui64 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)); }
edk::float32 edk::Math::pythagoras(edk::uint64 x,edk::uint64 y,edk::uint64 z){return edk::Math::pythagoras(edk::vec3ui64(x,y,z)); }
edk::float32 edk::Math::pythagoras(edk::vec3ui64 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                 edk::Math::square(vec.z)); }
edk::float32 edk::Math::pythagoras(edk::uint64 x,edk::uint64 y,edk::uint64 z, edk::uint64 w){return edk::Math::pythagoras(edk::vec4ui64(x,y,z,w)); }
edk::float32 edk::Math::pythagoras(edk::vec4ui64 vec){return (edk::float32)edk::Math::squareRoot(edk::Math::square(vec.x)+edk::Math::square(vec.y)+
                                                                                                 edk::Math::square(vec.z)+edk::Math::square(vec.w)); }

//Return sin and cosin of angle.
edk::float32 edk::Math::getSin(edk::float32 angle){
    if(angle == 180){
        return 0;
    }
    else{
        return sin(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getCosin(edk::float32 angle){
    if(angle == 90 || angle == 270){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getSin(edk::int8 angle){
    return sin((angle*PI)/180.f);
}
edk::float32 edk::Math::getCosin(edk::int8 angle){
    if(angle == 90){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getSin(edk::int16 angle){
    if(angle == 180){
        return 0;
    }
    else{
        return sin(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getCosin(edk::int16 angle){
    if(angle == 90 || angle == 270){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getSin(edk::int32 angle){
    if(angle == 180){
        return 0;
    }
    else{
        return sin((angle*PI)/180.f);
    }
}
edk::float32 edk::Math::getCosin(edk::int32 angle){
    if(angle == 90 || angle == 270){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getSin(edk::int64 angle){
    if(angle == 180){
        return 0;
    }
    else{
        return sin(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getCosin(edk::int64 angle){
    if(angle == 90 || angle == 270){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getSin(edk::uint8 angle){
    if(angle == 180){
        return 0;
    }
    else{
        return sin(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getCosin(edk::uint8 angle){
    if(angle == 90){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getSin(edk::uint16 angle){
    if(angle == 180){
        return 0;
    }
    else{
        return sin(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getCosin(edk::uint16 angle){
    if(angle == 90 || angle == 270){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getSin(edk::uint32 angle){
    if(angle == 180){
        return 0;
    }
    else{
        return sin(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getCosin(edk::uint32 angle){
    if(angle == 90 || angle == 270){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getSin(edk::uint64 angle){
    if(angle == 180){
        return 0;
    }
    else{
        return sin(angle*PI/180.f);
    }
}
edk::float32 edk::Math::getCosin(edk::uint64 angle){
    if(angle == 90 || angle == 270){
        return 0;
    }
    else{
        return cos(angle*PI/180.f);
    }
}

//Return asin and acosin of angle.
//edk::float32 edk::Math::arcSin(edk::float32 radius,edk::float32 y){if(radius==0)radius=0.000001f; return edk::Math::arcSin((edk::float32)y/radius); }
//edk::float32 edk::Math::arcCosin(edk::float32 radius,edk::float32 x){if(radius==0)radius=0.000001f; return edk::Math::arcCosin((edk::float32)x/radius); }
edk::float32 edk::Math::arcSin(edk::float32 radius,edk::float32 y){
    if(radius==0){
        radius=0.000001f;
    }
    return asin((edk::float32)y/radius)* 180.f / PI;
}
edk::float32 edk::Math::arcSin(edk::float32 y){return asin(y)* 180.f / PI; }
edk::float32 edk::Math::arcCosin(edk::float32 radius,edk::float32 x){
    if(radius==0){
        radius=0.000001f;
    }
    return acos((edk::float32)x/radius)* 180.f / PI;
}
edk::float32 edk::Math::arcCosin(edk::float32 x){return acos((edk::float32)x)* 180.f / PI; }

//return the 2D angle
edk::float32 edk::Math::getAngle(edk::float32 x,edk::float32 y){
    //
    return edk::Math::getAngle(edk::vec2f32(x,y));
}
edk::float32 edk::Math::getAngle(edk::vec2f32 vec){
    //
    vec=edk::Math::normalise(vec);
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
edk::float32 edk::Math::getAngleX(edk::float32 x,edk::float32 y,edk::float32 z){
    return getAngleX(edk::vec3f32(x,y,z));
}
edk::float32 edk::Math::getAngleX(edk::vec3f32 vec){
    return edk::Math::getAngle(edk::vec2f32(vec.y,vec.z));
}
edk::float32 edk::Math::getAngleY(edk::float32 x,edk::float32 y,edk::float32 z){
    return getAngleY(edk::vec3f32(x,y,z));
}
edk::float32 edk::Math::getAngleY(edk::vec3f32 vec){
    return edk::Math::getAngle(edk::vec2f32(vec.x,vec.z));
}
edk::float32 edk::Math::getAngleZ(edk::float32 x,edk::float32 y,edk::float32 z){
    return getAngleZ(edk::vec3f32(x,y,z));
}
edk::float32 edk::Math::getAngleZ(edk::vec3f32 vec){
    return edk::Math::getAngle(edk::vec2f32(vec.x,vec.y));
}
//3 angles
edk::vec3f32 edk::Math::getAngleXYZ(edk::float32 x,edk::float32 y,edk::float32 z){
    return getAngleXYZ(edk::vec3f32(x,y,z));
}
edk::vec3f32 edk::Math::getAngleXYZ(edk::vec3f32 vec){
    edk::vec3f32 ret(edk::Math::getAngleX(vec),
                     edk::Math::getAngleY(vec),
                     edk::Math::getAngleZ(vec)
                     );
    return ret;
}
//Return the 2D Angle between 2 vectors
edk::float32 edk::Math::getAngleDistanceModule(edk::float32 x1,edk::float32 y1,
                                               edk::float32 x2,edk::float32 y2
                                               ){
    return edk::Math::getAngleDistanceModule(edk::vec2f32(x1,y1),edk::vec2f32(x2,y2));
}
edk::float32 edk::Math::getAngleDistanceModule(edk::vec2f32 vec1,edk::vec2f32 vec2){
    //
    if(vec1==vec2){
        return 0.f;
    }
    return edk::Math::arcCosin(( edk::Math::pythagoras(vec1) * edk::Math::pythagoras(vec2)),edk::Math::dotProduct(vec1,vec2));
}
edk::float32 edk::Math::getAngleDistanceModule(edk::float32 x1,edk::float32 y1,edk::float32 z1,
                                               edk::float32 x2,edk::float32 y2,edk::float32 z2
                                               ){
    return edk::Math::getAngleDistanceModule(edk::vec3f32(x1,y1,z1),edk::vec3f32(x2,y2,z2));
}
edk::float32 edk::Math::getAngleDistanceModule(edk::vec3f32 vec1,edk::vec3f32 vec2){
    //
    if(vec1==vec2){
        return 0.f;
    }
    return edk::Math::arcCosin(( edk::Math::pythagoras(vec1) * edk::Math::pythagoras(vec2)),edk::Math::dotProduct(vec1,vec2));
}
edk::float32 edk::Math::getAngleDistanceModule(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 w1,
                                               edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 w2
                                               ){
    return edk::Math::getAngleDistanceModule(edk::vec4f32(x1,y1,z1,w1),edk::vec4f32(x2,y2,z2,w2));
}
edk::float32 edk::Math::getAngleDistanceModule(edk::vec4f32 vec1,edk::vec4f32 vec2){
    //
    if(vec1==vec2){
        return 0.f;
    }
    return edk::Math::arcCosin(( edk::Math::pythagoras(vec1) * edk::Math::pythagoras(vec2)),edk::Math::dotProduct(vec1,vec2));
}

//RightHand to find if the point is on the right or left
edk::float32 edk::Math::getAngleDistance(edk::float32 x1,edk::float32 y1,
                                         edk::float32 x2,edk::float32 y2
                                         ){
    return edk::Math::getAngleDistance(edk::vec2f32(x1,y1),edk::vec2f32(x2,y2));
}
edk::float32 edk::Math::getAngleDistance(edk::vec2f32 vec1,edk::vec2f32 vec2){
    //fload the angles
    edk::float32 ret = edk::Math::getAngle(vec2) - edk::Math::getAngle(vec1);

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

//generate matrices
//2D
//translate matrix
bool edk::Math::generateTranslateMatrix(edk::vec2f32 position,edk::vector::Matrixf32<3u,3u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(2u,0u,position.x);
        dest->set(2u,1u,position.y);
        return true;
    }
    return false;
}
//rotate matrix
bool edk::Math::generateRotateMatrixX(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(1u,1u,edk::Math::getCosin(angle)); //cos
        dest->set(2u,1u,edk::Math::getSin(angle)*-1.f); //-sin
        dest->set(1u,2u,edk::Math::getSin(angle)); //sin
        dest->set(2u,2u,edk::Math::getCosin(angle)); //cos
        return true;
    }
    return false;
}
bool edk::Math::generateRotateMatrixY(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(0u,0u,edk::Math::getCosin(angle)); //cos
        dest->set(2u,0u,edk::Math::getSin(angle)); //sin
        dest->set(0u,2u,edk::Math::getSin(angle)*-1.f); //-sin
        dest->set(2u,2u,edk::Math::getCosin(angle)); //cos
        return true;
    }
    return false;
}
bool edk::Math::generateRotateMatrixZ(edk::float32 angle,edk::vector::Matrixf32<3u,3u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(0u,0u,edk::Math::getCosin(angle)); //cos
        dest->set(1u,0u,edk::Math::getSin(angle)*-1.f); //-sin
        dest->set(0u,1u,edk::Math::getSin(angle)); //sin
        dest->set(1u,1u,edk::Math::getCosin(angle)); //cos
        return true;
    }
    return false;
}
//scale matrix
bool edk::Math::generateScaleMatrix(edk::size2f32 size,edk::vector::Matrixf32<3u,3u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(0u,0u,size.width);
        dest->set(1u,1u,size.height);
        return true;
    }
    return false;
}
//3D
//translate matrix
bool edk::Math::generateTranslateMatrix(edk::vec3f32 position,edk::vector::Matrixf32<3u,3u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(2u,0u,position.x);
        dest->set(2u,1u,position.y);
        dest->set(2u,2u,position.z);
        return true;
    }
    return false;
}
bool edk::Math::generateTranslateMatrix(edk::vec3f32 position,edk::vector::Matrixf32<4u,4u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(3u,0u,position.x);
        dest->set(3u,1u,position.y);
        dest->set(3u,2u,position.z);
        return true;
    }
    return false;
}
//rotate matrix
bool edk::Math::generateRotateMatrixX(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(1u,1u,edk::Math::getCosin(angle)); //cos
        dest->set(2u,1u,edk::Math::getSin(angle)*-1.f); //-sin
        dest->set(1u,2u,edk::Math::getSin(angle)); //sin
        dest->set(2u,2u,edk::Math::getCosin(angle)); //cos
        return true;
    }
    return false;
}
bool edk::Math::generateRotateMatrixY(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(0u,0u,edk::Math::getCosin(angle)); //cos
        dest->set(2u,0u,edk::Math::getSin(angle)); //sin
        dest->set(0u,2u,edk::Math::getSin(angle)*-1.f); //-sin
        dest->set(2u,2u,edk::Math::getCosin(angle)); //cos
        return true;
    }
    return false;
}
bool edk::Math::generateRotateMatrixZ(edk::float32 angle,edk::vector::Matrixf32<4u,4u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(0u,0u,edk::Math::getCosin(angle)); //cos
        dest->set(1u,0u,edk::Math::getSin(angle)*-1.f); //-sin
        dest->set(0u,1u,edk::Math::getSin(angle)); //sin
        dest->set(1u,1u,edk::Math::getCosin(angle)); //cos
        return true;
    }
    return false;
}
//scale matrix
bool edk::Math::generateScaleMatrix(edk::size3f32 size,edk::vector::Matrixf32<3u,3u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(0u,0u,size.width);
        dest->set(1u,1u,size.height);
        dest->set(2u,2u,size.length);
        return true;
    }
    return false;
}
bool edk::Math::generateScaleMatrix(edk::size3f32 size,edk::vector::Matrixf32<4u,4u>* dest){
    if(dest){
        //clean the matrix
        dest->setIdentity(1.f,0.f);
        //set the values
        dest->set(0u,0u,size.width);
        dest->set(1u,1u,size.height);
        dest->set(2u,2u,size.length);
        return true;
    }
    return false;
}
//lookat matrix
bool edk::Math::generateLookAtMatrix(edk::vec3f32 position,edk::vec3f32 look,edk::vec3f32 up,edk::vector::Matrixf32<4u,4u>* dest){
    if(dest){
        /*
        edk::vec3f32 forward = look - position;
        forward = edk::Math::normalise(forward);
        edk::vec3f32 right = edk::Math::crossProduct(forward,up);
        right = edk::Math::normalise(right);
        edk::vec3f32 newUP = edk::Math::crossProduct(right,forward);

        //set the values
        dest->set(0u,0u,right.x);
        dest->set(0u,1u,right.y);
        dest->set(0u,2u,right.z);
        dest->set(0u,3u,0.f);
        //
        dest->set(1u,0u,newUP.x);
        dest->set(1u,1u,newUP.y);
        dest->set(1u,2u,newUP.z);
        dest->set(1u,3u,0.f);
        //
        dest->set(2u,0u,forward.x);
        dest->set(2u,1u,forward.y);
        dest->set(2u,2u,forward.z);
        dest->set(2u,3u,0.f);
        //
        dest->set(3u,0u,0.f);
        dest->set(3u,1u,0.f);
        dest->set(3u,2u,0.f);
        dest->set(3u,2u,1.f);
*/
        edk::vec3f32 f = look - position;
        f = edk::Math::normalise(f);

        edk::vec3f32 s = edk::Math::crossProduct(f,up);
        s = edk::Math::normalise(s);

        edk::vec3f32 u = edk::Math::crossProduct(s,f);
        //
        dest->set(0u,0u,s.x);
        dest->set(0u,1u,u.x);
        dest->set(0u,2u,-f.x);
        dest->set(0u,3u,0.f);
        //
        dest->set(1u,0u,s.y);
        dest->set(1u,1u,u.y);
        dest->set(1u,2u,-f.y);
        dest->set(1u,3u,0.f);
        //
        dest->set(2u,0u,s.z);
        dest->set(2u,1u,u.z);
        dest->set(2u,2u,-f.z);
        dest->set(2u,3u,0.f);
        //
        dest->set(3u,0u,-edk::Math::dotProduct(s,position));
        dest->set(3u,1u,-edk::Math::dotProduct(u,position));
        dest->set(3u,2u,edk::Math::dotProduct(f,position));
        dest->set(3u,3u,1.f);
        return true;
    }
    return false;
}
//perspective matrix
bool edk::Math::generatePerspectiveMatrix(edk::float32 fieldOfView,
                                          edk::float32 aspectRatio,
                                          edk::float32 nearPlane,
                                          edk::float32 farPlane,
                                          edk::vector::Matrixf32<4u,4u>* dest
                                          ){
    if(dest){
        edk::float32 tanHalfFovy = tan(fieldOfView / 2.f);
        //
        dest->set(0u,0u,1.f/(aspectRatio * tanHalfFovy));
        dest->set(0u,1u,0.f);
        dest->set(0u,2u,0.f);
        dest->set(0u,3u,0.f);
        //
        dest->set(1u,0u,0.f);
        dest->set(1u,1u,1.f/tanHalfFovy);
        dest->set(1u,2u,0.f);
        dest->set(1u,3u,0.f);
        //
        dest->set(2u,0u,0.f);
        dest->set(2u,1u,0.f);
        dest->set(2u,2u,-(farPlane+nearPlane)/(farPlane-nearPlane));
        dest->set(2u,3u,-1.f);
        //
        dest->set(3u,0u,0.f);
        dest->set(3u,1u,0.f);
        dest->set(3u,2u,-(farPlane * nearPlane) / (farPlane - nearPlane));
        dest->set(3u,3u,0.f);
        return true;
    }
    return false;
}
//ortho matrix
bool edk::Math::generateOrthoMatrix(edk::float32 left,
                                    edk::float32 right,
                                    edk::float32 bottom,
                                    edk::float32 top,
                                    edk::float32 zNear,
                                    edk::float32 zFar,
                                    edk::vector::Matrixf32<4u,4u>* dest
                                    ){
    if(dest){
        dest->set(0u,0u,2.f/(right-left));
        dest->set(0u,1u,0.f);
        dest->set(0u,2u,0.f);
        dest->set(0u,3u,0.f);
        //
        dest->set(1u,0u,0.f);
        dest->set(1u,1u,2.f/(top-bottom));
        dest->set(1u,2u,0.f);
        dest->set(1u,3u,0.f);
        //
        dest->set(2u,0u,0.f);
        dest->set(2u,1u,0.f);
        dest->set(2u,2u,2.f/(zFar-zNear));
        dest->set(2u,3u,0.f);
        //
        dest->set(3u,0u,-(right+left)/(right-left));
        dest->set(3u,1u,-(top+bottom)/(top-bottom));
        dest->set(3u,2u,-(zFar+zNear)/(zFar-zNear));
        dest->set(3u,3u,1.f);
        return true;
    }
    return false;
}

//Rotate de vector
edk::float32 edk::Math::rotateXAxis(edk::float32 radius, edk::float32 angle){
    //
    return edk::Math::getCosin(angle)*radius;
}
edk::float32 edk::Math::rotateYAxis(edk::float32 radius, edk::float32 angle){
    //
    return edk::Math::getSin(angle)*radius;
}
edk::vec2f32 edk::Math::rotate(edk::float32 x,edk::float32 y,edk::float32 angle){
    return edk::Math::rotate(edk::vec2f32(x,y),angle);
}
edk::vec2f32 edk::Math::rotate(edk::vec2f32 vec,edk::float32 angle){
    //get the radius of the vector
    edk::float32 radius = edk::Math::pythagoras(vec);
    return edk::vec2f32( edk::Math::rotateXAxis(radius,angle),edk::Math::rotateYAxis(radius,angle));
}
edk::vec2f32 edk::Math::rotatePlus(edk::float32 x,edk::float32 y,edk::float32 angle){
    return edk::Math::rotatePlus(edk::vec2f32(x,y),angle);
}
edk::vec2f32 edk::Math::rotatePlus(edk::vec2f32 vec,edk::float32 angle){
    //find the angle
    angle += edk::Math::getAngle(vec);
    //filter the angle
    if(angle>360.0){
        angle-=360.f;
    }
    if(angle<0){
        angle+=360.f;
    }
    //
    return edk::Math::rotate(vec,angle);
}
//rotate in all axes
edk::vec3f32 edk::Math::rotateX(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 angle){
    return edk::Math::rotateX(edk::vec3f32(x,y,z),angle);
}
edk::vec3f32 edk::Math::rotateX(edk::vec3f32 vec,edk::float32 angle){
    //get the radius of the vector
    edk::float32 radius = edk::Math::pythagoras(edk::vec2f32(vec.y,vec.z));
    return edk::vec3f32(vec.x,edk::Math::rotateYAxis(radius,angle),edk::Math::rotateXAxis(radius,angle));
}
edk::vec3f32 edk::Math::rotateY(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 angle){
    return edk::Math::rotateY(edk::vec3f32(x,y,z),angle);
}
edk::vec3f32 edk::Math::rotateY(edk::vec3f32 vec,edk::float32 angle){
    //get the radius of the vector
    edk::float32 radius = edk::Math::pythagoras(edk::vec2f32(vec.x,vec.z));
    return edk::vec3f32(edk::Math::rotateXAxis(radius,angle),vec.y,edk::Math::rotateYAxis(radius,angle));
}
edk::vec3f32 edk::Math::rotateZ(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 angle){
    return edk::Math::rotateZ(edk::vec3f32(x,y,z),angle);
}
edk::vec3f32 edk::Math::rotateZ(edk::vec3f32 vec,edk::float32 angle){
    //get the radius of the vector
    edk::float32 radius = edk::Math::pythagoras(edk::vec2f32(vec.x,vec.y));
    return edk::vec3f32(edk::Math::rotateXAxis(radius,angle),edk::Math::rotateYAxis(radius,angle),vec.z);
}
edk::vec3f32 edk::Math::rotateZY(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 angleX,edk::float32 angleY){
    return edk::Math::rotateZY(edk::vec3f32(x,y,z),angleX,angleY);
}
edk::vec3f32 edk::Math::rotateZY(edk::vec3f32 vec,edk::float32 angleZ,edk::float32 angleY){
    angleZ = edk::Math::mathNormalizeAngle(angleZ);
    angleY = edk::Math::mathNormalizeAngle(angleY);
    //get the radius of the vector
    vec = edk::Math::rotateZ(vec,angleZ);
    if(angleZ>=90.f && angleZ<270.f){
        angleY+=180.f;
    }
    return edk::Math::rotateY(vec,angleY);
}
edk::vec3f32 edk::Math::rotateXYZ(edk::float32 x,edk::float32 y,edk::float32 z,
                                         edk::float32 angleX,edk::float32 angleY,edk::float32 angleZ
                                         ){
    return edk::Math::rotateXYZ(edk::vec3f32(x,y,z),angleX,angleY,angleZ);
}
edk::vec3f32 edk::Math::rotateXYZ(edk::vec3f32 vec,
                                         edk::float32 angleX,edk::float32 angleY,edk::float32 angleZ
                                         ){

    edk::vector::Matrixf32<4u,4u> mat;
    edk::vector::Matrixf32<4u,4u> matTemp;
    edk::vector::MatrixDynamic<edk::float32> matPosition;
    matPosition.createMatrix(1u,4u);
    //X
    mat.setIdentity(1.f,0.f);
    edk::Math::generateRotateMatrix3DX(angleX,&matTemp);
    mat.multiplyMatrixWithThis(&matTemp);
    //Y
    mat.setIdentity(1.f,0.f);
    edk::Math::generateRotateMatrix3DY(angleY,&matTemp);
    mat.multiplyMatrixWithThis(&matTemp);
    //Z
    mat.setIdentity(1.f,0.f);
    edk::Math::generateRotateMatrix3DZ(angleZ,&matTemp);
    mat.multiplyMatrixWithThis(&matTemp);

    //calculate the new position
    matPosition.set(0u,0u,edk::Math::pythagoras(vec));
    matPosition.set(0u,1u,0.f);
    matPosition.set(0u,2u,0.f);
    matPosition.set(0u,3u,1.f);

    matPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&mat);

    vec.x = matPosition.get(0u,0u);
    vec.y = matPosition.get(0u,1u);
    vec.z = matPosition.get(0u,2u);

    return vec;
}
//rotatePlus in all axes
edk::vec3f32 edk::Math::rotatePlusX(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 angle){
    return edk::Math::rotatePlusX(edk::vec3f32(x,y,z),angle);
}
edk::vec3f32 edk::Math::rotatePlusX(edk::vec3f32 vec,edk::float32 angle){
    return edk::Math::rotateX(vec,angle + edk::Math::getAngle(vec.z,vec.y));
}
edk::vec3f32 edk::Math::rotatePlusY(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 angle){
    return edk::Math::rotatePlusY(edk::vec3f32(x,y,z),angle);
}
edk::vec3f32 edk::Math::rotatePlusY(edk::vec3f32 vec,edk::float32 angle){
    return edk::Math::rotateY(vec,angle + edk::Math::getAngle(vec.x,vec.z));
}
edk::vec3f32 edk::Math::rotatePlusZ(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 angle){
    return edk::Math::rotatePlusZ(edk::vec3f32(x,y,z),angle);
}
edk::vec3f32 edk::Math::rotatePlusZ(edk::vec3f32 vec,edk::float32 angle){
    return edk::Math::rotateZ(vec,angle + edk::Math::getAngle(vec.y,vec.y));
}
edk::vec3f32 edk::Math::rotatePlusXYZ(edk::float32 x,edk::float32 y,edk::float32 z,
                                     edk::float32 angleX,edk::float32 angleY,edk::float32 angleZ
                                     ){
    return edk::Math::rotatePlusXYZ(edk::vec3f32(x,y,z),angleX,angleY,angleZ);
}
edk::vec3f32 edk::Math::rotatePlusXYZ(edk::vec3f32 vec,
                                     edk::float32 angleX,edk::float32 angleY,edk::float32 angleZ
                                     ){
    edk::vector::Matrixf32<4u,4u> mat;
    edk::vector::Matrixf32<4u,4u> matTemp;
    edk::vector::MatrixDynamic<edk::float32> matPosition;
    matPosition.createMatrix(1u,4u);
    //X
    mat.setIdentity(1.f,0.f);
    edk::Math::generateRotateMatrix3DX(angleX,&matTemp);
    mat.multiplyMatrixWithThis(&matTemp);
    //Y
    mat.setIdentity(1.f,0.f);
    edk::Math::generateRotateMatrix3DY(angleY,&matTemp);
    mat.multiplyMatrixWithThis(&matTemp);
    //Z
    mat.setIdentity(1.f,0.f);
    edk::Math::generateRotateMatrix3DZ(angleZ,&matTemp);
    mat.multiplyMatrixWithThis(&matTemp);

    //calculate the new position
    matPosition.set(0u,0u,vec.x);
    matPosition.set(0u,1u,vec.y);
    matPosition.set(0u,2u,vec.z);
    matPosition.set(0u,3u,1.f);

    matPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&mat);

    vec.x = matPosition.get(0u,0u);
    vec.y = matPosition.get(0u,1u);
    vec.z = matPosition.get(0u,2u);

    return vec;
}

//Normal of the triangle
edk::vec3f32 edk::Math::normalTriangle(edk::float32 x1,edk::float32 y1,edk::float32 z1,
                                       edk::float32 x2,edk::float32 y2,edk::float32 z2,
                                       edk::float32 x3,edk::float32 y3,edk::float32 z3
                                       ){
    return edk::Math::normalTriangle(edk::vec3f32(x1,y1,z1),edk::vec3f32(x2,y2,z2),edk::vec3f32(x3,y3,z3));
}
edk::vec3f32 edk::Math::normalTriangle(edk::vec3f32 vec1,edk::vec3f32 vec2,edk::vec3f32 vec3){
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

    if(smaller.x>vec2.x){
        smaller.x=vec2.x;
    }
    if(smaller.y>vec2.y){
        smaller.y=vec2.y;
    }
    if(smaller.z>vec2.z){
        smaller.z=vec2.z;
    }

    if(smaller.x>vec3.x){
        smaller.x=vec3.x;
    }
    if(smaller.y>vec3.y){
        smaller.y=vec3.y;
    }
    if(smaller.z>vec3.z){
        smaller.z=vec3.z;
    }

    if(bigger.x<vec2.x){
        bigger.x=vec2.x;
    }
    if(bigger.y<vec2.y){
        bigger.y=vec2.y;
    }
    if(bigger.z<vec2.z){
        bigger.z=vec2.z;
    }

    if(bigger.x<vec3.x){
        bigger.x=vec3.x;
    }
    if(bigger.y<vec3.y){
        bigger.y=vec3.y;
    }
    if(bigger.z<vec3.z){
        bigger.z=vec3.z;
    }

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
    if(!len){
        len=0.0001;
    }
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
edk::float32 edk::Math::angleToRad(edk::float32 angle){
    //
    return (angle * PI) / 180.0f;
}
edk::float32 edk::Math::radToAngle(edk::float32 rad){
    //
    return (rad * 180.0f) / PI;
}

//fill a size inside a size
edk::rectf32 edk::Math::fitInside(edk::size2f32 fill,edk::size2f32 inside){
    edk::rectf32 ret;
    //test if te fill width is bigger then fill width
    if(fill.width > fill.height){
        //test if the size width s bigger or smaller
        if((fill.width / fill.height) > (inside.width / inside.height)){
            //resize using the height as ONE
            ret.size.height = fill.height;
            ret.size.width = fill.height *(inside.width / inside.height);
            ret.origin.x = ((fill.width - ret.size.width) * 0.5f);
        }
        else{
            //resize using the width as ONE
            ret.size.width = fill.width;
            ret.size.height = fill.width *(inside.height / inside.width);
            ret.origin.y = ((fill.height - ret.size.height) * 0.5f);
        }
    }
    else{
        //test if the size height s bigger or smaller
        if((fill.height / fill.width) > (inside.height / inside.width)){
            //resize using the width as ONE
            ret.size.width = fill.width;
            ret.size.height = fill.width *(inside.height / inside.width);
            ret.origin.y = ((fill.height - ret.size.height) * 0.5f);
        }
        else{
            //resize using the height as ONE
            ret.size.height = fill.height;
            ret.size.width = fill.height *(inside.width / inside.height);
            ret.origin.x = ((fill.width - ret.size.width) * 0.5f);
        }
    }
    return ret;
}
edk::rectf32 edk::Math::fitInside(edk::float32 fillWidth,edk::float32 fillHeight,
                                  edk::float32 insideWidth,edk::float32 insideHeight
                                  ){
    return edk::Math::fitInside(edk::size2f32(fillWidth,fillHeight),edk::size2f32(insideWidth,insideHeight));
}
//fill a rectangle inside another rectangle
edk::rectf32 edk::Math::fitInside(edk::rectf32 fill,edk::size2f32 inside){
    edk::rectf32 ret = fitInside(fill.size,inside);
    ret.origin+=fill.origin;
    return ret;
}
edk::rectf32 edk::Math::fitInside(edk::vec2f32 fillOrigin,edk::size2f32 fillSize,edk::size2f32 insideSize){
    return edk::Math::fitInside(edk::rectf32(fillOrigin,fillSize),insideSize);
}
edk::rectf32 edk::Math::fitInside(edk::float32 fillOriginX,edk::float32 fillOriginY,edk::float32 fillSizeWidth,edk::float32 fillSizewidth,
                                  edk::float32 insideSizeWidth,edk::float32 insideSizewidth
                                  ){
    return edk::Math::fitInside(edk::vec2f32(fillOriginX,fillOriginY),edk::size2f32(fillSizeWidth,fillSizewidth),
                                edk::size2f32(insideSizeWidth,insideSizewidth)
                                );
}
