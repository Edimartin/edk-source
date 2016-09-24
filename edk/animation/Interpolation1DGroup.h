#ifndef EDK_ANIMATION_INTERPOLATION1DGROUP_H
#define EDK_ANIMATION_INTERPOLATION1DGROUP_H

/*
Library C++ InterpolationGroup1D - Manage one or more interpolations with one value in Edk Game Engine
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
        edk::float32 addShakingFramesX(edk::float32 interpolationDistance, edk::float32 position, edk::float32 percent = 0.9f);

        //set the animationSecond by the X
        bool setSecondByX(edk::float32 oldSecond,edk::float32 x);

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
    protected:
        edk::float32 tempX;
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
};
}//end namespace animation
}//end namespace edk


#endif // INTERPOLATION1DGROUP_H
