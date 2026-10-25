#ifndef SMS_OBJECT_H
#define SMS_OBJECT_H

/*
Library C++ SMS_Object - EDK Object used in the SMS.
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
#pragma message "Inside SMS_Object"
#endif

#ifdef printMessages
#pragma message "    Compiling SMS_Object"
#endif

#pragma once
#include "SMS_TypeVec2.h"
#include "SMS_MapVector.h"
#include "SMS_Tiles.h"

//Tile
struct Object{
    struct vec2i32 position;
    struct vec2ui8 size;
    int32 lenght;
    uint16* vector;
    uint16* temp;
    struct Tile** tiles;
};

void obj_construct(struct Object* obj);
void obj_init(struct Object* obj,uint8 width,uint8 height,uint16* vector,int32 lenght);
uint16 obj_getWidthPixels(struct Object* obj);
uint16 obj_getHeightPixels(struct Object* obj);
void obj_draw(struct Object* obj,uint8 frame);


#endif // SMS_OBJECT_H
