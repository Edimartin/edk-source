#ifndef EDK_WINDOWEVENTS_H
#define EDK_WINDOWEVENTS_H

/*
Library C++ WindowEvents - Manipulate window events in Edk Game Engine
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

//EDK WINDOW usa SFML
#pragma once
#include <SFML/Window.hpp>

#ifdef printMessages
#warning "Inside WindowEvents"
#endif

//EDK
#include "TypeVars.h"
#include "TypeVec2.h"
#include "TypeSize2.h"
#include "TypeDefines.h"
#include "vector/Stack.h"

#ifdef printMessages
#warning "    Compiling WindowEvents"
#endif

//WindowEvents structure

/*LIBS

-lsfml-window

*/

namespace edk{
class WindowEvents{
    public:
        WindowEvents(){
            //
            this->focus=true;
        }
        virtual ~WindowEvents(){
            //
        }

        //clean the events
        void clean(){
            //
            this->buttonExit = this->lostFocus = this->gainedFocus = this->resize = this->mouseMoved = mouseEnter = mouseExit = false;
            this->resizePos = edk::size2i32(0,0);
            this->windowSize = edk::size2ui32(0u,0u);
            this->mousePos = edk::vec2i32(0,0);
            this->mousePosWorld = edk::vec2i32(0,0);
            this->mousePosWindow = edk::vec2i32(0,0);
            this->mouseMove = edk::vec2i32(0,0);
            this->keyPressed.clean();
            this->keyRelease.clean();
            this->keyHolded.clean();
            this->mousePressed.clean();
            this->mouseRelease.clean();
            this->mouseHolded.clean();
            //this->mouseMoving.clean();
            this->mouseScrollWheel = 0u;
/*
            //clean controllers
            for(edk::uint32 i=0u;i<this->controllerPressed.size();i++){
                //
                //
                this->controllerPressed[i]->buttonPressed.clean();
                this->controllerPressed[i]->buttonRelease.clean();
            }
            //clean controllerPressed
            this->controllerPressed.clean();
*/
        }

        //Eventos
        bool buttonExit;
        //save the focus
        bool lostFocus;
        bool gainedFocus;
        bool focus;
        //Resize
        bool resize;
        edk::size2i32 resizePos;
        //save the size of the window
        edk::size2ui32 windowSize;
        //Keys
        edk::vector::Stack<edk::uint32> keyPressed;
        edk::vector::Stack<edk::uint32> keyRelease;
        edk::vector::Stack<edk::uint32> keyHolded;
        //Mouse
        edk::vector::Stack<edk::uint32> mousePressed;
        //edk::vector::Stack<edk::uint32> mouseMoving;
        edk::vector::Stack<edk::uint32> mouseRelease;
        edk::vector::Stack<edk::uint32> mouseHolded;
        //Mouse Movido
        bool mouseMoved;
        edk::vec2i32 mousePos;       //mouse position inside the view
        edk::vec2i32 mousePosWorld;  //mouse position inside the world
        edk::vec2i32 mousePosWindow; //mouse position inside the window
        edk::vec2i32 mouseMove;
        //Mouse entrou
        bool mouseEnter;
        //Mouse saiu
        bool mouseExit;
        //mouseScroll
        edk::int32 mouseScrollWheel;

        //Controler
        class ctrlPressed{
            //
            public: edk::vector::Stack<edk::uint32>buttonPressed;
        };
        class ctrlRelease{
            //
            public: edk::vector::Stack<edk::uint32>buttonRelease;
        };

        //Controler
        edk::vector::Stack<ctrlPressed> controllerPressed;
    protected:
    private:
};
}//end namespace edk

#endif // WINDOWEVENTS_H
