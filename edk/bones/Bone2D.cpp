#include "Bone2D.h"

/*
Library Bone2D - Bones2D used in Edk Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

edk::bones::Bone2D::Bone2D(){
    this->vector = edk::vec2f32(0,1);
    this->angle = 0u;
    this->setIdentity(&this->mat);
    this->canDeleteBone=true;
}
edk::bones::Bone2D::Bone2D(edk::char8* name)
    : edk::Name(name){
    this->vector = edk::vec2f32(0,1);
    this->angle = 0u;
    this->canDeleteBone=true;
}
edk::bones::Bone2D::Bone2D(const char* name)
    : edk::Name(name){
    this->vector = edk::vec2f32(0,1);
    this->angle = 0u;
    this->canDeleteBone=true;
}

edk::bones::Bone2D::~Bone2D(){
    //
    if(this->canDeleteBone){
    this->cleanBone();
    }
    else{
        //cant delete animations
        this->animationAngle.cantDeleteGroup();
        this->animationPosition.cantDeleteGroup();
        this->canDeleteBone=true;
    }
    /*
    this->removeAllAnimationNamesThis();
    this->removeAllAnimations();
    this->removeAllConnectionObjects();
    this->removeAllNexts();
    */
}
//set the indentity matrix
bool edk::bones::Bone2D::setIdentity(edk::float32 mat[][3u][3u]){
    //test the mat
    if(mat){
        //then clean the matrix
        for(edk::uint8 x=0u;x<3u;x++){
            for(edk::uint8 y=0u;y<3u;y++){
                if(x==y){
                    mat[0u][x][y] = 1.f;
                }
                else{
                    mat[0u][x][y] = 0.f;
                }
            }
        }
        return true;
    }
    return false;
}
//copy the matrix
bool edk::bones::Bone2D::copyMatrix(edk::float32 mat[][3u][3u],edk::float32 dest[][3u][3u]){
    //test the mat
    if(mat && dest){
        //then clean the matrix
        for(edk::uint8 x=0u;x<3u;x++){
            for(edk::uint8 y=0u;y<3u;y++){
                dest[0u][x][y] = mat[0u][x][y];
            }
        }
        return true;
    }
    return false;
}
//multiply the matrix
bool edk::bones::Bone2D::multiplyMatrix(edk::float32 mat[][3u][3u],edk::float32 vec[][3u]){
    //test the mat
    if(mat && vec){
        edk::float32 temp[3];
        //we need 3 multiplicatons
        temp[0u] = (mat[0u][0u][0u] * vec[0u][0u])
                +
                (mat[0u][1u][0u] * vec[0u][1u])
                +
                (mat[0u][2u][0u] * vec[0u][2u])
                ;
        temp[1u] = (mat[0u][0u][1u] * vec[0u][0u])
                +
                (mat[0u][1u][1u] * vec[0u][1u])
                +
                (mat[0u][2u][1u] * vec[0u][2u])
                ;
        temp[2u] = (mat[0u][0u][2u] * vec[0u][0u])
                +
                (mat[0u][1u][2u] * vec[0u][1u])
                +
                (mat[0u][2u][2u] * vec[0u][2u])
                ;
        //Put all in the vertex
        vec[0u][0u] = temp[0u];
        vec[0u][1u] = temp[1u];
        vec[0u][2u] = temp[2u];
        return true;
    }
    return false;
}
//multiply the matrix
bool edk::bones::Bone2D::multiplyMatrix(edk::float32 mat1[][3u][3u],edk::float32 mat2[][3u][3u]){
    //test the mat
    if(mat1 && mat2){
        edk::float32 temp[3u][3u];
        temp[0u][0u] = (mat1[0u][0u][0u] * mat2[0u][0u][0u])
                +
                (mat1[0u][1u][0u] * mat2[0u][0u][1u])
                +
                (mat1[0u][2u][0u] * mat2[0u][0u][2u])
                ;
        temp[1u][0u] = (mat1[0u][0u][0u] * mat2[0u][1u][0u])
                +
                (mat1[0u][1u][0u] * mat2[0u][1u][1u])
                +
                (mat1[0u][2u][0u] * mat2[0u][1u][2u])
                ;
        temp[2u][0u] = (mat1[0u][0u][0u] * mat2[0u][2u][0u])
                +
                (mat1[0u][1u][0u] * mat2[0u][2u][1u])
                +
                (mat1[0u][2u][0u] * mat2[0u][2u][2u])
                ;
        //
        temp[0u][1u] = (mat1[0u][0u][1u] * mat2[0u][0u][0u])
                +
                (mat1[0u][1u][1u] * mat2[0u][0u][1u])
                +
                (mat1[0u][2u][1u] * mat2[0u][0u][2u])
                ;
        temp[1u][1u] = (mat1[0u][0u][1u] * mat2[0u][1u][0u])
                +
                (mat1[0u][1u][1u] * mat2[0u][1u][1u])
                +
                (mat1[0u][2u][1u] * mat2[0u][1u][2u])
                ;
        temp[2u][1u] = (mat1[0u][0u][1u] * mat2[0u][2u][0u])
                +
                (mat1[0u][1u][1u] * mat2[0u][2u][1u])
                +
                (mat1[0u][2u][1u] * mat2[0u][2u][2u])
                ;
        //
        temp[0u][2u] = (mat1[0u][0u][2u] * mat2[0u][0u][0u])
                +
                (mat1[0u][1u][2u] * mat2[0u][0u][1u])
                +
                (mat1[0u][2u][2u] * mat2[0u][0u][2u])
                ;
        temp[1u][2u] = (mat1[0u][0u][2u] * mat2[0u][1u][0u])
                +
                (mat1[0u][1u][2u] * mat2[0u][1u][1u])
                +
                (mat1[0u][2u][2u] * mat2[0u][1u][2u])
                ;
        temp[2u][2u] = (mat1[0u][0u][2u] * mat2[0u][2u][0u])
                +
                (mat1[0u][1u][2u] * mat2[0u][2u][1u])
                +
                (mat1[0u][2u][2u] * mat2[0u][2u][2u])
                ;
        //copy the temp to the mat2
        edk::bones::Bone2D::copyMatrix(&temp,mat2);
        return true;
    }
    return false;
}
//generate the translate matrix
bool edk::bones::Bone2D::generateTranslateMatrix(edk::vec2f32 position,edk::float32 mat[][3u][3u]){
    if(mat){
        //then clean the matrix
        edk::bones::Bone2D::setIdentity(mat);
        mat[0u][2u][0u] = position.x;
        mat[0u][2u][1u] = position.y;
        mat[0u][2u][2u] = 1.f;
        return true;
    }
    return false;
}
bool edk::bones::Bone2D::generateRotationMatrix(edk::float32 angle,edk::float32 mat[][3u][3u]){
    if(mat){
        //then clean the matrix
        edk::bones::Bone2D::setIdentity(mat);
        mat[0u][0u][0u] = edk::Math::getCosinFloat(angle);//cos
        mat[0u][1u][0u] = edk::Math::getSinFloat(angle)*-1.f;//-sin
        mat[0u][0u][1u] = edk::Math::getSinFloat(angle);//sin
        mat[0u][1u][1u] = edk::Math::getCosinFloat(angle);//cos
        return true;
    }
    return false;
}
bool edk::bones::Bone2D::generateScaleMatrix(edk::size2f32 size,edk::float32 mat[][3u][3u]){
    if(mat){
        //then clean the matrix
        edk::bones::Bone2D::setIdentity(mat);
        mat[0u][0u][0u] = size.width;
        mat[0u][1u][1u] = size.height;
        return true;
    }
    return false;
}

