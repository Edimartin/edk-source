#ifndef VIEWSCROLLBAR_H
#define VIEWSCROLLBAR_H

/*
Library C++ ViewScrollBar - Show a scroolBar in the screen
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
#warning "Inside ViewScrollBar"
#endif

#pragma once
#include "ViewController.h"
#include "ViewMenu.h"
#include "ViewGU2D.h"

#ifdef printMessages
#warning "    Compiling ViewScrollBar"
#endif

namespace edk{
class ViewScrollBar : public edk::ViewController{
public:
    ViewScrollBar();
    ~ViewScrollBar();

    void load(rectf32 outsideViewOrigin);
    void unload();
    void update(edk::WindowEvents* events);
    bool addSubview(edk::View *addView);

    //set the border
    void setBorderSize(edk::uint32 size);
    //set the size
    void setForegroundSize(edk::size2f32 size);
    void setForegroundSize(edk::float32 width,edk::float32 height);
    //Set the percent
    void setPercent(edk::vec2f32 percent);
    void setPercent(edk::float32 x,edk::float32 y);
    void setPercentX(edk::float32 x);
    void setPercentY(edk::float32 y);

    //set the color
    void setBackColor(edk::color3f32 color);
    void setBackColor(edk::float32 r,edk::float32 g,edk::float32 b);
    void setBackColor(edk::color4f32 color);
    void setBackColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setFrontColor(edk::color3f32 color);
    void setFrontColor(edk::float32 r,edk::float32 g,edk::float32 b);
    void setFrontColor(edk::color4f32 color);
    void setFrontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

    //return the percent
    edk::float32 getPercentX();
    edk::float32 getPercentY();
    edk::vec2f32 getPercent();
    //return true if the scroll is selected
    bool isSelected();

    //get the scrollColor
    edk::color4f32 getBackColor();
    edk::color4f32 getFrontColor();

    //return true if the mouse is inside
    virtual bool isMouseInside();
private:
    //one ViewButton to represent the backgroun
    edk::ViewMenu background;
    //save the rect
    edk::rectf32 rectScrollSave;

    //update the frames
    void updateFrames();

    //button inside class
    class ForegroundButton:public edk::ViewGU2D{
    public:
        ForegroundButton();
        ~ForegroundButton();

        void load(rectf32 outsideViewOrigin);
        void unload();
        void update(edk::WindowEvents* events);
        void updateFrame();

        //Events
        virtual void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
        virtual void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);

        //draw the GU scene
        virtual void drawScene(rectf32 outsideViewOrigin);

        //set the borderSize
        bool setBorderSize(edk::float32 size);
        //set color
        void setColor(edk::color4f32 color);
        //set the size
        bool setSize(edk::size2f32 size);
        //set position
        void setPositionX(edk::float32 x);
        void setPositionY(edk::float32 y);
        void setPosition(edk::vec2f32 position);

        //Set the percent
        void setPercent(edk::vec2f32 percent);
        void setPercent(edk::float32 x,edk::float32 y);
        void setPercentX(edk::float32 x);
        void setPercentY(edk::float32 y);

        //return the percent
        edk::float32 getPercentX();
        edk::float32 getPercentY();
        edk::vec2f32 getPercent();
        //return if the mouse is holded
        bool isMouseHolded();

    private:
        //save the object color
        edk::color4f32 colorObject;
        //save the rect
        edk::float32 borderTemp;
        //size object
        edk::size2f32 sizeObject;
        //save the polygon rect
        edk::rectf32 polygonRect;
        //save mouse position
        edk::vec2f32 saveMousePos;
        //save object position
        edk::vec2f32 saveObjectPosition;
        //mouse holded
        bool mouseHolded;
    private:
    }foreground;
};
}//end namespace edk

#endif // VIEWSCROOLBAR_H
