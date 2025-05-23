#include "InterpolationGroup.h"

/*
Biblioteca C++ InterpolationGroup - Manage one or more interpolations in Edk Game Engine
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
#pragma message "            Inside InterpolationGroup.cpp"
#endif

edk::animation::InterpolationGroup::InterpolationGroup(){
    this->classThis=NULL;
    this->Constructor();
}

edk::animation::InterpolationGroup::~InterpolationGroup(){
    this->Destructor();
}

void edk::animation::InterpolationGroup::Constructor(){
    edk::ObjectSmart<InterpolationGroup>::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->animations.Constructor();
        this->animationNames.Constructor();
        this->clock.Constructor();

        this->frameSelectedStart=false;
        this->animationSecond=0.f;
        this->tempFrame=NULL;
        this->playing=false;
        this->paused=false;
        this->looping=false;
        this->incrementing=false;
        this->interpolationSelect=0u;
        this->interpolationStart=this->interpolationEnd=0u;
        this->frameStart=this->frameEnd=0.0f;
        this->tempInterpolation=NULL;
        this->setStart=false;
        this->rewind=false;
        this->nameSelected=NULL;
        this->callback=NULL;
        this->frameSelected=NULL;
        this->setfirstInterpolation=false;
        this->speed = 1.f;
        this->active=false;
    }
}
void edk::animation::InterpolationGroup::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //clean the animations
        this->cleanAnimations();
        this->deleteTempFrame();

        this->animations.Destructor();
        this->animationNames.Destructor();
        this->clock.Destructor();
    }
    edk::ObjectSmart<InterpolationGroup>::Destructor();
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
        return this->animations.get(this->interpolationSelect);
    }
    //else return NULL
    return NULL;
}
//print the frame
void edk::animation::InterpolationGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //test the frame
    if(interpolation){
        //
        printf("Start second %.4f end second %.4f"
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

//increment functions to run the increment for the values
void edk::animation::InterpolationGroup::runIncrementForward(){
    //
}
void edk::animation::InterpolationGroup::runIncrementRewind(){
    //
}
void edk::animation::InterpolationGroup::cleanIncrement(){
    //
}
void edk::animation::InterpolationGroup::startIncrement(){
    //
}

//Frame functions
//delete tempFrame
void edk::animation::InterpolationGroup::deleteTempFrame(){
    //
    if(this->tempFrame){
        delete this->tempFrame;
    }
    this->tempFrame=NULL;
}
//search the beckInterpolation for the frame
edk::uint32 edk::animation::InterpolationGroup::searchBackInterpoaltionMinusOne(edk::float32 second){
    //test if is in the last interpolation
    edk::uint32 size = this->animations.size();
    if(size){
        edk::animation::InterpolationLine* temp = NULL;
        if(this->animations.havePos(size-1u)){
            temp = this->animations.get(size-1u);
            if(second > temp->getEnd().second){
                return size-1u;
            }
        }
        if(size>1u){
            //test if the second are bigger then the frames
            for(edk::uint32 i=this->animations.size();i>0;i--){
                //test if have the frame
                if(this->animations.havePos(i-1u)){
                    temp = this->animations.get(i-1u);
                    //test if the second is inside the interpolation line
                    if(second<=temp->getEnd().second && second>temp->getStart().second){
                        //then return i
                        if(i-1u){
                            return i-2u;
                        }
                        else{
                            return i-1u;
                        }
                    }
                }
                else{
                    //move the interpolation to the end
                    this->animations.bringPositionTo(i-1u,this->animations.size()-1u);
                    //remove the position
                    this->animations.remove(this->animations.size()-1u);
                }
            }
        }
    }
    //else return 0u
    return 0u;
}
edk::uint32 edk::animation::InterpolationGroup::searchBackInterpoaltion(edk::float32 second){
    //test if is in the last interpolation
    edk::uint32 size = this->animations.size();
    if(size){
        edk::animation::InterpolationLine* temp = NULL;
        if(this->animations.havePos(size-1u)){
            temp = this->animations.get(size-1u);
            if(second > temp->getEnd().second){
                return size-1u;
            }
        }
        if(size>1u){
            //test if the second are bigger then the frames
            for(edk::uint32 i=this->animations.size();i>0;i--){
                //test if have the frame
                if(this->animations.havePos(i-1u)){
                    temp = this->animations.get(i-1u);
                    //test if the second is inside the interpolation line
                    if(second<=temp->getEnd().second && second>temp->getStart().second){
                        //then return i
                        return i-1u;
                    }
                }
                else{
                    //move the interpolation to the end
                    this->animations.bringPositionTo(i-1u,this->animations.size()-1u);
                    //remove the position
                    this->animations.remove(this->animations.size()-1u);
                }
            }
        }
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
                temp->setStart(frame.second-0.0001f);
                temp->setEnd(frame.second);

                //if(this->animations[position]){
                if(this->animations.havePos(position)){
                    //
                    if(this->animations.get(position)->useEndInStart(temp)){
                        //the next use the frame if exist
                        if(this->animations.havePos(position+2u)){
                            temp->useEndInStart(this->animations.get(position+2u));
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
                temp->setEnd(frame.second+0.0001f);
                temp->setStart(frame.second);

                if(this->animations.get(position)){
                    //
                    if(this->animations.get(position)->useEndInEnd(temp)){
                        //the next use the frame if exist
                        ///TODO: ARRUMAR O IF TESTAR SE REALMENTE PRECISA
                        //if(temp->useStartInEnd(this->animations[position]));
                        temp->useStartInEnd(this->animations.get(position));
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
                if(this->animations.get(1u)){
                    //
                    if(this->animations.get(1u)->useStartInEnd(temp)){
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
    edk::uint32 size = this->animations.size();
    //test the animations
    if(size){
        edk::animation::InterpolationLine* temp = NULL;
        //test if the second is outside the start and end interpolation
        temp = this->animations.get(0u);
        if(second < temp->getStart().second){
            this->interpolationSelect=0u;
            this->filterSelectInterpolation();
            return true;
        }
        temp = this->animations.get(size-1);
        if(second >= temp->getEnd().second){
            this->interpolationSelect=size-1;
            this->filterSelectInterpolation();
            return true;
        }
        //test with all interpolations
        for(edk::uint32 i=0u;i<size;i++){
            if(second>=this->animations.get(i)->getStart().second && second<=this->animations.get(i)->getEnd().second){
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
    this->interpolationSelect = this->searchBackInterpoaltion(second);
    if(this->animations.havePos(this->interpolationSelect)){
        this->filterSelectInterpolation();
        return true;
    }
    return false;
}
//print the selectedFrames
bool edk::animation::InterpolationGroup::printSelectedFramesFrom(edk::uint32 start,edk::uint32 end){
    //test if have frames
    if(this->animations.size()){
        //print the frames
        for(edk::uint32 i=start;i<=end;i++){
            //
            if(this->animations.get(i)){
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
                this->printInterpolationLine(this->animations.get(i));
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
            secondTemp=this->animations.get(this->interpolationStart)->getStart().second;
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
            secondTemp=this->animations.get(this->interpolationEnd)->getEnd().second;
            if(this->animationSecond>secondTemp){
                //then set the second
                this->animationSecond=secondTemp;
            }
        }
    }
}
void edk::animation::InterpolationGroup::updateStartFrame(){
    //
    this->frameStart=this->animations.get(this->interpolationStart)->getStart().second;
}
void edk::animation::InterpolationGroup::updateEndFrame(){
    //
    this->frameEnd=this->animations.get(this->interpolationEnd)->getEnd().second;
}
//update the start and end frames
void edk::animation::InterpolationGroup::updateStartEndFrames(){
    //set the start and end Frames
    this->updateStartFrame(); this->updateEndFrame();
}
//test if the second are inside the animation
bool edk::animation::InterpolationGroup::isSecondInsideAnimation(edk::float32 second){
    //test if have the animation
    if(this->animations.size()){
        //then test the interpolations
        if(second >= this->animations.get(0u)->getStart().second
                &&
                second <= this->animations.get(this->animations.size()-1u)->getEnd().second
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
        if(animations.get(i)){
            //
            delete this->animations.get(i);
            this->animations.set(i,NULL);
        }
    }
    //clean
    this->animations.clean();
    //clean the second
    this->animationSecond=0.f;
    this->saveAnimationSecond = this->animationSecond;
    this->deleteTempFrame();
}
void edk::animation::InterpolationGroup::clean(){
    this->cleanAnimations();

    this->frameSelectedStart=false;
    this->tempFrame=NULL;
    this->playing=false;
    this->paused=false;
    this->looping=false;
    this->incrementing=false;
    this->interpolationSelect=0u;
    this->interpolationStart=this->interpolationEnd=0u;
    this->frameStart=this->frameEnd=0.0f;
    this->tempInterpolation=NULL;
    this->setStart=false;
    this->rewind=false;
    this->nameSelected=NULL;
    this->callback=NULL;
    this->frameSelected=NULL;
    this->setfirstInterpolation=false;
    this->speed = 1.f;
    this->active=false;
    this->clock.start();
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
        edk::uint32 search = this->searchBackInterpoaltionMinusOne(frame.second);
        if(search>0u){
            //intert the the interpolation before the search-1 interpolation
            ret=insertLineFrameAfter(search,frame);
        }
        else{
            //intert the interpolation in the first interpolation

            //test if second are bigger than the first frame
            if(frame.second>this->animations.get(0u)->getStart().second){
                //test if need insert the frame after the first frame
                if(frame.second>this->animations.get(0u)->getEnd().second){
                    ret=insertLineFrameAfter(search,frame);
                }
                else{
                    //then insert inside the first
                    ret=this->insertLineFrameInside(0u,frame);
                }
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
    edk::uint32 search = this->searchBackInterpoaltionMinusOne(second);
    if(this->animations.havePos(search)){
        //load the interpolation
        edk::animation::InterpolationLine* temp = this->animations.get(search);
        if(temp){
            //test what is the second
            if(temp->getEnd().second == second){
                //
                this->frameSelected = temp;
                this->frameSelectedStart = false;
                return true;
            }
            else if(temp->getStart().second == second){
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
    if(this->tempFrame){
        return true;
    }
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
                edk::animation::InterpolationLine* temp = this->animations.get(i);
                if(temp){
                    if(!i){
                        temp->setStartNoFilter(temp->getStart().second * scale);
                    }
                    temp->setEndNoFilter(temp->getEnd().second * scale);
                }
            }
            for(edk::uint32 i=0u;i<animationSize;i++){
                edk::animation::InterpolationLine* temp = this->animations.get(i);
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
bool edk::animation::InterpolationGroup::setSpeed(edk::float32 speed){
    if(speed>0.f){
        this->speed = speed;
        return true;
    }
    this->speed = 1.f;
    return false;
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
    //if(this->isSecondInsideAnimation(second)){
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
        this->interpolationStart = this->searchBackInterpoaltionMinusOne(this->frameStart);
        //set the animation second
        this->animationSecond = second;
        //return true
        return true;
    }
    //}
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
    //if(this->isSecondInsideAnimation(second)){
    //test if the second are smaller the end
    if(second > this->frameStart){
        //then set the frameEnd
        this->frameEnd=second;
        //load the frameStart interpolation
        this->interpolationEnd = this->searchBackInterpoaltion(this->frameEnd);
        //return true
        return true;
    }
    //}
    //else return false
    return false;
}

//ANIMATIONNAMES
//Add a new animationName
bool edk::animation::InterpolationGroup::addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
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
                if(start >= this->animations.get(0u)->getStart().second
                        &&
                        end <= this->animations.get(this->animations.size()-1u)->getEnd().second
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
//get the animationName seconds
edk::float32 edk::animation::InterpolationGroup::getAnimationNameStart(const edk::char8* name){
    //
    return this->getAnimationNameStart((edk::char8*) name);
}
edk::float32 edk::animation::InterpolationGroup::getAnimationNameStart(edk::char8* name){
    //Test the name
    if(name){
        //create a tempAnimationName
        edk::animation::AnimationName temp(name);
        edk::animation::AnimationName* animName;
        //find the animationName
        animName = (edk::animation::AnimationName*)this->animationNames.getElement(&temp);
        if(animName){
            //
            return animName->start;
        }
    }
    //else return 0.f
    return 0.f;
}
edk::float32 edk::animation::InterpolationGroup::getAnimationNameEnd(const edk::char8* name){
    return this->getAnimationNameEnd((edk::char8*) name);
}
edk::float32 edk::animation::InterpolationGroup::getAnimationNameEnd(edk::char8* name){
    //Test the name
    if(name){
        //create a tempAnimationName
        edk::animation::AnimationName temp(name);
        edk::animation::AnimationName* animName;
        //find the animationName
        animName = (edk::animation::AnimationName*)this->animationNames.getElement(&temp);
        if(animName){
            //
            return animName->end;
        }
    }
    //else return 0.f
    return 0.f;
}
//select the animationName
bool edk::animation::InterpolationGroup::selectAnimationName(const edk::char8* name){
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
bool edk::animation::InterpolationGroup::haveAnimationName(const edk::char8* name){
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
bool edk::animation::InterpolationGroup::playNameForward(const edk::char8* name){
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
        //select the name a second time because the play fowardIn clean the name selected
        this->selectAnimationName(name);
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::playNameForwardIn(const edk::char8* name,edk::float32 second){
    //
    return this->playNameForwardIn((edk::char8*) name,second);
}
bool edk::animation::InterpolationGroup::playNameForwardIn(edk::char8* name,edk::float32 second){
    //first select the name
    if(this->selectAnimationName(name)){
        if(second >= this->nameSelected->start && second <= this->nameSelected->end){
            //then set the animationLimits
            this->setAnimationStartSecond(this->nameSelected->start);
            this->setAnimationEndSecond(this->nameSelected->end);
            //then play the animation
            this->playForwardIn(second);
            //select the name a second time because the play fowardIn clean the name selected
            this->selectAnimationName(name);
            //then return true
            return true;
        }
        this->selectAnimationName((edk::char8*)NULL);
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::animation::InterpolationGroup::playNameRewind(const edk::char8* name){
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
        //select the name a second time because the play rewindIn clean the name selected
        this->selectAnimationName(name);
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::playNameRewindIn(const edk::char8* name,edk::float32 second){
    //
    return this->playNameRewindIn((edk::char8*) name,second);
}
bool edk::animation::InterpolationGroup::playNameRewindIn(edk::char8* name,edk::float32 second){
    //first select the name
    if(this->selectAnimationName(name)){
        if(second >= this->nameSelected->start && second <= this->nameSelected->end){
            //then set the animationLimits
            this->setAnimationStartSecond(this->nameSelected->start);
            this->setAnimationEndSecond(this->nameSelected->end);
            //then play the animation
            this->playRewindIn(second);
            //select the name a second time because the play rewindIn clean the name selected
            this->selectAnimationName(name);
            //then return true
            return true;
        }
        this->selectAnimationName((edk::char8*)NULL);
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::animation::InterpolationGroup::removeAnimationName(const edk::char8* name){
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
        edk::uint32 search = this->searchBackInterpoaltionMinusOne(second);
        if(this->animations.havePos(search)){
            //load the interpolation
            edk::animation::InterpolationLine* temp = this->animations.get(search);
            if(temp){
                //test if the second is equal to first
                if(temp->getStart().second == second){
                    //test if have the search-1u
                    if(search){
                        //load the first
                        edk::animation::InterpolationLine* first = this->animations.get(search-1u);
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
                        edk::animation::InterpolationLine* last = this->animations.get(search+1u);
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
                        edk::animation::InterpolationLine* last = this->animations.get(this->animations.size()-1u);
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
bool edk::animation::InterpolationGroup::getLoop(){
    return this->looping;
}
//get Increment
bool edk::animation::InterpolationGroup::getIncrement(){
    return this->incrementing;
}

//CONTROLS
//animation controllers
void edk::animation::InterpolationGroup::playForward(){
    //play in the time
    this->playForwardIn(this->animationSecond);
}
void edk::animation::InterpolationGroup::playForwardIn(edk::float32 second){
    this->stop();
    //clean the animationNameSelected
    this->cleanAnimationNameSelected();
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
        this->saveAnimationSecond = this->animationSecond;

        //test if is incrementing
        if(this->incrementing){
            //run the start incrementing
            this->startIncrement();
        }
        return;
    }
    //else stop
    this->stop();
}
void edk::animation::InterpolationGroup::restartForward(){
    this->playForwardIn(this->frameStart);
}
void edk::animation::InterpolationGroup::playRewind(){
    //
    this->playRewindIn(this->animationSecond);
}
void edk::animation::InterpolationGroup::playRewindIn(edk::float32 second){
    //set play forward
    this->playForwardIn(second);
    //select the interpolation rewind
    this->selectInterpolationRewindBySecond(second);
    //and change to rewind
    this->rewind=true;

    //test if is incrementing
    if(this->incrementing){
        //run the start incrementing
        this->startIncrement();
    }
    else{
        this->cleanIncrement();
    }
}
void edk::animation::InterpolationGroup::pause(){
    if(!this->playing){
        this->playing=true;
    }
    this->paused = !this->paused;
}
void edk::animation::InterpolationGroup::restartRewind(){
    this->playRewindIn(this->frameEnd);
}
bool edk::animation::InterpolationGroup::changeToForward(){
    //test if is playing the animation
    if(this->isPlaying()){
        //change the animation way
        this->rewind=false;
        return true;
    }
    return false;
}
bool edk::animation::InterpolationGroup::changeToRewind(){
    //test if is playing the animation
    if(this->isPlaying()){
        //change the animation way
        this->rewind=true;
        return true;
    }
    return false;
}
bool edk::animation::InterpolationGroup::changeWay(){
    //test if is playing the animation
    if(this->isPlaying()){
        //change the animation way
        this->rewind=!this->rewind;
        return true;
    }
    return false;
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
    this->cleanIncrement();
    this->clock.start();
    this->playing=false;
    this->paused=false;
    if(!this->animations.size()){
        this->animationSecond=0.0f;
    }
    else{
        this->animationSecond=this->animations.get(0u)->getStart().second;
    }
    this->saveAnimationSecond = this->animationSecond;
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
//set increment - The animation will run in looping but incrementing the values
void edk::animation::InterpolationGroup::setIncrement(bool increment){
    this->incrementing=increment;
    if(this->isPlaying() && this->incrementing){
        this->startIncrement();
    }
}
void edk::animation::InterpolationGroup::incrementOn(){
    this->setIncrement(true);
}
void edk::animation::InterpolationGroup::incrementOff(){
    this->setIncrement(false);
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
//get the animation start and end
edk::float32 edk::animation::InterpolationGroup::getAnimationStart(){
    return this->frameStart;
}
edk::float32 edk::animation::InterpolationGroup::getAnimationEnd(){
    return this->frameEnd;
}
edk::float32 edk::animation::InterpolationGroup::getAnimationLenght(){
    edk::float32 ret;
    if(this->frameEnd<0.f){
        if(this->frameStart<0.f){
            ret = this->frameEnd - this->frameStart;
        }
        else{
            ret = (this->frameEnd*-1.f) + this->frameStart;
        }
    }
    else{
        if(this->frameStart<0.f){
            ret = (this->frameStart*-1.f) + this->frameEnd;
        }
        else{
            ret = this->frameEnd - this->frameStart;
        }
    }
    if(ret<0.f){
        ret*=-1.f;
    }
    return ret;
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
bool edk::animation::InterpolationGroup::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::isPlayingName(edk::char8* name){
    if(name && this->isPlaying() && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);
    }
    return false;
}
bool edk::animation::InterpolationGroup::isPlayingFoward(){
    //
    if(this->playing && !this->paused && !this->rewind && this->animations.size()){
        //
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::isPlayingFowardName(const edk::char8* name){
    return this->isPlayingFowardName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::isPlayingFowardName(edk::char8* name){
    if(name && this->isPlaying() && !this->rewind && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);
    }
    return false;
}
bool edk::animation::InterpolationGroup::isPlayingRewind(){
    //
    if(this->playing && !this->paused && this->rewind && this->animations.size()){
        //
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::isPlayingRewindName(const edk::char8* name){
    return this->isPlayingRewindName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::isPlayingRewindName(edk::char8* name){
    if(name && this->isPlayingRewind() && this->rewind && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);
    }
    return false;
}
bool edk::animation::InterpolationGroup::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::wasPlayingName(edk::char8* name){
    if(name && !this->isPlaying() && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);
    }
    return false;
}
bool edk::animation::InterpolationGroup::wasPlayingFoward(){
    if(!this->isPlayingFoward() && !this->rewind){
        return true;
    }
    return false;
}
bool edk::animation::InterpolationGroup::wasPlayingFowardName(const edk::char8* name){
    return this->wasPlayingFowardName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::wasPlayingFowardName(edk::char8* name){
    if(name && !this->isPlayingFoward() && !this->rewind && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);
    }
    return false;
}
bool edk::animation::InterpolationGroup::wasPlayingRewind(){
    if(!this->isPlayingRewind() && this->rewind){
        return true;
    }
    return false;
}
bool edk::animation::InterpolationGroup::wasPlayingRewindName(const edk::char8* name){
    return this->wasPlayingRewindName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::wasPlayingRewindName(edk::char8* name){
    if(name && !this->isPlayingRewind() && this->rewind && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);
    }
    return false;
}
bool edk::animation::InterpolationGroup::isPaused(){
    return this->paused;
}
bool edk::animation::InterpolationGroup::isPausedName(const edk::char8* name){
    return this->isPausedName((edk::char8*) name);
}
bool edk::animation::InterpolationGroup::isPausedName(edk::char8* name){
    if(name && this->isPaused() && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);
    }
    return false;
}
//return true if is rewind
bool edk::animation::InterpolationGroup::isRewind(){
    return this->rewind;
}

//return the interpolation seconds
edk::float32 edk::animation::InterpolationGroup::getInterpolationStartSecond(edk::float32 position){
    if(position < this->animations.size()){
        return this->animations.get(position)->getStart().second;
    }
    return 0u;
}
edk::float32 edk::animation::InterpolationGroup::getInterpolationEndSecond(edk::float32 position){
    if(position < this->animations.size()){
        return this->animations.get(position)->getEnd().second;
    }
    return 0u;
}
//return an interpolation position in second
edk::uint32 edk::animation::InterpolationGroup::getInterpolationPositionInSecond(edk::float32 second){
    edk::uint32 size = this->animations.size();
    //test the animations
    if(size){
        edk::animation::InterpolationLine* temp = NULL;
        //test if the second is outside the start and end interpolation
        temp = this->animations.get(0u);
        if(second < temp->getStart().second){
            return 0u;
        }
        temp = this->animations.get(size-1);
        if(second >= temp->getEnd().second){
            return size-1;
        }
        //test with all interpolations
        for(edk::uint32 i=0u;i<size;i++){
            if(second>=this->animations.get(i)->getStart().second && second<=this->animations.get(i)->getEnd().second){
                //find it
                return i;
            }
        }
    }
    //else return false
    return size;
}
bool edk::animation::InterpolationGroup::haveInterpolationPositionInSecond(edk::float32 second){
    edk::uint32 size = this->animations.size();
    //test the animations
    if(size){
        edk::animation::InterpolationLine* temp = NULL;
        //test if the second is outside the start and end interpolation
        temp = this->animations.get(0u);
        if(second < temp->getStart().second){
            return true;
        }
        temp = this->animations.get(size-1);
        if(second >= temp->getEnd().second){
            return true;
        }
        //test with all interpolations
        for(edk::uint32 i=0u;i<size;i++){
            if(second>=this->animations.get(i)->getStart().second && second<=this->animations.get(i)->getEnd().second){
                //find it
                return true;
            }
        }
    }
    //else return false
    return false;
}
//update the clock animation
edk::float32 edk::animation::InterpolationGroup::updateClockAnimation(){
    return this->updateClockAnimation(this->clock.getMicroseconds()*edk::watch::microsecond);
}
edk::float32 edk::animation::InterpolationGroup::updateClockAnimation(edk::float32 distance){
    //return
    edk::float32 ret=0.0;
    //test if have animations and playing
    if(this->isPlaying()){
        if(distance>0.f){
            this->clock.start();
        }
        //test if is playin rewind
        if(this->rewind){
            //decrement the second
            this->animationSecond-=distance * this->speed;

            //test if reach the start
            if(this->animationSecond<this->frameStart){
                //then reach the start

                //test if are looping;
                if(this->looping || this->incrementing){
                    edk::float32 dist = this->frameEnd-frameStart;
                    while(this->animationSecond<this->frameStart){
                        //then calculate the looping
                        this->animationSecond += dist;
                    }
                    //select the first animation
                    this->selectInterpolationRewindBySecond(this->animationSecond);

                    //run the increment to notify the increment values
                    if(this->incrementing){
                        this->runIncrementRewind();
                    }
                }
                else{
                    //else just set the end
                    this->animationSecond=this->frameStart;
                    //set stop
                    this->stop();
                }
                //run the callback
                if(this->callback){
                    this->callback->animationEnd(this);
                }
            }
            else{
                //test if back the interpolation selected
                edk::animation::InterpolationLine* temp = NULL;
                while(true){
                    if(this->animations.havePos(this->interpolationSelect)){
                        temp = this->animations.get(this->interpolationSelect);
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
                            else{
                                break;
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else if(this->interpolationSelect){
                        this->interpolationSelect--;
                    }
                    else{
                        break;
                    }
                }

                while(true){
                    if(this->animations.havePos(this->interpolationSelect)){
                        //test if over the interpolation selected
                        temp = this->animations.get(this->interpolationSelect);
                        if(temp){
                            //load the start and end seconds
                            if(this->animationSecond>temp->getEnd().second){

                                if(this->animations.havePos(this->interpolationSelect +1u)){

                                    //increment the interpolationSelected
                                    this->interpolationSelect++;

                                    if(this->interpolationSelect>this->animations.size()){
                                        break;
                                    }
                                }
                                else{
                                    break;
                                }
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        else{
            //increment the second
            this->animationSecond+=distance * this->speed;

            //test if reach the end
            if(this->animationSecond>this->frameEnd){
                //then reach the end

                //test if are looping;
                if(this->looping || this->incrementing){
                    edk::float32 dist = this->frameEnd-frameStart;
                    if(this->animationSecond>this->frameEnd){
                        //then calculate the looping
                        this->animationSecond -= dist; //+(this->animationSecond-this->frameEnd);
                    }
                    //select the first animation
                    this->selectInterpolationBySecond(this->animationSecond);

                    //run the increment to notify the increment values
                    if(this->incrementing){
                        this->runIncrementForward();
                    }
                }
                else{
                    //else just set the end
                    this->animationSecond=this->frameEnd;
                    //set stop
                    this->stop();
                }
                //run the callback
                if(this->callback){
                    this->callback->animationEnd(this);
                }
            }
            else{
                //test if over the interpolation selected
                edk::animation::InterpolationLine* temp = NULL;
                while(true){
                    if(this->animations.havePos(this->interpolationSelect)){
                        //test if over the interpolation selected
                        temp = this->animations.get(this->interpolationSelect);
                        if(temp){
                            //load the start and end seconds
                            if(this->animationSecond>temp->getEnd().second){

                                if(this->animations.havePos(this->interpolationSelect +1u)){

                                    //increment the interpolationSelected
                                    this->interpolationSelect++;

                                    if(this->interpolationSelect>this->animations.size()){
                                        break;
                                    }
                                }
                                else{
                                    break;
                                }
                            }
                            else{
                                break;

                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        this->interpolationSelect--;
                        break;
                    }
                }
            }
        }

        this->saveAnimationSecond = this->animationSecond;
        //then return the second
        ret = this->animationSecond;
    }
    //else return 0.0f
    return ret;
}
//test if have the keyframe
bool edk::animation::InterpolationGroup::haveKeyframe(edk::float32 second){
    if(this->animations.size()){
        //search the interpolation
        edk::uint32 search = this->searchBackInterpoaltionMinusOne(second);
        if(this->animations.havePos(search)){
            //load the interpolation
            edk::animation::InterpolationLine* temp = this->animations.get(search);
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
                        if(this->getLoop()){
                            xml->addSelectedNextAttribute("loop","on");
                        }
                        else{
                            xml->addSelectedNextAttribute("loop","off");
                        }
                        //save the incrementing
                        if(this->getIncrement()){
                            xml->addSelectedNextAttribute("increment","on");
                        }
                        else{
                            xml->addSelectedNextAttribute("increment","off");
                        }
                        //test if have the frameTemp
                        if(this->tempFrame){
                            //add the tempFrame
                            this->tempFrame->writeToXML(xml,count);
                            count++;
                        }
                        edk::uint32 size = 0u;

                        //write the animationFrames
                        size = this->animations.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            if(!i){
                                //write the first
                                this->animations.get(i)->writeToXMLStart(xml,count);
                                count++;
                            }
                            this->animations.get(i)->writeToXMLEnd(xml,count);
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
                free(name);
            }
            free(nameID);
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
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
