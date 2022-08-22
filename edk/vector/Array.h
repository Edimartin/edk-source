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
#warning "Inside Array"
#endif

#pragma once
#include <stdio.h>
#include "../TypeVars.h"

#ifdef printMessages
#warning "    Compiling Array"
#endif

namespace edk{
namespace vector{
//Use a template to alloc whatever
template <class typeTemplate>
//The arrayClass
class Array{
    public:
        Array(){
            //
            this->vector=NULL;
            this->canDeleteVector=false;
            this->vectorSize=0u;
            this->deleteArray();
        }
        Array(edk::uint32 size){
            //
            this->vector=NULL;
            this->canDeleteVector=false;
            this->vectorSize=0u;
            this->deleteArray();

            //create the array
            this->createArray(size);
        }
        virtual ~Array(){
            //delete the array
            if(this->canDeleteVector){
                //
                this->deleteArray();
            }
            this->canDeleteVector=false;
        }

        //create the array
        bool createArray(edk::uint32 size){
            //first delete
            this->deleteArray();

            //Test the size
            if(size){
                //create the new array
                if( ( this->vector = new typeTemplate[size] ) ){
                    //save the size of the vector
                    this->vectorSize=size;
                    //can delete the vector
                    this->canDeleteVector=true;
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
                this->vector[pos]=obj;
                //return true
                return true;
            }
            //else return false
            return false;
        }

        //GETTERS
        //returrn the vector size
        edk::uint32  size(){
            //
            return this->vectorSize;
        }
        edk::uint32  getSize(){
            //
            return this->size();
        }
        //test if have the object in the position
        bool have(edk::uint32 pos){
            if(this->vector && pos<this->getSize()){
                //return the variable
                return true;
            }
            return false;
        }
        //return the object
        typeTemplate get(edk::uint32 pos){
            //
            typeTemplate ret;
            /*
            printf("\nVector %u pos %u getSize(%u)"
                   ,(edk::uint32)this->vector
                   ,(edk::uint32)pos
                   ,(edk::uint32)this->getSize()
                   );
            */
            if(this->have(pos)){
                //return the variable
                return vector[pos];
            }
            #pragma GCC diagnostic push
            #pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
            return ret;
            #pragma GCC diagnostic pop
        }

        //delete the array
        void deleteArray(){
            //test if is alloc
            if(this->vector){
                //
                delete[] vector;
            }
            vector=NULL;
            vectorSize=0u;
            this->canDeleteVector=false;
        }

        //cant
        void cantDeleteVector(){
            //
            this->canDeleteVector=false;
        }

        //OPERATORS
        //[]
        typeTemplate operator[](edk::uint32 n){
            //
            return this->get(n);
        }

        virtual bool cloneFrom(edk::vector::Array<typeTemplate>* vec){
            this->deleteArray();
            if(vec){
                if(this->createArray(vec->size())){
                    //
                    for(edk::uint32 i=0u;i<vec->size();i++){
                        //
                        this->vector[i]=vec->get(i);
                    }
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
        this->deleteArray();
        if(this->createArray(vec.size())){
            //
            for(edk::uint32 i=0u;i<vec.size();i++){
                //
                this->vector[i]=vec[i];
            }
        }
        vec.cantDeleteVector();
        return vec;
    }
};
}//end namespace vector
}//end namespace edk

#endif // ARRAY_H
