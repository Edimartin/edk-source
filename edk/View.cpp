#include "View.h"

/*
Library C++ edkView - Viewport used in Edk Game Engine
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
#pragma message "            Inside View.cpp"
#endif

#include <stdio.h>

edk::View::View(){
    this->frame = edk::rectf32(0.f,0.f,0.f,0.f);edkEnd();
    this->positionInWindow=this->frame.origin;edkEnd();
    this->animatedFrame = this->frame;edkEnd();
    //set color to white
    this->backgroundColor = edk::color4f32(1,1,1,1);edkEnd();
    //set to show view
    this->hide=false;edkEnd();
    this->paused=false;edkEnd();
    this->mouseInside=false;edkEnd();
    this->borderSize=0.f;edkEnd();
    this->borderTemp=0.f;edkEnd();
    this->mousePos = edk::vec2f32(0,0);edkEnd();
    this->saveOutsideFrame=0.f;edkEnd();
}

edk::View::View(edk::rectf32 frame){
    this->frame = frame;edkEnd();
    this->positionInWindow=this->frame.origin;edkEnd();
    this->animatedFrame = this->frame;edkEnd();
    //set color to white
    this->backgroundColor = edk::color4f32(1,1,1,1);edkEnd();
    //set to show view
    this->hide=false;edkEnd();
    this->paused=false;edkEnd();
    this->mouseInside=false;edkEnd();
    this->borderSize=0.0;
    this->borderTemp=0.f;edkEnd();
}

edk::View::~View(){
    //
}

//Draw Functions
//draw viewPort
void edk::View::drawViewport(edk::rectf32 outsideViewOrigin){
    //DRAW VIEWPORT
    //test if are using the modelView
    if(!edk::GU::guUsingMatrix(GU_MODELVIEW)){
        edk::GU::guUseMatrix(GU_MODELVIEW);edkEnd();
    }
    //First create the view in GU
    rectTemp = edk::rectf32((edk::int32)(outsideViewOrigin.origin.x + this->animatedFrame.origin.x)
                            ,(edk::int32)( outsideViewOrigin.origin.y + outsideViewOrigin.size.height - this->animatedFrame.origin.y - this->animatedFrame.size.height)
                            ,(edk::int32)this->animatedFrame.size.width
                            ,(edk::int32)this->animatedFrame.size.height
                            );edkEnd();
    //Set the viewport
    edk::GU::guSetViewport((edk::uint32)rectTemp.origin.x
                           ,(edk::uint32)rectTemp.origin.y
                           ,(edk::uint32)this->animatedFrame.size.width
                           ,(edk::uint32)this->animatedFrame.size.height
                           );edkEnd();

    //set the viewPort Color
    edk::GU::guColor4f32(this->backgroundColor);edkEnd();
}
//draw Camera
void edk::View::drawCamera(){
    //DRAW THE VIEW CAMERA
    //Use the projection matrix to set the camera
    edk::GU::guUseMatrix(GU_PROJECTION);edkEnd();
    //Load the identity
    edk::GU::guLoadIdentity();edkEnd();
    //Set the ortho camera
    edk::GU::guUseOrtho(0,1,0,1,-1,1);edkEnd();
}
//draw the polygon on the scene
void edk::View::drawPolygon(edk::rectf32){
    //DRAW THE POLYGON
    //Set the modelView matrix to draw the polygon
    //edk::GU::guUseMatrix(GU_MODELVIEW);edkEnd();

    //Draw a quadrangle
    edk::GU::guBegin(GU_QUADS);edkEnd();
    edk::GU::guVertex3f32(0.f, 0.f, 0.f);edkEnd();
    edk::GU::guVertex3f32(1.f, 0.f, 0.f);edkEnd();
    edk::GU::guVertex3f32(1.f, 1.f, 0.f);edkEnd();
    edk::GU::guVertex3f32(0.f, 1.f, 0.f);edkEnd();
    edk::GU::guEnd();edkEnd();
}
//those functions run the other functions
void edk::View::runDraw(edk::rectf32 outsideViewOrigin){
    //test if the outsideViewOrigin is different then the saveFrame
    if(this->saveOutsideFrame != outsideViewOrigin){
        this->saveOutsideFrame = outsideViewOrigin;edkEnd();
        //run the resize function
        this->resize(outsideViewOrigin);edkEnd();
    }
    this->draw(outsideViewOrigin);edkEnd();
}
void edk::View::runLoad(edk::rectf32 outsideViewOrigin){
    this->paused=false;edkEnd();
    //save the first outsideViewOrigin
    this->saveOutsideFrame = outsideViewOrigin;edkEnd();
    //run the resize function
    this->resize(outsideViewOrigin);edkEnd();
    //then run load
    this->load(outsideViewOrigin);edkEnd();
}
void edk::View::runUnload(){
    this->paused=false;edkEnd();
    this->unload();edkEnd();
}
void edk::View::runUpdate(edk::WindowEvents* events){
    this->update(events);edkEnd();
}
//run the pause function
void edk::View::runPause(){
    this->paused=true;edkEnd();
    //
    this->pause();edkEnd();
}
//run the unpause functin
void edk::View::runUnpause(){
    this->paused=false;edkEnd();
    //
    this->unpause();edkEnd();
}
//run the pauseSwitch
void edk::View::runPauseSwitch(){
    if(this->paused){
        this->runUnpause();edkEnd();
    }
    else{
        this->runPause();edkEnd();
    }
}

void edk::View::draw(edk::rectf32 outsideViewOrigin){
    //test if it's not hided
    if(!this->hide){
        //Then draw
        this->drawViewport(outsideViewOrigin);edkEnd();

        //draw the viewCamera
        this->drawCamera();edkEnd();

        //DRAW THE POLYGON
        //Set the modelView matrix to draw the polygon
        edk::GU::guUseMatrix(GU_MODELVIEW);edkEnd();
        edk::GU::guPushMatrix();edkEnd();

        //draw the polygon in the view
        this->drawPolygon(outsideViewOrigin);edkEnd();
        edk::GU::guPopMatrix();edkEnd();
        /*
        //Draw the nextView
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            //test if the view exist
            if(this->nexts[i]){
                //then draw using the view in GU. no in EDK
                this->nexts[i]->draw(
                                    edk::rectf32(
                                                rectTemp.origin.x,
                                                rectTemp.origin.y,
                                                rectTemp.size.width,
                                                rectTemp.size.height
                                                )
                                    );edkEnd();
            }
        }
*/
    }
}
void edk::View::resize(edk::rectf32 /*outsideViewOrigin*/){
    //
}

