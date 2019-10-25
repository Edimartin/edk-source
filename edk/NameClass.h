#ifndef NAMECLASS_H
#define NAMECLASS_H

/*
Library C++ NameClass - Add a name to an Class
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
        this->_name=NULL;
        this->_size = 0u;
        this->canDelete=true;
    }
    Name(edk::char8* _name){
        //
        this->_name=NULL;
        this->_size = 0u;
        this->setName(_name);
        this->canDelete=true;
    }
    Name(const char* _name){
        //
        this->_name=NULL;
        this->_size = 0u;
        this->setName(_name);
        this->canDelete=true;
    }
    virtual ~Name(){
        //
        if(this->canDelete){
            this->deleteName();
        }
        else{
            this->canDelete=true;
        }
    }
    //clean the name
    void cleanName(){
        this->setName((edk::char8*)NULL);
    }
    bool setName(const char* _name){
        return this->setName((edk::char8*) _name);
    }
    //set the name
    bool setName(edk::char8* _name){
        //delete the lastName
        this->deleteName();
        //test the new name
        if(_name){
            //copy the name
            this->_name = edk::String::strCopy(_name);
            if(this->_name){
                this->_size = edk::String::strSize(this->_name);
                return true;
            }
        }
        //else return false
        return false;
    }
    //get the name
    edk::char8* getName(){
        //
        return this->_name;
    }
    edk::char8* name(){
        //
        return this->_name;
    }
    //return the name size
    edk::uint32 getSize(){
        return this->size();
    }
    edk::uint32 size(){
        return this->_size;
    }

    bool nameEqual(edk::char8* _name){
        return edk::Name::stringEqual(this->_name,_name);
    }
    bool nameEqual(const char* _name){
        return this->nameEqual((edk::char8*) _name);
    }
    bool nameEqual(edk::Name* _name){
        if(_name)
            return edk::Name::stringEqual(this->_name,_name->_name);
        return false;
    }
    bool nameBiggerThan(edk::char8* _name){
        return edk::Name::firstNameBiggerSecond(this->_name,_name);
    }
    bool nameBiggerThan(const char* _name){
        return nameBiggerThan((edk::char8*) _name);
    }
    bool nameBiggerThan(edk::Name* _name){
        if(_name)
            return edk::Name::firstNameBiggerSecond(this->_name,_name->_name);
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
    virtual void cantDelete(){
        this->canDelete=false;
    }
protected:
    //delete the name
    void deleteName(){
        //
        if(this->_name){
            delete[] this->_name;
            this->_name=NULL;
        }
        this->_size = 0u;
    }

private:
    //have just one string with one name
    edk::char8* _name;
    edk::uint32 _size;
    bool canDelete;
};
}

#endif // NAMECLASS_H
