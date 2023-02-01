#ifndef POINT_H
#define POINT_H

/*
Library Point - Control GU point lights on the EDK Game Engine
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
#warning "Inside Point"
#endif

#pragma once
#include "../TypeVars.h"
#include "../DebugFile.h"
#include "../GU/GU.h"
#include "Light.h"

#ifdef printMessages
#warning "    Compiling Point"
#endif

namespace edk{
namespace light{
class Point: public edk::light::Light{
public:
    Point();
    ~Point();
    //DRAW THE LIGH USING THE LIGHT NUMBER
    virtual void draw(edk::uint32 lightNumber);

    //Set the position of the light
    void setPosition(edk::float32 x,edk::float32 y,edk::float32 z);
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec3f32 position);
    void setPosition(edk::vec2f32 position);

    //get the position of the light
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    edk::float32 getPositionZ();
    edk::vec2f32 getPosition2f();
    edk::vec3f32 getPosition3f();
};
}//end namespace light
}//end namespace edk

#endif // POINT_H