void edk::View::load(rectf32){
    //
}
void edk::View::unload(){
    //
}

void edk::View::update(edk::WindowEvents*){
    //update the animation
}

void edk::View::pause(){
    //pause the view
}
void edk::View::unpause(){
    //unpause the view
}
void edk::View::updateAnimations(){
    if(!this->animationPosition.isPaused()){
        //clean the animatedFrame
        this->animatedFrame=this->frame;edkEnd();
        this->animationPosition.updateClockAnimation();edkEnd();
        if(this->animationPosition.isPlaying()){
            //update
            //printf("\n                     Second %.2f",this->animationPosition.updateClockAnimation());edkEnd();
            edk::vec2f32 posTemp;edkEnd();
            posTemp.x = this->animationPosition.getClockX();edkEnd();
            posTemp.y = this->animationPosition.getClockY();edkEnd();
            //update the position
            /*
                this->animatedFrame.origin.x += this->animationPosition.getClockX(&success);edkEnd();
                this->animatedFrame.origin.y += this->animationPosition.getClockY(&success);edkEnd();
                */
            this->animatedFrame.origin += posTemp;edkEnd();
        }
    }
}
void edk::View::updateAnimations(edk::float32 seconds){
    if(!this->animationPosition.isPaused()){
        //clean the animatedFrame
        this->animationPosition.updateClockAnimation(seconds);edkEnd();
        this->animatedFrame=this->frame;edkEnd();
        if(this->animationPosition.isPlaying()){
            //update
            //printf("\n                     Second %.2f",this->animationPosition.updateClockAnimation());edkEnd();
            edk::vec2f32 posTemp;edkEnd();
            posTemp.x = this->animationPosition.getClockX();edkEnd();
            posTemp.y = this->animationPosition.getClockY();edkEnd();
            //update the position
            /*
                this->animatedFrame.origin.x += this->animationPosition.getClockX(&success);edkEnd();
                this->animatedFrame.origin.y += this->animationPosition.getClockY(&success);edkEnd();
                */
            this->animatedFrame.origin += posTemp;edkEnd();
        }
    }
}

