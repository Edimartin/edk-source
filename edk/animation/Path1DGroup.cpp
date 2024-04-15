#include "Path1DGroup.h"

/*
Biblioteca C++ Path1DGroup - Manage one or more physics animation frames1D in Edk Game Engine
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
#pragma message "            Inside PathGroup1D.cpp"
#endif

edk::animation::Path1DGroup::Path1DGroup(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::animation::Path1DGroup::~Path1DGroup(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::animation::Path1DGroup::Constructor(bool runFather){
    if(runFather){
        edk::animation::PathGroup::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
        this->x = 0.f;edkEnd();
        this->incrementX=0.f;edkEnd();
        this->incrementXValue=0.f;edkEnd();
    }
}

//create the frame
edk::animation::Frame* edk::animation::Path1DGroup::newFrame(){
    return (edk::animation::Frame*)new edk::animation::Frame1D;edkEnd();
}
//return true if the value reach the frame position
bool edk::animation::Path1DGroup::reachFrame(edk::animation::Frame* frame){

    bool ret=false;edkEnd();
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)frame;edkEnd();
    //calculate the distance between the temp and the last
    edk::float32 distance = edk::Math::module(this->getXNoIncrement() - temp->x);edkEnd();
    if(distance<this->closerDistance
            ){
        if(this->saveStep>=1.f){
            ret=true;edkEnd();
        }
    }
    if(this->changeFrame){
        //test if reach the frame value
        if(this->getXNoIncrement()>=(temp->x-this->closerDistance)
                &&
                this->getXNoIncrement()<=(temp->x+this->closerDistance)
                ){
            //
            if(this->saveStep>=1.f){
                ret = true;edkEnd();
            }
        }
    }
    else{
        //test if the distance is bigger than last distance
        if(distance > this->lastDist){
            //
            if(this->saveStep>=1.f){
                ret=true;edkEnd();
            }
        }
    }
    //save distance
    this->lastDist = distance;edkEnd();

    this->changeFrame=false;edkEnd();
    return ret;
}

//increment functions to run the increment for the values
void edk::animation::Path1DGroup::runIncrementForward(){
    edk::animation::PathGroup::runIncrementForward();edkEnd();
    //run the increment value
    this->incrementX+=this->incrementXValue;edkEnd();
}
void edk::animation::Path1DGroup::runIncrementRewind(){
    edk::animation::PathGroup::runIncrementRewind();edkEnd();
    //run the increment value
    this->incrementX-=this->incrementXValue;edkEnd();
}
void edk::animation::Path1DGroup::cleanIncrement(){
    edk::animation::PathGroup::cleanIncrement();edkEnd();
    //clean the increment value
    this->incrementX = this->incrementXValue = 0.f;edkEnd();
}
void edk::animation::Path1DGroup::startIncrement(){
    edk::animation::PathGroup::startIncrement();edkEnd();
    this->incrementX = 0.f;edkEnd();
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::Frame1D* temp =
                (edk::animation::Frame1D*)this->animations.get(size-1u);edkEnd();
        if(temp){
            this->incrementXValue = temp->x;edkEnd();
        }
    }
}

void edk::animation::Path1DGroup::setXNoDecrement(edk::float32 x){
    this->x=x;edkEnd();
}
edk::float32 edk::animation::Path1DGroup::getXNoIncrement(){
    return x;edkEnd();
}

//add a new frame
bool edk::animation::Path1DGroup::addNewFrame(edk::float32 seconds,edk::float32 x){
    //create a new frame
    edk::animation::Frame1D* frame = (edk::animation::Frame1D*)this->newFrame();edkEnd();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrame(frame)){
            //set the frame values
            frame->second = seconds;edkEnd();
            frame->x = x;edkEnd();
            return true;
        }
        //else delete the frame
        delete frame;edkEnd();
    }
    return false;
}
//add a new frame to the position
bool edk::animation::Path1DGroup::addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x){
    //create a new frame
    edk::animation::Frame1D* frame = (edk::animation::Frame1D*)this->newFrame();edkEnd();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrameToPosition(position,frame)){
            //set the frame values
            frame->second = seconds;edkEnd();
            frame->x = x;edkEnd();
            return true;
        }
        //else delete the frame
        delete frame;edkEnd();
    }
    return false;
}

//set the X
void edk::animation::Path1DGroup::setX(edk::float32 x){
    this->x=x - this->incrementX;edkEnd();
}
//get the X
edk::float32 edk::animation::Path1DGroup::getX(){
    return this->x + this->incrementX;edkEnd();
}

//update the clock animation
edk::float32 edk::animation::Path1DGroup::updateClockAnimation(){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation();edkEnd();
    //load the frame
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->animations.get(this->animationPosition);edkEnd();
    edk::animation::Frame1D* last = (edk::animation::Frame1D*)this->getLastFrame();edkEnd();
    if(temp && last){
        //calculate the new position
        if(temp->second==0.f){
            this->saveStep = 1.f;edkEnd();
        }
        else{
            this->saveStep = (step - last->second)/(temp->second-last->second);edkEnd();
        }
        this->setXNoDecrement(last->x + ((temp->x - last->x) * this->saveStep));edkEnd();
        return step;edkEnd();
    }
    return 0.f;
}
edk::float32 edk::animation::Path1DGroup::updateClockAnimation(edk::float32 distance){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation(distance);edkEnd();
    //load the frame
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->animations.get(this->animationPosition);edkEnd();
    edk::animation::Frame1D* last = (edk::animation::Frame1D*)this->getLastFrame();edkEnd();
    if(last){
        //calculate the new position
        if(temp->second==0.f){
            this->saveStep = 1.f;edkEnd();
        }
        else{
            this->saveStep = (step - last->second)/(temp->second-last->second);edkEnd();
        }
        this->setXNoDecrement(last->x + ((temp->x - last->x) * this->saveStep));edkEnd();
        return step;edkEnd();
    }
    return 0.f;
}

//write to XML
bool edk::animation::Path1DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();edkEnd();
                        edk::animation::Frame1D* tempFrame;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            tempFrame = (edk::animation::Frame1D*)this->animations.get(i);edkEnd();
                            if(tempFrame){
                                tempFrame->writeToXML(xml,i);edkEnd();
                            }
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
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
//read XML
bool edk::animation::Path1DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame1D frameTemp;edkEnd();
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
                        this->addNewFrame(frameTemp.second,frameTemp.x);edkEnd();
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
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
