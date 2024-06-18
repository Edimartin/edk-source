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
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    MatrixDynamic(edk::size2f32 size){
        this->classThis=NULL;edkEnd();
        this->Constructor(size,false);edkEnd();
    }
    MatrixDynamic(edk::uint32 width,edk::uint32 height){
        this->classThis=NULL;edkEnd();
        this->Constructor(width,height,false);edkEnd();
    }
    ~MatrixDynamic(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            this->deleteMatrix();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->isClass = edk::ID<typeTemplate>::isClass();edkEnd();
            this->matrixSize = 0u;edkEnd();
            //set the matrix to NULL
            this->matrix=NULL;edkEnd();
            this->matrixDest=NULL;edkEnd();

            this->matrixPointer = &this->matrix;
            this->matrixDestPointer = &this->matrixDest;
            this->matrixSizePointer = &this->matrixSize;
        }
    }
    void Constructor(edk::size2f32 size,bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->isClass = edk::ID<typeTemplate>::isClass();edkEnd();
            //set the matrix to NULL
            this->matrix=NULL;edkEnd();
            this->matrixDest=NULL;edkEnd();

            this->matrixPointer = &this->matrix;
            this->matrixDestPointer = &this->matrixDest;
            this->matrixSizePointer = &this->matrixSize;

            //create a new matrix
            this->createMatrix(size);edkEnd();
        }
    }
    void Constructor(edk::uint32 width,edk::uint32 height,bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->isClass = edk::ID<typeTemplate>::isClass();edkEnd();
            //set the matrix to NULL
            this->matrix=NULL;edkEnd();
            this->matrixDest=NULL;edkEnd();

            this->matrixPointer = &this->matrix;
            this->matrixDestPointer = &this->matrixDest;
            this->matrixSizePointer = &this->matrixSize;

            //create a new matrix
            this->createMatrix(width,height);edkEnd();
        }
    }


    //create the matrix
    bool createMatrix(edk::size2ui32 size){
        //first delete
        this->deleteMatrix();edkEnd();

        //Test the size
        if(size.width && size.height){
            if(this->isClass){
                (*this->matrixPointer) = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);edkEnd();
                if((*this->matrixPointer)){
                    memset((*this->matrixPointer),0u,sizeof(typeTemplate)*size.height);edkEnd();
                    for(edk::uint32 i=0u;i<size.height;i++){
                        (*this->matrixPointer)[i] = new typeTemplate[size.width];edkEnd();
                        if((*this->matrixPointer)[i]){
                            //don't clean a class
                            //memset((*this->matrixPointer)[i],0u,sizeof(typeTemplate)*size.width);edkEnd();
                        }
                        else{
                            for(edk::uint32 j=i+1u;i>0u;j--){
                                //delete the matrix
                                delete[] (*this->matrixPointer)[j];edkEnd();
                            }
                            free((*this->matrixPointer));edkEnd();
                            return false;
                        }
                    }
                    (*this->matrixSizePointer) = size;edkEnd();
                    return true;
                }
            }
            else{
                (*this->matrixPointer) = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);edkEnd();
                if((*this->matrixPointer)){
                    memset((*this->matrixPointer),0u,sizeof(typeTemplate)*size.height);edkEnd();
                    for(edk::uint32 i=0u;i<size.height;i++){
                        (*this->matrixPointer)[i] = (typeTemplate*)malloc(sizeof(typeTemplate)*size.width);edkEnd();
                        if((*this->matrixPointer)[i]){
                            memset((*this->matrixPointer)[i],0u,sizeof(typeTemplate)*size.width);edkEnd();
                        }
                        else{
                            for(edk::uint32 j=i+1u;i>0u;j--){
                                //delete the matrix
                                free((*this->matrixPointer)[j]);edkEnd();
                            }
                            free((*this->matrixPointer));edkEnd();
                            return false;
                        }
                    }
                    (*this->matrixSizePointer) = size;edkEnd();
                    return true;
                }
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
            memcpy(&(*this->matrixPointer)[position.y][position.x],&obj,sizeof(typeTemplate));edkEnd();
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
        memcpy(&(*this->matrixPointer)[position.y][position.x],&obj,sizeof(typeTemplate));edkEnd();
    }
    inline void setNoIF(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        memcpy(&(*this->matrixPointer)[y][x],&obj,sizeof(typeTemplate));edkEnd();
    }
    //set the matrix as identity
    virtual bool setIdentity(typeTemplate valueOne,typeTemplate valueZero){
        if((*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    if(x==y){
                        memcpy(&(*this->matrixPointer)[y][x],&valueOne,sizeof(typeTemplate));edkEnd();
                    }
                    else{
                        memcpy(&(*this->matrixPointer)[y][x],&valueZero,sizeof(typeTemplate));edkEnd();
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
        return (*this->matrixSizePointer);edkEnd();
    }
    inline edk::uint32 width(){
        return (*this->matrixSizePointer).width;edkEnd();
    }
    inline edk::uint32 height(){
        return (*this->matrixSizePointer).height;edkEnd();
    }
    inline edk::size2ui32  getSize(){
        return (*this->matrixSizePointer);edkEnd();
    }
    inline edk::uint32 getWidth(){
        return (*this->matrixSizePointer).width;edkEnd();
    }
    inline edk::uint32 getHeight(){
        return (*this->matrixSizePointer).height;edkEnd();
    }
    //test if have the object in the position
    bool have(edk::vec2ui32 position){
        if((*this->matrixPointer) && position.x<(*this->matrixSizePointer).width && position.y<(*this->matrixSizePointer).height){
            //return true
            return true;
        }
        return false;
    }
    bool have(edk::uint32 x,edk::uint32 y){
        return this->have(edk::vec2f32(x,y));edkEnd();
    }
    bool haveMatrix(){
        if((*this->matrixPointer) && (*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            return true;
        }
        return false;
    }
    //return the value in a position
    inline typeTemplate get(edk::vec2ui32 position){
        //
        if(this->have(position)){
            //return the variable
            return (*this->matrixPointer)[position.y][position.x];edkEnd();
        }
        typeTemplate ret;edkEnd(); memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
        return ret;
    }
    //return the value in a position
    inline typeTemplate get(edk::uint32 x,edk::uint32 y){
        return this->get(edk::vec2ui32(x,y));edkEnd();
    }
    //GETTERS WITHOUT IF
    inline typeTemplate getNoIF(edk::vec2ui32 position){
        //return the variable
        return (*this->matrixPointer)[position.y][position.x];
    }
    //return the value in a position
    inline typeTemplate getNoIF(edk::uint32 x,edk::uint32 y){
        return (*this->matrixPointer)[y][x];
    }

    //test if a matrix is equal then other
    bool isEqual(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(matrix){
            if((*this->matrixPointer)
                    && matrix->matrix
                    && (*this->matrixSizePointer).width==matrix->matrixSize.width
                    && (*this->matrixSizePointer).height==matrix->matrixSize.height
                    ){
                for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                    for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                        if(edkMemCmp((edk::classID)&(*this->matrixPointer)[y][x],(edk::classID)&matrix->matrix[y][x],sizeof(typeTemplate))){
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
            if((*this->matrixPointer)
                    && matrix->matrix
                    && (*this->matrixSizePointer).width==matrix->matrixSize.width
                    && (*this->matrixSizePointer).height==matrix->matrixSize.height
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
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    (*this->matrixPointer)[y][x]=(*this->matrixPointer)[y][x]+matrix->matrix[y][x];edkEnd();
                }
            }
            return true;
        }
        return false;
    }
    //add the matrix with another
    bool increment(edk::int32 n){
        //test if the matrix is equal in size
        if((*this->matrixPointer) && (*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    (*this->matrixPointer)[y][x]=(*this->matrixPointer)[y][x]+n;edkEnd();
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
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    (*this->matrixPointer)[y][x]=(*this->matrixPointer)[y][x]-matrix->matrix[y][x];edkEnd();
                }
            }
            return true;
        }
        return false;
    }
    //add the matrix with another
    bool decrement(edk::int32 n){
        //test if the matrix is equal in size
        if((*this->matrixPointer) && (*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    (*this->matrixPointer)[y][x]=(*this->matrixPointer)[y][x]-n;edkEnd();
                }
            }
            return true;
        }
        return false;
    }
    //return true if can multiply
    inline bool canMultiplyThisWithMatrix(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if((*this->matrixPointer) && (*this->matrixSizePointer).width && (*this->matrixSizePointer).height
                &&
                matrix->matrix && matrix->matrixSize.width && matrix->matrixSize.height
                ){
            //first compare if can have the product of the matrix
            if((*this->matrixSizePointer).width == matrix->matrixSize.height){
                return true;
            }
        }
        return false;
    }
    inline bool canMultiplyMatrixWithThis(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if((*this->matrixPointer) && (*this->matrixSizePointer).width && (*this->matrixSizePointer).height
                &&
                matrix->matrix && matrix->matrixSize.width && matrix->matrixSize.height
                ){
            //first compare if can have the product of the matrix
            if(matrix->matrixSize.width == (*this->matrixSizePointer).height){
                return true;
            }
        }
        return false;
    }
    bool multiplyThisWithMatrix(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(this->canMultiplyThisWithMatrix(matrix)){
            typeTemplate destSum;edkEnd();
            typeTemplate destMultiply;edkEnd();
            if((*this->matrixSizePointer).width==matrix->matrixSize.width){
                //test if have the matrixDest
                if(!(*this->matrixDestPointer)){
                    //create the matrixDest
                    this->createMatrixDest();edkEnd();
                }
                if((*this->matrixDestPointer)){
                    //copy the values
                    for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                        for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                            //clean the value
                            memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                            //multiply
                            for(edk::uint32 i=0u;i<(*this->matrixSizePointer).width;i++){
                                this->multiplyElement(&(*this->matrixPointer)[y][i],&matrix->matrix[i][x],&destMultiply);edkEnd();
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
                edk::size2ui32 size = edk::size2ui32(matrix->matrixSize.width,(*this->matrixSizePointer).height);edkEnd();

                if(this->isClass){
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);edkEnd();
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = new typeTemplate[size.width];edkEnd();
                            if(newMatrix[y]){
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //multiply
                                    for(edk::uint32 i=0u;i<(*this->matrixSizePointer).width;i++){
                                        this->multiplyElement(&(*this->matrixPointer)[y][i],&matrix->matrix[i][x],&destMultiply);edkEnd();
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
                                free(newMatrix);edkEnd();
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();edkEnd();
                        (*this->matrixPointer) = newMatrix;edkEnd();
                        (*this->matrixSizePointer) = size;edkEnd();
                        return true;
                    }
                }
                else{
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);edkEnd();
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = (typeTemplate*)malloc(sizeof(typeTemplate)*size.width);edkEnd();
                            if(newMatrix[y]){
                                memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);edkEnd();
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //clean the value
                                    memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                                    //multiply
                                    for(edk::uint32 i=0u;i<(*this->matrixSizePointer).width;i++){
                                        this->multiplyElement(&(*this->matrixPointer)[y][i],&matrix->matrix[i][x],&destMultiply);edkEnd();
                                        this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                                    }
                                    //set the value
                                    memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                                }
                            }
                            else{
                                for(edk::uint32 j=y+1u;y>0u;j--){
                                    //delete the matrix
                                    free(newMatrix[j]);edkEnd();
                                }
                                free(newMatrix);edkEnd();
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();edkEnd();
                        (*this->matrixPointer) = newMatrix;edkEnd();
                        (*this->matrixSizePointer) = size;edkEnd();
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool multiplyMatrixWithThis(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(this->canMultiplyMatrixWithThis(matrix)){
            typeTemplate destSum;edkEnd();
            typeTemplate destMultiply;edkEnd();
            if((*this->matrixSizePointer).height==matrix->matrixSize.height){
                //test if have the matrixDest
                if(!(*this->matrixDestPointer)){
                    //create the matrixDest
                    this->createMatrixDest();edkEnd();
                }
                if((*this->matrixDestPointer)){
                    //copy the values
                    for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                        for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                            //clean the value
                            memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                            //multiply
                            for(edk::uint32 i=0u;i<matrix->matrixSize.width;i++){
                                this->multiplyElement(&matrix->matrix[y][i],&(*this->matrixPointer)[i][x],&destMultiply);edkEnd();
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
                edk::size2ui32 size = edk::size2ui32((*this->matrixSizePointer).width,matrix->matrixSize.height);edkEnd();

                if(this->isClass){
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);edkEnd();
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = new typeTemplate[size.width];edkEnd();
                            if(newMatrix[y]){
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //multiply
                                    for(edk::uint32 i=0u;i<matrix->matrixSize.width;i++){
                                        this->multiplyElement(&matrix->matrix[y][i],&(*this->matrixPointer)[i][x],&destMultiply);edkEnd();
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
                                free(newMatrix);edkEnd();
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();edkEnd();
                        (*this->matrixPointer) = newMatrix;edkEnd();
                        (*this->matrixSizePointer) = size;edkEnd();
                        return true;
                    }
                }
                else{
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);edkEnd();
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = (typeTemplate*)malloc(sizeof(typeTemplate)*size.width);edkEnd();
                            if(newMatrix[y]){
                                memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);edkEnd();
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //clean the value
                                    memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                                    //multiply
                                    for(edk::uint32 i=0u;i<matrix->matrixSize.width;i++){
                                        this->multiplyElement(&matrix->matrix[y][i],&(*this->matrixPointer)[i][x],&destMultiply);edkEnd();
                                        this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                                    }
                                    //set the value
                                    memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                                }
                            }
                            else{
                                for(edk::uint32 j=y+1u;y>0u;j--){
                                    //delete the matrix
                                    free(newMatrix[j]);edkEnd();
                                }
                                free(newMatrix);edkEnd();
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();edkEnd();
                        (*this->matrixPointer) = newMatrix;edkEnd();
                        (*this->matrixSizePointer) = size;edkEnd();
                        return true;
                    }
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
            if((*this->matrixSizePointer).width == matrix2->matrixSize.width && (*this->matrixSizePointer).height == matrix1->matrixSize.height){
                //test if have the matrixDest
                if(!(*this->matrixDestPointer)){
                    //create the matrixDest
                    this->createMatrixDest();edkEnd();
                }
                if((*this->matrixDestPointer)){
                    //copy the values
                    for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                        for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                            memset((void*)&destSum,0u,sizeof(typeTemplate));edkEnd();
                            //multiply
                            for(edk::uint32 i=0u;i<matrix1->matrixSize.width;i++){
                                this->multiplyElement(&matrix1->matrix[y][i],&matrix2->matrix[i][x],&destMultiply);edkEnd();
                                this->sumElement(&destMultiply,&destSum,&destSum);edkEnd();
                            }
                            //set the value
                            memcpy((void*)&(*this->matrixDestPointer)[y][x],&destSum,sizeof(typeTemplate));edkEnd();
                        }
                    }
                    this->flipMatrix();edkEnd();
                }
            }
            else{
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32(matrix2->matrixSize.width,matrix1->matrixSize.height);edkEnd();

                if(this->isClass){
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);edkEnd();
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = new typeTemplate[size.width];edkEnd();
                            if(newMatrix[y]){
                                for(edk::uint32 x=0u;x<size.width;x++){
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
                                free(newMatrix);edkEnd();
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();edkEnd();
                        (*this->matrixPointer) = newMatrix;edkEnd();
                        (*this->matrixSizePointer) = size;edkEnd();
                        return true;
                    }
                }
                else{
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);edkEnd();
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);edkEnd();
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = (typeTemplate*)malloc(sizeof(typeTemplate)*size.width);edkEnd();
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
                                    free(newMatrix[j]);edkEnd();
                                }
                                free(newMatrix);edkEnd();
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();edkEnd();
                        (*this->matrixPointer) = newMatrix;edkEnd();
                        (*this->matrixSizePointer) = size;edkEnd();
                        return true;
                    }
                }
            }
        }
        return false;
    }

    //print the matrix
    virtual bool printMatrix(){
        if((*this->matrixPointer) && (*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            printf("\nMatrix [%u] [%u]",(*this->matrixSizePointer).width,(*this->matrixSizePointer).height);edkEnd();
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    this->printElement(x,y,&(*this->matrixPointer)[y][x]);edkEnd();
                }
            }fflush(stdout);edkEnd();
            return true;
        }
        return false;
    }

    //delete the array
    void deleteMatrix(){
        //test if is alloc
        if((*this->matrixPointer)){
            //
            if(this->isClass){
                for(edk::uint32 i=0u;i<(*this->matrixSizePointer).height;i++){
                    delete[] (*this->matrixPointer)[i];edkEnd();
                }
                free((*this->matrixPointer));edkEnd();
            }
            else{
                for(edk::uint32 i=0u;i<(*this->matrixSizePointer).height;i++){
                    free((*this->matrixPointer)[i]);edkEnd();
                }
                free((*this->matrixPointer));edkEnd();
            }

            this->deleteMatrixDest();edkEnd();
        }
        (*this->matrixPointer)=NULL;edkEnd();
        (*this->matrixSizePointer)=0u;edkEnd();
    }

    bool cloneFrom(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(matrix){
            if(matrix->matrixSize.width && matrix->matrixSize.height){
                if((*this->matrixSizePointer).width == matrix->width() && (*this->matrixSizePointer).height == matrix->height()){
                    if(matrix){
                        //copy the values
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy((*this->matrixPointer)[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);edkEnd();
                        }
                        return true;
                    }
                }
                else{
                    this->deleteMatrix();edkEnd();
                    if(this->createMatrix(matrix->matrixSize.width,matrix->matrixSize.height)){
                        //copy the values
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy((*this->matrixPointer)[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);edkEnd();
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
    inline bool operator==(edk::vector::MatrixDynamic<typeTemplate> matrix){
        matrix.cantDeleteVector();edkEnd();
        return this->isEqual(&matrix);edkEnd();
    }
    inline bool operator!=(edk::vector::MatrixDynamic<typeTemplate> matrix){
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
    inline void operator+=(edk::vector::MatrixDynamic<typeTemplate> matrix){
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
    inline void operator-=(edk::vector::MatrixDynamic<typeTemplate> matrix){
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
    typeTemplate*** matrixPointer;
    typeTemplate** matrixDest;
    typeTemplate*** matrixDestPointer;
    //size of the vector
    edk::size2ui32 matrixSize;
    edk::size2ui32* matrixSizePointer;

    //test if the typeTemplete is a class
    bool isClass;
public:
    //delete the array
    void deleteMatrixDest(){
        //test if is alloc
        if((*this->matrixDestPointer)){
            //
            for(edk::uint32 i=0u;i<(*this->matrixSizePointer).height;i++){
                if(this->isClass){
                    delete[] (*this->matrixDestPointer)[i];edkEnd();
                }
                else{
                    free((*this->matrixDestPointer)[i]);edkEnd();
                }
            }
            free((*this->matrixDestPointer));edkEnd();
        }
        (*this->matrixDestPointer)=NULL;edkEnd();
    }

    //create the matrix Dest
    bool createMatrixDest(){
        //first delete
        this->deleteMatrixDest();edkEnd();

        //Test the size
        if((*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            if(this->isClass){
                (*this->matrixDestPointer) = (typeTemplate**)malloc(sizeof(typeTemplate*)*(*this->matrixSizePointer).height);edkEnd();
                if((*this->matrixDestPointer)){
                    memset((*this->matrixDestPointer),0u,sizeof(typeTemplate)*(*this->matrixSizePointer).height);edkEnd();
                    for(edk::uint32 i=0u;i<matrixSize.height;i++){
                        (*this->matrixDestPointer)[i] = new typeTemplate[(*this->matrixSizePointer).width];edkEnd();
                        if((*this->matrixDestPointer)[i]){
                            //don't set the matrix woth classes
                            //memset((*this->matrixDestPointer)[i],0u,sizeof(typeTemplate)*(*this->matrixSizePointer).width);edkEnd();
                        }
                        else{
                            for(edk::uint32 j=i+1u;i>0u;j--){
                                //delete the matrix
                                delete[] (*this->matrixDestPointer)[j];edkEnd();
                            }
                            free((*this->matrixDestPointer));edkEnd();
                            return false;
                        }
                    }
                    return true;
                }
            }
            else{
                (*this->matrixDestPointer) = (typeTemplate**)malloc(sizeof(typeTemplate*)*(*this->matrixSizePointer).height);edkEnd();
                if((*this->matrixDestPointer)){
                    memset((*this->matrixDestPointer),0u,sizeof(typeTemplate)*(*this->matrixSizePointer).height);edkEnd();
                    for(edk::uint32 i=0u;i<matrixSize.height;i++){
                        (*this->matrixDestPointer)[i] = (typeTemplate*)malloc(sizeof(typeTemplate)*(*this->matrixSizePointer).width);edkEnd();
                        if((*this->matrixDestPointer)[i]){
                            memset((*this->matrixDestPointer)[i],0u,sizeof(typeTemplate)*(*this->matrixSizePointer).width);edkEnd();
                        }
                        else{
                            for(edk::uint32 j=i+1u;i>0u;j--){
                                //delete the matrix
                                free((*this->matrixDestPointer)[j]);edkEnd();
                            }
                            free((*this->matrixDestPointer));edkEnd();
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
        //else return false
        return false;
    }
    //flip matrices
    void flipMatrix(){
        typeTemplate** matrixTemp = (*this->matrixPointer);edkEnd();
        (*this->matrixPointer) = (*this->matrixDestPointer);edkEnd();
        (*this->matrixDestPointer) = matrixTemp;edkEnd();
    }
private:
    edk::classID classThis;
};
//Use a template to alloc whatever
template <class typeTemplate,edk::uint32 m,edk::uint32 n>
class Matrix : private edk::vector::MatrixDynamic<typeTemplate>{
public:
    inline Matrix(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    inline ~Matrix(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            edk::vector::MatrixDynamic<typeTemplate>::deleteMatrix();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::vector::MatrixDynamic<typeTemplate>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            edk::vector::MatrixDynamic<typeTemplate>::createMatrix(m,n);edkEnd();
            if(m==n){
                canMultiplyMatrix=true;edkEnd();
            }
            else{
                canMultiplyMatrix=false;edkEnd();
            }
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
    inline virtual bool setIdentity(typeTemplate valueOne,typeTemplate valueZero){
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

    //GETTERS WITHOUT IF
    inline typeTemplate getNoIF(edk::vec2ui32 position){
        //return the variable
        return edk::vector::MatrixDynamic<typeTemplate>::getNoIF(position);
    }
    //return the value in a position
    inline typeTemplate getNoIF(edk::uint32 x,edk::uint32 y){
        return edk::vector::MatrixDynamic<typeTemplate>::getNoIF(x,y);
    }

    //test if a matrix is equal then other
    inline virtual bool isEqual(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::isEqual(matrix);edkEnd();
    }
    //add the matrix with another
    inline virtual bool add(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::add(matrix);edkEnd();
    }
    //add the matrix with another
    inline bool increment(edk::int32 value){
        return edk::vector::MatrixDynamic<typeTemplate>::increment(value);edkEnd();
    }
    //sub the matrix with another
    inline virtual bool sub(edk::vector::Matrix<typeTemplate,m,n>* matrix){
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
    inline virtual bool canMultiplyThisWithMatrix(edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline bool canMultiplyThisWithMatrix(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyThisWithMatrix(matrix);edkEnd();
    }
    inline virtual bool canMultiplyMatrixWithThis(edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline bool canMultiplyMatrixWithThis(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyMatrixWithThis(matrix);edkEnd();
    }
    inline virtual bool multiplyThisWithMatrix(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiplyThisWithMatrix(matrix);edkEnd();
        }
        return false;
    }
    inline virtual bool multiplyMatrixWithThis(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiplyMatrixWithThis(matrix);edkEnd();
        }
        return false;
    }
    //return true if can multiply
    inline bool canMultiply(edk::vector::MatrixDynamic<typeTemplate>* matrix1,edk::vector::MatrixDynamic<typeTemplate>* matrix2){
        return edk::vector::MatrixDynamic<typeTemplate>::multiply(matrix1,matrix2);edkEnd();
    }
    inline virtual bool canMultiply(edk::vector::Matrix<typeTemplate,m,n>*,edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline virtual bool multiply(edk::vector::Matrix<typeTemplate,m,n>* matrix1,edk::vector::Matrix<typeTemplate,m,n>* matrix2){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiply(matrix1,matrix2);edkEnd();
        }
        return false;
    }

    //print the matrix
    inline virtual bool printMatrix(){
        return edk::vector::MatrixDynamic<typeTemplate>::printMatrix();edkEnd();
    }

    inline virtual bool cloneFrom(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::cloneFrom(matrix);edkEnd();
    }

    //the operators are private because I can's fix it yet
private:
    inline edk::vector::Matrix<typeTemplate,m,n>* operator=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->cloneFrom(&matrix);edkEnd();
        return &matrix;edkEnd();
    }
    inline bool operator==(edk::vector::Matrix<typeTemplate,m,n> matrix){
        return this->isEqual(&matrix);edkEnd();
    }
    inline bool operator!=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        return !this->isEqual(&matrix);edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator+(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->add(&matrix);edkEnd();
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
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator*(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->multiplyThisWithMatrix(&matrix);edkEnd();
        return *this;edkEnd();
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator*=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->multiplyThisWithMatrix(&matrix);edkEnd();
        return *this;edkEnd();
    }
protected:
    inline void printElement(edk::uint32 /*x*/,edk::uint32 /*y*/,typeTemplate* /*value*/){
        //printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);edkEnd();
    }
    //save if can multiply the matrix
    bool canMultiplyMatrix;
private:
    edk::classID classThis;
};
template <edk::uint32 m,edk::uint32 n>
class Matrixf32: public edk::vector::Matrix<edk::float32,m,n>{
public:
    Matrixf32(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    ~Matrixf32(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::vector::Matrix<edk::float32,m,n>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
        }
    }

    //set the matrix as identity
    inline virtual bool setIdentity(edk::float32 valueOne,edk::float32 valueZero){
        return edk::vector::Matrix<edk::float32,m,n>::setIdentity(valueOne,valueZero);edkEnd();
    }
    inline virtual bool setIdentity(){
        return edk::vector::Matrix<edk::float32,m,n>::setIdentity(1.f,0.f);edkEnd();
    }

    //test if a matrix is equal then other
    inline virtual bool isEqual(edk::vector::Matrixf32<m,n>* matrix){
        return  edk::vector::Matrix<edk::float32,m,n>::isEqual(matrix);edkEnd();
    }
    //add the matrix with another
    inline virtual bool add(edk::vector::Matrixf32<m,n>* matrix){
        return  edk::vector::Matrix<edk::float32,m,n>::add(matrix);edkEnd();
    }
    //sub the matrix with another
    inline virtual bool sub(edk::vector::Matrixf32<m,n>* matrix){
        return  edk::vector::Matrix<edk::float32,m,n>::sub(matrix);edkEnd();
    }

    //return true if can multiply
    inline virtual bool canMultiplyThisWithMatrix(edk::vector::Matrixf32<m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline virtual bool canMultiplyMatrixWithThis(edk::vector::Matrixf32<m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline virtual bool multiplyThisWithMatrix(edk::vector::Matrixf32<m,n>* matrix){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float32,m,n>::multiplyThisWithMatrix(matrix);edkEnd();
        }
        return false;
    }
    inline virtual bool multiplyMatrixWithThis(edk::vector::Matrixf32<m,n>* matrix){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float32,m,n>::multiplyMatrixWithThis(matrix);edkEnd();
        }
        return false;
    }
    //return true if can multiply
    inline virtual bool canMultiply(edk::vector::Matrixf32<m,n>*,edk::vector::Matrixf32<m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline virtual bool multiply(edk::vector::Matrixf32<m,n>* matrix1,edk::vector::Matrixf32<m,n>* matrix2){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float32,m,n>::multiply(matrix1,matrix2);edkEnd();
        }
        return false;
    }

    //print the matrix
    inline virtual bool cloneFrom(edk::vector::Matrixf32<m,n>* matrix){
        return  edk::vector::Matrix<edk::float32,m,n>::cloneFrom(matrix);edkEnd();
    }

protected:
    inline void printElement(edk::uint32 x,edk::uint32 y,edk::float32* value){
        printf("\n[%u][%u] == [%.2f]",x,y,(edk::float32)(*value));edkEnd();
    }
private:
    edk::classID classThis;
};
template <edk::uint64 m,edk::uint64 n>
class Matrixf64: public edk::vector::Matrix<edk::float64,m,n>{
public:
    Matrixf64(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    ~Matrixf64(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::vector::Matrix<edk::float64,m,n>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
        }
    }

    //set the matrix as identity
    inline virtual bool setIdentity(edk::float64 valueOne,edk::float64 valueZero){
        return edk::vector::Matrix<edk::float64,m,n>::setIdentity(valueOne,valueZero);edkEnd();
    }
    inline virtual bool setIdentity(){
        return edk::vector::Matrix<edk::float64,m,n>::setIdentity(1.f,0.f);edkEnd();
    }

    //test if a matrix is equal then other
    inline virtual bool isEqual(edk::vector::Matrixf64<m,n>* matrix){
        return  edk::vector::Matrix<edk::float64,m,n>::isEqual(matrix);edkEnd();
    }
    //add the matrix with another
    inline virtual bool add(edk::vector::Matrixf64<m,n>* matrix){
        return  edk::vector::Matrix<edk::float64,m,n>::add(matrix);edkEnd();
    }
    //sub the matrix with another
    inline virtual bool sub(edk::vector::Matrixf64<m,n>* matrix){
        return  edk::vector::Matrix<edk::float64,m,n>::sub(matrix);edkEnd();
    }

    //return true if can multiply
    inline virtual bool canMultiplyThisWithMatrix(edk::vector::Matrixf64<m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline virtual bool canMultiplyMatrixWithThis(edk::vector::Matrixf64<m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline virtual bool multiplyThisWithMatrix(edk::vector::Matrixf64<m,n>* matrix){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float64,m,n>::multiplyThisWithMatrix(matrix);edkEnd();
        }
        return false;
    }
    inline virtual bool multiplyMatrixWithThis(edk::vector::Matrixf64<m,n>* matrix){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float64,m,n>::multiplyMatrixWithThis(matrix);edkEnd();
        }
        return false;
    }
    //return true if can multiply
    inline virtual bool canMultiply(edk::vector::Matrixf64<m,n>*,edk::vector::Matrixf64<m,n>*){
        return this->canMultiplyMatrix;edkEnd();
    }
    inline virtual bool multiply(edk::vector::Matrixf64<m,n>* matrix1,edk::vector::Matrixf64<m,n>* matrix2){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float64,m,n>::multiply(matrix1,matrix2);edkEnd();
        }
        return false;
    }

    //print the matrix
    inline virtual bool cloneFrom(edk::vector::Matrixf64<m,n>* matrix){
        return  edk::vector::Matrix<edk::float64,m,n>::cloneFrom(matrix);edkEnd();
    }

protected:
    inline void printElement(edk::uint64 x,edk::uint64 y,edk::float64* value){
        printf("\n[%u][%u] == [%.2f]",x,y,(edk::float64)(*value));edkEnd();
    }
private:
    edk::classID classThis;
};
}//end namespace vector
}//end namespace edk

#endif // MATRIX_H
