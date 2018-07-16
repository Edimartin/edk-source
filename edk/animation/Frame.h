#ifndef EDK_ANIMATION_FRAME_H
#define EDK_ANIMATION_FRAME_H

/*
Library C++ Frame - Alloc a animation frame in Edk Game Engine
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
#warning "Inside Frame"
#endif

#pragma once
#include "../Object.h"
#include "../TypeVars.h"
#include "../xml/XML.h"

#ifdef printMessages
#warning "    Compiling Frame"
#endif

namespace edk{
namespace animation{
class Frame: public edk::Object<edk::animation::Frame>{
public:
    Frame(){
        //
        this->second=0.0f;
    }
    Frame(edk::float32 second){
        //
        this->second=second;
    }
    virtual ~Frame(){
        //
    }

    //time of the frame
    edk::float32 second;

    virtual bool cloneFrom(edk::animation::Frame* frame){
        if(frame){
            this->second = frame->second;
            return true;
        }
        return false;
    }
    virtual bool equalThan(edk::animation::Frame* frame){
        if(frame){
            if(this->second == frame->second){
                return true;
            }
        }
        return false;
    }
    virtual bool differentThan(edk::animation::Frame* frame){
        if(frame){
            if(this->second!=frame->second){
                return true;
            }
        }
        return false;
    }
    virtual bool biggerThan(edk::animation::Frame* frame){
        if(frame){
            if(this->second>frame->second){
                return true;
            }
        }
        return false;
    }
    virtual bool biggerEqualThan(edk::animation::Frame* frame){
        if(frame){
            if(this->second>=frame->second){
                return true;
            }
        }
        return false;
    }
    virtual bool smallerThan(edk::animation::Frame* frame){
        if(frame){
            if(this->second<frame->second){
                return true;
            }
        }
        return false;
    }
    virtual bool smallerEqualThan(edk::animation::Frame* frame){
        if(frame){
            if(this->second<=frame->second){
                return true;
            }
        }
        return false;
    }

    //write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 frameID){
        if(xml){
            bool ret=false;
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            //write the frame
                            edk::char8* temp = edk::String::float32ToStr(this->second);
                            //test the temp
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"second",temp);
                                delete[] temp;
                            }
                            xml->selectFather();
                            ret=true;
                        }
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
            bool ret=false;
            edk::char8* nameID = edk::String::int64ToStr(frameID);
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("second");
                        if(temp){
                            //convert the second
                            this->second = edk::String::strToFloat32(temp);
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
    edk::animation::Frame operator=(edk::animation::Frame frame){
        //
        this->second = frame.second;
        frame.cantDestruct();
        return *this;
    }
    //Operator ==
    bool operator==(edk::animation::Frame frame){frame.cantDestruct();return this->second==frame.second;}
    //Operator !=
    bool operator!=(edk::animation::Frame frame){frame.cantDestruct();return this->second!=frame.second;}
    //Operator >
    bool operator>(edk::animation::Frame frame){frame.cantDestruct();return this->second>frame.second;}
    //Operator >=
    bool operator>=(edk::animation::Frame frame){frame.cantDestruct();return this->second>=frame.second;}
    //Operator <
    bool operator<(edk::animation::Frame frame){frame.cantDestruct();return this->second<frame.second;}
    //Operator <=
    bool operator<=(edk::animation::Frame frame){frame.cantDestruct();return this->second<=frame.second;}
};
}//end namespace animation
}//end namespace edk

#endif // FRAME_H
