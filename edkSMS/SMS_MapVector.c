#include "SMS_MapVector.h"

uint16 mapVector_getPosition(uint16* vector,uint16 x,uint16 y,uint16 width){
    return &vector[x + (y*width)];
}
