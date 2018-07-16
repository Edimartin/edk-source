#ifndef EDK_ANIMATION_FRAME1D_H
#define EDK_ANIMATION_FRAME1D_H

/*
Library C++ Frame1D - Alloc a animation frame with one value in Edk Game Engine
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
#warning "Inside Frame1D"
#endif

#pragma once
#include "../Object.h"
#include "../TypeVars.h"
#include "Frame.h"

#ifdef printMessages
#warning "    Compiling Frame1D"
#endif

namespace edk{
namespace animation{
class Frame1D: public edk::animation::Frame{
public:
    Frame1D(){
        //
        this->x=0.0f;
    }
    Frame1D(edk::float32 second,edk::float32 x){
        //
        this->second=second;
        this->x=x;
    }
    virtual ~Frame1D(){
        //
    }

    //x 2D of the frame
    edk::float32 x;

    bool cloneFrom(edk::animation::Frame1D* frame){
        if(frame){
            this->second = frame->second;
            this->x = frame->x;
            return true;
        }
        return false;
    }

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(edk::animation::Frame::writeToXML(xml,frameID)){
            bool ret=false;
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = edk::String::float32ToStr(this->x);
                        //test the temp
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"x",temp);
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
            bool ret=edk::animation::Frame::readFromXML(xml,frameID);
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("x");
                        if(temp){
                            //convert the second
                            this->x = edk::String::strToFloat32(temp);
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
    edk::animation::Frame1D operator=(edk::animation::Frame1D frame){
        //
        this->second = frame.second;
        this->x = frame.x;
        frame.cantDestruct();
        return *this;
    }


};







}//end namespace animation
}//end namespace edk

#endif // Frame1D_H
