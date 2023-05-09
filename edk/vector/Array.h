#ifndef EDK_VECTOR_ARRAY_H
#define EDK_VECTOR_ARRAY_H

/*
Library Array - Create an Array in EDK Game Engine
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
#pragma message "Inside Array"
#endif

#pragma once
#include <stdio.h>
#include <string.h>
#include "../TypeVars.h"
#include "../DebugFile.h"

#ifdef printMessages
#pragma message "    Compiling Array"
#endif

namespace edk{
namespace vector{
//Use a template to alloc whatever
template <class typeTemplate>
//The arrayClass
class Array{
public:
    Array(){
        this->vector=NULL;edkEnd();
        this->vectorSize=0u;edkEnd();
        this->canDeleteVector=false;edkEnd();
        this->deleteArray();edkEnd();
    }
    Array(edk::uint32 size){
        this->vector=NULL;edkEnd();
        this->vectorSize=0u;edkEnd();
        this->canDeleteVector=false;edkEnd();
        this->deleteArray();edkEnd();

        //create the array
        this->createArray(size);edkEnd();
    }
    virtual ~Array(){
        //delete the array
        if(this->canDeleteVector){
            //
            this->deleteArray();edkEnd();
        }
        this->canDeleteVector=false;edkEnd();
    }

    //create the array
    bool createArray(edk::uint32 size){
        //first delete
        this->deleteArray();edkEnd();

        //Test the size
        if(size){
            //create the new array
            if( ( this->vector = new typeTemplate[size] ) ){
                //save the size of the vector
                this->vectorSize=size;edkEnd();
                //can delete the vector
                this->canDeleteVector=true;edkEnd();
                //set with nulls
                memset((void*)this->vector,0u,sizeof(typeTemplate)*size);edkEnd();
                //return true
                return true;
            }
        }
        //else return false
        return false;
    }

    //SETTERS
    bool set(edk::uint32 pos,typeTemplate obj){
        //test if have the pos
        if(pos<this->getSize()){
            //set the object
            memcpy((void*)&this->vector[pos],(void*)&obj,sizeof(typeTemplate));edkEnd();
            //this->vector[pos]=obj;edkEnd();
            //return true
            return true;
        }
        //else return false
        return false;
    }
    //SETTERS WITHOUT IF
    void setNoIF(edk::uint32 pos,typeTemplate obj){
        //set the object
        memcpy((void*)&this->vector[pos],(void*)&obj,sizeof(typeTemplate));edkEnd();
    }

    //GETTERS
    //returrn the vector size
    edk::uint32  size(){
        //
        return this->vectorSize;edkEnd();
    }
    edk::uint32  getSize(){
        //
        return this->size();edkEnd();
    }
    //test if have the object in the position
    bool have(edk::uint32 pos){
        if(this->vector && pos<this->getSize()){
            //return the variable
            return true;
        }
        return false;
    }
    //return true if have the array
    inline bool haveArray(){
        return (bool)(this->vector);
    }
    //return the object
    inline typeTemplate get(edk::uint32 pos){
        typeTemplate ret;edkEnd();
        memcpy((void*)&ret,(void*)&vector[pos],sizeof(typeTemplate));edkEnd();
        if(this->have(pos)){
            //return the variable
            memcpy((void*)&ret,(void*)&vector[pos],sizeof(typeTemplate));edkEnd();
        }
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
        return ret;
#pragma GCC diagnostic pop
    }
    //GETTERS WITHOUT IF
    inline typeTemplate getNoIF(edk::uint32 pos){
        typeTemplate ret;edkEnd();
        //return the variable
        memcpy((void*)&ret,(void*)&vector[pos],sizeof(typeTemplate));edkEnd();
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
        return ret;
#pragma GCC diagnostic pop
    }

    //return the poiner
    inline typeTemplate* getPointer(){
        return this->vector;
    }

    //delete the array
    inline void deleteArray(){
        this->clean();
    }
    //delete the array
    inline void cleanArray(){
        this->clean();
    }
    void clean(){
        //test if is alloc
        if(this->vector){
            /*
            if(EDKArrayVectorFreeCounter == 44u){
                EDKArrayVectorFreeCounter++;
            }
            EDKArrayVectorFreeCounter++;
            */
            delete[] this->vector;edkEnd();
        }
        this->vector=NULL;edkEnd();
        this->vectorSize=0u;edkEnd();
        this->canDeleteVector=false;edkEnd();
    }

    //cant
    void cantDeleteVector(){
        //
        this->canDeleteVector=false;edkEnd();
    }

    /*
        //OPERATORS
        //[]
        typeTemplate operator[](edk::uint32 n){
            //
            return this->get(n);edkEnd();
        }
        */

    virtual bool cloneFrom(edk::vector::Array<typeTemplate>* vec){
        this->deleteArray();edkEnd();
        if(vec){
            if(this->createArray(vec->size())){
                memcpy((void*)this->vector,vec->vector,sizeof(typeTemplate) * vec->size());edkEnd();
            }
            return true;
        }
        return false;
    }

private:
    //the vector
    typeTemplate* vector;
    //size of the vector
    edk::uint32 vectorSize;
    //test if can delete the vector
    bool canDeleteVector;
private:
    edk::vector::Array<typeTemplate> operator=(edk::vector::Array<typeTemplate> vec){
        //
        this->deleteArray();edkEnd();
        if(this->createArray(vec.size())){
            //
            for(edk::uint32 i=0u;i<vec.size();i++){
                //
                memcpy((void*)&this->vector[i],(void*)&vec[i],sizeof(typeTemplate));edkEnd();
            }
        }
        vec.cantDeleteVector();edkEnd();
        return vec;edkEnd();
    }
};
}//end namespace vector
}//end namespace edk

#endif // ARRAY_H
