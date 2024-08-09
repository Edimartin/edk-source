#include "Bone2D.h"

/*
Library Bone2D - Bones2D used in Edk Game Engine
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

#define edkIKAngleLimit 0.1f

edk::bones::Bone2D::Bone2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::bones::Bone2D::Bone2D(edk::char8* name)
    : edk::Name(name){
    this->classThis=NULL;edkEnd();
    this->Constructor(name,false);edkEnd();
}
edk::bones::Bone2D::Bone2D(const edk::char8* name)
    : edk::Name(name){
    this->classThis=NULL;edkEnd();
    this->Constructor(name,false);edkEnd();
}

edk::bones::Bone2D::~Bone2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->cleanBone();edkEnd();
        /*
    this->removeAllAnimationNamesThis();edkEnd();
    this->removeAllAnimations();edkEnd();
    this->removeAllConnectionObjects();edkEnd();
    this->removeAllNexts();edkEnd();
    */
    }
}

void edk::bones::Bone2D::Constructor(bool runFather){
    if(runFather){
        edk::Name::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->animationAngle.Constructor();edkEnd();
        this->animationPosition.Constructor();edkEnd();
        this->nexts.Constructor();edkEnd();
        this->treeObjects.Constructor();edkEnd();
        this->matrixTranslate.Constructor();edkEnd();
        this->matrixRotate.Constructor();edkEnd();
        this->matrixTransform.Constructor();edkEnd();
        this->matrixPosition.Constructor();edkEnd();
        this->matrixPosition.createMatrix(3u,3u);

        this->vector = edk::vec2f32(0,1);edkEnd();
        this->angle = 0u;edkEnd();
        this->ikPosition=0.f;edkEnd();
        this->setIdentity(&this->mat);edkEnd();
    }
}
void edk::bones::Bone2D::Constructor(edk::char8* name,bool runFather){
    if(runFather){
        edk::Name::Constructor(name);edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->animationAngle.Constructor();edkEnd();
        this->animationPosition.Constructor();edkEnd();
        this->nexts.Constructor();edkEnd();
        this->treeObjects.Constructor();edkEnd();
        this->matrixTranslate.Constructor();edkEnd();
        this->matrixRotate.Constructor();edkEnd();
        this->matrixTransform.Constructor();edkEnd();
        this->matrixPosition.Constructor();edkEnd();
        this->matrixPosition.createMatrix(3u,3u);

        this->vector = edk::vec2f32(0,1);edkEnd();
        this->angle = 0u;edkEnd();
        this->ikPosition=0.f;edkEnd();
    }
}
void edk::bones::Bone2D::Constructor(const edk::char8* name,bool runFather){
    if(runFather){
        edk::Name::Constructor(name);edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->animationAngle.Constructor();edkEnd();
        this->animationPosition.Constructor();edkEnd();
        this->nexts.Constructor();edkEnd();
        this->treeObjects.Constructor();edkEnd();
        this->matrixTranslate.Constructor();edkEnd();
        this->matrixRotate.Constructor();edkEnd();
        this->matrixTransform.Constructor();edkEnd();
        this->matrixPosition.Constructor();edkEnd();
        this->matrixPosition.createMatrix(3u,3u);

        this->vector = edk::vec2f32(0,1);edkEnd();
        this->angle = 0u;edkEnd();
        this->ikPosition=0.f;edkEnd();
    }
}

