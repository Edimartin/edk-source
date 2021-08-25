#ifndef EDK_ANIMATION_INTERPOLATIONLINE_H
#define EDK_ANIMATION_INTERPOLATIONLINE_H

/*
Library C++ InterpolationLine - Animate one line interpolation in Edk Game Engine
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
