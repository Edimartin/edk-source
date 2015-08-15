#ifndef EDK_VIEWBUTTON_H
#define EDK_VIEWBUTTON_H

/*
Library C++ edkButton - Button used in Edk Game Engine
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
#warning "Inside ViewButton"
#endif

#pragma once
#include "TypeDefines.h"
#include "GU/GU.h"
#include "ViewSprite.h"
#include "vector/BinaryTree.h"
#include "Camera2D.h"
#include "fonts/FontMap.h"

#ifdef printMessages
#warning "    Compiling ViewButton"
#endif

/*
//EVENT
//event press button
void eventPressButton(edk::uint32 mouseButton){
    //
    //printf("\nPRESS BUTTON %u",mouseButton);
}
//event releaseButton
void eventReleaseButton(edk::uint32 mouseButton,bool inside){
    //
    //printf("\nRELEASE BUTTON %u",mouseButton);
}
//event holdButton
void eventHoldButton(edk::uint32 mouseButton){
    //
    //printf("\nHOLDING BUTTON %u",mouseButton);
}
//Mouse go Inside Outside
void eventMouseEntryInsideView(edk::vec2f32 point){
    //
}
void eventMouseLeftView(edk::vec2f32 point){
    //
}
void eventMouseMovingInsideView(edk::vec2f32 point){
    //
}
*/

namespace edk{

class ViewButton;
class ButtonCallback{
public:
    virtual void pressButton(edk::ViewButton* button,edk::uint32 mouseButton)=0;
    virtual void releaseButton(edk::ViewButton* button,edk::uint32 mouseButton,bool isInside)=0;
    virtual void holdButton(edk::ViewButton* button,edk::uint32 mouseButton)=0;
};
class ViewButton: public edk::ViewSprite{
    public:
        ViewButton();
        virtual ~ViewButton();
        //set borderSize
        bool setBorderSize(edk::uint32 size);
        //set the callback
        bool setCallback(edk::ButtonCallback* callback);
        //remove callback
        void removeCallback();

        //LOAD SPRITES
//        bool loadSprite(const char* name);
//        bool loadSprite(edk::char8* name);
        //load pressed sprite
        bool loadSpritePressed(const char* name,edk::uint32 filter = GU_NEAREST);
        bool loadSpritePressed(edk::char8* name,edk::uint32 filter = GU_NEAREST);
        bool loadSpritePressedFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        bool loadSpritePressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        //load UP sprite
        bool loadSpriteUp(const char* name,edk::uint32 filter = GU_NEAREST);
        bool loadSpriteUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
        bool loadSpriteUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        bool loadSpriteUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);

        //Load button symbol normal
        bool loadSymbol(const char* name,edk::uint32 filter = GU_NEAREST);
        bool loadSymbol(edk::char8* name,edk::uint32 filter = GU_NEAREST);
        bool loadSymbolFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        bool loadSymbolFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        //Load button symbol pressed
        bool loadSymbolPressed(const char* name,edk::uint32 filter = GU_NEAREST);
        bool loadSymbolPressed(edk::char8* name,edk::uint32 filter = GU_NEAREST);
        bool loadSymbolPressedFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        bool loadSymbolPressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        //Load button symbol up
        bool loadSymbolUp(const char* name,edk::uint32 filter = GU_NEAREST);
        bool loadSymbolUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
        bool loadSymbolUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        bool loadSymbolUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);

        //DELETE
        //delete the spritePressed
        void deleteSpritePressed();
        //delete the spriteUp
        void deleteSpriteUp();
        //delete all the sprites
        void deleteAllSprites();
        //deleteSymbolNormal
        void deleteSymbol();
        //deleteSymbolPressed
        void deleteSymbolPressed();
        //deleteSymbolUp
        void deleteSymbolUp();
        //deleteAllSymbols
        void deleteAllSymbols();

        //scale the symbol
        void scaleInside(edk::size2f32 size);
        void scaleInside(edk::float32 width,edk::float32 height);

        //set the state
        void setState(edk::uint8 state);
        //On and Off the button
        void on();
        void off();
        bool isOn();

        //TEXT
        //add the text to the button
        bool addButtonText(const char* str);
        bool addButtonText(edk::char8* str);
        //load the textFont
        bool loadFontImage(const char* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
        bool loadFontImage(edk::char8* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
        bool loadFontImageFromMemory(const char* name,
                                     edk::uint8* image,
                                     edk::uint32 size,
                                     edk::uint32 filter = GU_NEAREST,
                                     edk::color4f32 color = edk::color4f32(1,1,1,1)
                );
        bool loadFontImageFromMemory(edk::char8* name,
                                     edk::uint8* image,
                                     edk::uint32 size,
                                     edk::uint32 filter = GU_NEAREST,
                                     edk::color4f32 color = edk::color4f32(1,1,1,1)
                );

        //remove the buttonText
        void deleteButtonText();

        //EVENT
        //event press button
        virtual void eventPressButton(edk::uint32 mouseButton);
        //event releaseButton
        virtual void eventReleaseButton(edk::uint32 mouseButton,bool isInside);
        //event holdButton
        virtual void eventHoldButton(edk::uint32 mouseButton);

        //return is a button
        bool isButton();
    protected:
        //draw the polygon on the scene
        void drawPolygon(rectf32 outsideViewOrigin);
        //mouse events
        virtual void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
        virtual void eventMouseMoved(edk::vec2f32 point,edk::uint32 button);
        virtual void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);
        //Mouse go Inside Outside
        virtual void eventMouseEntryInsideView(edk::vec2f32 point);
        virtual void eventMouseLeftView(edk::vec2f32 point);
    private:
        //Events
        //update the view
        void update(edk::WindowEvents* events);
        //save the buttons pressed to hold the buttons
        edk::vector::BinaryTree<edk::uint32> holdButton;
        //mouse is inside
        bool mouseInside;
        //textures list
        edk::Texture2DList list;
        //sprite button pressed
        edk::uint32 spritePressedCode;
        //sprite mouse up button
        edk::uint32 spriteUpCode;
        //symbom button
        edk::uint32 symbolCode;
        //symbom buttonPressed
        edk::uint32 symbolPressedCode;
        //symbom buttonUp
        edk::uint32 symbolUpCode;
        //size of the symbom
        edk::size2ui32 symbolSize;
        //state of the button
        edk::uint8 stateButton;
        bool buttonOn;

        //fontMap to write some text in the button
        edk::fonts::FontMap text;

        //scale the symbol
        edk::size2f32 insideScale;

        //button callBack
        edk::ButtonCallback* buttonCallback;

        //camera
        edk::Camera2D cam;
        edk::float32 borderTemp;
        edk::rectf32 rectButtonSave;
};
}//end namesoace edk

#endif // VIEWBUTTON_H
