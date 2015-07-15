#ifndef EDK_ANIMATION_INTERPOLATION2DGROUP_H
#define EDK_ANIMATION_INTERPOLATION2DGROUP_H

/*
Library C++ InterpolationGroup2D - Manage one or more interpolations with two values in Edk Game Engine
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
#warning "Inside Interpolation2DGroup"
#endif

#pragma once
#include "Frame2D.h"
#include "Interpolation1DGroup.h"
#include "InterpolationLine2D.h"
#include "../TypeVec2.h"
#include "../vector/Stack.h"
//Clock to the animation
#include "../watch/Time.h"

#ifdef printMessages
#warning "    Compiling Interpolation2DGroup"
#endif

namespace edk{
namespace animation{
class Interpolation2DGroup: public edk::animation::Interpolation1DGroup{
    public:
        Interpolation2DGroup();
        ~Interpolation2DGroup();

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
        //Set the interpolation curve points
        bool setInterpolationP1Y(edk::uint32 position,edk::float32 second,edk::float32 y);
        bool setInterpolationP2Y(edk::uint32 position,edk::float32 second,edk::float32 y);

        //GETERS
        //return the animationPosition
        edk::float32 getClockY(bool* success=NULL);
        //return the interpolation Y
        edk::float32 getInterpolationStartY(edk::float32 position);
        edk::float32 getInterpolationEndY(edk::float32 position);
        //write to XML
        virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

        edk::animation::Interpolation2DGroup operator=(edk::animation::Interpolation2DGroup group){
            //clean frames
            this->cleanAnimations();
            //first copy the frames
            edk::uint32 size = group.animations.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)group.animations[i];
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
        edk::float32 tempY;
        //create the interpolation
        virtual edk::animation::InterpolationLine* newLineInterpolation();
        //create the frame
        virtual edk::animation::Frame* newFrame();
        //print the frame
        virtual void printInterpolationLine(edk::animation::InterpolationLine *interpolation);
    private:
};
}//end namespace animarion
}//end namespace edk

#endif // INTERPOLATION2DGROUP_H
