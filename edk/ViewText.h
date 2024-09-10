#ifndef VIEWTEXT_H
#define VIEWTEXT_H

/*
Library C++ Text - Render Text using ViewGu2D in EDK Game Engine
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
#pragma message "Inside ViewText"
#endif

#pragma once
#include "ViewGU2D.h"
#include "fonts/FontMap.h"

#ifdef printMessages
#pragma message "    Compiling ViewText"
#endif

namespace edk{
class ViewText:public edk::ViewGU2D{
public:
    ViewText();
    virtual ~ViewText();

    void Constructor(bool runFather=true);

    //createString
    bool createString(edk::char8* string);
    bool createString(const edk::char8* string);
    inline bool writeString(edk::char8* string){
        return this->createString(string);
    }
    inline bool writeString(const edk::char8* string){
        return this->createString(string);
    }

    //load the font image
    bool loadFontImage(edk::char8* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    bool loadFontImage(const edk::char8* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));

    //set the color
    void setColor(edk::color4f32 color);
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setAlpha(edk::float32 value);
    void setColor(edk::color4ui8 color);
    void setColor(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    void setAlpha(edk::uint8 value);

    //update the width
    void updateWidth();
    void setScale(edk::size2f32 scale);
    void setScale(edk::float32 width,edk::float32 height);

    //clean the string
    void cleanString();
protected:
    virtual void update(edk::WindowEvents* events);
    virtual void update(edk::WindowEvents* events,edk::float32 seconds);
    //draw the GU scene
    virtual void drawScene(edk::rectf32 outsideViewOrigin);
private:
    void load(edk::rectf32 outsideViewOrigin);
    void unload();

    //rect
    edk::rectf32 rectSave;
    //fontMap
    edk::fonts::FontMap text;
    //save the text lines
    edk::uint32 textLine;
    edk::uint32 saveLine;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // VIEWTEXT_H
