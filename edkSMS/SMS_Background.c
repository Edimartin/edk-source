#include "SMS_CamScroll.h"

static struct vec2i32 map1,map2;
static struct CamScroll scroll;
static struct CamScrollNext ret;

void smsBackground_drawZeros(uint8 x,uint8 y,uint8 w,uint8 h){
    w+=x;
    h+=y;
#if !defined(__GNUC__) && !defined(__clang__)
    uint16 zero = 0u;
#endif
    for(;x<w;++x){
        for(;y<h;++y){
#if !defined(__GNUC__) && !defined(__clang__)
            SMS_loadTileMapArea(x, y,
                                &zero,
                                1, 1
                                );
#endif
        }
    }
}

void smsBackground_drawHorizontal(uint16* vec,uint8 x,uint8 y,uint8 sx,uint8 sy,uint8 w,uint16 mapWidth){
    uint8 i=0u;
    for(;i<w;++i){

#ifdef SMS_DEBUG
        posB+=sprintf(&buffer[posB], "[%u]",sx);
#endif

#if !defined(__GNUC__) && !defined(__clang__)
        SMS_loadTileMapArea (sx, sy,
                             mapVector_getPosition(vec,
                                                   x,y,
                                                   mapWidth
                                                   ),
                             1, 1
                             );
#endif
        sx++;
        if(sx>=EDK_SMS_BACKGROUND_WIDTH){
            sx=0u;
        }
        x++;
    }
}
void smsBackground_drawVertical(uint16* vec,uint8 x,uint8 y,uint8 sx,uint8 sy,uint8 h,uint16 mapWidth){
    uint8 i=0u;
    for(;i<h;++i){

#ifdef SMS_DEBUG
        posB+=sprintf(&buffer[posB], "[%u]",sy);
#endif

#if !defined(__GNUC__) && !defined(__clang__)
        SMS_loadTileMapArea (sx, sy,
                             mapVector_getPosition(vec,
                                                   x,y,
                                                   mapWidth
                                                   ),
                             1, 1
                             );
#endif
        sy++;
        if(sy>=EDK_SMS_BACKGROUND_HEIGHT2){
            sy=0u;
        }
        y++;
    }
}

void smsBackground_start(){
    map1.x = 0;
    map1.y = 0;
    //
    map2.x = EDK_SMS_BACKGROUND_WIDTH -1;
    map2.y = EDK_SMS_BACKGROUND_HEIGHT - 1;

    camScroll_start(&scroll);
}
void smsBackground_moveTo(uint16* vec,uint8 x,uint8 y,uint16 mapWidth){
    map1.x=x;
    map1.y=y;
    map2.x = map1.x + EDK_SMS_BACKGROUND_WIDTH -1;
    map2.y = map1.y + EDK_SMS_BACKGROUND_HEIGHT - 1;

    uint8 ny=0u;
    for(;ny<EDK_SMS_BACKGROUND_HEIGHT2;++ny){
#if !defined(__GNUC__) && !defined(__clang__)
        SMS_loadTileMapArea (0, ny,
                             mapVector_getPosition(vec,
                                                   x,y + ny,
                                                   mapWidth
                                                   ),
                             EDK_SMS_BACKGROUND_WIDTH, 1
                             );
#endif
    }
}

void smsBackground_update(){
    //update background
#if !defined(__GNUC__) && !defined(__clang__)
    SMS_setBGScrollX(scroll.position.x);
    SMS_setBGScrollY(scroll.position.y);
#endif
}

