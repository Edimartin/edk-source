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

#define edkIKAngleLimit 0.01f

edk::bones::Bone2D::Bone2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::bones::Bone2D::Bone2D(edk::char8* name)
    : edk::Name(name){
    this->classThis=NULL;
    this->Constructor(name);
}
edk::bones::Bone2D::Bone2D(const edk::char8* name)
    : edk::Name(name){
    this->classThis=NULL;
    this->Constructor(name);
}

edk::bones::Bone2D::~Bone2D(){
    this->Destructor();
}

void edk::bones::Bone2D::Constructor(){
    edk::Name::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->animationAngle.Constructor();
        this->animationPosition.Constructor();
        this->nexts.Constructor();
        this->treeObjects.Constructor();
        this->matrixTranslate.Constructor();
        this->matrixRotate.Constructor();
        this->matrixTransform.Constructor();
        this->matrixPosition.Constructor();
        this->matrixPosition.createMatrix(3u,3u);

        this->vector = edk::vec2f32(0,1);
        this->angle = 0u;
        this->ikPosition=0.f;
        this->setIdentity(&this->mat);
    }
}
void edk::bones::Bone2D::Constructor(edk::char8* name){
    edk::Name::Constructor(name);
    if(this->classThis!=this){
        this->classThis=this;

        this->animationAngle.Constructor();
        this->animationPosition.Constructor();
        this->nexts.Constructor();
        this->treeObjects.Constructor();
        this->matrixTranslate.Constructor();
        this->matrixRotate.Constructor();
        this->matrixTransform.Constructor();
        this->matrixPosition.Constructor();
        this->matrixPosition.createMatrix(3u,3u);

        this->vector = edk::vec2f32(0,1);
        this->angle = 0u;
        this->ikPosition=0.f;
    }
}
void edk::bones::Bone2D::Constructor(const edk::char8* name){
    edk::Name::Constructor(name);
    if(this->classThis!=this){
        this->classThis=this;

        this->animationAngle.Constructor();
        this->animationPosition.Constructor();
        this->nexts.Constructor();
        this->treeObjects.Constructor();
        this->matrixTranslate.Constructor();
        this->matrixRotate.Constructor();
        this->matrixTransform.Constructor();
        this->matrixPosition.Constructor();
        this->matrixPosition.createMatrix(3u,3u);

        this->vector = edk::vec2f32(0,1);
        this->angle = 0u;
        this->ikPosition=0.f;
    }
}
void edk::bones::Bone2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanBone();
        /*
    this->removeAllAnimationNamesThis();
    this->removeAllAnimations();
    this->removeAllConnectionObjects();
    this->removeAllNexts();
    */
    }
    edk::Name::Destructor();
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
        mat[0u][0u][0u] = edk::Math::getCosin(angle); //cos
        mat[0u][1u][0u] = edk::Math::getSin(angle)*-1.f; //-sin
        mat[0u][0u][1u] = edk::Math::getSin(angle); //sin
        mat[0u][1u][1u] = edk::Math::getCosin(angle); //cos
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

