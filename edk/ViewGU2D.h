#ifndef EDK_VIEWGU2D_H
#define EDK_VIEWGU2D_H

/*
Library C++ viewGU2D - Render GU elements, and a 2D camera, inside this view in Edk Game Engine
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
#pragma message "Inside ViewGU2D"
#endif

#pragma once
#include "ViewGU.h"
#include "Camera2D.h"

#ifdef printMessages
#pragma message "    Compiling ViewGU2D"
#endif

namespace edk{
class ViewGU2D: public edk::ViewGU{
public:
    ViewGU2D();
    virtual ~ViewGU2D();

    void Constructor();
    void Destructor();

    virtual void updateAnimations();
    virtual void updateAnimations(edk::float32 seconds);

    //draw the GU scene
    virtual void drawScene(edk::rectf32 outsideViewOrigin);

    //the edkGU 2D camera
    edk::Camera2D camera;
protected:
    //draw the polygon on the scene
    void drawPolygon(edk::rectf32 outsideViewOrigin);
    //change point position beetween screen and world
    inline edk::vec2f32 convertPositionScreenToWorld(edk::vec2f32 position){
        return this->positionScreenToWorld(position);
    }
    edk::vec2f32 positionScreenToWorld(edk::vec2f32 position);
    inline edk::vec2f32 convertPositionScreenToWorld(edk::float32 x,edk::float32 y){
        return this->positionScreenToWorld(x,y);
    }
    edk::vec2f32 positionScreenToWorld(edk::float32 x,edk::float32 y);
    inline edk::vec2f32 convertPositionWorldToScreen(edk::vec2f32 position){
        return positionWorldToScreen(position);
    }
    edk::vec2f32 positionWorldToScreen(edk::vec2f32 position);
    inline edk::vec2f32 convertPositionWorldToScreen(edk::float32 x,edk::float32 y){
        return positionWorldToScreen(x,y);
    }
    edk::vec2f32 positionWorldToScreen(edk::float32 x,edk::float32 y);
private:
    //draw the 2Dcamera
    void drawCamera2D();
    //draw selection camera
    void drawSelectionCamera();
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // VIEWGU_H

/* EXAMPLE
class example: edk::ViewGU2D{
    //construtor
    example();
    //destrutor
    virtual ~example();

    //Load and Unload
    void load(edk::rectf32 outsideViewOrigin);
    void unload();

    //Mouse Events
    void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
    void eventMouseMoved(edk::vec2f32 point,edk::vec2f32 moved,edk::uint32 button);
    void eventMouseReleased(edk::vec2f32 point,edk::uint32 button);
    void eventMouseDoubleClicked(edk::vec2f32 point,edk::uint32 button);
    //Mouse go Inside Outside
    void eventMouseEntryInsideView(edk::vec2f32 point);
    void eventMouseLeftView(edk::vec2f32 point);

    //Update the scene
    void update(edk::WindowEvents* events);

    //draw the GU scene
    void drawScene(edk::rectf32 outsideViewOrigin);
};
*/
