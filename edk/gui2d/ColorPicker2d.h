#ifndef COLORPICKER2D_H
#define COLORPICKER2D_H

/*
ColorPicker2d - ColorPicker for the GUI 2D library
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
#pragma message "Inside gui2d::ColorPicker2d"
#endif

#pragma once
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::ColorPicker2d"
#endif

#define EDK_GUI2D_XML_GUI2D_COLORPICKER "gui2dColorPicker_"


#define EDK_GUI2D_HUE_PERCENT_BEGIN_X 0.85f
#define EDK_GUI2D_HUE_PERCENT_END_X 0.95f
#define EDK_GUI2D_SATURATION_PERCENT_BEGIN_X 0.0f
#define EDK_GUI2D_SATURATION_PERCENT_END_X 0.8f

namespace edk{
namespace gui2d{

enum ColorType{
    colorTypeNothing=0u,
    colorTypeRGB,
    colorTypeHLV,
    colorTypeSize
};

class ColorPicker2d : public edk::gui2d::ObjectGui2d{
public:
    ColorPicker2d();
    virtual ~ColorPicker2d();

    void Constructor();
    void Destructor();

    //set the draw type
    bool setColorType(edk::gui2d::ColorType type);

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

    //click to select an polygon inside the object
    virtual void clickStart(edk::uint32 name,edk::vec2f32 position);
    virtual void clickMove(edk::uint32 name,edk::vec2f32 position,bool mouseInside);
    virtual void clickEnd(edk::uint32 name,edk::vec2f32 position,bool mouseInside,bool doubleClick);

    //clone the gui object from
    virtual bool cloneFrom(edk::gui2d::ObjectGui2d* obj);
    virtual bool cloneFrom(edk::gui2d::ColorPicker2d* obj);
private:
    edk::gui2d::ColorType typeColor;
    //object to draw the color
    edk::Object2D objColor;
    edk::Object2D objColor2;

    bool controlling;

    //create the object to draw
    void createColor();

    void processClick(edk::vec2f32 position,bool start);

    bool updatePolygonColorValue(edk::color3f32 color32);
private:
    edk::classID classThis;
};
}
}
#endif // COLORPICKER2D_H
