#ifndef EDK_VIEWGU2D_H
#define EDK_VIEWGU2D_H

/*
Library C++ viewGU2D - Render GU elements, and a 2D camera, inside this view in Edk Game Engine
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
#warning "Inside ViewGU2D"
#endif

#pragma once
#include "ViewGU.h"
#include "Camera2D.h"

#ifdef printMessages
#warning "    Compiling ViewGU2D"
#endif

namespace edk{
class ViewGU2D: public edk::ViewGU{
    public:
        ViewGU2D();
        virtual ~ViewGU2D();

        //draw the GU scene
        virtual void drawScene(edk::rectf32 outsideViewOrigin);

        //the edkGU 2D camera
        edk::Camera2D camera;
    protected:
    //draw the polygon on the scene
    void drawPolygon(rectf32 outsideViewOrigin);
    private:
    //draw the 2Dcamera
    void drawCamera2D();
    //draw selection camera
    void drawSelectionCamera();
};
}//end namespace edk

#endif // VIEWGU_H

/* EXAMPLE
class example: edk::ViewGU2D{
    //construtor
    example();
    //destrutor
    ~example();

    //Load and Unload
    void load(edk::rectf32 outsideViewOrigin);
    void unload();

    //Mouse Events
    void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
    void eventMouseMoved(edk::vec2f32 point,edk::uint32 button);
    void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);
    //Mouse go Inside Outside
    void eventMouseEntryInsideView(edk::vec2f32 point);
    void eventMouseLeftView(edk::vec2f32 point);

    //Update the scene
    void update(edk::WindowEvents* events);

    //draw the GU scene
    void drawScene(edk::rectf32 outsideViewOrigin);
};
*/
