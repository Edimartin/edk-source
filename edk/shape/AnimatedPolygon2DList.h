#ifndef EDK_SHAPE_AnimatedPolygon2DList_H
#define EDK_SHAPE_AnimatedPolygon2DList_H

/*
Library AnimatedPolygon2DList - Add animation to 2D Polygons in EDK Game Engine
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
#pragma message "Inside AnimatedPolygon2DList"
#endif

#pragma once
#include "Polygon2DList.h"
//Animation
#include "../animation/Interpolation2DGroup.h"

#ifdef printMessages
#pragma message "    Compiling AnimatedPolygon2DList"
#endif

namespace edk{
namespace shape{
class AnimatedPolygon2DList : public edk::shape::Polygon2DList{
public:
    AnimatedPolygon2DList();
    virtual ~AnimatedPolygon2DList();

    void Constructor(bool runFather=true);

    //ANIMATIONS
    //create a new animation in a polygon
    bool setAnimationFramesToPolygon(edk::uint32 position);
    bool newAnimationFramesToPolygon(edk::uint32 position);
    bool createAnimationFramesToPolygon(edk::uint32 position);
    //copy an animation to another polygon
    bool copyAnimationFramesToPolygon(edk::uint32 position,edk::uint32 dest);
    bool copyThisAnimationFramesToPolygon(edk::animation::Interpolation1DGroup*,edk::uint32 dest);
    //remove polygonAnimation
    bool removeAnimationFramesFromPolygon(edk::uint32 position);
    //select the animation
    bool selectAnimationFramesFromPolygon(edk::uint32 position);
    //get animation ID selected
    edk::uint32 getAnimationFramesSelectedID();
    //return true if have the animation
    bool haveSelectedAnimation();
    //free the selected animation
    void freeSelectedAnimation();
    //Atualiza as animações da malha
    void updateFramesAnimations();
    void updateFramesAnimations(edk::float32 seconds);


    //AnimationSelected
    //set the abstract
    bool selectedAnimationSetAnimationCallback(edk::animation::AnimationCallback* callback);
    //create a new interpoationLine
    bool selectedAnimationAddInterpolationLine(edk::float32 second,edk::float32 x);
    //return frames size
    edk::uint32 selectedAnimationGetInterpolationSize();
    //cleanFrames and Names
    bool selectedAnimationClean();
    bool selectedAnimationCleanFrames();
    bool selectedAnimationCleanAnimationNames();
    //controls
    bool selectedAnimationPlayForward();
    bool selectedAnimationPlayForwardIn(edk::float32 second);
    bool selectedAnimationRestartForward();
    bool selectedAnimationPlayRewind();
    bool selectedAnimationPlayRewindIn(edk::float32 second);
    bool selectedAnimationRestartRewind();
    bool selectedAnimationChangeToForward();
    bool selectedAnimationChangeToRewind();
    bool selectedAnimationChangeWay();
    bool selectedAnimationPause();
    bool selectedAnimationPauseOn();
    bool selectedAnimationPauseOff();
    bool selectedAnimationStop();
    //set loop
    bool selectedAnimationSetLoop(bool loop);
    bool selectedAnimationLoopOn();
    bool selectedAnimationLoopOff();
    //get the second
    edk::float32 selectedAnimationGetSecond();
    //return if are playing
    bool selectedAnimationIsPlaying();
    bool selectedAnimationIsPlayingName(const edk::char8* name);
    bool selectedAnimationIsPlayingName(edk::char8* name);
    bool selectedAnimationIsPlayingFoward();
    bool selectedAnimationIsPlayingFowardName(const edk::char8* name);
    bool selectedAnimationIsPlayingFowardName(edk::char8* name);
    bool selectedAnimationIsPlayingRewind();
    bool selectedAnimationIsPlayingRewindName(const edk::char8* name);
    bool selectedAnimationIsPlayingRewindName(edk::char8* name);
    bool selectedAnimationWasPlayingName(const edk::char8* name);
    bool selectedAnimationWasPlayingName(edk::char8* name);
    bool selectedAnimationWasPlayingFoward();
    bool selectedAnimationWasPlayingFowardName(const edk::char8* name);
    bool selectedAnimationWasPlayingFowardName(edk::char8* name);
    bool selectedAnimationWasPlayingRewind();
    bool selectedAnimationWasPlayingRewindName(const edk::char8* name);
    bool selectedAnimationWasPlayingRewindName(edk::char8* name);
    //return if are paused
    bool selectedAnimationIsPaused();
    bool selectedAnimationIsPausedName(const edk::char8* name);
    bool selectedAnimationIsPausedName(edk::char8* name);
    //animationNames
    bool selectedAnimationAddAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end);
    bool selectedAnimationAddAnimationName(edk::char8* name, edk::float32 start,edk::float32 end);
    //test if have the animationName
    bool selectedAnimationHaveAnimationName(const edk::char8* name);
    bool selectedAnimationHaveAnimationName(edk::char8* name);
    //return the animation seconds
    edk::float32 selectedAnimationGetAnimationStart();
    edk::float32 selectedAnimationGetAnimationEnd();
    //return the animation name seconds
    edk::float32 selectedAnimationGetAnimationNameStart(const edk::char8* name);
    edk::float32 selectedAnimationGetAnimationNameStart(edk::char8* name);
    edk::float32 selectedAnimationGetAnimationNameEnd(const edk::char8* name);
    edk::float32 selectedAnimationGetAnimationNameEnd(edk::char8* name);
    //Play the animationName
    bool selectedAnimationPlayNameForward(const edk::char8* name);
    bool selectedAnimationPlayNameForward(edk::char8* name);
    bool selectedAnimationPlayNameRewind(const edk::char8* name);
    bool selectedAnimationPlayNameRewind(edk::char8* name);
    //remove the animationName
    bool selectedAnimationRemoveAnimationName(const edk::char8* name);
    bool selectedAnimationRemoveAnimationName(edk::char8* name);

    //Set one interpolation X as a curve
    bool selectedAnimationSetCurveX(edk::uint32 position);
    bool selectedAnimationSetNotCurveX(edk::uint32 position);
    bool selectedAnimationGetIsCurveX(edk::uint32 position);
    //Set the interpolation curve points
    bool selectedAnimationSetCurveP1X(edk::uint32 position,edk::float32 second,edk::float32 x);
    bool selectedAnimationSetCurveP2X(edk::uint32 position,edk::float32 second,edk::float32 x);
    //Speed
    bool selectedAnimationSetSpeed(edk::float32 speed);
    edk::float32 selectedAnimationGetSpeed();
    /*
    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    */

protected:
    //animationSelected
    edk::animation::Interpolation1DGroup* selectedAnimation;
    edk::uint32 selectedID;
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // EDK_SHAPE_AnimatedPolygon2DList_H
