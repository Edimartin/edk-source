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

    //load the button textures and meshes
    bool load();
    void unload();
    void update();

    //set border size
    bool setBorderSize(edk::float32 size);

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
    edk::gui2d::ObjectGui2dBorder objInside;
    edk::vec2f32 objPosition;
    edk::size2f32 saveSize;
    //foreground size
    edk::size2f32 foregroundSize;

    //object inside status
    edk::gui2d::gui2dTexture statusInside;
    //save the object inside status to compare in update function
    edk::gui2d::gui2dTexture saveStatusInside;
};
}//end namespace gui2d
}//end namespace edk

#endif // SCROLLBAR2D_H
