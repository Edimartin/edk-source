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
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::InterpolationTracks::~InterpolationTracks(){
    this->Destructor();
}

void edk::animation::InterpolationTracks::Constructor(){
    edk::animation::AnimationCallback::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();
        this->time.Constructor();

        this->time.start();
        this->tracks = &this->stack;
    }
}
void edk::animation::InterpolationTracks::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanTracks();
        //remove all animationCallbacks

        this->stack.Destructor();
        this->time.Destructor();
    }
    edk::animation::AnimationCallback::Destructor();
}

//animation callback
void edk::animation::InterpolationTracks::animationEnd(edk::animation::InterpolationGroup* animation){
    //get the animation position
    edk::animation::InterpolationTracks::AnimationAndPosition find;
    find.animation = animation;
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->positions.getElement(find);
    if(temp.animation == animation && this->tracks->havePos(temp.number)){
        edk::uint32 size = this->callbacks.size();
        edk::animation::AnimationTracksCallback* callback;
        //run the callbacks
        for(edk::uint32 i=0u;i<size;i++){
            callback = this->callbacks.getElementInPosition(i);
            if(callback){
                callback->animationEnd(temp.number);
            }
        }
    }
}
edk::animation::InterpolationGroup* edk::animation::InterpolationTracks::newInterpolationGroup(){
    return new edk::animation::InterpolationGroup;
}

//set the abstract
bool edk::animation::InterpolationTracks::addAnimationCallback(edk::animation::AnimationTracksCallback* callback){
    if(callback){
        return this->callbacks.add(callback);
    }
    return false;
}
bool edk::animation::InterpolationTracks::removeAnimationCallback(edk::animation::AnimationTracksCallback* callback){
    if(callback){
        return this->callbacks.remove(callback);
    }
    return false;
}

//get size
edk::uint32 edk::animation::InterpolationTracks::getSize(){
    return this->tracks->size();
}
edk::uint32 edk::animation::InterpolationTracks::size(){
    return this->tracks->size();
}

//clean all tracks
void edk::animation::InterpolationTracks::cleanTracks(){
    edk::uint32 size = this->tracks->size();
    edk::animation::InterpolationTracks::AnimationAndPosition temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->tracks->get(i);
        if(temp.animation){
            delete temp.animation;
        }
    }
    this->tracks->clean();
    this->positions.clean();
}
void edk::animation::InterpolationTracks::clean(){
    this->cleanTracks();
}

//create a new track and put it into the stack
edk::uint32 edk::animation::InterpolationTracks::newTrack(edk::typeID type){
    edk::uint32 ret = 0u;
    //get the size
    edk::uint32 size = this->tracks->size();
    //create a new interpolationTrack
    edk::animation::InterpolationTracks::AnimationAndPosition track;
    track.animation = this->newInterpolationGroup();
    if(track.animation){
        track.number = type;
        ret = this->tracks->pushBack(track);
        //add the track into tracks stack
        if(size>=this->tracks->size()){
            //then delete the track and return zero
            delete track.animation;
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
        edk::animation::InterpolationTracks::AnimationAndPosition temp =  this->tracks->remove(position);
        if(temp.animation){
            delete temp.animation;
            return true;
        }
    }
    return false;
}
//return true if have a track in a position
bool edk::animation::InterpolationTracks::haveTrack(edk::uint32 position){
    return this->tracks->havePos(position);
}

//move tracks
bool edk::animation::InterpolationTracks::squapTrack(edk::uint32 position1,edk::uint32 position2){
    return this->tracks->swap(position1,position2);
}
bool edk::animation::InterpolationTracks::moveTrack(edk::uint32 start,edk::uint32 dest){
    return this->tracks->bringPositionTo(start,dest);
}
bool edk::animation::InterpolationTracks::moveToEnd(edk::uint32 position){
    return this->tracks->bringPositionTo(position,this->tracks->size()-1u);
}
bool edk::animation::InterpolationTracks::moveToBegin(edk::uint32 position){
    return this->tracks->bringPositionTo(position,0u);
}

//ANIMATION FUNCTIONS
//Add a first interpolation
bool edk::animation::InterpolationTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond,edk::float32 endSecond){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->addFirstInterpolationLine(startSecond,endSecond);
    }
    return false;
}
bool edk::animation::InterpolationTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame start,edk::animation::Frame end){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->addFirstInterpolationLine(start,end);
    }
    return false;
}

