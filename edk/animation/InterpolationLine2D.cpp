#include "InterpolationLine2D.h"

/*
Library C++ InterpolationLine - Animate one line interpolation with two values in Edk Game Engine
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
#pragma message "            Inside InterpolationLine2D.cpp"
#endif

edk::animation::InterpolationLine2D::InterpolationLine2D()
    :InterpolationLine1D()
{
    //ctor
    this->allocStart();edkEnd();
    this->allocEnd();edkEnd();
    this->curveY=false;edkEnd();
    this->constantY=false;edkEnd();
}

edk::animation::InterpolationLine2D::~InterpolationLine2D()
{
    //dtor
}

//set new
edk::animation::Frame* edk::animation::InterpolationLine2D::useNewFrame(edk::uint8 count,edk::float32 values,...){
    //
    edk::float32* value = &values;edkEnd();
    switch(count){
    case 1:
        //
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame2D(value[0],0.0f,0.0f));
    case 2:
        //
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame2D(value[0],value[1],0.0f));
    case 3:
        //
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame2D(value[0],value[1],value[2]));
    default:
        edkEnd();
        return (edk::animation::Frame*)(new edk::animation::Frame2D());
    }
    return NULL;
}

//SETERS
//set the start frame
bool edk::animation::InterpolationLine2D::setStart(edk::animation::Frame2D* frame){
    //Set the frame1D data
    if(edk::animation::InterpolationLine1D::setStart(frame)){
        //convert to set the 2D
        edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->start;edkEnd();
        temp->y=frame->y;edkEnd();
        return true;
    }
    return false;
}
bool edk::animation::InterpolationLine2D::setStart(edk::float32 second,edk::vec2f32 value){
    //
    return this->setStart(second,value.x,value.y);edkEnd();
}
bool edk::animation::InterpolationLine2D::setStart(edk::float32 second,edk::float32 x,edk::float32 y){
    //
    if(edk::animation::InterpolationLine1D::setStart(second,x)){
        //
        edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->start;edkEnd();
        temp->y=y;edkEnd();
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine2D::setStartValue(edk::float32 x,edk::float32 y){
    //test if are using a frame alloc
    if(edk::animation::InterpolationLine1D::setStartValue(x)){
        //
        edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->start;edkEnd();
        temp->y=y;edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine2D::setEnd(edk::animation::Frame2D* frame){
    //first test if can set the second and x
    if(edk::animation::InterpolationLine1D::setEnd(frame)){
        //convert to set the Frame2D
        edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->end;edkEnd();
        temp->y=frame->y;edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine2D::setEnd(edk::float32 second,edk::vec2f32 value){
    //
    return this->setEnd(second,value.x,value.y);edkEnd();
}
bool edk::animation::InterpolationLine2D::setEnd(edk::float32 second,edk::float32 x,edk::float32 y){
    //
    if(edk::animation::InterpolationLine1D::setEnd(second,x)){
        //
        edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->end;edkEnd();
        temp->y=y;edkEnd();
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine2D::setEndValue(edk::float32 x,edk::float32 y){
    //test if are using a frame alloc
    if(edk::animation::InterpolationLine1D::setEndValue(x)){
        //
        edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->end;edkEnd();
        temp->y=y;edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
//set the points in the curve
bool edk::animation::InterpolationLine2D::setP1Y(edk::float32 second,edk::float32 y){
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
    this->p1Y.width = second;edkEnd();
    this->p1Y.height = y;edkEnd();

    return ret;
}
bool edk::animation::InterpolationLine2D::setP2Y(edk::float32 second,edk::float32 y){
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
    this->p2Y.width = second;edkEnd();
    this->p2Y.height = y;edkEnd();

    return ret;
}


//Set as a curve
bool edk::animation::InterpolationLine2D::setCurveY(bool curve){
    if(this->curveY!=curve){
        this->curveY = curve;edkEnd();

        edk::animation::Frame2D* tempStart = (edk::animation::Frame2D*)this->start;edkEnd();
        edk::animation::Frame2D* tempEnd = (edk::animation::Frame2D*)this->end;edkEnd();

        if(this->curveY){
            edk::size2f32 dist = edk::size2f32(tempEnd->second - tempStart->second,
                                               tempEnd->y - tempStart->y
                                               );edkEnd();
            this->p1Y = dist*0.25;edkEnd();
            this->p2Y = dist*0.75;edkEnd();
        }
        else{
            this->p1Y.width = tempStart->second;edkEnd();
            this->p1Y.height = tempStart->y;edkEnd();
            this->p2Y.width = tempEnd->second;edkEnd();
            this->p2Y.height = tempEnd->y;edkEnd();
        }

        return true;
    }
    return false;
}
void edk::animation::InterpolationLine2D::isCurveY(){
    this->setCurveY(true);edkEnd();
}
void edk::animation::InterpolationLine2D::isNotCurveY(){
    this->setCurveY(false);edkEnd();
}
bool edk::animation::InterpolationLine2D::getCurveY(){
    return this->curveY;edkEnd();
}
//set as constant interpolation
void edk::animation::InterpolationLine2D::setConstantY(){
    this->constantY=true;edkEnd();
    this->setCurveY(false);edkEnd();
}
void edk::animation::InterpolationLine2D::setLinearY(){
    this->constantY=false;edkEnd();
    this->setCurveY(false);edkEnd();
}

//GETERS
//return the start
edk::animation::Frame2D edk::animation::InterpolationLine2D::getStart2D(){
    //convert the frame to return
    edk::animation::Frame2D* ret = (edk::animation::Frame2D*)this->start;edkEnd();
    ret->cantDestruct();edkEnd();
    return *ret;edkEnd();
}
//return the end
edk::animation::Frame2D edk::animation::InterpolationLine2D::getEnd2D(){
    //convert the frame to return
    edk::animation::Frame2D* ret = (edk::animation::Frame2D*)this->end;edkEnd();
    ret->cantDestruct();edkEnd();
    return *ret;edkEnd();
}

//return the position in the second
edk::float32 edk::animation::InterpolationLine2D::getPositionY(edk::float32 second){
    //convert the two frames
    edk::animation::Frame2D* retStart = (edk::animation::Frame2D*)this->start;edkEnd();
    edk::animation::Frame2D* retEnd = (edk::animation::Frame2D*)this->end;edkEnd();
    if(this->constantY){
        return retStart->y;edkEnd();
    }
    //else test the linear or curve

    edk::float32 percent = ((second - retStart->second)/ distance);edkEnd();
    if(percent>=1.f){
        return retEnd->y;edkEnd();
    }
    else if(percent<=0.f){
        return retStart->y;edkEnd();
    }
    //test if is a curve
    if(this->curveY){
        edk::shape::Bezier2D bezier(edk::vec2f32(retStart->second,retStart->y),
                                    edk::vec2f32(this->p1Y.width,this->p1Y.height),
                                    edk::vec2f32(this->p2Y.width,this->p2Y.height),
                                    edk::vec2f32(retEnd->second,retEnd->y)
                                    );edkEnd();
        return bezier.getPoint(percent).y;edkEnd();
    }
    return retStart->y+((retEnd->y-retStart->y) *
                        percent
                        );edkEnd();
}

//write to XML
bool edk::animation::InterpolationLine2D::writeToXMLStart(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->start;edkEnd();
    return temp->writeToXML(xml,frameID);edkEnd();
}
bool edk::animation::InterpolationLine2D::writeToXMLEnd(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame2D* temp = (edk::animation::Frame2D*)this->end;edkEnd();
    return temp->writeToXML(xml,frameID);edkEnd();
}

//write curve
bool edk::animation::InterpolationLine2D::writeCurveToXML(edk::XML* xml,edk::uint32 curveID){
    bool ret=edk::animation::InterpolationLine1D::writeCurveToXML(xml,curveID);edkEnd();
    if(xml && this->curveY){
        edk::char8* nameID = edk::String::int64ToStr(curveID);edkEnd();
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveY_",nameID);edkEnd();
            if(name){
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = NULL;edkEnd();
                        //
                        temp = edk::String::float32ToStr(this->p1Y.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1W",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p1Y.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1H",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p2Y.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p2W",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->p2Y.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p2H",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }

                        xml->selectFather();edkEnd();
                        ret=true;edkEnd();
                    }
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
    }
    return ret;
}
//read the curve
bool edk::animation::InterpolationLine2D::readCurveFromXML(edk::XML* xml,edk::uint32 curveID){
    bool ret=edk::animation::InterpolationLine1D::readCurveFromXML(xml,curveID);edkEnd();
    if(xml && this->curveY){
        edk::char8* nameID = edk::String::int64ToStr(curveID);edkEnd();
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveY_",nameID);edkEnd();
            if(name){
                if(xml->selectChild(name)){
                    //read the values
                    this->p1Y.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1W"));edkEnd();
                    this->p1Y.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1H"));edkEnd();
                    this->p2Y.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2W"));edkEnd();
                    this->p2Y.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2H"));edkEnd();
                    xml->selectFather();edkEnd();
                    ret=true;edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
    }
    return ret;
}
