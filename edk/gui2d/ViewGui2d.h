#ifndef VIEWGUI2D_H
#define VIEWGUI2D_H

/*
ViewGui2d - View to show the objects on the GUI 2D library
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
#pragma message "Inside gui2d::ViewGui2d"
#endif

#pragma once
#include "ObjectGui2d.h"
#include "../ViewListSelection.h"
#include "../vector/BinaryTree.h"
#include "../vector/Array.h"
#include "TextField2d.h"
#include "../watch/Time.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::ViewGui2d"
#endif


namespace edk{
namespace gui2d{
enum gui2dMouseStatus{
    gui2dMouseNothing=0u,
    gui2dMousePressed,
    gui2dMouseHolded,
    gui2dMouseRelease,
    //
    gui2dMouseStatusSize,
};
class ObjectGui2dCallback{
public:
    virtual void mousePressed(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton)=0;
    virtual void mouseRelease(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton,bool isInside)=0;
    virtual void mouseHolded(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton)=0;
    virtual void returnPressed(edk::gui2d::ObjectGui2d* textField)=0;
};
class ViewGui2d : public edk::ViewGU2D{
public:
    ViewGui2d();
    virtual ~ViewGui2d();

    void Constructor();
    void Destructor();

    //add the object
    bool addObjectGui2d(edk::gui2d::ObjectGui2d* obj);
    //remove the object
    bool removeObjectGui2d(edk::gui2d::ObjectGui2d* obj);
    //remove all objects
    void removeAllObjectGui2d();

    //disable the mouse on the view (Can be used to have only one textField on the view).
    void enableMouse();
    void disableMouse();

    //function used to select an object on the view
    bool selectObject(edk::gui2d::ObjectGui2d* obj);
    void deselectObject();

    //get the volume rect inside the menu
    edk::rectf32 getVolume();

    virtual void update(edk::WindowEvents* events);

    //draw the GU scene
    virtual void drawScene(edk::rectf32 outsideViewOrigin);

    //callback
    bool addCallback(edk::gui2d::ObjectGui2dCallback* callback);
    bool removeCallback(edk::gui2d::ObjectGui2dCallback* callback);
    void cleanCallbacks();
protected:

    void drawSelectionScene();
    void selectObject(edk::uint32 position,edk::int32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);

private:
    edk::uint64 idCounter;
    edk::vector::BinaryTree<edk::uint32>* selectTree;
    edk::vector::BinaryTree<edk::uint32>* selectTreeS;
    edk::vector::BinaryTree<edk::uint32> tree1;
    edk::vector::BinaryTree<edk::uint32> tree2;
    edk::gui2d::ObjectGui2d* objPressed;
    edk::gui2d::ObjectGui2d* objSelected;
    edk::uint32 idSelected;
    bool endSelect;
    edk::gui2d::gui2dMouseStatus mouseStatus;
    bool selectionExec;
    bool shift;
    //press quote
    bool pressQuote;
    bool pressTilde;

    //volume object
    edk::Object2D volume;

    //save if the mouse is enabled or disabled
    bool mouseOn;

    //object to draw the mousePosition
    edk::vec2f32 saveMousePosition;
    edk::vec2f32 mouseDistance;
    bool mouseMoving;

    //save the time to text if have double click
    edk::watch::Time distanceClick;
    edk::watch::Time distanceDoubleClick;
    bool doubleClick;

    //mouse callback
    edk::vector::Stack<edk::gui2d::ObjectGui2dCallback*> listCallback;
    //return true if have the element on the callback list
    bool haveCallback(edk::gui2d::ObjectGui2dCallback* callback);
    //process the callbacks
    void processMousePressed(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton);
    void processMouseRelease(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton,bool isInside);
    void processMouseHolded(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton);
    void processReturnPressed(edk::gui2d::ObjectGui2d* textField);

    class ObjGui2dID{
    public:
        ObjGui2dID(edk::gui2d::ObjectGui2d* pointer,edk::uint64 id){
            this->classThis=NULL;
            this->Constructor(pointer,id);
        }
        virtual ~ObjGui2dID(){
            this->Destructor();
        }

        void Constructor(edk::gui2d::ObjectGui2d* pointer,edk::uint64 id){
            if(this->classThis!=this){
                this->classThis=this;
                this->pointer = pointer;
                this->id = id;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
        }
        //pointe
        edk::gui2d::ObjectGui2d* pointer;
        edk::uint64 id;
    private:
        edk::classID classThis;
    };

    //tree with objects
    class ObjGui2dPointerTree : public edk::vector::BinaryTree<edk::gui2d::ViewGui2d::ObjGui2dID*>{
    public:
        ObjGui2dPointerTree(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~ObjGui2dPointerTree(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::gui2d::ViewGui2d::ObjGui2dID*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::vector::BinaryTree<edk::gui2d::ViewGui2d::ObjGui2dID*>::Destructor();
        }

        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::gui2d::ViewGui2d::ObjGui2dID* first,edk::gui2d::ViewGui2d::ObjGui2dID* second){
            if(first && second){
                if(first->pointer>second->pointer){
                    //
                    return true;
                }
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::gui2d::ViewGui2d::ObjGui2dID* first,edk::gui2d::ViewGui2d::ObjGui2dID* second){
            if(first && second){
                if(first->pointer==second->pointer){
                    //
                    return true;
                }
            }
            return false;
        }
        //Print
        virtual void printElement(edk::gui2d::ViewGui2d::ObjGui2dID* /*value*/){
            //
        }
        virtual void renderElement(edk::gui2d::ViewGui2d::ObjGui2dID* /*value*/){
            //
        }
        //UPDATE
        virtual void updateElement(edk::gui2d::ViewGui2d::ObjGui2dID* /*value*/){
            //
        }
        //get the object by the object
        edk::gui2d::ViewGui2d::ObjGui2dID* getObjectByPointer(edk::gui2d::ObjectGui2d* pointer){
            if(pointer){
                edk::gui2d::ViewGui2d::ObjGui2dID search(pointer,0u);
                return this->getElement(&search);
            }
            return NULL;
        }
    private:
        edk::classID classThis;
    };
    //tree with objects
    class ObjGui2dIDTree : public edk::vector::BinaryTree<edk::gui2d::ViewGui2d::ObjGui2dID*>{
    public:
        ObjGui2dIDTree(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~ObjGui2dIDTree(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::gui2d::ViewGui2d::ObjGui2dID*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;

                this->tree.Constructor();

                this->cleanPressed=false;
                this->startUpdateVolume=false;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->removeAll();

                this->tree.Destructor();
            }
            edk::vector::BinaryTree<edk::gui2d::ViewGui2d::ObjGui2dID*>::Destructor();
        }
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::gui2d::ViewGui2d::ObjGui2dID* first,edk::gui2d::ViewGui2d::ObjGui2dID* second){
            if(first && second){
                if(first->id>second->id){
                    //
                    return true;
                }
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::gui2d::ViewGui2d::ObjGui2dID* first,edk::gui2d::ViewGui2d::ObjGui2dID* second){
            if(first && second){
                if(first->id==second->id){
                    //
                    return true;
                }
            }
            return false;
        }
        //Print
        virtual void printElement(edk::gui2d::ViewGui2d::ObjGui2dID* value){
            if(value->pointer->getTypeGUI() != edk::gui2d::gui2dTypeText){
                //draw the element for selection
                edk::GU::guPushName(value->id);
                value->pointer->drawSelection();
                edk::GU::guPopName();
            }
        }
        virtual void renderElement(edk::gui2d::ViewGui2d::ObjGui2dID* value){
            //
            value->pointer->draw();
        }
        //UPDATE
        virtual void updateElement(edk::gui2d::ViewGui2d::ObjGui2dID* value){
            //
            value->pointer->update();
            if(this->cleanPressed){
                value->pointer->pressed = false;
            }

            //test if are updating the volume for the first time
            if(this->startUpdateVolume){
                //
                edk::rectf32 temp = edk::rectf32(value->pointer->position.x - (value->pointer->size.width * 0.5f),
                                                 value->pointer->position.y - (value->pointer->size.height * 0.5f),
                                                 value->pointer->position.x + (value->pointer->size.width * 0.5f),
                                                 value->pointer->position.y + (value->pointer->size.height * 0.5f)
                                                 );
                if(temp.origin.x<this->volume.origin.x){
                    this->volume.origin.x = temp.origin.x;
                }
                if(temp.origin.y<this->volume.origin.y){
                    this->volume.origin.y = temp.origin.y;
                }
                temp.size.width = temp.size.width-this->volume.origin.x;
                if(temp.size.width>this->volume.size.width){
                    this->volume.size.width = temp.size.width;
                }
                temp.size.height = temp.size.height-this->volume.origin.y;
                if(temp.size.height>this->volume.size.height){
                    this->volume.size.height = temp.size.height;
                }
            }
            else{
                this->startUpdateVolume = true;
                this->volume = edk::rectf32(value->pointer->position.x - (value->pointer->size.width * 0.5f),
                                            value->pointer->position.y - (value->pointer->size.height * 0.5f),
                                            value->pointer->size.width,
                                            value->pointer->size.height
                                            );
            }
        }
        //add a new ObjectGui2d to the tree
        bool addNewObj(edk::gui2d::ObjectGui2d* obj,edk::uint64 id){
            if(obj){
                //create a new objectID
                edk::gui2d::ViewGui2d::ObjGui2dID* objID = new edk::gui2d::ViewGui2d::ObjGui2dID(obj,id);
                if(objID){
                    //first add to the tree
                    if(this->tree.add(objID)){
                        //then add to this tree
                        if(this->add(objID)){
                            return true;
                        }
                    }
                    delete objID;
                }
            }
            return false;
        }
        //test if have a object
        bool haveObjByID(edk::uint64 id){
            edk::gui2d::ViewGui2d::ObjGui2dID search(NULL,id);
            edk::gui2d::ViewGui2d::ObjGui2dID* have = this->getElement(&search);
            if(have){
                return this->tree.haveElement(have);
            }
            return false;
        }
        bool haveObjByPointer(edk::gui2d::ObjectGui2d* obj){
            edk::gui2d::ViewGui2d::ObjGui2dID search(obj,0u);
            edk::gui2d::ViewGui2d::ObjGui2dID* have = this->tree.getElement(&search);
            if(have){
                return this->haveElement(have);
            }
            return false;
        }
        //get the object
        edk::gui2d::ViewGui2d::ObjGui2dID* getObjectByID(edk::uint64 id){
            edk::gui2d::ViewGui2d::ObjGui2dID search(NULL,id);
            return this->getElement(&search);
        }
        edk::gui2d::ViewGui2d::ObjGui2dID* getObjectByPointer(edk::gui2d::ObjectGui2d* obj){
            edk::gui2d::ViewGui2d::ObjGui2dID search(obj,0u);
            return this->tree.getElement(&search);
        }
        //get pointer and id
        edk::gui2d::ObjectGui2d* getPointerByID(edk::uint64 id){
            edk::gui2d::ViewGui2d::ObjGui2dID search(NULL,id);
            edk::gui2d::ViewGui2d::ObjGui2dID* ret = this->getElement(&search);
            if(ret){
                return ret->pointer;
            }
            return NULL;
        }
        //get pointer and id
        edk::gui2d::ObjectGui2d* getPointerInPosition(edk::uint32 position){
            edk::gui2d::ViewGui2d::ObjGui2dID* ret = this->getElementInPosition(position);
            if(ret){
                return ret->pointer;
            }
            return NULL;
        }
        edk::uint64 getIdByPointer(edk::gui2d::ObjectGui2d* obj){
            edk::gui2d::ViewGui2d::ObjGui2dID search(obj,0u);
            edk::gui2d::ViewGui2d::ObjGui2dID* ret = this->tree.getElement(&search);
            if(ret){
                return ret->id;
            }
            return 0u;
        }
        //remove the object
        bool removeByPointer(edk::gui2d::ObjectGui2d* obj){
            return this->removeObj(this->getObjectByPointer(obj));
        }
        bool removeByID(edk::uint64 id){
            return this->removeObj(this->getObjectByID(id));
        }
        //remove all objectID's
        void removeAll(){
            edk::uint32 size = this->getSize();
            edk::gui2d::ViewGui2d::ObjGui2dID* obj = NULL;
            for(edk::uint32 i=0u;i<size;i++){
                //
                obj = this->getElementInPosition(0u);
                if(obj){
                    this->removeByPointer(obj->pointer);
                }
            }
            this->clean();
            this->tree.clean();
        }
        bool cleanPressed;
        //volume rectangle to fill al the objects inside
        bool startUpdateVolume;
        edk::rectf32 volume;
    private:
        //clean the objects pressed
        edk::gui2d::ViewGui2d::ObjGui2dPointerTree tree;
        bool removeObj(edk::gui2d::ViewGui2d::ObjGui2dID* obj){
            if(obj){
                this->remove(obj);
                this->tree.remove(obj);
                delete obj;
                return true;
            }
            return false;
        }
    private:
        edk::classID classThis;
    }list;
private:
    edk::classID classThis;
};
}//end namespace gui2d
}//end namespace edk

#endif // VIEWGUI2D_H
