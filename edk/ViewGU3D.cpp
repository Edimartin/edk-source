#include "ViewGU3D.h"

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

edk::ViewGU3D::ViewGU3D(){
    //
}
edk::ViewGU3D::~ViewGU3D(){
    //
}
//draw the 2Dcamera
void edk::ViewGU3D::drawCamera3D(){
    //
    this->camera.draw();
}
//draw selection camera
void edk::ViewGU3D::drawSelectionCamera(){
    //
    this->camera.drawAxisOnly();
}
//draw the polygon on the scene
void edk::ViewGU3D::drawPolygon(edk::rectf32 outsideViewOrigin){
    edk::ViewSpriteController::drawPolygon(outsideViewOrigin);

    //run selection function before draw the scene
    this->runSelectionFunction();

    this->drawCamera3D();

    //set the matrix before draw the scene
    edk::GU::guUseMatrix(GU_MODELVIEW);

    edk::GU::guEnable(GU_DEPTH_TEST);

    edk::GU::guDepthFunc(GU_LESS);

    edk::GU::guDepthRange(0.0f, 1.0f);

    edk::GU::guClear(GU_DEPTH_BUFFER_BIT);
    //draw the GU scene
    this->drawScene(outsideViewOrigin);

    edk::GU::guDisable(GU_DEPTH_TEST);

    edk::GU::guDisableAllLights();
}

//draw the GU scene
void edk::ViewGU3D::drawScene(edk::rectf32){
    //
}
