#ifndef VIEWMENU2D_H
#define VIEWMENU2D_H

/*
ViewMenu2d - View to show a menu on GUI 2D library
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
#warning "Inside gui2d::ViewMenu2d"
#endif

#pragma once
#include "../ViewGU2D.h"
#include "../Object2D.h"
#include "../fonts/FontMap.h"
#include "../ViewScrollBar.h"
#include "../vector/BinaryTree.h"
#include "../vector/Stack.h"
#include "ObjectGui2dBorder.h"
#include "../String.h"
#include "ViewGui2d.h"
#include "../NameClass.h"

#ifdef printMessages
#warning "    Compiling gui2d::ViewMenu2d"
#endif

#define edkGui2dInsideHeight 0.75f
#define edkGui2dInsideBorder 0.25f

namespace edk{
namespace gui2d{
//object to be added into the menu
class MenuObj{
public:
    MenuObj();
    virtual ~MenuObj();

    //load the object
    bool loadObject(edk::uint32 id,edk::char8* spriteName,edk::char8* text1,edk::char8* text2);

    //set the button position
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec2f32 position);
    //set size
    bool setSize(edk::size2f32 size);
    bool setSize(edk::float32 width,edk::float32 height);
    //get the size
    edk::size2f32 getSize();
    //return the object strings pointer
    edk::char8* getStr1();
    edk::char8* getStr2();
    //update the sizes
    void updateSizes();
    //set the status of the object to be draw
    bool setStatus(edk::gui2d::gui2dTexture status);

    void draw();
    void drawSelection();

    bool active;
    edk::uint32 id;
private:
    //object to be render
    edk::Object2D obj;
    edk::shape::Mesh2D meshObj;
    //save the obj ID only to be setted by the user
    //sprite to be added on the obj
    edk::Object2D sprite;
    //text to be render to the object
    edk::fonts::FontMap text1;
    edk::float32 positionText1;
    edk::Name str1;
    edk::fonts::FontMap text2;
    edk::float32 positionText2;
    edk::Name str2;
    //status of the button
    edk::gui2d::gui2dTexture status;
    edk::gui2d::gui2dTexture saveStatus;

    void updatePositions();

public:
    //menu colors
    edk::color4f32 color[edk::gui2d::gui2dTextureSize];
};

class Menu2dCallback{
public:
    virtual void enable(edk::gui2d::MenuObj* obj)=0;
    virtual void exec(edk::gui2d::MenuObj* obj)=0;
    virtual void disable(edk::gui2d::MenuObj* obj)=0;
};

class ViewMenu2d : public edk::ViewGU2D{
public:
    ViewMenu2d();
    virtual ~ViewMenu2d();

    //create a new object
    edk::uint32 newObject(edk::char8* spriteName,edk::char8* text1,edk::char8* text2,edk::uint32 id=0u);
    edk::uint32 newObject(const edk::char8* spriteName,const edk::char8* text1,const edk::char8* text2,edk::uint32 id=0u);
    //return the object strings pointer
    edk::char8* getObjectStr1(edk::uint32 position);
    edk::char8* getObjectStr2(edk::uint32 position);
    //return the size of objects inside the stack
    edk::uint32 getObjectsSize();
    //set the order to X
    void setOrderX();
    //set the order to Y
    void setOrderY();
    //return if is orderX
    bool isOrderX();
    bool iOrderY();

    virtual void load(edk::rectf32 outsideViewOrigin);
    virtual void unload();
    virtual void update(edk::WindowEvents* events);
    void drawSelectionScene();
    void drawScene(edk::rectf32 outsideViewOrigin);

    //callback
    bool addCallback(edk::gui2d::Menu2dCallback* callback);
    bool removeCallback(edk::gui2d::Menu2dCallback* callback);
    void cleanCallbacks();
private:
    //save if the menu is ordered on X
    bool xOrder;
    //obj positions
    edk::vec2f32 positions;

    edk::Object2D temp;

    //save the mouse status
    edk::gui2d::gui2dMouseStatus mouseStatus;
    //set true if activate the button
    bool mouseActivate;
    bool mouseOn;
    bool runSelection;
    //selection trees
    edk::vector::BinaryTree<edk::uint32>* selectTree;
    edk::vector::BinaryTree<edk::uint32>* selectTreeS;
    edk::vector::BinaryTree<edk::uint32> tree1;
    edk::vector::BinaryTree<edk::uint32> tree2;

    //mouse callback
    edk::vector::Stack<edk::gui2d::Menu2dCallback*> listCallback;
    //return true if have the element on the callback list
    bool haveCallback(edk::gui2d::Menu2dCallback* callback);
    //process the callbacks
    void processEnable(edk::gui2d::MenuObj* obj);
    void processExec(edk::gui2d::MenuObj* obj);
    void processDisable(edk::gui2d::MenuObj* obj);

    //
    edk::vector::Stack<edk::gui2d::MenuObj*> objs;
    //save the frame
    edk::rectf32 saveFrame;

    //update camera size and position to have all the objects
    void updateCamera();
    //update the objects positions
    void updatePositions();
    //process the selection
    void selectObject(edk::uint32 position,edk::uint32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);
};
}//end namespace gui2d
}//end namespace edk

#endif // VIEWMENU2D_H
