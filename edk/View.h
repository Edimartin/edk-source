#ifndef EDK_VIEW_h
#define EDK_VIEW_h

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
#warning "Inside View"
#endif

#pragma once
//Include the Graphic Unity to draw 3D.
#include "GU/GU.h"
//Include the types to set view attributes
#include "Types.h"
//shape rectangle
#include "shape/Rectangle2D.h"
//contact with the rectangle
#include "collision/RectangleContact.h"
//the vector to receive que mousepoints
#include "vector/Array.h"
//Events loaded
#include "WindowEvents.h"
//Animations
#include "animation/Interpolation2DGroup.h"

#ifdef printMessages
#warning "    Compiling View"
#endif

/*
//Events
void load(edk::rectf32 outsideViewOrigin){
    //
}
void unload(){
    //
}
void update(edk::WindowEvents* events){
    //
}
void pause(){
    //
}
void unpause(){
    //
}
void resize(edk::rectf32 outsideViewOrigin){
    //
}
void eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    //types
    //edk::mouse::left;
    //edk::mouse::right;
    //edk::mouse::middle;
    //edk::mouse::xButton1;
    //edk::mouse::xButton2;
    switch(button){
        //
        case edk::mouse::left:
            //
            //printf("\nMouse Left Pressed in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::right:
            //
            //printf("\nMouse right Pressed in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::middle:
            //
            //printf("\nMouse middle Pressed in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::xButton1:
            //
            //printf("\nMouse xButton1 Pressed in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::xButton2:
            //
            //printf("\nMouse xButton2 Pressed in pos (%.2f %.2f)",point.x,point.y);
            break;
        //
    }
}
void eventMouseMoved(edk::vec2f32 point,edk::uint32 button){
    //types
    //edk::mouse::left;
    //edk::mouse::right;
    //edk::mouse::middle;
    //edk::mouse::xButton1;
    //edk::mouse::xButton2;
    switch(button){
        //
        case edk::mouse::left:
            //
            //printf("\nMouse Left Moved in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::right:
            //
            //printf("\nMouse right Moved in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::middle:
            //
            //printf("\nMouse middle Moved in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::xButton1:
            //
            //printf("\nMouse xButton1 Moved in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::xButton2:
            //
            //printf("\nMouse xButton2 Moved in pos (%.2f %.2f)",point.x,point.y);
            break;
        default:
            //Mouse is moving without a Button pressed
            //printf("\nMouse Moved in pos (%.2f %.2f)",point.x,point.y);
            break;
        //
    }
}
void eventMouseReleased(edk::vec2f32 point,edk::uint32 button){
    //types
    //edk::mouse::left;
    //edk::mouse::right;
    //edk::mouse::middle;
    //edk::mouse::xButton1;
    //edk::mouse::xButton2;
    switch(button){
        //
        case edk::mouse::left:
            //
            //printf("\nMouse Left Released in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::right:
            //
            //printf("\nMouse right Released in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::middle:
            //
            //printf("\nMouse middle Released in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::xButton1:
            //
            //printf("\nMouse xButton1 Released in pos (%.2f %.2f)",point.x,point.y);
            break;
        case edk::mouse::xButton2:
            //
            //printf("\nMouse xButton2 Released in pos (%.2f %.2f)",point.x,point.y);
            break;
        //
    }
}
//Mouse go Inside Outside
void eventMouseEntryInsideView(edk::vec2f32 point){
    //
    //printf("\nMouse entry in to view in position (%.2f %.2f )",point.x,point.y);
}
void eventMouseLeftView(edk::vec2f32 point){
    //
    //printf("\nMouse left the view in position (%.2f %.2f )",point.x,point.y);
}
*/


namespace edk {
class ViewController;
class View {
 public:
    View();

    View(edk::rectf32 frame);

    //ViewController can access the protected functions
    friend edk::ViewController;

    virtual ~View();

    virtual void draw(edk::rectf32 outsideViewOrigin);
    virtual void resize(edk::rectf32 outsideViewOrigin);

    virtual void load(edk::rectf32 outsideViewOrigin);
    virtual void unload();

    virtual void update(edk::WindowEvents* events);

    virtual void pause();
    virtual void unpause();

    void updateAnimations();
    void updateAnimations(edk::float32 seconds);

    virtual bool contact(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons);
    virtual void contactRelease(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons);

    //Events
    virtual void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
    virtual void eventMouseMoved(edk::vec2f32 point,edk::uint32 button);
    virtual void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);
    //Mouse go Inside Outside
    virtual void eventMouseEntryInsideView(edk::vec2f32 point);
    virtual void eventMouseLeftView(edk::vec2f32 point);
    virtual void eventMouseMovingInsideView(edk::vec2f32 point);

