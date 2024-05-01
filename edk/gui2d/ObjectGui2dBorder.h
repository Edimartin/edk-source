#ifndef OBJECTBORDER_H
#define OBJECTBORDER_H

/*
ObjectBorder - Border used for the GUI 2D library
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
#pragma message "Inside ObjectBorder"
#endif

#pragma once
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../vector/BinaryTree.h"
#include "../shape/Mesh2D.h"
#include "../pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling ObjectBorder"
#endif



namespace edk{
namespace gui2d{
enum gui2dTexture{
    gui2dTextureNormal=0u,
    gui2dTextureUp,
    gui2dTexturePressed,
    gui2dTexturePressedUp,
    //
    gui2dTextureSize,
};
class ObjectGui2dBorder{
public:
    ObjectGui2dBorder();
    ~ObjectGui2dBorder();

    void Constructor(bool runFather=true);

    //save the FontTemplate
    static bool saveTemplate(const edk::char8* folder);
    static bool saveTemplate(edk::char8* folder);

    //LOAD SPRITES
    bool loadSpriteNormal(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteNormal(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteNormalFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteNormalFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteNormalFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteNormalFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSpriteNormal();
    //load pressed sprite
    bool loadSpritePressed(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressed(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSpritePressed();
    //load UP sprite
    bool loadSpriteUp(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSpriteUp();
    //load pressedUp sprite
    bool loadSpritePressedUp(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSpritePressedUp();

    //set the color
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b);
    void setColor(edk::color4f32 color);
    void setColor(edk::color3f32 color);

    //load the polygons
    bool updatePolygons(edk::size2f32 size);

    //set the borderSize
    bool setBorderSize(edk::float32 size);
    edk::float32 getBorderSize();

    //return the center rectangle
    edk::shape::Rectangle2D* getCenter();
    //return the rectangle of the center
    edk::rectf32 getRectCenter();


    //load the objectBorder
    bool load(edk::size2f32 size);
    //unload the objectBorder
    void unload();

    //draw the object
    void drawNormal();
    void drawUp();
    void drawPressed();
    void drawPressedUp();
    void drawSelection();
    bool calculateMeshBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat);
private:
    edk::shape::Mesh2D mesh;
    edk::shape::Rectangle2D center;
    edk::rectf32 rectCenter;
    edk::shape::Rectangle2D selection;
    edk::float32 border;
private:
    edk::classID classThis;
};
}//end namespace gui2d
}//end namespace edk

#endif // OBJECTBORDER_H
