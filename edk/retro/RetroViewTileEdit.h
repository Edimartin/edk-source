#ifndef RETROVIEWTILEEDIT_H
#define RETROVIEWTILEEDIT_H

/*
Library C++ RetroViewTileEdit - View used to Edit RetroTiles in EDK
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
#pragma message "Inside RetroViewTileEdit"
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

#ifdef printMessages
#pragma message "    Compiling RetroViewTileEdit"
#endif

namespace edk{
namespace retro{
class RetroViewTileEdit: public edk::ViewGU2D{
public:
    RetroViewTileEdit();
    ~RetroViewTileEdit();

    void Constructor();
    void Destructor();
private:
    void resize(edk::rectf32 outsideViewOrigin);
    void load(edk::rectf32 outsideViewOrigin);
    void unload();
    void update(edk::WindowEvents* events);
    void pause();
    void unpause();
    void drawScene(edk::rectf32 outsideViewOrigin);
private:
    edk::classID classThis;
};
}//end namespace retro
}//end namespace edk

#endif // RETROVIEWTILEEDIT_H