//calculate the lenght
edk::float32 edk::bones::Bone2D::calculateLenght(edk::bones::Bone2D* bone,edk::uint32 tail,edk::uint32* counter,bool* found){
    edk::float32 ret=0.f;
    if(bone){
        //test if find the bone
        if(bone == this){
            //
            *counter=1u;
            *found=true;
            return edk::Math::pythagoras(this->vector);
        }
        else{
            //else search another bone
            edk::uint32 size = this->nexts.size();
            for(edk::uint32 i=0u;i<size;i++){
                edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
                ret = temp->calculateLenght(bone,tail,counter,found);
                if(*found){
                    //found it
                    if(*counter<tail){
                        //increment the count
                        *counter+=1u;

                        ret+=edk::Math::pythagoras(this->vector);
                        *counter=1u;
                    }
                    break;
                }
            }
        }
    }
    return ret;
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
bool edk::bones::Bone2D::removeNextByName(const edk::char8* name){
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
void edk::bones::Bone2D::updateAnimations(edk::float32 seconds){
    this->updateAnimationsThis(seconds);
    //update the son's
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->updateAnimations(seconds);
    }
}
void edk::bones::Bone2D::updateAnimationsThis(){
    //test if is playng the animations
    if(this->animationPosition.isPlaying()){
        this->animationPosition.updateClockAnimation();
        edk::vec2f32 posTemp;
        posTemp.x = this->animationPosition.getClockX();
        posTemp.y = this->animationPosition.getClockY();
        //
        this->position = posTemp;
    }
    if(this->animationAngle.isPlaying()){
        this->animationAngle.updateClockAnimation();

        edk::float32 angleTemp = this->animationAngle.getClockX();
        this->angle = angleTemp;
    }
}
void edk::bones::Bone2D::updateAnimationsThis(edk::float32 seconds){
    //test if is playng the animations
    if(this->animationPosition.isPlaying()){
        this->animationPosition.updateClockAnimation(seconds);
        edk::vec2f32 posTemp;
        posTemp.x = this->animationPosition.getClockX();
        posTemp.y = this->animationPosition.getClockY();
        //
        this->position = posTemp;
    }
    if(this->animationAngle.isPlaying()){
        this->animationAngle.updateClockAnimation(seconds);
        edk::float32 angleTemp = this->animationAngle.getClockX();
        this->angle = angleTemp;
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
bool edk::bones::Bone2D::addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
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
bool edk::bones::Bone2D::selectAnimationName(const edk::char8* name){
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
bool edk::bones::Bone2D::haveAnimationName(const edk::char8* name){
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
bool edk::bones::Bone2D::playNameForward(const edk::char8* name){
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
bool edk::bones::Bone2D::playNameRewind(const edk::char8* name){
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
bool edk::bones::Bone2D::removeAnimationName(const edk::char8* name){
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
    if(this->isPlayingThis()){
        return true;
    }
    else{
        //update the son's
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
            if(temp->isPlaying()){
                return true;
            }
        }
    }
    return false;
}
bool edk::bones::Bone2D::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);
}
bool edk::bones::Bone2D::isPlayingName(edk::char8* name){
    if(name){
        //update the son's
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
            if(temp->isPlayingName(name)){
                return true;
            }
        }
    }
    return false;
}
bool edk::bones::Bone2D::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);
}
bool edk::bones::Bone2D::wasPlayingName(edk::char8* name){
    if(name){
        //update the son's
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
            if(temp->wasPlayingName(name)){
                return true;
            }
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
bool edk::bones::Bone2D::addNewAnimationNameThis(const edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=true;
    if(!this->animationPosition.addNewAnimationName(name,start,end)){
        ret=false;
    }
    if(!this->animationAngle.addNewAnimationName(name,start,end)){
        ret=false;
    }
    return ret;
}
bool edk::bones::Bone2D::addNewAnimationNameThis(edk::char8* name, edk::float32 start,edk::float32 end){
    bool ret=true;
    if(!this->animationPosition.addNewAnimationName(name,start,end)){
        ret=false;
    }
    if(!this->animationAngle.addNewAnimationName(name,start,end)){
        ret=false;
    }
    return ret;
}
//select the animationName
bool edk::bones::Bone2D::selectAnimationNameThis(const edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.selectAnimationName(name)){
        ret=false;
    }
    if(!this->animationAngle.selectAnimationName(name)){
        ret=false;
    }
    return ret;
}
bool edk::bones::Bone2D::selectAnimationNameThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.selectAnimationName(name)){
        ret=false;
    }
    if(!this->animationAngle.selectAnimationName(name)){
        ret=false;
    }
    return ret;
}
//test if have the animationName
bool edk::bones::Bone2D::haveAnimationNameThis(const edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.haveAnimationName(name)){
        ret=false;
    }
    if(!this->animationAngle.haveAnimationName(name)){
        ret=false;
    }
    return ret;
}
bool edk::bones::Bone2D::haveAnimationNameThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.haveAnimationName(name)){
        ret=false;
    }
    if(!this->animationAngle.haveAnimationName(name)){
        ret=false;
    }
    return ret;
}
//Play the animationName
bool edk::bones::Bone2D::playNameForwardThis(const edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.playNameForward(name)){
        ret=false;
    }
    if(!this->animationAngle.playNameForward(name)){
        ret=false;
    }
    return ret;
}
bool edk::bones::Bone2D::playNameForwardThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.playNameForward(name)){
        ret=false;
    }
    if(!this->animationAngle.playNameForward(name)){
        ret=false;
    }
    return ret;
}
bool edk::bones::Bone2D::playNameRewindThis(const edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.playNameRewind(name)){
        ret=false;
    }
    if(!this->animationAngle.playNameRewind(name)){
        ret=false;
    }
    return ret;
}
bool edk::bones::Bone2D::playNameRewindThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.playNameRewind(name)){
        ret=false;
    }
    if(!this->animationAngle.playNameRewind(name)){
        ret=false;
    }
    return ret;
}
//remove the animationName
bool edk::bones::Bone2D::removeAnimationNameThis(const edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.removeAnimationName(name)){
        ret=false;
    }
    if(!this->animationAngle.removeAnimationName(name)){
        ret=false;
    }
    return ret;
}
bool edk::bones::Bone2D::removeAnimationNameThis(edk::char8* name){
    bool ret=true;
    if(!this->animationPosition.removeAnimationName(name)){
        ret=false;
    }
    if(!this->animationAngle.removeAnimationName(name)){
        ret=false;
    }
    return ret;
}
void edk::bones::Bone2D::removeAllAnimationNamesThis(){
    this->animationPosition.cleanAnimationNames();
    this->animationAngle.cleanAnimationNames();
}

