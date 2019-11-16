#ifndef EDK_ANIMATION_PATH2DGROUP_H
#define EDK_ANIMATION_PATH2DGROUP_H

/*
Biblioteca C++ Path2DGroup - Manage one or more physics animation frames2D in Edk Game Engine
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
#warning "Inside Path2DGroup"
#endif

#pragma once
#include "Path1DGroup.h"
#include "Frame2D.h"

#ifdef printMessages
#warning "    Compiling Path2DGroup"
#endif

namespace edk{
namespace animation{
class Path2DGroup : public edk::animation::Path1DGroup{
public:
    Path2DGroup();

    //add a new frame
    bool addNewFrame(edk::float32 seconds,edk::float32 x,edk::float32 y);
    //add a new frame to the position
    bool addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x,edk::float32 y);

    //set the Y
    void setY(edk::float32 y);
    //get the Y
    edk::float32 getY();

    //update the clock animation
    virtual edk::float32 updateClockAnimation();
    virtual edk::float32 updateClockAnimation(edk::float32 distance);

    //write to XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    //read XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
protected:
    //create the frame
    virtual edk::animation::Frame* newFrame();
    //return true if the value reach the frame position
    virtual bool reachFrame(edk::animation::Frame* frame);
private:
    //the x value
    edk::float32 y;
};
}
}

#endif // PATH2DGROUP_H
