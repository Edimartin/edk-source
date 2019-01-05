#ifndef TEXTFIELD2D_H
#define TEXTFIELD2D_H

/*
TextField2d - TextField2d for the GUI 2D library
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
#warning "Inside gui2d::TextField2d"
#endif

#pragma once
#include "../Object2DValues.h"
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../ViewSprite.h"
#include "../vector/BinaryTree.h"
#include "../fonts/FontMap.h"
#include "../NameClass.h"
#include "../BinaryConverter.h"
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#warning "    Compiling gui2d::TextField2d"
#endif

//define the cursor second animation
#define edkGU2dCursorSecond 1.f
#define edkGU2dCursorWidthPercent 0.2f

namespace edk{
namespace gui2d{
class TextField2d: public edk::gui2d::ObjectGui2d{
public:
    TextField2d();
    virtual ~TextField2d();

    //get the type
    virtual edk::gui2d::gui2dTypes getType();

    //load the button textures and meshes
    bool load();
    void unload();
    void update();

    //set border size
    bool setBorderSize(edk::float32 size);
    bool setStatus(edk::gui2d::gui2dTexture status);
    //select functions
    void select();
    void deselect();
    //click to select an polygon inside the object
    void clickStart(edk::uint32 name);
    void clickMove(edk::uint32 name,bool mouseInside);
    void clickEnd(edk::uint32 name,bool mouseInside);

    //cursor functions
    void incrementCursor();
    void incrementCursorWithSelect();
    void decrementCursor();
    void decrementCursorWithSelect();
    void moveCursorToEnd();
    void moveCursorToEndWithSelect();
    void moveCursorToStart();
    void moveCursorToStartWithSelect();
    //add some character
    bool addCharacter(edk::char8 c);
    bool addString(edk::char8* str);
    bool addString(const edk::char8* str);

    //write text to clean the originID and cursorID
    bool writeText(const char* text);
    bool writeText(edk::char8* text);
    bool writeText(const char* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(const char* text,edk::size2f32 scale);
    bool writeText(edk::char8* text,edk::size2f32 scale);
    void cleanText();
    //remove or delete characters
    void deleteCharacter();
    void removeCharacter();
    //get string writed
    edk::char8* getText();
    //get string size
    edk::uint32 getTextSize();

    //draw the button
    void draw();
    void drawSelection();
private:
    void updateTextSize(edk::size2f32 sizeText,edk::size2f32 centerSize,edk::size2ui32 mapSize);
    void cleanTextVariables(edk::char8* newText);
    //remove a character from the vec and update the text
    bool removeCharacter(edk::uint32 position);
    //update the selection values with the cursor
    void updateSelection();

    //save the draw origin position
    edk::uint32 originID;
    edk::uint32 endID;
    edk::uint32 selectionStart;
    edk::uint32 selectionEnd;
    edk::uint32 selectionMiddle;
    edk::uint32 cursorID;
    edk::Object2D cursor;
    edk::size2f32 saveCursorSize;
    edk::Object2D selection;
    edk::Object2D selectionInside;
    //character map
    class TextVec{
    public:
        TextVec();
        ~TextVec();
        void clean();
        bool write(edk::char8* str);
        edk::uint32 add(edk::char8* str,edk::uint32 position);
        edk::uint32 add(edk::char8 c,edk::uint32 position);
        edk::uint32 add(edk::char16 c,edk::uint32 position);
        edk::uint32 add(edk::char32 c,edk::uint32 position);
        bool remove(edk::uint32 position);
        bool remove(edk::uint32 position,edk::uint32 times);
        edk::char8* getString();
        edk::char8* getStringWithLastSpace();
        edk::uint32 getSize();
    private:
        edk::vector::Stack <edk::char32> vec;
        edk::uint32 sizeOfString();
    }textVec;
};
}//end namespace gui2d
}//end namespace edk

#endif // TEXTFIELD2D_H
