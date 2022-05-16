#ifndef EDK_COLLISIONS_VECS4F32_H
#define EDK_COLLISIONS_VECS4F32_H

/*
Library Vecs4f32 - Save vector points to collisions
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
#warning "Inside Vecs4f32"
#endif

#pragma once
#include "../TypeVec4.h"
#include "../vector/Stack.h"

#ifdef printMessages
#warning "    Compiling Vecs4f32"
#endif

namespace edk{
namespace collision{
//Vector with points returned by the collision functions
class Vecs4f32: private edk::vector::Stack<edk::vec4f32*>{
public:
    Vecs4f32(){
        //
        canDeleteVecs=false;
    }
    Vecs4f32(edk::uint32 size):
        edk::vector::Stack<edk::vec4f32*>::Stack(size) {
        //
        canDeleteVecs=false;
    }
    ~Vecs4f32(){
        //
        //delete the array
        if(this->canDeleteVecs){
            this->clean();
            this->canDeleteVecs=false;
        }
        else{
            //
            this->canDeleteVecs=true;
        }
    }
    void clean(){
        //clean
        for(edk::uint32 i=0u;i<this->size();i++){
            //
            if(edk::vector::Stack<edk::vec4f32*>::get(i)){
                //
                delete edk::vector::Stack<edk::vec4f32*>::get(i);
            }
        }
        edk::vector::Stack<edk::vec4f32*>::clean();
    }
    edk::uint32 pushBack(edk::vec4f32 vec){
        //first create the vector
        edk::vec4f32* temp=new edk::vec4f32(vec.x,vec.y,vec.z,vec.w);
        if(temp){
            //
            return edk::vector::Stack<edk::vec4f32*>::pushBack(temp);
        }
        //else return zero
        return 0u;
    }

    bool set(edk::vec4f32 vec,edk::uint32 pos){
        //test if have one vector in the position
        edk::vec4f32* temp = edk::vector::Stack<edk::vec4f32*>::get(pos);
        if(temp){
            //
            //set
            temp->x=vec.x;
            temp->y=vec.y;
            temp->z=vec.z;
            temp->w=vec.w;
            //return true
            return true;
        }
        else{
            //delete the temp
            temp=new edk::vec4f32(vec.x,vec.y,vec.z,vec.w);

            if(edk::vector::Stack<edk::vec4f32*>::set(pos,temp)){
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
        return edk::vector::Stack<edk::vec4f32*>::size();
    }
    edk::uint32  getSize(){
        //
        return this->size();
    }
    //return the object
    edk::vec4f32 get(edk::uint32 pos){
        //
        edk::vec4f32* temp = edk::vector::Stack<edk::vec4f32*>::get(pos);
        if(temp){
            //
            return edk::vec4f32(temp->x,temp->y,temp->z,temp->w);
        }
        //else return zero vector
        return edk::vec4f32(0,0,0,0);
    }

    //cant
    void cantDeleteVector(){
        //
        edk::vector::Stack<edk::vec4f32*>::cantDestroy();
    }
    //OPERATORS
    //[]
    edk::vec4f32 operator[](edk::uint32 n){
        //
        return this->get(n);
    }
    virtual bool cloneFrom(edk::collision::Vecs4f32* vec){
        if(vec){
            //first clean
            for(edk::uint32 i=0u;i<this->size();i++){
                //
                if(edk::vector::Stack<edk::vec4f32*>::get(i)){
                    //
                    delete edk::vector::Stack<edk::vec4f32*>::get(i);
                }
            }
            edk::vector::Stack<edk::vec4f32*>::clean();

            //Then add the new vectors
            for(edk::uint32 i=0u;i<vec->size();i++){
                //copy the vectors
                this->pushBack( edk::vec4f32(vec->get(i).x ,vec->get(i).y ,vec->get(i).z ,vec->get(i).w ) );
            }
            return true;
        }
        return false;
    }
    virtual bool incrementFrom(edk::collision::Vecs4f32* vec){
        if(vec){
            //Just add new vectors
            for(edk::uint32 i=0u;i<vec->size();i++){
                //copy the vectors
                this->pushBack( edk::vec4f32(vec->get(i).x ,vec->get(i).y ,vec->get(i).z ,vec->get(i).w ) );
            }
            return true;
        }
        return false;
    }
protected:
private:
    bool canDeleteVecs;

    edk::collision::Vecs4f32 operator=(edk::collision::Vecs4f32 vec){
        //first clean
        for(edk::uint32 i=0u;i<this->size();i++){
            //
            if(edk::vector::Stack<edk::vec4f32*>::get(i)){
                //
                delete edk::vector::Stack<edk::vec4f32*>::get(i);
            }
        }
        edk::vector::Stack<edk::vec4f32*>::clean();

        //Then add the new vectors
        for(edk::uint32 i=0u;i<vec.size();i++){
            //copy the vectors
            this->pushBack( edk::vec4f32(vec[i].x ,vec[i].y ,vec[i].z ,vec[i].w ) );
        }
        //set to cant delete the vector
        vec.cantDeleteVector();
        return vec;
    }
    //Operator increment
    edk::collision::Vecs4f32 operator+=(edk::collision::Vecs4f32 vec){
        //dont clean the vector
        /*
            for(edk::uint32 i=0u;i<this->size();i++){
                //
                if(edk::vector::Stack<edk::vec4f32*>::get(i)){
                        //
                    delete edk::vector::Stack<edk::vec4f32*>::get(i);
                }
            }
            edk::vector::Stack<edk::vec4f32*>::clean();
            */

        //Just add new vectors
        for(edk::uint32 i=0u;i<vec.size();i++){
            //copy the vectors
            this->pushBack( edk::vec4f32(vec[i].x ,vec[i].y ,vec[i].z ,vec[i].w ) );
        }
        //set to cant delete the vector
        vec.cantDeleteVector();
        return vec;
    }
};

}//end namespace collision
}//end namesoace edk

#endif
