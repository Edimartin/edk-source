#include "Path2DGroup.h"

/*
Biblioteca C++ Path2DGroup - Manage one or more physics animation frames2D in Edk Game Engine
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
#warning "            Inside PathGroup2D.cpp"
#endif

edk::animation::Path2DGroup::Path2DGroup()
{
    this->y=0.f;edkEnd();
    this->incrementY=0.f;edkEnd();
    this->incrementYValue=0.f;edkEnd();
}
//create the frame
edk::animation::Frame* edk::animation::Path2DGroup::newFrame(){
    return (edk::animation::Frame*)new edk::animation::Frame2D;edkEnd();
}
//return true if the value reach the frame position
bool edk::animation::Path2DGroup::reachFrame(edk::animation::Frame* frame){
    bool ret=false;edkEnd();
    edk::animation::Frame2D* temp = (edk::animation::Frame2D*)frame;edkEnd();
    //calculate the distance between the temp and the last
    edk::float32 distance = edk::Math::pythagoras(edk::vec2f32(this->getXNoIncrement() - temp->x,this->getYNoIncrement() - temp->y));edkEnd();
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
                &&
                this->getYNoIncrement()>=(temp->y-this->closerDistance)
                &&
                this->getYNoIncrement()<=(temp->y+this->closerDistance)
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
void edk::animation::Path2DGroup::runIncrementForward(){
    edk::animation::Path1DGroup::runIncrementForward();edkEnd();
    //run the increment value
    this->incrementY+=this->incrementYValue;edkEnd();
}
void edk::animation::Path2DGroup::runIncrementRewind(){
    edk::animation::Path1DGroup::runIncrementRewind();edkEnd();
    //run the increment value
    this->incrementY-=this->incrementYValue;edkEnd();
}
void edk::animation::Path2DGroup::cleanIncrement(){
    edk::animation::Path1DGroup::cleanIncrement();edkEnd();
    //clean the increment value
    this->incrementY = this->incrementYValue = 0.f;edkEnd();
}
void edk::animation::Path2DGroup::startIncrement(){
    edk::animation::Path1DGroup::startIncrement();edkEnd();
    this->incrementY = 0.f;edkEnd();
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::Frame2D* temp =
                (edk::animation::Frame2D*)this->animations.get(size-1u);edkEnd();
        if(temp){
            this->incrementYValue = temp->y;edkEnd();
        }
    }
}

void edk::animation::Path2DGroup::setYNoDecrement(edk::float32 y){
    this->y=y;edkEnd();
}
edk::float32 edk::animation::Path2DGroup::getYNoIncrement(){
    return this->y;edkEnd();
}

//add a new frame
bool edk::animation::Path2DGroup::addNewFrame(edk::float32 seconds,edk::float32 x,edk::float32 y){
    //create a new frame
    edk::animation::Frame2D* frame = (edk::animation::Frame2D*)this->newFrame();edkEnd();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrame(frame)){
            //set the frame values
            frame->second = seconds;edkEnd();
            frame->x = x;edkEnd();
            frame->y = y;edkEnd();
            return true;
        }
        //else delete the frame
        delete frame;edkEnd();
    }
    return false;
}
//add a new frame to the position
bool edk::animation::Path2DGroup::addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x,edk::float32 y){
    //create a new frame
    edk::animation::Frame2D* frame = (edk::animation::Frame2D*)this->newFrame();edkEnd();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrameToPosition(position,frame)){
            //set the frame values
            frame->second = seconds;edkEnd();
            frame->x = x;edkEnd();
            frame->y = y;edkEnd();
            return true;
        }
        //else delete the frame
        delete frame;edkEnd();
    }
    return false;
}

//set the Y
void edk::animation::Path2DGroup::setY(edk::float32 y){
    this->y=y - this->incrementY;edkEnd();
}

//get the Y
edk::float32 edk::animation::Path2DGroup::getY(){
    return this->y - this->incrementY;edkEnd();
}

//update the clock animation
edk::float32 edk::animation::Path2DGroup::updateClockAnimation(){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation();edkEnd();
    //load the frame
    edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->animations[this->animationPosition];edkEnd();
    edk::animation::Frame2D* last = (edk::animation::Frame2D*)this->getLastFrame();edkEnd();
    if(last){
        //calculate the new position
        if(temp->second==0.f){
            this->saveStep = 1.f;edkEnd();
        }
        else{
            this->saveStep = (step - last->second)/(temp->second-last->second);edkEnd();
        }
        this->setXNoDecrement(last->x + ((temp->x - last->x) * this->saveStep));edkEnd();
        this->setYNoDecrement( last->y + ((temp->y - last->y) * this->saveStep));edkEnd();
        return step;edkEnd();
    }
    else{
        return 0.f;edkEnd();
    }
}
edk::float32 edk::animation::Path2DGroup::updateClockAnimation(edk::float32 distance){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation(distance);edkEnd();
    //load the frame
    edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->animations[this->animationPosition];edkEnd();
    edk::animation::Frame2D* last = (edk::animation::Frame2D*)this->getLastFrame();edkEnd();
    if(last){
        //calculate the new position
        if(temp->second==0.f){
            this->saveStep = 1.f;edkEnd();
        }
        else{
            this->saveStep = (step - last->second)/(temp->second-last->second);edkEnd();
        }
        this->setXNoDecrement(last->x + ((temp->x - last->x) * this->saveStep));edkEnd();
        this->setYNoDecrement(last->y + ((temp->y - last->y) * this->saveStep));edkEnd();
        return step;edkEnd();
    }
    else{
        return 0.f;edkEnd();
    }
}

//write to XML
bool edk::animation::Path2DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::animation::Frame2D* tempFrame;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            tempFrame = (edk::animation::Frame2D*)this->animations[i];edkEnd();
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
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        return ret;
    }
    return false;
}
//read XML
bool edk::animation::Path2DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame2D frameTemp;edkEnd();
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
                        this->addNewFrame(frameTemp.second,frameTemp.x,frameTemp.y);edkEnd();
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
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        return ret;
    }
    return false;
}
