#include "ViewGU.h"

/*
Library C++ viewGU - Render GU elements inside this view in Edk Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside ViewGU.cpp"
#endif

edk::ViewGU::ViewGU()
{
    //ctor
}

edk::ViewGU::~ViewGU()
{
    //dtor
}
//return true if is a GU View
bool edk::ViewGU::isGU(){
    //return true because its a GU View
    return true;
}
//Draw Functions
//draw viewPort
void edk::ViewGU::drawViewport(rectf32 outsideViewOrigin){
    //
    edk::ViewSpriteController::drawViewport(outsideViewOrigin);
}
//draw Camera
void edk::ViewGU::drawCamera(){
    //
    edk::ViewSpriteController::drawCamera();
}
//draw the polygon on the scene
void edk::ViewGU::drawPolygon(rectf32 outsideViewOrigin){
    //
    edk::ViewSpriteController::drawPolygon(outsideViewOrigin);

    //Draw the camera in the future

    //then draw the scene
    this->drawScene(outsideViewOrigin);

    edk::GU::guDisableAllLights();
}

//load the background
bool edk::ViewGU::loadBackground(const char* name){
    //
    return this->loadSprite(name);
}
bool edk::ViewGU::loadBackground(edk::char8* name){
    //
    return this->loadSprite(name);
}

//delete the background
void edk::ViewGU::deleteBackground(){
    //
    this->deleteSprite();
}

//draw the GU scene
void edk::ViewGU::drawScene(rectf32 outsideViewOrigin){
    //
}
void edk::ViewGU::update(edk::WindowEvents* events){
    //
    edk::View::update(events);
}
