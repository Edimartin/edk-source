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
#include "TypeColor.h"
#include "animation/Interpolation3DGroup.h"
#include "animation/Interpolation3DTracks.h"
#include "DebugFile.h"

#ifdef printMessages
#pragma message "    Compiling Object3DValues"
#endif

namespace edk{
class Object3DValues{
public:
    Object3DValues();
    virtual ~Object3DValues();

    void Constructor();
    void Destructor();

    //print the values
    virtual void print();

    edk::vec3f32 position;
    edk::vec3f32 angle;
    edk::size3f32 size;
    bool fixedRotation;
    //animarion position
    edk::animation::Interpolation3DTracks animationPosition;
    //Animation rotation
    edk::animation::Interpolation1DGroup animationRotation;
    //animationSize
    edk::animation::Interpolation3DGroup animationSize;
    //pivo point
    edk::vec3f32 pivo;
    void loadIdentityValues();
    //operators
    // =
    edk::Object3DValues operator=(edk::Object3DValues values){
        this->position = values.position;
        this->angle = values.angle;
        this->size = values.size;
        return *this;
    }

    // ==
    inline bool operator==(edk::Object3DValues values){
        return (this->position==values.position && this->angle==values.angle && this->size == values.size);
    }
    // !=
    inline bool operator!=(edk::Object3DValues values){
        return (this->position!=values.position || this->angle!=values.angle || this->size != values.size);
    }
    //clone from
    bool cloneValuesFrom(edk::Object3DValues* values){
        if(values){
            this->position = values->position;
            this->angle = values->angle;
            this->size = values->size;
            return true;
        }
        return false;
    }
    //draw the pivo
    virtual void drawPivo(edk::float32 size,edk::color3f32 color);
    virtual void drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    //update all animations
    virtual bool updateAnimations();
    virtual bool updateAnimations(edk::float32 seconds);
    //draw
    virtual void draw();

    //get the bodyType
    edk::TypeObject getType();
    edk::uint8 getTypeValue();
protected:
    edk::TypeObject type;

    //connected translations
    edk::vec3f32 connectedPosition;
    edk::size3f32 connectedSize;
    edk::vec3f32 connectedAngle;
    edk::vec3f32 connectedPivo;

    void connectedLoadIdentityValues();
    void updateValuesFromConnected();
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // OBJECT3DVALUES_H
