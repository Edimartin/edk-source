#include "Interpolation3DGroup.h"

/*
Library C++ InterpolationGroup3D - Manage one or more interpolations with tree values in Edk Game Engine
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
#pragma message "            Inside Interpolation3DGroup.cpp"
#endif

edk::animation::Interpolation3DGroup::Interpolation3DGroup()
{
    //ctor
    this->incrementZ=0.f;edkEnd();
    this->incrementZValue=0.f;edkEnd();
}

edk::animation::Interpolation3DGroup::~Interpolation3DGroup()
{
    //dtor
}


//create the interpolation
edk::animation::InterpolationLine* edk::animation::Interpolation3DGroup::newLineInterpolation(){
    //
    return (edk::animation::InterpolationLine*)(new edk::animation::InterpolationLine3D());edkEnd();
}
//create the frame
edk::animation::Frame* edk::animation::Interpolation3DGroup::newFrame(){
    //
    return (edk::animation::Frame*)(new edk::animation::Frame3D());edkEnd();
}
//print the frame
void edk::animation::Interpolation3DGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //
    if(interpolation){
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)interpolation;edkEnd();
        printf("Start second %.4f X %.4f Y %.4f Z %.4f end second %.4f X %.4f Y %.4f Z %.4f"
               ,temp->getStart3D().second
               ,temp->getStart3D().x
               ,temp->getStart3D().y
               ,temp->getStart3D().z
               ,temp->getEnd3D().second
               ,temp->getEnd3D().x
               ,temp->getEnd3D().y
               ,temp->getEnd3D().z
               );edkEnd();
    }
}

//copy interpolation frame
void edk::animation::Interpolation3DGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine3D* f = (edk::animation::InterpolationLine3D*) first;edkEnd();
    edk::animation::InterpolationLine3D* s = (edk::animation::InterpolationLine3D*) second;edkEnd();
    s->setStart(f->getStart3D().second,f->getStart3D().x,f->getStart3D().y,f->getStart3D().z);edkEnd();
}
void edk::animation::Interpolation3DGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine3D* f = (edk::animation::InterpolationLine3D*) first;edkEnd();
    edk::animation::InterpolationLine3D* s = (edk::animation::InterpolationLine3D*) second;edkEnd();
    s->setEnd(f->getEnd3D().second,f->getEnd3D().x,f->getEnd3D().y,f->getEnd3D().z);edkEnd();
}

//increment functions to run the increment for the values
void edk::animation::Interpolation3DGroup::runIncrementForward(){
    edk::animation::Interpolation2DGroup::runIncrementForward();edkEnd();
    //run the increment value
    this->incrementZ+=this->incrementZValue;edkEnd();
}
void edk::animation::Interpolation3DGroup::runIncrementRewind(){
    edk::animation::Interpolation2DGroup::runIncrementRewind();edkEnd();
    //run the increment value
    this->incrementZ-=this->incrementZValue;edkEnd();
}
void edk::animation::Interpolation3DGroup::cleanIncrement(){
    edk::animation::Interpolation2DGroup::cleanIncrement();edkEnd();
    //clean the increment value
    this->incrementZ = 0.f;edkEnd();
}
void edk::animation::Interpolation3DGroup::startIncrement(){
    edk::animation::Interpolation2DGroup::startIncrement();edkEnd();
    this->incrementZ = 0.f;edkEnd();
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::InterpolationLine3D* temp =
                (edk::animation::InterpolationLine3D*)this->animations.get(size-1u);edkEnd();
        if(temp){
            this->incrementZValue = temp->getEnd3D().z;edkEnd();
        }
    }
}

//Add a first interpolation
bool edk::animation::Interpolation3DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 startZ,
                                                                     edk::float32 endSecond,edk::float32 endX,edk::float32 endY,edk::float32 endZ){
    //
    return this->addFirstInterpolationLine(startSecond, edk::vec3f32(startX,startY,startZ), endSecond, edk::vec3f32(endX,endY,endZ));edkEnd();
}
bool edk::animation::Interpolation3DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::vec3f32 startValue, edk::float32 endSecond, edk::vec3f32 endValue){
    //
    return this->addFirstInterpolationLine(edk::animation::Frame3D(startSecond,startValue),edk::animation::Frame3D(endSecond,endValue));edkEnd();
}
bool edk::animation::Interpolation3DGroup::addFirstInterpolationLine(edk::animation::Frame3D start,edk::animation::Frame3D end){
    //first create the frame
    if(edk::animation::InterpolationGroup::addFirstInterpolationLine((edk::animation::Frame)start,(edk::animation::Frame)end)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->tempInterpolation;edkEnd();
        if(temp){
            //
            temp->setStartValue(start.x,start.y,start.z);edkEnd();
            temp->setEndValue(end.x,end.y,end.z);edkEnd();
        }
        //return true
        return true;
    }
    //else return false
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation3DGroup::addNewInterpolationLine(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z){
    //
    return this->addNewInterpolationLine(second,edk::vec3f32(x,y,z));edkEnd();
}
bool edk::animation::Interpolation3DGroup::addNewInterpolationLine(edk::float32 second,edk::vec3f32 value){
    //
    return this->addNewInterpolationLine(edk::animation::Frame3D(second,value));edkEnd();
}
bool edk::animation::Interpolation3DGroup::addNewInterpolationLine(edk::animation::Frame3D frame){
    //first create the frame
    if(edk::animation::InterpolationGroup::addNewInterpolationLine((edk::animation::Frame)frame)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->tempInterpolation;edkEnd();
        if(temp){
            //test if set start or end
            if(this->setStart){
                //
                temp->setStartValue(frame.x,frame.y,frame.z);edkEnd();
            }
            else{
                //
                temp->setEndValue(frame.x,frame.y,frame.z);edkEnd();
                //test if have a tempFrame
                edk::animation::Frame3D* frameTemp = (edk::animation::Frame3D*)this->tempFrame;edkEnd();
                if(frameTemp){
                    //
                    temp->setStartValue(frameTemp->x,frameTemp->y,frameTemp->z);edkEnd();
                }
                else if(this->setfirstInterpolation){
                    temp->setStartValue(tempX,tempY,tempZ);edkEnd();
                }
            }
        }
        else{
            //test if have a tempFrame
            edk::animation::Frame3D* frameTemp = (edk::animation::Frame3D*)this->tempFrame;edkEnd();
            if(frameTemp){
                //
                frameTemp->x=frame.x;edkEnd();
                frameTemp->y=frame.y;edkEnd();
                frameTemp->z=frame.z;edkEnd();
                this->tempX = frame.x;edkEnd();
                this->tempY = frame.y;edkEnd();
                this->tempZ = frame.z;edkEnd();
            }
        }
        //clean the tempInterpolation
        //this->tempInterpolation=NULL;edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}

//Set the frame value
bool edk::animation::Interpolation3DGroup::setFrame3D(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->frameSelected;edkEnd();
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(x,y,z);edkEnd();
            }
            else{
                temp->setEndValue(x,y,z);edkEnd();
            }
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::setFrameZ(edk::float32 second,edk::float32 z){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->frameSelected;edkEnd();
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                edk::animation::Frame2D frame = temp->getStart2D();edkEnd();
                temp->setStartValue(frame.x,frame.y,z);edkEnd();
            }
            else{
                edk::animation::Frame2D frame = temp->getEnd2D();edkEnd();
                temp->setEndValue(frame.x,frame.y,z);edkEnd();
            }
            return true;
        }
    }
    else{
        //test if have the temp animation
        if(this->tempFrame){
            edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->tempFrame;edkEnd();
            //test if temp frame have the second
            if(temp->second == second){
                temp->z = z;edkEnd();
            }
        }
    }
    return false;
}

//Set one interpolation Y as a curve
bool edk::animation::Interpolation3DGroup::setInterpolationCurveZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            temp->isCurveZ();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::setInterpolationNotCurveZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            //test if is a curve
            if(!temp->getCurveZ()){
                //set as curve
                temp->isCurveZ();edkEnd();
            }
            temp->isNotCurveZ();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::getInterpolationIsCurveZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            return temp->getCurveZ();edkEnd();
        }
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation3DGroup::setConstantZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            temp->setConstantZ();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::setLinearZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            temp->setLinearZ();edkEnd();
            return true;
        }
    }
    return false;
}
//set all as constant interpolation
void edk::animation::Interpolation3DGroup::setAllConstantZ(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::InterpolationLine3D* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine3D*)this->animations[i];edkEnd();
        temp->setConstantZ();edkEnd();
    }
}
void edk::animation::Interpolation3DGroup::setAllLinearZ(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::InterpolationLine3D* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine3D*)this->animations[i];edkEnd();
        temp->setLinearZ();edkEnd();
    }
}

//Set the interpolation curve points
bool edk::animation::Interpolation3DGroup::setInterpolationP1Z(edk::uint32 position,edk::float32 second,edk::float32 z){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            return temp->setP1Z(second,z);edkEnd();
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::setInterpolationP2Z(edk::uint32 position,edk::float32 second,edk::float32 z){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            return temp->setP2Z(second,z);edkEnd();
        }
    }
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation3DGroup::getClockZ(){
    //test if is playing
    if(this->isPlaying()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)edk::animation::InterpolationGroup::getSelectedInterpolation();edkEnd();
        //load the position
        if(temp){
            //
            return temp->getPositionZ(this->animationSecond) + this->incrementZ;edkEnd();
        }
    }
    //else return 0.0f;edkEnd();
    return 0.0f;edkEnd();
}
//return the interpolation Z
edk::float32 edk::animation::Interpolation3DGroup::getInterpolationStartZ(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            return temp->getStart3D().z;edkEnd();
        }
    }
    return 0u;edkEnd();
}
edk::float32 edk::animation::Interpolation3DGroup::getInterpolationEndZ(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];edkEnd();
        if(temp){
            return temp->getStart3D().z;edkEnd();
        }
    }
    return 0u;edkEnd();
}
//return the animation start and end in Z
edk::float32 edk::animation::Interpolation3DGroup::getAnimationStartZ(){
    if(this->animations.size()){
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[0u];edkEnd();
        if(temp){
            return temp->getStart3D().z;edkEnd();
        }
    }
    return 0.f;
}
edk::float32 edk::animation::Interpolation3DGroup::getAnimationEndZ(){
    if(this->animations.size()){
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[this->animations.size()-1u];edkEnd();
        if(temp){
            return temp->getEnd3D().z;edkEnd();
        }
    }
    return 0.f;
}
//write to XML
bool edk::animation::Interpolation3DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::uint32 count = 0u;edkEnd();
                        edk::animation::InterpolationLine3D* temp = NULL;edkEnd();
                        edk::animation::Frame3D* frameTemp=(edk::animation::Frame3D*)this->tempFrame;edkEnd();
                        if(frameTemp){
                            //add the tempFrame
                            frameTemp->writeToXML(xml,count);edkEnd();
                            count++;edkEnd();
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine3D*)this->animations[i];edkEnd();
                            if(temp){
                                if(!i){
                                    //write the first
                                    temp->writeToXMLStart(xml,count);edkEnd();
                                    count++;edkEnd();
                                }
                                temp->writeToXMLEnd(xml,count);edkEnd();
                                count++;edkEnd();
                            }
                        }
                        //write the curvers
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine3D*)this->animations[i];edkEnd();
                            if(temp){
                                temp->writeCurveToXML(xml,i);edkEnd();
                            }
                        }
                        //write the animationNames
                        size = this->animationNames.size();edkEnd();
                        edk::animation::AnimationName *animationTemp = NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            animationTemp = (edk::animation::AnimationName *)this->animationNames.getElementInPosition(i);edkEnd();
                            if(animationTemp){
                                animationTemp->writeToXML(xml,i);edkEnd();
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
bool edk::animation::Interpolation3DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::uint32 count = 0u;edkEnd();
                    edk::animation::Frame3D frameTemp;edkEnd();
                    edk::animation::InterpolationLine3D* interpolationTemp=NULL;edkEnd();
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
                    edk::uint32 size = this->animations.size();edkEnd();
                    //read the curves
                    for(edk::uint32 i=0u;i<size;i++){
                        //read the XML
                        interpolationTemp = (edk::animation::InterpolationLine3D*)this->animations[i];edkEnd();
                        if(interpolationTemp){
                            interpolationTemp->readCurveFromXML(xml,i);edkEnd();
                        }
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
