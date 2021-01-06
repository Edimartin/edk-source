#include "View.h"

/*
Library C++ edkView - Viewport used in Edk Game Engine
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
#warning "            Inside View.cpp"
#endif

#include <stdio.h>

namespace edk {




View::View(){
    this->frame = edk::rectf32(0.f,0.f,0.f,0.f);
    this->animatedFrame = this->frame;
    //set color to white
    this->backgroundColor = edk::color4f32(1,1,1,1);
    //set to show view
    this->hide=false;
    this->mouseInside=false;
    this->borderSize=0.f;
    this->borderTemp=0.f;
    this->mousePos = edk::vec2f32(0,0);
}

View::View(edk::rectf32 frame){
    this->frame = frame;
    this->animatedFrame = this->frame;
    //set color to white
    this->backgroundColor = edk::color4f32(1,1,1,1);
    //set to show view
    this->hide=false;
    this->mouseInside=false;
    this->borderSize=0.0;
    this->borderTemp=0.f;
}

View::~View(){
    //
}

//Draw Functions
//draw viewPort
void View::drawViewport(edk::rectf32 outsideViewOrigin){
    //DRAW VIEWPORT
    //test if are using the modelView
    if(!edk::GU::guUsingMatrix(GU_MODELVIEW))edk::GU::guUseMatrix(GU_MODELVIEW);
    //First create the view in GU
    rectTemp = edk::rectf32((edk::int32)(outsideViewOrigin.origin.x + this->animatedFrame.origin.x)
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
void View::drawCamera(){
    //DRAW THE VIEW CAMERA
    //Use the projection matrix to set the camera
    edk::GU::guUseMatrix(GU_PROJECTION);
    //Load the identity
    edk::GU::guLoadIdentity();
    //Set the ortho camera
    edk::GU::guUseOrtho(0,1,0,1,-1,1);
}
//draw the polygon on the scene
void View::drawPolygon(edk::rectf32){
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

void View::runDraw(edk::rectf32 outsideViewOrigin){
    this->draw(outsideViewOrigin);
}
void View::runLoad(edk::rectf32 outsideViewOrigin){
    this->load(outsideViewOrigin);
}
void View::runUnload(){
    this->unload();
}
void View::runUpdate(edk::WindowEvents* events){
    this->update(events);
}

void View::draw(edk::rectf32 outsideViewOrigin){
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

void edk::View::load(rectf32){
    //
}
void edk::View::unload(){
    //
}

void edk::View::update(edk::WindowEvents*){
    //update the animation
}
void View::updateAnimations(){
    bool success;
    if(!this->animationPosition.isPaused()){
        //clean the animatedFrame
        this->animatedFrame=this->frame;
        if(this->animationPosition.isPlaying()){
            //update
            //printf("\n                     Second %.2f",this->animationPosition.updateClockAnimation());
            this->animationPosition.updateClockAnimation();
            edk::vec2f32 posTemp;
            posTemp.x = this->animationPosition.getClockX(&success);
            if(success){
                posTemp.y = this->animationPosition.getClockY(&success);
                if(success){
                    //update the position
                    /*
                this->animatedFrame.origin.x += this->animationPosition.getClockX(&success);
                this->animatedFrame.origin.y += this->animationPosition.getClockY(&success);
                */
                    this->animatedFrame.origin += posTemp;
                }
            }
        }
    }
}
void View::updateAnimations(edk::float32 seconds){
    bool success;
    if(!this->animationPosition.isPaused()){
        //clean the animatedFrame
        this->animatedFrame=this->frame;
        if(this->animationPosition.isPlaying()){
            //update
            //printf("\n                     Second %.2f",this->animationPosition.updateClockAnimation());
            this->animationPosition.updateClockAnimation(seconds);
            edk::vec2f32 posTemp;
            posTemp.x = this->animationPosition.getClockX(&success);
            if(success){
                posTemp.y = this->animationPosition.getClockY(&success);
                if(success){
                    //update the position
                    /*
                this->animatedFrame.origin.x += this->animationPosition.getClockX(&success);
                this->animatedFrame.origin.y += this->animationPosition.getClockY(&success);
                */
                    this->animatedFrame.origin += posTemp;
                }
            }
        }
    }
}