//MOVE CAMERA
void smsBackground_moveCameraUP(uint16* vec,uint16 value,uint16 mapWidth,uint16 mapHeight){
    ret.insert=0u;
    //test if can go up
    if(map1.y>0){
        camScroll_moveUP(&scroll,value,&ret);
        if(ret.insert == CAMSCROLL_INSERT_ADD_UP){
            map1.y--;
            if(map1.y>=0
                    && map1.y<mapHeight
                    ){
                uint8 newPos = map1.x;
                if(ret.positionH.x+1u<EDK_SMS_BACKGROUND_WIDTH){
                    newPos++;
                }
#ifdef SMS_DEBUG
                posB=0u;
                memset(buffer,0u,sizeof(buffer));
                posB+=sprintf(&buffer[posB], "[%u]drawHorizontal11(%d,%d,%d,%u)",__LINE__,
                              newPos,map1.y,
                              ret.positionH.x+1u, ret.positionH.y,
                              ret.size.x
                              );
#endif
                //READ FROM MAP
                smsBackground_drawHorizontal(vec,
                                             newPos,map1.y,
                                             ret.positionH.x+1u, ret.positionH.y,
                                             ret.size.x,
                                             mapWidth
                                             );
            }
            else{
                //READ ALL ZEROS
                smsBackground_drawZeros(ret.positionH.x, ret.positionH.y,ret.size.x,ret.size.y);
            }
        }
        else if(ret.insert == CAMSCROLL_INSERT_REMOVE_DOWN){
            map2.y--;
#ifdef SMS_DEBUG
            posB=0u;
            memset(buffer,0u,sizeof(buffer));
            posB+=sprintf(&buffer[posB], "[%u]move2Y(%d)",__LINE__,
                          map2.y
                          );
#endif
        }
    }
}
void smsBackground_moveCameraDOWN(uint16* vec,uint16 value,uint16 mapWidth,uint16 mapHeight){
    ret.insert=0u;
    //test if can go down
    if(map2.y<mapHeight-1u){
        camScroll_moveDOWN(&scroll,value,&ret);
        if(ret.insert == CAMSCROLL_INSERT_ADD_DOWN){
            map2.y++;
            if(map2.y>=0
                    && map2.y<mapHeight
                    ){
                uint8 newPos = map1.x;
                if(ret.positionH.x+1u<EDK_SMS_BACKGROUND_WIDTH){
                    newPos++;
                }
#ifdef SMS_DEBUG
                posB=0u;
                memset(buffer,0u,sizeof(buffer));
                posB+=sprintf(&buffer[posB], "[%u]drawHorizontal12(%d,%d,%d,%u)",__LINE__,
                              newPos,map2.y,
                              ret.positionH.x+1u, ret.positionH.y,
                              ret.size.x
                              );
#endif
                //READ FROM MAP
                smsBackground_drawHorizontal(vec,
                                             newPos,map2.y,
                                             ret.positionH.x+1u, ret.positionH.y,
                                             ret.size.x,
                                             mapWidth
                                             );
            }
            else{
                //READ ALL ZEROS
                smsBackground_drawZeros(ret.positionH.x, ret.positionH.y,ret.size.x,ret.size.y);
            }
        }
        else if(ret.insert == CAMSCROLL_INSERT_REMOVE_UP){
            map1.y++;
#ifdef SMS_DEBUG
            posB=0u;
            memset(buffer,0u,sizeof(buffer));
            posB+=sprintf(&buffer[posB], "[%u]move1Y(%d)",__LINE__,
                          map1.y
                          );
#endif
        }
    }
}
void smsBackground_moveCameraLEFT(uint16* vec,uint16 value,uint16 mapWidth,uint16 mapHeight){
    ret.insert=0u;
    //test if can go left
    if(map1.x>0){
        camScroll_moveLEFT(&scroll,value,&ret);
        if(ret.insert == CAMSCROLL_INSERT_ADD_LEFT){
            if(map1.x>=0
                    && map1.x<mapWidth
                    ){
#ifdef SMS_DEBUG
                posB=0u;
                memset(buffer,0u,sizeof(buffer));
                posB+=sprintf(&buffer[posB], "[%u]drawVertical11(%d,%d,%d,%u)",__LINE__,
                              map1.x,map1.y,
                              ret.positionV.x, ret.positionV.y,
                              ret.size.y
                              );
#endif
                //READ FROM MAP
                smsBackground_drawVertical(vec,
                                           map1.x,map1.y,
                                           ret.positionV.x, ret.positionV.y,
                                           ret.size.y,
                                           mapWidth
                                           );
            }
            else{
                //READ ALL ZEROS
                smsBackground_drawZeros(ret.positionH.x, ret.positionH.y,ret.size.x,ret.size.y);
            }
            map1.x--;
        }
        else if(ret.insert == CAMSCROLL_INSERT_REMOVE_RIGHT){
            map2.x--;
#ifdef SMS_DEBUG
            posB=0u;
            memset(buffer,0u,sizeof(buffer));
            posB+=sprintf(&buffer[posB], "[%u]move2X(%d)",__LINE__,
                          map2.x
                          );
#endif
        }
    }
}
void smsBackground_moveCameraRIGHT(uint16* vec,uint16 value,uint16 mapWidth,uint16 mapHeight){
    ret.insert=0u;
    //test if can go right
    if(map2.x<mapWidth-1){
        camScroll_moveRIGHT(&scroll,value,&ret);
        if(ret.insert == CAMSCROLL_INSERT_ADD_RIGHT){
            map2.x++;
            if(map2.x>=0
                    && map2.x<mapWidth
                    ){
#ifdef SMS_DEBUG
                posB=0u;
                memset(buffer,0u,sizeof(buffer));
                posB+=sprintf(&buffer[posB], "[%u]drawVertical21(%d,%d,%d,%u)",__LINE__,
                              map2.x,map1.y,
                              ret.positionV.x, ret.positionV.y,
                              ret.size.y
                              );
#endif
                //READ FROM MAP
                smsBackground_drawVertical(vec,
                                           map2.x,map1.y,
                                           ret.positionV.x, ret.positionV.y,
                                           ret.size.y,
                                           mapWidth
                                           );
            }
            else{
                //READ ALL ZEROS
                smsBackground_drawZeros(ret.positionH.x, ret.positionH.y,ret.size.x,ret.size.y);
            }
        }
        else if(ret.insert == CAMSCROLL_INSERT_REMOVE_LEFT){
            map1.x++;
#ifdef SMS_DEBUG
            posB=0u;
            memset(buffer,0u,sizeof(buffer));
            posB+=sprintf(&buffer[posB], "[%u]move1X(%d)",__LINE__,
                          map1.x
                          );
#endif
        }
    }
}