    //ANIMATIONS
    //add a new position frame
    bool animationAddFrame(edk::float32 second, edk::float32 x,edk::float32 y);
    bool animationAddFrame(edk::float32 second, edk::vec2f32 position);
    bool animationAddFrame(edk::animation::Frame2D frame);
    //clean animation
    void animationClean();
    //return if are playing
    bool animationIsPlaying();
    //Animation curve
    //Set one interpolation X as a curve
    bool animationSetInterpolationCurveX(edk::uint32 position);
    bool animationSetInterpolationNotCurveX(edk::uint32 position);
    bool animationGetInterpolationIsCurveX(edk::uint32 position);
    //Set the interpolation curve points
    bool animationSetInterpolationP1X(edk::uint32 position,edk::float32 second,edk::float32 x);
    bool animationSetInterpolationP2X(edk::uint32 position,edk::float32 second,edk::float32 x);
    //Set one interpolation Y as a curve
    bool animationSetInterpolationCurveY(edk::uint32 position);
    bool animationSetInterpolationNotCurveY(edk::uint32 position);
    bool animationGetInterpolationIsCurveY(edk::uint32 position);
    //Set the interpolation curve points
    bool animationSetInterpolationP1Y(edk::uint32 position,edk::float32 second,edk::float32 y);
    bool animationSetInterpolationP2Y(edk::uint32 position,edk::float32 second,edk::float32 y);
    //Position controls
    void animationPlayForward();
    void animationPlayForwardIn(edk::float32 second);
    void animationPlayRewind();
    void animationPlayRewindIn(edk::float32 second);
    void animationPause();
    void animationStop();
    //set loop
    void animationSetLoop(bool loop);
    void animationLoopOn();
    void animationLoopOff();
    //AnimationNames
    bool animationAddAnimationName(const edk::char8* name,edk::float32 start,edk::float32 end);
    bool animationAddAnimationName(edk::char8* name,edk::float32 start,edk::float32 end);
    bool animationPlayNameForward(const edk::char8* name);
    bool animationPlayNameForward(edk::char8* name);
    bool animationPlayNameRewind(const edk::char8* name);
    bool animationPlayNameRewind(edk::char8* name);
    void animationRemoveAnimationName(const edk::char8* name);
    void animationRemoveAnimationName(edk::char8* name);
    //clean all animation Names
    void animationCleanAnimationNames();
    //Print
    void animationPrintAnimation();
    //Callback
    bool animationSetCallback(edk::animation::AnimationCallback* callback);
    //remove callback
    void animationRemoveCallback();
    //test the animationPointer
    bool isThisAnimationPosition(edk::animation::InterpolationGroup* animation);

    //test if a point is inside the view
    virtual bool pointInside(edk::vec2f32 point);

    //return true if is leaf
    virtual bool isLeaf();

    //return true if is a GUView
    virtual bool isGU();

    //return true if is a buttonView
    virtual bool isButton();

    //return true if the mouse is inside
    virtual bool isMouseInside();

    //update the view
    virtual void updateView(edk::WindowEvents* events);

 public:
    edk::rectf32 frame;
    edk::rectf32 animatedFrame;
    edk::color4f32 backgroundColor;
    //set if the view is hided
    bool hide;
    //set if mouse is inside the view
    bool mouseInside;
    //mouse position to save
    edk::vec2f32 mousePos;
    edk::float64 borderSize;

 protected:
    edk::rectf32 rectTemp;
    edk::float32 borderTemp;
    //save if it's paused
    bool paused;

    //Draw Functions
    //draw viewPort
    virtual void drawViewport(edk::rectf32 outsideViewOrigin);
    //draw Camera
    virtual void drawCamera();
    //draw the polygon on the scene
    virtual void drawPolygon(edk::rectf32 outsideViewOrigin);
    //those functions run the other functions
    virtual void runDraw(edk::rectf32 outsideViewOrigin);
    virtual void runLoad(edk::rectf32 outsideViewOrigin);
    virtual void runUnload();
    virtual void runUpdate(edk::WindowEvents* events);
    //run the pause function
    virtual void runPause();
    //run the unpause function
    virtual void runUnpause();

    //Animations
    //Position animation to change the viewPosition on the window (or View)
    edk::animation::Interpolation2DGroup animationPosition;
private:
    //save the outside frame to test if it was changed
    edk::rectf32 saveOutsideFrame;
};

} /* End of namespace edk */

#endif // edk_View_h
