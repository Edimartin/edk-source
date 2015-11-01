#include "Path2DGroup.h"

/*
Biblioteca C++ Path2DGroup - Manage one or more physics animation frames2D in Edk Game Engine
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
#warning "            Inside PathGroup2D.cpp"
#endif

edk::animation::Path2DGroup::Path2DGroup()
{
}
//create the frame
edk::animation::Frame* edk::animation::Path2DGroup::newFrame(){
    return (edk::animation::Frame*)new edk::animation::Frame2D;
}
//return true if the value reach the frame position
bool edk::animation::Path2DGroup::reachFrame(edk::animation::Frame* frame){
    bool ret=false;
    edk::animation::Frame2D* temp = (edk::animation::Frame2D*)frame;
    //calculate the distance between the temp and the last
    edk::float32 distance = edk::Math::pythagoras2f(edk::vec2f32(this->getX() - temp->x,this->getY() - temp->y));
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
bool edk::animation::Path2DGroup::addNewFrame(edk::float32 seconds,edk::float32 x,edk::float32 y){
    //create a new frame
    edk::animation::Frame2D* frame = (edk::animation::Frame2D*)this->newFrame();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrame(frame)){
            //set the frame values
            frame->second = seconds;
            frame->x = x;
            frame->y = y;
            return true;
        }
        //else delete the frame
        delete frame;
    }
    return false;
}
//add a new frame to the position
bool edk::animation::Path2DGroup::addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x,edk::float32 y){
    //create a new frame
    edk::animation::Frame2D* frame = (edk::animation::Frame2D*)this->newFrame();
    if(frame){
        //add to the animation
        if(edk::animation::PathGroup::addNewFrameToPosition(position,frame)){
            //set the frame values
            frame->second = seconds;
            frame->x = x;
            frame->y = y;
            return true;
        }
        //else delete the frame
        delete frame;
    }
    return false;
}

//set the Y
void edk::animation::Path2DGroup::setY(edk::float32 y){
    this->y=y;
}

//get the Y
edk::float32 edk::animation::Path2DGroup::getY(){
    return this->y;
}

//update the clock animation
edk::float32 edk::animation::Path2DGroup::updateClockAnimation(){
    //calculate the step
    edk::float32 step = edk::animation::PathGroup::updateClockAnimation();
    //load the frame
    edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->animations[this->animationPosition];
    edk::animation::Frame2D* last = (edk::animation::Frame2D*)this->getLastFrame();

    this->saveStep = step/temp->second;
    this->setX(last->x + ((temp->x - last->x) * this->saveStep));
    this->setY( last->y + ((temp->y - last->y) * this->saveStep));

    /*

    //this->setY(vec.y);

    //calculate the new position
    //this->y = this->y + ((temp->y - this->y) * step);
    /*
    if(step>=temp->second){
        this->setX(temp->x);
        this->y = temp->y;
    }
    else{
        edk::float32 div = step/temp->second;
        this->setX(last->x + ((temp->x - last->x) * div));
        this->y = last->y + ((temp->y - last->y) * div);
    }
    */
    return step;
}

//write to XML
bool edk::animation::Path2DGroup::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::animation::Frame2D* tempFrame;
                        for(edk::uint32 i=0u;i<size;i++){
                            //write the first
                            tempFrame = (edk::animation::Frame2D*)this->animations[i];
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
bool edk::animation::Path2DGroup::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::animation::Frame2D frameTemp;
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
                        this->addNewFrame(frameTemp.second,frameTemp.x,frameTemp.y);
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
