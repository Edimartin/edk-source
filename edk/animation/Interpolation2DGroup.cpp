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

edk::animation::Interpolation2DGroup::Interpolation2DGroup(){
    this->classThis=NULL;
    this->Constructor();
}

edk::animation::Interpolation2DGroup::~Interpolation2DGroup(){
    this->Destructor();
}

void edk::animation::Interpolation2DGroup::Constructor(){
    edk::animation::Interpolation1DGroup::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->incrementY=0.f;
        this->incrementYValue=0.f;
    }
}
void edk::animation::Interpolation2DGroup::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::animation::Interpolation1DGroup::Destructor();
}

//create the interpolation
edk::animation::InterpolationLine* edk::animation::Interpolation2DGroup::newLineInterpolation(){
    //
    return (edk::animation::InterpolationLine*)(new edk::animation::InterpolationLine2D());
}
//create the frame
edk::animation::Frame* edk::animation::Interpolation2DGroup::newFrame(){
    //
    return (edk::animation::Frame*)(new edk::animation::Frame2D());
}
//print the frame
void edk::animation::Interpolation2DGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //
    if(interpolation){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)interpolation;
        printf("Start second %.4f X %.4f Y %.4f end second %.4f X %.4f Y %.4f"
               ,temp->getStart2D().second
               ,temp->getStart2D().x
               ,temp->getStart2D().y
               ,temp->getEnd2D().second
               ,temp->getEnd2D().x
               ,temp->getEnd2D().y
               );
    }
}

//copy interpolation frame
void edk::animation::Interpolation2DGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine2D* f = (edk::animation::InterpolationLine2D*) first;
    edk::animation::InterpolationLine2D* s = (edk::animation::InterpolationLine2D*) second;
    s->setStart(f->getStart2D().second,f->getStart2D().x,f->getStart2D().y);
}
void edk::animation::Interpolation2DGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine2D* f = (edk::animation::InterpolationLine2D*) first;
    edk::animation::InterpolationLine2D* s = (edk::animation::InterpolationLine2D*) second;
    s->setEnd(f->getEnd2D().second,f->getEnd2D().x,f->getEnd2D().y);
}

//increment functions to run the increment for the values
void edk::animation::Interpolation2DGroup::runIncrementForward(){
    edk::animation::Interpolation1DGroup::runIncrementForward();
    //run the increment value
    this->incrementY+=this->incrementYValue;
}
void edk::animation::Interpolation2DGroup::runIncrementRewind(){
    edk::animation::Interpolation1DGroup::runIncrementRewind();
    //run the increment value
    this->incrementY-=this->incrementYValue;
}
void edk::animation::Interpolation2DGroup::cleanIncrement(){
    edk::animation::Interpolation1DGroup::cleanIncrement();
    //clean the increment value
    this->incrementY = 0.f;
}
void edk::animation::Interpolation2DGroup::startIncrement(){
    edk::animation::Interpolation1DGroup::startIncrement();
    this->incrementY = 0.f;
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();
    if(size){
        edk::animation::InterpolationLine2D* temp =
                (edk::animation::InterpolationLine2D*)this->animations.get(size-1u);
        if(temp){
            this->incrementYValue = temp->getEnd2D().y;
        }
    }
}