//TEMP print the matrix
void edk::bones::Bone2D::printMatrix(edk::float32 mat[3u][3u]){
    //then clean the matrix
    for(edk::uint8 y=0u;y<3u;y++){
        printf("\n[");
        for(edk::uint8 x=0u;x<3u;x++){
            printf(" %.2f "
                   ,mat[x][y]
                   );
        }
        printf("]");
    }
}
void edk::bones::Bone2D::printVector(edk::float32 mat[3u]){
    //then clean the matrix
    printf("\n[");
    for(edk::uint8 i=0u;i<3u;i++){
        printf(" %.2f "
               ,mat[i]
               );
    }
    printf("]");
}

//clean the bone
void edk::bones::Bone2D::cleanBone(){
    //this->removeAllAnimationNames();
    this->removeAllAnimations();
    this->removeAllNexts();
    this->deleteName();
    this->vector = edk::vec2f32(0,1);
    this->angle = 0u;
    this->setIdentity(&this->mat);
}

//add a bome to the nexts
bool edk::bones::Bone2D::addNext(edk::bones::Bone2D* next){
    //test the next
    if(next){
        //add the next
        return this->nexts.add(next);
    }
    return false;
}
//remove next
bool edk::bones::Bone2D::removeNext(edk::bones::Bone2D* next){
    if(next){
        return this->nexts.remove(next);
    }
    return false;
}
//remove all nexts
void edk::bones::Bone2D::removeAllNexts(){
    //test if have nexts
    this->nexts.clean();
}

