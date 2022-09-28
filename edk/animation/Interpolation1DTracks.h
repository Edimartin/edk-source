#ifndef Interpolation1DTracks_H
#define Interpolation1DTracks_H

/*
Biblioteca C++ Interpolation1DTracks - Manage one or more interpolation tracks 1D in Edk Game Engine
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
#warning "Inside Interpolation1DTracks"
#endif

#pragma once
#include "../TypeDefines.h"
//Include the interpolation to add in the group
#include "Interpolation1DGroup.h"
//The interpolations are puted in a stack
#include "../vector/Stack.h"
//BinaryTree
#include "../NameClass.h"
//The Object
#include "../Object.h"
//the InterpolationTracks
#include "InterpolationTracks.h"

#ifdef printMessages
#warning "    Compiling Interpolation1DTracks"
#endif

namespace edk{
namespace animation{
class Interpolation1DTracks : public edk::animation::InterpolationTracks{
public:
    Interpolation1DTracks();
    ~Interpolation1DTracks();

    //Add a first interpolation
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::float32 startX, edk::float32 endSecond,edk::float32 endX);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame1D start,edk::animation::Frame1D end);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond,edk::float32 endSecond);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame start,edk::animation::Frame end);

    //Add New Interpolation
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x);
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame1D frame);

    //Set the frame value
    bool setFrameX(edk::uint32 trackPosition,edk::float32 second,edk::float32 x);

    //Set one interpolation X as a curve
    bool setInterpolationCurveX(edk::uint32 trackPosition,edk::uint32 position);
    bool setInterpolationNotCurveX(edk::uint32 trackPosition,edk::uint32 position);
    bool getInterpolationIsCurveX(edk::uint32 trackPosition,edk::uint32 position);
    //set as constant interpolation
    bool setConstantX(edk::uint32 trackPosition,edk::uint32 position);
    bool setLinearX(edk::uint32 trackPosition,edk::uint32 position);
    //set all as constant interpolation
    bool setAllConstantX(edk::uint32 trackPosition);
    bool setAllLinearX(edk::uint32 trackPosition);
    //Set the interpolation curve points
    bool setInterpolationP1X(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 x);
    bool setInterpolationP2X(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 x);

    //create random animations
    //shake
    edk::float32 addShakingFramesX(edk::uint32 trackPosition,edk::float32 position,edk::float32 percent = 0.9f,edk::float32 interpolationDistance=0.05f);

    //set the animationSecond by the X
    bool setSecondByX(edk::uint32 trackPosition,edk::float32 oldSecond,edk::float32 x);

    //GETERS
    //return the animationPosition
    edk::float32 getClockX();
    edk::float32 getClockX(edk::float32 x);
    //return the interpolation seconds
    edk::float32 getInterpolationStartX(edk::uint32 trackPosition,edk::float32 position);
    edk::float32 getInterpolationEndX(edk::uint32 trackPosition,edk::float32 position);
    //return the animation start and end in X
    edk::float32 getAnimationStartX(edk::uint32 trackPosition);
    edk::float32 getAnimationEndX(edk::uint32 trackPosition);
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::animation::Interpolation1DTracks* tracks){
        //clean frames
        this->cleanTracks();
        if(tracks){
            edk::uint32 size = tracks->stack.size();
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            edk::animation::InterpolationTracks::AnimationAndPosition set;
            edk::animation::Interpolation1DGroup* tempGroup;
            edk::animation::Interpolation1DGroup* setGroup;
            edk::uint32 position=0u;
            for(edk::uint32 i=0u;i<size;i++){
                temp = tracks->stack.get(i);
                tempGroup = (edk::animation::Interpolation1DGroup*)temp.animation;
                if(tempGroup){
                    //create a new animation
                    position = this->newTrack(temp.number);
                    if(position<this->stack.size()){
                        set = this->stack.get(position);
                        setGroup = (edk::animation::Interpolation1DGroup*)set.animation;
                        if(setGroup){
                            setGroup->cloneFrom(tempGroup);
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }

protected:
    //stack of tracks
    class StackTracks1D : public edk::animation::InterpolationTracks::StackTracks{
    public:
        StackTracks1D(){}
        ~StackTracks1D(){}
        virtual void loadElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)value.animation;
            if(group){
                if(group->isPlaying()){
                    if(value.number & EDK_TRACK_ADD_X)
                        this->x+=group->getClockX();
                    else if(value.number & EDK_TRACK_SUB_X)
                        this->x-=group->getClockX();
                    else if(value.number & EDK_TRACK_MULTIPLY_X)
                        this->x*=group->getClockX();
                    else if(value.number & EDK_TRACK_DIVIDE_X)
                        this->x/=group->getClockX();
                    else if(value.number & EDK_TRACK_REPLACE_X)
                        this->x=group->getClockX();
                }
            }
        }
        edk::float32 x;
    }stack;
    //
    virtual edk::animation::InterpolationGroup* newInterpolationGroup();
};
}//end namespace animation
}//end namespace edk

#endif // Interpolation1DTracks_H
