#include "InterpolationLine4D.h"

/*
Library C++ InterpolationLine - Animate one line interpolation with tree values in Edk Game Engine
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
#pragma message "            Inside InterpolationLine4D.cpp"
#endif

edk::animation::InterpolationLine4D::InterpolationLine4D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::animation::InterpolationLine4D::~InterpolationLine4D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::animation::InterpolationLine4D::Constructor(bool runFather){
    if(runFather){
        edk::animation::InterpolationLine3D::Constructor();
    }
    if(this->classThis!=this){
        this->classThis=this;
        //ctor
        this->allocStart();edkEnd();
        this->allocEnd();edkEnd();
        this->curveW=false;edkEnd();
        this->constantW=false;edkEnd();
    }
}

//set new
edk::animation::Frame* edk::animation::InterpolationLine4D::useNewFrame(edk::uint8 count,edk::float32 values,...){
    //
    edk::float32* value = &values;edkEnd();
    switch(count){
    case 1:
        //
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],0.0f,0.0f,0.0f,0.0f));
    case 2:
        //
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],value[1u],0.0f,0.0f,0.0f));
    case 3:
        //
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],value[1u],value[2u],0.0f,0.0f));
    case 4:
        //
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],value[1u],value[2u],value[3u],0.f));
    case 5:
        //
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],value[1u],value[2u],value[3u],value[4u]));
    default:
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame4D());
    }
    return NULL;
}

//SETERS
//set the start frame
bool edk::animation::InterpolationLine4D::setStart(edk::animation::Frame4D* frame){
    //Set the Frame3D data
    if(edk::animation::InterpolationLine3D::setStart(frame)){
        //convert to set the 3D
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->start;edkEnd();
        temp->w=frame->w;edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationLine4D::setStart(edk::float32 second,edk::vec4f32 value){
    //
    return this->setStart(second,value.x,value.y,value.z,value.w);edkEnd();
}
bool edk::animation::InterpolationLine4D::setStart(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //
    if(edk::animation::InterpolationLine3D::setStart(second,x,y,z)){
        //
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->start;edkEnd();
        temp->w=w;edkEnd();
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine4D::setStartValue(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //test if are using a frame alloc
    if(edk::animation::InterpolationLine3D::setStartValue(x,y,z)){
        //
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->start;edkEnd();
        temp->w=w;edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine4D::setEnd(edk::animation::Frame4D* frame){
    //first test if can set the second and x
    if(edk::animation::InterpolationLine3D::setEnd(frame)){
        //convert to set the Frame4D
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->end;edkEnd();
        temp->w=frame->w;edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine4D::setEnd(edk::float32 second,edk::vec4f32 value){
    //
    return this->setEnd(second,value.x,value.y,value.z,value.w);edkEnd();
}
bool edk::animation::InterpolationLine4D::setEnd(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //
    if(edk::animation::InterpolationLine3D::setEnd(second,x,y,z)){
        //
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->end;edkEnd();
        temp->w=w;edkEnd();
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine4D::setEndValue(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //test if are using a frame alloc
    if(edk::animation::InterpolationLine3D::setEndValue(x,y,z)){
        //
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->end;edkEnd();
        temp->w=w;edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
//set the points in the curve
bool edk::animation::InterpolationLine4D::setP1W(edk::float32 second,edk::float32 w){
    bool ret=true;edkEnd();
    //filter the second
    if(second<this->start->second){
        second = this->start->second;edkEnd();
        ret=false;edkEnd();
    }
    if(second>this->end->second){
        second = this->end->second;edkEnd();
        ret=false;edkEnd();
    }

    //set the position
    this->p1W.width = second;edkEnd();
    this->p1W.height = w;edkEnd();

    return ret;
}
bool edk::animation::InterpolationLine4D::setP2W(edk::float32 second,edk::float32 w){
    bool ret=true;edkEnd();
    //filter the second
    if(second<this->start->second){
        second = this->start->second;edkEnd();
        ret=false;edkEnd();
    }
    if(second>this->end->second){
        second = this->end->second;edkEnd();
        ret=false;edkEnd();
    }

    //set the position
    this->p2W.width = second;edkEnd();
    this->p2W.height = w;edkEnd();

    return ret;
}

//Set as a curve
bool edk::animation::InterpolationLine4D::setCurveW(bool curve){
    if(this->curveW!=curve){
        this->curveW = curve;edkEnd();

        edk::animation::Frame4D* tempStart = (edk::animation::Frame4D*)this->start;edkEnd();
        edk::animation::Frame4D* tempEnd = (edk::animation::Frame4D*)this->end;edkEnd();

        if(this->curveW){
            edk::size2f32 dist = edk::size2f32(tempEnd->second - tempStart->second,
                                               tempEnd->w - tempStart->w
                                               );edkEnd();
            this->p1W = dist*0.25;edkEnd();
            this->p2W = dist*0.75;edkEnd();
        }
        else{
            this->p1W.width = tempStart->second;edkEnd();
            this->p1W.height = tempStart->w;edkEnd();
            this->p2W.width = tempEnd->second;edkEnd();
            this->p2W.height = tempEnd->w;edkEnd();
        }

        return true;
    }
    return false;
}
void edk::animation::InterpolationLine4D::isCurveW(){
    this->setCurveW(true);edkEnd();
}
void edk::animation::InterpolationLine4D::isNotCurveW(){
    this->setCurveW(false);edkEnd();
}
bool edk::animation::InterpolationLine4D::getCurveW(){
    return this->curveW;edkEnd();
}
//set as constant interpolation
void edk::animation::InterpolationLine4D::setConstantW(){
    this->constantW=true;edkEnd();
    this->setCurveW(false);edkEnd();
}
void edk::animation::InterpolationLine4D::setLinearW(){
    this->constantW=false;edkEnd();
    this->setCurveW(false);edkEnd();
}

//GETERS
//return the start
edk::animation::Frame4D edk::animation::InterpolationLine4D::getStart4D(){
    //convert the frame to return
    edk::animation::Frame4D* ret = (edk::animation::Frame4D*)this->start;edkEnd();
    return *ret;edkEnd();
}
//return the end
edk::animation::Frame4D edk::animation::InterpolationLine4D::getEnd4D(){
    //convert the frame to return
    edk::animation::Frame4D* ret = (edk::animation::Frame4D*)this->end;edkEnd();
    return *ret;edkEnd();
}

//return the position in the second
edk::float32 edk::animation::InterpolationLine4D::getPositionW(edk::float32 second){
    //convert the two frames
    edk::animation::Frame4D* retStart = (edk::animation::Frame4D*)this->start;edkEnd();
    edk::animation::Frame4D* retEnd = (edk::animation::Frame4D*)this->end;edkEnd();
    if(this->constantW){
        return retStart->w;edkEnd();
    }
    //else test the linear or curve

    edk::float32 percent = ((second - retStart->second)/ distance);edkEnd();
    if(percent>=1.f){
        return retEnd->w;edkEnd();
    }
    else if(percent<=0.f){
        return retStart->w;edkEnd();
    }
    //test if is a curve
    if(this->curveW){
        edk::shape::Bezier2D bezier(edk::vec2f32(retStart->second,retStart->w),
                                    edk::vec2f32(this->p1W.width,this->p1W.height),
                                    edk::vec2f32(this->p2W.width,this->p2W.height),
                                    edk::vec2f32(retEnd->second,retEnd->w)
                                    );edkEnd();
        return bezier.getPoint(percent).y;edkEnd();
    }
    return retStart->w+((retEnd->w-retStart->w) *
                        percent
                        );edkEnd();
}

//write to XML
bool edk::animation::InterpolationLine4D::writeToXMLStart(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->start;edkEnd();
    return temp->writeToXML(xml,frameID);edkEnd();
}
bool edk::animation::InterpolationLine4D::writeToXMLEnd(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->end;edkEnd();
    return temp->writeToXML(xml,frameID);edkEnd();
}

//write curve
bool edk::animation::InterpolationLine4D::writeCurveToXML(edk::XML* xml,edk::uint32 curveID){
    bool ret=edk::animation::InterpolationLine3D::writeCurveToXML(xml,curveID);edkEnd();
    if(xml && this->curveW){
        edk::char8* nameID = edk::String::int64ToStr(curveID);edkEnd();
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveW_",nameID);edkEnd();
            if(name){
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = NULL;edkEnd();
                        //
                        temp = edk::String::float32ToStr(this->p1W.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1W",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p1W.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1H",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p2W.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p2W",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p2W.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p2H",temp);edkEnd();
                            free(temp);edkEnd();
                        }

                        xml->selectFather();edkEnd();
                        ret=true;edkEnd();
                    }
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
    }
    return ret;
}
//read the curve
bool edk::animation::InterpolationLine4D::readCurveFromXML(edk::XML* xml,edk::uint32 curveID){
    bool ret=edk::animation::InterpolationLine3D::readCurveFromXML(xml,curveID);edkEnd();
    if(xml && this->curveW){
        edk::char8* nameID = edk::String::int64ToStr(curveID);edkEnd();
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveY_",nameID);edkEnd();
            if(name){
                if(xml->selectChild(name)){
                    //read the values
                    this->p1W.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1W"));edkEnd();
                    this->p1W.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1H"));edkEnd();
                    this->p2W.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2W"));edkEnd();
                    this->p2W.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2H"));edkEnd();
                    xml->selectFather();edkEnd();
                    ret=true;edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
    }
    return ret;
}
