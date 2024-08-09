#ifndef BONE2D_H
#define BONE2D_H

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

#ifdef printMessages
#pragma message "Inside Bone2D"
#endif

#pragma once
#include "../TypeVec2.h"
#include "../NameClass.h"
#include "../vector/Stack.h"
#include "../Math.h"

#include "../GU/GU.h"

#include "../animation/Interpolation1DGroup.h"
#include "../animation/Interpolation2DGroup.h"

#include "../Object2D.h"
#include "../Object2DValues.h"

#include <stdio.h>

#ifdef printMessages
#pragma message "    Compiling Bone2D"
#endif

namespace edk{
namespace bones{
class Bone2D : public edk::Name{
public:
    Bone2D();
    Bone2D(edk::char8* name);
    Bone2D(const edk::char8* name);
    virtual ~Bone2D();

    void Constructor(bool runFather=true);
    void Constructor(edk::char8* name,bool runFather=true);
    void Constructor(const edk::char8* name,bool runFather=true);

    edk::vec2f32 position;
    edk::vec2f32 vector;
    edk::float32 angle;

    edk::vec2f32 ikPosition;

    //adimations
    edk::animation::Interpolation1DGroup animationAngle;
    edk::animation::Interpolation2DGroup animationPosition;

    //clean the bone
    void cleanBone();

    //add a bone to the nexts
    bool addNext(edk::bones::Bone2D* next);
    //remove next
    bool removeNext(edk::bones::Bone2D* next);
    //remove by the name
    bool removeNextByName(const edk::char8* name);
    bool removeNextByName(edk::char8* name);
    //remove all nexts
    void removeAllNexts();

    //add a connection object
    bool addConnectionObject(edk::Object2DValues* object);
    //return the objects size
    edk::uint32 getConnectionObjectSize();
    //remove the connectionObject
    bool removeConnectionObject(edk::Object2DValues* object);
    //remove the connectionObject in the position
    bool removeConnectionObjectInPosition(edk::uint32 position);
    //remove all connection objects
    void removeAllConnectionObjects();
    //remove all animations
    void removeAllAnimations();

    //update all animations
    void updateAnimations();
    void updateAnimations(edk::float32 seconds);
    void updateAnimationsThis();
    void updateAnimationsThis(edk::float32 seconds);
    //scale animations
    void scaleAnimations(edk::float32 scale);
    void scaleAnimationsPosition(edk::float32 scale);
    void scaleAnimationsAngle(edk::float32 scale);
    //Speed
    void setAnimationsSpeed(edk::float32 speed);
    void setAnimationPositionSpeed(edk::float32 speed);
    void setAnimationAngleSpeed(edk::float32 speed);
    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardIn(edk::float32 second);
    void playRewind();
    void playRewindIn(edk::float32 second);
    void pause();
    void pauseOn();
    void pauseOff();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();
    void printFrames();
    //ANIMATIONNAMES
    bool addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end);
    //select the animationName
    bool selectAnimationName(const edk::char8* name);
    bool selectAnimationName(edk::char8* name);
    //test if have the animationName
    bool haveAnimationName(const edk::char8* name);
    bool haveAnimationName(edk::char8* name);
    //Play the animationName
    bool playNameForward(const edk::char8* name);
    bool playNameForward(edk::char8* name);
    bool playNameRewind(const edk::char8* name);
    bool playNameRewind(edk::char8* name);
    //remove the animationName
    bool removeAnimationName(const edk::char8* name);
    bool removeAnimationName(edk::char8* name);
    void removeAllAnimationNames();
    //return if are playing
    bool isPlaying();
    bool isPlayingName(const edk::char8* name);
    bool isPlayingName(edk::char8* name);
    bool wasPlayingName(const edk::char8* name);
    bool wasPlayingName(edk::char8* name);

