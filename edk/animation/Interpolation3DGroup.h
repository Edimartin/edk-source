#ifndef EDK_ANIMATION_INTERPOLATION3DGROUP_H
#define EDK_ANIMATION_INTERPOLATION3DGROUP_H

/*
Library C++ InterpolationGroup3D - Manage one or more interpolations with tree values in Edk Game Engine
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
class Interpolation3DGroup: public Interpolation2DGroup
{
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
        edk::float32 getClockZ(bool* success=NULL);
        //return the interpolation Z
        edk::float32 getInterpolationStartZ(edk::float32 position);
        edk::float32 getInterpolationEndZ(edk::float32 position);
        //write to XML
        virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

        edk::animation::Interpolation3DGroup operator=(edk::animation::Interpolation3DGroup group){
            //clean frames
            this->cleanAnimations();
            //first copy the frames
            edk::uint32 size = group.animations.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)group.animations[i];
                if(temp){
                    //test if it create the start frame
                    if(temp->getCreateStart()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getStart3D());
                    }
                    //test if it create the end frame
                    if(temp->getCreateEnd()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getEnd3D());
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
        edk::float32 tempZ;
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

#endif // INTERPOLATION3DGROUP_H
