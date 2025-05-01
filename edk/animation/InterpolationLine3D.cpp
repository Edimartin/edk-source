#include "InterpolationLine3D.h"

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
#pragma message "            Inside InterpolationLine3D.cpp"
#endif

edk::animation::InterpolationLine3D::InterpolationLine3D(){
    this->classThis=NULL;
    this->Constructor();
}

edk::animation::InterpolationLine3D::~InterpolationLine3D(){
    this->Destructor();
}

void edk::animation::InterpolationLine3D::Constructor(){
    edk::animation::InterpolationLine2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        //ctor
        this->allocStart();
        this->allocEnd();
        this->curveZ=false;
        this->constantZ=false;
    }
}
void edk::animation::InterpolationLine3D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::animation::InterpolationLine2D::Destructor();
}

//set new
edk::animation::Frame* edk::animation::InterpolationLine3D::useNewFrame(edk::uint8 count,edk::float32 values,...){
    //
    edk::float32* value = &values;
    switch(count){
    case 1:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame3D(value[0],0.0f,0.0f,0.0f));
    case 2:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame3D(value[0],value[1],0.0f,0.0f));
    case 3:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame3D(value[0],value[1],value[2],0.0f));
    case 4:
        //

        return (edk::animation::Frame*)(new edk::animation::Frame3D(value[0],value[1],value[2],value[3]));
    default:

        return (edk::animation::Frame*)(new edk::animation::Frame3D());
    }
    return NULL;
}

