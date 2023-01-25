#include "InterpolationTracks.h"

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

edk::animation::InterpolationTracks::InterpolationTracks(){
    //
    this->time.start();edkEnd();
    this->tracks = &this->stack;edkEnd();
}
edk::animation::InterpolationTracks::~InterpolationTracks(){
    //
    this->cleanTracks();edkEnd();
    //remove all animationCallbacks
}
//animation callback
void edk::animation::InterpolationTracks::animationEnd(edk::animation::InterpolationGroup* animation){
    //get the animation position
    edk::animation::InterpolationTracks::AnimationAndPosition find;edkEnd();
    find.animation = animation;edkEnd();
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->positions.getElement(find);edkEnd();
    if(temp.animation == animation && this->tracks->havePos(temp.number)){
        edk::uint32 size = this->callbacks.size();edkEnd();
        edk::animation::AnimationTracksCallback* callback;edkEnd();
        //run the callbacks
        for(edk::uint32 i=0u;i<size;i++){
            callback = this->callbacks.getElementInPosition(i);edkEnd();
            if(callback){
                callback->animationEnd(temp.number);edkEnd();
            }
        }
    }
}
edk::animation::InterpolationGroup* edk::animation::InterpolationTracks::newInterpolationGroup(){
    return new edk::animation::InterpolationGroup;edkEnd();
}

//set the abstract
bool edk::animation::InterpolationTracks::addAnimationCallback(edk::animation::AnimationTracksCallback* callback){
    if(callback){
        return this->callbacks.add(callback);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::removeAnimationCallback(edk::animation::AnimationTracksCallback* callback){
    if(callback){
        return this->callbacks.remove(callback);edkEnd();
    }
    return false;
}

//get size
edk::uint32 edk::animation::InterpolationTracks::getSize(){
    return this->tracks->size();edkEnd();
}
edk::uint32 edk::animation::InterpolationTracks::size(){
    return this->tracks->size();edkEnd();
}

//clean all tracks
void edk::animation::InterpolationTracks::cleanTracks(){
    edk::uint32 size = this->tracks->size();edkEnd();
    edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->tracks->get(i);edkEnd();
        if(temp.animation){
            delete temp.animation;edkEnd();
        }
    }
    this->tracks->clean();edkEnd();
    this->positions.clean();edkEnd();
}

//create a new track and put it into the stack
edk::uint32 edk::animation::InterpolationTracks::newTrack(edk::typeID type){
    edk::uint32 ret = 0u;edkEnd();
    //get the size
    edk::uint32 size = this->tracks->size();edkEnd();
    //create a new interpolationTrack
    edk::animation::InterpolationTracks::AnimationAndPosition track;edkEnd();
    track.animation = this->newInterpolationGroup();edkEnd();
    if(track.animation){
        track.number = type;edkEnd();
        ret = this->tracks->pushBack(track);edkEnd();
        //add the track into tracks stack
        if(size>=this->tracks->size()){
            //then delete the track and return zero
            delete track.animation;edkEnd();
            ret=0u;
        }
    }
    return ret;
}

//remove the track in a position
bool edk::animation::InterpolationTracks::removeTrack(edk::uint32 position){
    //first test if have the track
    if(this->haveTrack(position)){
        //then remove the track
        edk::animation::InterpolationTracks::AnimationAndPosition temp =  this->tracks->remove(position);edkEnd();
        if(temp.animation){
            delete temp.animation;edkEnd();
            return true;
        }
    }
    return false;
}
//return true if have a track in a position
bool edk::animation::InterpolationTracks::haveTrack(edk::uint32 position){
    return this->tracks->havePos(position);edkEnd();
}

//move tracks
bool edk::animation::InterpolationTracks::squapTrack(edk::uint32 position1,edk::uint32 position2){
    return this->tracks->swap(position1,position2);edkEnd();
}
bool edk::animation::InterpolationTracks::moveTrack(edk::uint32 start,edk::uint32 dest){
    return this->tracks->bringPositionTo(start,dest);edkEnd();
}
bool edk::animation::InterpolationTracks::moveToEnd(edk::uint32 position){
    return this->tracks->bringPositionTo(position,this->tracks->size()-1u);edkEnd();
}
bool edk::animation::InterpolationTracks::moveToBegin(edk::uint32 position){
    return this->tracks->bringPositionTo(position,0u);edkEnd();
}

//ANIMATION FUNCTIONS
//Add a first interpolation
bool edk::animation::InterpolationTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond,edk::float32 endSecond){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->addFirstInterpolationLine(startSecond,endSecond);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame start,edk::animation::Frame end){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->addFirstInterpolationLine(start,end);edkEnd();
    }
    return false;
}

