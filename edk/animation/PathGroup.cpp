#include "PathGroup.h"

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
#warning "            Inside PathGroup.cpp"
#endif

edk::animation::PathGroup::PathGroup(){
    //
    this->animationPosition = this->positionStart = this->positionEnd = 0u;
    this->rewind = this->playing = this->looping=false;
    this->canDelete=true;
    this->lastDist=0.f;
    this->saveStep = 0.f;
    this->closerDistance=0.5f;
    this->changeFrame=false;
    this->step = 0.f;
}
edk::animation::PathGroup::~PathGroup(){
    //
    if(this->canDelete){
        this->deleteFrames();
    }
    else{
        this->animations.cantDestroy();
        this->animationNames.cantDeleteNames();
    }
    this->canDelete=true;
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
                return this->animations[this->animationPosition-1u];
            }
            else if(this->animationPosition==this->positionEnd){
                //test if is looping
                if(this->isLopping()){
                    //then get the start position
                    return this->animations[this->positionStart];
                }
            }
        }
        else{
            //test if have the last frame
            if(this->animationPosition>this->positionStart){
                //then return the last frame
                return this->animations[this->animationPosition-1u];
            }
            else if(this->animationPosition==this->positionStart){
                //test if is looping
                if(this->isLopping()){
                    //then get the start position
                    return this->animations[this->positionEnd];
                }
            }
        }
        //else return this frame
        return this->animations[this->animationPosition];
    }
    //else return this frame
    return NULL;
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
        edk::animation::Frame* temp = this->animations[position];
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
        temp = this->animations[i];
        if(temp) delete temp;
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
    }
    return false;
}
bool edk::animation::PathGroup::setAnimationEndPosition(edk::uint32 position){
    //test the position
    if(this->havePosition(position)){
        //test if is lower thn end
        if(position>this->positionStart){
            this->positionEnd = position;
            return true;
        }
    }
    return false;
}

//CONTROLS
//animation controllers
void edk::animation::PathGroup::playForward(){
    this->playForwardIn(this->animationPosition);
}
void edk::animation::PathGroup::playForwardIn(edk::uint32 position){
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
        }
    }
}
void edk::animation::PathGroup::playRewind(){
    this->playRewindIn(this->animationPosition);
}
void edk::animation::PathGroup::playRewindIn(edk::uint32 position){
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
        }
    }
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

//return if is looping
bool edk::animation::PathGroup::isLopping(){
    return this->looping;
}
bool edk::animation::PathGroup::isPlaying(){
    return this->playing;
}
bool edk::animation::PathGroup::isRewind(){
    return this->rewind;
}

//ANIMATIONNAMES
bool edk::animation::PathGroup::addNewAnimationName(const edk::char8* name, edk::uint32 start,edk::uint32 end){
    return this->addNewAnimationName((edk::char8*) name, start,end);
}
bool edk::animation::PathGroup::addNewAnimationName(edk::char8* name, edk::uint32 start,edk::uint32 end){
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
        //then set the animationLimits
        this->setAnimationStartPosition(this->nameSelected->start);
        this->setAnimationEndPosition(this->nameSelected->end);
        //then play the animation
        this->playForwardIn(this->positionStart);
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
        //then set the animationLimits
        this->setAnimationStartPosition(this->nameSelected->start);
        this->setAnimationEndPosition(this->nameSelected->end);
        //then play the animation
        this->playRewindIn(this->positionEnd);
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
        temp = this->animations[i];
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
        //load the clock
        if(distance>0.f){
            this->clock.start();
        }
        edk::animation::Frame* temp = this->animations[this->animationPosition];

        //test if reach the frame
        if(this->reachFrame(temp)){
            //printf("\nReach");
            //then change the animation position and load the new frame

            //test if is rewind
            if(this->isRewind()){
                //rewind

                //test if reach the start
                if(this->animationPosition<=this->positionStart){
                    //test if is loopig
                    if(this->isLopping()){
                        //use the end position
                        this->changeFrame=true;
                        this->animationPosition=this->positionEnd;
                        this->step = temp->second;
                        temp = this->animations[this->animationPosition];
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
                        if(this->isLopping()){
                            //use the end position
                            this->changeFrame=true;
                            this->animationPosition=this->positionEnd;
                            this->step = temp->second;
                            temp = this->animations[this->animationPosition];
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
                        temp = this->animations[this->animationPosition];
                    }
                }
            }
            else{
                //foward

                //test if reach the start
                if(this->animationPosition>=this->positionEnd){
                    //test if is loopig
                    if(this->isLopping()){
                        //use the start  position
                        this->changeFrame=true;
                        this->animationPosition=this->positionStart;
                        this->step = temp->second;
                        temp = this->animations[this->animationPosition];
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
                        if(this->isLopping()){
                            //use the start position
                            this->changeFrame=true;
                            this->animationPosition=this->positionStart;
                            this->step = temp->second;
                            temp = this->animations[this->animationPosition];
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
                        temp = this->animations[this->animationPosition];
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
                //test if it's bigget then frame second
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

//cand delete
void edk::animation::PathGroup::cantDeleteGroup(){
    this->canDelete = false;
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
                        if(this->looping) xml->addSelectedNextAttribute("loop","on");
                        else              xml->addSelectedNextAttribute("loop","off");
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            this->animations[i]->writeToXML(xml,i);
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
                delete[] name;
            }
            delete[] nameID;
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
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
