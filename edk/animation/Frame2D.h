#ifndef EDK_ANIMATION_FRAME2D_H
#define EDK_ANIMATION_FRAME2D_H

/*
Library C++ Frame1D - Alloc a animation frame with two values in Edk Game Engine
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
#warning "Inside Frame2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "Frame1D.h"

#ifdef printMessages
#warning "    Compiling Frame2D"
#endif

namespace edk{
namespace animation{
class Frame2D:public Frame1D{
    public:
        Frame2D()
        :Frame1D(){
            //
            this->y=0.0f;
        }
        Frame2D(edk::float32 second,edk::vec2f32 value)
        :Frame1D(second,value.x),y(value.y)
        {
            //
        }
        Frame2D(edk::float32 second,edk::float32 x,edk::float32 y)
        :Frame1D(second,x),y(y)
        {
            //
        }
        virtual ~Frame2D(){
            //
        }

        //y 2D of the frame
        edk::float32 y;

        //Operator =
        edk::animation::Frame2D operator=(edk::animation::Frame2D frame){
            //
            this->second = frame.second;
            this->x = frame.x;
            this->y = frame.y;
            frame.cantDestruct();
            return *this;
        }
        /*
        //Operator ==
        bool operator==(edk::animation::Frame2D frame){return this->second==frame.second;}
        //Operator !=
        bool operator!=(edk::animation::Frame2D frame){return this->second!=frame.second;}
        //Operator >
        bool operator>(edk::animation::Frame2D frame){return this->second>frame.second;}
        //Operator >=
        bool operator>=(edk::animation::Frame2D frame){return this->second>=frame.second;}
        //Operator <
        bool operator<(edk::animation::Frame2D frame){return this->second<frame.second;}
        //Operator <=
        bool operator<=(edk::animation::Frame2D frame){return this->second<=frame.second;}
        */

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(edk::animation::Frame1D::writeToXML(xml,frameID)){
            bool ret=false;
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = edk::String::float32ToStr(this->y);
                        //test the temp
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"y",temp);
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
            bool ret=edk::animation::Frame1D::readFromXML(xml,frameID);
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("y");
                        if(temp){
                            //convert the second
                            this->y = edk::String::strToFloat32(temp);
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
};
}//end namespace animation
}//end namespace edk

#endif // Frame2D_H
