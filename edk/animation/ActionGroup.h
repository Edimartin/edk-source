#ifndef ACTIONGROUP_H
#define ACTIONGROUP_H

/*
Library C++ ActionGroup - Animate Actions
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
#warning "Inside ActionGroup"
#endif

#ifdef printMessages
#warning "    Compiling ActionGroup"
#endif

#pragma once
//Use Actions
#include "../Action.h"
//Use binaryTree's
#include "../vector/BinaryTree.h"
#include "../vector/Stack.h"
//Use one animation
#include "Interpolation1DGroup.h"

namespace edk{
namespace animation{
class ActionGroup
{
public:
    ActionGroup();
    virtual ~ActionGroup();

    //add one action
    bool addAction(edk::float32 second,edk::Action* action);
    bool addZeroAction(edk::float32 second);
    //remove second
    bool removeSecond(edk::float32 second);

    //get the keyFrames size
    edk::uint32 getKeySize();
    //get the key second
    edk::float32 getKeySecond(edk::uint32 keyPosition);
    //get the actions size in position
    edk::uint32 getActionsSize(edk::uint32 keyPosition);
    //return the action code
    edk::uint32 getActionCode(edk::uint32 keyPosition,edk::uint32 actionPosition);
    //return the action
    edk::Action* getActionInKey(edk::uint32 keyPosition,edk::uint32 actionPosition);
    edk::Action* getActionInSecond(edk::float32 second,edk::uint32 actionPosition);

    //clean animation
    void clean();

    //update animations
    void update();

    //ANIMATION FUNCTIONS
    //get Loop
    bool isLooping();

    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardIn(edk::float32 second);
    //void playRewind();
    //void playRewindIn(edk::float32 second);
    void pause();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();

    //return if are playing
    bool isPlaying();
    bool isPaused();

    //cand delete
    void cantDeleteGroup();
private:
    bool canDeleteGroup;
    //animation
    edk::animation::Interpolation1DGroup anim;
    //save the value
    edk::float32 valueTemp;

    //first update
    void firstUpdate();

    //create a stack to save the actions
    class ActionsTree : public edk::vector::BinaryTree<edk::Action*>{
    public:
        ActionsTree(edk::float32 second){
            this->second = second;
        }
        ~ActionsTree(){
            this->clean();
        }
        //return the second
        edk::float32 getSecond(){
            return this->second;
        }

        //UPDATE
        void updateElement(edk::Action* value){
            //update the value
            value->runAction();
        }
    private:
        edk::float32 second;
    };
    class ActionReferenceCount{
    public:
        ActionReferenceCount(edk::Action* action){
            count=0u;
            this->action=action;
        }
        ~ActionReferenceCount(){
            //
        }
        void retain(){
            this->count++;
        }
        bool release(){
            if(this->count){
                this->count--;
                if(this->count){
                    return true;
                }
            }
            return false;
        }
        edk::Action* getAction(){return this->action;}
    private:
        edk::uint32 count;
        edk::Action* action;
    };

    //create a tree to save the actions
    class ActionStackTree: public edk::vector::BinaryTree<edk::animation::ActionGroup::ActionsTree*>{
    public:
        ActionStackTree(){
            this->canDeleteTree=true;
        }
        ~ActionStackTree(){
            if(this->canDeleteTree){
            this->cleanActions();
            }
            else{
                this->cantDestruct();
                this->actionsTree.cantDestruct();
                edk::uint32 size = this->size();
                edk::animation::ActionGroup::ActionsTree* temp;
                for(edk::uint32 i=0u;i<size;i++){
                    temp = this->getElementInPosition(i);
                    if(temp)
                        temp->cantDestruct();
                }
            }
            this->canDeleteTree=true;
        }

        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::animation::ActionGroup::ActionsTree* first,edk::animation::ActionGroup::ActionsTree* second){
            if(first->getSecond()>second->getSecond()){
                //
                return true;
            }
            return false;
        }
        bool firstEqualSecond(edk::animation::ActionGroup::ActionsTree* first,edk::animation::ActionGroup::ActionsTree* second){
            if(first->getSecond()==second->getSecond()){
                //
                return true;
            }
            return false;
        }

        //update the second
        bool updateSecond(edk::float32 second){
            edk::animation::ActionGroup::ActionsTree* tree = this->getActionTree(second);
            if(tree){
                tree->update();
            }
            return false;
        }

        //cant delete the tree
        void cantDeleteTrees(){
            /*
            this->cantDestruct();
            edk::uint32 size = this->size();
            edk::animation::ActionGroup::ActionsTree* temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp)
              temp->cantDestruct();
            }
            */
            this->canDeleteTree=false;
        }

        //Add a new Action
        bool addAction(edk::float32 second,edk::Action* action){
            if(action){
                //load the action stack
                edk::animation::ActionGroup::ActionsTree* tree = this->getActionTree(second);
                if(tree){
                    //add the action to the tree
                    if(tree->add(action)){
                        //add the action to the reference count
                        this->actionsTree.addAction(action);
                        return true;
                    }
                }
                //else create a new tree to the second
                tree = new edk::animation::ActionGroup::ActionsTree(second);
                if(tree){
                    //add the tree to the tree
                    if(this->add(tree)){
                        //add the action to the tree
                        if(tree->add(action)){
                            //add the action to the reference count
                            this->actionsTree.addAction(action);
                            return true;
                        }
                    }
                    //else delete the tree
                    delete tree;
                }
            }
            return false;
        }
        //get the second in the position
        edk::float32 getSecond(edk::uint32 position){
            edk::animation::ActionGroup::ActionsTree* tree = this->getElementInPosition(position);
            if(tree){
                return tree->getSecond();
            }
            return 0.f;
        }
        //test if have the position
        bool havePosition(edk::uint32 position){
            edk::animation::ActionGroup::ActionsTree* tree = this->getElementInPosition(position);
            if(tree){
                return true;
            }
            return false;
        }
        //find the action second
        edk::float32 getActionSecond(edk::Action* action){
            edk::uint32 size = this->size();
            edk::animation::ActionGroup::ActionsTree* tree=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                tree = this->getElementInPosition(i);
                if(tree->haveElement(action)){
                    //return the second
                    return tree->getSecond();
                }
            }
            return 0.f;
        }
        //remove the action
        bool removeAction(edk::Action* action){
            return this->removeActionInSecond(this->getActionSecond(action),action);
        }
        //get actions in second
        edk::uint32 getActionSizeInSecond(edk::float32 second){
            edk::animation::ActionGroup::ActionsTree* tree = this->getActionTree(second);
            if(tree){
                return tree->size();
            }
            return 0u;
        }
        edk::uint32 getActionSizeInPosition(edk::uint32 position){
            edk::animation::ActionGroup::ActionsTree* tree = this->getElementInPosition(position);
            if(tree){
                return tree->size();
            }
            return 0u;
        }
        //get the action
        edk::Action* getActionInSecond(edk::float32 second,edk::uint32 position){
            edk::animation::ActionGroup::ActionsTree* tree = this->getActionTree(second);
            if(tree){
                //return the action in position
                return tree->getElementInPosition(position);
            }
            return NULL;
        }
        edk::Action* getActionInPosition(edk::uint32 secondPosition,edk::uint32 position){
            edk::animation::ActionGroup::ActionsTree* tree = this->getElementInPosition(secondPosition);
            if(tree){
                //return the action in position
                return tree->getElementInPosition(position);
            }
            return NULL;
        }

        //remove the action
        bool removeActionInSecond(edk::float32 second,edk::Action* action){
            //test the action
            if(action){
                edk::animation::ActionGroup::ActionsTree* tree = this->getActionTree(second);
                if(tree){
                    //remove the action
                    if(tree->remove(action)){
                        //release the action
                        this->actionsTree.releaseAction(action);
                        //test if the tree have nothing
                        this->removeTree(tree);
                        return true;
                    }
                }
            }
            return false;
        }
        //remove the action in position
        bool removeActionInPosition(edk::float32 second,edk::uint32 position){
            edk::animation::ActionGroup::ActionsTree* tree = this->getActionTree(second);
            if(tree){
                //remove the second
                edk::Action* temp = tree->getElementInPosition(position);
                if(temp){
                    if(tree->remove(temp)){
                        //release the action
                        this->actionsTree.releaseAction(temp);
                        //test if the tree have nothing
                        this->removeTree(tree);
                        return true;
                    }
                }
            }
            return false;
        }
        //remove the second
        bool cleanActionsInSecond(edk::float32 second){
            edk::animation::ActionGroup::ActionsTree* tree = this->getActionTree(second);
            if(tree){
                edk::float32 size = tree->size();
                edk::uint32 position=0u;
                edk::Action* temp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    temp = tree->getElementInPosition(position);
                    if(temp){
                        if(!tree->remove(temp))
                            position++;
                        this->actionsTree.releaseAction(temp);
                    }
                }
                tree->clean();
                if(this->remove(tree)){
                    delete tree;
                    return true;
                }
            }
            return false;
        }
        //clean all actions in all seconds
        void cleanActions(){
            edk::uint32 size = this->size();
            edk::uint32 position = 0u;
            edk::animation::ActionGroup::ActionsTree* tree = NULL;
            for(edk::uint32 i=0u;i<size;i++){
                tree = this->getElementInPosition(position);
                if(tree){
                    if(!this->cleanActionsInSecond(tree->getSecond())){
                        position++;
                    }
                }
            }
        }

    private:
        bool canDeleteTree;
        edk::animation::ActionGroup::ActionsTree* getActionTree(edk::float32 second){
            edk::animation::ActionGroup::ActionsTree find(second);
            return this->getElement(&find);
        }
        //remove the tree if have nothing
        void removeTree(edk::animation::ActionGroup::ActionsTree* tree){
            if(!tree->size()){
                if(this->remove(tree)){
                    delete tree;
                }
            }
        }
        //tree to save all the actions used
        class TreeActions: public edk::vector::BinaryTree<edk::animation::ActionGroup::ActionReferenceCount*>{
        public:
            TreeActions(){}
            virtual ~TreeActions(){
            }

            //compare if the value is bigger
            virtual bool firstBiggerSecond(edk::animation::ActionGroup::ActionReferenceCount* first,edk::animation::ActionGroup::ActionReferenceCount* second){
                if(first->getAction()>second->getAction())
                    return true;
                return false;
            }
            bool firstEqualSecond(edk::animation::ActionGroup::ActionReferenceCount* first,edk::animation::ActionGroup::ActionReferenceCount* second){
                if(first->getAction()==second->getAction())
                    return true;
                return false;
            }

            //add an action
            bool addAction(edk::Action* action){
                if(action){
                    //find the action
                    edk::animation::ActionGroup::ActionReferenceCount* temp = this->getReferenceCount(action);
                    if(temp){
                        //just increment the reference count
                        temp->retain();
                        return true;
                    }
                    else{
                        //else create a new temp
                        temp = new edk::animation::ActionGroup::ActionReferenceCount(action);
                        if(temp){
                            //add the temp to the tree
                            if(this->add(temp)){
                                temp->retain();
                                return true;
                            }
                            delete temp;
                        }
                    }
                }
                return false;
            }
            //remove the action
            bool releaseAction(edk::Action* action){
                //test the action
                if(action){
                    edk::animation::ActionGroup::ActionReferenceCount* temp = this->getReferenceCount(action);
                    if(temp){
                        //release the temp
                        if(!temp->release()){
                            this->remove(temp);
                            //then need to be deleted
                            edk::Action* action = temp->getAction();
                            if(action) delete action;
                            delete temp;
                        }
                        return true;
                    }
                }
                return false;
            }
            bool removeAction(edk::Action* action){
                //test the action
                if(action){
                    edk::animation::ActionGroup::ActionReferenceCount* temp = this->getReferenceCount(action);
                    if(temp){
                        //release the temp
                        this->remove(temp);
                        delete temp;
                        return true;
                    }
                }
                return false;
            }

        private:
            edk::animation::ActionGroup::ActionReferenceCount* getReferenceCount(edk::Action* action){
                edk::animation::ActionGroup::ActionReferenceCount find(action);
                return this->getElement(&find);
            }
        }actionsTree;
    }tree;
};
}//end namespace animation
}//end namespace edk

#endif // ACTIONGROUP_H
