#include "ViewGU2DTexture.h"

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

edk::ViewGU2DTexture::ViewGU2DTexture(edk::size2ui32 size)
    :edk::ViewGUTexture(size)
{
    this->classThis=NULL;
    this->Constructor(size);
}
edk::ViewGU2DTexture::ViewGU2DTexture(edk::uint32 width,edk::uint32 height)
    :edk::ViewGUTexture(width,height)
{
    this->classThis=NULL;
    this->Constructor(width,height);
}
edk::ViewGU2DTexture::~ViewGU2DTexture(){
    this->Destructor();
}

void edk::ViewGU2DTexture::Constructor(edk::size2ui32 size){
    edk::ViewGUTexture::Constructor(size);
    if(this->classThis!=this){
        this->classThis=this;

        this->camera.Constructor();

        this->camera.position=edk::vec2f32(0u,0u);
    }
}
void edk::ViewGU2DTexture::Constructor(edk::uint32 width,edk::uint32 height){
    edk::ViewGUTexture::Constructor(width,height);
    if(this->classThis!=this){
        this->classThis=this;

        this->camera.Constructor();

    }
}
void edk::ViewGU2DTexture::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->camera.Destructor();
    }
    edk::ViewGUTexture::Destructor();
}

void edk::ViewGU2DTexture::updateAnimations(){
    this->camera.updateAnimations();
    edk::View::updateAnimations();
}
void edk::ViewGU2DTexture::updateAnimations(edk::float32 seconds){
    this->camera.updateAnimations(seconds);
    edk::View::updateAnimations(seconds);
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
