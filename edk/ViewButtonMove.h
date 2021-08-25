#ifndef VIEWBUTTONMOVE_H
#define VIEWBUTTONMOVE_H

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

#ifdef printMessages
#warning "Inside ViewButtonMove"
#endif

#pragma once
#include "ViewButton.h"

#ifdef printMessages
#warning "    Compiling ViewButtonMove"
#endif

namespace edk{
class ViewButtonMove : public edk::ViewButton{
public:
    ViewButtonMove();
    ~ViewButtonMove();

    virtual void updateView(edk::WindowEvents* events);
    //Function to set button position
    virtual void setPosition(edk::vec2f32 position);
protected:
    //save mouse position
    edk::vec2f32 saveMousePos;
    //save the button position
    edk::vec2f32 savePosition;
    //set holded
    bool holdedMouse;
    //set if save the first position
    bool saveFirst;
private:
    //mouse events
    void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
    void eventMouseMoved(edk::vec2f32 point,edk::uint32 button);
    void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);
};
}//end namespace edk

#endif // VIEWBUTTONMOVE_H