bool View::contact(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons){
    if(this->pointInside(edk::vec2f32(point.x,point.y))){
        //
        this->mousePos = point - this->animatedFrame.origin;

        //test if the mouse is not on the view
        if(!this->mouseInside){
            //run the function
            this->eventMouseEntryInsideView(this->mousePos);
        }
        else eventMouseMovingInsideView(this->mousePos);
        //set the mouse inside
        this->mouseInside=true;

        //run the functions to the buttons
        if(buttons){
            //test the state of the mouse
            switch(state){
            case edk::mouse::state::pressed:
                for(edk::uint8 i=0u;i<buttons->size();i++){
                    this->eventMousePressed(mousePos,buttons->get(i));
                }
                break;
            case edk::mouse::state::released:
                //
                for(edk::uint8 i=0u;i<buttons->size();i++){
                    this->eventMouseReleased(mousePos,buttons->get(i));
                }
                break;
            case edk::mouse::state::moved:
                //test if have buttons
                if(buttons->size()){
                    //then move with the buttons
                    for(edk::uint8 i=0u;i<buttons->size();i++){
                        this->eventMouseMoved(mousePos,buttons->get(i));
                    }
                }
                else{
                    //else run with no button
                    this->eventMouseMoved(mousePos,0u);
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
void View::contactRelease(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons){
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
    }
}

//Events
void View::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
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
void View::eventMouseMoved(edk::vec2f32 point,edk::uint32 button){
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
            printf("\nMouse Left Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::right:
        //
        /*
            printf("\nMouse right Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::middle:
        //
        /*
            printf("\nMouse middle Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton1:
        //
        /*
            printf("\nMouse xButton1 Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    case edk::mouse::xButton2:
        //
        /*
            printf("\nMouse xButton2 Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
    default:
        //Mouse is moving without a Button pressed
        /*
            printf("\nMouse Moved in pos (%.2f %.2f)"
                   ,point.x
                   ,point.y
                   );
*/
        break;
        //
    }
}
void View::eventMouseReleased(edk::vec2f32 point,edk::uint32 button){
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
//Mouse go Inside Outside
void View::eventMouseEntryInsideView(edk::vec2f32 point){
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
void View::eventMouseLeftView(edk::vec2f32 point){
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
void View::eventMouseMovingInsideView(edk::vec2f32){
    //
}

//ANIMATIONS
//add a new position frame
bool View::animationAddFrame(edk::float32 second, edk::float32 x,edk::float32 y){
    //
    return this->animationAddFrame(second, edk::vec2f32(x,y));
}
bool View::animationAddFrame(edk::float32 second, edk::vec2f32 position){
    //
    return this->animationAddFrame(edk::animation::Frame2D(second, position.x,position.y));
}
bool View::animationAddFrame(edk::animation::Frame2D frame){
    //add the new frame in animationPosition
    return this->animationPosition.addNewInterpolationLine(frame);
}
//clean animation
void View::animationClean(){
    this->animationPosition.cleanAnimations();
}
//return if are playing
bool View::animationIsPlaying(){
    return this->animationPosition.isPlaying();
}
//Animation curve
//Set one interpolation X as a curve
bool View::animationSetInterpolationCurveX(edk::uint32 position){
    return this->animationPosition.setInterpolationCurveX(position);
}
bool View::animationSetInterpolationNotCurveX(edk::uint32 position){
    return this->animationPosition.setInterpolationNotCurveX(position);
}
bool View::animationGetInterpolationIsCurveX(edk::uint32 position){
    return this->animationPosition.getInterpolationIsCurveX(position);
}
//Set the interpolation curve points
bool View::animationSetInterpolationP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    return this->animationPosition.setInterpolationP1X(position,second,x);
}
bool View::animationSetInterpolationP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    return this->animationPosition.setInterpolationP2X(position,second,x);
}
//Set one interpolation Y as a curve
bool View::animationSetInterpolationCurveY(edk::uint32 position){
    return this->animationPosition.setInterpolationCurveY(position);
}
bool View::animationSetInterpolationNotCurveY(edk::uint32 position){
    return this->animationPosition.setInterpolationNotCurveY(position);
}
bool View::animationGetInterpolationIsCurveY(edk::uint32 position){
    return this->animationPosition.getInterpolationIsCurveY(position);
}
//Set the interpolation curve points
bool View::animationSetInterpolationP1Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    return this->animationPosition.setInterpolationP1Y(position,second,y);
}
bool View::animationSetInterpolationP2Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    return this->animationPosition.setInterpolationP2Y(position,second,y);
}
//Position controls
void View::animationPlayForward(){
    //
    this->animationPosition.playForward();
}
void View::animationPlayForwardIn(edk::float32 second){
    //
    this->animationPosition.playForwardIn(second);
}
void View::animationPlayRewind(){
    //
    this->animationPosition.playRewind();
}
void View::animationPlayRewindIn(edk::float32 second){
    //
    this->animationPosition.playRewindIn(second);
}
void View::animationPause(){
    //
    this->animationPosition.pause();
}
void View::animationStop(){
    //
    this->animationPosition.stop();
}
//set loop
void View::animationSetLoop(bool loop){
    //
    this->animationPosition.setLoop(loop);
}
void View::animationLoopOn(){
    //
    this->animationPosition.loopOn();
}
void View::animationLoopOff(){
    //
    this->animationPosition.loopOff();
}
//AnimationNames
bool View::animationAddAnimationName(const edk::char8* name,edk::float32 start,edk::float32 end){
    //
    return this->animationPosition.addNewAnimationName(name,start,end);
}
bool View::animationAddAnimationName(edk::char8* name,edk::float32 start,edk::float32 end){
    //
    return this->animationPosition.addNewAnimationName(name,start,end);
}
bool View::animationPlayNameForward(const edk::char8* name){
    //
    return this->animationPosition.playNameForward(name);
}
bool View::animationPlayNameForward(edk::char8* name){
    //
    return this->animationPosition.playNameForward(name);
}
bool View::animationPlayNameRewind(const edk::char8* name){
    //
    return this->animationPosition.playNameRewind(name);
}
bool View::animationPlayNameRewind(edk::char8* name){
    //
    return this->animationPosition.playNameRewind(name);
}
void View::animationRemoveAnimationName(const edk::char8* name){
    //
    this->animationPosition.removeAnimationName(name);
}
void View::animationRemoveAnimationName(edk::char8* name){
    //
    this->animationPosition.removeAnimationName(name);
}
//clean all animation Names
void View::animationCleanAnimationNames(){
    this->animationPosition.cleanAnimationNames();
}
//Print
void View::animationPrintAnimation(){
    //
    this->animationPosition.printFrames();
}
//Callback
bool View::animationSetCallback(edk::animation::AnimationCallback* callback){
    return this->animationPosition.setAnimationCallback(callback);
}
//remove callback
void View::animationRemoveCallback(){
    this->animationPosition.removeAnimationCallback();
}
//test the animationPointer
bool View::isThisAnimationPosition(edk::animation::InterpolationGroup* animation){
    if(animation == &this->animationPosition) return true;
    return false;
}

//test if a point is inside the view
bool View::pointInside(edk::vec2f32 point){
    //create a tempRectangleShape
    edk::shape::Rectangle2D temp;
    temp.setVertexPosition(0u,this->animatedFrame.origin);
    temp.setVertexPosition(1u,this->animatedFrame.origin.x + this->animatedFrame.size.width,this->animatedFrame.origin.y + this->animatedFrame.size.height);
    //test the contact
    return edk::collision::RectangleContact::contactPoint(point,temp);
}

//Return if is leaf
bool View::isLeaf(){
    //
    return true;
}

//return true if is a GUView
bool View::isGU(){
    //return false
    return false;
}
//return true if is a buttonView
bool View::isButton(){
    //
    return false;
}

//return true if the mouse is inside
bool View::isMouseInside(){
    return this->mouseInside;
}

//update the view
void View::updateView(edk::WindowEvents* events){
    //update the view function
    this->runUpdate(events);
}

} /* End of namespace edk */
