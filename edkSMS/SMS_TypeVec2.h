#ifndef EDK_TYPEVEC2_H
#define EDK_TYPEVEC2_H

/*
Library C++ typeVec2 - 2D vectors used in Edk Game Engine
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
#pragma message "Inside TypesVec2"
#endif

#pragma once
#include "SMS_TypeVars.h"

#ifdef printMessages
#pragma message "    Compiling TypesVec2"
#endif

//vec2i8
struct vec2i8{
    int8 x,y;
};

static bool isEqual2i8(struct vec2i8* vec1,struct vec2i8* vec2){
    if(vec1->x == vec2->x && vec1->y == vec2->y)
        return true;
    return false;
}
static bool isBigger2i8(struct vec2i8* vec1,struct vec2i8* vec2){
    if(vec1->x > vec2->x)
        return true;
    else if(vec1->x == vec2->x && vec1->y > vec2->y
            )
        return true;
    return false;
}

//vec2i16
struct vec2i16{
    int16 x,y;
};

static bool isEqual2i16(struct vec2i16* vec1,struct vec2i16* vec2){
    if(vec1->x == vec2->x && vec1->y == vec2->y)
        return true;
    return false;
}
static bool isBigger2i16(struct vec2i16* vec1,struct vec2i16* vec2){
    if(vec1->x > vec2->x)
        return true;
    else if(vec1->x == vec2->x && vec1->y > vec2->y
            )
        return true;
    return false;
}

//vec2i32
struct vec2i32{
    int32 x,y;
};

static bool isEqual2i32(struct vec2i32* vec1,struct vec2i32* vec2){
    if(vec1->x == vec2->x && vec1->y == vec2->y)
        return true;
    return false;
}
static bool isBigger2i32(struct vec2i32* vec1,struct vec2i32* vec2){
    if(vec1->x > vec2->x)
        return true;
    else if(vec1->x == vec2->x && vec1->y > vec2->y
            )
        return true;
    return false;
}

//vec2ui8
struct vec2ui8{
    uint8 x,y;
};

static bool isEqual2ui8(struct vec2ui8* vec1,struct vec2ui8* vec2){
    if(vec1->x == vec2->x && vec1->y == vec2->y)
        return true;
    return false;
}
static bool isBigger2ui8(struct vec2ui8* vec1,struct vec2ui8* vec2){
    if(vec1->x > vec2->x)
        return true;
    else if(vec1->x == vec2->x && vec1->y > vec2->y
            )
        return true;
    return false;
}

//vec2ui16
struct vec2ui16{
    uint16 x,y;
};

static bool isEqual2ui16(struct vec2ui16* vec1,struct vec2ui16* vec2){
    if(vec1->x == vec2->x && vec1->y == vec2->y)
        return true;
    return false;
}
static bool isBigger2ui16(struct vec2ui16* vec1,struct vec2ui16* vec2){
    if(vec1->x > vec2->x)
        return true;
    else if(vec1->x == vec2->x && vec1->y > vec2->y
            )
        return true;
    return false;
}

//vec2ui32
struct vec2ui32{
    uint32 x,y;
};

static bool isEqual2ui32(struct vec2ui32* vec1,struct vec2ui32* vec2){
    if(vec1->x == vec2->x && vec1->y == vec2->y)
        return true;
    return false;
}
static bool isBigger2ui32(struct vec2ui32* vec1,struct vec2ui32* vec2){
    if(vec1->x > vec2->x)
        return true;
    else if(vec1->x == vec2->x && vec1->y > vec2->y
            )
        return true;
    return false;
}

#endif // TYPEVEC2_H
