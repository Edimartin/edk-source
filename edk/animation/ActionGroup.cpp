#include "ActionGroup.h"

/*
Library C++ ActionGroup - Animate Actions
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
#warning "            Inside ActionGroup.cpp"
#endif

edk::animation::ActionGroup::ActionGroup(){
}
edk::animation::ActionGroup::~ActionGroup(){
    this->clean();
}

//add one action
bool edk::animation::ActionGroup::addAction(edk::float32 second,edk::Action* action){
    bool ret=false;
    //test if dont have the keyframe
    if(!this->anim.haveKeyframe(second)){
        //then add the keyframe
        this->anim.addNewInterpolationLine(second,second);
        //convert the interpolations to constant
        this->anim.setAllConstantX();
        ret = true;
    }
    //add the action to the tree
    if(tree.addAction(second,action)){
        ret = true;
    }
    return ret;
}
bool edk::animation::ActionGroup::addZeroAction(edk::float32 second){
    return this->addAction(second,new edk::ActionZero());
}

//remove second
bool edk::animation::ActionGroup::removeSecond(edk::float32 second){
    if(this->anim.haveKeyframe(second)){
        //remove the keyframe
        this->anim.removeKeyFrame(second);
    }
    //clean the secon on the tree
    this->tree.cleanActionsInSecond(second);
    return false;
}

//clean animation
void edk::animation::ActionGroup::clean(){
    this->anim.cleanFrameSelected();
    this->anim.cleanAnimations();
    this->tree.cleanActions();
}

//update animations
void edk::animation::ActionGroup::update(){
    if(this->anim.isPlaying()){
        //update the clock
        this->anim.updateClockAnimation();
        //get the value
        bool success = false;
        edk::float32 value = this->anim.getClockX(&success);
        if(success){
            //tets if the value is diferent than the last value
            if(value!=this->valueTemp){
                //then run the actions
                //printf("\nUpdate Tree %.2f",value);
                this->tree.updateSecond(value);
                this->valueTemp = value;
            }
        }
    }
}

//ANIMATION FUNCTIONS
//get Loop
bool edk::animation::ActionGroup::isLooping(){return this->anim.isLooping();}

//CONTROLS
//animation controllers
void edk::animation::ActionGroup::playForward(){this->anim.playForward();}
void edk::animation::ActionGroup::playForwardIn(edk::float32 second){this->anim.playForwardIn(second);}
//void edk::animation::ActionGroup::playRewind(){this->anim.playRewind();}
//void edk::animation::ActionGroup::playRewindIn(edk::float32 second){this->anim.playRewindIn(second);}
void edk::animation::ActionGroup::pause(){this->anim.pause();}
void edk::animation::ActionGroup::stop(){this->anim.stop();}
//set loop
void edk::animation::ActionGroup::setLoop(bool loop){this->anim.setLoop(loop);}
void edk::animation::ActionGroup::loopOn(){this->anim.loopOn();}
void edk::animation::ActionGroup::loopOff(){this->anim.loopOff();}

//return if are playing
bool edk::animation::ActionGroup::isPlaying(){return this->anim.isPlaying();}
bool edk::animation::ActionGroup::isPaused(){return this->isPaused();}
