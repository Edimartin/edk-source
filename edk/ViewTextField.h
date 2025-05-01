#ifndef VIEWTEXTFIELD_H
#define VIEWTEXTFIELD_H

/*
Library C++ ViewTextField - Entry text
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
#pragma message "Inside ViewTextField"
#endif

#pragma once
#include "ViewText.h"
#include "ViewMenu.h"
#include "fonts/FontMap.h"
#include "animation/Interpolation1DGroup.h"

#ifdef printMessages
#pragma message "    Compiling ViewTextField"
#endif

namespace edk{
class ViewTextField: public edk::ViewMenu{
public:
    ViewTextField();
    virtual ~ViewTextField();

    void Constructor();
    void Destructor();

    void load(rectf32 outsideViewOrigin);
    void unload();
    void update(edk::WindowEvents* events);

    //create a string
    bool createString(const edk::char8* string);
    bool createString(edk::char8* string);
    //get the string
    edk::char8* getString();
    //return the size of the string
    edk::uint32 getStringSize();
    //clean the string
    void cleanString();
    //add a character
    bool addCharacter(edk::char8 c);
    //remove the caracter
    bool removeCharacter();
    //delete the character
    bool deleteCharacter();
    //test if press enter
    bool havePressReturn();
    //Set the writer position
    void setWritePosition(edk::uint32 position);
    //return true if is selected
    bool isSelected();
    //test if the mouse is inside
    bool isMouseInside();
private:
    //save rect
    edk::rectf32 saveRect;

    //Text View
    class TextField: public edk::ViewText{
    public:
        TextField();
        virtual ~TextField();

        void Constructor();
        void Destructor();

        void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
        void eventMouseMoved(edk::vec2f32 point,edk::vec2f32 moved,edk::uint32 button);
        void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);
        void eventMouseDoubleClicked(edk::vec2f32 point,edk::uint32 button);

        void load(rectf32 outsideViewOrigin);
        void unload();
        void update(edk::WindowEvents* events);
        void update(edk::WindowEvents* events,edk::float32 seconds);
        //draw the GU scene
        void drawScene(rectf32 outsideViewOrigin);

        //test if a point is inside the view
        bool pointInside(edk::vec2f32 point);

        //set writePosition
        void setWritePosition(edk::uint32 position);
        //delete the string
        void deleteString();
        //copy the string
        bool setString(edk::char8* string);
        //add a characted
        bool addCharacter(edk::char8 c);
        bool addCharacterFromString(const edk::char8* str);
        bool addCharacterFromString(edk::char8* str);
        //remove the caracter
        bool removeCharacter();
        //delete the character
        bool deleteCharacter();
        //return the string
        edk::char8* getString();
        edk::uint32 getSizeString();
        //eturn true if the text is selected
        bool isSelected();

        //save border
        edk::float32 saveBorder;
        //test if press enter
        bool pressReturn;
    private:
        //save rect
        edk::rectf32 saveRect;
        edk::rectf32 saveOutsideView;
        //press the mouse inside the view
        bool pressInside;
        //save if is selecting the view
        bool selectView;

        //press quote
        bool pressQuote;
        bool pressTilde;

        //save the string
        edk::char8* string;
        //string size
        edk::uint32 sizeString;
        //position to write the string
        edk::uint32 writePosition;

        //Set the entryPosition
        bool setEntryPosition(edk::float32 x);

        //TEMP
        edk::Object2D obj;
        //animation to the object
        edk::animation::Interpolation1DGroup anim;
    private:
        edk::classID classThis;
    }text;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // VIEWTEXTFIELD_H
