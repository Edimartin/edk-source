#ifndef EDK_VIEWGU_H
#define EDK_VIEWGU_H

/*
Library C++ viewGU - Render GU elements inside this view in Edk Game Engine
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
#warning "Inside ViewGU"
#endif

#pragma once
#include "ViewSpriteController.h"
#include "WindowEvents.h"
#include "GU/GU.h"

#ifdef printMessages
#warning "    Compiling ViewGU"
#endif

/*
void load(edk::rectf32 outsideViewOrigin){
    //
}
void unload(){
    //
}
void update(edk::WindowEvents* events){
    //
}
void drawScene(edk::rectf32 outsideViewOrigin){
    //
}
*/

namespace edk{
class ViewGU: public edk::ViewSpriteController{
    public:
        ViewGU();
        virtual ~ViewGU();

        //load the background
        bool loadBackground(const char* name);
        bool loadBackground(edk::char8* name);

        //delete the background
        void deleteBackground();

        //test the selection
        void testSelection(edk::vec2f32 position,edk::size2f32 size = edk::size2f32(1,1));
        void testSelection(edk::vec2i32 position,edk::size2f32 size = edk::size2f32(1,1));

        virtual void update(edk::WindowEvents* events);

        //draw the GU scene
        virtual void drawScene(edk::rectf32 outsideViewOrigin);

        virtual void drawSelectionScene();

        //return true if is a GU View
        bool isGU();
    protected:
    //Draw Functions
    //draw viewPort
    void drawViewport(edk::rectf32 outsideViewOrigin);
    //draw Camera
    void drawCamera();
    //draw the polygon on the scene
    virtual void drawPolygon(edk::rectf32 outsideViewOrigin);
    //draw selection camera
    virtual void drawSelectionCamera();
    //push and pop the selection names
    void selectionPushName(edk::uint32 id);
    void selectionPopName();
    //process the selection
    virtual void processHits(edk::uint32 hits, edk::uint32 buffer[]);
    //process the selection
    virtual void selectObject(edk::uint32 position,edk::uint32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);
    //run selection function
    void runSelectionFunction();
    //get true if go run selection
    bool isRunningSelection();
    private:
    //save selection position
    edk::vec2f32 selectionPosition;
    edk::size2f32 selectionSize;
    bool runSelection;
};
}//end namespace

#endif // VIEWGU_H