//remove by the name
bool edk::bones::Bone2D::removeNextByName(const char* name){
    return this->removeNextByName((edk::char8*) name);
}
bool edk::bones::Bone2D::removeNextByName(edk::char8* name){
    if(name){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementByName(name);
        if(temp){
            return this->removeNext(temp);
        }
    }
    return false;
}

//add a connection object
bool edk::bones::Bone2D::addConnectionObject(edk::Object2DValues* object){
    if(object){
        return this->treeObjects.addObject(object);
    }
    return NULL;
}
//return the objects size
edk::uint32 edk::bones::Bone2D::getConnectionObjectSize(){
    return this->treeObjects.size();
}
//remove the connectionObject
bool edk::bones::Bone2D::removeConnectionObject(edk::Object2DValues* object){
    return this->treeObjects.removeObject(object);
}
//remove the connectionObject in the position
bool edk::bones::Bone2D::removeConnectionObjectInPosition(edk::uint32 position){
    return this->treeObjects.removeObjectInPosition(position);
}
//remove all connection objects
void edk::bones::Bone2D::removeAllConnectionObjects(){
    edk::uint32 size = this->treeObjects.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeObjects.removeObjectInPosition(0u);
    }
    this->treeObjects.clean();
}
//remove all animations
void edk::bones::Bone2D::removeAllAnimations(){
    this->animationPosition.cleanAnimations();
    this->animationAngle.cleanAnimations();
}

//update all animations
void edk::bones::Bone2D::updateAnimations(){
    this->updateAnimationsThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->updateAnimations();
    }
}
void edk::bones::Bone2D::updateAnimationsThis(){
    bool success;
    //test if is playng the animations
    if(this->animationPosition.isPlaying()){
        this->animationPosition.updateClockAnimation();

        edk::vec2f32 posTemp;
        posTemp.x = this->animationPosition.getClockX(&success);
        if(success){
            posTemp.y = this->animationPosition.getClockY(&success);
            if(success){
                //
                this->position = posTemp;
            }
        }

        /*
        printf(" position %.2f %.2f "
               ,this->position.x
               ,this->position.y
               );
*/
    }
    if(this->animationAngle.isPlaying()){
        this->animationAngle.updateClockAnimation();

        edk::float32 angleTemp = this->animationAngle.getClockX(&success);
        if(success){
            this->angle = angleTemp;
        }


        /*
        printf("  Angle %.2f "
               ,this->angle
               );
*/
    }
}
//scale animations
void edk::bones::Bone2D::scaleAnimations(edk::float32 scale){
    this->animationAngle.scaleFrames(scale);
    this->animationPosition.scaleFrames(scale);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->scaleAnimations(scale);
    }
}
void edk::bones::Bone2D::scaleAnimationsPosition(edk::float32 scale){
    this->animationPosition.scaleFrames(scale);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->scaleAnimationsPosition(scale);
    }
}
void edk::bones::Bone2D::scaleAnimationsAngle(edk::float32 scale){
    this->animationAngle.scaleFrames(scale);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->scaleAnimationsAngle(scale);
    }
}
//Speed
void edk::bones::Bone2D::setAnimationsSpeed(edk::float32 speed){
    this->animationAngle.setSpeed(speed);
    this->animationPosition.setSpeed(speed);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->setAnimationsSpeed(speed);
    }
}
void edk::bones::Bone2D::setAnimationPositionSpeed(edk::float32 speed){
    this->animationAngle.setSpeed(speed);
    this->animationPosition.setSpeed(speed);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->setAnimationPositionSpeed(speed);
    }
}
void edk::bones::Bone2D::setAnimationAngleSpeed(edk::float32 speed){
    this->animationAngle.setSpeed(speed);
    this->animationPosition.setSpeed(speed);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->setAnimationAngleSpeed(speed);
    }
}

