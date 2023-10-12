#ifndef EDK_VIEWSPRITECONTROLLER_H
#define EDK_VIEWSPRITECONTROLLER_H

/*
Library C++ viewSpriteControler - Render an image, and other views, inside this view in Edk Game Engine
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
#pragma message "Inside ViewSpriteController"
#endif

#pragma once
#include "ViewController.h"
#include "Texture2DList.h"
#include "pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling ViewSpriteController"
#endif

namespace edk{
class ViewSpriteController :public edk::ViewController{
public:
    ViewSpriteController();
    virtual ~ViewSpriteController();

    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    //create a new sprite
    bool createSprite(const edk::char8* name,edk::size2ui32 size, edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool createSprite(edk::char8* name,edk::size2ui32 size, edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool createSprite(const edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool createSprite(edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    //draw sprite
    bool drawSprite(edk::uint8* sprite,edk::uint32 filter = GU_NEAREST);
    //load the sprite
    bool loadSprite(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSprite(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //load the sprite from memory
    bool loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    //set sprite from memory
    bool setTextureFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter = GU_NEAREST);
    bool setTextureFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter = GU_NEAREST);
    //load the sprite
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);

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
    //sprite
    edk::uint32 spriteCode;
private:
    //textures list
    edk::Texture2DList list;
    edk::uint32 spriteFilter;
    edk::size2ui32 spriteSize;
};
}//end namespace

#endif // VIEWSPRITECONTROLLER_H
