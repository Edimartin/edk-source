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
#pragma message "Inside Array"
#endif

#pragma once
#include <stdio.h>
#include "../TypeVars.h"
#include "../TypeSize2.h"
#include "../TypeVec2.h"
#include "../DebugFile.h"
#include <string.h>

#ifdef printMessages
#pragma message "    Compiling Array"
#endif

namespace edk{
namespace vector{
//Use a template to alloc whatever
template <class typeTemplate>
class MatrixDynamic{
public:
    MatrixDynamic(){
        this->canDeleteVector=true;edkEnd();
        this->matrixSize = 0u;edkEnd();
        //set the matrix to NULL
        this->matrix=NULL;edkEnd();
        this->matrixDest=NULL;edkEnd();
        //set can delete vector
    }
    MatrixDynamic(edk::size2f32 size){
        this->canDeleteVector=true;edkEnd();
        //set the matrix to NULL
        this->matrix=NULL;edkEnd();
        this->matrixDest=NULL;edkEnd();
        //create a new matrix
        this->createMatrix(size);edkEnd();
    }
    MatrixDynamic(edk::uint32 width,edk::uint32 height){
        this->canDeleteVector=true;edkEnd();
        //set the matrix to NULL
        this->matrix=NULL;edkEnd();
        this->matrixDest=NULL;edkEnd();
        //create a new matrix
        this->createMatrix(width,height);edkEnd();
    }
    ~MatrixDynamic(){
        if(this->canDeleteVector){
            this->deleteMatrix();edkEnd();
        }
        else{
            this->canDeleteVector=true;edkEnd();
        }
    }


    //create the matrix
    bool createMatrix(edk::size2ui32 size){
        //first delete
        this->deleteMatrix();edkEnd();

        //Test the size
        if(size.width && size.height){
            this->matrix = new typeTemplate*[size.height];edkEnd();
            if(this->matrix){
                memset(this->matrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                for(edk::uint32 i=0u;i<size.height;i++){
                    this->matrix[i] = new typeTemplate[size.width];edkEnd();
                    if(this->matrix[i]){
                        memset(this->matrix[i],0u,sizeof(typeTemplate)*size.width);edkEnd();
                    }
                    else{
                        for(edk::uint32 j=i+1u;i>0u;j--){
                            //delete the matrix
                            delete[] this->matrix[j];edkEnd();
                        }
                        delete[] this->matrix;edkEnd();
                        return false;
                    }
                }
                this->matrixSize = size;edkEnd();
                return true;
            }
        }
        //else return false
        return false;
    }
    bool createMatrix(edk::uint32 width,edk::uint32 height){
        return this->createMatrix(edk::size2ui32(width,height));edkEnd();
    }

    //SETTERS
    bool set(edk::vec2ui32 position,typeTemplate obj){
        //test if have the pos
        if(position.x<this->getWidth() && position.y < this->getHeight()){
            //set the object
            memcpy(&this->matrix[position.y][position.x],&obj,sizeof(typeTemplate));edkEnd();
            //return true
            return true;
        }
        //else return false
        return false;
    }
    bool set(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        return this->set(edk::vec2ui32(x,y),obj);edkEnd();
    }
    //SETTER WITHOUT IF
    inline void setNoIF(edk::vec2ui32 position,typeTemplate obj){
        memcpy(&this->matrix[position.y][position.x],&obj,sizeof(typeTemplate));edkEnd();
    }
    inline void setNoIF(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        memcpy(&this->matrix[y][x],&obj,sizeof(typeTemplate));edkEnd();
    }
    //set the matrix as identity
    bool setIdentity(typeTemplate valueOne,typeTemplate valueZero){
        if(this->matrixSize.width && this->matrixSize.height){
            for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                    if(x==y){
                        memcpy(&this->matrix[y][x],&valueOne,sizeof(typeTemplate));edkEnd();
                    }
                    else{
                        memcpy(&this->matrix[y][x],&valueZero,sizeof(typeTemplate));edkEnd();
                    }
                }
            }
            return true;
        }
        return false;
    }