//Add New Interpolation
bool edk::animation::InterpolationTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->addNewInterpolationLine(second);
    }
    return false;
}
bool edk::animation::InterpolationTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame frame){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->addNewInterpolationLine(frame);
    }
    return false;
}

//Select the frame
bool edk::animation::InterpolationTracks::selectFrame(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->selectFrame(second);
    }
    return false;
}
//clean the selected
bool edk::animation::InterpolationTracks::cleanFrameSelected(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->cleanFrameSelected();
        return true;
    }
    return false;
}

//test if have a tempFrame
bool edk::animation::InterpolationTracks::haveTempFrame(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->haveTempFrame();
    }
    return false;
}
bool edk::animation::InterpolationTracks::selectTempFrame(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->selectTempFrame(second);
    }
    return false;
}

//scale the frames
bool edk::animation::InterpolationTracks::scaleFrames(edk::uint32 trackPosition,edk::float32 scale){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->scaleFrames(scale);
    }
    return false;
}
//Speed
bool edk::animation::InterpolationTracks::setSpeedAllTracks(edk::float32 speed){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->setSpeed(speed)){
                    ret=true;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setSpeed(edk::uint32 trackPosition,edk::float32 speed){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->setSpeed(speed);
        return true;
    }
    return false;
}
edk::float32 edk::animation::InterpolationTracks::getSpeed(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getSpeed();
    }
    return 0.f;
}

//set the animationStartFrame
bool edk::animation::InterpolationTracks::setAllTracksStartInterpolation(edk::uint32 animationInterpolation){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->setAnimationStartInterpolation(animationInterpolation)){
                    ret=true;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setAllTracksStartSecond(edk::float32 second){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->setAnimationStartSecond(second)){
                    ret=true;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setAnimationStartInterpolation(edk::uint32 trackPosition,edk::uint32 animationInterpolation){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->setAnimationStartInterpolation(animationInterpolation);
    }
    return false;
}
bool edk::animation::InterpolationTracks::setAnimationStartSecond(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->setAnimationStartSecond(second);
    }
    return false;
}
//set the animationEndFrame
bool edk::animation::InterpolationTracks::setAllTracksEndInterpolation(edk::uint32 animationInterpolation){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->setAnimationEndInterpolation(animationInterpolation)){
                    ret=true;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setAllTracksEndSecond(edk::float32 second){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->setAnimationEndSecond(second)){
                    ret=true;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setAnimationEndInterpolation(edk::uint32 trackPosition,edk::uint32 animationInterpolation){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->setAnimationEndInterpolation(animationInterpolation);
    }
    return false;
}
bool edk::animation::InterpolationTracks::setAnimationEndSecond(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->setAnimationEndSecond(second);
    }
    return false;
}

