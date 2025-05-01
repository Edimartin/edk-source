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
#pragma message "Inside Vecs4f32"
#endif

#pragma once
#include "../TypeVec4.h"
#include "../vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling Vecs4f32"
#endif

namespace edk{
namespace collision{
//Vector with points returned by the collision functions
class Vecs4f32: public edk::vector::Stack<edk::vec4f32>{
public:
    Vecs4f32(){
        this->classThis=NULL;
        this->Constructor();
    }
    Vecs4f32(edk::uint32 size):
        edk::vector::Stack<edk::vec4f32>::Stack(size){
        this->classThis=NULL;
        this->Constructor(size);
    }
    virtual ~Vecs4f32(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::Stack<edk::vec4f32>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Constructor(edk::uint32 size){
        edk::vector::Stack<edk::vec4f32>::Constructor(size);
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            //delete the array
            this->clean();
        }
        edk::vector::Stack<edk::vec4f32>::Destructor();
    }

    edk::uint32 pushBack(edk::vec4f32 vec){
        //first create the vector
        return edk::vector::Stack<edk::vec4f32>::pushBack(vec);
    }
    edk::uint32 pushBack(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
        //first create the vector
        return edk::vector::Stack<edk::vec4f32>::pushBack(edk::vec4f32(x,y,z,w));
    }

    //OPERATORS
    //[]
    edk::vec4f32 operator[](edk::uint32 n){
        //
        return this->get(n);
    }
    virtual bool cloneFrom(edk::collision::Vecs4f32* vec){
        this->clean();
        return this->incrementFrom(vec);
    }
    virtual bool incrementFrom(edk::collision::Vecs4f32* vec){
        if(vec){
            //Just add new vectors
            edk::uint32 size = vec->size();
            for(edk::uint32 i=0u;i<size;i++){
                //copy the vectors
                edk::vector::Stack<edk::vec4f32>::pushBack(vec->get(i));
            }
            return true;
        }
        return false;
    }
protected:
private:
    edk::collision::Vecs4f32 operator=(edk::collision::Vecs4f32 vec){
        return vec;
    }
    //Operator increment
    edk::collision::Vecs4f32 operator+=(edk::collision::Vecs4f32 vec){
        return vec;
    }
private:
    edk::classID classThis;
};

}//end namespace collision
}//end namesoace edk

#endif
