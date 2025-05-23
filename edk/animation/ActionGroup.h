#ifndef ACTIONGROUP_H
#define ACTIONGROUP_H

/*
Library C++ ActionGroup - Animate Actions
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
#pragma message "Inside ActionGroup"
#endif

#pragma once
//Use Actions
#include "../Action.h"
//Use binaryTree's
#include "../vector/BinaryTree.h"
#include "../vector/Stack.h"
//Use one animation
#include "Interpolation1DGroup.h"

#ifdef printMessages
#pragma message "    Compiling ActionGroup"
#endif


/*
FUNCTION EXAMPLE
static edk::Action* newXMLAction(edk::classID thisPointer,edk::uint32 actionCode);
*/

namespace edk{
namespace animation{
class ActionGroup{
public:
    ActionGroup();
    virtual ~ActionGroup();

    void Constructor();
    void Destructor();

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
    void update(edk::float32 seconds);

    //ANIMATION FUNCTIONS
    //get Loop
    bool isLooping();

    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardIn(edk::float32 second);
    void playForward(edk::float32 updateSeconds);
    void playForwardIn(edk::float32 second,edk::float32 updateSeconds);
    //void playRewind();
    //void playRewindIn(edk::float32 second);
    void pause();
    void pauseOn();
    void pauseOff();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();

    //return if are playing
    bool isPlaying();
    bool isPaused();

    bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    bool readFromXML(edk::XML* xml,edk::uint32 id,edk::classID thisPointer=NULL);
    //set readXMLaction funcion
    bool setReadXMLActionFunction(edk::Action*(*readXMLAction)(edk::classID thisPointer,edk::uint32 actionCode));
    //clean readXMLAction function
    void cleanReadXMLActionFunction();

private:
    //animation
    edk::animation::Interpolation1DGroup anim;
    //save the value
    edk::float32 valueTemp;

    //functionPointer
    edk::Action*(*readXMLAction)(edk::classID thisPointer,edk::uint32 actionCode);
    //return the zero action
    static edk::Action* readXMLZero(edk::classID thisPointer,edk::uint32 actionCode);

    //first update
    void firstUpdate();
    void firstUpdate(edk::float32 seconds);

    //create a stack to save the actions
    class ActionsTree : public edk::vector::BinaryTree<edk::Action*>{
    public:
        ActionsTree(edk::float32 second){
            this->classThis=NULL;
            this->Constructor(second);
        }
        virtual ~ActionsTree(){
            this->Destructor();
        }

        void Constructor(edk::float32 second){
            edk::vector::BinaryTree<edk::Action*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
                this->second = second;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->clean();
            }
            edk::vector::BinaryTree<edk::Action*>::Destructor();
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
    private:
        edk::classID classThis;
    };
    class ActionReferenceCount{
    public:
        ActionReferenceCount(edk::Action* action){
            this->classThis=NULL;
            this->Constructor(action);
        }
        virtual ~ActionReferenceCount(){
            this->Destructor();
        }

        void Constructor(edk::Action* action){
            if(this->classThis!=this){
                this->classThis=this;
                count=0u;
                this->action=action;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
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
        edk::Action* getAction(){return this->action; }
    private:
        edk::uint32 count;
        edk::Action* action;
    private:
        edk::classID classThis;
    };

    //create a tree to save the actions
    class ActionStackTree: public edk::vector::BinaryTree<edk::animation::ActionGroup::ActionsTree*>{
    public:
        ActionStackTree(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~ActionStackTree(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::animation::ActionGroup::ActionsTree*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;

                this->actionsTree.Constructor();
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->cleanActions();

                this->actionsTree.Destructor();
            }
            edk::vector::BinaryTree<edk::animation::ActionGroup::ActionsTree*>::Destructor();
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
                        if(!tree->remove(temp)){
                            position++;
                        }
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
            TreeActions(){
                this->classThis=NULL;
                this->Constructor();
            }
            virtual ~TreeActions(){
                this->Destructor();
            }

            void Constructor(){
                edk::vector::BinaryTree<edk::animation::ActionGroup::ActionReferenceCount*>::Constructor();
                if(this->classThis!=this){
                    this->classThis=this;
                }
            }
            void Destructor(){
                if(this->classThis==this){
                    this->classThis=NULL;
                    //can destruct the class
                }
                edk::vector::BinaryTree<edk::animation::ActionGroup::ActionReferenceCount*>::Destructor();
            }

            //compare if the value is bigger
            virtual bool firstBiggerSecond(edk::animation::ActionGroup::ActionReferenceCount* first,edk::animation::ActionGroup::ActionReferenceCount* second){
                if(first->getAction()>second->getAction()){
                    return true;
                }
                return false;
            }
            bool firstEqualSecond(edk::animation::ActionGroup::ActionReferenceCount* first,edk::animation::ActionGroup::ActionReferenceCount* second){
                if(first->getAction()==second->getAction()){
                    return true;
                }
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
                            if(action){
                                delete action;
                            }
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
        private:
            edk::classID classThis;
        }actionsTree;
    private:
        edk::classID classThis;
    }tree;
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // ACTIONGROUP_H
