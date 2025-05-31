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
#pragma message "            Inside ActionGroup.cpp"
#endif

edk::animation::ActionGroup::ActionGroup(){
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::ActionGroup::~ActionGroup(){
    this->Destructor();
}

void edk::animation::ActionGroup::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->anim.Constructor();
        this->tree.Constructor();

        this->valueTemp=0.0;
        this->setReadXMLActionFunction(&this->readXMLZero);
    }
}
void edk::animation::ActionGroup::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        this->clean();

        this->anim.Destructor();
        this->tree.Destructor();
    }
}

//return the zero action
edk::Action* edk::animation::ActionGroup::readXMLZero(edk::classID,edk::uint32 ){
    return new edk::ActionZero();
}

//first update
void edk::animation::ActionGroup::firstUpdate(){
    if(this->anim.isPlaying()){
        //update the clock
        this->anim.updateClockAnimation();
        //get the value
        this->valueTemp = this->anim.getClockX() - 1.f;
    }
}
void edk::animation::ActionGroup::firstUpdate(edk::float32 seconds){
    if(this->anim.isPlaying()){
        //update the clock
        this->anim.updateClockAnimation(seconds);
        //get the value
        this->valueTemp = this->anim.getClockX() - 1.f;
    }
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

//get the keyFrames size
edk::uint32 edk::animation::ActionGroup::getKeySize(){
    //
    return this->tree.size();
}
//get the key second
edk::float32 edk::animation::ActionGroup::getKeySecond(edk::uint32 keyPosition){
    //
    return this->tree.getSecond(keyPosition);
}
//get the actions size in position
edk::uint32 edk::animation::ActionGroup::getActionsSize(edk::uint32 keyPosition){
    //
    return this->tree.getActionSizeInPosition(keyPosition);
}
//return the action code
edk::uint32 edk::animation::ActionGroup::getActionCode(edk::uint32 keyPosition,edk::uint32 actionPosition){
    edk::Action* temp = this->tree.getActionInPosition(keyPosition,actionPosition);
    if(temp){
        return temp->getCode();
    }
    return 0u;
}
//return the action
edk::Action* edk::animation::ActionGroup::getActionInKey(edk::uint32 keyPosition,edk::uint32 actionPosition){
    //
    return this->tree.getActionInPosition(keyPosition,actionPosition);
}
edk::Action* edk::animation::ActionGroup::getActionInSecond(edk::float32 second,edk::uint32 actionPosition){
    //
    return this->tree.getActionInSecond(second,actionPosition);
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
        edk::float32 value = this->anim.getClockX();
        //tets if the value is diferent than the last value
        if(value!=this->valueTemp){
            //then run the actions
            //printf("\nUpdate Tree %.2f",value);
            this->tree.updateSecond(value);
            this->valueTemp = value;
        }
    }
}
void edk::animation::ActionGroup::update(edk::float32 seconds){
    if(this->anim.isPlaying()){
        //update the clock
        this->anim.updateClockAnimation(seconds);
        //get the value
        edk::float32 value = this->anim.getClockX();
        //tets if the value is diferent than the last value
        if(value!=this->valueTemp){
            //then run the actions
            //printf("\nUpdate Tree %.2f",value);
            this->tree.updateSecond(value);
            this->valueTemp = value;
        }
    }
}

//ANIMATION FUNCTIONS
//get Loop
bool edk::animation::ActionGroup::isLooping(){return this->anim.getLoop();}

//CONTROLS
//animation controllers
void edk::animation::ActionGroup::playForward(){
    this->anim.playForward();
    this->firstUpdate();
}
void edk::animation::ActionGroup::playForwardIn(edk::float32 second){
    this->anim.playForwardIn(second);
    this->firstUpdate();
}
void edk::animation::ActionGroup::playForward(edk::float32 updateSeconds){
    this->anim.playForward();
    this->firstUpdate(updateSeconds);
}
void edk::animation::ActionGroup::playForwardIn(edk::float32 second,edk::float32 updateSeconds){
    this->anim.playForwardIn(second);
    this->firstUpdate(updateSeconds);
}
//void edk::animation::ActionGroup::playRewind(){this->anim.playRewind();}
//void edk::animation::ActionGroup::playRewindIn(edk::float32 second){this->anim.playRewindIn(second);}
void edk::animation::ActionGroup::pause(){this->anim.pause();}
void edk::animation::ActionGroup::pauseOn(){this->anim.pauseOn();}
void edk::animation::ActionGroup::pauseOff(){this->anim.pauseOff();}
void edk::animation::ActionGroup::stop(){this->anim.stop();}
//set loop
void edk::animation::ActionGroup::setLoop(bool loop){this->anim.setLoop(loop);}
void edk::animation::ActionGroup::loopOn(){this->anim.loopOn();}
void edk::animation::ActionGroup::loopOff(){this->anim.loopOff();}

