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
#pragma message "            Inside Interpolation1DGroup.cpp"
#endif

edk::animation::Interpolation1DGroup::Interpolation1DGroup()
    :edk::animation::InterpolationGroup()
{
    //ctor
    this->incrementX=0.f;edkEnd();
    this->incrementXValue=0.f;edkEnd();
    this->tempX=0.f;edkEnd();
}

edk::animation::Interpolation1DGroup::~Interpolation1DGroup()
{
    //dtor
}
//create the interpolation
edk::animation::InterpolationLine* edk::animation::Interpolation1DGroup::newLineInterpolation(){
    //
    return (edk::animation::InterpolationLine*)new edk::animation::InterpolationLine1D();edkEnd();
}
//create the frame
edk::animation::Frame* edk::animation::Interpolation1DGroup::newFrame(){
    //
    return new edk::animation::Frame1D();edkEnd();
}
//print the frame
void edk::animation::Interpolation1DGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //
    if(interpolation){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)interpolation;edkEnd();
        //
        printf("Start second %.4f X %.4f end second %.4f X %.4f"
               ,temp->getStart1D().second
               ,temp->getStart1D().x
               ,temp->getEnd1D().second
               ,temp->getEnd1D().x
               );edkEnd();
    }
}

//copy interpolation frame
void edk::animation::Interpolation1DGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine1D* f = (edk::animation::InterpolationLine1D*) first;edkEnd();
    edk::animation::InterpolationLine1D* s = (edk::animation::InterpolationLine1D*) second;edkEnd();
    s->setStart(f->getStart1D().second,f->getStart1D().x);edkEnd();
}
void edk::animation::Interpolation1DGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine1D* f = (edk::animation::InterpolationLine1D*) first;edkEnd();
    edk::animation::InterpolationLine1D* s = (edk::animation::InterpolationLine1D*) second;edkEnd();
    s->setEnd(f->getEnd1D().second,f->getEnd1D().x);edkEnd();
}

//increment functions to run the increment for the values
void edk::animation::Interpolation1DGroup::runIncrementForward(){
    edk::animation::InterpolationGroup::runIncrementForward();edkEnd();
    //run the increment value
    this->incrementX+=this->incrementXValue;edkEnd();
}
void edk::animation::Interpolation1DGroup::runIncrementRewind(){
    edk::animation::InterpolationGroup::runIncrementRewind();edkEnd();
    //run the increment value
    this->incrementX-=this->incrementXValue;edkEnd();
}
void edk::animation::Interpolation1DGroup::cleanIncrement(){
    edk::animation::InterpolationGroup::cleanIncrement();edkEnd();
    //clean the increment value
    this->incrementX = this->incrementXValue = 0.f;edkEnd();
}
void edk::animation::Interpolation1DGroup::startIncrement(){
    edk::animation::InterpolationGroup::startIncrement();edkEnd();
    this->incrementX = 0.f;edkEnd();
    //get the last Interpolation Line
    edk::uint32 size = this->animations.size();edkEnd();
    if(size){
        edk::animation::InterpolationLine1D* temp =
                (edk::animation::InterpolationLine1D*)this->animations.get(size-1u);edkEnd();
        if(temp){
            this->incrementXValue = temp->getEnd1D().x;edkEnd();
        }
    }
}