//return if are playing
bool edk::bones::Bone2D::isPlayingThis(){
    bool ret=false;
    if(this->animationPosition.isPlaying()){
        ret=true;
    }
    if(this->animationAngle.isPlaying()){
        ret=true;
    }
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
    edk::GU::guRotateZf32(this->angle);

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

    edk::GU::guRotateZf32(this->angle*-1.f);
    edk::GU::guTranslate2f32(this->position*-1.f);
}
void edk::bones::Bone2D::drawLines(){
    //    printf("Angle == %.2f  ",this->angle);
    //    printf("position %.2f %.2f ",this->position.x,this->position.y);

    //edk::GU::guTranslate2f32(this->position);
    edk::GU::guTranslate2f32(this->position.x,this->position.y);
    edk::GU::guRotateZf32(this->angle);

    edk::GU::guBegin(GU_LINES);
    //edk::GU::guVertex2f32(this->position.x,this->position.y);
    edk::GU::guVertex2f32(0,0);
    edk::GU::guVertex2f32(this->vector.x,this->vector.y);
    edk::GU::guEnd();

    //draw the line
    //edk::GU::guTranslate2f32(this->vector);
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->drawLines();
    }

    edk::GU::guRotateZf32(this->angle*-1.f);
    edk::GU::guTranslate2f32(this->position*-1.f);
}
void edk::bones::Bone2D::drawLinesIK(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::vec2f32 pos;

    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){

        this->matrixPosition.setIdentity(1.f,0.f);

        //transform all the vertices
        if(this->matrixPosition.haveMatrix()){
            //
            this->matrixPosition.set(0u,0u,this->position.x);
            this->matrixPosition.set(0u,1u,this->position.y);
            this->matrixPosition.set(0u,2u,1.f);

            //multiply the matrix
            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

            pos.x = this->matrixPosition.getNoIF(0u,0u);
            pos.y = this->matrixPosition.getNoIF(0u,1u);

            //draw the line
            edk::GU::guVertex2f32(pos);
            edk::GU::guVertex2f32(this->ikPosition);
        }
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);

        //multiply the matrix by
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);

        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
            temp->drawLinesIK(&this->matrixTransform);
        }
    }
}
void edk::bones::Bone2D::drawPoints(edk::float32 scale){
    //    printf("Angle == %.2f  ",this->angle);
    //    printf("position %.2f %.2f ",this->position.x,this->position.y);

    edk::GU::guTranslate2f32(this->position.x,this->position.y);
    edk::GU::guRotateZf32(this->angle);

    edk::GU::guBegin(GU_POLYGON);
    edk::GU::guVertex2f32(-scale,-scale);
    edk::GU::guVertex2f32(-scale,+scale);
    edk::GU::guVertex2f32(+scale,+scale);
    edk::GU::guVertex2f32(+scale,-scale);
    edk::GU::guEnd();

    //draw the line
    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        temp->drawPoints(scale);
    }

    edk::GU::guRotateZf32(this->angle*-1.f);
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
edk::vec2f32 edk::bones::Bone2D::getWorldVector(edk::bones::Bone2D* bone,bool* found,edk::float32 angle,edk::size2f32 size,edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::vec2f32 ret(0,0);
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){
        this->matrixPosition.setIdentity(1.f,0.f);

        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);

        //multiply the matrix by
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);

        //transform all the vertices
        if(this->matrixPosition.haveMatrix()){
            if(bone){
                if(bone == this){
                    //
                    this->matrixPosition.set(0u,0u,this->vector.x);
                    this->matrixPosition.set(0u,1u,this->vector.y);
                    this->matrixPosition.set(0u,2u,1.f);

                    //multiply the matrix
                    this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                    ret.x = this->matrixPosition.getNoIF(0u,0u);
                    ret.y = this->matrixPosition.getNoIF(0u,1u);

                    *found=true;

                    return ret;
                }
            }
            else{
                return ret;
            }
        }
    }

    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        ret = temp->getWorldVector(bone,found,angle,size,&this->matrixTransform);
        if(*found){
            return ret;
        }
    }
    ret.x=0.f;
    ret.y=0.f;
    return ret;
}
edk::vec2f32 edk::bones::Bone2D::getWorldPosition(edk::bones::Bone2D* bone,bool* found,edk::float32 angle,edk::size2f32 size,edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::vec2f32 ret(0,0);
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){

        this->matrixPosition.setIdentity(1.f,0.f);

        //transform all the vertices
        if(this->matrixPosition.haveMatrix()){
            if(bone){
                if(bone == this){
                    //
                    this->matrixPosition.set(0u,0u,this->position.x);
                    this->matrixPosition.set(0u,1u,this->position.y);
                    this->matrixPosition.set(0u,2u,1.f);

                    //multiply the matrix
                    this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                    ret.x = this->matrixPosition.getNoIF(0u,0u);
                    ret.y = this->matrixPosition.getNoIF(0u,1u);

                    *found=true;

                    return ret;
                }
            }
            else{
                return ret;
            }
        }
    }

    //generate transform matrices
    edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);
    edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);

    //multiply the matrix by
    //translate
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);
    //angle
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);

    for(edk::uint32 i=0u;i<this->nexts.size();i++){
        edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
        ret = temp->getWorldPosition(bone,found,angle,size,&this->matrixTransform);
        if(*found){
            return ret;
        }
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
                                                           edk::uint32* counterAngles,
                                                           edk::vector::Matrixf32<3u,3u>* transformMat
                                                           ){
    edk::vec2f32 ret(0,0);
    edk::vec2f32 positionWorld(0,0);
    edk::float32 rotateAngle;
    if(this->matrixTransform.cloneFrom(transformMat)){
        //test if found the bone
        if(bone){
            if(bone == this){
                *found=true;
                *count=0u;
                *counterAngles=0u;

                edk::vector::Matrixf32<3u,3u>  matrixVector;
                matrixVector.cloneFrom(transformMat);

                edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);

                //multiply the matrix by
                //translate
                matrixVector.multiplyThisWithMatrix(&this->matrixTranslate);
                //angle
                matrixVector.multiplyThisWithMatrix(&this->matrixRotate);

                this->matrixPosition.setIdentity(1.f,0.f);

                //calculate the boneVector in the world
                this->matrixPosition.set(0u,0u,this->vector.x);
                this->matrixPosition.set(0u,1u,this->vector.y);
                this->matrixPosition.set(0u,2u,1.f);

                //multiply the matrix
                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&matrixVector);

                ret.x = this->matrixPosition.getNoIF(0u,0u);
                ret.y = this->matrixPosition.getNoIF(0u,1u);

                //get the bone worldPosition
                this->matrixPosition.setIdentity(1.f,0.f);
                //
                this->matrixPosition.set(0u,0u,0.f);
                this->matrixPosition.set(0u,1u,0.f);
                this->matrixPosition.set(0u,2u,1.f);

                //multiply the matrix
                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&matrixVector);

                positionWorld.x = this->matrixPosition.getNoIF(0u,0u);
                positionWorld.y = this->matrixPosition.getNoIF(0u,1u);

                rotateAngle = edk::Math::getAngle(worldPoint-positionWorld)-edk::Math::getAngle(ret-positionWorld);

                if(rotateAngle>edkIKAngleLimit || rotateAngle<-edkIKAngleLimit){
                    this->angle+=rotateAngle;
                    if(this->angle<0.f){
                        this->angle+=360.f;
                    }
                    if(this->angle>360.f){
                        this->angle-=360.f;
                    }

                    //rotate the ret
                    ret = edk::Math::rotatePlus(ret - positionWorld,rotateAngle)+positionWorld;
                }
                else{
                    *counterAngles+=1u;
                }
                this->ikPosition = ret;
                //increment the count
                *count+=1u;
                return ret;
            }
            else{
                if(!(*found)){
                    //generate transform matrices
                    edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);
                    edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);

                    //multiply the matrix by
                    //translate
                    this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);
                    //angle
                    this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);

                    //else search the selected bone
                    edk::uint32 size = this->nexts.size();
                    if(size){
                        for(edk::uint32 i=0u;i<size;i++){
                            edk::bones::Bone2D* temp = (edk::bones::Bone2D*)this->nexts.getElementInPosition(i);
                            ret = temp->calculateInverseKinematic(bone,found,worldPoint,limit,count,counterAngles,&this->matrixTransform);
                            if(*found){
                                //rotate the angle
                                if(*count<limit){
                                    //increment the count
                                    *count+=1u;

                                    this->matrixPosition.setIdentity(1.f,0.f);

                                    //transform all the vertices
                                    if(this->matrixPosition.haveMatrix()){
                                        //
                                        this->matrixPosition.set(0u,0u,0.f);
                                        this->matrixPosition.set(0u,1u,0.f);
                                        this->matrixPosition.set(0u,2u,1.f);

                                        //multiply the matrix
                                        this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                                        positionWorld.x = this->matrixPosition.getNoIF(0u,0u);
                                        positionWorld.y = this->matrixPosition.getNoIF(0u,1u);

                                        rotateAngle = edk::Math::getAngle(worldPoint-positionWorld)-edk::Math::getAngle(ret-positionWorld);
                                        /*
                                    printf("\n%u ret[%.2f] worldPoint[%.2f] rotateAngle[%.2f]",__LINE__
                                           ,edk::Math::getAngle(ret-positionWorld)
                                           ,edk::Math::getAngle(worldPoint-positionWorld)
                                           ,rotateAngle
                                           );fflush(stdout);
*/

                                        if(rotateAngle>edkIKAngleLimit || rotateAngle<-edkIKAngleLimit){
                                            this->angle+=rotateAngle;
                                            if(this->angle<0.f){
                                                this->angle+=360.f;
                                            }
                                            if(this->angle>360.f){
                                                this->angle-=360.f;
                                            }
                                            //rotate the ret
                                            ret = edk::Math::rotatePlus(ret - positionWorld,rotateAngle)+positionWorld;
                                        }
                                        else{
                                            *counterAngles+=1u;
                                        }
                                    }
                                }
                                this->ikPosition = ret;
                                return ret;
                            }
                        }
                    }
                    else{
                        return ret;
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
