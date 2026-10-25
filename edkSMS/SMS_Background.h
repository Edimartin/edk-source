#ifndef SMS_BACKGROUND_H
#define SMS_BACKGROUND_H

/*
Library C++ SMS_Background - Functions to draw tiles in SMS background.
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
#pragma message "Inside SMS_Background"
#endif

#ifdef printMessages
#pragma message "    Compiling SMS_Background"
#endif

#include "SMS_MapVector.h"
#include "SMS_CamScroll.h"

void smsBackground_drawZeros(uint8 x,uint8 y,uint8 w,uint8 h);
void smsBackground_drawHorizontal(uint16* vec,uint8 x,uint8 y,uint8 sx,uint8 sy,uint8 w,uint16 mapWidth);
void smsBackground_drawVertical(uint16* vec,uint8 x,uint8 y,uint8 sx,uint8 sy,uint8 h,uint16 mapWidth);

void smsBackground_start();
void smsBackground_moveTo(uint16* vec,uint8 x,uint8 y,uint16 mapWidth);

void smsBackground_update();

//MOVE CAMERA
void smsBackground_moveCameraUP(uint16* vec,uint16 value,uint16 mapWidth,uint16 mapHeight);
void smsBackground_moveCameraDOWN(uint16* vec,uint16 value,uint16 mapWidth,uint16 mapHeight);
void smsBackground_moveCameraLEFT(uint16* vec,uint16 value,uint16 mapWidth,uint16 mapHeight);
void smsBackground_moveCameraRIGHT(uint16* vec,uint16 value,uint16 mapWidth,uint16 mapHeight);

#endif // SMS_BACKGROUND_H