//SETERS
//set the start frame
bool edk::animation::InterpolationLine3D::setStart(edk::animation::Frame3D* frame){
    //Set the Frame2D data
    if(edk::animation::InterpolationLine2D::setStart(frame)){
        //convert to set the 2D
        edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->start;
        temp->z=frame->z;
        return true;
    }
    return false;
}
bool edk::animation::InterpolationLine3D::setStart(edk::float32 second,edk::vec3f32 value){
    //
    return this->setStart(second,value.x,value.y,value.z);
}
bool edk::animation::InterpolationLine3D::setStart(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z){
    //
    if(edk::animation::InterpolationLine2D::setStart(second,x,y)){
        //
        edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->start;
        temp->z=z;
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine3D::setStartValue(edk::float32 x,edk::float32 y,edk::float32 z){
    //test if are using a frame alloc
    if(edk::animation::InterpolationLine2D::setStartValue(x,y)){
        //
        edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->start;
        temp->z=z;
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine3D::setEnd(edk::animation::Frame3D* frame){
    //first test if can set the second and x
    if(edk::animation::InterpolationLine2D::setEnd(frame)){
        //convert to set the Frame3D
        edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->end;
        temp->z=frame->z;
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine3D::setEnd(edk::float32 second,edk::vec3f32 value){
    //
    return this->setEnd(second,value.x,value.y,value.z);
}
bool edk::animation::InterpolationLine3D::setEnd(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z){
    //
    if(edk::animation::InterpolationLine2D::setEnd(second,x,y)){
        //
        edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->end;
        temp->z=z;
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine3D::setEndValue(edk::float32 x,edk::float32 y,edk::float32 z){
    //test if are using a frame alloc
    if(edk::animation::InterpolationLine2D::setEndValue(x,y)){
        //
        edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->end;
        temp->z=z;
        //return true
        return true;
    }
    //else return false
    return false;
}
//set the points in the curve
bool edk::animation::InterpolationLine3D::setP1Z(edk::float32 second,edk::float32 z){
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
    this->p1Z.width = second;
    this->p1Z.height = z;

    return ret;
}
bool edk::animation::InterpolationLine3D::setP2Z(edk::float32 second,edk::float32 z){
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
    this->p2Z.width = second;
    this->p2Z.height = z;

    return ret;
}

//Set as a curve
bool edk::animation::InterpolationLine3D::setCurveZ(bool curve){
    if(this->curveZ!=curve){
        this->curveZ = curve;

        edk::animation::Frame3D* tempStart = (edk::animation::Frame3D*)this->start;
        edk::animation::Frame3D* tempEnd = (edk::animation::Frame3D*)this->end;

        if(this->curveZ){
            edk::size2f32 dist = edk::size2f32(tempEnd->second - tempStart->second,
                                               tempEnd->z - tempStart->z
                                               );
            this->p1Z = dist*0.25;
            this->p2Z = dist*0.75;
        }
        else{
            this->p1Z.width = tempStart->second;
            this->p1Z.height = tempStart->z;
            this->p2Z.width = tempEnd->second;
            this->p2Z.height = tempEnd->z;
        }

        return true;
    }
    return false;
}
void edk::animation::InterpolationLine3D::isCurveZ(){
    this->setCurveZ(true);
}
void edk::animation::InterpolationLine3D::isNotCurveZ(){
    this->setCurveZ(false);
}
bool edk::animation::InterpolationLine3D::getCurveZ(){
    return this->curveZ;
}
//set as constant interpolation
void edk::animation::InterpolationLine3D::setConstantZ(){
    this->constantZ=true;
    this->setCurveZ(false);
}
void edk::animation::InterpolationLine3D::setLinearZ(){
    this->constantZ=false;
    this->setCurveZ(false);
}

//GETERS
//return the start
edk::animation::Frame3D edk::animation::InterpolationLine3D::getStart3D(){
    //convert the frame to return
    edk::animation::Frame3D* ret = (edk::animation::Frame3D*)this->start;
    return *ret;
}
//return the end
edk::animation::Frame3D edk::animation::InterpolationLine3D::getEnd3D(){
    //convert the frame to return
    edk::animation::Frame3D* ret = (edk::animation::Frame3D*)this->end;
    return *ret;
}

//return the position in the second
edk::float32 edk::animation::InterpolationLine3D::getPositionZ(edk::float32 second){
    //convert the two frames
    edk::animation::Frame3D* retStart = (edk::animation::Frame3D*)this->start;
    edk::animation::Frame3D* retEnd = (edk::animation::Frame3D*)this->end;
    if(this->constantZ){
        return retStart->z;
    }
    //else test the linear or curve

    edk::float32 percent = ((second - retStart->second)/ distance);
    if(percent>=1.f){
        return retEnd->z;
    }
    else if(percent<=0.f){
        return retStart->z;
    }
    //test if is a curve
    if(this->curveZ){
        edk::shape::Bezier2D bezier(edk::vec2f32(retStart->second,retStart->z),
                                    edk::vec2f32(this->p1Z.width,this->p1Z.height),
                                    edk::vec2f32(this->p2Z.width,this->p2Z.height),
                                    edk::vec2f32(retEnd->second,retEnd->z)
                                    );
        return bezier.getPoint(percent).y;
    }
    return retStart->z+((retEnd->z-retStart->z) *
                        percent
                        );
}

//write to XML
bool edk::animation::InterpolationLine3D::writeToXMLStart(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->start;
    return temp->writeToXML(xml,frameID);
}
bool edk::animation::InterpolationLine3D::writeToXMLEnd(edk::XML* xml,edk::uint32 frameID){
    edk::animation::Frame3D* temp = (edk::animation::Frame3D*)this->end;
    return temp->writeToXML(xml,frameID);
}

//write curve
bool edk::animation::InterpolationLine3D::writeCurveToXML(edk::XML* xml,edk::uint32 curveID){
    bool ret=edk::animation::InterpolationLine2D::writeCurveToXML(xml,curveID);
    if(xml && this->curveZ){
        edk::char8* nameID = edk::String::int64ToStr(curveID);
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveZ_",nameID);
            if(name){
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = NULL;
                        //
                        temp = edk::String::float32ToStr(this->p1Z.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1W",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->p1Z.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p1H",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->p2Z.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"p2W",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->p2Z.height);
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
bool edk::animation::InterpolationLine3D::readCurveFromXML(edk::XML* xml,edk::uint32 curveID){
    bool ret=edk::animation::InterpolationLine2D::readCurveFromXML(xml,curveID);
    if(xml && this->curveZ){
        edk::char8* nameID = edk::String::int64ToStr(curveID);
        if(nameID){
            //create the name
            edk::char8* name = edk::String::strCat((edk::char8*)"curveY_",nameID);
            if(name){
                if(xml->selectChild(name)){
                    //read the values
                    this->p1Z.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1W"));
                    this->p1Z.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p1H"));
                    this->p2Z.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2W"));
                    this->p2Z.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("p2H"));
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
