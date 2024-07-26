#include "Camera2D.h"

/*
Library Camera2D - 2D camera in a 2D World
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
#pragma message "            Inside Camera2D.cpp"
#endif

edk::Camera2D::Camera2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::Camera2D::Camera2D(edk::vec2f32 position){
    this->classThis=NULL;edkEnd();
    this->Constructor(position,false);edkEnd();
}
edk::Camera2D::Camera2D(edk::float32 posX,edk::float32 posY){
    this->classThis=NULL;edkEnd();
    this->Constructor(posX,posY,false);edkEnd();
}

edk::Camera2D::~Camera2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::Camera2D::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;edkEnd();
        //construct the variables
        this->shakePosition=edk::vec2f32(0.f,0.f);edkEnd();
        this->shakeAngle=0.f;edkEnd();
        this->shakeDistance=0.f;
        this->runningShakePosition=false;edkEnd();
        this->runningShakeAngle=false;edkEnd();
        this->shakeSecondsInit=0.f;edkEnd();
        this->shakeRandomPercent=0.f;edkEnd();
        this->shakeInterpolationDistance=0.f;edkEnd();
        this->secondPassed=0.f;edkEnd();
        this->animPosition.Constructor();edkEnd();
        this->animAngle.Constructor();edkEnd();
        this->animShakingPosition.Constructor();edkEnd();
        this->animShakingAngle.Constructor();edkEnd();
        this->positionSave = this->position = edk::vec2f32(0.f,0.f);edkEnd();
        this->start();edkEnd();
    }
}
void edk::Camera2D::Constructor(edk::vec2f32 position,bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;edkEnd();
        this->shakePosition=edk::vec2f32(0.f,0.f);edkEnd();
        this->shakeAngle=0.f;edkEnd();
        this->shakeDistance=0.f;
        this->runningShakePosition=false;edkEnd();
        this->runningShakeAngle=false;edkEnd();
        this->shakeSecondsInit=0.f;edkEnd();
        this->shakeRandomPercent=0.f;edkEnd();
        this->shakeInterpolationDistance=0.f;edkEnd();
        this->secondPassed=0.f;edkEnd();
        this->animPosition.Constructor();edkEnd();
        this->animAngle.Constructor();edkEnd();
        this->animShakingPosition.Constructor();edkEnd();
        this->animShakingAngle.Constructor();edkEnd();
        this->start();edkEnd();
        //set the position
        this->positionSave = this->position = position;edkEnd();
    }
}
void edk::Camera2D::Constructor(edk::float32 posX,edk::float32 posY,bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;edkEnd();
        this->shakePosition=edk::vec2f32(0.f,0.f);edkEnd();
        this->shakeAngle=0.f;edkEnd();
        this->shakeDistance=0.f;
        this->runningShakePosition=false;edkEnd();
        this->runningShakeAngle=false;edkEnd();
        this->shakeSecondsInit=0.f;edkEnd();
        this->shakeRandomPercent=0.f;edkEnd();
        this->shakeInterpolationDistance=0.f;edkEnd();
        this->secondPassed=0.f;edkEnd();
        this->animPosition.Constructor();edkEnd();
        this->animAngle.Constructor();edkEnd();
        this->animShakingPosition.Constructor();edkEnd();
        this->animShakingAngle.Constructor();edkEnd();
        this->start();edkEnd();
        //set the position
        this->positionSave = this->position = edk::vec2f32(posX,posY);edkEnd();
    }
}

void edk::Camera2D::start(){
    //set the start position of the camera
    this->positionSave = this->position = edk::vec2f32(0.0f,0.0f);edkEnd();
    //set the screen to -1 1;edkEnd();
    this->setSize(1.0f,1.0f);edkEnd();
    //set the up
    this->up = edk::vec2f32(0,1);edkEnd();
    //set the start angle
    this->angle = 0.f;edkEnd();
}
//SETTERS
//set the size
void edk::Camera2D::setSize(edk::size2f32 size){
    //
    this->size=size*0.5f;edkEnd();
}
void edk::Camera2D::setSize(edk::float32 sizeW,edk::float32 sizeH){
    //
    return this->setSize(edk::size2f32(sizeW,sizeH));edkEnd();
}
void edk::Camera2D::setSizeW(edk::float32 width){
    this->size.width = width*0.5f;edkEnd();
}
void edk::Camera2D::setSizeH(edk::float32 height){
    this->size.height = height*0.5f;edkEnd();
}
//Set a rectangle to the camera
bool edk::Camera2D::setRect(edk::rectf32 rect){
    //test the size
    if(rect.size.width && rect.size.height){
        //set the position of the camera
        this->position.x = rect.origin.x + (rect.size.width*0.5f);edkEnd();
        this->position.y = rect.origin.y + (rect.size.height*0.5f);edkEnd();
        //copi the new size for the camera
        this->size = rect.size * 0.5f;edkEnd();

        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Camera2D::setRect(edk::vec2f32 origin,size2f32 size){
    //else return false
    return this->setRect(edk::rectf32(origin.x,origin.y,size.width,size.height));edkEnd();
}
bool edk::Camera2D::setRect(edk::float32 originX,edk::float32 originY,edk::float32 width,edk::float32 height){
    //else return false
    return this->setRect(edk::vec2f32(originX,originY),size2f32(width,height));edkEnd();
}
//Set the points of the camera in the world
bool edk::Camera2D::setPoints(edk::vec2f32 p1, edk::vec2f32 p2){
    //test if p2 is bigger than p1
    if(p2.x>p1.x && p2.y>p1.y){
        //set the size of the camera
        this->size = size2f32(p2.x-p1.x,p2.y-p1.y);edkEnd();
        //then set the position of the camera
        this->position = edk::vec2f32( p1.x + (this->size.width*0.5f)  , p1.y + (this->size.height*0.5f));edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Camera2D::setPoints(edk::float32 p1X,edk::float32 p1Y,edk::float32 p2X,edk::float32 p2Y){
    //
    return setPoints(edk::vec2f32(p1X,p1Y), edk::vec2f32(p2X,p2Y));edkEnd();
}
//save the position in the save buffer to calculate the distance
void edk::Camera2D::savePosition(){
    this->positionSave = this->position;edkEnd();
}
void edk::Camera2D::pastePosition(){
    this->position = this->positionSave;edkEnd();
}

//GETTERS
//get the size
edk::size2f32 edk::Camera2D::getSize(){
    //return the size double of the size
    return edk::size2f32(this->size*2);edkEnd();
}
//return the camera rect
edk::rectf32 edk::Camera2D::getRect(){
    return edk::rectf32(this->position.x - (this->size.width),this->position.y - (this->size.height),
                        this->position.x + this->size.width,this->position.y + this->size.height
                        );edkEnd();
}

//get the distance beetween the position and save distance
edk::float32 edk::Camera2D::getDistanceFromSave(){
    return edk::Math::pythagoras(this->getTranslateFromSave());edkEnd();
}
//get the camera translate from saveDistance
edk::vec2f32 edk::Camera2D::getTranslateFromSave(){
    return this->position - this->positionSave;edkEnd();
}


//draw the camera
void edk::Camera2D::draw(){
    //
    //test if are NOT using GUmodelview
    if(!edk::GU::guUsingMatrix(GU_PROJECTION)){
        //then set to use modelView
        edk::GU::guUseMatrix(GU_PROJECTION);edkEnd();
    }
    edk::GU::guLoadIdentity();edkEnd();

    this->drawOrthoOnly();edkEnd();
}
void edk::Camera2D::drawOrthoOnly(){
    edk::GU::guUseOrtho(-this->size.width,
                        this->size.width,
                        -this->size.height,
                        this->size.height,
                        -1.f,//nea
                        1.f//far
                        );edkEnd();
    //update the shaking animations

    //shake angle
    this->animShakeInitAngle.updateClockAnimation(this->secondPassed);
    if(this->runningShakeAngle || this->animShakeInitAngle.isPlaying()){
        edk::float32 secondPercent;
        if(this->animShakeInitAngle.isPlaying()){
            secondPercent = this->animShakeInitAngle.getClockX();
        }
        else{
            secondPercent=1.f;
        }

        this->shakeAngle = -90.f + (edk::Random::getStaticRandPercent() * 180.f);edkEnd();
        //rotate the angle
        this->up = edk::Math::rotatePlus(edk::vec2f32(1.f,0.f),180.f + (this->shakeAngle * this->shakeRandomPercent*secondPercent));edkEnd();

        this->shakeAngle = edk::Math::pythagoras(this->up);
    }
    else{
        this->animShakingAngle.updateClockAnimation();edkEnd();
        if(this->animShakingAngle.isPlaying()){
            //calculate the angle of shaking
            this->up = edk::Math::rotate(edk::vec2f32(1,0),(((this->angle + this->animShakingAngle.getClockX())*-1)+360.f)+90);edkEnd();
        }
        else{
            this->up = edk::Math::rotate(edk::vec2f32(1,0),((this->angle*-1)+360.f)+90);edkEnd();
        }
    }

    //shake position
    this->animShakeInitPosition.updateClockAnimation(this->secondPassed);
    if(this->runningShakePosition || this->animShakeInitPosition.isPlaying()){
        edk::float32 secondPercent;
        if(this->animShakeInitPosition.isPlaying()){
            secondPercent = this->animShakeInitPosition.getClockX();
        }
        else{
            secondPercent=1.f;
        }
        //get next position
        this->shakeAngle = -90.f + (edk::Random::getStaticRandPercent() * 180.f);edkEnd();
        //rotate the angle
        this->shakePosition = edk::Math::rotatePlus(this->shakePosition,180.f + (this->shakeAngle * this->shakeRandomPercent));edkEnd();
        this->tempPosition.x = this->position.x+(this->shakePosition.x*secondPercent);edkEnd();
        this->tempPosition.y = this->position.y+(this->shakePosition.y*secondPercent);edkEnd();
        edk::GU::guLookAt(this->tempPosition.x,this->tempPosition.y,1.f,
                          this->tempPosition.x,this->tempPosition.y,0.f,
                          this->up.x,this->up.y,0.f
                          );edkEnd();
    }
    else{
        if(this->animShakingPosition.isPlaying()){
            this->tempPosition.x = this->position.x+this->animShakingPosition.getClockX();edkEnd();
            this->tempPosition.y = this->position.y+this->animShakingPosition.getClockY();edkEnd();
            edk::GU::guLookAt(this->tempPosition.x,this->tempPosition.y,1.f,
                              this->tempPosition.x,this->tempPosition.y,0.f,
                              this->up.x,this->up.y,0.f
                              );edkEnd();
        }
        else{
            edk::GU::guLookAt(this->position.x,this->position.y,1.f,
                              this->position.x,this->position.y,0.f,
                              this->up.x,this->up.y,0.f
                              );edkEnd();
        }
    }
    this->secondPassed=0.f;
}
void edk::Camera2D::drawOrthoOnly(edk::float32 seconds){
    edk::GU::guUseOrtho(-this->size.width,
                        this->size.width,
                        -this->size.height,
                        this->size.height,
                        -1.f,//nea
                        1.f//far
                        );edkEnd();
    //update the shaking animations
    this->animAngle.updateClockAnimation(seconds);edkEnd();
    if(this->animAngle.isPlaying()){
        //calculate the angle of shaking
        this->up = edk::Math::rotate(edk::vec2f32(1,0),(((this->angle + this->animAngle.getClockX())*-1)+360.f)+90);edkEnd();
    }
    else{
        this->up = edk::Math::rotate(edk::vec2f32(1,0),((this->angle*-1)+360.f)+90);edkEnd();
    }

    //shake position
    this->animPosition.updateClockAnimation(seconds);edkEnd();
    if(this->animPosition.isPlaying()){
        this->tempPosition.x = this->position.x+this->animPosition.getClockX();edkEnd();
        this->tempPosition.y = this->position.y+this->animPosition.getClockY();edkEnd();
        edk::GU::guLookAt(this->tempPosition.x,this->tempPosition.y,1.f,
                          this->tempPosition.x,this->tempPosition.y,0.f,
                          this->up.x,this->up.y,0.f
                          );edkEnd();
    }
    else{
        edk::GU::guLookAt(this->position.x,this->position.y,1.f,
                          this->position.x,this->position.y,0.f,
                          this->up.x,this->up.y,0.f
                          );edkEnd();
    }
}


//move the camera
void edk::Camera2D::moveLeft(edk::float32 dist){
    //
    this->position.x-=dist;edkEnd();
}
void edk::Camera2D::moveLeft(edk::float64 dist){
    //
    this->position.x-=dist;edkEnd();
}
void edk::Camera2D::moveRight(edk::float32 dist){
    //
    this->position.x+=dist;edkEnd();
}
void edk::Camera2D::moveRight(edk::float64 dist){
    //
    this->position.x+=dist;edkEnd();
}
void edk::Camera2D::moveUp(edk::float32 dist){
    //
    this->position.y+=dist;edkEnd();
}
void edk::Camera2D::moveUp(edk::float64 dist){
    //
    this->position.y+=dist;edkEnd();
}
void edk::Camera2D::moveDown(edk::float32 dist){
    //
    this->position.y-=dist;edkEnd();
}
void edk::Camera2D::moveDown(edk::float64 dist){
    //
    this->position.y-=dist;edkEnd();
}
void edk::Camera2D::move(edk::vec2f32 position){
    this->position+=position;edkEnd();
}
void edk::Camera2D::move(edk::float32 x,edk::float32 y){
    this->move(edk::vec2f32(x,y));edkEnd();
}

void edk::Camera2D::scaleX(edk::float32 dist){
    //
    this->size.width+=dist*0.5f;edkEnd();
}
void edk::Camera2D::scaleX(edk::float64 dist){
    //
    this->size.width+=dist*0.5f;edkEnd();
}
void edk::Camera2D::scaleY(edk::float32 dist){
    //
    this->size.height+=dist*0.5f;edkEnd();
}
void edk::Camera2D::scaleY(edk::float64 dist){
    //
    this->size.height+=dist*0.5f;edkEnd();
}
//set camera angle
void edk::Camera2D::setAngle(edk::float32 angle){
    //set the angle
    this->angle = angle;edkEnd();
    while(this->angle>360.f){
        this->angle-=360.f;edkEnd();
    }
    while(this->angle<0.f){
        this->angle+=360.f;edkEnd();
    }
}
//rotate the camera
void edk::Camera2D::rotateCamera(edk::float32 angle){
    this->setAngle(this->angle+angle);edkEnd();
}
//get the camera angle
edk::float32 edk::Camera2D::getAngle(){
    return this->angle;edkEnd();
}

//pause the animations
void edk::Camera2D::pauseAnim(){
    this->animAngle.pause();
    this->animPosition.pause();
    this->animShakeInitAngle.pause();
    this->animShakingPosition.pause();
}
void edk::Camera2D::pauseAnimOn(){
    this->animAngle.pause();
    this->animPosition.pause();
    this->animShakeInitAngle.pause();
    this->animShakingPosition.pause();
}
void edk::Camera2D::pauseAnimOff(){
    this->animAngle.pause();
    this->animPosition.pause();
    this->animShakeInitAngle.pause();
    this->animShakingPosition.pause();
}
bool edk::Camera2D::isPausedAnim(){
    return this->animAngle.isPaused();
}

//update the camera animations
void edk::Camera2D::updateAnimations(){
    this->secondPassed = this->clock.getSeconds();
    this->clock.start();
    this->animPosition.updateClockAnimation(this->secondPassed);edkEnd();
    this->animAngle.updateClockAnimation(this->secondPassed);edkEnd();
    if(this->animPosition.isPlaying()){
        this->position.x = this->animPosition.getClockX();edkEnd();
        this->position.y = this->animPosition.getClockY();edkEnd();
    }
    if(this->animAngle.isPlaying()){
        this->angle = this->animAngle.getClockX();edkEnd();
    }
}
void edk::Camera2D::updateAnimations(edk::float32 seconds){
    this->animPosition.updateClockAnimation(seconds);edkEnd();
    this->animAngle.updateClockAnimation(seconds);edkEnd();
    if(this->animPosition.isPlaying()){
        this->position.x = this->animPosition.getClockX();edkEnd();
        this->position.y = this->animPosition.getClockY();edkEnd();
    }
    if(this->animAngle.isPlaying()){
        this->angle = this->animAngle.getClockX();edkEnd();
    }
    this->secondPassed = seconds;
    this->clock.start();
}

//start the animation
bool edk::Camera2D::addShakingAngle(edk::float32 angle,
                                    edk::float32 percent,
                                    edk::float32 interpolationDistance
                                    ){
    //stop the last animation
    this->animShakingAngle.stop();edkEnd();
    this->animShakingAngle.cleanAnimations();edkEnd();
    //create the shaking animation
    if(this->animShakingAngle.addShakingFramesX(angle,percent,interpolationDistance)){
        this->animShakingAngle.playForward();edkEnd();
        //return true;
        return true;
    }
    return false;
}
bool edk::Camera2D::addShakingPosition(edk::vec2f32 position,
                                       edk::float32 randomPercent,
                                       edk::float32 percent,
                                       edk::float32 interpolationDistance
                                       ){
    //stop the last animation
    this->animShakingPosition.stop();edkEnd();
    this->animShakingPosition.cleanAnimations();edkEnd();
    //create the shaking animation
    if(this->animShakingPosition.addShakingFramesXY(position,randomPercent,percent,interpolationDistance)){
        this->animShakingPosition.playForward();edkEnd();
        //return true;
        return true;
    }
    return false;
}

//start and end shakking
bool edk::Camera2D::startShakeAngle(edk::float32 angle,
                                    edk::float32 secondsInit,
                                    edk::float32 interpolationDistance
                                    ){
    this->shakeAngle=angle;
    this->shakeInterpolationDistance=interpolationDistance;
    this->animShakeInitAngle.clean();
    this->animShakeInitAngle.addFirstInterpolationLine(0.f,0.f,secondsInit,1.f);
    this->animShakeInitAngle.restartForward();
    this->shakeDistance = edk::Math::pythagoras(position);
    if(!this->runningShakeAngle){
        this->runningShakeAngle=true;
        return true;
    }
    return false;
}
bool edk::Camera2D::stopShakeAngle(edk::float32 secondsEnd){
    //test if are running
    if(this->runningShakeAngle){
        this->runningShakeAngle=false;
        this->animShakeInitAngle.clean();
        this->animShakeInitAngle.addFirstInterpolationLine(0.f,0.f,secondsEnd,1.f);
        this->animShakeInitAngle.restartRewind();
/*
        //add a new shake position
        return this->addShakingAngle(this->shakeAngle,
                                     0.9f,
                                     this->shakeInterpolationDistance
                                     );
*/
    }
    return false;
}
bool edk::Camera2D::stopShakeAngle(){
    //test if are running
    if(this->runningShakeAngle){
        this->runningShakeAngle=false;
        this->animShakeInitAngle.restartRewind();
        return true;
    }
    return false;
}
bool edk::Camera2D::isShakingAngle(){
    return (this->runningShakeAngle || this->animShakeInitAngle.isPlaying());
}
bool edk::Camera2D::startShakePosition(edk::vec2f32 position,
                                       edk::float32 randomPercent,
                                       edk::float32 secondsInit,
                                       edk::float32 interpolationDistance
                                       ){
    this->shakeAngle = edk::Math::getAngle(position);
    this->shakePosition=position;
    this->shakeRandomPercent=randomPercent;
    this->shakeInterpolationDistance=interpolationDistance;
    this->animShakeInitPosition.clean();
    this->animShakeInitPosition.addFirstInterpolationLine(0.f,0.f,secondsInit,1.f);
    this->animShakeInitPosition.restartForward();
    if(!this->runningShakePosition){
        this->runningShakePosition=true;
        return true;
    }
    return false;
}
bool edk::Camera2D::stopShakePosition(edk::float32 secondsEnd){
    //test if are running
    if(this->runningShakePosition){
        this->runningShakePosition=false;
        this->animShakeInitPosition.clean();
        this->animShakeInitPosition.addFirstInterpolationLine(0.f,0.f,secondsEnd,1.f);
        this->animShakeInitPosition.restartRewind();
        return true;
    }
    return false;
}
bool edk::Camera2D::stopShakePosition(){
    //test if are running
    if(this->runningShakePosition){
        this->runningShakePosition=false;
        this->animShakeInitPosition.restartRewind();
        return true;
    }
    return false;
}
bool edk::Camera2D::isShakingPosition(){
    return (this->runningShakePosition || this->animShakeInitPosition.isPlaying());
}

//operator to copy the cameras
bool edk::Camera2D::cloneFrom(edk::Camera2D* cam){
    if(cam){
        this->size = cam->size;edkEnd();
        return true;
    }
    return false;
}
