#ifndef SMS_CAMSCROLL_H
#define SMS_CAMSCROLL_H

/*
Library C++ SMS_CamScroll - Functions to scroll the camera moving inside a map.
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
#pragma message "Inside SMS_CamScroll"
#endif

#ifdef printMessages
#pragma message "    Compiling SMS_CamScroll"
#endif

#pragma once
#include <stdio.h>
#include <stdbool.h>

#include "SMS_TypeVec2.h"

#define CAMSCROLL_INSERT_ADD_LEFT     0b00000001
#define CAMSCROLL_INSERT_ADD_RIGHT    0b00000010
#define CAMSCROLL_INSERT_ADD_UP       0b00000100
#define CAMSCROLL_INSERT_ADD_DOWN     0b00001000

#define CAMSCROLL_INSERT_REMOVE_LEFT  0b00010000
#define CAMSCROLL_INSERT_REMOVE_RIGHT 0b00100000
#define CAMSCROLL_INSERT_REMOVE_UP    0b01000000
#define CAMSCROLL_INSERT_REMOVE_DOWN  0b10000000

struct CamScroll{
    struct vec2i32 position;
    struct vec2i32 savePositionStart;
    struct vec2i32 savePositionEnd;
    struct vec2ui8 tileStart;
    struct vec2ui8 tileEnd;
    bool haveSwap;
};
struct CamScrollNext{
    struct vec2i32 positionH;
    struct vec2i32 positionV;
    struct vec2ui8 size;
    struct vec2ui8 tileEnd;
    uint8 insert;
};

//FUNCTIONS
void camScroll_start(struct CamScroll* scroll);
void camScroll_moveDOWN(struct CamScroll* scroll,uint16 value,struct CamScrollNext* ret);
void camScroll_moveUP(struct CamScroll* scroll,uint16 value,struct CamScrollNext* ret);
void camScroll_moveLEFT(struct CamScroll* scroll,uint16 value,struct CamScrollNext* ret);
void camScroll_moveRIGHT(struct CamScroll* scroll,uint16 value,struct CamScrollNext* ret);
void camScroll_print(struct CamScroll* scroll);

#endif // SMS_CAMSCROLL_H
