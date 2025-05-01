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
    this->classThis=NULL;
    this->Constructor();
}

edk::animation::Interpolation4DGroup::~Interpolation4DGroup(){
    this->Destructor();
}

void edk::animation::Interpolation4DGroup::Constructor(){
    Interpolation3DGroup::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        //ctor
        this->incrementW=0.f;
        this->incrementWValue=0.f;
    }
}
void edk::animation::Interpolation4DGroup::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    Interpolation3DGroup::Destructor();
}

//create the interpolation
edk::animation::InterpolationLine* edk::animation::Interpolation4DGroup::newLineInterpolation(){
    //
    return (edk::animation::InterpolationLine*)(new edk::animation::InterpolationLine4D());
}
//create the frame
edk::animation::Frame* edk::animation::Interpolation4DGroup::newFrame(){
    //
    return (edk::animation::Frame*)(new edk::animation::Frame4D());
}
//print the frame
void edk::animation::Interpolation4DGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //
    if(interpolation){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)interpolation;
        printf("Start second %.4f X %.4f Y %.4f Z %.4f end second %.4f X %.4f Y %.4f Z %.4f"
               ,temp->getStart4D().second
               ,temp->getStart4D().x
               ,temp->getStart4D().y
               ,temp->getStart4D().z
               ,temp->getEnd4D().second
               ,temp->getEnd4D().x
               ,temp->getEnd4D().y
               ,temp->getEnd4D().z
               );
    }
}

//copy interpolation frame
void edk::animation::Interpolation4DGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine4D* f = (edk::animation::InterpolationLine4D*) first;
    edk::animation::InterpolationLine4D* s = (edk::animation::InterpolationLine4D*) second;
    s->setStart(f->getStart4D().second,f->getStart4D().x,f->getStart4D().y,f->getStart4D().z,f->getStart4D().w);
}
void edk::animation::Interpolation4DGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine4D* f = (edk::animation::InterpolationLine4D*) first;
    edk::animation::InterpolationLine4D* s = (edk::animation::InterpolationLine4D*) second;
    s->setEnd(f->getEnd4D().second,f->getEnd4D().x,f->getEnd4D().y,f->getEnd4D().z,f->getEnd4D().w);
}

//increment functions to run the increment for the values
void edk::animation::Interpolation4DGroup::runIncrementForward(){
    edk::animation::Interpolation3DGroup::runIncrementForward();
    //run the increment value
    this->incrementW+=this->incrementWValue;
}
void edk::animation::Interpolation4DGroup::runIncrementRewind(){
    edk::animation::Interpolation3DGroup::runIncrementRewind();
    //run the increment value
    this->incrementW-=this->incrementWValue;
}
void edk::animation::Interpolation4DGroup::cleanIncrement(){
    edk::animation::Interpolation3DGroup::cleanIncrement();
    //clean the increment value
    this->incrementW = 0.f;
}
void edk::animation::Interpolation4DGroup::startIncrement(){
    edk::animation::Interpolation3DGroup::startIncrement();
    this->incrementW = 0.f;
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();
    if(size){
        edk::animation::InterpolationLine4D* temp =
                (edk::animation::InterpolationLine4D*)this->animations.get(size-1u);
        if(temp){
            this->incrementWValue = temp->getEnd4D().z;
        }
    }
}

