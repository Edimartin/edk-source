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
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::Path1DGroup::~Path1DGroup(){
    this->Destructor();
}

void edk::animation::Path1DGroup::Constructor(){
    edk::animation::PathGroup::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->x = 0.f;
        this->incrementX=0.f;
        this->incrementXValue=0.f;
    }
}
void edk::animation::Path1DGroup::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::animation::PathGroup::Destructor();
}

//create the frame
edk::animation::Frame* edk::animation::Path1DGroup::newFrame(){
    return (edk::animation::Frame*)new edk::animation::Frame1D;
}
//return true if the value reach the frame position
bool edk::animation::Path1DGroup::reachFrame(edk::animation::Frame* frame){

    bool ret=false;
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)frame;
    //calculate the distance between the temp and the last
    edk::float32 distance = edk::Math::module(this->getXNoIncrement() - temp->x);
    if(distance<this->closerDistance
            ){
        if(this->saveStep>=1.f){
            ret=true;
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
                ret = true;
            }
        }
    }
    else{
        //test if the distance is bigger than last distance
        if(distance > this->lastDist){
            //
            if(this->saveStep>=1.f){
                ret=true;
            }
        }
    }
    //save distance
    this->lastDist = distance;

    this->changeFrame=false;
    return ret;
}

//increment functions to run the increment for the values
void edk::animation::Path1DGroup::runIncrementForward(){
    edk::animation::PathGroup::runIncrementForward();
    //run the increment value
    this->incrementX+=this->incrementXValue;
}
void edk::animation::Path1DGroup::runIncrementRewind(){
    edk::animation::PathGroup::runIncrementRewind();
    //run the increment value
    this->incrementX-=this->incrementXValue;
}
void edk::animation::Path1DGroup::cleanIncrement(){
    edk::animation::PathGroup::cleanIncrement();
    //clean the increment value
    this->incrementX = this->incrementXValue = 0.f;
}
void edk::animation::Path1DGroup::startIncrement(){
    edk::animation::PathGroup::startIncrement();
    this->incrementX = 0.f;
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();
    if(size){
        edk::animation::Frame1D* temp =
                (edk::animation::Frame1D*)this->animations.get(size-1u);
        if(temp){
            this->incrementXValue = temp->x;
        }
    }
}

void edk::animation::Path1DGroup::setXNoDecrement(edk::float32 x){
    this->x=x;
}
edk::float32 edk::animation::Path1DGroup::getXNoIncrement(){
    return x;
}

//add a new frame
bool edk::animation::Path1DGroup::addNewFrame(edk::float32 seconds,edk::float32 x){
    //create a new frame
    edk::animation::Frame1D* frame = (edk::animation::Frame1D*)this->newFrame();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrame(frame)){
            //set the frame values
            frame->second = seconds;
            frame->x = x;
            return true;
        }
        //else delete the frame
        delete frame;
    }
    return false;
}
//add a new frame to the position
bool edk::animation::Path1DGroup::addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x){
    //create a new frame
    edk::animation::Frame1D* frame = (edk::animation::Frame1D*)this->newFrame();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrameToPosition(position,frame)){
            //set the frame values
            frame->second = seconds;
            frame->x = x;
            return true;
        }
        //else delete the frame
        delete frame;
    }
    return false;
}

//set the X
void edk::animation::Path1DGroup::setX(edk::float32 x){
    this->x=x - this->incrementX;
}
//get the X
edk::float32 edk::animation::Path1DGroup::getX(){
    return this->x + this->incrementX;
}

//update the clock animation
edk::float32 edk::animation::Path1DGroup::updateClockAnimation(){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation();
    //load the frame
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->animations.get(this->animationPosition);
    edk::animation::Frame1D* last = (edk::animation::Frame1D*)this->getLastFrame();
    if(temp && last){
        //calculate the new position
        if(temp->second==0.f){
            this->saveStep = 1.f;
        }
        else{
            this->saveStep = (step - last->second)/(temp->second-last->second);
        }
        this->setXNoDecrement(last->x + ((temp->x - last->x) * this->saveStep));
        return step;
    }
    return 0.f;
}
edk::float32 edk::animation::Path1DGroup::updateClockAnimation(edk::float32 distance){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation(distance);
    //load the frame
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->animations.get(this->animationPosition);
    edk::animation::Frame1D* last = (edk::animation::Frame1D*)this->getLastFrame();
    if(last){
        //calculate the new position
        if(temp->second==0.f){
            this->saveStep = 1.f;
        }
        else{
            this->saveStep = (step - last->second)/(temp->second-last->second);
        }
        this->setXNoDecrement(last->x + ((temp->x - last->x) * this->saveStep));
        return step;
    }
    return 0.f;
}

//write to XML
bool edk::animation::Path1DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        edk::animation::Frame1D* tempFrame;
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            tempFrame = (edk::animation::Frame1D*)this->animations.get(i);
                            if(tempFrame){
                                tempFrame->writeToXML(xml,i);
                            }
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
bool edk::animation::Path1DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame1D frameTemp;
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
                        this->addNewFrame(frameTemp.second,frameTemp.x);
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
