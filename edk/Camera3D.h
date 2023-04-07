#ifndef CAMERA3D_H
#define CAMERA3D_H

/*
Library Camera3D - 3D camera in a 3D World
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
#pragma message "Inside Camera3D"
#endif

#pragma once
#include "Math.h"
#include "GU/GU.h"
#include <stdio.h>
#include "Object.h"
#include "TypeVec3.h"
#include "TypeRect.h"
#include "animation/Interpolation3DGroup.h"

#ifdef printMessages
#pragma message "    Compiling Camera3D"
#endif

namespace edk{
class Camera3D{
public:
    Camera3D();
    Camera3D(edk::vec3f32 position,edk::vec3f32 lookAt);
    Camera3D(edk::float32 pX,edk::float32 pY,edk::float32 pZ,edk::float32 lookX,edk::float32 lookY,edk::float32 lookZ);
    virtual ~Camera3D();
    edk::vec3f32 position;
    edk::vec3f32 lookAt;

    //Sset witch camera type its using
    void usePerspective();
    void useOrtho();

    //set the size
    void setSize(edk::size2f32 size);
    void setSize(edk::float32 sizeW,edk::float32 sizeH);
    void setSizeW(edk::float32 width);
    void setSizeH(edk::float32 height);
    //return the size
    edk::float32 getWidth();
    edk::float32 getHeight();

    //set near and far
    void setNearFar(edk::float32 near,edk::float32 far);
    void setFar(edk::float32 far);
    //Get near and far
    edk::float32 getNear();
    edk::float32 getFar();

    //Distance
    edk::float32 getDistance();
    //set the distance
    bool setDistance(edk::float32 distance);
    //move the distance
    bool moveDistance(edk::float32 distance);

    //functions to move the camera in his axis
    void moveHorizontal(edk::float32 distance);
    void moveVertical(edk::float32 distance);

    //return the angle width and height
    edk::float32 getAngleX();
    edk::float32 getAngleY();
    edk::float32 getAngleUp();
    //set the angles
    void setAngleX(edk::float32 angle);
    void setAngleY(edk::float32 angle);
    void setAngleUp(edk::float32 angle);
    //move the angles
    void rotateAngleX(edk::float32 angle);
    void rotateAngleY(edk::float32 angle);
    void rotateAngleUp(edk::float32 angle);

    //draw the camera
    void draw();
    void drawAxisOnly();
    void drawAxisOnly(edk::float32 seconds);

    //operator to copy the cameras
    bool cloneFrom(edk::Camera3D* cam);
private:
    edk::Camera3D operator=(edk::Camera3D){return *this;}
    bool perspective;
    edk::vec2f32 up;
    edk::size2f32 size;
    edk::float32 sizePercent;
    edk::float32 _near;
    edk::float32 _far;
    bool firstPerson;
    void start();
};
}//end namespace edk

#endif // CAMERA3D_H