//Add a first interpolation
bool edk::animation::Interpolation4DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 startZ, edk::float32 startW,
                                                                     edk::float32 endSecond,edk::float32 endX,edk::float32 endY,edk::float32 endZ,edk::float32 endW){
    //
    return this->addFirstInterpolationLine(startSecond, edk::vec4f32(startX,startY,startZ,startW), endSecond, edk::vec4f32(endX,endY,endZ,endW));
}
bool edk::animation::Interpolation4DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::vec4f32 startValue, edk::float32 endSecond, edk::vec4f32 endValue){
    //
    return this->addFirstInterpolationLine(edk::animation::Frame4D(startSecond,startValue),edk::animation::Frame4D(endSecond,endValue));
}
bool edk::animation::Interpolation4DGroup::addFirstInterpolationLine(edk::animation::Frame4D start,edk::animation::Frame4D end){
    //first create the frame
    if(edk::animation::InterpolationGroup::addFirstInterpolationLine((edk::animation::Frame)start,(edk::animation::Frame)end)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->tempInterpolation;
        if(temp){
            //
            temp->setStartValue(start.x,start.y,start.z,start.w);
            temp->setEndValue(end.x,end.y,end.z,end.w);
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
    return this->addNewInterpolationLine(second,edk::vec4f32(x,y,z,w));
}
bool edk::animation::Interpolation4DGroup::addNewInterpolationLine(edk::float32 second,edk::vec4f32 value){
    //
    return this->addNewInterpolationLine(edk::animation::Frame4D(second,value));
}
bool edk::animation::Interpolation4DGroup::addNewInterpolationLine(edk::animation::Frame4D frame){
    //first create the frame
    if(edk::animation::InterpolationGroup::addNewInterpolationLine((edk::animation::Frame)frame)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->tempInterpolation;
        if(temp){
            //test if set start or end
            if(this->setStart){
                //
                temp->setStartValue(frame.x,frame.y,frame.z,frame.w);
            }
            else{
                //
                temp->setEndValue(frame.x,frame.y,frame.z,frame.w);
                //test if have a tempFrame
                edk::animation::Frame4D* frameTemp = (edk::animation::Frame4D*)this->tempFrame;
                if(frameTemp){
                    //
                    temp->setStartValue(frameTemp->x,frameTemp->y,frameTemp->z,frameTemp->w);
                }
                else if(this->setfirstInterpolation){
                    temp->setStartValue(this->tempX,this->tempY,this->tempZ,this->tempW);
                }
            }
        }
        else{
            //test if have a tempFrame
            edk::animation::Frame4D* frameTemp = (edk::animation::Frame4D*)this->tempFrame;
            if(frameTemp){
                //
                frameTemp->x=frame.x;
                frameTemp->y=frame.y;
                frameTemp->z=frame.z;
                frameTemp->w=frame.w;
                this->tempX = frame.x;
                this->tempY = frame.y;
                this->tempZ = frame.z;
                this->tempW = frame.w;
            }
        }
        //clean the tempInterpolation
        //this->tempInterpolation=NULL;

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
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->frameSelected;
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(x,y,z,w);
            }
            else{
                temp->setEndValue(x,y,z,w);
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
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->frameSelected;
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                edk::animation::Frame4D frame = temp->getStart4D();
                temp->setStartValue(frame.x,frame.y,frame.z,w);
            }
            else{
                edk::animation::Frame4D frame = temp->getEnd4D();
                temp->setEndValue(frame.x,frame.y,frame.z,w);
            }
            return true;
        }
    }
    else{
        //test if have the temp animation
        if(this->tempFrame){
            edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->tempFrame;
            //test if temp frame have the second
            if(temp->second == second){
                temp->w = w;
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
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            temp->isCurveW();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::setInterpolationNotCurveW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            //test if is a curve
            if(!temp->getCurveW()){
                //set as curve
                temp->isCurveW();
            }
            temp->isNotCurveW();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::getInterpolationIsCurveW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            return temp->getCurveW();
        }
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation4DGroup::setConstantW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            temp->setConstantW();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::setLinearW(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            temp->setLinearW();
            return true;
        }
    }
    return false;
}
//set all as constant interpolation
void edk::animation::Interpolation4DGroup::setAllConstantW(){
    edk::uint32 size = this->animations.size();
    edk::animation::InterpolationLine4D* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine4D*)this->animations.get(i);
        temp->setConstantW();
    }
}
void edk::animation::Interpolation4DGroup::setAllLinearW(){
    edk::uint32 size = this->animations.size();
    edk::animation::InterpolationLine4D* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine4D*)this->animations.get(i);
        temp->setLinearW();
    }
}

