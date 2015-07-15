#ifndef EDK_ANIMATION_INTERPOLATIONLINE_H
#define EDK_ANIMATION_INTERPOLATIONLINE_H

/*
Library C++ InterpolationLine - Animate one line interpolation in Edk Game Engine
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
#warning "Inside InterpolationLine"
#endif

#pragma once
#include "Frame.h"
#include "../xml/XML.h"

#ifdef printMessages
#warning "    Compiling InterpolationLine"
#endif

namespace edk{
namespace animation{
class InterpolationLine{
    public:
        InterpolationLine();
        virtual ~InterpolationLine();

        //SETERS
        //set the start frame
        virtual bool setStart(edk::animation::Frame* frame);
        virtual bool setStart(edk::float32 second);
        virtual bool setStartNoFilter(edk::float32 second);
        virtual bool setEnd(edk::animation::Frame* frame);
        virtual bool setEnd(edk::float32 second);
        virtual bool setEndNoFilter(edk::float32 second);

        //GETERS
        //return the start
        edk::animation::Frame getStart();
        //return if create the start
        bool getCreateStart();
        //return the end
        edk::animation::Frame getEnd();
        //return if create the end
        bool getCreateEnd();
        //use the start frame in another interpolation
        bool useStartInStart(edk::animation::InterpolationLine* get);
        bool useStartInEnd(edk::animation::InterpolationLine* get);
        //use the start frame in another interpolation
        bool useEndInEnd(edk::animation::InterpolationLine* get);
        bool useEndInStart(edk::animation::InterpolationLine* get);
        //calculate de distance
        void updateDistance();

        //write to XML
        virtual bool writeToXMLStart(edk::XML* xml,edk::uint32 frameID);
        virtual bool writeToXMLEnd(edk::XML* xml,edk::uint32 frameID);
    protected:

    //frames of the interpolation
    edk::animation::Frame *start,*end;
    //set true if are using alloc frames/ set false if are using other frames
    bool startAlloc,endAlloc;
    //distance betwet the frames
    edk::float32 distance;

    //alloc frames
    bool allocStart();
    bool allocEnd();
    //set new
    virtual edk::animation::Frame* useNewFrame(edk::uint8 count,edk::float32 values,...);

    //delete the frames
    void deleteStart();
    void deleteEnd();
    void deleteFrames();

    //switch the frames
    void switchFrames();
    private:
};
}
}

#endif // INTERPOLATIONLINE_H
