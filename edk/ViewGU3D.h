#ifndef VIEWGU3D_H
#define VIEWGU3D_H

/*
Library C++ viewGU3D - Render GU elements, and a 3D camera, inside this view in Edk Game Engine
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
#pragma message "Inside ViewGU3D"
#endif

#pragma once
#include "ViewGU.h"
#include "Camera3D.h"

#ifdef printMessages
#pragma message "    Compiling ViewGU3D"
#endif

namespace edk{
class ViewGU3D: public edk::ViewGU{
public:
    ViewGU3D();
    virtual ~ViewGU3D();

    void Constructor(bool runFather=true);

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
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // VIEWGU3D_H
