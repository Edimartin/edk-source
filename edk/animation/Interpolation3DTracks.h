#ifndef INTERPOLATION3DTRACKS_H

/*
Biblioteca C++ Interpolation3DTracks - Manage one or more interpolation tracks 3D in Edk Game Engine
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
#warning "Inside Interpolation3DTracks"
#endif

#pragma once
#include "../TypeDefines.h"
//Include the interpolation to add in the group
#include "Interpolation3DGroup.h"
//The interpolations are puted in a stack
#include "../vector/Stack.h"
//BinaryTree
#include "../NameClass.h"
//The Object
#include "../Object.h"
//the InterpolationTracks
#include "Interpolation2DTracks.h"

#ifdef printMessages
#warning "    Compiling Interpolation3DTracks"
#endif

namespace edk{
namespace animation{
class Interpolation3DTracks : public edk::animation::Interpolation2DTracks{
public:
    Interpolation3DTracks();
    ~Interpolation3DTracks();

    //Add a first interpolation
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 startZ,
                                   edk::float32 endSecond,edk::float32 endX,edk::float32 endY,edk::float32 endZ);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::vec3f32 startValue, edk::float32 endSecond, edk::vec3f32 endValue);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame3D start,edk::animation::Frame3D end);

    //Add New Interpolation
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z);
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::vec3f32 value);
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame3D frame);

    //Set the frame value
    bool setFrame3D(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z);
    bool setFrameZ(edk::uint32 trackPosition,edk::float32 second,edk::float32 z);

    //Set one interpolation Y as a curve
    bool setInterpolationCurveZ(edk::uint32 trackPosition,edk::uint32 position);
    bool setInterpolationNotCurveZ(edk::uint32 trackPosition,edk::uint32 position);
    bool getInterpolationIsCurveZ(edk::uint32 trackPosition,edk::uint32 position);
    //set as constant interpolation
    bool setConstantZ(edk::uint32 trackPosition,edk::uint32 position);
    bool setLinearZ(edk::uint32 trackPosition,edk::uint32 position);
    //set all as constant interpolation
    bool setAllConstantZ(edk::uint32 trackPosition);
    bool setAllLinearZ(edk::uint32 trackPosition);
    //Set the interpolation curve points
    bool setInterpolationP1Z(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 z);
    bool setInterpolationP2Z(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 z);

    //GETERS
    //return the animationPosition
    edk::float32 getClockZ();
    //return the interpolation Z
    edk::float32 getInterpolationStartZ(edk::uint32 trackPosition,edk::float32 position);
    edk::float32 getInterpolationEndZ(edk::uint32 trackPosition,edk::float32 position);
    //return the animation start and end in Z
    edk::float32 getAnimationStartZ(edk::uint32 trackPosition);
    edk::float32 getAnimationEndZ(edk::uint32 trackPosition);
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::animation::Interpolation3DTracks* tracks){
        //clean frames
        this->cleanTracks();
        if(tracks){
            edk::uint32 size = tracks->tracks.size();
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            edk::animation::InterpolationTracks::AnimationAndPosition set;
            edk::animation::Interpolation3DGroup* tempGroup;
            edk::animation::Interpolation3DGroup* setGroup;
            edk::uint32 position=0u;
            for(edk::uint32 i=0u;i<size;i++){
                temp = tracks->tracks.get(i);
                tempGroup = (edk::animation::Interpolation3DGroup*)temp.animation;
                if(tempGroup){
                    //create a new animation
                    position = this->newTrack(temp.number);
                    if(position<this->tracks.size()){
                        set = this->tracks.get(position);
                        setGroup = (edk::animation::Interpolation3DGroup*)set.animation;
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
    class StackTracks3D : public edk::animation::Interpolation2DTracks::StackTracks2D{
    public:
        StackTracks3D(){}
        ~StackTracks3D(){}
        virtual void renderElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)value.animation;
            if(group){
                if(group->isPlaying()){
                    if(value.number & EDK_TRACK_ADD_Z)
                        this->z+=group->getClockZ();
                    else if(value.number & EDK_TRACK_SUB_Z)
                        this->z-=group->getClockZ();
                    else if(value.number & EDK_TRACK_MULTIPLY_Z)
                        this->z*=group->getClockZ();
                    else if(value.number & EDK_TRACK_DIVIDE_Z)
                        this->z/=group->getClockZ();
                    else if(value.number & EDK_TRACK_REPLACE_Z)
                        this->z=group->getClockZ();
                }
            }
        }
        edk::float32 z;
    }tracks;
    //
    virtual edk::animation::InterpolationGroup* newInterpolationGroup();
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATION3DTRACKS_H
