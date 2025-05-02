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
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::PathGroup::~PathGroup(){
    this->Destructor();
}

void edk::animation::PathGroup::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->animations.Constructor();
        this->clock.Constructor();
        this->animationNames.Constructor();

        this->animationPosition = this->positionStart = this->positionEnd = 0u;
        this->secondStart = this->secondEnd = 0.f;
        this->rewind = this->playing = this->looping= this->incrementing = false;
        this->lastDist=0.f;
        this->saveStep = 0.f;
        this->closerDistance=0.5f;
        this->changeFrame=false;
        this->step = 0.f;
        this->active=false;
        this->nameSelected=NULL;
        this->speed=1.f;
    }
}
void edk::animation::PathGroup::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteFrames();
        this->nameSelected=NULL;

        this->animations.Destructor();
        this->clock.Destructor();
        this->animationNames.Destructor();
    }
}

//create the frame
edk::animation::Frame* edk::animation::PathGroup::newFrame(){
    return new edk::animation::Frame;
}
//return true if the value reach the frame position
bool edk::animation::PathGroup::reachFrame(edk::animation::Frame*){
    this->changeFrame=false;
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
                return this->animations.get(this->animationPosition-1u);
            }
            else if(this->animationPosition==this->positionEnd){
                //test if is looping
                if(this->getLoop()){
                    //then get the start position
                    return this->animations.get(this->positionStart);
                }
            }
        }
        else{
            //test if have the last frame
            if(this->animationPosition>this->positionStart){
                //then return the last frame
                return this->animations.get(this->animationPosition-1u);
            }
            else if(this->animationPosition==this->positionStart){
                //test if is looping
                if(this->getLoop()){
                    //then get the start position
                    return this->animations.get(this->positionEnd);
                }
            }
        }
        //else return this frame
        return this->animations.get(this->animationPosition);
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
    edk::uint32 ret =this->animations.size();
    edk::uint32 size = ret;
    edk::animation::Frame* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        //search for the animation frame with the second
        temp = this->animations.get(i);
        if(temp){
            if(i==size-1u){
                //test the last frames
                if(second> temp->second){
                    //cant find the position
                    ret=size;
                }
                else if(second > temp->second-0.0001f && second < temp->second+0.0001f){
                    ret=i;
                }
            }
            else{
                if(second < temp->second){
                    //get the animation position
                    break;
                }
                else if(second> temp->second-0.0001f){
                    //copy the position
                    ret=i;
                }
            }
        }
    }
    return ret;
}

//add a new frame
bool edk::animation::PathGroup::addNewFrame(edk::float32 seconds){
    //create a new frame
    edk::animation::Frame* frame = this->newFrame();
    if(frame){
        //add the frame to the stack
        if(this->addNewFrame(frame)){
            //set the seconds
            frame->second = seconds;
            return true;
        }
        //else delete the frame
        delete frame;
    }
    return false;
}
bool edk::animation::PathGroup::addNewFrame(edk::animation::Frame* frame){
    //create a new frame
    if(frame){
        //add the frame to the stack
        edk::uint32 size = this->animations.size();
        this->animations.pushBack(frame);
        if(size<this->animations.size()){
            this->positionEnd = size;
            this->positionStart=0u;
            return true;
        }
    }
    return false;
}

