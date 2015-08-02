#ifndef BONE2D_H
#define BONE2D_H

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

namespace edk{
namespace bones{
class Bone2D : public edk::Name{
public:
    Bone2D();
    Bone2D(edk::char8* name);
    Bone2D(const char* name);
    ~Bone2D();
    edk::vec2f32 position;
    edk::vec2f32 vector;
    edk::float32 angle;

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
    bool removeNextByName(const char* name);
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
    void updateAnimationsThis();
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
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();
    void printFrames();
    //ANIMATIONNAMES
    bool addNewAnimationName(const char* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end);
    //select the animationName
    bool selectAnimationName(const char* name);
    bool selectAnimationName(edk::char8* name);
    //test if have the animationName
    bool haveAnimationName(const char* name);
    bool haveAnimationName(edk::char8* name);
    //Play the animationName
    bool playNameForward(const char* name);
    bool playNameForward(edk::char8* name);
    bool playNameRewind(const char* name);
    bool playNameRewind(edk::char8* name);
    //remove the animationName
    bool removeAnimationName(const char* name);
    bool removeAnimationName(edk::char8* name);
    void removeAllAnimationNames();
    //return if are playing
    bool isPlaying();

    //This Bone
    void playForwardThis();
    void playForwardInThis(edk::float32 second);
    void playRewindThis();
    void playRewindInThis(edk::float32 second);
    void pauseThis();
    void stopThis();
    //set loop
    void setLoopThis(bool loop);
    void loopOnThis();
    void loopOffThis();
    void printFramesThis();
    //ANIMATIONNAMES
    bool addNewAnimationNameThis(const char* name, edk::float32 start,edk::float32 end);
    bool addNewAnimationNameThis(edk::char8* name, edk::float32 start,edk::float32 end);
    //select the animationName
    bool selectAnimationNameThis(const char* name);
    bool selectAnimationNameThis(edk::char8* name);
    //test if have the animationName
    bool haveAnimationNameThis(const char* name);
    bool haveAnimationNameThis(edk::char8* name);
    //Play the animationName
    bool playNameForwardThis(const char* name);
    bool playNameForwardThis(edk::char8* name);
    bool playNameRewindThis(const char* name);
    bool playNameRewindThis(edk::char8* name);
    //remove the animationName
    bool removeAnimationNameThis(const char* name);
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
    //update the objects
    void updateObjects(edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1),edk::float32 mat[][3u][3u] = NULL,edk::float32 angleRemove = 0.f,edk::float32 angleMultiply = 1.f);
    //calculate the bone point in the world
    edk::vec2f32 getWorldVector(edk::bones::Bone2D* bone,bool* found,edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1),edk::float32 mat[][3u][3u] = NULL);
    //calculate the IK with a point in the world
    edk::vec2f32 calculateInverseKinematic(edk::bones::Bone2D* bone,
                                           bool* found,
                                           edk::vec2f32 worldPoint,
                                           edk::uint32 limit,
                                           edk::uint32* count,
                                           edk::float32 angle=0.f,
                                           edk::size2f32 size = edk::size2f32(1,1),
                                           edk::float32 mat[][3u][3u] = NULL
            );

    virtual void cantDelete();



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
private:
    edk::vector::NameTree nexts;

    //class to add the objects to the bone
    class ObjectConnect{
    public:
        ObjectConnect(){this->object=NULL;this->angle=0u;}
        ObjectConnect(edk::Object2DValues* object){
            if(object){
                this->object=object;
                this->angle=object->angle;
                this->position = object->position;
                this->size = object->size;
            }
            else{
                this->object=NULL;this->angle=0u;
            }
        }
        ~ObjectConnect(){}

        //Object transformations
        edk::vec2f32 position;
        edk::float32 angle;
        edk::size2f32 size;
        //Object used in the bone
        //edk::Object2D* object;
        edk::Object2DValues * object;
    };

