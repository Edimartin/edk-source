#ifndef EDK_ANIMATION_INTERPOLATION3DGROUP_H
#define EDK_ANIMATION_INTERPOLATION3DGROUP_H

/*
Library C++ InterpolationGroup3D - Manage one or more interpolations with tree values in Edk Game Engine
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
#warning "Inside Interpolation3DGroup"
#endif

#pragma once
#include "Frame3D.h"
#include "InterpolationLine3D.h"
#include "Interpolation2DGroup.h"
#include "../TypeVec3.h"
#include "../vector/Stack.h"
//Clock to the animation
#include "../watch/Time.h"

#ifdef printMessages
#warning "    Compiling Interpolation3DGroup"
#endif

namespace edk{
namespace animation{
class Interpolation3DGroup: public Interpolation2DGroup{
    public:
        Interpolation3DGroup();
        virtual ~Interpolation3DGroup();

        //Add a first interpolation
        bool addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 startZ,
                                       edk::float32 endSecond,edk::float32 endX,edk::float32 endY,edk::float32 endZ);
        bool addFirstInterpolationLine(edk::float32 startSecond, edk::vec3f32 startValue, edk::float32 endSecond, edk::vec3f32 endValue);
        bool addFirstInterpolationLine(edk::animation::Frame3D start,edk::animation::Frame3D end);

        //Add New Interpolation
        bool addNewInterpolationLine(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z);
        bool addNewInterpolationLine(edk::float32 second,edk::vec3f32 value);
        bool addNewInterpolationLine(edk::animation::Frame3D frame);

        //Set the frame value
        bool setFrame3D(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z);
        bool setFrameZ(edk::float32 second,edk::float32 z);

        //Set one interpolation Y as a curve
        bool setInterpolationCurveZ(edk::uint32 position);
        bool setInterpolationNotCurveZ(edk::uint32 position);
        bool getInterpolationIsCurveZ(edk::uint32 position);
        //set as constant interpolation
        bool setConstantZ(edk::uint32 position);
        bool setLinearZ(edk::uint32 position);
        //set all as constant interpolation
        void setAllConstantZ();
        void setAllLinearZ();
        //Set the interpolation curve points
        bool setInterpolationP1Z(edk::uint32 position,edk::float32 second,edk::float32 z);
        bool setInterpolationP2Z(edk::uint32 position,edk::float32 second,edk::float32 z);

        //GETERS
        //return the animationPosition
        edk::float32 getClockZ();
        //return the interpolation Z
        edk::float32 getInterpolationStartZ(edk::float32 position);
        edk::float32 getInterpolationEndZ(edk::float32 position);
        //return the animation start and end in Z
        edk::float32 getAnimationStartZ();
        edk::float32 getAnimationEndZ();
        //write to XML
        virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

        virtual bool cloneFrom(edk::animation::Interpolation3DGroup* group){
            //clean frames
            this->cleanAnimations();edkEnd();
            if(group){
                //first copy the frames
                edk::uint32 size = group->animations.size();edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    //
                    edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)group->animations[i];edkEnd();
                    if(temp){
                        //test if it create the start frame
                        if(temp->getCreateStart()){
                            //copy the frame to the animation
                            this->addNewInterpolationLine(temp->getStart3D());edkEnd();
                        }
                        //test if it create the end frame
                        if(temp->getCreateEnd()){
                            //copy the frame to the animation
                            this->addNewInterpolationLine(temp->getEnd3D());edkEnd();
                        }
                    }
                }

                //now copy the animation names
                size = group->animationNames.size();edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    edk::animation::AnimationName* temp = (edk::animation::AnimationName*)group->animationNames.getElementInPosition(i);edkEnd();
                    if(temp){
                        this->addNewAnimationName(temp->name(),temp->start,temp->end);edkEnd();
                    }
                }

                this->setLoop(group->getLoop());edkEnd();
                this->setIncrement(group->getIncrement());edkEnd();
                return true;
            }
            return false;
        }
    protected:
        edk::float32 tempZ;
        edk::float32 incrementZ;
        edk::float32 incrementZValue;
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

        edk::animation::Interpolation3DGroup operator=(edk::animation::Interpolation3DGroup group){
            return group;
        }
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATION3DGROUP_H
