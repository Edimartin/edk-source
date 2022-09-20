#ifndef INTERPOLATION2DTRACKS_H
#define INTERPOLATION2DTRACKS_H

/*
Biblioteca C++ Interpolation2DTracks - Manage one or more interpolation tracks 2D in Edk Game Engine
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
#warning "Inside Interpolation2DTracks"
#endif

#pragma once
#include "../TypeDefines.h"
//Include the interpolation to add in the group
#include "Interpolation2DGroup.h"
//The interpolations are puted in a stack
#include "../vector/Stack.h"
//BinaryTree
#include "../NameClass.h"
//The Object
#include "../Object.h"
//the InterpolationTracks
#include "Interpolation1DTracks.h"

#ifdef printMessages
#warning "    Compiling Interpolation2DTracks"
#endif

namespace edk{
namespace animation{
class Interpolation2DTracks : public edk::animation::Interpolation1DTracks{
public:
    Interpolation2DTracks();
    ~Interpolation2DTracks();

    //Add a first interpolation
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 endSecond,edk::float32 endX,edk::float32 endY);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::vec2f32 startValue, edk::float32 endSecond, edk::vec2f32 endValue);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame2D start,edk::animation::Frame2D end);

    //Add New Interpolation
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y);
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::vec2f32 value);
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame2D frame);

    //Set the frame value
    bool setFrame2D(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y);
    bool setFrameY(edk::uint32 trackPosition,edk::float32 second,edk::float32 y);

    //Set one interpolation Y as a curve
    bool setInterpolationCurveY(edk::uint32 trackPosition,edk::uint32 position);
    bool setInterpolationNotCurveY(edk::uint32 trackPosition,edk::uint32 position);
    bool getInterpolationIsCurveY(edk::uint32 trackPosition,edk::uint32 position);
    //set as constant interpolation
    bool setConstantY(edk::uint32 trackPosition,edk::uint32 position);
    bool setLinearY(edk::uint32 trackPosition,edk::uint32 position);
    //set all as constant interpolation
    bool setAllConstantY(edk::uint32 trackPosition);
    bool setAllLinearY(edk::uint32 trackPosition);
    //Set the interpolation curve points
    bool setInterpolationP1Y(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 y);
    bool setInterpolationP2Y(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 y);

    //create random animations
    //shake
    edk::float32 addShakingFramesXY(edk::uint32 trackPosition,edk::vec2f32 position,edk::float32 random,edk::float32 percent = 0.9f,edk::float32 interpolationDistance=0.05f);

    //GETERS
    //return the animationPosition
    edk::float32 getClockY();
    //return the interpolation Y
    edk::float32 getInterpolationStartY(edk::uint32 trackPosition,edk::float32 position);
    edk::float32 getInterpolationEndY(edk::uint32 trackPosition,edk::float32 position);
    //return the animation start and end in Y
    edk::float32 getAnimationStartY(edk::uint32 trackPosition);
    edk::float32 getAnimationEndY(edk::uint32 trackPosition);
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::animation::Interpolation2DTracks* tracks){
        //clean frames
        this->cleanTracks();
        if(tracks){
            edk::uint32 size = tracks->tracks.size();
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            edk::animation::InterpolationTracks::AnimationAndPosition set;
            edk::animation::Interpolation2DGroup* tempGroup;
            edk::animation::Interpolation2DGroup* setGroup;
            edk::uint32 position=0u;
            for(edk::uint32 i=0u;i<size;i++){
                temp = tracks->tracks.get(i);
                tempGroup = (edk::animation::Interpolation2DGroup*)temp.animation;
                if(tempGroup){
                    //create a new animation
                    position = this->newTrack(temp.number);
                    if(position<this->tracks.size()){
                        set = this->tracks.get(position);
                        setGroup = (edk::animation::Interpolation2DGroup*)set.animation;
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
    class StackTracks2D : public edk::animation::Interpolation1DTracks::StackTracks1D{
    public:
        StackTracks2D(){}
        ~StackTracks2D(){}
        virtual void printElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)value.animation;
            if(group){
                if(group->isPlaying()){
                    if(value.number & EDK_TRACK_ADD_Y)
                        this->y+=group->getClockY();
                    else if(value.number & EDK_TRACK_SUB_Y)
                        this->y-=group->getClockY();
                    else if(value.number & EDK_TRACK_MULTIPLY_Y)
                        this->y*=group->getClockY();
                    else if(value.number & EDK_TRACK_DIVIDE_Y)
                        this->y/=group->getClockY();
                    else if(value.number & EDK_TRACK_REPLACE_Y)
                        this->y=group->getClockY();
                }
            }
        }
        edk::float32 y;
    }tracks;
    //
    virtual edk::animation::InterpolationGroup* newInterpolationGroup();
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATION2DTRACKS_H
