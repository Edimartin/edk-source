#ifndef VIEWGUTEXTURE_H
#define VIEWGUTEXTURE_H

/*
Library C++ ViewGUTexture - View to write the scene in a texture.
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
#warning "Inside ViewGUTexture"
#endif

#pragma once
#include "ViewGU.h"
//Include the renderTexture
#include "Texture2DRender.h"
#include "Camera2D.h"

#ifdef printMessages
#warning "    Compiling ViewGUTexture"
#endif


namespace edk{
class ViewGUTexture : public edk::ViewGU{
public:
    ViewGUTexture(edk::size2ui32 size);
    ViewGUTexture(edk::uint32 width,edk::uint32 height);
    ~ViewGUTexture();

    //set the new size of the texture
    bool setTextureSize(edk::size2ui32 size);
    bool setTextureSize(edk::uint32 width,edk::uint32 height);
    //return the textureSize
    edk::size2ui32 getTextureSize();
    edk::uint32 getTextureWidth();
    edk::uint32 getTextureHeight();
    //return the texture mode
    //EDK_LUMINANCE 1u
    //EDK_LUMINANCE_ALPHA 2u
    //EDK_RGB  3u
    //EDK_RGBA 4u
    edk::uint32 getTextureModeEDK();
    //GU_RGB
    //GU_RGBA
    //GU_LUMINANCE
    //GU_LUMINANCE_ALPHA
    edk::uint32 getTextureModeGU();

    void draw(edk::rectf32 outsideViewOrigin);
    //read from the texture

    //format
    //GU_STENCIL_INDEX
    //GU_DEPTH_COMPONENT
    //GU_DEPTH_STENCIL
    //GU_RED
    //GU_GREEN
    //GU_BLUE
    //GU_RG
    //GU_RGB
    //GU_RGBA
    //GU_BGR
    //GU_BGRA
    bool read(const edk::classID  data,edk::uint32 format = GU_RGB);
private:
    edk::Texture2DRender render;
    //camera to draw the polygon with the render texture
    edk::Camera2D renderCamera;
};
}//end namespace edk

#endif // VIEWGUTEXTURE_H
