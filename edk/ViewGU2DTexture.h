#ifndef VIEWGU2DTEXTURE_H
#define VIEWGU2DTEXTURE_H

/*
Library C++ ViewGU2DTexture - View Texture using a 2D Camera.
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
#warning "Inside ViewGU2DTexture"
#endif

#pragma once
#include "ViewGUTexture.h"

#ifdef printMessages
#warning "    Compiling ViewGU2DTexture"
#endif


namespace edk{
class ViewGU2DTexture : public edk::ViewGUTexture{
public:
    ViewGU2DTexture(edk::size2ui32 size);
    ViewGU2DTexture(edk::uint32 width,edk::uint32 height);
    ~ViewGU2DTexture();

    //the edkGU 2D camera
    edk::Camera2D camera;
protected:
//draw the polygon on the scene
void drawPolygon(edk::rectf32 outsideViewOrigin);
private:
//draw the 2Dcamera
void drawCamera2D();
};
}//end namespace edk

#endif // VIEWGU2DTEXTURE_H