//Set the interpolation curve points
bool edk::animation::Interpolation4DGroup::setInterpolationP1W(edk::uint32 position,edk::float32 second,edk::float32 w){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            return temp->setP1W(second,w);
        }
    }
    return false;
}
bool edk::animation::Interpolation4DGroup::setInterpolationP2W(edk::uint32 position,edk::float32 second,edk::float32 w){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            return temp->setP2W(second,w);
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
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)edk::animation::InterpolationGroup::getSelectedInterpolation();
        //load the position
        if(temp){
            //
            return temp->getPositionW(this->animationSecond) + this->incrementW;
        }
    }
    //else return 0.0f;
    return 0.0f;
}
//return the interpolation W
edk::float32 edk::animation::Interpolation4DGroup::getInterpolationStartW(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            return temp->getStart4D().w;
        }
    }
    return 0u;
}
edk::float32 edk::animation::Interpolation4DGroup::getInterpolationEndW(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(position);
        if(temp){
            return temp->getStart4D().w;
        }
    }
    return 0u;
}
//return the animation start and end in W
edk::float32 edk::animation::Interpolation4DGroup::getAnimationStartW(){
    if(this->animations.size()){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(0u);
        if(temp){
            return temp->getStart4D().w;
        }
    }
    return 0.f;
}
edk::float32 edk::animation::Interpolation4DGroup::getAnimationEndW(){
    if(this->animations.size()){
        edk::animation::InterpolationLine4D* temp = (edk::animation::InterpolationLine4D*)this->animations.get(this->animations.size()-1u);
        if(temp){
            return temp->getEnd4D().w;
        }
    }
    return 0.f;
}
//write to XML
bool edk::animation::Interpolation4DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"anim_",nameID);
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
                        edk::uint32 count = 0u;
                        edk::animation::InterpolationLine4D* temp = NULL;
                        edk::animation::Frame4D* frameTemp=(edk::animation::Frame4D*)this->tempFrame;
                        if(frameTemp){
                            //add the tempFrame
                            frameTemp->writeToXML(xml,count);
                            count++;
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine4D*)this->animations.get(i);
                            if(temp){
                                if(!i){
                                    //write the first
                                    temp->writeToXMLStart(xml,count);
                                    count++;
                                }
                                temp->writeToXMLEnd(xml,count);
                                count++;
                            }
                        }
                        //write the curvers
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine4D*)this->animations.get(i);
                            if(temp){
                                temp->writeCurveToXML(xml,i);
                            }
                        }
                        //write the animationNames
                        size = this->animationNames.size();
                        edk::animation::AnimationName *animationTemp = NULL;
                        for(edk::uint32 i=0u;i<size;i++){
                            animationTemp = (edk::animation::AnimationName *)this->animationNames.getElementInPosition(i);
                            if(animationTemp){
                                animationTemp->writeToXML(xml,i);
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
bool edk::animation::Interpolation4DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"anim_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->cleanAnimations();
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
                    edk::uint32 count = 0u;
                    edk::animation::Frame4D frameTemp;
                    edk::animation::InterpolationLine4D* interpolationTemp=NULL;
                    //read the frames
                    while(frameTemp.readFromXML(xml,count)){
                        //add the frame to the interpolation
                        this->addNewInterpolationLine(frameTemp);
                        //
                        count++;
                        //clean the frame
                        frameTemp.second = 0.f;
                        //return true
                        ret=true;
                    }
                    edk::uint32 size = this->animations.size();
                    //read the curves
                    for(edk::uint32 i=0u;i<size;i++){
                        //read the XML
                        interpolationTemp = (edk::animation::InterpolationLine4D*)this->animations.get(i);
                        if(interpolationTemp){
                            interpolationTemp->readCurveFromXML(xml,i);
                        }
                    }
                    count = 0;
                    //read the names
                    edk::animation::AnimationName nameTemp;
                    while(nameTemp.readFromXML(xml,count)){
                        //add the animationName
                        this->addNewAnimationName(nameTemp.getName(),nameTemp.start,nameTemp.end);

                        count++;
                        //clean nameTemp
                        nameTemp.setName((edk::char8*)NULL);
                        nameTemp.start = 0.f;
                        nameTemp.end = 0.f;
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
