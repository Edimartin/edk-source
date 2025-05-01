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
        this->classThis=NULL;
        this->Constructor();
    }
    Frame4D(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w)
        :edk::animation::Frame3D(second,x,y,z),w(w){
        this->classThis=NULL;
        this->Constructor(second,x,y,z,w);
    }
    Frame4D(edk::float32 second,edk::vec4f32 value)
        :edk::animation::Frame3D(second,value.x,value.y,value.z),w(value.w){
        this->classThis=NULL;
        this->Constructor(second,value);
    }
    virtual ~Frame4D(){
        this->Destructor();
    }


    void Constructor(){
        edk::animation::Frame3D::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->w=0.0f;
        }
    }
    void Constructor(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
        edk::animation::Frame3D::Constructor(second,x,y,z);
        if(this->classThis!=this){
            this->classThis=this;
            this->w=w;
        }
    }
    void Constructor(edk::float32 second,edk::vec4f32 value){
        edk::animation::Frame3D::Constructor(second,value.x,value.y,value.z);
        if(this->classThis!=this){
            this->classThis=this;
            this->w=value.w;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
        edk::animation::Frame3D::Destructor();
    }

    //w 4D of the frame
    edk::float32 w;

    virtual bool cloneFrom(edk::animation::Frame4D* frame){
        if(frame){
            this->second = frame->second;
            this->x = frame->x;
            this->y = frame->y;
            this->z = frame->z;
            this->w = frame->w;
            return true;
        }
        return false;
    }

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(edk::animation::Frame3D::writeToXML(xml,frameID)){
            bool ret=false;
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = edk::String::float32ToStr(this->w);
                        //test the temp
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"w",temp);
                            free(temp);
                        }
                        xml->selectFather();
                        ret=true;
                    }
                    free(name);
                }
                free(nameID);
            }
            return ret;
        }
        return false;
    }
    bool readFromXML(edk::XML* xml,edk::uint32 frameID){
        if(xml){
            bool ret=edk::animation::Frame3D::readFromXML(xml,frameID);
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("w");
                        if(temp){
                            //convert the second
                            this->w = edk::String::strToFloat32(temp);
                        }
                        xml->selectFather();
                        ret=true;
                    }
                    free(name);
                }
                free(nameID);
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
        this->second = frame.second;
        this->x = frame.x;
        this->y = frame.y;
        this->z = frame.z;
        this->w = frame.w;
        return *this;
    }
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // FRAME4D_H
