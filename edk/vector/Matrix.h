#ifndef MATRIX_H
#define MATRIX_H

/*
Library Matrix - Create a Matrix in EDK Game Engine
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
#include "../TypeSize2.h"
#include "../TypeVec2.h"
#include <string.h>

#ifdef printMessages
#warning "    Compiling Array"
#endif

namespace edk{
namespace vector{
//Use a template to alloc whatever
template <class typeTemplate>
class Matrix{
public:
    Matrix(){
        //set the matrix to NULL
        this->matrix=NULL;
    }
    Matrix(edk::size2f32 size){
        //set the matrix to NULL
        this->matrix=NULL;
        //create a new matrix
        this->createMatrix(size);
    }
    Matrix(edk::uint32 width,edk::uint32 height){
        //set the matrix to NULL
        this->matrix=NULL;
        //create a new matrix
        this->createMatrix(width,height);
    }
    ~Matrix(){
        //
        if(this->canDeleteVector){
            this->deleteMatrix();
        }
        this->canDeleteVector=false;
    }


    //create the matrix
    bool createMatrix(edk::size2ui32 size){
        //first delete
        this->deleteMatrix();

        //Test the size
        if(size.width && size.height){
            this->matrix = new typeTemplate*[size.height];
            if(this->matrix){
                memset(this->matrix,0u,sizeof(typeTemplate)*size.height);
                for(edk::uint32 i=0u;i<size.width;i++){
                    this->matrix[i] = new typeTemplate[size.width];
                    if(this->matrix[i]){
                        memset(this->matrix[i],0u,sizeof(typeTemplate)*size.width);
                    }
                    else{
                        for(edk::uint32 j=i+1u;i>0u;i--){
                            //delete the matrix
                            delete[] this->matrix[j];
                        }
                        delete[] this->matrix;
                        return false;
                    }
                }
                this->matrixSize = size;
                return true;
            }
        }
        //else return false
        return false;
    }
    bool createMatrix(edk::uint32 width,edk::uint32 height){
        return this->createMatrix(edk::size2ui32(width,height));
    }

    //SETTERS
    bool set(edk::vec2ui32 position,typeTemplate obj){
        //test if have the pos
        if(position.x<this->getWidth() && position.y < this->getHeight()){
            //set the object
            this->matrix[position.y][position.x]=obj;
            //return true
            return true;
        }
        //else return false
        return false;
    }
    bool set(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        return this->set(edk::vec2ui32(x,y),obj);
    }

    //GETTERS
    //returrn the matrix size
    edk::size2ui32 size(){
        return this->matrixSize;
    }
    edk::uint32 width(){
        return this->matrixSize.width;
    }
    edk::uint32 height(){
        return this->matrixSize.height;
    }
    edk::size2ui32  getSize(){
        return this->matrixSize;
    }
    edk::uint32 getWidth(){
        return this->matrixSize.width;
    }
    edk::uint32 getHeight(){
        return this->matrixSize.height;
    }
    //test if have the object in the position
    bool have(edk::vec2ui32 position){
        if(this->matrix && position.x<this->matrixSize.width && position.y<this->matrixSize.height){
            //return true
            return true;
        }
        return false;
    }
    bool have(edk::uint32 x,edk::uint32 y){
        return this->have(edk::vec2f32(x,y));
    }
    bool haveMatrix(){
        if(this->matrix && this->matrixSize.width && this->matrixSize.height){
            return true;
        }
        return false;
    }
    //return the value in a position
    typeTemplate get(edk::vec2ui32 position){
        //
        typeTemplate ret;
        if(this->have(position)){
            //return the variable
            return this->matrix[position.y][position.x];
        }
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
        return ret;
#pragma GCC diagnostic pop
    }
    //return the value in a position
    typeTemplate get(edk::uint32 x,edk::uint32 y){
        return this->get(edk::vec2ui32(x,y));
    }

    //delete the array
    void deleteMatrix(){
        //test if is alloc
        if(this->matrix){
            //
            for(edk::uint32 i=0u;i<this->matrixSize.height;i++){
                delete[] this->matrix[i];
            }
            delete[] this->matrix;
        }
        this->matrix=NULL;
        this->matrixSize=0u;
        this->canDeleteVector=false;
    }


    //cant
    void cantDeleteVector(){
        //
        this->canDeleteVector=false;
    }

    bool cloneFrom(edk::vector::Matrix<typeTemplate>* matrix){
        this->deleteMatrix();
        if(matrix){
            if(matrix->matrixSize.width && matrix->matrixSize.height){
                if(this->createMatrix(matrix->matrixSize.width,matrix->matrixSize.height)){
                    //copy the values
                    for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                        for(edk::uint32 x=0u;x<matrix->matrixSize.width;x++){
                            this->matrix[y][x] = matrix->matrix[y][x];
                        }
                    }
                    return true;
                }
            }
        }
        return false;
    }

private:
    typeTemplate** matrix;
    //size of the vector
    edk::size2ui32 matrixSize;
    //test if can delete the vector
    bool canDeleteVector;
};
}//end namespace vector
}//end namespace edk

#endif // MATRIX_H
