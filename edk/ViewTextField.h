#ifndef VIEWTEXTFIELD_H
#define VIEWTEXTFIELD_H

/*
Library C++ ViewTextField - Entry text
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
#warning "Inside ViewTextField"
#endif

#pragma once
#include "ViewText.h"
#include "ViewMenu.h"
#include "fonts/FontMap.h"
#include "animation/Interpolation1DGroup.h"

#ifdef printMessages
#warning "    Compiling ViewTextField"
#endif

namespace edk{
class ViewTextField: public edk::ViewMenu{
public:
    ViewTextField();
    ~ViewTextField();

    void load(rectf32 outsideViewOrigin);
    void unload();
    void update(edk::WindowEvents* events);

    //create a string
    bool createString(const char* string);
    bool createString(edk::char8* string);
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
private:
    //save rect
    edk::rectf32 saveRect;

    //Text View
    class TextField: public edk::ViewText{
    public:
        TextField();
        ~TextField();

        void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
        void eventMouseMoved(edk::vec2f32 point,edk::uint32 button);
        void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);

        void load(rectf32 outsideViewOrigin);
        void unload();
        void update(edk::WindowEvents* events);
        //draw the GU scene
        void drawScene(rectf32 outsideViewOrigin);

        //set writePosition
        void setWritePosition(edk::uint32 position);
        //delete the string
        void deleteString();
        //copy the string
        bool setString(edk::char8* string);
        //add a characted
        bool addCharacter(edk::char8 c);
        //remove the caracter
        bool removeCharacter();
        //delete the character
        bool deleteCharacter();

        //save border
        edk::float32 saveBorder;
        //test if press enter
        bool pressReturn;
    private:
        //save rect
        edk::rectf32 saveRect;
        //press the mouse inside the view
        bool pressInside;
        //save if is selecting the view
        bool selectView;

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
    }text;
};
}//end namespace edk

#endif // VIEWTEXTFIELD_H
