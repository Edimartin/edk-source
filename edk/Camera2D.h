#ifndef EDK_CAMERA2D_H
#define EDK_CAMERA2D_H

/*
Library Camera2D - 2D camera in a 2D World
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
#pragma message "Inside Camera2D"
#endif

#pragma once
#include "Math.h"
#include "GU/GU.h"
#include <stdio.h>
#include "Object.h"
#include "TypeVec2.h"
#include "TypeRect.h"
#include "animation/Interpolation2DGroup.h"

#ifdef printMessages
#pragma message "    Compiling Camera2D"
#endif


namespace edk{
class Camera2D{
    public:
        Camera2D();
        Camera2D(edk::vec2f32 position);
        Camera2D(edk::float32 posX,edk::float32 posY);
        virtual ~Camera2D();

        //Position of the camera 2D
        edk::vec2f32 position;

        //SETTERS
        //set the size
        void setSize(edk::size2f32 size);
        void setSize(edk::float32 sizeW,edk::float32 sizeH);
        void setSizeW(edk::float32 width);
        void setSizeH(edk::float32 height);
        //Set a rectangle to the camera
        bool setRect(edk::rectf32 rect);
        bool setRect(edk::vec2f32 origin,size2f32 size);
        bool setRect(edk::float32 originX,edk::float32 originY,edk::float32 width,edk::float32 height);
        //Set the points of the camera in the world
        bool setPoints(edk::vec2f32 p1, edk::vec2f32 p2);
        bool setPoints(edk::float32 p1X,edk::float32 p1Y,edk::float32 p2X,edk::float32 p2Y);
        //save the position in the save buffer to calculate the distance
        void savePosition();
        void pastePosition();

        //GETTERS
        //get the size
        edk::size2f32 getSize();
        //return the camera rect
        edk::rectf32 getRect();

        //get the distance beetween the position and save distance
        edk::float32 getDistanceFromSave();
        //get the camera translate from saveDistance
        edk::vec2f32 getTranslateFromSave();

        //draw the camera
        void draw();
        void drawOrthoOnly();
        void drawOrthoOnly(edk::float32 seconds);

        //move the camera
        void moveLeft(edk::float32 dist);
        void moveLeft(edk::float64 dist);
        void moveRight(edk::float32 dist);
        void moveRight(edk::float64 dist);
        void moveUp(edk::float32 dist);
        void moveUp(edk::float64 dist);
        void moveDown(edk::float32 dist);
        void moveDown(edk::float64 dist);
        void move(edk::vec2f32 position);
        void move(edk::float32 x,edk::float32 y);

        void scaleX(edk::float32 dist);
        void scaleX(edk::float64 dist);
        void scaleY(edk::float32 dist);
        void scaleY(edk::float64 dist);

        //set camera angle
        void setAngle(edk::float32 angle);
        //rotate the camera
        void rotateCamera(edk::float32 angle);
        //get the camera angle
        edk::float32 getAngle();

        void updateAnimations();

        //start the animation
        bool addShakingAngle(edk::float32 position,edk::float32 percent = 0.9f,edk::float32 interpolationDistance=0.1f);
        bool addShakingPosition(edk::vec2f32 position,edk::float32 random,edk::float32 percent = 0.9f,edk::float32 interpolationDistance=0.05f);

        //operator to copy the cameras
        bool cloneFrom(edk::Camera2D* cam);
        //animated position
        edk::animation::Interpolation2DGroup animPosition;
        //animated angle
        edk::animation::Interpolation1DGroup animAngle;
    protected:
    private:
        edk::Camera2D operator=(edk::Camera2D){return *this;}
        //size of the camera screen
        edk::size2f32 size;
        edk::vec2f32 up;
        edk::vec2f32 tempPosition;
        edk::float32 angle;

        //save the camera positon to calculate the distance
        edk::vec2f32 positionSave;

        //animated position
        edk::animation::Interpolation2DGroup animShakingPosition;
        //animated angle
        edk::animation::Interpolation1DGroup animShakingAngle;
    void start();
};
}//end namespace edk

#endif // CAMERA2D_H
