#ifndef EDK_ANIMATION_INTERPOLATIONGROUP_H
#define EDK_ANIMATION_INTERPOLATIONGROUP_H

/*
Biblioteca C++ InterpolationGroup - Manage one or more interpolations in Edk Game Engine
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
class AnimationName:public edk::vector::Name{
    //
public:
    AnimationName(){
        //
    }
    AnimationName(edk::char8* name)
        :edk::vector::Name(name)
    {
        //
    }
    virtual ~AnimationName(){
        //
        this->deleteName();
    }
    //start and end seconds
    edk::float32 start;
    edk::float32 end;

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 nameID){
        if(xml && this->getName()){
            bool ret=false;
            edk::char8* nameTemp = edk::String::int64ToStr(nameID);
            if(nameTemp){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"animationName_",nameTemp);
                if(name){
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            xml->setSelectedString(this->getName());
                            //write the frame
                            edk::char8* temp = edk::String::float32ToStr(this->start);
                            //test the temp
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"start",temp);
                                delete[] temp;
                            }
                            temp = edk::String::float32ToStr(this->end);
                            //test the temp
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"end",temp);
                                delete[] temp;
                            }
                            xml->selectFather();
                            ret=true;
                        }
                    }
                    delete[] name;
                }
                delete[] nameTemp;
            }
            return ret;
        }
        return false;
    }
    //read from XMl
    bool readFromXML(edk::XML* xml,edk::uint32 nameID){
        if(xml){
            bool ret=false;
            edk::char8* nameTemp = edk::String::int64ToStr(nameID);
            if(nameTemp){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"animationName_",nameTemp);
                if(name){
                    if(xml->selectChild(name)){
                        edk::char8 filter[3u] = {9u,'\n',0u};
                        edk::char8* temp;
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            this->setName(temp);
                            delete[] temp;
                        }
                        this->start = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("start"));
                        this->end   = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("end"  ));
                        xml->selectFather();
                        ret=true;
                    }
                    delete[] name;
                }
                delete[] nameTemp;
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
    void setSpeed(edk::float32 speed);
    edk::float32 getSpeed();

    //set the animationStartFrame
    bool setAnimationStartInterpolation(edk::uint32 animationInterpolation);
    bool setAnimationStartSecond(edk::float32 second);
    //set the animationEndFrame
    bool setAnimationEndInterpolation(edk::uint32 animationInterpolation);
    bool setAnimationEndSecond(edk::float32 second);

    //ANIMATIONNAMES
    bool addNewAnimationName(const char* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end);
    //select the animationName
    bool selectAnimationName(const char* name);
    bool selectAnimationName(edk::char8* name);
    //test if have the animationName
    bool haveAnimationName(const char* name);
    bool haveAnimationName(edk::char8* name);
    //Play the animationName
    bool playNameForward(const char* name);
    bool playNameForward(edk::char8* name);
    bool playNameRewind(const char* name);
    bool playNameRewind(edk::char8* name);
    //remove the animationName
    bool removeAnimationName(const char* name);
    bool removeAnimationName(edk::char8* name);
    //clean animationName selected
    void cleanAnimationNameSelected();
    //clean all animation Names
    void cleanAnimationNames();

    //get Loop
    bool isLooping();

    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardIn(edk::float32 second);
    void playRewind();
    void playRewindIn(edk::float32 second);
    void pause();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();

    //GETERS
    //return the number of animations
    edk::uint32 getInterpolationSize();
    //get the second
    edk::float32 getAnimationSecond();
    //return the interpolation seconds
    edk::float32 getInterpolationStartSecond(edk::float32 position);
    edk::float32 getInterpolationEndSecond(edk::float32 position);
    //return if are playing
    bool isPlaying();
    bool isPaused();
    //return true if is rewind
    bool isRewind();
    //update the clock animation
    virtual edk::float32 updateClockAnimation();

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

    edk::animation::InterpolationGroup operator=(edk::animation::InterpolationGroup group){
        //clean frames
        this->cleanAnimations();
        //first copy the frames
        edk::uint32 size = group.animations.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            edk::animation::InterpolationLine* temp = group.animations[i];
            if(temp){
                //test if it create the start frame
                if(temp->getCreateStart()){
                    //copy the frame to the animation
                    this->addNewInterpolationLine(temp->getStart());
                }
                //test if it create the end frame
                if(temp->getCreateEnd()){
                    //copy the frame to the animation
                    this->addNewInterpolationLine(temp->getEnd());
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
    //create the interpolation
    virtual edk::animation::InterpolationLine* newLineInterpolation();
    //create the frame
    virtual edk::animation::Frame* newFrame();
    //return the selected interpolation
    edk::animation::InterpolationLine* getSelectedInterpolation();
    //print the frame
    virtual void printInterpolationLine(edk::animation::InterpolationLine *interpolation);

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
private:
    //set if if playing
    bool playing;
    bool paused;
    //set if is playing rewind
    bool rewind;
    //set if it is looping
    bool looping;
    //processor clock
    edk::watch::Time clock;
    //callbacks
    edk::animation::AnimationCallback* callback;

    bool canDeleteGroup;

    //Frame functions
    //delete tempFrame
    void deleteTempFrame();
    //search the backInterpolation for the frame
    unsigned int searchBackInterpoaltion(edk::float32 second);
    //insert the frame after the position interpolation
    bool insertLineFrameAfter(unsigned int position,edk::animation::Frame frame);
    bool insertLineFrameInside(unsigned int position,edk::animation::Frame frame);
    bool insertLineFrameFirst(edk::animation::Frame frame);
    //select the interpolation by the second
    bool selectInterpolationBySecond(edk::float32 second);
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
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATIONGROUP_H
