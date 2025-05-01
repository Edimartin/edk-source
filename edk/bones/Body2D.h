#ifndef BODY2D_H
#define BODY2D_H

/*
Library bones Body2D - Body 2D to create the bones2D
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
#pragma message "Inside Body2D"
#endif

#pragma once
#include "Bone2D.h"
#include "../String.h"
#include "../File.h"
#include "../TypeDefines.h"
#include "../vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling Body2D"
#endif


namespace edk{
namespace bones{
class Body2D : public edk::Object2DValues{
public:
    Body2D();
    virtual ~Body2D();

    void Constructor();
    void Destructor();

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

    //add a new bone with world position to the selected
    edk::bones::Bone2D* createBoneWorldPositionToSelected(const edk::char8* name);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(const edk::char8* name,edk::vec2f32 position);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(const edk::char8* name,edk::float32 positionX,edk::float32 positionY);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(const edk::char8* name,edk::vec2f32 position,edk::float32 angle);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(const edk::char8* name,edk::float32 positionX,edk::float32 positionY,edk::float32 angle);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(edk::char8* name);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(edk::char8* name,edk::vec2f32 position);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(edk::char8* name,edk::float32 positionX,edk::float32 positionY);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(edk::char8* name,edk::vec2f32 position,edk::float32 angle);
    edk::bones::Bone2D* createBoneWorldPositionToSelected(edk::char8* name,edk::float32 positionX,edk::float32 positionY,edk::float32 angle);

    //Add the bone to the selected
    bool addBoneToSelected(edk::bones::Bone2D* bone);
    bool addBoneToSelected(const edk::char8* name);
    bool addBoneToSelected(edk::char8* name);

    bool removeBoneFromSelected(edk::bones::Bone2D* bone);
    bool removeBoneFromSelected(const edk::char8* name);
    bool removeBoneFromSelected(edk::char8* name);

    bool removeBonesFromSelected();

    //Add the bone world position to the selected
    bool addBoneWorldPositionToSelected(edk::bones::Bone2D* bone);
    bool addBoneWorldPositionToSelected(const edk::char8* name);
    bool addBoneWorldPositionToSelected(edk::char8* name);

    //Select the bone
    void selectBoneRoot();
    bool selectBone(edk::bones::Bone2D* bone);
    //Select the bone by the name
    bool selectBoneByName(const edk::char8* name);
    bool selectBoneByName(edk::char8* name);

    bool selectedSetPosition(edk::vec2f32 position);
    bool selectedSetPosition(edk::float32 x,edk::float32 y);
    bool selectedSetVector(edk::vec2f32 vector);
    bool selectedSetVector(edk::float32 x,edk::float32 y);
    bool selectedSetAngle(edk::float32 angle);
    edk::vec2f32 selectedGetPosition();
    edk::vec2f32 selectedGetWorldPosition();
    edk::vec2f32 selectedGetWorldVector();
    edk::vec2f32 selectedGetVector();
    edk::float32 selectedGetAngle();
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
    bool updateAnimations();
    bool updateAnimations(edk::float32 seconds);
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
    bool isPlayingName(const edk::char8* name);
    bool isPlayingName(edk::char8* name);
    bool wasPlayingName(const edk::char8* name);
    bool wasPlayingName(edk::char8* name);

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
    //draw the bones
    void drawLines();
    void drawLinesIK();
    void drawPoints(edk::float32 size);
    //update the connected objects
    void updateObjects();
    //return the world vector of the bone
    edk::vec2f32 getBoneWorldVector(edk::bones::Bone2D* bone, bool* found = NULL);
    edk::vec2f32 getBoneWorldPosition(edk::bones::Bone2D* bone, bool* found = NULL);
    bool calculateInverseKinematic(const edk::char8* name,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times);
    bool calculateInverseKinematic(edk::char8* name,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times);
    bool calculateInverseKinematic(edk::bones::Bone2D* bone,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times);

    //calculate the bones lenght
    edk::float32 calculateLenght(edk::bones::Bone2D* bone,edk::uint32 tail);

private:
    edk::bones::Bone2D root;
    edk::bones::Bone2D* selected;

    //transform matrices
    edk::vector::Matrixf32<3u,3u> matrixPosition;
    edk::vector::Matrixf32<3u,3u> matrixPivo;
    edk::vector::Matrixf32<3u,3u> matrixAngle;
    edk::vector::Matrixf32<3u,3u> matrixSize;
    edk::vector::Matrixf32<3u,3u> matrixTransform;

    class TreeBoneName:public edk::vector::BinaryTree<edk::bones::Bone2D*>{
    public:
        TreeBoneName(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TreeBoneName(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::bones::Bone2D*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::vector::BinaryTree<edk::bones::Bone2D*>::Destructor();
        }

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
    private:
        edk::classID classThis;
    }bones;

    class ChannelLink{
    public:
        ChannelLink(){this->bone=NULL; this->channel=0u; }
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

        return body;
    }
private:
    edk::classID classThis;
};
}//end namespace bones
}//end namespace edk

#endif // BODY2D_H
