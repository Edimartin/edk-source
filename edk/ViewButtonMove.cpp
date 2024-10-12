#include "ViewButtonMove.h"

/*
Library C++ ViewButtonMove - Move the button automaticaly
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

edk::ViewButtonMove::ViewButtonMove(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::ViewButtonMove::~ViewButtonMove(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::ViewButtonMove::Constructor(bool runFather){
    if(runFather){
        edk::ViewButton::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
        this->saveFirst = false;edkEnd();
        this->holdedMouse = false;edkEnd();
    }
}

void edk::ViewButtonMove::updateView(edk::WindowEvents* events){
    //test if is holding the mouse
    if(this->holdedMouse){
        //load the new position
        edk::vec2f32 newPosition = edk::vec2f32((edk::float32)events->mousePos.x,(edk::float32)events->mousePos.y);edkEnd();
        //save the first position
        if(!this->saveFirst){
            this->saveMousePos = newPosition;edkEnd();
            this->saveFirst=true;edkEnd();
        }
        //calculate the distance
        edk::vec2f32 distance = newPosition - this->saveMousePos;edkEnd();
        this->setPosition(distance + this->savePosition);edkEnd();
    }
    else{
        this->saveFirst=false;edkEnd();
    }

    //update the view
    edk::View::updateView(events);edkEnd();
}
//Function to set button position
void edk::ViewButtonMove::setPosition(edk::vec2f32 position){
    this->frame.origin = position;edkEnd();
}

//mouse events
void edk::ViewButtonMove::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    edk::ViewButton::eventMousePressed(point,button);edkEnd();

    //test the left buttons
    if(button == edk::mouse::left){
        //hold the mouse
        this->holdedMouse=true;edkEnd();
        //save the position
        this->savePosition = this->frame.origin;edkEnd();
    }
}
void edk::ViewButtonMove::eventMouseMoved(edk::vec2f32 point,edk::vec2f32 moved,edk::uint32 button){
    edk::ViewButton::eventMouseMoved(point,moved,button);edkEnd();
}
void edk::ViewButtonMove::eventMouseReleased(edk::vec2f32 position,edk::uint32 button){
    edk::ViewButton::eventMouseReleased(position,button);edkEnd();

    //test the left buttons
    if(button == edk::mouse::left){
        //remove hold the mouse
        this->holdedMouse=false;edkEnd();
    }
}
void edk::ViewButtonMove::eventMouseDoubleClicked(edk::vec2f32 point,edk::uint32 button){
    edk::ViewButton::eventMouseDoubleClicked(point,button);edkEnd();
}
