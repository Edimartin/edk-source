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
    eventWindowMouseScrollWheelVertical,
    eventWindowMouseScrollWheelHorizontal,
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
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~WindowEvents(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;

            this->keyPressed.Constructor();
            this->keyRelease.Constructor();
            this->keyHolded.Constructor();
            this->keyText.Constructor();
            this->mousePressed.Constructor();
            this->mouseRelease.Constructor();
            this->mouseHolded.Constructor();
            this->mouseDoubleClick.Constructor();
            for(edk::uint32 i=0u;i<edk::mouse::mouseButtonsSize;i++){
                timeMouseDouble[i].Constructor();
            }
            this->controllerPressed.Constructor();
            this->controllerHolded.Constructor();
            this->controllerReleased.Constructor();
            this->controllerAxisMoved.Constructor();

            //
            this->focus=true;

            //start all doubleClicks
            edk::uint32 size = edk::mouse::mouseButtonsSize;
            for(edk::uint32 i=0u;i<size;i++){
                this->timeMouseDouble[i].start();
            }

            //set the mouse double click limit
            this->timeMouseDoubleLimit = EDK_TIME_LIMIT_DOUBLE_CLICK;
            this->runForceSecondPassed=false;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class

            this->keyPressed.Destructor();
            this->keyRelease.Destructor();
            this->keyHolded.Destructor();
            this->keyText.Destructor();
            this->mousePressed.Destructor();
            this->mouseRelease.Destructor();
            this->mouseHolded.Destructor();
            this->mouseDoubleClick.Destructor();
            for(edk::uint32 i=0u;i<edk::mouse::mouseButtonsSize;i++){
                timeMouseDouble[i].Destructor();
            }
            this->controllerPressed.Destructor();
            this->controllerHolded.Destructor();
            this->controllerReleased.Destructor();
            this->controllerAxisMoved.Destructor();
        }
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
            this->buttonExit = event->buttonExit;
            this->lostFocus = event->lostFocus;
            this->gainedFocus = event->gainedFocus;
            this->resize = event->resize;
            this->mouseMoved = event->mouseMoved;
            this->mouseEnter = event->mouseEnter;
            this->mouseExit = event->mouseExit;
            this->resizePos = event->resizePos;
            this->windowSize = event->windowSize;
            this->mousePosView = event->mousePosView;
            this->mousePosWorld = event->mousePosWorld;
            this->mousePosWindow = event->mousePosWindow;
            this->mouseMove = event->mouseMove;
            this->keyPressed.cloneFrom(&event->keyPressed);
            this->keyRelease.cloneFrom(&event->keyRelease);
            this->keyHolded.cloneFrom(&event->keyHolded);
            this->keyText.cloneFrom(&event->keyText);
            this->mousePressed.cloneFrom(&event->mousePressed);
            this->mouseRelease.cloneFrom(&event->mouseRelease);
            this->mouseHolded.cloneFrom(&event->mouseHolded);
            this->mouseDoubleClick.cloneFrom(&event->mouseDoubleClick);
            //this->mouseMoving.cloneFrom(event->mouseMoving);
            this->mouseScrollWheelVertical = event->mouseScrollWheelVertical;
            this->mouseScrollWheelHorizontal = event->mouseScrollWheelHorizontal;
            this->secondPassed = event->secondPassed;
            this->secondsGlobal = event->secondsGlobal;
            this->controllerPressed.cloneFrom(&event->controllerPressed);
            this->controllerHolded.cloneFrom(&event->controllerHolded);
            this->controllerReleased.cloneFrom(&event->controllerReleased);
            this->controllerAxisMoved.cloneFrom(&event->controllerAxisMoved);
            return true;
        }
        return false;
    }
    bool cloneFromSaved(edk::WindowEvents* event){
        //first clean this events
        this->clean();
        //test if have the event
        if(event){
            edk::uint32 size = 0u;
            edk::uint32 size2 = 0u;
            //copy the values
            //this->buttonExit = event->buttonExit;
            //this->lostFocus = event->lostFocus;
            //this->gainedFocus = event->gainedFocus;
            //this->resize = event->resize;
            //this->mouseMoved = event->mouseMoved;
            //this->mouseEnter = event->mouseEnter;
            //this->mouseExit = event->mouseExit;
            //this->resizePos = event->resizePos;
            //this->windowSize = event->windowSize;
            //this->mousePosView = event->mousePosView;
            //this->mousePosWorld = event->mousePosWorld;
            //this->mousePosWindow = event->mousePosWindow;
            this->mouseMove = event->mouseMove;
            //this->keyPressed.cloneFrom(&event->keyPressed);
            //this->keyRelease.cloneFrom(&event->keyRelease);
            size = event->keyHolded.size();
            for(edk::uint32 i=0u;i<size;i++){
                if(!event->keyRelease.haveElement(event->keyHolded.get(i))){
                    this->keyHolded.pushBack(event->keyHolded.get(i));
                }
            }
            //this->keyText.cloneFrom(&event->keyText);
            //this->mousePressed.cloneFrom(&event->mousePressed);
            //this->mouseRelease.cloneFrom(&event->mouseRelease);
            size = event->mouseHolded.size();
            for(edk::uint32 i=0u;i<size;i++){
                if(!event->mouseRelease.haveElement(event->mouseHolded.get(i))){
                    this->mouseHolded.pushBack(event->mouseHolded.get(i));
                }
            }
            //this->mouseDoubleClick.cloneFrom(&event->mouseDoubleClick);
            //this->mouseScrollWheelVertical = event->mouseScrollWheelVertical;
            //this->mouseScrollWheelHorizontal = event->mouseScrollWheelHorizontal;
            //this->secondPassed = event->secondPassed;
            //this->secondsGlobal = event->secondsGlobal;
            //this->controllerPressed.cloneFrom(&event->controllerPressed);
            size = event->controllerHolded.getControllerSize();
            for(edk::uint32 i=0u;i<size;i++){
                size2 = event->controllerHolded.getControllerButtonSizeByID(i);
                for(edk::uint32 j=0u;j<size2;j++){
                    if(!event->controllerReleased.haveButtonID(event->controllerHolded.getControllerIDInPosition(i),
                                                               event->controllerHolded.getControllerButtonInPosition(i,j)
                                                               )
                            ){
                        this->controllerHolded.addButton(event->controllerHolded.getControllerIDInPosition(i),
                                                         event->controllerHolded.getControllerButtonInPosition(i,j)
                                                         );
                    }
                }
            }
            //this->controllerReleased.cloneFrom(&event->controllerReleased);
            //this->controllerAxisMoved.cloneFrom(&event->controllerAxisMoved);
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
                || this->mouseScrollWheelVertical
                || this->mouseScrollWheelHorizontal
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
            case edk::eventWindowMouseScrollWheelVertical:
                if(this->mouseScrollWheelVertical){
                    return true;
                }
                break;
            case edk::eventWindowMouseScrollWheelHorizontal:
                if(this->mouseScrollWheelHorizontal){
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
                case edk::eventWindowMouseScrollWheelVertical:
                    if(this->mouseScrollWheelVertical){
                        return true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelHorizontal:
                    if(this->mouseScrollWheelHorizontal){
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
        printf("\nEvents:");
        bool have=false;
        if(this->buttonExit){
            printf("\n    edk::eventWindow_ButtonExit(TRUE)");
            have=true;
        }
        if(this->lostFocus){
            printf("\n    edk::eventWindow_LostFocus(TRUE)");
            have=true;
        }
        if(this->gainedFocus){
            printf("\n    edk::eventWindow_GainedFocus(TRUE)");
            have=true;
        }
        if(this->resize){
            printf("\n    edk::eventWindow_Resize(TRUE)"
                   "\n        WindowSize(%u,%u)"
                   "\n        ResizePos(%d,%d)"
                   ,this->windowSize.width
                   ,this->windowSize.height
                   ,this->resizePos.width
                   ,this->resizePos.height
                   );
            have=true;
        }
        if(this->mouseMoved){
            printf("\n    edk::eventWindow_MouseMoved(TRUE)"
                   "\n        MousePos(%d,%d)"
                   "\n        MousePosWorld(%d,%d)"
                   "\n        MousePosWindow(%d,%d)"
                   "\n        MouseMove(%d,%d)"
                   ,this->mousePosView.x
                   ,this->mousePosView.y
                   ,this->mousePosWorld.x
                   ,this->mousePosWorld.y
                   ,this->mousePosWindow.x
                   ,this->mousePosWindow.y
                   ,this->mouseMove.x
                   ,this->mouseMove.y
                   );
            have=true;
        }
        if(this->mouseEnter){
            printf("\n    edk::eventWindow_MouseEnter(TRUE)"
                   "\n        MousePos(%d,%d)"
                   "\n        MousePosWorld(%d,%d)"
                   "\n        MousePosWindow(%d,%d)"
                   "\n        MouseMove(%d,%d)"
                   ,this->mousePosView.x
                   ,this->mousePosView.y
                   ,this->mousePosWorld.x
                   ,this->mousePosWorld.y
                   ,this->mousePosWindow.x
                   ,this->mousePosWindow.y
                   ,this->mouseMove.x
                   ,this->mouseMove.y
                   );
            have=true;
        }
        if(this->mouseExit){
            printf("\n    edk::eventWindow_MouseExit(TRUE)"
                   "\n        MousePos(%d,%d)"
                   "\n        MousePosWorld(%d,%d)"
                   "\n        MousePosWindow(%d,%d)"
                   "\n        MouseMove(%d,%d)"
                   ,this->mousePosView.x
                   ,this->mousePosView.y
                   ,this->mousePosWorld.x
                   ,this->mousePosWorld.y
                   ,this->mousePosWindow.x
                   ,this->mousePosWindow.y
                   ,this->mouseMove.x
                   ,this->mouseMove.y
                   );
            have=true;
        }
        if(this->resizePos.width || this->resizePos.height){
            printf("\n    edk::eventWindow_ResizePos(%d,%d)"
                   ,this->resizePos.width
                   ,this->resizePos.height
                   );
            have=true;
        }
        /*
        if(this->windowSize.width || this->windowSize.height){
            printf("\n    edk::eventWindow_WindowSize(%u,%u)"
                   ,this->windowSize.width
                   ,this->windowSize.height
                   );
            have=true;
        }
        */
        /*
        if(this->mousePos.x || this->mousePos.y){
            printf("\n    edk::eventWindow_MousePos(%d,%d)"
                   ,this->mousePos.x
                   ,this->mousePos.y
                   );
            have=true;
        }
        */
        /*
        if(this->mousePosWorld.x || this->mousePosWorld.y){
            printf("\n    edk::eventWindow_MousePosWorld(%d,%d)"
                   ,this->mousePosWorld.x
                   ,this->mousePosWorld.y
                   );
            have=true;
        }
        */
        /*
        if(this->mousePosWindow.x || this->mousePosWindow.y){
            printf("\n    edk::eventWindow_MousePosWindow(%d,%d)"
                   ,this->mousePosWindow.x
                   ,this->mousePosWindow.y
                   );
            have=true;
        }
        */
        if(this->mouseMove.x || this->mouseMove.y){
            printf("\n    edk::eventWindow_MouseMove(%d,%d)"
                   ,this->mouseMove.x
                   ,this->mouseMove.y
                   );
            have=true;
        }
        if(this->keyPressed.size()){
            printf("\n    edk::eventWindow_KeyPressed(%u)"
                   ,this->keyPressed.size()
                   );
            edk::uint32 size = this->keyPressed.size();
            printf("\n        ");
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->keyPressed.get(i)
                       );
            }
            have=true;
        }
        if(this->keyRelease.size()){
            printf("\n    edk::eventWindow_KeyRelease(%u)"
                   ,this->keyRelease.size()
                   );
            edk::uint32 size = this->keyRelease.size();
            printf("\n        ");
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->keyRelease.get(i)
                       );
            }
            have=true;
        }
        if(this->keyHolded.size()){
            printf("\n    edk::eventWindow_KeyHolded(%u)"
                   ,this->keyHolded.size()
                   );
            edk::uint32 size = this->keyHolded.size();
            printf("\n        ");
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->keyHolded.get(i)
                       );
            }
            have=true;
        }
        if(this->keyText.size()){
            printf("\n    edk::eventWindow_KeyText(%u)"
                   ,this->keyText.size()
                   );
            edk::uint32 size = this->keyText.size();
            printf("\n        ");
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->keyText.get(i)
                       );
            }
            have=true;
        }
        if(this->mousePressed.size()){
            printf("\n    edk::eventWindow_MousePressed(%u)"
                   ,this->mousePressed.size()
                   );
            edk::uint32 size = this->mousePressed.size();
            printf("\n        ");
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->mousePressed.get(i)
                       );
            }
            have=true;
        }
        if(this->mouseRelease.size()){
            printf("\n    edk::eventWindow_MouseRelease(%u)"
                   ,this->mouseRelease.size()
                   );
            edk::uint32 size = this->mouseRelease.size();
            printf("\n        ");
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->mouseRelease.get(i)
                       );
            }
            have=true;
        }
        if(this->mouseHolded.size()){
            printf("\n    edk::eventWindow_MouseHolded(%u)"
                   ,this->mouseHolded.size()
                   );
            edk::uint32 size = this->mouseHolded.size();
            printf("\n        ");
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->mouseHolded.get(i)
                       );
            }
            have=true;
        }
        if(this->mouseDoubleClick.size()){
            printf("\n    edk::eventWindow_MouseDoubleClick(%u)"
                   ,this->mouseDoubleClick.size()
                   );
            edk::uint32 size = this->mouseDoubleClick.size();
            printf("\n        ");
            for(edk::uint32 i=0u;i<size;i++){
                printf("[%u]"
                       ,this->mouseDoubleClick.get(i)
                       );
            }
            have=true;
        }
        //if(this->mouseMoving.size()){}
        if(this->mouseScrollWheelVertical){
            printf("\n    edk::eventWindow_MouseScrollWheelVertical(%d)"
                   ,this->mouseScrollWheelVertical
                   );
            have=true;
        }
        if(this->mouseScrollWheelHorizontal){
            printf("\n    edk::eventWindow_MouseScrollWheelHorizontal(%d)"
                   ,this->mouseScrollWheelHorizontal
                   );
            have=true;
        }
        /*
        if(this->secondPassed){
            printf("\n    edk::eventWindow_SecondPassed(%.4f)"
                   ,this->secondPassed
                   );
            have=true;
        }
        */
        /*
        if(this->secondsGlobal){
            printf("\n    edk::eventWindow_SecondsGlobal(%.4f)"
                   ,this->secondsGlobal
                   );
            have=true;
        }
        */
        if(this->controllerPressed.getControllerSize()){
            printf("\n    edk::eventWindow_ControllerPressed(%u)"
                   ,this->controllerPressed.getControllerSize()
                   );
            edk::uint32 sizeI = this->controllerPressed.getControllerSize();
            for(edk::uint32 i=0u;i<sizeI;i++){
                printf("\n        (%u)"
                       ,this->controllerPressed.getControllerIDInPosition(i)
                       );
                edk::uint32 sizeJ = this->controllerPressed.getControllerButtonSizeInPosition(i);
                for(edk::uint32 j=0u;j<sizeJ;j++){
                    printf("[%u]"
                           ,this->controllerPressed.getControllerButtonByID(i,j)
                           );
                }
            }
            have=true;
        }
        if(this->controllerHolded.getControllerSize()){
            printf("\n    edk::eventWindow_ControllerHolded(%u)"
                   ,this->controllerHolded.getControllerSize()
                   );
            edk::uint32 sizeI = this->controllerHolded.getControllerSize();
            for(edk::uint32 i=0u;i<sizeI;i++){
                printf("\n        (%u)"
                       ,this->controllerHolded.getControllerIDInPosition(i)
                       );
                edk::uint32 sizeJ = this->controllerHolded.getControllerButtonSizeInPosition(i);
                for(edk::uint32 j=0u;j<sizeJ;j++){
                    printf("[%u]"
                           ,this->controllerHolded.getControllerButtonByID(i,j)
                           );
                }
            }
            have=true;
        }
        if(this->controllerReleased.getControllerSize()){
            printf("\n    edk::eventWindow_ControllerReleased(%u)"
                   ,this->controllerReleased.getControllerSize()
                   );
            edk::uint32 sizeI = this->controllerReleased.getControllerSize();
            for(edk::uint32 i=0u;i<sizeI;i++){
                printf("\n        (%u)"
                       ,this->controllerReleased.getControllerIDInPosition(i)
                       );
                edk::uint32 sizeJ = this->controllerReleased.getControllerButtonSizeInPosition(i);
                for(edk::uint32 j=0u;j<sizeJ;j++){
                    printf("[%u]"
                           ,this->controllerReleased.getControllerButtonByID(i,j)
                           );
                }
            }
            have=true;
        }
        if(this->controllerAxisMoved.getControllerSize()){
            printf("\n    edk::eventWindow_ControllerAxisMoved(%u)"
                   ,this->controllerAxisMoved.getControllerSize()
                   );
            edk::uint32 sizeI = this->controllerAxisMoved.getControllerSize();
            for(edk::uint32 i=0u;i<sizeI;i++){
                printf("\n        (%u)"
                       ,this->controllerAxisMoved.getControllerIDInPosition(i)
                       );
                edk::uint32 sizeJ = this->controllerAxisMoved.getControllerButtonSizeInPosition(i);
                for(edk::uint32 j=0u;j<sizeJ;j++){
                    printf("[%u,%.2f]"
                           ,this->controllerAxisMoved.getControllerAxisIDInPosition(i,j)
                           ,this->controllerAxisMoved.getControllerAxisValueInPosition(i,j)
                           );
                }
            }
            have=true;
        }
        if(!have){
            printf("\n    NOTHING");
        }
        fflush(stdout);
    }
    //write the events into a file
    bool writeFile(edk::File* file){
        if(file){
            bool ret=false;
            bool writeWindowSize=false;
            bool writeMousePos=false;
            bool writeMousePosWorld=false;
            bool writeMousePosWindow=false;

            //first write the size of elements
            edk::uint32 sizeElements=0u;
            if(this->buttonExit){
                sizeElements++;
            }
            if(this->lostFocus){
                sizeElements++;
            }
            if(this->gainedFocus){
                sizeElements++;
            }
            if(this->resize){
                sizeElements++;
                writeWindowSize=true;
            }
            if(this->mouseMoved){
                sizeElements++;
                writeMousePos=true;
                writeMousePosWorld=true;
                writeMousePosWindow=true;
            }
            if(this->mouseEnter){
                sizeElements++;
                writeMousePos=true;
                writeMousePosWorld=true;
                writeMousePosWindow=true;
            }
            if(this->mouseExit){
                sizeElements++;
                writeMousePos=true;
                writeMousePosWorld=true;
                writeMousePosWindow=true;
            }
            if(this->resizePos.width || this->resizePos.height){
                sizeElements++;
                writeWindowSize=true;
            }


            if(writeWindowSize){
                sizeElements++;
            }
            if(writeMousePos){
                sizeElements++;
            }
            if(writeMousePosWindow){
                sizeElements++;
            }
            if(writeMousePosWorld){
                sizeElements++;
            }


            if(this->mouseMove.x || this->mouseMove.y){
                sizeElements++;
            }
            if(this->keyPressed.size()){
                sizeElements++;
            }
            if(this->keyRelease.size()){
                sizeElements++;
            }
            if(this->keyHolded.size()){
                sizeElements++;
            }
            if(this->keyText.size()){
                sizeElements++;
            }
            if(this->mousePressed.size()){
                sizeElements++;
            }
            if(this->mouseRelease.size()){
                sizeElements++;
            }
            if(this->mouseHolded.size()){
                sizeElements++;
            }
            if(this->mouseDoubleClick.size()){
                sizeElements++;
            }
            //if(this->mouseMoving.size()){}
            if(this->mouseScrollWheelVertical){
                sizeElements++;
            }
            if(this->mouseScrollWheelHorizontal){
                sizeElements++;
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
                sizeElements++;
            }
            if(this->controllerHolded.getControllerSize()){
                sizeElements++;
            }
            if(this->controllerReleased.getControllerSize()){
                sizeElements++;
            }
            if(this->controllerAxisMoved.getControllerSize()){
                sizeElements++;
            }
            //write the sizeElements
            file->writeBin((edk::uint32)sizeElements);


            //write the elements
            if(this->buttonExit){
                file->writeBin((edk::uint32)edk::eventWindowButtonExit);
                ret=true;
            }
            if(this->lostFocus){
                file->writeBin((edk::uint32)edk::eventWindowLostFocus);
                ret=true;
            }
            if(this->gainedFocus){
                file->writeBin((edk::uint32)edk::eventWindowGainedFocus);
                ret=true;
            }
            if(this->resize){
                file->writeBin((edk::uint32)edk::eventWindowResize);
                writeWindowSize=true;
                ret=true;
            }
            if(this->mouseMoved){
                file->writeBin((edk::uint32)edk::eventWindowMouseMoved);
                writeMousePos=true;
                writeMousePosWorld=true;
                writeMousePosWindow=true;
                ret=true;
            }
            if(this->mouseEnter){
                file->writeBin((edk::uint32)edk::eventWindowMouseEnter);
                writeMousePos=true;
                writeMousePosWorld=true;
                writeMousePosWindow=true;
                ret=true;
            }
            if(this->mouseExit){
                file->writeBin((edk::uint32)edk::eventWindowMouseExit);
                writeMousePos=true;
                writeMousePosWorld=true;
                writeMousePosWindow=true;
                ret=true;
            }
            if(this->resizePos.width || this->resizePos.height){
                file->writeBin((edk::uint32)edk::eventWindowResizePos);
                file->writeBin(this->resizePos.width);
                file->writeBin(this->resizePos.height);
                writeWindowSize=true;
                ret=true;
            }


            if(this->mouseMove.x || this->mouseMove.y){
                file->writeBin((edk::uint32)edk::eventWindowMouseMove);
                file->writeBin(this->mouseMove.x);
                file->writeBin(this->mouseMove.y);
                ret=true;
            }
            if(this->keyPressed.size()){
                file->writeBin((edk::uint32)edk::eventWindowKeyPressed);
                edk::uint32 size = this->keyPressed.size();
                file->writeBin((edk::uint32)size);
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->keyPressed.get(i));
                }
                ret=true;
            }
            if(this->keyRelease.size()){
                file->writeBin((edk::uint32)edk::eventWindowKeyRelease);
                edk::uint32 size = this->keyRelease.size();
                file->writeBin((edk::uint32)size);
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->keyRelease.get(i));
                }
                ret=true;
            }
            if(this->keyHolded.size()){
                file->writeBin((edk::uint32)edk::eventWindowKeyHolded);
                edk::uint32 size = this->keyHolded.size();
                file->writeBin((edk::uint32)size);
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->keyHolded.get(i));
                }
                ret=true;
            }
            if(this->keyText.size()){
                file->writeBin((edk::uint32)edk::eventWindowKeyText);
                edk::uint32 size = this->keyText.size();
                file->writeBin((edk::uint32)size);
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->keyText.get(i));
                }
                ret=true;
            }
            if(this->mousePressed.size()){
                file->writeBin((edk::uint32)edk::eventWindowMousePressed);
                edk::uint32 size = this->mousePressed.size();
                file->writeBin((edk::uint32)size);
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->mousePressed.get(i));
                }
                ret=true;
            }
            if(this->mouseRelease.size()){
                file->writeBin((edk::uint32)edk::eventWindowMouseRelease);
                edk::uint32 size = this->mouseRelease.size();
                file->writeBin((edk::uint32)size);
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->mouseRelease.get(i));
                }
                ret=true;
            }
            if(this->mouseHolded.size()){
                file->writeBin((edk::uint32)edk::eventWindowMouseHolded);
                edk::uint32 size = this->mouseHolded.size();
                file->writeBin((edk::uint32)size);
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->mouseHolded.get(i));
                }
                ret=true;
            }
            if(this->mouseDoubleClick.size()){
                file->writeBin((edk::uint32)edk::eventWindowMouseDoubleClick);
                edk::uint32 size = this->mouseDoubleClick.size();
                file->writeBin((edk::uint32)size);
                for(edk::uint32 i=0u;i<size;i++){
                    file->writeBin((edk::uint32)this->mouseDoubleClick.get(i));
                }
                ret=true;
            }
            //if(this->mouseMoving.size()){}
            if(this->mouseScrollWheelVertical){
                file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheelVertical);
                file->writeBin((edk::int32)this->mouseScrollWheelVertical);
                ret=true;
            }
            if(this->mouseScrollWheelHorizontal){
                file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheelHorizontal);
                file->writeBin((edk::int32)this->mouseScrollWheelHorizontal);
                ret=true;
            }
            /*
            if(this->secondPassed){
                file->writeBin((edk::uint32)edk::eventWindowSecondPassed);
                ret=true;
            }
            */
            /*
            if(this->secondsGlobal){
                file->writeBin((edk::uint32)edk::eventWindowSecondsGlobal);
                ret=true;
            }
            */
            if(this->controllerPressed.getControllerSize()){
                file->writeBin((edk::uint32)edk::eventWindowControllerPressed);
                edk::uint32 sizeI = this->controllerPressed.getControllerSize();
                file->writeBin((edk::uint32)sizeI);
                for(edk::uint32 i=0u;i<sizeI;i++){
                    file->writeBin((edk::uint32)this->controllerPressed.getControllerIDInPosition(i));
                    edk::uint32 sizeJ = this->controllerPressed.getControllerButtonSizeInPosition(i);
                    file->writeBin((edk::uint32)sizeJ);
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        file->writeBin((edk::uint32)this->controllerPressed.getControllerButtonByID(i,j));
                    }
                }
                ret=true;
            }
            if(this->controllerHolded.getControllerSize()){
                file->writeBin((edk::uint32)edk::eventWindowControllerHolded);
                edk::uint32 sizeI = this->controllerHolded.getControllerSize();
                file->writeBin((edk::uint32)sizeI);
                for(edk::uint32 i=0u;i<sizeI;i++){
                    file->writeBin((edk::uint32)this->controllerHolded.getControllerIDInPosition(i));
                    edk::uint32 sizeJ = this->controllerHolded.getControllerButtonSizeInPosition(i);
                    file->writeBin((edk::uint32)sizeJ);
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        file->writeBin((edk::uint32)this->controllerHolded.getControllerButtonByID(i,j));
                    }
                }
                ret=true;
            }
            if(this->controllerReleased.getControllerSize()){
                file->writeBin((edk::uint32)edk::eventWindowControllerReleased);
                edk::uint32 sizeI = this->controllerReleased.getControllerSize();
                file->writeBin((edk::uint32)sizeI);
                for(edk::uint32 i=0u;i<sizeI;i++){
                    file->writeBin((edk::uint32)this->controllerReleased.getControllerIDInPosition(i));
                    edk::uint32 sizeJ = this->controllerReleased.getControllerButtonSizeInPosition(i);
                    file->writeBin((edk::uint32)sizeJ);
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        file->writeBin((edk::uint32)this->controllerReleased.getControllerButtonByID(i,j));
                    }
                }
                ret=true;
            }
            if(this->controllerAxisMoved.getControllerSize()){
                file->writeBin((edk::uint32)edk::eventWindowControllerAxisMoved);
                edk::uint32 sizeI = this->controllerAxisMoved.getControllerSize();
                file->writeBin((edk::uint32)sizeI);
                for(edk::uint32 i=0u;i<sizeI;i++){
                    file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerIDInPosition(i));
                    edk::uint32 sizeJ = this->controllerAxisMoved.getControllerButtonSizeInPosition(i);
                    file->writeBin((edk::uint32)sizeJ);
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisIDInPosition(i,j));
                        file->writeBin((edk::float32)this->controllerAxisMoved.getControllerAxisValueInPosition(i,j));
                    }
                }
                ret=true;
            }

            if(writeWindowSize){
                file->writeBin((edk::uint32)edk::eventWindowWindowSize);
                file->writeBin(this->windowSize.width);
                file->writeBin(this->windowSize.height);
                ret=true;
            }
            if(writeMousePos){
                file->writeBin((edk::uint32)edk::eventWindowMousePos);
                file->writeBin(this->mousePosView.x);
                file->writeBin(this->mousePosView.y);
                ret=true;
            }
            if(writeMousePosWindow){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWindow);
                file->writeBin(this->mousePosWindow.x);
                file->writeBin(this->mousePosWindow.y);
                ret=true;
            }
            if(writeMousePosWorld){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWorld);
                file->writeBin(this->mousePosWorld.x);
                file->writeBin(this->mousePosWorld.y);
                ret=true;
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

            bool writeWindowSize=false;
            bool writeMousePos=false;
            bool writeMousePosWorld=false;
            bool writeMousePosWindow=false;

            //first write the size of elements
            edk::uint32 sizeElements=0u;

            while(type){
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        sizeElements++;
                        writeWindowSize=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        sizeElements++;
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        sizeElements++;
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        sizeElements++;
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        sizeElements++;
                        writeWindowSize=true;
                        ret=true;
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
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelVertical:
                    if(this->mouseScrollWheelVertical){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelHorizontal:
                    if(this->mouseScrollWheelHorizontal){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        sizeElements++;
                        ret=true;
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
                sizeElements++;
            }
            if(writeMousePos){
                sizeElements++;
            }
            if(writeMousePosWindow){
                sizeElements++;
            }
            if(writeMousePosWorld){
                sizeElements++;
            }
            //write the sizeElements
            file->writeBin((edk::uint32)sizeElements);

            file->flush();


            if(!sizeElements){
                return false;
            }





            writeWindowSize=false;
            writeMousePos=false;
            writeMousePosWorld=false;
            writeMousePosWindow=false;





            first=true;
            //
            typeTemp = types;
            type = (edk::EventWindowType)typeTemp;
            while(type){
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        file->writeBin((edk::uint32)edk::eventWindowButtonExit);
                        ret=true;
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        file->writeBin((edk::uint32)edk::eventWindowLostFocus);
                        ret=true;
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        file->writeBin((edk::uint32)edk::eventWindowGainedFocus);
                        ret=true;
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        file->writeBin((edk::uint32)edk::eventWindowResize);
                        writeWindowSize=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        file->writeBin((edk::uint32)edk::eventWindowMouseMoved);
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        file->writeBin((edk::uint32)edk::eventWindowMouseEnter);
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        file->writeBin((edk::uint32)edk::eventWindowMouseExit);
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        file->writeBin((edk::uint32)edk::eventWindowResizePos);
                        file->writeBin(this->resizePos.width);
                        file->writeBin(this->resizePos.height);
                        writeWindowSize=true;
                        ret=true;
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
                        file->writeBin((edk::uint32)edk::eventWindowMouseMove);
                        file->writeBin(this->mouseMove.x);
                        file->writeBin(this->mouseMove.y);
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyPressed);
                        edk::uint32 size = this->keyPressed.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyPressed.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyRelease);
                        edk::uint32 size = this->keyRelease.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyRelease.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyHolded);
                        edk::uint32 size = this->keyHolded.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyHolded.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyText);
                        edk::uint32 size = this->keyText.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyText.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMousePressed);
                        edk::uint32 size = this->mousePressed.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mousePressed.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseRelease);
                        edk::uint32 size = this->mouseRelease.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseRelease.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseHolded);
                        edk::uint32 size = this->mouseHolded.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseHolded.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseDoubleClick);
                        edk::uint32 size = this->mouseDoubleClick.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseDoubleClick.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelVertical:
                    if(this->mouseScrollWheelVertical){
                        file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheelVertical);
                        file->writeBin((edk::int32)this->mouseScrollWheelVertical);
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelHorizontal:
                    if(this->mouseScrollWheelHorizontal){
                        file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheelHorizontal);
                        file->writeBin((edk::int32)this->mouseScrollWheelHorizontal);
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerPressed);
                        edk::uint32 sizeI = this->controllerPressed.getControllerSize();
                        file->writeBin((edk::uint32)sizeI);
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerPressed.getControllerIDInPosition(i));
                            edk::uint32 sizeJ = this->controllerPressed.getControllerButtonSizeInPosition(i);
                            file->writeBin((edk::uint32)sizeJ);
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerPressed.getControllerButtonByID(i,j));
                            }
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerHolded);
                        edk::uint32 sizeI = this->controllerHolded.getControllerSize();
                        file->writeBin((edk::uint32)sizeI);
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerHolded.getControllerIDInPosition(i));
                            edk::uint32 sizeJ = this->controllerHolded.getControllerButtonSizeInPosition(i);
                            file->writeBin((edk::uint32)sizeJ);
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerHolded.getControllerButtonByID(i,j));
                            }
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerReleased);
                        edk::uint32 sizeI = this->controllerReleased.getControllerSize();
                        file->writeBin((edk::uint32)sizeI);
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerReleased.getControllerIDInPosition(i));
                            edk::uint32 sizeJ = this->controllerReleased.getControllerButtonSizeInPosition(i);
                            file->writeBin((edk::uint32)sizeJ);
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerReleased.getControllerButtonByID(i,j));
                            }
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerAxisMoved);
                        edk::uint32 sizeI = this->controllerAxisMoved.getControllerSize();
                        file->writeBin((edk::uint32)sizeI);
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerIDInPosition(i));
                            edk::uint32 sizeJ = this->controllerAxisMoved.getControllerButtonSizeInPosition(i);
                            file->writeBin((edk::uint32)sizeJ);
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisIDInPosition(i,j));
                                file->writeBin((edk::float32)this->controllerAxisMoved.getControllerAxisValueInPosition(i,j));
                            }
                        }
                        ret=true;
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
                file->writeBin((edk::uint32)edk::eventWindowWindowSize);
                file->writeBin(this->windowSize.width);
                file->writeBin(this->windowSize.height);
                ret=true;
            }
            if(writeMousePos){
                file->writeBin((edk::uint32)edk::eventWindowMousePos);
                file->writeBin(this->mousePosView.x);
                file->writeBin(this->mousePosView.y);
                ret=true;
            }
            if(writeMousePosWindow){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWorld);
                file->writeBin(this->mousePosWorld.x);
                file->writeBin(this->mousePosWorld.y);
                ret=true;
            }
            if(writeMousePosWorld){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWindow);
                file->writeBin(this->mousePosWindow.x);
                file->writeBin(this->mousePosWindow.y);
                ret=true;
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


            bool writeWindowSize=false;
            bool writeMousePos=false;
            bool writeMousePosWorld=false;
            bool writeMousePosWindow=false;

            //first write the size of elements
            edk::uint32 sizeElements=0u;

            edk::uint32 size = tree->size();

            for(edk::uint32 i=0u;i<size;i++){
                type = tree->getElementInPosition(i);
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        sizeElements++;
                        writeWindowSize=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        sizeElements++;
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        sizeElements++;
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        sizeElements++;
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        sizeElements++;
                        writeWindowSize=true;
                        ret=true;
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
                        sizeElements++;
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelVertical:
                    if(this->mouseScrollWheelVertical){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelHorizontal:
                    if(this->mouseScrollWheelHorizontal){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        sizeElements++;
                        ret=true;
                    }
                    break;
                default:
                    break;
                }
            }
            if(writeWindowSize){
                sizeElements++;
            }
            if(writeMousePos){
                sizeElements++;
            }
            if(writeMousePosWindow){
                sizeElements++;
            }
            if(writeMousePosWorld){
                sizeElements++;
            }
            //write the sizeElements
            file->writeBin((edk::uint32)sizeElements);

            file->flush();


            if(!sizeElements){
                return false;
            }



            writeWindowSize=false;
            writeMousePos=false;
            writeMousePosWorld=false;
            writeMousePosWindow=false;






            //write the values into the file
            for(edk::uint32 i=0u;i<size;i++){
                type = tree->getElementInPosition(i);
                switch(type){
                case edk::eventWindowButtonExit:
                    if(this->buttonExit){
                        file->writeBin((edk::uint32)edk::eventWindowButtonExit);
                        ret=true;
                    }
                    break;
                case edk::eventWindowLostFocus:
                    if(this->lostFocus){
                        file->writeBin((edk::uint32)edk::eventWindowLostFocus);
                        ret=true;
                    }
                    break;
                case edk::eventWindowGainedFocus:
                    if(this->gainedFocus){
                        file->writeBin((edk::uint32)edk::eventWindowGainedFocus);
                        ret=true;
                    }
                    break;
                case edk::eventWindowResize:
                    if(this->resize){
                        file->writeBin((edk::uint32)edk::eventWindowResize);
                        writeWindowSize=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseMoved:
                    if(this->mouseMoved){
                        file->writeBin((edk::uint32)edk::eventWindowMouseMoved);
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseEnter:
                    if(this->mouseEnter){
                        file->writeBin((edk::uint32)edk::eventWindowMouseEnter);
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseExit:
                    if(this->mouseExit){
                        file->writeBin((edk::uint32)edk::eventWindowMouseExit);
                        writeMousePos=true;
                        writeMousePosWorld=true;
                        writeMousePosWindow=true;
                        ret=true;
                    }
                    break;
                case edk::eventWindowResizePos:
                    if(this->resizePos.width || this->resizePos.height){
                        file->writeBin((edk::uint32)edk::eventWindowResizePos);
                        file->writeBin(this->resizePos.width);
                        file->writeBin(this->resizePos.height);
                        writeWindowSize=true;
                        ret=true;
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
                        file->writeBin((edk::uint32)edk::eventWindowMouseMove);
                        file->writeBin(this->mouseMove.x);
                        file->writeBin(this->mouseMove.y);
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyPressed:
                    if(this->keyPressed.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyPressed);
                        edk::uint32 size = this->keyPressed.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyPressed.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyRelease:
                    if(this->keyRelease.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyRelease);
                        edk::uint32 size = this->keyRelease.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyRelease.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyHolded:
                    if(this->keyHolded.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyHolded);
                        edk::uint32 size = this->keyHolded.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyHolded.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowKeyText:
                    if(this->keyText.size()){
                        file->writeBin((edk::uint32)edk::eventWindowKeyText);
                        edk::uint32 size = this->keyText.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->keyText.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMousePressed:
                    if(this->mousePressed.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMousePressed);
                        edk::uint32 size = this->mousePressed.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mousePressed.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseRelease:
                    if(this->mouseRelease.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseRelease);
                        edk::uint32 size = this->mouseRelease.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseRelease.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseHolded:
                    if(this->mouseHolded.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseHolded);
                        edk::uint32 size = this->mouseHolded.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseHolded.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseDoubleClick:
                    if(this->mouseDoubleClick.size()){
                        file->writeBin((edk::uint32)edk::eventWindowMouseDoubleClick);
                        edk::uint32 size = this->mouseDoubleClick.size();
                        file->writeBin((edk::uint32)size);
                        for(edk::uint32 i=0u;i<size;i++){
                            file->writeBin((edk::uint32)this->mouseDoubleClick.get(i));
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelVertical:
                    if(this->mouseScrollWheelVertical){
                        file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheelVertical);
                        file->writeBin((edk::int32)this->mouseScrollWheelVertical);
                        ret=true;
                    }
                    break;
                case edk::eventWindowMouseScrollWheelHorizontal:
                    if(this->mouseScrollWheelHorizontal){
                        file->writeBin((edk::uint32)edk::eventWindowMouseScrollWheelHorizontal);
                        file->writeBin((edk::int32)this->mouseScrollWheelHorizontal);
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerPressed:
                    if(this->controllerPressed.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerPressed);
                        edk::uint32 sizeI = this->controllerPressed.getControllerSize();
                        file->writeBin((edk::uint32)sizeI);
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerPressed.getControllerIDInPosition(i));
                            edk::uint32 sizeJ = this->controllerPressed.getControllerButtonSizeInPosition(i);
                            file->writeBin((edk::uint32)sizeJ);
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerPressed.getControllerButtonByID(i,j));
                            }
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerHolded:
                    if(this->controllerHolded.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerHolded);
                        edk::uint32 sizeI = this->controllerHolded.getControllerSize();
                        file->writeBin((edk::uint32)sizeI);
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerHolded.getControllerIDInPosition(i));
                            edk::uint32 sizeJ = this->controllerHolded.getControllerButtonSizeInPosition(i);
                            file->writeBin((edk::uint32)sizeJ);
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerHolded.getControllerButtonByID(i,j));
                            }
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerReleased:
                    if(this->controllerReleased.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerReleased);
                        edk::uint32 sizeI = this->controllerReleased.getControllerSize();
                        file->writeBin((edk::uint32)sizeI);
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerReleased.getControllerIDInPosition(i));
                            edk::uint32 sizeJ = this->controllerReleased.getControllerButtonSizeInPosition(i);
                            file->writeBin((edk::uint32)sizeJ);
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerReleased.getControllerButtonByID(i,j));
                            }
                        }
                        ret=true;
                    }
                    break;
                case edk::eventWindowControllerAxisMoved:
                    if(this->controllerAxisMoved.getControllerSize()){
                        file->writeBin((edk::uint32)edk::eventWindowControllerAxisMoved);
                        edk::uint32 sizeI = this->controllerAxisMoved.getControllerSize();
                        file->writeBin((edk::uint32)sizeI);
                        for(edk::uint32 i=0u;i<sizeI;i++){
                            file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerIDInPosition(i));
                            edk::uint32 sizeJ = this->controllerAxisMoved.getControllerButtonSizeInPosition(i);
                            file->writeBin((edk::uint32)sizeJ);
                            for(edk::uint32 j=0u;j<sizeJ;j++){
                                file->writeBin((edk::uint32)this->controllerAxisMoved.getControllerAxisIDInPosition(i,j));
                                file->writeBin((edk::float32)this->controllerAxisMoved.getControllerAxisValueInPosition(i,j));
                            }
                        }
                        ret=true;
                    }
                    break;
                default:
                    break;
                }
            }
            if(writeWindowSize){
                file->writeBin((edk::uint32)edk::eventWindowWindowSize);
                file->writeBin(this->windowSize.width);
                file->writeBin(this->windowSize.height);
                ret=true;
            }
            if(writeMousePos){
                file->writeBin((edk::uint32)edk::eventWindowMousePos);
                file->writeBin(this->mousePosView.x);
                file->writeBin(this->mousePosView.y);
                ret=true;
            }
            if(writeMousePosWindow){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWorld);
                file->writeBin(this->mousePosWorld.x);
                file->writeBin(this->mousePosWorld.y);
                ret=true;
            }
            if(writeMousePosWorld){
                file->writeBin((edk::uint32)edk::eventWindowMousePosWindow);
                file->writeBin(this->mousePosWindow.x);
                file->writeBin(this->mousePosWindow.y);
                ret=true;
            }
            file->flush();
            //
        }
        return ret;
    }
    //read the events from a file
    bool readFile(edk::File* file){
        if(file){
            bool ret=false;
            edk::uint32 sizeElements = 0u;
            file->readBin(&sizeElements,sizeof(sizeElements));
            if(sizeElements<100u){
                edk::uint32 type;
                for(edk::uint32 e=0u;e<sizeElements;e++){
                    //get the type
                    file->readBin(&type,sizeof(edk::uint32));
                    switch(type){
                    case edk::eventWindowButtonExit:
                        this->buttonExit=true;
                        ret=true;
                        break;
                    case edk::eventWindowLostFocus:
                        this->lostFocus=true;
                        ret=true;
                        break;
                    case edk::eventWindowGainedFocus:
                        this->gainedFocus=true;
                        ret=true;
                        break;
                    case edk::eventWindowResize:
                        this->resize=true;
                        ret=true;
                        break;
                    case edk::eventWindowMouseMoved:
                        this->mouseMoved=true;
                        ret=true;
                        break;
                    case edk::eventWindowMouseEnter:
                        this->mouseEnter=true;
                        ret=true;
                        break;
                    case edk::eventWindowMouseExit:
                        this->mouseExit=true;
                        ret=true;
                        break;
                    case edk::eventWindowResizePos:
                        file->readBin(&this->resizePos.width,sizeof(this->resizePos.width));
                        file->readBin(&this->resizePos.height,sizeof(this->resizePos.height));
                        ret=true;
                        break;
                    case edk::eventWindowWindowSize:
                        file->readBin(&this->windowSize.width,sizeof(this->windowSize.width));
                        file->readBin(&this->windowSize.height,sizeof(this->windowSize.height));
                        ret=true;
                        break;
                    case edk::eventWindowMousePos:
                        file->readBin(&this->mousePosView.x,sizeof(this->mousePosView.x));
                        file->readBin(&this->mousePosView.y,sizeof(this->mousePosView.y));
                        ret=true;
                        break;
                    case edk::eventWindowMousePosWorld:
                        file->readBin(&this->mousePosWorld.x,sizeof(this->mousePosWorld.x));
                        file->readBin(&this->mousePosWorld.y,sizeof(this->mousePosWorld.y));
                        ret=true;
                        break;
                    case edk::eventWindowMousePosWindow:
                        file->readBin(&this->mousePosWindow.x,sizeof(this->mousePosWindow.x));
                        file->readBin(&this->mousePosWindow.y,sizeof(this->mousePosWindow.y));
                        ret=true;
                        break;
                    case edk::eventWindowMouseMove:
                        file->readBin(&this->mouseMove.x,sizeof(this->mouseMove.x));
                        file->readBin(&this->mouseMove.y,sizeof(this->mouseMove.y));
                        ret=true;
                        break;
                    case edk::eventWindowKeyPressed:
                    {
                        //get the size
                        edk::uint32 size = 0u;
                        edk::uint32 key = 0u;
                        file->readBin(&size,sizeof(size));
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->keyPressed.pushBack(key);
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowKeyRelease:
                    {
                        //get the size
                        edk::uint32 size = 0u;
                        file->readBin(&size,sizeof(size));
                        edk::uint32 key = 0u;
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->keyRelease.pushBack(key);
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowKeyHolded:
                    {
                        //get the size
                        edk::uint32 size = 0u;
                        file->readBin(&size,sizeof(size));
                        edk::uint32 key = 0u;
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->keyHolded.pushBack(key);
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowKeyText:
                    {
                        //get the size
                        edk::uint32 size = 0u;
                        file->readBin(&size,sizeof(size));
                        edk::uint32 key = 0u;
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->keyText.pushBack(key);
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowMousePressed:
                    {
                        //get the size
                        edk::uint32 size = 0u;
                        file->readBin(&size,sizeof(size));
                        edk::uint32 key = 0u;
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->mousePressed.pushBack(key);
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowMouseRelease:
                    {
                        //get the size
                        edk::uint32 size = 0u;
                        file->readBin(&size,sizeof(size));
                        edk::uint32 key = 0u;
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->mouseRelease.pushBack(key);
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowMouseHolded:
                    {
                        //get the size
                        edk::uint32 size = 0u;
                        file->readBin(&size,sizeof(size));
                        edk::uint32 key = 0u;
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->mouseHolded.pushBack(key);
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowMouseDoubleClick:
                    {
                        //get the size
                        edk::uint32 size = 0u;
                        file->readBin(&size,sizeof(size));
                        edk::uint32 key = 0u;
                        if(size<1000u){
                            for(edk::uint32 i=0u;i<size;i++){
                                //get the key
                                file->readBin(&key,sizeof(edk::uint32));
                                this->mouseDoubleClick.pushBack(key);
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowMouseScrollWheelVertical:
                        file->readBin(&this->mouseScrollWheelVertical,sizeof(this->mouseScrollWheelVertical));
                        ret=true;
                        break;
                    case edk::eventWindowMouseScrollWheelHorizontal:
                        file->readBin(&this->mouseScrollWheelHorizontal,sizeof(this->mouseScrollWheelHorizontal));
                        ret=true;
                        break;
                    case edk::eventWindowControllerPressed:
                    {
                        //get the sizeI
                        edk::uint32 sizeI = 0u;
                        file->readBin(&sizeI,sizeof(sizeI));
                        edk::uint32 controllerID;
                        edk::uint32 value;
                        edk::uint32 sizeJ;
                        if(sizeI<100u){
                            for(edk::uint32 i=0u;i<sizeI;i++){
                                file->readBin(&controllerID,sizeof(controllerID));
                                //get the sizeJ
                                file->readBin(&sizeJ,sizeof(sizeJ));
                                if(sizeJ<100u){
                                    for(edk::uint32 j=0u;j<sizeJ;j++){
                                        //get the button
                                        file->readBin(&value,sizeof(edk::uint32));
                                        this->controllerPressed.addButton(controllerID,value);
                                    }
                                }
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowControllerHolded:
                    {
                        //get the sizeI
                        edk::uint32 sizeI = 0u;
                        file->readBin(&sizeI,sizeof(sizeI));
                        edk::uint32 controllerID;
                        edk::uint32 value;
                        edk::uint32 sizeJ;
                        if(sizeI<100u){
                            for(edk::uint32 i=0u;i<sizeI;i++){
                                file->readBin(&controllerID,sizeof(controllerID));
                                //get the sizeJ
                                file->readBin(&sizeJ,sizeof(sizeJ));
                                if(sizeJ<100u){
                                    for(edk::uint32 j=0u;j<sizeJ;j++){
                                        //get the button
                                        file->readBin(&value,sizeof(edk::uint32));
                                        this->controllerHolded.addButton(controllerID,value);
                                    }
                                }
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowControllerReleased:
                    {
                        //get the sizeI
                        edk::uint32 sizeI = 0u;
                        file->readBin(&sizeI,sizeof(sizeI));
                        edk::uint32 controllerID;
                        edk::uint32 value;
                        edk::uint32 sizeJ;
                        if(sizeI<100u){
                            for(edk::uint32 i=0u;i<sizeI;i++){
                                file->readBin(&controllerID,sizeof(controllerID));
                                //get the sizeJ
                                file->readBin(&sizeJ,sizeof(sizeJ));
                                if(sizeJ<100u){
                                    for(edk::uint32 j=0u;j<sizeJ;j++){
                                        //get the button
                                        file->readBin(&value,sizeof(edk::uint32));
                                        this->controllerReleased.addButton(controllerID,value);
                                    }
                                }
                            }
                        }
                    }
                        ret=true;
                        break;
                    case edk::eventWindowControllerAxisMoved:
                    {
                        //get the sizeI
                        edk::uint32 sizeI = 0u;
                        file->readBin(&sizeI,sizeof(sizeI));
                        edk::uint32 controllerID;
                        edk::uint32 position;
                        edk::float32 value;
                        edk::uint32 sizeJ;
                        if(sizeI<100u){
                            for(edk::uint32 i=0u;i<sizeI;i++){
                                file->readBin(&controllerID,sizeof(controllerID));
                                //get the sizeJ
                                file->readBin(&sizeJ,sizeof(sizeJ));
                                if(sizeJ<100u){
                                    for(edk::uint32 j=0u;j<sizeJ;j++){
                                        //get the button
                                        file->readBin(&position,sizeof(position));
                                        file->readBin(&value,sizeof(value));
                                        this->controllerAxisMoved.addAxis(controllerID,position,value);
                                    }
                                }
                            }
                        }
                    }
                        ret=true;
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
        this->buttonExit = this->lostFocus = this->gainedFocus = this->resize = this->mouseMoved = this->mouseEnter = this->mouseExit = false;
        this->resizePos = edk::size2i32(0,0);
        this->windowSize = edk::size2ui32(0u,0u);
        this->mousePosView = edk::vec2i32(0,0);
        this->mousePosWorld = edk::vec2i32(0,0);
        this->mousePosWindow = edk::vec2i32(0,0);
        this->mouseMove = edk::vec2i32(0,0);
        this->keyPressed.clean();
        this->keyRelease.clean();
        this->keyHolded.clean();
        this->keyText.clean();
        this->mousePressed.clean();
        this->mouseRelease.clean();
        this->mouseHolded.clean();
        this->mouseDoubleClick.clean();
        //this->mouseMoving.clean();
        this->mouseScrollWheelVertical = 0u;
        this->mouseScrollWheelHorizontal = 0u;
        this->secondPassed = 0.f;
        this->secondsGlobal = 0.f;
        this->controllerPressed.clean();
        //this->controllerHolded.clean();
        this->controllerReleased.clean();
        this->controllerAxisMoved.clean();
    }
    void cleanMouseOnly(){
        this->mouseMoved = this->mouseEnter = this->mouseExit = false;
        this->mousePosView = edk::vec2i32(0,0);
        this->mousePosWorld = edk::vec2i32(0,0);
        this->mousePosWindow = edk::vec2i32(0,0);
        this->mouseMove = edk::vec2i32(0,0);
        this->mousePressed.clean();
        this->mouseRelease.clean();
        this->mouseHolded.clean();
        this->mouseDoubleClick.clean();
        //this->mouseMoving.clean();
        this->mouseScrollWheelVertical = 0u;
        this->mouseScrollWheelHorizontal = 0u;
    }
    //set the mouse double time limit
    bool setMouseDoubleClickLimit(edk::float32 seconds){
        if(seconds>0.f){
            this->timeMouseDoubleLimit = seconds;
            return true;
        }
        this->timeMouseDoubleLimit = EDK_TIME_LIMIT_DOUBLE_CLICK;
        return false;
    }
    edk::float32 getMouseDoubleClickLimit(){
        return this->timeMouseDoubleLimit;
    }

    //force the second passed
    bool forceSecondPassed(edk::float32 seconds){
        if(seconds>0.f){
            this->runForceSecondPassed=true;
            this->runForceSecondPassedValue=seconds;
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
            this->runForceSecondPassed=false;
            this->secondPassed = this->runForceSecondPassedValue;
            this->runForceSecondPassedValue=0.f;
            return true;
        }
        this->runForceSecondPassedValue=0.f;
        return false;
    }


    //Eventos
    bool buttonExit;
    //save the focus
    bool lostFocus;
    bool gainedFocus;
    bool focus;
    //sve the grab
    bool stopGrab;
    bool startGrab;
    bool grab;
    //sve the minimized
    bool minimizeWindow;
    bool restoreWindow;
    bool minimized;
    //Resize
    bool resize;
    edk::size2i32 resizePos;
    //Move
    bool move;
    edk::vec2i32 movePos;
    //save the size of the window
    edk::size2ui32 windowSize;
    //Keys
    edk::vector::Stack<edk::uint32> keyPressed;
    edk::vector::Stack<edk::uint32> keyRelease;
    edk::vector::Stack<edk::uint32> keyHolded;
    edk::vector::Stack<edk::uint32> keyText;
    edk::vector::Stack<edk::uint32> keyPressedGlobal;
    edk::vector::Stack<edk::uint32> keyReleaseGlobal;
    edk::vector::Stack<edk::uint32> keyHoldedGlobal;
    //Mouse
    edk::vector::Stack<edk::uint32> mousePressed;
    //edk::vector::Stack<edk::uint32> mouseMoving;
    edk::vector::Stack<edk::uint32> mouseRelease;
    edk::vector::Stack<edk::uint32> mouseHolded;
    edk::vector::Stack<edk::uint32> mouseDoubleClick;
    //mouse global
    bool mouseMovedGlobal;
    edk::vec2i32 mousePosWorldGlobal;  //mouse position inside the world
    edk::vec2i32 mousePosWindowGlobal; //mouse position inside the window
    edk::vec2i32 mouseMoveGlobal;
    //Mouse Movido
    bool mouseMoved;
    edk::vec2i32 mousePosView;       //mouse position inside the view
    edk::vec2i32 mousePosWorld;  //mouse position inside the world
    edk::vec2i32 mousePosWindow; //mouse position inside the window
    edk::vec2i32 mouseMove;
    //Mouse entrou
    bool mouseEnter;
    //Mouse saiu
    bool mouseExit;
    //mouseScroll
    edk::int32 mouseScrollWheelVertical;
    edk::int32 mouseScrollWheelHorizontal;
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
public:
    //Controller
    class ControllerButtons{
    public:
        ControllerButtons(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~ControllerButtons(){
            this->Destructor();
        }

        void Constructor(){
            if(this->classThis!=this){
                this->classThis=this;

                this->buttons.Constructor();

                this->controller=0u;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->buttons.clean();

                this->buttons.Destructor();
            }
        }

        edk::uint32 controller;
        edk::vector::BinaryTree<edk::uint32> buttons;
    private:
        edk::classID classThis;
    };
    //controller button tree
    class ControllerButtonsEvent{
    public:
        ControllerButtonsEvent(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~ControllerButtonsEvent(){
            this->Destructor();
        }

        void Constructor(){
            if(this->classThis!=this){
                this->classThis=this;

                this->buttons.Constructor();
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->clean();

                this->buttons.Destructor();
            }
        }

        bool cloneFrom(edk::WindowEvents::ControllerButtonsEvent* event){
            this->clean();
            if(event){
                //
                edk::uint32 size = this->buttons.size();
                edk::WindowEvents::ControllerButtons* temp=NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    temp = this->buttons.getElementInPosition(i);
                    if(temp){
                        edk::uint32 size = temp->buttons.size();
                        for(edk::uint32 j=0u;j<size;j++){
                            this->addButton(temp->controller,temp->buttons.getElementInPosition(j));
                        }
                    }
                }
                return true;
            }
            return false;
        }

        //clean the controllers
        void clean(){
            edk::uint32 size = this->buttons.size();
            edk::WindowEvents::ControllerButtons* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->buttons.getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            this->buttons.clean();
        }
        //get the controllers size
        edk::uint32 getControllerSize(){
            return this->buttons.size();
        }
        //get the controller buttons size
        edk::uint32 getControllerButtonSizeByID(edk::uint32 controller){
            //get the controller
            edk::WindowEvents::ControllerButtons* temp = getButtons(controller);
            if(temp){
                return temp->buttons.size();
            }
            return 0u;
        }
        //get the controller buttons size in position
        edk::uint32 getControllerButtonSizeInPosition(edk::uint32 position){
            //get the controller
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(position);
            if(temp){
                return temp->buttons.size();
            }
            return 0u;
        }
        //get the controller button by ID
        edk::uint32 getControllerButtonByID(edk::uint32 controller,edk::uint32 position){
            edk::WindowEvents::ControllerButtons* temp = this->getButtons(controller);
            if(temp){
                return temp->buttons.getElementInPosition(position);
            }
            return 0u;
        }
        //get the controller button in position
        edk::uint32 getControllerButtonInPosition(edk::uint32 controllerPosition,edk::uint32 position){
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(controllerPosition);
            if(temp){
                return temp->buttons.getElementInPosition(position);
            }
            return 0u;
        }
        //return the controller ID
        edk::uint32 getControllerIDInPosition(edk::uint32 controllerPosition){
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(controllerPosition);
            if(temp){
                return temp->controller;
            }
            return 0u;
        }
        //add a button pressed
        bool addButton(edk::uint32 controllerID,edk::uint32 button){
            //test if have the controller
            edk::WindowEvents::ControllerButtons* temp = this->getButtons(controllerID);
            //test if dont have the button
            if(!temp){
                //create a new button
                temp = new edk::WindowEvents::ControllerButtons;
                if(temp){
                    temp->controller = controllerID;
                    //add the button
                    if(!this->buttons.add(temp)){
                        //cant add the temp
                        delete temp;
                        return false;
                    }
                }
            }
            if(temp){
                //add the button
                temp->buttons.add(button);
                return true;
            }
            return false;
        }
        bool removeControllerButtonByID(edk::uint32 controllerID,edk::uint32 button){
            edk::WindowEvents::ControllerButtons* temp = getButtons(controllerID);
            if(temp){
                return temp->buttons.remove(button);
            }
            return false;
        }
        bool removeControllerButtonInPosition(edk::uint32 controllerPosition,edk::uint32 button){
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(controllerPosition);
            if(temp){
                return temp->buttons.remove(button);
            }
            return false;
        }
        //clean controller buttons
        bool cleanControllerButtonsByID(edk::uint32 controllerID){
            edk::WindowEvents::ControllerButtons* temp = getButtons(controllerID);
            if(temp){
                //remove this controller
                temp->buttons.clean();
                if(this->buttons.remove(temp)){
                    delete temp;
                    return true;
                }
            }
            return false;
        }
        bool cleanControllerButtonsInPosition(edk::uint32 controllerPosition){
            edk::WindowEvents::ControllerButtons* temp = this->getButtonsInPosition(controllerPosition);
            if(temp){
                temp->buttons.clean();
                if(this->buttons.remove(temp)){
                    delete temp;
                    return true;
                }
            }
            return false;
        }
        bool haveButtonID(edk::uint32 controllerID,edk::uint32 buttonID){
            edk::WindowEvents::ControllerButtons* temp = this->getButtons(controllerID);
            if(temp){
                temp->buttons.haveElement(buttonID);
            }
            return false;
        }

    protected:
        class ButtonTree: public edk::vector::BinaryTree<edk::WindowEvents::ControllerButtons*>{
        public:
            ButtonTree(){
                this->classThis=NULL;
                this->Constructor();
            }
            virtual ~ButtonTree(){
                this->Destructor();
            }

            void Constructor(){
                edk::vector::BinaryTree<edk::WindowEvents::ControllerButtons*>::Constructor();
                if(this->classThis!=this){
                    this->classThis=this;
                }
            }
            void Destructor(){
                if(this->classThis==this){
                    this->classThis=NULL;
                    //can destruct the class
                }
                edk::vector::BinaryTree<edk::WindowEvents::ControllerButtons*>::Destructor();
            }

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
        private:
            edk::classID classThis;
        }buttons;

        //get the controller by ID
        edk::WindowEvents::ControllerButtons* getButtons(edk::uint32 controller){
            edk::WindowEvents::ControllerButtons find;
            find.controller = controller;
            return this->buttons.getElement(&find);
        }
        edk::WindowEvents::ControllerButtons* getButtonsInPosition(edk::uint32 position){
            return this->buttons.getElementInPosition(position);
        }
        //test if have Buttons
        bool haveButtons(edk::uint32 controller){
            edk::WindowEvents::ControllerButtons find;
            find.controller = controller;
            return this->buttons.haveElement(&find);
        }
    private:
        edk::classID classThis;
    };
    class ControllerAxis: public edk::WindowEvents::ControllerButtons{
    public:
        ControllerAxis(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~ControllerAxis(){
            this->Destructor();
        }

        void Constructor(){
            edk::WindowEvents::ControllerButtons::Constructor();
            if(this->classThis!=this){
                this->classThis=this;

                this->axisValue.Constructor();

                this->controller=0u;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->axisValue.clean();

                this->axisValue.Destructor();
            }
            edk::WindowEvents::ControllerButtons::Destructor();
        }

        class AxisValue{
        public:
            AxisValue(){
                this->classThis=NULL;
                this->Constructor();
            }
            virtual ~AxisValue(){
                this->Destructor();
            }

            void Constructor(){
                if(this->classThis!=this){
                    this->classThis=this;
                    this->value=0.f;
                    this->id=0u;
                }
            }
            void Destructor(){
                if(this->classThis==this){
                    this->classThis=NULL;
                    //can destruct the class
                }
            }

            edk::float32 value;
            edk::uint32 id;
        private:
            edk::classID classThis;
        };
        //tree to save the values
        class AxisValueTree: public edk::vector::BinaryTree<edk::WindowEvents::ControllerAxis::AxisValue*>{
        public:
            AxisValueTree(){
                this->classThis=NULL;
                this->Constructor();
            }
            virtual ~AxisValueTree(){
                this->Destructor();
            }

            void Constructor(){
                edk::vector::BinaryTree<edk::WindowEvents::ControllerAxis::AxisValue*>::Constructor();
                if(this->classThis!=this){
                    this->classThis=this;
                }
            }
            void Destructor(){
                if(this->classThis==this){
                    this->classThis=NULL;
                    //can destruct the class
                }
                edk::vector::BinaryTree<edk::WindowEvents::ControllerAxis::AxisValue*>::Destructor();
            }

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
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getAxis(axis);
                if(!temp){
                    //create a new axis
                    temp = new edk::WindowEvents::ControllerAxis::AxisValue;
                    if(temp){
                        temp->id=axis;
                        if(!this->add(temp)){
                            delete temp;
                            return false;
                        }
                    }
                }
                if(temp){
                    //set the value
                    temp->value = value;
                    return true;
                }
                //test if have the axisID
                return false;
            }
            //remove the axis
            bool removeAxisByID(edk::uint32 axis){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getAxis(axis);
                if(temp){
                    //remove the temp
                    if(this->remove(temp)){
                        //delete the temp
                        delete temp;
                        return true;
                    }
                }
                return false;
            }
            //remove the axis
            bool removeAxisInPosition(edk::uint32 position){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getElementInPosition(position);
                if(temp){
                    //remove the temp
                    if(this->remove(temp)){
                        //delete the temp
                        delete temp;
                        return true;
                    }
                }
                return false;
            }
            //return the axis id
            edk::uint32 getAxisID(edk::uint32 position){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getElementInPosition(position);
                if(temp){
                    return temp->id;
                }
                return 0u;
            }
            edk::float32 getAxisValueByID(edk::uint32 axisID){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getAxis(axisID);
                if(temp){
                    return temp->value;
                }
                return 0.f;
            }
            edk::float32 getAxisValueInPosition(edk::uint32 position){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = this->getElementInPosition(position);
                if(temp){
                    return temp->value;
                }
                return 0.f;
            }
            //clean axis
            void cleanAxis(){
                edk::WindowEvents::ControllerAxis::AxisValue* temp = NULL;
                edk::uint32 size = this->getSize();
                for(edk::uint32 i=0u;i<size;i++){
                    temp = this->getElementInPosition(i);
                    if(temp){
                        delete temp;
                    }
                }
            }
        private:
            //get the Axis
            edk::WindowEvents::ControllerAxis::AxisValue* getAxis(edk::uint32 axis){
                edk::WindowEvents::ControllerAxis::AxisValue find;
                find.id = axis;
                return this->getElement(&find);
            }
        private:
            edk::classID classThis;
        }axisValue;
    private:
        edk::classID classThis;
    };
    class ControllerAxisEvent : private edk::WindowEvents::ControllerButtonsEvent{
    public:
        ControllerAxisEvent(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~ControllerAxisEvent(){
            this->Destructor();
        }

        void Constructor(){
            edk::WindowEvents::ControllerButtonsEvent::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::WindowEvents::ControllerButtonsEvent::Destructor();
        }

        bool cloneFrom(edk::WindowEvents::ControllerAxisEvent* event){
            if(event){
                return edk::WindowEvents::ControllerButtonsEvent::cloneFrom(event);
            }
            return false;
        }

        void clean(){
            edk::WindowEvents::ControllerButtonsEvent::clean();
        }
        edk::uint32 getControllerSize(){
            return this->buttons.size();
        }
        //return the controller ID
        edk::uint32 getControllerIDInPosition(edk::uint32 controllerPosition){
            return edk::WindowEvents::ControllerButtonsEvent::getControllerIDInPosition(controllerPosition);
        }
        //get the controller buttons size
        edk::uint32 getControllerButtonSizeByID(edk::uint32 controllerID){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtons(controllerID);
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.size();
            }
            return 0u;
        }
        //get the controller buttons size in position
        edk::uint32 getControllerButtonSizeInPosition(edk::uint32 controllerPosition){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtonsInPosition(controllerPosition);
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.size();
            }
            return 0u;
        }
        //get the controller button by ID
        edk::uint32 getControllerAxisIDByControllerID(edk::uint32 controllerID,edk::uint32 position){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtons(controllerID);
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.getAxisID(position);
            }
            return 0u;
        }//get the controller button in position
        edk::uint32 getControllerAxisIDInPosition(edk::uint32 controllerPosition,edk::uint32 position){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtonsInPosition(controllerPosition);
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.getAxisID(position);
            }
            return 0u;
        }
        //return the controller axisValue by ID
        edk::float32 getControllerAxisValueByControllerID(edk::uint32 controllerID,edk::uint32 position){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtons(controllerID);
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.getAxisValueByID(position);
            }
            return 0.f;
        }
        //return the controller axisValue in position
        edk::float32 getControllerAxisValueInPosition(edk::uint32 controllerPosition,edk::uint32 position){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtonsInPosition(controllerPosition);
            //test if dont have the button
            if(temp){
                //return the size
                return temp->axisValue.getAxisValueInPosition(position);
            }
            return 0.f;
        }

        //add a button pressed
        bool addAxis(edk::uint32 controllerID,edk::uint32 axisID,edk::float32 axisValue){
            //test if have the controller
            edk::WindowEvents::ControllerAxis* temp = (edk::WindowEvents::ControllerAxis*)this->getButtons(controllerID);
            //test if dont have the button
            if(!temp){
                //create a new button
                temp = new edk::WindowEvents::ControllerAxis;
                if(temp){
                    temp->controller = controllerID;
                    //add the button
                    if(!this->buttons.add(temp)){
                        //cant add the temp
                        delete temp;
                        return false;
                    }
                }
            }
            if(temp){
                //add the button
                temp->buttons.add(axisID);
                temp->axisValue.addAxis(axisID,axisValue);
                return true;
            }
            return false;
        }
    private:
        edk::classID classThis;
    };

public:
    //Controler
    edk::WindowEvents::ControllerButtonsEvent controllerPressed;
    edk::WindowEvents::ControllerButtonsEvent controllerHolded;
    edk::WindowEvents::ControllerButtonsEvent controllerReleased;
    edk::WindowEvents::ControllerAxisEvent controllerAxisMoved;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // WINDOWEVENTS_H