//add a new frame to the position
bool edk::animation::PathGroup::addNewFrameToPosition(edk::uint32 position,edk::float32 seconds){
    //create a new frame
    edk::animation::Frame* frame = this->newFrame();
    if(frame){
        //add the frame to the stack
        if(this->addNewFrameToPosition(position,frame)){
            //set the seconds
            frame->second = seconds;
            return true;
        }
        //else delete the frame
        delete frame;
    }
    return false;
}
bool edk::animation::PathGroup::addNewFrameToPosition(edk::uint32 position,edk::animation::Frame* frame){
    //test if have the position
    if(position<(this->animations.size()+1u)
            &&
            frame){
        edk::uint32 newPosition = this->animations.size();
        //then add new frame
        if(this->addNewFrame(frame)){
            //now test if need to change position
            if(position != newPosition){
                //swap the frames
                for(edk::uint32 i=position;i<newPosition;i++){
                    //swap
                    this->animations.swap(i,newPosition);
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
        edk::animation::Frame* temp = this->animations.get(position);
        if(temp){
            //
            edk::uint32 size = this->animations.size()-1u;
            for(edk::uint32 i=position;i<size;i++){
                //swap the position
                this->animations.swap(i,i+1u);
            }
            //then remove the last position
            if(this->animations.popBack()){
                //delete the frame
                delete temp;
                return true;
            }
        }
    }
    return false;
}
void edk::animation::PathGroup::deleteFrames(){
    edk::uint32 size = this->animations.size();
    edk::animation::Frame* temp;
    for(edk::uint32 i=0u;i<size;i++){
        //swap the position
        temp = this->animations.get(i);
        if(temp){
            delete temp;
        }
    }
    this->animations.clean();
}

//set the closerDistance
void edk::animation::PathGroup::setCloserDistance(edk::float32 closerDistance){
    this->closerDistance = closerDistance;
}
edk::float32 edk::animation::PathGroup::getCloserDistance(){
    return this->closerDistance;
}

//test if have the position
bool edk::animation::PathGroup::havePosition(edk::uint32 position){
    if(position<this->animations.size())
        return true;
    return false;
}

//swap
bool edk::animation::PathGroup::swapFrames(edk::uint32 position1,edk::uint32 position2){
    return this->animations.swap(position1,position2);
}

//Set start end
bool edk::animation::PathGroup::setAnimationStartPosition(edk::uint32 position){
    //test the position
    if(this->havePosition(position)){
        //test if is lower thn end
        if(position<this->positionEnd){
            this->animationPosition = this->positionStart = position;
            return true;
        }
        else{
            this->positionEnd = position;
            this->animationPosition = this->positionStart = position;
            return true;
        }
    }
    return false;
}
bool edk::animation::PathGroup::setAnimationStartSecond(edk::float32 second){
    return this->setAnimationStartPosition(this->getPositionFromSecond(second));
}
bool edk::animation::PathGroup::setAnimationEndPosition(edk::uint32 position){
    //test the position
    if(this->havePosition(position)){
        //test if is lower thn end
        if(position>this->positionStart){
            this->positionEnd = position;
            return true;
        }
        else{
            this->positionStart = position;
            this->positionEnd = position;
            return true;
        }
    }
    return false;
}
bool edk::animation::PathGroup::setAnimationEndSecond(edk::float32 second){
    return this->setAnimationEndPosition(this->getPositionFromSecond(second));
}

//Set the speed
bool edk::animation::PathGroup::setSpeed(edk::float32 speed){
    if(speed>0.f){
        this->speed=speed;
        return true;
    }
    this->speed=1.f;
    return false;
}
edk::float32 edk::animation::PathGroup::getSpeed(){
    return this->speed;
}

//CONTROLS
//animation controllers
void edk::animation::PathGroup::playForward(){
    this->playForwardInPosition(this->animationPosition);
}
void edk::animation::PathGroup::playForwardInPosition(edk::uint32 position){
    this->lastDist=0.f;
    //test the position
    if(this->havePosition(position)){
        //test if is inside the animation
        if(position>=this->positionStart
                &&
                position<=this->positionEnd
                ){
            //set foward
            this->rewind=false;
            this->animationPosition=position;
            this->step = 0.f;
            this->saveStep = 0.f;
            //set play
            this->playing=true;
            this->clock.start();

            //test if is incrementing
            if(this->incrementing){
                //run the start incrementing
                this->startIncrement();
            }
        }
    }
}
void edk::animation::PathGroup::playForwardIn(edk::float32 second){
    return this->playForwardInPosition(this->getPositionFromSecond(second));
}
void edk::animation::PathGroup::playRewind(){
    this->playRewindInPosition(this->animationPosition);
}
void edk::animation::PathGroup::playRewindInPosition(edk::uint32 position){
    this->lastDist=0.f;
    //test the position
    if(this->havePosition(position)){
        //test if is inside the animation
        if(position>=this->positionStart
                &&
                position>=this->positionEnd
                ){
            //set foward
            this->rewind=true;
            this->animationPosition=position;
            this->step = 0.f;
            this->saveStep = 0.f;
            //set play
            this->playing=true;
            this->clock.start();

            //test if is incrementing
            if(this->incrementing){
                //run the start incrementing
                this->startIncrement();
            }
            else{
                this->cleanIncrement();
            }
        }
    }
}
void edk::animation::PathGroup::playRewindIn(edk::float32 second){
    return this->playRewindInPosition(this->getPositionFromSecond(second));
}
void edk::animation::PathGroup::pause(){
    this->lastDist=0.f;
    this->playing=!this->playing;
    this->clock.start();
}
void edk::animation::PathGroup::pauseOn(){
    if(!this->playing){
        this->lastDist=0.f;
        this->playing=false;
        this->clock.start();
    }
}
void edk::animation::PathGroup::pauseOff(){
    if(this->playing){
        this->lastDist=0.f;
        this->playing=true;
        this->clock.start();
    }
}
void edk::animation::PathGroup::stop(){
    this->cleanIncrement();
    this->lastDist=0.f;
    this->step = 0.f;
    this->saveStep = 0.f;
    this->playing=false;
    this->animationPosition = this->positionStart;
}
//set loop
void edk::animation::PathGroup::setLoop(bool loop){
    this->looping=loop;
}
void edk::animation::PathGroup::loopOn(){
    this->looping=true;
}
void edk::animation::PathGroup::loopOff(){
    this->looping=false;
}
void edk::animation::PathGroup::setIncrement(bool incrementing){
    this->incrementing=incrementing;
    if(this->isPlaying() && this->incrementing){
        this->startIncrement();
    }
}
void edk::animation::PathGroup::incrementOn(){
    this->setIncrement(true);
}
void edk::animation::PathGroup::incrementOff(){
    this->setIncrement(false);
}

//return if is looping
bool edk::animation::PathGroup::getLoop(){
    return this->looping;
}
bool edk::animation::PathGroup::getIncrement(){
    return this->incrementing;
}
bool edk::animation::PathGroup::isPlaying(){
    return this->playing;
}
bool edk::animation::PathGroup::isRewind(){
    return this->rewind;
}

//ANIMATIONNAMES
bool edk::animation::PathGroup::addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
    return this->addNewAnimationName((edk::char8*) name, start,end);
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
                edk::animation::PathGroup::AnimationPathNames* temp = new edk::animation::PathGroup::AnimationPathNames(name);
                if(temp){
                    //then save the new animationName
                    temp->start=start;
                    temp->end=end;
                    //add the temp
                    if(this->animationNames.add((edk::Name*)temp)){
                        //then return true
                        return true;
                    }

                    //else delete the temp
                    delete temp;
                }
            }
        }
    }
    //else return false
    return false;
}
//select the animationName
bool edk::animation::PathGroup::selectAnimationName(const edk::char8* name){
    return this->selectAnimationName((edk::char8*) name);
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
        edk::animation::PathGroup::AnimationPathNames temp(name);
        //find the animationName
        this->nameSelected = (edk::animation::PathGroup::AnimationPathNames*)this->animationNames.getElement(&temp);
        if(this->nameSelected){
            //
            return true;
        }
    }
    this->nameSelected=NULL;
    //else return false
    return false;
}
//test if have the animationName
bool edk::animation::PathGroup::haveAnimationName(const edk::char8* name){
    return this->haveAnimationName((edk::char8*) name);
}
bool edk::animation::PathGroup::haveAnimationName(edk::char8* name){
    //test the name
    if(name){
        //test if have animationName
        return this->animationNames.haveName(name);
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::animation::PathGroup::playNameForward(const edk::char8* name){
    return this->playNameForward((edk::char8*) name);
}
bool edk::animation::PathGroup::playNameForward(edk::char8* name){
    //first select the name
    if(this->selectAnimationName(name)){
        this->positionStart=0u;
        //then set the animationLimits
        this->setAnimationEndSecond(this->nameSelected->end);
        this->setAnimationStartSecond(this->nameSelected->start);
        //then play the animation
        this->playForwardInPosition(this->positionStart);
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::PathGroup::playNameRewind(const edk::char8* name){
    return this->playNameRewind((edk::char8*) name);
}
bool edk::animation::PathGroup::playNameRewind(edk::char8* name){
    //first select the name
    if(this->selectAnimationName(name)){
        this->positionStart=0u;
        //then set the animationLimits
        this->setAnimationEndSecond(this->nameSelected->end);
        this->setAnimationStartSecond(this->nameSelected->start);
        //then play the animation
        this->playRewindInPosition(this->positionEnd);
        //then return true
        return true;
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::animation::PathGroup::removeAnimationName(const edk::char8* name){
    return this->removeAnimationName((edk::char8*) name);
}
bool edk::animation::PathGroup::removeAnimationName(edk::char8* name){
    //test the name
    if(name){
        //test if have a name selected
        if(this->nameSelected){
            //test if is this nameSelected
            if(edk::String::strCompare(name,this->nameSelected->getName())){
                //clean the nameSelected
                this->cleanAnimationNameSelected();
            }
        }
        //create a temp
        edk::animation::PathGroup::AnimationPathNames *get = (edk::animation::PathGroup::AnimationPathNames *)this->animationNames.getElementByName(name);
        if(get){
            //if have the elemente
            //remove
            this->animationNames.removeName(name);
            //delete
            delete get;
            //and return true
            return true;
        }
    }
    //else return false
    return false;
}
//clean animationName selected
void edk::animation::PathGroup::cleanAnimationNameSelected(){
    this->nameSelected = NULL;
}

//clean all animation Names
void edk::animation::PathGroup::cleanAnimationNames(){
    this->cleanAnimationNameSelected();
    //remove all the root's
    edk::animation::PathGroup::AnimationPathNames* temp=NULL;
    while((temp = (edk::animation::PathGroup::AnimationPathNames*)this->animationNames.getElementInPosition(0u) )){
        //remove the root
        this->animationNames.remove(temp);
        //delete temp
        delete temp;
    }
}

//print frames
void edk::animation::PathGroup::printFrames(){
    edk::uint32 size = this->animations.size();
    edk::animation::Frame* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->animations.get(i);
        if(temp){
            printf("\nSpeed %.2f"
                   ,temp->second
                   );
        }
    }
}
//return the size of frames

edk::uint32 edk::animation::PathGroup::getFramesSize(){
    return this->animations.size();
}
edk::uint32 edk::animation::PathGroup::size(){
    return this->animations.size();
}
//update the clock animation
edk::float32 edk::animation::PathGroup::updateClockAnimation(){
    return this->updateClockAnimation(this->clock.getMicroseconds()*edk::watch::microsecond);
}
edk::float32 edk::animation::PathGroup::updateClockAnimation(edk::float32 distance){
    //test if is playing
    if(this->playing){
        distance*=this->speed;
        //load the clock
        if(distance>0.f){
            this->clock.start();
        }
        edk::animation::Frame* temp = this->animations.get(this->animationPosition);

        //test if reach the frame
        if(this->reachFrame(temp)){
            //printf("\nReach");
            //then change the animation position and load the new frame

            //test if is rewind
            if(this->isRewind()){
                //rewind

                //test if reach the start
                if(this->animationPosition<=this->positionStart){
                    //test if is loopig or incrementing
                    if(this->getLoop() || this->getIncrement()){
                        //use the end position
                        this->changeFrame=true;
                        this->animationPosition=this->positionEnd;
                        this->step = temp->second;
                        temp = this->animations.get(this->animationPosition);

                        if(this->getIncrement()){
                            this->runIncrementRewind();
                        }
                    }
                    else{
                        //stop
                        this->stop();
                        return 0.f;
                    }
                }
                else{
                    //test if reach the zero position
                    if(!this->animationPosition){
                        //test if is looping
                        if(this->getLoop() || this->getIncrement()){
                            //use the end position
                            this->changeFrame=true;
                            this->animationPosition=this->positionEnd;
                            this->step = temp->second;
                            temp = this->animations.get(this->animationPosition);

                            if(this->getIncrement()){
                                this->runIncrementRewind();
                            }
                        }
                        else{
                            //else stop
                            this->stop();
                            return 0.f;
                        }
                    }
                    else{
                        //else just decrement the animationPosition
                        this->changeFrame=true;
                        this->animationPosition--;
                        this->step = temp->second;
                        temp = this->animations.get(this->animationPosition);
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
                        this->changeFrame=true;
                        this->animationPosition=this->positionStart;
                        this->step = temp->second;
                        temp = this->animations.get(this->animationPosition);

                        if(this->getIncrement()){
                            this->runIncrementForward();
                        }
                    }
                    else{
                        //stop
                        this->stop();
                        return 0.f;
                    }
                }
                else{
                    //test if reach the zero position
                    if(this->animationPosition>=this->animations.size()-1u){
                        //test if is looping
                        if(this->getLoop() || this->getIncrement()){
                            //use the start position
                            this->changeFrame=true;
                            this->animationPosition=this->positionStart;
                            this->step = temp->second;
                            temp = this->animations.get(this->animationPosition);

                            if(this->getIncrement()){
                                this->runIncrementForward();
                            }
                        }
                        else{
                            //else stop
                            this->stop();
                            return 0.f;
                        }
                    }
                    else{
                        //else just decrement the animationPosition
                        this->changeFrame=true;
                        this->animationPosition++;
                        this->step = temp->second;
                        temp = this->animations.get(this->animationPosition);
                    }
                }
            }
        }
        else{
            //update the step
            if(this->isRewind()){
                //decrement
                this->step-=distance;
                //test if it's smaller then frame second
                if(this->step < temp->second){
                    //then corret the step
                    this->step = temp->second;
                }
            }
            else{
                //increment
                this->step+=distance;
                //test if it's bigger then frame second
                if(this->step > temp->second){
                    //then corret the step
                    this->step = temp->second;
                }
            }
        }


        //step*=temp->second;

        //clock.start();

        return this->step;
    }
    return 0.f;
}

//write to XML
bool edk::animation::PathGroup::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"pathAnim_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //save the looping
                        if(this->looping){
                            xml->addSelectedNextAttribute("loop","on");
                        }
                        else{
                            xml->addSelectedNextAttribute("loop","off");
                        }
                        //save the incrementing
                        if(this->incrementing){
                            xml->addSelectedNextAttribute("increment","on");
                        }
                        else{
                            xml->addSelectedNextAttribute("increment","off");
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            this->animations.get(i)->writeToXML(xml,i);
                        }

                        //write the animationNames
                        size = this->animationNames.size();
                        edk::animation::PathGroup::AnimationPathNames *temp = NULL;
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::PathGroup::AnimationPathNames *)this->animationNames.getElementInPosition(i);
                            if(temp){
                                temp->writeToXML(xml,i);
                            }
                        }

                        //
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
bool edk::animation::PathGroup::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"pathAnim_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->deleteFrames();
                    edk::uint32 count = 0u;
                    edk::animation::Frame frameTemp;
                    //read the loop
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("loop"),(edk::char8*)"on")){
                        this->loopOn();
                    }
                    else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("loop"),(edk::char8*)"off")){
                        this->loopOff();
                    }
                    //read the increment
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("increment"),(edk::char8*)"on")){
                        this->incrementOn();
                    }
                    else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("increment"),(edk::char8*)"off")){
                        this->incrementOff();
                    }
                    //read the frames
                    while(frameTemp.readFromXML(xml,count)){
                        //add the frame to the interpolation
                        this->addNewFrame(frameTemp.second);
                        //
                        count++;
                        //clean the frame
                        frameTemp.second = 0.f;
                        //return true
                        ret=true;
                    }

                    //read the names
                    edk::animation::PathGroup::AnimationPathNames nameTemp;
                    while(nameTemp.readFromXML(xml,count)){
                        //add the animationName
                        this->addNewAnimationName(nameTemp.getName(),nameTemp.start,nameTemp.end);

                        count++;
                        //clean nameTemp
                        nameTemp.cleanName();
                        nameTemp.start = 0u;
                        nameTemp.end = 0u;
                    }

                    //
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
