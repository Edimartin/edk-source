#ifndef GRIDPOLYGONS2D_H
#define GRIDPOLYGONS2D_H

/*
Library GridPolygons2D - Grid in the 2D world drawing polygons by ID.
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
#pragma message "Inside GridPolygons2D"
#endif

#pragma once
#include "../TypeDefines.h"
#include "../TypeByte.h"
#include "../TypeColor.h"
#include "../TypeRect.h"
#include "../TypeSize2.h"
#include "../vector/Matrix.h"
#include "../Object2D.h"
#include "GridLines2D.h"

#ifdef printMessages
#pragma message "    Compiling GridPolygons2D"
#endif

namespace edk{
namespace shape{
class GridPolygons2D : public edk::shape::GridLines2D{
public:
    GridPolygons2D();
    ~GridPolygons2D();

    void Constructor();
    void Destructor();

    //create a new matrix
    bool newMatrix(edk::size2ui32 size);
    bool newMatrix(edk::uint32 width,edk::uint32 height);

    edk::size2ui32 getMatrixSize();
    edk::uint32 getMatrixWidth();
    edk::uint32 getMatrixHeight();

    //set color value in position
    bool setColor(edk::vec2ui32 position,edk::color4f32 color);
    bool setColor(edk::uint32 x,edk::uint32 y,edk::color4f32 color);
    bool setColor(edk::vec2ui32 position,edk::float32 r,edk::float32 g,edk::float32 b);
    bool setColor(edk::uint32 x,edk::uint32 y,edk::float32 r,edk::float32 g,edk::float32 b);
    bool setColor(edk::vec2ui32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    bool setColor(edk::uint32 x,edk::uint32 y,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

    //draw the grid
    virtual void draw();

    void drawSelection();
private:
    edk::vector::MatrixDynamic<edk::uint32> mat;
    //polygon to draw the color
    edk::Object2D obj;

    //colors
    class ColorWithID{
    public:
        ColorWithID(){
            this->position=0u;
            this->color = edk::color4f32(1.f,1.f,1.f,0.f);
        }
        ~ColorWithID(){}
        inline bool operator>(edk::shape::GridPolygons2D::ColorWithID color){
            if(this->color.r>color.color.r){
                return true;
            }
            else if(this->color.r==color.color.r){
                if(this->color.g>color.color.g){
                    return true;
                }
                else if(this->color.g==color.color.g){
                    if(this->color.b>color.color.b){
                        return true;
                    }
                    else if(this->color.b==color.color.b){
                        if(this->color.a>color.color.a){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        inline bool operator==(edk::shape::GridPolygons2D::ColorWithID color){
            if(this->color.r==color.color.r
                    &&
                    this->color.g==color.color.g
                    &&
                    this->color.b==color.color.b
                    &&
                    this->color.a==color.color.a
                    ){
                return true;
            }
            return false;
        }
        inline edk::shape::GridPolygons2D::ColorWithID operator=(edk::shape::GridPolygons2D::ColorWithID color){
            this->color.r=color.color.r;
            this->color.g=color.color.g;
            this->color.b=color.color.b;
            this->color.a=color.color.a;
            this->position=color.position;
            return *this;
        }
        edk::uint32 position;
        edk::color4f32 color;
    };
    edk::vector::BinaryTree<edk::shape::GridPolygons2D::ColorWithID> tree;
    edk::vector::Stack<edk::color4f32> stack;
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // GRIDPOLYGONS2D_H