    //GETTERS
    //returrn the matrix size
    inline edk::size2ui32 size(){
        return this->matrixSize;edkEnd();
    }
    inline edk::uint32 width(){
        return this->matrixSize.width;edkEnd();
    }
    inline edk::uint32 height(){
        return this->matrixSize.height;edkEnd();
    }
    inline edk::size2ui32  getSize(){
        return this->matrixSize;edkEnd();
    }
    inline edk::uint32 getWidth(){
        return this->matrixSize.width;edkEnd();
    }
    inline edk::uint32 getHeight(){
        return this->matrixSize.height;edkEnd();
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
        return this->have(edk::vec2f32(x,y));edkEnd();
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
            return this->matrix[position.y][position.x];edkEnd();
        }
        typeTemplate ret;edkEnd(); memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
        return ret;
    }
    //return the value in a position
    typeTemplate get(edk::uint32 x,edk::uint32 y){
        return this->get(edk::vec2ui32(x,y));edkEnd();
    }
    //GETTERS WITHOUT IF
    inline typeTemplate getNoIF(edk::vec2ui32 position){
        //return the variable
        return this->matrix[position.y][position.x];
    }
    //return the value in a position
    inline typeTemplate getNoIF(edk::uint32 x,edk::uint32 y){
        return this->matrix[y][x];
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
                    this->matrix[y][x]=this->matrix[y][x]+matrix->matrix[y][x];edkEnd();
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
                    this->matrix[y][x]=this->matrix[y][x]+n;edkEnd();
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
                    this->matrix[y][x]=this->matrix[y][x]-matrix->matrix[y][x];edkEnd();
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
                    this->matrix[y][x]=this->matrix[y][x]-n;edkEnd();
                }
            }
            return true;
        }
        return false;
    }
    //return true if can multiply
    inline bool canMultiplyThisWithMatrix(edk::vector::MatrixDynamic<typeTemplate>* matrix){
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
    inline bool canMultiplyMatrixWithThis(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(this->matrix && this->matrixSize.width && this->matrixSize.height
                &&
                matrix->matrix && matrix->matrixSize.width && matrix->matrixSize.height
                ){
            //first compare if can have the product of the matrix
            if(matrix->matrixSize.width == this->matrixSize.height){
                return true;
            }
        }
        return false;
    }
    bool multiplyThisWithMatrix(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(this->canMultiplyThisWithMatrix(matrix)){
            typeTemplate destSum;edkEnd();
            typeTemplate destMultiply;edkEnd();
            if(this->matrixSize.width==matrix->matrixSize.width){
                //test if have the matrixDest
                if(!this->matrixDest){
                    //create the matrixDest
                    this->createMatrixDest();edkEnd();
                }
                if(this->matrixDest){
                    //copy the values
                    for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                        for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                            //clean the value
                            memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                            //multiply
                            for(edk::uint32 i=0u;i<this->matrixSize.width;i++){
                                this->multiplyElement(&this->matrix[y][i],&matrix->matrix[i][x],&destMultiply);edkEnd();
                                this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                            }
                            //set the value
                            memcpy((void*)&matrixDest[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                        }
                    }
                    this->flipMatrix();edkEnd();
                    return true;
                }
            }
            else{
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32(matrix->matrixSize.width,this->matrixSize.height);edkEnd();

                typeTemplate** newMatrix = new typeTemplate*[size.height];edkEnd();
                if(newMatrix){
                    memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                    for(edk::uint32 y=0u;y<size.height;y++){
                        newMatrix[y] = new typeTemplate[size.width];edkEnd();
                        if(newMatrix[y]){
                            memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);edkEnd();
                            for(edk::uint32 x=0u;x<size.width;x++){
                                //clean the value
                                memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                                //multiply
                                for(edk::uint32 i=0u;i<this->matrixSize.width;i++){
                                    this->multiplyElement(&this->matrix[y][i],&matrix->matrix[i][x],&destMultiply);edkEnd();
                                    this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                                }
                                //set the value
                                memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                            }
                        }
                        else{
                            for(edk::uint32 j=y+1u;y>0u;j--){
                                //delete the matrix
                                delete[] newMatrix[j];edkEnd();
                            }
                            delete[] newMatrix;edkEnd();
                            return false;
                        }
                    }
                    //in the end. delete the old matrix and copy the new matrix
                    this->deleteMatrix();edkEnd();
                    this->matrix = newMatrix;edkEnd();
                    this->matrixSize = size;edkEnd();
                    return true;
                }
            }
        }
        return false;
    }
    bool multiplyMatrixWithThis(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(this->canMultiplyMatrixWithThis(matrix)){
            typeTemplate destSum;edkEnd();
            typeTemplate destMultiply;edkEnd();
            if(this->matrixSize.height==matrix->matrixSize.height){
                //test if have the matrixDest
                if(!this->matrixDest){
                    //create the matrixDest
                    this->createMatrixDest();edkEnd();
                }
                if(this->matrixDest){
                    //copy the values
                    for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                        for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                            //clean the value
                            memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                            //multiply
                            for(edk::uint32 i=0u;i<matrix->matrixSize.width;i++){
                                this->multiplyElement(&matrix->matrix[y][i],&this->matrix[i][x],&destMultiply);edkEnd();
                                this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                            }
                            //set the value
                            memcpy((void*)&matrixDest[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                        }
                    }
                    this->flipMatrix();edkEnd();
                    return true;
                }
            }
            else{
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32(this->matrixSize.width,matrix->matrixSize.height);edkEnd();

                typeTemplate** newMatrix = new typeTemplate*[size.height];edkEnd();
                if(newMatrix){
                    memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                    for(edk::uint32 y=0u;y<size.height;y++){
                        newMatrix[y] = new typeTemplate[size.width];edkEnd();
                        if(newMatrix[y]){
                            memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);edkEnd();
                            for(edk::uint32 x=0u;x<size.width;x++){
                                //clean the value
                                memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                                //multiply
                                for(edk::uint32 i=0u;i<matrix->matrixSize.width;i++){
                                    this->multiplyElement(&matrix->matrix[y][i],&this->matrix[i][x],&destMultiply);edkEnd();
                                    this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                                }
                                //set the value
                                memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                            }
                        }
                        else{
                            for(edk::uint32 j=y+1u;y>0u;j--){
                                //delete the matrix
                                delete[] newMatrix[j];edkEnd();
                            }
                            delete[] newMatrix;edkEnd();
                            return false;
                        }
                    }
                    //in the end. delete the old matrix and copy the new matrix
                    this->deleteMatrix();edkEnd();
                    this->matrix = newMatrix;edkEnd();
                    this->matrixSize = size;edkEnd();
                    return true;
                }
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
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyMatrices(matrix1,matrix2);edkEnd();
    }

    bool multiply(edk::vector::MatrixDynamic<typeTemplate>* matrix1,edk::vector::MatrixDynamic<typeTemplate>* matrix2){
        if(this->canMultiply(matrix1,matrix2)){
            typeTemplate destSum;edkEnd();
            typeTemplate destMultiply;edkEnd();
            if(this->matrixSize.width == matrix2->matrixSize.width && this->matrixSize.height == matrix1->matrixSize.height){
                //test if have the matrixDest
                if(!this->matrixDest){
                    //create the matrixDest
                    this->createMatrixDest();edkEnd();
                }
                if(this->matrixDest){
                    //copy the values
                    for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                        for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                            memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                            //multiply
                            for(edk::uint32 i=0u;i<matrix1->matrixSize.width;i++){
                                this->multiplyElement(&matrix1->matrix[y][i],&matrix2->matrix[i][x],&destMultiply);edkEnd();
                                this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                            }
                            //set the value
                            memcpy((void*)&this->matrixDest[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                        }
                    }
                    this->flipMatrix();edkEnd();
                }
            }
            else{
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32(matrix2->matrixSize.width,matrix1->matrixSize.height);edkEnd();

                typeTemplate** newMatrix = new typeTemplate*[size.height];edkEnd();
                if(newMatrix){
                    memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                    for(edk::uint32 y=0u;y<size.height;y++){
                        newMatrix[y] = new typeTemplate[size.width];edkEnd();
                        if(newMatrix[y]){
                            memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);edkEnd();
                            for(edk::uint32 x=0u;x<size.width;x++){
                                //clean the value
                                memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                                //multiply
                                for(edk::uint32 i=0u;i<matrix1->matrixSize.width;i++){
                                    this->multiplyElement(&matrix1->matrix[y][i],&matrix2->matrix[i][x],&destMultiply);edkEnd();
                                    this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                                }
                                //set the value
                                memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                            }
                        }
                        else{
                            for(edk::uint32 j=y+1u;y>0u;j--){
                                //delete the matrix
                                delete[] newMatrix[j];edkEnd();
                            }
                            delete[] newMatrix;edkEnd();
                            return false;
                        }
                    }
                    //in the end. delete the old matrix and copy the new matrix
                    this->deleteMatrix();edkEnd();
                    this->matrix = newMatrix;edkEnd();
                    this->matrixSize = size;edkEnd();
                    return true;
                }
            }
        }
        return false;
    }

    //print the matrix
    bool printMatrix(){
        if(this->matrix && this->matrixSize.width && this->matrixSize.height){
            printf("\nMatrix [%u] [%u]",this->matrixSize.width,this->matrixSize.height);edkEnd();
            for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                for(edk::uint32 x=0u;x<this->matrixSize.width;x++){
                    this->printElement(x,y,&this->matrix[y][x]);edkEnd();
                }
            }fflush(stdout);edkEnd();
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
                delete[] this->matrix[i];edkEnd();
            }
            delete[] this->matrix;edkEnd();

            this->deleteMatrixDest();edkEnd();
        }
        this->matrix=NULL;edkEnd();
        this->matrixSize=0u;edkEnd();
    }

    bool cloneFrom(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(matrix){
            if(matrix->matrixSize.width && matrix->matrixSize.height){
                if(this->matrixSize.width == matrix->width() && this->matrixSize.height == matrix->height()){
                    if(matrix){
                        //copy the values
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy(this->matrix[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);edkEnd();
                        }
                        return true;
                    }
                }
                else{
                    this->deleteMatrix();edkEnd();
                    if(this->createMatrix(matrix->matrixSize.width,matrix->matrixSize.height)){
                        //copy the values
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy(this->matrix[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);edkEnd();
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    //the operators are private because I can's fix it yet
private:
    edk::vector::MatrixDynamic<typeTemplate>* operator=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->cloneFrom(&matrix);edkEnd();
        matrix.cantDeleteVector();edkEnd();
        return this;edkEnd();
    }
    bool operator==(edk::vector::MatrixDynamic<typeTemplate> matrix){
        matrix.cantDeleteVector();edkEnd();
        return this->isEqual(&matrix);edkEnd();
    }
    bool operator!=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        matrix.cantDeleteVector();edkEnd();
        return !this->isEqual(&matrix);edkEnd();
    }
    edk::vector::MatrixDynamic<typeTemplate> operator+(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->add(&matrix);edkEnd();
        return matrix;edkEnd();
    }
    edk::vector::MatrixDynamic<typeTemplate> operator++(edk::int32 n){
        this->increment(n);edkEnd();
        return this;edkEnd();
    }
    edk::vector::MatrixDynamic<typeTemplate> operator++(){
        this->increment(1);edkEnd();
        return this;edkEnd();
    }
    void operator+=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->add(&matrix);edkEnd();
    }
    edk::vector::MatrixDynamic<typeTemplate> operator-(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->sub(&matrix);edkEnd();
        return matrix;edkEnd();
    }
    edk::vector::MatrixDynamic<typeTemplate> operator--(){
        this->decrement(1);edkEnd();
        return this;edkEnd();
    }
    edk::vector::MatrixDynamic<typeTemplate> operator--(edk::int32 n){
        this->decrement(n);edkEnd();
        return this;edkEnd();
    }
    void operator-=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->sub(&matrix);edkEnd();
    }
    edk::vector::MatrixDynamic<typeTemplate> operator*(edk::vector::MatrixDynamic<typeTemplate> matrix){
        edk::vector::MatrixDynamic<typeTemplate> ret;edkEnd();
        ret.multiply(this,&matrix);edkEnd();
        return ret;
    }
    edk::vector::MatrixDynamic<typeTemplate> operator*=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->multiplyThisWithMatrix(&matrix);edkEnd();
        return *this;edkEnd();
    }
protected:
    virtual void printElement(edk::uint32 /*x*/,edk::uint32 /*y*/,typeTemplate* /*value*/){
        //printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);edkEnd();
    }
    virtual void multiplyElement(typeTemplate* value1,typeTemplate* value2,typeTemplate* dest){
        *dest = (*value1)*(*value2);edkEnd();
    }
    virtual void sumElement(typeTemplate* value1,typeTemplate* value2,typeTemplate* dest){
        *dest = (*value1)+(*value2);edkEnd();
    }

private:
    typeTemplate** matrix;
    typeTemplate** matrixDest;
    //size of the vector
    edk::size2ui32 matrixSize;
    //test if can delete the vector
    bool canDeleteVector;
public:
    //cant
    void cantDeleteVector(){
        this->canDeleteVector=false;edkEnd();
    }
    //delete the array
    void deleteMatrixDest(){
        //test if is alloc
        if(this->matrixDest){
            //
            for(edk::uint32 i=0u;i<this->matrixSize.height;i++){
                delete[] this->matrixDest[i];edkEnd();
            }
            delete[] this->matrixDest;edkEnd();
        }
        this->matrixDest=NULL;edkEnd();
    }

    //create the matrix Dest
    bool createMatrixDest(){
        //first delete
        this->deleteMatrixDest();edkEnd();

        //Test the size
        if(this->matrixSize.width && this->matrixSize.height){
            this->matrixDest = new typeTemplate*[this->matrixSize.height];edkEnd();
            if(this->matrixDest){
                memset(this->matrixDest,0u,sizeof(typeTemplate)*this->matrixSize.height);edkEnd();
                for(edk::uint32 i=0u;i<matrixSize.height;i++){
                    this->matrixDest[i] = new typeTemplate[this->matrixSize.width];edkEnd();
                    if(this->matrixDest[i]){
                        memset(this->matrixDest[i],0u,sizeof(typeTemplate)*this->matrixSize.width);edkEnd();
                    }
                    else{
                        for(edk::uint32 j=i+1u;i>0u;j--){
                            //delete the matrix
                            delete[] this->matrixDest[j];edkEnd();
                        }
                        delete[] this->matrixDest;edkEnd();
                        return false;
                    }
                }
                return true;
            }
        }
        //else return false
        return false;
    }
    //flip matrices
    void flipMatrix(){
        typeTemplate** matrixTemp = this->matrix;edkEnd();
        this->matrix = this->matrixDest;edkEnd();
        this->matrixDest = matrixTemp;edkEnd();
    }
};
//Use a template to alloc whatever
template <class typeTemplate,edk::uint32 m,edk::uint32 n>
class Matrix : private edk::vector::MatrixDynamic<typeTemplate>{
public:
    inline Matrix(){
        this->canDeleteMatrix=true;edkEnd();
        edk::vector::MatrixDynamic<typeTemplate>::createMatrix(m,n);edkEnd();
        if(m==n){
            canMultiplyMatrix=true;edkEnd();
        }
        else{
            canMultiplyMatrix=false;edkEnd();
        }
    }
    inline ~Matrix(){
        if(this->canDeleteMatrix){
            edk::vector::MatrixDynamic<typeTemplate>::deleteMatrix();edkEnd();
        }
        else{
            this->canDeleteMatrix=true;edkEnd();
        }
    }

