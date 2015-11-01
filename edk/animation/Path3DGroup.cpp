#include "Path3DGroup.h"

/*
Biblioteca C++ Path3DGroup - Manage one or more physics animation frames3D in Edk Game Engine
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
#warning "            Inside PathGroup3D.cpp"
#endif

edk::animation::Path3DGroup::Path3DGroup()
{
}
//create the frame
edk::animation::Frame* edk::animation::Path3DGroup::newFrame(){
    return (edk::animation::Frame*)new edk::animation::Frame3D;
}
//return true if the value reach the frame position
bool edk::animation::Path3DGroup::reachFrame(edk::animation::Frame* frame){
    bool ret=false;
    edk::animation::Frame3D* temp = (edk::animation::Frame3D*)frame;
    //calculate the distance between the temp and the last
    edk::float32 distance = edk::Math::pythagoras3f(edk::vec3f32(this->getX() - temp->x,
                                                                 this->getY() - temp->y,
                                                                 this->getZ() - temp->z
                                                                 )
                                                    );
    if(distance<this->closerDistance
            &&
            distance>-this->closerDistance
            ){
        if(this->saveStep>1.f)
        ret=true;
    }
    if(this->changeFrame){
        //test if reach the frame value
        if(this->getX()>=(temp->x-this->closerDistance)
                &&
                this->getX()<=(temp->x+this->closerDistance)
                &&
                this->getY()>=(temp->y-this->closerDistance)
                &&
                this->getY()<=(temp->y+this->closerDistance)
                &&
                this->getZ()>=(temp->z-this->closerDistance)
                &&
                this->getZ()<=(temp->z+this->closerDistance)
                ){
            //
            if(this->saveStep>1.f)
            ret = true;
        }
    }
    else{
        //test if the distance is bigger than last distance
        if(distance > this->lastDist){
            //
            if(this->saveStep>1.f)
            ret=true;
        }
    }
    //save distance
    this->lastDist = distance;

    this->changeFrame=false;
    return ret;
}

//add a new frame
bool edk::animation::Path3DGroup::addNewFrame(edk::float32 seconds,edk::float32 x,edk::float32 y,edk::float32 z){
    //create a new frame
    edk::animation::Frame3D* frame = (edk::animation::Frame3D*)this->newFrame();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrame(frame)){
            //set the frame values
            frame->second = seconds;
            frame->x=x;
            frame->y=y;
            frame->z=z;
            return true;
        }
        //else delete the frame
        delete frame;
    }
    return false;
}
//add a new frame to the position
bool edk::animation::Path3DGroup::addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x,edk::float32 y,edk::float32 z){
    //create a new frame
    edk::animation::Frame3D* frame = (edk::animation::Frame3D*)this->newFrame();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrameToPosition(position,frame)){
            //set the frame values
            frame->second = seconds;
            frame->x=x;
            frame->y=y;
            frame->z=z;
            return true;
        }
        //else delete the frame
        delete frame;
    }
    return false;
}

//set the Z
void edk::animation::Path3DGroup::setZ(edk::float32 z){
    this->z=z;
}
//get the Z
edk::float32 edk::animation::Path3DGroup::getZ(){
    return this->z;
}

//update the clock animation
edk::float32 edk::animation::Path3DGroup::updateClockAnimation(){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation();
    //load the frame
    edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->animations[this->animationPosition];
    edk::animation::Frame3D* last = (edk::animation::Frame3D*)this->getLastFrame();
    //calculate the new position
    this->saveStep = step/temp->second;
    this->setX(last->x + ((temp->x - last->x) * this->saveStep));
    this->setY( last->y + ((temp->y - last->y) * this->saveStep));
    this->setZ( last->z + ((temp->z - last->z) * this->saveStep));
    return step;
}

//write to XML
bool edk::animation::Path3DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"pathAnim_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //save the looping
                        if(this->isLopping()) xml->addSelectedNextAttribute("loop","on");
                        else              xml->addSelectedNextAttribute("loop","off");
                        //write the animationFrames
                        edk::uint32 size = this->animations.size();
                        edk::animation::Frame3D* tempFrame;
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            tempFrame = (edk::animation::Frame3D*)this->animations[i];
                            if(tempFrame){
                                tempFrame->writeToXML(xml,i);
                            }
                        }

                        //write the animationNames
                        size = this->animationNames.size();
                        edk::animation::PathGroup::AnimationPathNames *temp = NULL;
                        for(edk::uint32 i=0u;i<size;i++){
                            temp = (edk::animation::PathGroup::AnimationPathNames *)this->animationNames.getElementInPosition(i);
                            if(temp){
                                temp->writeToXML(xml,i);
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
bool edk::animation::Path3DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"pathAnim_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->deleteFrames();
                    edk::uint32 count = 0u;
                    edk::animation::Frame3D frameTemp;
                    //read the loop
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("loop"),(edk::char8*)"on")){
                        this->loopOn();
                    }
                    else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("loop"),(edk::char8*)"off")){
                        this->loopOff();
                    }
                    //read the frames
                    while(frameTemp.readFromXML(xml,count)){
                        //add the frame to the interpolation
                        this->addNewFrame(frameTemp.second,frameTemp.x,frameTemp.y,frameTemp.z);
                        //
                        count++;
                        //clean the frame
                        frameTemp.second = 0.f;
                        //return true
                        ret=true;
                    }

                    //read the names
                    edk::animation::PathGroup::AnimationPathNames nameTemp;
                    while(nameTemp.readFromXML(xml,count)){
                        //add the animationName
                        this->addNewAnimationName(nameTemp.getName(),nameTemp.start,nameTemp.end);

                        count++;
                        //clean nameTemp
                        nameTemp.cleanName();
                        nameTemp.start = 0u;
                        nameTemp.end = 0u;
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
