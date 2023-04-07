#include "PathGroup.h"

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
#pragma message "            Inside PathGroup.cpp"
#endif

edk::animation::PathGroup::PathGroup(){
    //
    this->animationPosition = this->positionStart = this->positionEnd = 0u;edkEnd();
    this->secondStart = this->secondEnd = 0.f;edkEnd();
    this->rewind = this->playing = this->looping= this->incrementing = false;edkEnd();
    this->canDelete=true;edkEnd();
    this->lastDist=0.f;edkEnd();
    this->saveStep = 0.f;edkEnd();
    this->closerDistance=0.5f;edkEnd();
    this->changeFrame=false;edkEnd();
    this->step = 0.f;edkEnd();
    this->active=false;edkEnd();
    this->nameSelected=NULL;edkEnd();
    this->speed=1.f;edkEnd();
}
edk::animation::PathGroup::~PathGroup(){
    //
    if(this->canDelete){
        this->deleteFrames();edkEnd();
    }
    else{
        this->animations.cantDestroy();edkEnd();
        this->animationNames.cantDeleteNames();edkEnd();
    }
    this->canDelete=true;edkEnd();
    this->nameSelected=NULL;edkEnd();
}

//create the frame
edk::animation::Frame* edk::animation::PathGroup::newFrame(){
    return new edk::animation::Frame;edkEnd();
}
//return true if the value reach the frame position
bool edk::animation::PathGroup::reachFrame(edk::animation::Frame*){
    this->changeFrame=false;edkEnd();
    return false;
}
//return the last frame
edk::animation::Frame* edk::animation::PathGroup::getLastFrame(){
    //test if is playing
    if(this->isPlaying()){
        //test if it's rewind
        if(this->isRewind()){
            //test if have the last frame
            if(this->animationPosition<this->positionEnd){
                //then return the last frame
                return this->animations[this->animationPosition-1u];edkEnd();
            }
            else if(this->animationPosition==this->positionEnd){
                //test if is looping
                if(this->getLoop()){
                    //then get the start position
                    return this->animations[this->positionStart];edkEnd();
                }
            }
        }
        else{
            //test if have the last frame
            if(this->animationPosition>this->positionStart){
                //then return the last frame
                return this->animations[this->animationPosition-1u];edkEnd();
            }
            else if(this->animationPosition==this->positionStart){
                //test if is looping
                if(this->getLoop()){
                    //then get the start position
                    return this->animations[this->positionEnd];edkEnd();
                }
            }
        }
        //else return this frame
        return this->animations[this->animationPosition];edkEnd();
    }
    //else return this frame
    return NULL;
}

//increment functions to run the increment for the values
void edk::animation::PathGroup::runIncrementForward(){
    //
}
void edk::animation::PathGroup::runIncrementRewind(){
    //
}
void edk::animation::PathGroup::cleanIncrement(){
    //
}
void edk::animation::PathGroup::startIncrement(){
    //
}

//function to get the position by the second inside the animation
edk::uint32 edk::animation::PathGroup::getPositionFromSecond(edk::float32 second){
    edk::uint32 ret =this->animations.size();edkEnd();
    edk::uint32 size = ret;edkEnd();
    edk::animation::Frame* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //search for the animation frame with the second
        temp = this->animations.get(i);edkEnd();
        if(temp){
            if(i==size-1u){
                //test the last frames
                if(second> temp->second){
                    //cant find the position
                    ret=size;edkEnd();
                }
                else if(second > temp->second-0.0001f && second < temp->second+0.0001f){
                    ret=i;edkEnd();
                }
            }
            else{
            if(second < temp->second){
                //get the animation position
                break;
            }
            else if(second> temp->second-0.0001f){
                //copy the position
                ret=i;edkEnd();
            }
            }
        }
    }
    return ret;
}

//add a new frame
bool edk::animation::PathGroup::addNewFrame(edk::float32 seconds){
    //create a new frame
    edk::animation::Frame* frame = this->newFrame();edkEnd();
    if(frame){
        //add the frame to the stack
        if(this->addNewFrame(frame)){
            //set the seconds
            frame->second = seconds;edkEnd();
            return true;
        }
        //else delete the frame
        delete frame;edkEnd();
    }
    return false;
}
bool edk::animation::PathGroup::addNewFrame(edk::animation::Frame* frame){
    //create a new frame
    if(frame){
        //add the frame to the stack
        edk::uint32 size = this->animations.size();edkEnd();
        this->animations.pushBack(frame);edkEnd();
        if(size<this->animations.size()){
            this->positionEnd = size;edkEnd();
            this->positionStart=0u;
            return true;
        }
    }
    return false;
}

