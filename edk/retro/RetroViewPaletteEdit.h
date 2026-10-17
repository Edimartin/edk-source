#ifndef RETROVIEWPALETTEEDIT_H
#define RETROVIEWPALETTEEDIT_H

/*
Library C++ RetroViewPaletteEdit - View used to Edit Palettes in EDK
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
#pragma message "Inside RetroViewPaletteEdit"
#endif

#pragma once
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../ViewGU2D.h"
#include "../vector/BinaryTree.h"
#include "../Camera2D.h"
#include "../fonts/FontMap.h"
#include "../pack/FilePackage.h"
#include "../animation/Interpolation1DGroup.h"
#include "RetroPalette.h"

#ifdef printMessages
#pragma message "    Compiling RetroViewPaletteEdit"
#endif

namespace edk{
namespace retro{
class RetroViewPaletteEdit: public edk::ViewGU2D{
public:
    RetroViewPaletteEdit();
    ~RetroViewPaletteEdit();

    void Constructor();
    void Destructor();

    //set the img pointer
    bool setFromImg(edk::Image2D* img);
    bool setFromPalette(edk::uint8* palette,edk::uint32 size,edk::uint8 channels,edk::uint8 bytesPerChannel=1u);

    bool setPalette(edk::retro::RetroPalette* palette);
    edk::retro::RetroPalette* getPalette();

    bool havePressedColor();
    edk::uint32 getPressedColorId();
    edk::uint32 getPressedMouseButton();

    bool needMoveID();
    edk::uint32 getMoveIdStart();
    edk::uint32 getMoveIdEnd();

    //start select to move
    void selectMove(edk::uint32 id);

    void updateViewSize();
protected:
    //
private:
    //palette
    static edk::retro::RetroPalette staticPalette;
    static edk::uint64 staticCounterPalette;

    edk::retro::RetroPalette* palette;
    //save the camera size to calculate the zoom
    edk::Object2D posMouse;
    edk::vec2f32 savePosMouse;
    edk::float32 distanceMouse;
    edk::vec2f32 savePosMouseSelect;
    edk::animation::Interpolation1DGroup animSelection;
    //edk::vec2f32 posCamera;
    edk::animation::Interpolation2DGroup animCenterCamera;

    //save the screen to set the camera automatically
    edk::rectf32 saveFrame;

    edk::uint32 mousePressed;
    edk::uint32 idPressed;
    bool colorPressed;
    bool selectingMove;
    edk::uint32 movingIdStart;
    edk::uint32 movingIdEnd;
    bool haveMoveId;

    //update the camera size
    void updateCamera();
    //process the selection
    void selectObject(edk::uint32 position,edk::int32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);

    void resize(edk::rectf32 outsideViewOrigin);
    void load(edk::rectf32 outsideViewOrigin);
    void unload();
    //update the view
    void update(edk::WindowEvents* events);
    void drawScene(edk::rectf32 outsideViewOrigin);
    void drawSelectionScene();
private:
    edk::classID classThis;
};
}//end namespace edk
}//end namespace retro

#endif // RETROVIEWPALETTEEDIT_H
