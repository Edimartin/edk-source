#ifndef BOXGUI2D_H
#define BOXGUI2D_H

/*
BoxGui2d - Box for use objects inside a menu in the GUI 2D library
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
#pragma message "Inside gui2d::BoxGui2d"
#endif

#pragma once
#include "../Object2DValues.h"
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../vector/BinaryTree.h"
#include "../vector/Stack.h"
#include "../fonts/FontMap.h"
#include "../NameClass.h"
#include "../BinaryConverter.h"
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::BoxGui2d"
#endif

namespace edk{
namespace gui2d{
class BoxGui2d: public edk::gui2d::ObjectGui2d{
public:
    BoxGui2d();
    ~BoxGui2d();

    void Constructor(bool runFather=true);

    //Add a subObject in to the nexes
    bool addSubObjectBackground(edk::Object2DValues* object);
    //remove the usbObject
    bool removeSubObjectBackground(edk::Object2DValues* object);
    void removeAllSubObjectsBackground();

    //Add a subObject in to the nexes
    bool addSubObjectForeground(edk::Object2DValues* object);
    //remove the usbObject
    bool removeSubObjectForeground(edk::Object2DValues* object);
    void removeAllSubObjectsForeground();

    bool removeSubObject(edk::Object2DValues* object);
    void removeAllSubObjects();

    //create a map
    bool createMap(edk::size2ui32 size);
    bool createMap(edk::uint32 width,edk::uint32 height);
    //create a map with only the height size and the scale
    bool createMapHeight(edk::uint32 height,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool createMapHeight(edk::uint32 height,edk::size2f32 scale);
    bool createMapHeight(edk::uint32 height);

    bool writeText(const edk::char8* text);
    bool writeText(edk::char8* text);
    bool writeText(const edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(const edk::char8* text,edk::size2f32 scale);
    bool writeText(edk::char8* text,edk::size2f32 scale);
    void cleanText();
    void deleteText();

    virtual void update();

    //draw the button
    virtual void draw();
    virtual void drawSelection();
private:
    //nexes objects
    edk::vector::Stack<edk::Object2DValues*> nextsBack;
    edk::vector::Stack<edk::Object2DValues*> nextsFore;

    //save the textScale
    edk::size2f32 textScale;
    bool canCleanText;
private:
    edk::classID classThis;
};
}//end namespace gui2d
}//end namespace edk

#endif // BOXGUI2D_H