//return if are playing
bool edk::animation::ActionGroup::isPlaying(){return this->anim.isPlaying();}
bool edk::animation::ActionGroup::isPaused(){return this->isPaused();}

bool edk::animation::ActionGroup::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("ActionGroup_",number);
            if(name){
                //create the Action
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //create the animations
                        this->anim.writeToXML(xml,0u);

                        //get size of tree
                        edk::uint32 size = this->tree.size();

                        //add the size
                        xml->addSelectedNextAttribute("keySize",size);
                        if(size){
                            edk::uint32 sizeSecond;
                            edk::Action* temp;
                            edk::char8* nameTemp;
                            edk::char8* numberTemp;
                            //get the actions
                            for(edk::uint32 i=0u;i<size;i++){
                                sizeSecond = this->tree.getActionSizeInPosition(i);
                                numberTemp = edk::String::uint32ToStr(i);
                                if(numberTemp){
                                    nameTemp = edk::String::strCat("key_",numberTemp);
                                    if(nameTemp){

                                        //create the child
                                        if(xml->addSelectedNextChild(nameTemp)){
                                            if(xml->selectChild(nameTemp)){
                                                //add the second attribute
                                                xml->addSelectedNextAttribute("second",this->tree.getSecond(i));
                                                //write the size
                                                xml->addSelectedNextAttribute("actionsSize",sizeSecond);
                                                for(edk::uint32 j=0u;j<sizeSecond;j++){
                                                    temp = this->tree.getActionInPosition(i,j);
                                                    if(temp){
                                                        //save the action
                                                        temp->writeToXML(xml,j);
                                                    }
                                                }

                                                //then select the father
                                                xml->selectFather();
                                            }
                                        }
                                        free(nameTemp);
                                    }
                                    free(numberTemp);
                                }
                            }
                        }

                        //then select the father
                        xml->selectFather();
                    }
                }
                free(name);
            }
            free(number);
        }
    }
    return ret;
}
//read XML
bool edk::animation::ActionGroup::readFromXML(edk::XML* xml,edk::uint32 id,edk::classID thisPointer){
    bool ret=false;
    if(xml){
        this->clean();
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("ActionGroup_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //create the animations
                    this->anim.readFromXML(xml,0u);

                    //get size of actions
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("keySize"));
                    if(size){
                        edk::uint32 sizeSecond;
                        edk::float32 second;
                        edk::ActionZero action;
                        edk::Action* actionTemp;
                        edk::char8* nameTemp;
                        edk::char8* numberTemp;
                        //get the actions
                        for(edk::uint32 i=0u;i<size;i++){
                            numberTemp = edk::String::uint32ToStr(i);
                            if(numberTemp){
                                nameTemp = edk::String::strCat("key_",numberTemp);
                                if(nameTemp){
                                    //create the child
                                    if(xml->selectChild(nameTemp)){

                                        //read the second
                                        second = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("second"));
                                        //read the size
                                        sizeSecond = edk::String::strToInt64(xml->getSelectedAttributeValueByName("actionsSize"));
                                        for(edk::uint32 j=0u;j<sizeSecond;j++){
                                            //load the action
                                            action.readFromXML(xml,j);
                                            //add the new action to the second
                                            actionTemp = this->readXMLAction(thisPointer,action.getCode());
                                            if(actionTemp){
                                                actionTemp->readFromXML(xml,j);
                                                this->addAction(second,actionTemp);
                                            }
                                        }
                                        //then select the father
                                        xml->selectFather();
                                    }
                                    free(nameTemp);
                                }
                                free(numberTemp);
                            }
                        }
                    }
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    return ret;
}
//set readXMLaction funcion
bool edk::animation::ActionGroup::setReadXMLActionFunction(edk::Action*(*readXMLAction)(edk::classID thisPointer,edk::uint32 actionCode)){
    if(readXMLAction){
        //set the functio
        this->readXMLAction = readXMLAction;
        return true;
    }
    return false;
}

//clean readXMLAction function
void edk::animation::ActionGroup::cleanReadXMLActionFunction(){
    this->setReadXMLActionFunction(&this->readXMLZero);
}
