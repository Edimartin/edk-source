#ifndef VORONOI_H
#define VORONOI_H

/*
Library C++ Voronoi - Voronoi generator to be used in EDK.
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
#warning "Inside Action"
#endif

#ifdef printMessages
#warning "    Compiling Action"
#endif

#pragma once
#include "Math.h"
#include "Random.h"
#include "Image2D.h"
#include "vector/Array.h"
#include "thread/Thread.h"

namespace edk{
//class with position and color
class vec2f32ColorRGB{
public:
    vec2f32ColorRGB(){
        this->position.x = this->position.y = 0.f;
        this->color.r = this->color.g = this->color.b = 0u;
    }
    vec2f32ColorRGB(edk::vec2f32 position,edk::color3ui8 color){
        this->position = position;
        this->color = color;
    }
    vec2f32ColorRGB(edk::float32 x,edk::float32 y,edk::uint8 r,edk::uint8 g,edk::uint8 b){
        this->position.x = x;
        this->position.y = y;
        this->color.r = r;
        this->color.g = g;
        this->color.b = b;
    }
    virtual ~vec2f32ColorRGB(){}
    //operator =
    edk::vec2f32ColorRGB operator=(edk::vec2f32ColorRGB vecColor){
        this->position.x= vecColor.position.x;
        this->position.y= vecColor.position.y;
        this->color.r = vecColor.color.r;
        this->color.g = vecColor.color.g;
        this->color.b = vecColor.color.b;
        return *this;
    }
    edk::vec2f32 position;
    edk::color3ui8 color;
};
class vec2f32ColorGray{
public:
    vec2f32ColorGray(){
        this->position.x = this->position.y = 0.f;
        this->grayscale = 0u;
    }
    vec2f32ColorGray(edk::vec2f32 position,edk::uint8 grayscale){
        this->position = position;
        this->grayscale = grayscale;
    }
    vec2f32ColorGray(edk::float32 x,edk::float32 y,edk::uint8 grayscale){
        this->position.x = x;
        this->position.y = y;
        this->grayscale = grayscale;
    }
    virtual ~vec2f32ColorGray(){}
    //operator =
    edk::vec2f32ColorGray operator=(edk::vec2f32ColorGray vecColor){
        this->position.x= vecColor.position.x;
        this->position.y= vecColor.position.y;
        this->grayscale = vecColor.grayscale;
        return *this;
    }
    edk::vec2f32 position;
    edk::uint8 grayscale;
};

class Voronoi{
public:
    Voronoi();
    virtual ~Voronoi();

    //generate the voronoi image
    static bool generateImageRGB(edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool generateImageRGB(edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool generateImageRGB(edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool generateImageGray(edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool generateImageGray(edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool generateImageGray(edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool generateImage(edk::uint32 pointSize,edk::Image2D* image);
    static bool generateImage(edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::Image2D* image);
    static bool generateImage(edk::vector::Array<edk::vec2f32ColorGray>* points,edk::Image2D* image);
    //multiThread
    static bool multiGenerateImageRGB(edk::uint32 cores,edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool multiGenerateImageRGB(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool multiGenerateImageRGB(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool multiGenerateImageGray(edk::uint32 cores,edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool multiGenerateImageGray(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool multiGenerateImageGray(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height);
    static bool multiGenerateImage(edk::uint32 cores,edk::uint32 pointSize,edk::Image2D* image);
    static bool multiGenerateImage(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::Image2D* image);
    static bool multiGenerateImage(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorGray>* points,edk::Image2D* image);
private:
    //functions used the generate the image
    static bool runGenerateImageRGB(edk::vector::Array<edk::vec2f32ColorRGB>* points,
                                    edk::uint8* image,
                                    edk::uint32 width,
                                    edk::uint32 height,
                                    edk::uint32 start,
                                    edk::uint32 end
                                    );
    static bool runGenerateImageRGB(edk::vector::Array<edk::vec2f32ColorGray>* points,
                                    edk::uint8* image,
                                    edk::uint32 width,
                                    edk::uint32 height,
                                    edk::uint32 start,
                                    edk::uint32 end
                                    );
    static bool runGenerateImageGray(edk::vector::Array<edk::vec2f32ColorRGB>* points,
                                     edk::uint8* image,
                                     edk::uint32 width,
                                     edk::uint32 height,
                                     edk::uint32 start,
                                     edk::uint32 end
                                     );
    static bool runGenerateImageGray(edk::vector::Array<edk::vec2f32ColorGray>* points,
                                     edk::uint8* image,
                                     edk::uint32 width,
                                     edk::uint32 height,
                                     edk::uint32 start,
                                     edk::uint32 end
                                     );
    class ImageRGB{
    public:
        ImageRGB(){
            this->image=NULL;
            this->width=0u;
            this->height=0u;
            this->start=0u;
            this->end=0u;
        }
        virtual ~ImageRGB(){
            this->points.deleteArray();
        }
        edk::vector::Array<edk::vec2f32ColorRGB> points;
        edk::uint8* image;
        edk::uint32 width;
        edk::uint32 height;
        edk::uint32 start;
        edk::uint32 end;
    };
    class ImageGray{
    public:
        ImageGray(){
            this->image=NULL;
            this->width=0u;
            this->height=0u;
            this->start=0u;
            this->end=0u;
        }
        virtual ~ImageGray(){
            this->points.deleteArray();
        }
        edk::vector::Array<edk::vec2f32ColorGray> points;
        edk::uint8* image;
        edk::uint32 width;
        edk::uint32 height;
        edk::uint32 start;
        edk::uint32 end;
    };
    //thread functions
    static edk::classID runThreadGenerateImageRGBFromRGB(edk::classID image);
    static edk::classID runThreadGenerateImageRGBFromGray(edk::classID image);
    static edk::classID runThreadGenerateImageGrayFromRGB(edk::classID image);
    static edk::classID runThreadGenerateImageGrayFromGray(edk::classID image);
};
}//end namespace edk

#endif // VORONOI_H