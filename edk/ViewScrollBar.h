#ifndef VIEWSCROLLBAR_H
#define VIEWSCROLLBAR_H

/*
Library C++ ViewScrollBar - Show a scroolBar in the screen
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
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

    //get the scrollColor
    edk::color4f32 getBackColor();
    edk::color4f32 getFrontColor();
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

        //Events
        virtual void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
        virtual void eventMouseMoved(edk::vec2f32 point,edk::uint32 button);
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

    private:
        //save the object color
        edk::color4f32 colorObject;
        //save the rect
        edk::rectf32 saveFrame;
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
