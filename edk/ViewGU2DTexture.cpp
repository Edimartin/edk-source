#include "ViewGU2DTexture.h"

edk::ViewGU2DTexture::ViewGU2DTexture(edk::size2ui32 size)
    :edk::ViewGUTexture(size)
{
    //
    this->camera.position=edk::vec2f32(0u,0u);
}
edk::ViewGU2DTexture::ViewGU2DTexture(edk::uint32 width,edk::uint32 height)
    :edk::ViewGUTexture(width,height)
{
    //
}
edk::ViewGU2DTexture::~ViewGU2DTexture(){
    //
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
