#ifndef INTERPOLATIONTRACKS_H
#define INTERPOLATIONTRACKS_H

/*
Biblioteca C++ InterpolationTracks - Manage one or more interpolation tracks in Edk Game Engine
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
#warning "Inside InterpolationTracks"
#endif

#pragma once
#include "../TypeDefines.h"
//Include the interpolation to add in the group
#include "InterpolationGroup.h"
//The interpolations are puted in a stack
#include "../vector/Stack.h"
//BinaryTree
#include "../NameClass.h"
//The Object
#include "../Object.h"

#ifdef printMessages
#warning "    Compiling InterpolationTracks"
#endif

namespace edk{
namespace animation{
//Animation abstract to callback
class AnimationTracksCallback{
public:
    //animationEnd
    virtual void animationEnd(edk::uint32 position)=0;
};
class InterpolationTracks : public edk::animation::AnimationCallback{
public:
    InterpolationTracks();
    ~InterpolationTracks();

    //set the abstract
    bool addAnimationCallback(edk::animation::AnimationTracksCallback* callback);
    bool removeAnimationCallback(edk::animation::AnimationTracksCallback* callback);

    //get size
    edk::uint32 getSize();
    edk::uint32 size();

    //clean all tracks
    void cleanTracks();

    //create a new track and put it into the stack
    edk::uint32 newTrack(edk::typeID type = EDK_TRACK_ADD);
    //set track type in a position
    bool setTrackType(edk::uint32 position,edk::typeID type);

    //remove the track in a position
    bool removeTrack(edk::uint32 position);
    //return true if have a track in a position
    bool haveTrack(edk::uint32 position);

    //move tracks
    bool squapTrack(edk::uint32 position1,edk::uint32 position2);
    bool moveTrack(edk::uint32 start,edk::uint32 dest);
    bool moveToEnd(edk::uint32 position);
    bool moveToBegin(edk::uint32 position);

    //ANIMATION FUNCTIONS
    //Add a first interpolation
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond,edk::float32 endSecond);
    bool addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame start,edk::animation::Frame end);

    //Add New Interpolation
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second);
    bool addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame frame);

    //Select the frame
    bool selectFrame(edk::uint32 trackPosition,edk::float32 second);
    //clean the selected
    bool cleanFrameSelected(edk::uint32 trackPosition);

    //test if have a tempFrame
    bool haveTempFrame(edk::uint32 trackPosition);
    bool selectTempFrame(edk::uint32 trackPosition,edk::float32 second);

    //scale the frames
    bool scaleFrames(edk::uint32 trackPosition,edk::float32 scale);
    //Speed
    bool setSpeedAllTracks(edk::float32 speed);
    bool setSpeed(edk::uint32 trackPosition,edk::float32 speed);
    edk::float32 getSpeed(edk::uint32 trackPosition);

    //set the animationStartFrame
    bool setAllTracksStartInterpolation(edk::uint32 animationInterpolation);
    bool setAllTracksStartSecond(edk::float32 second);
    bool setAnimationStartInterpolation(edk::uint32 trackPosition,edk::uint32 animationInterpolation);
    bool setAnimationStartSecond(edk::uint32 trackPosition,edk::float32 second);
    //set the animationEndFrame
    bool setAllTracksEndInterpolation(edk::uint32 animationInterpolation);
    bool setAllTracksEndSecond(edk::float32 second);
    bool setAnimationEndInterpolation(edk::uint32 trackPosition,edk::uint32 animationInterpolation);
    bool setAnimationEndSecond(edk::uint32 trackPosition,edk::float32 second);

    //ANIMATIONNAMES
    bool addNewAnimationName(edk::uint32 trackPosition,const edk::char8* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationName(edk::uint32 trackPosition,edk::char8* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationNameAllTracks(const edk::char8* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationNameAllTracks(edk::char8* name, edk::float32 start,edk::float32 end);
    //get the animationName seconds
    edk::float32 getAnimationNameStart(edk::uint32 trackPosition,const edk::char8* name);
    edk::float32 getAnimationNameStart(edk::uint32 trackPosition,edk::char8* name);
    edk::float32 getAnimationNameEnd(edk::uint32 trackPosition,const edk::char8* name);
    edk::float32 getAnimationNameEnd(edk::uint32 trackPosition,edk::char8* name);
    //select the animationName
    bool selectAnimationName(edk::uint32 trackPosition,const edk::char8* name);
    bool selectAnimationName(edk::uint32 trackPosition,edk::char8* name);
    //test if have the animationName
    bool haveAnimationName(edk::uint32 trackPosition,const edk::char8* name);
    bool haveAnimationName(edk::uint32 trackPosition,edk::char8* name);
    //Play the animationName
    bool playNameForwardAllTracks(const edk::char8* name);
    bool playNameForwardAllTracks(edk::char8* name);
    bool playNameForward(edk::uint32 trackPosition,const edk::char8* name);
    bool playNameForward(edk::uint32 trackPosition,edk::char8* name);
    bool playNameRewindAllTracks(const edk::char8* name);
    bool playNameRewindAllTracks(edk::char8* name);
    bool playNameRewind(edk::uint32 trackPosition,const edk::char8* name);
    bool playNameRewind(edk::uint32 trackPosition,edk::char8* name);
    //remove the animationName
    bool removeAnimationName(edk::uint32 trackPosition,const edk::char8* name);
    bool removeAnimationName(edk::uint32 trackPosition,edk::char8* name);
    //remove a keyframe
    bool removeKeyFrame(edk::uint32 trackPosition,edk::float32 second);
    //clean animationName selected
    bool cleanAnimationNameSelected(edk::uint32 trackPosition);
    //clean all animation Names
    bool cleanAnimationNamesAllTracks();
    bool cleanAnimationNames(edk::uint32 trackPosition);

    bool setActive(edk::uint32 trackPosition,bool active);
    bool getActive(edk::uint32 trackPosition);

    //get Loop
    bool getLoop(edk::uint32 trackPosition);
    //get Increment
    bool getIncrement(edk::uint32 trackPosition);

    //CONTROLS
    //animation controllers
    bool playForward();
    bool playForwardTrack(edk::uint32 trackPosition);
    bool playForwardIn(edk::float32 second);
    bool playForwardTrackIn(edk::uint32 trackPosition,edk::float32 second);
    bool restartForward();
    bool restartForwardTrack(edk::uint32 trackPosition);
    bool playRewind();
    bool playRewindTrack(edk::uint32 trackPosition);
    bool playRewindIn(edk::float32 second);
    bool playRewindTrackIn(edk::uint32 trackPosition,edk::float32 second);
    bool restartRewind();
    bool restartRewindTrack(edk::uint32 trackPosition);
    bool pause();
    bool pauseTrack(edk::uint32 trackPosition);
    bool pauseOn();
    bool pauseTrackOn(edk::uint32 trackPosition);
    bool pauseOff();
    bool pauseTrackOff(edk::uint32 trackPosition);
    bool stop();
    bool stopTrack(edk::uint32 trackPosition);
    //set loop
    bool setLoopAllTracks(bool loop);
    bool setLoop(edk::uint32 trackPosition,bool loop);
    bool loopOnAllTracks();
    bool loopOn(edk::uint32 trackPosition);
    bool loopOffAllTracks();
    bool loopOff(edk::uint32 trackPosition);
    //set increment - The animation will run in looping but incrementing the values
    bool setIncrementAllTracks(bool incrementing);
    bool setIncrement(edk::uint32 trackPosition,bool incrementing);
    bool incrementAllTracksOn();
    bool incrementOn(edk::uint32 trackPosition);
    bool incrementAllTracksOff();
    bool incrementOff(edk::uint32 trackPosition);

    //GETERS
    //return the number of animations
    edk::uint32 getInterpolationSize(edk::uint32 trackPosition);
    edk::uint32 getInterpolations(edk::uint32 trackPosition);
    //get the second
    edk::float32 getAnimationSecond(edk::uint32 trackPosition);
    //return the missingTime
    edk::float32 getAnimationMissingSecond(edk::uint32 trackPosition);
    //get the animation start and end
    edk::float32 getAnimationStart(edk::uint32 trackPosition);
    edk::float32 getAnimationEnd(edk::uint32 trackPosition);
    edk::float32 getAnimationLenght(edk::uint32 trackPosition);
    //return the interpolation seconds
    edk::float32 getInterpolationStartSecond(edk::uint32 trackPosition,edk::float32 position);
    edk::float32 getInterpolationEndSecond(edk::uint32 trackPosition,edk::float32 position);
    //return if are playing
    bool isPlaying();
    bool isPlayingTrack(edk::uint32 trackPosition);
    bool isPaused();
    bool isPausedTrack(edk::uint32 trackPosition);
    //return true if is rewind
    bool isRewind();
    bool isRewindTrack(edk::uint32 trackPosition);
    //update the clock animation
    virtual edk::float32 updateClockAnimation();
    virtual edk::float32 updateClockAnimation(edk::float32 distance);
    //test if have the keyframe
    bool haveKeyframe(edk::uint32 trackPosition,edk::float32 second);

    //Print the frames
    bool printFrames(edk::uint32 trackPosition);
    bool printFramesAllTracks();
    //Print the frames from start and end
    bool printSelectedFrames(edk::uint32 trackPosition);

    //cand delete
    bool cantDeleteGroup();
    bool cantDeleteGroupTrack(edk::uint32 trackPosition);
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::animation::InterpolationTracks* tracks){
        //clean frames
        this->cleanTracks();
        if(tracks){
            edk::uint32 size = tracks->tracks.size();
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            edk::animation::InterpolationTracks::AnimationAndPosition set;
            edk::uint32 position=0u;
            for(edk::uint32 i=0u;i<size;i++){
                temp = tracks->tracks.get(i);
                if(temp.animation){
                    //create a new animation
                    position = this->newTrack(temp.number);
                    if(position<this->tracks.size()){
                        set = this->tracks.get(position);
                        if(set.animation){
                            set.animation->cloneFrom(temp.animation);
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }

protected:
    virtual edk::animation::InterpolationGroup* newInterpolationGroup();

    //animations in position
    class AnimationAndPosition{
    public:
        AnimationAndPosition(){this->animation=NULL;this->number = 0u;}
        ~AnimationAndPosition(){}
        edk::animation::InterpolationTracks::AnimationAndPosition* operator=(edk::animation::InterpolationTracks::AnimationAndPosition anim){
            this->animation=anim.animation;
            this->number=anim.number;
            return this;
        }
        bool operator>(edk::animation::InterpolationTracks::AnimationAndPosition anim){
            if(this->animation>anim.animation) return true;
            return false;
        }
        bool operator==(edk::animation::InterpolationTracks::AnimationAndPosition anim){
            if(this->animation==anim.animation) return true;
            return false;
        }
        edk::animation::InterpolationGroup* animation;
        edk::uint32 number;
    };
    //animationCallbacks
    edk::vector::BinaryTree<edk::animation::AnimationTracksCallback*> callbacks;
    //tree with the animations position
    edk::vector::BinaryTree<edk::animation::InterpolationTracks::AnimationAndPosition> positions;
    //stack of tracks
    class StackTracks : public edk::vector::Stack<edk::animation::InterpolationTracks::AnimationAndPosition>{
    public:
        StackTracks(){this->seconds=0.f;}
        ~StackTracks(){}
        //
        /*
        virtual void loadElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            //
        }
        virtual void unloadElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            //
        }
        */
        virtual void updateElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            value.animation->updateClockAnimation(this->seconds);
        }
        /*
        virtual void printElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            //
        }
        virtual void renderElement(edk::animation::InterpolationTracks::AnimationAndPosition value){
            //
        }
        */

        /*
        virtual bool load(){
            return edk::vector::Stack<edk::animation::InterpolationTracks::AnimationAndPosition>::load();
        }
        virtual bool unload(){
            return edk::vector::Stack<edk::animation::InterpolationTracks::AnimationAndPosition>::unload();
        }
        virtual bool update(){
            return edk::vector::Stack<edk::animation::InterpolationTracks::AnimationAndPosition>::update();
        }
        virtual bool print(){
            return edk::vector::Stack<edk::animation::InterpolationTracks::AnimationAndPosition>::print();
        }
        virtual bool render(){
            return edk::vector::Stack<edk::animation::InterpolationTracks::AnimationAndPosition>::render();
        }
        */
        edk::float32 seconds;
    }tracks;
private:
    edk::watch::Time time;
    //animation callback
    void animationEnd(edk::animation::InterpolationGroup* animation);

    edk::animation::InterpolationTracks operator=(edk::animation::InterpolationTracks tracks){return tracks;}
};
}//end namespace anim
}//end namespace edk

#endif // INTERPOLATIONTRACKS_H
