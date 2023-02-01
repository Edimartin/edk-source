#ifndef SPOT_H
#define SPOT_H

/*
Library Spot - Control GU spot lights on the EDK Game Engine
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
#warning "Inside SUN"
#endif

#pragma once
#include "../TypeVars.h"
#include "../DebugFile.h"
#include "../GU/GU.h"
#include "Light.h"

#ifdef printMessages
#warning "    Compiling SUN"
#endif

namespace edk{
namespace light{
class Spot : public edk::light::Light{
public:
    Spot();
    ~Spot();

    //DRAW THE LIGH USING THE LIGHT NUMBER
    void draw(edk::uint32 lightNumber);
    //draw the pivo
    void drawPivo(edk::float32 size,edk::color3f32 color);

    //Set the position of the light
    void setPosition(edk::float32 x,edk::float32 y,edk::float32 z);
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec3f32 position);
    void setPosition(edk::vec2f32 position);
    void setDirection(edk::float32 x,edk::float32 y,edk::float32 z);
    void setDirection(edk::float32 x,edk::float32 y);
    void setDirection(edk::vec3f32 direction);
    void setDirection(edk::vec2f32 direction);
    //Spot Values
    void setExponent(edk::float32 exponent);
    void setCutoff(edk::float32 cutoff);
    void setConstantAttenuation(edk::float32 constantAttenuation);
    void setLinearAttenuation(edk::float32 linearAttenuation);
    void setQuadraticAttenuation(edk::float32 quadraticAttenuation);

    //get the position of the light
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    edk::float32 getPositionZ();
    edk::vec2f32 getPosition2f();
    edk::vec3f32 getPosition3f();
    edk::float32 getDirectionX();
    edk::float32 getDirectionY();
    edk::float32 getDirectionZ();
    edk::vec2f32 getDirection2f();
    edk::vec3f32 getDirection3f();

    //Spot Values
    edk::float32 getExponent();
    edk::float32 getCutoff();
    edk::float32 getConstantAttenuation();
    edk::float32 getLinearAttenuation();
    edk::float32 getQuadraticAttenuation();
};
}//end namespace light
}//end namespace edk

#endif // SPOT_H
