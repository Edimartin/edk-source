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
#include "Button2D.h"
#include "ScrollBar2d.h"
#include "Text2D.h"
#include "TextField2d.h"
#include "../ViewScrollBar.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::ViewGui2d"
#endif

//defines XML names
#define EDK_GUI2D_XML_VIEW "gui2dView_"
#define EDK_GUI2D_XML_TABLE "gui2dTable_"
#define EDK_GUI2D_XML_TABLE_MOVE "tableMove_"

#define scrollSizePixels 20u

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
enum gui2dTableMove{
    gui2dTableMoveNoWay=0u,
    gui2dTableMoveTwoWays,
    gui2dTableMoveHorizontal,
    gui2dTableMoveVertical,
    //
    gui2dTableMoveSize,
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

    void clean();

    //add the object
    bool addObjectGui2d(edk::gui2d::ObjectGui2d* obj);
    //remove the object
    bool removeObjectGui2d(edk::gui2d::ObjectGui2d* obj);
    //remove all objects
    void removeAllObjectGui2d();
    void deleteAllObjectGui2d();
    //get the size of objects inside the view
    edk::uint32 getObjectGui2dSize();
    inline edk::uint32 getSizeObjectsGui2d(){
        return getObjectGui2dSize();
    }
    //get the object
    edk::gui2d::ObjectGui2d* getObjectInPosition(edk::uint32 position);
    //get object by name
    edk::gui2d::ObjectGui2d* getObjectByName(const edk::char8* name);
    edk::gui2d::ObjectGui2d* getObjectByName(edk::char8* name);
    bool printAllObjectNames();

    //disable the mouse on the view (Can be used to have only one textField on the view).
    void enableMouse();
    void disableMouse();

    //function used to select an object on the view
    bool selectObject(edk::gui2d::ObjectGui2d* obj);
    void deselectObject();
    inline void deselect(){
        this->deselectObject();
    }

    //set the table position and size
    bool setTableRectPointsFromCamera();
    bool setTableRectPoints(edk::rectf32 table);
    bool setTableRectPositionAndSize(edk::rectf32 table);
    bool setTablePositionAndSize(edk::vec2f32 position,edk::size2f32 size);
    bool setTablePositionAndSize(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height);
    bool setTablePoints(edk::vec2f32 point1,edk::vec2f32 point2);
    bool setTablePoints(edk::float32 p1x,edk::float32 p1Y,edk::float32 p2X,edk::float32 p2Y);
    edk::rectf32 getTableRectPoints();
    edk::rectf32 getTableRectPostionAndSize();
    //set the table way
    bool setTableMoveWay(edk::gui2d::gui2dTableMove move);
    bool setTableMoveNoWay();
    bool setTableMoveTwoWays();
    bool setTableMoveHorizontal();
    bool setTableMoveVertical();
    edk::gui2d::gui2dTableMove getTableMoveWay();
    bool haveTableMoveNoWay();
    bool haveTableMoveTwoWays();
    bool haveTableMoveHorizontal();
    bool haveTableMoveVertical();
    //move the camera over the table
    void moveCameraPercent(edk::vec2f32 percent);
    void moveCameraPercentVertical(edk::float32 percentY);
    void moveCameraPercentHorizontal(edk::float32 percentX);

    //get the volume rect inside the menu
    edk::rectf32 getVolume();

    void resize(edk::rectf32 outsideViewOrigin);

    virtual void update(edk::WindowEvents* events);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);
    virtual bool writeToXML(const edk::char8* name,edk::uint32 id);
    virtual bool writeToXML(edk::char8* name,edk::uint32 id);
    virtual bool readFromXML(const edk::char8* name,edk::uint32 id);
    virtual bool readFromXML(edk::char8* name,edk::uint32 id);

    //draw the GU scene
    virtual void drawScene(edk::rectf32 outsideViewOrigin);

    //callback
    bool addCallback(edk::gui2d::ObjectGui2dCallback* callback);
    bool removeCallback(edk::gui2d::ObjectGui2dCallback* callback);
    void cleanCallbacks();

    //clone the gui object from
    virtual bool cloneFrom(edk::gui2d::ViewGui2d* obj);
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

    edk::rectf32 table;
    edk::size2f32 tableSize;
    edk::gui2d::gui2dTableMove tableMove;
    //camera move points
    edk::rectf32 rectMoveCamera;
    edk::vec2f32 percentMoveCamera;
    edk::vec2f32 percentMoveSpeed;
    edk::uint8 useScroll;
    edk::ViewScrollBar scrollH,scrollV;
    edk::float32 savePercentH,savePercentV;

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

    //update the camera in view from the table
    void updateCameraFromTable();
    void updateCameraPercentPosition();

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
        void deleteAll(){
            edk::uint32 size = this->getSize();
            edk::gui2d::ViewGui2d::ObjGui2dID* obj = NULL;
            for(edk::uint32 i=0u;i<size;i++){
                //
                obj = this->getElementInPosition(0u);
                if(obj){
                    this->removeByPointer(obj->pointer);
                    delete obj;
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

    //tree with object names
    class TreeObjectNames: public edk::vector::BinaryTree<edk::gui2d::ObjectGui2d*>{
    public:
        TreeObjectNames(){}
        ~TreeObjectNames(){}

        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::gui2d::ObjectGui2d* first,edk::gui2d::ObjectGui2d* second){
            if(edk::String::strBiggerStr(first->getName(),second->getName())){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::gui2d::ObjectGui2d* first,edk::gui2d::ObjectGui2d* second){
            if(edk::String::strCompare(first->getName(),second->getName())){
                return true;
            }
            return false;
        }

        //Print
        virtual void printElement(edk::gui2d::ObjectGui2d* value){
            printf("\n%s",value->getName());
        }

        bool addName(edk::gui2d::ObjectGui2d* obj){
            if(obj){
                //add the object into the names
                edk::uint32 counter = 1u;
                edk::char8* strID=NULL;
                edk::char8* strName=NULL;
                edk::Name oldName = obj->getName();
                //test if can add the object in the name tree
                while(!this->add(obj)){
                    strID = edk::String::uint32ToStr(counter);
                    if(strID){
                        strName = edk::String::strCatMulti(oldName.getName()," (",strID,")",NULL);
                        if(strName){
                            obj->setName(strName);
                            free(strName);
                        }
                        else{
                            free(strID);
                            return false;
                        }
                        free(strID);
                    }
                    counter++;
                }
                return true;
            }
            return false;
        }
    }names;

    edk::gui2d::ObjectGui2d nameTemplate;
private:
    edk::classID classThis;
};
}//end namespace gui2d
}//end namespace edk

#endif // VIEWGUI2D_H
