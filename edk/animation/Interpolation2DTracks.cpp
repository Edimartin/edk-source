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
}
edk::animation::Interpolation2DTracks::~Interpolation2DTracks(){
    //
}

edk::animation::InterpolationGroup* edk::animation::Interpolation2DTracks::newInterpolationGroup(){
    return (edk::animation::InterpolationGroup*) new edk::animation::Interpolation2DGroup;
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
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->addFirstInterpolationLine(startSecond,startX,startY,endSecond,endX,endY);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::float32 startSecond,
                                                                      edk::vec2f32 startValue,
                                                                      edk::float32 endSecond,
                                                                      edk::vec2f32 endValue
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->addFirstInterpolationLine(startSecond,startValue,endSecond,endValue);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::animation::Frame2D start,
                                                                      edk::animation::Frame2D end
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->addFirstInterpolationLine(start,end);
    }
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation2DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->addNewInterpolationLine(second,x,y);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::vec2f32 value){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->addNewInterpolationLine(second,value);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame2D frame){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->addNewInterpolationLine(frame);
    }
    return false;
}

//Set the frame value
bool edk::animation::Interpolation2DTracks::setFrame2D(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->setFrame2D(second,x,y);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setFrameY(edk::uint32 trackPosition,edk::float32 second,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->setFrameY(second,y);
    }
    return false;
}

//Set one interpolation Y as a curve
bool edk::animation::Interpolation2DTracks::setInterpolationCurveY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->setInterpolationCurveY(position);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setInterpolationNotCurveY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->setInterpolationNotCurveY(position);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::getInterpolationIsCurveY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->getInterpolationIsCurveY(position);
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation2DTracks::setConstantY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->setConstantY(position);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setLinearY(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->setLinearY(position);
    }
    return false;
}
//set all as constant interpolation
bool edk::animation::Interpolation2DTracks::setAllConstantY(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        group->setAllConstantY();
        return true;
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setAllLinearY(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        group->setAllLinearY();
        return true;
    }
    return false;
}
//Set the interpolation curve points
bool edk::animation::Interpolation2DTracks::setInterpolationP1Y(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->setInterpolationP1Y(position,second,y);
    }
    return false;
}
bool edk::animation::Interpolation2DTracks::setInterpolationP2Y(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 y){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->setInterpolationP2Y(position,second,y);
    }
    return false;
}

//create random animations
//shake
edk::float32 edk::animation::Interpolation2DTracks::addShakingFramesXY(edk::uint32 trackPosition,edk::vec2f32 position,edk::float32 random,edk::float32 percent,edk::float32 interpolationDistance){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->addShakingFramesXY(position,random,percent,interpolationDistance);
    }
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation2DTracks::getClockY(){
    this->tracks.y = 0.f;
    //update the calculate all X from the tracks
    this->tracks.print();
    //return the Y
    return this->tracks.y;
}
//return the interpolation Y
edk::float32 edk::animation::Interpolation2DTracks::getInterpolationStartY(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->getInterpolationStartY(position);
    }
    return false;
}
edk::float32 edk::animation::Interpolation2DTracks::getInterpolationEndY(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->getInterpolationEndY(position);
    }
    return false;
}
//return the animation start and end in Y
edk::float32 edk::animation::Interpolation2DTracks::getAnimationStartY(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->getAnimationStartY();
    }
    return false;
}
edk::float32 edk::animation::Interpolation2DTracks::getAnimationEndY(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks.get(trackPosition);
    if(temp.animation){
        edk::animation::Interpolation2DGroup* group = (edk::animation::Interpolation2DGroup*)temp.animation;
        return group->getAnimationEndY();
    }
    return false;
}
//write to XML
bool edk::animation::Interpolation2DTracks::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks2D_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->tracks.size();
                        if(size){
                            edk::animation::InterpolationTracks::AnimationAndPosition temp;
                            edk::animation::Interpolation2DGroup* group;
                            edk::char8* trackID = NULL;
                            edk::char8* trackName = NULL;
                            edk::uint32 counter=0u;
                            for(edk::uint32 i=0u;i<size;i++){
                                temp = this->tracks.get(i);
                                group = (edk::animation::Interpolation2DGroup*)temp.animation;
                                if(group){
                                    trackID = edk::String::int64ToStr(counter);
                                    if(trackID){
                                        trackName = edk::String::strCat((edk::char8*)"animTrack2D_",trackID);
                                        if(trackName){
                                            //add the track
                                            xml->addSelectedNextChild("animTrack2D_");
                                            if(xml->selectChild("animTrack2D_")){
                                                xml->setSelectedString(temp.number);
                                                //write the animation
                                                group->writeToXML(xml,counter);
                                                ++counter;
                                                xml->selectFather();
                                            }
                                            delete[] trackName;
                                        }
                                        delete[] trackID;
                                    }
                                }
                            }
                        }
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
bool edk::animation::Interpolation2DTracks::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks2D_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //
                    edk::animation::InterpolationTracks::AnimationAndPosition temp;
                    edk::animation::Interpolation2DGroup* group;
                    edk::char8* trackID = NULL;
                    edk::char8* trackName = NULL;
                    edk::uint32 counter=0u;
                    edk::uint32 position=0u;
                    bool running=true;
                    while(running){
                        //generate the strings
                        trackID = edk::String::int64ToStr(counter);
                        if(trackID){
                            trackName = edk::String::strCat((edk::char8*)"animTrack2D_",trackID);
                            if(trackName){
                                //select the child
                                if(xml->selectChild(trackID)){
                                    //read the string
                                    temp.number = xml->getSelectedStringAsUint32();
                                    //create a new track
                                    position = this->newTrack(temp.number);
                                    if(position<this->tracks.size()){
                                        //get the track and read the XML
                                        temp=this->tracks.get(position);
                                        group = (edk::animation::Interpolation2DGroup*)temp.animation;
                                        if(group){
                                            temp.animation->readFromXML(xml,counter);
                                        }
                                    }
                                    else{
                                        running=false;
                                    }
                                    xml->selectFather();
                                }
                                delete[] trackName;
                            }
                            delete[] trackID;
                        }
                        counter++;
                    }
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
