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
    this->classThis=NULL;
    this->Constructor();
}

edk::View::View(edk::rectf32 frame){
    this->classThis=NULL;
    this->Constructor(frame);
}

edk::View::~View(){
    this->Destructor();
}

void edk::View::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->animationPosition.Constructor();

        this->frame = edk::rectf32(0.f,0.f,0.f,0.f);
        this->positionInWindow=this->frame.origin;
        this->animatedFrame = this->frame;
        //set color to white
        this->backgroundColor = edk::color4f32(1,1,1,1);
        //set to show view
        this->hide=false;
        this->paused=false;
        this->mouseInside=false;
        this->borderSize=0.f;
        this->borderTemp=0.f;
        this->mousePos = edk::vec2f32(0,0);
        this->saveOutsideFrame=0.f;
    }
}
void edk::View::Constructor(edk::rectf32 frame){
    if(this->classThis!=this){
        this->classThis=this;

        this->animationPosition.Constructor();

        this->frame = frame;
        this->positionInWindow=this->frame.origin;
        this->animatedFrame = this->frame;
        //set color to white
        this->backgroundColor = edk::color4f32(1,1,1,1);
        //set to show view
        this->hide=false;
        this->paused=false;
        this->mouseInside=false;
        this->borderSize=0.0;
        this->borderTemp=0.f;
    }
}
void edk::View::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->animationPosition.Destructor();
    }
}

//Draw Functions
//draw viewPort
void edk::View::drawViewport(edk::rectf32 outsideViewOrigin){
    //DRAW VIEWPORT
    //test if are using the modelView
    if(!edk::GU::guUsingMatrix(GU_MODELVIEW)){
        edk::GU::guUseMatrix(GU_MODELVIEW);
    }
    //First create the view in GU
    this->rectTemp = edk::rectf32((edk::int32)(outsideViewOrigin.origin.x + this->animatedFrame.origin.x)
                            ,(edk::int32)( outsideViewOrigin.origin.y + outsideViewOrigin.size.height - this->animatedFrame.origin.y - this->animatedFrame.size.height)
                            ,(edk::int32)this->animatedFrame.size.width
                            ,(edk::int32)this->animatedFrame.size.height
                            );
    //Set the viewport
    edk::GU::guSetViewport((edk::uint32)rectTemp.origin.x
                           ,(edk::uint32)rectTemp.origin.y
                           ,(edk::uint32)this->animatedFrame.size.width
                           ,(edk::uint32)this->animatedFrame.size.height
                           );

    //set the viewPort Color
    edk::GU::guColor4f32(this->backgroundColor);
}
//draw Camera
void edk::View::drawCamera(){
    //DRAW THE VIEW CAMERA
    //Use the projection matrix to set the camera
    edk::GU::guUseMatrix(GU_PROJECTION);
    //Load the identity
    edk::GU::guLoadIdentity();
    //Set the ortho camera
    edk::GU::guUseOrtho(0,1,0,1,-1,1);
}
//draw the polygon on the scene
void edk::View::drawPolygon(edk::rectf32){
    //DRAW THE POLYGON
    //Set the modelView matrix to draw the polygon
    //edk::GU::guUseMatrix(GU_MODELVIEW);

    //Draw a quadrangle
    edk::GU::guBegin(GU_QUADS);
    edk::GU::guVertex3f32(0.f, 0.f, 0.f);
    edk::GU::guVertex3f32(1.f, 0.f, 0.f);
    edk::GU::guVertex3f32(1.f, 1.f, 0.f);
    edk::GU::guVertex3f32(0.f, 1.f, 0.f);
    edk::GU::guEnd();
}
//those functions run the other functions
void edk::View::runDraw(edk::rectf32 outsideViewOrigin){
    //test if the outsideViewOrigin is different then the saveFrame
    if(this->saveOutsideFrame != outsideViewOrigin){
        this->saveOutsideFrame = outsideViewOrigin;
        //run the resize function
        this->resize(outsideViewOrigin);
    }
    this->draw(outsideViewOrigin);
}
void edk::View::runLoad(edk::rectf32 outsideViewOrigin){
    this->paused=false;
    //save the first outsideViewOrigin
    this->saveOutsideFrame = outsideViewOrigin;
    //then run load
    this->load(outsideViewOrigin);
    //run the resize function
    this->resize(outsideViewOrigin);
}
void edk::View::runUnload(){
    this->paused=false;
    this->unload();
}
void edk::View::runUpdate(edk::WindowEvents* events){
    this->update(events);
}
//run the pause function
void edk::View::runPause(){
    if(!this->paused){
        this->paused=true;
        //
        this->pause();
    }
}
//run the unpause functin
void edk::View::runUnpause(){
    if(this->paused){
        this->paused=false;
        //
        this->unpause();
    }
}
//run the pauseSwitch
void edk::View::runPauseSwitch(){
    if(this->paused){
        this->runUnpause();
    }
    else{
        this->runPause();
    }
}

