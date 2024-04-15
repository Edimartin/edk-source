#ifndef EDK_ANIMATION_FRAME_H
#define EDK_ANIMATION_FRAME_H

/*
Library C++ Frame - Alloc a animation frame in Edk Game Engine
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
#pragma message "Inside Frame"
#endif

#pragma once
#include "../Object.h"
#include "../TypeVars.h"
#include "../xml/XML.h"

#ifdef printMessages
#pragma message "    Compiling Frame"
#endif

namespace edk{
namespace animation{
class Frame: public edk::Object<edk::animation::Frame>{
public:
    Frame(){
        //
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    Frame(edk::float32 second){
        //
        this->second=second;edkEnd();
    }
    virtual ~Frame(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::Object<edk::animation::Frame>::Constructor();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->second=0.0f;edkEnd();
        }
    }

    //time of the frame
    edk::float32 second;

    virtual bool cloneFrom(edk::animation::Frame* frame){
        if(frame){
            this->second = frame->second;edkEnd();
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
            bool ret=false;edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            //write the frame
                            edk::char8* temp = edk::String::float32ToStr(this->second);edkEnd();
                            //test the temp
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"second",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            xml->selectFather();edkEnd();
                            ret=true;edkEnd();
                        }
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
            bool ret=false;edkEnd();
            edk::char8* nameID = edk::String::int64ToStr(frameID);edkEnd();
            if(nameID){
                //create the name
                edk::char8* name = edk::String::strCat((edk::char8*)"frame_",nameID);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //write the frame
                        edk::char8* temp = xml->getSelectedAttributeValueByName("second");edkEnd();
                        if(temp){
                            //convert the second
                            this->second = edk::String::strToFloat32(temp);edkEnd();
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
    edk::animation::Frame operator=(edk::animation::Frame frame){
        //
        this->second = frame.second;edkEnd();
        frame.cantDestruct();edkEnd();
        return *this;edkEnd();
    }
    //Operator ==
    inline bool operator==(edk::animation::Frame frame){frame.cantDestruct();edkEnd();return this->second==frame.second;edkEnd();}
    //Operator !=
    inline bool operator!=(edk::animation::Frame frame){frame.cantDestruct();edkEnd();return this->second!=frame.second;edkEnd();}
    //Operator >
    inline bool operator>(edk::animation::Frame frame){frame.cantDestruct();edkEnd();return this->second>frame.second;edkEnd();}
    //Operator >=
    inline bool operator>=(edk::animation::Frame frame){frame.cantDestruct();edkEnd();return this->second>=frame.second;edkEnd();}
    //Operator <
    inline bool operator<(edk::animation::Frame frame){frame.cantDestruct();edkEnd();return this->second<frame.second;edkEnd();}
    //Operator <=
    inline bool operator<=(edk::animation::Frame frame){frame.cantDestruct();edkEnd();return this->second<=frame.second;edkEnd();}
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // FRAME_H
