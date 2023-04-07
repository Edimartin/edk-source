#include "Interpolation2DGroup.h"

/*
Library C++ InterpolationGroup2D - Manage one or more interpolations with two values in Edk Game Engine
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
#pragma message "            Inside Interpolation2DGroup.cpp"
#endif

edk::animation::Interpolation2DGroup::Interpolation2DGroup()
{
    //
    this->incrementY=0.f;edkEnd();
    this->incrementYValue=0.f;edkEnd();
}

edk::animation::Interpolation2DGroup::~Interpolation2DGroup()
{
    //
}

//create the interpolation
edk::animation::InterpolationLine* edk::animation::Interpolation2DGroup::newLineInterpolation(){
    //
    return (edk::animation::InterpolationLine*)(new edk::animation::InterpolationLine2D());edkEnd();
}
//create the frame
edk::animation::Frame* edk::animation::Interpolation2DGroup::newFrame(){
    //
    return (edk::animation::Frame*)(new edk::animation::Frame2D());edkEnd();
}
//print the frame
void edk::animation::Interpolation2DGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //
    if(interpolation){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)interpolation;edkEnd();
        printf("Start second %.4f X %.4f Y %.4f end second %.4f X %.4f Y %.4f"
               ,temp->getStart2D().second
               ,temp->getStart2D().x
               ,temp->getStart2D().y
               ,temp->getEnd2D().second
               ,temp->getEnd2D().x
               ,temp->getEnd2D().y
               );edkEnd();
    }
}

//copy interpolation frame
void edk::animation::Interpolation2DGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine2D* f = (edk::animation::InterpolationLine2D*) first;edkEnd();
    edk::animation::InterpolationLine2D* s = (edk::animation::InterpolationLine2D*) second;edkEnd();
    s->setStart(f->getStart2D().second,f->getStart2D().x,f->getStart2D().y);edkEnd();
}
void edk::animation::Interpolation2DGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine2D* f = (edk::animation::InterpolationLine2D*) first;edkEnd();
    edk::animation::InterpolationLine2D* s = (edk::animation::InterpolationLine2D*) second;edkEnd();
    s->setEnd(f->getEnd2D().second,f->getEnd2D().x,f->getEnd2D().y);edkEnd();
}

//increment functions to run the increment for the values
void edk::animation::Interpolation2DGroup::runIncrementForward(){
    edk::animation::Interpolation1DGroup::runIncrementForward();edkEnd();
    //run the increment value
    this->incrementY+=this->incrementYValue;edkEnd();
}
void edk::animation::Interpolation2DGroup::runIncrementRewind(){
    edk::animation::Interpolation1DGroup::runIncrementRewind();edkEnd();
    //run the increment value
    this->incrementY-=this->incrementYValue;edkEnd();
}
void edk::animation::Interpolation2DGroup::cleanIncrement(){
    edk::animation::Interpolation1DGroup::cleanIncrement();edkEnd();
    //clean the increment value
    this->incrementY = 0.f;edkEnd();
}
void edk::animation::Interpolation2DGroup::startIncrement(){
    edk::animation::Interpolation1DGroup::startIncrement();edkEnd();
    this->incrementY = 0.f;edkEnd();
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::InterpolationLine2D* temp =
                (edk::animation::InterpolationLine2D*)this->animations.get(size-1u);edkEnd();
        if(temp){
            this->incrementYValue = temp->getEnd2D().y;edkEnd();
        }
    }
}

//Add a first interpolation
bool edk::animation::Interpolation2DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY,
                                                                     edk::float32 endSecond,edk::float32 endX,edk::float32 endY){
    //
    return this->addFirstInterpolationLine(startSecond, edk::vec2f32(startX,startY), endSecond, edk::vec2f32(endX,endY));edkEnd();
}
bool edk::animation::Interpolation2DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::vec2f32 startValue, edk::float32 endSecond, edk::vec2f32 endValue){
    //
    return this->addFirstInterpolationLine(edk::animation::Frame2D(startSecond,startValue),edk::animation::Frame2D(endSecond,endValue));edkEnd();
}
bool edk::animation::Interpolation2DGroup::addFirstInterpolationLine(edk::animation::Frame2D start,edk::animation::Frame2D end){
    //first create the frame
    if(edk::animation::InterpolationGroup::addFirstInterpolationLine((edk::animation::Frame)start,(edk::animation::Frame)end)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->tempInterpolation;edkEnd();
        if(temp){
            //
            temp->setStartValue(start.x,start.y);edkEnd();
            temp->setEndValue(end.x,end.y);edkEnd();
        }
        //return true
        return true;
    }
    //else return false
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation2DGroup::addNewInterpolationLine(edk::float32 second,edk::float32 x,edk::float32 y){
    //
    return this->addNewInterpolationLine(second,edk::vec2f32(x,y));edkEnd();
}
bool edk::animation::Interpolation2DGroup::addNewInterpolationLine(edk::float32 second,edk::vec2f32 value){
    //
    return this->addNewInterpolationLine(edk::animation::Frame2D(second,value));edkEnd();
}
bool edk::animation::Interpolation2DGroup::addNewInterpolationLine(edk::animation::Frame2D frame){
    //first create the frame
    if(edk::animation::InterpolationGroup::addNewInterpolationLine((edk::animation::Frame)frame)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->tempInterpolation;edkEnd();
        if(temp){
            //test if set start or end
            if(this->setStart){
                //
                temp->setStartValue(frame.x,frame.y);edkEnd();
            }
            else{
                //
                temp->setEndValue(frame.x,frame.y);edkEnd();
                //test if have a tempFrame
                edk::animation::Frame2D* frameTemp = (edk::animation::Frame2D*)this->tempFrame;edkEnd();
                if(frameTemp){
                    //
                    temp->setStartValue(frameTemp->x,frameTemp->y);edkEnd();
                }
                else if(this->setfirstInterpolation){
                    temp->setStartValue(tempX,tempY);edkEnd();
                }
            }
        }
        else{
            //test if have a tempFrame
            edk::animation::Frame2D* frameTemp = (edk::animation::Frame2D*)this->tempFrame;edkEnd();
            if(frameTemp){
                //
                frameTemp->x=frame.x;edkEnd();
                frameTemp->y=frame.y;edkEnd();
                this->tempX = frame.x;edkEnd();
                this->tempY = frame.y;edkEnd();
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
bool edk::animation::Interpolation2DGroup::setFrame2D(edk::float32 second,edk::float32 x,edk::float32 y){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->frameSelected;edkEnd();
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(x,y);edkEnd();
            }
            else{
                temp->setEndValue(x,y);edkEnd();
            }
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::setFrameY(edk::float32 second,edk::float32 y){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->frameSelected;edkEnd();
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(temp->getStart1D().x,y);edkEnd();
            }
            else{
                temp->setEndValue(temp->getEnd1D().x,y);edkEnd();
            }
            return true;
        }
    }
    else{
        //test if have the temp animation
        if(this->tempFrame){
            edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->tempFrame;edkEnd();
            //test if temp frame have the second
            if(temp->second == second){
                temp->y = y;edkEnd();
            }
        }
    }
    return false;
}

//Set one interpolation Y as a curve
bool edk::animation::Interpolation2DGroup::setInterpolationCurveY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            temp->isCurveY();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::setInterpolationNotCurveY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            //test if is a curve
            if(!temp->getCurveY()){
                //set as curve
                temp->isCurveY();edkEnd();
            }
            temp->isNotCurveY();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::getInterpolationIsCurveY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            return temp->getCurveY();edkEnd();
        }
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation2DGroup::setConstantY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            temp->setConstantY();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::setLinearY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            temp->setLinearY();edkEnd();
            return true;
        }
    }
    return false;
}
//set all as constant interpolation
void edk::animation::Interpolation2DGroup::setAllConstantY(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::InterpolationLine2D* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine2D*)this->animations[i];edkEnd();
        temp->setConstantY();edkEnd();
    }
}
void edk::animation::Interpolation2DGroup::setAllLinearY(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::InterpolationLine2D* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine2D*)this->animations[i];edkEnd();
        temp->setLinearY();edkEnd();
    }
}
//Set the interpolation curve points
bool edk::animation::Interpolation2DGroup::setInterpolationP1Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            return temp->setP1Y(second,y);edkEnd();
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::setInterpolationP2Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            return temp->setP2Y(second,y);edkEnd();
        }
    }
    return false;
}

//create random animations
//shake
edk::float32 edk::animation::Interpolation2DGroup::addShakingFramesXY(edk::vec2f32 position,edk::float32 random,edk::float32 percent,edk::float32 interpolationDistance){
    //test if is not animatin the shake
    if(interpolationDistance>0.f
            &&
            percent<1.f){
        edk::float32 angle = 0.f;edkEnd();
        edk::vec2f32 translate = edk::vec2f32(0,0);edkEnd();
        edk::float32 second = 0.f;edkEnd();
        edk::uint32 interpolation=0u;
        //get the last animation position
        if(this->animations.size()){
            //get the last animation frame
            interpolation = this->animations.size()-1u;edkEnd();
            translate.x = this->getInterpolationEndX(interpolation);edkEnd();
            translate.y = this->getInterpolationEndY(interpolation);edkEnd();
            second = this->getInterpolationEndSecond(interpolation);edkEnd();
            interpolation++;edkEnd();
        }
        else if(this->tempFrame){
            edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->tempFrame;edkEnd();
            translate.x = temp->x;edkEnd();
            translate.y = temp->y;edkEnd();
            second = temp->second;edkEnd();;
        }
        else{
            //else add the first frame
            this->addNewInterpolationLine(second,translate.x,translate.y);edkEnd();
        }

        //increment the second
        second+=interpolationDistance;edkEnd();
        while((position.x>0.1f
               ||
               position.x<-0.1f)
              ||
              (position.y>0.1f
               ||
               position.y<-0.1f)
              ){
            //add the interpolation
            this->addNewInterpolationLine(second,position.x + translate.x,position.y + translate.y);edkEnd();

            //set the curve
            this->setInterpolationCurveX(interpolation);edkEnd();
            this->setInterpolationCurveY(interpolation);edkEnd();
            //set the curve points
            this->setInterpolationP1X(interpolation,second,position.x+ translate.x);edkEnd();
            this->setInterpolationP1Y(interpolation,second,position.y+ translate.y);edkEnd();
            this->setInterpolationP2X(interpolation,second,position.x+ translate.x);edkEnd();
            this->setInterpolationP2Y(interpolation,second,position.y+ translate.y);edkEnd();

            //get the random angle between -90 and 90
            angle = -90.f + (edk::Random::getRandPercent() * 180.f);edkEnd();
            //rotate the angle
            position = edk::Math::rotatePlus(position,180.f + (angle * random));edkEnd();
            //increment the second
            second+=interpolationDistance;edkEnd();
            //add the next frame

            //translate the percent
            position.x = position.x*percent;edkEnd();
            position.y = position.y*percent;edkEnd();
            //increment the interpolation
            interpolation++;edkEnd();
        }
        //add the last interpolation to position zero
        this->addNewInterpolationLine(second,translate.x,translate.y);edkEnd();

        //set the curve
        this->setInterpolationCurveX(interpolation);edkEnd();
        this->setInterpolationCurveY(interpolation);edkEnd();
        //set the curve points
        this->setInterpolationP1X(interpolation,second,translate.x);edkEnd();
        this->setInterpolationP1Y(interpolation,second,translate.y);edkEnd();
        this->setInterpolationP2X(interpolation,second,translate.x);edkEnd();
        this->setInterpolationP2Y(interpolation,second,translate.y);edkEnd();

        //return how many seconds the animation have
        return second;edkEnd();
    }
    return 0.f;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation2DGroup::getClockY(){
    //test if is playing
    if(this->isPlaying()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)edk::animation::InterpolationGroup::getSelectedInterpolation();edkEnd();
        //load the position
        if(temp){
            //
            return temp->getPositionY(this->animationSecond) + this->incrementY;edkEnd();
        }
    }
    //else return 0.0f;edkEnd();
    return 0.0f;edkEnd();
}
//return the interpolation Y
edk::float32 edk::animation::Interpolation2DGroup::getInterpolationStartY(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            return temp->getStart2D().y;edkEnd();
        }
    }
    return 0u;edkEnd();
}
edk::float32 edk::animation::Interpolation2DGroup::getInterpolationEndY(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[position];edkEnd();
        if(temp){
            return temp->getEnd2D().y;edkEnd();
        }
    }
    return 0u;edkEnd();
}
//return the animation start and end in Y
edk::float32 edk::animation::Interpolation2DGroup::getAnimationStartY(){
    if(this->animations.size()){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[0u];edkEnd();
        if(temp){
            return temp->getStart2D().y;edkEnd();
        }
    }
    return 0.f;
}
edk::float32 edk::animation::Interpolation2DGroup::getAnimationEndY(){
    if(this->animations.size()){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations[this->animations.size()-1u];edkEnd();
        if(temp){
            return temp->getEnd2D().y;edkEnd();
        }
    }
    return 0.f;
}
//write to XML
bool edk::animation::Interpolation2DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::animation::InterpolationLine2D* temp = NULL;edkEnd();
                        edk::animation::Frame2D* frameTemp=(edk::animation::Frame2D*)this->tempFrame;edkEnd();
                        if(frameTemp){
                            //add the tempFrame
                            frameTemp->writeToXML(xml,count);edkEnd();
                            count++;edkEnd();
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine2D*)this->animations[i];edkEnd();
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
                            temp = (edk::animation::InterpolationLine2D*)this->animations[i];edkEnd();
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
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
//read XML
bool edk::animation::Interpolation2DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame2D frameTemp;edkEnd();
                    edk::animation::InterpolationLine2D* interpolationTemp=NULL;edkEnd();
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
                        interpolationTemp = (edk::animation::InterpolationLine2D*)this->animations[i];edkEnd();
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
