#ifndef SMS_TILES_H
#define SMS_TILES_H

/*
Library C++ SMS_Tiles - EDK List of tiles to be draw in SMS.
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
#pragma message "Inside SMS_Tiles"
#endif

#ifdef printMessages
#pragma message "    Compiling SMS_Tiles"
#endif

#pragma once
#include "SMS_TypeVec2.h"
//#include "SMS_Debugger.h"

#define SMS_TILES_LENGHT 128u

//Tile
struct Tile{
    struct vec2i32 position;
    int16 id;
};

void tiles_clean(struct Tile* tile);
void tiles_cleanTiles();
void tiles_reset();
struct Tile* tiles_getPointerPosition(uint8 position);
void tiles_addTile(struct vec2i32 position,int16 id);
void tiles_drawFirst();
void tiles_drawLast();
void tiles_draw(bool even);
void tiles_drawLenght(bool even);
void tiles_drawLenghtAll();

#endif // SMS_TILES_H
