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
#warning "            Inside InterpolationGroup.cpp"
#endif

edk::animation::InterpolationGroup::InterpolationGroup(){
    this->frameSelectedStart=false;edkEnd();
    this->animationSecond=0.f;edkEnd();
    this->tempFrame=NULL;edkEnd();
    this->playing=false;edkEnd();
    this->paused=false;edkEnd();
    this->looping=false;edkEnd();
    this->incrementing=false;edkEnd();
    this->interpolationSelect=0u;
    this->interpolationStart=this->interpolationEnd=0u;
    this->frameStart=this->frameEnd=0.0f;edkEnd();
    this->tempInterpolation=NULL;edkEnd();
    this->setStart=false;edkEnd();
    this->rewind=false;edkEnd();
    this->nameSelected=NULL;edkEnd();
    this->callback=NULL;edkEnd();
    this->frameSelected=NULL;edkEnd();
    this->canDeleteGroup=true;edkEnd();
    this->setfirstInterpolation=false;edkEnd();
    this->speed = 1.f;edkEnd();
    this->active=false;edkEnd();
}

edk::animation::InterpolationGroup::~InterpolationGroup(){
    if(this->canDeleteGroup){
        //clean the animations
        this->cleanAnimations();edkEnd();
        this->deleteTempFrame();edkEnd();
    }
    else{
        this->animations.cantDestroy();edkEnd();
        this->animationNames.cantDeleteNames();edkEnd();
        this->cantDestruct();edkEnd();
    }
    this->canDeleteGroup=true;edkEnd();
}

//create the interpolation
edk::animation::InterpolationLine* edk::animation::InterpolationGroup::newLineInterpolation(){
    //return the interpolation
    return new edk::animation::InterpolationLine();edkEnd();
}
//create the frame
edk::animation::Frame* edk::animation::InterpolationGroup::newFrame(){
    //
    return new edk::animation::Frame;edkEnd();
}
//return the selected interpolation
edk::animation::InterpolationLine* edk::animation::InterpolationGroup::getSelectedInterpolation(){
    //test if have interpolations
    if(this->interpolationSelect<this->animations.size()){
        //return the selected interpolation
        return this->animations[this->interpolationSelect];edkEnd();
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
               );edkEnd();
    }
}