    //SETTERS
    inline bool set(edk::vec2ui32 position,typeTemplate obj){
        return edk::vector::MatrixDynamic<typeTemplate>::set(position,obj);edkEnd();
    }
    inline bool set(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        return edk::vector::MatrixDynamic<typeTemplate>::set(x,y,obj);edkEnd();
    }
    //set the matrix as identity
    inline bool setIdentity(typeTemplate valueOne,typeTemplate valueZero){
        return edk::vector::MatrixDynamic<typeTemplate>::setIdentity(valueOne,valueZero);edkEnd();
    }

    //GETTERS
    //returrn the matrix size
    inline edk::size2ui32 size(){
        return edk::vector::MatrixDynamic<typeTemplate>::size();edkEnd();
    }
    inline edk::uint32 width(){
        return edk::vector::MatrixDynamic<typeTemplate>::width();edkEnd();
    }
    inline edk::uint32 height(){
        return edk::vector::MatrixDynamic<typeTemplate>::height();edkEnd();
    }
    inline edk::size2ui32  getSize(){
        return edk::vector::MatrixDynamic<typeTemplate>::getSize();edkEnd();
    }
    inline edk::uint32 getWidth(){
        return edk::vector::MatrixDynamic<typeTemplate>::getWidth();edkEnd();
    }
    inline edk::uint32 getHeight(){
        return edk::vector::MatrixDynamic<typeTemplate>::getHeight();edkEnd();
    }
    //test if have the object in the position
    inline bool have(edk::vec2ui32 position){
        return edk::vector::MatrixDynamic<typeTemplate>::have(position);edkEnd();
    }
    inline bool have(edk::uint32 x,edk::uint32 y){
        return edk::vector::MatrixDynamic<typeTemplate>::have(x,y);edkEnd();
    }
    inline bool haveMatrix(){
        return edk::vector::MatrixDynamic<typeTemplate>::haveMatrix();edkEnd();
    }
    //return the value in a position
    inline typeTemplate get(edk::vec2ui32 position){
        return edk::vector::MatrixDynamic<typeTemplate>::get(position);edkEnd();
    }
    //return the value in a position
    inline typeTemplate get(edk::uint32 x,edk::uint32 y){
        return edk::vector::MatrixDynamic<typeTemplate>::get(x,y);edkEnd();
    }

