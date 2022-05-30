#include "Interpolation1DGroup.h"

/*
Library C++ InterpolationGroup1D - Manage one or more interpolations with one value in Edk Game Engine
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
#warning "            Inside Interpolation1DGroup.cpp"
#endif

edk::animation::Interpolation1DGroup::Interpolation1DGroup()
    :edk::animation::InterpolationGroup()
{
    //ctor
    this->incrementX=0.f;
    this->incrementXValue=0.f;
    this->tempX=0.f;
}

edk::animation::Interpolation1DGroup::~Interpolation1DGroup()
{
    //dtor
}
//create the interpolation
edk::animation::InterpolationLine* edk::animation::Interpolation1DGroup::newLineInterpolation(){
    //
    return (edk::animation::InterpolationLine*)new edk::animation::InterpolationLine1D();
}
//create the frame
edk::animation::Frame* edk::animation::Interpolation1DGroup::newFrame(){
    //
    return new edk::animation::Frame1D();
}
//print the frame
void edk::animation::Interpolation1DGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //
    if(interpolation){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)interpolation;
        //
        printf("Start second %.2f X %.2f end second %.2f X %.2f"
               ,temp->getStart1D().second
               ,temp->getStart1D().x
               ,temp->getEnd1D().second
               ,temp->getEnd1D().x
               );
    }
}

//copy interpolation frame
void edk::animation::Interpolation1DGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine1D* f = (edk::animation::InterpolationLine1D*) first;
    edk::animation::InterpolationLine1D* s = (edk::animation::InterpolationLine1D*) second;
    s->setStart(f->getStart1D().second,f->getStart1D().x);
}
void edk::animation::Interpolation1DGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine1D* f = (edk::animation::InterpolationLine1D*) first;
    edk::animation::InterpolationLine1D* s = (edk::animation::InterpolationLine1D*) second;
    s->setEnd(f->getEnd1D().second,f->getEnd1D().x);
}

//increment functions to run the increment for the values
void edk::animation::Interpolation1DGroup::runIncrementForward(){
    edk::animation::InterpolationGroup::runIncrementForward();
    //run the increment value
    this->incrementX+=this->incrementXValue;
}
void edk::animation::Interpolation1DGroup::runIncrementRewind(){
    edk::animation::InterpolationGroup::runIncrementRewind();
    //run the increment value
    this->incrementX-=this->incrementXValue;
}
void edk::animation::Interpolation1DGroup::cleanIncrement(){
    edk::animation::InterpolationGroup::cleanIncrement();
    //clean the increment value
    this->incrementX = this->incrementXValue = 0.f;
}
void edk::animation::Interpolation1DGroup::startIncrement(){
    edk::animation::InterpolationGroup::startIncrement();
    this->incrementX = 0.f;
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();
    if(size){
        edk::animation::InterpolationLine1D* temp =
                (edk::animation::InterpolationLine1D*)this->animations.get(size-1u);
        if(temp){
            this->incrementXValue = temp->getEnd1D().x;
        }
    }
}


//Add a first interpolation
bool edk::animation::Interpolation1DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 endSecond,edk::float32 endX){
    return this->addFirstInterpolationLine(edk::animation::Frame1D(startSecond,startX),edk::animation::Frame1D(endSecond,endX));
}
bool edk::animation::Interpolation1DGroup::addFirstInterpolationLine(edk::animation::Frame1D start,edk::animation::Frame1D end){
    //first create the frame
    if(edk::animation::InterpolationGroup::addFirstInterpolationLine((edk::animation::Frame)start,(edk::animation::Frame)end)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->tempInterpolation;
        if(temp){
            //
            temp->setStartValue(start.x);
            temp->setEndValue(end.x);
        }
        //return true
        return true;
    }
    //else return false
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation1DGroup::addNewInterpolationLine(edk::float32 second,edk::float32 x){
    return this->addNewInterpolationLine(edk::animation::Frame1D(second,x));
}
bool edk::animation::Interpolation1DGroup::addNewInterpolationLine(edk::animation::Frame1D frame){
    //first create the frame
    if(edk::animation::InterpolationGroup::addNewInterpolationLine((edk::animation::Frame)frame)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->tempInterpolation;
        if(temp){
            //test if set start or end
            if(this->setStart){
                //
                temp->setStartValue(frame.x);
            }
            else{
                //
                temp->setEndValue(frame.x);
                //test if have a tempFrame
                edk::animation::Frame1D* frameTemp = (edk::animation::Frame1D*)this->tempFrame;
                if(frameTemp){
                    //
                    temp->setStartValue(frameTemp->x);
                }
                else if(this->setfirstInterpolation){
                    temp->setStartValue(tempX);
                }
            }
        }
        else{
            //test if have a tempFrame
            edk::animation::Frame1D* frameTemp = (edk::animation::Frame1D*)this->tempFrame;
            if(frameTemp){
                //
                frameTemp->x=frame.x;
                this->tempX = frame.x;
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
bool edk::animation::Interpolation1DGroup::setFrameX(edk::float32 second,edk::float32 x){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->frameSelected;
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(x);
            }
            else{
                temp->setEndValue(x);
            }
            return true;
        }
    }
    else{
        //test if have the temp animation
        if(this->tempFrame){
            edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->tempFrame;
            //test if temp frame have the second
            if(temp->second == second){
                temp->x = x;
            }
        }
    }
    return false;
}

//Set one interpolation X as a curve
bool edk::animation::Interpolation1DGroup::setInterpolationCurveX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            temp->isCurveX();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation1DGroup::setInterpolationNotCurveX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            temp->isNotCurveX();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation1DGroup::getInterpolationIsCurveX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            return temp->getCurveX();
        }
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation1DGroup::setConstantX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            temp->setConstantX();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation1DGroup::setLinearX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            temp->setLinearX();
            return true;
        }
    }
    return false;
}
//set all as constant interpolation
void edk::animation::Interpolation1DGroup::setAllConstantX(){
    edk::uint32 size = this->animations.size();
    edk::animation::InterpolationLine1D* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine1D*)this->animations[i];
        temp->setConstantX();
    }
}
void edk::animation::Interpolation1DGroup::setAllLinearX(){
    edk::uint32 size = this->animations.size();
    edk::animation::InterpolationLine1D* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine1D*)this->animations[i];
        temp->setLinearX();
    }
}
//Set the interpolation curve points
bool edk::animation::Interpolation1DGroup::setInterpolationP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            //test if is a curve
            if(!temp->getCurveX()){
                //set as curve
                temp->isCurveX();
            }
            return temp->setP1X(second,x);
        }
    }
    return false;
}
bool edk::animation::Interpolation1DGroup::setInterpolationP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            //test if is a curve
            if(!temp->getCurveX()){
                //set as curve
                temp->isCurveX();
            }
            return temp->setP2X(second,x);
        }
    }
    return false;
}

//create random animations
//shake
edk::float32 edk::animation::Interpolation1DGroup::addShakingFramesX(edk::float32 position,edk::float32 percent,edk::float32 interpolationDistance){
    //test if is not animatin the shake
    if(interpolationDistance>0.f
            &&
            percent<1.f){
        edk::float32 translate = 0.f;
        edk::float32 second = 0.f;
        edk::uint32 interpolation=0u;
        //get the last animation position
        if(this->animations.size()){
            //get the last animation frame
            interpolation = this->animations.size()-1u;
            translate = this->getInterpolationEndX(interpolation);
            second = this->getInterpolationEndSecond(interpolation);
            interpolation++;
        }
        else if(this->tempFrame){
            edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->tempFrame;
            translate = temp->x;
            second = temp->second;;
        }
        else{
            //else add the first frame
            this->addNewInterpolationLine(second,translate);
        }


        //increment the second
        second+=interpolationDistance;
        while(position>0.1f
               ||
               position<-0.1f
              ){
            //add the interpolation
            this->addNewInterpolationLine(second,position + translate);

            //set the curve
            this->setInterpolationCurveX(interpolation);
            //set the curve points
            this->setInterpolationP1X(interpolation,second,position + translate);
            this->setInterpolationP2X(interpolation,second,position + translate);

            //increment the second
            second+=interpolationDistance;

            //translate the percent
            position = position*percent*-1.f;
            //increment the interpolation
            interpolation++;
        }
        //add the last interpolation to position zero
        this->addNewInterpolationLine(second,translate);

        //set the curve
        this->setInterpolationCurveX(interpolation);
        //set the curve points
        this->setInterpolationP1X(interpolation,second,translate);
        this->setInterpolationP2X(interpolation,second,translate);

        //return how many seconds the animation have
        return second;
    }
    return 0.f;
}

//set the animationSecond by the X
bool edk::animation::Interpolation1DGroup::setSecondByX(edk::float32 oldSecond,edk::float32 x){
    //test if is playing
    if(this->isPlaying()
            &&
            oldSecond<=this->frameEnd
            &&
            oldSecond>=this->frameStart
            ){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)edk::animation::InterpolationGroup::getSelectedInterpolation();
        if(temp){
            //
            edk::uint32 select;
            edk::uint32 saveSelect;
            //test if the X perence to the atual interpolation
            if(temp->haveSecond(oldSecond)){
                //
                //printf(" oldSec %.2f true",oldSecond);
                //test if have the X
                if(temp->haveX(x)){
                    //set the second
                    this->animationSecond = temp->getSecond(x);
                    //printf(" returnTrue1 %.2f",this->animationSecond);
                    return true;
                }
                else{
                    //find next
                    saveSelect = select = this->interpolationSelect;
                    if(this->isRewind()){
                        while(true){
                            temp = (edk::animation::InterpolationLine1D*)this->animations[select];
                            if(temp){
                                //test if have the x
                                if(temp->haveX(x)){
                                    //set the second
                                    this->animationSecond = temp->getSecond(x);
                                    this->interpolationSelect = select;
                                    //printf(" returnTrue2");
                                    return true;
                                }
                            }
                            else break;

                            //decrement the select
                            if(select){
                                select--;
                                if(select<=this->interpolationStart){
                                    select = this->interpolationEnd;
                                }
                                if(select==saveSelect){
                                    break;
                                }
                            }
                            else{
                                if(select==this->interpolationStart){
                                    select = this->interpolationEnd;
                                }
                            }
                        }
                    }
                    else{
                        while(true){
                            temp = (edk::animation::InterpolationLine1D*)this->animations[select];
                            if(temp){
                                //test if have the x
                                if(temp->haveX(x)){
                                    //set the second
                                    this->animationSecond = temp->getSecond(x);
                                    this->interpolationSelect = select;
                                    //printf(" returnTrue3");
                                    return true;
                                }
                            }
                            else break;

                            //increment select
                            select++;
                            if(select>=this->interpolationEnd){
                                select=this->interpolationStart;
                            }
                            if(select==saveSelect){
                                break;
                            }
                        }
                    }
                }
            }
            else{
                saveSelect = select = this->interpolationSelect;
                //printf(" oldSec false");
                //test if is foward or backward
                if(this->isRewind()){
                    //
                    //printf(" rew");
                    //find the next second
                    while(true){
                        temp = (edk::animation::InterpolationLine1D*)this->animations[select];
                        if(temp){
                            //test if have the x
                            if(temp->haveSecond(oldSecond)){
                                if(temp->haveX(x)){
                                    //set the second
                                    this->animationSecond = temp->getSecond(x);
                                    this->interpolationSelect = select;
                                    //printf(" returnTrue4");
                                    return true;
                                }
                                else{
                                    //else find the X
                                    saveSelect = select;
                                    while(true){
                                        temp = (edk::animation::InterpolationLine1D*)this->animations[select];
                                        if(temp){
                                            //test if have the x
                                            if(temp->haveX(x)){
                                                //set the second
                                                this->animationSecond = temp->getSecond(x);
                                                this->interpolationSelect = select;
                                                //printf(" returnTrue5");
                                                return true;
                                            }
                                        }
                                        else break;

                                        //decrement the select
                                        if(select){
                                            select--;
                                            if(select<=this->interpolationStart){
                                                select = this->interpolationEnd;
                                            }
                                            if(select==saveSelect){
                                                break;
                                            }
                                        }
                                        else{
                                            if(select==this->interpolationStart){
                                                select = this->interpolationEnd;
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                        }
                        else break;

                        //increment select
                        select++;
                        if(select>=this->interpolationEnd){
                            select=this->interpolationStart;
                        }
                        if(select==saveSelect){
                            break;
                        }
                    }
                }
                else{
                    //
                    //printf(" fow");
                    while(true){
                        temp = (edk::animation::InterpolationLine1D*)this->animations[select];
                        if(temp){
                            //test if have the x
                            if(temp->haveSecond(oldSecond)){
                                if(temp->haveX(x)){
                                    //set the second
                                    this->animationSecond = temp->getSecond(x);
                                    this->interpolationSelect = select;
                                    //printf(" returnTrue6");
                                    return true;
                                }
                                else{
                                    //else find the X
                                    saveSelect = select;while(true){
                                        temp = (edk::animation::InterpolationLine1D*)this->animations[select];
                                        if(temp){
                                            //test if have the x
                                            if(temp->haveX(x)){
                                                //set the second
                                                this->animationSecond = temp->getSecond(x);
                                                this->interpolationSelect = select;
                                                //printf(" returnTrue7");
                                                return true;
                                            }
                                        }
                                        else break;

                                        //increment select
                                        select++;
                                        if(select>=this->interpolationEnd){
                                            select=this->interpolationStart;
                                        }
                                        if(select==saveSelect){
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                        else break;

                        //decrement the select
                        if(select){
                            select--;
                            if(select<=this->interpolationStart){
                                select = this->interpolationEnd;
                            }
                            if(select==saveSelect){
                                break;
                            }
                        }
                        else{
                            if(select==this->interpolationStart){
                                select = this->interpolationEnd;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation1DGroup::getClockX(bool* success){
    //test if is playing
    if(this->isPlaying()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)edk::animation::InterpolationGroup::getSelectedInterpolation();
        //set success
        if(success) *success=true;
        //load the position
        if(temp){
            //

            return temp->getPositionX(this->animationSecond) + this->incrementX;
        }
    }
    //set success
    else if(success) *success=false;
    //else return 0.0f;
    return 0.0f;
}
//return the interpolation seconds
edk::float32 edk::animation::Interpolation1DGroup::getInterpolationStartX(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            return temp->getStart1D().x;
        }
    }
    return 0u;
}
edk::float32 edk::animation::Interpolation1DGroup::getInterpolationEndX(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations[position];
        if(temp){
            return temp->getEnd1D().x;
        }
    }
    return 0u;
}
//write to XML
bool edk::animation::Interpolation1DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        if(this->getLoop()) xml->addSelectedNextAttribute("loop","on");
                        else                xml->addSelectedNextAttribute("loop","off");
                        //save the incrementing
                        if(this->getIncrement()) xml->addSelectedNextAttribute("increment","on");
                        else                     xml->addSelectedNextAttribute("increment","off");
                        edk::uint32 count = 0u;
                        edk::animation::InterpolationLine1D* temp = NULL;
                        edk::animation::Frame1D* frameTemp=(edk::animation::Frame1D*)this->tempFrame;
                        if(frameTemp){
                            //add the tempFrame
                            frameTemp->writeToXML(xml,count);
                            count++;
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine1D*)this->animations[i];
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
                            temp = (edk::animation::InterpolationLine1D*)this->animations[i];
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
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
//read XML
bool edk::animation::Interpolation1DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame1D frameTemp;
                    edk::animation::InterpolationLine1D* interpolationTemp=NULL;
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
                        interpolationTemp = (edk::animation::InterpolationLine1D*)this->animations[i];
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
                delete[] name;
            }
            delete []nameID;
        }
        return ret;
    }
    return false;
}
