#include "Interpolation4DGroup.h"

/*
Library C++ InterpolationGroup4D - Manage one or more interpolations with tree values in Edk Game Engine
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
#pragma message "            Inside Interpolation4DGroup.cpp"
#endif

edk::animation::Interpolation4DGroup::Interpolation4DGroup(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::animation::Interpolation4DGroup::~Interpolation4DGroup(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::animation::Interpolation4DGroup::Constructor(bool runFather){
    if(runFather){
        Interpolation3DGroup::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
        //ctor
        this->incrementW=0.f;edkEnd();
        this->incrementWValue=0.f;edkEnd();
    }
}

//create the interpolation
edk::animation::InterpolationLine* edk::animation::Interpolation4DGroup::newLineInterpolation(){
    //
    return (edk::animation::InterpolationLine*)(new edk::animation::InterpolationLine4D());edkEnd();
}
//create the frame
edk::animation::Frame* edk::animation::Interpolation4DGroup::newFrame(){
    //
    return (edk::animation::Frame*)(new edk::animation::Frame4D());edkEnd();
}
//print the frame
void edk::animation::Interpolation4DGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //
    if(interpolation){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)interpolation;edkEnd();
        printf("Start second %.4f X %.4f Y %.4f Z %.4f end second %.4f X %.4f Y %.4f Z %.4f"
               ,temp->getStart4D().second
               ,temp->getStart4D().x
               ,temp->getStart4D().y
               ,temp->getStart4D().z
               ,temp->getEnd4D().second
               ,temp->getEnd4D().x
               ,temp->getEnd4D().y
               ,temp->getEnd4D().z
               );edkEnd();
    }
}

//copy interpolation frame
void edk::animation::Interpolation4DGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine4D* f = (edk::animation::InterpolationLine4D*) first;edkEnd();
    edk::animation::InterpolationLine4D* s = (edk::animation::InterpolationLine4D*) second;edkEnd();
    s->setStart(f->getStart4D().second,f->getStart4D().x,f->getStart4D().y,f->getStart4D().z,f->getStart4D().w);edkEnd();
}
void edk::animation::Interpolation4DGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine4D* f = (edk::animation::InterpolationLine4D*) first;edkEnd();
    edk::animation::InterpolationLine4D* s = (edk::animation::InterpolationLine4D*) second;edkEnd();
    s->setEnd(f->getEnd4D().second,f->getEnd4D().x,f->getEnd4D().y,f->getEnd4D().z,f->getEnd4D().w);edkEnd();
}

//increment functions to run the increment for the values
void edk::animation::Interpolation4DGroup::runIncrementForward(){
    edk::animation::Interpolation3DGroup::runIncrementForward();edkEnd();
    //run the increment value
    this->incrementW+=this->incrementWValue;edkEnd();
}
void edk::animation::Interpolation4DGroup::runIncrementRewind(){
    edk::animation::Interpolation3DGroup::runIncrementRewind();edkEnd();
    //run the increment value
    this->incrementW-=this->incrementWValue;edkEnd();
}
void edk::animation::Interpolation4DGroup::cleanIncrement(){
    edk::animation::Interpolation3DGroup::cleanIncrement();edkEnd();
    //clean the increment value
    this->incrementW = 0.f;edkEnd();
}
void edk::animation::Interpolation4DGroup::startIncrement(){
    edk::animation::Interpolation3DGroup::startIncrement();edkEnd();
    this->incrementW = 0.f;edkEnd();
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::InterpolationLine4D* temp =
                (edk::animation::InterpolationLine4D*)this->animations.get(size-1u);edkEnd();
        if(temp){
            this->incrementWValue = temp->getEnd4D().z;edkEnd();
        }
    }
}

//Add a first interpolation
bool edk::animation::Interpolation4DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 startZ, edk::float32 startW,
                                                                     edk::float32 endSecond,edk::float32 endX,edk::float32 endY,edk::float32 endZ,edk::float32 endW){
    //
    return this->addFirstInterpolationLine(startSecond, edk::vec4f32(startX,startY,startZ,startW), endSecond, edk::vec4f32(endX,endY,endZ,endW));edkEnd();
}
bool edk::animation::Interpolation4DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::vec4f32 startValue, edk::float32 endSecond, edk::vec4f32 endValue){
    //
    return this->addFirstInterpolationLine(edk::animation::Frame4D(startSecond,startValue),edk::animation::Frame4D(endSecond,endValue));edkEnd();
}
bool edk::animation::Interpolation4DGroup::addFirstInterpolationLine(edk::animation::Frame4D start,edk::animation::Frame4D end){
    //first create the frame
    if(edk::animation::InterpolationGroup::addFirstInterpolationLine((edk::animation::Frame)start,(edk::animation::Frame)end)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->tempInterpolation;edkEnd();
        if(temp){
            //
            temp->setStartValue(start.x,start.y,start.z,start.w);edkEnd();
            temp->setEndValue(end.x,end.y,end.z,end.w);edkEnd();
        }
        //return true
        return true;
    }
    //else return false
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation4DGroup::addNewInterpolationLine(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //
    return this->addNewInterpolationLine(second,edk::vec4f32(x,y,z,w));edkEnd();
}
bool edk::animation::Interpolation4DGroup::addNewInterpolationLine(edk::float32 second,edk::vec4f32 value){
    //
    return this->addNewInterpolationLine(edk::animation::Frame4D(second,value));edkEnd();
}
bool edk::animation::Interpolation4DGroup::addNewInterpolationLine(edk::animation::Frame4D frame){
    //first create the frame
    if(edk::animation::InterpolationGroup::addNewInterpolationLine((edk::animation::Frame)frame)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->tempInterpolation;edkEnd();
        if(temp){
            //test if set start or end
            if(this->setStart){
                //
                temp->setStartValue(frame.x,frame.y,frame.z,frame.w);edkEnd();
            }
            else{
                //
                temp->setEndValue(frame.x,frame.y,frame.z,frame.w);edkEnd();
                //test if have a tempFrame
                edk::animation::Frame4D* frameTemp = (edk::animation::Frame4D*)this->tempFrame;edkEnd();
                if(frameTemp){
                    //
                    temp->setStartValue(frameTemp->x,frameTemp->y,frameTemp->z,frameTemp->w);edkEnd();
                }
                else if(this->setfirstInterpolation){
                    temp->setStartValue(this->tempX,this->tempY,this->tempZ,this->tempW);edkEnd();
                }
            }
        }
        else{
            //test if have a tempFrame
            edk::animation::Frame4D* frameTemp = (edk::animation::Frame4D*)this->tempFrame;edkEnd();
            if(frameTemp){
                //
                frameTemp->x=frame.x;edkEnd();
                frameTemp->y=frame.y;edkEnd();
                frameTemp->z=frame.z;edkEnd();
                frameTemp->w=frame.w;edkEnd();
                this->tempX = frame.x;edkEnd();
                this->tempY = frame.y;edkEnd();
                this->tempZ = frame.z;edkEnd();
                this->tempW = frame.w;edkEnd();
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
bool edk::animation::Interpolation4DGroup::setFrame4D(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->frameSelected;edkEnd();
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(x,y,z,w);edkEnd();
            }
            else{
                temp->setEndValue(x,y,z,w);edkEnd();
            }
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::setFrameW(edk::float32 second,edk::float32 w){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->frameSelected;edkEnd();
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                edk::animation::Frame4D frame = temp->getStart4D();edkEnd();
                temp->setStartValue(frame.x,frame.y,frame.z,w);edkEnd();
            }
            else{
                edk::animation::Frame4D frame = temp->getEnd4D();edkEnd();
                temp->setEndValue(frame.x,frame.y,frame.z,w);edkEnd();
            }
            return true;
        }
    }
    else{
        //test if have the temp animation
        if(this->tempFrame){
            edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->tempFrame;edkEnd();
            //test if temp frame have the second
            if(temp->second == second){
                temp->w = w;edkEnd();
            }
        }
    }
    return false;
}

//Set one interpolation Y as a curve
bool edk::animation::Interpolation4DGroup::setInterpolationCurveW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            temp->isCurveW();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::setInterpolationNotCurveW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            //test if is a curve
            if(!temp->getCurveW()){
                //set as curve
                temp->isCurveW();edkEnd();
            }
            temp->isNotCurveW();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::getInterpolationIsCurveW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            return temp->getCurveW();edkEnd();
        }
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation4DGroup::setConstantW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            temp->setConstantW();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::setLinearW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            temp->setLinearW();edkEnd();
            return true;
        }
    }
    return false;
}
//set all as constant interpolation
void edk::animation::Interpolation4DGroup::setAllConstantW(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::InterpolationLine4D* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine4D*)this->animations.get(i);edkEnd();
        temp->setConstantW();edkEnd();
    }
}
void edk::animation::Interpolation4DGroup::setAllLinearW(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::InterpolationLine4D* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine4D*)this->animations.get(i);edkEnd();
        temp->setLinearW();edkEnd();
    }
}

//Set the interpolation curve points
bool edk::animation::Interpolation4DGroup::setInterpolationP1W(edk::uint32 position,edk::float32 second,edk::float32 w){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            return temp->setP1W(second,w);edkEnd();
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::setInterpolationP2W(edk::uint32 position,edk::float32 second,edk::float32 w){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            return temp->setP2W(second,w);edkEnd();
        }
    }
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation4DGroup::getClockW(){
    //test if is playing
    if(this->isPlaying()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)edk::animation::InterpolationGroup::getSelectedInterpolation();edkEnd();
        //load the position
        if(temp){
            //
            return temp->getPositionW(this->animationSecond) + this->incrementW;edkEnd();
        }
    }
    //else return 0.0f;edkEnd();
    return 0.0f;edkEnd();
}
//return the interpolation W
edk::float32 edk::animation::Interpolation4DGroup::getInterpolationStartW(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            return temp->getStart4D().w;edkEnd();
        }
    }
    return 0u;edkEnd();
}
edk::float32 edk::animation::Interpolation4DGroup::getInterpolationEndW(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);edkEnd();
        if(temp){
            return temp->getStart4D().w;edkEnd();
        }
    }
    return 0u;edkEnd();
}
//return the animation start and end in W
edk::float32 edk::animation::Interpolation4DGroup::getAnimationStartW(){
    if(this->animations.size()){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(0u);edkEnd();
        if(temp){
            return temp->getStart4D().w;edkEnd();
        }
    }
    return 0.f;
}
edk::float32 edk::animation::Interpolation4DGroup::getAnimationEndW(){
    if(this->animations.size()){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(this->animations.size()-1u);edkEnd();
        if(temp){
            return temp->getEnd4D().w;edkEnd();
        }
    }
    return 0.f;
}
//write to XML
bool edk::animation::Interpolation4DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::animation::InterpolationLine4D* temp = NULL;edkEnd();
                        edk::animation::Frame4D* frameTemp=(edk::animation::Frame4D*)this->tempFrame;edkEnd();
                        if(frameTemp){
                            //add the tempFrame
                            frameTemp->writeToXML(xml,count);edkEnd();
                            count++;edkEnd();
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine4D*)this->animations.get(i);edkEnd();
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
                            temp = (edk::animation::InterpolationLine4D*)this->animations.get(i);edkEnd();
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
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
//read XML
bool edk::animation::Interpolation4DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame4D frameTemp;edkEnd();
                    edk::animation::InterpolationLine4D* interpolationTemp=NULL;edkEnd();
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
                        interpolationTemp = (edk::animation::InterpolationLine4D*)this->animations.get(i);edkEnd();
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
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
