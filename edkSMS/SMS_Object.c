#include "SMS_Object.h"

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
#pragma message "            Inside SMS_Object.c"
#endif

void obj_construct(struct Object* obj){
    obj->position.x=0;
    obj->position.y=0;
    obj->size.x=0u;
    obj->size.y=0u;
    obj->lenght=0;
    obj->vector=NULL;
    obj->tiles=NULL;
}
void obj_init(struct Object* obj,uint8 width,uint8 height,uint16* vector,int32 lenght){
    obj->vector = vector;
    obj->size.x = width;
    obj->size.y = height;
    obj->lenght = lenght;
}
uint16 obj_getWidthPixels(struct Object* obj){
    return obj->size.x*8u;
}
uint16 obj_getHeightPixels(struct Object* obj){
    return obj->size.y*8u;
}
void obj_draw(struct Object* obj,uint8 frame){
    obj->temp = mapVector_getPosition(obj->vector,0u,obj->size.y * frame,obj->size.x);
    //draw the tiles
    uint8 x,y=0u,i=0u;
    struct vec2i32 position;
    int16 temp = obj->position.x - (obj_getWidthPixels(obj)>>1u);
    position.y = obj->position.y - (obj_getHeightPixels(obj)>>1u);
    position.x = temp;
    for(;y<obj->size.y;++y){
        x=0u;
        position.x = temp;
        for(;x<obj->size.x;++x){
#if !defined(__GNUC__) && !defined(__clang__)
            SMS_addSpriteClipping(position.x,
                          position.y,
                          obj->temp[i]
                          );
#endif
            position.x+=8;
            i++;
        }
        position.y+=8;
    }
}
