#include "ViewGU3DTexture.h"

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
#pragma message "            Inside ViewGU3DTexture.cpp"
#endif

edk::ViewGU3DTexture::ViewGU3DTexture(edk::size2ui32 size)
    :edk::ViewGUTexture(size)
{
    this->classThis=NULL;
    this->Constructor(size);
}
edk::ViewGU3DTexture::ViewGU3DTexture(edk::uint32 width,edk::uint32 height)
    :edk::ViewGUTexture(width,height)
{
    this->classThis=NULL;
    this->Constructor(width,height);
}
edk::ViewGU3DTexture::~ViewGU3DTexture(){
    this->Destructor();
}

void edk::ViewGU3DTexture::Constructor(edk::size2ui32 size){
    edk::ViewGUTexture::Constructor(size);
    if(this->classThis!=this){
        this->classThis=this;

        this->camera.Constructor();

        this->camera.position=edk::vec3f32(0u,0u,0u);
    }
}
void edk::ViewGU3DTexture::Constructor(edk::uint32 width,edk::uint32 height){
    edk::ViewGUTexture::Constructor(width,height);
    if(this->classThis!=this){
        this->classThis=this;

        this->camera.Constructor();

    }
}
void edk::ViewGU3DTexture::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->camera.Destructor();
    }
    edk::ViewGUTexture::Destructor();
}

void edk::ViewGU3DTexture::updateAnimations(){
    this->camera.updateAnimations();
    edk::View::updateAnimations();
}
void edk::ViewGU3DTexture::updateAnimations(edk::float32 seconds){
    this->camera.updateAnimations(seconds);
    edk::View::updateAnimations(seconds);
}

//draw the 2Dcamera
void edk::ViewGU3DTexture::drawCamera3D(){
    //
    edk::GU::guUseMatrix(GU_PROJECTION);
    //draw the camera2D
    this->camera.draw();
}
//draw selection camera
void edk::ViewGU3DTexture::drawSelectionCamera(){
    //
    this->camera.drawAxisOnly();
}
//draw the polygon on the scene
void edk::ViewGU3DTexture::drawPolygon(rectf32 outsideViewOrigin){
    //
    //edk::ViewSpriteController::drawPolygon(outsideViewOrigin);
    this->drawCamera3D();

    //set the matrix before draw the scene
    edk::GU::guUseMatrix(GU_MODELVIEW);

    //Load the identity
    edk::GU::guLoadIdentity();

    edk::GU::guEnable(GU_CULL_FACE);
    edk::GU::guEnable(GU_DEPTH_TEST);

    //edk::GU::guCullFace(GU_FRONT_AND_BACK);
    edk::GU::guCullFace(GU_BACK);

    edk::GU::guDepthFunc(GU_LEQUAL);

    edk::GU::guDepthRange(0.0f, 1.0f);

    edk::GU::guClear(GU_DEPTH_BUFFER_BIT);
    //draw the GU scene
    this->drawScene(outsideViewOrigin);

    edk::GU::guDisable(GU_DEPTH_TEST);
    edk::GU::guDisable(GU_CULL_FACE);

    edk::GU::guDisableAllLights();
}

//change point position beetween screen and world
edk::vec2f32 edk::ViewGU3DTexture::positionScreenToWorld(edk::vec2f32 position){
    edk::rectf32 rectCam = this->camera.getRectPoints();
    if(edk::Math::equal(0.f,this->frame.size.width)
            || edk::Math::equal(0.f,this->frame.size.height)
            ){
        return edk::vec2f32(((position.x/(this->frame.size.width+0.001f))*this->camera.getSize().width)
                            + rectCam.origin.x
                            ,
                            ((((position.y/(this->frame.size.height+0.001f))*-1.f)+1.f)*this->camera.getSize().height)
                            + rectCam.origin.y
                            );
    }
    else{
        return edk::vec2f32(((position.x/this->frame.size.width)*this->camera.getSize().width)
                            + rectCam.origin.x
                            ,
                            ((((position.y/this->frame.size.height)*-1.f)+1.f)*this->camera.getSize().height)
                            + rectCam.origin.y
                            );
    }
}
edk::vec2f32 edk::ViewGU3DTexture::positionScreenToWorld(edk::float32 x,edk::float32 y){
    return this->positionScreenToWorld(edk::vec2f32(x,y));
}
edk::vec2f32 edk::ViewGU3DTexture::positionWorldToScreen(edk::vec2f32 position){
    edk::rectf32 rectCam = this->camera.getRectPoints();
    if(edk::Math::equal(0.f,this->camera.getSize().width)
            || edk::Math::equal(0.f,this->camera.getSize().height)
            ){
        return edk::vec2f32((((position.x - rectCam.origin.x) / (this->camera.getSize().width+0.001f))
                             * (this->frame.size.width - this->frame.origin.x))
                            ,
                            (((((position.y - rectCam.origin.y) / (this->camera.getSize().height+0.001f)) * -1.f)+1.f)
                             * (this->frame.size.height - this->frame.origin.y))
                            );
    }
    else{
        return edk::vec2f32((((position.x - rectCam.origin.x) / this->camera.getSize().width)
                             * (this->frame.size.width - this->frame.origin.x))
                            ,
                            (((((position.y - rectCam.origin.y) / this->camera.getSize().height) * -1.f)+1.f)
                             * (this->frame.size.height - this->frame.origin.y))
                            );
    }
}
edk::vec2f32 edk::ViewGU3DTexture::positionWorldToScreen(edk::float32 x,edk::float32 y){
    return this->positionWorldToScreen(edk::vec2f32(x,y));
}
