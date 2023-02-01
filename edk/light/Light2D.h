#ifndef EDK_LIGHT_LIGHT2D_H
#define EDK_LIGHT_LIGHT2D_H

/*
Library Light2D - Control GU lights on the EDK Game Engine
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
#warning "Inside Light2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../DebugFile.h"
#include "../GU/GU.h"
#include "Light.h"

#ifdef printMessages
#warning "    Compiling Light2D"
#endif

namespace edk{
namespace light{
class Light2D : public edk::light::Light{
public:
    Light2D();

    //Set the 2D Values
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec2f32 position);
    void setZ(edk::float32 z);
    void setDirection(edk::float32 x,edk::float32 y);
    void setDirection(edk::vec2f32 direction);

    //get Position
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    edk::vec2f32 getPosition2f();
    edk::float32 getDirectionX();
    edk::float32 getDirectionY();
    edk::vec2f32 getDirection2f();
};
}//end namespace light
}//end namespace edk

#endif // LIGHT2D_H

/*
GU_SPOT_DIRECTION (0.0, 0.0, -1.0) (x, y, z) direction of spotlight

GU_SPOT_EXPONENT 0.0 spotlight exponent

GU_SPOT_CUTOFF 180.0 spotlight cutoff angle

GU_CONSTANT_ATTENUATION 1.0 constant attenuation factor

GU_LINEAR_ATTENUATION 0.0 linear attenuation factor

GU_QUADRATIC_ATTENUATION 0.0 quadratic attenuation factor
*/
