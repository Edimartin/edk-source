#ifndef EDK_ANIMATION_INTERPOLATION1DGROUP_H
#define EDK_ANIMATION_INTERPOLATION1DGROUP_H

/*
Library C++ InterpolationGroup1D - Manage one or more interpolations with one value in Edk Game Engine
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
#warning "Inside Interpolation1DGroup"
#endif

#pragma once
#include "InterpolationGroup.h"
#include "Frame1D.h"
#include "InterpolationLine1D.h"
#include "../vector/Stack.h"

#ifdef printMessages
#warning "    Compiling Interpolation1DGroup"
#endif

namespace edk{
namespace animation{
class Interpolation1DGroup: public edk::animation::InterpolationGroup{
    public:
        Interpolation1DGroup();
        virtual ~Interpolation1DGroup();

        //Add a first interpolation
        bool addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 endSecond,edk::float32 endX);
        bool addFirstInterpolationLine(edk::animation::Frame1D start,edk::animation::Frame1D end);

        //Add New Interpolation
        bool addNewInterpolationLine(edk::float32 second,edk::float32 x);
        bool addNewInterpolationLine(edk::animation::Frame1D frame);

        //Set the frame value
        bool setFrameX(edk::float32 second,edk::float32 x);

        //Set one interpolation X as a curve
        bool setInterpolationCurveX(edk::uint32 position);
        bool setInterpolationNotCurveX(edk::uint32 position);
        bool getInterpolationIsCurveX(edk::uint32 position);
        //set as constant interpolation
        bool setConstantX(edk::uint32 position);
        bool setLinearX(edk::uint32 position);
        //set all as constant interpolation
        void setAllConstantX();
        void setAllLinearX();
        //Set the interpolation curve points
        bool setInterpolationP1X(edk::uint32 position,edk::float32 second,edk::float32 x);
        bool setInterpolationP2X(edk::uint32 position,edk::float32 second,edk::float32 x);

        //create random animations
        //shake
        edk::float32 addShakingFramesX(edk::float32 position,edk::float32 percent = 0.9f,edk::float32 interpolationDistance=0.05f);

        //set the animationSecond by the X
        bool setSecondByX(edk::float32 oldSecond,edk::float32 x);

        //increment functions to run the increment for the values
        virtual void runIncrementForward();
        virtual void runIncrementRewind();
        virtual void cleanIncrement();
        virtual void startIncrement();

        //GETERS
        //return the animationPosition
        edk::float32 getClockX(bool* success=NULL);
        //return the interpolation seconds
        edk::float32 getInterpolationStartX(edk::float32 position);
        edk::float32 getInterpolationEndX(edk::float32 position);
        //write to XML
        virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

        virtual bool cloneFrom(edk::animation::Interpolation1DGroup* group){
            //clean frames
            this->cleanAnimations();
            if(group){
                //first copy the frames
                edk::uint32 size = group->animations.size();
                for(edk::uint32 i=0u;i<size;i++){
                    //
                    edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)group->animations[i];
                    if(temp){
                        //test if it create the start frame
                        if(temp->getCreateStart()){
                            //copy the frame to the animation
                            this->addNewInterpolationLine(temp->getStart1D());
                        }
                        //test if it create the end frame
                        if(temp->getCreateEnd()){
                            //copy the frame to the animation
                            this->addNewInterpolationLine(temp->getEnd1D());
                        }
                    }
                }

                //now copy the animation names
                size = group->animationNames.size();
                for(edk::uint32 i=0u;i<size;i++){
                    edk::animation::AnimationName* temp = (edk::animation::AnimationName*)group->animationNames.getElementInPosition(i);
                    if(temp){
                        this->addNewAnimationName(temp->name(),temp->start,temp->end);
                    }
                }

                this->setLoop(group->getLoop());
                return true;
            }
            return false;
        }
    protected:
        edk::float32 tempX;
        edk::float32 incrementX;
        edk::float32 incrementXValue;
        //create the interpolation
        virtual edk::animation::InterpolationLine* newLineInterpolation();
        //create the frame
        virtual edk::animation::Frame* newFrame();
        //print the frame
        virtual void printInterpolationLine(edk::animation::InterpolationLine *interpolation);

        //copy interpolation frame
        virtual void copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second);
        virtual void copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second);
    private:

        edk::animation::Interpolation1DGroup operator=(edk::animation::Interpolation1DGroup group){
            //clean frames
            this->cleanAnimations();
            //first copy the frames
            edk::uint32 size = group.animations.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)group.animations[i];
                if(temp){
                    //test if it create the start frame
                    if(temp->getCreateStart()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getStart1D());
                    }
                    //test if it create the end frame
                    if(temp->getCreateEnd()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getEnd1D());
                    }
                }
            }

            //now copy the animation names
            size = group.animationNames.size();
            for(edk::uint32 i=0u;i<size;i++){
                edk::animation::AnimationName* temp = (edk::animation::AnimationName*)group.animationNames.getElementInPosition(i);
                if(temp){
                    this->addNewAnimationName(temp->name(),temp->start,temp->end);
                }
            }
            //
            group.cantDeleteGroup();
            return group;
        }
};
}//end namespace animation
}//end namespace edk


#endif // INTERPOLATION1DGROUP_H
