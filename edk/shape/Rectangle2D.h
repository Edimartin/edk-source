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
#pragma message "Inside Rectangle2D"
#endif

//Include the polygon
#pragma once
#include "Polygon2D.h"

#ifdef printMessages
#pragma message "    Compiling Rectangle2D"
#endif

namespace edk{
namespace shape{
class Rectangle2D : public edk::shape::Polygon2D{
public:
    Rectangle2D();
    virtual ~Rectangle2D();

    void Constructor(bool runFather=true);

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
    //function to create the VBO
    virtual bool createVBO(edk::uint32 vertexCount,edk::shape::EDKVBOType type);
    //setters to VBO
    virtual bool setVBOVertexPosition(edk::uint32 vertex,edk::vec2f32 position);
    virtual bool setVBOVertexNormal(edk::uint32 vertex,edk::vec3f32 normal);
    virtual bool setVBOVertexColor(edk::uint32 vertex,edk::color4f32 color);
    virtual bool setVBOVertexUV(edk::uint32 vertex,edk::vec2f32 uv);
    virtual bool setVBOVertexU(edk::uint32 vertex,edk::float32 u);
    virtual bool setVBOVertexV(edk::uint32 vertex,edk::float32 v);
    //updafe the UV into the VBO
    virtual bool updateVBOUV();
    virtual bool updateVBOValues();

    //DRAW
    virtual void draw_NULL(edk::uint32 mode);
    //DRAW UPDATE
    virtual void drawUpdate_NULL(edk::uint32 mode);
private:
    //createPolygon
    bool createPolygon();
private:
    //Operator =
    edk::shape::Rectangle2D operator=(edk::shape::Rectangle2D poly){
        //first remove the UV from the polygon
        this->deletePolygon();edkEnd();
        //copy the polygons
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //copy the vertex
            edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);edkEnd();
            if(temp){
                //this->setVertexPosition(i,poly.getVertexPosition(i));edkEnd();
                temp->position = poly.getVertexPosition(i);edkEnd();
                //this->setVertexColor(i,poly.getVertexColor(i));edkEnd();
                temp->color = poly.getVertexColor(i);edkEnd();
                //get vertexType
                switch(poly.getVertexType(i)){
                //
                case EDK_SHAPE_ANIMATED_UV:
                    //
                    this->setVertexUVFrames(i,poly.getFrames());edkEnd();
                case EDK_SHAPE_UV:
                    //
                    this->setVertexUV(i,poly.getVertexUV(i));edkEnd();
                    break;
                };
            }
        }
        //copy the polygons
        for(edk::uint32 i=0u;i<this->vertexsOriginal.size();i++){
            //copy the vertex
            edk::shape::Vertex2DAnimatedUV* vTemp = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);edkEnd();
            edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)poly.vertexsOriginal.get(i);edkEnd();
            if(vTemp && temp){
                //this->setVertexPosition(i,poly.getVertexPosition(i));edkEnd();
                vTemp->position = temp->position;edkEnd();
                //this->setVertexColor(i,poly.getVertexColor(i));edkEnd();
                vTemp->color = temp->color;edkEnd();
                //get vertexType
                switch(poly.getVertexType(i)){
                //
                case EDK_SHAPE_ANIMATED_UV:
                    //
                    vTemp->setUV(temp->getUV());
                    vTemp->setUVFrames(temp->getUVFrames());
                case EDK_SHAPE_UV:
                    //
                    vTemp->setUV(temp->getUV());
                    break;
                };
            }
        }
        //return the polygon
        edk::shape::Rectangle2D temp;edkEnd();
        return temp;edkEnd();
    }
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // RECTANGLE2D_H