//set the indentity matrix
bool edk::bones::Bone2D::setIdentity(edk::float32 mat[][3u][3u]){
    //test the mat
    if(mat){
        //then clean the matrix
        for(edk::uint8 x=0u;x<3u;x++){
            for(edk::uint8 y=0u;y<3u;y++){
                if(x==y){
                    mat[0u][x][y] = 1.f;edkEnd();
                }
                else{
                    mat[0u][x][y] = 0.f;edkEnd();
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
                dest[0u][x][y] = mat[0u][x][y];edkEnd();
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
        edk::float32 temp[3];edkEnd();
        //we need 3 multiplicatons
        temp[0u] = (mat[0u][0u][0u] * vec[0u][0u])
                +
                (mat[0u][1u][0u] * vec[0u][1u])
                +
                (mat[0u][2u][0u] * vec[0u][2u])
                ;edkEnd();
        temp[1u] = (mat[0u][0u][1u] * vec[0u][0u])
                +
                (mat[0u][1u][1u] * vec[0u][1u])
                +
                (mat[0u][2u][1u] * vec[0u][2u])
                ;edkEnd();
        temp[2u] = (mat[0u][0u][2u] * vec[0u][0u])
                +
                (mat[0u][1u][2u] * vec[0u][1u])
                +
                (mat[0u][2u][2u] * vec[0u][2u])
                ;edkEnd();
        //Put all in the vertex
        vec[0u][0u] = temp[0u];edkEnd();
        vec[0u][1u] = temp[1u];edkEnd();
        vec[0u][2u] = temp[2u];edkEnd();
        return true;
    }
    return false;
}
//multiply the matrix
bool edk::bones::Bone2D::multiplyMatrix(edk::float32 mat1[][3u][3u],edk::float32 mat2[][3u][3u]){
    //test the mat
    if(mat1 && mat2){
        edk::float32 temp[3u][3u];edkEnd();
        temp[0u][0u] = (mat1[0u][0u][0u] * mat2[0u][0u][0u])
                +
                (mat1[0u][1u][0u] * mat2[0u][0u][1u])
                +
                (mat1[0u][2u][0u] * mat2[0u][0u][2u])
                ;edkEnd();
        temp[1u][0u] = (mat1[0u][0u][0u] * mat2[0u][1u][0u])
                +
                (mat1[0u][1u][0u] * mat2[0u][1u][1u])
                +
                (mat1[0u][2u][0u] * mat2[0u][1u][2u])
                ;edkEnd();
        temp[2u][0u] = (mat1[0u][0u][0u] * mat2[0u][2u][0u])
                +
                (mat1[0u][1u][0u] * mat2[0u][2u][1u])
                +
                (mat1[0u][2u][0u] * mat2[0u][2u][2u])
                ;edkEnd();
        //
        temp[0u][1u] = (mat1[0u][0u][1u] * mat2[0u][0u][0u])
                +
                (mat1[0u][1u][1u] * mat2[0u][0u][1u])
                +
                (mat1[0u][2u][1u] * mat2[0u][0u][2u])
                ;edkEnd();
        temp[1u][1u] = (mat1[0u][0u][1u] * mat2[0u][1u][0u])
                +
                (mat1[0u][1u][1u] * mat2[0u][1u][1u])
                +
                (mat1[0u][2u][1u] * mat2[0u][1u][2u])
                ;edkEnd();
        temp[2u][1u] = (mat1[0u][0u][1u] * mat2[0u][2u][0u])
                +
                (mat1[0u][1u][1u] * mat2[0u][2u][1u])
                +
                (mat1[0u][2u][1u] * mat2[0u][2u][2u])
                ;edkEnd();
        //
        temp[0u][2u] = (mat1[0u][0u][2u] * mat2[0u][0u][0u])
                +
                (mat1[0u][1u][2u] * mat2[0u][0u][1u])
                +
                (mat1[0u][2u][2u] * mat2[0u][0u][2u])
                ;edkEnd();
        temp[1u][2u] = (mat1[0u][0u][2u] * mat2[0u][1u][0u])
                +
                (mat1[0u][1u][2u] * mat2[0u][1u][1u])
                +
                (mat1[0u][2u][2u] * mat2[0u][1u][2u])
                ;edkEnd();
        temp[2u][2u] = (mat1[0u][0u][2u] * mat2[0u][2u][0u])
                +
                (mat1[0u][1u][2u] * mat2[0u][2u][1u])
                +
                (mat1[0u][2u][2u] * mat2[0u][2u][2u])
                ;edkEnd();
        //copy the temp to the mat2
        edk::bones::Bone2D::copyMatrix(&temp,mat2);edkEnd();
        return true;
    }
    return false;
}
//generate the translate matrix
bool edk::bones::Bone2D::generateTranslateMatrix(edk::vec2f32 position,edk::float32 mat[][3u][3u]){
    if(mat){
        //then clean the matrix
        edk::bones::Bone2D::setIdentity(mat);edkEnd();
        mat[0u][2u][0u] = position.x;edkEnd();
        mat[0u][2u][1u] = position.y;edkEnd();
        mat[0u][2u][2u] = 1.f;edkEnd();
        return true;
    }
    return false;
}
bool edk::bones::Bone2D::generateRotationMatrix(edk::float32 angle,edk::float32 mat[][3u][3u]){
    if(mat){
        //then clean the matrix
        edk::bones::Bone2D::setIdentity(mat);edkEnd();
        mat[0u][0u][0u] = edk::Math::getCosin(angle);edkEnd();//cos
        mat[0u][1u][0u] = edk::Math::getSin(angle)*-1.f;edkEnd();//-sin
        mat[0u][0u][1u] = edk::Math::getSin(angle);edkEnd();//sin
        mat[0u][1u][1u] = edk::Math::getCosin(angle);edkEnd();//cos
        return true;
    }
    return false;
}
bool edk::bones::Bone2D::generateScaleMatrix(edk::size2f32 size,edk::float32 mat[][3u][3u]){
    if(mat){
        //then clean the matrix
        edk::bones::Bone2D::setIdentity(mat);edkEnd();
        mat[0u][0u][0u] = size.width;edkEnd();
        mat[0u][1u][1u] = size.height;edkEnd();
        return true;
    }
    return false;
}

//TEMP print the matrix
void edk::bones::Bone2D::printMatrix(edk::float32 mat[3u][3u]){
    //then clean the matrix
    for(edk::uint8 y=0u;y<3u;y++){
        printf("\n[");edkEnd();
        for(edk::uint8 x=0u;x<3u;x++){
            printf(" %.2f "
                   ,mat[x][y]
                   );edkEnd();
        }
        printf("]");edkEnd();
    }
}
void edk::bones::Bone2D::printVector(edk::float32 mat[3u]){
    //then clean the matrix
    printf("\n[");edkEnd();
    for(edk::uint8 i=0u;i<3u;i++){
        printf(" %.2f "
               ,mat[i]
               );edkEnd();
    }
    printf("]");edkEnd();
}

//clean the bone
void edk::bones::Bone2D::cleanBone(){
    //this->removeAllAnimationNames();edkEnd();
    this->removeAllAnimations();edkEnd();
    this->removeAllNexts();edkEnd();
    this->deleteName();edkEnd();
    this->vector = edk::vec2f32(0,1);edkEnd();
    this->angle = 0u;edkEnd();
    this->setIdentity(&this->mat);edkEnd();
}

//add a bome to the nexts
bool edk::bones::Bone2D::addNext(edk::bones::Bone2D* next){
    //test the next
    if(next){
        //add the next
        return this->nexts.add(next);edkEnd();
    }
    return false;
}
//remove next
bool edk::bones::Bone2D::removeNext(edk::bones::Bone2D* next){
    if(next){
        return this->nexts.remove(next);edkEnd();
    }
    return false;
}
//remove all nexts
void edk::bones::Bone2D::removeAllNexts(){
    //test if have nexts
    this->nexts.clean();edkEnd();
}

//remove by the name
bool edk::bones::Bone2D::removeNextByName(const edk::char8* name){
    return this->removeNextByName((edk::char8*) name);edkEnd();
}
bool edk::bones::Bone2D::removeNextByName(edk::char8* name){
    if(name){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementByName(name);edkEnd();
        if(temp){
            return this->removeNext(temp);edkEnd();
        }
    }
    return false;
}

//add a connection object
bool edk::bones::Bone2D::addConnectionObject(edk::Object2DValues* object){
    if(object){
        return this->treeObjects.addObject(object);edkEnd();
    }
    return NULL;
}
//return the objects size
edk::uint32 edk::bones::Bone2D::getConnectionObjectSize(){
    return this->treeObjects.size();edkEnd();
}
//remove the connectionObject
bool edk::bones::Bone2D::removeConnectionObject(edk::Object2DValues* object){
    return this->treeObjects.removeObject(object);edkEnd();
}
//remove the connectionObject in the position
bool edk::bones::Bone2D::removeConnectionObjectInPosition(edk::uint32 position){
    return this->treeObjects.removeObjectInPosition(position);edkEnd();
}
//remove all connection objects
void edk::bones::Bone2D::removeAllConnectionObjects(){
    edk::uint32 size = this->treeObjects.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeObjects.removeObjectInPosition(0u);edkEnd();
    }
    this->treeObjects.clean();edkEnd();
}
//remove all animations
void edk::bones::Bone2D::removeAllAnimations(){
    this->animationPosition.cleanAnimations();edkEnd();
    this->animationAngle.cleanAnimations();edkEnd();
}

//update all animations
void edk::bones::Bone2D::updateAnimations(){
    this->updateAnimationsThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->updateAnimations();edkEnd();
    }
}
void edk::bones::Bone2D::updateAnimations(edk::float32 seconds){
    this->updateAnimationsThis(seconds);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->updateAnimations(seconds);edkEnd();
    }
}
void edk::bones::Bone2D::updateAnimationsThis(){
    //test if is playng the animations
    if(this->animationPosition.isPlaying()){
        this->animationPosition.updateClockAnimation();edkEnd();
        edk::vec2f32 posTemp;edkEnd();
        posTemp.x = this->animationPosition.getClockX();edkEnd();
        posTemp.y = this->animationPosition.getClockY();edkEnd();
        //
        this->position = posTemp;edkEnd();
    }
    if(this->animationAngle.isPlaying()){
        this->animationAngle.updateClockAnimation();edkEnd();

        edk::float32 angleTemp = this->animationAngle.getClockX();edkEnd();
        this->angle = angleTemp;edkEnd();
    }
}
void edk::bones::Bone2D::updateAnimationsThis(edk::float32 seconds){
    //test if is playng the animations
    if(this->animationPosition.isPlaying()){
        this->animationPosition.updateClockAnimation(seconds);edkEnd();
        edk::vec2f32 posTemp;edkEnd();
        posTemp.x = this->animationPosition.getClockX();edkEnd();
        posTemp.y = this->animationPosition.getClockY();edkEnd();
        //
        this->position = posTemp;edkEnd();
    }
    if(this->animationAngle.isPlaying()){
        this->animationAngle.updateClockAnimation(seconds);edkEnd();
        edk::float32 angleTemp = this->animationAngle.getClockX();edkEnd();
        this->angle = angleTemp;edkEnd();
    }
}
//scale animations
void edk::bones::Bone2D::scaleAnimations(edk::float32 scale){
    this->animationAngle.scaleFrames(scale);edkEnd();
    this->animationPosition.scaleFrames(scale);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->scaleAnimations(scale);edkEnd();
    }
}
void edk::bones::Bone2D::scaleAnimationsPosition(edk::float32 scale){
    this->animationPosition.scaleFrames(scale);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->scaleAnimationsPosition(scale);edkEnd();
    }
}
void edk::bones::Bone2D::scaleAnimationsAngle(edk::float32 scale){
    this->animationAngle.scaleFrames(scale);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->scaleAnimationsAngle(scale);edkEnd();
    }
}
//Speed
void edk::bones::Bone2D::setAnimationsSpeed(edk::float32 speed){
    this->animationAngle.setSpeed(speed);edkEnd();
    this->animationPosition.setSpeed(speed);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->setAnimationsSpeed(speed);edkEnd();
    }
}
void edk::bones::Bone2D::setAnimationPositionSpeed(edk::float32 speed){
    this->animationAngle.setSpeed(speed);edkEnd();
    this->animationPosition.setSpeed(speed);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->setAnimationPositionSpeed(speed);edkEnd();
    }
}
void edk::bones::Bone2D::setAnimationAngleSpeed(edk::float32 speed){
    this->animationAngle.setSpeed(speed);edkEnd();
    this->animationPosition.setSpeed(speed);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->setAnimationAngleSpeed(speed);edkEnd();
    }
}

