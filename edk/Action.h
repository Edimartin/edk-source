#ifndef ACTION_H
#define ACTION_H

/*
Library C++ Action - Set Actions and CounterActions to the Game Engine
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
#warning "Inside Action"
#endif

#pragma once
#include "String.h"
#include "TypeVars.h"
#include "NameClass.h"
#include "xml/XML.h"

#ifdef printMessages
#warning "    Compiling Action"
#endif

namespace edk{
//This is an Action. You can use this class to save actions to animation or ctrl+z.
class Action{
public:
    Action(){}
    virtual ~Action(){}

    //run action function
    virtual void runAction()=0;
    //run a counter action used for ctrl+z
    virtual void runCounterAction()=0;
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id)=0;
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id)=0;

    //return the code
    virtual edk::uint64 getCode()=0;
};
class ActionZero: public edk::Action{
public:
    ActionZero(){this->code = 0u;}
    virtual ~ActionZero(){}

    //run action function
    virtual void runAction(){}
    //run a counter action used for ctrl+z
    virtual void runCounterAction(){}
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id){
        bool ret=false;
        if(xml){
            edk::char8* number = edk::String::uint32ToStr(id);
            if(number){
                edk::char8* name = edk::String::strCat((edk::char8*)"Action_",number);
                if(name){
                    //create the Action
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            edk::char8* str = edk::String::uint32ToStr(this->getCode());
                            if(str){
                                xml->addSelectedNextAttribute((edk::char8*)"code",str);
                                delete str;
                            }

                            ret=true;
                            //then select the father
                            xml->selectFather();
                        }
                    }
                    delete[] name;
                }
                delete[] number;
            }
        }
        return ret;
    }
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id){
        bool ret=false;
        if(xml){
            edk::char8* number = edk::String::uint32ToStr(id);
            if(number){
                edk::char8* name = edk::String::strCat((edk::char8*)"Action_",number);
                if(name){
                    //create the Action
                    if(xml->selectChild(name)){
                        //read the code
                        this->code = edk::String::strToInt64(xml->getSelectedAttributeValueByName("code"));

                        ret=true;
                        //then select the father
                        xml->selectFather();
                    }
                    delete[] name;
                }
                delete[] number;
            }
        }
        return ret;
    }

    //return the code
    edk::uint64 getCode(){
        return this->code;
    }
protected:
    edk::uint64 code;
};
//Action with names
class ActionName: public edk::Name ,public edk::Action{
public:
    ActionName(){this->code = 0u;}
    ActionName(edk::char8* _name){
        edk::Name::setName(_name);
    }
    ActionName(const edk::char8* _name){
        edk::Name::setName(_name);
    }
    virtual ~ActionName(){
        this->deleteName();
    }

    //run action function
    virtual void runAction(){}
    //run a counter action used for ctrl+z
    virtual void runCounterAction(){}
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id){
        bool ret=false;
        if(xml){
            edk::char8* number = edk::String::uint32ToStr(id);
            if(number){
                edk::char8* name = edk::String::strCat((edk::char8*)"Action_",number);
                if(name){
                    //create the Action
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            edk::char8* str = edk::String::uint32ToStr(this->getCode());
                            if(str){
                                xml->addSelectedNextAttribute((edk::char8*)"code",str);
                                delete str;
                            }
                            if(this->getName()) xml->addSelectedNextAttribute((edk::char8*)"name",this->getName());
                            //then select the father
                            xml->selectFather();
                        }
                    }
                    delete[] name;
                }
                delete[] number;
            }
        }
        return ret;
    }
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id){
        bool ret=false;
        if(xml){
            edk::char8* number = edk::String::uint32ToStr(id);
            if(number){
                edk::char8* name = edk::String::strCat((edk::char8*)"Action_",number);
                if(name){
                    //create the Action
                    if(xml->selectChild(name)){
                        //read the code
                        this->code = edk::String::strToInt64(xml->getSelectedAttributeValueByName((edk::char8*)"code"));
                        //read the name
                        this->setName(xml->getSelectedAttributeValueByName((edk::char8*)"name"));
                        //then select the father
                        xml->selectFather();
                    }
                    delete[] name;
                }
                delete[] number;
            }
        }
        return ret;
    }

    //return the code
    edk::uint64 getCode(){
        return this->code;
    }
protected:
    edk::uint64 code;
};
}//end namespace edk

#endif // ACTION_H
