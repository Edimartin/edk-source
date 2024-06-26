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
    Action(){this->classThis=NULL;this->Constructor(false);edkEnd();}
    virtual ~Action(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
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
    ActionZero(){this->classThis=NULL;this->Constructor(false);}
    virtual ~ActionZero(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::Action::Constructor();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->code = 0u;edkEnd();
        }
    }

    //run action function
    virtual void runAction(){}
    //run a counter action used for ctrl+z
    virtual void runCounterAction(){}
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id){
        bool ret=false;edkEnd();
        if(xml){
            edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
            if(number){
                edk::char8* name = edk::String::strCat((edk::char8*)"Action_",number);edkEnd();
                if(name){
                    //create the Action
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            edk::char8* str = edk::String::uint32ToStr(this->getCode());edkEnd();
                            if(str){
                                xml->addSelectedNextAttribute((edk::char8*)"code",str);edkEnd();
                                delete str;edkEnd();
                            }

                            ret=true;edkEnd();
                            //then select the father
                            xml->selectFather();edkEnd();
                        }
                    }
                    free(name);edkEnd();
                }
                free(number);edkEnd();
            }
        }
        return ret;
    }
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id){
        bool ret=false;edkEnd();
        if(xml){
            edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
            if(number){
                edk::char8* name = edk::String::strCat((edk::char8*)"Action_",number);edkEnd();
                if(name){
                    //create the Action
                    if(xml->selectChild(name)){
                        //read the code
                        this->code = edk::String::strToInt64(xml->getSelectedAttributeValueByName("code"));edkEnd();

                        ret=true;edkEnd();
                        //then select the father
                        xml->selectFather();edkEnd();
                    }
                    free(name);edkEnd();
                }
                free(number);edkEnd();
            }
        }
        return ret;
    }

    //return the code
    edk::uint64 getCode(){
        return this->code;edkEnd();
    }
protected:
    edk::uint64 code;
private:
    edk::classID classThis;
};
//Action with names
class ActionName: public edk::Name ,public edk::Action{
public:
    ActionName(){this->classThis=NULL;this->Constructor(false);edkEnd();}
    ActionName(edk::char8* _name){
        this->classThis=NULL;edkEnd();
        this->Constructor(_name,false);edkEnd();
    }
    ActionName(const edk::char8* _name){
        this->classThis=NULL;edkEnd();
        this->Constructor(_name,false);edkEnd();
    }
    virtual ~ActionName(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        this->deleteName();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::Name::Constructor();edkEnd();
            edk::Action::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->code = 0u;edkEnd();
        }
    }
    void Constructor(edk::char8* _name,bool runFather=true){
        if(runFather){
            edk::Name::Constructor(_name);edkEnd();
            edk::Action::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Constructor(const edk::char8* _name,bool runFather=true){
        if(runFather){
            edk::Name::Constructor(_name);edkEnd();
            edk::Action::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
        }
    }

    //run action function
    virtual void runAction(){}
    //run a counter action used for ctrl+z
    virtual void runCounterAction(){}
    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id){
        bool ret=false;edkEnd();
        if(xml){
            edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
            if(number){
                edk::char8* name = edk::String::strCat((edk::char8*)"Action_",number);edkEnd();
                if(name){
                    //create the Action
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            edk::char8* str = edk::String::uint32ToStr(this->getCode());edkEnd();
                            if(str){
                                xml->addSelectedNextAttribute((edk::char8*)"code",str);edkEnd();
                                delete str;edkEnd();
                            }
                            if(this->getName()){
                                xml->addSelectedNextAttribute((edk::char8*)"name",this->getName());edkEnd();
                            }
                            //then select the father
                            xml->selectFather();edkEnd();
                        }
                    }
                    free(name);edkEnd();
                }
                free(number);edkEnd();
            }
        }
        return ret;
    }
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id){
        bool ret=false;edkEnd();
        if(xml){
            edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
            if(number){
                edk::char8* name = edk::String::strCat((edk::char8*)"Action_",number);edkEnd();
                if(name){
                    //create the Action
                    if(xml->selectChild(name)){
                        //read the code
                        this->code = edk::String::strToInt64(xml->getSelectedAttributeValueByName((edk::char8*)"code"));edkEnd();
                        //read the name
                        this->setName(xml->getSelectedAttributeValueByName((edk::char8*)"name"));edkEnd();
                        //then select the father
                        xml->selectFather();edkEnd();
                    }
                    free(name);edkEnd();
                }
                free(number);edkEnd();
            }
        }
        return ret;
    }

    //return the code
    edk::uint64 getCode(){
        return this->code;edkEnd();
    }
protected:
    edk::uint64 code;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // ACTION_H
