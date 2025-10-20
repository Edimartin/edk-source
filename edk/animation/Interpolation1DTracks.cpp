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

#ifdef printMessages
#pragma message "            Inside Interpolation1DTracks.cpp"
#endif

edk::animation::Interpolation1DTracks::Interpolation1DTracks(){
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::Interpolation1DTracks::~Interpolation1DTracks(){
    this->Destructor();
}

void edk::animation::Interpolation1DTracks::Constructor(){
    edk::animation::InterpolationTracks::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();

        this->tracks = &this->stack;
    }
}
void edk::animation::Interpolation1DTracks::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->stack.Destructor();
    }
    edk::animation::InterpolationTracks::Destructor();
}

edk::animation::InterpolationGroup* edk::animation::Interpolation1DTracks::newInterpolationGroup(){
    return (edk::animation::InterpolationGroup*) new edk::animation::Interpolation1DGroup;
}


//Add a first interpolation
bool edk::animation::Interpolation1DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond, edk::float32 startX, edk::float32 endSecond,edk::float32 endX){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->addFirstInterpolationLine(startSecond,startX, endSecond,endX);
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame1D start,edk::animation::Frame1D end){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->addFirstInterpolationLine(start,end);
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::float32 startSecond,edk::float32 endSecond){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->addFirstInterpolationLine(startSecond,endSecond);
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame start,edk::animation::Frame end){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->addFirstInterpolationLine(start,end);
    }

    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation1DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->addNewInterpolationLine(second,x);
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame1D frame){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->addNewInterpolationLine(frame);
    }

    return false;
}

//Set the frame value
bool edk::animation::Interpolation1DTracks::setFrameX(edk::uint32 trackPosition,edk::float32 second,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->setFrameX(second,x);
    }

    return false;
}

//Set one interpolation X as a curve
bool edk::animation::Interpolation1DTracks::setInterpolationCurveX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->setInterpolationCurveX(position);
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::setInterpolationNotCurveX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->setInterpolationNotCurveX(position);
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::getInterpolationIsCurveX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->getInterpolationIsCurveX(position);
    }

    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation1DTracks::setConstantX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->setConstantX(position);
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::setLinearX(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->setLinearX(position);
    }

    return false;
}
//set all as constant interpolation
bool edk::animation::Interpolation1DTracks::setAllConstantX(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;
        group->setAllConstantX();

        return true;
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::setAllLinearX(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;
        group->setAllLinearX();

        return true;
    }

    return false;
}
//Set the interpolation curve points
bool edk::animation::Interpolation1DTracks::setInterpolationP1X(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->setInterpolationP1X(position,second,x);
    }

    return false;
}
bool edk::animation::Interpolation1DTracks::setInterpolationP2X(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->setInterpolationP2X(position,second,x);
    }

    return false;
}

//create random animations
//shake
edk::float32 edk::animation::Interpolation1DTracks::addShakingFramesX(edk::uint32 trackPosition,edk::float32 position,edk::float32 percent,edk::float32 interpolationDistance){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->addShakingFramesX(position,percent,interpolationDistance);
    }

    return false;
}

//set the animationSecond by the X
bool edk::animation::Interpolation1DTracks::setSecondByX(edk::uint32 trackPosition,edk::float32 oldSecond,edk::float32 x){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->setSecondByX(oldSecond,x);
    }

    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation1DTracks::getClockX(){
    edk::animation::Interpolation1DTracks::StackTracks1D* temp = (edk::animation::Interpolation1DTracks::StackTracks1D*)this->tracks;
    temp->x = 0.f;
    //update the calculate all X from the tracks
    temp->load();
    //return the X

    return temp->x;
}
edk::float32 edk::animation::Interpolation1DTracks::getClockX(edk::float32 x){
    edk::animation::Interpolation1DTracks::StackTracks1D* temp = (edk::animation::Interpolation1DTracks::StackTracks1D*)this->tracks;
    temp->x = x;
    //update the calculate all X from the tracks
    temp->load();
    //return the X

    return temp->x;
}
//return the interpolation seconds
edk::float32 edk::animation::Interpolation1DTracks::getInterpolationStartX(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->getInterpolationStartX(position);
    }

    return false;
}
edk::float32 edk::animation::Interpolation1DTracks::getInterpolationEndX(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->getInterpolationEndX(position);
    }

    return false;
}
//return the animation start and end in X
edk::float32 edk::animation::Interpolation1DTracks::getAnimationStartX(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->getAnimationStartX();
    }

    return false;
}
edk::float32 edk::animation::Interpolation1DTracks::getAnimationEndX(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation1DGroup* group = (edk::animation::Interpolation1DGroup*)temp.animation;

        return group->getAnimationEndX();
    }

    return false;
}
//write to XML
bool edk::animation::Interpolation1DTracks::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks1D_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->tracks->size();
                        if(size){
                            edk::animation::InterpolationTracks::AnimationAndPosition temp;
                            edk::animation::Interpolation1DGroup* group;
                            edk::char8* trackID = NULL;
                            edk::char8* trackName = NULL;
                            edk::uint32 counter=0u;
                            for(edk::uint32 i=0u;i<size;i++){
                                temp = this->tracks->get(i);
                                group = (edk::animation::Interpolation1DGroup*)temp.animation;
                                if(group){
                                    trackID = edk::String::int64ToStr(counter);
                                    if(trackID){
                                        trackName = edk::String::strCat((edk::char8*)"animTrack1D_",trackID);
                                        if(trackName){
                                            //add the track
                                            xml->addSelectedNextChild("animTrack1D_");
                                            if(xml->selectChild("animTrack1D_")){
                                                xml->setSelectedString(temp.number);
                                                //write the animation
                                                group->writeToXML(xml,counter);
                                                ++counter;
                                                xml->selectFather();
                                            }
                                            free(trackName);
                                        }
                                        free(trackID);
                                    }
                                }
                            }
                        }
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
bool edk::animation::Interpolation1DTracks::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks1D_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //
                    edk::animation::InterpolationTracks::AnimationAndPosition temp;
                    edk::animation::Interpolation1DGroup* group;
                    edk::char8* trackID = NULL;
                    edk::char8* trackName = NULL;
                    edk::uint32 counter=0u;
                    edk::uint32 position=0u;
                    bool running=true;
                    while(running){
                        //generate the strings
                        trackID = edk::String::int64ToStr(counter);
                        if(trackID){
                            trackName = edk::String::strCat((edk::char8*)"animTrack1D_",trackID);
                            if(trackName){
                                //select the child
                                if(xml->selectChild(trackID)){
                                    //read the string
                                    temp.number = xml->getSelectedStringAsUint32();
                                    //create a new track
                                    position = this->newTrack(temp.number);
                                    if(position<this->tracks->size()){
                                        //get the track and read the XML
                                        temp=this->tracks->get(position);
                                        group = (edk::animation::Interpolation1DGroup*)temp.animation;
                                        if(group){
                                            temp.animation->readFromXML(xml,counter);
                                        }
                                    }
                                    else{
                                        running=false;
                                    }
                                    xml->selectFather();
                                }
                                free(trackName);
                            }
                            free(trackID);
                        }
                        counter++;
                    }
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
