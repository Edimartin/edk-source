#ifndef PATH3DGROUP_H
#define PATH3DGROUP_H

/*
Biblioteca C++ Path3DGroup - Manage one or more physics animation frames3D in Edk Game Engine
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
#warning "Inside Path3DGroup"
#endif

#pragma once
#include "Path2DGroup.h"
#include "Frame3D.h"

#ifdef printMessages
#warning "    Compiling Path3DGroup"
#endif

namespace edk{
namespace animation{
class Path3DGroup : public edk::animation::Path2DGroup{
public:
    Path3DGroup();

    //add a new frame
    bool addNewFrame(edk::float32 seconds,edk::float32 x,edk::float32 y,edk::float32 z);
    //add a new frame to the position
    bool addNewFrameToPosition(edk::uint32 position,edk::float32 seconds,edk::float32 x,edk::float32 y,edk::float32 z);

    //set the Z
    void setZ(edk::float32 z);
    //get the Z
    edk::float32 getZ();

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
    edk::float32 z;
};
}
}

#endif // PATH3DGROUP_H
