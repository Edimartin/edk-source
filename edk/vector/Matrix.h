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
class MatrixDynamic{
public:
    MatrixDynamic(){
        this->canDeleteVector=true;
        this->matrixSize = 0u;
        //set the matrix to NULL
        this->matrix=NULL;
        //set can delete vector
    }
    MatrixDynamic(edk::size2f32 size){
        this->canDeleteVector=true;
        //set the matrix to NULL
        this->matrix=NULL;
        //create a new matrix
        this->createMatrix(size);
    }
    MatrixDynamic(edk::uint32 width,edk::uint32 height){
        this->canDeleteVector=true;
        //set the matrix to NULL
        this->matrix=NULL;
        //create a new matrix
        this->createMatrix(width,height);
    }
    ~MatrixDynamic(){
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
            memcpy(&this->matrix[position.y][position.x],&obj,sizeof(typeTemplate));
            //return true
            return true;
        }
        //else return false
        return false;
    }
    bool set(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        return this->set(edk::vec2ui32(x,y),obj);
    }
    //set the matrix as identity
    bool setIdentity(typeTemplate valueOne,typeTemplate valueZero){
        if(this->matrixSize.width && this->matrixSize.height){
            for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                    if(x==y){
                        memcpy(&this->matrix[y][x],&valueOne,sizeof(typeTemplate));
                    }
                    else{
                        memcpy(&this->matrix[y][x],&valueZero,sizeof(typeTemplate));
                    }
                }
            }
            return true;
        }
        return false;
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
    bool isEqual(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(matrix){
            if(this->matrix
                    && matrix->matrix
                    && this->matrixSize.width==matrix->matrixSize.width
                    && this->matrixSize.height==matrix->matrixSize.height
                    ){
                for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                    for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                        if(memcmp(this->matrix[y][x],matrix->matrix[y][x],sizeof(typeTemplate))){
                            return false;
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }
    bool isEqualSize(edk::vector::MatrixDynamic<typeTemplate>* matrix){
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
    bool add(edk::vector::MatrixDynamic<typeTemplate>* matrix){
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
    bool sub(edk::vector::MatrixDynamic<typeTemplate>* matrix){
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
    //return true if can multiply
    inline bool canMultiply(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(this->matrix && this->matrixSize.width && this->matrixSize.height
                &&
                matrix->matrix && matrix->matrixSize.width && matrix->matrixSize.height
                ){
            //first compare if can have the product of the matrix
            if(this->matrixSize.width == matrix->matrixSize.height){
                return true;
            }
        }
        return false;
    }
    bool multiply(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(canMultiply(matrix)){
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
        return false;
    }
    static inline bool canMultiplyMatrices(edk::vector::MatrixDynamic<typeTemplate>* matrix1,edk::vector::MatrixDynamic<typeTemplate>* matrix2){
        if(matrix1->matrix && matrix1->matrixSize.width && matrix1->matrixSize.height
                &&
                matrix2->matrix && matrix2->matrixSize.width && matrix2->matrixSize.height
                ){
            //first compare if can have the product of the matrix
            if(matrix1->matrixSize.width == matrix2->matrixSize.height){
                return true;
            }
        }
        return false;
    }
    inline bool canMultiply(edk::vector::MatrixDynamic<typeTemplate>* matrix1,edk::vector::MatrixDynamic<typeTemplate>* matrix2){
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyMatrices(matrix1,matrix2);
    }

    bool multiply(edk::vector::MatrixDynamic<typeTemplate>* matrix1,edk::vector::MatrixDynamic<typeTemplate>* matrix2){
        if(this->canMultiply(matrix1,matrix2)){
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
    }

    bool cloneFrom(edk::vector::MatrixDynamic<typeTemplate>* matrix){
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

    //the operators are private because I can's fix it yet
private:
    edk::vector::MatrixDynamic<typeTemplate>* operator=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->cloneFrom(&matrix);
        matrix.cantDeleteVector();
        return this;
    }
    bool operator==(edk::vector::MatrixDynamic<typeTemplate> matrix){
        matrix.cantDeleteVector();
        return this->isEqual(&matrix);
    }
    bool operator!=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        matrix.cantDeleteVector();
        return !this->isEqual(&matrix);
    }
    edk::vector::MatrixDynamic<typeTemplate> operator+(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->add(&matrix);
        return matrix;
    }
    edk::vector::MatrixDynamic<typeTemplate> operator++(edk::int32 n){
        this->increment(n);
        return this;
    }
    edk::vector::MatrixDynamic<typeTemplate> operator++(){
        this->increment(1);
        return this;
    }
    void operator+=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->add(&matrix);
    }
    edk::vector::MatrixDynamic<typeTemplate> operator-(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->sub(&matrix);
        return matrix;
    }
    edk::vector::MatrixDynamic<typeTemplate> operator--(){
        this->decrement(1);
        return this;
    }
    edk::vector::MatrixDynamic<typeTemplate> operator--(edk::int32 n){
        this->decrement(n);
        return this;
    }
    void operator-=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->sub(&matrix);
    }
    edk::vector::MatrixDynamic<typeTemplate> operator*(edk::vector::MatrixDynamic<typeTemplate> matrix){
        edk::vector::MatrixDynamic<typeTemplate> ret;
        ret.multiply(this,&matrix);
        return ret;
    }
    edk::vector::MatrixDynamic<typeTemplate> operator*=(edk::vector::MatrixDynamic<typeTemplate> matrix){
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
public:
    //cant
    void cantDeleteVector(){
        this->canDeleteVector=false;
    }
};
//Use a template to alloc whatever
template <class typeTemplate,edk::uint32 m,edk::uint32 n>
class Matrix : private edk::vector::MatrixDynamic<typeTemplate>{
public:
    inline Matrix(){
        this->canDeleteMatrix=true;
        edk::vector::MatrixDynamic<typeTemplate>::createMatrix(m,n);
        if(m==n){
            canMultiplyMatrix=true;
        }
        else{
            canMultiplyMatrix=false;
        }
    }
    inline ~Matrix(){
        if(this->canDeleteMatrix){
            edk::vector::MatrixDynamic<typeTemplate>::deleteMatrix();
        }
        else{
            this->canDeleteMatrix=true;
        }
    }

    //SETTERS
    inline bool set(edk::vec2ui32 position,typeTemplate obj){
        return edk::vector::MatrixDynamic<typeTemplate>::set(position,obj);
    }
    inline bool set(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        return edk::vector::MatrixDynamic<typeTemplate>::set(x,y,obj);
    }
    //set the matrix as identity
    inline bool setIdentity(typeTemplate valueOne,typeTemplate valueZero){
        return edk::vector::MatrixDynamic<typeTemplate>::setIdentity(valueOne,valueZero);
    }

    //GETTERS
    //returrn the matrix size
    inline edk::size2ui32 size(){
        return edk::vector::MatrixDynamic<typeTemplate>::size();
    }
    inline edk::uint32 width(){
        return edk::vector::MatrixDynamic<typeTemplate>::width();
    }
    inline edk::uint32 height(){
        return edk::vector::MatrixDynamic<typeTemplate>::height();
    }
    inline edk::size2ui32  getSize(){
        return edk::vector::MatrixDynamic<typeTemplate>::getSize();
    }
    inline edk::uint32 getWidth(){
        return edk::vector::MatrixDynamic<typeTemplate>::getWidth();
    }
    inline edk::uint32 getHeight(){
        return edk::vector::MatrixDynamic<typeTemplate>::getHeight();
    }
    //test if have the object in the position
    inline bool have(edk::vec2ui32 position){
        return edk::vector::MatrixDynamic<typeTemplate>::have(position);
    }
    inline bool have(edk::uint32 x,edk::uint32 y){
        return edk::vector::MatrixDynamic<typeTemplate>::have(x,y);
    }
    inline bool haveMatrix(){
        return edk::vector::MatrixDynamic<typeTemplate>::haveMatrix();
    }
    //return the value in a position
    inline typeTemplate get(edk::vec2ui32 position){
        return edk::vector::MatrixDynamic<typeTemplate>::get(position);
    }
    //return the value in a position
    inline typeTemplate get(edk::uint32 x,edk::uint32 y){
        return edk::vector::MatrixDynamic<typeTemplate>::get(x,y);
    }

    //test if a matrix is equal then other
    inline bool isEqual(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::isEqual(matrix);
    }
    //add the matrix with another
    inline bool add(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::add(matrix);
    }
    //add the matrix with another
    inline bool increment(edk::int32 value){
        return edk::vector::MatrixDynamic<typeTemplate>::increment(value);
    }
    //sub the matrix with another
    inline bool sub(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::sub(matrix);
    }
    //add the matrix with another
    inline bool decrement(edk::int32 value){
        return edk::vector::MatrixDynamic<typeTemplate>::decrement(value);
    }

    //return true if can multiply
    inline bool canMultiply(){
        return this->canMultiplyMatrix;
    }
    inline bool canMultiply(edk::vector::MatrixDynamic<typeTemplate>*){
        return this->canMultiplyMatrix;
    }
    inline bool multiply(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        if(this->canMultiplyMatrix)
            return edk::vector::MatrixDynamic<typeTemplate>::multiply(matrix);
        return false;
    }
    //return true if can multiply
    inline bool canMultiply(edk::vector::MatrixDynamic<typeTemplate>*,edk::vector::MatrixDynamic<typeTemplate>*){
        return this->canMultiplyMatrix;
    }
    inline bool multiply(edk::vector::Matrix<typeTemplate,m,n>* matrix1,edk::vector::Matrix<typeTemplate,m,n>* matrix2){
        if(this->canMultiplyMatrix)
            return edk::vector::MatrixDynamic<typeTemplate>::multiply(matrix1,matrix2);
        return false;
    }

    //print the matrix
    inline bool printMatrix(){
        return edk::vector::MatrixDynamic<typeTemplate>::printMatrix();
    }

    inline bool cloneFrom(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::cloneFrom(matrix);
    }

    //the operators are private because I can's fix it yet
private:
    inline edk::vector::Matrix<typeTemplate,m,n>* operator=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->cloneFrom(&matrix);
        return &matrix;
    }
    inline bool operator==(edk::vector::Matrix<typeTemplate,m,n> matrix){
        matrix.cantDeleteVector();
        return this->isEqual(&matrix);
    }
    inline bool operator!=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        matrix.cantDeleteVector();
        return !this->isEqual(&matrix);
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator+(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->add(&matrix);
        matrix.cantDeleteMatrix();
        return matrix;
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator++(edk::int32 value){
        this->increment(value);
        return this;
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator++(){
        this->increment(1);
        return this;
    }
    inline void operator+=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->add(&matrix);
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator-(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->sub(&matrix);
        matrix.cantDeleteMatrix();
        return matrix;
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator--(){
        this->decrement(1);
        return this;
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator--(edk::int32 value){
        this->decrement(value);
        return this;
    }
    inline void operator-=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->sub(&matrix);
        matrix.cantDeleteMatrix();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator*(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->multiply(&matrix);
        matrix.cantDeleteMatrix();
        this->cantDeleteMatrix();
        return *this;
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator*=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->multiply(&matrix);
        matrix.cantDeleteMatrix();
        this->cantDeleteMatrix();
        return *this;
    }
protected:
    inline void printElement(edk::uint32 x,edk::uint32 y,typeTemplate* value){
        printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);
    }
private:
    //test if can delete the vector
    bool canDeleteMatrix;
    //save if can multiply the matrix
    bool canMultiplyMatrix;
public:
    //cant
    void cantDeleteMatrix(){
        this->canDeleteMatrix=false;
        edk::vector::MatrixDynamic<typeTemplate>::cantDeleteVector();
    }
};
}//end namespace vector
}//end namespace edk

#endif // MATRIX_H
