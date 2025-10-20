#include "Interpolation4DTracks.h"

/*
Biblioteca C++ Interpolation4DTracks - Manage one or more interpolation tracks 4D in Edk Game Engine
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
#pragma message "            Inside Interpolation4DTracks.cpp"
#endif

edk::animation::Interpolation4DTracks::Interpolation4DTracks(){
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::Interpolation4DTracks::~Interpolation4DTracks(){
    this->Destructor();
}

void edk::animation::Interpolation4DTracks::Constructor(){
    edk::animation::Interpolation3DTracks::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();

        this->tracks = &this->stack;
    }
}
void edk::animation::Interpolation4DTracks::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->stack.Destructor();
    }
    edk::animation::Interpolation3DTracks::Destructor();
}

edk::animation::InterpolationGroup* edk::animation::Interpolation4DTracks::newInterpolationGroup(){
    return (edk::animation::Interpolation4DGroup*) new edk::animation::Interpolation4DGroup;
}

//Add a first interpolation
bool edk::animation::Interpolation4DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::float32 startSecond,
                                                                      edk::float32 startX,
                                                                      edk::float32 startY,
                                                                      edk::float32 startZ,
                                                                      edk::float32 startW,
                                                                      edk::float32 endSecond,
                                                                      edk::float32 endX,
                                                                      edk::float32 endY,
                                                                      edk::float32 endZ,
                                                                      edk::float32 endW
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->addFirstInterpolationLine(startSecond,startX,startY,startZ,startW,endSecond,endX,endY,endZ,endW);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::float32 startSecond,
                                                                      edk::vec4f32 startValue,
                                                                      edk::float32 endSecond,
                                                                      edk::vec4f32 endValue
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->addFirstInterpolationLine(startSecond,startValue,endSecond,endValue);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::animation::Frame4D start,
                                                                      edk::animation::Frame4D end
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->addFirstInterpolationLine(start,end);
    }
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation4DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->addNewInterpolationLine(second,x,y,z,w);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::vec4f32 value){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->addNewInterpolationLine(second,value);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame4D frame){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->addNewInterpolationLine(frame);
    }
    return false;
}

//Set the frame value
bool edk::animation::Interpolation4DTracks::setFrame4D(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->setFrame4D(second,x,y,z,w);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::setFrameW(edk::uint32 trackPosition,edk::float32 second,edk::float32 w){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->setFrameW(second,w);
    }
    return false;
}

//Set one interpolation Y as a curve
bool edk::animation::Interpolation4DTracks::setInterpolationCurveW(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->setInterpolationCurveW(position);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::setInterpolationNotCurveW(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->setInterpolationNotCurveW(position);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::getInterpolationIsCurveW(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->getInterpolationIsCurveW(position);
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation4DTracks::setConstantW(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->setConstantW(position);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::setLinearW(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->setLinearW(position);
    }
    return false;
}
//set all as constant interpolation
bool edk::animation::Interpolation4DTracks::setAllConstantW(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        group->setAllConstantW();
        return true;
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::setAllLinearW(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        group->setAllLinearW();
        return true;
    }
    return false;
}
//Set the interpolation curve points
bool edk::animation::Interpolation4DTracks::setInterpolationP1W(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 w){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->setInterpolationP1W(position,second,w);
    }
    return false;
}
bool edk::animation::Interpolation4DTracks::setInterpolationP2W(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 w){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->setInterpolationP2W(position,second,w);
    }
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation4DTracks::getClockW(){
    edk::animation::Interpolation4DTracks::StackTracks4D* temp = (edk::animation::Interpolation4DTracks::StackTracks4D*)this->tracks;
    temp->w = 0.f;
    //update the calculate all X from the tracks
    temp->render();
    //return the W
    return temp->w;
}
edk::float32 edk::animation::Interpolation4DTracks::getClockW(edk::float32 w){
    edk::animation::Interpolation4DTracks::StackTracks4D* temp = (edk::animation::Interpolation4DTracks::StackTracks4D*)this->tracks;
    temp->w = w;
    //update the calculate all X from the tracks
    temp->render();
    //return the W
    return temp->w;
}
//return the interpolation W
edk::float32 edk::animation::Interpolation4DTracks::getInterpolationStartW(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->getInterpolationStartW(position);
    }
    return false;
}
edk::float32 edk::animation::Interpolation4DTracks::getInterpolationEndW(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->getInterpolationEndW(position);
    }
    return false;
}
//return the animation start and end in W
edk::float32 edk::animation::Interpolation4DTracks::getAnimationStartW(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->getAnimationStartW();
    }
    return false;
}
edk::float32 edk::animation::Interpolation4DTracks::getAnimationEndW(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation4DGroup* group = (edk::animation::Interpolation4DGroup*)temp.animation;
        return group->getAnimationEndW();
    }
    return false;
}
//write to XML
bool edk::animation::Interpolation4DTracks::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks4D_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->tracks->size();
                        if(size){
                            edk::animation::InterpolationTracks::AnimationAndPosition temp;
                            edk::animation::Interpolation3DGroup* group;
                            edk::char8* trackID = NULL;
                            edk::char8* trackName = NULL;
                            edk::uint32 counter=0u;
                            for(edk::uint32 i=0u;i<size;i++){
                                temp = this->tracks->get(i);
                                group = (edk::animation::Interpolation3DGroup*)temp.animation;
                                if(group){
                                    trackID = edk::String::int64ToStr(counter);
                                    if(trackID){
                                        trackName = edk::String::strCat((edk::char8*)"animTrack4D_",trackID);
                                        if(trackName){
                                            //add the track
                                            xml->addSelectedNextChild("animTrack4D_");
                                            if(xml->selectChild("animTrack4D_")){
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
bool edk::animation::Interpolation4DTracks::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks4D_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //
                    edk::animation::InterpolationTracks::AnimationAndPosition temp;
                    edk::animation::Interpolation3DGroup* group;
                    edk::char8* trackID = NULL;
                    edk::char8* trackName = NULL;
                    edk::uint32 counter=0u;
                    edk::uint32 position=0u;
                    bool running=true;
                    while(running){
                        //generate the strings
                        trackID = edk::String::int64ToStr(counter);
                        if(trackID){
                            trackName = edk::String::strCat((edk::char8*)"animTrack4D_",trackID);
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
                                        group = (edk::animation::Interpolation3DGroup*)temp.animation;
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
