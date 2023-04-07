#ifndef EDK_OBJECT2DVALUES_H
#define EDK_OBJECT2DVALUES_H

/*
Library Object2DValues - 2D Position angle and size
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
#pragma message "Inside Object2DValues"
#endif

#pragma once
#include "TypeVec2.h"
#include "TypeSize2.h"
#include "TypeColor.h"
#include "animation/Interpolation2DGroup.h"
#include "animation/Interpolation2DTracks.h"

#ifdef printMessages
#pragma message "    Compiling Object2DValues"
#endif

namespace edk{
class Object2DValues{
public:
    Object2DValues();
    edk::vec2f32 position;
    edk::float32 angle;
    edk::size2f32 size;
    bool fixedRotation;
    //animarion position
    edk::animation::Interpolation2DTracks animationPosition;
    //Animation rotation
    edk::animation::Interpolation1DGroup animationRotation;
    //animationSize
    edk::animation::Interpolation2DGroup animationSize;
    //pivo point
    edk::vec2f32 pivo;
    void loadIdentityValues();
    //operators
    // =
    edk::Object2DValues operator=(edk::Object2DValues values){
        this->position = values.position;edkEnd();
        this->angle = values.angle;edkEnd();
        this->size = values.size;edkEnd();
        return *this;edkEnd();
    }

    // ==
    bool operator==(edk::Object2DValues values){
        return (this->position==values.position && this->angle==values.angle && this->size == values.size);edkEnd();
    }
    // !=
    bool operator!=(edk::Object2DValues values){
        return (this->position!=values.position || this->angle!=values.angle || this->size != values.size);edkEnd();
    }
    //draw the pivo
    virtual void drawPivo(edk::float32 size,edk::color3f32 color);
    //update all animations
    virtual bool updateAnimations();
    virtual bool updateAnimations(edk::float32 seconds);
    //draw
    virtual void draw();
};
}

#endif // OBJECT2DVALUES_H
