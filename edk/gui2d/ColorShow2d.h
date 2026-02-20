#ifndef COLORSHOW2D_H
#define COLORSHOW2D_H

/*
ColorShow2d - ColorShow for the GUI 2D library
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
#pragma message "Inside gui2d::ColorShow2d"
#endif

#pragma once
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::ColorShow2d"
#endif

#define EDK_GUI2D_XML_GUI2D_COLORSHOW "gui2dColorShow_"

namespace edk{
namespace gui2d{

class ColorShow2d : public edk::gui2d::ObjectGui2d{
public:
    ColorShow2d();
    virtual ~ColorShow2d();

    void Constructor();
    void Destructor();

    bool setColorRGB(edk::color3f32 colorRGB);
    bool setColorR(edk::float32 r);
    bool setColorG(edk::float32 g);
    bool setColorB(edk::float32 b);
    bool setColorRGBA(edk::color4f32 colorRGBA);
    bool setColorA(edk::float32 a);

    //load the button textures and meshes
    bool load();
    void unload();
    void update();

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //draw the button
    virtual void draw();
    virtual void drawSelection();

    ////click to select an polygon inside the object
    //virtual void clickStart(edk::uint32 name,edk::vec2f32 position);
    //virtual void clickMove(edk::uint32 name,edk::vec2f32 position,bool mouseInside);
    //virtual void clickEnd(edk::uint32 name,edk::vec2f32 position,bool mouseInside,bool doubleClick);

    //clone the gui object from
    virtual bool cloneFrom(edk::gui2d::ObjectGui2d* obj);
    virtual bool cloneFrom(edk::gui2d::ColorShow2d* obj);
private:
    //object to draw the color
    edk::Object2D objColor;
private:
    edk::classID classThis;
};
}
}

#endif // COLORSHOW2D_H
