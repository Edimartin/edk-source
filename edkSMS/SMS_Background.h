#ifndef SMS_BACKGROUND_H
#define SMS_BACKGROUND_H

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
