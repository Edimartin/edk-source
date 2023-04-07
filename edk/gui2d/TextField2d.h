#ifndef TEXTFIELD2D_H
#define TEXTFIELD2D_H

/*
TextField2d - TextField2d for the GUI 2D library
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
#pragma message "Inside gui2d::TextField2d"
#endif

#pragma once
#include "../Object2DValues.h"
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../vector/BinaryTree.h"
#include "../fonts/FontMap.h"
#include "../NameClass.h"
#include "../BinaryConverter.h"
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::TextField2d"
#endif

//define the cursor second animation
#define edkGU2dCursorSecond 1.f
#define edkGU2dCursorWidthPercent 0.2f

namespace edk{
namespace gui2d{
enum Case{
    upperAndLowerCase=0,
    upperCase=1,
    lowerCase=2,
};
class TextField2d: public edk::gui2d::ObjectGui2d{
public:
    TextField2d();
    virtual ~TextField2d();

    //get the type
    virtual edk::gui2d::gui2dTypes getType();
    //clean all characters
    void cleanCharacters();

    //save the FontTemplate
    static bool saveTemplate(const edk::char8* folder);
    static bool saveTemplate(edk::char8* folder);

    //load the button textures and meshes
    bool load();
    void unload();
    void update();

    //enable and disable the background draw
    void enableBackground();
    void disableBackground();
    bool haveDrawBackground();

    //set the textLimit. Use zero to unlimited
    void setCharacterLimit(edk::uint32 limit);

    //set border size
    bool setBorderSize(edk::float32 size);
    bool setStatus(edk::gui2d::gui2dTexture status);
    //set the color of the font and cursor
    void setFontColor(edk::color4f32 fontColor);
    void setFontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    //select functions
    void select();
    void deselect();
    //click to select an polygon inside the object
    void clickStart(edk::uint32 name);
    void clickMove(edk::uint32 name,bool mouseInside);
    void clickEnd(edk::uint32 name,bool mouseInside,bool doubleClick);

    //set the case
    void setUpperAndLowerCase();
    void setUpperCase();
    void setLowerCase();

    //cursor functions
    void incrementCursor();
    void incrementCursorWithSelect();
    void decrementCursor();
    void decrementCursorWithSelect();
    void moveCursorToEnd();
    void moveCursorToEndWithSelect();
    void moveCursorToStart();
    void moveCursorToStartWithSelect();
    void selectAll();
    //add some character
    bool addCharacter(edk::char8 c);
    bool addString(edk::char8* str);
    bool addString(const edk::char8* str);
    //add characters to the filters
    bool addCharacterFilterIn(edk::char8 c);
    bool addStringFilterIn(edk::char8* str);
    bool addStringFilterIn(const edk::char8* str);
    bool addCharacterFilterOut(edk::char8 c);
    bool addStringFilterOut(edk::char8* str);
    bool addStringFilterOut(const edk::char8* str);
    void cleanFilterIn();
    void cleanFilterOut();

    //write text to clean the originID and cursorID
    bool writeText(const edk::char8* text);
    bool writeText(edk::char8* text);
    bool writeText(const edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(const edk::char8* text,edk::size2f32 scale);
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

    bool drawBackground;
    //save the fontColor
    edk::color4f32 fontColor;

    //save the draw origin position
    edk::uint32 originID;
    edk::uint32 endID;
    edk::uint32 selectionStart;
    edk::uint32 selectionEnd;
    edk::uint32 selectionMiddle;
    edk::uint32 cursorID;
    edk::Object2D cursor;
    edk::shape::Mesh2D meshCursor;
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
        //add a character to the filter
        bool addFilterIn(edk::char8* str);
        bool addFilterIn(edk::char8 c);
        bool addFilterIn(edk::char16 c);
        bool addFilterIn(edk::char32 c);
        void cleanFilterIn();
        bool addFilterOut(edk::char8* str);
        bool addFilterOut(edk::char8 c);
        bool addFilterOut(edk::char16 c);
        bool addFilterOut(edk::char32 c);
        void cleanFilterOut();
        //set the textLimit. Use zero to unlimited
        void setCharacterLimit(edk::uint32 limit);
        //set the caseInput
        void setCaseInput(edk::gui2d::Case caseInput);
    private:
        edk::vector::Stack <edk::char32> vec;
        //Filter some characters who can be inside the text field
        edk::vector::BinaryTree <edk::char32> filterIn;
        //Filter some characters who need be outside the text field (can't be inside the text field)
        edk::vector::BinaryTree <edk::char32> filterOut;
        //character limt on the text field. Use zero to no limit
        edk::uint32 limit;
        //set the inputCase
        edk::gui2d::Case caseInput;
        //return the size of string
        edk::uint32 sizeOfString();
        //return true if the character can be inside the tree
        bool canGetIt(edk::char32 c);
    }textVec;
};
}//end namespace gui2d
}//end namespace edk

#endif // TEXTFIELD2D_H
