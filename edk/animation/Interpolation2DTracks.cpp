#include "Interpolation2DTracks.h"

/*
Biblioteca C++ Interpolation2DTracks - Manage one or more interpolation tracks 2D in Edk Game Engine
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

edk::animation::Interpolation2DTracks::Interpolation2DTracks(){
    //
    this->tracks = &this->stack;edkEnd();
    this->active = false;
}
edk::animation::Interpolation2DTracks::~Interpolation2DTracks(){
    //
}

edk::animation::InterpolationGroup* edk::animation::Interpolation2DTracks::newInterpolationGroup(){
    return (edk::animation::InterpolationGroup*) new edk::animation::Interpolation2DGroup;edkEnd();
}

//Add a first interpolation
bool edk::animation::Interpolation2DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::float32 startSecond,
                                                                      edk::float32 startX,
                                                                      edk::float32 startY,
                                                                      edk::float32 endSecond,
                                                                      edk::float32 endX,
                                                                      edk::float32 endY
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->addFirstInterpolationLine(startSecond,startX,startY,endSecond,endX,endY);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::float32 startSecond,
                                                                      edk::vec2f32 startValue,
                                                                      edk::float32 endSecond,
                                                                      edk::vec2f32 endValue
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->addFirstInterpolationLine(startSecond,startValue,endSecond,endValue);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::animation::Frame2D start,
                                                                      edk::animation::Frame2D end
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->addFirstInterpolationLine(start,end);edkEnd();
    }
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation2DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->addNewInterpolationLine(second,x,y);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::vec2f32 value){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->addNewInterpolationLine(second,value);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame2D frame){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->addNewInterpolationLine(frame);edkEnd();
    }
    return false;
}

//Set the frame value
bool edk::animation::Interpolation2DTracks::setFrame2D(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->setFrame2D(second,x,y);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setFrameY(edk::uint32 trackPosition,edk::float32 second,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->setFrameY(second,y);edkEnd();
    }
    return false;
}

//Set one interpolation Y as a curve
bool edk::animation::Interpolation2DTracks::setInterpolationCurveY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->setInterpolationCurveY(position);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setInterpolationNotCurveY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->setInterpolationNotCurveY(position);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::getInterpolationIsCurveY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->getInterpolationIsCurveY(position);edkEnd();
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation2DTracks::setConstantY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->setConstantY(position);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setLinearY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->setLinearY(position);edkEnd();
    }
    return false;
}
//set all as constant interpolation
bool edk::animation::Interpolation2DTracks::setAllConstantY(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        group->setAllConstantY();edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setAllLinearY(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        group->setAllLinearY();edkEnd();
        return true;
    }
    return false;
}
//Set the interpolation curve points
bool edk::animation::Interpolation2DTracks::setInterpolationP1Y(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->setInterpolationP1Y(position,second,y);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setInterpolationP2Y(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->setInterpolationP2Y(position,second,y);edkEnd();
    }
    return false;
}

//create random animations
//shake
edk::float32 edk::animation::Interpolation2DTracks::addShakingFramesXY(edk::uint32 trackPosition,edk::vec2f32 position,edk::float32 random,edk::float32 percent,edk::float32 interpolationDistance){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->addShakingFramesXY(position,random,percent,interpolationDistance);edkEnd();
    }
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation2DTracks::getClockY(){
    edk::animation::Interpolation2DTracks::StackTracks2D* temp = (edk::animation::Interpolation2DTracks::StackTracks2D*)this->tracks;edkEnd();
    temp->y = 0.f;edkEnd();
    //update the calculate all X from the tracks
    temp->print();edkEnd();
    //return the Y
    return temp->y;edkEnd();
}
edk::float32 edk::animation::Interpolation2DTracks::getClockY(edk::float32 y){
    edk::animation::Interpolation2DTracks::StackTracks2D* temp = (edk::animation::Interpolation2DTracks::StackTracks2D*)this->tracks;edkEnd();
    temp->y = y;edkEnd();
    //update the calculate all X from the tracks
    temp->print();edkEnd();
    //return the Y
    return temp->y;edkEnd();
}
//return the interpolation Y
edk::float32 edk::animation::Interpolation2DTracks::getInterpolationStartY(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->getInterpolationStartY(position);edkEnd();
    }
    return false;
}
edk::float32 edk::animation::Interpolation2DTracks::getInterpolationEndY(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->getInterpolationEndY(position);edkEnd();
    }
    return false;
}
//return the animation start and end in Y
edk::float32 edk::animation::Interpolation2DTracks::getAnimationStartY(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->getAnimationStartY();edkEnd();
    }
    return false;
}
edk::float32 edk::animation::Interpolation2DTracks::getAnimationEndY(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
        return group->getAnimationEndY();edkEnd();
    }
    return false;
}
//write to XML
bool edk::animation::Interpolation2DTracks::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks2D_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->tracks->size();edkEnd();
                        if(size){
                            edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
                            edk::animation::Interpolation2DGroup* group;edkEnd();
                            edk::char8* trackID = NULL;edkEnd();
                            edk::char8* trackName = NULL;edkEnd();
                            edk::uint32 counter=0u;
                            for(edk::uint32 i=0u;i<size;i++){
                                temp = this->tracks->get(i);edkEnd();
                                group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
                                if(group){
                                    trackID = edk::String::int64ToStr(counter);edkEnd();
                                    if(trackID){
                                        trackName = edk::String::strCat((edk::char8*)"animTrack2D_",trackID);edkEnd();
                                        if(trackName){
                                            //add the track
                                            xml->addSelectedNextChild("animTrack2D_");edkEnd();
                                            if(xml->selectChild("animTrack2D_")){
                                                xml->setSelectedString(temp.number);edkEnd();
                                                //write the animation
                                                group->writeToXML(xml,counter);edkEnd();
                                                ++counter;edkEnd();
                                                xml->selectFather();edkEnd();
                                            }
                                            free(trackName);edkEnd();
                                        }
                                        free(trackID);edkEnd();
                                    }
                                }
                            }
                        }
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
bool edk::animation::Interpolation2DTracks::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks2D_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //
                    edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
                    edk::animation::Interpolation2DGroup* group;edkEnd();
                    edk::char8* trackID = NULL;edkEnd();
                    edk::char8* trackName = NULL;edkEnd();
                    edk::uint32 counter=0u;
                    edk::uint32 position=0u;
                    bool running=true;edkEnd();
                    while(running){
                        //generate the strings
                        trackID = edk::String::int64ToStr(counter);edkEnd();
                        if(trackID){
                            trackName = edk::String::strCat((edk::char8*)"animTrack2D_",trackID);edkEnd();
                            if(trackName){
                                //select the child
                                if(xml->selectChild(trackID)){
                                    //read the string
                                    temp.number = xml->getSelectedStringAsUint32();edkEnd();
                                    //create a new track
                                    position = this->newTrack(temp.number);edkEnd();
                                    if(position<this->tracks->size()){
                                        //get the track and read the XML
                                        temp=this->tracks->get(position);edkEnd();
                                        group = (edk::animation::Interpolation2DGroup*)temp.animation;edkEnd();
                                        if(group){
                                            temp.animation->readFromXML(xml,counter);edkEnd();
                                        }
                                    }
                                    else{
                                        running=false;edkEnd();
                                    }
                                    xml->selectFather();edkEnd();
                                }
                                running=false;edkEnd();
                                free(trackName);edkEnd();
                            }
                            free(trackID);edkEnd();
                        }
                        counter++;edkEnd();
                    }
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
