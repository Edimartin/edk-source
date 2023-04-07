#ifndef EDK_COLLISIONS_VECS3F32_H
#define EDK_COLLISIONS_VECS3F32_H

/*
Library Vecs3f32 - Save vector points to collisions
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
#pragma message "Inside Vecs3f32"
#endif

#pragma once
#include "../TypeVec3.h"
#include "../vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling Vecs3f32"
#endif

namespace edk{
namespace collision{
//Vector with points returned by the collision functions
class Vecs3f32: private edk::vector::Stack<edk::vec3f32*>{
public:
    Vecs3f32(){
        //
        canDeleteVecs=false;edkEnd();
    }
    Vecs3f32(edk::uint32 size):
        edk::vector::Stack<edk::vec3f32*>::Stack(size){
        //
        canDeleteVecs=false;edkEnd();
    }
    ~Vecs3f32(){
        //
        //delete the array
        if(this->canDeleteVecs){
            this->clean();edkEnd();
            this->canDeleteVecs=false;edkEnd();
        }
        else{
            //
            this->canDeleteVecs=true;edkEnd();
        }
    }
    void clean(){
        //clean
        for(edk::uint32 i=0u;i<this->size();i++){
            //
            if(edk::vector::Stack<edk::vec3f32*>::get(i)){
                //
                delete edk::vector::Stack<edk::vec3f32*>::get(i);edkEnd();
            }
        }
        edk::vector::Stack<edk::vec3f32*>::clean();edkEnd();
    }
    edk::uint32 pushBack(edk::vec3f32 vec){
        //first create the vector
        edk::vec3f32* temp=new edk::vec3f32(vec.x,vec.y,vec.z);edkEnd();
        if(temp){
            //
            return edk::vector::Stack<edk::vec3f32*>::pushBack(temp);edkEnd();
        }
        //else return zero
        return 0u;edkEnd();
    }

    bool set(edk::vec3f32 vec,edk::uint32 pos){
        //test if have one vector in the position
        edk::vec3f32* temp = edk::vector::Stack<edk::vec3f32*>::get(pos);edkEnd();
        if(temp){
            //
            //set
            temp->x=vec.x;edkEnd();
            temp->y=vec.y;edkEnd();
            temp->z=vec.z;edkEnd();
            //return true
            return true;
        }
        else{
            //delete the temp
            temp=new edk::vec3f32(vec.x,vec.y,vec.z);edkEnd();

            if(edk::vector::Stack<edk::vec3f32*>::set(pos,temp)){
                //
                return true;
            }
            else{
                //
                delete temp;edkEnd();
            }
        }
        temp=NULL;edkEnd();
        return false;
    }

    //GETTERS
    //returrn the vector size
    edk::uint32  size(){
        //
        return edk::vector::Stack<edk::vec3f32*>::size();edkEnd();
    }
    edk::uint32  getSize(){
        //
        return this->size();edkEnd();
    }
    //return the object
    edk::vec3f32 get(edk::uint32 pos){
        //
        edk::vec3f32* temp = edk::vector::Stack<edk::vec3f32*>::get(pos);edkEnd();
        if(temp){
            //
            return edk::vec3f32(temp->x,temp->y,temp->z);edkEnd();
        }
        //else return zero vector
        return edk::vec3f32(0,0,0);edkEnd();
    }

    //cant
    void cantDeleteVector(){
        //
        edk::vector::Stack<edk::vec3f32*>::cantDestroy();edkEnd();
    }
    //OPERATORS
    //[]
    edk::vec3f32 operator[](edk::uint32 n){
        //
        return this->get(n);edkEnd();
    }
    virtual bool cloneFrom(edk::collision::Vecs3f32* vec){
        if(vec){
            //first clean
            for(edk::uint32 i=0u;i<this->size();i++){
                //
                if(edk::vector::Stack<edk::vec3f32*>::get(i)){
                    //
                    delete edk::vector::Stack<edk::vec3f32*>::get(i);edkEnd();
                }
            }
            edk::vector::Stack<edk::vec3f32*>::clean();edkEnd();

            //Then add the new vectors
            for(edk::uint32 i=0u;i<vec->size();i++){
                //copy the vectors
                this->pushBack( edk::vec3f32(vec->get(i).x ,vec->get(i).y ,vec->get(i).z ) );edkEnd();
            }
            return true;
        }
        return false;
    }
    virtual bool incrementFrom(edk::collision::Vecs3f32* vec){
        if(vec){
            //Just add new vectors
            for(edk::uint32 i=0u;i<vec->size();i++){
                //copy the vectors
                this->pushBack( edk::vec3f32(vec->get(i).x ,vec->get(i).y ,vec->get(i).z ) );edkEnd();
            }
            return true;
        }
        return false;
    }
protected:
private:
    bool canDeleteVecs;

    edk::collision::Vecs3f32 operator=(edk::collision::Vecs3f32 vec){
        //first clean
        for(edk::uint32 i=0u;i<this->size();i++){
            //
            if(edk::vector::Stack<edk::vec3f32*>::get(i)){
                //
                delete edk::vector::Stack<edk::vec3f32*>::get(i);edkEnd();
            }
        }
        edk::vector::Stack<edk::vec3f32*>::clean();edkEnd();

        //Then add the new vectors
        for(edk::uint32 i=0u;i<vec.size();i++){
            //copy the vectors
            this->pushBack( edk::vec3f32(vec[i].x ,vec[i].y ,vec[i].z ) );edkEnd();
        }
        //set to cant delete the vector
        vec.cantDeleteVector();edkEnd();
        return vec;edkEnd();
    }
    //Operator increment
    edk::collision::Vecs3f32 operator+=(edk::collision::Vecs3f32 vec){
        //dont clean the vector
        /*
            for(edk::uint32 i=0u;i<this->size();i++){
                //
                if(edk::vector::Stack<edk::vec3f32*>::get(i)){
                        //
                    delete edk::vector::Stack<edk::vec3f32*>::get(i);edkEnd();
                }
            }
            edk::vector::Stack<edk::vec3f32*>::clean();edkEnd();
            */

        //Just add new vectors
        for(edk::uint32 i=0u;i<vec.size();i++){
            //copy the vectors
            this->pushBack( edk::vec3f32(vec[i].x ,vec[i].y ,vec[i].z ) );edkEnd();
        }
        //set to cant delete the vector
        vec.cantDeleteVector();edkEnd();
        return vec;edkEnd();
    }
};

}//end namespace collision
}//end namesoace edk

#endif