//CONTROLS
//animation controllers
void edk::bones::Bone2D::playForward(){
    this->playForwardThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->playForward();
    }
}
void edk::bones::Bone2D::playForwardIn(edk::float32 second){
    this->playForwardInThis(second);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->playForwardIn(second);
    }
}
void edk::bones::Bone2D::playRewind(){
    this->playRewindThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->playRewind();
    }
}
void edk::bones::Bone2D::playRewindIn(edk::float32 second){
    this->playRewindInThis(second);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->playRewindIn(second);
    }
}
void edk::bones::Bone2D::pause(){
    this->pauseThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->pause();
    }
}
void edk::bones::Bone2D::pauseOn(){
    this->pauseOnThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->pauseOn();
    }
}
void edk::bones::Bone2D::pauseOff(){
    this->pauseOffThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->pauseOff();
    }
}
void edk::bones::Bone2D::stop(){
    this->stopThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->stop();
    }
}
//set loop
void edk::bones::Bone2D::setLoop(bool loop){
    this->setLoopThis(loop);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->setLoop(loop);
    }
}
void edk::bones::Bone2D::loopOn(){
    this->loopOnThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->loopOn();
    }
}
void edk::bones::Bone2D::loopOff(){
    this->loopOffThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->loopOff();
    }
}
void edk::bones::Bone2D::printFrames(){
    this->printFramesThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->printFrames();
    }
}
//ANIMATIONNAMES
bool edk::bones::Bone2D::addNewAnimationName(const char* name, edk::float32 start,edk::float32 end){
    bool ret =
            this->addNewAnimationNameThis(name,start,end);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->addNewAnimationName(name,start,end);
    }
    return ret;
}
bool edk::bones::Bone2D::addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret =
            this->addNewAnimationNameThis(name,start,end);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->addNewAnimationName(name,start,end);
    }
    return ret;
}
//select the animationName
bool edk::bones::Bone2D::selectAnimationName(const char* name){
    bool ret =
            this->selectAnimationNameThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->selectAnimationName(name);
    }
    return ret;
}
bool edk::bones::Bone2D::selectAnimationName(edk::char8* name){
    bool ret =
            this->selectAnimationNameThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->selectAnimationName(name);
    }
    return ret;
}
//test if have the animationName
bool edk::bones::Bone2D::haveAnimationName(const char* name){
    bool ret =
            this->haveAnimationNameThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->haveAnimationName(name);
    }
    return ret;
}
bool edk::bones::Bone2D::haveAnimationName(edk::char8* name){
    bool ret =
            this->haveAnimationNameThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->haveAnimationName(name);
    }
    return ret;
}
//Play the animationName
bool edk::bones::Bone2D::playNameForward(const char* name){
    bool ret =
            this->playNameForwardThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->playNameForward(name);
    }
    return ret;
}
bool edk::bones::Bone2D::playNameForward(edk::char8* name){
    bool ret =
            this->playNameForwardThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->playNameForward(name);
    }
    return ret;
}
bool edk::bones::Bone2D::playNameRewind(const char* name){
    bool ret =
            this->playNameRewindThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->playNameRewind(name);
    }
    return ret;
}
bool edk::bones::Bone2D::playNameRewind(edk::char8* name){
    bool ret =
            this->playNameRewindThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->playNameRewind(name);
    }
    return ret;
}
//remove the animationName
bool edk::bones::Bone2D::removeAnimationName(const char* name){
    bool ret =
            this->removeAnimationNameThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->removeAnimationName(name);
    }
    return ret;
}
bool edk::bones::Bone2D::removeAnimationName(edk::char8* name){
    bool ret =
            this->removeAnimationNameThis(name);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->removeAnimationName(name);
    }
    return ret;
}
void edk::bones::Bone2D::removeAllAnimationNames(){
    this->removeAllAnimationNamesThis();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->removeAllAnimationNames();
    }
}
//return if are playing
bool edk::bones::Bone2D::isPlaying(){
    if(this->isPlayingThis()) return true;
    else{
        //update the son's
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
            if(temp->isPlaying()) return true;
        }
    }
    return false;
}
//This Bone
void edk::bones::Bone2D::playForwardThis(){
    this->animationPosition.playForward();
    this->animationAngle.playForward();
}
void edk::bones::Bone2D::playForwardInThis(edk::float32 second){
    this->animationPosition.playForwardIn(second);
    this->animationAngle.playForwardIn(second);
}
void edk::bones::Bone2D::playRewindThis(){
    this->animationPosition.playRewind();
    this->animationAngle.playRewind();
}
void edk::bones::Bone2D::playRewindInThis(edk::float32 second){
    this->animationPosition.playRewindIn(second);
    this->animationAngle.playRewindIn(second);
}
void edk::bones::Bone2D::pauseThis(){
    this->animationPosition.pause();
    this->animationAngle.pause();
}
void edk::bones::Bone2D::pauseOnThis(){
    this->animationPosition.pauseOn();
    this->animationAngle.pauseOn();
}
void edk::bones::Bone2D::pauseOffThis(){
    this->animationPosition.pauseOff();
    this->animationAngle.pauseOff();
}
void edk::bones::Bone2D::stopThis(){
    this->animationPosition.stop();
    this->animationAngle.stop();
}
//set loop
void edk::bones::Bone2D::setLoopThis(bool loop){
    this->animationPosition.setLoop(loop);
    this->animationAngle.setLoop(loop);
}
void edk::bones::Bone2D::loopOnThis(){
    this->animationPosition.loopOn();
    this->animationAngle.loopOn();
}
void edk::bones::Bone2D::loopOffThis(){
    this->animationPosition.loopOff();
    this->animationAngle.loopOff();
}
void edk::bones::Bone2D::printFramesThis(){
    printf("\nPosition");
    this->animationPosition.printFrames();
    printf("\nAngle");
    this->animationAngle.printFrames();
}
//ANIMATIONNAMES
bool edk::bones::Bone2D::addNewAnimationNameThis(const char* name, edk::float32 start,edk::float32 end){
    bool ret=true;
    if(!this->animationPosition.addNewAnimationName(name,start,end)) ret=false;
    if(!this->animationAngle.addNewAnimationName(name,start,end)) ret=false;
    return ret;
}
bool edk::bones::Bone2D::addNewAnimationNameThis(edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=true;
    if(!this->animationPosition.addNewAnimationName(name,start,end)) ret=false;
    if(!this->animationAngle.addNewAnimationName(name,start,end)) ret=false;
    return ret;
}
//select the animationName
bool edk::bones::Bone2D::selectAnimationNameThis(const char* name){
    bool ret=true;
    if(!this->animationPosition.selectAnimationName(name)) ret=false;
    if(!this->animationAngle.selectAnimationName(name)) ret=false;
    return ret;
}
bool edk::bones::Bone2D::selectAnimationNameThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.selectAnimationName(name)) ret=false;
    if(!this->animationAngle.selectAnimationName(name)) ret=false;
    return ret;
}
//test if have the animationName
bool edk::bones::Bone2D::haveAnimationNameThis(const char* name){
    bool ret=true;
    if(!this->animationPosition.haveAnimationName(name)) ret=false;
    if(!this->animationAngle.haveAnimationName(name)) ret=false;
    return ret;
}
bool edk::bones::Bone2D::haveAnimationNameThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.haveAnimationName(name)) ret=false;
    if(!this->animationAngle.haveAnimationName(name)) ret=false;
    return ret;
}
//Play the animationName
bool edk::bones::Bone2D::playNameForwardThis(const char* name){
    bool ret=true;
    if(!this->animationPosition.playNameForward(name)) ret=false;
    if(!this->animationAngle.playNameForward(name)) ret=false;
    return ret;
}
bool edk::bones::Bone2D::playNameForwardThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.playNameForward(name)) ret=false;
    if(!this->animationAngle.playNameForward(name)) ret=false;
    return ret;
}
bool edk::bones::Bone2D::playNameRewindThis(const char* name){
    bool ret=true;
    if(!this->animationPosition.playNameRewind(name)) ret=false;
    if(!this->animationAngle.playNameRewind(name)) ret=false;
    return ret;
}
bool edk::bones::Bone2D::playNameRewindThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.playNameRewind(name)) ret=false;
    if(!this->animationAngle.playNameRewind(name)) ret=false;
    return ret;
}
//remove the animationName
bool edk::bones::Bone2D::removeAnimationNameThis(const char* name){
    bool ret=true;
    if(!this->animationPosition.removeAnimationName(name)) ret=false;
    if(!this->animationAngle.removeAnimationName(name)) ret=false;
    return ret;
}
bool edk::bones::Bone2D::removeAnimationNameThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.removeAnimationName(name)) ret=false;
    if(!this->animationAngle.removeAnimationName(name)) ret=false;
    return ret;
}
void edk::bones::Bone2D::removeAllAnimationNamesThis(){
    this->animationPosition.cleanAnimationNames();
    this->animationAngle.cleanAnimationNames();
}

