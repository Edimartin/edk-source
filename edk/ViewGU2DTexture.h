#ifndef VIEWGU2DTEXTURE_H
#define VIEWGU2DTEXTURE_H

/*
Library C++ ViewGU2DTexture - View Texture using a 2D Camera.
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

#ifdef printMessages
#pragma message "    Compiling ViewGU2DTexture"
#endif


namespace edk{
class ViewGU2DTexture : public edk::ViewGUTexture{
public:
    ViewGU2DTexture(edk::size2ui32 size);
    ViewGU2DTexture(edk::uint32 width,edk::uint32 height);
    virtual ~ViewGU2DTexture();

    void Constructor(edk::size2ui32 size,bool runFather=true);
    void Constructor(edk::uint32 width,edk::uint32 height,bool runFather=true);

    virtual void updateAnimations();
    virtual void updateAnimations(edk::float32 seconds);

    //the edkGU 2D camera
    edk::Camera2D camera;
protected:
    //draw the polygon on the scene
    void drawPolygon(edk::rectf32 outsideViewOrigin);
private:
    //draw the 2Dcamera
    void drawCamera2D();
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // VIEWGU2DTEXTURE_H