//Add a first interpolation
bool edk::animation::Interpolation2DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY,
                                                                     edk::float32 endSecond,edk::float32 endX,edk::float32 endY){
    //
    return this->addFirstInterpolationLine(startSecond, edk::vec2f32(startX,startY), endSecond, edk::vec2f32(endX,endY));
}
bool edk::animation::Interpolation2DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::vec2f32 startValue, edk::float32 endSecond, edk::vec2f32 endValue){
    //
    return this->addFirstInterpolationLine(edk::animation::Frame2D(startSecond,startValue),edk::animation::Frame2D(endSecond,endValue));
}
bool edk::animation::Interpolation2DGroup::addFirstInterpolationLine(edk::animation::Frame2D start,edk::animation::Frame2D end){
    //first create the frame
    if(edk::animation::InterpolationGroup::addFirstInterpolationLine((edk::animation::Frame)start,(edk::animation::Frame)end)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->tempInterpolation;
        if(temp){
            //
            temp->setStartValue(start.x,start.y);
            temp->setEndValue(end.x,end.y);
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
    return this->addNewInterpolationLine(second,edk::vec2f32(x,y));
}
bool edk::animation::Interpolation2DGroup::addNewInterpolationLine(edk::float32 second,edk::vec2f32 value){
    //
    return this->addNewInterpolationLine(edk::animation::Frame2D(second,value));
}
bool edk::animation::Interpolation2DGroup::addNewInterpolationLine(edk::animation::Frame2D frame){
    //first create the frame
    if(edk::animation::InterpolationGroup::addNewInterpolationLine((edk::animation::Frame)frame)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->tempInterpolation;
        if(temp){
            //test if set start or end
            if(this->setStart){
                //
                temp->setStartValue(frame.x,frame.y);
            }
            else{
                //
                temp->setEndValue(frame.x,frame.y);
                //test if have a tempFrame
                edk::animation::Frame2D* frameTemp = (edk::animation::Frame2D*)this->tempFrame;
                if(frameTemp){
                    //
                    temp->setStartValue(frameTemp->x,frameTemp->y);
                }
                else if(this->setfirstInterpolation){
                    temp->setStartValue(tempX,tempY);
                }
            }
        }
        else{
            //test if have a tempFrame
            edk::animation::Frame2D* frameTemp = (edk::animation::Frame2D*)this->tempFrame;
            if(frameTemp){
                //
                frameTemp->x=frame.x;
                frameTemp->y=frame.y;
                this->tempX = frame.x;
                this->tempY = frame.y;
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
bool edk::animation::Interpolation2DGroup::setFrame2D(edk::float32 second,edk::float32 x,edk::float32 y){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->frameSelected;
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(x,y);
            }
            else{
                temp->setEndValue(x,y);
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
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->frameSelected;
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(temp->getStart1D().x,y);
            }
            else{
                temp->setEndValue(temp->getEnd1D().x,y);
            }
            return true;
        }
    }
    else{
        //test if have the temp animation
        if(this->tempFrame){
            edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->tempFrame;
            //test if temp frame have the second
            if(temp->second == second){
                temp->y = y;
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
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            temp->isCurveY();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::setInterpolationNotCurveY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            //test if is a curve
            if(!temp->getCurveY()){
                //set as curve
                temp->isCurveY();
            }
            temp->isNotCurveY();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::getInterpolationIsCurveY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            return temp->getCurveY();
        }
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation2DGroup::setConstantY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            temp->setConstantY();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::setLinearY(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            temp->setLinearY();
            return true;
        }
    }
    return false;
}
//set all as constant interpolation
void edk::animation::Interpolation2DGroup::setAllConstantY(){
    edk::uint32 size = this->animations.size();
    edk::animation::InterpolationLine2D* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine2D*)this->animations.get(i);
        temp->setConstantY();
    }
}
void edk::animation::Interpolation2DGroup::setAllLinearY(){
    edk::uint32 size = this->animations.size();
    edk::animation::InterpolationLine2D* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine2D*)this->animations.get(i);
        temp->setLinearY();
    }
}
//Set the interpolation curve points
bool edk::animation::Interpolation2DGroup::setInterpolationP1Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            return temp->setP1Y(second,y);
        }
    }
    return false;
}
bool edk::animation::Interpolation2DGroup::setInterpolationP2Y(edk::uint32 position,edk::float32 second,edk::float32 y){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            return temp->setP2Y(second,y);
        }
    }
    return false;
}

