#ifndef EDK_ANIMATION_INTERPOLATIONGROUP_H
#define EDK_ANIMATION_INTERPOLATIONGROUP_H

/*
Biblioteca C++ InterpolationGroup - Manage one or more interpolations in Edk Game Engine
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
#warning "Inside InterpolationGroup"
#endif

#pragma once
//Include the frames
#include "Frame.h"
//Include the interpolation to add in the group
#include "InterpolationLine.h"
//The interpolations are puted in a stack
#include "../vector/Stack.h"
//Clock for the animation
#include "../watch/Time.h"
//BinaryTree
#include "../NameClass.h"
#include "../vector/BinaryTree.h"
//The Object
#include "../Object.h"

#ifdef printMessages
#warning "    Compiling InterpolationGroup"
#endif

namespace edk{
namespace animation{
class InterpolationGroup;
//Animation abstract to callback
class AnimationCallback{
public:
    //animationEnd
    virtual void animationEnd(edk::animation::InterpolationGroup* animation)=0;
};

//animationName
class AnimationName:public edk::Name{
    //
public:
    AnimationName(){
        //
    }
    AnimationName(edk::char8* name)
        :edk::Name(name)
    {
        //
    }
    virtual ~AnimationName(){
        //
        this->deleteName();edkEnd();
    }
    //start and end seconds
    edk::float32 start;
    edk::float32 end;

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 nameID){
        if(xml && this->getName()){
            bool ret=false;edkEnd();
            edk::char8* nameTemp = edk::String::int64ToStr(nameID);edkEnd();
            if(nameTemp){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"animationName_",nameTemp);edkEnd();
                if(name){
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            xml->setSelectedString(this->getName());edkEnd();
                            //write the frame
                            edk::char8* temp = edk::String::float32ToStr(this->start);edkEnd();
                            //test the temp
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"start",temp);edkEnd();
                                delete[] temp;edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->end);edkEnd();
                            //test the temp
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"end",temp);edkEnd();
                                delete[] temp;edkEnd();
                            }
                            xml->selectFather();edkEnd();
                            ret=true;edkEnd();
                        }
                    }
                    delete[] name;edkEnd();
                }
                delete[] nameTemp;edkEnd();
            }
            return ret;
        }
        return false;
    }
    //read from XMl
    bool readFromXML(edk::XML* xml,edk::uint32 nameID){
        if(xml){
            bool ret=false;edkEnd();
            edk::char8* nameTemp = edk::String::int64ToStr(nameID);edkEnd();
            if(nameTemp){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"animationName_",nameTemp);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        edk::char8 filter[3u] = {9u,'\n',0u};
                        edk::char8* temp;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            this->setName(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        this->start = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("start"));edkEnd();
                        this->end   = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("end"  ));edkEnd();
                        xml->selectFather();edkEnd();
                        ret=true;edkEnd();
                    }
                    delete[] name;edkEnd();
                }
                delete[] nameTemp;edkEnd();
            }
            return ret;
        }
        return false;
    }
};

class InterpolationGroup:public edk::Object<InterpolationGroup>{
public:
    InterpolationGroup();
    virtual ~InterpolationGroup();

    //set the abstract
    bool setAnimationCallback(edk::animation::AnimationCallback* callback);
    void removeAnimationCallback();

    //clean the animations
    void cleanAnimations();
    void clean();

    //Add a first interpolation
    bool addFirstInterpolationLine(edk::float32 startSecond,edk::float32 endSecond);
    bool addFirstInterpolationLine(edk::animation::Frame start,edk::animation::Frame end);

    //Add New Interpolation
    bool addNewInterpolationLine(edk::float32 second);
    bool addNewInterpolationLine(edk::animation::Frame frame);

    //Select the frame
    bool selectFrame(edk::float32 second);
    //clean the selected
    void cleanFrameSelected();

    //test if have a tempFrame
    bool haveTempFrame();
    bool selectTempFrame(edk::float32 second);

    //scale the frames
    bool scaleFrames(edk::float32 scale);
    //Speed
    bool setSpeed(edk::float32 speed);
    edk::float32 getSpeed();

    //set the animationStartFrame
    bool setAnimationStartInterpolation(edk::uint32 animationInterpolation);
    bool setAnimationStartSecond(edk::float32 second);
    //set the animationEndFrame
    bool setAnimationEndInterpolation(edk::uint32 animationInterpolation);
    bool setAnimationEndSecond(edk::float32 second);

    //ANIMATIONNAMES
    bool addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end);
    //get the animationName seconds
    edk::float32 getAnimationNameStart(const edk::char8* name);
    edk::float32 getAnimationNameStart(edk::char8* name);
    edk::float32 getAnimationNameEnd(const edk::char8* name);
    edk::float32 getAnimationNameEnd(edk::char8* name);
    //select the animationName
    bool selectAnimationName(const edk::char8* name);
    bool selectAnimationName(edk::char8* name);
    //test if have the animationName
    bool haveAnimationName(const edk::char8* name);
    bool haveAnimationName(edk::char8* name);
    //Play the animationName
    bool playNameForward(const edk::char8* name);
    bool playNameForward(edk::char8* name);
    bool playNameRewind(const edk::char8* name);
    bool playNameRewind(edk::char8* name);
    //remove the animationName
    bool removeAnimationName(const edk::char8* name);
    bool removeAnimationName(edk::char8* name);
    //remove a keyframe
    bool removeKeyFrame(edk::float32 second);
    //clean animationName selected
    void cleanAnimationNameSelected();
    //clean all animation Names
    void cleanAnimationNames();

    //get Loop
    bool getLoop();
    //get Increment
    bool getIncrement();

    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardIn(edk::float32 second);
    void restartForward();
    void playRewind();
    void playRewindIn(edk::float32 second);
    void restartRewind();
    bool changeToForward();
    bool changeToRewind();
    void pause();
    void pauseOn();
    void pauseOff();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();
    //set increment - The animation will run in looping but incrementing the values
    void setIncrement(bool incrementing);
    void incrementOn();
    void incrementOff();

    //GETERS
    //return the number of animations
    edk::uint32 getInterpolationSize();
    edk::uint32 getInterpolations();
    //get the second
    edk::float32 getAnimationSecond();
    //return the missingTime
    edk::float32 getAnimationMissingSecond();
    //get the animation start and end
    edk::float32 getAnimationStart();
    edk::float32 getAnimationEnd();
    edk::float32 getAnimationLenght();
    //return the interpolation seconds
    edk::float32 getInterpolationStartSecond(edk::float32 position);
    edk::float32 getInterpolationEndSecond(edk::float32 position);
    //return if are playing
    bool isPlaying();
    bool isPlayingName(const edk::char8* name);
    bool isPlayingName(edk::char8* name);
    bool isPaused();
    //return true if is rewind
    bool isRewind();
    //update the clock animation
    virtual edk::float32 updateClockAnimation();
    virtual edk::float32 updateClockAnimation(edk::float32 distance);
    //test if have the keyframe
    bool haveKeyframe(edk::float32 second);

    //Print the frames
    bool printFrames();
    //Print the frames from start and end
    bool printSelectedFrames();

    //cand delete
    void cantDeleteGroup();
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::animation::InterpolationGroup* group){
        //clean frames
        this->cleanAnimations();edkEnd();
        if(group){
            //first copy the frames
            edk::uint32 size = group->animations.size();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::InterpolationLine* temp = group->animations[i];edkEnd();
                if(temp){
                    //test if it create the start frame
                    if(temp->getCreateStart()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getStart());edkEnd();
                    }
                    //test if it create the end frame
                    if(temp->getCreateEnd()){
                        //copy the frame to the animation
                        this->addNewInterpolationLine(temp->getEnd());edkEnd();
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

    bool active;
protected:
    //create the interpolation
    virtual edk::animation::InterpolationLine* newLineInterpolation();
    //create the frame
    virtual edk::animation::Frame* newFrame();
    //return the selected interpolation
    edk::animation::InterpolationLine* getSelectedInterpolation();
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

    //TempFrame to save the first interpolation
    edk::animation::Frame* tempFrame;
    //TempInterpolation save the last interpolation added
    edk::animation::InterpolationLine* tempInterpolation;
    //Select a frame to manipulate de data
    edk::animation::InterpolationLine* frameSelected;
    bool frameSelectedStart;
    //save if set the start ou end in interpolation
    bool setStart;
    //save if set the first interpolation
    bool setfirstInterpolation;
    //interpolationList
    edk::vector::Stack<edk::animation::InterpolationLine*> animations;
    //interpolation selected
    edk::uint32 interpolationSelect;
    //animationNames Tree
    edk::vector::NameTree animationNames;
    //animationName selected
    edk::animation::AnimationName* nameSelected;
    //animation speed
    edk::float32 speed;
    //save the frameStart end frameEnd
    edk::float32 frameStart,frameEnd;
    //set the startInterpolation
    edk::uint32 interpolationStart,interpolationEnd;
    //second of the animation
    edk::float32 animationSecond;
    edk::float32 saveAnimationSecond;
private:
    //set if if playing
    bool playing;
    bool paused;
    //set if is playing rewind
    bool rewind;
    //set if it is looping
    bool looping;
    //set if it's incrementing the animation
    bool incrementing;
    //processor clock
    edk::watch::Time clock;
    //callbacks
    edk::animation::AnimationCallback* callback;

    bool canDeleteGroup;

    //Frame functions
    //delete tempFrame
    void deleteTempFrame();
    //search the backInterpolation for the frame
    edk::uint32 searchBackInterpoaltionMinusOne(edk::float32 second);
    edk::uint32 searchBackInterpoaltion(edk::float32 second);
    //insert the frame after the position interpolation
    bool insertLineFrameAfter(edk::uint32 position,edk::animation::Frame frame);
    bool insertLineFrameInside(edk::uint32 position,edk::animation::Frame frame);
    bool insertLineFrameFirst(edk::animation::Frame frame);
    //select the interpolation by the second
    bool selectInterpolationBySecond(edk::float32 second);
    bool selectInterpolationRewindBySecond(edk::float32 second);
    //print the selectedFrames
    bool printSelectedFramesFrom(edk::uint32 start,edk::uint32 end);
    //filter the selectInterpolation from start and end
    void filterSelectInterpolation();
    //update the start and end frames
    void updateStartFrame();
    void updateEndFrame();
    void updateStartEndFrames();
    //test if the second are inside the animation
    bool isSecondInsideAnimation(edk::float32 second);
private:
    edk::animation::InterpolationGroup operator=(edk::animation::InterpolationGroup group){
        //clean frames
        this->cleanAnimations();edkEnd();
        //first copy the frames
        edk::uint32 size = group.animations.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            edk::animation::InterpolationLine* temp = group.animations[i];edkEnd();
            if(temp){
                //test if it create the start frame
                if(temp->getCreateStart()){
                    //copy the frame to the animation
                    this->addNewInterpolationLine(temp->getStart());edkEnd();
                }
                //test if it create the end frame
                if(temp->getCreateEnd()){
                    //copy the frame to the animation
                    this->addNewInterpolationLine(temp->getEnd());edkEnd();
                }
            }
        }

        //now copy the animation names
        size = group.animationNames.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            edk::animation::AnimationName* temp = (edk::animation::AnimationName*)group.animationNames.getElementInPosition(i);edkEnd();
            if(temp){
                this->addNewAnimationName(temp->name(),temp->start,temp->end);edkEnd();
            }
        }
        //
        group.cantDeleteGroup();edkEnd();
        return group;edkEnd();
    }
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATIONGROUP_H