    //tree with objects
    class TreeObjects:public edk::vector::BinaryTree<ObjectConnect*>{
    public:
        TreeObjects(){
            //set the matrix identity
            edk::bones::Bone2D::setIdentity(&this->mat);
            this->setAngleRemove(0.f);
            this->setAngleMultiply(1.f);
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
                edk::float32 vec[3u];
                //copy the position to the vector
                vec[0u] = value->position.x;
                vec[1u] = value->position.y;
                vec[2u] = 1.f;

                //multiply for the matrix
                edk::bones::Bone2D::multiplyMatrix(&this->mat,&vec);

                //set the position values
                value->object->position.x = vec[0u];
                value->object->position.y = vec[1u];

                //Scale the angle
                edk::float32 angleScaled = (value->angle * this->angleMultiply) + this->angle;
                if(this->scale.width!=this->scale.height)
                    angleScaled = edk::Math::getAngle2f(
                                edk::vec2f32( edk::Math::getCosinFloat(angleScaled) * this->scale.width ,
                                              edk::Math::getSinFloat(angleScaled) * this->scale.height
                                              )
                                );

                if(!value->object->fixedRotation){
                    value->object->angle = (angleScaled * this->angleMultiply) - this->angleRemove;
                }
                value->object->size = value->size * this->scale;
            }
        }
        //return true if have the object
        bool haveObject(edk::Object2D* object){
            if(object){
                //find the object
                edk::bones::Bone2D::ObjectConnect find(object);
                return this->haveElement(&find);
            }
            return false;
        }
        //return the object in the position
        edk::Object2DValues* getObjectInPosition(edk::uint32 position){
            edk::bones::Bone2D::ObjectConnect* temp = this->getElementInPosition(position);
            if(temp){
                return temp->object;
            }
            return NULL;
        }
        //return the position
        edk::vec2f32 getObjectFirstPosition(edk::Object2DValues* object){
            edk::vec2f32 ret(0,0);
            edk::bones::Bone2D::ObjectConnect* temp = this->getConnect(object);
            if(temp){
                return temp->position;
            }
            return ret;
        }
        //return the angle
        edk::float32 getObjectFirstAngle(edk::Object2DValues* object){
            edk::float32 ret = 0.f;
            edk::bones::Bone2D::ObjectConnect* temp = this->getConnect(object);
            if(temp){
                return temp->angle;
            }
            return ret;
        }
        //remove the object
        bool removeObject(edk::Object2DValues* object){
            edk::bones::Bone2D::ObjectConnect* temp = this->getConnect(object);
            if(temp){
                if(this->remove(temp)){
                    delete temp;
                    return true;
                }
            }
            return false;
        }
        //remove the object in position
        bool removeObjectInPosition(edk::uint32 position){
            edk::bones::Bone2D::ObjectConnect* temp = this->getElementInPosition(position);
            if(temp){
                if(this->remove(temp)){
                    delete temp;
                    return true;
                }
            }
            return false;
        }

        //add a object to the tree
        bool addObject(edk::Object2DValues* object){
            if(object){
                edk::bones::Bone2D::ObjectConnect* temp = this->getConnect(object);
                if(!temp){
                    //create the new connect
                    temp = new edk::bones::Bone2D::ObjectConnect(object);
                    if(temp){
                        //add the temp to the tree
                        if(this->add(temp)){
                            return true;
                        }
                        //else delete temp
                        delete temp;
                    }
                }
            }
            return false;
        }

        //set the matrix
        bool setMatrix(edk::float32 mat[][3u][3u]){
            return edk::bones::Bone2D::copyMatrix(mat,&this->mat);
        }
        //set the angle
        void setAngle(edk::float32 angle){
            this->angle=angle;
        }
        void setAngleRemove(edk::float32 angleRemove){
            this->angleRemove = angleRemove;
        }
        void setAngleMultiply(edk::float32 angleMultiply){
            this->angleMultiply = angleMultiply;
        }
        void setScale(edk::size2f32 scale){
            this->scale=scale;
        }

    private:
        //return the connect
        edk::bones::Bone2D::ObjectConnect* getConnect(edk::Object2DValues* object){
            if(object){
                //find the object
                edk::bones::Bone2D::ObjectConnect find(object);
                return this->getElement(&find);
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

    bool canDeleteBone;
public:
    //operator
    edk::bones::Bone2D operator=(edk::bones::Bone2D bone){
        //copy the vectors

        this->position = bone.position;
        this->vector = bone.vector;
        this->angle = bone.angle;
        //copy the animations
        this->animationAngle = bone.animationAngle;
        this->animationPosition = bone.animationPosition;

        this->setName(bone.getName());

        //copy the connectionObjects
        edk::uint32 size = bone.treeObjects.size();
        edk::bones::Bone2D::ObjectConnect* temp;
        edk::bones::Bone2D::ObjectConnect* newConnection;
        for(edk::uint32 i=0u;i<size;i++){
            if((temp = bone.treeObjects.getElementInPosition(i))){
                if((newConnection = new edk::bones::Bone2D::ObjectConnect)){
                    //copy the object valuess
                    newConnection->position = temp->position;
                    newConnection->angle = temp->angle;
                    newConnection->size = temp->size;
                    newConnection->object = temp->object;
                    //add the new connection to the tree
                    if(!this->treeObjects.add(newConnection)){
                        delete newConnection;
                    }
                }
            }
        }

        //can delete bone
        bone.cantDelete();
        return bone;
    }
};
}//end namespace bones
}//end namespace edk

#endif // BONE2D_H
