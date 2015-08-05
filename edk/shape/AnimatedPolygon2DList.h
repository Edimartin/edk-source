#ifndef EDK_SHAPE_AnimatedPolygon2DList_H
#define EDK_SHAPE_AnimatedPolygon2DList_H

/*
Library AnimatedPolygon2DList - Add animation to 2D Polygons in EDK Game Engine
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

#pragma once
#include "Polygon2DList.h"
//Animation
#include "../animation/Interpolation2DGroup.h"


namespace edk{
namespace shape{
class AnimatedPolygon2DList : public edk::shape::Polygon2DList{
public:
    AnimatedPolygon2DList();
    ~AnimatedPolygon2DList();

    //ANIMATIONS
    //create a new animation in a polygon
    bool newAnimationFramesToPolygon(edk::uint32 position);
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


    //AnimationSelected
    //set the abstract
    bool selectedAnimationSetAnimationCallback(edk::animation::AnimationCallback* callback);
    //create a new interpoationLine
    bool selectedAnimationAddInterpolationLine(edk::float32 second,edk::float32 x);
    //return frames size
    edk::uint32 selectedAnimationGetInterpolationSize();
    //cleanFrames
    bool selectedAnimationCleanFrames();
    //controls
    bool selectedAnimationPlayForward();
    bool selectedAnimationPlayForwardIn(edk::float32 second);
    bool selectedAnimationPlayRewind();
    bool selectedAnimationPlayRewindIn(edk::float32 second);
    bool selectedAnimationPause();
    bool selectedAnimationStop();
    //set loop
    bool selectedAnimationSetLoop(bool loop);
    bool selectedAnimationLoopOn();
    bool selectedAnimationLoopOff();
    //get the second
    edk::float32 selectedAnimationGetSecond();
    //return if are playing
    bool selectedAnimationIsPlaying();
    //animationNames
    bool selectedAnimationAddAnimationName(const char* name, edk::float32 start,edk::float32 end);
    bool selectedAnimationAddAnimationName(edk::char8* name, edk::float32 start,edk::float32 end);
    //test if have the animationName
    bool selectedAnimationHaveAnimationName(const char* name);
    bool selectedAnimationHaveAnimationName(edk::char8* name);
    //Play the animationName
    bool selectedAnimationPlayNameForward(const char* name);
    bool selectedAnimationPlayNameForward(edk::char8* name);
    bool selectedAnimationPlayNameRewind(const char* name);
    bool selectedAnimationPlayNameRewind(edk::char8* name);
    //remove the animationName
    bool selectedAnimationRemoveAnimationName(const char* name);
    bool selectedAnimationRemoveAnimationName(edk::char8* name);

    //Set one interpolation X as a curve
    bool selectedAnimationSetCurveX(edk::uint32 position);
    bool selectedAnimationSetNotCurveX(edk::uint32 position);
    bool selectedAnimationGetIsCurveX(edk::uint32 position);
    //Set the interpolation curve points
    bool selectedAnimationSetCurveP1X(edk::uint32 position,edk::float32 second,edk::float32 x);
    bool selectedAnimationSetCurveP2X(edk::uint32 position,edk::float32 second,edk::float32 x);
    /*
    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    */

protected:
    //animationSelected
    edk::animation::Interpolation1DGroup* selectedAnimation;
    edk::uint32 selectedID;
};
}//end namespace shape
}//end namespace edk

#endif // EDK_SHAPE_AnimatedPolygon2DList_H
