#ifndef EDK_VIEWMENU_H
#define EDK_VIEWMENU_H

/*
Library C++ edkViewMenu - Viewport used to show a Menu sprite in the background
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
#warning "Inside ViewMenu"
#endif

#include "ViewSpriteController.h"
#include "Camera2D.h"

#ifdef printMessages
#warning "    Compiling ViewMenu"
#endif

//#define borderSize 50.f

namespace edk{
class ViewMenu: public edk::ViewSpriteController{
public:
    ViewMenu();

    //set borderSize
    bool setBorderSize(edk::uint32 size);
    //return the inside frame
    edk::rectui32 getInsideFrame();
    //return the size inside
    edk::size2ui32 getInsideSize();

    //draw
    virtual void draw(rectf32 outsideViewOrigin);
protected:
    //draw the polygon on the scene
    virtual void drawPolygon(rectf32 outsideViewOrigin);
private:
    edk::Camera2D cam;
    edk::float32 borderTemp;
    edk::rectf32 rectMenuSave;
};
}//end namespace edk

#endif // EDK_VIEWMENU_H
