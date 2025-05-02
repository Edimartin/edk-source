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
    this->classThis=NULL;
    this->Constructor();
}

edk::ViewGU2D::~ViewGU2D(){
    this->Destructor();
}

void edk::ViewGU2D::Constructor(){
    edk::ViewGU::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->camera.Constructor();

        this->camera.position=edk::vec2f32(0u,0u);
    }
}
void edk::ViewGU2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->camera.Destructor();
    }
    edk::ViewGU::Destructor();
}

void edk::ViewGU2D::updateAnimations(){
    this->camera.updateAnimations();
    edk::View::updateAnimations();
}
void edk::ViewGU2D::updateAnimations(edk::float32 seconds){
    this->camera.updateAnimations(seconds);
    edk::View::updateAnimations(seconds);
}

//draw the 2Dcamera
void edk::ViewGU2D::drawCamera2D(){
    //draw the camera2D
    this->camera.draw();
}
//draw selection camera
void edk::ViewGU2D::drawSelectionCamera(){
    this->camera.drawOrthoOnly();
}

//draw the polygon on the scene
void edk::ViewGU2D::drawPolygon(edk::rectf32 outsideViewOrigin){
    edk::ViewSpriteController::drawPolygon(outsideViewOrigin);

    //run selection function before draw the scene
    this->runSelectionFunction();

    this->drawCamera2D();

    //set the matrix before draw the scene
    edk::GU::guUseMatrix(GU_MODELVIEW);

    //draw the GU scene
    this->drawScene(outsideViewOrigin);

    edk::GU::guDisableAllLights();
}


//draw
void edk::ViewGU2D::drawScene(edk::rectf32 ){
    //
}
