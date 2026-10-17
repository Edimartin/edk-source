#ifndef SMS_CAMSCROLL_H
#define SMS_CAMSCROLL_H

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
