#ifndef VIEWGU3DTEXTURE_H
#define VIEWGU3DTEXTURE_H

/*
Library C++ ViewGU3DTexture - View Texture using a 3D Camera.
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
#pragma message "Inside ViewGU2DTexture"
#endif

#pragma once
#include "ViewGUTexture.h"
#include "Camera3D.h"

#ifdef printMessages
#pragma message "    Compiling ViewGU2DTexture"
#endif

namespace edk{
class ViewGU3DTexture : public edk::ViewGUTexture{
public:
    ViewGU3DTexture(edk::size2ui32 size);
    ViewGU3DTexture(edk::uint32 width,edk::uint32 height);
    virtual ~ViewGU3DTexture();

    void Constructor(edk::size2ui32 size);
    void Constructor(edk::uint32 width,edk::uint32 height);
    void Destructor();

    virtual void updateAnimations();
    virtual void updateAnimations(edk::float32 seconds);

    //the edkGU 2D camera
    edk::Camera3D camera;
protected:
    //draw the polygon on the scene
    void drawPolygon(edk::rectf32 outsideViewOrigin);
    //change point position beetween screen and world
    inline edk::vec2f32 convertPositionScreenToWorld(edk::vec2f32 position){
        return this->positionScreenToWorld(position);
    }
    edk::vec2f32 positionScreenToWorld(edk::vec2f32 position);
    inline edk::vec2f32 convertPositionScreenToWorld(edk::float32 x,edk::float32 y){
        return this->positionScreenToWorld(x,y);
    }
    edk::vec2f32 positionScreenToWorld(edk::float32 x,edk::float32 y);
    inline edk::vec2f32 convertPositionWorldToScreen(edk::vec2f32 position){
        return positionWorldToScreen(position);
    }
    edk::vec2f32 positionWorldToScreen(edk::vec2f32 position);
    inline edk::vec2f32 convertPositionWorldToScreen(edk::float32 x,edk::float32 y){
        return positionWorldToScreen(x,y);
    }
    edk::vec2f32 positionWorldToScreen(edk::float32 x,edk::float32 y);
private:
    //draw the 2Dcamera
    void drawCamera3D();
    //draw selection camera
    void drawSelectionCamera();
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // VIEWGU3DTEXTURE_H
