#ifndef VIEWGUI2D_H
#define VIEWGUI2D_H

#include "ObjectGui2d.h"
#include "../ViewListSelection.h"
#include "../vector/BinaryTree.h"
#include "../vector/Array.h"

namespace edk{
namespace gui2d{
class ObjectGui2dCallback{
public:
    virtual void mousePressed(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton)=0;
    virtual void mouseRelease(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton,bool isInside)=0;
    virtual void mouseHolded(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton)=0;
};
class ViewGui2d : public edk::ViewGU2D{
public:
    ViewGui2d();
    ~ViewGui2d();

    //add the object
    bool addObjectGui2d(edk::gui2d::ObjectGui2d* obj);
    //remove the object
    bool removeObjectGui2d(edk::gui2d::ObjectGui2d* obj);
    //remove all objects
    void removeAllObjectGui2d();

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
    edk::vec2f32 objPressedPosition;
    bool mousePressed;
    bool mouseHolded;
    bool mouseRelease;
    bool selectionExec;

    //object to draw the mousePosition
    edk::vec2f32 saveMousePosition;
    edk::vec2f32 mouseDistance;
    bool mouseMoving;

    //mouse callback
    edk::vector::Stack<edk::gui2d::ObjectGui2dCallback*> listCallback;
    //return true if have the element on the callback list
    bool haveCallback(edk::gui2d::ObjectGui2dCallback* callback);
    //process the callbacks
    void processMousePressed(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton);
    void processMouseRelease(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton,bool isInside);
    void processMouseHolded(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton);

    class ObjGui2dID{
    public:
        ObjGui2dID(edk::gui2d::ObjectGui2d* pointer,edk::uint64 id){
            this->pointer = pointer;
            this->id = id;
        }
        ~ObjGui2dID(){}
        //pointe
        edk::gui2d::ObjectGui2d* pointer;
        edk::uint64 id;
    };

    //tree with objects
    class ObjGui2dPointerTree : public edk::vector::BinaryTree<edk::gui2d::ViewGui2d::ObjGui2dID*>{
    public:
        ObjGui2dPointerTree(){}
        ~ObjGui2dPointerTree(){}
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
    };
    //tree with objects
    class ObjGui2dIDTree : public edk::vector::BinaryTree<edk::gui2d::ViewGui2d::ObjGui2dID*>{
    public:
        ObjGui2dIDTree(){this->cleanPressed=false;}
        ~ObjGui2dIDTree(){}
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
            //draw the element for selection
            edk::GU::guPushName(value->id);
            value->pointer->drawSelection();
            edk::GU::guPopName();
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
        edk::uint64 haveObjByPointer(edk::gui2d::ObjectGui2d* obj){
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
    }list;
};
}//end namespace gui2d
}//end namespace edk

#endif // VIEWGUI2D_H