//ANIMATIONNAMES
bool edk::animation::InterpolationTracks::addNewAnimationName(edk::uint32 trackPosition,const edk::char8* name, edk::float32 start,edk::float32 end){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->addNewAnimationName(name, start,end);
    }
    return false;
}
bool edk::animation::InterpolationTracks::addNewAnimationName(edk::uint32 trackPosition,edk::char8* name, edk::float32 start,edk::float32 end){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->addNewAnimationName(name, start,end);
    }
    return false;
}
bool edk::animation::InterpolationTracks::addNewAnimationNameAllTracks(const edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->addNewAnimationName(name,start,end)){
                    ret=true;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::addNewAnimationNameAllTracks(edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->addNewAnimationName(name,start,end)){
                    ret=true;
                }
            }
        }
    }
    return ret;
}
//get the animationName seconds
edk::float32 edk::animation::InterpolationTracks::getAnimationNameStart(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationNameStart(name);
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationNameStart(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationNameStart(name);
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationNameEnd(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationNameEnd(name);
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationNameEnd(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationNameEnd(name);
    }
    return 0.f;
}
//select the animationName
bool edk::animation::InterpolationTracks::selectAnimationName(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->selectAnimationName(name);
    }
    return false;
}
bool edk::animation::InterpolationTracks::selectAnimationName(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->selectAnimationName(name);
    }
    return false;
}
//test if have the animationName
bool edk::animation::InterpolationTracks::haveAnimationName(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->haveAnimationName(name);
    }
    return false;
}
bool edk::animation::InterpolationTracks::haveAnimationName(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->haveAnimationName(name);
    }
    return false;
}
//Play the animationName
bool edk::animation::InterpolationTracks::playNameForwardAllTracks(const edk::char8* name){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->playNameForward(name)){
                    ret=true;
                }
            }
        }
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::playNameForwardAllTracks(edk::char8* name){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->playNameForward(name)){
                    ret=true;
                }
            }
        }
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::playNameForward(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->playNameForward(name);
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playNameForward(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->playNameForward(name);
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playNameForwardIn(edk::uint32 trackPosition,const edk::char8* name,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->playNameForwardIn(name,second);
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playNameForwardIn(edk::uint32 trackPosition,edk::char8* name,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->playNameForwardIn(name,second);
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playNameRewindAllTracks(const edk::char8* name){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->playNameRewind(name)){
                    ret=true;
                }
            }
        }
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::playNameRewindAllTracks(edk::char8* name){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->playNameRewind(name)){
                    ret=true;
                }
            }
        }
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::playNameRewind(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->playNameRewind(name);
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playNameRewind(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->playNameRewind(name);
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playNameRewindIn(edk::uint32 trackPosition,const edk::char8* name,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->playNameRewindIn(name,second);
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playNameRewindIn(edk::uint32 trackPosition,edk::char8* name,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->playNameRewindIn(name,second);
    }
    this->time.start();
    return false;
}
//remove the animationName
bool edk::animation::InterpolationTracks::removeAnimationName(edk::uint32 trackPosition,const edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->removeAnimationName(name);
    }
    return false;
}
bool edk::animation::InterpolationTracks::removeAnimationName(edk::uint32 trackPosition,edk::char8* name){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->removeAnimationName(name);
    }
    return false;
}
//remove a keyframe
bool edk::animation::InterpolationTracks::removeKeyFrame(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->removeKeyFrame(second);
    }
    return false;
}
//clean animationName selected
bool edk::animation::InterpolationTracks::cleanAnimationNameSelected(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->cleanAnimationNameSelected();
        return true;
    }
    return false;
}
//clean all animation Names
bool edk::animation::InterpolationTracks::cleanAnimationNamesAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->cleanAnimationNames();
            }
        }
        ret=true;
    }
    return ret;
}
bool edk::animation::InterpolationTracks::cleanAnimationNames(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->cleanAnimationNames();
        return true;
    }
    return false;
}

bool edk::animation::InterpolationTracks::setActive(edk::uint32 trackPosition,bool active){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->active=active;
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::getActive(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->active;
    }
    return false;
}

//get Loop
bool edk::animation::InterpolationTracks::getLoop(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getLoop();
    }
    return false;
}
//get Increment
bool edk::animation::InterpolationTracks::getIncrement(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getIncrement();
    }
    return false;
}

//CONTROLS
//animation controllers
bool edk::animation::InterpolationTracks::playForwardAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->playForward();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::playForwardTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->playForward();
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playForwardAllTracksIn(edk::float32 second){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->playForwardIn(second);
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::playForwardTrackIn(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->playForwardIn(second);
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::changeToForwardAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->changeToForward()){
                    ret=true;
                }
            }
        }
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::changeToForwardTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->changeToForward();
    }
    return false;
}
bool edk::animation::InterpolationTracks::restartForwardAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->restartForward();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::restartForwardTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->restartForward();
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playRewindAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->playRewind();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::playRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->playRewind();
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::playRewindAllTracksIn(edk::float32 second){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->playRewindIn(second);
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::playRewindTrackIn(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->playRewindIn(second);
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::changeToRewindAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->changeToRewind()){
                    ret=true;
                }
            }
        }
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::changeToRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->changeToRewind();
    }
    return false;
}
bool edk::animation::InterpolationTracks::restartRewindAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->restartRewind();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::restartRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->restartRewind();
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::changeWayAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->changeWay();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::changeWayTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->changeWay();
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::pauseAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->pause();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::pauseTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->pause();
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
bool edk::animation::InterpolationTracks::pauseOnAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->pauseOn();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::pauseTrackOn(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->pauseOn();
        this->time.start();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::pauseOffAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->pauseOff();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::pauseTrackOff(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->pauseOff();
        this->time.start();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::stopAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->stop();
            }
        }
        ret=true;
    }
    this->time.start();
    return ret;
}
bool edk::animation::InterpolationTracks::stopTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->stop();
        this->time.start();
        return true;
    }
    this->time.start();
    return false;
}
//set loop
bool edk::animation::InterpolationTracks::setLoopAllTracks(bool loop){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->setLoop(loop);
            }
        }
        ret=true;
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setLoop(edk::uint32 trackPosition,bool loop){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->setLoop(loop);
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::loopOnAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->loopOn();
            }
        }
        ret=true;
    }
    return ret;
}
bool edk::animation::InterpolationTracks::loopOn(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->loopOn();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::loopOffAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->loopOff();
            }
        }
        ret=true;
    }
    return ret;
}
bool edk::animation::InterpolationTracks::loopOff(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->loopOff();
        return true;
    }
    return false;
}
//set increment - The animation will run in looping but incrementing the values
bool edk::animation::InterpolationTracks::setIncrementAllTracks(bool incrementing){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->setIncrement(incrementing);
            }
        }
        ret=true;
    }
    return ret;
}
bool edk::animation::InterpolationTracks::setIncrement(edk::uint32 trackPosition,bool incrementing){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->setIncrement(incrementing);
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::incrementAllTracksOn(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->incrementOn();
            }
        }
        ret=true;
    }
    return ret;
}
bool edk::animation::InterpolationTracks::incrementOn(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->incrementOn();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::incrementAllTracksOff(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->incrementOff();
            }
        }
        ret=true;
    }
    return ret;
}
bool edk::animation::InterpolationTracks::incrementOff(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->incrementOff();
        return true;
    }
    return false;
}

