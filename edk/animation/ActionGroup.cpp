#include "ActionGroup.h"

/*
Library C++ ActionGroup - Animate Actions
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
#warning "            Inside ActionGroup.cpp"
#endif

edk::animation::ActionGroup::ActionGroup(){
    this->canDeleteGroup=true;edkEnd();
    this->valueTemp=0.0;
    this->setReadXMLActionFunction(&this->readXMLZero);edkEnd();
}
edk::animation::ActionGroup::~ActionGroup(){
    if(this->canDeleteGroup){
        this->clean();edkEnd();
    }
    else{
        this->anim.cantDeleteGroup();edkEnd();
        this->tree.cantDeleteTrees();edkEnd();
    }
    this->canDeleteGroup=true;edkEnd();
}

//return the zero action
edk::Action* edk::animation::ActionGroup::readXMLZero(edk::classID,edk::uint32 ){
    return new edk::ActionZero();edkEnd();
}

//first update
void edk::animation::ActionGroup::firstUpdate(){
    if(this->anim.isPlaying()){
        //update the clock
        this->anim.updateClockAnimation();edkEnd();
        //get the value
        this->valueTemp = this->anim.getClockX() - 1.f;edkEnd();
    }
}
void edk::animation::ActionGroup::firstUpdate(edk::float32 seconds){
    if(this->anim.isPlaying()){
        //update the clock
        this->anim.updateClockAnimation(seconds);edkEnd();
        //get the value
        this->valueTemp = this->anim.getClockX() - 1.f;edkEnd();
    }
}

//add one action
bool edk::animation::ActionGroup::addAction(edk::float32 second,edk::Action* action){
    bool ret=false;edkEnd();
    //test if dont have the keyframe
    if(!this->anim.haveKeyframe(second)){
        //then add the keyframe
        this->anim.addNewInterpolationLine(second,second);edkEnd();
        //convert the interpolations to constant
        this->anim.setAllConstantX();edkEnd();
        ret = true;edkEnd();
    }
    //add the action to the tree
    if(tree.addAction(second,action)){
        ret = true;edkEnd();
    }
    return ret;
}
bool edk::animation::ActionGroup::addZeroAction(edk::float32 second){
    return this->addAction(second,new edk::ActionZero());edkEnd();
}

//remove second
bool edk::animation::ActionGroup::removeSecond(edk::float32 second){
    if(this->anim.haveKeyframe(second)){
        //remove the keyframe
        this->anim.removeKeyFrame(second);edkEnd();
    }
    //clean the secon on the tree
    this->tree.cleanActionsInSecond(second);edkEnd();
    return false;
}

//get the keyFrames size
edk::uint32 edk::animation::ActionGroup::getKeySize(){
    //
    return this->tree.size();edkEnd();
}
//get the key second
edk::float32 edk::animation::ActionGroup::getKeySecond(edk::uint32 keyPosition){
    //
    return this->tree.getSecond(keyPosition);edkEnd();
}
//get the actions size in position
edk::uint32 edk::animation::ActionGroup::getActionsSize(edk::uint32 keyPosition){
    //
    return this->tree.getActionSizeInPosition(keyPosition);edkEnd();
}
//return the action code
edk::uint32 edk::animation::ActionGroup::getActionCode(edk::uint32 keyPosition,edk::uint32 actionPosition){
    edk::Action* temp = this->tree.getActionInPosition(keyPosition,actionPosition);edkEnd();
    if(temp){
        return temp->getCode();edkEnd();
    }
    return 0u;edkEnd();
}
//return the action
edk::Action* edk::animation::ActionGroup::getActionInKey(edk::uint32 keyPosition,edk::uint32 actionPosition){
    //
    return this->tree.getActionInPosition(keyPosition,actionPosition);edkEnd();
}
edk::Action* edk::animation::ActionGroup::getActionInSecond(edk::float32 second,edk::uint32 actionPosition){
    //
    return this->tree.getActionInSecond(second,actionPosition);edkEnd();
}

//clean animation
void edk::animation::ActionGroup::clean(){
    this->anim.cleanFrameSelected();edkEnd();
    this->anim.cleanAnimations();edkEnd();
    this->tree.cleanActions();edkEnd();
}

//update animations
void edk::animation::ActionGroup::update(){
    if(this->anim.isPlaying()){
        //update the clock
        this->anim.updateClockAnimation();edkEnd();
        //get the value
        edk::float32 value = this->anim.getClockX();edkEnd();
        //tets if the value is diferent than the last value
        if(value!=this->valueTemp){
            //then run the actions
            //printf("\nUpdate Tree %.2f",value);edkEnd();
            this->tree.updateSecond(value);edkEnd();
            this->valueTemp = value;edkEnd();
        }
    }
}
void edk::animation::ActionGroup::update(edk::float32 seconds){
    if(this->anim.isPlaying()){
        //update the clock
        this->anim.updateClockAnimation(seconds);edkEnd();
        //get the value
        edk::float32 value = this->anim.getClockX();edkEnd();
        //tets if the value is diferent than the last value
        if(value!=this->valueTemp){
            //then run the actions
            //printf("\nUpdate Tree %.2f",value);edkEnd();
            this->tree.updateSecond(value);edkEnd();
            this->valueTemp = value;edkEnd();
        }
    }
}

//ANIMATION FUNCTIONS
//get Loop
bool edk::animation::ActionGroup::isLooping(){return this->anim.getLoop();edkEnd();}

//CONTROLS
//animation controllers
void edk::animation::ActionGroup::playForward(){
    this->anim.playForward();edkEnd();
    this->firstUpdate();edkEnd();
}
void edk::animation::ActionGroup::playForwardIn(edk::float32 second){
    this->anim.playForwardIn(second);edkEnd();
    this->firstUpdate();edkEnd();
}
void edk::animation::ActionGroup::playForward(edk::float32 updateSeconds){
    this->anim.playForward();edkEnd();
    this->firstUpdate(updateSeconds);edkEnd();
}
void edk::animation::ActionGroup::playForwardIn(edk::float32 second,edk::float32 updateSeconds){
    this->anim.playForwardIn(second);edkEnd();
    this->firstUpdate(updateSeconds);edkEnd();
}
//void edk::animation::ActionGroup::playRewind(){this->anim.playRewind();edkEnd();}
//void edk::animation::ActionGroup::playRewindIn(edk::float32 second){this->anim.playRewindIn(second);edkEnd();}
void edk::animation::ActionGroup::pause(){this->anim.pause();edkEnd();}
void edk::animation::ActionGroup::pauseOn(){this->anim.pauseOn();edkEnd();}
void edk::animation::ActionGroup::pauseOff(){this->anim.pauseOff();edkEnd();}
void edk::animation::ActionGroup::stop(){this->anim.stop();edkEnd();}
//set loop
void edk::animation::ActionGroup::setLoop(bool loop){this->anim.setLoop(loop);edkEnd();}
void edk::animation::ActionGroup::loopOn(){this->anim.loopOn();edkEnd();}
void edk::animation::ActionGroup::loopOff(){this->anim.loopOff();edkEnd();}

//return if are playing
bool edk::animation::ActionGroup::isPlaying(){return this->anim.isPlaying();edkEnd();}
bool edk::animation::ActionGroup::isPaused(){return this->isPaused();edkEnd();}

bool edk::animation::ActionGroup::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("ActionGroup_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //create the animations
                        this->anim.writeToXML(xml,0u);edkEnd();

                        //get size of tree
                        edk::uint32 size = this->tree.size();edkEnd();

                        //add the size
                        xml->addSelectedNextAttribute("keySize",size);edkEnd();
                        if(size){
                            edk::uint32 sizeSecond;edkEnd();
                            edk::Action* temp;edkEnd();
                            edk::char8* nameTemp;edkEnd();
                            edk::char8* numberTemp;edkEnd();
                            //get the actions
                            for(edk::uint32 i=0u;i<size;i++){
                                sizeSecond = this->tree.getActionSizeInPosition(i);edkEnd();
                                numberTemp = edk::String::uint32ToStr(i);edkEnd();
                                if(numberTemp){
                                    nameTemp = edk::String::strCat("key_",numberTemp);edkEnd();
                                    if(nameTemp){

                                        //create the child
                                        if(xml->addSelectedNextChild(nameTemp)){
                                            if(xml->selectChild(nameTemp)){
                                                //add the second attribute
                                                xml->addSelectedNextAttribute("second",this->tree.getSecond(i));edkEnd();
                                                //write the size
                                                xml->addSelectedNextAttribute("actionsSize",sizeSecond);edkEnd();
                                                for(edk::uint32 j=0u;j<sizeSecond;j++){
                                                    temp = this->tree.getActionInPosition(i,j);edkEnd();
                                                    if(temp){
                                                        //save the action
                                                        temp->writeToXML(xml,j);edkEnd();
                                                    }
                                                }

                                                //then select the father
                                                xml->selectFather();edkEnd();
                                            }
                                        }
                                        delete[] nameTemp;edkEnd();
                                    }
                                    delete[] numberTemp;edkEnd();
                                }
                            }
                        }

                        //then select the father
                        xml->selectFather();edkEnd();
                    }
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::animation::ActionGroup::readFromXML(edk::XML* xml,edk::uint32 id,edk::classID thisPointer){
    bool ret=false;edkEnd();
    if(xml){
        this->clean();edkEnd();
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("ActionGroup_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //create the animations
                    this->anim.readFromXML(xml,0u);edkEnd();

                    //get size of actions
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("keySize"));edkEnd();
                    if(size){
                        edk::uint32 sizeSecond;edkEnd();
                        edk::float32 second;edkEnd();
                        edk::ActionZero action;edkEnd();
                        edk::Action* actionTemp;edkEnd();
                        edk::char8* nameTemp;edkEnd();
                        edk::char8* numberTemp;edkEnd();
                        //get the actions
                        for(edk::uint32 i=0u;i<size;i++){
                            numberTemp = edk::String::uint32ToStr(i);edkEnd();
                            if(numberTemp){
                                nameTemp = edk::String::strCat("key_",numberTemp);edkEnd();
                                if(nameTemp){
                                    //create the child
                                    if(xml->selectChild(nameTemp)){

                                        //read the second
                                        second = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("second"));edkEnd();
                                        //read the size
                                        sizeSecond = edk::String::strToInt64(xml->getSelectedAttributeValueByName("actionsSize"));edkEnd();
                                        for(edk::uint32 j=0u;j<sizeSecond;j++){
                                            //load the action
                                            action.readFromXML(xml,j);edkEnd();
                                            //add the new action to the second
                                            actionTemp = this->readXMLAction(thisPointer,action.getCode());edkEnd();
                                            if(actionTemp){
                                                actionTemp->readFromXML(xml,j);edkEnd();
                                                this->addAction(second,actionTemp);edkEnd();
                                            }
                                        }
                                        //then select the father
                                        xml->selectFather();edkEnd();
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] numberTemp;edkEnd();
                            }
                        }
                    }
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//set readXMLaction funcion
bool edk::animation::ActionGroup::setReadXMLActionFunction(edk::Action*(*readXMLAction)(edk::classID thisPointer,edk::uint32 actionCode)){
    if(readXMLAction){
        //set the functio
        this->readXMLAction = readXMLAction;edkEnd();
        return true;
    }
    return false;
}

//clean readXMLAction function
void edk::animation::ActionGroup::cleanReadXMLActionFunction(){
    this->setReadXMLActionFunction(&this->readXMLZero);edkEnd();
}

//cand delete
void edk::animation::ActionGroup::cantDeleteGroup(){
    this->canDeleteGroup=false;edkEnd();
}