//copy interpolation frame
void edk::animation::InterpolationGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    second->setStart(first->getStart().second);edkEnd();
}
void edk::animation::InterpolationGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    second->setEnd(first->getEnd().second);edkEnd();
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
        delete this->tempFrame;edkEnd();
    }
    this->tempFrame=NULL;edkEnd();
}
//search the beckInterpolation for the frame
edk::uint32 edk::animation::InterpolationGroup::searchBackInterpoaltionMinusOne(edk::float32 second){
    //test if is in the last interpolation
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::InterpolationLine* temp = NULL;edkEnd();
        if(this->animations.havePos(size-1u)){
            temp = this->animations[size-1u];edkEnd();
            if(second > temp->getEnd().second){
                return size-1u;edkEnd();
            }
        }
        if(size>1u){
            //test if the second are bigger then the frames
            for(edk::uint32 i=this->animations.size();i>0;i--){
                //test if have the frame
                if(this->animations.havePos(i-1u)){
                    temp = this->animations[i-1u];edkEnd();
                    //test if the second is inside the interpolation line
                    if(second<=temp->getEnd().second && second>temp->getStart().second){
                        //then return i
                        if(i-1u){
                            return i-2u;edkEnd();
                        }
                        else{
                            return i-1u;edkEnd();
                        }
                    }
                }
                else{
                    //move the interpolation to the end
                    this->animations.bringPositionTo(i-1u,this->animations.size()-1u);edkEnd();
                    //remove the position
                    this->animations.remove(this->animations.size()-1u);edkEnd();
                }
            }
        }
    }
    //else return 0u
    return 0u;edkEnd();
}
edk::uint32 edk::animation::InterpolationGroup::searchBackInterpoaltion(edk::float32 second){
    //test if is in the last interpolation
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::InterpolationLine* temp = NULL;edkEnd();
        if(this->animations.havePos(size-1u)){
            temp = this->animations[size-1u];edkEnd();
            if(second > temp->getEnd().second){
                return size-1u;edkEnd();
            }
        }
        if(size>1u){
            //test if the second are bigger then the frames
            for(edk::uint32 i=this->animations.size();i>0;i--){
                //test if have the frame
                if(this->animations.havePos(i-1u)){
                    temp = this->animations[i-1u];edkEnd();
                    //test if the second is inside the interpolation line
                    if(second<=temp->getEnd().second && second>temp->getStart().second){
                        //then return i
                        return i-1u;edkEnd();
                    }
                }
                else{
                    //move the interpolation to the end
                    this->animations.bringPositionTo(i-1u,this->animations.size()-1u);edkEnd();
                    //remove the position
                    this->animations.remove(this->animations.size()-1u);edkEnd();
                }
            }
        }
    }
    //else return 0u
    return 0u;edkEnd();
}
//insert the frame after the position interpolation
bool edk::animation::InterpolationGroup::insertLineFrameAfter(edk::uint32 position,edk::animation::Frame frame){
    //test if the position is smallet then size
    if(position<this->animations.size()){
        //create a new interpolation 2D
        edk::animation::InterpolationLine* temp = this->newLineInterpolation();edkEnd();
        if(temp){
            //save the stack size
            edk::uint32 size = this->animations.size();edkEnd();
            //add the frame
            this->animations.pushBack(temp);edkEnd();

            //test if the frame are added
            if(size<this->animations.size()){
                //change the temp position on the list
                this->animations.bringPositionTo(size,position+1u);edkEnd();

                //set the end frame
                temp->setStart(frame.second-0.0001f);edkEnd();
                temp->setEnd(frame.second);edkEnd();

                //if(this->animations[position]){
                if(this->animations.havePos(position)){
                    //
                    if(this->animations[position]->useEndInStart(temp)){
                        //the next use the frame if exist
                        if(this->animations.havePos(position+2u)){
                            temp->useEndInStart(this->animations[position+2u]);edkEnd();
                        }
                        //set the end
                        this->setStart=false;edkEnd();
                        //save the interpolation
                        this->tempInterpolation=temp;edkEnd();
                        //return true
                        return true;
                    }
                }
                //else bring temp to the last
                this->animations.bringPositionTo(position+1u,size);edkEnd();
                //else remove the temp
                this->animations.remove(size);edkEnd();
            }
            //else delete temp
            delete temp;edkEnd();
        }
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::insertLineFrameInside(edk::uint32 position,edk::animation::Frame frame){
    //test if the position is smallet then size
    if(position<this->animations.size()){
        //create a new interpolation
        edk::animation::InterpolationLine* temp = this->newLineInterpolation();edkEnd();
        if(temp){
            //save the stack size
            edk::uint32 size = this->animations.size();edkEnd();
            //add the frame
            this->animations.pushBack(temp);edkEnd();

            //test if the frame are added
            if(size<this->animations.size()){
                //change the temp position on the list
                this->animations.bringPositionTo(size,position+1u);edkEnd();

                //set the end frame
                temp->setEnd(frame.second+0.0001f);edkEnd();
                temp->setStart(frame.second);edkEnd();

                if(this->animations[position]){
                    //
                    if(this->animations[position]->useEndInEnd(temp)){
                        //the next use the frame if exist
                        ///TODO: ARRUMAR O IF TESTAR SE REALMENTE PRECISA
                        //if(temp->useStartInEnd(this->animations[position]));edkEnd();
                        temp->useStartInEnd(this->animations[position]);edkEnd();
                        //set the start
                        this->setStart=true;edkEnd();
                        //save the interpolation
                        this->tempInterpolation=temp;edkEnd();
                        //return true
                        return true;
                    }
                }
                //else bring temp to the last
                this->animations.bringPositionTo(position+1u,size);edkEnd();
                //else remove the temp
                this->animations.remove(size);edkEnd();
            }
            //else delete temp
            delete temp;edkEnd();
        }
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::insertLineFrameFirst(edk::animation::Frame frame){
    //test if have a first frame
    if(this->animations.size()){
        //create a new interpolation
        edk::animation::InterpolationLine* temp = this->newLineInterpolation();edkEnd();
        if(temp){
            //save the stack size
            edk::uint32 size = this->animations.size();edkEnd();
            //add the frame
            this->animations.pushBack(temp);edkEnd();

            //test if the frame are added
            if(size<this->animations.size()){
                //change the temp position to be the first
                this->animations.bringPositionTo(size,0u);edkEnd();

                //set the end frame
                temp->setEnd(frame.second+0.1f);edkEnd();
                temp->setStart(frame.second);edkEnd();
                //test if have the second
                if(this->animations[1u]){
                    //
                    if(this->animations[1u]->useStartInEnd(temp)){
                        //set the start
                        this->setStart=true;edkEnd();
                        //save the interpolation
                        this->tempInterpolation=temp;edkEnd();
                        //return true
                        return true;
                    }
                }
                //else bring temp to the last
                this->animations.bringPositionTo(0u,size);edkEnd();
                //else remove the temp
                this->animations.remove(size);edkEnd();
            }
            //else delete temp
            delete temp;edkEnd();
        }
    }
    //else return false
    return false;
}
//select the interpolation by the second
bool edk::animation::InterpolationGroup::selectInterpolationBySecond(edk::float32 second){
    edk::uint32 size = this->animations.size();edkEnd();
    //test the animations
    if(size){
        edk::animation::InterpolationLine* temp = NULL;edkEnd();
        //test if the second is outside the start and end interpolation
        temp = this->animations[0u];edkEnd();
        if(second < temp->getStart().second){
            this->interpolationSelect=0u;
            this->filterSelectInterpolation();edkEnd();
            return true;
        }
        temp = this->animations[size-1];edkEnd();
        if(second >= temp->getEnd().second){
            this->interpolationSelect=size-1;edkEnd();
            this->filterSelectInterpolation();edkEnd();
            return true;
        }
        //test with all interpolations
        for(edk::uint32 i=0u;i<size;i++){
            if(second>=this->animations[i]->getStart().second && second<=this->animations[i]->getEnd().second){
                //find it
                this->interpolationSelect=i;edkEnd();
                this->filterSelectInterpolation();edkEnd();
                return true;
            }
        }
    }
    this->interpolationSelect=0u;
    //else return false
    return false;
}
bool edk::animation::InterpolationGroup::selectInterpolationRewindBySecond(edk::float32 second){
    this->interpolationSelect = this->searchBackInterpoaltion(second);edkEnd();
    if(this->animations.havePos(this->interpolationSelect)){
        this->filterSelectInterpolation();edkEnd();
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
            if(this->animations[i]){
                /*
                printf("\nFrame %u start %.2f end %.2f"
                    ,i
                    ,this->animations[i]->getStart().second
                    ,this->animations[i]->getEnd().second
                );edkEnd();
            */
                printf("\nFrame %u "
                       ,i
                       );edkEnd();
                this->printInterpolationLine(this->animations[i]);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//filter the selectInterpolation from start and end
void edk::animation::InterpolationGroup::filterSelectInterpolation(){
    edk::float32 secondTemp = 0.0f;edkEnd();
    //filter the selected interpolation
    if(this->interpolationSelect<this->interpolationStart){
        //
        this->interpolationSelect=this->interpolationStart;edkEnd();
        //filter the second
        if(this->animations.size()){
            secondTemp=this->animations[this->interpolationStart]->getStart().second;edkEnd();
            if(this->animationSecond<secondTemp){
                //then set the second
                this->animationSecond=secondTemp;edkEnd();
            }
        }
    }
    else if(this->interpolationSelect>this->interpolationEnd){
        //
        this->interpolationSelect=this->interpolationEnd;edkEnd();
        //filter the second
        if(this->animations.size()){
            secondTemp=this->animations[this->interpolationEnd]->getEnd().second;edkEnd();
            if(this->animationSecond>secondTemp){
                //then set the second
                this->animationSecond=secondTemp;edkEnd();
            }
        }
    }
}
void edk::animation::InterpolationGroup::updateStartFrame(){
    //
    this->frameStart=this->animations[this->interpolationStart]->getStart().second;edkEnd();
}
void edk::animation::InterpolationGroup::updateEndFrame(){
    //
    this->frameEnd=this->animations[this->interpolationEnd]->getEnd().second;edkEnd();
}
//update the start and end frames
void edk::animation::InterpolationGroup::updateStartEndFrames(){
    //set the start and end Frames
    this->updateStartFrame();edkEnd();this->updateEndFrame();edkEnd();
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
    this->callback=NULL;edkEnd();
    if(callback){
        this->callback=callback;edkEnd();
        //
        return true;
    }
    //else return false
    return false;
}
void edk::animation::InterpolationGroup::removeAnimationCallback(){
    this->callback=NULL;edkEnd();
}

//clean the animations
void edk::animation::InterpolationGroup::cleanAnimations(){
    //set stop
    this->stop();edkEnd();
    //clean animationNames
    this->cleanAnimationNames();edkEnd();
    //clean the temps
    this->tempInterpolation=NULL;edkEnd();
    //remove the tempFrame
    //this->deleteTempFrame();edkEnd();
    //
    for(edk::uint32 i=0u;i<this->animations.size();i++){
        //delete if this exist
        if(animations[i]){
            //
            delete this->animations[i];edkEnd();
            this->animations.set(i,NULL);edkEnd();
        }
    }
    //clean
    this->animations.clean();edkEnd();
    //clean the second
    this->animationSecond=0.f;edkEnd();
    this->saveAnimationSecond = this->animationSecond;edkEnd();
    this->deleteTempFrame();edkEnd();
}
void edk::animation::InterpolationGroup::clean(){
    this->cleanAnimations();edkEnd();

    this->frameSelectedStart=false;edkEnd();
    this->tempFrame=NULL;edkEnd();
    this->playing=false;edkEnd();
    this->paused=false;edkEnd();
    this->looping=false;edkEnd();
    this->incrementing=false;edkEnd();
    this->interpolationSelect=0u;
    this->interpolationStart=this->interpolationEnd=0u;
    this->frameStart=this->frameEnd=0.0f;edkEnd();
    this->tempInterpolation=NULL;edkEnd();
    this->setStart=false;edkEnd();
    this->rewind=false;edkEnd();
    this->nameSelected=NULL;edkEnd();
    this->callback=NULL;edkEnd();
    this->frameSelected=NULL;edkEnd();
    this->canDeleteGroup=true;edkEnd();
    this->setfirstInterpolation=false;edkEnd();
    this->speed = 1.f;edkEnd();
    this->active=false;edkEnd();
    this->clock.start();edkEnd();
}

//Add a first interpolation
bool edk::animation::InterpolationGroup::addFirstInterpolationLine(edk::float32 startSecond,edk::float32 endSecond){
    //
    return this->addFirstInterpolationLine(edk::animation::Frame(startSecond),edk::animation::Frame(endSecond));edkEnd();
}
bool edk::animation::InterpolationGroup::addFirstInterpolationLine(edk::animation::Frame start,edk::animation::Frame end){
    //clean the list
    this->cleanAnimations();edkEnd();
    //add the new interpolation

    //create the interpolation
    edk::animation::InterpolationLine* temp = this->newLineInterpolation();edkEnd();
    if(temp){

        //add the temporary to the list
        this->animations.pushBack(temp);edkEnd();
        //test if add the temp
        if(this->animations.size()){
            //Add the frames
            temp->setEnd(end.second);edkEnd();
            temp->setStart(start.second);edkEnd();

            //set the animationSecond to the first second
            //this->animationSecond = start.second;edkEnd();

            //set the first and last interpolations
            this->setAnimationStartInterpolation(0u);edkEnd();
            this->setAnimationEndInterpolation(0u);edkEnd();

            //save the last interpolation added
            this->tempInterpolation=temp;edkEnd();

            //return true
            return true;
        }
        //else delete the temp
        delete temp;edkEnd();
    }
    //else return false
    return false;
}

//Add New Interpolation
bool edk::animation::InterpolationGroup::addNewInterpolationLine(edk::float32 second){
    //
    return this->addNewInterpolationLine(edk::animation::Frame(second));edkEnd();
}
bool edk::animation::InterpolationGroup::addNewInterpolationLine(edk::animation::Frame frame){
    this->setfirstInterpolation=false;edkEnd();
    //set stop
    this->stop();edkEnd();
    bool ret=false;edkEnd();
    //clean the interpolation
    this->tempInterpolation=NULL;edkEnd();
    //test if have some interpolation in the stack
    if(this->animations.size()){
        //remove the interpolationTemp
        this->deleteTempFrame();edkEnd();
        //then search for the back interpolation
        edk::uint32 search = this->searchBackInterpoaltionMinusOne(frame.second);edkEnd();
        if(search>0u){
            //intert the the interpolation before the search-1 interpolation
            ret=insertLineFrameAfter(search,frame);edkEnd();
        }
        else{
            //intert the interpolation in the first interpolation

            //test if second are bigger than the first frame
            if(frame.second>this->animations[0u]->getStart().second){
                //test if need insert the frame after the first frame
                if(frame.second>this->animations[0u]->getEnd().second){
                    ret=insertLineFrameAfter(search,frame);edkEnd();
                }
                else{
                    //then insert inside the first
                    ret=this->insertLineFrameInside(0u,frame);edkEnd();
                }
            }
            else{
                //add a new first frame
                ret=this->insertLineFrameFirst(frame);edkEnd();
            }
        }
    }
    else{
        //else test if have a tempFrame
        if(this->tempFrame){
            //then add the first InterpolationLine
            if(this->addFirstInterpolationLine(this->tempFrame->second,frame.second)){
                this->setfirstInterpolation=true;edkEnd();
                //then return true
                ret = true;edkEnd();
            }
        }
        else{
            //else create a new tempFrame
            this->tempFrame = this->newFrame();edkEnd();
            if(this->tempFrame){
                //set the second
                this->tempFrame->second=frame.second;edkEnd();
                //return true
                ret=true;edkEnd();
            }
        }
    }
    //set the end interpolation
    this->setAnimationEndInterpolation(this->animations.size()-1u);edkEnd();
    //else return false
    return ret;
}

//Select the frame
bool edk::animation::InterpolationGroup::selectFrame(edk::float32 second){
    //
    edk::uint32 search = this->searchBackInterpoaltionMinusOne(second);edkEnd();
    if(this->animations.havePos(search)){
        //load the interpolation
        edk::animation::InterpolationLine* temp = this->animations[search];edkEnd();
        if(temp){
            //test what is the second
            if(temp->getEnd().second == second){
                //
                this->frameSelected = temp;edkEnd();
                this->frameSelectedStart = false;edkEnd();
                return true;
            }
            else if(temp->getStart().second == second){
                //
                this->frameSelected = temp;edkEnd();
                this->frameSelectedStart = true;edkEnd();
                return true;
            }
        }
    }
    this->cleanFrameSelected();edkEnd();
    return false;
}
//clean the selected
void edk::animation::InterpolationGroup::cleanFrameSelected(){
    this->frameSelected = NULL;edkEnd();
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
            edk::uint32 animationSize = this->animations.size();edkEnd();
            for(edk::uint32 i=0u;i<animationSize;i++){
                edk::animation::InterpolationLine* temp = this->animations[i];edkEnd();
                if(temp){
                    if(!i){
                        temp->setStartNoFilter(temp->getStart().second * scale);edkEnd();
                    }
                    temp->setEndNoFilter(temp->getEnd().second * scale);edkEnd();
                }
            }
            for(edk::uint32 i=0u;i<animationSize;i++){
                edk::animation::InterpolationLine* temp = this->animations[i];edkEnd();
                if(temp){
                    temp->updateDistance();edkEnd();
                }
            }
            //scale the animationNames
            animationSize = this->animationNames.size();edkEnd();
            for(edk::uint32 i=0u;i<animationSize;i++){
                edk::animation::AnimationName* temp = (edk::animation::AnimationName *)this->animationNames.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->start*=scale;edkEnd();
                    temp->end*=scale;edkEnd();
                }
            }
            //scale the animation using
            this->frameStart*=scale;edkEnd();
            this->frameEnd*=scale;edkEnd();
            this->animationSecond*=scale;edkEnd();
            //then return true;
            return true;
        }
    }
    return false;
}
//Speed
bool edk::animation::InterpolationGroup::setSpeed(edk::float32 speed){
    if(speed>0.f){
        this->speed = speed;edkEnd();
        return true;
    }
    this->speed = 1.f;edkEnd();
    return false;
}
edk::float32 edk::animation::InterpolationGroup::getSpeed(){
    return this->speed;edkEnd();
}

//set the animationStartFrame
bool edk::animation::InterpolationGroup::setAnimationStartInterpolation(edk::uint32 animationInterpolation){
    //test if animationInterpolation is valid
    if(animationInterpolation<this->animations.size()){
        //set the interpolation
        this->interpolationStart=animationInterpolation;edkEnd();
        //then test if the animationInterpolation are bigger then start
        if(this->interpolationStart>this->interpolationEnd){
            //set the interpolation end
            this->interpolationEnd=this->interpolationStart;edkEnd();
            this->updateStartEndFrames();edkEnd();
        }
        else{
            //else update only the start frame
            this->updateStartFrame();edkEnd();
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
        this->setAnimationEndSecond(second+0.1f);edkEnd();
    }
    //test if the second are smaller the end
    if(second < this->frameEnd){
        //then set the frameStart
        this->frameStart=second;edkEnd();
        //load the frameStart interpolation
        this->interpolationStart = this->searchBackInterpoaltionMinusOne(this->frameStart);edkEnd();
        //set the animation second
        this->animationSecond = second;edkEnd();
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
        this->interpolationEnd=animationInterpolation;edkEnd();
        //then test if the animationInterpolation are bigger then start
        if(this->interpolationEnd<this->interpolationStart){
            //set the interpolation end
            this->interpolationStart=this->interpolationEnd;edkEnd();
            this->updateStartEndFrames();edkEnd();
        }
        else{
            //else update only the end frame
            this->updateEndFrame();edkEnd();
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
        this->frameEnd=second;edkEnd();
        //load the frameStart interpolation
        this->interpolationEnd = this->searchBackInterpoaltion(this->frameEnd);edkEnd();
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
    return this->addNewAnimationName((edk::char8*) name, start,end);edkEnd();
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
                //edk::float32 animStart = this->animations[0u]->getStart().second,animEnd = this->animations[this->animations.size()-1u]->getEnd().second;edkEnd();
                //test if the animation fill inside the full animation
                if(start >= this->animations[0u]->getStart().second
                        &&
                        end <= this->animations[this->animations.size()-1u]->getEnd().second
                        ){
                    edk::animation::AnimationName* temp = new edk::animation::AnimationName(name);edkEnd();
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
    }
    //else return false
    return false;
}
//get the animationName seconds
edk::float32 edk::animation::InterpolationGroup::getAnimationNameStart(const edk::char8* name){
    //
    return this->getAnimationNameStart((edk::char8*) name);edkEnd();
}
edk::float32 edk::animation::InterpolationGroup::getAnimationNameStart(edk::char8* name){
    //Test the name
    if(name){
        //create a tempAnimationName
        edk::animation::AnimationName temp(name);edkEnd();
        edk::animation::AnimationName* animName;edkEnd();
        //find the animationName
        animName = (edk::animation::AnimationName*)this->animationNames.getElement(&temp);edkEnd();
        if(animName){
            //
            return animName->start;edkEnd();
        }
    }
    //else return 0.f
    return 0.f;
}
edk::float32 edk::animation::InterpolationGroup::getAnimationNameEnd(const edk::char8* name){
    return this->getAnimationNameEnd((edk::char8*) name);edkEnd();
}
edk::float32 edk::animation::InterpolationGroup::getAnimationNameEnd(edk::char8* name){
    //Test the name
    if(name){
        //create a tempAnimationName
        edk::animation::AnimationName temp(name);edkEnd();
        edk::animation::AnimationName* animName;edkEnd();
        //find the animationName
        animName = (edk::animation::AnimationName*)this->animationNames.getElement(&temp);edkEnd();
        if(animName){
            //
            return animName->end;edkEnd();
        }
    }
    //else return 0.f
    return 0.f;
}
//select the animationName
bool edk::animation::InterpolationGroup::selectAnimationName(const edk::char8* name){
    //
    return this->selectAnimationName((edk::char8*) name);edkEnd();
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
        edk::animation::AnimationName temp(name);edkEnd();
        //find the animationName
        this->nameSelected = (edk::animation::AnimationName*)this->animationNames.getElement(&temp);edkEnd();
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
bool edk::animation::InterpolationGroup::haveAnimationName(const edk::char8* name){
    //
    return this->haveAnimationName((edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationGroup::haveAnimationName(edk::char8* name){
    //test the name
    if(name){
        //test if have animationName
        return this->animationNames.haveName(name);edkEnd();
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::animation::InterpolationGroup::playNameForward(const edk::char8* name){
    //
    return this->playNameForward((edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationGroup::playNameForward(edk::char8* name){
    //first select the name
    if(this->selectAnimationName(name)){
        //then set the animationLimits
        this->setAnimationStartSecond(this->nameSelected->start);edkEnd();
        this->setAnimationEndSecond(this->nameSelected->end);edkEnd();
        //then play the animation
        this->playForwardIn(this->frameStart);edkEnd();
        //select the name a second time because the play fowardIn clean the name selected
        this->selectAnimationName(name);
        //then return true
        return true;
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::animation::InterpolationGroup::playNameRewind(const edk::char8* name){
    //
    return this->playNameRewind((edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationGroup::playNameRewind(edk::char8* name){
    //first select the name
    if(this->selectAnimationName(name)){
        //then set the animationLimits
        this->setAnimationStartSecond(this->nameSelected->start);edkEnd();
        this->setAnimationEndSecond(this->nameSelected->end);edkEnd();
        //then play the animation
        this->playRewindIn(this->frameEnd);edkEnd();
        //select the name a second time because the play rewindIn clean the name selected
        this->selectAnimationName(name);
        //then return true
        return true;
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::animation::InterpolationGroup::removeAnimationName(const edk::char8* name){
    //
    return this->removeAnimationName((edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationGroup::removeAnimationName(edk::char8* name){
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
        edk::animation::AnimationName *get = (edk::animation::AnimationName *)this->animationNames.getElementByName(name);edkEnd();
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
//rmove a keyframe
bool edk::animation::InterpolationGroup::removeKeyFrame(edk::float32 second){
    bool ret=false;edkEnd();
    if(this->animations.size()){
        //search the interpolation
        edk::uint32 search = this->searchBackInterpoaltionMinusOne(second);edkEnd();
        if(this->animations.havePos(search)){
            //load the interpolation
            edk::animation::InterpolationLine* temp = this->animations[search];edkEnd();
            if(temp){
                //test if the second is equal to first
                if(temp->getStart().second == second){
                    //test if have the search-1u
                    if(search){
                        //load the first
                        edk::animation::InterpolationLine* first = this->animations[search-1u];edkEnd();
                        if(first){
                            //send the last to the end of the stack
                            this->animations.bringPositionTo(search,this->animations.size()-1u);edkEnd();

                            //remove the last
                            this->animations.remove(this->animations.size()-1u);edkEnd();

                            //set the end of the temp
                            //first->setStart(temp->getStart().second);edkEnd();
                            this->copyStartToStart(temp,first);edkEnd();
                            //delete last
                            delete temp;edkEnd();
                            ret=true;edkEnd();
                        }
                    }
                    else{
                        //else just remove the first interpolation

                        //send the forst to the end of the stack
                        this->animations.bringPositionTo(search,this->animations.size()-1u);edkEnd();

                        //remove the last
                        this->animations.remove(this->animations.size()-1u);edkEnd();

                        delete temp;edkEnd();
                        ret=true;edkEnd();
                    }
                }
                else if(temp->getEnd().second == second){
                    //test if have the next
                    if(search+1u<this->animations.size()){
                        //load the last interpolation
                        edk::animation::InterpolationLine* last = this->animations[search+1u];edkEnd();
                        if(last){
                            //send the last to the end of the stack
                            this->animations.bringPositionTo(search+1u,this->animations.size()-1u);edkEnd();

                            //remove the last
                            this->animations.remove(this->animations.size()-1u);edkEnd();

                            //set the end of the temp
                            //temp->setEnd(last->getEnd().second);edkEnd();
                            this->copyEndToEnd(last,temp);edkEnd();
                            //delete last
                            delete last;edkEnd();
                            ret=true;edkEnd();
                        }
                    }
                    else{
                        //just remove the interpolation

                        //load the last
                        edk::animation::InterpolationLine* last = this->animations[this->animations.size()-1u];edkEnd();
                        if(last){
                            this->animations.remove(this->animations.size()-1u);edkEnd();
                            delete last;edkEnd();
                            ret=true;edkEnd();
                        }
                    }
                }
            }
        }
    }
    //set the end interpolation
    this->setAnimationEndInterpolation(this->animations.size()-1u);edkEnd();
    return ret;
}

//clean animationName selected
void edk::animation::InterpolationGroup::cleanAnimationNameSelected(){
    this->nameSelected = NULL;edkEnd();
}
//clean all animation Names
void edk::animation::InterpolationGroup::cleanAnimationNames(){
    this->cleanAnimationNameSelected();edkEnd();
    //remove all the root's
    edk::animation::AnimationName* temp=NULL;edkEnd();
    while((temp = (edk::animation::AnimationName*)this->animationNames.getElementInPosition(0u) )){
        //remove the root
        this->animationNames.remove(temp);edkEnd();
        //delete temp
        delete temp;edkEnd();
    }
}

//get Loop
bool edk::animation::InterpolationGroup::getLoop(){
    return this->looping;edkEnd();
}
//get Increment
bool edk::animation::InterpolationGroup::getIncrement(){
    return this->incrementing;edkEnd();
}

//CONTROLS
//animation controllers
void edk::animation::InterpolationGroup::playForward(){
    //play in the time
    this->playForwardIn(this->animationSecond);edkEnd();
}
void edk::animation::InterpolationGroup::playForwardIn(edk::float32 second){
    this->stop();edkEnd();
    //clean the animationNameSelected
    this->cleanAnimationNameSelected();
    this->rewind=false;edkEnd();
    //set false for playing
    this->playing=false;edkEnd();
    this->paused=false;edkEnd();
    //test if have animation
    if(this->animations.size()){
        //then read the first and last second
        //edk::float32 firstSecond = this->animations[this->interpolationStart]->getStart().second;edkEnd();
        edk::float32 firstSecond = this->frameStart;edkEnd();
        //edk::float32 LastSecond = this->animations[this->interpolationEnd]->getEnd().second;edkEnd();
        edk::float32 LastSecond = this->frameEnd;edkEnd();
        //testa if the second is in the animation
        if(second>=firstSecond){
            if(second<=LastSecond){
                //animationSecond receive the second
                this->animationSecond=second;edkEnd();
            }
            else{
                //animationSecond receive the lastSecond
                this->animationSecond=LastSecond;edkEnd();
            }
        }
        else{
            //animationSecond receive the firstSecond
            this->animationSecond=firstSecond;edkEnd();
        }
        //select the interpolation
        this->selectInterpolationBySecond(this->animationSecond);edkEnd();
        //start the clock
        this->clock.start();edkEnd();
        //set true for playing
        this->playing=true;edkEnd();
        this->saveAnimationSecond = this->animationSecond;edkEnd();

        //test if is incrementing
        if(this->incrementing){
            //run the start incrementing
            this->startIncrement();edkEnd();
        }
        return;edkEnd();
    }
    //else stop
    this->stop();edkEnd();
}
void edk::animation::InterpolationGroup::restartForward(){
    this->playForwardIn(this->frameStart);edkEnd();
}
void edk::animation::InterpolationGroup::playRewind(){
    //
    this->playRewindIn(this->animationSecond);edkEnd();
}
void edk::animation::InterpolationGroup::playRewindIn(edk::float32 second){
    //set play forward
    this->playForwardIn(second);edkEnd();
    //select the interpolation rewind
    this->selectInterpolationRewindBySecond(second);edkEnd();
    //and change to rewind
    this->rewind=true;edkEnd();

    //test if is incrementing
    if(this->incrementing){
        //run the start incrementing
        this->startIncrement();edkEnd();
    }
    else{
        this->cleanIncrement();edkEnd();
    }
}
void edk::animation::InterpolationGroup::pause(){
    if(!this->playing){
        this->playing=true;edkEnd();
    }
    this->paused = !this->paused;edkEnd();
}
void edk::animation::InterpolationGroup::restartRewind(){
    this->playRewindIn(this->frameEnd);edkEnd();
}
bool edk::animation::InterpolationGroup::changeToForward(){
    //test if is playing the animation
    if(this->isPlaying()){
        //change the animation way
        this->rewind=false;edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationGroup::changeToRewind(){
    //test if is playing the animation
    if(this->isPlaying()){
        //change the animation way
        this->rewind=true;edkEnd();
    }
    return false;
}
void edk::animation::InterpolationGroup::pauseOn(){
    //test if wasn't playing
    this->clock.start();edkEnd();
    this->paused=true;edkEnd();
}
void edk::animation::InterpolationGroup::pauseOff(){
    //test if was playing
    this->clock.start();edkEnd();
    this->paused=false;edkEnd();
}
void edk::animation::InterpolationGroup::stop(){
    //start the clock
    this->cleanIncrement();edkEnd();
    this->clock.start();edkEnd();
    this->playing=false;edkEnd();
    this->paused=false;edkEnd();
    if(!this->animations.size()){
        this->animationSecond=0.0f;edkEnd();
    }
    else{
        this->animationSecond=this->animations[0u]->getStart().second;edkEnd();
    }
    this->saveAnimationSecond = this->animationSecond;edkEnd();
}
//set loop
void edk::animation::InterpolationGroup::setLoop(bool loop){
    //set the loop
    this->looping=loop;edkEnd();
}
void edk::animation::InterpolationGroup::loopOn(){
    //
    this->setLoop(true);edkEnd();
}
void edk::animation::InterpolationGroup::loopOff(){
    //
    this->setLoop(false);edkEnd();
}
//set increment - The animation will run in looping but incrementing the values
void edk::animation::InterpolationGroup::setIncrement(bool increment){
    this->incrementing=increment;edkEnd();
    if(this->isPlaying() && this->incrementing){
        this->startIncrement();edkEnd();
    }
}
void edk::animation::InterpolationGroup::incrementOn(){
    this->setIncrement(true);edkEnd();
}
void edk::animation::InterpolationGroup::incrementOff(){
    this->setIncrement(false);edkEnd();
}

//GETERS
//return the number of animations
edk::uint32 edk::animation::InterpolationGroup::getInterpolationSize(){
    return this->animations.size();edkEnd();
}
edk::uint32 edk::animation::InterpolationGroup::getInterpolations(){
    return this->animations.size();edkEnd();
}
//get the second
edk::float32 edk::animation::InterpolationGroup::getAnimationSecond(){
    //
    return this->animationSecond;edkEnd();
}
//return the missingTime
edk::float32 edk::animation::InterpolationGroup::getAnimationMissingSecond(){
    //
    if(this->rewind){
        return this->animationSecond - this->frameStart;edkEnd();
    }
    else{
        return this->frameEnd - this->animationSecond;edkEnd();
    }
    return 0.f;
}
//get the animation start and end
edk::float32 edk::animation::InterpolationGroup::getAnimationStart(){
    return this->frameStart;edkEnd();
}
edk::float32 edk::animation::InterpolationGroup::getAnimationEnd(){
    return this->frameEnd;edkEnd();
}
edk::float32 edk::animation::InterpolationGroup::getAnimationLenght(){
    edk::float32 ret;edkEnd();
    if(this->frameEnd<0.f){
        if(this->frameStart<0.f){
            ret = this->frameEnd - this->frameStart;edkEnd();
        }
        else{
            ret = (this->frameEnd*-1.f) + this->frameStart;edkEnd();
        }
    }
    else{
        if(this->frameStart<0.f){
            ret = (this->frameStart*-1.f) + this->frameEnd;edkEnd();
        }
        else{
            ret = this->frameEnd - this->frameStart;edkEnd();
        }
    }
    if(ret<0.f){
        ret*=-1.f;edkEnd();
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
    return this->isPlayingName((edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationGroup::isPlayingName(edk::char8* name){
    if(name && this->isPlaying() && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationGroup::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);edkEnd();
}
bool edk::animation::InterpolationGroup::wasPlayingName(edk::char8* name){
    if(name && !this->isPlaying() && this->nameSelected){
        //test if is playing the name
        return this->nameSelected->nameEqual(name);edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationGroup::isPaused(){
    return this->paused;edkEnd();
}
//return true if is rewind
bool edk::animation::InterpolationGroup::isRewind(){
    return this->rewind;edkEnd();
}

//return the interpolation seconds
edk::float32 edk::animation::InterpolationGroup::getInterpolationStartSecond(edk::float32 position){
    if(position < this->animations.size()){
        return this->animations[position]->getStart().second;edkEnd();
    }
    return 0u;edkEnd();
}
edk::float32 edk::animation::InterpolationGroup::getInterpolationEndSecond(edk::float32 position){
    if(position < this->animations.size()){
        return this->animations[position]->getEnd().second;edkEnd();
    }
    return 0u;edkEnd();
}
//update the clock animation
edk::float32 edk::animation::InterpolationGroup::updateClockAnimation(){
    return this->updateClockAnimation(this->clock.getMicroseconds()*edk::watch::microsecond);edkEnd();
}
edk::float32 edk::animation::InterpolationGroup::updateClockAnimation(edk::float32 distance){
    //return
    edk::float32 ret=0.0;
    //test if have animations and playing
    if(this->isPlaying()){
        if(distance>0.f){
            this->clock.start();edkEnd();
        }
        //test if is playin rewind
        if(this->rewind){
            //decrement the second
            this->animationSecond-=distance * this->speed;edkEnd();

            //test if reach the start
            if(this->animationSecond<this->frameStart){
                //then reach the start

                //test if are looping;edkEnd();
                if(this->looping || this->incrementing){
                    edk::float32 dist = this->frameEnd-frameStart;edkEnd();
                    while(this->animationSecond<this->frameStart){
                        //then calculate the looping
                        this->animationSecond += dist;edkEnd();
                    }
                    //select the first animation
                    this->selectInterpolationRewindBySecond(this->animationSecond);edkEnd();

                    //run the increment to notify the increment values
                    if(this->incrementing){
                        this->runIncrementRewind();edkEnd();
                    }
                }
                else{
                    //else just set the end
                    this->animationSecond=this->frameStart;edkEnd();
                    //set stop
                    this->stop();edkEnd();
                }
                //run the callback
                if(this->callback){
                    this->callback->animationEnd(this);edkEnd();
                }
            }
            else{
                //test if back the interpolation selected
                edk::animation::InterpolationLine* temp = NULL;edkEnd();
                while(true){
                    if(this->animations.havePos(this->interpolationSelect)){
                        temp = this->animations[this->interpolationSelect];edkEnd();
                        if(temp){
                            //load the start and end seconds
                            if(this->animationSecond<temp->getStart().second
                                    &&
                                    this->interpolationSelect>0u
                                    ){
                                if(this->interpolationSelect){
                                    //increment the interpolationSelected
                                    this->interpolationSelect--;edkEnd();
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
                            this->interpolationSelect--;edkEnd();
                        }
                        else{
                            break;
                    }
                }

                while(true){
                    if(this->animations.havePos(this->interpolationSelect)){
                        //test if over the interpolation selected
                        temp = this->animations[this->interpolationSelect];edkEnd();
                        if(temp){
                            //load the start and end seconds
                            if(this->animationSecond>temp->getEnd().second){

                                if(this->animations.havePos(this->interpolationSelect +1u)){

                                    //increment the interpolationSelected
                                    this->interpolationSelect++;edkEnd();

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
            this->animationSecond+=distance * this->speed;edkEnd();

            //test if reach the end
            if(this->animationSecond>this->frameEnd){
                //then reach the end

                //test if are looping;edkEnd();
                if(this->looping || this->incrementing){
                    edk::float32 dist = this->frameEnd-frameStart;edkEnd();
                    if(this->animationSecond>this->frameEnd){
                        //then calculate the looping
                        this->animationSecond -= dist;edkEnd();//+(this->animationSecond-this->frameEnd);edkEnd();
                    }
                    //select the first animation
                    this->selectInterpolationBySecond(this->animationSecond);edkEnd();

                    //run the increment to notify the increment values
                    if(this->incrementing){
                        this->runIncrementForward();edkEnd();
                    }
                }
                else{
                    //else just set the end
                    this->animationSecond=this->frameEnd;edkEnd();
                    //set stop
                    this->stop();edkEnd();
                }
                //run the callback
                if(this->callback){
                    this->callback->animationEnd(this);edkEnd();
                }
            }
            else{
                //test if over the interpolation selected
                edk::animation::InterpolationLine* temp = NULL;edkEnd();
                while(true){
                    if(this->animations.havePos(this->interpolationSelect)){
                        //test if over the interpolation selected
                        temp = this->animations[this->interpolationSelect];edkEnd();
                        if(temp){
                            //load the start and end seconds
                            if(this->animationSecond>temp->getEnd().second){

                                if(this->animations.havePos(this->interpolationSelect +1u)){

                                    //increment the interpolationSelected
                                    this->interpolationSelect++;edkEnd();

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
                        this->interpolationSelect--;edkEnd();
                        break;
                    }
                }
            }
        }

        this->saveAnimationSecond = this->animationSecond;edkEnd();
        //then return the second
        ret = this->animationSecond;edkEnd();
    }
    //else return 0.0f
    return ret;
}
//test if have the keyframe
bool edk::animation::InterpolationGroup::haveKeyframe(edk::float32 second){
    if(this->animations.size()){
        //search the interpolation
        edk::uint32 search = this->searchBackInterpoaltionMinusOne(second);edkEnd();
        if(this->animations.havePos(search)){
            //load the interpolation
            edk::animation::InterpolationLine* temp = this->animations[search];edkEnd();
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
        return this->printSelectedFramesFrom(0,this->animations.size()-1u);edkEnd();
    }
    //else return false
    return false;
}
//Print the frames from start and end
bool edk::animation::InterpolationGroup::printSelectedFrames(){
    //test if have frames
    if(this->animations.size()){
        //print the frames
        return this->printSelectedFramesFrom(this->interpolationStart,this->interpolationEnd);edkEnd();
    }
    //else return false
    return false;
}

//cand delete
void edk::animation::InterpolationGroup::cantDeleteGroup(){
    this->canDeleteGroup=false;edkEnd();
}

//write to XML
bool edk::animation::InterpolationGroup::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"anim_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 count = 0u;edkEnd();
                        //save the looping
                        if(this->getLoop()){
                            xml->addSelectedNextAttribute("loop","on");edkEnd();
                        }
                        else{
                            xml->addSelectedNextAttribute("loop","off");edkEnd();
                        }
                        //save the incrementing
                        if(this->getIncrement()){
                            xml->addSelectedNextAttribute("increment","on");edkEnd();
                        }
                        else{
                            xml->addSelectedNextAttribute("increment","off");edkEnd();
                        }
                        //test if have the frameTemp
                        if(this->tempFrame){
                            //add the tempFrame
                            this->tempFrame->writeToXML(xml,count);edkEnd();
                            count++;edkEnd();
                        }
			edk::uint32 size = 0u;
						
                        //write the animationFrames
                        size = this->animations.size();edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            if(!i){
                                //write the first
                                this->animations[i]->writeToXMLStart(xml,count);edkEnd();
                                count++;edkEnd();
                            }
                            this->animations[i]->writeToXMLEnd(xml,count);edkEnd();
                            count++;edkEnd();
                        }
                        //write the animationNames
                        size = this->animationNames.size();edkEnd();
                        edk::animation::AnimationName *temp = NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::AnimationName *)this->animationNames.getElementInPosition(i);edkEnd();
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
bool edk::animation::InterpolationGroup::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"anim_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->cleanAnimations();edkEnd();
                    this->deleteTempFrame();edkEnd();
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
                        this->addNewInterpolationLine(frameTemp);edkEnd();
                        //
                        count++;edkEnd();
                        //clean the frame
                        frameTemp.second = 0.f;edkEnd();
                        //return true
                        ret=true;edkEnd();
                    }
                    count = 0;
                    //read the names
                    edk::animation::AnimationName nameTemp;edkEnd();
                    while(nameTemp.readFromXML(xml,count)){
                        //add the animationName
                        this->addNewAnimationName(nameTemp.getName(),nameTemp.start,nameTemp.end);edkEnd();

                        count++;edkEnd();
                        //clean nameTemp
                        nameTemp.setName((edk::char8*)NULL);edkEnd();
                        nameTemp.start = 0.f;edkEnd();
                        nameTemp.end = 0.f;edkEnd();
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
