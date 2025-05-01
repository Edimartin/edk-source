#ifndef EDK_SHAPE_LINE3D_H
#define EDK_SHAPE_LINE3D_H

/*
Library Line3D - Draw a 3D line in EDK Game Engine
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
#pragma message "Inside Line3D"
#endif

//Include the polygon
#pragma once
#include "../TypeVec3.h"
#include "Vertex3D.h"

#ifdef printMessages
#pragma message "    Compiling Line3D"
#endif

namespace edk{
namespace shape{
class Line3D{
public:
    Line3D();
    Line3D(edk::vec3f32 start,edk::vec3f32 end);
    virtual ~Line3D();

    void Constructor();
    void Constructor(edk::vec3f32 start,edk::vec3f32 end);
    void Destructor();
    //line Vectex's
    edk::shape::Vertex3D start,end;

    //set the points
    void setStart(edk::vec3f32 point);
    void setEnd(edk::vec3f32 point);

    //set points
    void setPoints(edk::vec3f32 start,edk::vec3f32 end);

    //return the point
    virtual edk::vec3f32 getPoint(edk::float32 percent);

    //print the line
    void print();
    //Draw the line
    void draw();

    edk::shape::Line3D operator=(edk::shape::Line3D line){
        this->start = line.start;
        this->end = line.end;
        return line;
    }
    edk::shape::Line3D operator=(edk::shape::Line3D* line){
        if(line){
            this->start = line->start;
            this->end = line->end;
        }
        return *line;
    }
protected:
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // LINE3D_H
