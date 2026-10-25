#include "SMS_Tiles.h"

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
#pragma message "            Inside SMS_Tiles.c"
#endif

static struct Tile tiles[SMS_TILES_LENGHT];
static uint8 lenghtTiles = 0u;

void tiles_clean(struct Tile* tile){
    tile->position.x = 0;
    tile->position.y = 0;
    tile->id = -1;
}
void tiles_cleanTiles(){
    uint8 i=0u;
    for(;i<SMS_TILES_LENGHT;++i){
        tiles_clean(&tiles[i]);
    }
    lenghtTiles = 0u;
}
struct Tile* tiles_getPointerPosition(uint8 position){
    if(position<SMS_TILES_LENGHT){
        return &tiles[position];
    }
    return NULL;
}
void tiles_drawFirst(){
    uint8 i=0u;
    uint8 size = (SMS_TILES_LENGHT>>1u);
    for(;i<size;++i){
#if !defined(__GNUC__) && !defined(__clang__)
        SMS_addSpriteClipping(tiles[i].position.x,
                              tiles[i].position.y,
                              tiles[i].id
                              );
#endif
    }
}
void tiles_drawLast(){
    uint8 i=(SMS_TILES_LENGHT>>1u);
    uint8 size = SMS_TILES_LENGHT;
    for(;i<size;++i){
#if !defined(__GNUC__) && !defined(__clang__)
        SMS_addSpriteClipping(tiles[i].position.x,
                              tiles[i].position.y,
                              tiles[i].id
                              );
#endif
    }
}
void tiles_draw(bool even){
    uint8 i=0u;
    uint8 size = SMS_TILES_LENGHT;
    if(even){
        for(;i<size;i+=2u){
#if !defined(__GNUC__) && !defined(__clang__)
            SMS_addSpriteClipping(tiles[i].position.x,
                                  tiles[i].position.y,
                                  tiles[i].id
                                  );
#endif
        }
    }
    else{
        i=1u;
        for(;i<size;i+=2u){
#if !defined(__GNUC__) && !defined(__clang__)
            SMS_addSpriteClipping(tiles[i].position.x,
                                  tiles[i].position.y,
                                  tiles[i].id
                                  );
#endif
        }
    }
}
void tiles_drawLenght(bool even){
    uint8 i=0u;
    uint8 size = lenghtTiles;
    if(lenghtTiles < (SMS_TILES_LENGHT>>1u)){
        for(;i<size;++i){
#if !defined(__GNUC__) && !defined(__clang__)
            SMS_addSpriteClipping(tiles[i].position.x,
                                  tiles[i].position.y,
                                  tiles[i].id
                                  );
#endif
        }
    }
    else{
        if(even){
            for(;i<size;i+=2u){
#if !defined(__GNUC__) && !defined(__clang__)
                SMS_addSpriteClipping(tiles[i].position.x,
                                      tiles[i].position.y,
                                      tiles[i].id
                                      );
#endif
            }
        }
        else{
            i=1u;
            for(;i<size;i+=2u){
#if !defined(__GNUC__) && !defined(__clang__)
                SMS_addSpriteClipping(tiles[i].position.x,
                                      tiles[i].position.y,
                                      tiles[i].id
                                      );
#endif
            }
        }
    }
}

#if !defined(__GNUC__) && !defined(__clang__)
#endif