//GETERS
//return the number of animations
edk::uint32 edk::animation::InterpolationTracks::getInterpolationSize(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getInterpolationSize();
    }
    return 0u;
}
edk::uint32 edk::animation::InterpolationTracks::getInterpolations(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getInterpolations();
    }
    return 0u;
}
//get the second
edk::float32 edk::animation::InterpolationTracks::getAnimationSecond(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationSecond();
    }
    return 0.f;
}
//return the missingTime
edk::float32 edk::animation::InterpolationTracks::getAnimationMissingSecond(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationMissingSecond();
    }
    return 0.f;
}
//get the animation start and end
edk::float32 edk::animation::InterpolationTracks::getAnimationStart(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationStart();
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationEnd(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationEnd();
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getAnimationLenght(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getAnimationLenght();
    }
    return 0.f;
}
//return the interpolation seconds
edk::float32 edk::animation::InterpolationTracks::getInterpolationStartSecond(edk::uint32 trackPosition,edk::float32 position){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getInterpolationStartSecond(position);
    }
    return 0.f;
}
edk::float32 edk::animation::InterpolationTracks::getInterpolationEndSecond(edk::uint32 trackPosition,edk::float32 position){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getInterpolationEndSecond(position);
    }
    return 0.f;
}
//return an interpolation position in second
edk::uint32 edk::animation::InterpolationTracks::getInterpolationPositionInSecond(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->getInterpolationPositionInSecond(second);
    }
    return 0u;
}
//return an interpolation position in second
bool edk::animation::InterpolationTracks::haveInterpolationPositionInSecond(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->haveInterpolationPositionInSecond(second);
    }
    return false;
}
//return if are playing
bool edk::animation::InterpolationTracks::isPlaying(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->isPlaying()){
                    ret=true;
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);
}
bool edk::animation::InterpolationTracks::isPlayingName(edk::char8* name){
    bool ret=false;
    if(name){
        edk::uint32 size = this->tracks->size();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);
                if(temp.animation){
                    if(temp.animation->isPlayingName(name)){
                        ret=true;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPlayingFoward(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->isPlayingFoward()){
                    ret=true;
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPlayingFowardName(const edk::char8* name){
    return this->isPlayingFowardName((edk::char8*) name);
}
bool edk::animation::InterpolationTracks::isPlayingFowardName(edk::char8* name){
    bool ret=false;
    if(name){
        edk::uint32 size = this->tracks->size();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);
                if(temp.animation){
                    if(temp.animation->isPlayingFowardName(name)){
                        ret=true;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPlayingRewind(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->isPlayingRewind()){
                    ret=true;
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPlayingRewindName(const edk::char8* name){
    return this->isPlayingRewindName((edk::char8*) name);
}
bool edk::animation::InterpolationTracks::isPlayingRewindName(edk::char8* name){
    bool ret=false;
    if(name){
        edk::uint32 size = this->tracks->size();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);
                if(temp.animation){
                    if(temp.animation->isPlayingRewindName(name)){
                        ret=true;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);
}
bool edk::animation::InterpolationTracks::wasPlayingName(edk::char8* name){
    bool ret=false;
    if(name){
        edk::uint32 size = this->tracks->size();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);
                if(temp.animation){
                    if(temp.animation->wasPlayingName(name)){
                        ret=true;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::wasPlayingFoward(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->wasPlayingFoward()){
                    ret=true;
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::wasPlayingFowardName(const edk::char8* name){
    return this->wasPlayingFowardName((edk::char8*) name);
}
bool edk::animation::InterpolationTracks::wasPlayingFowardName(edk::char8* name){
    bool ret=false;
    if(name){
        edk::uint32 size = this->tracks->size();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);
                if(temp.animation){
                    if(temp.animation->wasPlayingFowardName(name)){
                        ret=true;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::wasPlayingRewind(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->wasPlayingRewind()){
                    ret=true;
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::wasPlayingRewindName(const edk::char8* name){
    return this->wasPlayingRewindName((edk::char8*) name);
}
bool edk::animation::InterpolationTracks::wasPlayingRewindName(edk::char8* name){
    bool ret=false;
    if(name){
        edk::uint32 size = this->tracks->size();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);
                if(temp.animation){
                    if(temp.animation->wasPlayingRewindName(name)){
                        ret=true;
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
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->isPlaying();
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPlayingNameTrack(edk::uint32 trackPosition,const edk::char8* name){
    return this->isPlayingNameTrack(trackPosition,(edk::char8*) name);
}
bool edk::animation::InterpolationTracks::isPlayingNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
        if(temp.animation){
            return temp.animation->isPlayingName(name);
        }
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPlayingFowardTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->isPlayingFoward();
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPlayingFowardNameTrack(edk::uint32 trackPosition,const edk::char8* name){
    return this->isPlayingFowardNameTrack(trackPosition,(edk::char8*) name);
}
bool edk::animation::InterpolationTracks::isPlayingFowardNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
        if(temp.animation){
            return temp.animation->isPlayingFowardName(name);
        }
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPlayingRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->isPlayingRewind();
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPlayingRewindNameTrack(edk::uint32 trackPosition,const edk::char8* name){
    return this->isPlayingRewindNameTrack(trackPosition,(edk::char8*) name);
}
bool edk::animation::InterpolationTracks::isPlayingRewindNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
        if(temp.animation){
            return temp.animation->isPlayingRewindName(name);
        }
    }
    return false;
}
bool edk::animation::InterpolationTracks::wasPlayingNameTrack(edk::uint32 trackPosition,const edk::char8* name){
    return this->wasPlayingNameTrack(trackPosition,(edk::char8*) name);
}
bool edk::animation::InterpolationTracks::wasPlayingNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
        if(temp.animation){
            return temp.animation->wasPlayingName(name);
        }
    }
    return false;
}
bool edk::animation::InterpolationTracks::wasPlayingFowardTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->wasPlayingFoward();
    }
    return false;
}
bool edk::animation::InterpolationTracks::wasPlayingFowardNameTrack(edk::uint32 trackPosition,const edk::char8* name){
    return this->wasPlayingFowardNameTrack(trackPosition,(edk::char8*) name);
}
bool edk::animation::InterpolationTracks::wasPlayingFowardNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
        if(temp.animation){
            return temp.animation->wasPlayingFowardName(name);
        }
    }
    return false;
}
bool edk::animation::InterpolationTracks::wasPlayingRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->wasPlayingRewind();
    }
    return false;
}
bool edk::animation::InterpolationTracks::wasPlayingRewindNameTrack(edk::uint32 trackPosition,const edk::char8* name){
    return this->wasPlayingRewindNameTrack(trackPosition,(edk::char8*) name);
}
bool edk::animation::InterpolationTracks::wasPlayingRewindNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
        if(temp.animation){
            return temp.animation->wasPlayingRewindName(name);
        }
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPaused(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->isPaused()){
                    ret=true;
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPausedName(const edk::char8* name){
    return this->isPausedName((edk::char8*) name);
}
bool edk::animation::InterpolationTracks::isPausedName(edk::char8* name){
    bool ret=false;
    if(name){
        edk::uint32 size = this->tracks->size();
        if(size){
            edk::animation::InterpolationTracks::AnimationAndPosition temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->tracks->get(i);
                if(temp.animation){
                    if(temp.animation->isPausedName(name)){
                        ret=true;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isPausedTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->isPaused();
    }
    return false;
}
bool edk::animation::InterpolationTracks::isPausedNameTrack(edk::uint32 /*trackPosition*/,const edk::char8* /*name*/){
    //
    return false;
}
bool edk::animation::InterpolationTracks::isPausedNameTrack(edk::uint32 trackPosition,edk::char8* name){
    if(name){
        //get track in position
        edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
        if(temp.animation){
            return temp.animation->isPausedName(name);
        }
    }
    return false;
}
//return true if is rewind
bool edk::animation::InterpolationTracks::isRewind(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                if(temp.animation->isRewind()){
                    ret=true;
                    break;
                }
            }
        }
    }
    return ret;
}
bool edk::animation::InterpolationTracks::isRewindTrack(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->isRewind();
    }
    return false;
}
//update the clock animation
edk::float32 edk::animation::InterpolationTracks::updateClockAnimation(){
    edk::float32 distance = this->time.getSeconds();
    this->time.start();
    return this->updateClockAnimation(distance);
}
edk::float32 edk::animation::InterpolationTracks::updateClockAnimation(edk::float32 distance){
    this->tracks->seconds = distance;
    this->tracks->update();
    return distance;
}
//test if have the keyframe
bool edk::animation::InterpolationTracks::haveKeyframe(edk::uint32 trackPosition,edk::float32 second){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->haveKeyframe(second);
    }
    return false;
}

//Print the frames
bool edk::animation::InterpolationTracks::printFrames(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        temp.animation->printFrames();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationTracks::printFramesAllTracks(){
    bool ret=false;
    edk::uint32 size = this->tracks->size();
    if(size){
        edk::animation::InterpolationTracks::AnimationAndPosition temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->tracks->get(i);
            if(temp.animation){
                temp.animation->printFrames();
            }
        }
        ret=true;
    }
    return ret;
}
//Print the frames from start and end
bool edk::animation::InterpolationTracks::printSelectedFrames(edk::uint32 trackPosition){
    //get track in position
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        return temp.animation->printSelectedFrames();
    }
    return false;
}

//write to XML
bool edk::animation::InterpolationTracks::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->tracks->size();
                        if(size){
                            edk::animation::InterpolationTracks::AnimationAndPosition temp;
                            edk::char8* trackID = NULL;
                            edk::char8* trackName = NULL;
                            edk::uint32 counter=0u;
                            for(edk::uint32 i=0u;i<size;i++){
                                temp = this->tracks->get(i);
                                if(temp.animation){
                                    trackID = edk::String::int64ToStr(counter);
                                    if(trackID){
                                        trackName = edk::String::strCat((edk::char8*)"animTrack_",trackID);
                                        if(trackName){
                                            //add the track
                                            xml->addSelectedNextChild("animTrack_");
                                            if(xml->selectChild("animTrack_")){
                                                xml->setSelectedString(temp.number);
                                                //write the animation
                                                temp.animation->writeToXML(xml,counter);
                                                ++counter;
                                                xml->selectFather();
                                            }
                                            free(trackName);
                                        }
                                        free(trackID);
                                    }
                                }
                            }
                        }
                        xml->selectFather();
                    }
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
//read XML
bool edk::animation::InterpolationTracks::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //
                    edk::animation::InterpolationTracks::AnimationAndPosition temp;
                    edk::char8* trackID = NULL;
                    edk::char8* trackName = NULL;
                    edk::uint32 counter=0u;
                    edk::uint32 position=0u;
                    bool running=true;
                    while(running){
                        //generate the strings
                        trackID = edk::String::int64ToStr(counter);
                        if(trackID){
                            trackName = edk::String::strCat((edk::char8*)"animTrack_",trackID);
                            if(trackName){
                                //select the child
                                if(xml->selectChild(trackID)){
                                    //read the string
                                    temp.number = xml->getSelectedStringAsUint32();
                                    //create a new track
                                    position = this->newTrack(temp.number);
                                    if(position<this->tracks->size()){
                                        //get the track and read the XML
                                        temp=this->tracks->get(position);
                                        if(temp.animation){
                                            temp.animation->readFromXML(xml,counter);
                                        }
                                    }
                                    else{
                                        running=false;
                                    }
                                    xml->selectFather();
                                }
                                free(trackName);
                            }
                            free(trackID);
                        }
                        counter++;
                    }
                    xml->selectFather();
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
