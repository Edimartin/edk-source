#ifndef SCROLLBAR2D_H
#define SCROLLBAR2D_H

/*
ScrollBar2d - ScrollBar for the GUI 2D library
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
#pragma message "Inside gui2d::ScrollBar2d"
#endif

#pragma once
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::ScrollBar2d"
#endif

#define EDK_GUI2D_XML_GUI2D_SCROLL "gui2dScroll_"
#define EDK_GUI2D_XML_GUI2D_SCROLL_FOREGROUND_SIZE "gui2dScrollForeSize_"
#define EDK_GUI2D_XML_GUI2D_SCROLL_FOREGROUND_PERCENT "gui2dScrollForePercent_"
#define EDK_GUI2D_XML_GUI2D_SCROLL_FOREGROUND_INSIDE "gui2dScrollForeInside_"

namespace edk{
namespace gui2d{
class ScrollBar2d : public edk::gui2d::ObjectGui2d{
public:
    ScrollBar2d();
    virtual ~ScrollBar2d();

    void Constructor();
    void Destructor();

    //save the FontTemplate
    static bool saveTemplates(const edk::char8* folder);
    static bool saveTemplates(edk::char8* folder);

    //Set the percent
    void setPercent(edk::vec2f32 percent);
    void setPercent(edk::float32 x,edk::float32 y);
    void setPercentX(edk::float32 x);
    void setPercentY(edk::float32 y);
    //return the percent
    edk::float32 getPercentX();
    edk::float32 getPercentY();
    edk::vec2f32 getPercent();

    //load the button textures and meshes
    bool load();
    void unload();
    void update();

    //set border size
    bool setBorderSize(edk::float32 size);
    //set the size
    bool setForegroundSize(edk::size2f32 size);
    bool setForegroundSize(edk::float32 width,edk::float32 height);
    inline bool setPercentLimit(edk::size2f32 size){
        return this->setForegroundSize(size.width,size.height);
    }
    inline bool setPercentLimit(edk::float32 width,edk::float32 height){
        return this->setForegroundSize(width,height);
    }
    //get the foregroundSize
    edk::float32 getForegroundWidth();
    edk::float32 getForegroundHeight();
    edk::size2f32 getForegroundSize();

    //set the color
    void setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b);
    void setForegroundColor(edk::color4f32 color);
    void setForegroundColor(edk::color3f32 color);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //draw the button
    void draw();

    //move functions
    void startMove(edk::vec2f32 mousePosition);
    void moveTo(edk::vec2f32 position);
    void cancelMove();
    //return true if the object can be moved
    bool canMove();
    bool setStatus(edk::gui2d::gui2dTexture status);
    edk::gui2d::gui2dTexture getStatus();

    //clone the gui object from
    virtual bool cloneFrom(edk::gui2d::ObjectGui2d* obj);
    virtual bool cloneFrom(edk::gui2d::ScrollBar2d* obj);
private:
    void updateObjPosition();
    //function to calculate the percent values for X and Y
    void calculatePercents();
    //calculate the position from the percents
    void calculatePosition();
    edk::gui2d::ObjectGui2dBorder objInside;
    edk::vec2f32 objPosition;
    edk::size2f32 saveSize;
    edk::vec2f32 saveMovePosition;
    edk::vec2f32 savePosition;
    edk::vec2f32 saveGlobalPosition;
    edk::float32 saveAngle;
    //foreground size
    edk::size2f32 foregroundSize;
    //position percent
    edk::vec2f32 percent;

    //object inside status
    edk::gui2d::gui2dTexture statusInside;
    //save the object inside status to compare in update function
    edk::gui2d::gui2dTexture saveStatusInside;
private:
    edk::classID classThis;
};
}//end namespace gui2d
}//end namespace edk

#endif // SCROLLBAR2D_H