//create random animations
//shake
edk::float32 edk::animation::Interpolation2DGroup::addShakingFramesXY(edk::vec2f32 position,edk::float32 randomPercent,edk::float32 percent,edk::float32 interpolationDistance){
    //test if is not animatin the shake
    if(interpolationDistance>0.f
            &&
            percent<1.f){
        edk::float32 angle = 0.f;
        edk::vec2f32 translate = edk::vec2f32(0,0);
        edk::float32 second = 0.f;
        edk::uint32 interpolation=0u;
        //get the last animation position
        if(this->animations.size()){
            //get the last animation frame
            interpolation = this->animations.size()-1u;
            translate.x = this->getInterpolationEndX(interpolation);
            translate.y = this->getInterpolationEndY(interpolation);
            second = this->getInterpolationEndSecond(interpolation);
            interpolation++;
        }
        else if(this->tempFrame){
            edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->tempFrame;
            translate.x = temp->x;
            translate.y = temp->y;
            second = temp->second; ;
        }
        else{
            //else add the first frame
            this->addNewInterpolationLine(second,translate.x,translate.y);
        }

        //increment the second
        second+=interpolationDistance;
        while((position.x>0.1f
               ||
               position.x<-0.1f)
              ||
              (position.y>0.1f
               ||
               position.y<-0.1f)
              ){
            //add the interpolation
            this->addNewInterpolationLine(second,position.x + translate.x,position.y + translate.y);

            //set the curve
            this->setInterpolationCurveX(interpolation);
            this->setInterpolationCurveY(interpolation);
            //set the curve points
            this->setInterpolationP1X(interpolation,second,position.x+ translate.x);
            this->setInterpolationP1Y(interpolation,second,position.y+ translate.y);
            this->setInterpolationP2X(interpolation,second,position.x+ translate.x);
            this->setInterpolationP2Y(interpolation,second,position.y+ translate.y);

            //get the random angle between -90 and 90
            angle = -90.f + (edk::Random::getStaticRandPercent() * 180.f);
            //rotate the angle
            position = edk::Math::rotatePlus(position,180.f + (angle * randomPercent));
            //increment the second
            second+=interpolationDistance;
            //add the next frame

            //translate the percent
            position.x = position.x*percent;
            position.y = position.y*percent;
            //increment the interpolation
            interpolation++;
        }
        //add the last interpolation to position zero
        this->addNewInterpolationLine(second,translate.x,translate.y);

        //set the curve
        this->setInterpolationCurveX(interpolation);
        this->setInterpolationCurveY(interpolation);
        //set the curve points
        this->setInterpolationP1X(interpolation,second,translate.x);
        this->setInterpolationP1Y(interpolation,second,translate.y);
        this->setInterpolationP2X(interpolation,second,translate.x);
        this->setInterpolationP2Y(interpolation,second,translate.y);

        //return how many seconds the animation have
        return second;
    }
    return 0.f;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation2DGroup::getClockY(){
    //test if is playing
    if(this->isPlaying()){
        //load the interpolation
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)edk::animation::InterpolationGroup::getSelectedInterpolation();
        //load the position
        if(temp){
            //
            return temp->getPositionY(this->animationSecond) + this->incrementY;
        }
    }
    //else return 0.0f;
    return 0.0f;
}
//return the interpolation Y
edk::float32 edk::animation::Interpolation2DGroup::getInterpolationStartY(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            return temp->getStart2D().y;
        }
    }
    return 0u;
}
edk::float32 edk::animation::Interpolation2DGroup::getInterpolationEndY(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(position);
        if(temp){
            return temp->getEnd2D().y;
        }
    }
    return 0u;
}
//return the animation start and end in Y
edk::float32 edk::animation::Interpolation2DGroup::getAnimationStartY(){
    if(this->animations.size()){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(0u);
        if(temp){
            return temp->getStart2D().y;
        }
    }
    return 0.f;
}
edk::float32 edk::animation::Interpolation2DGroup::getAnimationEndY(){
    if(this->animations.size()){
        edk::animation::InterpolationLine2D* temp = (edk::animation::InterpolationLine2D*)this->animations.get(this->animations.size()-1u);
        if(temp){
            return temp->getEnd2D().y;
        }
    }
    return 0.f;
}
//write to XML
bool edk::animation::Interpolation2DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::animation::InterpolationLine2D* temp = NULL;
                        edk::animation::Frame2D* frameTemp=(edk::animation::Frame2D*)this->tempFrame;
                        if(frameTemp){
                            //add the tempFrame
                            frameTemp->writeToXML(xml,count);
                            count++;
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine2D*)this->animations.get(i);
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
                            temp = (edk::animation::InterpolationLine2D*)this->animations.get(i);
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
bool edk::animation::Interpolation2DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame2D frameTemp;
                    edk::animation::InterpolationLine2D* interpolationTemp=NULL;
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
                        interpolationTemp = (edk::animation::InterpolationLine2D*)this->animations.get(i);
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