bool edk::View::contact(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons){
    if(this->pointInside(edk::vec2f32(point.x,point.y))){
        //
        this->mousePos = point - this->animatedFrame.origin;edkEnd();

        //test if the mouse is not on the view
        if(!this->mouseInside){
            //run the function
            this->eventMouseEntryInsideView(this->mousePos);edkEnd();
        }
        else{
            eventMouseMovingInsideView(this->mousePos);edkEnd();
        }
        //set the mouse inside
        this->mouseInside=true;edkEnd();

        //run the functions to the buttons
        if(buttons){
            //test the state of the mouse
            switch(state){
            case edk::mouse::state::pressed:
                for(edk::uint8 i=0u;i<buttons->size();i++){
                    this->eventMousePressed(mousePos,buttons->get(i));edkEnd();
                }
                break;
            case edk::mouse::state::released:
                //
                for(edk::uint8 i=0u;i<buttons->size();i++){
                    this->eventMouseReleased(mousePos,buttons->get(i));edkEnd();
                }
                break;
            case edk::mouse::state::doubleClicked:
                //
                for(edk::uint8 i=0u;i<buttons->size();i++){
                    this->eventMouseDoubleClicked(mousePos,buttons->get(i));edkEnd();
                }
                break;
            case edk::mouse::state::moved:
                //test if have buttons
                if(buttons->size()){
                    //then move with the buttons
                    for(edk::uint8 i=0u;i<buttons->size();i++){
                        this->eventMouseMoved(mousePos,buttons->get(i));edkEnd();
                    }
                }
                else{
                    //else run with no button
                    this->eventMouseMoved(mousePos,0u);edkEnd();
                }
                break;
                //
            }
        }
        //return true
        return true;
    }
    //else return false
    return false;
}
void edk::View::contactRelease(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons){
    //test if mouse was inside
    if(this->mouseInside){
        //run the function to mouse left
        this->eventMouseLeftView(this->mousePos);edkEnd();
    }
    //set the mouseInside to false
    this->mouseInside=false;edkEnd();

    //run the functions to the buttons
    if(buttons){
        //test the state of the mouse
        if(state == edk::mouse::state::released){
            //
            for(edk::uint8 i=0u;i<buttons->size();i++){
                this->eventMouseReleased(point,buttons->get(i));edkEnd();
            }
        }
        else if(state == edk::mouse::state::doubleClicked){
            //
            for(edk::uint8 i=0u;i<buttons->size();i++){
                this->eventMouseDoubleClicked(point,buttons->get(i));edkEnd();
            }
        }
    }
}

