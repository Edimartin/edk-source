#ifndef VIEWTEXT_H
#define VIEWTEXT_H

/*
Library C++ Text - Render Text using ViewGu2D in EDK Game Engine
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
#warning "Inside ViewText"
#endif

#pragma once
#include "ViewGU2D.h"
#include "fonts/FontMap.h"

#ifdef printMessages
#warning "    Compiling ViewText"
#endif

namespace edk{
class ViewText:public edk::ViewGU2D{
public:
    ViewText();
    ~ViewText();

    //createString
    bool createString(edk::char8* string);
    bool createString(const char* string);
protected:
    virtual void update(edk::WindowEvents* events);
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
};
}//end namespace edk

#endif // VIEWTEXT_H
