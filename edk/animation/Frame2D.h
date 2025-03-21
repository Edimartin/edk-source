#ifndef EDK_ANIMATION_FRAME2D_H
#define EDK_ANIMATION_FRAME2D_H

/*
Library C++ Frame1D - Alloc a animation frame with two values in Edk Game Engine
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
#pragma message "Inside Frame2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "Frame1D.h"

#ifdef printMessages
#pragma message "    Compiling Frame2D"
#endif

namespace edk{
namespace animation{
class Frame2D:public edk::animation::Frame1D{
public:
    Frame2D()
        :Frame1D(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    Frame2D(edk::float32 second,edk::vec2f32 value)
        :Frame1D(second,value.x),y(value.y)
    {
        this->classThis=NULL;edkEnd();
        this->Constructor(second,value,false);edkEnd();
    }
    Frame2D(edk::float32 second,edk::float32 x,edk::float32 y)
        :Frame1D(second,x),y(y)
    {
        this->classThis=NULL;edkEnd();
        this->Constructor(second,x,y,false);edkEnd();
    }
    virtual ~Frame2D(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }


    void Constructor(bool runFather=true){
        if(runFather){
            edk::animation::Frame1D::Constructor();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->y=0.0f;edkEnd();
        }
    }
    void Constructor(edk::float32 second,edk::vec2f32 value,bool runFather=true){
        if(runFather){
            edk::animation::Frame1D::Constructor(second,value.x);
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->y=value.y;
        }
    }
    void Constructor(edk::float32 second,edk::float32 x,edk::float32 y,bool runFather=true){
        if(runFather){
            edk::animation::Frame1D::Constructor(second,x);
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->y=y;
        }
    }

    //y 2D of the frame
    edk::float32 y;

    virtual bool cloneFrom(edk::animation::Frame2D* frame){
        if(frame){
            this->second = frame->second;edkEnd();
            this->x = frame->x;edkEnd();
            this->y = frame->y;edkEnd();
            return true;
        }
        return false;
    }

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(edk::animation::Frame1D::writeToXML(xml,frameID)){
            bool ret=false;edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = edk::String::float32ToStr(this->y);edkEnd();
                        //test the temp
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"y",temp);edkEnd();
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
            bool ret=edk::animation::Frame1D::readFromXML(xml,frameID);edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("y");edkEnd();
                        if(temp){
                            //convert the second
                            this->y = edk::String::strToFloat32(temp);edkEnd();
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
    edk::animation::Frame2D operator=(edk::animation::Frame2D frame){
        //
        this->second = frame.second;edkEnd();
        this->x = frame.x;edkEnd();
        this->y = frame.y;edkEnd();
        return *this;edkEnd();
    }
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // Frame2D_H
