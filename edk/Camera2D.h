#ifndef EDK_CAMERA2D_H
#define EDK_CAMERA2D_H

/*
Library Camera2D - 2D camera in a 2D World
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "Inside Camera2D"
#endif

#pragma once
#include "GU/GU.h"
#include <stdio.h>
#include "Object.h"
#include "TypeVec2.h"
#include "TypeRect.h"

#ifdef printMessages
#warning "    Compiling Camera2D"
#endif


namespace edk{
class Camera2D/* : public edk::Object<edk::Camera2D>*/{
    public:
        Camera2D();
        Camera2D(edk::vec2f32 position);
        Camera2D(edk::float32 posX,edk::float32 posY);
        virtual ~Camera2D();

        //Position of the camera 2D
        edk::vec2f32 position;

        //SETTERS
        //set the size
        bool setSize(edk::size2f32 size);
        bool setSize(edk::float32 sizeX,edk::float32 sizeY);
        //Set a rectangle to the camera
        bool setRect(edk::rectf32 rect);
        bool setRect(edk::vec2f32 origin,size2f32 size);
        bool setRect(edk::float32 originX,edk::float32 originY,edk::float32 width,edk::float32 height);
        //Set the points of the camera in the world
        bool setPoints(edk::vec2f32 p1, edk::vec2f32 p2);
        bool setPoints(edk::float32 p1X,edk::float32 p1Y,edk::float32 p2X,edk::float32 p2Y);
        //GETTERS
        //get the size
        edk::size2f32 getSize();
        //return the camera rect
        edk::rectf32 getRect();

        //draw the camera
        void draw();

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

        //operator to copy the cameras
        edk::Camera2D operator=(edk::Camera2D newCam){this->size = newCam.size;return newCam;}
    protected:
    private:
        //size of the camera screen
        edk::size2f32 size;
    void start();
};
}//end namespace edk

#endif // CAMERA2D_H