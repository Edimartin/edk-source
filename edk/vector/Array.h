#ifndef EDK_VECTOR_ARRAY_H
#define EDK_VECTOR_ARRAY_H

/*
Library Array - Create a Array in EDK Game Engine
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
        ~Array(){
            //delete the array
            if(this->canDeleteVector){
                //
                this->deleteArray();
                this->canDeleteVector=false;
            }
            else{
                //
                this->canDeleteVector=true;
            }
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

    protected:
    private:
    //the vector
    typeTemplate* vector;
    //size of the vector
    edk::uint32 vectorSize;
    //test if can delete the vector
    bool canDeleteVector;
};
}//end namespace vector
}//end namespace edk

#endif // ARRAY_H
