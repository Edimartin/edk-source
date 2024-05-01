#ifndef OBJECT3DVALUES_H
#define OBJECT3DVALUES_H

/*
Library Object3DValues - 3D Position angle and size
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
#pragma message "Inside Object3DValues"
#endif

#pragma once
#include "TypeDefines.h"
#include "TypeVec3.h"
#include "TypeSize3.h"
#include "DebugFile.h"

#ifdef printMessages
#pragma message "    Compiling Object3DValues"
#endif

namespace edk{
class Object3DValues{
public:
    Object3DValues();
    ~Object3DValues();

    void Constructor(bool runFather=true);
    edk::vec3f32 position;
    edk::vec3f32 angle;
    edk::size3f32 size;
    bool fixedRotation;
    void loadIdentityValues();

    //get the bodyType
    edk::TypeObject getType();
    edk::uint8 getTypeValue();
protected:
    edk::TypeObject type;

    //connected values
    edk::vec3f32 connectedPosition;
    edk::vec3f32 connectedAngle;
    edk::size3f32 connectedSize;

    void connectedLoadIdentityValues();
    void updateValuesFromConnected();
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // OBJECT3DVALUES_H
