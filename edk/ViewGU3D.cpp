#include "ViewGU3D.h"

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
