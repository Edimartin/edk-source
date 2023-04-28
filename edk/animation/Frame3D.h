#ifndef EDK_ANIMATION_FRAME3D_H
#define EDK_ANIMATION_FRAME3D_H

/*
Library C++ Frame1D - Alloc a animation frame with tree values in Edk Game Engine
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
#pragma message "Inside Frame3D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec3.h"
#include "Frame2D.h"

#ifdef printMessages
#pragma message "    Compiling Frame3D"
#endif

namespace edk{
namespace animation{
class Frame3D:public Frame2D{
    public:
        Frame3D()
        :Frame2D(){
            //
            this->z=0.0f;edkEnd();
        }
        Frame3D(edk::float32 second,edk::float32 x,edk::float32 y,edk::float32 z)
        :Frame2D(second,x,y),z(z){
            //
        }
        Frame3D(edk::float32 second,edk::vec3f32 value)
        :Frame2D(second,value.x,value.y),z(value.z){
            //
        }
        virtual ~Frame3D(){
            //
        }

        //z 2D of the frame
        edk::float32 z;

        virtual bool cloneFrom(edk::animation::Frame3D* frame){
            if(frame){
                this->second = frame->second;edkEnd();
                this->x = frame->x;edkEnd();
                this->y = frame->y;edkEnd();
                this->z = frame->z;edkEnd();
                return true;
            }
            return false;
        }

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(edk::animation::Frame2D::writeToXML(xml,frameID)){
            bool ret=false;edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = edk::String::float32ToStr(this->z);edkEnd();
                        //test the temp
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"z",temp);edkEnd();
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
            bool ret=edk::animation::Frame2D::readFromXML(xml,frameID);edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("z");edkEnd();
                        if(temp){
                            //convert the second
                            this->z = edk::String::strToFloat32(temp);edkEnd();
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
    edk::animation::Frame3D operator=(edk::animation::Frame3D frame){
        //
        this->second = frame.second;edkEnd();
        this->x = frame.x;edkEnd();
        this->y = frame.y;edkEnd();
        this->z = frame.z;edkEnd();
        frame.cantDestruct();edkEnd();
        return *this;edkEnd();
    }
};
}//end namespace animation
}//end namespace edk

#endif // Frame3D_H