//add a new frame to the position
bool edk::animation::PathGroup::addNewFrameToPosition(edk::uint32 position,edk::float32 seconds){
    //create a new frame
    edk::animation::Frame* frame = this->newFrame();edkEnd();
    if(frame){
        //add the frame to the stack
        if(this->addNewFrameToPosition(position,frame)){
            //set the seconds
            frame->second = seconds;edkEnd();
            return true;
        }
        //else delete the frame
        delete frame;edkEnd();
    }
    return false;
}
bool edk::animation::PathGroup::addNewFrameToPosition(edk::uint32 position,edk::animation::Frame* frame){
    //test if have the position
    if(position<(this->animations.size()+1u)
            &&
            frame){
        edk::uint32 newPosition = this->animations.size();edkEnd();
        //then add new frame
        if(this->addNewFrame(frame)){
            //now test if need to change position
            if(position != newPosition){
                //swap the frames
                for(edk::uint32 i=position;i<newPosition;i++){
                    //swap
                    this->animations.swap(i,newPosition);edkEnd();
                }
            }
            return true;
        }
    }
    return false;
}

//delete all frames
bool edk::animation::PathGroup::deleteFrame(edk::uint32 position){
    //test if have the position
    if(this->havePosition(position)){
        //get the frame
        edk::animation::Frame* temp = this->animations[position];edkEnd();
        if(temp){
            //
            edk::uint32 size = this->animations.size()-1u;edkEnd();
            for(edk::uint32 i=position;i<size;i++){
                //swap the position
                this->animations.swap(i,i+1u);edkEnd();
            }
            //then remove the last position
            if(this->animations.popBack()){
                //delete the frame
                delete temp;edkEnd();
                return true;
            }
        }
    }
    return false;
}
void edk::animation::PathGroup::deleteFrames(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::Frame* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //swap the position
        temp = this->animations[i];edkEnd();
        if(temp){
            delete temp;edkEnd();
        }
    }
    this->animations.clean();edkEnd();
}

//set the closerDistance
void edk::animation::PathGroup::setCloserDistance(edk::float32 closerDistance){
    this->closerDistance = closerDistance;edkEnd();
}
edk::float32 edk::animation::PathGroup::getCloserDistance(){
    return this->closerDistance;edkEnd();
}

//test if have the position
bool edk::animation::PathGroup::havePosition(edk::uint32 position){
    if(position<this->animations.size())
        return true;
    return false;
}

//swap
bool edk::animation::PathGroup::swapFrames(edk::uint32 position1,edk::uint32 position2){
    return this->animations.swap(position1,position2);edkEnd();
}

