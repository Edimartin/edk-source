#ifndef BODY2D_H
#define BODY2D_H

/*
Library bones Body2D - Body 2D to create the bones2D
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

#ifdef printMessages
#warning "Inside Body2D"
#endif

#pragma once
#include "Bone2D.h"
#include "../String.h"
#include "../File.h"
#include "../TypeDefines.h"
#include "../vector/Stack.h"

#ifdef printMessages
#warning "    Compiling Body2D"
#endif


namespace edk{
namespace bones{
class Body2D : public edk::Object2DValues{
public:
    Body2D();
    virtual ~Body2D();

    //add a new bone to the selected
    edk::bones::Bone2D* createBoneToSelected(const edk::char8* name);
    edk::bones::Bone2D* createBoneToSelected(const edk::char8* name,edk::vec2f32 position);
    edk::bones::Bone2D* createBoneToSelected(const edk::char8* name,edk::float32 positionX,edk::float32 positionY);
    edk::bones::Bone2D* createBoneToSelected(const edk::char8* name,edk::vec2f32 position,edk::float32 angle);
    edk::bones::Bone2D* createBoneToSelected(const edk::char8* name,edk::float32 positionX,edk::float32 positionY,edk::float32 angle);
    edk::bones::Bone2D* createBoneToSelected(edk::char8* name);
    edk::bones::Bone2D* createBoneToSelected(edk::char8* name,edk::vec2f32 position);
    edk::bones::Bone2D* createBoneToSelected(edk::char8* name,edk::float32 positionX,edk::float32 positionY);
    edk::bones::Bone2D* createBoneToSelected(edk::char8* name,edk::vec2f32 position,edk::float32 angle);
    edk::bones::Bone2D* createBoneToSelected(edk::char8* name,edk::float32 positionX,edk::float32 positionY,edk::float32 angle);

    //Add the bone to the selected
    bool addBoneToSelected(edk::bones::Bone2D* bone);
    bool addBoneToSelected(const edk::char8* name);
    bool addBoneToSelected(edk::char8* name);

    //Select the bone
    bool selectBone(edk::bones::Bone2D* bone);
    //Select the bone by the name
    bool selectBoneByName(const edk::char8* name);
    bool selectBoneByName(edk::char8* name);

    bool selectedSetPosition(edk::vec2f32 position);
    bool selectedSetPosition(edk::float32 x,edk::float32 y);
    bool selectedSetVector(edk::vec2f32 vector);
    bool selectedSetVector(edk::float32 x,edk::float32 y);
    bool selectedSetAngle(edk::float32 angle);
    //animations
    bool selectedCleanAnimationPosition();
    bool selectedCleanAnimationNamesPosition();
    bool selectedCleanAnimationAngle();
    bool selectedCleanAnimationNamesAngle();

    //return the size of the bones
    edk::uint32 getBonesSize();

    //get the bone
    edk::bones::Bone2D* getBone(edk::uint32 position);
    edk::bones::Bone2D* getBoneByName(const edk::char8* name);
    edk::bones::Bone2D* getBoneByName(edk::char8* name);

    //remove the selection
    void cleanSelected();
    //delete a bone
    bool deleteBone(edk::bones::Bone2D* bone);
    bool deleteBone(const edk::char8* name);
    bool deleteBone(edk::char8* name);
    //delete all bones
    void deleteAllBones();

    //add a connection object
    bool addConnectionObject(const edk::char8* boneName,edk::Object2DValues* object);
    bool addConnectionObject(edk::char8* boneName,edk::Object2DValues* object);
    //return the objects size
    edk::uint32 getConnectionObjectSize(const edk::char8* boneName);
    edk::uint32 getConnectionObjectSize(edk::char8* boneName);
    //remove the connectionObject
    bool removeConnectionObject(const edk::char8* boneName,edk::Object2DValues* object);
    bool removeConnectionObject(edk::char8* boneName,edk::Object2DValues* object);
    //remove the connectionObject in the position
    bool removeConnectionObjectInPosition(const edk::char8* boneName,edk::uint32 position);
    bool removeConnectionObjectInPosition(edk::char8* boneName,edk::uint32 position);
    //remove all connection objects
    bool removeAllConnectionObjects(const edk::char8* boneName);
    bool removeAllConnectionObjects(edk::char8* boneName);
    void removeAllConnectionObjects();

    //update animations
    void updateAnimations();
    //scale animations
    void scaleAnimations(edk::float32 scale);
    void scaleAnimationsPosition(edk::float32 scale);
    void scaleAnimationsAngle(edk::float32 scale);
    //scale animations
    void setAnimationsSpeed(edk::float32 speed);
    void setAnimationsPositionSpeed(edk::float32 speed);
    void setAnimationsAngleSpeed(edk::float32 speed);
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

    //load the BVH
    bool loadBVHXY(const edk::char8* name);
    bool loadBVHXY(edk::char8* name);
    bool loadBVHXZ(const edk::char8* name);
    bool loadBVHXZ(edk::char8* name);
    bool loadBVHYZ(const edk::char8* name);
    bool loadBVHYZ(edk::char8* name);

    //print the bones
    void print();
    //draw the bones
    void draw();
    //update the connected objects
    void updateObjects();
    //return the world vector of the bone
    edk::vec2f32 getBoneWorldVector(edk::bones::Bone2D* bone, bool* found = NULL);
    void calculateInverseKinematic(const edk::char8* name,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times);
    void calculateInverseKinematic(edk::char8* name,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times);
    void calculateInverseKinematic(edk::bones::Bone2D* bone,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times);

    virtual void cantDelete();
private:
    edk::bones::Bone2D root;
    edk::bones::Bone2D* selected;
    //edk::vector::NameTree bones;
    bool canDelete;

    class TreeBoneName:public edk::vector::BinaryTree<edk::bones::Bone2D*>{
    public:
        TreeBoneName(){}
        ~TreeBoneName(){}

        //compare if the value is bigger
        bool firstBiggerSecond(edk::bones::Bone2D* first,edk::bones::Bone2D* second){
            //
            if(first && second){
                if(edk::Name::firstNameBiggerSecond(first->getName(),second->getName())){
                    return true;
                }
            }
            return false;
        }
        bool firstEqualSecond(edk::bones::Bone2D* first,edk::bones::Bone2D* second){
            //
            if(first && second){
                if(edk::Name::stringEqual(first->getName(),second->getName())){
                    return true;
                }
            }
            return false;
        }
        edk::bones::Bone2D* getElementByName(const edk::char8* name){
            return this->getElementByName((edk::char8*) name);
        }
        edk::bones::Bone2D* getElementByName(edk::char8* name){
            edk::bones::Bone2D find;
            find.setName(name);
            return this->getElement(&find);
        }
    }bones;

    class ChannelLink{
    public:
        ChannelLink(){this->bone=NULL;this->channel=0u;}
        edk::bones::Bone2D* bone;
        edk::uint8 channel;
        ChannelLink operator=(ChannelLink link){
            this->bone = link.bone;
            this->channel = link.channel;
            return link;
        }
    };

    edk::vector::Stack<edk::bones::Body2D::ChannelLink> links;

    //remove using recursivity
    bool removeRecursive(edk::bones::Bone2D* next,edk::bones::Bone2D* removing);
    //load the Hierarckhy
    edk::uint32 loadHierarkhy(edk::File* file,edk::bones::Bone2D* last,edk::bones::Bone2D* bone, edk::uint8 mode,edk::vector::Stack<edk::bones::Body2D::ChannelLink>* channelLinks);

    //load the BVH
    bool loadBVH(edk::char8* name,edk::uint8 mode);

public:
    virtual bool cloneFrom(edk::bones::Body2D* body){
        //delete all bones
        this->deleteAllBones();
        if(body){
            //copy the root
            //this->root = body->root;
            this->root.cloneFrom(&body->root);

            //copy the bonesTree
            edk::uint32 size = body->bones.size();
            edk::bones::Bone2D* temp;
            edk::bones::Bone2D* newBone;
            edk::bones::Bone2D* nextTemp;
            for(edk::uint32 i=0u;i<size;i++){
                if((temp = body->bones.getElementInPosition(i))){
                    //create a new bone
                    if((newBone = new edk::bones::Bone2D)){
                        //copy the temp
                        //*newBone = *temp;
                        newBone->cloneFrom(temp);
                        //add the newBone to the tree
                        if(!this->bones.add(newBone)){
                            //
                            delete newBone;
                            newBone = NULL;
                        }
                    }
                }
            }
            edk::uint32 nextsSize;
            //copy root nexts
            nextsSize = body->root.getNextsSize();
            //copy the root nexts
            for(edk::uint32 j=0u;j<nextsSize;j++){
                if((nextTemp = body->root.getNextInPosition(j))){
                    //add the next to the next bone
                    this->root.addNext(this->bones.getElementByName(nextTemp->getName()));
                }
            }

            //copy the nexts bones
            size = this->bones.size();
            for(edk::uint32 i=0u;i<size;i++){
                if((newBone = this->bones.getElementInPosition(i))){
                    //load the bone in body
                    if((temp = body->bones.getElementByName(newBone->getName()))){
                        //copy the nexts pointers
                        nextsSize = temp->getNextsSize();
                        for(edk::uint32 j=0u;j<nextsSize;j++){
                            if((nextTemp = temp->getNextInPosition(j))){
                                //add the next to the next bone
                                newBone->addNext(this->bones.getElementByName(nextTemp->getName()));
                            }
                        }
                    }
                }
            }

            //select the bone
            if(body->selected){
                this->selected = this->bones.getElementByName(body->selected->getName());
            }
            else{
                this->cleanSelected();
            }
            this->position = body->position;
            this->size = body->size;
            this->angle = body->angle;
            this->fixedRotation = body->fixedRotation;
            return false;
        }
        return false;
    }

private:

    edk::bones::Body2D operator=(edk::bones::Body2D body){
        //delete all bones
        this->deleteAllBones();
        //copy the root
        //this->root = body.root;
        this->root.cloneFrom(&body.root);

        //copy the bonesTree
        edk::uint32 size = body.bones.size();
        edk::bones::Bone2D* temp;
        edk::bones::Bone2D* newBone;
        edk::bones::Bone2D* nextTemp;
        for(edk::uint32 i=0u;i<size;i++){
            if((temp = body.bones.getElementInPosition(i))){
                //create a new bone
                if((newBone = new edk::bones::Bone2D)){
                    //copy the temp
                    //*newBone = *temp;
                    newBone->cloneFrom(temp);
                    //add the newBone to the tree
                    if(!this->bones.add(newBone)){
                        //
                        delete newBone;
                        newBone = NULL;
                    }
                }
            }
        }
        edk::uint32 nextsSize;
        //copy root nexts
        nextsSize = body.root.getNextsSize();
        //copy the root nexts
        for(edk::uint32 j=0u;j<nextsSize;j++){
            if((nextTemp = body.root.getNextInPosition(j))){
                //add the next to the next bone
                this->root.addNext(this->bones.getElementByName(nextTemp->getName()));
            }
        }

        //copy the nexts bones
        size = this->bones.size();
        for(edk::uint32 i=0u;i<size;i++){
            if((newBone = this->bones.getElementInPosition(i))){
                //load the bone in body
                if((temp = body.bones.getElementByName(newBone->getName()))){
                    //copy the nexts pointers
                    nextsSize = temp->getNextsSize();
                    for(edk::uint32 j=0u;j<nextsSize;j++){
                        if((nextTemp = temp->getNextInPosition(j))){
                            //add the next to the next bone
                            newBone->addNext(this->bones.getElementByName(nextTemp->getName()));
                        }
                    }
                }
            }
        }

        //select the bone
        if(body.selected){
            this->selected = this->bones.getElementByName(body.selected->getName());
        }
        else{
            this->cleanSelected();
        }
        this->position = body.position;
        this->size = body.size;
        this->angle = body.angle;
        this->fixedRotation = body.fixedRotation;

        //
        body.cantDelete();
        return body;
    }
};
}//end namespace bones
}//end namespace edk

#endif // BODY2D_H
