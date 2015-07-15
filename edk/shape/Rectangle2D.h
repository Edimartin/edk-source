#ifndef EDK_SHAPE_RECTANGLE2D_H
#define EDK_SHAPE_RECTANGLE2D_H

/*
Library Rectangle2D - Draw a 2D Rectangle in EDK Game Engine
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

    protected:
    private:
    //createPolygon
    bool createPolygon();
};
}//end namespace shape
}//end namespace edk

#endif // RECTANGLE2D_H