//Add New Interpolation
bool edk::animation::InterpolationTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->addNewInterpolationLine(second);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame frame){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->addNewInterpolationLine(frame);edkEnd();
    }
    return false;
}

//Select the frame
bool edk::animation::InterpolationTracks::selectFrame(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->selectFrame(second);edkEnd();
    }
    return false;
}
//clean the selected
bool edk::animation::InterpolationTracks::cleanFrameSelected(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->cleanFrameSelected();edkEnd();
        return true;
    }
    return false;
}

//test if have a tempFrame
bool edk::animation::InterpolationTracks::haveTempFrame(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->haveTempFrame();edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::selectTempFrame(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->selectTempFrame(second);edkEnd();
    }
    return false;
}

//scale the frames
bool edk::animation::InterpolationTracks::scaleFrames(edk::uint32 trackPosition,edk::float32 scale){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->scaleFrames(scale);edkEnd();
    }
    return false;
}
//Speed
bool edk::animation::InterpolationTracks::setSpeedAllTracks(edk::float32 speed){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->setSpeed(speed)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setSpeed(edk::uint32 trackPosition,edk::float32 speed){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->setSpeed(speed);edkEnd();
        return true;
    }
    return false;
}
edk::float32 edk::animation::InterpolationTracks::getSpeed(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getSpeed();edkEnd();
    }
    return 0.f;
}

