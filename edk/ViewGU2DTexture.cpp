#include "ViewGU2DTexture.h"

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

edk::ViewGU2DTexture::ViewGU2DTexture(edk::size2ui32 size)
    :edk::ViewGUTexture(size)
{
    //
    this->camera.position=edk::vec2f32(0u,0u);
}
edk::ViewGU2DTexture::ViewGU2DTexture(edk::uint32 width,edk::uint32 height)
    :edk::ViewGUTexture(width,height)
{
    //
}
edk::ViewGU2DTexture::~ViewGU2DTexture(){
    //
}
//draw the 2Dcamera
void edk::ViewGU2DTexture::drawCamera2D(){
    //
    edk::GU::guUseMatrix(GU_PROJECTION);
    //draw the camera2D
    this->camera.draw();
}
//draw the polygon on the scene
void edk::ViewGU2DTexture::drawPolygon(rectf32 outsideViewOrigin){
    //
    edk::ViewSpriteController::drawPolygon(outsideViewOrigin);
    this->drawCamera2D();

    //set the matrix before draw the scene
    edk::GU::guUseMatrix(GU_MODELVIEW);

    //draw the GU scene
    this->drawScene(outsideViewOrigin);
}
