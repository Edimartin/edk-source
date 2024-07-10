#ifndef GRID3D_H
#define GRID3D_H

/*
Library Grid3D - Draw a 3D Grid in EDK Game Engine
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
#pragma message "Inside Grid3D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec3.h"
#include "../TypeSize3.h"
#include "../DebugFile.h"

#include "Grid2D.h"

#ifdef printMessages
#pragma message "    Compiling Grid3D"
#endif

namespace edk{
namespace shape{
class Grid3D{
public:
    Grid3D();
    virtual ~Grid3D();

    void Constructor(bool runFather=true);

    //set the distanceLines
    bool setDistanceLines(edk::float32 distance);
    bool setDistanceLinesBold(edk::float32 distance);
    edk::float32 getDistanceLines();
    edk::float32 getDistanceLinesBold();

    //draw the grid
    void drawXY();
    void drawXZ();
    void drawYZ();
    //draw the grid in the axis
    inline void drawAxisX(){
        this->drawYZ();
    }
    inline void drawAxisY(){
        this->drawXZ();
    }
    inline void drawAxisZ(){
        this->drawXY();
    }
    inline void drawAxisXY(){
        this->drawAxisX();
        this->drawAxisY();
    }
    inline void drawAxisXZ(){
        this->drawAxisX();
        this->drawAxisZ();
    }
    inline void drawAxisYZ(){
        this->drawAxisY();
        this->drawAxisZ();
    }
    inline void drawAxisXYZ(){
        this->drawAxisX();
        this->drawAxisY();
        this->drawAxisZ();
    }

    //position of the grid
    edk::vec3f32 position;
    edk::size3f32 size;
    edk::vec3f32 angles;
    //color of the lines
    edk::color4f32 colorLines;
    edk::color4f32 colorLinesBold;
private:
    //set lines distance
    edk::float32 distanceLines;
    edk::float32 distanceLinesBold;
    //private attributes to use in the render function
    edk::float32 limit;
    edk::float32 p1,p2;
    edk::float32 i;
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // GRID3D_H