//set the animationStartFrame
bool edk::animation::InterpolationTracks::setAllTracksStartInterpolation(edk::uint32 animationInterpolation){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->setAnimationStartInterpolation(animationInterpolation)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setAllTracksStartSecond(edk::float32 second){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->setAnimationStartSecond(second)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setAnimationStartInterpolation(edk::uint32 trackPosition,edk::uint32 animationInterpolation){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->setAnimationStartInterpolation(animationInterpolation);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::setAnimationStartSecond(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->setAnimationStartSecond(second);edkEnd();
    }
    return false;
}
//set the animationEndFrame
bool edk::animation::InterpolationTracks::setAllTracksEndInterpolation(edk::uint32 animationInterpolation){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->setAnimationEndInterpolation(animationInterpolation)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setAllTracksEndSecond(edk::float32 second){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->setAnimationEndSecond(second)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    return ret;
}

//ANIMATIONNAMES
bool edk::animation::InterpolationTracks::addNewAnimationName(edk::uint32 trackPosition,const edk::char8* name, edk::float32 start,edk::float32 end){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->addNewAnimationName(name, start,end);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::addNewAnimationName(edk::uint32 trackPosition,edk::char8* name, edk::float32 start,edk::float32 end){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->addNewAnimationName(name, start,end);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::addNewAnimationNameAllTracks(const edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->addNewAnimationName(name,start,end)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::addNewAnimationNameAllTracks(edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->addNewAnimationName(name,start,end)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    return ret;
}
//get the animationName seconds
edk::float32 edk::animation::InterpolationTracks::getAnimationNameStart(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationNameStart(name);edkEnd();
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationNameStart(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationNameStart(name);edkEnd();
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationNameEnd(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationNameEnd(name);edkEnd();
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationNameEnd(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationNameEnd(name);edkEnd();
    }
    return 0.f;
}
//select the animationName
bool edk::animation::InterpolationTracks::selectAnimationName(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->selectAnimationName(name);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::selectAnimationName(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->selectAnimationName(name);edkEnd();
    }
    return false;
}
//test if have the animationName
bool edk::animation::InterpolationTracks::haveAnimationName(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->haveAnimationName(name);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::haveAnimationName(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->haveAnimationName(name);edkEnd();
    }
    return false;
}
//Play the animationName
bool edk::animation::InterpolationTracks::playNameForwardAllTracks(const edk::char8* name){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->playNameForward(name)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::playNameForwardAllTracks(edk::char8* name){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->playNameForward(name)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::playNameForward(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->playNameForward(name);edkEnd();
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::playNameForward(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->playNameForward(name);edkEnd();
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::playNameRewindAllTracks(const edk::char8* name){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->playNameRewind(name)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::playNameRewindAllTracks(edk::char8* name){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->playNameRewind(name)){
                    ret=true;edkEnd();
                }
            }
        }
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::playNameRewind(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->playNameRewind(name);edkEnd();
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::playNameRewind(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->playNameRewind(name);edkEnd();
    }
    this->time.start();edkEnd();
    return false;
}
//remove the animationName
bool edk::animation::InterpolationTracks::removeAnimationName(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->removeAnimationName(name);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::removeAnimationName(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->removeAnimationName(name);edkEnd();
    }
    return false;
}
//remove a keyframe
bool edk::animation::InterpolationTracks::removeKeyFrame(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->removeKeyFrame(second);edkEnd();
    }
    return false;
}
//clean animationName selected
bool edk::animation::InterpolationTracks::cleanAnimationNameSelected(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->cleanAnimationNameSelected();edkEnd();
        return true;
    }
    return false;
}
//clean all animation Names
bool edk::animation::InterpolationTracks::cleanAnimationNamesAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->cleanAnimationNames();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::animation::InterpolationTracks::cleanAnimationNames(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->cleanAnimationNames();edkEnd();
        return true;
    }
    return false;
}

bool edk::animation::InterpolationTracks::setActive(edk::uint32 trackPosition,bool active){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->active=active;edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::getActive(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->active;edkEnd();
    }
    return false;
}

//get Loop
bool edk::animation::InterpolationTracks::getLoop(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getLoop();edkEnd();
    }
    return false;
}
//get Increment
bool edk::animation::InterpolationTracks::getIncrement(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getIncrement();edkEnd();
    }
    return false;
}

//CONTROLS
//animation controllers
bool edk::animation::InterpolationTracks::playForwardAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->playForward();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::playForwardTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->playForward();edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::playForwardIn(edk::float32 second){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->playForwardIn(second);edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::playForwardTrackIn(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->playForwardIn(second);edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::changeToForwardAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->changeToForward()){
                    ret=true;edkEnd();
                }
            }
        }
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::changeToForwardTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->changeToForward();edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::restartForwardAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->restartForward();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::restartForwardTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->restartForward();edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::playRewindAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->playRewind();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::playRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->playRewind();edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::playRewindIn(edk::float32 second){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->playRewindIn(second);edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::playRewindTrackIn(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->playRewindIn(second);edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::changeToRewindAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->changeToRewind()){
                    ret=true;edkEnd();
                }
            }
        }
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::changeToRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->changeToRewind();edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::restartRewindAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->restartRewind();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::restartRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->restartRewind();edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::pauseAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->pause();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::pauseTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->pause();edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    this->time.start();edkEnd();
    return false;
}
bool edk::animation::InterpolationTracks::pauseOnAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->pauseOn();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::pauseTrackOn(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->pauseOn();edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::pauseOffAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->pauseOff();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::pauseTrackOff(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->pauseOff();edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::stopAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->stop();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    this->time.start();edkEnd();
    return ret;
}
bool edk::animation::InterpolationTracks::stopTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->stop();edkEnd();
        this->time.start();edkEnd();
        return true;
    }
    this->time.start();edkEnd();
    return false;
}
//set loop
bool edk::animation::InterpolationTracks::setLoopAllTracks(bool loop){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->setLoop(loop);edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setLoop(edk::uint32 trackPosition,bool loop){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->setLoop(loop);edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::loopOnAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->loopOn();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::animation::InterpolationTracks::loopOn(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->loopOn();edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::loopOffAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->loopOff();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::animation::InterpolationTracks::loopOff(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->loopOff();edkEnd();
        return true;
    }
    return false;
}
//set increment - The animation will run in looping but incrementing the values
bool edk::animation::InterpolationTracks::setIncrementAllTracks(bool incrementing){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->setIncrement(incrementing);edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setIncrement(edk::uint32 trackPosition,bool incrementing){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->setIncrement(incrementing);edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::incrementAllTracksOn(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->incrementOn();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::animation::InterpolationTracks::incrementOn(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->incrementOn();edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::incrementAllTracksOff(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->incrementOff();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::animation::InterpolationTracks::incrementOff(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->incrementOff();edkEnd();
        return true;
    }
    return false;
}

//GETERS
//return the number of animations
edk::uint32 edk::animation::InterpolationTracks::getInterpolationSize(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getInterpolationSize();edkEnd();
    }
    return 0u;
}
edk::uint32 edk::animation::InterpolationTracks::getInterpolations(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getInterpolations();edkEnd();
    }
    return 0u;
}
//get the second
edk::float32 edk::animation::InterpolationTracks::getAnimationSecond(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationSecond();edkEnd();
    }
    return 0.f;
}
//return the missingTime
edk::float32 edk::animation::InterpolationTracks::getAnimationMissingSecond(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationMissingSecond();edkEnd();
    }
    return 0.f;
}
//get the animation start and end
edk::float32 edk::animation::InterpolationTracks::getAnimationStart(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationStart();edkEnd();
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationEnd(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationEnd();edkEnd();
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationLenght(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getAnimationLenght();edkEnd();
    }
    return 0.f;
}
//return the interpolation seconds
edk::float32 edk::animation::InterpolationTracks::getInterpolationStartSecond(edk::uint32 trackPosition,edk::float32 position){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getInterpolationStartSecond(position);edkEnd();
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getInterpolationEndSecond(edk::uint32 trackPosition,edk::float32 position){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->getInterpolationEndSecond(position);edkEnd();
    }
    return 0.f;
}
//return if are playing
bool edk::animation::InterpolationTracks::isPlaying(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->isPlaying()){
                    ret=true;edkEnd();
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationTracks::isPlayingName(edk::char8* name){
    bool ret=false;edkEnd();
    if(name){
        edk::uint32 size = this->tracks->size();edkEnd();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);edkEnd();
                if(temp.animation){
                    if(temp.animation->isPlayingName(name)){
                        ret=true;edkEnd();
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationTracks::wasPlayingName(edk::char8* name){
    bool ret=false;edkEnd();
    if(name){
        edk::uint32 size = this->tracks->size();edkEnd();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);edkEnd();
                if(temp.animation){
                    if(temp.animation->wasPlayingName(name)){
                        ret=true;edkEnd();
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPlayingTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->isPlaying();edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPlayingNameTrack(edk::uint32 trackPosition,const edk::char8* name){
    return this->isPlayingNameTrack(trackPosition,(edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationTracks::isPlayingNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
        if(temp.animation){
            return temp.animation->isPlayingName(name);edkEnd();
        }
    }
    return false;
}
bool edk::animation::InterpolationTracks::wasPlayingNameTrack(edk::uint32 trackPosition,const edk::char8* name){
    return this->wasPlayingNameTrack(trackPosition,(edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationTracks::wasPlayingNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
        if(temp.animation){
            return temp.animation->wasPlayingName(name);edkEnd();
        }
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPaused(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->isPaused()){
                    ret=true;edkEnd();
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPausedTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->isPaused();edkEnd();
    }
    return false;
}
//return true if is rewind
bool edk::animation::InterpolationTracks::isRewind(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                if(temp.animation->isRewind()){
                    ret=true;edkEnd();
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->isRewind();edkEnd();
    }
    return false;
}
//update the clock animation
edk::float32 edk::animation::InterpolationTracks::updateClockAnimation(){
    edk::float32 distance = this->time.getSeconds();edkEnd();
    this->time.start();edkEnd();
    return this->updateClockAnimation(distance);edkEnd();
}
edk::float32 edk::animation::InterpolationTracks::updateClockAnimation(edk::float32 distance){
    this->tracks->seconds = distance;edkEnd();
    this->tracks->update();edkEnd();
    return distance;edkEnd();
}
//test if have the keyframe
bool edk::animation::InterpolationTracks::haveKeyframe(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->haveKeyframe(second);edkEnd();
    }
    return false;
}

//Print the frames
bool edk::animation::InterpolationTracks::printFrames(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->printFrames();edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::printFramesAllTracks(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->printFrames();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
//Print the frames from start and end
bool edk::animation::InterpolationTracks::printSelectedFrames(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        return temp.animation->printSelectedFrames();edkEnd();
    }
    return false;
}

//cand delete
bool edk::animation::InterpolationTracks::cantDeleteGroup(){
    bool ret=false;edkEnd();
    edk::uint32 size = this->tracks->size();edkEnd();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);edkEnd();
            if(temp.animation){
                temp.animation->cantDeleteGroup();edkEnd();
            }
        }
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::animation::InterpolationTracks::cantDeleteGroupTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        temp.animation->cantDeleteGroup();edkEnd();
        return true;
    }
    return false;
}
//write to XML
bool edk::animation::InterpolationTracks::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->tracks->size();edkEnd();
                        if(size){
                            edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
                            edk::char8* trackID = NULL;edkEnd();
                            edk::char8* trackName = NULL;edkEnd();
                            edk::uint32 counter=0u;
                            for(edk::uint32 i=0u;i<size;i++){
                                temp = this->tracks->get(i);edkEnd();
                                if(temp.animation){
                                    trackID = edk::String::int64ToStr(counter);edkEnd();
                                    if(trackID){
                                        trackName = edk::String::strCat((edk::char8*)"animTrack_",trackID);edkEnd();
                                        if(trackName){
                                            //add the track
                                            xml->addSelectedNextChild("animTrack_");edkEnd();
                                            if(xml->selectChild("animTrack_")){
                                                xml->setSelectedString(temp.number);edkEnd();
                                                //write the animation
                                                temp.animation->writeToXML(xml,counter);edkEnd();
                                                ++counter;edkEnd();
                                                xml->selectFather();edkEnd();
                                            }
                                            delete[] trackName;edkEnd();
                                        }
                                        delete[] trackID;edkEnd();
                                    }
                                }
                            }
                        }
                        xml->selectFather();edkEnd();
                    }
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        return ret;
    }
    return false;
}
//read XML
bool edk::animation::InterpolationTracks::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //
                    edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
                    edk::char8* trackID = NULL;edkEnd();
                    edk::char8* trackName = NULL;edkEnd();
                    edk::uint32 counter=0u;
                    edk::uint32 position=0u;
                    bool running=true;edkEnd();
                    while(running){
                        //generate the strings
                        trackID = edk::String::int64ToStr(counter);edkEnd();
                        if(trackID){
                            trackName = edk::String::strCat((edk::char8*)"animTrack_",trackID);edkEnd();
                            if(trackName){
                                //select the child
                                if(xml->selectChild(trackID)){
                                    //read the string
                                    temp.number = xml->getSelectedStringAsUint32();edkEnd();
                                    //create a new track
                                    position = this->newTrack(temp.number);edkEnd();
                                    if(position<this->tracks->size()){
                                        //get the track and read the XML
                                        temp=this->tracks->get(position);edkEnd();
                                        if(temp.animation){
                                            temp.animation->readFromXML(xml,counter);edkEnd();
                                        }
                                    }
                                    else{
                                        running=false;edkEnd();
                                    }
                                    xml->selectFather();edkEnd();
                                }
                                delete[] trackName;edkEnd();
                            }
                            delete[] trackID;edkEnd();
                        }
                        counter++;edkEnd();
                    }
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        return ret;
    }
    return false;
}
