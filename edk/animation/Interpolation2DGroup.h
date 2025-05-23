#ifndef EDK_ANIMATION_INTERPOLATION2DGROUP_H
#define EDK_ANIMATION_INTERPOLATION2DGROUP_H

/*
Library C++ InterpolationGroup2D - Manage one or more interpolations with two values in Edk Game Engine
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
#pragma message "Inside Interpolation2DGroup"
#endif

#pragma once
#include "Frame2D.h"
#include "Interpolation1DGroup.h"
#include "InterpolationLine2D.h"
#include "../TypeVec2.h"
#include "../vector/Stack.h"
//Clock to the animation
#include "../watch/Time.h"
#include "../Random.h"
#include "../Math.h"

#ifdef printMessages
#pragma message "    Compiling Interpolation2DGroup"
#endif

namespace edk{
namespace animation{
class Interpolation2DGroup: public edk::animation::Interpolation1DGroup{
public:
    Interpolation2DGroup();
    virtual ~Interpolation2DGroup();

    void Constructor();
    void Destructor();

    //Add a first interpolation
    bool addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 endSecond,edk::float32 endX,edk::float32 endY);
    bool addFirstInterpolationLine(edk::float32 startSecond, edk::vec2f32 startValue, edk::float32 endSecond, edk::vec2f32 endValue);
    bool addFirstInterpolationLine(edk::animation::Frame2D start,edk::animation::Frame2D end);

    //Add New Interpolation
    bool addNewInterpolationLine(edk::float32 second,edk::float32 x,edk::float32 y);
    bool addNewInterpolationLine(edk::float32 second,edk::vec2f32 value);
    bool addNewInterpolationLine(edk::animation::Frame2D frame);

    //Set the frame value
    bool setFrame2D(edk::float32 second,edk::float32 x,edk::float32 y);
    bool setFrameY(edk::float32 second,edk::float32 y);

    //Set one interpolation Y as a curve
    bool setInterpolationCurveY(edk::uint32 position);
    bool setInterpolationNotCurveY(edk::uint32 position);
    bool getInterpolationIsCurveY(edk::uint32 position);
    //set as constant interpolation
    bool setConstantY(edk::uint32 position);
    bool setLinearY(edk::uint32 position);
    //set all as constant interpolation
    void setAllConstantY();
    void setAllLinearY();
    //Set the interpolation curve points
    bool setInterpolationP1Y(edk::uint32 position,edk::float32 second,edk::float32 y);
    bool setInterpolationP2Y(edk::uint32 position,edk::float32 second,edk::float32 y);

    //create random animations
    //shake
    edk::float32 addShakingFramesXY(edk::vec2f32 position,edk::float32 randomPercent,edk::float32 percent = 0.9f,edk::float32 interpolationDistance=0.05f);

    //GETERS
    //return the animationPosition
    edk::float32 getClockY();
    //return the interpolation Y
    edk::float32 getInterpolationStartY(edk::float32 position);
    edk::float32 getInterpolationEndY(edk::float32 position);
    //return the animation start and end in Y
    edk::float32 getAnimationStartY();
    edk::float32 getAnimationEndY();
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::animation::Interpolation2DGroup* group){
        //clean frames
        this->cleanAnimations();
        if(group){
            //first copy the frames
            edk::uint32 size = group->animations.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)group->animations.get(i);
                if(temp){
                    //test if it create the start frame
                    if(temp->getCreateStart()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getStart2D());
                    }
                    //test if it create the end frame
                    if(temp->getCreateEnd()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getEnd2D());
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
            this->setIncrement(group->getIncrement());
            return true;
        }
        return false;
    }
protected:
    edk::float32 tempY;
    edk::float32 incrementY;
    edk::float32 incrementYValue;
    //create the interpolation
    virtual edk::animation::InterpolationLine* newLineInterpolation();
    //create the frame
    virtual edk::animation::Frame* newFrame();
    //print the frame
    virtual void printInterpolationLine(edk::animation::InterpolationLine *interpolation);

    //copy interpolation frame
    virtual void copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second);
    virtual void copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second);

    //increment functions to run the increment for the values
    virtual void runIncrementForward();
    virtual void runIncrementRewind();
    virtual void cleanIncrement();
    virtual void startIncrement();
private:

    edk::animation::Interpolation2DGroup operator=(edk::animation::Interpolation2DGroup group){
        return group;
    }
private:
    edk::classID classThis;
};
}//end namespace animarion
}//end namespace edk

#endif // INTERPOLATION2DGROUP_H
