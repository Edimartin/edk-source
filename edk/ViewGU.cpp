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
    this->runSelection=false;
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

    this->runSelectionfunction();

    edk::GU::guDisableAllLights();
}
//draw selection camera
void edk::ViewGU::drawSelectionCamera(){
    //
}
//process the selection
void edk::ViewGU::processHits(edk::uint32 hits, edk::uint32 buffer[]){
    edk::uint32 i, j;
    edk::uint32 names, *ptr;
    edk::float32 near=0.f,far=0.f;
    //stack with names
    edk::vector::Stack<edk::uint32> nameStack;

    ptr = (GLuint *) buffer;
    for (i = 0; i < hits; i++) {  /* for each hit  */
        nameStack.clean();
        names = *ptr;
        ptr++;
        near = (edk::float32)*ptr/0x7fffffff;
        ptr++;
        far = (edk::float32)*ptr/0x7fffffff;
        ptr++;
        for (j = 0; j < names; j++) {  /* for each name */
            nameStack.pushBack(*ptr);
            ptr++;
        }
        //run the function
        this->selectObject(i,hits,near,far,&nameStack);
    }
}
//run selection function
void edk::ViewGU::runSelectionfunction(){
    //test if need run the selection
    if(this->runSelection){
        //
        this->runSelection=false;

        edk::uint32 buffer[100u];
        edk::GU::guSetSelectionBuffer(100u,buffer);

        edk::GU::guUseMatrix(GU_PROJECTION);
        edk::GU::guLoadIdentity();

        edk::GU::guRenderMode(GU_SELECT);

        edk::GU::guInitNames();

        //set pick buffer
        edk::GU::guPickMatrix((edk::float64)this->selectionPosition.x,(edk::float64)this->selectionPosition.y,
                              this->selectionSize.width,this->selectionSize.height
                              );

        this->drawSelectionCamera();

        edk::GU::guDisable(GU_TEXTURE);
        edk::GU::guDisable(GU_LIGHTING);

        //draw the polygon with UV Map
        edk::GU::guUseMatrix(GU_MODELVIEW);

        this->drawSelectionScene();

        edk::uint32 total = edk::GU::guRenderMode(GU_RENDER);
        this->processHits(total,buffer);
    }
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

//test the selection
void edk::ViewGU::testSelection(edk::vec2f32 position,edk::size2f32 size){
    //
    this->runSelection = true;
    this->selectionPosition = edk::vec2f32(position.x,(position.y*-1)+this->frame.size.height);
    this->selectionSize = size;
}
//process the selection
void edk::ViewGU::selectObject(edk::uint32 ,edk::uint32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* ){
    //
}

//draw the GU scene
void edk::ViewGU::drawScene(edk::rectf32){
    //
}
void edk::ViewGU::drawSelectionScene(){
    //
}

void edk::ViewGU::update(edk::WindowEvents* events){
    //
    edk::View::update(events);
}
