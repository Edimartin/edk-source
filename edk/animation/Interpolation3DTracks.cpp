#include "Interpolation3DTracks.h"

/*
Biblioteca C++ Interpolation3DTracks - Manage one or more interpolation tracks 3D in Edk Game Engine
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

edk::animation::Interpolation3DTracks::Interpolation3DTracks(){
    //
    this->tracks = &this->stack;edkEnd();
}
edk::animation::Interpolation3DTracks::~Interpolation3DTracks(){
    //
}

edk::animation::InterpolationGroup* edk::animation::Interpolation3DTracks::newInterpolationGroup(){
    return (edk::animation::Interpolation3DGroup*) new edk::animation::Interpolation3DGroup;edkEnd();
}

//Add a first interpolation
bool edk::animation::Interpolation3DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::float32 startSecond,
                                                                      edk::float32 startX,
                                                                      edk::float32 startY,
                                                                      edk::float32 startZ,
                                                                      edk::float32 endSecond,
                                                                      edk::float32 endX,
                                                                      edk::float32 endY,
                                                                      edk::float32 endZ
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->addFirstInterpolationLine(startSecond,startX,startY,startZ,endSecond,endX,endY,endZ);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::float32 startSecond,
                                                                      edk::vec3f32 startValue,
                                                                      edk::float32 endSecond,
                                                                      edk::vec3f32 endValue
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->addFirstInterpolationLine(startSecond,startValue,endSecond,endValue);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::addFirstInterpolationLine(edk::uint32 trackPosition,
                                                                      edk::animation::Frame3D start,
                                                                      edk::animation::Frame3D end
                                                                      ){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->addFirstInterpolationLine(start,end);edkEnd();
    }
    return false;
}

//Add New Interpolation
bool edk::animation::Interpolation3DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->addNewInterpolationLine(second,x,y,z);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::float32 second,edk::vec3f32 value){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->addNewInterpolationLine(second,value);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::addNewInterpolationLine(edk::uint32 trackPosition,edk::animation::Frame3D frame){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->addNewInterpolationLine(frame);edkEnd();
    }
    return false;
}

//Set the frame value
bool edk::animation::Interpolation3DTracks::setFrame3D(edk::uint32 trackPosition,edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->setFrame3D(second,x,y,z);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::setFrameZ(edk::uint32 trackPosition,edk::float32 second,edk::float32 z){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->setFrameZ(second,z);edkEnd();
    }
    return false;
}

//Set one interpolation Y as a curve
bool edk::animation::Interpolation3DTracks::setInterpolationCurveZ(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->setInterpolationCurveZ(position);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::setInterpolationNotCurveZ(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->setInterpolationNotCurveZ(position);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::getInterpolationIsCurveZ(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->getInterpolationIsCurveZ(position);edkEnd();
    }
    return false;
}
//set as constant interpolation
bool edk::animation::Interpolation3DTracks::setConstantZ(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->setConstantZ(position);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::setLinearZ(edk::uint32 trackPosition,edk::uint32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->setLinearZ(position);edkEnd();
    }
    return false;
}
//set all as constant interpolation
bool edk::animation::Interpolation3DTracks::setAllConstantZ(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        group->setAllConstantZ();edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::setAllLinearZ(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        group->setAllLinearZ();edkEnd();
        return true;
    }
    return false;
}
//Set the interpolation curve points
bool edk::animation::Interpolation3DTracks::setInterpolationP1Z(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 z){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->setInterpolationP1Z(position,second,z);edkEnd();
    }
    return false;
}
bool edk::animation::Interpolation3DTracks::setInterpolationP2Z(edk::uint32 trackPosition,edk::uint32 position,edk::float32 second,edk::float32 z){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->setInterpolationP2Z(position,second,z);edkEnd();
    }
    return false;
}

//GETERS
//return the animationPosition
edk::float32 edk::animation::Interpolation3DTracks::getClockZ(){
    edk::animation::Interpolation3DTracks::StackTracks3D* temp = (edk::animation::Interpolation3DTracks::StackTracks3D*)this->tracks;edkEnd();
    temp->z = 0.f;edkEnd();
    //update the calculate all X from the tracks
    temp->render();edkEnd();
    //return the Z
    return temp->z;edkEnd();
}
edk::float32 edk::animation::Interpolation3DTracks::getClockZ(edk::float32 z){
    edk::animation::Interpolation3DTracks::StackTracks3D* temp = (edk::animation::Interpolation3DTracks::StackTracks3D*)this->tracks;edkEnd();
    temp->z = z;edkEnd();
    //update the calculate all X from the tracks
    temp->render();edkEnd();
    //return the Z
    return temp->z;edkEnd();
}
//return the interpolation Z
edk::float32 edk::animation::Interpolation3DTracks::getInterpolationStartZ(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->getInterpolationStartZ(position);edkEnd();
    }
    return false;
}
edk::float32 edk::animation::Interpolation3DTracks::getInterpolationEndZ(edk::uint32 trackPosition,edk::float32 position){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->getInterpolationEndZ(position);edkEnd();
    }
    return false;
}
//return the animation start and end in Z
edk::float32 edk::animation::Interpolation3DTracks::getAnimationStartZ(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->getAnimationStartZ();edkEnd();
    }
    return false;
}
edk::float32 edk::animation::Interpolation3DTracks::getAnimationEndZ(edk::uint32 trackPosition){
    edk::animation::InterpolationTracks::AnimationAndPosition temp = this->tracks->get(trackPosition);edkEnd();
    if(temp.animation){
        edk::animation::Interpolation3DGroup* group = (edk::animation::Interpolation3DGroup*)temp.animation;edkEnd();
        return group->getAnimationEndZ();edkEnd();
    }
    return false;
}
//write to XML
bool edk::animation::Interpolation3DTracks::writeToXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks3D_",nameID);edkEnd();
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
                                        trackName = edk::String::strCat((edk::char8*)"animTrack3D_",trackID);edkEnd();
                                        if(trackName){
                                            //add the track
                                            xml->addSelectedNextChild("animTrack3D_");edkEnd();
                                            if(xml->selectChild("animTrack3D_")){
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
bool edk::animation::Interpolation3DTracks::readFromXML(edk::XML* xml,edk::uint32 id){
    //test the XML
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"animTracks3D_",nameID);edkEnd();
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
                            trackName = edk::String::strCat((edk::char8*)"animTrack3D_",trackID);edkEnd();
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
