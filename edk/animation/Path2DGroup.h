#ifndef EDK_ANIMATION_PATH2DGROUP_H
#define EDK_ANIMATION_PATH2DGROUP_H

/*
Biblioteca C++ Path2DGroup - Manage one or more physics animation frames2D in Edk Game Engine
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
#warning "Inside Path2DGroup"
#endif

#pragma once
#include "Path1DGroup.h"
#include "Frame2D.h"

#ifdef printMessages
#warning "    Compiling Path2DGroup"
#endif

namespace edk{
namespace animation{
class Path2DGroup : public edk::animation::Path1DGroup{
public:
    Path2DGroup();

    //add a new frame
    bool addNewFrame(edk::float32 seconds,edk::float32 x,edk::float32 y);
    //add a new frame to the position
    bool addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x,edk::float32 y);

    //set the Y
    void setY(edk::float32 y);
    //get the Y
    edk::float32 getY();

    //update the clock animation
    virtual edk::float32 updateClockAnimation();
    virtual edk::float32 updateClockAnimation(edk::float32 distance);

    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
protected:
    //create the frame
    virtual edk::animation::Frame* newFrame();
    //return true if the value reach the frame position
    virtual bool reachFrame(edk::animation::Frame* frame);

    //increment functions to run the increment for the values
    virtual void runIncrementForward();
    virtual void runIncrementRewind();
    virtual void cleanIncrement();
    virtual void startIncrement();

    void setYNoDecrement(edk::float32 y);
    edk::float32 getYNoIncrement();
private:
    //the x value
    edk::float32 y;
    edk::float32 incrementY;
    edk::float32 incrementYValue;

public:
    virtual bool cloneFrom(edk::animation::Path2DGroup* group){
        //clean frames
        this->deleteFrames();
        if(group){
            //first copy the frames
            edk::uint32 size = group->animations.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::Frame2D* temp = (edk::animation::Frame2D*)group->animations[i];
                if(temp){
                    this->addNewFrame(temp->second,temp->x,temp->y);
                }
            }

            //set if it is loop
            this->setLoop(group->getLoop());
            this->setIncrement(group->getIncrement());

            //now copy the animation names
            size = group->animationNames.size();
            for(edk::uint32 i=0u;i<size;i++){
                edk::animation::PathGroup::AnimationPathNames* temp = (edk::animation::PathGroup::AnimationPathNames*)group->animationNames.getElementInPosition(i);
                if(temp){
                    this->addNewAnimationName(temp->name(),temp->start,temp->end);
                }
            }
            return true;
        }
        return false;
    }
};
}
}

#endif // PATH2DGROUP_H
