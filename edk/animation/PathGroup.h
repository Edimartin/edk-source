#ifndef EDK_ANIMATION_PATHGROUP_H
#define EDK_ANIMATION_PATHGROUP_H

/*
Biblioteca C++ PathGroup - Manage one or more physics animation frames in Edk Game Engine
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
#warning "Inside PathGroup"
#endif

#pragma once
#include "Frame.h"
#include "../vector/Stack.h"
#include "../watch/Time.h"
#include "../xml/XML.h"
#include "../Math.h"

#ifdef printMessages
#warning "    Compiling PathGroup"
#endif

namespace edk{
namespace animation{
class PathGroup{
public:
    PathGroup();
    ~PathGroup();

    //add a new frame
    bool addNewFrame(edk::float32 seconds);
    bool addNewFrame(edk::animation::Frame* frame);
    //add a new frame to the position
    bool addNewFrameToPosition(edk::uint32 position,edk::float32 seconds);
    bool addNewFrameToPosition(edk::uint32 position,edk::animation::Frame* frame);

    //delete all frames
    bool deleteFrame(edk::uint32 position);
    void deleteFrames();

    //set the closerDistance
    void setCloserDistance(edk::float32 closerDistance);
    edk::float32 getCloserDistance();

    //test if have the position
    bool havePosition(edk::uint32 position);

    //swap
    bool swapFrames(edk::uint32 position1,edk::uint32 position2);

    //Set start end
    bool setAnimationStartPosition(edk::uint32 position);
    bool setAnimationEndPosition(edk::uint32 position);

    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardIn(edk::uint32 position);
    void playRewind();
    void playRewindIn(edk::uint32 position);
    void pause();
    void pauseOn();
    void pauseOff();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();
    //return if is looping
    bool isLopping();
    bool isPlaying();
    bool isRewind();

    //ANIMATIONNAMES
    bool addNewAnimationName(const char* name, edk::uint32 start,edk::uint32 end);
    bool addNewAnimationName(edk::char8* name, edk::uint32 start,edk::uint32 end);
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

    //print frames
    void printFrames();
    //return the size of frames
    edk::uint32 getFramesSize();
    edk::uint32 size();

    //update the clock animation
    virtual edk::float32 updateClockAnimation();
    virtual edk::float32 updateClockAnimation(edk::float32 distance);

    //cand delete
    void cantDeleteGroup();
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
protected:
    //create the frame
    virtual edk::animation::Frame* newFrame();
    //return true if the value reach the frame position
    virtual bool reachFrame(edk::animation::Frame* frame);
    //return the last frame
    edk::animation::Frame* getLastFrame();

    edk::vector::Stack<edk::animation::Frame*> animations;
    //positions start and end
    edk::uint32 positionStart;
    edk::uint32 positionEnd;
    edk::uint32 animationPosition;
    //save the last distance
    edk::float32 lastDist;
    //save if chane the frame
    bool changeFrame;
    //save closerDistance
    edk::float32 closerDistance;
    //step
    edk::float32 step;
    //save the step
    edk::float32 saveStep;
private:
    bool canDelete;
    //
    //set if if playing
    bool playing;
    //set if is playing rewind
    bool rewind;
    //set if it is looping
    bool looping;
    //processor clock
    edk::watch::Time clock;
    //callbacks
    //edk::animation::AnimationCallback* callback;

protected:

    //Animation Names
    class AnimationPathNames:public edk::Name{
    public:
        AnimationPathNames(){this->start = this->end = 0u;}
        AnimationPathNames(edk::char8* name)
            :edk::Name(name){
            this->start = this->end = 0u;
        }
        ~AnimationPathNames(){
            //
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
                    edk::char8* name = edk::String::strCat((edk::char8*)"animationPathName_",nameTemp);
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
                    edk::char8* name = edk::String::strCat((edk::char8*)"animationPathName_",nameTemp);
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

public:
    //animationNames Tree
    edk::vector::NameTree animationNames;
    //animationName selected
    edk::animation::PathGroup::AnimationPathNames* nameSelected;

    virtual bool cloneFrom(edk::animation::PathGroup* group){
        //clean frames
        this->deleteFrames();
        if(group){
            //first copy the frames
            edk::uint32 size = group->animations.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::Frame* temp = group->animations[i];
                if(temp){
                    this->addNewFrame(temp->second);
                }
            }

            //now copy the animation names
            size = group->animationNames.size();
            for(edk::uint32 i=0u;i<size;i++){
                edk::animation::PathGroup::AnimationPathNames* temp = (edk::animation::PathGroup::AnimationPathNames*)group->animationNames.getElementInPosition(i);
                if(temp){
                    this->addNewAnimationName(temp->name(),temp->start,temp->end);
                }
            }
            return false;
        }
        return false;
    }

private:
    edk::animation::PathGroup operator=(edk::animation::PathGroup group){
        //clean frames
        this->deleteFrames();
        //first copy the frames
        edk::uint32 size = group.animations.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            edk::animation::Frame* temp = group.animations[i];
            if(temp){
                this->addNewFrame(temp->second);
            }
        }

        //now copy the animation names
        size = group.animationNames.size();
        for(edk::uint32 i=0u;i<size;i++){
            edk::animation::PathGroup::AnimationPathNames* temp = (edk::animation::PathGroup::AnimationPathNames*)group.animationNames.getElementInPosition(i);
            if(temp){
                this->addNewAnimationName(temp->name(),temp->start,temp->end);
            }
        }
        //
        group.cantDeleteGroup();
        return group;
    }
};
}//end namespace animation
}//edn namespace edk

#endif // PATHGROUP_H
