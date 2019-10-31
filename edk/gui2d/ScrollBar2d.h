#ifndef SCROLLBAR2D_H
#define SCROLLBAR2D_H

/*
ScrollBar2d - ScrollBar for the GUI 2D library
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
#warning "Inside gui2d::ScrollBar2d"
#endif

#pragma once
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#warning "    Compiling gui2d::ScrollBar2d"
#endif

namespace edk{
namespace gui2d{
class ScrollBar2d : public edk::gui2d::ObjectGui2d{
public:
    ScrollBar2d();
    virtual ~ScrollBar2d();

    //get the type
    virtual edk::gui2d::gui2dTypes getType();

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
    //get the foregroundSize
    edk::float32 getForegroundWidth();
    edk::float32 getForegroundHeight();
    edk::size2f32 getForegroundSize();

    //set the color
    void setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b);
    void setForegroundColor(edk::color4f32 color);
    void setForegroundColor(edk::color3f32 color);

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
private:
    void updateObjPosition();
    //function to calculate the percent values for X and Y
    void calculatePercents();
    //calculate the position from the percents
    void calculatePosition();
    edk::gui2d::ObjectGui2dBorder objInside;
    edk::vec2f32 objPosition;
    edk::size2f32 saveSize;
    //foreground size
    edk::size2f32 foregroundSize;
    //position percent
    edk::vec2f32 percent;

    //object inside status
    edk::gui2d::gui2dTexture statusInside;
    //save the object inside status to compare in update function
    edk::gui2d::gui2dTexture saveStatusInside;
};
}//end namespace gui2d
}//end namespace edk

#endif // SCROLLBAR2D_H
