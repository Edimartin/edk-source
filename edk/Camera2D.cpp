#include "Camera2D.h"

/*
Library Camera2D - 2D camera in a 2D World
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
#warning "            Inside Camera2D.cpp"
#endif

using namespace edk;
edk::Camera2D::Camera2D(){
    //
    this->start();
}
edk::Camera2D::Camera2D(edk::vec2f32 position){
    //
    this->start();
    //set the position
    this->position = position;
}
edk::Camera2D::Camera2D(edk::float32 posX,edk::float32 posY){
    //
    this->start();
    //set the position
    this->position = edk::vec2f32(posX,posY);
}

edk::Camera2D::~Camera2D(){
    //dtor
}
void edk::Camera2D::start(){
    //set the start position of the camera
    this->position = edk::vec2f32(0.0f,0.0f);
    //set the screen to -1 1;
    this->setSize(1.0f,1.0f);
    //set the up
    this->up = edk::vec2f32(0,1);
    //set the start angle
    this->angle = 0.f;
}
//SETTERS
//set the size
void edk::Camera2D::setSize(edk::size2f32 size){
    //
    this->size=size*0.5f;
}
void edk::Camera2D::setSize(edk::float32 sizeW,edk::float32 sizeH){
    //
    return this->setSize(edk::size2f32(sizeW,sizeH));
}
void edk::Camera2D::setSizeW(edk::float32 width){
    this->size.width = width*0.5f;
}
void edk::Camera2D::setSizeH(edk::float32 height){
    this->size.height = height*0.5f;
}
//Set a rectangle to the camera
bool edk::Camera2D::setRect(edk::rectf32 rect){
    //test the size
    if(rect.size.width && rect.size.height){
        //set the position of the camera
        this->position.x = rect.origin.x + (rect.size.width*0.5f);
        this->position.y = rect.origin.y + (rect.size.height*0.5f);
        //copi the new size for the camera
        this->size = rect.size * 0.5f;

        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Camera2D::setRect(edk::vec2f32 origin,size2f32 size){
    //else return false
    return this->setRect(edk::rectf32(origin.x,origin.y,size.width,size.height));
}
bool edk::Camera2D::setRect(edk::float32 originX,edk::float32 originY,edk::float32 width,edk::float32 height){
    //else return false
    return this->setRect(edk::vec2f32(originX,originY),size2f32(width,height));
}
//Set the points of the camera in the world
bool edk::Camera2D::setPoints(edk::vec2f32 p1, edk::vec2f32 p2){
    //test if p2 is bigger than p1
    if(p2.x>p1.x && p2.y>p1.y){
        //set the size of the camera
        this->size = size2f32(p2.x-p1.x,p2.y-p1.y);
        //then set the position of the camera
        this->position = edk::vec2f32( p1.x + (this->size.width*0.5f)  , p1.y + (this->size.height*0.5f));
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Camera2D::setPoints(edk::float32 p1X,edk::float32 p1Y,edk::float32 p2X,edk::float32 p2Y){
    //
    return setPoints(edk::vec2f32(p1X,p1Y), edk::vec2f32(p2X,p2Y));
}
//GETTERS
//get the size
edk::size2f32 edk::Camera2D::getSize(){
    //return the size double of the size
    return edk::size2f32(this->size*2);
}
//return the camera rect
edk::rectf32 edk::Camera2D::getRect(){
    return edk::rectf32(this->position.x - (this->size.width),this->position.y - (this->size.height),
                        this->size.width*2.f,this->size.height*2.f
                        );
}


//draw the camera
void edk::Camera2D::draw(){
    //
    //test if are NOT using GUmodelview
    if(!edk::GU::guUsingMatrix(GU_PROJECTION))
        //then set to use modelView
        edk::GU::guUseMatrix(GU_PROJECTION);
    edk::GU::guLoadIdentity();

    this->drawOrthoOnly();
}
void edk::Camera2D::drawOrthoOnly(){
    edk::GU::guUseOrtho(-this->size.width,
                        this->size.width,
                        -this->size.height,
                        this->size.height,
                        -1.f,//nea
                        1.f//far
                        );
    //update the shaking animations
    this->animAngle.updateClockAnimation();
    if(this->animAngle.isPlaying()){
        //calculate the angle of shaking
        this->up = edk::Math::rotate2f(edk::vec2f32(1,0),(((this->angle + this->animAngle.getClockX())*-1)+360.f)+90);
    }
    else{
        this->up = edk::Math::rotate2f(edk::vec2f32(1,0),((this->angle*-1)+360.f)+90);
    }

    //shake position
    this->animPosition.updateClockAnimation();
    if(this->animPosition.isPlaying()){
        this->tempPosition.x = this->position.x+this->animPosition.getClockX();
        this->tempPosition.y = this->position.y+this->animPosition.getClockY();
        edk::GU::guLookAt(this->tempPosition.x,this->tempPosition.y,1.f,
                          this->tempPosition.x,this->tempPosition.y,0.f,
                          this->up.x,this->up.y,0.f
                          );
    }
    else{
        edk::GU::guLookAt(this->position.x,this->position.y,1.f,
                          this->position.x,this->position.y,0.f,
                          this->up.x,this->up.y,0.f
                          );
    }
}
void edk::Camera2D::drawOrthoOnly(edk::float32 seconds){
    edk::GU::guUseOrtho(-this->size.width,
                        this->size.width,
                        -this->size.height,
                        this->size.height,
                        -1.f,//nea
                        1.f//far
                        );
    //update the shaking animations
    this->animAngle.updateClockAnimation(seconds);
    if(this->animAngle.isPlaying()){
        //calculate the angle of shaking
        this->up = edk::Math::rotate2f(edk::vec2f32(1,0),(((this->angle + this->animAngle.getClockX())*-1)+360.f)+90);
    }
    else{
        this->up = edk::Math::rotate2f(edk::vec2f32(1,0),((this->angle*-1)+360.f)+90);
    }

    //shake position
    this->animPosition.updateClockAnimation(seconds);
    if(this->animPosition.isPlaying()){
        this->tempPosition.x = this->position.x+this->animPosition.getClockX();
        this->tempPosition.y = this->position.y+this->animPosition.getClockY();
        edk::GU::guLookAt(this->tempPosition.x,this->tempPosition.y,1.f,
                          this->tempPosition.x,this->tempPosition.y,0.f,
                          this->up.x,this->up.y,0.f
                          );
    }
    else{
        edk::GU::guLookAt(this->position.x,this->position.y,1.f,
                          this->position.x,this->position.y,0.f,
                          this->up.x,this->up.y,0.f
                          );
    }
}


//move the camera
void edk::Camera2D::moveLeft(edk::float32 dist){
    //
    this->position.x-=dist;
}
void edk::Camera2D::moveLeft(edk::float64 dist){
    //
    this->position.x-=dist;
}
void edk::Camera2D::moveRight(edk::float32 dist){
    //
    this->position.x+=dist;
}
void edk::Camera2D::moveRight(edk::float64 dist){
    //
    this->position.x+=dist;
}
void edk::Camera2D::moveUp(edk::float32 dist){
    //
    this->position.y+=dist;
}
void edk::Camera2D::moveUp(edk::float64 dist){
    //
    this->position.y+=dist;
}
void edk::Camera2D::moveDown(edk::float32 dist){
    //
    this->position.y-=dist;
}
void edk::Camera2D::moveDown(edk::float64 dist){
    //
    this->position.y-=dist;
}
void edk::Camera2D::move(edk::vec2f32 position){
    this->position+=position;
}
void edk::Camera2D::move(edk::float32 x,edk::float32 y){
    this->move(edk::vec2f32(x,y));
}

void edk::Camera2D::scaleX(edk::float32 dist){
    //
    this->size.width+=dist*0.5f;
}
void edk::Camera2D::scaleX(edk::float64 dist){
    //
    this->size.width+=dist*0.5f;
}
void edk::Camera2D::scaleY(edk::float32 dist){
    //
    this->size.height+=dist*0.5f;
}
void edk::Camera2D::scaleY(edk::float64 dist){
    //
    this->size.height+=dist*0.5f;
}
//set camera angle
void edk::Camera2D::setAngle(edk::float32 angle){
    //set the angle
    this->angle = angle;
    while(this->angle>360.f)this->angle-=360.f;
    while(this->angle<0.f)this->angle+=360.f;
}
//rotate the camera
void edk::Camera2D::rotateCamera(edk::float32 angle){
    this->setAngle(this->angle+angle);
}
//get the camera angle
edk::float32 edk::Camera2D::getAngle(){
    return this->angle;
}

//start the animation
bool edk::Camera2D::addShakingAngle(edk::float32 position,edk::float32 percent,edk::float32 interpolationDistance){
    //stop the last animation
    this->animAngle.stop();
    this->animAngle.cleanAnimations();
    //create the shaking animation
    if(this->animAngle.addShakingFramesX(position,percent,interpolationDistance)){
        this->animAngle.playForward();
        //return true;
        return true;
    }
    return false;
}
bool edk::Camera2D::addShakingPosition(edk::vec2f32 position,edk::float32 random,edk::float32 percent,edk::float32 interpolationDistance){
    //stop the last animation
    this->animPosition.stop();
    this->animPosition.cleanAnimations();
    //create the shaking animation
    if(this->animPosition.addShakingFramesXY(position,random,percent,interpolationDistance)){
        this->animPosition.playForward();
        //return true;
        return true;
    }
    return false;
}

//operator to copy the cameras
bool edk::Camera2D::cloneFrom(edk::Camera2D* cam){
    if(cam){
        this->size = cam->size;
        return true;
    }
    return false;
}
