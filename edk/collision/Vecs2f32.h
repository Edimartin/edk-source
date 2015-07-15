#ifndef EDK_COLLISIONS_VECS2F32_H
#define EDK_COLLISIONS_VECS2F32_H

/*
Library Vecs2f32 - Save vector points to collisions
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
#warning "Inside Vecs2f32"
#endif

#pragma once
#include "../TypeVec2.h"
#include "../vector/Stack.h"

#ifdef printMessages
#warning "    Compiling Vecs2f32"
#endif

namespace edk{
namespace collision{
//Vector with points returned by the collision functions
class Vecs2f32: private edk::vector::Stack<edk::vec2f32*>{
public:
    Vecs2f32(){
        //
        canDeleteVecs=false;
    }
    Vecs2f32(edk::uint32 size):
        edk::vector::Stack<edk::vec2f32*>::Stack(size) {
        //
        canDeleteVecs=false;
    }
    ~Vecs2f32(){
        //
        //delete the array
        if(this->canDeleteVecs){
            //clean
            for(edk::uint32 i=0u;i<this->size();i++){
                //
                if(edk::vector::Stack<edk::vec2f32*>::get(i)){
                    //
                    delete edk::vector::Stack<edk::vec2f32*>::get(i);
                }
            }

            this->canDeleteVecs=false;
        }
        else{
            //
            this->canDeleteVecs=true;
        }
    }
    edk::uint32 pushBack(edk::vec2f32 vec){
        //first create the vector
        edk::vec2f32* temp=new edk::vec2f32(vec.x,vec.y);
        if(temp){
            //
            return edk::vector::Stack<edk::vec2f32*>::pushBack(temp);
        }
        //else return zero
        return 0u;
    }

    bool set(edk::vec2f32 vec,edk::uint32 pos){
        //test if have one vector in the position
        edk::vec2f32* temp = edk::vector::Stack<edk::vec2f32*>::get(pos);
        if(temp){
            //
            //set
            temp->x=vec.x;
            temp->y=vec.y;
            //return true
            return true;
        }
        else{
            //delete the temp
            temp=new edk::vec2f32(vec.x,vec.y);

            if(edk::vector::Stack<edk::vec2f32*>::set(pos,temp)){
                //
                return true;
            }
            else{
                //
                delete temp;
            }
        }
        temp=NULL;
        return false;
    }

    //GETTERS
    //returrn the vector size
    edk::uint32  size(){
        //
        return edk::vector::Stack<edk::vec2f32*>::size();
    }
    edk::uint32  getSize(){
        //
        return this->size();
    }
    //return the object
    edk::vec2f32 get(edk::uint32 pos){
        //
        edk::vec2f32* temp = edk::vector::Stack<edk::vec2f32*>::get(pos);
        if(temp){
            //
            return edk::vec2f32(temp->x,temp->y);
        }
        //else return zero vector
        return edk::vec2f32(0,0);
    }

    //cant
    void cantDeleteVector(){
        //
        edk::vector::Stack<edk::vec2f32*>::cantDestroy();
    }
    //OPERATORS
    //[]
    edk::vec2f32 operator[](edk::uint32 n){
        //
        return this->get(n);
    }
    edk::collision::Vecs2f32 operator=(edk::collision::Vecs2f32 vec){
        //first clean
        for(edk::uint32 i=0u;i<this->size();i++){
            //
            if(edk::vector::Stack<edk::vec2f32*>::get(i)){
                //
                delete edk::vector::Stack<edk::vec2f32*>::get(i);
            }
        }
        edk::vector::Stack<edk::vec2f32*>::clean();

        //Then add the new vectors
        for(edk::uint32 i=0u;i<vec.size();i++){
            //copy the vectors
            this->pushBack( edk::vec2f32(vec[i].x ,vec[i].y ) );
        }
        //set to cant delete the vector
        vec.cantDeleteVector();
        return vec;
    }
    //Operator increment
    edk::collision::Vecs2f32 operator+=(edk::collision::Vecs2f32 vec){
        //dont clean the vector
        /*
            for(edk::uint32 i=0u;i<this->size();i++){
                //
                if(edk::vector::Stack<edk::vec2f32*>::get(i)){
                        //
                    delete edk::vector::Stack<edk::vec2f32*>::get(i);
                }
            }
            edk::vector::Stack<edk::vec2f32*>::clean();
            */

        //Just add new vectors
        for(edk::uint32 i=0u;i<vec.size();i++){
            //copy the vectors
            this->pushBack( edk::vec2f32(vec[i].x ,vec[i].y ) );
        }
        //set to cant delete the vector
        vec.cantDeleteVector();
        return vec;
    }
protected:
private:
    bool canDeleteVecs;
};

}//end namespace collision
}//end namesoace edk

#endif // POINT2F_H