void edk::View::draw(edk::rectf32 outsideViewOrigin){
    //test if it's not hided
    if(!this->hide){
        //Then draw
        this->drawViewport(outsideViewOrigin);

        //draw the viewCamera
        this->drawCamera();

        //DRAW THE POLYGON
        //Set the modelView matrix to draw the polygon
        edk::GU::guUseMatrix(GU_MODELVIEW);
        edk::GU::guPushMatrix();

        //draw the polygon in the view
        this->drawPolygon(outsideViewOrigin);
        edk::GU::guUseMatrix(GU_MODELVIEW);
        edk::GU::guPopMatrix();
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
                                    );
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
        this->animatedFrame=this->frame;
        this->animationPosition.updateClockAnimation();
        if(this->animationPosition.isPlaying()){
            //update
            //printf("\n                     Second %.2f",this->animationPosition.updateClockAnimation());
            edk::vec2f32 posTemp;
            posTemp.x = this->animationPosition.getClockX();
            posTemp.y = this->animationPosition.getClockY();
            //update the position
            /*
                this->animatedFrame.origin.x += this->animationPosition.getClockX(&success);
                this->animatedFrame.origin.y += this->animationPosition.getClockY(&success);
                */
            this->animatedFrame.origin += posTemp;
        }
    }
}
void edk::View::updateAnimations(edk::float32 seconds){
    if(!this->animationPosition.isPaused()){
        //clean the animatedFrame
        this->animationPosition.updateClockAnimation(seconds);
        this->animatedFrame=this->frame;
        if(this->animationPosition.isPlaying()){
            //update
            //printf("\n                     Second %.2f",this->animationPosition.updateClockAnimation());
            edk::vec2f32 posTemp;
            posTemp.x = this->animationPosition.getClockX();
            posTemp.y = this->animationPosition.getClockY();
            //update the position
            /*
                this->animatedFrame.origin.x += this->animationPosition.getClockX(&success);
                this->animatedFrame.origin.y += this->animationPosition.getClockY(&success);
                */
            this->animatedFrame.origin += posTemp;
        }
    }
}

