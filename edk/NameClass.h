#ifndef NAMECLASS_H
#define NAMECLASS_H

/*
Library C++ NameClass - Add a name to an Class
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
#pragma message "Inside NameClass"
#endif

#pragma once
#include "TypeVars.h"
#include "String.h"

#ifdef printMessages
#pragma message "    Compiling NameClass"
#endif


//Class with name to save in the nameTree
namespace edk{
class Name{
public:
    Name(){
        this->classThis=NULL;
        this->Constructor();
    }
    Name(edk::char8* _name){
        this->classThis=NULL;
        this->Constructor(_name);
    }
    Name(const edk::char8* _name){
        this->classThis=NULL;
        this->Constructor(_name);
    }
    virtual ~Name(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->_name=NULL;
            this->_size = 0u;
            this->_namePointer=&this->_name;
            this->_sizePointer=&this->_size;
        }
    }
    void Constructor(edk::char8* _name){
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->_name=NULL;
            this->_size = 0u;

            this->_namePointer=&this->_name;
            this->_sizePointer=&this->_size;

            this->setName(_name);
        }
    }
    void Constructor(const edk::char8* _name){
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->_name=NULL;
            this->_size = 0u;

            this->_namePointer=&this->_name;
            this->_sizePointer=&this->_size;

            this->setName(_name);
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->deleteName();
        }
    }

    //clean the name
    void cleanName(){
        this->setName((edk::char8*)NULL);
    }
    bool setName(const edk::char8* _name){
        return this->setName((edk::char8*) _name);
    }
    //set the name
    bool setName(edk::char8* _name){
        //delete the lastName
        this->deleteName();
        //test the new name
        if(_name){
            //copy the name
            (*this->_namePointer) = edk::String::strCopy(_name);
            if((*this->_namePointer)){
                (*this->_sizePointer) = edk::String::strSize((*this->_namePointer));
                return true;
            }
        }
        //else return false
        return false;
    }
    bool clone(edk::Name* name){
        if(name){
            return this->setName(name->getName());
        }
        return false;
    }
    bool clone(edk::Name name){
        return this->setName(name.getName());
    }
    //get the name
    edk::char8* getName(){
        //
        return (*this->_namePointer);
    }
    edk::char8* name(){
        //
        return (*this->_namePointer);
    }
    bool haveName(){
        return (*this->_namePointer) && (*this->_sizePointer);
    }
    //return the name size
    edk::uint32 getSize(){
        return this->size();
    }
    edk::uint32 size(){
        return (*this->_sizePointer);
    }

    bool nameEqual(edk::char8* _name){
        return edk::Name::stringEqual((*this->_namePointer),_name);
    }
    bool nameEqual(const edk::char8* _name){
        return this->nameEqual((edk::char8*) _name);
    }
    bool nameEqual(edk::Name* _name){
        if(_name){
            return edk::Name::stringEqual((*this->_namePointer),_name->_name);
        }
        return false;
    }
    bool nameBiggerThan(edk::char8* _name){
        return edk::Name::firstNameBiggerSecond((*this->_namePointer),_name);
    }
    bool nameBiggerThan(const edk::char8* _name){
        return nameBiggerThan((edk::char8*) _name);
    }
    bool nameBiggerThan(edk::Name* _name){
        if(_name){
            return edk::Name::firstNameBiggerSecond((*this->_namePointer),_name->_name);
        }
        return false;
    }

    //compare the names
    static bool firstNameBiggerSecond(edk::char8* name1,edk::char8* name2){
        //test the strings
        if(name1 && name2){
            //test if name1 is bigger
            while(*name1!='\0' || *name2!='\0'){
                //test if the first is bigger then second
                if(*name1>*name2){
                    //the return true
                    return true;
                }
                else if(*name2>*name1){
                    //
                    break;
                }
                //else equal increment i
                name2++;
                name1++;
            }
        }
        //else return false
        return false;
    }
    static bool stringEqual(edk::char8* name1,edk::char8* name2){
        //test the two strings
        if(name1 && name2){
            //compare the two strings
            while(*name1!='\0' || *name2!='\0'){
                //test if the first is bigger then second
                if(*name1!=*name2){
                    //the return true
                    return false;
                }
                //else equal increment i
                name1++;
                name2++;
            }
            //test if are equal
            if(*name1==*name2){
                //return true
                return true;
            }
        }
        //else return false
        return false;
    }
    bool print(){
        if(this->haveName()){
            printf("%s",this->getName());
            return true;
        }
        return false;
    }
protected:
    //delete the name
    void deleteName(){
        //
        if((*this->_namePointer)){
            free((*this->_namePointer));
            (*this->_namePointer)=NULL;
        }
        (*this->_sizePointer) = 0u;
    }

private:
    //have just one string with one name
    edk::char8** _namePointer;
    edk::char8* _name;
    edk::uint32* _sizePointer;
    edk::uint32 _size;
private:
    edk::classID classThis;
};
}

#endif // NAMECLASS_H
