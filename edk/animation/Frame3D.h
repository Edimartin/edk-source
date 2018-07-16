#ifndef EDK_ANIMATION_FRAME3D_H
#define EDK_ANIMATION_FRAME3D_H

/*
Library C++ Frame1D - Alloc a animation frame with tree values in Edk Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "Inside Frame3D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec3.h"
#include "Frame2D.h"

#ifdef printMessages
#warning "    Compiling Frame3D"
#endif

namespace edk{
namespace animation{
class Frame3D:public Frame2D{
    public:
        Frame3D()
        :Frame2D(){
            //
            this->z=0.0f;
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
                this->second = frame->second;
                this->x = frame->x;
                this->y = frame->y;
                this->z = frame->z;
                return true;
            }
            return false;
        }

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(edk::animation::Frame2D::writeToXML(xml,frameID)){
            bool ret=false;
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = edk::String::float32ToStr(this->z);
                        //test the temp
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"z",temp);
                            delete[] temp;
                        }
                        xml->selectFather();
                        ret=true;
                    }
                    delete[] name;
                }
                delete[] nameID;
            }
            return ret;
        }
        return false;
    }
    bool readFromXML(edk::XML* xml,edk::uint32 frameID){
        if(xml){
            bool ret=edk::animation::Frame2D::readFromXML(xml,frameID);
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("z");
                        if(temp){
                            //convert the second
                            this->z = edk::String::strToFloat32(temp);
                        }
                        xml->selectFather();
                        ret=true;
                    }
                    delete[] name;
                }
                delete[] nameID;
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
        this->second = frame.second;
        this->x = frame.x;
        this->y = frame.y;
        this->z = frame.z;
        frame.cantDestruct();
        return *this;
    }
};
}//end namespace animation
}//end namespace edk

#endif // Frame3D_H