    //test if a matrix is equal then other
    inline bool isEqual(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::isEqual(matrix);edkEnd();
    }
    //add the matrix with another
    inline bool add(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::add(matrix);edkEnd();
    }
    //add the matrix with another
    inline bool increment(edk::int32 value){
        return edk::vector::MatrixDynamic<typeTemplate>::increment(value);edkEnd();
    }
    //sub the matrix with another
    inline bool sub(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::sub(matrix);edkEnd();
    }
    //add the matrix with another
    inline bool decrement(edk::int32 value){
        return edk::vector::MatrixDynamic<typeTemplate>::decrement(value);edkEnd();
    }

    //return true if can multiply
    inline bool canMultiplyThis(){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline bool canMultiplyThisWithMatrix(edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline bool canMultiplyThisWithMatrix(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyThisWithMatrix(matrix);edkEnd();
    }
    inline bool canMultiplyMatrixWithThis(edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline bool canMultiplyMatrixWithThis(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyMatrixWithThis(matrix);edkEnd();
    }
    inline bool multiplyThisWithMatrix(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiplyThisWithMatrix(matrix);edkEnd();
        }
        return false;
    }
    inline bool multiplyMatrixWithThis(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiplyMatrixWithThis(matrix);edkEnd();
        }
        return false;
    }
    //return true if can multiply
    inline bool canMultiply(edk::vector::MatrixDynamic<typeTemplate>* matrix1,edk::vector::MatrixDynamic<typeTemplate>* matrix2){
        return edk::vector::MatrixDynamic<typeTemplate>::multiply(matrix1,matrix2);edkEnd();
    }
    inline bool canMultiply(edk::vector::Matrix<typeTemplate,m,n>*,edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline bool multiply(edk::vector::Matrix<typeTemplate,m,n>* matrix1,edk::vector::Matrix<typeTemplate,m,n>* matrix2){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiply(matrix1,matrix2);edkEnd();
        }
        return false;
    }

    //print the matrix
    inline bool printMatrix(){
        return edk::vector::MatrixDynamic<typeTemplate>::printMatrix();edkEnd();
    }

    inline bool cloneFrom(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::cloneFrom(matrix);edkEnd();
    }

    //the operators are private because I can's fix it yet
private:
    inline edk::vector::Matrix<typeTemplate,m,n>* operator=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->cloneFrom(&matrix);edkEnd();
        return &matrix;edkEnd();
    }
    inline bool operator==(edk::vector::Matrix<typeTemplate,m,n> matrix){
        matrix.cantDeleteVector();edkEnd();
        return this->isEqual(&matrix);edkEnd();
    }
    inline bool operator!=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        matrix.cantDeleteVector();edkEnd();
        return !this->isEqual(&matrix);edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator+(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->add(&matrix);edkEnd();
        matrix.cantDeleteMatrix();edkEnd();
        return matrix;edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator++(edk::int32 value){
        this->increment(value);edkEnd();
        return this;edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator++(){
        this->increment(1);edkEnd();
        return this;edkEnd();
    }
    inline void operator+=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->add(&matrix);edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator-(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->sub(&matrix);edkEnd();
        matrix.cantDeleteMatrix();edkEnd();
        return matrix;edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator--(){
        this->decrement(1);edkEnd();
        return this;edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator--(edk::int32 value){
        this->decrement(value);edkEnd();
        return this;edkEnd();
    }
    inline void operator-=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->sub(&matrix);edkEnd();
        matrix.cantDeleteMatrix();edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator*(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->multiplyThisWithMatrix(&matrix);edkEnd();
        matrix.cantDeleteMatrix();edkEnd();
        this->cantDeleteMatrix();edkEnd();
        return *this;edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator*=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->multiplyThisWithMatrix(&matrix);edkEnd();
        matrix.cantDeleteMatrix();edkEnd();
        this->cantDeleteMatrix();edkEnd();
        return *this;edkEnd();
    }
protected:
    inline void printElement(edk::uint32 /*x*/,edk::uint32 /*y*/,typeTemplate* /*value*/){
        //printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);edkEnd();
    }
private:
    //test if can delete the vector
    bool canDeleteMatrix;
    //save if can multiply the matrix
    bool canMultiplyMatrix;
public:
    //cant
    void cantDeleteMatrix(){
        this->canDeleteMatrix=false;edkEnd();
        edk::vector::MatrixDynamic<typeTemplate>::cantDeleteVector();edkEnd();
    }
};
}//end namespace vector
}//end namespace edk

#endif // MATRIX_H
