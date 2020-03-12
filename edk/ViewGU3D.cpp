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

    //draw the GU scene
    this->drawScene(outsideViewOrigin);

    edk::GU::guDisableAllLights();
}

//draw the GU scene
void edk::ViewGU3D::drawScene(edk::rectf32){
    //
}
