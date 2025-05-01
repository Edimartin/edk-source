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
    this->classThis=NULL;
    this->Constructor();
}

edk::animation::InterpolationLine4D::~InterpolationLine4D(){
    this->Destructor();
}

void edk::animation::InterpolationLine4D::Constructor(){
    edk::animation::InterpolationLine3D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        //ctor
        this->allocStart();
        this->allocEnd();
        this->curveW=false;
        this->constantW=false;
    }
}
void edk::animation::InterpolationLine4D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::animation::InterpolationLine3D::Destructor();
}

//set new
edk::animation::Frame* edk::animation::InterpolationLine4D::useNewFrame(edk::uint8 count,edk::float32 values,...){
    //
    edk::float32* value = &values;
    switch(count){
    case 1:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],0.0f,0.0f,0.0f,0.0f));
    case 2:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],value[1u],0.0f,0.0f,0.0f));
    case 3:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],value[1u],value[2u],0.0f,0.0f));
    case 4:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],value[1u],value[2u],value[3u],0.f));
    case 5:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame4D(value[0u],value[1u],value[2u],value[3u],value[4u]));
    default:

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
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->start;
        temp->w=frame->w;
        return true;
    }
    return false;
}
bool edk::animation::InterpolationLine4D::setStart(edk::float32 second,edk::vec4f32 value){
    //
    return this->setStart(second,value.x,value.y,value.z,value.w);
}
bool edk::animation::InterpolationLine4D::setStart(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //
    if(edk::animation::InterpolationLine3D::setStart(second,x,y,z)){
        //
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->start;
        temp->w=w;
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine4D::setStartValue(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //test if are using a frame alloc
    if(edk::animation::InterpolationLine3D::setStartValue(x,y,z)){
        //
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->start;
        temp->w=w;
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
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->end;
        temp->w=frame->w;
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine4D::setEnd(edk::float32 second,edk::vec4f32 value){
    //
    return this->setEnd(second,value.x,value.y,value.z,value.w);
}
bool edk::animation::InterpolationLine4D::setEnd(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //
    if(edk::animation::InterpolationLine3D::setEnd(second,x,y,z)){
        //
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->end;
        temp->w=w;
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine4D::setEndValue(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    //test if are using a frame alloc
    if(edk::animation::InterpolationLine3D::setEndValue(x,y,z)){
        //
        edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->end;
        temp->w=w;
        //return true
        return true;
    }
    //else return false
    return false;
}
//set the points in the curve
bool edk::animation::InterpolationLine4D::setP1W(edk::float32 second,edk::float32 w){
    bool ret=true;
    //filter the second
    if(second<this->start->second){
        second = this->start->second;
        ret=false;
    }
    if(second>this->end->second){
        second = this->end->second;
        ret=false;
    }

    //set the position
    this->p1W.width = second;
    this->p1W.height = w;

    return ret;
}
bool edk::animation::InterpolationLine4D::setP2W(edk::float32 second,edk::float32 w){
    bool ret=true;
    //filter the second
    if(second<this->start->second){
        second = this->start->second;
        ret=false;
    }
    if(second>this->end->second){
        second = this->end->second;
        ret=false;
    }

    //set the position
    this->p2W.width = second;
    this->p2W.height = w;

    return ret;
}

//Set as a curve
bool edk::animation::InterpolationLine4D::setCurveW(bool curve){
    if(this->curveW!=curve){
        this->curveW = curve;

        edk::animation::Frame4D* tempStart = (edk::animation::Frame4D*)this->start;
        edk::animation::Frame4D* tempEnd = (edk::animation::Frame4D*)this->end;

        if(this->curveW){
            edk::size2f32 dist = edk::size2f32(tempEnd->second - tempStart->second,
                                               tempEnd->w - tempStart->w
                                               );
            this->p1W = dist*0.25;
            this->p2W = dist*0.75;
        }
        else{
            this->p1W.width = tempStart->second;
            this->p1W.height = tempStart->w;
            this->p2W.width = tempEnd->second;
            this->p2W.height = tempEnd->w;
        }

        return true;
    }
    return false;
}
void edk::animation::InterpolationLine4D::isCurveW(){
    this->setCurveW(true);
}
void edk::animation::InterpolationLine4D::isNotCurveW(){
    this->setCurveW(false);
}
bool edk::animation::InterpolationLine4D::getCurveW(){
    return this->curveW;
}
//set as constant interpolation
void edk::animation::InterpolationLine4D::setConstantW(){
    this->constantW=true;
    this->setCurveW(false);
}
void edk::animation::InterpolationLine4D::setLinearW(){
    this->constantW=false;
    this->setCurveW(false);
}

//GETERS
//return the start
edk::animation::Frame4D edk::animation::InterpolationLine4D::getStart4D(){
    //convert the frame to return
    edk::animation::Frame4D* ret = (edk::animation::Frame4D*)this->start;
    return *ret;
}
//return the end
edk::animation::Frame4D edk::animation::InterpolationLine4D::getEnd4D(){
    //convert the frame to return
    edk::animation::Frame4D* ret = (edk::animation::Frame4D*)this->end;
    return *ret;
}

//return the position in the second
edk::float32 edk::animation::InterpolationLine4D::getPositionW(edk::float32 second){
    //convert the two frames
    edk::animation::Frame4D* retStart = (edk::animation::Frame4D*)this->start;
    edk::animation::Frame4D* retEnd = (edk::animation::Frame4D*)this->end;
    if(this->constantW){
        return retStart->w;
    }
    //else test the linear or curve

    edk::float32 percent = ((second - retStart->second)/ distance);
    if(percent>=1.f){
        return retEnd->w;
    }
    else if(percent<=0.f){
        return retStart->w;
    }
    //test if is a curve
    if(this->curveW){
        edk::shape::Bezier2D bezier(edk::vec2f32(retStart->second,retStart->w),
                                    edk::vec2f32(this->p1W.width,this->p1W.height),
                                    edk::vec2f32(this->p2W.width,this->p2W.height),
                                    edk::vec2f32(retEnd->second,retEnd->w)
                                    );
        return bezier.getPoint(percent).y;
    }
    return retStart->w+((retEnd->w-retStart->w) *
                        percent
                        );
}

//write to XML
bool edk::animation::InterpolationLine4D::writeToXMLStart(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->start;
    return temp->writeToXML(xml,frameID);
}
bool edk::animation::InterpolationLine4D::writeToXMLEnd(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame4D* temp = (edk::animation::Frame4D*)this->end;
    return temp->writeToXML(xml,frameID);
}

//write curve
bool edk::animation::InterpolationLine4D::writeCurveToXML(edk::XML* xml,edk::uint32 curveID){
    bool ret=edk::animation::InterpolationLine3D::writeCurveToXML(xml,curveID);
    if(xml && this->curveW){
        edk::char8* nameID = edk::String::int64ToStr(curveID);
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveW_",nameID);
            if(name){
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = NULL;
                        //
                        temp = edk::String::float32ToStr(this->p1W.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1W",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->p1W.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1H",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->p2W.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p2W",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->p2W.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p2H",temp);
                            free(temp);
                        }

                        xml->selectFather();
                        ret=true;
                    }
                }
                free(name);
            }
            free(nameID);
        }
    }
    return ret;
}
//read the curve
bool edk::animation::InterpolationLine4D::readCurveFromXML(edk::XML* xml,edk::uint32 curveID){
    bool ret=edk::animation::InterpolationLine3D::readCurveFromXML(xml,curveID);
    if(xml && this->curveW){
        edk::char8* nameID = edk::String::int64ToStr(curveID);
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveY_",nameID);
            if(name){
                if(xml->selectChild(name)){
                    //read the values
                    this->p1W.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1W"));
                    this->p1W.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1H"));
                    this->p2W.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2W"));
                    this->p2W.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2H"));
                    xml->selectFather();
                    ret=true;
                }
                free(name);
            }
            free(nameID);
        }
    }
    return ret;
}
