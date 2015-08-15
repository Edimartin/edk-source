#ifndef VIEWBUTTONMOVE_H
#define VIEWBUTTONMOVE_H

/*
Library C++ ViewButtonMove - Move the button automaticaly
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
#warning "Inside ViewButtonMove"
#endif

#pragma once
#include "edk/ViewButton.h"

#ifdef printMessages
#warning "    Compiling ViewButtonMove"
#endif

namespace edk{
class ViewButtonMove : public edk::ViewButton{
public:
    ViewButtonMove();
    ~ViewButtonMove();

    virtual void updateView(edk::WindowEvents* events);
    //Function to set button position
    virtual void setPosition(edk::vec2f32 position);
protected:
    //save mouse position
    edk::vec2f32 saveMousePos;
    //save the button position
    edk::vec2f32 savePosition;
    //set holded
    bool holdedMouse;
    //set if save the first position
    bool saveFirst;
private:
    //mouse events
    void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
    void eventMouseMoved(edk::vec2f32 point,edk::uint32 button);
    void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);
};
}//end namespace edk

#endif // VIEWBUTTONMOVE_H
