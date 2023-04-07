#include "Path3DGroup.h"

/*
Biblioteca C++ Path3DGroup - Manage one or more physics animation frames3D in Edk Game Engine
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
#pragma message "            Inside PathGroup3D.cpp"
#endif

edk::animation::Path3DGroup::Path3DGroup()
{
    this->z=0.f;edkEnd();
    this->incrementZ=0.f;edkEnd();
    this->incrementZValue=0.f;edkEnd();
}
//create the frame
edk::animation::Frame* edk::animation::Path3DGroup::newFrame(){
    return (edk::animation::Frame*)new edk::animation::Frame3D;edkEnd();
}
//return true if the value reach the frame position
bool edk::animation::Path3DGroup::reachFrame(edk::animation::Frame* frame){
    bool ret=false;edkEnd();
    edk::animation::Frame3D* temp = (edk::animation::Frame3D*)frame;edkEnd();
    //calculate the distance between the temp and the last
    edk::float32 distance = edk::Math::pythagoras(edk::vec3f32(this->getXNoIncrement() - temp->x,
                                                                 this->getYNoIncrement() - temp->y,
                                                                 this->getZNoIncrement() - temp->z
                                                                 )
                                                    );edkEnd();
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
                &&
                this->getZNoIncrement()>=(temp->z-this->closerDistance)
                &&
                this->getZNoIncrement()<=(temp->z+this->closerDistance)
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
void edk::animation::Path3DGroup::runIncrementForward(){
    edk::animation::Path2DGroup::runIncrementForward();edkEnd();
    //run the increment value
    this->incrementZ+=this->incrementZValue;edkEnd();
}
void edk::animation::Path3DGroup::runIncrementRewind(){
    edk::animation::Path2DGroup::runIncrementRewind();edkEnd();
    //run the increment value
    this->incrementZ-=this->incrementZValue;edkEnd();
}
void edk::animation::Path3DGroup::cleanIncrement(){
    edk::animation::Path2DGroup::cleanIncrement();edkEnd();
    //clean the increment value
    this->incrementZ = this->incrementZValue = 0.f;edkEnd();
}
void edk::animation::Path3DGroup::startIncrement(){
    edk::animation::Path2DGroup::startIncrement();edkEnd();
    this->incrementZ = 0.f;edkEnd();
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::Frame3D* temp =
                (edk::animation::Frame3D*)this->animations.get(size-1u);edkEnd();
        if(temp){
            this->incrementZValue = temp->y;edkEnd();
        }
    }
}

void edk::animation::Path3DGroup::setZNoDecrement(edk::float32 z){
    this->z=z;edkEnd();
}
edk::float32 edk::animation::Path3DGroup::getZNoIncrement(){
    return this->z;edkEnd();
}

//add a new frame
bool edk::animation::Path3DGroup::addNewFrame(edk::float32 seconds,edk::float32 x,edk::float32 y,edk::float32 z){
    //create a new frame
    edk::animation::Frame3D* frame = (edk::animation::Frame3D*)this->newFrame();edkEnd();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrame(frame)){
            //set the frame values
            frame->second = seconds;edkEnd();
            frame->x=x;edkEnd();
            frame->y=y;edkEnd();
            frame->z=z;edkEnd();
            return true;
        }
        //else delete the frame
        delete frame;edkEnd();
    }
    return false;
}
//add a new frame to the position
bool edk::animation::Path3DGroup::addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x,edk::float32 y,edk::float32 z){
    //create a new frame
    edk::animation::Frame3D* frame = (edk::animation::Frame3D*)this->newFrame();edkEnd();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrameToPosition(position,frame)){
            //set the frame values
            frame->second = seconds;edkEnd();
            frame->x=x;edkEnd();
            frame->y=y;edkEnd();
            frame->z=z;edkEnd();
            return true;
        }
        //else delete the frame
        delete frame;edkEnd();
    }
    return false;
}

//set the Z
void edk::animation::Path3DGroup::setZ(edk::float32 z){
    this->z=z - this->incrementZ;edkEnd();
}
//get the Z
edk::float32 edk::animation::Path3DGroup::getZ(){
    return this->z + this->incrementZ;edkEnd();
}

//update the clock animation
edk::float32 edk::animation::Path3DGroup::updateClockAnimation(){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation();edkEnd();
    //load the frame
    edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->animations[this->animationPosition];edkEnd();
    edk::animation::Frame3D* last = (edk::animation::Frame3D*)this->getLastFrame();edkEnd();
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
        this->setZNoDecrement( last->z + ((temp->z - last->z) * this->saveStep));edkEnd();
        return step;edkEnd();
    }
    else{
        return 0.f;
    }
}
edk::float32 edk::animation::Path3DGroup::updateClockAnimation(edk::float32 distance){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation(distance);edkEnd();
    //load the frame
    edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->animations[this->animationPosition];edkEnd();
    edk::animation::Frame3D* last = (edk::animation::Frame3D*)this->getLastFrame();edkEnd();
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
        this->setZNoDecrement( last->z + ((temp->z - last->z) * this->saveStep));edkEnd();
        return step;edkEnd();
    }
    else{
        return 0.f;
    }
}

//write to XML
bool edk::animation::Path3DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::animation::Frame3D* tempFrame;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            tempFrame = (edk::animation::Frame3D*)this->animations[i];edkEnd();
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
bool edk::animation::Path3DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame3D frameTemp;edkEnd();
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
                        this->addNewFrame(frameTemp.second,frameTemp.x,frameTemp.y,frameTemp.z);edkEnd();
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