bool edk::View::contact(edk::vec2f32 point,edk::vec2f32 moved,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons){
    if(this->pointInside(edk::vec2f32(point.x,point.y))){
        //
        this->mousePos = point - this->animatedFrame.origin;

        //test if the mouse is not on the view
        if(!this->mouseInside){
            //run the function
            this->eventMouseEntryInsideView(this->mousePos);
        }
        else{
            eventMouseMovingInsideView(this->mousePos);
        }
        //set the mouse inside
        this->mouseInside=true;

        //run the functions to the buttons
        if(buttons){
            //test the state of the mouse
            switch(state){
            case edk::mouse::state::pressed:
                for(edk::uint8 i=0u;i<buttons->size();i++){
                    this->eventMousePressed(this->mousePos,buttons->get(i));
                }
                break;
            case edk::mouse::state::released:
                //
                for(edk::uint8 i=0u;i<buttons->size();i++){
                    this->eventMouseReleased(this->mousePos,buttons->get(i));
                }
                break;
            case edk::mouse::state::doubleClicked:
                //
                for(edk::uint8 i=0u;i<buttons->size();i++){
                    this->eventMouseDoubleClicked(this->mousePos,buttons->get(i));
                }
                break;
            case edk::mouse::state::moved:
                //test if have buttons
                if(buttons->size()){
                    //then move with the buttons
                    for(edk::uint8 i=0u;i<buttons->size();i++){
                        this->eventMouseMoved(this->mousePos,moved,buttons->get(i));
                    }
                }
                else{
                    //else run with no button
                    this->eventMouseMoved(this->mousePos,moved,0u);
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
        this->eventMouseLeftView(this->mousePos);
    }
    //set the mouseInside to false
    this->mouseInside=false;

    //run the functions to the buttons
    if(buttons){
        //test the state of the mouse
        if(state == edk::mouse::state::released){
            //
            for(edk::uint8 i=0u;i<buttons->size();i++){
                this->eventMouseReleased(point,buttons->get(i));
            }
        }
        else if(state == edk::mouse::state::doubleClicked){
            //
            for(edk::uint8 i=0u;i<buttons->size();i++){
                this->eventMouseDoubleClicked(point,buttons->get(i));
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
    edk::mouse::left;
    edk::mouse::right;
    edk::mouse::middle;
    edk::mouse::xButton1;
    edk::mouse::xButton2;
    */
    switch(button){
    //
    case edk::mouse::left:
        //
        /*
            printf("\nMouse Left Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Pressed in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
        //
    }
}
void edk::View::eventMouseMoved(edk::vec2f32 point,edk::vec2f32 /*moved*/,edk::uint32 button){
    if(point.x){
        //remove the warning
    }
    //types
    /*
    edk::mouse::left;
    edk::mouse::right;
    edk::mouse::middle;
    edk::mouse::xButton1;
    edk::mouse::xButton2;
    */
    switch(button){
    //
    case edk::mouse::left:
        //
        /*
            printf("\nMouse Left Moved (%.2f %.2f) in pos (%.2f %.2f)"
                   ,moved.x
                   ,moved.y
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Moved (%.2f %.2f) in pos (%.2f %.2f)"
                   ,moved.x
                   ,moved.y
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Moved (%.2f %.2f) in pos (%.2f %.2f)"
                   ,moved.x
                   ,moved.y
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Moved (%.2f %.2f) in pos (%.2f %.2f)"
                   ,moved.x
                   ,moved.y
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Moved (%.2f %.2f) in pos (%.2f %.2f)"
                   ,moved.x
                   ,moved.y
                   ,point.x
                   ,point.y
                   );
*/
        break;
    default:
        //Mouse is moving without a Button pressed
        /*
            printf("\nMouse Moved (%.2f %.2f) in pos (%.2f %.2f)"
                   ,moved.x
                   ,moved.y
                   ,point.x
                   ,point.y
                   );
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
    edk::mouse::left;
    edk::mouse::right;
    edk::mouse::middle;
    edk::mouse::xButton1;
    edk::mouse::xButton2;
    */
    switch(button){
    //
    case edk::mouse::left:
        //
        /*
            printf("\nMouse Left Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Released in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
        //
    }
}
void edk::View::eventMouseDoubleClicked(edk::vec2f32 ,edk::uint32 button){

    //types
    /*
    edk::mouse::left;
    edk::mouse::right;
    edk::mouse::middle;
    edk::mouse::xButton1;
    edk::mouse::xButton2;
    */
    switch(button){
    //
    case edk::mouse::left:
        //
        /*
            printf("\nMouse Left Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Double Clicked in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
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
           );
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
           );
*/
}
void edk::View::eventMouseMovingInsideView(edk::vec2f32){
    //
}

//ANIMATIONS
//add a new position frame
bool edk::View::animationAddFrame(edk::float32 second, edk::float32 x,edk::float32 y){
    //
    return this->animationAddFrame(second, edk::vec2f32(x,y));
}
bool edk::View::animationAddFrame(edk::float32 second, edk::vec2f32 position){
    //
    return this->animationAddFrame(edk::animation::Frame2D(second, position.x,position.y));
}
bool edk::View::animationAddFrame(edk::animation::Frame2D frame){
    //add the new frame in animationPosition
    return this->animationPosition.addNewInterpolationLine(frame);
}
//clean animation
void edk::View::animationClean(){
    this->animationPosition.cleanAnimations();
}
//return if are playing
bool edk::View::animationIsPlaying(){
    return this->animationPosition.isPlaying();
}
//Animation curve
//Set one interpolation X as a curve
bool edk::View::animationSetInterpolationCurveX(edk::uint32 position){
    return this->animationPosition.setInterpolationCurveX(position);
}
bool edk::View::animationSetInterpolationNotCurveX(edk::uint32 position){
    return this->animationPosition.setInterpolationNotCurveX(position);
}
bool edk::View::animationGetInterpolationIsCurveX(edk::uint32 position){
    return this->animationPosition.getInterpolationIsCurveX(position);
}
//Set the interpolation curve points
bool edk::View::animationSetInterpolationP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    return this->animationPosition.setInterpolationP1X(position,second,x);
}
bool edk::View::animationSetInterpolationP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    return this->animationPosition.setInterpolationP2X(position,second,x);
}
//Set one interpolation Y as a curve
bool edk::View::animationSetInterpolationCurveY(edk::uint32 position){
    return this->animationPosition.setInterpolationCurveY(position);
}
bool edk::View::animationSetInterpolationNotCurveY(edk::uint32 position){
    return this->animationPosition.setInterpolationNotCurveY(position);
}
bool edk::View::animationGetInterpolationIsCurveY(edk::uint32 position){
    return this->animationPosition.getInterpolationIsCurveY(position);
}
//Set the interpolation curve points
bool edk::View::animationSetInterpolationP1Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    return this->animationPosition.setInterpolationP1Y(position,second,y);
}
bool edk::View::animationSetInterpolationP2Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    return this->animationPosition.setInterpolationP2Y(position,second,y);
}
//Position controls
void edk::View::animationPlayForward(){
    //
    this->animationPosition.playForward();
}
void edk::View::animationPlayForwardIn(edk::float32 second){
    //
    this->animationPosition.playForwardIn(second);
}
void edk::View::animationPlayRewind(){
    //
    this->animationPosition.playRewind();
}
void edk::View::animationPlayRewindIn(edk::float32 second){
    //
    this->animationPosition.playRewindIn(second);
}
void edk::View::animationPause(){
    //
    this->animationPosition.pause();
}
void edk::View::animationStop(){
    //
    this->animationPosition.stop();
}
//set loop
void edk::View::animationSetLoop(bool loop){
    //
    this->animationPosition.setLoop(loop);
}
void edk::View::animationLoopOn(){
    //
    this->animationPosition.loopOn();
}
void edk::View::animationLoopOff(){
    //
    this->animationPosition.loopOff();
}
//AnimationNames
bool edk::View::animationAddAnimationName(const edk::char8* name,edk::float32 start,edk::float32 end){
    //
    return this->animationPosition.addNewAnimationName(name,start,end);
}
bool edk::View::animationAddAnimationName(edk::char8* name,edk::float32 start,edk::float32 end){
    //
    return this->animationPosition.addNewAnimationName(name,start,end);
}
bool edk::View::animationPlayNameForward(const edk::char8* name){
    //
    return this->animationPosition.playNameForward(name);
}
bool edk::View::animationPlayNameForward(edk::char8* name){
    //
    return this->animationPosition.playNameForward(name);
}
bool edk::View::animationPlayNameRewind(const edk::char8* name){
    //
    return this->animationPosition.playNameRewind(name);
}
bool edk::View::animationPlayNameRewind(edk::char8* name){
    //
    return this->animationPosition.playNameRewind(name);
}
void edk::View::animationRemoveAnimationName(const edk::char8* name){
    //
    this->animationPosition.removeAnimationName(name);
}
void edk::View::animationRemoveAnimationName(edk::char8* name){
    //
    this->animationPosition.removeAnimationName(name);
}
//clean all animation Names
void edk::View::animationCleanAnimationNames(){
    this->animationPosition.cleanAnimationNames();
}
//Print
void edk::View::animationPrintAnimation(){
    //
    this->animationPosition.printFrames();
}
//Callback
bool edk::View::animationSetCallback(edk::animation::AnimationCallback* callback){
    return this->animationPosition.setAnimationCallback(callback);
}
//remove callback
void edk::View::animationRemoveCallback(){
    this->animationPosition.removeAnimationCallback();
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
    edk::shape::Rectangle2D temp;
    temp.setVertexPosition(0u,this->animatedFrame.origin);
    temp.setVertexPosition(1u,this->animatedFrame.origin.x + this->animatedFrame.size.width,this->animatedFrame.origin.y + this->animatedFrame.size.height);
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
    return this->mouseInside;
}

//update the view
void edk::View::updateView(edk::WindowEvents* events){
    //update the view function
    this->runUpdate(events);
}

//return if the pause is true
bool edk::View::isPaused(){
    return this->paused;
}