//return if are playing
bool edk::bones::Bone2D::isPlayingThis(){
    bool ret=false;
    if(this->animationPosition.isPlaying()) ret=true;
    if(this->animationAngle.isPlaying()) ret=true;
    return ret;
}

//return the size of the nexts
edk::uint32 edk::bones::Bone2D::getNextsSize(){
    return this->nexts.size();
}

//return the next in position
edk::bones::Bone2D* edk::bones::Bone2D::getNextInPosition(edk::uint32 position){
    //test if have the position
    if(position<this->nexts.size()){
        return (edk::bones::Bone2D*)this->nexts.getElementInPosition(position);
    }
    return NULL;
}

void edk::bones::Bone2D::print(){
    printf("\n%s position %.2f %.2f end %.2f %.2f angle %.2f"
           ,this->name()
           ,this->position.x
           ,this->position.y
           ,this->vector.x
           ,this->vector.y
           ,this->angle
           );
    //draw the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->print();
    }
}
//draw the boneLine
void edk::bones::Bone2D::draw(){
    //    printf("Angle == %.2f  ",this->angle);
    //    printf("position %.2f %.2f ",this->position.x,this->position.y);

    //edk::GU::guTranslate2f32(this->position);
    edk::GU::guTranslate2f32(this->position.x,this->position.y);
    edk::GU::guRotateYf32(this->angle);

    edk::GU::guBegin(GU_LINES);
    //edk::GU::guVertex2f32(this->position.x,this->position.y);
    edk::GU::guVertex2f32(0,0);
    edk::GU::guVertex2f32(this->vector.x,this->vector.y);
    edk::GU::guEnd();

    //draw the line
    //edk::GU::guTranslate2f32(this->vector);
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->draw();
    }

    edk::GU::guRotateYf32(this->angle*-1.f);
    edk::GU::guTranslate2f32(this->position*-1.f);
}
//update the objects
void edk::bones::Bone2D::updateObjects(edk::float32 angle,edk::size2f32 size,edk::float32 mat[][3u][3u],edk::float32 angleRemove,edk::float32 angleMultiply){
    angle+=this->angle*angleMultiply;
    //rotate de position
    edk::float32 vecPos[3u];
    vecPos[0u] = this->position.x;
    vecPos[1u] = this->position.y;
    vecPos[2u] = 1.f;


    //test the matrix
    if(mat){
        //rotate the bone position as the bone father
        edk::bones::Bone2D::multiplyMatrix(mat,&vecPos);
    }

    edk::vec2f32 posTemp;
    posTemp.x = vecPos[0u];
    posTemp.y = vecPos[1u];

    //TRANSLATE AND ROTATE DE BONE POSITION
    edk::float32 translate[3u][3u];
    edk::bones::Bone2D::generateTranslateMatrix(posTemp,&translate);
    //generate matrix
    edk::float32 rotate[3u][3u];
    edk::bones::Bone2D::generateRotationMatrix(angle,&rotate);
    //generate scale
    edk::float32 scale[3u][3u];
    edk::bones::Bone2D::generateScaleMatrix(size,&scale);

    //create a new matrix
    edk::float32 newMat[3u][3u];
    edk::bones::Bone2D::setIdentity(&newMat);

    //multiply the scale matrix
    edk::bones::Bone2D::multiplyMatrix(&scale,&newMat);
    //multiply the rotatio matrix
    edk::bones::Bone2D::multiplyMatrix(&rotate,&newMat);
    //multiply the translation matrix
    edk::bones::Bone2D::multiplyMatrix(&translate,&newMat);

    //set the tree angle and matrix
    this->treeObjects.setMatrix(&newMat);
    this->treeObjects.setAngle(angle);
    this->treeObjects.setAngleRemove(angleRemove);
    this->treeObjects.setAngleMultiply(angleMultiply);

    this->treeObjects.setScale(size);
    this->treeObjects.update();

    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->updateObjects(angle,size,&newMat,angleRemove,angleMultiply);
    }
}
//calculate the bone point in the world
edk::vec2f32 edk::bones::Bone2D::getWorldVector(edk::bones::Bone2D* bone,bool* found,edk::float32 angle,edk::size2f32 size,edk::float32 mat[][3u][3u]){

    angle+=this->angle;
    //rotate de position
    edk::float32 vecPos[3u];
    vecPos[0u] = this->position.x;
    vecPos[1u] = this->position.y;
    vecPos[2u] = 1.f;


    //test the matrix
    if(mat){
        //rotate the bone position as the bone father
        edk::bones::Bone2D::multiplyMatrix(mat,&vecPos);
    }

    edk::vec2f32 posTemp;
    posTemp.x = vecPos[0u];
    posTemp.y = vecPos[1u];

    //TRANSLATE AND ROTATE DE BONE POSITION
    edk::float32 translate[3u][3u];
    edk::bones::Bone2D::generateTranslateMatrix(posTemp,&translate);
    //generate matrix
    edk::float32 rotate[3u][3u];
    edk::bones::Bone2D::generateRotationMatrix(angle,&rotate);
    //generate scale
    edk::float32 scale[3u][3u];
    edk::bones::Bone2D::generateScaleMatrix(size,&scale);

    //create a new matrix
    edk::float32 newMat[3u][3u];
    edk::bones::Bone2D::setIdentity(&newMat);

    //multiply the rotatio matrix
    edk::bones::Bone2D::multiplyMatrix(&rotate,&newMat);
    //multiply the scale matrix
    edk::bones::Bone2D::multiplyMatrix(&scale,&newMat);
    //multiply the translation matrix
    edk::bones::Bone2D::multiplyMatrix(&translate,&newMat);

    edk::vec2f32 ret(0,0);

    //test if find the bone
    if(bone){
        if(bone == this){

            edk::float32 vec[3u];
            //copy the position to the vector
            vec[0u] = this->vector.x;
            vec[1u] = this->vector.y;
            vec[2u] = 1.f;

            //multiply for the matrix
            edk::bones::Bone2D::multiplyMatrix(&newMat,&vec);

            //return the point
            ret.x = vec[0u];
            ret.y = vec[1u];

            *found=true;

            return ret;
        }
    }
    else{
        return ret;
    }

    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        ret = temp->getWorldVector(bone,found,angle,size,&newMat);
        if(*found) return ret;
    }
    ret.x=0.f;
    ret.y=0.f;
    return ret;
}
//calculate the IK with a point in the world
edk::vec2f32 edk::bones::Bone2D::calculateInverseKinematic(edk::bones::Bone2D* bone,
                                                           bool* found,
                                                           edk::vec2f32 worldPoint,
                                                           edk::uint32 limit,
                                                           edk::uint32* count,
                                                           edk::float32 angle,
                                                           edk::size2f32 size,
                                                           edk::float32 mat[][3u][3u]
){
    edk::float32 saveAngle = angle;
    edk::size2f32 saveSize = size;

    angle+=this->angle;
    //rotate de position
    edk::float32 vecPos[3u];
    vecPos[0u] = this->position.x;
    vecPos[1u] = this->position.y;
    vecPos[2u] = 1.f;


    //test the matrix
    if(mat){
        //rotate the bone position as the bone father
        edk::bones::Bone2D::multiplyMatrix(mat,&vecPos);
    }

    edk::vec2f32 posTemp;
    posTemp.x = vecPos[0u];
    posTemp.y = vecPos[1u];
    /*
    printf("\nPosTemp %.2f %.2f angle %.2f scale %.2f %.2f"
           ,posTemp.x
           ,posTemp.y
           ,angle
           ,size.width
           ,size.height
           );fflush(stdout);
*/
    //TRANSLATE AND ROTATE DE BONE POSITION
    edk::float32 translate[3u][3u];
    edk::bones::Bone2D::generateTranslateMatrix(posTemp,&translate);
    //generate matrix
    edk::float32 rotate[3u][3u];
    edk::bones::Bone2D::generateRotationMatrix(angle,&rotate);
    //generate scale
    edk::float32 scale[3u][3u];
    edk::bones::Bone2D::generateScaleMatrix(size,&scale);

    //create a new matrix
    edk::float32 newMat[3u][3u];
    edk::bones::Bone2D::setIdentity(&newMat);

    //multiply the rotatio matrix
    edk::bones::Bone2D::multiplyMatrix(&rotate,&newMat);
    //multiply the scale matrix
    edk::bones::Bone2D::multiplyMatrix(&scale,&newMat);
    //multiply the translation matrix
    edk::bones::Bone2D::multiplyMatrix(&translate,&newMat);

    edk::vec2f32 ret(0,0);

    //test if find the bone
    if(bone){
        if(bone == this){
            *found=true;
            *count=0u;
        }
    }
    else{
        return ret;
    }

    if(!*found){
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
            ret = temp->calculateInverseKinematic(bone,found,worldPoint,limit,count,angle,size,&newMat);
            if(*found) break;
        }
    }

    if(*found){
        bool foundVector = false;
        if(*count<limit){
            //
            //printf("\nCalculate");fflush(stdout);

            //load the world vector
            edk::vec2f32 point = worldPoint - posTemp;
            edk::vec2f32 worldVector = this->getWorldVector(bone,&foundVector,saveAngle,saveSize,mat);
            edk::vec2f32 boneVector = worldVector - posTemp;
            /*
            printf("\nWorldPoint %.2f %.2f Point %.2f %.2f worldVector %.2f %.2f boneVector %.2f %.2f posTemp %.2f %.2f"
                   ,worldPoint.x
                   ,worldPoint.y
                   ,point.x
                   ,point.y
                   ,worldVector.x
                   ,worldVector.y
                   ,boneVector.x
                   ,boneVector.y
                   ,posTemp.x
                   ,posTemp.y
                   );fflush(stdout);
*/
            //get the angle between the two vectors
            edk::float32 rotateAngle = edk::Math::getAngle2f(point) - edk::Math::getAngle2f(boneVector);
            /*
            printf(" rotate %.2f"
                   ,rotateAngle
                   );fflush(stdout);
*/
            this->angle+=rotateAngle;
            if(this->angle<0.f) this->angle+=360.f;
            if(this->angle>360.f) this->angle-=360.f;
            *count+=1u;
        }
    }

    ret.x=0.f;
    ret.y=0.f;
    return ret;
}
void edk::bones::Bone2D::cantDelete(){
    edk::Name::cantDelete();
    this->canDeleteBone = false;
}