//Set start end
bool edk::animation::PathGroup::setAnimationStartPosition(edk::uint32 position){
    //test the position
    if(this->havePosition(position)){
        //test if is lower thn end
        if(position<this->positionEnd){
            this->animationPosition = this->positionStart = position;edkEnd();
            return true;
        }
        else{
            this->positionEnd = position;edkEnd();
            this->animationPosition = this->positionStart = position;edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::PathGroup::setAnimationStartSecond(edk::float32 second){
    return this->setAnimationStartPosition(this->getPositionFromSecond(second));edkEnd();
}
bool edk::animation::PathGroup::setAnimationEndPosition(edk::uint32 position){
    //test the position
    if(this->havePosition(position)){
        //test if is lower thn end
        if(position>this->positionStart){
            this->positionEnd = position;edkEnd();
            return true;
        }
        else{
            this->positionStart = position;edkEnd();
            this->positionEnd = position;edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::PathGroup::setAnimationEndSecond(edk::float32 second){
    return this->setAnimationEndPosition(this->getPositionFromSecond(second));edkEnd();
}

//Set the speed
bool edk::animation::PathGroup::setSpeed(edk::float32 speed){
    if(speed>0.f){
        this->speed=speed;edkEnd();
        return true;
    }
    this->speed=1.f;edkEnd();
    return false;
}
edk::float32 edk::animation::PathGroup::getSpeed(){
    return this->speed;edkEnd();
}

//CONTROLS
//animation controllers
void edk::animation::PathGroup::playForward(){
    this->playForwardInPosition(this->animationPosition);edkEnd();
}
void edk::animation::PathGroup::playForwardInPosition(edk::uint32 position){
    this->lastDist=0.f;edkEnd();
    //test the position
    if(this->havePosition(position)){
        //test if is inside the animation
        if(position>=this->positionStart
                &&
                position<=this->positionEnd
                ){
            //set foward
            this->rewind=false;edkEnd();
            this->animationPosition=position;edkEnd();
            this->step = 0.f;edkEnd();
            this->saveStep = 0.f;edkEnd();
            //set play
            this->playing=true;edkEnd();
            this->clock.start();edkEnd();

            //test if is incrementing
            if(this->incrementing){
                //run the start incrementing
                this->startIncrement();edkEnd();
            }
        }
    }
}
void edk::animation::PathGroup::playForwardIn(edk::float32 second){
    return this->playForwardInPosition(this->getPositionFromSecond(second));edkEnd();
}
void edk::animation::PathGroup::playRewind(){
    this->playRewindInPosition(this->animationPosition);edkEnd();
}
void edk::animation::PathGroup::playRewindInPosition(edk::uint32 position){
    this->lastDist=0.f;edkEnd();
    //test the position
    if(this->havePosition(position)){
        //test if is inside the animation
        if(position>=this->positionStart
                &&
                position>=this->positionEnd
                ){
            //set foward
            this->rewind=true;edkEnd();
            this->animationPosition=position;edkEnd();
            this->step = 0.f;edkEnd();
            this->saveStep = 0.f;edkEnd();
            //set play
            this->playing=true;edkEnd();
            this->clock.start();edkEnd();

            //test if is incrementing
            if(this->incrementing){
                //run the start incrementing
                this->startIncrement();edkEnd();
            }
            else{
                this->cleanIncrement();edkEnd();
            }
        }
    }
}
void edk::animation::PathGroup::playRewindIn(edk::float32 second){
    return this->playRewindInPosition(this->getPositionFromSecond(second));edkEnd();
}
void edk::animation::PathGroup::pause(){
    this->lastDist=0.f;edkEnd();
    this->playing=!this->playing;edkEnd();
    this->clock.start();edkEnd();
}
void edk::animation::PathGroup::pauseOn(){
    if(!this->playing){
        this->lastDist=0.f;edkEnd();
        this->playing=false;edkEnd();
        this->clock.start();edkEnd();
    }
}
void edk::animation::PathGroup::pauseOff(){
    if(this->playing){
        this->lastDist=0.f;edkEnd();
        this->playing=true;edkEnd();
        this->clock.start();edkEnd();
    }
}
void edk::animation::PathGroup::stop(){
    this->cleanIncrement();edkEnd();
    this->lastDist=0.f;edkEnd();
    this->step = 0.f;edkEnd();
    this->saveStep = 0.f;edkEnd();
    this->playing=false;edkEnd();
    this->animationPosition = this->positionStart;edkEnd();
}
//set loop
void edk::animation::PathGroup::setLoop(bool loop){
    this->looping=loop;edkEnd();
}
void edk::animation::PathGroup::loopOn(){
    this->looping=true;edkEnd();
}
void edk::animation::PathGroup::loopOff(){
    this->looping=false;edkEnd();
}
void edk::animation::PathGroup::setIncrement(bool incrementing){
    this->incrementing=incrementing;edkEnd();
    if(this->isPlaying() && this->incrementing){
        this->startIncrement();edkEnd();
    }
}
void edk::animation::PathGroup::incrementOn(){
    this->setIncrement(true);edkEnd();
}
void edk::animation::PathGroup::incrementOff(){
    this->setIncrement(false);edkEnd();
}

//return if is looping
bool edk::animation::PathGroup::getLoop(){
    return this->looping;edkEnd();
}
bool edk::animation::PathGroup::getIncrement(){
    return this->incrementing;edkEnd();
}
bool edk::animation::PathGroup::isPlaying(){
    return this->playing;edkEnd();
}
bool edk::animation::PathGroup::isRewind(){
    return this->rewind;edkEnd();
}

//ANIMATIONNAMES
bool edk::animation::PathGroup::addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
    return this->addNewAnimationName((edk::char8*) name, start,end);edkEnd();
}
bool edk::animation::PathGroup::addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    //test if have animations
    if(this->animations.size()){
        //test if the name exist and if the start is before the end
        if(name && start<=end){
            //test if the animation dont have the name
            if(!this->animationNames.haveName(name)){
                //then he can add the animationName

                //test if the animation fill inside the full animation
                edk::animation::PathGroup::AnimationPathNames* temp = new edk::animation::PathGroup::AnimationPathNames(name);edkEnd();
                if(temp){
                    //then save the new animationName
                    temp->start=start;edkEnd();
                    temp->end=end;edkEnd();
                    //add the temp
                    if(this->animationNames.add((edk::Name*)temp)){
                        //then return true
                        return true;
                    }

                    //else delete the temp
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return false
    return false;
}
//select the animationName
bool edk::animation::PathGroup::selectAnimationName(const edk::char8* name){
    return this->selectAnimationName((edk::char8*) name);edkEnd();
}
bool edk::animation::PathGroup::selectAnimationName(edk::char8* name){
    //Test the name
    if(name){
        //test if have one selected
        if(this->nameSelected){
            //test if the name is the selected
            if(edk::String::strCompare(name,this->nameSelected->getName())){
                //return true
                return true;
            }
        }
        //create a tempAnimationName
        edk::animation::PathGroup::AnimationPathNames temp(name);edkEnd();
        //find the animationName
        this->nameSelected = (edk::animation::PathGroup::AnimationPathNames*)this->animationNames.getElement(&temp);edkEnd();
        if(this->nameSelected){
            //
            return true;
        }
    }
    this->nameSelected=NULL;edkEnd();
    //else return false
    return false;
}
//test if have the animationName
bool edk::animation::PathGroup::haveAnimationName(const edk::char8* name){
    return this->haveAnimationName((edk::char8*) name);edkEnd();
}
bool edk::animation::PathGroup::haveAnimationName(edk::char8* name){
    //test the name
    if(name){
        //test if have animationName
        return this->animationNames.haveName(name);edkEnd();
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::animation::PathGroup::playNameForward(const edk::char8* name){
    return this->playNameForward((edk::char8*) name);edkEnd();
}
bool edk::animation::PathGroup::playNameForward(edk::char8* name){
    //first select the name
    if(this->selectAnimationName(name)){
        this->positionStart=0u;
        //then set the animationLimits
        this->setAnimationEndSecond(this->nameSelected->end);edkEnd();
        this->setAnimationStartSecond(this->nameSelected->start);edkEnd();
        //then play the animation
        this->playForwardInPosition(this->positionStart);edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::PathGroup::playNameRewind(const edk::char8* name){
    return this->playNameRewind((edk::char8*) name);edkEnd();
}
bool edk::animation::PathGroup::playNameRewind(edk::char8* name){
    //first select the name
    if(this->selectAnimationName(name)){
        this->positionStart=0u;
        //then set the animationLimits
        this->setAnimationEndSecond(this->nameSelected->end);edkEnd();
        this->setAnimationStartSecond(this->nameSelected->start);edkEnd();
        //then play the animation
        this->playRewindInPosition(this->positionEnd);edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::animation::PathGroup::removeAnimationName(const edk::char8* name){
    return this->removeAnimationName((edk::char8*) name);edkEnd();
}
bool edk::animation::PathGroup::removeAnimationName(edk::char8* name){
    //test the name
    if(name){
        //test if have a name selected
        if(this->nameSelected){
            //test if is this nameSelected
            if(edk::String::strCompare(name,this->nameSelected->getName())){
                //clean the nameSelected
                this->cleanAnimationNameSelected();edkEnd();
            }
        }
        //create a temp
        edk::animation::PathGroup::AnimationPathNames *get = (edk::animation::PathGroup::AnimationPathNames *)this->animationNames.getElementByName(name);edkEnd();
        if(get){
            //if have the elemente
            //remove
            this->animationNames.removeName(name);edkEnd();
            //delete
            delete get;edkEnd();
            //and return true
            return true;
        }
    }
    //else return false
    return false;
}
//clean animationName selected
void edk::animation::PathGroup::cleanAnimationNameSelected(){
    this->nameSelected = NULL;edkEnd();
}

//clean all animation Names
void edk::animation::PathGroup::cleanAnimationNames(){
    this->cleanAnimationNameSelected();edkEnd();
    //remove all the root's
    edk::animation::PathGroup::AnimationPathNames* temp=NULL;edkEnd();
    while((temp = (edk::animation::PathGroup::AnimationPathNames*)this->animationNames.getElementInPosition(0u) )){
        //remove the root
        this->animationNames.remove(temp);edkEnd();
        //delete temp
        delete temp;edkEnd();
    }
}

//print frames
void edk::animation::PathGroup::printFrames(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::Frame* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->animations[i];edkEnd();
        if(temp){
            printf("\nSpeed %.2f"
                   ,temp->second
                   );edkEnd();
        }
    }
}
//return the size of frames

edk::uint32 edk::animation::PathGroup::getFramesSize(){
    return this->animations.size();edkEnd();
}
edk::uint32 edk::animation::PathGroup::size(){
    return this->animations.size();edkEnd();
}
//update the clock animation
edk::float32 edk::animation::PathGroup::updateClockAnimation(){
    return this->updateClockAnimation(this->clock.getMicroseconds()*edk::watch::microsecond);edkEnd();
}
edk::float32 edk::animation::PathGroup::updateClockAnimation(edk::float32 distance){
    //test if is playing
    if(this->playing){
        distance*=this->speed;edkEnd();
        //load the clock
        if(distance>0.f){
            this->clock.start();edkEnd();
        }
        edk::animation::Frame* temp = this->animations[this->animationPosition];edkEnd();

        //test if reach the frame
        if(this->reachFrame(temp)){
            //printf("\nReach");edkEnd();
            //then change the animation position and load the new frame

            //test if is rewind
            if(this->isRewind()){
                //rewind

                //test if reach the start
                if(this->animationPosition<=this->positionStart){
                    //test if is loopig or incrementing
                    if(this->getLoop() || this->getIncrement()){
                        //use the end position
                        this->changeFrame=true;edkEnd();
                        this->animationPosition=this->positionEnd;edkEnd();
                        this->step = temp->second;edkEnd();
                        temp = this->animations[this->animationPosition];edkEnd();

                        if(this->getIncrement()){
                            this->runIncrementRewind();edkEnd();
                        }
                    }
                    else{
                        //stop
                        this->stop();edkEnd();
                        return 0.f;
                    }
                }
                else{
                    //test if reach the zero position
                    if(!this->animationPosition){
                        //test if is looping
                        if(this->getLoop() || this->getIncrement()){
                            //use the end position
                            this->changeFrame=true;edkEnd();
                            this->animationPosition=this->positionEnd;edkEnd();
                            this->step = temp->second;edkEnd();
                            temp = this->animations[this->animationPosition];edkEnd();

                            if(this->getIncrement()){
                                this->runIncrementRewind();edkEnd();
                            }
                        }
                        else{
                            //else stop
                            this->stop();edkEnd();
                            return 0.f;
                        }
                    }
                    else{
                        //else just decrement the animationPosition
                        this->changeFrame=true;edkEnd();
                        this->animationPosition--;edkEnd();
                        this->step = temp->second;edkEnd();
                        temp = this->animations[this->animationPosition];edkEnd();
                    }
                }
            }
            else{
                //foward

                //test if reach the start
                if(this->animationPosition>=this->positionEnd){
                    //test if is loopig
                    if(this->getLoop() || this->getIncrement()){
                        //use the start  position
                        this->changeFrame=true;edkEnd();
                        this->animationPosition=this->positionStart;edkEnd();
                        this->step = temp->second;edkEnd();
                        temp = this->animations[this->animationPosition];edkEnd();

                        if(this->getIncrement()){
                            this->runIncrementForward();edkEnd();
                        }
                    }
                    else{
                        //stop
                        this->stop();edkEnd();
                        return 0.f;
                    }
                }
                else{
                    //test if reach the zero position
                    if(this->animationPosition>=this->animations.size()-1u){
                        //test if is looping
                        if(this->getLoop() || this->getIncrement()){
                            //use the start position
                            this->changeFrame=true;edkEnd();
                            this->animationPosition=this->positionStart;edkEnd();
                            this->step = temp->second;edkEnd();
                            temp = this->animations[this->animationPosition];edkEnd();

                            if(this->getIncrement()){
                                this->runIncrementForward();edkEnd();
                            }
                        }
                        else{
                            //else stop
                            this->stop();edkEnd();
                            return 0.f;
                        }
                    }
                    else{
                        //else just decrement the animationPosition
                        this->changeFrame=true;edkEnd();
                        this->animationPosition++;edkEnd();
                        this->step = temp->second;edkEnd();
                        temp = this->animations[this->animationPosition];edkEnd();
                    }
                }
            }
        }
        else{
            //update the step
            if(this->isRewind()){
                //decrement
                this->step-=distance;edkEnd();
                //test if it's smaller then frame second
                if(this->step < temp->second){
                    //then corret the step
                    this->step = temp->second;edkEnd();
                }
            }
            else{
                //increment
                this->step+=distance;edkEnd();
                //test if it's bigger then frame second
                if(this->step > temp->second){
                    //then corret the step
                    this->step = temp->second;edkEnd();
                }
            }
        }


        //step*=temp->second;edkEnd();

        //clock.start();edkEnd();

        return this->step;edkEnd();
    }
    return 0.f;
}

//cand delete
void edk::animation::PathGroup::cantDeleteGroup(){
    this->canDelete = false;edkEnd();
}
//write to XML
bool edk::animation::PathGroup::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"pathAnim_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //save the looping
                        if(this->looping){
                            xml->addSelectedNextAttribute("loop","on");edkEnd();
                        }
                        else{
                            xml->addSelectedNextAttribute("loop","off");edkEnd();
                        }
                        //save the incrementing
                        if(this->incrementing){
                            xml->addSelectedNextAttribute("increment","on");edkEnd();
                        }
                        else{
                            xml->addSelectedNextAttribute("increment","off");edkEnd();
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            this->animations[i]->writeToXML(xml,i);edkEnd();
                        }

                        //write the animationNames
                        size = this->animationNames.size();edkEnd();
                        edk::animation::PathGroup::AnimationPathNames *temp = NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::PathGroup::AnimationPathNames *)this->animationNames.getElementInPosition(i);edkEnd();
                            if(temp){
                                temp->writeToXML(xml,i);edkEnd();
                            }
                        }

                        //
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
bool edk::animation::PathGroup::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"pathAnim_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->deleteFrames();edkEnd();
                    edk::uint32 count = 0u;edkEnd();
                    edk::animation::Frame frameTemp;edkEnd();
                    //read the loop
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("loop"),(edk::char8*)"on")){
                        this->loopOn();edkEnd();
                    }
                    else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("loop"),(edk::char8*)"off")){
                        this->loopOff();edkEnd();
                    }
                    //read the increment
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("increment"),(edk::char8*)"on")){
                        this->incrementOn();edkEnd();
                    }
                    else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("increment"),(edk::char8*)"off")){
                        this->incrementOff();edkEnd();
                    }
                    //read the frames
                    while(frameTemp.readFromXML(xml,count)){
                        //add the frame to the interpolation
                        this->addNewFrame(frameTemp.second);edkEnd();
                        //
                        count++;edkEnd();
                        //clean the frame
                        frameTemp.second = 0.f;edkEnd();
                        //return true
                        ret=true;edkEnd();
                    }

                    //read the names
                    edk::animation::PathGroup::AnimationPathNames nameTemp;edkEnd();
                    while(nameTemp.readFromXML(xml,count)){
                        //add the animationName
                        this->addNewAnimationName(nameTemp.getName(),nameTemp.start,nameTemp.end);edkEnd();

                        count++;edkEnd();
                        //clean nameTemp
                        nameTemp.cleanName();edkEnd();
                        nameTemp.start = 0u;edkEnd();
                        nameTemp.end = 0u;edkEnd();
                    }

                    //
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
