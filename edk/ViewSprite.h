#ifndef EDK_VIEWSPRITE_H
#define EDK_VIEWSPRITE_H

/*
Library C++ viewSprite - Render an image inside this view in Edk Game Engine
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
#pragma message "Inside ViewSprite"
#endif

//ViewSprite draw a texture in a view
#pragma once
#include "View.h"
#include "Texture2DList.h"
#include "pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling ViewSprite"
#endif

namespace edk{
class ViewSprite :public edk::View{
public:
    ViewSprite();
    virtual ~ViewSprite();

    void Constructor();
    void Destructor();

    //create a new sprite
    bool createSprite(const edk::char8* name,edk::size2ui32 size, edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool createSprite(edk::char8* name,edk::size2ui32 size, edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool createSprite(const edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool createSprite(edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //create a new spriteRepeat
    bool createSpriteRepeat(const edk::char8* name,edk::size2ui32 size, edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool createSpriteRepeat(edk::char8* name,edk::size2ui32 size, edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool createSpriteRepeat(const edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool createSpriteRepeat(edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //draw sprite
    bool drawSprite(edk::uint8* sprite,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load the sprite
    bool loadSprite(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSprite(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load the spriteRepeat
    bool loadSpriteRepeat(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteRepeat(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load the sprite from memory
    bool loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load the spriteRepeat from memory
    bool loadSpriteRepeatFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteRepeatFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //set sprite from memory
    bool setSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool setSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //set spriteRepeat from memory
    bool setSpriteRepeatFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool setSpriteRepeatFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load the sprite
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load the spriteRepeat
    bool loadSpriteRepeatFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteRepeatFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);

    //Set UV
    bool setSpriteUV(edk::vec2f32 uv);
    bool setSpriteUV(edk::float32 u,edk::float32 v);

    //Delete the sprite
    void deleteSprite();
    //return the spriteSize
    edk::size2ui32 getSpriteSize();

    //draw
    virtual void draw(rectf32 outsideViewOrigin);
protected:
    //Draw Functions
    //draw viewPort
    //virtual void drawViewport(rectf32 outsideViewOrigin);
    //draw Camera
    //virtual void drawCamera();
    //draw the polygon on the scene
    virtual void drawPolygon(rectf32 outsideViewOrigin);
    //get the spriteCode
    edk::uint32 getSpriteCode();
private:
    //textures list
    edk::Texture2DList list;
    //sprite
    edk::uint32 spriteCode;
    edk::vec2f32 spriteUV;
    edk::uint32 spriteMinFilter;
    edk::uint32 spriteMagFilter;
    edk::size2ui32 spriteSize;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // VIEWSPRITE_H
