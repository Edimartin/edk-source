#include "AnimatedPolygon3DList.h"

/*
Library AnimatedPolygon3DList - Add animation to 3D Polygons in EDK Game Engine
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

edk::shape::AnimatedPolygon3DList::AnimatedPolygon3DList(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::AnimatedPolygon3DList::~AnimatedPolygon3DList(){
    this->Destructor();
}

void edk::shape::AnimatedPolygon3DList::Constructor(){
    edk::shape::Polygon3DList::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->freeSelectedAnimation();
        this->selectedID=0u;
    }
}
void edk::shape::AnimatedPolygon3DList::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::shape::Polygon3DList::Destructor();
}

//ANIMATIONS
//create a new animation in a polygon
bool edk::shape::AnimatedPolygon3DList::setAnimationFramesToPolygon(edk::uint32 position){
    //test if have the polygon
    if(this->polygons.havePos(position)){
        //select the polygon
        edk::shape::Polygon3D* temp = this->polygons.get(position);
        //test if have selected some polygon
        if(temp){
            //then add a new animation
            return temp->framesCreateAnimation();
        }
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::newAnimationFramesToPolygon(edk::uint32 position){
    return this->setAnimationFramesToPolygon(position);
}
bool edk::shape::AnimatedPolygon3DList::createAnimationFramesToPolygon(edk::uint32 position){
    return this->setAnimationFramesToPolygon(position);
}
//copy an animation to another polygon
bool edk::shape::AnimatedPolygon3DList::copyAnimationFramesToPolygon(edk::uint32 position,edk::uint32 dest){
    //test if have the 2 polygons
    if(this->polygons.havePos(position)
            &&
            this->polygons.havePos(dest)){
        //select the polygon
        edk::shape::Polygon3D* temp1 = this->polygons.get(position);
        edk::shape::Polygon3D* temp2 = this->polygons.get(dest);
        //test if have selected some polygon
        if(temp1 && temp2){
            //then copy the animation from temp1 to temp2
            return temp2->framesSetAnimation(temp1->framesGetAnimation());
        }
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::copyThisAnimationFramesToPolygon(edk::animation::Interpolation1DGroup* anim,edk::uint32 dest){
    //test if have the 2 polygons
    if(this->polygons.havePos(dest)
            &&
            anim){
        //select the polygon
        edk::shape::Polygon3D* poly = this->polygons.get(dest);
        if(poly){
            //clean the animation
            edk::animation::Interpolation1DGroup* temp = poly->framesGetAnimation();
            if(temp){
                temp->cleanAnimations();
                //*temp = *anim;
                temp->cloneFrom(anim);
                return true;
            }
        }
    }
    return false;
}
//remove polygonAnimation
bool edk::shape::AnimatedPolygon3DList::removeAnimationFramesFromPolygon(edk::uint32 position){
    //test if have the polygon
    if(this->polygons.havePos(position)){
        //select the polygon
        edk::shape::Polygon3D* temp = this->polygons.get(position);
        //test if have selected some polygon
        if(temp){
            //then remove the animation
            temp->framesRemoveAnimation();
            //then return true
            return true;
        }
    }
    //else return false
    return false;
}
//select the animation
bool edk::shape::AnimatedPolygon3DList::selectAnimationFramesFromPolygon(edk::uint32 position){
    //free the animation
    this->freeSelectedAnimation();
    //test if have the polygon
    if(this->polygons.havePos(position)){
        //select the polygon
        edk::shape::Polygon3D* temp = this->polygons.get(position);
        //test if have selected some polygon
        if(temp){
            //test if have an animation
            if(temp->framesHaveAnimation()){
                //then select the animation
                this->selectedAnimation = temp->framesGetAnimation();
                //then return true
                return true;
            }
        }
    }
    //else return false
    return false;
}
//get animation ID selected
edk::uint32 edk::shape::AnimatedPolygon3DList::getAnimationFramesSelectedID(){
    return this->selectedID;
}
//return true if have the animation
bool edk::shape::AnimatedPolygon3DList::haveSelectedAnimation(){
    if(this->selectedAnimation){
        return true;
    }
    return false;
}

//free the selected animation
void edk::shape::AnimatedPolygon3DList::freeSelectedAnimation(){
    //set selectedAnimation to NULL
    this->selectedAnimation=NULL;
    this->selectedID=0u;
}
//Atualiza as animações da malha
void edk::shape::AnimatedPolygon3DList::updateFramesAnimations(){
    //update all animations
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        //
        if(this->polygons.get(i)){
            //carrega a animation
            if(this->polygons.get(i)->framesIsAnimationCreator()){
                //carrega a animation
                this->polygons.get(i)->framesGetAnimation()->updateClockAnimation();
            }
        }
    }
    //after update all polygons

    edk::float32 frameTemp = 0.f;

    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        //
        if(this->polygons.get(i)){
            //carrega a animation
            if(this->polygons.get(i)->framesGetAnimation()){
                if(this->polygons.get(i)->framesGetAnimation()->isPlaying()){
                    frameTemp = this->polygons.get(i)->framesGetAnimation()->getClockX();
                    this->polygons.get(i)->usePolygonUVFramePosition(frameTemp);
                }
            }
        }
    }
}
void edk::shape::AnimatedPolygon3DList::updateFramesAnimations(edk::float32 seconds){
    //update all animations
    edk::uint32 size = this->polygons.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.get(i)){
            //carrega a animation
            if(this->polygons.get(i)->framesIsAnimationCreator()){
                //load the animation
                this->polygons.get(i)->framesGetAnimation()->updateClockAnimation(seconds);
            }
        }
    }
    //after update all polygons
    edk::float32 frameTemp = 0.f;
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.get(i)){
            //carrega a animation
            if(this->polygons.get(i)->framesGetAnimation()){
                if(this->polygons.get(i)->framesGetAnimation()->isPlaying()){
                    frameTemp = this->polygons.get(i)->framesGetAnimation()->getClockX();
                    this->polygons.get(i)->usePolygonUVFramePosition(frameTemp);
                }
            }
        }
    }
}


//AnimationSelected
//set the abstract
bool edk::shape::AnimatedPolygon3DList::selectedAnimationSetAnimationCallback(edk::animation::AnimationCallback* callback){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->setAnimationCallback(callback);
    }
    //else return false
    return false;
}
//create a new interpoationLine
bool edk::shape::AnimatedPolygon3DList::selectedAnimationAddInterpolationLine(edk::float32 second,edk::float32 x){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->addNewInterpolationLine(second,x);
    }
    //else return false
    return false;
}
//return frames size
edk::uint32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetInterpolationSize(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getInterpolationSize();
    }
    //else return false
    return 0u;
}

//cleanFrames and Names
bool edk::shape::AnimatedPolygon3DList::selectedAnimationClean(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->clean();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationCleanFrames(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->cleanAnimations();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationCleanAnimationNames(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->cleanAnimationNames();
        return true;
    }
    //else return false
    return false;
}
//controls
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayForward(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playForward();
        this->updateFramesAnimations(0.001f);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayForwardIn(edk::float32 second){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playForwardIn(second);
        this->updateFramesAnimations(0.001f);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationRestartForward(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->restartForward();
        this->updateFramesAnimations(0.001f);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayRewind(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playRewind();
        this->updateFramesAnimations(0.001f);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayRewindIn(edk::float32 second){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playRewindIn(second);
        this->updateFramesAnimations(0.001f);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationRestartRewind(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->restartRewind();
        this->updateFramesAnimations(0.001f);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationChangeToForward(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->changeToForward();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationChangeToRewind(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->changeToRewind();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationChangeWay(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->changeWay();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPause(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->pause();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPauseOn(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->pauseOn();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPauseOff(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->pauseOff();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationStop(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->stop();
        return true;
    }
    //else return false
    return false;
}
//set loop
bool edk::shape::AnimatedPolygon3DList::selectedAnimationSetLoop(bool loop){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->setLoop(loop);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationLoopOn(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->loopOn();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationLoopOff(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->loopOff();
        return true;
    }
    //else return false
    return false;
}
//get the second
edk::float32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetSecond(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getAnimationSecond();
    }
    //return zero;
    return 0.0f;
}
//return if are playing
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlaying(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->isPlaying();
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlayingName(const edk::char8* name){
    return this->selectedAnimationIsPlayingName((edk::char8*) name);
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlayingName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->isPlayingName(name);
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlayingFoward(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->isPlayingFoward();
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlayingFowardName(const edk::char8* name){
    return this->selectedAnimationIsPlayingFowardName((edk::char8*) name);
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlayingFowardName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->isPlayingFowardName(name);
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlayingRewind(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->isPlaying();
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlayingRewindName(const edk::char8* name){
    return this->selectedAnimationIsPlayingRewindName((edk::char8*) name);
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPlayingRewindName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->isPlayingName(name);
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationWasPlayingName(const edk::char8* name){
    return this->selectedAnimationWasPlayingName((edk::char8*) name);
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationWasPlayingName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->wasPlayingName(name);
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationWasPlayingFoward(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->wasPlayingFoward();
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationWasPlayingFowardName(const edk::char8* name){
    return this->selectedAnimationWasPlayingFowardName((edk::char8*) name);
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationWasPlayingFowardName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->wasPlayingFowardName(name);
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationWasPlayingRewind(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->wasPlayingRewind();
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationWasPlayingRewindName(const edk::char8* name){
    return this->selectedAnimationWasPlayingRewindName((edk::char8*) name);
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationWasPlayingRewindName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->wasPlayingRewindName(name);
    }
    //else return false
    return false;
}
//return if are paused
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPaused(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->isPaused();
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPausedName(const edk::char8* name){
    return this->selectedAnimationIsPausedName((edk::char8*) name);
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationIsPausedName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->isPausedName(name);
    }
    //else return false
    return false;
}
//animationNames
bool edk::shape::AnimatedPolygon3DList::selectedAnimationAddAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->addNewAnimationName(name,start,end);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationAddAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->addNewAnimationName(name,start,end);
        return true;
    }
    //else return false
    return false;
}
//test if have the animationName
bool edk::shape::AnimatedPolygon3DList::selectedAnimationHaveAnimationName(const edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->haveAnimationName(name);
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationHaveAnimationName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->haveAnimationName(name);
    }
    //else return false
    return false;
}
//return the animation seconds
edk::float32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetAnimationStart(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getAnimationStart();
    }
    //else return false
    return 0.f;
}
edk::float32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetAnimationEnd(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getAnimationEnd();
    }
    //else return false
    return 0.f;
}
//return the animation name seconds
edk::float32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetAnimationNameStart(const edk::char8* name){
    return this->selectedAnimationGetAnimationNameStart((edk::char8*) name);
}
edk::float32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetAnimationNameStart(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getAnimationNameStart(name);
    }
    //else return false
    return 0.f;
}
edk::float32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetAnimationNameEnd(const edk::char8* name){
    return this->selectedAnimationGetAnimationNameEnd((edk::char8*) name);
}
edk::float32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetAnimationNameEnd(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getAnimationNameEnd(name);
    }
    //else return false
    return 0.f;
}
//Play the animationName
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayNameForward(const edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameForward(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayNameForward(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameForward(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayNameForwardIn(const edk::char8* name,edk::float32 second){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameForwardIn(name,second);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayNameForwardIn(edk::char8* name,edk::float32 second){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameForwardIn(name,second);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayNameRewind(const edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameRewind(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayNameRewind(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameRewind(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayNameRewindIn(const edk::char8* name,edk::float32 second){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameRewindIn(name,second);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationPlayNameRewindIn(edk::char8* name,edk::float32 second){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameRewindIn(name,second);
        return true;
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::shape::AnimatedPolygon3DList::selectedAnimationRemoveAnimationName(const edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->removeAnimationName(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationRemoveAnimationName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->removeAnimationName(name);
        return true;
    }
    //else return false
    return false;
}

//Set one interpolation X as a curve
bool edk::shape::AnimatedPolygon3DList::selectedAnimationSetCurveX(edk::uint32 position){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->setInterpolationCurveX(position);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationSetNotCurveX(edk::uint32 position){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->setInterpolationNotCurveX(position);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationGetIsCurveX(edk::uint32 position){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getInterpolationIsCurveX(position);
    }
    //else return false
    return false;
}
//Set the interpolation curve points
bool edk::shape::AnimatedPolygon3DList::selectedAnimationSetCurveP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->setInterpolationP1X(position,second,x);
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon3DList::selectedAnimationSetCurveP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->setInterpolationP2X(position,second,x);
    }
    //else return false
    return false;
}
//Speed
bool edk::shape::AnimatedPolygon3DList::selectedAnimationSetSpeed(edk::float32 speed){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->setSpeed(speed);
    }
    //else return false
    return false;
}
edk::float32 edk::shape::AnimatedPolygon3DList::selectedAnimationGetSpeed(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getSpeed();
    }
    //else return false
    return 0.f;
}
/*
//XML
bool edk::shape::AnimatedPolygon3DList::writeToXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon3DList::writeToXML(xml,id)){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //write the animation
                    ret=true;
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
bool edk::shape::AnimatedPolygon3DList::readFromXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon3DList::readFromXML(xml,id)){
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("pCount"));
                    edk::shape::Polygon3D poly;
                    //write the polygons
                    for(edk::uint32 i=0u;i<size;i++){
                        poly.deletePolygon();
                        poly.readFromXML(xml,i);
                        //add the poly
                        this->addPolygon(poly);
                    }
                    xml->selectFather();
                }
                free(name);
            }
            free(nameID);
        }
    }
    return false;
}
*/
