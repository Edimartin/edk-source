#include "InterpolationGroup.h"

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
#warning "            Inside InterpolationGroup.cpp"
#endif

edk::animation::InterpolationGroup::InterpolationGroup(){
    this->animationSecond=0.f;
    this->tempFrame=NULL;
    this->playing=false;
    this->paused=false;
    this->looping=false;
    this->interpolationSelect=0u;
    this->interpolationStart=this->interpolationEnd=0u;
    this->frameStart=this->frameEnd=0.0f;
    this->tempInterpolation=NULL;
    this->setStart=false;
    this->rewind=false;
    this->nameSelected=NULL;
    this->callback=NULL;
    this->frameSelected=NULL;
    this->canDeleteGroup=true;
    this->setfirstInterpolation=false;
    this->speed = 1.f;
}

edk::animation::InterpolationGroup::~InterpolationGroup(){
    if(this->canDeleteGroup){
        //clean the animations
        this->cleanAnimations();
        this->deleteTempFrame();
    }
    else{
        this->animations.cantDestroy();
        this->animationNames.cantDeleteNames();
        this->cantDestruct();
    }
    this->canDeleteGroup=true;
}

//create the interpolation
edk::animation::InterpolationLine* edk::animation::InterpolationGroup::newLineInterpolation(){
    //return the interpolation
    return new edk::animation::InterpolationLine();
}
//create the frame
edk::animation::Frame* edk::animation::InterpolationGroup::newFrame(){
    //
    return new edk::animation::Frame;
}
//return the selected interpolation
edk::animation::InterpolationLine* edk::animation::InterpolationGroup::getSelectedInterpolation(){
    //test if have interpolations
    if(this->interpolationSelect<this->animations.size()){
        //return the selected interpolation
        return this->animations[this->interpolationSelect];
    }
    //else return NULL
    return NULL;
}
//print the frame
void edk::animation::InterpolationGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //test the frame
    if(interpolation){
        //
        printf("Start second %.2f end second %.2f"
               ,interpolation->getStart().second
               ,interpolation->getEnd().second
               );
    }
}

//copy interpolation frame
void edk::animation::InterpolationGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    second->setStart(first->getStart().second);
}
void edk::animation::InterpolationGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    second->setEnd(first->getEnd().second);
}

