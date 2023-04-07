#ifndef EDK_ANIMATION_INTERPOLATIONLINE1D_H
#define EDK_ANIMATION_INTERPOLATIONLINE1D_H

/*
Library C++ InterpolationLine - Animate one line interpolation with one value in Edk Game Engine
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
#pragma message "Inside InterpolationLine1D"
#endif

#pragma once
#include "InterpolationLine.h"
#include "Frame1D.h"
#include "../TypeSize2.h"
#include "../shape/Bezier2D.h"

#ifdef printMessages
#pragma message "    Compiling InterpolationLine1D"
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
