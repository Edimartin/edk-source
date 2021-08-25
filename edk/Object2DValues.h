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
#warning "Inside Object2DValues"
#endif

#pragma once
#include "TypeVec2.h"
#include "TypeSize2.h"

#ifdef printMessages
#warning "    Compiling Object2DValues"
#endif

namespace edk{
class Object2DValues{
public:
    Object2DValues();
    edk::vec2f32 position;
    edk::float32 angle;
    edk::size2f32 size;
    bool fixedRotation;
    void loadIdentityValues();
/*
    //save the values
    void saveValues();
    //clean the saved values
    void cleanSaved();
    //return the saved values
    edk::vec2f32 getSavedPosition();
    edk::float32 getSavedPositionX();
    edk::float32 getSavedPositionY();
    //return the saved size
    edk::size2f32 getSavedSize();
    edk::float32 getSavedSizeWidth();
    edk::float32 getSavedSizeHeight();
    //return the savedAngle
    edk::float32 getSavedAngle();
private:
    //save the atual values
    edk::vec2f32 savePosition;
    edk::float32 saveAngle;
    edk::size2f32 saveSize;
*/
};
}

#endif // OBJECT2DVALUES_H
