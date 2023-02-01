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
#warning "Inside WindowEvents"
#endif

//EDK
#include "TypeVars.h"
#include "DebugFile.h"
#include "TypeVec2.h"
#include "TypeSize2.h"
#include "TypeDefines.h"
#include "vector/Stack.h"
#include "watch/Time.h"

#ifdef printMessages
#warning "    Compiling WindowEvents"
#endif

//WindowEvents structure

/*LIBS

-lsfml-window

*/

namespace edk{
class Window;
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
    }
    virtual ~WindowEvents(){
        //
    }

    //friendClass
    friend edk::Window;

    //clean the events
    void clean(){
        //
        this->buttonExit = this->lostFocus = this->gainedFocus = this->resize = this->mouseMoved = mouseEnter = mouseExit = false;edkEnd();
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
            this->timeMouseDoubleLimit = seconds;
            return true;
        }
        this->timeMouseDoubleLimit = EDK_TIME_LIMIT_DOUBLE_CLICK;
        return false;
    }
    edk::float32 getMouseDoubleClickLimit(){
        return this->timeMouseDoubleLimit;
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
