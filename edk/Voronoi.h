#ifndef VORONOI_H
#define VORONOI_H

/*
Library C++ Voronoi - Voronoi generator to be used in EDK.
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
#pragma message "Inside Action"
#endif

#ifdef printMessages
#pragma message "    Compiling Action"
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
        this->position.x = this->position.y = 0.f;edkEnd();
        this->color.r = this->color.g = this->color.b = 0u;edkEnd();
    }
    vec2f32ColorRGB(edk::vec2f32 position,edk::color3ui8 color){
        this->position = position;edkEnd();
        this->color = color;edkEnd();
    }
    vec2f32ColorRGB(edk::float32 x,edk::float32 y,edk::uint8 r,edk::uint8 g,edk::uint8 b){
        this->position.x = x;edkEnd();
        this->position.y = y;edkEnd();
        this->color.r = r;edkEnd();
        this->color.g = g;edkEnd();
        this->color.b = b;edkEnd();
    }
    virtual ~vec2f32ColorRGB(){}
    //operator =
    edk::vec2f32ColorRGB operator=(edk::vec2f32ColorRGB vecColor){
        this->position.x= vecColor.position.x;edkEnd();
        this->position.y= vecColor.position.y;edkEnd();
        this->color.r = vecColor.color.r;edkEnd();
        this->color.g = vecColor.color.g;edkEnd();
        this->color.b = vecColor.color.b;edkEnd();
        return *this;edkEnd();
    }
    edk::vec2f32 position;
    edk::color3ui8 color;
};
class vec2f32ColorGray{
public:
    vec2f32ColorGray(){
        this->position.x = this->position.y = 0.f;edkEnd();
        this->grayscale = 0u;edkEnd();
    }
    vec2f32ColorGray(edk::vec2f32 position,edk::uint8 grayscale){
        this->position = position;edkEnd();
        this->grayscale = grayscale;edkEnd();
    }
    vec2f32ColorGray(edk::float32 x,edk::float32 y,edk::uint8 grayscale){
        this->position.x = x;edkEnd();
        this->position.y = y;edkEnd();
        this->grayscale = grayscale;edkEnd();
    }
    virtual ~vec2f32ColorGray(){}
    //operator =
    edk::vec2f32ColorGray operator=(edk::vec2f32ColorGray vecColor){
        this->position.x= vecColor.position.x;edkEnd();
        this->position.y= vecColor.position.y;edkEnd();
        this->grayscale = vecColor.grayscale;edkEnd();
        return *this;edkEnd();
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
            this->image=NULL;edkEnd();
            this->width=0u;edkEnd();
            this->height=0u;edkEnd();
            this->start=0u;edkEnd();
            this->end=0u;edkEnd();
        }
        virtual ~ImageRGB(){
            this->points.deleteArray();edkEnd();
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
            this->image=NULL;edkEnd();
            this->width=0u;edkEnd();
            this->height=0u;edkEnd();
            this->start=0u;edkEnd();
            this->end=0u;edkEnd();
        }
        virtual ~ImageGray(){
            this->points.deleteArray();edkEnd();
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
