#include "ViewGU2D.h"

/*
Library C++ viewGU2D - Render GU elements, and a 2D camera, inside this view in Edk Game Engine
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
#pragma message "            Inside ViewGU2D.cpp"
#endif

edk::ViewGU2D::ViewGU2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::ViewGU2D::~ViewGU2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::ViewGU2D::Constructor(bool runFather){
    if(runFather){
        edk::ViewGU::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->camera.Constructor();edkEnd();

        this->camera.position=edk::vec2f32(0u,0u);edkEnd();
    }
}

//draw the 2Dcamera
void edk::ViewGU2D::drawCamera2D(){
    //draw the camera2D
    this->camera.draw();edkEnd();
}
//draw selection camera
void edk::ViewGU2D::drawSelectionCamera(){
    this->camera.drawOrthoOnly();edkEnd();
}

//draw the polygon on the scene
void edk::ViewGU2D::drawPolygon(edk::rectf32 outsideViewOrigin){
    edk::ViewSpriteController::drawPolygon(outsideViewOrigin);edkEnd();

    //run selection function before draw the scene
    this->runSelectionFunction();edkEnd();

    this->drawCamera2D();edkEnd();

    //set the matrix before draw the scene
    edk::GU::guUseMatrix(GU_MODELVIEW);edkEnd();

    //draw the GU scene
    this->drawScene(outsideViewOrigin);edkEnd();

    edk::GU::guDisableAllLights();edkEnd();
}
void edk::ViewGU2D::runUpdate(edk::WindowEvents* events){
    this->camera.updateAnimations(events->secondPassed);
    edk::View::runUpdate(events);
}


//draw
void edk::ViewGU2D::drawScene(edk::rectf32 ){
    //
}
