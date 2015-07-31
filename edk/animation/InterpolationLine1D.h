#ifndef EDK_ANIMATION_INTERPOLATIONLINE1D_H
#define EDK_ANIMATION_INTERPOLATIONLINE1D_H

/*
Library C++ InterpolationLine - Animate one line interpolation with one value in Edk Game Engine
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
#warning "Inside InterpolationLine1D"
#endif

#pragma once
#include "InterpolationLine.h"
#include "Frame1D.h"
#include "../TypeSize2.h"
#include "../shape/Bezier2D.h"

#ifdef printMessages
#warning "    Compiling InterpolationLine1D"
#endif

namespace edk{
namespace animation{
class InterpolationLine1D:public InterpolationLine{
    public:
        InterpolationLine1D();
        virtual ~InterpolationLine1D();

        //SETERS
        //set the start frame
        virtual bool setStart(edk::animation::Frame1D* frame);
        virtual bool setStart(edk::float32 second,edk::float32 x);
        virtual bool setStartValue(edk::float32 x);
        virtual bool setEnd(edk::animation::Frame1D* frame);
        virtual bool setEnd(edk::float32 second,edk::float32 x);
        virtual bool setEndValue(edk::float32 x);
        //set the points in the curve
        bool setP1X(edk::float32 second,edk::float32 x);
        bool setP2X(edk::float32 second,edk::float32 x);


        //Set as a curve
        bool setCurveX(bool curve);
        void isCurveX();
        void isNotCurveX();
        bool getCurveX();
        //set as constant interpolation
        void setConstantX();
        void setLinearX();

        //GETERS
        //return the start
        edk::animation::Frame1D getStart1D();
        //return the end
        edk::animation::Frame1D getEnd1D();

        //return the position in the second
        virtual edk::float32 getPositionX(edk::float32 second);
        virtual bool haveX(edk::float32 positionX);
        virtual bool haveSecond(edk::float32 second);
        virtual edk::float32 getSecond(edk::float32 positionX);

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
        edk::size2f32 p1X;
        edk::size2f32 p2X;
        bool curveX;
        bool constantX;
    private:
};
}//end namespace animation
}//edn namespace edk

#endif // InterpolationLine1D_H
