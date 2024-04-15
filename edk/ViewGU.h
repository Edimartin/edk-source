#ifndef EDK_VIEWGU_H
#define EDK_VIEWGU_H

/*
Library C++ viewGU - Render GU elements inside this view in Edk Game Engine
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
#pragma message "Inside ViewGU"
#endif

#pragma once
#include "GU/GU.h"
#include "ViewSpriteController.h"
#include "WindowEvents.h"
#include "pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling ViewGU"
#endif

/*
void resize(edk::rectf32 outsideViewOrigin){
    //
}
void load(edk::rectf32 outsideViewOrigin){
    //
}
void unload(){
    //
}
void update(edk::WindowEvents* events){
    //
}
void pause(){
    //
}
void unpause(){
    //
}
void drawScene(edk::rectf32 outsideViewOrigin){
    //
}
*/

namespace edk{
class ViewGU: public edk::ViewSpriteController{
public:
    ViewGU();
    virtual ~ViewGU();

    void Constructor(bool runFather=true);

    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    //load the background
    bool loadBackground(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadBackground(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //load the sprite from memory
    bool loadBackgroundFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadBackgroundFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    //laod the sprite from pack
    bool loadBackgroundFromPack(edk::pack::FilePackage* pack, edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadBackgroundFromPack(edk::pack::FilePackage* pack, const edk::char8* name,edk::uint32 filter = GU_NEAREST);

    //delete the background
    void deleteBackground();

    //test the selection
    void testSelection(edk::vec2f32 position,edk::size2f32 size = edk::size2f32(1.f,1.f));
    void testSelection(edk::float32 x,edk::float32 y,edk::size2f32 size = edk::size2f32(1.f,1.f));
    void testSelection(edk::float32 x,edk::float32 y,edk::float32 width=1.f,edk::float32 height=1.f);
    void testSelection(edk::vec2i32 position,edk::size2f32 size = edk::size2f32(1.f,1.f));
    void testSelection(edk::int32 x,edk::int32 y,edk::size2f32 size = edk::size2f32(1.f,1.f));
    void testSelection(edk::int32 x,edk::int32 y,edk::float32 width = 1.f,edk::float32 height = 1.f);

    virtual void update(edk::WindowEvents* events);

    //draw the GU scene
    virtual void drawScene(edk::rectf32 outsideViewOrigin);

    virtual void drawSelectionScene();

    //return true if is a GU View
    bool isGU();
protected:
    //Draw Functions
    //draw viewPort
    void drawViewport(edk::rectf32 outsideViewOrigin);
    //draw Camera
    void drawCamera();
    //draw the polygon on the scene
    virtual void drawPolygon(edk::rectf32 outsideViewOrigin);
    //draw selection camera
    virtual void drawSelectionCamera();
    //push and pop the selection names
    void selectionPushName(edk::uint32 id);
    void selectionPopName();
    //process the selection
    virtual void processHits(edk::int32 hits, edk::uint32 buffer[]);
    //process the selection
    virtual void selectObject(edk::uint32 position,edk::int32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);
    //run selection function
    void runSelectionFunction();
    //get true if go run selection
    bool isRunningSelection();
    //function to run the drawScene
    virtual void runDrawScene(edk::rectf32 outsideViewOrigin);
private:
    //save selection position
    edk::vec2f32 selectionPosition;
    edk::size2f32 selectionSize;
    bool runSelection;

    edk::uint32 buffer[1024u];
    edk::uint32 sizeBuffer;
private:
    edk::classID classThis;
};
}//end namespace

#endif // VIEWGU_H
