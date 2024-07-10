#ifndef VIEWGUTEXTURE_H
#define VIEWGUTEXTURE_H

/*
Library C++ ViewGUTexture - View to write the scene in a texture.
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifdef printMessages
#pragma message "Inside ViewGUTexture"
#endif

#pragma once
#include "ViewGU.h"
//Include the renderTexture
#include "Texture2DRender.h"
#include "Camera2D.h"

#include "shd/GLSL.h"

#ifdef printMessages
#pragma message "    Compiling ViewGUTexture"
#endif


namespace edk{
class ViewGUTexture : public edk::ViewGU{
public:
    ViewGUTexture(edk::size2ui32 size);
    ViewGUTexture(edk::uint32 width,edk::uint32 height);
    virtual ~ViewGUTexture();

    void Constructor(edk::size2ui32 size,bool runFather=true);
    void Constructor(edk::uint32 width,edk::uint32 height,bool runFather=true);

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
protected:
    //shader program
    edk::shd::GLSL shader;
private:
    edk::Texture2DRender render;
    //camera to draw the polygon with the render texture
    edk::Camera2D renderCamera;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // VIEWGUTEXTURE_H
