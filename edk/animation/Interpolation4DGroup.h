#ifndef INTERPOLATION4DGROUP_H
#define INTERPOLATION4DGROUP_H

/*
Library C++ InterpolationGroup4D - Manage one or more interpolations with tree values in Edk Game Engine
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
#pragma message "Inside Interpolation4DGroup"
#endif

#pragma once
#include "Frame3D.h"
#include "InterpolationLine4D.h"
#include "Interpolation3DGroup.h"
#include "../TypeVec4.h"
#include "../vector/Stack.h"
//Clock to the animation
#include "../watch/Time.h"

#ifdef printMessages
#pragma message "    Compiling Interpolation4DGroup"
#endif

namespace edk{
namespace animation{
class Interpolation4DGroup: public Interpolation3DGroup{
public:
    Interpolation4DGroup();
    virtual ~Interpolation4DGroup();

    void Constructor();
    void Destructor();

    //Add a first interpolation
    bool addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 startZ, edk::float32 startW,
                                   edk::float32 endSecond,edk::float32 endX,edk::float32 endY,edk::float32 endZ,edk::float32 endW);
    bool addFirstInterpolationLine(edk::float32 startSecond, edk::vec4f32 startValue, edk::float32 endSecond, edk::vec4f32 endValue);
    bool addFirstInterpolationLine(edk::animation::Frame4D start,edk::animation::Frame4D end);

    //Add New Interpolation
    bool addNewInterpolationLine(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    bool addNewInterpolationLine(edk::float32 second,edk::vec4f32 value);
    bool addNewInterpolationLine(edk::animation::Frame4D frame);

    //Set the frame value
    bool setFrame4D(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    bool setFrameW(edk::float32 second,edk::float32 w);

    //Set one interpolation Y as a curve
    bool setInterpolationCurveW(edk::uint32 position);
    bool setInterpolationNotCurveW(edk::uint32 position);
    bool getInterpolationIsCurveW(edk::uint32 position);
    //set as constant interpolation
    bool setConstantW(edk::uint32 position);
    bool setLinearW(edk::uint32 position);
    //set all as constant interpolation
    void setAllConstantW();
    void setAllLinearW();
    //Set the interpolation curve points
    bool setInterpolationP1W(edk::uint32 position,edk::float32 second,edk::float32 w);
    bool setInterpolationP2W(edk::uint32 position,edk::float32 second,edk::float32 w);

    //GETERS
    //return the animationPosition
    edk::float32 getClockW();
    //return the interpolation W
    edk::float32 getInterpolationStartW(edk::float32 position);
    edk::float32 getInterpolationEndW(edk::float32 position);
    //return the animation start and end in W
    edk::float32 getAnimationStartW();
    edk::float32 getAnimationEndW();
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::animation::Interpolation4DGroup* group){
        //clean frames
        this->cleanAnimations();
        if(group){
            //first copy the frames
            edk::uint32 size = group->animations.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)group->animations.get(i);
                if(temp){
                    //test if it create the start frame
                    if(temp->getCreateStart()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getStart4D());
                    }
                    //test if it create the end frame
                    if(temp->getCreateEnd()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getEnd4D());
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
    edk::float32 tempW;
    edk::float32 incrementW;
    edk::float32 incrementWValue;
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

    edk::animation::Interpolation4DGroup operator=(edk::animation::Interpolation4DGroup group){
        return group;
    }
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATION4DGROUP_H
