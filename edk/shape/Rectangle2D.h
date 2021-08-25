#ifndef EDK_SHAPE_RECTANGLE2D_H
#define EDK_SHAPE_RECTANGLE2D_H

/*
Library Rectangle2D - Draw a 2D Rectangle in EDK Game Engine
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
#warning "Inside Rectangle2D"
#endif

//Include the polygon
#pragma once
#include "Polygon2D.h"

#ifdef printMessages
#warning "    Compiling Rectangle2D"
#endif

namespace edk{
namespace shape{
class Rectangle2D : public edk::shape::Polygon2D{
    public:
        Rectangle2D();
        virtual ~Rectangle2D();

        //Virtual Functions
        bool createPolygon(edk::uint32 vertexCount);
        void deletePolygon();

        //set the pivo to the center of the rectangle
        void setPivoToCenter();

        //print the rectangle
        void print();
        //Draw the rectangle
        void draw();
        //Draw the rectangle with lights
        bool drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],bool lightIsOn[][EDK_LIGHT_LIMIT]);
        //
        void drawWire();

        virtual bool cloneFrom(edk::shape::Polygon2D* poly);

    protected:
    private:
    //createPolygon
    bool createPolygon();
private:
        //Operator =
        edk::shape::Rectangle2D operator=(edk::shape::Polygon2D poly){
            //first remove the UV from the polygon
            this->deletePolygon();
            //copy the polygons
            for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                //
                //copy the vertex
                edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)vertexs[i];
                if(temp){
                    //this->setVertexPosition(i,poly.getVertexPosition(i));
                    temp->position = poly.getVertexPosition(i);
                    //this->setVertexColor(i,poly.getVertexColor(i));
                    temp->color = poly.getVertexColor(i);
                    //get vertexType
                    switch(poly.getVertexType(i)){
                        //
                        case EDK_SHAPE_ANIMATED_UV:
                            //
                            this->setVertexUVFrames(i,poly.getFrames());
                        case EDK_SHAPE_UV:
                            //
                            this->setVertexUV(i,poly.getVertexUV(i));
                            break;
                        };
                }
            }
            //cant delete the polygon
            poly.cantDeletePolygon();
            this->cantDeletePolygon();
            //return the polygon
            edk::shape::Rectangle2D temp;
            return temp;
        }
};
}//end namespace shape
}//end namespace edk

#endif // RECTANGLE2D_H
