#ifndef FRAME4D_H
#define FRAME4D_H

/*
Library C++ Frame4D - Alloc a animation frame with tree values in Edk Game Engine
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
#pragma message "Inside Frame4D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec4.h"
#include "Frame3D.h"

#ifdef printMessages
#pragma message "    Compiling Frame4D"
#endif

namespace edk{
namespace animation{
class Frame4D:public edk::animation::Frame3D{
public:
    Frame4D()
        :edk::animation::Frame3D(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    Frame4D(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w)
        :edk::animation::Frame3D(second,x,y,z),w(w){
        this->classThis=NULL;edkEnd();
        this->Constructor(second,x,y,z,false);edkEnd();
    }
    Frame4D(edk::float32 second,edk::vec4f32 value)
        :edk::animation::Frame3D(second,value.x,value.y,value.z),w(value.w){
        this->classThis=NULL;edkEnd();
        this->Constructor(second,value,false);edkEnd();
    }
    virtual ~Frame4D(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }


    void Constructor(bool runFather=true){
        if(runFather){
            edk::animation::Frame3D::Constructor();
        }
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->w=0.0f;edkEnd();
        }
    }
    void Constructor(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w,bool runFather=true){
        if(runFather){
            edk::animation::Frame3D::Constructor(second,x,y,z);
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->w=w;
        }
    }
    void Constructor(edk::float32 second,edk::vec4f32 value,bool runFather=true){
        if(runFather){
            edk::animation::Frame3D::Constructor(second,value.x,value.y,value.z);
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->w=value.w;
        }
    }

    //w 4D of the frame
    edk::float32 w;

    virtual bool cloneFrom(edk::animation::Frame4D* frame){
        if(frame){
            this->second = frame->second;edkEnd();
            this->x = frame->x;edkEnd();
            this->y = frame->y;edkEnd();
            this->z = frame->z;edkEnd();
            this->w = frame->w;edkEnd();
            return true;
        }
        return false;
    }

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(edk::animation::Frame3D::writeToXML(xml,frameID)){
            bool ret=false;edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = edk::String::float32ToStr(this->w);edkEnd();
                        //test the temp
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"w",temp);edkEnd();
                            free(temp);edkEnd();
                        }
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
    bool readFromXML(edk::XML* xml,edk::uint32 frameID){
        if(xml){
            bool ret=edk::animation::Frame3D::readFromXML(xml,frameID);edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("w");edkEnd();
                        if(temp){
                            //convert the second
                            this->w = edk::String::strToFloat32(temp);edkEnd();
                        }
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
protected:
private:
    //Operator =
    edk::animation::Frame4D operator=(edk::animation::Frame4D frame){
        //
        this->second = frame.second;edkEnd();
        this->x = frame.x;edkEnd();
        this->y = frame.y;edkEnd();
        this->z = frame.z;edkEnd();
        this->w = frame.w;edkEnd();
        return *this;edkEnd();
    }
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // FRAME4D_H