//Frame functions
//delete tempFrame
void edk::animation::InterpolationGroup::deleteTempFrame(){
    //
    if(this->tempFrame)delete this->tempFrame;
    this->tempFrame=NULL;
}
//search the beckInterpolation for the frame
edk::uint32 edk::animation::InterpolationGroup::searchBackInterpoaltion(edk::float32 second){
    //test if the seond are bigger then the frames
    for(edk::uint32 i=this->animations.size();i>0;i--){
        //test if have the frame
        if(this->animations[i-1u]){
            //then test if the second are bigger then last second
            if(second>this->animations[i-1u]->getEnd().second){
                //then return i
                return i;
            }
        }
        else{
            //move the interpolation to the end
            this->animations.bringPositionTo(i-1u,this->animations.size()-1u);
            //remove the position
            this->animations.remove(this->animations.size()-1u);
        }
        //test if the last second are smaller
    }
    //else return 0u
    return 0u;
}
//insert the frame after the position interpolation
bool edk::animation::InterpolationGroup::insertLineFrameAfter(edk::uint32 position,edk::animation::Frame frame){
    //test if the position is smallet then size
    if(position<this->animations.size()){
        //create a new interpolation 2D
        edk::animation::InterpolationLine* temp = this->newLineInterpolation();
        if(temp){
            //save the stack size
            edk::uint32 size = this->animations.size();
            //add the frame
            this->animations.pushBack(temp);

            //test if the frame are added
            if(size<this->animations.size()){
                //change the temp position on the list
                this->animations.bringPositionTo(size,position+1u);

                //set the end frame
                temp->setStart(frame.second-0.1f);
                temp->setEnd(frame.second);

                //if(this->animations[position]){
                if(this->animations.havePos(position)){
                    //
                    if(this->animations[position]->useEndInStart(temp)){
                        //the next use the frame if exist
                        if(this->animations.havePos(position+2u)){
                            temp->useEndInStart(this->animations[position+2u]);
                        }
                        //set the end
                        this->setStart=false;
                        //save the interpolation
                        this->tempInterpolation=temp;
                        //return true
                        return true;
                    }
                }
                //else bring temp to the last
                this->animations.bringPositionTo(position+1u,size);
                //else remove the temp
                this->animations.remove(size);
            }
            //else delete temp
            delete temp;
        }
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::insertLineFrameInside(edk::uint32 position,edk::animation::Frame frame){
    //test if the position is smallet then size
    if(position<this->animations.size()){
        //create a new interpolation
        edk::animation::InterpolationLine* temp = this->newLineInterpolation();
        if(temp){
            //save the stack size
            edk::uint32 size = this->animations.size();
            //add the frame
            this->animations.pushBack(temp);

            //test if the frame are added
            if(size<this->animations.size()){
                //change the temp position on the list
                this->animations.bringPositionTo(size,position+1u);

                //set the end frame
                temp->setEnd(frame.second+0.1f);
                temp->setStart(frame.second);

                if(this->animations[position]){
                    //
                    if(this->animations[position]->useEndInEnd(temp)){
                        //the next use the frame if exist
                        ///TODO: ARRUMAR O IF TESTAR SE REALMENTE PRECISA
                        //if(temp->useStartInEnd(this->animations[position]));
                        temp->useStartInEnd(this->animations[position]);
                        //set the start
                        this->setStart=true;
                        //save the interpolation
                        this->tempInterpolation=temp;
                        //return true
                        return true;
                    }
                }
                //else bring temp to the last
                this->animations.bringPositionTo(position+1u,size);
                //else remove the temp
                this->animations.remove(size);
            }
            //else delete temp
            delete temp;
        }
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::insertLineFrameFirst(edk::animation::Frame frame){
    //test if have a first frame
    if(this->animations.size()){
        //create a new interpolation
        edk::animation::InterpolationLine* temp = this->newLineInterpolation();
        if(temp){
            //save the stack size
            edk::uint32 size = this->animations.size();
            //add the frame
            this->animations.pushBack(temp);

            //test if the frame are added
            if(size<this->animations.size()){
                //change the temp position to be the first
                this->animations.bringPositionTo(size,0u);

                //set the end frame
                temp->setEnd(frame.second+0.1f);
                temp->setStart(frame.second);
                //test if have the second
                if(this->animations[1u]){
                    //
                    if(this->animations[1u]->useStartInEnd(temp)){
                        //set the start
                        this->setStart=true;
                        //save the interpolation
                        this->tempInterpolation=temp;
                        //return true
                        return true;
                    }
                }
                //else bring temp to the last
                this->animations.bringPositionTo(0u,size);
                //else remove the temp
                this->animations.remove(size);
            }
            //else delete temp
            delete temp;
        }
    }
    //else return false
    return false;
}
//select the interpolation by the second
bool edk::animation::InterpolationGroup::selectInterpolationBySecond(edk::float32 second){
    //test the animations
    if(this->animations.size()){
        //test with all interpolations
        for(edk::uint32 i=0u;i<this->animations.size();i++){
            if(second>=this->animations[i]->getStart().second && second<this->animations[i]->getEnd().second){
                //find it
                this->interpolationSelect=i;
                this->filterSelectInterpolation();
                return true;
            }
        }
    }
    this->interpolationSelect=0u;
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::selectInterpolationRewindBySecond(edk::float32 second){
    //test the animations
    if(this->animations.size()){
        //test with all interpolations
        for(edk::uint32 i=this->animations.size();i>0u;i--){
            if(second>this->animations[i-1u]->getStart().second && second<=this->animations[i-1u]->getEnd().second){
                //find it
                this->interpolationSelect=i;
                this->filterSelectInterpolation();
                return true;
            }
        }
    }
    this->interpolationSelect=0u;
    //else return false
    return false;
}
//print the selectedFrames
bool edk::animation::InterpolationGroup::printSelectedFramesFrom(edk::uint32 start,edk::uint32 end){
    //test if have frames
    if(this->animations.size()){
        //print the frames
        for(edk::uint32 i=start;i<=end;i++){
            //
            if(this->animations[i]){
                /*
                printf("\nFrame %u start %.2f end %.2f"
                    ,i
                    ,this->animations[i]->getStart().second
                    ,this->animations[i]->getEnd().second
                );
            */
                printf("\nFrame %u "
                       ,i
                       );
                this->printInterpolationLine(this->animations[i]);
            }
        }
    }
    //else return false
    return false;
}
//filter the selectInterpolation from start and end
void edk::animation::InterpolationGroup::filterSelectInterpolation(){
    edk::float32 secondTemp = 0.0f;
    //filter the selected interpolation
    if(this->interpolationSelect<this->interpolationStart){
        //
        this->interpolationSelect=this->interpolationStart;
        //filter the second
        if(this->animations.size()){
            secondTemp=this->animations[this->interpolationStart]->getStart().second;
            if(this->animationSecond<secondTemp){
                //then set the second
                this->animationSecond=secondTemp;
            }
        }
    }
    else if(this->interpolationSelect>this->interpolationEnd){
        //
        this->interpolationSelect=this->interpolationEnd;
        //filter the second
        if(this->animations.size()){
            secondTemp=this->animations[this->interpolationEnd]->getEnd().second;
            if(this->animationSecond>secondTemp){
                //then set the second
                this->animationSecond=secondTemp;
            }
        }
    }
}
void edk::animation::InterpolationGroup::updateStartFrame(){
    //
    this->frameStart=this->animations[this->interpolationStart]->getStart().second;
}
void edk::animation::InterpolationGroup::updateEndFrame(){
    //
    this->frameEnd=this->animations[this->interpolationEnd]->getEnd().second;
}
//update the start and end frames
void edk::animation::InterpolationGroup::updateStartEndFrames(){
    //set the start and end Frames
    this->updateStartFrame();this->updateEndFrame();
}
//test if the second are inside the animation
bool edk::animation::InterpolationGroup::isSecondInsideAnimation(edk::float32 second){
    //test if have the animation
    if(this->animations.size()){
        //then test the interpolations
        if(second >= this->animations[0u]->getStart().second
                &&
                second <= this->animations[this->animations.size()-1u]->getEnd().second
                ){
            //return true
            return true;
        }
    }

    //else return false
    return false;
}

//set the abstract
bool edk::animation::InterpolationGroup::setAnimationCallback(edk::animation::AnimationCallback* callback){
    //clean the callback
    this->callback=NULL;
    if(callback){
        this->callback=callback;
        //
        return true;
    }
    //else return false
    return false;
}
void edk::animation::InterpolationGroup::removeAnimationCallback(){
    this->callback=NULL;
}

//clean the animations
void edk::animation::InterpolationGroup::cleanAnimations(){
    //set stop
    this->stop();
    //clean animationNames
    this->cleanAnimationNames();
    //clean the temps
    this->tempInterpolation=NULL;
    //remove the tempFrame
    //this->deleteTempFrame();
    //
    for(edk::uint32 i=0u;i<this->animations.size();i++){
        //delete if this exist
        if(animations[i]){
            //
            delete this->animations[i];
            this->animations.set(i,NULL);
        }
    }
    //clean
    this->animations.clean();
    //clean the second
    this->animationSecond=0u;
    this->deleteTempFrame();
}

//Add a first interpolation
bool edk::animation::InterpolationGroup::addFirstInterpolationLine(edk::float32 startSecond,edk::float32 endSecond){
    //
    return this->addFirstInterpolationLine(edk::animation::Frame(startSecond),edk::animation::Frame(endSecond));
}
bool edk::animation::InterpolationGroup::addFirstInterpolationLine(edk::animation::Frame start,edk::animation::Frame end){
    //clean the list
    this->cleanAnimations();
    //add the new interpolation

    //create the interpolation
    edk::animation::InterpolationLine* temp = this->newLineInterpolation();
    if(temp){

        //add the temporary to the list
        this->animations.pushBack(temp);
        //test if add the temp
        if(this->animations.size()){
            //Add the frames
            temp->setEnd(end.second);
            temp->setStart(start.second);

            //set the animationSecond to the first second
            //this->animationSecond = start.second;

            //set the first and last interpolations
            this->setAnimationStartInterpolation(0u);
            this->setAnimationEndInterpolation(0u);

            //save the last interpolation added
            this->tempInterpolation=temp;

            //return true
            return true;
        }
        //else delete the temp
        delete temp;
    }
    //else return false
    return false;
}

//Add New Interpolation
bool edk::animation::InterpolationGroup::addNewInterpolationLine(edk::float32 second){
    //
    return this->addNewInterpolationLine(edk::animation::Frame(second));
}
bool edk::animation::InterpolationGroup::addNewInterpolationLine(edk::animation::Frame frame){
    this->setfirstInterpolation=false;
    //set stop
    this->stop();
    bool ret=false;
    //clean the interpolation
    this->tempInterpolation=NULL;
    //test if have some interpolation in the stack
    if(this->animations.size()){
        //remove the interpolationTemp
        this->deleteTempFrame();
        //then search for the back interpolation
        edk::uint32 search = this->searchBackInterpoaltion(frame.second);
        if(search>0u){
            //intert the the interpolation before the search-1 interpolation
            ret=insertLineFrameAfter(search-1u,frame);
        }
        else{
            //intert the interpolation in the first interpolation

            //test if second are bigger que first frame
            if(frame.second>this->animations[0u]->getStart().second){
                //then insert inside the first
                ret=this->insertLineFrameInside(0u,frame);
            }
            else{
                //add a new first frame
                ret=this->insertLineFrameFirst(frame);
            }
        }
    }
    else{
        //else test if have a tempFrame
        if(this->tempFrame){
            //then add the first InterpolationLine
            if(this->addFirstInterpolationLine(this->tempFrame->second,frame.second)){
                this->setfirstInterpolation=true;
                //then return true
                ret = true;
            }
            /*
            //delete the tempFrame
            delete this->tempFrame;
            this->tempFrame=NULL;
            */
        }
        else{
            //else create a new tempFrame
            this->tempFrame = this->newFrame();
            if(this->tempFrame){
                //set the second
                this->tempFrame->second=frame.second;
                //return true
                ret=true;
            }
        }
    }
    //set the end interpolation
    this->setAnimationEndInterpolation(this->animations.size()-1u);
    //else return false
    return ret;
}

//Select the frame
bool edk::animation::InterpolationGroup::selectFrame(edk::float32 second){
    //
    edk::uint32 search = this->searchBackInterpoaltion(second);
    if(this->animations.havePos(search)){
        //load the interpolation
        edk::animation::InterpolationLine* temp = this->animations[search];
        if(temp){
            //test what is the second
            if(temp->getEnd().second == second){
                //
                this->frameSelected = temp;
                this->frameSelectedStart = false;
                return true;
            }
            else if (temp->getStart().second == second){
                //
                this->frameSelected = temp;
                this->frameSelectedStart = true;
                return true;
            }
        }
    }
    this->cleanFrameSelected();
    return false;
}
//clean the selected
void edk::animation::InterpolationGroup::cleanFrameSelected(){
    this->frameSelected = NULL;
}

//test if have a tempFrame
bool edk::animation::InterpolationGroup::haveTempFrame(){
    if(this->tempFrame) return true;
    return false;
}
bool edk::animation::InterpolationGroup::selectTempFrame(edk::float32 second){
    if(this->haveTempFrame()){
        if(this->tempFrame->second == second){
            return true;
        }
    }
    return false;
}

//scale the frames
bool edk::animation::InterpolationGroup::scaleFrames(edk::float32 scale){
    //test the size
    if(scale!=0.f){
        if(this->animations.size()){
            edk::uint32 animationSize = this->animations.size();
            for(edk::uint32 i=0u;i<animationSize;i++){
                edk::animation::InterpolationLine* temp = this->animations[i];
                if(temp){
                    if(!i){
                        temp->setStartNoFilter(temp->getStart().second * scale);
                    }
                    temp->setEndNoFilter(temp->getEnd().second * scale);
                }
            }
            for(edk::uint32 i=0u;i<animationSize;i++){
                edk::animation::InterpolationLine* temp = this->animations[i];
                if(temp){
                    temp->updateDistance();
                }
            }
            //scale the animationNames
            animationSize = this->animationNames.size();
            for(edk::uint32 i=0u;i<animationSize;i++){
                edk::animation::AnimationName* temp = (edk::animation::AnimationName *)this->animationNames.getElementInPosition(i);
                if(temp){
                    temp->start*=scale;
                    temp->end*=scale;
                }
            }
            //scale the animation using
            this->frameStart*=scale;
            this->frameEnd*=scale;
            this->animationSecond*=scale;
            //then return true;
            return true;
        }
    }
    return false;
}
//Speed
void edk::animation::InterpolationGroup::setSpeed(edk::float32 speed){
    this->speed = speed;
}
edk::float32 edk::animation::InterpolationGroup::getSpeed(){
    return this->speed;
}

//set the animationStartFrame
bool edk::animation::InterpolationGroup::setAnimationStartInterpolation(edk::uint32 animationInterpolation){
    //test if animationInterpolation is valid
    if(animationInterpolation<this->animations.size()){
        //set the interpolation
        this->interpolationStart=animationInterpolation;
        //then test if the animationInterpolation are bigger then start
        if(this->interpolationStart>this->interpolationEnd){
            //set the interpolation end
            this->interpolationEnd=this->interpolationStart;
            this->updateStartEndFrames();
        }
        else{
            //else update only the start frame
            this->updateStartFrame();
        }
        //return true
        return true;
    }
    //else clean the animationInterpolations
    this->interpolationStart=this->interpolationEnd=0u;
    return false;
}
bool edk::animation::InterpolationGroup::setAnimationStartSecond(edk::float32 second){
    //test if the second are inside the animation
    if(this->isSecondInsideAnimation(second)){
        //test the second
        if(second >= this->frameEnd){
            //set the frameEnd
            this->setAnimationEndSecond(second+0.1f);
        }
        //test if the second are smaller the end
        if(second < this->frameEnd){
            //then set the frameStart
            this->frameStart=second;
            //load the frameStart interpolation
            this->interpolationStart = this->searchBackInterpoaltion(this->frameStart);
            //return true
            return true;
        }
    }
    //else return false
    return false;
}
//set the animationEndFrame
bool edk::animation::InterpolationGroup::setAnimationEndInterpolation(edk::uint32 animationInterpolation){
    //test if animationInterpolation is valid
    if(animationInterpolation<this->animations.size()){
        //set the interpolation
        this->interpolationEnd=animationInterpolation;
        //then test if the animationInterpolation are bigger then start
        if(this->interpolationEnd<this->interpolationStart){
            //set the interpolation end
            this->interpolationStart=this->interpolationEnd;
            this->updateStartEndFrames();
        }
        else{
            //else update only the end frame
            this->updateEndFrame();
        }
        //return true
        return true;
    }
    //else clean the animationInterpolations
    this->interpolationStart=this->interpolationEnd=0u;
    return false;
}
bool edk::animation::InterpolationGroup::setAnimationEndSecond(edk::float32 second){
    //test if the second are inside the animation
    if(this->isSecondInsideAnimation(second)){
        //test if the second are smaller the end
        if(second > this->frameStart){
            //then set the frameEnd
            this->frameEnd=second;
            //load the frameStart interpolation
            this->interpolationEnd = this->searchBackInterpoaltion(this->frameEnd);
            //return true
            return true;
        }
    }
    //else return false
    return false;
}

//ANIMATIONNAMES
//Add a new animationName
bool edk::animation::InterpolationGroup::addNewAnimationName(const char* name, edk::float32 start,edk::float32 end){
    //
    return this->addNewAnimationName((edk::char8*) name, start,end);
}
bool edk::animation::InterpolationGroup::addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    //test if have animations
    if(this->animations.size()){
        //test if the name exist and if the start is before the end
        if(name && start<end){
            //test if the animation dont have the name
            if(!this->animationNames.haveName(name)){
                //then he can add the animationName

                //load the start and end from the full animation
                //edk::float32 animStart = this->animations[0u]->getStart().second,animEnd = this->animations[this->animations.size()-1u]->getEnd().second;
                //test if the animation fill inside the full animation
                if(start >= this->animations[0u]->getStart().second
                        &&
                        end <= this->animations[this->animations.size()-1u]->getEnd().second
                        ){
                    edk::animation::AnimationName* temp = new edk::animation::AnimationName(name);
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
    }
    //else return false
    return false;
}
//select the animationName
bool edk::animation::InterpolationGroup::selectAnimationName(const char* name){
    //
    return this->selectAnimationName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::selectAnimationName(edk::char8* name){
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
        edk::animation::AnimationName temp(name);
        //find the animationName
        this->nameSelected = (edk::animation::AnimationName*)this->animationNames.getElement(&temp);
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
bool edk::animation::InterpolationGroup::haveAnimationName(const char* name){
    //
    return this->haveAnimationName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::haveAnimationName(edk::char8* name){
    //test the name
    if(name){
        //test if have animationName
        return this->animationNames.haveName(name);
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::animation::InterpolationGroup::playNameForward(const char* name){
    //
    return this->playNameForward((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::playNameForward(edk::char8* name){
    //first select the name
    if(this->selectAnimationName(name)){
        //then set the animationLimits
        this->setAnimationStartSecond(this->nameSelected->start);
        this->setAnimationEndSecond(this->nameSelected->end);
        //then play the animation
        this->playForwardIn(this->frameStart);
        //then return true
        return true;
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::animation::InterpolationGroup::playNameRewind(const char* name){
    //
    return this->playNameRewind((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::playNameRewind(edk::char8* name){
    //first select the name
    if(this->selectAnimationName(name)){
        //then set the animationLimits
        this->setAnimationStartSecond(this->nameSelected->start);
        this->setAnimationEndSecond(this->nameSelected->end);
        //then play the animation
        this->playRewindIn(this->frameEnd);
        //then return true
        return true;
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::animation::InterpolationGroup::removeAnimationName(const char* name){
    //
    return this->removeAnimationName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::removeAnimationName(edk::char8* name){
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
        edk::animation::AnimationName *get = (edk::animation::AnimationName *)this->animationNames.getElementByName(name);
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
//rmove a keyframe
bool edk::animation::InterpolationGroup::removeKeyFrame(edk::float32 second){
    bool ret=false;
    if(this->animations.size()){
        //search the interpolation
        edk::uint32 search = this->searchBackInterpoaltion(second);
        if(this->animations.havePos(search)){
            //load the interpolation
            edk::animation::InterpolationLine* temp = this->animations[search];
            if(temp){
                //test if the second is equal to first
                if(temp->getStart().second == second){
                    //test if have the search-1u
                    if(search){
                        //load the first
                        edk::animation::InterpolationLine* first = this->animations[search-1u];
                        if(first){
                            //send the last to the end of the stack
                            this->animations.bringPositionTo(search,this->animations.size()-1u);

                            //remove the last
                            this->animations.remove(this->animations.size()-1u);

                            //set the end of the temp
                            //first->setStart(temp->getStart().second);
                            this->copyStartToStart(temp,first);
                            //delete last
                            delete temp;
                            ret=true;
                        }
                    }
                    else{
                        //else just remove the first interpolation

                        //send the forst to the end of the stack
                        this->animations.bringPositionTo(search,this->animations.size()-1u);

                        //remove the last
                        this->animations.remove(this->animations.size()-1u);

                        delete temp;
                        ret=true;
                    }
                }
                else if(temp->getEnd().second == second){
                    //test if have the next
                    if(search+1u<this->animations.size()){
                        //load the last interpolation
                        edk::animation::InterpolationLine* last = this->animations[search+1u];
                        if(last){
                            //send the last to the end of the stack
                            this->animations.bringPositionTo(search+1u,this->animations.size()-1u);

                            //remove the last
                            this->animations.remove(this->animations.size()-1u);

                            //set the end of the temp
                            //temp->setEnd(last->getEnd().second);
                            this->copyEndToEnd(last,temp);
                            //delete last
                            delete last;
                            ret=true;
                        }
                    }
                    else{
                        //just remove the interpolation

                        //load the last
                        edk::animation::InterpolationLine* last = this->animations[this->animations.size()-1u];
                        if(last){
                            this->animations.remove(this->animations.size()-1u);
                            delete last;
                            ret=true;
                        }
                    }
                }
            }
        }
    }
    //set the end interpolation
    this->setAnimationEndInterpolation(this->animations.size()-1u);
    return ret;
}

//clean animationName selected
void edk::animation::InterpolationGroup::cleanAnimationNameSelected(){
    this->nameSelected = NULL;
}
//clean all animation Names
void edk::animation::InterpolationGroup::cleanAnimationNames(){
    this->cleanAnimationNameSelected();
    //remove all the root's
    edk::animation::AnimationName* temp=NULL;
    while((temp = (edk::animation::AnimationName*)this->animationNames.getElementInPosition(0u) )){
        //remove the root
        this->animationNames.remove(temp);
        //delete temp
        delete temp;
    }
}

//get Loop
bool edk::animation::InterpolationGroup::isLooping(){
    return looping;
}

//CONTROLS
//animation controllers
void edk::animation::InterpolationGroup::playForward(){
    //play in the time
    this->playForwardIn(this->animationSecond);
}
void edk::animation::InterpolationGroup::playForwardIn(edk::float32 second){
    this->stop();
    this->rewind=false;
    //set false for playing
    this->playing=false;
    this->paused=false;
    //test if have animation
    if(this->animations.size()){
        //then read the first and last second
        //edk::float32 firstSecond = this->animations[this->interpolationStart]->getStart().second;
        edk::float32 firstSecond = this->frameStart;
        //edk::float32 LastSecond = this->animations[this->interpolationEnd]->getEnd().second;
        edk::float32 LastSecond = this->frameEnd;
        //testa if the second is in the animation
        if(second>=firstSecond){
            if(second<=LastSecond){
                //animationSecond receive the second
                this->animationSecond=second;
            }
            else{
                //animationSecond receive the lastSecond
                this->animationSecond=LastSecond;
            }
        }
        else{
            //animationSecond receive the firstSecond
            this->animationSecond=firstSecond;
        }
        //select the interpolation
        this->selectInterpolationBySecond(this->animationSecond);
        //start the clock
        this->clock.start();
        //set true for playing
        this->playing=true;
        return;
    }
    //else stop
    this->stop();
}
void edk::animation::InterpolationGroup::playRewind(){
    //
    return playRewindIn(this->animationSecond);
}
void edk::animation::InterpolationGroup::playRewindIn(edk::float32 second){
    //set play forward
    this->playForwardIn(second);
    //select the interpolation rewind
    this->selectInterpolationRewindBySecond(second);
    //and change to rewind
    this->rewind=true;
}
void edk::animation::InterpolationGroup::pause(){
    if(!this->playing){
        this->playing=true;
    }
    this->paused = !this->paused;
}
void edk::animation::InterpolationGroup::pauseOn(){
    //test if wasn't playing
    this->clock.start();
    this->paused=true;
}
void edk::animation::InterpolationGroup::pauseOff(){
    //test if was playing
    this->clock.start();
    this->paused=false;
}
void edk::animation::InterpolationGroup::stop(){
    //start the clock
    this->clock.start();
    this->playing=false;
    this->paused=false;
    if(!this->animations.size()){
        this->animationSecond=0.0f;
    }
    else{
        this->animationSecond=this->animations[0u]->getStart().second;
    }
}
//set loop
void edk::animation::InterpolationGroup::setLoop(bool loop){
    //set the loop
    this->looping=loop;
}
void edk::animation::InterpolationGroup::loopOn(){
    //
    this->setLoop(true);
}
void edk::animation::InterpolationGroup::loopOff(){
    //
    this->setLoop(false);
}

//GETERS
//return the number of animations
edk::uint32 edk::animation::InterpolationGroup::getInterpolationSize(){
    return this->animations.size();
}
edk::uint32 edk::animation::InterpolationGroup::getInterpolations(){
    return this->animations.size();
}
//get the second
edk::float32 edk::animation::InterpolationGroup::getAnimationSecond(){
    //
    return this->animationSecond;
}
//return the missingTime
edk::float32 edk::animation::InterpolationGroup::getAnimationMissingSecond(){
    //
    if(this->rewind){
        return this->animationSecond - this->frameStart;
    }
    else{
        return this->frameEnd - this->animationSecond;
    }
    return 0.f;
}
//return if are playing
bool edk::animation::InterpolationGroup::isPlaying(){
    //
    if(this->playing && !this->paused && this->animations.size()){
        //
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::isPaused(){
    return this->paused;
}
//return true if is rewind
bool edk::animation::InterpolationGroup::isRewind(){
    return this->rewind;
}

//return the interpolation seconds
edk::float32 edk::animation::InterpolationGroup::getInterpolationStartSecond(edk::float32 position){
    if(position < this->animations.size()){
        return this->animations[position]->getStart().second;
    }
    return 0u;
}
edk::float32 edk::animation::InterpolationGroup::getInterpolationEndSecond(edk::float32 position){
    if(position < this->animations.size()){
        return this->animations[position]->getEnd().second;
    }
    return 0u;
}
//update the clock animation
edk::float32 edk::animation::InterpolationGroup::updateClockAnimation(){
    //return
    edk::float32 ret=0.0;
    //test if have animations and playing
    if(this->isPlaying()){
        //test if is playin rewind
        if(this->rewind){
            //decrement the second
            this->animationSecond-=(this->clock.getMicroseconds()*edk::watch::microsecond) * this->speed;

            //test if reach the start
            if(this->animationSecond<this->frameStart){
                //then reach the start

                //test if are looping;
                if(this->looping){
                    edk::float32 dist = this->frameEnd-frameStart;
                    while(this->animationSecond<this->frameStart){
                        //then calculate the looping
                        this->animationSecond += dist;
                    }
                    //select the first animation
                    this->selectInterpolationRewindBySecond(this->animationSecond);
                }
                else{
                    //else just set the end
                    this->animationSecond=this->frameStart;
                    //set stop
                    this->stop();
                }
                //run the callback
                if(this->callback)this->callback->animationEnd(this);
            }
            else{
                //test if back the interpolation selected
                edk::animation::InterpolationLine* temp = NULL;
                while(true){
                    temp = this->animations[this->interpolationSelect];
                    if(temp){
                        //load the start and end seconds
                        if(this->animationSecond<temp->getStart().second
                                &&
                                this->interpolationSelect>0u
                                ){
                            if(this->interpolationSelect){
                                //increment the interpolationSelected
                                this->interpolationSelect--;
                            }
                            else{
                                break;
                            }
                        }
                        else break;
                    }
                    else break;
                }
            }
        }
        else{
            //increment the second
            this->animationSecond+=(this->clock.getMicroseconds()*edk::watch::microsecond) * this->speed;


            //test if reach the end
            if(this->animationSecond>this->frameEnd){
                //then reach the end

                //test if are looping;
                if(this->looping){
                    edk::float32 dist = this->frameEnd-frameStart;
                    if(this->animationSecond>this->frameEnd){
                        //then calculate the looping
                        this->animationSecond -= dist;//+(this->animationSecond-this->frameEnd);
                    }
                    //select the first animation
                    this->selectInterpolationBySecond(this->animationSecond);
                }
                else{
                    //else just set the end
                    this->animationSecond=this->frameEnd;
                    //set stop
                    this->stop();
                }
                //run the callback
                if(this->callback)this->callback->animationEnd(this);
            }
            else{
                //test if over the interpolation selected
                edk::animation::InterpolationLine* temp = NULL;
                while(true){
                    //test if over the interpolation selected
                    temp = this->animations[this->interpolationSelect];
                    if(temp){
                        //load the start and end seconds
                        if(this->animationSecond>temp->getEnd().second){
                            //increment the interpolationSelected
                            this->interpolationSelect++;

                            if(this->interpolationSelect>this->animations.size()){
                                break;
                            }
                        }
                        else break;
                    }
                    else break;
                }
            }
        }


        //then return the second
        ret = this->animationSecond;
    }
    //set the clock start
    this->clock.start();
    //else return 0.0f
    return ret;
}
//test if have the keyframe
bool edk::animation::InterpolationGroup::haveKeyframe(edk::float32 second){
    if(this->animations.size()){
        //search the interpolation
        edk::uint32 search = this->searchBackInterpoaltion(second);
        if(this->animations.havePos(search)){
            //load the interpolation
            edk::animation::InterpolationLine* temp = this->animations[search];
            if(temp){
                //test if the second is the start
                if(temp->getStart().second == second){
                    return true;
                }
                else if(temp->getEnd().second == second){
                    //
                    return true;
                }
            }
        }
    }
    else if(this->tempFrame){
        //test the tempFrame
        if(this->tempFrame->second == second){
            return true;
        }
    }
    return false;
}

//Print the frames
bool edk::animation::InterpolationGroup::printFrames(){
    //test if have frames
    if(this->animations.size()){
        //print the frames
        return this->printSelectedFramesFrom(0,this->animations.size()-1u);
    }
    //else return false
    return false;
}
//Print the frames from start and end
bool edk::animation::InterpolationGroup::printSelectedFrames(){
    //test if have frames
    if(this->animations.size()){
        //print the frames
        return this->printSelectedFramesFrom(this->interpolationStart,this->interpolationEnd);
    }
    //else return false
    return false;
}

//cand delete
void edk::animation::InterpolationGroup::cantDeleteGroup(){
    this->canDeleteGroup=false;
}

//write to XML
bool edk::animation::InterpolationGroup::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"anim_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 count = 0u;
                        //save the looping
                        if(this->looping) xml->addSelectedNextAttribute("loop","on");
                        else              xml->addSelectedNextAttribute("loop","off");
                        //test if have the frameTemp
                        if(this->tempFrame){
                            //add the tempFrame
                            this->tempFrame->writeToXML(xml,count);
                            count++;
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            if(!i){
                                //write the first
                                this->animations[i]->writeToXMLStart(xml,count);
                                count++;
                            }
                            this->animations[i]->writeToXMLEnd(xml,count);
                            count++;
                        }
                        //write the animationNames
                        size = this->animationNames.size();
                        edk::animation::AnimationName *temp = NULL;
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::AnimationName *)this->animationNames.getElementInPosition(i);
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
bool edk::animation::InterpolationGroup::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"anim_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->cleanAnimations();
                    this->deleteTempFrame();
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
                        this->addNewInterpolationLine(frameTemp);
                        //
                        count++;
                        //clean the frame
                        frameTemp.second = 0.f;
                        //return true
                        ret=true;
                    }
                    count = 0;
                    //read the names
                    edk::animation::AnimationName nameTemp;
                    while(nameTemp.readFromXML(xml,count)){
                        //add the animationName
                        this->addNewAnimationName(nameTemp.getName(),nameTemp.start,nameTemp.end);

                        count++;
                        //clean nameTemp
                        nameTemp.setName((edk::char8*)NULL);
                        nameTemp.start = 0.f;
                        nameTemp.end = 0.f;
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