//CONTROLS
//animation controllers
void edk::bones::Bone2D::playForward(){
    this->playForwardThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->playForward();edkEnd();
    }
}
void edk::bones::Bone2D::playForwardIn(edk::float32 second){
    this->playForwardInThis(second);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->playForwardIn(second);edkEnd();
    }
}
void edk::bones::Bone2D::playRewind(){
    this->playRewindThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->playRewind();edkEnd();
    }
}
void edk::bones::Bone2D::playRewindIn(edk::float32 second){
    this->playRewindInThis(second);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->playRewindIn(second);edkEnd();
    }
}
void edk::bones::Bone2D::pause(){
    this->pauseThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->pause();edkEnd();
    }
}
void edk::bones::Bone2D::pauseOn(){
    this->pauseOnThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->pauseOn();edkEnd();
    }
}
void edk::bones::Bone2D::pauseOff(){
    this->pauseOffThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->pauseOff();edkEnd();
    }
}
void edk::bones::Bone2D::stop(){
    this->stopThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->stop();edkEnd();
    }
}
//set loop
void edk::bones::Bone2D::setLoop(bool loop){
    this->setLoopThis(loop);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->setLoop(loop);edkEnd();
    }
}
void edk::bones::Bone2D::loopOn(){
    this->loopOnThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->loopOn();edkEnd();
    }
}
void edk::bones::Bone2D::loopOff(){
    this->loopOffThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->loopOff();edkEnd();
    }
}
void edk::bones::Bone2D::printFrames(){
    this->printFramesThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->printFrames();edkEnd();
    }
}
//ANIMATIONNAMES
bool edk::bones::Bone2D::addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret =
            this->addNewAnimationNameThis(name,start,end);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->addNewAnimationName(name,start,end);edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret =
            this->addNewAnimationNameThis(name,start,end);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->addNewAnimationName(name,start,end);edkEnd();
    }
    return ret;
}
//select the animationName
bool edk::bones::Bone2D::selectAnimationName(const edk::char8* name){
    bool ret =
            this->selectAnimationNameThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->selectAnimationName(name);edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::selectAnimationName(edk::char8* name){
    bool ret =
            this->selectAnimationNameThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->selectAnimationName(name);edkEnd();
    }
    return ret;
}
//test if have the animationName
bool edk::bones::Bone2D::haveAnimationName(const edk::char8* name){
    bool ret =
            this->haveAnimationNameThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->haveAnimationName(name);edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::haveAnimationName(edk::char8* name){
    bool ret =
            this->haveAnimationNameThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->haveAnimationName(name);edkEnd();
    }
    return ret;
}
//Play the animationName
bool edk::bones::Bone2D::playNameForward(const edk::char8* name){
    bool ret =
            this->playNameForwardThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->playNameForward(name);edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::playNameForward(edk::char8* name){
    bool ret =
            this->playNameForwardThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->playNameForward(name);edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::playNameRewind(const edk::char8* name){
    bool ret =
            this->playNameRewindThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->playNameRewind(name);edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::playNameRewind(edk::char8* name){
    bool ret =
            this->playNameRewindThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->playNameRewind(name);edkEnd();
    }
    return ret;
}
//remove the animationName
bool edk::bones::Bone2D::removeAnimationName(const edk::char8* name){
    bool ret =
            this->removeAnimationNameThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->removeAnimationName(name);edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::removeAnimationName(edk::char8* name){
    bool ret =
            this->removeAnimationNameThis(name);edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->removeAnimationName(name);edkEnd();
    }
    return ret;
}
void edk::bones::Bone2D::removeAllAnimationNames(){
    this->removeAllAnimationNamesThis();edkEnd();
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->removeAllAnimationNames();edkEnd();
    }
}
//return if are playing
bool edk::bones::Bone2D::isPlaying(){
    if(this->isPlayingThis()){
        return true;
    }
    else{
        //update the son's
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
            if(temp->isPlaying()){
                return true;
            }
        }
    }
    return false;
}
bool edk::bones::Bone2D::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);edkEnd();
}
bool edk::bones::Bone2D::isPlayingName(edk::char8* name){
    if(name){
        //update the son's
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
            if(temp->isPlayingName(name)){
                return true;
            }
        }
    }
    return false;
}
bool edk::bones::Bone2D::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);edkEnd();
}
bool edk::bones::Bone2D::wasPlayingName(edk::char8* name){
    if(name){
        //update the son's
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
            if(temp->wasPlayingName(name)){
                return true;
            }
        }
    }
    return false;
}
//This Bone
void edk::bones::Bone2D::playForwardThis(){
    this->animationPosition.playForward();edkEnd();
    this->animationAngle.playForward();edkEnd();
}
void edk::bones::Bone2D::playForwardInThis(edk::float32 second){
    this->animationPosition.playForwardIn(second);edkEnd();
    this->animationAngle.playForwardIn(second);edkEnd();
}
void edk::bones::Bone2D::playRewindThis(){
    this->animationPosition.playRewind();edkEnd();
    this->animationAngle.playRewind();edkEnd();
}
void edk::bones::Bone2D::playRewindInThis(edk::float32 second){
    this->animationPosition.playRewindIn(second);edkEnd();
    this->animationAngle.playRewindIn(second);edkEnd();
}
void edk::bones::Bone2D::pauseThis(){
    this->animationPosition.pause();edkEnd();
    this->animationAngle.pause();edkEnd();
}
void edk::bones::Bone2D::pauseOnThis(){
    this->animationPosition.pauseOn();edkEnd();
    this->animationAngle.pauseOn();edkEnd();
}
void edk::bones::Bone2D::pauseOffThis(){
    this->animationPosition.pauseOff();edkEnd();
    this->animationAngle.pauseOff();edkEnd();
}
void edk::bones::Bone2D::stopThis(){
    this->animationPosition.stop();edkEnd();
    this->animationAngle.stop();edkEnd();
}
//set loop
void edk::bones::Bone2D::setLoopThis(bool loop){
    this->animationPosition.setLoop(loop);edkEnd();
    this->animationAngle.setLoop(loop);edkEnd();
}
void edk::bones::Bone2D::loopOnThis(){
    this->animationPosition.loopOn();edkEnd();
    this->animationAngle.loopOn();edkEnd();
}
void edk::bones::Bone2D::loopOffThis(){
    this->animationPosition.loopOff();edkEnd();
    this->animationAngle.loopOff();edkEnd();
}
void edk::bones::Bone2D::printFramesThis(){
    printf("\nPosition");edkEnd();
    this->animationPosition.printFrames();edkEnd();
    printf("\nAngle");edkEnd();
    this->animationAngle.printFrames();edkEnd();
}
//ANIMATIONNAMES
bool edk::bones::Bone2D::addNewAnimationNameThis(const edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=true;edkEnd();
    if(!this->animationPosition.addNewAnimationName(name,start,end)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.addNewAnimationName(name,start,end)){
        ret=false;edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::addNewAnimationNameThis(edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=true;edkEnd();
    if(!this->animationPosition.addNewAnimationName(name,start,end)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.addNewAnimationName(name,start,end)){
        ret=false;edkEnd();
    }
    return ret;
}
//select the animationName
bool edk::bones::Bone2D::selectAnimationNameThis(const edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.selectAnimationName(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.selectAnimationName(name)){
        ret=false;edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::selectAnimationNameThis(edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.selectAnimationName(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.selectAnimationName(name)){
        ret=false;edkEnd();
    }
    return ret;
}
//test if have the animationName
bool edk::bones::Bone2D::haveAnimationNameThis(const edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.haveAnimationName(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.haveAnimationName(name)){
        ret=false;edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::haveAnimationNameThis(edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.haveAnimationName(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.haveAnimationName(name)){
        ret=false;edkEnd();
    }
    return ret;
}
//Play the animationName
bool edk::bones::Bone2D::playNameForwardThis(const edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.playNameForward(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.playNameForward(name)){
        ret=false;edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::playNameForwardThis(edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.playNameForward(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.playNameForward(name)){
        ret=false;edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::playNameRewindThis(const edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.playNameRewind(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.playNameRewind(name)){
        ret=false;edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::playNameRewindThis(edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.playNameRewind(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.playNameRewind(name)){
        ret=false;edkEnd();
    }
    return ret;
}
//remove the animationName
bool edk::bones::Bone2D::removeAnimationNameThis(const edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.removeAnimationName(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.removeAnimationName(name)){
        ret=false;edkEnd();
    }
    return ret;
}
bool edk::bones::Bone2D::removeAnimationNameThis(edk::char8* name){
    bool ret=true;edkEnd();
    if(!this->animationPosition.removeAnimationName(name)){
        ret=false;edkEnd();
    }
    if(!this->animationAngle.removeAnimationName(name)){
        ret=false;edkEnd();
    }
    return ret;
}
void edk::bones::Bone2D::removeAllAnimationNamesThis(){
    this->animationPosition.cleanAnimationNames();edkEnd();
    this->animationAngle.cleanAnimationNames();edkEnd();
}

//return if are playing
bool edk::bones::Bone2D::isPlayingThis(){
    bool ret=false;edkEnd();
    if(this->animationPosition.isPlaying()){
        ret=true;edkEnd();
    }
    if(this->animationAngle.isPlaying()){
        ret=true;edkEnd();
    }
    return ret;
}

//return the size of the nexts
edk::uint32 edk::bones::Bone2D::getNextsSize(){
    return this->nexts.size();edkEnd();
}

//return the next in position
edk::bones::Bone2D* edk::bones::Bone2D::getNextInPosition(edk::uint32 position){
    //test if have the position
    if(position<this->nexts.size()){
        return (edk::bones::Bone2D*)this->nexts.getElementInPosition(position);edkEnd();
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
           );edkEnd();
    //draw the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->print();edkEnd();
    }
}
//draw the boneLine
void edk::bones::Bone2D::draw(){
    //    printf("Angle == %.2f  ",this->angle);edkEnd();
    //    printf("position %.2f %.2f ",this->position.x,this->position.y);edkEnd();

    //edk::GU::guTranslate2f32(this->position);edkEnd();
    edk::GU::guTranslate2f32(this->position.x,this->position.y);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();

    edk::GU::guBegin(GU_LINES);edkEnd();
    //edk::GU::guVertex2f32(this->position.x,this->position.y);edkEnd();
    edk::GU::guVertex2f32(0,0);edkEnd();
    edk::GU::guVertex2f32(this->vector.x,this->vector.y);edkEnd();
    edk::GU::guEnd();edkEnd();

    //draw the line
    //edk::GU::guTranslate2f32(this->vector);edkEnd();
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->draw();edkEnd();
    }

    edk::GU::guRotateZf32(this->angle*-1.f);edkEnd();
    edk::GU::guTranslate2f32(this->position*-1.f);edkEnd();
}
void edk::bones::Bone2D::drawLines(){
    //    printf("Angle == %.2f  ",this->angle);edkEnd();
    //    printf("position %.2f %.2f ",this->position.x,this->position.y);edkEnd();

    //edk::GU::guTranslate2f32(this->position);edkEnd();
    edk::GU::guTranslate2f32(this->position.x,this->position.y);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();

    edk::GU::guBegin(GU_LINES);edkEnd();
    //edk::GU::guVertex2f32(this->position.x,this->position.y);edkEnd();
    edk::GU::guVertex2f32(0,0);edkEnd();
    edk::GU::guVertex2f32(this->vector.x,this->vector.y);edkEnd();
    edk::GU::guEnd();edkEnd();

    //draw the line
    //edk::GU::guTranslate2f32(this->vector);edkEnd();
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->drawLines();edkEnd();
    }

    edk::GU::guRotateZf32(this->angle*-1.f);edkEnd();
    edk::GU::guTranslate2f32(this->position*-1.f);edkEnd();
}
void edk::bones::Bone2D::drawLinesIK(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::vec2f32 pos;

    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){

        this->matrixPosition.setIdentity(1.f,0.f);edkEnd();

        //transform all the vertices
        if(this->matrixPosition.haveMatrix()){
            //
            this->matrixPosition.set(0u,0u,this->position.x);edkEnd();
            this->matrixPosition.set(0u,1u,this->position.y);edkEnd();
            this->matrixPosition.set(0u,2u,1.f);edkEnd();

            //multiply the matrix
            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

            pos.x = this->matrixPosition.getNoIF(0u,0u);edkEnd();
            pos.y = this->matrixPosition.getNoIF(0u,1u);edkEnd();

            //draw the line
            edk::GU::guVertex2f32(pos);edkEnd();
            edk::GU::guVertex2f32(this->ikPosition);edkEnd();
        }
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);edkEnd();

        //multiply the matrix by
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();

        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
            temp->drawLinesIK(&this->matrixTransform);edkEnd();
        }
    }
}
void edk::bones::Bone2D::drawPoints(edk::float32 scale){
    //    printf("Angle == %.2f  ",this->angle);edkEnd();
    //    printf("position %.2f %.2f ",this->position.x,this->position.y);edkEnd();

    edk::GU::guTranslate2f32(this->position.x,this->position.y);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();

    edk::GU::guBegin(GU_POLYGON);edkEnd();
    edk::GU::guVertex2f32(-scale,-scale);edkEnd();
    edk::GU::guVertex2f32(-scale,+scale);edkEnd();
    edk::GU::guVertex2f32(+scale,+scale);edkEnd();
    edk::GU::guVertex2f32(+scale,-scale);edkEnd();
    edk::GU::guEnd();edkEnd();

    //draw the line
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->drawPoints(scale);edkEnd();
    }

    edk::GU::guRotateZf32(this->angle*-1.f);edkEnd();
    edk::GU::guTranslate2f32(this->position*-1.f);edkEnd();
}
//update the objects
void edk::bones::Bone2D::updateObjects(edk::float32 angle,edk::size2f32 size,edk::float32 mat[][3u][3u],edk::float32 angleRemove,edk::float32 angleMultiply){
    angle+=this->angle*angleMultiply;edkEnd();
    //rotate de position
    edk::float32 vecPos[3u];edkEnd();
    vecPos[0u] = this->position.x;edkEnd();
    vecPos[1u] = this->position.y;edkEnd();
    vecPos[2u] = 1.f;edkEnd();


    //test the matrix
    if(mat){
        //rotate the bone position as the bone father
        edk::bones::Bone2D::multiplyMatrix(mat,&vecPos);edkEnd();
    }

    edk::vec2f32 posTemp;edkEnd();
    posTemp.x = vecPos[0u];edkEnd();
    posTemp.y = vecPos[1u];edkEnd();

    //TRANSLATE AND ROTATE DE BONE POSITION
    edk::float32 translate[3u][3u];edkEnd();
    edk::bones::Bone2D::generateTranslateMatrix(posTemp,&translate);edkEnd();
    //generate matrix
    edk::float32 rotate[3u][3u];edkEnd();
    edk::bones::Bone2D::generateRotationMatrix(angle,&rotate);edkEnd();
    //generate scale
    edk::float32 scale[3u][3u];edkEnd();
    edk::bones::Bone2D::generateScaleMatrix(size,&scale);edkEnd();

    //create a new matrix
    edk::float32 newMat[3u][3u];edkEnd();
    edk::bones::Bone2D::setIdentity(&newMat);edkEnd();

    //multiply the scale matrix
    edk::bones::Bone2D::multiplyMatrix(&scale,&newMat);edkEnd();
    //multiply the rotatio matrix
    edk::bones::Bone2D::multiplyMatrix(&rotate,&newMat);edkEnd();
    //multiply the translation matrix
    edk::bones::Bone2D::multiplyMatrix(&translate,&newMat);edkEnd();

    //set the tree angle and matrix
    this->treeObjects.setMatrix(&newMat);edkEnd();
    this->treeObjects.setAngle(angle);edkEnd();
    this->treeObjects.setAngleRemove(angleRemove);edkEnd();
    this->treeObjects.setAngleMultiply(angleMultiply);edkEnd();

    this->treeObjects.setScale(size);edkEnd();
    this->treeObjects.update();edkEnd();

    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        temp->updateObjects(angle,size,&newMat,angleRemove,angleMultiply);edkEnd();
    }
}
//calculate the bone point in the world
edk::vec2f32 edk::bones::Bone2D::getWorldVector(edk::bones::Bone2D* bone,bool* found,edk::float32 angle,edk::size2f32 size,edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::vec2f32 ret(0,0);edkEnd();
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){
        this->matrixPosition.setIdentity(1.f,0.f);

        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);edkEnd();

        //multiply the matrix by
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();

        //transform all the vertices
        if(this->matrixPosition.haveMatrix()){
            if(bone){
                if(bone == this){
                    //
                    this->matrixPosition.set(0u,0u,this->vector.x);edkEnd();
                    this->matrixPosition.set(0u,1u,this->vector.y);edkEnd();
                    this->matrixPosition.set(0u,2u,1.f);edkEnd();

                    //multiply the matrix
                    this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                    ret.x = this->matrixPosition.getNoIF(0u,0u);edkEnd();
                    ret.y = this->matrixPosition.getNoIF(0u,1u);edkEnd();

                    *found=true;edkEnd();

                    return ret;
                }
            }
            else{
                return ret;
            }
        }
    }

    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        ret = temp->getWorldVector(bone,found,angle,size,&this->matrixTransform);edkEnd();
        if(*found){
            return ret;
        }
    }
    ret.x=0.f;edkEnd();
    ret.y=0.f;edkEnd();
    return ret;
}
edk::vec2f32 edk::bones::Bone2D::getWorldPosition(edk::bones::Bone2D* bone,bool* found,edk::float32 angle,edk::size2f32 size,edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::vec2f32 ret(0,0);edkEnd();
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){

        this->matrixPosition.setIdentity(1.f,0.f);

        //transform all the vertices
        if(this->matrixPosition.haveMatrix()){
            if(bone){
                if(bone == this){
                    //
                    this->matrixPosition.set(0u,0u,this->position.x);edkEnd();
                    this->matrixPosition.set(0u,1u,this->position.y);edkEnd();
                    this->matrixPosition.set(0u,2u,1.f);edkEnd();

                    //multiply the matrix
                    this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                    ret.x = this->matrixPosition.getNoIF(0u,0u);edkEnd();
                    ret.y = this->matrixPosition.getNoIF(0u,1u);edkEnd();

                    *found=true;edkEnd();

                    return ret;
                }
            }
            else{
                return ret;
            }
        }
    }

    //generate transform matrices
    edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
    edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);edkEnd();

    //multiply the matrix by
    //translate
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
    //angle
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();

    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
        ret = temp->getWorldPosition(bone,found,angle,size,&this->matrixTransform);edkEnd();
        if(*found){
            return ret;
        }
    }
    ret.x=0.f;edkEnd();
    ret.y=0.f;edkEnd();
    return ret;
}
//calculate the IK with a point in the world
edk::vec2f32 edk::bones::Bone2D::calculateInverseKinematic(edk::bones::Bone2D* bone,
                                                           bool* found,
                                                           edk::vec2f32 worldPoint,
                                                           edk::uint32 limit,
                                                           edk::uint32* count,
                                                           edk::float32 angle,
                                                           edk::size2f32,
                                                           edk::vector::Matrixf32<3u,3u>* transformMat
                                                           ){
    edk::vec2f32 ret(0,0);edkEnd();
    edk::vec2f32 positionWorld(0,0);
    edk::float32 rotateAngle;
    edk::float32 angle1,angle2;
    if(this->matrixTransform.cloneFrom(transformMat)){
        //test if found the bone
        if(bone){
            if(bone == this){
                *found=true;edkEnd();
                *count=0u;

                edk::vector::Matrixf32<3u,3u>  matrixVector;
                matrixVector.cloneFrom(transformMat);

                edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);edkEnd();

                //multiply the matrix by
                //translate
                matrixVector.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
                //angle
                matrixVector.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();

                this->matrixPosition.setIdentity(1.f,0.f);

                //calculate the boneVector in the world
                this->matrixPosition.set(0u,0u,this->vector.x);edkEnd();
                this->matrixPosition.set(0u,1u,this->vector.y);edkEnd();
                this->matrixPosition.set(0u,2u,1.f);edkEnd();

                //multiply the matrix
                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&matrixVector);edkEnd();

                ret.x = this->matrixPosition.getNoIF(0u,0u);edkEnd();
                ret.y = this->matrixPosition.getNoIF(0u,1u);edkEnd();

                //get the bone worldPosition
                this->matrixPosition.setIdentity(1.f,0.f);
                //
                this->matrixPosition.set(0u,0u,0.f);edkEnd();
                this->matrixPosition.set(0u,1u,0.f);edkEnd();
                this->matrixPosition.set(0u,2u,1.f);edkEnd();

                //multiply the matrix
                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                positionWorld.x = this->matrixPosition.getNoIF(0u,0u);edkEnd();
                positionWorld.y = this->matrixPosition.getNoIF(0u,1u);edkEnd();

                angle1 = edk::Math::getAngle(worldPoint-positionWorld)-edk::Math::getAngle(ret-positionWorld);
                angle2 = edk::Math::getAngle(ret-positionWorld)-edk::Math::getAngle(worldPoint-positionWorld);

                //rotateAngle = edk::Math::getAngle(worldPoint-positionWorld)-edk::Math::getAngle(ret-positionWorld);
                rotateAngle = angle1;
/*
                printf("\n%u ret[%.2f] worldPoint[%.2f] rotateAngle[%.2f]",__LINE__
                       ,edk::Math::getAngle(ret-positionWorld)
                       ,edk::Math::getAngle(worldPoint-positionWorld)
                       ,rotateAngle
                       );fflush(stdout);
*/
                if(rotateAngle>360.f){
                    rotateAngle-=360.f;
                }
                if(rotateAngle<-360.f){
                    rotateAngle+=360.f;
                }

                if(rotateAngle>edkIKAngleLimit || rotateAngle<-edkIKAngleLimit){
                    this->angle+=rotateAngle;edkEnd();
                    if(this->angle<0.f){
                        this->angle+=360.f;edkEnd();
                    }
                    if(this->angle>360.f){
                        this->angle-=360.f;edkEnd();
                    }

                    //rotate the ret
                    ret = edk::Math::rotatePlus(ret - positionWorld,rotateAngle)+positionWorld;
                }
                this->ikPosition = ret;
                //increment the count
                *count+=1u;edkEnd();
                return ret;
            }
            else{
                if(!(*found)){
                    //generate transform matrices
                    edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
                    edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);edkEnd();

                    //multiply the matrix by
                    //translate
                    this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
                    //angle
                    this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();

                    //else search the selected bone
                    edk::uint32 size = this->nexts.size();
                    for(edk::uint32 i=0u;i<size;i++){
                        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);edkEnd();
                        ret = temp->calculateInverseKinematic(bone,found,worldPoint,limit,count,angle,size,&this->matrixTransform);edkEnd();
                        if(*found){
                            //rotate the angle
                            if(*count<limit){
                                //increment the count
                                *count+=1u;edkEnd();

                                this->matrixPosition.setIdentity(1.f,0.f);

                                //transform all the vertices
                                if(this->matrixPosition.haveMatrix()){
                                    //
                                    this->matrixPosition.set(0u,0u,0.f);edkEnd();
                                    this->matrixPosition.set(0u,1u,0.f);edkEnd();
                                    this->matrixPosition.set(0u,2u,1.f);edkEnd();

                                    //multiply the matrix
                                    this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                                    positionWorld.x = this->matrixPosition.getNoIF(0u,0u);edkEnd();
                                    positionWorld.y = this->matrixPosition.getNoIF(0u,1u);edkEnd();

                                    rotateAngle = edk::Math::getAngle(worldPoint-positionWorld)-edk::Math::getAngle(ret-positionWorld);
/*
                                    printf("\n%u ret[%.2f] worldPoint[%.2f] rotateAngle[%.2f]",__LINE__
                                           ,edk::Math::getAngle(ret-positionWorld)
                                           ,edk::Math::getAngle(worldPoint-positionWorld)
                                           ,rotateAngle
                                           );fflush(stdout);
*/
                                    if(rotateAngle>360.f){
                                        rotateAngle-=360.f;
                                    }
                                    if(rotateAngle<-360.f){
                                        rotateAngle+=360.f;
                                    }

                                    if(rotateAngle>edkIKAngleLimit || rotateAngle<-edkIKAngleLimit){
                                        this->angle+=rotateAngle;edkEnd();
                                        if(this->angle<0.f){
                                            this->angle+=360.f;edkEnd();
                                        }
                                        if(this->angle>360.f){
                                            this->angle-=360.f;edkEnd();
                                        }
                                        //rotate the ret
                                        ret = edk::Math::rotatePlus(ret - positionWorld,rotateAngle)+positionWorld;
                                    }
                                }
                            }
                            this->ikPosition = ret;
                            return ret;
                        }
                    }
                }
            }
        }
        else{
            this->ikPosition = ret;
            return ret;
        }
    }
    this->ikPosition = ret;
    return ret;
}
