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
#warning "Inside NameClass"
#endif

#pragma once
#include "TypeVars.h"
#include "String.h"

#ifdef printMessages
#warning "    Compiling NameClass"
#endif


//Class with name to save in the nameTree
namespace edk{
class Name{
public:
    Name(){
        //
        this->_name=NULL;edkEnd();
        this->_size = 0u;edkEnd();
        this->canDelete=true;edkEnd();
    }
    Name(edk::char8* _name){
        //
        this->_name=NULL;edkEnd();
        this->_size = 0u;edkEnd();
        this->setName(_name);edkEnd();
        this->canDelete=true;edkEnd();
    }
    Name(const edk::char8* _name){
        //
        this->_name=NULL;edkEnd();
        this->_size = 0u;edkEnd();
        this->setName(_name);edkEnd();
        this->canDelete=true;edkEnd();
    }
    virtual ~Name(){
        //
        if(this->canDelete){
            this->deleteName();edkEnd();
        }
        else{
            this->canDelete=true;edkEnd();
        }
    }
    //clean the name
    void cleanName(){
        this->setName((edk::char8*)NULL);edkEnd();
    }
    bool setName(const edk::char8* _name){
        return this->setName((edk::char8*) _name);edkEnd();
    }
    //set the name
    bool setName(edk::char8* _name){
        //delete the lastName
        this->deleteName();edkEnd();
        //test the new name
        if(_name){
            //copy the name
            this->_name = edk::String::strCopy(_name);edkEnd();
            if(this->_name){
                this->_size = edk::String::strSize(this->_name);edkEnd();
                return true;
            }
        }
        //else return false
        return false;
    }
    //get the name
    edk::char8* getName(){
        //
        return this->_name;edkEnd();
    }
    edk::char8* name(){
        //
        return this->_name;edkEnd();
    }
    bool haveName(){
        return this->_name && this->_size;edkEnd();
    }
    //return the name size
    edk::uint32 getSize(){
        return this->size();edkEnd();
    }
    edk::uint32 size(){
        return this->_size;edkEnd();
    }

    bool nameEqual(edk::char8* _name){
        return edk::Name::stringEqual(this->_name,_name);edkEnd();
    }
    bool nameEqual(const edk::char8* _name){
        return this->nameEqual((edk::char8*) _name);edkEnd();
    }
    bool nameEqual(edk::Name* _name){
        if(_name){
            return edk::Name::stringEqual(this->_name,_name->_name);edkEnd();
        }
        return false;
    }
    bool nameBiggerThan(edk::char8* _name){
        return edk::Name::firstNameBiggerSecond(this->_name,_name);edkEnd();
    }
    bool nameBiggerThan(const edk::char8* _name){
        return nameBiggerThan((edk::char8*) _name);edkEnd();
    }
    bool nameBiggerThan(edk::Name* _name){
        if(_name){
            return edk::Name::firstNameBiggerSecond(this->_name,_name->_name);edkEnd();
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
                name2++;edkEnd();
                name1++;edkEnd();
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
                name1++;edkEnd();
                name2++;edkEnd();
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
    virtual void cantDelete(){
        this->canDelete=false;edkEnd();
    }
protected:
    //delete the name
    void deleteName(){
        //
        if(this->_name){
            delete[] this->_name;edkEnd();
            this->_name=NULL;edkEnd();
        }
        this->_size = 0u;edkEnd();
    }

private:
    //have just one string with one name
    edk::char8* _name;
    edk::uint32 _size;
    bool canDelete;
};
}

#endif // NAMECLASS_H
