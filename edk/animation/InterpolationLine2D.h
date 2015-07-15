#ifndef EDK_ANIMATION_INTERPOLATIONLINE2D_H
#define EDK_ANIMATION_INTERPOLATIONLINE2D_H

/*
Library C++ InterpolationLine - Animate one line interpolation with two values in Edk Game Engine
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
#warning "Inside InterpolationLine2D"
#endif

#pragma once
#include "../TypeVec2.h"
#include "InterpolationLine1D.h"
#include "Frame2D.h"

#ifdef printMessages
#warning "    Compiling InterpolationLine2D"
#endif

namespace edk{
namespace animation{
class InterpolationLine2D:public InterpolationLine1D{
    public:
        InterpolationLine2D();
        virtual ~InterpolationLine2D();

        //SETERS
        //set the start frame
        virtual bool setStart(edk::animation::Frame2D* frame);
        virtual bool setStart(edk::float32 second,edk::vec2f32 value);
        virtual bool setStart(edk::float32 second,edk::float32 x,edk::float32 y);
        virtual bool setStartValue(edk::float32 x,edk::float32 y);
        virtual bool setEnd(edk::animation::Frame2D* frame);
        virtual bool setEnd(edk::float32 second,edk::vec2f32 value);
        virtual bool setEnd(edk::float32 second,edk::float32 x,edk::float32 y);
        virtual bool setEndValue(edk::float32 x,edk::float32 y);
        //set the points in the curve
        bool setP1Y(edk::float32 second,edk::float32 y);
        bool setP2Y(edk::float32 second,edk::float32 y);


        //Set as a curve
        bool setCurveY(bool curve);
        void isCurveY();
        void isNotCurveY();
        bool getCurveY();

        //GETERS
        //return the start
        edk::animation::Frame2D getStart2D();
        //return the end
        edk::animation::Frame2D getEnd2D();

        //return the position in the second
        virtual edk::float32 getPositionY(edk::float32 second);

        //write to XML
        virtual bool writeToXMLStart(edk::XML* xml,edk::uint32 frameID);
        virtual bool writeToXMLEnd(edk::XML* xml,edk::uint32 frameID);
        //write curve
        virtual bool writeCurveToXML(edk::XML* xml,edk::uint32 curveID);
        //read the curve
        virtual bool readCurveFromXML(edk::XML* xml,edk::uint32 curveID);
    protected:
        //set new
        virtual edk::animation::Frame* useNewFrame(edk::uint8 count,edk::float32 values,...);

        //curve points
        edk::size2f32 p1Y;
        edk::size2f32 p2Y;
        bool curveY;
    private:
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATIONLINE2D_H
