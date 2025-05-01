#ifndef ACTION_H
#define ACTION_H

/*
Library C++ Action - Set Actions and CounterActions to the Game Engine
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
#pragma message "Inside Action"
#endif

#pragma once
#include "String.h"
#include "TypeVars.h"
#include "NameClass.h"
#include "xml/XML.h"

#ifdef printMessages
#pragma message "    Compiling Action"
#endif

namespace edk{
//This is an Action. You can use this class to save actions to animation or ctrl+z.
class Action{
public:
    Action(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~Action(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

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
private:
    edk::classID classThis;
};
class ActionZero: public edk::Action{
public:
    ActionZero(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~ActionZero(){
        this->Destructor();
    }

    void Constructor(){
        edk::Action::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->code = 0u;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
        edk::Action::Destructor();
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

                            ret=true;
                            //then select the father
                            xml->selectFather();
                        }
                    }
                    free(name);
                }
                free(number);
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
                    free(name);
                }
                free(number);
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
private:
    edk::classID classThis;
};
//Action with names
class ActionName: public edk::Name ,public edk::Action{
public:
    ActionName(){
        this->classThis=NULL;
        this->Constructor();
    }
    ActionName(edk::char8* _name){
        this->classThis=NULL;
        this->Constructor(_name);
    }
    ActionName(const edk::char8* _name){
        this->classThis=NULL;
        this->Constructor(_name);
    }
    virtual ~ActionName(){
        this->Destructor();
    }

    void Constructor(){
        edk::Name::Constructor();
        edk::Action::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->code = 0u;
        }
    }
    void Constructor(edk::char8* _name){
        edk::Name::Constructor(_name);
        edk::Action::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Constructor(const edk::char8* _name){
        edk::Name::Constructor(_name);
        edk::Action::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->deleteName();
        }
        edk::Name::Destructor();
        edk::Action::Destructor();
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
                            if(this->getName()){
                                xml->addSelectedNextAttribute((edk::char8*)"name",this->getName());
                            }
                            //then select the father
                            xml->selectFather();
                        }
                    }
                    free(name);
                }
                free(number);
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
                    free(name);
                }
                free(number);
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
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // ACTION_H
