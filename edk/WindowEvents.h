#ifndef EDK_WINDOWEVENTS_H
#define EDK_WINDOWEVENTS_H

/*
Library C++ WindowEvents - Manipulate window events in Edk Game Engine
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

//EDK WINDOW usa SFML
#pragma once
#include <SFML/Window.hpp>

#ifdef printMessages
#pragma message "Inside WindowEvents"
#endif

//EDK
#include "TypeVars.h"
#include "TypeVec2.h"
#include "TypeSize2.h"
#include "TypeDefines.h"
#include "vector/Stack.h"
#include "vector/BinaryTree.h"
#include "watch/Time.h"

#ifdef printMessages
#pragma message "    Compiling WindowEvents"
#endif

//WindowEvents structure

/*LIBS

-lsfml-window

*/

namespace edk{
class Window;
//events ID
enum EventWindowType{
    eventWindowNothing=0u,
    eventWindowButtonExit=1u,
    eventWindowLostFocus,
    eventWindowGainedFocus,
    eventWindowResize,
    eventWindowMouseMoved,
    eventWindowMouseEnter,
    eventWindowMouseExit,
    eventWindowResizePos,
    eventWindowWindowSize,
    eventWindowMousePos,
    eventWindowMousePosWorld,
    eventWindowMousePosWindow,
    eventWindowMouseMove,
    eventWindowKeyPressed,
    eventWindowKeyRelease,
    eventWindowKeyHolded,
    eventWindowKeyText,
    eventWindowMousePressed,
    eventWindowMouseRelease,
    eventWindowMouseHolded,
    eventWindowMouseDoubleClick,
    //eventWindowMouseMoving,
    eventWindowMouseScrollWheel,
    eventWindowSecondPassed,
    eventWindowSecondsGlobal,
    eventWindowControllerPressed,
    eventWindowControllerHolded,
    eventWindowControllerReleased,
    eventWindowControllerAxisMoved,
    //
    eventWindowSize
};
class WindowEvents{
public:
    WindowEvents(){
        //
        this->focus=true;edkEnd();

        //start all doubleClicks
        edk::uint32 size = edk::mouse::mouseButtonsSize;
        for(edk::uint32 i=0u;i<size;i++){
            this->timeMouseDouble[i].start();
        }

        //set the mouse double click limit
        this->timeMouseDoubleLimit = EDK_TIME_LIMIT_DOUBLE_CLICK;
        this->runForceSecondPassed=false;edkEnd();
    }
    virtual ~WindowEvents(){
        //
    }

    //friendClass
    friend edk::Window;

