#include "InterpolationLine1D.h"

/*
Library C++ InterpolationLine - Animate one line interpolation with one value in Edk Game Engine
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
#pragma message "            Inside InterpolationLine1D.cpp"
#endif

edk::animation::InterpolationLine1D::InterpolationLine1D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::animation::InterpolationLine1D::~InterpolationLine1D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::animation::InterpolationLine1D::Constructor(bool runFather){
    if(runFather){
        edk::animation::InterpolationLine::Constructor();
    }
    if(this->classThis!=this){
        this->classThis=this;
        //ctor
        this->allocStart();edkEnd();
        this->allocEnd();edkEnd();
        this->curveX=false;edkEnd();
        this->constantX=false;edkEnd();
    }
}

//set new
edk::animation::Frame* edk::animation::InterpolationLine1D::useNewFrame(edk::uint8 count,edk::float32 values,...){
    //
    edk::float32* value = &values;edkEnd();
    switch(count){
    case 1:
        //
        return (edk::animation::Frame*)(new edk::animation::Frame1D(value[0],0.0f));
    case 2:
        //
        return (edk::animation::Frame*)(new edk::animation::Frame1D(value[0],value[2]));
    default:
        return (edk::animation::Frame*)(new edk::animation::Frame1D());
    }
    return NULL;
}

//SETERS
//set the start frame
bool edk::animation::InterpolationLine1D::setStart(edk::animation::Frame1D* frame){
    //Set the frame1D data
    if(edk::animation::InterpolationLine1D::setStart(frame)){
        //convert to set the 1D
        edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->start;edkEnd();
        temp->x=frame->x;edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationLine1D::setStart(edk::float32 second,edk::float32 x){
    //
    if(edk::animation::InterpolationLine::setStart(second)){
        //
        edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->start;edkEnd();
        temp->x=x;edkEnd();
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine1D::setStartValue(edk::float32 x){
    //test if are using a frame alloc
    //if(edk::animation::InterpolationLine::setStartValue(x)){
    //
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->start;edkEnd();
    temp->x=x;edkEnd();
    //return true
    return true;
    //}
    //else return false
    return false;
}
bool edk::animation::InterpolationLine1D::setEnd(edk::animation::Frame1D* frame){
    //first test if can set the second and x
    if(edk::animation::InterpolationLine::setEnd(frame)){
        //convert to set the Frame1D
        edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->end;edkEnd();
        temp->x=frame->x;edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine1D::setEnd(edk::float32 second,edk::float32 x){
    //
    if(edk::animation::InterpolationLine::setEnd(second)){
        //
        edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->end;edkEnd();
        temp->x=x;edkEnd();
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine1D::setEndValue(edk::float32 x){
    //test if are using a frame alloc
    //if(edk::animation::InterpolationLine::setEndValue(x)){
    //
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->end;edkEnd();
    temp->x=x;edkEnd();
    //return true
    return true;
    //}
    //else return false
    return false;
}
//set the points in the curve
bool edk::animation::InterpolationLine1D::setP1X(edk::float32 second,edk::float32 x){
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
    this->p1X.width = second;edkEnd();
    this->p1X.height = x;edkEnd();

    return ret;
}
bool edk::animation::InterpolationLine1D::setP2X(edk::float32 second,edk::float32 x){
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
    this->p2X.width = second;edkEnd();
    this->p2X.height = x;edkEnd();

    return ret;
}

//Set as a curve
bool edk::animation::InterpolationLine1D::setCurveX(bool curve){
    if(this->curveX!=curve){
        this->curveX = curve;edkEnd();

        edk::animation::Frame1D* tempStart = (edk::animation::Frame1D*)this->start;edkEnd();
        edk::animation::Frame1D* tempEnd = (edk::animation::Frame1D*)this->end;edkEnd();

        if(this->curveX){
            edk::size2f32 dist = edk::size2f32(tempEnd->second - tempStart->second,
                                               tempEnd->x - tempStart->x
                                               );edkEnd();
            this->p1X = dist*0.25;edkEnd();
            this->p2X = dist*0.75;edkEnd();

            this->constantX=false;edkEnd();
        }
        else{
            this->p1X.width = tempStart->second;edkEnd();
            this->p1X.height = tempStart->x;edkEnd();
            this->p2X.width = tempEnd->second;edkEnd();
            this->p2X.height = tempEnd->x;edkEnd();
        }

        return true;
    }
    return false;
}
void edk::animation::InterpolationLine1D::isCurveX(){
    this->setCurveX(true);edkEnd();
}
void edk::animation::InterpolationLine1D::isNotCurveX(){
    this->setCurveX(false);edkEnd();
}
bool edk::animation::InterpolationLine1D::getCurveX(){
    return this->curveX;edkEnd();
}
//set as constant interpolation
void edk::animation::InterpolationLine1D::setConstantX(){
    this->constantX = true;edkEnd();
    this->setCurveX(false);edkEnd();
}
void edk::animation::InterpolationLine1D::setLinearX(){
    this->constantX=false;edkEnd();
    this->setCurveX(false);edkEnd();
}

//GETERS
//return the start
edk::animation::Frame1D edk::animation::InterpolationLine1D::getStart1D(){
    //convert the frame to return
    edk::animation::Frame1D* ret = (edk::animation::Frame1D*)this->start;edkEnd();
    ret->cantDestruct();edkEnd();
    return *ret;edkEnd();
}
//return the end
edk::animation::Frame1D edk::animation::InterpolationLine1D::getEnd1D(){
    //convert the frame to return
    edk::animation::Frame1D* ret = (edk::animation::Frame1D*)this->end;edkEnd();
    ret->cantDestruct();edkEnd();
    return *ret;edkEnd();
}

//return the position in the second
edk::float32 edk::animation::InterpolationLine1D::getPositionX(edk::float32 second){
    //convert the two frames
    edk::animation::Frame1D* retStart = (edk::animation::Frame1D*)this->start;edkEnd();
    edk::animation::Frame1D* retEnd = (edk::animation::Frame1D*)this->end;edkEnd();
    if(this->constantX){
        return retStart->x;edkEnd();
    }
    //else test the linear or curve

    edk::float32 percent = ((second - retStart->second)/ distance);edkEnd();
    if(percent>=1.f){
        return retEnd->x;edkEnd();
    }
    else if(percent<=0.f){
        return retStart->x;edkEnd();
    }
    //test if is a curve
    if(this->curveX){
        edk::shape::Bezier2D bezier(edk::vec2f32(retStart->second,retStart->x),
                                    edk::vec2f32(this->p1X.width,this->p1X.height),
                                    edk::vec2f32(this->p2X.width,this->p2X.height),
                                    edk::vec2f32(retEnd->second,retEnd->x)
                                    );edkEnd();
        /*
        printf("\npercent == %.2f bezier percent %.2f position %.2f"
               ,percent
               ,((bezier.getPoint(percent).x - retStart->second)/ distance)
               ,bezier.getPoint(percent).y
               );edkEnd();
*/
        return bezier.getPoint(percent).y;edkEnd();
    }
    edk::float32 ret =  retStart->x+(((retEnd->x-retStart->x) *
                                      percent)
                                     );edkEnd();
    return ret;
}
bool edk::animation::InterpolationLine1D::haveX(edk::float32 positionX){
    edk::animation::Frame1D* retStart = (edk::animation::Frame1D*)this->start;edkEnd();
    edk::animation::Frame1D* retEnd = (edk::animation::Frame1D*)this->end;edkEnd();
    //test if have the X
    if(positionX>=retStart->x
            &&
            positionX<=retEnd->x
            ){
        //return true
        return true;
    }
    return false;
}
bool edk::animation::InterpolationLine1D::haveSecond(edk::float32 second){
    edk::animation::Frame1D* retStart = (edk::animation::Frame1D*)this->start;edkEnd();
    edk::animation::Frame1D* retEnd = (edk::animation::Frame1D*)this->end;edkEnd();
    //test if have the X
    if(second>=retStart->second
            &&
            second<=retEnd->second
            ){
        //return true
        return true;
    }
    return false;
}
edk::float32 edk::animation::InterpolationLine1D::getSecond(edk::float32 positionX){
    edk::float32 ret=0.f;edkEnd();
    //test if have the X
    if(this->haveX(positionX)){
        //get the frames
        edk::animation::Frame1D* retStart = (edk::animation::Frame1D*)this->start;edkEnd();
        edk::animation::Frame1D* retEnd = (edk::animation::Frame1D*)this->end;edkEnd();

        ret = ((positionX-retStart->x)/(retEnd->x - retStart->x))
                *
                (retEnd->second - retStart->second)
                +
                retStart->second;edkEnd();
    }
    return ret;
}
//write to XML
bool edk::animation::InterpolationLine1D::writeToXMLStart(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->start;edkEnd();
    return temp->writeToXML(xml,frameID);edkEnd();
}
bool edk::animation::InterpolationLine1D::writeToXMLEnd(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame1D* temp = (edk::animation::Frame1D*)this->end;edkEnd();
    return temp->writeToXML(xml,frameID);edkEnd();
}

//write curve
bool edk::animation::InterpolationLine1D::writeCurveToXML(edk::XML* xml,edk::uint32 curveID){
    if(xml && this->curveX){
        bool ret=false;edkEnd();
        edk::char8* nameID = edk::String::int64ToStr(curveID);edkEnd();
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveX_",nameID);edkEnd();
            if(name){
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = NULL;edkEnd();
                        //
                        temp = edk::String::float32ToStr(this->p1X.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1W",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p1X.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1H",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p2X.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p2W",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p2X.height);edkEnd();
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
        return ret;
    }
    return false;
}
//read the curve
bool edk::animation::InterpolationLine1D::readCurveFromXML(edk::XML* xml,edk::uint32 curveID){
    if(xml && this->curveX){
        bool ret=false;edkEnd();
        edk::char8* nameID = edk::String::int64ToStr(curveID);edkEnd();
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveX_",nameID);edkEnd();
            if(name){
                if(xml->selectChild(name)){
                    //read the values
                    this->p1X.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1W"));edkEnd();
                    this->p1X.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1H"));edkEnd();
                    this->p2X.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2W"));edkEnd();
                    this->p2X.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2H"));edkEnd();
                    xml->selectFather();edkEnd();
                    ret=true;edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}

