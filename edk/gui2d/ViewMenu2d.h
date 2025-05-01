#ifndef VIEWMENU2D_H
#define VIEWMENU2D_H

/*
ViewMenu2d - View to show a menu on GUI 2D library
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
#pragma message "Inside gui2d::ViewMenu2d"
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
#include "../pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::ViewMenu2d"
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

    void Constructor();
    void Destructor();

    //get the type
    virtual edk::gui2d::gui2dTypes getType();

    //load the object
    bool loadObject(edk::uint32 id,edk::char8* spriteName,edk::char8* text1,edk::char8* text2);
    bool loadObject(edk::uint32 id,const edk::char8* spriteName,edk::char8* text1,edk::char8* text2);
    bool loadObjectFromPack(edk::pack::FilePackage* pack,edk::uint32 id,edk::char8* spriteName,edk::char8* text1,edk::char8* text2);
    bool loadObjectFromPack(edk::pack::FilePackage* pack,edk::uint32 id,const edk::char8* spriteName,edk::char8* text1,edk::char8* text2);

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
private:
    edk::classID classThis;
};
class ViewMenu2d;
class Menu2dCallback{
public:
    virtual void enable(edk::gui2d::ViewMenu2d* menu, edk::gui2d::MenuObj* obj)=0;
    virtual void exec(edk::gui2d::ViewMenu2d* menu, edk::gui2d::MenuObj* obj)=0;
    virtual void disable(edk::gui2d::ViewMenu2d* menu, edk::gui2d::MenuObj* obj)=0;
};

class ViewMenu2d : public edk::ViewGU2D{
public:
    ViewMenu2d();
    virtual ~ViewMenu2d();

    void Constructor();
    void Destructor();

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

    //set the menu colors
    void setColorNormal(edk::color3f32 color);
    void setColorNormal(edk::color4f32 color);
    void setColorNormal(edk::float32 r,edk::float32 g,edk::float32 b);
    void setColorNormal(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setColorUp(edk::color3f32 color);
    void setColorUp(edk::color4f32 color);
    void setColorUp(edk::float32 r,edk::float32 g,edk::float32 b);
    void setColorUp(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setColorPressed(edk::color3f32 color);
    void setColorPressed(edk::color4f32 color);
    void setColorPressed(edk::float32 r,edk::float32 g,edk::float32 b);
    void setColorPressed(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setColorPressedUp(edk::color3f32 color);
    void setColorPressedUp(edk::color4f32 color);
    void setColorPressedUp(edk::float32 r,edk::float32 g,edk::float32 b);
    void setColorPressedUp(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

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

    //menu colors
    edk::color4f32 color[edk::gui2d::gui2dTextureSize];

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

    edk::gui2d::MenuObj* objSelected;

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
    void selectObject(edk::uint32 position,edk::int32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);
private:
    edk::classID classThis;
};
}//end namespace gui2d
}//end namespace edk

#endif // VIEWMENU2D_H
