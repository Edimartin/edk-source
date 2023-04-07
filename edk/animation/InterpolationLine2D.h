#ifndef EDK_ANIMATION_INTERPOLATIONLINE2D_H
#define EDK_ANIMATION_INTERPOLATIONLINE2D_H

/*
Library C++ InterpolationLine - Animate one line interpolation with two values in Edk Game Engine
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
#pragma message "Inside InterpolationLine2D"
#endif

#pragma once
#include "../TypeVec2.h"
#include "InterpolationLine1D.h"
#include "Frame2D.h"

#ifdef printMessages
#pragma message "    Compiling InterpolationLine2D"
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
        //set as constant interpolation
        void setConstantY();
        void setLinearY();

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
        bool constantY;
    private:
};
}//end namespace animation
}//end namespace edk

#endif // INTERPOLATIONLINE2D_H
