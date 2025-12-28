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
        this->classThis=NULL;
        this->Constructor();
    }
    MatrixDynamic(edk::size2f32 size){
        this->classThis=NULL;
        this->Constructor(size);
    }
    MatrixDynamic(edk::uint32 width,edk::uint32 height){
        this->classThis=NULL;
        this->Constructor(width,height);
    }
    virtual ~MatrixDynamic(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            this->isClass = edk::ID<typeTemplate>::isClass();
            this->matrixSize = 0u;
            //set the matrix to NULL
            this->matrix=NULL;
            this->matrixDest=NULL;

            this->matrixPointer = &this->matrix;
            this->matrixDestPointer = &this->matrixDest;
            this->matrixSizePointer = &this->matrixSize;
        }
    }
    void Constructor(edk::size2f32 size){
        if(this->classThis!=this){
            this->classThis=this;
            this->isClass = edk::ID<typeTemplate>::isClass();
            //set the matrix to NULL
            this->matrix=NULL;
            this->matrixDest=NULL;

            this->matrixPointer = &this->matrix;
            this->matrixDestPointer = &this->matrixDest;
            this->matrixSizePointer = &this->matrixSize;

            //create a new matrix
            this->createMatrix(size);
        }
    }
    void Constructor(edk::uint32 width,edk::uint32 height){
        if(this->classThis!=this){
            this->classThis=this;
            this->isClass = edk::ID<typeTemplate>::isClass();
            //set the matrix to NULL
            this->matrix=NULL;
            this->matrixDest=NULL;

            this->matrixPointer = &this->matrix;
            this->matrixDestPointer = &this->matrixDest;
            this->matrixSizePointer = &this->matrixSize;

            //create a new matrix
            this->createMatrix(width,height);
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->deleteMatrix();
        }
    }


    //create the matrix
    bool createMatrix(edk::size2ui32 size){
        //first delete
        this->deleteMatrix();

        //Test the size
        if(size.width && size.height){
            if(this->isClass){
                (*this->matrixPointer) = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);
                if((*this->matrixPointer)){
                    memset((*this->matrixPointer),0u,sizeof(typeTemplate)*size.height);
                    for(edk::uint32 i=0u;i<size.height;i++){
                        (*this->matrixPointer)[i] = new typeTemplate[size.width];
                        if((*this->matrixPointer)[i]){
                            //don't clean a class
                            //memset((*this->matrixPointer)[i],0u,sizeof(typeTemplate)*size.width);
                        }
                        else{
                            for(edk::uint32 j=i+1u;i>0u;j--){
                                //delete the matrix
                                delete[] (*this->matrixPointer)[j-1u];
                            }
                            free((*this->matrixPointer));
                            return false;
                        }
                    }
                    (*this->matrixSizePointer) = size;
                    return true;
                }
            }
            else{
                (*this->matrixPointer) = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);
                if((*this->matrixPointer)){
                    memset((*this->matrixPointer),0u,sizeof(typeTemplate)*size.height);
                    for(edk::uint32 i=0u;i<size.height;i++){
                        (*this->matrixPointer)[i] = (typeTemplate*)malloc(sizeof(typeTemplate)*size.width);
                        if((*this->matrixPointer)[i]){
                            memset((*this->matrixPointer)[i],0u,sizeof(typeTemplate)*size.width);
                        }
                        else{
                            for(edk::uint32 j=i+1u;i>0u;j--){
                                //delete the matrix
                                free((*this->matrixPointer)[j-1u]);
                            }
                            free((*this->matrixPointer));
                            return false;
                        }
                    }
                    (*this->matrixSizePointer) = size;
                    return true;
                }
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
            memcpy(&(*this->matrixPointer)[position.y][position.x],&obj,sizeof(typeTemplate));
            //return true
            return true;
        }
        //else return false
        return false;
    }
    bool set(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        return this->set(edk::vec2ui32(x,y),obj);
    }
    //SETTER WITHOUT IF
    inline void setNoIF(edk::vec2ui32 position,typeTemplate obj){
        memcpy(&(*this->matrixPointer)[position.y][position.x],&obj,sizeof(typeTemplate));
    }
    inline void setNoIF(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        memcpy(&(*this->matrixPointer)[y][x],&obj,sizeof(typeTemplate));
    }
    //set the matrix as identity
    virtual bool setIdentity(typeTemplate valueOne,typeTemplate valueZero){
        if((*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    if(x==y){
                        memcpy(&(*this->matrixPointer)[y][x],&valueOne,sizeof(typeTemplate));
                    }
                    else{
                        memcpy(&(*this->matrixPointer)[y][x],&valueZero,sizeof(typeTemplate));
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
        return (*this->matrixSizePointer);
    }
    inline edk::uint32 width(){
        return (*this->matrixSizePointer).width;
    }
    inline edk::uint32 height(){
        return (*this->matrixSizePointer).height;
    }
    inline edk::size2ui32  getSize(){
        return (*this->matrixSizePointer);
    }
    inline edk::uint32 getWidth(){
        return (*this->matrixSizePointer).width;
    }
    inline edk::uint32 getHeight(){
        return (*this->matrixSizePointer).height;
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
        return this->have(edk::vec2f32(x,y));
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
            return (*this->matrixPointer)[position.y][position.x];
        }
        typeTemplate ret;  memset((void*)&ret,0u,sizeof(typeTemplate));
        return ret;
    }
    //return the value in a position
    inline typeTemplate get(edk::uint32 x,edk::uint32 y){
        return this->get(edk::vec2ui32(x,y));
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
                    (*this->matrixPointer)[y][x]=(*this->matrixPointer)[y][x]+matrix->matrix[y][x];
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
                    (*this->matrixPointer)[y][x]=(*this->matrixPointer)[y][x]+n;
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
                    (*this->matrixPointer)[y][x]=(*this->matrixPointer)[y][x]-matrix->matrix[y][x];
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
                    (*this->matrixPointer)[y][x]=(*this->matrixPointer)[y][x]-n;
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
            typeTemplate destSum;
            typeTemplate destMultiply;
            if((*this->matrixSizePointer).width==matrix->matrixSize.width){
                //test if have the matrixDest
                if(!(*this->matrixDestPointer)){
                    //create the matrixDest
                    this->createMatrixDest();
                }
                if((*this->matrixDestPointer)){
                    //copy the values
                    for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                        for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                            //clean the value
                            memset((void*)&destSum,0u,sizeof(typeTemplate));
                            //multiply
                            for(edk::uint32 i=0u;i<(*this->matrixSizePointer).width;i++){
                                this->multiplyElement(&(*this->matrixPointer)[y][i],&matrix->matrix[i][x],&destMultiply);
                                this->sumElement(&destMultiply,&destSum,&destSum);
                            }
                            //set the value
                            memcpy((void*)&((*this->matrixDestPointer)[y][x]),&destSum,sizeof(typeTemplate));
                        }
                    }
                    this->flipMatrix();
                    return true;
                }
            }
            else{
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32(matrix->matrixSize.width,(*this->matrixSizePointer).height);

                if(this->isClass){
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = new typeTemplate[size.width];
                            if(newMatrix[y]){
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //multiply
                                    for(edk::uint32 i=0u;i<(*this->matrixSizePointer).width;i++){
                                        this->multiplyElement(&(*this->matrixPointer)[y][i],&matrix->matrix[i][x],&destMultiply);
                                        this->sumElement(&destMultiply,&destSum,&destSum);
                                    }
                                    //set the value
                                    memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));
                                }
                            }
                            else{
                                for(edk::uint32 j=y+1u;y>0u;j--){
                                    //delete the matrix
                                    delete[] newMatrix[j];
                                }
                                free(newMatrix);
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();
                        (*this->matrixPointer) = newMatrix;
                        (*this->matrixSizePointer) = size;
                        return true;
                    }
                }
                else{
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = (typeTemplate*)malloc(sizeof(typeTemplate)*size.width);
                            if(newMatrix[y]){
                                memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //clean the value
                                    memset((void*)&destSum,0u,sizeof(typeTemplate));
                                    //multiply
                                    for(edk::uint32 i=0u;i<(*this->matrixSizePointer).width;i++){
                                        this->multiplyElement(&(*this->matrixPointer)[y][i],&matrix->matrix[i][x],&destMultiply);
                                        this->sumElement(&destMultiply,&destSum,&destSum);
                                    }
                                    //set the value
                                    memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));
                                }
                            }
                            else{
                                for(edk::uint32 j=y+1u;y>0u;j--){
                                    //delete the matrix
                                    free(newMatrix[j]);
                                }
                                free(newMatrix);
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();
                        (*this->matrixPointer) = newMatrix;
                        (*this->matrixSizePointer) = size;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool multiplyMatrixWithThis(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(this->canMultiplyMatrixWithThis(matrix)){
            typeTemplate destSum;
            typeTemplate destMultiply;
            if((*this->matrixSizePointer).height==matrix->matrixSize.height){
                //test if have the matrixDest
                if(!(*this->matrixDestPointer)){
                    //create the matrixDest
                    this->createMatrixDest();
                }
                if((*this->matrixDestPointer)){
                    //copy the values
                    for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                        for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                            //clean the value
                            memset((void*)&destSum,0u,sizeof(typeTemplate));
                            //multiply
                            for(edk::uint32 i=0u;i<matrix->matrixSize.width;i++){
                                this->multiplyElement(&matrix->matrix[y][i],&(*this->matrixPointer)[i][x],&destMultiply);
                                this->sumElement(&destMultiply,&destSum,&destSum);
                            }
                            //set the value
                            memcpy((void*)&matrixDest[y][x],&destSum,sizeof(typeTemplate));
                        }
                    }
                    this->flipMatrix();
                    return true;
                }
            }
            else{
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32((*this->matrixSizePointer).width,matrix->matrixSize.height);

                if(this->isClass){
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = new typeTemplate[size.width];
                            if(newMatrix[y]){
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //multiply
                                    for(edk::uint32 i=0u;i<matrix->matrixSize.width;i++){
                                        this->multiplyElement(&matrix->matrix[y][i],&(*this->matrixPointer)[i][x],&destMultiply);
                                        this->sumElement(&destMultiply,&destSum,&destSum);
                                    }
                                    //set the value
                                    memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));
                                }
                            }
                            else{
                                for(edk::uint32 j=y+1u;y>0u;j--){
                                    //delete the matrix
                                    delete[] newMatrix[j];
                                }
                                free(newMatrix);
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();
                        (*this->matrixPointer) = newMatrix;
                        (*this->matrixSizePointer) = size;
                        return true;
                    }
                }
                else{
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = (typeTemplate*)malloc(sizeof(typeTemplate)*size.width);
                            if(newMatrix[y]){
                                memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //clean the value
                                    memset((void*)&destSum,0u,sizeof(typeTemplate));
                                    //multiply
                                    for(edk::uint32 i=0u;i<matrix->matrixSize.width;i++){
                                        this->multiplyElement(&matrix->matrix[y][i],&(*this->matrixPointer)[i][x],&destMultiply);
                                        this->sumElement(&destMultiply,&destSum,&destSum);
                                    }
                                    //set the value
                                    memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));
                                }
                            }
                            else{
                                for(edk::uint32 j=y+1u;y>0u;j--){
                                    //delete the matrix
                                    free(newMatrix[j]);
                                }
                                free(newMatrix);
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();
                        (*this->matrixPointer) = newMatrix;
                        (*this->matrixSizePointer) = size;
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
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyMatrices(matrix1,matrix2);
    }

    bool multiply(edk::vector::MatrixDynamic<typeTemplate>* matrix1,edk::vector::MatrixDynamic<typeTemplate>* matrix2){
        if(this->canMultiply(matrix1,matrix2)){
            typeTemplate destSum;
            typeTemplate destMultiply;
            if((*this->matrixSizePointer).width == matrix2->matrixSize.width && (*this->matrixSizePointer).height == matrix1->matrixSize.height){
                //test if have the matrixDest
                if(!(*this->matrixDestPointer)){
                    //create the matrixDest
                    this->createMatrixDest();
                }
                if((*this->matrixDestPointer)){
                    //copy the values
                    for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                        for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                            memset((void*)&destSum,0u,sizeof(typeTemplate));
                            //multiply
                            for(edk::uint32 i=0u;i<matrix1->matrixSize.width;i++){
                                this->multiplyElement(&matrix1->matrix[y][i],&matrix2->matrix[i][x],&destMultiply);
                                this->sumElement(&destMultiply,&destSum,&destSum);
                            }
                            //set the value
                            memcpy((void*)&(*this->matrixDestPointer)[y][x],&destSum,sizeof(typeTemplate));
                        }
                    }
                    this->flipMatrix();
                }
            }
            else{
                //alloc the new matrix
                edk::size2ui32 size = edk::size2ui32(matrix2->matrixSize.width,matrix1->matrixSize.height);

                if(this->isClass){
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = new typeTemplate[size.width];
                            if(newMatrix[y]){
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //multiply
                                    for(edk::uint32 i=0u;i<matrix1->matrixSize.width;i++){
                                        this->multiplyElement(&matrix1->matrix[y][i],&matrix2->matrix[i][x],&destMultiply);
                                        this->sumElement(&destMultiply,&destSum,&destSum);
                                    }
                                    //set the value
                                    memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));
                                }
                            }
                            else{
                                for(edk::uint32 j=y+1u;y>0u;j--){
                                    //delete the matrix
                                    delete[] newMatrix[j];
                                }
                                free(newMatrix);
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();
                        (*this->matrixPointer) = newMatrix;
                        (*this->matrixSizePointer) = size;
                        return true;
                    }
                }
                else{
                    typeTemplate** newMatrix = (typeTemplate**)malloc(sizeof(typeTemplate*)*size.height);
                    if(newMatrix){
                        memset(newMatrix,0u,sizeof(typeTemplate)*size.height);
                        for(edk::uint32 y=0u;y<size.height;y++){
                            newMatrix[y] = (typeTemplate*)malloc(sizeof(typeTemplate)*size.width);
                            if(newMatrix[y]){
                                memset(newMatrix[y],0u,sizeof(typeTemplate)*size.width);
                                for(edk::uint32 x=0u;x<size.width;x++){
                                    //clean the value
                                    memset((void*)&destSum,0u,sizeof(typeTemplate));
                                    //multiply
                                    for(edk::uint32 i=0u;i<matrix1->matrixSize.width;i++){
                                        this->multiplyElement(&matrix1->matrix[y][i],&matrix2->matrix[i][x],&destMultiply);
                                        this->sumElement(&destMultiply,&destSum,&destSum);
                                    }
                                    //set the value
                                    memcpy((void*)&newMatrix[y][x],&destSum,sizeof(typeTemplate));
                                }
                            }
                            else{
                                for(edk::uint32 j=y+1u;y>0u;j--){
                                    //delete the matrix
                                    free(newMatrix[j]);
                                }
                                free(newMatrix);
                                return false;
                            }
                        }
                        //in the end. delete the old matrix and copy the new matrix
                        this->deleteMatrix();
                        (*this->matrixPointer) = newMatrix;
                        (*this->matrixSizePointer) = size;
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
            printf("\nMatrix [%u] [%u]",(*this->matrixSizePointer).width,(*this->matrixSizePointer).height);
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    this->printElement(x,y,&(*this->matrixPointer)[y][x]);
                }
            }fflush(stdout);
            return true;
        }
        return false;
    }

    virtual bool printMatrixX(){
        if((*this->matrixPointer) && (*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            //printf("\nMatrix [%u] [%u]",(*this->matrixSizePointer).width,(*this->matrixSizePointer).height);
            for(edk::uint32 y=0u;y<(*this->matrixSizePointer).height;y++){
                printf("\n");
                for(edk::uint32 x=0u;x<(*this->matrixSizePointer).width;x++){
                    this->printElementX(&(*this->matrixPointer)[y][x]);
                    printf(",");
                }
            }fflush(stdout);
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
                    delete[] (*this->matrixPointer)[i];
                }
                free((*this->matrixPointer));
            }
            else{
                for(edk::uint32 i=0u;i<(*this->matrixSizePointer).height;i++){
                    free((*this->matrixPointer)[i]);
                }
                free((*this->matrixPointer));
            }

            this->deleteMatrixDest();
        }
        (*this->matrixPointer)=NULL;
        (*this->matrixSizePointer)=0u;
    }

    virtual inline bool copyFrom(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(matrix){
            if(matrix->getWidth() && matrix->getHeight()
                    && this->getWidth() && this->getHeight()
                    ){
                if(this->getWidth() <= matrix->getWidth()){
                    if(this->getHeight() <= matrix->getHeight()){
                        for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                            memcpy(this->matrix[y],matrix->matrix[y],sizeof(typeTemplate)*this->matrixSize.width);
                        }
                    }
                    else{
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy(this->matrix[y],matrix->matrix[y],sizeof(typeTemplate)*this->matrixSize.width);
                        }
                    }
                }
                else{
                    if(this->getHeight() <= matrix->getHeight()){
                        for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                            memcpy(this->matrix[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);
                        }
                    }
                    else{
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy(this->matrix[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }
    virtual inline bool copyTo(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(matrix){
            if(matrix->getWidth() && matrix->getHeight()
                    && this->getWidth() && this->getHeight()
                    ){
                if(matrix->getWidth() <= this->getWidth()){
                    if(matrix->getHeight() <= this->getHeight()){
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy(matrix->matrix[y],this->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);
                        }
                    }
                    else{
                        for(edk::uint32 y=0u;y<this->matrixSize.height;y++){
                            memcpy(matrix->matrix[y],this->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);
                        }
                    }
                }
                else{
                    if(matrix->getHeight() <= this->getHeight()){
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy(matrix->matrix[y],this->matrix[y],sizeof(typeTemplate)*this->matrixSize.width);
                        }
                    }
                    else{
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy(matrix->matrix[y],this->matrix[y],sizeof(typeTemplate)*this->matrixSize.width);
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }

    virtual inline bool invertThis(){
        if(*this->matrixPointer){
            if((*this->matrixSizePointer).width == (*this->matrixSizePointer).height){
                //test if have the matrixDest
                if(!(*this->matrixDestPointer)){
                    //create the matrixDest
                    this->createMatrixDest();
                }
                if((*this->matrixDestPointer)){
                    //matrix 2x2
                    typeTemplate zeroCompare;
                    memset(&zeroCompare,0u,sizeof(typeTemplate));
                    //create the dest matrix
                    if((*this->matrixSizePointer).width==2u){

                        //calculate the determinant
                        typeTemplate temp1;
                        this->multiplyElement(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[1u][1u],&temp1);
                        typeTemplate temp2;
                        this->multiplyElement(&(*this->matrixPointer)[1u][0u],&(*this->matrixPointer)[0u][1u],&temp2);
                        typeTemplate determinant;
                        this->subElement(&temp1,&temp2,&determinant);

                        if(!memcmp(&determinant,&zeroCompare,sizeof(typeTemplate))){
                            return false;
                        }

                        //divide the matrix by the determinant
                        this->divideElement(&(*this->matrixPointer)[0u][0u],&determinant,&(*this->matrixPointer)[0u][0u]);
                        this->divideElement(&(*this->matrixPointer)[1u][0u],&determinant,&(*this->matrixPointer)[1u][0u]);
                        this->divideElement(&(*this->matrixPointer)[1u][0u],&determinant,&(*this->matrixPointer)[0u][1u]);
                        this->divideElement(&(*this->matrixPointer)[1u][1u],&determinant,&(*this->matrixPointer)[1u][1u]);

                        //invert positions in the the principal diagonal
                        memcpy(&temp1,&(*this->matrixPointer)[0u][0u],sizeof(typeTemplate));
                        memcpy(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[1u][1u],sizeof(typeTemplate));
                        memcpy(&(*this->matrixPointer)[1u][1u],&temp1,sizeof(typeTemplate));

                        //invert the non principal diagonal values
                        //this->multiplyElementMinusOne(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[0u][0u]);
                        this->multiplyElementMinusOne(&(*this->matrixPointer)[1u][0u],&(*this->matrixPointer)[1u][0u]);
                        this->multiplyElementMinusOne(&(*this->matrixPointer)[0u][1u],&(*this->matrixPointer)[0u][1u]);
                        //this->multiplyElementMinusOne(&(*this->matrixPointer)[1u][1u],&(*this->matrixPointer)[1u][1u]);

                        return true;
                    }
                    else if((*this->matrixSizePointer).width==3u){
                        //matrix 3x3

                        typeTemplate temp1;
                        typeTemplate temp2;
                        typeTemplate tempMultiply;

                        this->multiplyElement(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[1u][1u],&tempMultiply);
                        this->multiplyElement(&tempMultiply,&(*this->matrixPointer)[2u][2u],&tempMultiply);
                        this->sumElement(&tempMultiply,&zeroCompare,&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[1u][0u],&(*this->matrixPointer)[2u][1u],&tempMultiply);
                        this->multiplyElement(&tempMultiply,&(*this->matrixPointer)[0u][2u],&tempMultiply);
                        this->sumElement(&tempMultiply,&temp1,&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[2u][0u],&(*this->matrixPointer)[0u][1u],&tempMultiply);
                        this->multiplyElement(&tempMultiply,&(*this->matrixPointer)[1u][2u],&tempMultiply);
                        this->sumElement(&tempMultiply,&temp1,&temp1);

                        this->multiplyElement(&(*this->matrixPointer)[2u][0u],&(*this->matrixPointer)[1u][1u],&tempMultiply);
                        this->multiplyElement(&tempMultiply,&(*this->matrixPointer)[0u][2u],&tempMultiply);
                        this->sumElement(&tempMultiply,&zeroCompare,&temp2);
                        this->multiplyElement(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[2u][1u],&tempMultiply);
                        this->multiplyElement(&tempMultiply,&(*this->matrixPointer)[1u][2u],&tempMultiply);
                        this->sumElement(&tempMultiply,&temp2,&temp2);
                        this->multiplyElement(&(*this->matrixPointer)[1u][0u],&(*this->matrixPointer)[0u][1u],&tempMultiply);
                        this->multiplyElement(&tempMultiply,&(*this->matrixPointer)[2u][2u],&tempMultiply);
                        this->sumElement(&tempMultiply,&temp2,&temp2);

                        typeTemplate determinant;
                        this->subElement(&temp1,&temp2,&determinant);

                        if(!memcmp(&determinant,&zeroCompare,sizeof(typeTemplate))){
                            return false;
                        }

                        //calculate the co-factor matrix

                        //0x0
                        this->multiplyElement(&(*this->matrixPointer)[1u][1u],&(*this->matrixPointer)[2u][2u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[2u][1u],&(*this->matrixPointer)[1u][2u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[0u][0u]);
                        //1x0
                        this->multiplyElement(&(*this->matrixPointer)[0u][1u],&(*this->matrixPointer)[2u][2u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[2u][1u],&(*this->matrixPointer)[0u][2u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[1u][0u]);
                        //2x0
                        this->multiplyElement(&(*this->matrixPointer)[0u][1u],&(*this->matrixPointer)[1u][2u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[1u][1u],&(*this->matrixPointer)[0u][2u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[2u][0u]);
                        //0x1
                        this->multiplyElement(&(*this->matrixPointer)[1u][0u],&(*this->matrixPointer)[2u][2u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[2u][0u],&(*this->matrixPointer)[1u][2u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[0u][1u]);
                        //1x1
                        this->multiplyElement(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[2u][2u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[2u][0u],&(*this->matrixPointer)[0u][2u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[1u][1u]);
                        //2x1
                        this->multiplyElement(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[1u][2u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[1u][0u],&(*this->matrixPointer)[0u][2u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[2u][1u]);
                        //0x2
                        this->multiplyElement(&(*this->matrixPointer)[1u][0u],&(*this->matrixPointer)[2u][1u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[2u][0u],&(*this->matrixPointer)[1u][1u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[0u][2u]);
                        //1x2
                        this->multiplyElement(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[2u][1u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[2u][0u],&(*this->matrixPointer)[0u][1u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[1u][2u]);
                        //2x2
                        this->multiplyElement(&(*this->matrixPointer)[0u][0u],&(*this->matrixPointer)[1u][1u],&temp1);
                        this->multiplyElement(&(*this->matrixPointer)[1u][0u],&(*this->matrixPointer)[0u][1u],&temp2);
                        this->subElement(&temp1,&temp2,&(*this->matrixDestPointer)[2u][2u]);

                        //invert the signals
                        //this->multiplyElementMinusOne(&(*this->matrixDestPointer)[0u][0u],&(*this->matrixDestPointer)[0u][0u]);
                        this->multiplyElementMinusOne(&(*this->matrixDestPointer)[0u][1u],&(*this->matrixDestPointer)[0u][1u]);
                        //this->multiplyElementMinusOne(&(*this->matrixDestPointer)[0u][2u],&(*this->matrixDestPointer)[0u][2u]);
                        this->multiplyElementMinusOne(&(*this->matrixDestPointer)[1u][0u],&(*this->matrixDestPointer)[1u][0u]);
                        //this->multiplyElementMinusOne(&(*this->matrixDestPointer)[1u][1u],&(*this->matrixDestPointer)[1u][1u]);
                        this->multiplyElementMinusOne(&(*this->matrixDestPointer)[1u][2u],&(*this->matrixDestPointer)[1u][2u]);
                        //this->multiplyElementMinusOne(&(*this->matrixDestPointer)[2u][0u],&(*this->matrixDestPointer)[2u][0u]);
                        this->multiplyElementMinusOne(&(*this->matrixDestPointer)[2u][1u],&(*this->matrixDestPointer)[2u][1u]);
                        //this->multiplyElementMinusOne(&(*this->matrixDestPointer)[2u][2u],&(*this->matrixDestPointer)[2u][2u]);


                        this->divideElement(&(*this->matrixDestPointer)[0u][0u],&determinant,&(*this->matrixPointer)[0u][0u]);
                        this->divideElement(&(*this->matrixDestPointer)[1u][0u],&determinant,&(*this->matrixPointer)[0u][1u]);
                        this->divideElement(&(*this->matrixDestPointer)[2u][0u],&determinant,&(*this->matrixPointer)[0u][2u]);

                        this->divideElement(&(*this->matrixDestPointer)[0u][1u],&determinant,&(*this->matrixPointer)[1u][0u]);
                        this->divideElement(&(*this->matrixDestPointer)[1u][1u],&determinant,&(*this->matrixPointer)[1u][1u]);
                        this->divideElement(&(*this->matrixDestPointer)[2u][1u],&determinant,&(*this->matrixPointer)[1u][2u]);

                        this->divideElement(&(*this->matrixDestPointer)[0u][2u],&determinant,&(*this->matrixPointer)[2u][0u]);
                        this->divideElement(&(*this->matrixDestPointer)[1u][2u],&determinant,&(*this->matrixPointer)[2u][1u]);
                        this->divideElement(&(*this->matrixDestPointer)[2u][2u],&determinant,&(*this->matrixPointer)[2u][2u]);

                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool cloneFrom(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        if(matrix){
            if(matrix->matrixSize.width && matrix->matrixSize.height){
                if((*this->matrixSizePointer).width == matrix->width() && (*this->matrixSizePointer).height == matrix->height()){
                    if(matrix){
                        //copy the values
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy((*this->matrixPointer)[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);
                        }
                        return true;
                    }
                }
                else{
                    this->deleteMatrix();
                    if(this->createMatrix(matrix->matrixSize.width,matrix->matrixSize.height)){
                        //copy the values
                        for(edk::uint32 y=0u;y<matrix->matrixSize.height;y++){
                            memcpy((*this->matrixPointer)[y],matrix->matrix[y],sizeof(typeTemplate)*matrix->matrixSize.width);
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
        this->cloneFrom(&matrix);
        matrix.cantDeleteVector();
        return this;
    }
    inline bool operator==(edk::vector::MatrixDynamic<typeTemplate> matrix){
        matrix.cantDeleteVector();
        return this->isEqual(&matrix);
    }
    inline bool operator!=(edk::vector::MatrixDynamic<typeTemplate> matrix){
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
    inline void operator+=(edk::vector::MatrixDynamic<typeTemplate> matrix){
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
    inline void operator-=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->sub(&matrix);
    }
    edk::vector::MatrixDynamic<typeTemplate> operator*(edk::vector::MatrixDynamic<typeTemplate> matrix){
        edk::vector::MatrixDynamic<typeTemplate> ret;
        ret.multiply(this,&matrix);
        return ret;
    }
    edk::vector::MatrixDynamic<typeTemplate> operator*=(edk::vector::MatrixDynamic<typeTemplate> matrix){
        this->multiplyThisWithMatrix(&matrix);
        return *this;
    }
protected:
    virtual void printElement(edk::uint32 /*x*/,edk::uint32 /*y*/,typeTemplate* /*value*/){
        //printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);
    }
    virtual void printElementX(typeTemplate* /*value*/){
        //printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);
    }
    virtual void multiplyElement(typeTemplate* value1,typeTemplate* value2,typeTemplate* dest){
        *dest = (*value1)*(*value2);
    }
    virtual void multiplyElementMinusOne(typeTemplate* value,typeTemplate* dest){
        *dest = (*value)*(-1);
    }
    virtual void sumElement(typeTemplate* value1,typeTemplate* value2,typeTemplate* dest){
        *dest = (*value1)+(*value2);
    }
    virtual void subElement(typeTemplate* value1,typeTemplate* value2,typeTemplate* dest){
        *dest = (*value1)-(*value2);
    }
    virtual void divideElement(typeTemplate* value1,typeTemplate* value2,typeTemplate* dest){
        *dest = (*value1)/(*value2);
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
                    delete[] (*this->matrixDestPointer)[i];
                }
                else{
                    free((*this->matrixDestPointer)[i]);
                }
            }
            free((*this->matrixDestPointer));
        }
        (*this->matrixDestPointer)=NULL;
    }

    //create the matrix Dest
    bool createMatrixDest(){
        //first delete
        this->deleteMatrixDest();

        //Test the size
        if((*this->matrixSizePointer).width && (*this->matrixSizePointer).height){
            if(this->isClass){
                (*this->matrixDestPointer) = (typeTemplate**)malloc(sizeof(typeTemplate*)*(*this->matrixSizePointer).height);
                if((*this->matrixDestPointer)){
                    memset((*this->matrixDestPointer),0u,sizeof(typeTemplate)*(*this->matrixSizePointer).height);
                    for(edk::uint32 i=0u;i<matrixSize.height;i++){
                        (*this->matrixDestPointer)[i] = new typeTemplate[(*this->matrixSizePointer).width];
                        if((*this->matrixDestPointer)[i]){
                            //don't set the matrix woth classes
                            //memset((*this->matrixDestPointer)[i],0u,sizeof(typeTemplate)*(*this->matrixSizePointer).width);
                        }
                        else{
                            for(edk::uint32 j=i+1u;i>0u;j--){
                                //delete the matrix
                                delete[] (*this->matrixDestPointer)[j];
                            }
                            free((*this->matrixDestPointer));
                            return false;
                        }
                    }
                    return true;
                }
            }
            else{
                (*this->matrixDestPointer) = (typeTemplate**)malloc(sizeof(typeTemplate*)*(*this->matrixSizePointer).height);
                if((*this->matrixDestPointer)){
                    memset((*this->matrixDestPointer),0u,sizeof(typeTemplate)*(*this->matrixSizePointer).height);
                    for(edk::uint32 i=0u;i<matrixSize.height;i++){
                        (*this->matrixDestPointer)[i] = (typeTemplate*)malloc(sizeof(typeTemplate)*(*this->matrixSizePointer).width);
                        if((*this->matrixDestPointer)[i]){
                            memset((*this->matrixDestPointer)[i],0u,sizeof(typeTemplate)*(*this->matrixSizePointer).width);
                        }
                        else{
                            for(edk::uint32 j=i+1u;i>0u;j--){
                                //delete the matrix
                                free((*this->matrixDestPointer)[j]);
                            }
                            free((*this->matrixDestPointer));
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
        typeTemplate** matrixTemp = (*this->matrixPointer);
        (*this->matrixPointer) = (*this->matrixDestPointer);
        (*this->matrixDestPointer) = matrixTemp;
    }
private:
#if defined(EDK_DEBUG_VECTOR)
    inline edk::uint64 generateDebugValue(typeTemplate* value){
        edk::uint64 newValue=0uL;
        if(sizeof(typeTemplate)>=sizeof(newValue)){
            memcpy((void*)&newValue,(void*)value,sizeof(newValue));
        }
        else{
            memcpy((void*)&newValue,(void*)value,sizeof(typeTemplate));
        }
        return newValue;
    }
#endif
private:
    edk::classID classThis;
};
//Use a template to alloc whatever
template <class typeTemplate,edk::uint32 m,edk::uint32 n>
class Matrix : private edk::vector::MatrixDynamic<typeTemplate>{
public:
    inline Matrix(){
        this->classThis=NULL;
        this->Constructor();
    }
    inline ~Matrix(){
        this->Destructor();
    }

    inline void Constructor(){
        edk::vector::MatrixDynamic<typeTemplate>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            edk::vector::MatrixDynamic<typeTemplate>::createMatrix(m,n);
            if(m==n){
                canMultiplyMatrix=true;
            }
            else{
                canMultiplyMatrix=false;
            }
        }
    }
    inline void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            edk::vector::MatrixDynamic<typeTemplate>::deleteMatrix();
        }
        edk::vector::MatrixDynamic<typeTemplate>::Destructor();
    }

    //SETTERS
    inline bool set(edk::vec2ui32 position,typeTemplate obj){
        return edk::vector::MatrixDynamic<typeTemplate>::set(position,obj);
    }
    inline bool set(edk::uint32 x,edk::uint32 y,typeTemplate obj){
        return edk::vector::MatrixDynamic<typeTemplate>::set(x,y,obj);
    }
    //set the matrix as identity
    inline virtual bool setIdentity(typeTemplate valueOne,typeTemplate valueZero){
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
        return edk::vector::MatrixDynamic<typeTemplate>::isEqual(matrix);
    }
    //add the matrix with another
    inline virtual bool add(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::add(matrix);
    }
    //add the matrix with another
    inline bool increment(edk::int32 value){
        return edk::vector::MatrixDynamic<typeTemplate>::increment(value);
    }
    //sub the matrix with another
    inline virtual bool sub(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::sub(matrix);
    }
    //add the matrix with another
    inline bool decrement(edk::int32 value){
        return edk::vector::MatrixDynamic<typeTemplate>::decrement(value);
    }

    //return true if can multiply
    inline bool canMultiplyThis(){
        return this->canMultiplyMatrix;
    }
    inline virtual bool canMultiplyThisWithMatrix(edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;
    }
    inline bool canMultiplyThisWithMatrix(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyThisWithMatrix(matrix);
    }
    inline virtual bool canMultiplyMatrixWithThis(edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;
    }
    inline bool canMultiplyMatrixWithThis(edk::vector::MatrixDynamic<typeTemplate>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::canMultiplyMatrixWithThis(matrix);
    }
    inline virtual bool multiplyThisWithMatrix(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiplyThisWithMatrix(matrix);
        }
        return false;
    }
    inline virtual bool multiplyMatrixWithThis(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiplyMatrixWithThis(matrix);
        }
        return false;
    }
    //return true if can multiply
    inline bool canMultiply(edk::vector::MatrixDynamic<typeTemplate>* matrix1,edk::vector::MatrixDynamic<typeTemplate>* matrix2){
        return edk::vector::MatrixDynamic<typeTemplate>::multiply(matrix1,matrix2);
    }
    inline virtual bool canMultiply(edk::vector::Matrix<typeTemplate,m,n>*,edk::vector::Matrix<typeTemplate,m,n>*){
        return this->canMultiplyMatrix;
    }
    inline virtual bool multiply(edk::vector::Matrix<typeTemplate,m,n>* matrix1,edk::vector::Matrix<typeTemplate,m,n>* matrix2){
        if(this->canMultiplyMatrix){
            return edk::vector::MatrixDynamic<typeTemplate>::multiply(matrix1,matrix2);
        }
        return false;
    }

    //print the matrix
    inline virtual bool printMatrix(){
        return edk::vector::MatrixDynamic<typeTemplate>::printMatrix();
    }
    inline virtual bool printMatrixX(){
        return edk::vector::MatrixDynamic<typeTemplate>::printMatrixX();
    }

    virtual inline bool copyFrom(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::copyFrom(matrix);
    }

    virtual inline bool invertThis(){
        return edk::vector::MatrixDynamic<typeTemplate>::invertThis();
    }

    inline virtual bool cloneFrom(edk::vector::Matrix<typeTemplate,m,n>* matrix){
        return edk::vector::MatrixDynamic<typeTemplate>::cloneFrom(matrix);
    }

    //the operators are private because I can's fix it yet
private:
    inline edk::vector::Matrix<typeTemplate,m,n>* operator=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->cloneFrom(&matrix);
        return &matrix;
    }
    inline bool operator==(edk::vector::Matrix<typeTemplate,m,n> matrix){
        return this->isEqual(&matrix);
    }
    inline bool operator!=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        return !this->isEqual(&matrix);
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator+(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->add(&matrix);
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
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator*(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->multiplyThisWithMatrix(&matrix);
        return *this;
    }
    inline edk::vector::Matrix<typeTemplate,m,n> operator*=(edk::vector::Matrix<typeTemplate,m,n> matrix){
        this->multiplyThisWithMatrix(&matrix);
        return *this;
    }
protected:
    inline void printElement(edk::uint32 /*x*/,edk::uint32 /*y*/,typeTemplate* /*value*/){
        //printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);
    }
    inline void printElementX(typeTemplate* /*value*/){
        //printf("\n[%u][%u] == [%ld]",x,y,(edk::int64)*value);
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
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~Matrixf32(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::Matrix<edk::float32,m,n>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
        }
        edk::vector::Matrix<edk::float32,m,n>::Destructor();
    }

    //set the matrix as identity
    inline virtual bool setIdentity(edk::float32 valueOne,edk::float32 valueZero){
        return edk::vector::Matrix<edk::float32,m,n>::setIdentity(valueOne,valueZero);
    }
    inline virtual bool setIdentity(){
        return edk::vector::Matrix<edk::float32,m,n>::setIdentity(1.f,0.f);
    }

    //test if a matrix is equal then other
    inline virtual bool isEqual(edk::vector::Matrixf32<m,n>* matrix){
        return  edk::vector::Matrix<edk::float32,m,n>::isEqual(matrix);
    }
    //add the matrix with another
    inline virtual bool add(edk::vector::Matrixf32<m,n>* matrix){
        return  edk::vector::Matrix<edk::float32,m,n>::add(matrix);
    }
    //sub the matrix with another
    inline virtual bool sub(edk::vector::Matrixf32<m,n>* matrix){
        return  edk::vector::Matrix<edk::float32,m,n>::sub(matrix);
    }

    //return true if can multiply
    inline virtual bool canMultiplyThisWithMatrix(edk::vector::Matrixf32<m,n>*){
        return this->canMultiplyMatrix;
    }
    inline virtual bool canMultiplyMatrixWithThis(edk::vector::Matrixf32<m,n>*){
        return this->canMultiplyMatrix;
    }
    inline virtual bool multiplyThisWithMatrix(edk::vector::Matrixf32<m,n>* matrix){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float32,m,n>::multiplyThisWithMatrix(matrix);
        }
        return false;
    }
    inline virtual bool multiplyMatrixWithThis(edk::vector::Matrixf32<m,n>* matrix){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float32,m,n>::multiplyMatrixWithThis(matrix);
        }
        return false;
    }
    //return true if can multiply
    inline virtual bool canMultiply(edk::vector::Matrixf32<m,n>*,edk::vector::Matrixf32<m,n>*){
        return this->canMultiplyMatrix;
    }
    inline virtual bool multiply(edk::vector::Matrixf32<m,n>* matrix1,edk::vector::Matrixf32<m,n>* matrix2){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float32,m,n>::multiply(matrix1,matrix2);
        }
        return false;
    }

    virtual bool copyFrom(edk::vector::MatrixDynamic<edk::float32>* matrix){
        if(matrix){
            return matrix->copyTo((edk::vector::MatrixDynamic<edk::float32>*)this);
        }
        return false;
    }

    virtual bool invertThis(){
        return  edk::vector::Matrix<edk::float32,m,n>::invertThis();
    }

    //print the matrix
    inline virtual bool cloneFrom(edk::vector::Matrixf32<m,n>* matrix){
        return  edk::vector::Matrix<edk::float32,m,n>::cloneFrom(matrix);
    }

protected:
    inline void printElement(edk::uint32 x,edk::uint32 y,edk::float32* value){
        printf("\n[%u][%u] == [%.2f]",x,y,(edk::float32)(*value));
    }
    inline void printElementX(edk::float32* value){
        printf("%.2f",(edk::float32)(*value));
    }
private:
    edk::classID classThis;
};
template <edk::uint64 m,edk::uint64 n>
class Matrixf64: public edk::vector::Matrix<edk::float64,m,n>{
public:
    Matrixf64(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~Matrixf64(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::Matrix<edk::float64,m,n>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
        }
        edk::vector::Matrix<edk::float64,m,n>::Destructor();
    }

    //set the matrix as identity
    inline virtual bool setIdentity(edk::float64 valueOne,edk::float64 valueZero){
        return edk::vector::Matrix<edk::float64,m,n>::setIdentity(valueOne,valueZero);
    }
    inline virtual bool setIdentity(){
        return edk::vector::Matrix<edk::float64,m,n>::setIdentity(1.f,0.f);
    }

    //test if a matrix is equal then other
    inline virtual bool isEqual(edk::vector::Matrixf64<m,n>* matrix){
        return  edk::vector::Matrix<edk::float64,m,n>::isEqual(matrix);
    }
    //add the matrix with another
    inline virtual bool add(edk::vector::Matrixf64<m,n>* matrix){
        return  edk::vector::Matrix<edk::float64,m,n>::add(matrix);
    }
    //sub the matrix with another
    inline virtual bool sub(edk::vector::Matrixf64<m,n>* matrix){
        return  edk::vector::Matrix<edk::float64,m,n>::sub(matrix);
    }

    //return true if can multiply
    inline virtual bool canMultiplyThisWithMatrix(edk::vector::Matrixf64<m,n>*){
        return this->canMultiplyMatrix;
    }
    inline virtual bool canMultiplyMatrixWithThis(edk::vector::Matrixf64<m,n>*){
        return this->canMultiplyMatrix;
    }
    inline virtual bool multiplyThisWithMatrix(edk::vector::Matrixf64<m,n>* matrix){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float64,m,n>::multiplyThisWithMatrix(matrix);
        }
        return false;
    }
    inline virtual bool multiplyMatrixWithThis(edk::vector::Matrixf64<m,n>* matrix){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float64,m,n>::multiplyMatrixWithThis(matrix);
        }
        return false;
    }
    //return true if can multiply
    inline virtual bool canMultiply(edk::vector::Matrixf64<m,n>*,edk::vector::Matrixf64<m,n>*){
        return this->canMultiplyMatrix;
    }
    inline virtual bool multiply(edk::vector::Matrixf64<m,n>* matrix1,edk::vector::Matrixf64<m,n>* matrix2){
        if(this->canMultiplyMatrix){
            return  edk::vector::Matrix<edk::float64,m,n>::multiply(matrix1,matrix2);
        }
        return false;
    }

    //print the matrix
    inline virtual bool cloneFrom(edk::vector::Matrixf64<m,n>* matrix){
        return  edk::vector::Matrix<edk::float64,m,n>::cloneFrom(matrix);
    }

protected:
    inline void printElement(edk::uint64 x,edk::uint64 y,edk::float64* value){
        printf("\n[%u][%u] == [%.2f]",x,y,(edk::float64)(*value));
    }
    inline void printElementX(edk::float64* value){
        printf("%.2f",(edk::float32)(*value));
    }
private:
    edk::classID classThis;
};
}//end namespace vector
}//end namespace edk

#endif // MATRIX_H
