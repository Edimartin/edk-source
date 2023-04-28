#ifndef EDK_ANIMATION_PATHGROUP_H
#define EDK_ANIMATION_PATHGROUP_H

/*
Biblioteca C++ PathGroup - Manage one or more physics animation frames in Edk Game Engine
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
#pragma message "Inside PathGroup"
#endif

#pragma once
#include "Frame.h"
#include "../vector/Stack.h"
#include "../watch/Time.h"
#include "../xml/XML.h"
#include "../Math.h"

#ifdef printMessages
#pragma message "    Compiling PathGroup"
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
    bool setAnimationStartSecond(edk::float32 second);
    bool setAnimationEndPosition(edk::uint32 position);
    bool setAnimationEndSecond(edk::float32 second);

    //Set the speed
    bool setSpeed(edk::float32 speed);
    edk::float32 getSpeed();

    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardInPosition(edk::uint32 position);
    void playForwardIn(edk::float32 second);
    void playRewind();
    void playRewindInPosition(edk::uint32 position);
    void playRewindIn(edk::float32 second);
    void pause();
    void pauseOn();
    void pauseOff();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();
    void setIncrement(bool incrementing);
    void incrementOn();
    void incrementOff();
    //return
    bool getLoop();
    bool getIncrement();
    bool isPlaying();
    bool isRewind();

    //ANIMATIONNAMES
    bool addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end);
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

    bool active;
protected:
    //create the frame
    virtual edk::animation::Frame* newFrame();
    //return true if the value reach the frame position
    virtual bool reachFrame(edk::animation::Frame* frame);
    //return the last frame
    edk::animation::Frame* getLastFrame();

    //increment functions to run the increment for the values
    virtual void runIncrementForward();
    virtual void runIncrementRewind();
    virtual void cleanIncrement();
    virtual void startIncrement();

    edk::vector::Stack<edk::animation::Frame*> animations;
    //positions start and end
    edk::uint32 positionStart;
    edk::uint32 positionEnd;
    edk::float32 secondStart;
    edk::float32 secondEnd;
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
    //set if it's incrementing the animation
    bool incrementing;
    //processor clock
    edk::watch::Time clock;
    //speed
    edk::float32 speed;
    //callbacks
    //edk::animation::AnimationCallback* callback;

protected:

    //function to get the position by the second inside the animation
    edk::uint32 getPositionFromSecond(edk::float32 second);


    //Animation Names
    class AnimationPathNames:public edk::Name{
    public:
        AnimationPathNames(){this->start = this->end = 0u;edkEnd();}
        AnimationPathNames(edk::char8* name)
            :edk::Name(name){
            this->start = this->end = 0u;edkEnd();
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
                bool ret=false;edkEnd();
                edk::char8* nameTemp = edk::String::int64ToStr(nameID);edkEnd();
                if(nameTemp){
                    //create the name
                    edk::char8* name = edk::String::strCat((edk::char8*)"animationPathName_",nameTemp);edkEnd();
                    if(name){
                        if(xml->addSelectedNextChild(name)){
                            if(xml->selectChild(name)){
                                xml->setSelectedString(this->getName());edkEnd();
                                //write the frame
                                edk::char8* temp = edk::String::float32ToStr(this->start);edkEnd();
                                //test the temp
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"start",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->end);edkEnd();
                                //test the temp
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"end",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                xml->selectFather();edkEnd();
                                ret=true;edkEnd();
                            }
                        }
                        free(name);edkEnd();
                    }
                    free(nameTemp);edkEnd();
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
                    edk::char8* name = edk::String::strCat((edk::char8*)"animationPathName_",nameTemp);edkEnd();
                    if(name){
                        if(xml->selectChild(name)){
                            edk::char8 filter[3u] = {9u,'\n',0u};
                            edk::char8* temp;edkEnd();
                            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                            if(temp){
                                this->setName(temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            this->start = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("start"));edkEnd();
                            this->end   = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("end"  ));edkEnd();
                            xml->selectFather();edkEnd();
                            ret=true;edkEnd();
                        }
                        free(name);edkEnd();
                    }
                    free(nameTemp);edkEnd();
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
        this->deleteFrames();edkEnd();
        if(group){
            //first copy the frames
            edk::uint32 size = group->animations.size();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                //
                edk::animation::Frame* temp = group->animations.get(i);edkEnd();
                if(temp){
                    this->addNewFrame(temp->second);edkEnd();
                }
            }

            //set if it is loop
            this->setLoop(group->getLoop());edkEnd();
            this->setIncrement(group->getIncrement());edkEnd();

            //now copy the animation names
            size = group->animationNames.size();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                edk::animation::PathGroup::AnimationPathNames* temp = (edk::animation::PathGroup::AnimationPathNames*)group->animationNames.getElementInPosition(i);edkEnd();
                if(temp){
                    this->addNewAnimationName(temp->name(),temp->start,temp->end);edkEnd();
                }
            }
            return true;
        }
        return false;
    }

private:
    edk::animation::PathGroup operator=(edk::animation::PathGroup group){
        return group;edkEnd();
    }
};
}//end namespace animation
}//edn namespace edk

#endif // PATHGROUP_H