//Events
void edk::View::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    if(point.x){
        //remove the warning
    }
    //types
    /*
    edk::mouse::left;edkEnd();
    edk::mouse::right;edkEnd();
    edk::mouse::middle;edkEnd();
    edk::mouse::xButton1;edkEnd();
    edk::mouse::xButton2;edkEnd();
    */
    switch(button){
    //
    case edk::mouse::left:
        //
        /*
            printf("\nMouse Left Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
        //
    }
}
void edk::View::eventMouseMoved(edk::vec2f32 point,edk::uint32 button){
    if(point.x){
        //remove the warning
    }
    //types
    /*
    edk::mouse::left;edkEnd();
    edk::mouse::right;edkEnd();
    edk::mouse::middle;edkEnd();
    edk::mouse::xButton1;edkEnd();
    edk::mouse::xButton2;edkEnd();
    */
    switch(button){
    //
    case edk::mouse::left:
        //
        /*
            printf("\nMouse Left Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    default:
        //Mouse is moving without a Button pressed
        /*
            printf("\nMouse Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
        //
    }
}
void edk::View::eventMouseReleased(edk::vec2f32 point,edk::uint32 button){
    if(point.x){
        //remove the warning
    }
    //types
    /*
    edk::mouse::left;edkEnd();
    edk::mouse::right;edkEnd();
    edk::mouse::middle;edkEnd();
    edk::mouse::xButton1;edkEnd();
    edk::mouse::xButton2;edkEnd();
    */
    switch(button){
    //
    case edk::mouse::left:
        //
        /*
            printf("\nMouse Left Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
        //
    }
}
void edk::View::eventMouseDoubleClicked(edk::vec2f32 ,edk::uint32 button){

    //types
    /*
    edk::mouse::left;edkEnd();
    edk::mouse::right;edkEnd();
    edk::mouse::middle;edkEnd();
    edk::mouse::xButton1;edkEnd();
    edk::mouse::xButton2;edkEnd();
    */
    switch(button){
    //
    case edk::mouse::left:
        //
        /*
            printf("\nMouse Left Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );edkEnd();
*/
        break;
        //
    }
}
//Mouse go Inside Outside
void edk::View::eventMouseEntryInsideView(edk::vec2f32 point){
    if(point.x){
        //remove the warning
    }
    //
    /*
    printf("\nMouse entry in to view in position (%.2f %.2f )"
           ,point.x
           ,point.y
           );edkEnd();
*/
}
void edk::View::eventMouseLeftView(edk::vec2f32 point){
    if(point.x){
        //remove the warning
    }
    //
    /*
    printf("\nMouse left the view in position (%.2f %.2f )"
           ,point.x
           ,point.y
           );edkEnd();
*/
}
void edk::View::eventMouseMovingInsideView(edk::vec2f32){
    //
}

//ANIMATIONS
//add a new position frame
bool edk::View::animationAddFrame(edk::float32 second, edk::float32 x,edk::float32 y){
    //
    return this->animationAddFrame(second, edk::vec2f32(x,y));edkEnd();
}
bool edk::View::animationAddFrame(edk::float32 second, edk::vec2f32 position){
    //
    return this->animationAddFrame(edk::animation::Frame2D(second, position.x,position.y));edkEnd();
}
bool edk::View::animationAddFrame(edk::animation::Frame2D frame){
    //add the new frame in animationPosition
    return this->animationPosition.addNewInterpolationLine(frame);edkEnd();
}
//clean animation
void edk::View::animationClean(){
    this->animationPosition.cleanAnimations();edkEnd();
}
//return if are playing
bool edk::View::animationIsPlaying(){
    return this->animationPosition.isPlaying();edkEnd();
}
//Animation curve
//Set one interpolation X as a curve
bool edk::View::animationSetInterpolationCurveX(edk::uint32 position){
    return this->animationPosition.setInterpolationCurveX(position);edkEnd();
}
bool edk::View::animationSetInterpolationNotCurveX(edk::uint32 position){
    return this->animationPosition.setInterpolationNotCurveX(position);edkEnd();
}
bool edk::View::animationGetInterpolationIsCurveX(edk::uint32 position){
    return this->animationPosition.getInterpolationIsCurveX(position);edkEnd();
}
//Set the interpolation curve points
bool edk::View::animationSetInterpolationP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    return this->animationPosition.setInterpolationP1X(position,second,x);edkEnd();
}
bool edk::View::animationSetInterpolationP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    return this->animationPosition.setInterpolationP2X(position,second,x);edkEnd();
}
//Set one interpolation Y as a curve
bool edk::View::animationSetInterpolationCurveY(edk::uint32 position){
    return this->animationPosition.setInterpolationCurveY(position);edkEnd();
}
bool edk::View::animationSetInterpolationNotCurveY(edk::uint32 position){
    return this->animationPosition.setInterpolationNotCurveY(position);edkEnd();
}
bool edk::View::animationGetInterpolationIsCurveY(edk::uint32 position){
    return this->animationPosition.getInterpolationIsCurveY(position);edkEnd();
}
//Set the interpolation curve points
bool edk::View::animationSetInterpolationP1Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    return this->animationPosition.setInterpolationP1Y(position,second,y);edkEnd();
}
bool edk::View::animationSetInterpolationP2Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    return this->animationPosition.setInterpolationP2Y(position,second,y);edkEnd();
}
//Position controls
void edk::View::animationPlayForward(){
    //
    this->animationPosition.playForward();edkEnd();
}
void edk::View::animationPlayForwardIn(edk::float32 second){
    //
    this->animationPosition.playForwardIn(second);edkEnd();
}
void edk::View::animationPlayRewind(){
    //
    this->animationPosition.playRewind();edkEnd();
}
void edk::View::animationPlayRewindIn(edk::float32 second){
    //
    this->animationPosition.playRewindIn(second);edkEnd();
}
void edk::View::animationPause(){
    //
    this->animationPosition.pause();edkEnd();
}
void edk::View::animationStop(){
    //
    this->animationPosition.stop();edkEnd();
}
//set loop
void edk::View::animationSetLoop(bool loop){
    //
    this->animationPosition.setLoop(loop);edkEnd();
}
void edk::View::animationLoopOn(){
    //
    this->animationPosition.loopOn();edkEnd();
}
void edk::View::animationLoopOff(){
    //
    this->animationPosition.loopOff();edkEnd();
}
//AnimationNames
bool edk::View::animationAddAnimationName(const edk::char8* name,edk::float32 start,edk::float32 end){
    //
    return this->animationPosition.addNewAnimationName(name,start,end);edkEnd();
}
bool edk::View::animationAddAnimationName(edk::char8* name,edk::float32 start,edk::float32 end){
    //
    return this->animationPosition.addNewAnimationName(name,start,end);edkEnd();
}
bool edk::View::animationPlayNameForward(const edk::char8* name){
    //
    return this->animationPosition.playNameForward(name);edkEnd();
}
bool edk::View::animationPlayNameForward(edk::char8* name){
    //
    return this->animationPosition.playNameForward(name);edkEnd();
}
bool edk::View::animationPlayNameRewind(const edk::char8* name){
    //
    return this->animationPosition.playNameRewind(name);edkEnd();
}
bool edk::View::animationPlayNameRewind(edk::char8* name){
    //
    return this->animationPosition.playNameRewind(name);edkEnd();
}
void edk::View::animationRemoveAnimationName(const edk::char8* name){
    //
    this->animationPosition.removeAnimationName(name);edkEnd();
}
void edk::View::animationRemoveAnimationName(edk::char8* name){
    //
    this->animationPosition.removeAnimationName(name);edkEnd();
}
//clean all animation Names
void edk::View::animationCleanAnimationNames(){
    this->animationPosition.cleanAnimationNames();edkEnd();
}
//Print
void edk::View::animationPrintAnimation(){
    //
    this->animationPosition.printFrames();edkEnd();
}
//Callback
bool edk::View::animationSetCallback(edk::animation::AnimationCallback* callback){
    return this->animationPosition.setAnimationCallback(callback);edkEnd();
}
//remove callback
void edk::View::animationRemoveCallback(){
    this->animationPosition.removeAnimationCallback();edkEnd();
}
//test the animationPointer
bool edk::View::isThisAnimationPosition(edk::animation::InterpolationGroup* animation){
    if(animation == &this->animationPosition){
        return true;
    }
    return false;
}

//test if a point is inside the view
bool edk::View::pointInside(edk::vec2f32 point){
    //create a tempRectangleShape
    edk::shape::Rectangle2D temp;edkEnd();
    temp.setVertexPosition(0u,this->animatedFrame.origin);edkEnd();
    temp.setVertexPosition(1u,this->animatedFrame.origin.x + this->animatedFrame.size.width,this->animatedFrame.origin.y + this->animatedFrame.size.height);edkEnd();
    //test the contact
    return edk::collision::RectangleContact::contactPoint(point,temp);
}

//Return if is leaf
bool edk::View::isLeaf(){
    //
    return true;
}

//return true if is a GUView
bool edk::View::isGU(){
    //return false
    return false;
}
//return true if is a buttonView
bool edk::View::isButton(){
    //
    return false;
}

//return true if the mouse is inside
bool edk::View::isMouseInside(){
    return this->mouseInside;edkEnd();
}

//update the view
void edk::View::updateView(edk::WindowEvents* events){
    //update the view function
    this->runUpdate(events);edkEnd();
}

//return if the pause is true
bool edk::View::isPaused(){
    return this->paused;
}
