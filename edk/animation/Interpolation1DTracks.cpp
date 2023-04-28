#include "Interpolation1DTracks.h"

/*
Biblioteca C++ Interpolation1DTracks - Manage one or more interpolation tracks 1D in Edk Game Engine
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

edk::animation::Interpolation1DTracks::Interpolation1DTracks(){
    //
    this->tracks = &this->stack;edkEnd();
}
edk::animation::Interpolation1DTracks::~Interpolation1DTracks(){
    //
}

edk::animation::InterpolationGroup* edk::animation::Interpolation1DTracks::newInterpolationGroup(){
    return (edk::animation::InterpolationGroup*) new edk::animation::Interpolation1DGroup;edkEnd();
}


//Add a first interpolation
bool edk::animation::Interpolation1DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::float32 startX, edk::float32 endSecond,edk::float32 endX){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->addFirstInterpolationLine(startSecond,startX, endSecond,endX);
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame1D start,edk::animation::Frame1D end){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->addFirstInterpolationLine(start,end);
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond,edk::float32 endSecond){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->addFirstInterpolationLine(startSecond,endSecond);
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame start,edk::animation::Frame end){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->addFirstInterpolationLine(start,end);
    }
    edkEnd();
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation1DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->addNewInterpolationLine(second,x);
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame1D frame){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->addNewInterpolationLine(frame);
    }
    edkEnd();
    return false;
}

//Set the frame value
bool edk::animation::Interpolation1DTracks::setFrameX(edk::uint32 trackPosition,edk::float32 second,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->setFrameX(second,x);
    }
    edkEnd();
    return false;
}

//Set one interpolation X as a curve
bool edk::animation::Interpolation1DTracks::setInterpolationCurveX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->setInterpolationCurveX(position);
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::setInterpolationNotCurveX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->setInterpolationNotCurveX(position);
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::getInterpolationIsCurveX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->getInterpolationIsCurveX(position);
    }
    edkEnd();
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation1DTracks::setConstantX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->setConstantX(position);
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::setLinearX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->setLinearX(position);
    }
    edkEnd();
    return false;
}
//set all as constant interpolation
bool edk::animation::Interpolation1DTracks::setAllConstantX(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        group->setAllConstantX();edkEnd();
        edkEnd();
        return true;
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::setAllLinearX(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        group->setAllLinearX();edkEnd();
        edkEnd();
        return true;
    }
    edkEnd();
    return false;
}
//Set the interpolation curve points
bool edk::animation::Interpolation1DTracks::setInterpolationP1X(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->setInterpolationP1X(position,second,x);
    }
    edkEnd();
    return false;
}
bool edk::animation::Interpolation1DTracks::setInterpolationP2X(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->setInterpolationP2X(position,second,x);
    }
    edkEnd();
    return false;
}

//create random animations
//shake
edk::float32 edk::animation::Interpolation1DTracks::addShakingFramesX(edk::uint32 trackPosition,edk::float32 position,edk::float32 percent,edk::float32 interpolationDistance){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->addShakingFramesX(position,percent,interpolationDistance);
    }
    edkEnd();
    return false;
}

//set the animationSecond by the X
bool edk::animation::Interpolation1DTracks::setSecondByX(edk::uint32 trackPosition,edk::float32 oldSecond,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->setSecondByX(oldSecond,x);
    }
    edkEnd();
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation1DTracks::getClockX(){
    edk::animation::Interpolation1DTracks::StackTracks1D* temp = (edk::animation::Interpolation1DTracks::StackTracks1D*)this->tracks;edkEnd();
    temp->x = 0.f;edkEnd();
    //update the calculate all X from the tracks
    temp->load();edkEnd();
    //return the X
    edkEnd();
    return temp->x;
}
edk::float32 edk::animation::Interpolation1DTracks::getClockX(edk::float32 x){
    edk::animation::Interpolation1DTracks::StackTracks1D* temp = (edk::animation::Interpolation1DTracks::StackTracks1D*)this->tracks;edkEnd();
    temp->x = x;edkEnd();
    //update the calculate all X from the tracks
    temp->load();edkEnd();
    //return the X
    edkEnd();
    return temp->x;
}
//return the interpolation seconds
edk::float32 edk::animation::Interpolation1DTracks::getInterpolationStartX(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->getInterpolationStartX(position);
    }
    edkEnd();
    return false;
}
edk::float32 edk::animation::Interpolation1DTracks::getInterpolationEndX(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->getInterpolationEndX(position);
    }
    edkEnd();
    return false;
}
//return the animation start and end in X
edk::float32 edk::animation::Interpolation1DTracks::getAnimationStartX(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->getAnimationStartX();
    }
    edkEnd();
    return false;
}
edk::float32 edk::animation::Interpolation1DTracks::getAnimationEndX(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
        edkEnd();
        return group->getAnimationEndX();
    }
    edkEnd();
    return false;
}
//write to XML
bool edk::animation::Interpolation1DTracks::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks1D_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->tracks->size();edkEnd();
                        if(size){
                            edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
                            edk::animation::Interpolation1DGroup* group;edkEnd();
                            edk::char8* trackID = NULL;edkEnd();
                            edk::char8* trackName = NULL;edkEnd();
                            edk::uint32 counter=0u;
                            for(edk::uint32 i=0u;i<size;i++){
                                temp = this->tracks->get(i);edkEnd();
                                group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
                                if(group){
                                    trackID = edk::String::int64ToStr(counter);edkEnd();
                                    if(trackID){
                                        trackName = edk::String::strCat((edk::char8*)"animTrack1D_",trackID);edkEnd();
                                        if(trackName){
                                            //add the track
                                            xml->addSelectedNextChild("animTrack1D_");edkEnd();
                                            if(xml->selectChild("animTrack1D_")){
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
        edkEnd();
        return ret;
    }
    edkEnd();
    return false;
}
//read XML
bool edk::animation::Interpolation1DTracks::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks1D_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //
                    edk::animation::InterpolationTracks::AnimationAndPosition temp;edkEnd();
                    edk::animation::Interpolation1DGroup* group;edkEnd();
                    edk::char8* trackID = NULL;edkEnd();
                    edk::char8* trackName = NULL;edkEnd();
                    edk::uint32 counter=0u;
                    edk::uint32 position=0u;
                    bool running=true;edkEnd();
                    while(running){
                        //generate the strings
                        trackID = edk::String::int64ToStr(counter);edkEnd();
                        if(trackID){
                            trackName = edk::String::strCat((edk::char8*)"animTrack1D_",trackID);edkEnd();
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
                                        group = (edk::animation::Interpolation1DGroup*)temp.animation;edkEnd();
                                        if(group){
                                            temp.animation->readFromXML(xml,counter);edkEnd();
                                        }
                                    }
                                    else{
                                        running=false;edkEnd();
                                    }
                                    xml->selectFather();edkEnd();
                                }
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
        edkEnd();
        return ret;
    }
    edkEnd();
    return false;
}
