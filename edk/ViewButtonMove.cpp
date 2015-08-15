#include "ViewButtonMove.h"

edk::ViewButtonMove::ViewButtonMove()
{
    this->saveFirst = false;
    this->holdedMouse = false;
}
edk::ViewButtonMove::~ViewButtonMove()
{
}

void edk::ViewButtonMove::updateView(edk::WindowEvents* events){
    //test if is holding the mouse
    if(this->holdedMouse){
        //load the new position
        edk::vec2f32 newPosition = edk::vec2f32((edk::float32)events->mousePos.x,(edk::float32)events->mousePos.y);
        //save the first position
        if(!this->saveFirst){
            this->saveMousePos = newPosition;
            this->saveFirst=true;
        }
        //calculate the distance
        edk::vec2f32 distance = newPosition - this->saveMousePos;
        this->setPosition(distance + this->savePosition);
    }
    else{
        this->saveFirst=false;
    }

    //update the view
    edk::View::updateView(events);
}
//Function to set button position
void edk::ViewButtonMove::setPosition(edk::vec2f32 position){
    this->frame.origin = position;
}

//mouse events
void edk::ViewButtonMove::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    edk::ViewButton::eventMousePressed(point,button);

    //test the left buttons
    if(button == edk::mouse::left){
        //hold the mouse
        this->holdedMouse=true;
        //save the position
        this->savePosition = this->frame.origin;
    }
}
void edk::ViewButtonMove::eventMouseMoved(edk::vec2f32 point,edk::uint32 button){
    edk::ViewButton::eventMouseMoved(point,button);
}
void edk::ViewButtonMove::eventMouseReleased(edk::vec2f32 position,edk::uint32 button){
    edk::ViewButton::eventMouseReleased(position,button);

    //test the left buttons
    if(button == edk::mouse::left){
        //remove hold the mouse
        this->holdedMouse=false;
    }
}
