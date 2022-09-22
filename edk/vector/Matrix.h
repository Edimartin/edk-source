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
        this->canDeleteVector=true;
        this->matrixSize = 0u;
        //set the matrix to NULL
        this->matrix=NULL;
        //set can delete vector
    }
    Matrix(edk::size2f32 size){
        this->canDeleteVector=true;
        //set the matrix to NULL
        this->matrix=NULL;
        //create a new matrix
        this->createMatrix(size);
    }
    Matrix(edk::uint32 width,edk::uint32 height){
        this->canDeleteVector=true;
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
        else{
            this->canDeleteVector=true;
        }
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
                for(edk::uint32 i=0u;i<size.height;i++){
                    this->matrix[i] = new typeTemplate[size.width];
                    if(this->matrix[i]){
                        memset(this->matrix[i],0u,sizeof(typeTemplate)*size.width);
                    }
                    else{
                        for(edk::uint32 j=i+1u;i>0u;j--){
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
        if(this->have(position)){
            //return the variable
            return this->matrix[position.y][position.x];
        }
        typeTemplate ret; memset((void*)&ret,0u,sizeof(typeTemplate));
        return ret;
    }
    //return the value in a position
    typeTemplate get(edk::uint32 x,edk::uint32 y){
        return this->get(edk::vec2ui32(x,y));
    }

    //test if a matrix is equal then other
    bool isEqual(edk::vector::Matrix<typeTemplate>* matrix){
        if(matrix){
            if(this->matrix
                    && matrix->matrix
                    && this->matrixSize.width==matrix->matrixSize.width
                    && this->matrixSize.height==matrix->matrixSize.height
                    ){
                for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                    for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                        if(this->matrix[y][x]!=matrix->matrix[y][x]){
                            return false;
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }
    bool isEqualSize(edk::vector::Matrix<typeTemplate>* matrix){
        if(matrix){
            if(this->matrix
                    && matrix->matrix
                    && this->matrixSize.width==matrix->matrixSize.width
                    && this->matrixSize.height==matrix->matrixSize.height
                    ){
                return true;
            }
        }
        return false;
    }
    //add the matrix with another
    bool add(edk::vector::Matrix<typeTemplate>* matrix){
        //test if the matrix is equal in size
        if(this->isEqualSize(matrix)){
            for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                    this->matrix[y][x]=this->matrix[y][x]+matrix->matrix[y][x];
                }
            }
            return true;
        }
        return false;
    }
    //add the matrix with another
    bool increment(edk::int32 n){
        //test if the matrix is equal in size
        if(this->matrix && this->matrixSize.width && this->matrixSize.height){
            for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                    this->matrix[y][x]=this->matrix[y][x]+n;
                }
            }
            return true;
        }
        return false;
    }
    //sub the matrix with another
    bool sub(edk::vector::Matrix<typeTemplate>* matrix){
        //test if the matrix is equal in size
        if(this->isEqualSize(matrix)){
            for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                    this->matrix[y][x]=this->matrix[y][x]-matrix->matrix[y][x];
                }
            }
            return true;
        }
        return false;
    }
    //add the matrix with another
    bool decrement(edk::int32 n){
        //test if the matrix is equal in size
        if(this->matrix && this->matrixSize.width && this->matrixSize.height){
            for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                    this->matrix[y][x]=this->matrix[y][x]-n;
                }
            }
            return true;
        }
        return false;
    }
    bool multiply(edk::vector::Matrix<typeTemplate>* matrix){
        if(this->matrix && this->matrixSize.width && this->matrixSize.height
                &&
                matrix->matrix && matrix->matrixSize.width && matrix->matrixSize.height
                ){
            //first compare if can have the product of the matrix
            if(this->matrixSize.width == matrix->matrixSize.height){
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32(matrix->matrixSize.width,this->matrixSize.height);


                typeTemplate** newMatrix = new typeTemplate*[size.height];
                typeTemplate value;
                if(newMatrix){
                    memset(newMatrix,0u,sizeof(typeTemplate)*size.height);
                    for(edk::uint32 y=0u;y<size.height;y++){
                        newMatrix[y] = new typeTemplate[size.width];
                        if(newMatrix[y]){
                            memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);
                            for(edk::uint32 x=0u;x<size.width;x++){
                                //clean the value
                                memset((void*)&value,0u,sizeof(typeTemplate));
                                //multiply
                                for(edk::uint32 i=0u;i<this->matrixSize.width;i++){
                                    value = value + (this->matrix[y][i] * matrix->matrix[i][x]);
                                }
                                //set the value
                                newMatrix[y][x]=value;
                            }
                        }
                        else{
                            for(edk::uint32 j=y+1u;y>0u;j--){
                                //delete the matrix
                                delete[] newMatrix[j];
                            }
                            delete[] newMatrix;
                            return false;
                        }
                    }
                    //in the end. delete the old matrix and copy the new matrix
                    this->deleteMatrix();
                    this->matrix = newMatrix;
                    this->matrixSize = size;
                    return true;
                }
            }
        }
        return false;
    }
    bool multiply(edk::vector::Matrix<typeTemplate>* matrix1,edk::vector::Matrix<typeTemplate>* matrix2){
        if(matrix1->matrix && matrix1->matrixSize.width && matrix1->matrixSize.height
                &&
                matrix2->matrix && matrix2->matrixSize.width && matrix2->matrixSize.height
                ){
            //first compare if can have the product of the matrix
            if(matrix1->matrixSize.width == matrix2->matrixSize.height){
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32(matrix2->matrixSize.width,matrix1->matrixSize.height);


                typeTemplate** newMatrix = new typeTemplate*[size.height];
                typeTemplate value;
                if(newMatrix){
                    memset(newMatrix,0u,sizeof(typeTemplate)*size.height);
                    for(edk::uint32 y=0u;y<size.height;y++){
                        newMatrix[y] = new typeTemplate[size.width];
                        if(newMatrix[y]){
                            memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);
                            for(edk::uint32 x=0u;x<size.width;x++){
                                //clean the value
                                memset((void*)&value,0u,sizeof(typeTemplate));
                                //multiply
                                for(edk::uint32 i=0u;i<matrix1->matrixSize.width;i++){
                                    value = value + (matrix1->matrix[y][i] * matrix2->matrix[i][x]);
                                }
                                //set the value
                                newMatrix[y][x]=value;
                            }
                        }
                        else{
                            for(edk::uint32 j=y+1u;y>0u;j--){
                                //delete the matrix
                                delete[] newMatrix[j];
                            }
                            delete[] newMatrix;
                            return false;
                        }
                    }
                    //in the end. delete the old matrix and copy the new matrix
                    this->deleteMatrix();
                    this->matrix = newMatrix;
                    this->matrixSize = size;
                    return true;
                }
            }
        }
        return false;
    }

    //print the matrix
    bool printMatrix(){
        if(this->matrix && this->matrixSize.width && this->matrixSize.height){
            printf("\nMatrix [%u] [%u]",this->matrixSize.width,this->matrixSize.height);
            for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                    this->printElement(x,y,&this->matrix[y][x]);
                }
            }fflush(stdout);
            return true;
        }
        return false;
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

    bool cloneFrom(edk::vector::Matrix<typeTemplate>* matrix){
        this->deleteMatrix();
        if(matrix){
            if(matrix->matrixSize.width && matrix->matrixSize.height){
                if(this->createMatrix(matrix->matrixSize.width,matrix->matrixSize.height)){
                    //copy the values
                    for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                        memcpy(this->matrix[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);
                    }
                    return true;
                }
            }
        }
        return false;
    }

    edk::vector::Matrix<typeTemplate>* operator=(edk::vector::Matrix<typeTemplate> matrix){
        this->cloneFrom(&matrix);
        matrix.cantDeleteVector();
        return this;
    }
    bool operator==(edk::vector::Matrix<typeTemplate> matrix){
        matrix.cantDeleteVector();
        return this->isEqual(&matrix);
    }
    bool operator!=(edk::vector::Matrix<typeTemplate> matrix){
        matrix.cantDeleteVector();
        return !this->isEqual(&matrix);
    }
    edk::vector::Matrix<typeTemplate> operator+(edk::vector::Matrix<typeTemplate> matrix){
        this->add(&matrix);
        return matrix;
    }
    edk::vector::Matrix<typeTemplate> operator++(edk::int32 n){
        this->increment(n);
        return matrix;
    }
    edk::vector::Matrix<typeTemplate> operator++(){
        this->increment(1);
        return matrix;
    }
    void operator+=(edk::vector::Matrix<typeTemplate> matrix){
        this->add(&matrix);
    }
    edk::vector::Matrix<typeTemplate> operator-(edk::vector::Matrix<typeTemplate> matrix){
        this->sub(&matrix);
        return matrix;
    }
    edk::vector::Matrix<typeTemplate> operator--(){
        this->decrement(1);
        return matrix;
    }
    edk::vector::Matrix<typeTemplate> operator--(edk::int32 n){
        this->decrement(n);
        return matrix;
    }
    void operator-=(edk::vector::Matrix<typeTemplate> matrix){
        this->sub(&matrix);
    }
    edk::vector::Matrix<typeTemplate> operator*(edk::vector::Matrix<typeTemplate> matrix){
        edk::vector::Matrix<typeTemplate> ret;
        ret.multiply(this,&matrix);
        return ret;
    }
    edk::vector::Matrix<typeTemplate> operator*=(edk::vector::Matrix<typeTemplate> matrix){
        this->multiply(&matrix);
        return *this;
    }
protected:
    void printElement(edk::uint32 x,edk::uint32 y,typeTemplate* value){
        printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);
    }

private:
    typeTemplate** matrix;
    //size of the vector
    edk::size2ui32 matrixSize;
    //test if can delete the vector
    bool canDeleteVector;

    //cant
    void cantDeleteVector(){
        this->canDeleteVector=false;
    }
};
}//end namespace vector
}//end namespace edk

#endif // MATRIX_H
