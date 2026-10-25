#include "SMS_CamScroll.h"

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
#pragma message "            Inside SMS_CamScroll.c"
#endif

#include <string.h>

//FUNCTIONS
void camScroll_start(struct CamScroll* scroll){
    scroll->position.x =
            scroll->position.y =
            scroll->savePositionStart.x =
            scroll->savePositionStart.y =
            scroll->savePositionEnd.x =
            scroll->savePositionEnd.y =
            0;
    //set the tile positions
    scroll->tileStart.x = 0u;
    scroll->tileStart.y = 0u;
    scroll->tileEnd.x = EDK_SMS_BACKGROUND_WIDTH-1u;
    scroll->tileEnd.y = EDK_SMS_BACKGROUND_HEIGHT-1u;
}
void camScroll_moveDOWN(struct CamScroll* scroll,uint16 value,struct CamScrollNext* ret){
    scroll->position.y+=value;

    while(scroll->position.y > (scroll->savePositionEnd.y)){
        //
        scroll->savePositionEnd.y+=8;
        //load the next line
        scroll->tileEnd.y++;
        if(scroll->tileEnd.y>=EDK_SMS_BACKGROUND_HEIGHT2){
            scroll->tileEnd.y=0u;
        }

        ret->positionH.x = scroll->tileStart.x;
        ret->positionH.y = scroll->tileEnd.y;
        ret->size.x = EDK_SMS_BACKGROUND_WIDTH;
        ret->size.y = 1u;
        ret->insert=CAMSCROLL_INSERT_ADD_DOWN;
    }

    //test if pass 8 tiles
    while(scroll->position.y >= (scroll->savePositionStart.y+8)){
        //move the saveTile
        scroll->savePositionStart.y+=8;

        //decrement the tile line
        scroll->tileStart.y++;
        if(scroll->tileStart.y>=EDK_SMS_BACKGROUND_HEIGHT2){
            scroll->tileStart.y=0u;
        }

        ret->insert=CAMSCROLL_INSERT_REMOVE_UP;
    }

    while(scroll->position.y >= EDK_SMS_SCREEN_HEIGHT2){
        scroll->position.y -= EDK_SMS_SCREEN_HEIGHT2;
        scroll->savePositionStart.y -= EDK_SMS_SCREEN_HEIGHT2;
        scroll->savePositionEnd.y -= EDK_SMS_SCREEN_HEIGHT2;
    }
}
void camScroll_moveUP(struct CamScroll* scroll,uint16 value,struct CamScrollNext* ret){
    scroll->position.y-=value;

    while(scroll->position.y < (scroll->savePositionStart.y)){
        //
        scroll->savePositionStart.y-=8;
        //load the next line
        if(scroll->tileStart.y<=0){
            scroll->tileStart.y=EDK_SMS_BACKGROUND_HEIGHT2;
        }
        scroll->tileStart.y--;
        /*
            printf("\nPUSH %u %u size %u %u"
                   ,scroll->tileStart.x
                   ,scroll->tileStart.y
                   ,EDK_SMS_BACKGROUND_WIDTH
                   ,1u
                   );fflush(stdout);
*/
        ret->positionH.x = scroll->tileStart.x;
        ret->positionH.y = scroll->tileStart.y;
        ret->size.x = EDK_SMS_BACKGROUND_WIDTH;
        ret->size.y = 1u;
        ret->insert=CAMSCROLL_INSERT_ADD_UP;
    }

    //test if pass 8 tiles
    while(scroll->position.y <= (scroll->savePositionEnd.y-8)){
        //move the saveTile
        scroll->savePositionEnd.y-=8;

        //decrement the tile line
        if(scroll->tileEnd.y<=0){
            scroll->tileEnd.y=EDK_SMS_BACKGROUND_HEIGHT2;
        }
        scroll->tileEnd.y--;

        ret->insert=CAMSCROLL_INSERT_REMOVE_DOWN;
    }

    if(scroll->position.y <= 0){
        scroll->position.y += EDK_SMS_SCREEN_HEIGHT2;
        scroll->savePositionStart.y += EDK_SMS_SCREEN_HEIGHT2;
        scroll->savePositionEnd.y += EDK_SMS_SCREEN_HEIGHT2;
    }
}
void camScroll_moveLEFT(struct CamScroll* scroll,uint16 value,struct CamScrollNext* ret){
    scroll->position.x+=value;

    while(scroll->position.x > (scroll->savePositionEnd.x)){
        //
        scroll->savePositionEnd.x+=8;

        ret->positionV.x = scroll->tileStart.x;
        ret->positionV.y = scroll->tileStart.y;
        ret->size.x = 1u;
        ret->size.y = EDK_SMS_BACKGROUND_HEIGHT2;
        ret->insert=CAMSCROLL_INSERT_ADD_LEFT;

        //load the next line
        if(scroll->tileStart.x<=0){
            scroll->tileStart.x=EDK_SMS_BACKGROUND_WIDTH;
        }
        scroll->tileStart.x--;
    }

    //test if pass 8 tiles
    while(scroll->position.x >= (scroll->savePositionStart.x+8)){
        //move the saveTile
        scroll->savePositionStart.x+=8;

        //decrement the tile line
        if(scroll->tileEnd.x<=0){
            scroll->tileEnd.x=EDK_SMS_BACKGROUND_WIDTH;
        }
        scroll->tileEnd.x--;

        ret->insert=CAMSCROLL_INSERT_REMOVE_RIGHT;
    }

    while(scroll->position.x >= EDK_SMS_SCREEN_WIDTH){
        scroll->position.x -= EDK_SMS_SCREEN_WIDTH;
        scroll->savePositionStart.x -= EDK_SMS_SCREEN_WIDTH;
        scroll->savePositionEnd.x -= EDK_SMS_SCREEN_WIDTH;
    }
}
void camScroll_moveRIGHT(struct CamScroll* scroll,uint16 value,struct CamScrollNext* ret){
    scroll->position.x-=value;

    while(scroll->position.x < (scroll->savePositionStart.x)){
        //
        scroll->savePositionStart.x-=8;
        //load the next line
        scroll->tileEnd.x++;
        if(scroll->tileEnd.x>=EDK_SMS_BACKGROUND_WIDTH){
            scroll->tileEnd.x=0u;
        }

        ret->positionV.x = scroll->tileEnd.x;
        ret->positionV.y = scroll->tileStart.y;
        ret->size.x = 1u;
        ret->size.y = EDK_SMS_BACKGROUND_HEIGHT2;
        ret->insert=CAMSCROLL_INSERT_ADD_RIGHT;
    }

    //test if pass 8 tiles
    while(scroll->position.x <= (scroll->savePositionEnd.x-8)){
        //move the saveTile
        scroll->savePositionEnd.x-=8;

        //decrement the tile line
        scroll->tileStart.x++;
        if(scroll->tileStart.x>=EDK_SMS_BACKGROUND_WIDTH){
            scroll->tileStart.x=0u;
        }

        ret->insert=CAMSCROLL_INSERT_REMOVE_LEFT;
    }

    if(scroll->position.x <= 0){
        scroll->position.x += EDK_SMS_SCREEN_WIDTH;
        scroll->savePositionStart.x += EDK_SMS_SCREEN_WIDTH;
        scroll->savePositionEnd.x += EDK_SMS_SCREEN_WIDTH;
    }
}
void camScroll_print(struct CamScroll* scroll){
    /*
    printf("\n");
    printf("\nposition[%d][%d]"
           ,scroll->position.x
           ,scroll->position.y
           );
    printf("\nsavePositionStart[%d][%d]"
           ,scroll->savePositionStart.x
           ,scroll->savePositionStart.y
           );
    printf("\nsavePositionEnd[%d][%d]"
           ,scroll->savePositionEnd.x
           ,scroll->savePositionEnd.y
           );
    printf("\ntileStart[%u][%u]"
           ,scroll->tileStart.x
           ,scroll->tileStart.y
           );
    printf("\ntileEnd[%u][%u]"
           ,scroll->tileEnd.x
           ,scroll->tileEnd.y
           );
    fflush(stdout);
*/
}