    //clone the event from another event
    bool cloneFrom(edk::WindowEvents* event){
        //first clean this events
        this->clean();
        //test if have the event
        if(event){
            //copy the values
            this->buttonExit = event->buttonExit;edkEnd();
            this->lostFocus = event->lostFocus;edkEnd();
            this->gainedFocus = event->gainedFocus;edkEnd();
            this->resize = event->resize;edkEnd();
            this->mouseMoved = event->mouseMoved;edkEnd();
            this->mouseEnter = event->mouseEnter;edkEnd();
            this->mouseExit = event->mouseExit;edkEnd();
            this->resizePos = event->resizePos;edkEnd();
            this->windowSize = event->windowSize;edkEnd();
            this->mousePos = event->mousePos;edkEnd();
            this->mousePosWorld = event->mousePosWorld;edkEnd();
            this->mousePosWindow = event->mousePosWindow;edkEnd();
            this->mouseMove = event->mouseMove;edkEnd();
            this->keyPressed.cloneFrom(&event->keyPressed);edkEnd();
            this->keyRelease.cloneFrom(&event->keyRelease);edkEnd();
            this->keyHolded.cloneFrom(&event->keyHolded);edkEnd();
            this->keyText.cloneFrom(&event->keyText);edkEnd();
            this->mousePressed.cloneFrom(&event->mousePressed);edkEnd();
            this->mouseRelease.cloneFrom(&event->mouseRelease);edkEnd();
            this->mouseHolded.cloneFrom(&event->mouseHolded);edkEnd();
            this->mouseDoubleClick.cloneFrom(&event->mouseDoubleClick);edkEnd();
            //this->mouseMoving.cloneFrom(event->mouseMoving);edkEnd();
            this->mouseScrollWheel = event->mouseScrollWheel;edkEnd();
            this->secondPassed = event->secondPassed;edkEnd();
            this->secondsGlobal = event->secondsGlobal;edkEnd();
            this->controllerPressed.cloneFrom(&event->controllerPressed);edkEnd();
            this->controllerHolded.cloneFrom(&event->controllerHolded);edkEnd();
            this->controllerReleased.cloneFrom(&event->controllerReleased);edkEnd();
            this->controllerAxisMoved.cloneFrom(&event->controllerAxisMoved);edkEnd();
            return true;
        }
        return false;
    }
    //test if the events have something
    bool haveSomething(){
        if(this->buttonExit
                || this->lostFocus
                || this->gainedFocus
                || this->resize
                || this->mouseMoved
                || this->mouseEnter
                || this->mouseExit
                || this->resizePos.width || this->resizePos.height
                //|| this->windowSize.width || this->windowSize.height
                //|| this->mousePos.x || this->mousePos.y
                //|| this->mousePosWorld.x || this->mousePosWorld.y
                //|| this->mousePosWindow.x || this->mousePosWindow.y
                || this->mouseMove.x || this->mouseMove.y
                || this->keyPressed.size()
                || this->keyRelease.size()
                || this->keyHolded.size()
                || this->keyText.size()
                || this->mousePressed.size()
                || this->mouseRelease.size()
                || this->mouseHolded.size()
                || this->mouseDoubleClick.size()
                //|| this->mouseMoving.size()
                || this->mouseScrollWheel
                //|| this->secondPassed
                //|| this->secondsGlobal
                || this->controllerPressed.getControllerSize()
                || this->controllerHolded.getControllerSize()
                || this->controllerReleased.getControllerSize()
                || this->controllerAxisMoved.getControllerSize()
                ){
            return true;
        }
        return false;
    }
    bool haveSomethingTypes(edk::EventWindowType types, ...){
        bool first=true;
        edk::uint32 typeTemp;
        edk::EventWindowType type;
        va_list vl;
        //
        typeTemp = types;
        type = (edk::EventWindowType)typeTemp;
        while(type){
            switch(type){
            case edk::eventWindowButtonExit:
                if(this->buttonExit){
                    return true;
                }
                break;
            case edk::eventWindowLostFocus:
                if(this->lostFocus){
                    return true;
                }
                break;
            case edk::eventWindowGainedFocus:
                if(this->gainedFocus){
                    return true;
                }
                break;
            case edk::eventWindowResize:
                if(this->resize){
                    return true;
                }
                break;
            case edk::eventWindowMouseMoved:
                if(this->mouseMoved){
                    return true;
                }
                break;
            case edk::eventWindowMouseEnter:
                if(this->mouseEnter){
                    return true;
                }
                break;
            case edk::eventWindowMouseExit:
                if(this->mouseExit){
                    return true;
                }
                break;
            case edk::eventWindowResizePos:
                if(this->resizePos.width || this->resizePos.height){
                    return true;
                }
                break;
            case edk::eventWindowWindowSize:
                return true;
                break;
            case edk::eventWindowMousePos:
                return true;
                break;
            case edk::eventWindowMousePosWorld:
                return true;
                break;
            case edk::eventWindowMousePosWindow:
                return true;
                break;
            case edk::eventWindowMouseMove:
                if(this->mouseMove.x || this->mouseMove.y){
                    return true;
                }
                break;
            case edk::eventWindowKeyPressed:
                if(this->keyPressed.size()){
                    return true;
                }
                break;
            case edk::eventWindowKeyRelease:
                if(this->keyRelease.size()){
                    return true;
                }
                break;
            case edk::eventWindowKeyHolded:
                if(this->keyHolded.size()){
                    return true;
                }
                break;
            case edk::eventWindowKeyText:
                if(this->keyText.size()){
                    return true;
                }
                break;
            case edk::eventWindowMousePressed:
                if(this->mousePressed.size()){
                    return true;
                }
                break;
            case edk::eventWindowMouseRelease:
                if(this->mouseRelease.size()){
                    return true;
                }
                break;
            case edk::eventWindowMouseHolded:
                if(this->mouseHolded.size()){
                    return true;
                }
                break;
            case edk::eventWindowMouseDoubleClick:
                if(this->mouseDoubleClick.size()){
                    return true;
                }
                break;
            case edk::eventWindowMouseScrollWheel:
                if(this->mouseScrollWheel){
                    return true;
                }
                break;
            case edk::eventWindowControllerPressed:
                if(this->controllerPressed.getControllerSize()){
                    return true;
                }
                break;
            case edk::eventWindowControllerHolded:
                if(this->controllerHolded.getControllerSize()){
                    return true;
                }
                break;
            case edk::eventWindowControllerReleased:
                if(this->controllerReleased.getControllerSize()){
                    return true;
                }
                break;
            case edk::eventWindowControllerAxisMoved:
                if(this->controllerAxisMoved.getControllerSize()){
                    return true;
                }
                break;
            default:
                break;
            }
            if(first){
                va_start(vl,types);
                first=false;
            }
            typeTemp = va_arg(vl,edk::uint32);
            type = (edk::EventWindowType)typeTemp;
        }
        return false;
    }
    bool haveSomethingTypesTree(edk::vector::BinaryTree<edk::EventWindowType>* tree){
        if(tree){
            edk::EventWindowType type;
            edk::uint32 size = tree->size();
            for(edk::uint32 i=0u;i<size;i++){
                type = tree->getElementInPosition(i);
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        return true;
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        return true;
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        return true;
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        return true;
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        return true;
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        return true;
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        return true;
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        return true;
                    }
                    break;
                case edk::eventWindowWindowSize:
                    return true;
                    break;
                case edk::eventWindowMousePos:
                    return true;
                    break;
                case edk::eventWindowMousePosWorld:
                    return true;
                    break;
                case edk::eventWindowMousePosWindow:
                    return true;
                    break;
                case edk::eventWindowMouseMove:
                    if(this->mouseMove.x || this->mouseMove.y){
                        return true;
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        return true;
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        return true;
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        return true;
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        return true;
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        return true;
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        return true;
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        return true;
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        return true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheel:
                    if(this->mouseScrollWheel){
                        return true;
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        return true;
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        return true;
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        return true;
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        return true;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        return false;
    }
    void printEvents(){
        printf("\nEvents:");edkEnd();
        bool have=false;
        if(this->buttonExit){
            printf("\n    edk::eventWindow_ButtonExit(TRUE)");edkEnd();
            have=true;edkEnd();
        }
        if(this->lostFocus){
            printf("\n    edk::eventWindow_LostFocus(TRUE)");edkEnd();
            have=true;edkEnd();
        }
        if(this->gainedFocus){
            printf("\n    edk::eventWindow_GainedFocus(TRUE)");edkEnd();
            have=true;edkEnd();
        }
        if(this->resize){
            printf("\n    edk::eventWindow_Resize(TRUE)"
                   "\n        WindowSize(%u,%u)"
                   "\n        ResizePos(%d,%d)"
                   ,this->windowSize.width
                   ,this->windowSize.height
                   ,this->resizePos.width
                   ,this->resizePos.height
                   );edkEnd();
            have=true;edkEnd();
        }
        if(this->mouseMoved){
            printf("\n    edk::eventWindow_MouseMoved(TRUE)"
                   "\n        MousePos(%d,%d)"
                   "\n        MousePosWorld(%d,%d)"
                   "\n        MousePosWindow(%d,%d)"
                   "\n        MouseMove(%d,%d)"
                   ,this->mousePos.x
                   ,this->mousePos.y
                   ,this->mousePosWorld.x
                   ,this->mousePosWorld.y
                   ,this->mousePosWindow.x
                   ,this->mousePosWindow.y
                   ,this->mouseMove.x
                   ,this->mouseMove.y
                   );edkEnd();
            have=true;edkEnd();
        }
        if(this->mouseEnter){
            printf("\n    edk::eventWindow_MouseEnter(TRUE)"
                   "\n        MousePos(%d,%d)"
                   "\n        MousePosWorld(%d,%d)"
                   "\n        MousePosWindow(%d,%d)"
                   "\n        MouseMove(%d,%d)"
                   ,this->mousePos.x
                   ,this->mousePos.y
                   ,this->mousePosWorld.x
                   ,this->mousePosWorld.y
                   ,this->mousePosWindow.x
                   ,this->mousePosWindow.y
                   ,this->mouseMove.x
                   ,this->mouseMove.y
                   );edkEnd();
            have=true;edkEnd();
        }
        if(this->mouseExit){
            printf("\n    edk::eventWindow_MouseExit(TRUE)"
                   "\n        MousePos(%d,%d)"
                   "\n        MousePosWorld(%d,%d)"
                   "\n        MousePosWindow(%d,%d)"
                   "\n        MouseMove(%d,%d)"
                   ,this->mousePos.x
                   ,this->mousePos.y
                   ,this->mousePosWorld.x
                   ,this->mousePosWorld.y
                   ,this->mousePosWindow.x
                   ,this->mousePosWindow.y
                   ,this->mouseMove.x
                   ,this->mouseMove.y
                   );edkEnd();
            have=true;edkEnd();
        }
        if(this->resizePos.width || this->resizePos.height){
            printf("\n    edk::eventWindow_ResizePos(%d,%d)"
                   ,this->resizePos.width
                   ,this->resizePos.height
                   );edkEnd();
            have=true;edkEnd();
        }
        /*
        if(this->windowSize.width || this->windowSize.height){
            printf("\n    edk::eventWindow_WindowSize(%u,%u)"
                   ,this->windowSize.width
                   ,this->windowSize.height
                   );edkEnd();
            have=true;edkEnd();
        }
        */
        /*
        if(this->mousePos.x || this->mousePos.y){
            printf("\n    edk::eventWindow_MousePos(%d,%d)"
                   ,this->mousePos.x
                   ,this->mousePos.y
                   );edkEnd();
            have=true;edkEnd();
        }
        */
        /*
        if(this->mousePosWorld.x || this->mousePosWorld.y){
            printf("\n    edk::eventWindow_MousePosWorld(%d,%d)"
                   ,this->mousePosWorld.x
                   ,this->mousePosWorld.y
                   );edkEnd();
            have=true;edkEnd();
        }
        */
        /*
        if(this->mousePosWindow.x || this->mousePosWindow.y){
            printf("\n    edk::eventWindow_MousePosWindow(%d,%d)"
                   ,this->mousePosWindow.x
                   ,this->mousePosWindow.y
                   );edkEnd();
            have=true;edkEnd();
        }
        */
        if(this->mouseMove.x || this->mouseMove.y){
            printf("\n    edk::eventWindow_MouseMove(%d,%d)"
                   ,this->mouseMove.x
                   ,this->mouseMove.y
                   );edkEnd();
            have=true;edkEnd();
        }
        if(this->keyPressed.size()){
            printf("\n    edk::eventWindow_KeyPressed(%u)"
                   ,this->keyPressed.size()
                   );edkEnd();
            edk::uint32 size = this->keyPressed.size();edkEnd();
            printf("\n        ");edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->keyPressed.get(i)
                       );edkEnd();
            }
            have=true;edkEnd();
        }
        if(this->keyRelease.size()){
            printf("\n    edk::eventWindow_KeyRelease(%u)"
                   ,this->keyRelease.size()
                   );edkEnd();
            edk::uint32 size = this->keyRelease.size();edkEnd();
            printf("\n        ");edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->keyRelease.get(i)
                       );edkEnd();
            }
            have=true;edkEnd();
        }
        if(this->keyHolded.size()){
            printf("\n    edk::eventWindow_KeyHolded(%u)"
                   ,this->keyHolded.size()
                   );edkEnd();
            edk::uint32 size = this->keyHolded.size();edkEnd();
            printf("\n        ");edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->keyHolded.get(i)
                       );edkEnd();
            }
            have=true;edkEnd();
        }
        if(this->keyText.size()){
            printf("\n    edk::eventWindow_KeyText(%u)"
                   ,this->keyText.size()
                   );edkEnd();
            edk::uint32 size = this->keyText.size();edkEnd();
            printf("\n        ");edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->keyText.get(i)
                       );edkEnd();
            }
            have=true;edkEnd();
        }
        if(this->mousePressed.size()){
            printf("\n    edk::eventWindow_MousePressed(%u)"
                   ,this->mousePressed.size()
                   );edkEnd();
            edk::uint32 size = this->mousePressed.size();edkEnd();
            printf("\n        ");edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->mousePressed.get(i)
                       );edkEnd();
            }
            have=true;edkEnd();
        }
        if(this->mouseRelease.size()){
            printf("\n    edk::eventWindow_MouseRelease(%u)"
                   ,this->mouseRelease.size()
                   );edkEnd();
            edk::uint32 size = this->mouseRelease.size();edkEnd();
            printf("\n        ");edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->mouseRelease.get(i)
                       );edkEnd();
            }
            have=true;edkEnd();
        }
        if(this->mouseHolded.size()){
            printf("\n    edk::eventWindow_MouseHolded(%u)"
                   ,this->mouseHolded.size()
                   );edkEnd();
            edk::uint32 size = this->mouseHolded.size();edkEnd();
            printf("\n        ");edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->mouseHolded.get(i)
                       );edkEnd();
            }
            have=true;edkEnd();
        }
        if(this->mouseDoubleClick.size()){
            printf("\n    edk::eventWindow_MouseDoubleClick(%u)"
                   ,this->mouseDoubleClick.size()
                   );edkEnd();
            edk::uint32 size = this->mouseDoubleClick.size();edkEnd();
            printf("\n        ");edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->mouseDoubleClick.get(i)
                       );edkEnd();
            }
            have=true;edkEnd();
        }
        //if(this->mouseMoving.size()){}
        if(this->mouseScrollWheel){
            printf("\n    edk::eventWindow_MouseScrollWheel(%d)"
                   ,this->mouseScrollWheel
                   );edkEnd();
            have=true;edkEnd();
        }
        /*
        if(this->secondPassed){
            printf("\n    edk::eventWindow_SecondPassed(%.4f)"
                   ,this->secondPassed
                   );edkEnd();
            have=true;edkEnd();
        }
        */
        /*
        if(this->secondsGlobal){
            printf("\n    edk::eventWindow_SecondsGlobal(%.4f)"
                   ,this->secondsGlobal
                   );edkEnd();
            have=true;edkEnd();
        }
        */
        if(this->controllerPressed.getControllerSize()){
            printf("\n    edk::eventWindow_ControllerPressed(%u)"
                   ,this->controllerPressed.getControllerSize()
                   );edkEnd();
            edk::uint32 sizeI = this->controllerPressed.getControllerSize();edkEnd();
            for(edk::uint32 i=0u;i<sizeI;i++){
                printf("\n        (%u)"
                       ,this->controllerPressed.getControllerIDInPosition(i)
                       );edkEnd();
                edk::uint32 sizeJ = this->controllerPressed.getControllerButtonSizeInPosition(i);edkEnd();
                for(edk::uint32 j=0u;j<sizeJ;j++){
                    printf("[%u]"
                           ,this->controllerPressed.getControllerButtonByID(i,j)
                           );edkEnd();
                }
            }
            have=true;edkEnd();
        }
        if(this->controllerHolded.getControllerSize()){
            printf("\n    edk::eventWindow_ControllerHolded(%u)"
                   ,this->controllerHolded.getControllerSize()
                   );edkEnd();
            edk::uint32 sizeI = this->controllerHolded.getControllerSize();edkEnd();
            for(edk::uint32 i=0u;i<sizeI;i++){
                printf("\n        (%u)"
                       ,this->controllerHolded.getControllerIDInPosition(i)
                       );edkEnd();
                edk::uint32 sizeJ = this->controllerHolded.getControllerButtonSizeInPosition(i);edkEnd();
                for(edk::uint32 j=0u;j<sizeJ;j++){
                    printf("[%u]"
                           ,this->controllerHolded.getControllerButtonByID(i,j)
                           );edkEnd();
                }
            }
            have=true;edkEnd();
        }
        if(this->controllerReleased.getControllerSize()){
            printf("\n    edk::eventWindow_ControllerReleased(%u)"
                   ,this->controllerReleased.getControllerSize()
                   );edkEnd();
            edk::uint32 sizeI = this->controllerReleased.getControllerSize();edkEnd();
            for(edk::uint32 i=0u;i<sizeI;i++){
                printf("\n        (%u)"
                       ,this->controllerReleased.getControllerIDInPosition(i)
                       );edkEnd();
                edk::uint32 sizeJ = this->controllerReleased.getControllerButtonSizeInPosition(i);edkEnd();
                for(edk::uint32 j=0u;j<sizeJ;j++){
                    printf("[%u]"
                           ,this->controllerReleased.getControllerButtonByID(i,j)
                           );edkEnd();
                }
            }
            have=true;edkEnd();
        }
        if(this->controllerAxisMoved.getControllerSize()){
            printf("\n    edk::eventWindow_ControllerAxisMoved(%u)"
                   ,this->controllerAxisMoved.getControllerSize()
                   );edkEnd();
            edk::uint32 sizeI = this->controllerAxisMoved.getControllerSize();edkEnd();
            for(edk::uint32 i=0u;i<sizeI;i++){
                printf("\n        (%u)"
                       ,this->controllerAxisMoved.getControllerIDInPosition(i)
                       );edkEnd();
                edk::uint32 sizeJ = this->controllerAxisMoved.getControllerButtonSizeInPosition(i);edkEnd();
                for(edk::uint32 j=0u;j<sizeJ;j++){
                    printf("[%u,%.2f]"
                           ,this->controllerAxisMoved.getControllerAxisInPosition(i,j)
                           ,this->controllerAxisMoved.getControllerAxisValueInPosition(i,j)
                           );edkEnd();
                }
            }
            have=true;edkEnd();
        }
        if(!have){
            printf("\n    NOTHING");edkEnd();
        }
        fflush(stdout);edkEnd();
    }
    //write the events into a file
    bool writeFile(edk::File* file){
        if(file){
            bool ret=false;edkEnd();
            bool writeWindowSize=false;edkEnd();
            bool writeMousePos=false;edkEnd();
            bool writeMousePosWorld=false;edkEnd();
            bool writeMousePosWindow=false;edkEnd();

            //first write the size of elements
            edk::uint32 sizeElements=0u;
            if(this->buttonExit){
                sizeElements++;edkEnd();
            }
            if(this->lostFocus){
                sizeElements++;edkEnd();
            }
            if(this->gainedFocus){
                sizeElements++;edkEnd();
            }
            if(this->resize){
                sizeElements++;edkEnd();
                writeWindowSize=true;edkEnd();
            }
            if(this->mouseMoved){
                sizeElements++;edkEnd();
                writeMousePos=true;edkEnd();
                writeMousePosWorld=true;edkEnd();
                writeMousePosWindow=true;edkEnd();
            }
            if(this->mouseEnter){
                sizeElements++;edkEnd();
                writeMousePos=true;edkEnd();
                writeMousePosWorld=true;edkEnd();
                writeMousePosWindow=true;edkEnd();
            }
            if(this->mouseExit){
                sizeElements++;edkEnd();
                writeMousePos=true;edkEnd();
                writeMousePosWorld=true;edkEnd();
                writeMousePosWindow=true;edkEnd();
            }
            if(this->resizePos.width || this->resizePos.height){
                sizeElements++;edkEnd();
                writeWindowSize=true;edkEnd();
            }


            if(writeWindowSize){
                sizeElements++;edkEnd();
            }
            if(writeMousePos){
                sizeElements++;edkEnd();
            }
            if(writeMousePosWindow){
                sizeElements++;edkEnd();
            }
            if(writeMousePosWorld){
                sizeElements++;edkEnd();
            }


            if(this->mouseMove.x || this->mouseMove.y){
                sizeElements++;edkEnd();
            }
            if(this->keyPressed.size()){
                sizeElements++;edkEnd();
            }
            if(this->keyRelease.size()){
                sizeElements++;edkEnd();
            }
            if(this->keyHolded.size()){
                sizeElements++;edkEnd();
            }
            if(this->keyText.size()){
                sizeElements++;edkEnd();
            }
            if(this->mousePressed.size()){
                sizeElements++;edkEnd();
            }
            if(this->mouseRelease.size()){
                sizeElements++;edkEnd();
            }
            if(this->mouseHolded.size()){
                sizeElements++;edkEnd();
            }
            if(this->mouseDoubleClick.size()){
                sizeElements++;edkEnd();
            }
            //if(this->mouseMoving.size()){}
            if(this->mouseScrollWheel){
                sizeElements++;edkEnd();
            }
            /*
            if(this->secondPassed){
            }
            */
            /*
            if(this->secondsGlobal){
            }
            */
            if(this->controllerPressed.getControllerSize()){
                sizeElements++;edkEnd();
            }
            if(this->controllerHolded.getControllerSize()){
                sizeElements++;edkEnd();
            }
            if(this->controllerReleased.getControllerSize()){
                sizeElements++;edkEnd();
            }
            if(this->controllerAxisMoved.getControllerSize()){
                sizeElements++;edkEnd();
            }
            //write the sizeElements
            file->writeBin((edk::uint32)sizeElements);edkEnd();


            //write the elements
            if(this->buttonExit){
                file->writeBin((edk::uint32)edk::eventWindowButtonExit);edkEnd();
                ret=true;edkEnd();
            }
            if(this->lostFocus){
                file->writeBin((edk::uint32)edk::eventWindowLostFocus);edkEnd();
                ret=true;edkEnd();
            }
            if(this->gainedFocus){
                file->writeBin((edk::uint32)edk::eventWindowGainedFocus);edkEnd();
                ret=true;edkEnd();
            }
            if(this->resize){
                file->writeBin((edk::uint32)edk::eventWindowResize);edkEnd();
                writeWindowSize=true;edkEnd();
                ret=true;edkEnd();
            }
            if(this->mouseMoved){
                file->writeBin((edk::uint32)edk::eventWindowMouseMoved);edkEnd();
                writeMousePos=true;edkEnd();
                writeMousePosWorld=true;edkEnd();
                writeMousePosWindow=true;edkEnd();
                ret=true;edkEnd();
            }
            if(this->mouseEnter){
                file->writeBin((edk::uint32)edk::eventWindowMouseEnter);edkEnd();
                writeMousePos=true;edkEnd();
                writeMousePosWorld=true;edkEnd();
                writeMousePosWindow=true;edkEnd();
                ret=true;edkEnd();
            }
            if(this->mouseExit){
                file->writeBin((edk::uint32)edk::eventWindowMouseExit);edkEnd();
                writeMousePos=true;edkEnd();
                writeMousePosWorld=true;edkEnd();
                writeMousePosWindow=true;edkEnd();
                ret=true;edkEnd();
            }
            if(this->resizePos.width || this->resizePos.height){
                file->writeBin((edk::uint32)edk::eventWindowResizePos);edkEnd();
                writeWindowSize=true;edkEnd();
                ret=true;edkEnd();
            }


            if(this->mouseMove.x || this->mouseMove.y){
                file->writeBin((edk::uint32)edk::eventWindowMouseMove);edkEnd();
                ret=true;edkEnd();
            }
            if(this->keyPressed.size()){
                file->writeBin((edk::uint32)edk::eventWindowKeyPressed);edkEnd();
                edk::uint32 size = this->keyPressed.size();edkEnd();
                file->writeBin((edk::uint32)size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->keyPressed.get(i));edkEnd();
                }
                ret=true;edkEnd();
            }
            if(this->keyRelease.size()){
                file->writeBin((edk::uint32)edk::eventWindowKeyRelease);edkEnd();
                edk::uint32 size = this->keyRelease.size();edkEnd();
                file->writeBin((edk::uint32)size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->keyRelease.get(i));edkEnd();
                }
                ret=true;edkEnd();
            }
            if(this->keyHolded.size()){
                file->writeBin((edk::uint32)edk::eventWindowKeyHolded);edkEnd();
                edk::uint32 size = this->keyHolded.size();edkEnd();
                file->writeBin((edk::uint32)size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->keyHolded.get(i));edkEnd();
                }
                ret=true;edkEnd();
            }
            if(this->keyText.size()){
                file->writeBin((edk::uint32)edk::eventWindowKeyText);edkEnd();
                edk::uint32 size = this->keyText.size();edkEnd();
                file->writeBin((edk::uint32)size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->keyText.get(i));edkEnd();
                }
                ret=true;edkEnd();
            }
            if(this->mousePressed.size()){
                file->writeBin((edk::uint32)edk::eventWindowMousePressed);edkEnd();
                edk::uint32 size = this->mousePressed.size();edkEnd();
                file->writeBin((edk::uint32)size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->mousePressed.get(i));edkEnd();
                }
                ret=true;edkEnd();
            }
            if(this->mouseRelease.size()){
                file->writeBin((edk::uint32)edk::eventWindowMouseRelease);edkEnd();
                edk::uint32 size = this->mouseRelease.size();edkEnd();
                file->writeBin((edk::uint32)size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->mouseRelease.get(i));edkEnd();
                }
                ret=true;edkEnd();
            }
            if(this->mouseHolded.size()){
                file->writeBin((edk::uint32)edk::eventWindowMouseHolded);edkEnd();
                edk::uint32 size = this->mouseHolded.size();edkEnd();
                file->writeBin((edk::uint32)size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->mouseHolded.get(i));edkEnd();
                }
                ret=true;edkEnd();
            }
            if(this->mouseDoubleClick.size()){
                file->writeBin((edk::uint32)edk::eventWindowMouseDoubleClick);edkEnd();
                edk::uint32 size = this->mouseDoubleClick.size();edkEnd();
                file->writeBin((edk::uint32)size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->mouseDoubleClick.get(i));edkEnd();
                }
                ret=true;edkEnd();
            }
            //if(this->mouseMoving.size()){}
            if(this->mouseScrollWheel){
                file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheel);edkEnd();
                file->writeBin((edk::int32)this->mouseScrollWheel);edkEnd();
                ret=true;edkEnd();
            }
            /*
            if(this->secondPassed){
                file->writeBin((edk::uint32)edk::eventWindowSecondPassed);edkEnd();
                ret=true;edkEnd();
            }
            */
            /*
            if(this->secondsGlobal){
                file->writeBin((edk::uint32)edk::eventWindowSecondsGlobal);edkEnd();
                ret=true;edkEnd();
            }
            */
            if(this->controllerPressed.getControllerSize()){
                file->writeBin((edk::uint32)edk::eventWindowControllerPressed);edkEnd();
                edk::uint32 sizeI = this->controllerPressed.getControllerSize();edkEnd();
                file->writeBin((edk::uint32)sizeI);edkEnd();
                for(edk::uint32 i=0u;i<sizeI;i++){
                    file->writeBin((edk::uint32)this->controllerPressed.getControllerIDInPosition(i));edkEnd();
                    edk::uint32 sizeJ = this->controllerPressed.getControllerButtonSizeInPosition(i);edkEnd();
                    file->writeBin((edk::uint32)sizeJ);edkEnd();
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        file->writeBin((edk::uint32)this->controllerPressed.getControllerButtonByID(i,j));edkEnd();
                    }
                }
                ret=true;edkEnd();
            }
            if(this->controllerHolded.getControllerSize()){
                file->writeBin((edk::uint32)edk::eventWindowControllerHolded);edkEnd();
                edk::uint32 sizeI = this->controllerHolded.getControllerSize();edkEnd();
                file->writeBin((edk::uint32)sizeI);edkEnd();
                for(edk::uint32 i=0u;i<sizeI;i++){
                    file->writeBin((edk::uint32)this->controllerHolded.getControllerIDInPosition(i));edkEnd();
                    edk::uint32 sizeJ = this->controllerHolded.getControllerButtonSizeInPosition(i);edkEnd();
                    file->writeBin((edk::uint32)sizeJ);edkEnd();
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        file->writeBin((edk::uint32)this->controllerHolded.getControllerButtonByID(i,j));edkEnd();
                    }
                }
                ret=true;edkEnd();
            }
            if(this->controllerReleased.getControllerSize()){
                file->writeBin((edk::uint32)edk::eventWindowControllerReleased);edkEnd();
                edk::uint32 sizeI = this->controllerReleased.getControllerSize();edkEnd();
                file->writeBin((edk::uint32)sizeI);edkEnd();
                for(edk::uint32 i=0u;i<sizeI;i++){
                    file->writeBin((edk::uint32)this->controllerReleased.getControllerIDInPosition(i));edkEnd();
                    edk::uint32 sizeJ = this->controllerReleased.getControllerButtonSizeInPosition(i);edkEnd();
                    file->writeBin((edk::uint32)sizeJ);edkEnd();
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        file->writeBin((edk::uint32)this->controllerReleased.getControllerButtonByID(i,j));edkEnd();
                    }
                }
                ret=true;edkEnd();
            }
            if(this->controllerAxisMoved.getControllerSize()){
                file->writeBin((edk::uint32)edk::eventWindowControllerAxisMoved);edkEnd();
                edk::uint32 sizeI = this->controllerAxisMoved.getControllerSize();edkEnd();
                file->writeBin((edk::uint32)sizeI);edkEnd();
                for(edk::uint32 i=0u;i<sizeI;i++){
                    file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerIDInPosition(i));edkEnd();
                    edk::uint32 sizeJ = this->controllerAxisMoved.getControllerButtonSizeInPosition(i);edkEnd();
                    file->writeBin((edk::uint32)sizeJ);edkEnd();
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisInPosition(i,j));edkEnd();
                        file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisValueInPosition(i,j));edkEnd();
                    }
                }
                ret=true;edkEnd();
            }


            if(writeWindowSize){
                file->writeBin((edk::uint32)edk::eventWindowWindowSize);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePos){
                file->writeBin((edk::uint32)edk::eventWindowMousePos);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePosWindow){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWorld);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePosWorld){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWindow);edkEnd();
                ret=true;edkEnd();
            }
            file->flush();
            return ret;
        }
        return false;
    }
    bool writeFileTypes(edk::File* file,edk::EventWindowType types, ...){
        //Alloc the return
        bool ret=false;
        //test if have the fileTemp
        if(file){
            bool first=true;
            edk::uint32 typeTemp;
            edk::EventWindowType type;
            va_list vl;
            //
            typeTemp = types;
            type = (edk::EventWindowType)typeTemp;

            bool writeWindowSize=false;edkEnd();
            bool writeMousePos=false;edkEnd();
            bool writeMousePosWorld=false;edkEnd();
            bool writeMousePosWindow=false;edkEnd();

            //first write the size of elements
            edk::uint32 sizeElements=0u;

            while(type){
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        sizeElements++;edkEnd();
                        writeWindowSize=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        sizeElements++;edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        sizeElements++;edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        sizeElements++;edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        sizeElements++;edkEnd();
                        writeWindowSize=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowWindowSize:
                    writeWindowSize=true;
                    break;
                case edk::eventWindowMousePos:
                    writeMousePos=true;
                    break;
                case edk::eventWindowMousePosWorld:
                    writeMousePosWorld=true;
                    break;
                case edk::eventWindowMousePosWindow:
                    writeMousePosWindow=true;
                    break;
                case edk::eventWindowMouseMove:
                    if(this->mouseMove.x || this->mouseMove.y){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseScrollWheel:
                    if(this->mouseScrollWheel){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                default:
                    break;
                }
                if(first){
                    va_start(vl,types);
                    first=false;
                }
                typeTemp = va_arg(vl,edk::uint32);
                type = (edk::EventWindowType)typeTemp;
            }
            if(writeWindowSize){
                sizeElements++;edkEnd();
            }
            if(writeMousePos){
                sizeElements++;edkEnd();
            }
            if(writeMousePosWindow){
                sizeElements++;edkEnd();
            }
            if(writeMousePosWorld){
                sizeElements++;edkEnd();
            }
            //write the sizeElements
            file->writeBin((edk::uint32)sizeElements);edkEnd();

            file->flush();


            if(!sizeElements){
                return false;
            }





            writeWindowSize=false;edkEnd();
            writeMousePos=false;edkEnd();
            writeMousePosWorld=false;edkEnd();
            writeMousePosWindow=false;edkEnd();





            first=true;
            //
            typeTemp = types;
            type = (edk::EventWindowType)typeTemp;
            while(type){
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        file->writeBin((edk::uint32)edk::eventWindowButtonExit);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        file->writeBin((edk::uint32)edk::eventWindowLostFocus);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        file->writeBin((edk::uint32)edk::eventWindowGainedFocus);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        file->writeBin((edk::uint32)edk::eventWindowResize);edkEnd();
                        writeWindowSize=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        file->writeBin((edk::uint32)edk::eventWindowMouseMoved);edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        file->writeBin((edk::uint32)edk::eventWindowMouseEnter);edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        file->writeBin((edk::uint32)edk::eventWindowMouseExit);edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        file->writeBin((edk::uint32)edk::eventWindowResizePos);edkEnd();
                        writeWindowSize=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowWindowSize:
                    writeWindowSize=true;
                    break;
                case edk::eventWindowMousePos:
                    writeMousePos=true;
                    break;
                case edk::eventWindowMousePosWorld:
                    writeMousePosWorld=true;
                    break;
                case edk::eventWindowMousePosWindow:
                    writeMousePosWindow=true;
                    break;
                case edk::eventWindowMouseMove:
                    if(this->mouseMove.x || this->mouseMove.y){
                        file->writeBin((edk::uint32)edk::eventWindowMouseMove);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyPressed);edkEnd();
                        edk::uint32 size = this->keyPressed.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyPressed.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyRelease);edkEnd();
                        edk::uint32 size = this->keyRelease.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyRelease.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyHolded);edkEnd();
                        edk::uint32 size = this->keyHolded.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyHolded.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyText);edkEnd();
                        edk::uint32 size = this->keyText.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyText.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMousePressed);edkEnd();
                        edk::uint32 size = this->mousePressed.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mousePressed.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseRelease);edkEnd();
                        edk::uint32 size = this->mouseRelease.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseRelease.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseHolded);edkEnd();
                        edk::uint32 size = this->mouseHolded.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseHolded.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseDoubleClick);edkEnd();
                        edk::uint32 size = this->mouseDoubleClick.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseDoubleClick.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseScrollWheel:
                    if(this->mouseScrollWheel){
                        file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheel);edkEnd();
                        file->writeBin((edk::int32)this->mouseScrollWheel);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerPressed);edkEnd();
                        edk::uint32 sizeI = this->controllerPressed.getControllerSize();edkEnd();
                        file->writeBin((edk::uint32)sizeI);edkEnd();
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerPressed.getControllerIDInPosition(i));edkEnd();
                            edk::uint32 sizeJ = this->controllerPressed.getControllerButtonSizeInPosition(i);edkEnd();
                            file->writeBin((edk::uint32)sizeJ);edkEnd();
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerPressed.getControllerButtonByID(i,j));edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerHolded);edkEnd();
                        edk::uint32 sizeI = this->controllerHolded.getControllerSize();edkEnd();
                        file->writeBin((edk::uint32)sizeI);edkEnd();
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerHolded.getControllerIDInPosition(i));edkEnd();
                            edk::uint32 sizeJ = this->controllerHolded.getControllerButtonSizeInPosition(i);edkEnd();
                            file->writeBin((edk::uint32)sizeJ);edkEnd();
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerHolded.getControllerButtonByID(i,j));edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerReleased);edkEnd();
                        edk::uint32 sizeI = this->controllerReleased.getControllerSize();edkEnd();
                        file->writeBin((edk::uint32)sizeI);edkEnd();
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerReleased.getControllerIDInPosition(i));edkEnd();
                            edk::uint32 sizeJ = this->controllerReleased.getControllerButtonSizeInPosition(i);edkEnd();
                            file->writeBin((edk::uint32)sizeJ);edkEnd();
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerReleased.getControllerButtonByID(i,j));edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerAxisMoved);edkEnd();
                        edk::uint32 sizeI = this->controllerAxisMoved.getControllerSize();edkEnd();
                        file->writeBin((edk::uint32)sizeI);edkEnd();
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerIDInPosition(i));edkEnd();
                            edk::uint32 sizeJ = this->controllerAxisMoved.getControllerButtonSizeInPosition(i);edkEnd();
                            file->writeBin((edk::uint32)sizeJ);edkEnd();
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisInPosition(i,j));edkEnd();
                                file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisValueInPosition(i,j));edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    break;
                default:
                    break;
                }
                if(first){
                    va_start(vl,types);
                    first=false;
                }
                typeTemp = va_arg(vl,edk::uint32);
                type = (edk::EventWindowType)typeTemp;
            }
            if(writeWindowSize){
                file->writeBin((edk::uint32)edk::eventWindowWindowSize);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePos){
                file->writeBin((edk::uint32)edk::eventWindowMousePos);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePosWindow){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWorld);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePosWorld){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWindow);edkEnd();
                ret=true;edkEnd();
            }
            //
            file->flush();
        }
        return ret;
    }
    bool writeFileTypesTree(edk::File* file,edk::vector::BinaryTree<edk::EventWindowType>* tree){
        //Alloc the return
        bool ret=false;
        //test if have the fileTemp
        if(file && tree){
            edk::EventWindowType type;


            bool writeWindowSize=false;edkEnd();
            bool writeMousePos=false;edkEnd();
            bool writeMousePosWorld=false;edkEnd();
            bool writeMousePosWindow=false;edkEnd();

            //first write the size of elements
            edk::uint32 sizeElements=0u;

            edk::uint32 size = tree->size();

            for(edk::uint32 i=0u;i<size;i++){
                type = tree->getElementInPosition(i);
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        sizeElements++;edkEnd();
                        writeWindowSize=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        sizeElements++;edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        sizeElements++;edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        sizeElements++;edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        sizeElements++;edkEnd();
                        writeWindowSize=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowWindowSize:
                    writeWindowSize=true;
                    break;
                case edk::eventWindowMousePos:
                    writeMousePos=true;
                    break;
                case edk::eventWindowMousePosWorld:
                    writeMousePosWorld=true;
                    break;
                case edk::eventWindowMousePosWindow:
                    writeMousePosWindow=true;
                    break;
                case edk::eventWindowMouseMove:
                    if(this->mouseMove.x || this->mouseMove.y){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseScrollWheel:
                    if(this->mouseScrollWheel){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        sizeElements++;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                default:
                    break;
                }
            }
            if(writeWindowSize){
                sizeElements++;edkEnd();
            }
            if(writeMousePos){
                sizeElements++;edkEnd();
            }
            if(writeMousePosWindow){
                sizeElements++;edkEnd();
            }
            if(writeMousePosWorld){
                sizeElements++;edkEnd();
            }
            //write the sizeElements
            file->writeBin((edk::uint32)sizeElements);edkEnd();

            file->flush();


            if(!sizeElements){
                return false;
            }



            writeWindowSize=false;edkEnd();
            writeMousePos=false;edkEnd();
            writeMousePosWorld=false;edkEnd();
            writeMousePosWindow=false;edkEnd();






            //write the values into the file
            for(edk::uint32 i=0u;i<size;i++){
                type = tree->getElementInPosition(i);
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        file->writeBin((edk::uint32)edk::eventWindowButtonExit);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        file->writeBin((edk::uint32)edk::eventWindowLostFocus);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        file->writeBin((edk::uint32)edk::eventWindowGainedFocus);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        file->writeBin((edk::uint32)edk::eventWindowResize);edkEnd();
                        writeWindowSize=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        file->writeBin((edk::uint32)edk::eventWindowMouseMoved);edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        file->writeBin((edk::uint32)edk::eventWindowMouseEnter);edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        file->writeBin((edk::uint32)edk::eventWindowMouseExit);edkEnd();
                        writeMousePos=true;edkEnd();
                        writeMousePosWorld=true;edkEnd();
                        writeMousePosWindow=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        file->writeBin((edk::uint32)edk::eventWindowResizePos);edkEnd();
                        writeWindowSize=true;edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowWindowSize:
                    writeWindowSize=true;
                    break;
                case edk::eventWindowMousePos:
                    writeMousePos=true;
                    break;
                case edk::eventWindowMousePosWorld:
                    writeMousePosWorld=true;
                    break;
                case edk::eventWindowMousePosWindow:
                    writeMousePosWindow=true;
                    break;
                case edk::eventWindowMouseMove:
                    if(this->mouseMove.x || this->mouseMove.y){
                        file->writeBin((edk::uint32)edk::eventWindowMouseMove);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyPressed);edkEnd();
                        edk::uint32 size = this->keyPressed.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyPressed.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyRelease);edkEnd();
                        edk::uint32 size = this->keyRelease.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyRelease.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyHolded);edkEnd();
                        edk::uint32 size = this->keyHolded.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyHolded.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyText);edkEnd();
                        edk::uint32 size = this->keyText.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyText.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMousePressed);edkEnd();
                        edk::uint32 size = this->mousePressed.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mousePressed.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseRelease);edkEnd();
                        edk::uint32 size = this->mouseRelease.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseRelease.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseHolded);edkEnd();
                        edk::uint32 size = this->mouseHolded.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseHolded.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseDoubleClick);edkEnd();
                        edk::uint32 size = this->mouseDoubleClick.size();edkEnd();
                        file->writeBin((edk::uint32)size);edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseDoubleClick.get(i));edkEnd();
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowMouseScrollWheel:
                    if(this->mouseScrollWheel){
                        file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheel);edkEnd();
                        file->writeBin((edk::int32)this->mouseScrollWheel);edkEnd();
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerPressed);edkEnd();
                        edk::uint32 sizeI = this->controllerPressed.getControllerSize();edkEnd();
                        file->writeBin((edk::uint32)sizeI);edkEnd();
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerPressed.getControllerIDInPosition(i));edkEnd();
                            edk::uint32 sizeJ = this->controllerPressed.getControllerButtonSizeInPosition(i);edkEnd();
                            file->writeBin((edk::uint32)sizeJ);edkEnd();
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerPressed.getControllerButtonByID(i,j));edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerHolded);edkEnd();
                        edk::uint32 sizeI = this->controllerHolded.getControllerSize();edkEnd();
                        file->writeBin((edk::uint32)sizeI);edkEnd();
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerHolded.getControllerIDInPosition(i));edkEnd();
                            edk::uint32 sizeJ = this->controllerHolded.getControllerButtonSizeInPosition(i);edkEnd();
                            file->writeBin((edk::uint32)sizeJ);edkEnd();
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerHolded.getControllerButtonByID(i,j));edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerReleased);edkEnd();
                        edk::uint32 sizeI = this->controllerReleased.getControllerSize();edkEnd();
                        file->writeBin((edk::uint32)sizeI);edkEnd();
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerReleased.getControllerIDInPosition(i));edkEnd();
                            edk::uint32 sizeJ = this->controllerReleased.getControllerButtonSizeInPosition(i);edkEnd();
                            file->writeBin((edk::uint32)sizeJ);edkEnd();
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerReleased.getControllerButtonByID(i,j));edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerAxisMoved);edkEnd();
                        edk::uint32 sizeI = this->controllerAxisMoved.getControllerSize();edkEnd();
                        file->writeBin((edk::uint32)sizeI);edkEnd();
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerIDInPosition(i));edkEnd();
                            edk::uint32 sizeJ = this->controllerAxisMoved.getControllerButtonSizeInPosition(i);edkEnd();
                            file->writeBin((edk::uint32)sizeJ);edkEnd();
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisInPosition(i,j));edkEnd();
                                file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisValueInPosition(i,j));edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    break;
                default:
                    break;
                }
            }
            if(writeWindowSize){
                file->writeBin((edk::uint32)edk::eventWindowWindowSize);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePos){
                file->writeBin((edk::uint32)edk::eventWindowMousePos);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePosWindow){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWorld);edkEnd();
                ret=true;edkEnd();
            }
            if(writeMousePosWorld){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWindow);edkEnd();
                ret=true;edkEnd();
            }
            file->flush();
            //
        }
        return ret;
    }
    //read the events from a file
    bool readFile(edk::File* file){
        if(file){
            bool ret=false;edkEnd();
            edk::uint32 sizeElements = 0u;edkEnd();
            file->readBin(&sizeElements,sizeof(sizeElements));edkEnd();
            if(sizeElements<100u){
                edk::uint32 type;edkEnd();
                for(edk::uint32 e=0u;e<sizeElements;e++){
                    //get the type
                    file->readBin(&type,sizeof(edk::uint32));edkEnd();
                    switch(type){
                    case edk::eventWindowButtonExit:
                        this->buttonExit=true;edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowLostFocus:
                        this->lostFocus=true;edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowGainedFocus:
                        this->gainedFocus=true;edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowResize:
                        this->resize=true;edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMouseMoved:
                        this->mouseMoved=true;edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMouseEnter:
                        this->mouseEnter=true;edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMouseExit:
                        this->mouseExit=true;edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowResizePos:
                        edk::size2i32(file->readBin(&this->resizePos.width,sizeof(this->resizePos.width)),file->readBin(&this->resizePos.height,sizeof(this->resizePos.height)));edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowWindowSize:
                        edk::size2i32(file->readBin(&this->windowSize.width,sizeof(this->windowSize.width)),file->readBin(&this->windowSize.height,sizeof(this->windowSize.height)));edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMousePos:
                        edk::vec2i32(file->readBin(&this->mousePos.x,sizeof(this->mousePos.x)),file->readBin(&this->mousePos.y,sizeof(this->mousePos.y)));edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMousePosWorld:
                        edk::vec2i32(file->readBin(&this->mousePosWorld.x,sizeof(this->mousePosWorld.x)),file->readBin(&this->mousePosWorld.y,sizeof(this->mousePosWorld.y)));edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMousePosWindow:
                        edk::vec2i32(file->readBin(&this->mousePosWindow.x,sizeof(this->mousePosWindow.x)),file->readBin(&this->mousePosWindow.y,sizeof(this->mousePosWindow.y)));edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMouseMove:
                        edk::vec2i32(file->readBin(&this->mouseMove.x,sizeof(this->mouseMove.x)),file->readBin(&this->mouseMove.y,sizeof(this->mouseMove.y)));edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowKeyPressed:
                    {
                        //get the size
                        edk::uint32 size = 0u;edkEnd();
                        edk::uint32 key = 0u;edkEnd();
                        file->readBin(&size,sizeof(size));edkEnd();
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));edkEnd();
                                this->keyPressed.pushBack(key);edkEnd();
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowKeyRelease:
                    {
                        //get the size
                        edk::uint32 size = 0u;edkEnd();
                        file->readBin(&size,sizeof(size));edkEnd();
                        edk::uint32 key = 0u;edkEnd();
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->keyRelease.pushBack(key);edkEnd();
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowKeyHolded:
                    {
                        //get the size
                        edk::uint32 size = 0u;edkEnd();
                        file->readBin(&size,sizeof(size));edkEnd();
                        edk::uint32 key = 0u;edkEnd();
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->keyHolded.pushBack(key);edkEnd();
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowKeyText:
                    {
                        //get the size
                        edk::uint32 size = 0u;edkEnd();
                        file->readBin(&size,sizeof(size));edkEnd();
                        edk::uint32 key = 0u;edkEnd();
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->keyText.pushBack(key);edkEnd();
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMousePressed:
                    {
                        //get the size
                        edk::uint32 size = 0u;edkEnd();
                        file->readBin(&size,sizeof(size));edkEnd();
                        edk::uint32 key = 0u;edkEnd();
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->mousePressed.pushBack(key);edkEnd();
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMouseRelease:
                    {
                        //get the size
                        edk::uint32 size = 0u;edkEnd();
                        file->readBin(&size,sizeof(size));edkEnd();
                        edk::uint32 key = 0u;edkEnd();
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->mouseRelease.pushBack(key);edkEnd();
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMouseHolded:
                    {
                        //get the size
                        edk::uint32 size = 0u;edkEnd();
                        file->readBin(&size,sizeof(size));edkEnd();
                        edk::uint32 key = 0u;edkEnd();
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->mouseHolded.pushBack(key);edkEnd();
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMouseDoubleClick:
                    {
                        //get the size
                        edk::uint32 size = 0u;edkEnd();
                        file->readBin(&size,sizeof(size));edkEnd();
                        edk::uint32 key = 0u;edkEnd();
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->mouseDoubleClick.pushBack(key);edkEnd();
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowMouseScrollWheel:
                        file->readBin(&this->mouseScrollWheel,sizeof(this->mouseScrollWheel));edkEnd();
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowControllerPressed:
                    {
                        //get the sizeI
                        edk::uint32 sizeI = 0u;edkEnd();
                        file->readBin(&sizeI,sizeof(sizeI));edkEnd();
                        edk::uint32 controllerID;edkEnd();
                        edk::uint32 value;edkEnd();
                        edk::uint32 sizeJ;
                        if(sizeI<100u){
                            for(edk::uint32 i=0u;i<sizeI;i++){
                                file->readBin(&controllerID,sizeof(controllerID));edkEnd();
                                //get the sizeJ
                                file->readBin(&sizeJ,sizeof(sizeJ));edkEnd();
                                if(sizeJ<100u){
                                    for(edk::uint32 j=0u;j<sizeJ;j++){
                                        //get the button
                                        file->readBin(&value,sizeof(edk::uint32));edkEnd();
                                        this->controllerPressed.addButton(controllerID,value);edkEnd();
                                    }
                                }
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowControllerHolded:
                    {
                        //get the sizeI
                        edk::uint32 sizeI = 0u;edkEnd();
                        file->readBin(&sizeI,sizeof(sizeI));edkEnd();
                        edk::uint32 controllerID;edkEnd();
                        edk::uint32 value;edkEnd();
                        edk::uint32 sizeJ;
                        if(sizeI<100u){
                            for(edk::uint32 i=0u;i<sizeI;i++){
                                file->readBin(&controllerID,sizeof(controllerID));edkEnd();
                                //get the sizeJ
                                file->readBin(&sizeJ,sizeof(sizeJ));edkEnd();
                                if(sizeJ<100u){
                                    for(edk::uint32 j=0u;j<sizeJ;j++){
                                        //get the button
                                        file->readBin(&value,sizeof(edk::uint32));edkEnd();
                                        this->controllerHolded.addButton(controllerID,value);edkEnd();
                                    }
                                }
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowControllerReleased:
                    {
                        //get the sizeI
                        edk::uint32 sizeI = 0u;edkEnd();
                        file->readBin(&sizeI,sizeof(sizeI));edkEnd();
                        edk::uint32 controllerID;edkEnd();
                        edk::uint32 value;edkEnd();
                        edk::uint32 sizeJ;
                        if(sizeI<100u){
                            for(edk::uint32 i=0u;i<sizeI;i++){
                                file->readBin(&controllerID,sizeof(controllerID));edkEnd();
                                //get the sizeJ
                                file->readBin(&sizeJ,sizeof(sizeJ));edkEnd();
                                if(sizeJ<100u){
                                    for(edk::uint32 j=0u;j<sizeJ;j++){
                                        //get the button
                                        file->readBin(&value,sizeof(edk::uint32));edkEnd();
                                        this->controllerReleased.addButton(controllerID,value);edkEnd();
                                    }
                                }
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    case edk::eventWindowControllerAxisMoved:
                    {
                        //get the sizeI
                        edk::uint32 sizeI = 0u;edkEnd();
                        file->readBin(&sizeI,sizeof(sizeI));edkEnd();
                        edk::uint32 controllerID;edkEnd();
                        edk::uint32 position;edkEnd();
                        edk::float32 value;edkEnd();
                        edk::uint32 sizeJ;
                        if(sizeI<100u){
                            for(edk::uint32 i=0u;i<sizeI;i++){
                                file->readBin(&controllerID,sizeof(controllerID));edkEnd();
                                //get the sizeJ
                                file->readBin(&sizeJ,sizeof(sizeJ));edkEnd();
                                if(sizeJ<100u){
                                    for(edk::uint32 j=0u;j<sizeJ;j++){
                                        //get the button
                                        file->readBin(&position,sizeof(position));edkEnd();
                                        file->readBin(&value,sizeof(value));edkEnd();
                                        this->controllerAxisMoved.addAxis(controllerID,position,value);edkEnd();
                                    }
                                }
                            }
                        }
                    }
                        ret=true;edkEnd();
                        break;
                    default:
                        break;
                    }
                    if(file->endOfFile()){
                        break;
                    }
                }
            }
            return ret;
        }
        return false;
    }

    //clean the events
    void clean(){
        //
        this->buttonExit = this->lostFocus = this->gainedFocus = this->resize = this->mouseMoved = this->mouseEnter = this->mouseExit = false;edkEnd();
        this->resizePos = edk::size2i32(0,0);edkEnd();
        this->windowSize = edk::size2ui32(0u,0u);edkEnd();
        this->mousePos = edk::vec2i32(0,0);edkEnd();
        this->mousePosWorld = edk::vec2i32(0,0);edkEnd();
        this->mousePosWindow = edk::vec2i32(0,0);edkEnd();
        this->mouseMove = edk::vec2i32(0,0);edkEnd();
        this->keyPressed.clean();edkEnd();
        this->keyRelease.clean();edkEnd();
        this->keyHolded.clean();edkEnd();
        this->keyText.clean();edkEnd();
        this->mousePressed.clean();edkEnd();
        this->mouseRelease.clean();edkEnd();
        this->mouseHolded.clean();edkEnd();
        this->mouseDoubleClick.clean();edkEnd();
        //this->mouseMoving.clean();edkEnd();
        this->mouseScrollWheel = 0u;edkEnd();
        this->secondPassed = 0.f;edkEnd();
        this->secondsGlobal = 0.f;edkEnd();
        this->controllerPressed.clean();edkEnd();
        //this->controllerHolded.clean();edkEnd();
        this->controllerReleased.clean();edkEnd();
        this->controllerAxisMoved.clean();edkEnd();
    }
    //set the mouse double time limit
    bool setMouseDoubleClickLimit(edk::float32 seconds){
        if(seconds>0.f){
            this->timeMouseDoubleLimit = seconds;edkEnd();
            return true;
        }
        this->timeMouseDoubleLimit = EDK_TIME_LIMIT_DOUBLE_CLICK;edkEnd();
        return false;
    }
    edk::float32 getMouseDoubleClickLimit(){
        return this->timeMouseDoubleLimit;edkEnd();
    }

    //force the second passed
    bool forceSecondPassed(edk::float32 seconds){
        if(seconds>0.f){
            this->runForceSecondPassed=true;edkEnd();
            this->runForceSecondPassedValue=seconds;edkEnd();
            return true;
        }
        if(this->runForceSecondPassed){
            return true;
        }
        return false;
    }
    bool updateForceSecondPassed(){
        if(this->runForceSecondPassed){
            //value in the next load
            this->runForceSecondPassed=false;edkEnd();
            this->secondPassed = this->runForceSecondPassedValue;
            this->runForceSecondPassedValue=0.f;edkEnd();
            return true;
        }
        this->runForceSecondPassedValue=0.f;edkEnd();
        return false;
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
    edk::vector::Stack<edk::uint32> keyText;
    //Mouse
    edk::vector::Stack<edk::uint32> mousePressed;
    //edk::vector::Stack<edk::uint32> mouseMoving;
    edk::vector::Stack<edk::uint32> mouseRelease;
    edk::vector::Stack<edk::uint32> mouseHolded;
    edk::vector::Stack<edk::uint32> mouseDoubleClick;
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
    //percent of the seconds in the time
    edk::float32 secondPassed;
    //percent of the seconds in the time
    edk::float32 secondsGlobal;
protected:
private:
    //force the second passed to have a value in the next load
    bool runForceSecondPassed;
    edk::float32 runForceSecondPassedValue;

    //time to controle the mouse doubleClick
    edk::watch::Time timeMouseDouble[edk::mouse::mouseButtonsSize];
    //mouse doubleClick time limit
    edk::float32 timeMouseDoubleLimit;

    //Controller
    class ControllerButtons{
    public:
        ControllerButtons(){this->controller=0u;edkEnd();}
        virtual ~ControllerButtons(){this->buttons.clean();edkEnd();}
        edk::uint32 controller;
        edk::vector::BinaryTree<edk::uint32> buttons;
    };
    //controller button tree
    class ControllerButtonsEvent{
    public:
        ControllerButtonsEvent(){}
        virtual ~ControllerButtonsEvent(){this->clean();edkEnd();}

        bool cloneFrom(edk::WindowEvents::ControllerButtonsEvent* event){
            this->clean();
            if(event){
                //
                edk::uint32 size = this->buttons.size();edkEnd();
                edk::WindowEvents::ControllerButtons* temp=NULL;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    temp = this->buttons.getElementInPosition(i);edkEnd();
                    if(temp){
                        edk::uint32 size = temp->buttons.size();edkEnd();
                        for(edk::uint32 j=0u;j<size;j++){
                            this->addButton(temp->controller,temp->buttons.getElementInPosition(j));edkEnd();
                        }
                    }
                }
                return true;
            }
            return false;
        }

        //clean the controllers
        void clean(){
            edk::uint32 size = this->buttons.size();edkEnd();
            edk::WindowEvents::ControllerButtons* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->buttons.getElementInPosition(i);edkEnd();
                if(temp){
                    delete temp;edkEnd();
                }
            }
            this->buttons.clean();edkEnd();
        }
        //get the controllers size
        edk::uint32 getControllerSize(){
            return this->buttons.size();edkEnd();
        }
        //get the controller buttons size
        edk::uint32 getControllerButtonSizeByID(edk::uint32 controller){
            //get the controller
            edk::WindowEvents::ControllerButtons* temp = getButtons(controller);edkEnd();
            if(temp){
                return temp->buttons.size();edkEnd();
            }
            return 0u;edkEnd();
        }
        //get the controller buttons size in position
        edk::uint32 getControllerButtonSizeInPosition(edk::uint32 position){
            //get the controller
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(position);edkEnd();
            if(temp){
                return temp->buttons.size();edkEnd();
            }
            return 0u;edkEnd();
        }
        //get the controller button by ID
        edk::uint32 getControllerButtonByID(edk::uint32 controller,edk::uint32 position){
            edk::WindowEvents::ControllerButtons* temp = this->getButtons(controller);edkEnd();
            if(temp){
                return temp->buttons.getElementInPosition(position);edkEnd();
            }
            return 0u;edkEnd();
        }
        //get the controller button in position
        edk::uint32 getControllerButtonInPosition(edk::uint32 controllerPosition,edk::uint32 position){
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(controllerPosition);edkEnd();
            if(temp){
                return temp->buttons.getElementInPosition(position);edkEnd();
            }
            return 0u;edkEnd();
        }
        //return the controller ID
        edk::uint32 getControllerIDInPosition(edk::uint32 controllerPosition){
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(controllerPosition);edkEnd();
            if(temp){
                return temp->controller;edkEnd();
            }
            return 0u;edkEnd();
        }
        //add a button pressed
        bool addButton(edk::uint32 controllerID,edk::uint32 button){
            //test if have the controller
            edk::WindowEvents::ControllerButtons* temp = this->getButtons(controllerID);edkEnd();
            //test if dont have the button
            if(!temp){
                //create a new button
                temp = new edk::WindowEvents::ControllerButtons;edkEnd();
                if(temp){
                    temp->controller = controllerID;edkEnd();
                    //add the button
                    if(!this->buttons.add(temp)){
                        //cant add the temp
                        delete temp;edkEnd();
                        return false;
                    }
                }
            }
            if(temp){
                //add the button
                temp->buttons.add(button);edkEnd();
                return true;
            }
            return false;
        }
        bool removeControllerButtonByID(edk::uint32 controllerID,edk::uint32 button){
            edk::WindowEvents::ControllerButtons* temp = getButtons(controllerID);edkEnd();
            if(temp){
                return temp->buttons.remove(button);edkEnd();
            }
            return false;
        }
        bool removeControllerButtonInPosition(edk::uint32 controllerPosition,edk::uint32 button){
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(controllerPosition);edkEnd();
            if(temp){
                return temp->buttons.remove(button);edkEnd();
            }
            return false;
        }
        //clean controller buttons
        bool cleanControllerButtonsByID(edk::uint32 controllerID){
            edk::WindowEvents::ControllerButtons* temp = getButtons(controllerID);edkEnd();
            if(temp){
                //remove this controller
                temp->buttons.clean();edkEnd();
                if(this->buttons.remove(temp)){
                    delete temp;edkEnd();
                    return true;
                }
            }
            return false;
        }
        bool cleanControllerButtonsInPosition(edk::uint32 controllerPosition){
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(controllerPosition);edkEnd();
            if(temp){
                temp->buttons.clean();edkEnd();
                if(this->buttons.remove(temp)){
                    delete temp;edkEnd();
                    return true;
                }
            }
            return false;
        }

    protected:
        class ButtonTree: public edk::vector::BinaryTree<edk::WindowEvents::ControllerButtons*>{
        public:
            ButtonTree(){}
            ~ButtonTree(){}
            //compare if the value is bigger
            bool firstBiggerSecond(edk::WindowEvents::ControllerButtons* first,edk::WindowEvents::ControllerButtons* second){
                if(first&&second){
                    if(first->controller>second->controller){
                        return true;
                    }
                }
                return false;
            }
            bool firstEqualSecond(edk::WindowEvents::ControllerButtons* first,edk::WindowEvents::ControllerButtons* second){
                if(first&&second){
                    if(first->controller==second->controller){
                        return true;
                    }
                }
                return false;
            }
        }buttons;

        //get the controller by ID
        edk::WindowEvents::ControllerButtons* getButtons(edk::uint32 controller){
            edk::WindowEvents::ControllerButtons find;edkEnd();
            find.controller = controller;edkEnd();
            return this->buttons.getElement(&find);
        }
        edk::WindowEvents::ControllerButtons* getButtonsInPosition(edk::uint32 position){
            return this->buttons.getElementInPosition(position);edkEnd();
        }
        //test if have Buttons
        bool haveButtons(edk::uint32 controller){
            edk::WindowEvents::ControllerButtons find;edkEnd();
            find.controller = controller;edkEnd();
            return this->buttons.haveElement(&find);
        }
    };
    class ControllerAxis: public edk::WindowEvents::ControllerButtons{
    public:
        ControllerAxis(){this->controller=0u;edkEnd();}
        virtual ~ControllerAxis(){this->axisValue.clean();edkEnd();}
        class AxisValue{
        public:
            AxisValue(){this->value=0.f;edkEnd();this->id=0u;edkEnd();}
            ~AxisValue(){}
            edk::float32 value;
            edk::uint32 id;
        };
        //tree to save the values
        class AxisValueTree: public edk::vector::BinaryTree<edk::WindowEvents::ControllerAxis::AxisValue*>{
        public:
            AxisValueTree(){}
            ~AxisValueTree(){}
            bool firstBiggerSecond(edk::WindowEvents::ControllerAxis::AxisValue* first,edk::WindowEvents::ControllerAxis::AxisValue* second){
                if(first&&second){
                    if(first->id>second->id){
                        return true;
                    }
                }
                return false;
            }
            bool firstEqualSecond(edk::WindowEvents::ControllerAxis::AxisValue* first,edk::WindowEvents::ControllerAxis::AxisValue* second){
                if(first&&second){
                    if(first->id==second->id){
                        return true;
                    }
                }
                return false;
            }
            //add the value
            bool addAxis(edk::uint32 axis,edk::float32 value){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getAxis(axis);edkEnd();
                if(!temp){
                    //create a new axis
                    temp = new edk::WindowEvents::ControllerAxis::AxisValue;edkEnd();
                    if(temp){
                        temp->id=axis;edkEnd();
                        if(!this->add(temp)){
                            delete temp;edkEnd();
                            return false;
                        }
                    }
                }
                if(temp){
                    //set the value
                    temp->value = value;edkEnd();
                    return true;
                }
                //test if have the axisID
                return false;
            }
            //remove the axis
            bool removeAxisByID(edk::uint32 axis){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getAxis(axis);edkEnd();
                if(temp){
                    //remove the temp
                    if(this->remove(temp)){
                        //delete the temp
                        delete temp;edkEnd();
                        return true;
                    }
                }
                return false;
            }
            //remove the axis
            bool removeAxisInPosition(edk::uint32 position){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getElementInPosition(position);edkEnd();
                if(temp){
                    //remove the temp
                    if(this->remove(temp)){
                        //delete the temp
                        delete temp;edkEnd();
                        return true;
                    }
                }
                return false;
            }
            //return the axis id
            edk::uint32 getAxisID(edk::uint32 position){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getElementInPosition(position);edkEnd();
                if(temp){
                    return temp->id;edkEnd();
                }
                return 0u;edkEnd();
            }
            edk::float32 getAxisValueByID(edk::uint32 axisID){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getAxis(axisID);edkEnd();
                if(temp){
                    return temp->value;edkEnd();
                }
                return 0.f;
            }
            edk::float32 getAxisValueInPosition(edk::uint32 position){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getElementInPosition(position);edkEnd();
                if(temp){
                    return temp->value;edkEnd();
                }
                return 0.f;
            }
            //clean axis
            void cleanAxis(){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = NULL;edkEnd();
                edk::uint32 size = this->getSize();edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    temp = this->getElementInPosition(i);edkEnd();
                    if(temp){
                        delete temp;edkEnd();
                    }
                }
            }
        private:
            //get the Axis
            edk::WindowEvents::ControllerAxis::AxisValue* getAxis(edk::uint32 axis){
                edk::WindowEvents::ControllerAxis::AxisValue find;edkEnd();
                find.id = axis;edkEnd();
                return this->getElement(&find);
            }
        }axisValue;
    };
    class ControllerAxisEvent : private edk::WindowEvents::ControllerButtonsEvent{
    public:
        ControllerAxisEvent(){}
        ~ControllerAxisEvent(){}

        bool cloneFrom(edk::WindowEvents::ControllerAxisEvent* event){
            if(event){
                return edk::WindowEvents::ControllerButtonsEvent::cloneFrom(event);
            }
            return false;
        }

        void clean(){
            edk::WindowEvents::ControllerButtonsEvent::clean();edkEnd();
        }
        edk::uint32 getControllerSize(){
            return this->buttons.size();edkEnd();
        }
        //return the controller ID
        edk::uint32 getControllerIDInPosition(edk::uint32 controllerPosition){
            return edk::WindowEvents::ControllerButtonsEvent::getControllerIDInPosition(controllerPosition);edkEnd();
        }
        //get the controller buttons size
        edk::uint32 getControllerButtonSizeByID(edk::uint32 controllerID){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtons(controllerID);edkEnd();
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.size();edkEnd();
            }
            return 0u;edkEnd();
        }
        //get the controller buttons size in position
        edk::uint32 getControllerButtonSizeInPosition(edk::uint32 controllerPosition){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtonsInPosition(controllerPosition);edkEnd();
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.size();edkEnd();
            }
            return 0u;edkEnd();
        }
        //get the controller button by ID
        edk::uint32 getControllerAxisByID(edk::uint32 controllerID,edk::uint32 position){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtons(controllerID);edkEnd();
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.getAxisID(position);edkEnd();
            }
            return 0u;edkEnd();
        }//get the controller button in position
        edk::uint32 getControllerAxisInPosition(edk::uint32 controllerPosition,edk::uint32 position){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtonsInPosition(controllerPosition);edkEnd();
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.getAxisID(position);edkEnd();
            }
            return 0u;edkEnd();
        }
        //return the controller axisValue by ID
        edk::float32 getControllerAxisValueByID(edk::uint32 controllerID,edk::uint32 position){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtons(controllerID);edkEnd();
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.getAxisValueByID(position);edkEnd();
            }
            return 0.f;
        }
        //return the controller axisValue in position
        edk::float32 getControllerAxisValueInPosition(edk::uint32 controllerPosition,edk::uint32 position){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtonsInPosition(controllerPosition);edkEnd();
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.getAxisValueInPosition(position);edkEnd();
            }
            return 0.f;
        }

        //add a button pressed
        bool addAxis(edk::uint32 controllerID,edk::uint32 axisID,edk::float32 axisValue){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtons(controllerID);edkEnd();
            //test if dont have the button
            if(!temp){
                //create a new button
                temp = new edk::WindowEvents::ControllerAxis;edkEnd();
                if(temp){
                    temp->controller = controllerID;edkEnd();
                    //add the button
                    if(!this->buttons.add(temp)){
                        //cant add the temp
                        delete temp;edkEnd();
                        return false;
                    }
                }
            }
            if(temp){
                //add the button
                temp->buttons.add(axisID);edkEnd();
                temp->axisValue.addAxis(axisID,axisValue);edkEnd();
                return true;
            }
            return false;
        }
    };

public:
    //Controler
    edk::WindowEvents::ControllerButtonsEvent controllerPressed;
    edk::WindowEvents::ControllerButtonsEvent controllerHolded;
    edk::WindowEvents::ControllerButtonsEvent controllerReleased;
    edk::WindowEvents::ControllerAxisEvent controllerAxisMoved;
};
}//end namespace edk

#endif // WINDOWEVENTS_H
