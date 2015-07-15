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

#ifdef printMessages
#warning "    Compiling ViewGU"
#endif

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

        virtual void update(edk::WindowEvents* events);

        //draw the GU scene
        virtual void drawScene(rectf32 outsideViewOrigin);

        //return true if is a GU View
        bool isGU();
    protected:
    //Draw Functions
    //draw viewPort
    void drawViewport(rectf32 outsideViewOrigin);
    //draw Camera
    void drawCamera();
    //draw the polygon on the scene
    virtual void drawPolygon(rectf32 outsideViewOrigin);
    private:
};
}//end namespace

#endif // VIEWGU_H