//Add a first interpolation
bool edk::animation::Interpolation1DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 endSecond,edk::float32 endX){
    return this->addFirstInterpolationLine(edk::animation::Frame1D(startSecond,startX),edk::animation::Frame1D(endSecond,endX));edkEnd();
}
bool edk::animation::Interpolation1DGroup::addFirstInterpolationLine(edk::animation::Frame1D start,edk::animation::Frame1D end){
    //first create the frame
    if(edk::animation::InterpolationGroup::addFirstInterpolationLine((edk::animation::Frame)start,(edk::animation::Frame)end)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->tempInterpolation;edkEnd();
        if(temp){
            //
            temp->setStartValue(start.x);edkEnd();
            temp->setEndValue(end.x);edkEnd();
        }
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::Interpolation1DGroup::addFirstInterpolationLine(edk::float32 startSecond,edk::float32 endSecond){
    return this->addFirstInterpolationLine(edk::animation::Frame1D(startSecond,startSecond),edk::animation::Frame1D(endSecond,endSecond));edkEnd();
}
bool edk::animation::Interpolation1DGroup::addFirstInterpolationLine(edk::animation::Frame start,edk::animation::Frame end){
    return this->addFirstInterpolationLine(edk::animation::Frame1D(start.second,start.second),edk::animation::Frame1D(end.second,end.second));edkEnd();
}

//Add New Interpolation
bool edk::animation::Interpolation1DGroup::addNewInterpolationLine(edk::float32 second,edk::float32 x){
    return this->addNewInterpolationLine(edk::animation::Frame1D(second,x));edkEnd();
}
bool edk::animation::Interpolation1DGroup::addNewInterpolationLine(edk::animation::Frame1D frame){
    //first create the frame
    if(edk::animation::InterpolationGroup::addNewInterpolationLine((edk::animation::Frame)frame)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->tempInterpolation;edkEnd();
        if(temp){
            //test if set start or end
            if(this->setStart){
                //
                temp->setStartValue(frame.x);edkEnd();
            }
            else{
                //
                temp->setEndValue(frame.x);edkEnd();
                //test if have a tempFrame
                edk::animation::Frame1D* frameTemp = (edk::animation::Frame1D*)this->tempFrame;edkEnd();
                if(frameTemp){
                    //
                    temp->setStartValue(frameTemp->x);edkEnd();
                }
                else if(this->setfirstInterpolation){
                    temp->setStartValue(tempX);edkEnd();
                }
            }
        }
        else{
            //test if have a tempFrame
            edk::animation::Frame1D* frameTemp = (edk::animation::Frame1D*)this->tempFrame;edkEnd();
            if(frameTemp){
                //
                frameTemp->x=frame.x;edkEnd();
                this->tempX = frame.x;edkEnd();
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
bool edk::animation::Interpolation1DGroup::setFrameX(edk::float32 second,edk::float32 x){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->frameSelected;edkEnd();
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(x);edkEnd();
            }
            else{
                temp->setEndValue(x);edkEnd();
            }
            return true;
        }
    }
    else{
        //test if have the temp animation
        if(this->tempFrame){
            edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->tempFrame;edkEnd();
            //test if temp frame have the second
            if(temp->second == second){
                temp->x = x;edkEnd();
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
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            temp->isCurveX();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation1DGroup::setInterpolationNotCurveX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            temp->isNotCurveX();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation1DGroup::getInterpolationIsCurveX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            return temp->getCurveX();edkEnd();
        }
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation1DGroup::setConstantX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            temp->setConstantX();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation1DGroup::setLinearX(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            temp->setLinearX();edkEnd();
            return true;
        }
    }
    return false;
}
//set all as constant interpolation
void edk::animation::Interpolation1DGroup::setAllConstantX(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::InterpolationLine1D* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine1D*)this->animations.get(i);edkEnd();
        temp->setConstantX();edkEnd();
    }
}
void edk::animation::Interpolation1DGroup::setAllLinearX(){
    edk::uint32 size = this->animations.size();edkEnd();
    edk::animation::InterpolationLine1D* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine1D*)this->animations.get(i);edkEnd();
        temp->setLinearX();edkEnd();
    }
}
//Set the interpolation curve points
bool edk::animation::Interpolation1DGroup::setInterpolationP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            //test if is a curve
            if(!temp->getCurveX()){
                //set as curve
                temp->isCurveX();edkEnd();
            }
            return temp->setP1X(second,x);edkEnd();
        }
    }
    return false;
}
bool edk::animation::Interpolation1DGroup::setInterpolationP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            //test if is a curve
            if(!temp->getCurveX()){
                //set as curve
                temp->isCurveX();edkEnd();
            }
            return temp->setP2X(second,x);edkEnd();
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
        edk::float32 translate = 0.f;edkEnd();
        edk::float32 second = 0.f;edkEnd();
        edk::uint32 interpolation=0u;
        //get the last animation position
        if(this->animations.size()){
            //get the last animation frame
            interpolation = this->animations.size()-1u;edkEnd();
            translate = this->getInterpolationEndX(interpolation);edkEnd();
            second = this->getInterpolationEndSecond(interpolation);edkEnd();
            interpolation++;edkEnd();
        }
        else if(this->tempFrame){
            edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->tempFrame;edkEnd();
            translate = temp->x;edkEnd();
            second = temp->second;edkEnd();;
        }
        else{
            //else add the first frame
            this->addNewInterpolationLine(second,translate);edkEnd();
        }


        //increment the second
        second+=interpolationDistance;edkEnd();
        while(position>0.1f
               ||
               position<-0.1f
              ){
            //add the interpolation
            this->addNewInterpolationLine(second,position + translate);edkEnd();

            //set the curve
            this->setInterpolationCurveX(interpolation);edkEnd();
            //set the curve points
            this->setInterpolationP1X(interpolation,second,position + translate);edkEnd();
            this->setInterpolationP2X(interpolation,second,position + translate);edkEnd();

            //increment the second
            second+=interpolationDistance;edkEnd();

            //translate the percent
            position = position*percent*-1.f;edkEnd();
            //increment the interpolation
            interpolation++;edkEnd();
        }
        //add the last interpolation to position zero
        this->addNewInterpolationLine(second,translate);edkEnd();

        //set the curve
        this->setInterpolationCurveX(interpolation);edkEnd();
        //set the curve points
        this->setInterpolationP1X(interpolation,second,translate);edkEnd();
        this->setInterpolationP2X(interpolation,second,translate);edkEnd();

        //return how many seconds the animation have
        return second;edkEnd();
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
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)edk::animation::InterpolationGroup::getSelectedInterpolation();edkEnd();
        if(temp){
            //
            edk::uint32 select;edkEnd();
            edk::uint32 saveSelect;edkEnd();
            //test if the X perence to the atual interpolation
            if(temp->haveSecond(oldSecond)){
                //
                //printf(" oldSec %.2f true",oldSecond);edkEnd();
                //test if have the X
                if(temp->haveX(x)){
                    //set the second
                    this->animationSecond = temp->getSecond(x);edkEnd();
                    //printf(" returnTrue1 %.2f",this->animationSecond);edkEnd();
                    return true;
                }
                else{
                    //find next
                    saveSelect = select = this->interpolationSelect;edkEnd();
                    if(this->isRewind()){
                        while(true){
                            temp = (edk::animation::InterpolationLine1D*)this->animations.get(select);edkEnd();
                            if(temp){
                                //test if have the x
                                if(temp->haveX(x)){
                                    //set the second
                                    this->animationSecond = temp->getSecond(x);edkEnd();
                                    this->interpolationSelect = select;edkEnd();
                                    //printf(" returnTrue2");edkEnd();
                                    return true;
                                }
                            }
                            else{
                                break;
                            }

                            //decrement the select
                            if(select){
                                select--;edkEnd();
                                if(select<=this->interpolationStart){
                                    select = this->interpolationEnd;edkEnd();
                                }
                                if(select==saveSelect){
                                    break;
                                }
                            }
                            else{
                                if(select==this->interpolationStart){
                                    select = this->interpolationEnd;edkEnd();
                                }
                            }
                        }
                    }
                    else{
                        while(true){
                            temp = (edk::animation::InterpolationLine1D*)this->animations.get(select);edkEnd();
                            if(temp){
                                //test if have the x
                                if(temp->haveX(x)){
                                    //set the second
                                    this->animationSecond = temp->getSecond(x);edkEnd();
                                    this->interpolationSelect = select;edkEnd();
                                    //printf(" returnTrue3");edkEnd();
                                    return true;
                                }
                            }
                            else{
                                break;
                            }

                            //increment select
                            select++;edkEnd();
                            if(select>=this->interpolationEnd){
                                select=this->interpolationStart;edkEnd();
                            }
                            if(select==saveSelect){
                                break;
                            }
                        }
                    }
                }
            }
            else{
                saveSelect = select = this->interpolationSelect;edkEnd();
                //printf(" oldSec false");edkEnd();
                //test if is foward or backward
                if(this->isRewind()){
                    //
                    //printf(" rew");edkEnd();
                    //find the next second
                    while(true){
                        temp = (edk::animation::InterpolationLine1D*)this->animations.get(select);edkEnd();
                        if(temp){
                            //test if have the x
                            if(temp->haveSecond(oldSecond)){
                                if(temp->haveX(x)){
                                    //set the second
                                    this->animationSecond = temp->getSecond(x);edkEnd();
                                    this->interpolationSelect = select;edkEnd();
                                    //printf(" returnTrue4");edkEnd();
                                    return true;
                                }
                                else{
                                    //else find the X
                                    saveSelect = select;edkEnd();
                                    while(true){
                                        temp = (edk::animation::InterpolationLine1D*)this->animations.get(select);edkEnd();
                                        if(temp){
                                            //test if have the x
                                            if(temp->haveX(x)){
                                                //set the second
                                                this->animationSecond = temp->getSecond(x);edkEnd();
                                                this->interpolationSelect = select;edkEnd();
                                                //printf(" returnTrue5");edkEnd();
                                                return true;
                                            }
                                        }
                                        else{
                                            break;
                                        }

                                        //decrement the select
                                        if(select){
                                            select--;edkEnd();
                                            if(select<=this->interpolationStart){
                                                select = this->interpolationEnd;edkEnd();
                                            }
                                            if(select==saveSelect){
                                                break;
                                            }
                                        }
                                        else{
                                            if(select==this->interpolationStart){
                                                select = this->interpolationEnd;edkEnd();
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                        }
                        else{
                            break;
                        }

                        //increment select
                        select++;edkEnd();
                        if(select>=this->interpolationEnd){
                            select=this->interpolationStart;edkEnd();
                        }
                        if(select==saveSelect){
                            break;
                        }
                    }
                }
                else{
                    //
                    //printf(" fow");edkEnd();
                    while(true){
                        temp = (edk::animation::InterpolationLine1D*)this->animations.get(select);edkEnd();
                        if(temp){
                            //test if have the x
                            if(temp->haveSecond(oldSecond)){
                                if(temp->haveX(x)){
                                    //set the second
                                    this->animationSecond = temp->getSecond(x);edkEnd();
                                    this->interpolationSelect = select;edkEnd();
                                    //printf(" returnTrue6");edkEnd();
                                    return true;
                                }
                                else{
                                    //else find the X
                                    saveSelect = select;edkEnd();while(true){
                                        temp = (edk::animation::InterpolationLine1D*)this->animations.get(select);edkEnd();
                                        if(temp){
                                            //test if have the x
                                            if(temp->haveX(x)){
                                                //set the second
                                                this->animationSecond = temp->getSecond(x);edkEnd();
                                                this->interpolationSelect = select;edkEnd();
                                                //printf(" returnTrue7");edkEnd();
                                                return true;
                                            }
                                        }
                                        else{
                                            break;
                                        }

                                        //increment select
                                        select++;edkEnd();
                                        if(select>=this->interpolationEnd){
                                            select=this->interpolationStart;edkEnd();
                                        }
                                        if(select==saveSelect){
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                        else{
                            break;
                        }

                        //decrement the select
                        if(select){
                            select--;edkEnd();
                            if(select<=this->interpolationStart){
                                select = this->interpolationEnd;edkEnd();
                            }
                            if(select==saveSelect){
                                break;
                            }
                        }
                        else{
                            if(select==this->interpolationStart){
                                select = this->interpolationEnd;edkEnd();
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
edk::float32 edk::animation::Interpolation1DGroup::getClockX(){
    //test if is playing
    if(this->isPlaying()){
        //load the interpolation
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)edk::animation::InterpolationGroup::getSelectedInterpolation();edkEnd();
        //load the position
        if(temp){
            //
            return temp->getPositionX(this->animationSecond) + this->incrementX;edkEnd();
        }
    }
    //else return 0.0f;edkEnd();
    return 0.0f;edkEnd();
}
//return the interpolation seconds
edk::float32 edk::animation::Interpolation1DGroup::getInterpolationStartX(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            return temp->getStart1D().x;edkEnd();
        }
    }
    return 0u;edkEnd();
}
edk::float32 edk::animation::Interpolation1DGroup::getInterpolationEndX(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(position);edkEnd();
        if(temp){
            return temp->getEnd1D().x;edkEnd();
        }
    }
    return 0u;edkEnd();
}
//return the animation start and end in X
edk::float32 edk::animation::Interpolation1DGroup::getAnimationStartX(){
    if(this->animations.size()){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(0u);edkEnd();
        if(temp){
            return temp->getStart1D().x;edkEnd();
        }
    }
    return 0.f;
}
edk::float32 edk::animation::Interpolation1DGroup::getAnimationEndX(){
    if(this->animations.size()){
        edk::animation::InterpolationLine1D* temp = (edk::animation::InterpolationLine1D*)this->animations.get(this->animations.size()-1u);edkEnd();
        if(temp){
            return temp->getEnd1D().x;edkEnd();
        }
    }
    return 0.f;
}
//write to XML
bool edk::animation::Interpolation1DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::animation::InterpolationLine1D* temp = NULL;edkEnd();
                        edk::animation::Frame1D* frameTemp=(edk::animation::Frame1D*)this->tempFrame;edkEnd();
                        if(frameTemp){
                            //add the tempFrame
                            frameTemp->writeToXML(xml,count);edkEnd();
                            count++;edkEnd();
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine1D*)this->animations.get(i);edkEnd();
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
                            temp = (edk::animation::InterpolationLine1D*)this->animations.get(i);edkEnd();
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
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
//read XML
bool edk::animation::Interpolation1DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame1D frameTemp;edkEnd();
                    edk::animation::InterpolationLine1D* interpolationTemp=NULL;edkEnd();
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
                        interpolationTemp = (edk::animation::InterpolationLine1D*)this->animations.get(i);edkEnd();
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
