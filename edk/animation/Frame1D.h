#ifndef EDK_ANIMATION_FRAME1D_H
#define EDK_ANIMATION_FRAME1D_H

/*
Library C++ Frame1D - Alloc a animation frame with one value in Edk Game Engine
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
#pragma message "Inside Frame1D"
#endif

#pragma once
#include "../Object.h"
#include "../TypeVars.h"
#include "Frame.h"

#ifdef printMessages
#pragma message "    Compiling Frame1D"
#endif

namespace edk{
namespace animation{
class Frame1D: public edk::animation::Frame{
public:
    Frame1D(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    Frame1D(edk::float32 second,edk::float32 x){
        this->classThis=NULL;edkEnd();
        this->Constructor(second,x,false);edkEnd();
    }
    virtual ~Frame1D(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::animation::Frame::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->x=0.0f;edkEnd();
        }
    }
    void Constructor(edk::float32 second,edk::float32 x,bool runFather=true){
        if(runFather){
            edk::animation::Frame::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->second=second;edkEnd();
            this->x=x;edkEnd();
        }
    }

    //x 2D of the frame
    edk::float32 x;

    bool cloneFrom(edk::animation::Frame1D* frame){
        if(frame){
            this->second = frame->second;edkEnd();
            this->x = frame->x;edkEnd();
            return true;
        }
        return false;
    }

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(edk::animation::Frame::writeToXML(xml,frameID)){
            bool ret=false;edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = edk::String::float32ToStr(this->x);edkEnd();
                        //test the temp
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"x",temp);edkEnd();
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
            bool ret=edk::animation::Frame::readFromXML(xml,frameID);edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("x");edkEnd();
                        if(temp){
                            //convert the second
                            this->x = edk::String::strToFloat32(temp);edkEnd();
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
    edk::animation::Frame1D operator=(edk::animation::Frame1D frame){
        //
        this->second = frame.second;edkEnd();
        this->x = frame.x;edkEnd();
        return *this;edkEnd();
    }
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // Frame1D_H
