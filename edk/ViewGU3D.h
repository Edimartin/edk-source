#ifndef VIEWGU3D_H
#define VIEWGU3D_H

/*
Library C++ viewGU3D - Render GU elements, and a 3D camera, inside this view in Edk Game Engine
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
#warning "Inside ViewGU3D"
#endif

#pragma once
#include "ViewGU.h"
#include "Camera3D.h"

#ifdef printMessages
#warning "    Compiling ViewGU3D"
#endif

namespace edk{
class ViewGU3D: public edk::ViewGU{
public:
    ViewGU3D();
    virtual ~ViewGU3D();

    //draw the GU scene
    virtual void drawScene(edk::rectf32 outsideViewOrigin);

    //the edkGU 2D camera
    edk::Camera3D camera;
protected:
    //draw the polygon on the scene
    void drawPolygon(edk::rectf32 outsideViewOrigin);
private:
    //draw the 2Dcamera
    void drawCamera3D();
    //draw selection camera
    void drawSelectionCamera();
};
}//end namespace edk

#endif // VIEWGU3D_H
