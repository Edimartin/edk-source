#include "Interpolation3DGroup.h"

/*
Library C++ InterpolationGroup3D - Manage one or more interpolations with tree values in Edk Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside Interpolation3DGroup.cpp"
#endif

edk::animation::Interpolation3DGroup::Interpolation3DGroup()
{
    //ctor
}

edk::animation::Interpolation3DGroup::~Interpolation3DGroup()
{
    //dtor
}


//create the interpolation
edk::animation::InterpolationLine* edk::animation::Interpolation3DGroup::newLineInterpolation(){
    //
    return (edk::animation::InterpolationLine*)(new edk::animation::InterpolationLine3D());
}
//create the frame
edk::animation::Frame* edk::animation::Interpolation3DGroup::newFrame(){
    //
    return (edk::animation::Frame*)(new edk::animation::Frame3D());
}
//print the frame
void edk::animation::Interpolation3DGroup::printInterpolationLine(edk::animation::InterpolationLine *interpolation){
    //
    if(interpolation){
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)interpolation;
        printf("Start second %.2f X %.2f Y %.2f Z %.2f end second %.2f X %.2f Y %.2f Z %.2f"
               ,temp->getStart3D().second
               ,temp->getStart3D().x
               ,temp->getStart3D().y
               ,temp->getStart3D().z
               ,temp->getEnd3D().second
               ,temp->getEnd3D().x
               ,temp->getEnd3D().y
               ,temp->getEnd3D().z
               );
    }
}

//copy interpolation frame
void edk::animation::Interpolation3DGroup::copyStartToStart(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine3D* f = (edk::animation::InterpolationLine3D*) first;
    edk::animation::InterpolationLine3D* s = (edk::animation::InterpolationLine3D*) second;
    s->setStart(f->getStart3D().second,f->getStart3D().x,f->getStart3D().y,f->getStart3D().z);
}
void edk::animation::Interpolation3DGroup::copyEndToEnd(edk::animation::InterpolationLine* first,edk::animation::InterpolationLine* second){
    edk::animation::InterpolationLine3D* f = (edk::animation::InterpolationLine3D*) first;
    edk::animation::InterpolationLine3D* s = (edk::animation::InterpolationLine3D*) second;
    s->setEnd(f->getEnd3D().second,f->getEnd3D().x,f->getEnd3D().y,f->getEnd3D().z);
}

//Add a first interpolation
bool edk::animation::Interpolation3DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::float32 startX, edk::float32 startY, edk::float32 startZ,
                                                                     edk::float32 endSecond,edk::float32 endX,edk::float32 endY,edk::float32 endZ){
    //
    return this->addFirstInterpolationLine(startSecond, edk::vec3f32(startX,startY,startZ), endSecond, edk::vec3f32(endX,endY,endZ));
}
bool edk::animation::Interpolation3DGroup::addFirstInterpolationLine(edk::float32 startSecond, edk::vec3f32 startValue, edk::float32 endSecond, edk::vec3f32 endValue){
    //
    return this->addFirstInterpolationLine(edk::animation::Frame3D(startSecond,startValue),edk::animation::Frame3D(endSecond,endValue));
}
bool edk::animation::Interpolation3DGroup::addFirstInterpolationLine(edk::animation::Frame3D start,edk::animation::Frame3D end){
    //first create the frame
    if(edk::animation::InterpolationGroup::addFirstInterpolationLine((edk::animation::Frame)start,(edk::animation::Frame)end)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->tempInterpolation;
        if(temp){
            //
            temp->setStartValue(start.x,start.y,start.z);
            temp->setEndValue(end.x,end.y,end.z);
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
    return this->addNewInterpolationLine(second,edk::vec3f32(x,y,z));
}
bool edk::animation::Interpolation3DGroup::addNewInterpolationLine(edk::float32 second,edk::vec3f32 value){
    //
    return this->addNewInterpolationLine(edk::animation::Frame3D(second,value));
}
bool edk::animation::Interpolation3DGroup::addNewInterpolationLine(edk::animation::Frame3D frame){
    //first create the frame
    if(edk::animation::InterpolationGroup::addNewInterpolationLine((edk::animation::Frame)frame)){
        //set the positions if have the interpolationLine
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->tempInterpolation;
        if(temp){
            //test if set start or end
            if(this->setStart){
                //
                temp->setStartValue(frame.x,frame.y,frame.z);
            }
            else{
                //
                temp->setEndValue(frame.x,frame.y,frame.z);
                //test if have a tempFrame
                edk::animation::Frame3D* frameTemp = (edk::animation::Frame3D*)this->tempFrame;
                if(frameTemp){
                    //
                    temp->setStartValue(frameTemp->x,frameTemp->y,frameTemp->z);
                }
                else if(this->setfirstInterpolation){
                    temp->setStartValue(tempX,tempY,tempZ);
                }
            }
        }
        else{
            //test if have a tempFrame
            edk::animation::Frame3D* frameTemp = (edk::animation::Frame3D*)this->tempFrame;
            if(frameTemp){
                //
                frameTemp->x=frame.x;
                frameTemp->y=frame.y;
                frameTemp->z=frame.z;
                this->tempX = frame.x;
                this->tempY = frame.y;
                this->tempZ = frame.z;
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
bool edk::animation::Interpolation3DGroup::setFrame3D(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z){
    //select the frame
    if(this->selectFrame(second)){
        //set the X value
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->frameSelected;
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                temp->setStartValue(x,y,z);
            }
            else{
                temp->setEndValue(x,y,z);
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
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->frameSelected;
        if(temp){
            //set the X value
            if(this->frameSelectedStart){
                edk::animation::Frame2D frame = temp->getStart2D();
                temp->setStartValue(frame.x,frame.y,z);
            }
            else{
                edk::animation::Frame2D frame = temp->getEnd2D();
                temp->setEndValue(frame.x,frame.y,z);
            }
            return true;
        }
    }
    else{
        //test if have the temp animation
        if(this->tempFrame){
            edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->tempFrame;
            //test if temp frame have the second
            if(temp->second == second){
                temp->z = z;
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
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            temp->isCurveZ();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::setInterpolationNotCurveZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            //test if is a curve
            if(!temp->getCurveZ()){
                //set as curve
                temp->isCurveZ();
            }
            temp->isNotCurveZ();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::getInterpolationIsCurveZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            return temp->getCurveZ();
        }
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation3DGroup::setConstantZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            temp->setConstantZ();
            return true;
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::setLinearZ(edk::uint32 position){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            temp->setLinearZ();
            return true;
        }
    }
    return false;
}
//set all as constant interpolation
void edk::animation::Interpolation3DGroup::setAllConstantZ(){
    edk::uint32 size = this->animations.size();
    edk::animation::InterpolationLine3D* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine3D*)this->animations[i];
        temp->setConstantZ();
    }
}
void edk::animation::Interpolation3DGroup::setAllLinearZ(){
    edk::uint32 size = this->animations.size();
    edk::animation::InterpolationLine3D* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::animation::InterpolationLine3D*)this->animations[i];
        temp->setLinearZ();
    }
}

//Set the interpolation curve points
bool edk::animation::Interpolation3DGroup::setInterpolationP1Z(edk::uint32 position,edk::float32 second,edk::float32 z){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            return temp->setP1Z(second,z);
        }
    }
    return false;
}
bool edk::animation::Interpolation3DGroup::setInterpolationP2Z(edk::uint32 position,edk::float32 second,edk::float32 z){
    //test if have the interpolation
    if(position < this->getInterpolationSize()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            return temp->setP2Z(second,z);
        }
    }
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation3DGroup::getClockZ(bool* success){
    //test if is playing
    if(this->isPlaying()){
        //load the interpolation
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)edk::animation::InterpolationGroup::getSelectedInterpolation();
        //set success
        if(success) *success=true;
        //load the position
        if(temp){
            //
            return temp->getPositionZ(this->animationSecond);
        }
    }
    //set success
    else if(success) *success=false;
    //else return 0.0f;
    return 0.0f;
}
//return the interpolation Z
edk::float32 edk::animation::Interpolation3DGroup::getInterpolationStartZ(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            return temp->getStart3D().z;
        }
    }
    return 0u;
}
edk::float32 edk::animation::Interpolation3DGroup::getInterpolationEndZ(edk::float32 position){
    if(position < this->animations.size()){
        edk::animation::InterpolationLine3D* temp = (edk::animation::InterpolationLine3D*)this->animations[position];
        if(temp){
            return temp->getStart3D().z;
        }
    }
    return 0u;
}
//write to XML
bool edk::animation::Interpolation3DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        if(this->isLooping()) xml->addSelectedNextAttribute("loop","on");
                        else              xml->addSelectedNextAttribute("loop","off");
                        edk::uint32 count = 0u;
                        edk::animation::InterpolationLine3D* temp = NULL;
                        edk::animation::Frame3D* frameTemp=(edk::animation::Frame3D*)this->tempFrame;
                        if(frameTemp){
                            //add the tempFrame
                            frameTemp->writeToXML(xml,count);
                            count++;
                        }
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::InterpolationLine3D*)this->animations[i];
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
                            temp = (edk::animation::InterpolationLine3D*)this->animations[i];
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
bool edk::animation::Interpolation3DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::uint32 count = 0u;
                    edk::animation::Frame3D frameTemp;
                    edk::animation::InterpolationLine3D* interpolationTemp=NULL;
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
                        interpolationTemp = (edk::animation::InterpolationLine3D*)this->animations[i];
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
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
