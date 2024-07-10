#ifndef EDK_COLLISIONS_VECS2F32_H
#define EDK_COLLISIONS_VECS2F32_H

/*
Library Vecs2f32 - Save vector points to collisions
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
#pragma message "Inside Vecs2f32"
#endif

#pragma once
#include "../TypeVec2.h"
#include "../vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling Vecs2f32"
#endif

namespace edk{
namespace collision{
//Vector with points returned by the collision functions
class Vecs2f32: public edk::vector::Stack<edk::vec2f32>{
public:
    Vecs2f32(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    Vecs2f32(edk::uint32 size):
        edk::vector::Stack<edk::vec2f32>::Stack(size){
        this->classThis=NULL;edkEnd();
        this->Constructor(size,false);edkEnd();
    }
    virtual ~Vecs2f32(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            //delete the array
            this->clean();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::vector::Stack<edk::vec2f32>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Constructor(edk::uint32 size,bool runFather=true){
        if(runFather){
            edk::vector::Stack<edk::vec2f32>::Constructor(size);edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    edk::uint32 pushBack(edk::vec2f32 vec){
        //first create the vector
        return edk::vector::Stack<edk::vec2f32>::pushBack(vec);
    }
    edk::uint32 pushBack(edk::float32 x,edk::float32 y){
        //first create the vector
        return edk::vector::Stack<edk::vec2f32>::pushBack(edk::vec2f32(x,y));
    }

    //OPERATORS
    //[]
    edk::vec2f32 operator[](edk::uint32 n){
        //
        return this->get(n);edkEnd();
    }
    virtual bool cloneFrom(edk::collision::Vecs2f32* vec){
        this->clean();
        return this->incrementFrom(vec);
    }
    virtual bool incrementFrom(edk::collision::Vecs2f32* vec){
        if(vec){
            //Just add new vectors
            edk::uint32 size = vec->size();
            for(edk::uint32 i=0u;i<size;i++){
                //copy the vectors
                edk::vector::Stack<edk::vec2f32>::pushBack(vec->get(i));edkEnd();
            }
            return true;
        }
        return false;
    }
protected:
private:
    edk::collision::Vecs2f32 operator=(edk::collision::Vecs2f32 vec){
        return vec;
    }
    //Operator increment
    edk::collision::Vecs2f32 operator+=(edk::collision::Vecs2f32 vec){
        return vec;
    }
private:
    edk::classID classThis;
};

}//end namespace collision
}//end namesoace edk

#endif
