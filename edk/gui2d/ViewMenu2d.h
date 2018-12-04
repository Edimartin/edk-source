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
    bool loadObject(edk::char8* spriteName,edk::char8* text1,edk::char8* text2);

    //set the button position
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec2f32 position);
    //set size
    bool setSize(edk::size2f32 size);
    bool setSize(edk::float32 width,edk::float32 height);
    //get the size
    edk::size2f32 getSize();
    //update the sizes
    void updateSizes();

    void draw();
private:
    //object to be render
    edk::Object2D obj;
    edk::shape::Mesh2D meshObj;
    //sprite to be added on the obj
    edk::Object2D sprite;
    //text to be render to the object
    edk::fonts::FontMap text1;
    edk::float32 positionText1;
    edk::fonts::FontMap text2;
    edk::float32 positionText2;
    //status of the button
    edk::gui2d::gui2dTexture status;
    edk::gui2d::gui2dTexture saveStatus;

    void updatePositions();

public:
    //menu colors
    edk::color4f32 color[edk::gui2d::gui2dTextureSize];
};

class ViewMenu2d : public edk::ViewGU2D{
public:
    ViewMenu2d();
    virtual ~ViewMenu2d();

    //create a new object
    edk::uint32 newObject(edk::char8* spriteName,edk::char8* text1,edk::char8* text2);
    edk::uint32 newObject(const edk::char8* spriteName,const edk::char8* text1,const edk::char8* text2);
    //return the size of objects inside the stack
    edk::uint32 getObjectsSize();
    //set the order to X
    void setOrderX();
    //set the order to Y
    void setOrderY();
    //return if is orderX
    bool isOrderX();
    bool iOrderY();

    void load(edk::rectf32 outsideViewOrigin);
    void unload();
    void update(edk::WindowEvents* events);
    void drawScene(edk::rectf32 outsideViewOrigin);
private:
    //save if the menu is ordered on X
    bool xOrder;
    //obj positions
    edk::vec2f32 positions;

    edk::Object2D temp;

    //
    edk::vector::Stack<edk::gui2d::MenuObj*> objs;
    //save the frame
    edk::rectf32 saveFrame;

    //update camera size and position to have all the objects
    void updateCamera();
    //update the objects positions
    void updatePositions();
};
}//end namespace gui2d
}//end namespace edk

#endif // VIEWMENU2D_H
