#ifndef ARRAYSTATIC_H
#define ARRAYSTATIC_H


/*
Library ArrayStatic - Create an ArrayStatic in EDK Game Engine
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
#pragma message "Inside ArrayStatic"
#endif

#pragma once
#include <stdio.h>
#include <string.h>
#include "../TypeVars.h"
#include "../DebugFile.h"

#ifdef printMessages
#pragma message "    Compiling ArrayStatic"
#endif

namespace edk{
namespace vector{
//Use a template to alloc whatever
template <class typeTemplate>
//The arrayStaticClass
class ArrayStatic{
public:
    ArrayStatic(){}
    virtual ~ArrayStatic(){}

    virtual void construct(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    virtual void construct(edk::uint32 size){
        this->classThis=NULL;edkEnd();
        this->Constructor(size,false);edkEnd();
    }

    virtual void destruct(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            //delete the arrayStatic
            this->deleteArray();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;edkEnd();
            this->isClass = edk::ID<typeTemplate>::isClass();edkEnd();
            this->vector=NULL;edkEnd();
            this->vectorSize=0u;edkEnd();

            this->vectorPointer = &this->vector;edkEnd();
            this->vectorSizePointer = &this->vectorSize;edkEnd();

            this->deleteArray();edkEnd();
        }
    }
    void Constructor(edk::uint32 size,bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;edkEnd();
            this->isClass = edk::ID<typeTemplate>::isClass();edkEnd();
            this->vector=NULL;edkEnd();
            this->vectorSize=0u;edkEnd();

            this->vectorPointer = &this->vector;edkEnd();
            this->vectorSizePointer = &this->vectorSize;edkEnd();

            this->deleteArray();edkEnd();

            //create the array
            this->createArray(size);edkEnd();
        }
    }

    //create the array
    bool createArray(edk::uint32 size){
        //first delete
        this->deleteArray();edkEnd();

        //Test the size
        if(size){
            //create the new array
            if(this->isClass){
                (*this->vectorPointer) = new typeTemplate[size];edkEnd();
                if((*this->vectorPointer)){
                    //save the size of the vector
                    (*this->vectorSizePointer)=size;edkEnd();
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebugNoPosition(this,size,true);
#endif
                    return true;
                }
            }
            else{
                (*this->vectorPointer) = (typeTemplate*)malloc(sizeof(typeTemplate)*size);edkEnd();
                if((*this->vectorPointer)){
                    //save the size of the vector
                    (*this->vectorSizePointer)=size;edkEnd();
                    //set with nulls
                    memset((void*)(*this->vectorPointer),0u,sizeof(typeTemplate)*size);edkEnd();
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebugNoPosition(this,size,true);
#endif
                    //return true
                    return true;
                }
            }
        }
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebugNoPosition(this,size,false);
#endif
        //else return false
        return false;
    }

    //SETTERS
    bool set(edk::uint32 pos,typeTemplate obj){
        //test if have the pos
        if(pos<this->getSize()){
            //set the object
            memcpy((void*)&(*this->vectorPointer)[pos],(void*)&obj,sizeof(typeTemplate));edkEnd();
            //(*this->vectorPointer)[pos]=obj;edkEnd();
            //return true
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,this->generateDebugValue(&obj),true);
#endif
            return true;
        }
        //else return false
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,this->generateDebugValue(&obj),false);
#endif
        return false;
    }
    //SETTERS WITHOUT IF
    void setNoIF(edk::uint32 pos,typeTemplate obj){
        //set the object
        memcpy((void*)&(*this->vectorPointer)[pos],(void*)&obj,sizeof(typeTemplate));edkEnd();
    }

    //GETTERS
    //returrn the vector size
    edk::uint32  size(){
        //
        return (*this->vectorSizePointer);edkEnd();
    }
    edk::uint32  getSize(){
        //
        return this->size();edkEnd();
    }
    //test if have the object in the position
    bool have(edk::uint32 pos){
        if((*this->vectorPointer) && pos<this->getSize()){
            //return the variable
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,0uL,true);
#endif
            return true;
        }
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,0uL,false);
#endif
        return false;
    }
    //return true if have the array
    inline bool haveArray(){
        return (bool)((*this->vectorPointer));
    }
    //return the object
    inline typeTemplate get(edk::uint32 pos){
        typeTemplate ret;edkEnd();
        if(this->have(pos)){
            //return the variable
            memcpy((void*)&ret,(void*)&vector[pos],sizeof(typeTemplate));edkEnd();
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),true);
#endif
            return ret;
        }
        memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),false);
#endif
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
#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),true);
#endif
        return ret;
#pragma GCC diagnostic pop
    }

    //return the poiner
    inline typeTemplate* getPointer(){
        return (*this->vectorPointer);
    }

    //delete the array
    inline void deleteArray(){
        this->clean();edkEnd();
    }
    //delete the array
    inline void cleanArray(){
        this->clean();edkEnd();
    }
    void clean(){
        //test if is alloc
        if((*this->vectorPointer)){
            /*
            if(EDKArrayVectorFreeCounter == 44u){
                EDKArrayVectorFreeCounter++;
            }
            EDKArrayVectorFreeCounter++;
            */
            if(this->isClass){
                delete[] (*this->vectorPointer);edkEnd();
            }
            else{
                free((*this->vectorPointer));edkEnd();
            }
        }
        (*this->vectorPointer)=NULL;edkEnd();
        (*this->vectorSizePointer)=0u;edkEnd();
    }

    //set the array with a value
    bool setClean(typeTemplate value){
        if((*this->vectorPointer) && (*this->vectorSizePointer)){
            //set the array with the value
            for(edk::uint32 i=0u;i<(*this->vectorSizePointer);i++){
                this->set(i,value);edkEnd();
            }
            return true;
        }
        return false;
    }

    /*
        //OPERATORS
        //[]
        typeTemplate operator[](edk::uint32 n){
            //
            return this->get(n);edkEnd();
        }
        */

    virtual bool cloneFrom(edk::vector::ArrayStatic<typeTemplate>* vec){
        this->deleteArray();edkEnd();
        if(vec){
            if(this->createArray(vec->size())){
                memcpy((void*)(*this->vectorPointer),vec->vector,sizeof(typeTemplate) * vec->size());edkEnd();
            }
            return true;
        }
        return false;
    }

private:
    //the vector
    typeTemplate** vectorPointer;
    typeTemplate* vector;
    //size of the vector
    edk::uint32* vectorSizePointer;
    edk::uint32 vectorSize;

    //test if the typeTemplete is a class
    bool isClass;
private:
    edk::vector::ArrayStatic<typeTemplate> operator=(edk::vector::ArrayStatic<typeTemplate> vec){
        return vec;edkEnd();
    }
#if defined(EDK_DEBUG_VECTOR)
    inline edk::uint64 generateDebugValue(typeTemplate* value){
        edk::uint64 newValue=0uL;edkEnd();
        if(sizeof(typeTemplate)>=sizeof(newValue)){
            memcpy((void*)&newValue,(void*)value,sizeof(newValue));edkEnd();
        }
        else{
            memcpy((void*)&newValue,(void*)value,sizeof(typeTemplate));edkEnd();
        }
        return newValue;
    }
#endif
private:
    edk::classID classThis;
};
}//end namespace vector
}//end namespace edk

#endif // ARRAYSTATIC_H