    //This Bone
    void playForwardThis();
    void playForwardInThis(edk::float32 second);
    void playRewindThis();
    void playRewindInThis(edk::float32 second);
    void pauseThis();
    void pauseOnThis();
    void pauseOffThis();
    void stopThis();
    //set loop
    void setLoopThis(bool loop);
    void loopOnThis();
    void loopOffThis();
    void printFramesThis();
    //ANIMATIONNAMES
    bool addNewAnimationNameThis(const edk::char8* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationNameThis(edk::char8* name, edk::float32 start,edk::float32 end);
    //select the animationName
    bool selectAnimationNameThis(const edk::char8* name);
    bool selectAnimationNameThis(edk::char8* name);
    //test if have the animationName
    bool haveAnimationNameThis(const edk::char8* name);
    bool haveAnimationNameThis(edk::char8* name);
    //Play the animationName
    bool playNameForwardThis(const edk::char8* name);
    bool playNameForwardThis(edk::char8* name);
    bool playNameRewindThis(const edk::char8* name);
    bool playNameRewindThis(edk::char8* name);
    //remove the animationName
    bool removeAnimationNameThis(const edk::char8* name);
    bool removeAnimationNameThis(edk::char8* name);
    void removeAllAnimationNamesThis();
    //return if are playing
    bool isPlayingThis();

    //return the size of the nexts
    edk::uint32 getNextsSize();

    //return the next in position
    edk::bones::Bone2D* getNextInPosition(edk::uint32 position);

    void print();
    //draw the boneLine
    void draw();
    void drawLines();
    void drawLinesIK(edk::vector::Matrixf32<3u,3u>* transformMat);
    void drawPoints(edk::float32 scale);
    //update the objects
    void updateObjects(edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1),edk::float32 mat[][3u][3u] = NULL,edk::float32 angleRemove = 0.f,edk::float32 angleMultiply = 1.f);
    //calculate the bone point in the world
    edk::vec2f32 getWorldVector(edk::bones::Bone2D* bone,bool* found,edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1),edk::vector::Matrixf32<3u,3u>* transformMat=NULL);
    edk::vec2f32 getWorldPosition(edk::bones::Bone2D* bone,bool* found,edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1),edk::vector::Matrixf32<3u,3u>* transformMat=NULL);
    //calculate the IK with a point in the world
    edk::vec2f32 calculateInverseKinematic(edk::bones::Bone2D* bone,
                                           bool* found,
                                           edk::vec2f32 worldPoint,
                                           edk::uint32 limit,
                                           edk::uint32* count,
                                           edk::uint32* counterAngles,
                                           edk::vector::Matrixf32<3u,3u>* transformMat = NULL
            );



    //set the indentity matrix
    static bool setIdentity(edk::float32 mat[][3u][3u]);
    //copy the matrix
    static bool copyMatrix(edk::float32 mat[][3u][3u],edk::float32 dest[][3u][3u]);
    //multiply the matrix
    static bool multiplyMatrix(edk::float32 mat[][3u][3u],edk::float32 vec[][3u]);
    //multiply the matrix
    static bool multiplyMatrix(edk::float32 mat1[][3u][3u],edk::float32 mat2[][3u][3u]);
    //generate the translate matrix
    static bool generateTranslateMatrix(edk::vec2f32 position,edk::float32 mat[][3u][3u]);
    static bool generateRotationMatrix(edk::float32 angle,edk::float32 mat[][3u][3u]);
    static bool generateScaleMatrix(edk::size2f32 size,edk::float32 mat[][3u][3u]);

    //calculate the lenght
    edk::float32 calculateLenght(edk::bones::Bone2D* bone,edk::uint32 tail,edk::uint32* counter,bool* found);

    virtual bool cloneFrom(edk::bones::Bone2D* bone){
        if(bone){
            this->position = bone->position;edkEnd();
            this->vector = bone->vector;edkEnd();
            this->angle = bone->angle;edkEnd();
            //copy the animations
            //this->animationAngle = bone.animationAngle;edkEnd();
            this->animationAngle.cloneFrom(&bone->animationAngle);edkEnd();
            //this->animationPosition = bone->animationPosition;edkEnd();
            this->animationPosition.cloneFrom(&bone->animationPosition);edkEnd();

            this->setName(bone->getName());edkEnd();

            //copy the connectionObjects
            edk::uint32 size = bone->treeObjects.size();edkEnd();
            edk::bones::Bone2D::ObjectConnect* temp;edkEnd();
            edk::bones::Bone2D::ObjectConnect* newConnection;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                if((temp = bone->treeObjects.getElementInPosition(i))){
                    if((newConnection = new edk::bones::Bone2D::ObjectConnect)){
                        //copy the object valuess
                        newConnection->position = temp->position;edkEnd();
                        newConnection->angle = temp->angle;edkEnd();
                        newConnection->size = temp->size;edkEnd();
                        newConnection->object = temp->object;edkEnd();
                        //add the new connection to the tree
                        if(!this->treeObjects.add(newConnection)){
                            delete newConnection;edkEnd();
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }

private:
    edk::vector::NameTree nexts;
    //transform matrices
    edk::vector::Matrixf32<3u,3u>  matrixTranslate;
    edk::vector::Matrixf32<3u,3u>  matrixRotate;
    edk::vector::Matrixf32<3u,3u>  matrixTransform;
    edk::vector::MatrixDynamic<edk::float32> matrixPosition;

    //class to add the objects to the bone
    class ObjectConnect{
    public:
        ObjectConnect(){this->classThis=NULL;this->Constructor(false);edkEnd();}
        ObjectConnect(edk::Object2DValues* object){this->classThis=NULL;this->Constructor(object,false);edkEnd();}
        virtual ~ObjectConnect(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(bool runFather=true){
            if(runFather){edkEnd();}
            if(this->classThis!=this){
                this->classThis=this;
                this->object=NULL;edkEnd();
                this->angle=0u;edkEnd();
            }
        }
        void Constructor(edk::Object2DValues* object,bool runFather=true){
            if(runFather){edkEnd();}
            if(this->classThis!=this){
                this->classThis=this;
                if(object){
                    this->object=object;edkEnd();
                    this->angle=object->angle;edkEnd();
                    this->position = object->position;edkEnd();
                    this->size = object->size;edkEnd();
                }
                else{
                    this->object=NULL;edkEnd();this->angle=0u;edkEnd();
                }
            }
        }

        //Object transformations
        edk::vec2f32 position;
        edk::float32 angle;
        edk::size2f32 size;
        //Object used in the bone
        //edk::Object2D* object;
        edk::Object2DValues * object;
    private:
        edk::classID classThis;
    };

    //tree with objects
    class TreeObjects:public edk::vector::BinaryTree<ObjectConnect*>{
    public:
        TreeObjects(){
            //set the matrix identity
            edk::bones::Bone2D::setIdentity(&this->mat);edkEnd();
            this->setAngleRemove(0.f);edkEnd();
            this->setAngleMultiply(1.f);edkEnd();
        }

        //compare if the value is bigger
        virtual bool firstBiggerSecond(ObjectConnect* first,ObjectConnect* second){
            if(first->object>second->object){
                //
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(ObjectConnect* first,ObjectConnect* second){
            //
            if(first->object==second->object){
                //
                return true;
            }
            return false;
        }
        //UPDATE
        virtual void updateElement(ObjectConnect* value){
            //test the object
            if(value->object){
                edk::float32 vec[3u];edkEnd();
                //copy the position to the vector
                vec[0u] = value->position.x;edkEnd();
                vec[1u] = value->position.y;edkEnd();
                vec[2u] = 1.f;edkEnd();

                //multiply for the matrix
                edk::bones::Bone2D::multiplyMatrix(&this->mat,&vec);edkEnd();

                //set the position values
                value->object->position.x = vec[0u];edkEnd();
                value->object->position.y = vec[1u];edkEnd();

                //Scale the angle
                edk::float32 angleScaled = (value->angle * this->angleMultiply) + this->angle;edkEnd();
                if(this->scale.width!=this->scale.height){
                    angleScaled = edk::Math::getAngle(
                                edk::vec2f32( edk::Math::getCosin(angleScaled) * this->scale.width ,
                                              edk::Math::getSin(angleScaled) * this->scale.height
                                              )
                                );edkEnd();
                }
                if(!value->object->fixedRotation){
                    value->object->angle = (angleScaled * this->angleMultiply) - this->angleRemove;edkEnd();
                }
                value->object->size = value->size * this->scale;edkEnd();
            }
        }
        //return true if have the object
        bool haveObject(edk::Object2D* object){
            if(object){
                //find the object
                edk::bones::Bone2D::ObjectConnect find(object);edkEnd();
                return this->haveElement(&find);edkEnd();
            }
            return false;
        }
        //return the object in the position
        edk::Object2DValues* getObjectInPosition(edk::uint32 position){
            edk::bones::Bone2D::ObjectConnect* temp = this->getElementInPosition(position);edkEnd();
            if(temp){
                return temp->object;edkEnd();
            }
            return NULL;
        }
        //return the position
        edk::vec2f32 getObjectFirstPosition(edk::Object2DValues* object){
            edk::vec2f32 ret(0,0);edkEnd();
            edk::bones::Bone2D::ObjectConnect* temp = this->getConnect(object);edkEnd();
            if(temp){
                return temp->position;edkEnd();
            }
            return ret;
        }
        //return the angle
        edk::float32 getObjectFirstAngle(edk::Object2DValues* object){
            edk::float32 ret = 0.f;edkEnd();
            edk::bones::Bone2D::ObjectConnect* temp = this->getConnect(object);edkEnd();
            if(temp){
                return temp->angle;edkEnd();
            }
            return ret;
        }
        //remove the object
        bool removeObject(edk::Object2DValues* object){
            edk::bones::Bone2D::ObjectConnect* temp = this->getConnect(object);edkEnd();
            if(temp){
                if(this->remove(temp)){
                    delete temp;edkEnd();
                    return true;
                }
            }
            return false;
        }
        //remove the object in position
        bool removeObjectInPosition(edk::uint32 position){
            edk::bones::Bone2D::ObjectConnect* temp = this->getElementInPosition(position);edkEnd();
            if(temp){
                if(this->remove(temp)){
                    delete temp;edkEnd();
                    return true;
                }
            }
            return false;
        }

        //add a object to the tree
        bool addObject(edk::Object2DValues* object){
            if(object){
                edk::bones::Bone2D::ObjectConnect* temp = this->getConnect(object);edkEnd();
                if(!temp){
                    //create the new connect
                    temp = new edk::bones::Bone2D::ObjectConnect(object);edkEnd();
                    if(temp){
                        //add the temp to the tree
                        if(this->add(temp)){
                            return true;
                        }
                        //else delete temp
                        delete temp;edkEnd();
                    }
                }
            }
            return false;
        }

        //set the matrix
        bool setMatrix(edk::float32 mat[][3u][3u]){
            return edk::bones::Bone2D::copyMatrix(mat,&this->mat);edkEnd();
        }
        //set the angle
        void setAngle(edk::float32 angle){
            this->angle=angle;edkEnd();
        }
        void setAngleRemove(edk::float32 angleRemove){
            this->angleRemove = angleRemove;edkEnd();
        }
        void setAngleMultiply(edk::float32 angleMultiply){
            this->angleMultiply = angleMultiply;edkEnd();
        }
        void setScale(edk::size2f32 scale){
            this->scale=scale;edkEnd();
        }

    private:
        //return the connect
        edk::bones::Bone2D::ObjectConnect* getConnect(edk::Object2DValues* object){
            if(object){
                //find the object
                edk::bones::Bone2D::ObjectConnect find(object);edkEnd();
                return this->getElement(&find);edkEnd();
            }
            return NULL;
        }

        //matrix and angle to update
        edk::float32 mat[3u][3u];
        edk::float32 angle;
        edk::float32 angleRemove;
        edk::float32 angleMultiply;
        edk::size2f32 scale;
    }treeObjects;

    //the transformation matrix
    edk::float32 mat[3u][3u];
    //TEMP print the matrix
    void printMatrix(edk::float32 mat[3u][3u]);
    void printVector(edk::float32 mat[3u]);

private:
    //operator
    edk::bones::Bone2D operator=(edk::bones::Bone2D bone){
        //copy the vectors

        this->position = bone.position;edkEnd();
        this->vector = bone.vector;edkEnd();
        this->angle = bone.angle;edkEnd();
        //copy the animations
        //this->animationAngle = bone.animationAngle;edkEnd();
        this->animationAngle.cloneFrom(&bone.animationAngle);edkEnd();
        //this->animationPosition = bone.animationPosition;edkEnd();
        this->animationPosition.cloneFrom(&bone.animationPosition);edkEnd();

        this->setName(bone.getName());edkEnd();

        //copy the connectionObjects
        edk::uint32 size = bone.treeObjects.size();edkEnd();
        edk::bones::Bone2D::ObjectConnect* temp;edkEnd();
        edk::bones::Bone2D::ObjectConnect* newConnection;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if((temp = bone.treeObjects.getElementInPosition(i))){
                if((newConnection = new edk::bones::Bone2D::ObjectConnect)){
                    //copy the object valuess
                    newConnection->position = temp->position;edkEnd();
                    newConnection->angle = temp->angle;edkEnd();
                    newConnection->size = temp->size;edkEnd();
                    newConnection->object = temp->object;edkEnd();
                    //add the new connection to the tree
                    if(!this->treeObjects.add(newConnection)){
                        delete newConnection;edkEnd();
                    }
                }
            }
        }

        return bone;edkEnd();
    }
private:
    edk::classID classThis;
};
}//end namespace bones
}//end namespace edk

#endif // BONE2D_H
