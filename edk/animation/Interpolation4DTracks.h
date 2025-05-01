#ifndef INTERPOLATION4DTRACKS_H
#define INTERPOLATION4DTRACKS_H

/*
Biblioteca C++ Interpolation4DTracks - Manage one or more interpolation tracks 4D in Edk Game Engine
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
#pragma message "Inside Interpolation4DTracks"
#endif

#pragma once
#include "../TypeDefines.h"
//Include the interpolation to add in the group
#include "Interpolation4DGroup.h"
//The interpolations are puted in a stack
#include "../vector/Stack.h"
//BinaryTree
#include "../NameClass.h"
//The Object
#include "../Object.h"
//the InterpolationTracks
#include "Interpolation3DTracks.h"

#ifdef printMessages
#pragma message "    Compiling Interpolation4DTracks"
#endif

namespace edk{
namespace animation{
class Interpolation4DTracks : public edk::animation::Interpolation3DTracks{
public:
    Interpolation4DTracks();
    virtual ~Interpolation4DTracks();

    void Constructor();
    void Destructor();

    //Add a first interpolation
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 startZ, edk::float32 startW,
                                   edk::float32 endSecond,edk::float32 endX,edk::float32 endY,edk::float32 endZ,edk::float32 endW);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::vec4f32 startValue, edk::float32 endSecond, edk::vec4f32 endValue);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame4D start,edk::animation::Frame4D end);

    //Add New Interpolation
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::vec4f32 value);
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame4D frame);

    //Set the frame value
    bool setFrame4D(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    bool setFrameW(edk::uint32 trackPosition,edk::float32 second,edk::float32 w);

    //Set one interpolation Y as a curve
    bool setInterpolationCurveW(edk::uint32 trackPosition,edk::uint32 position);
    bool setInterpolationNotCurveW(edk::uint32 trackPosition,edk::uint32 position);
    bool getInterpolationIsCurveW(edk::uint32 trackPosition,edk::uint32 position);
    //set as constant interpolation
    bool setConstantW(edk::uint32 trackPosition,edk::uint32 position);
    bool setLinearW(edk::uint32 trackPosition,edk::uint32 position);
    //set all as constant interpolation
    bool setAllConstantW(edk::uint32 trackPosition);
    bool setAllLinearW(edk::uint32 trackPosition);
    //Set the interpolation curve points
    bool setInterpolationP1W(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 w);
    bool setInterpolationP2W(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 w);

    //GETERS
    //return the animationPosition
    edk::float32 getClockW();
    edk::float32 getClockW(edk::float32 w);
    //return the interpolation W
    edk::float32 getInterpolationStartW(edk::uint32 trackPosition,edk::float32 position);
    edk::float32 getInterpolationEndW(edk::uint32 trackPosition,edk::float32 position);
    //return the animation start and end in W
    edk::float32 getAnimationStartW(edk::uint32 trackPosition);
    edk::float32 getAnimationEndW(edk::uint32 trackPosition);
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::animation::Interpolation4DTracks* tracks){
        //clean frames
        this->cleanTracks();
        if(tracks){
            edk::uint32 size = tracks->stack.size();
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            edk::animation::InterpolationTracks::AnimationAndPosition set;
            edk::animation::Interpolation4DGroup* tempGroup;
            edk::animation::Interpolation4DGroup* setGroup;
            edk::uint32 position=0u;
            for(edk::uint32 i=0u;i<size;i++){
                temp = tracks->stack.get(i);
                tempGroup = (edk::animation::Interpolation4DGroup*)temp.animation;
                if(tempGroup){
                    //create a new animation
                    position = this->newTrack(temp.number);
                    if(position<this->stack.size()){
                        set = this->stack.get(position);
                        setGroup = (edk::animation::Interpolation4DGroup*)set.animation;
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
    class StackTracks4D : public edk::animation::Interpolation3DTracks::StackTracks3D{
    public:
        StackTracks4D(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~StackTracks4D(){
            this->Destructor();
        }

        void Constructor(){
            edk::animation::Interpolation3DTracks::StackTracks3D::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::animation::Interpolation3DTracks::StackTracks3D::Destructor();
        }

        virtual void renderElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)value.animation;
            if(group){
                if(group->isPlaying()){
                    if(value.number & EDK_TRACK_ADD_W){
                        this->w+=group->getClockW();
                    }
                    else if(value.number & EDK_TRACK_SUB_W){
                        this->w-=group->getClockW();
                    }
                    else if(value.number & EDK_TRACK_MULTIPLY_W){
                        this->w*=group->getClockW();
                    }
                    else if(value.number & EDK_TRACK_DIVIDE_W){
                        this->w/=group->getClockW();
                    }
                    else if(value.number & EDK_TRACK_REPLACE_W){
                        this->w=group->getClockW();
                    }
                }
            }
        }
        edk::float32 w;
    private:
        edk::classID classThis;
    }stack;
    //
    virtual edk::animation::InterpolationGroup* newInterpolationGroup();
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATION4DTRACKS_H
