#ifndef EDK_SHAPE_POLYGON2DLIST_H
#define EDK_SHAPE_POLYGON2DLIST_H

/*
Library Polygon2DList - Manage 2D Polygons in EDK Game Engine
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
#pragma message "Inside Polygon2DList"
#endif

#pragma once
#include "Polygon2D.h"
#include "../vector/Stack.h"
#include "Polygon2D.h"
#include "Lines2D.h"
#include "Circle2D.h"
#include "Rectangle2D.h"
#include "Triangle2D.h"
#include "Quadrangle2D.h"
//Animation
#include "../animation/Interpolation2DGroup.h"

#ifdef printMessages
#pragma message "    Compiling Polygon2DList"
#endif

namespace edk{
namespace shape{
class Polygon2DList{
public:
    Polygon2DList();
    virtual ~Polygon2DList();

    void Constructor(bool runFather=true);

    //Set polygons color
    bool setPolygonsColor(edk::color4f32 color);
    bool setPolygonsColor(edk::color3f32 color);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    bool setPolygonsColorR(edk::float32 r);
    bool setPolygonsColorG(edk::float32 g);
    bool setPolygonsColorB(edk::float32 b);
    bool setPolygonsColorA(edk::float32 a);
    //set physics
    bool setPolygonDensity(edk::uint32 position,edk::float32 density);
    void setDensity(edk::float32 density);
    bool setPolygonFriction(edk::uint32 position,edk::float32 friction);
    void setFriction(edk::float32 friction);
    bool setPolygonRestitution(edk::uint32 position,edk::float32 restitution);
    void setRestitution(edk::float32 restitution);
    //getPhysics
    edk::float32 getPolygonDensity(edk::uint32 position);
    edk::float32 getPolygonFriction(edk::uint32 position);
    edk::float32 getPolygonRestitution(edk::uint32 position);

    //function to calculate boundingBox
    bool calculateBoundingBox(edk::rectf32* rectangle,edk::vector::Matrixf32<3u,3u>* transformMat);
    edk::rectf32 generateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);
    bool getWorldPolygon(edk::shape::Polygon2D* dest,edk::uint32 polygonPosition,edk::vector::Matrixf32<3u,3u>* transformMat);

    //ADD
    //add a polygon to the mesh
    virtual edk::uint32 addPolygon(edk::shape::Polygon2D polygon);
    //GETERS
    //return the polygonSize
    edk::uint32 getPolygonSize();
    //return true if have a polygon selected
    bool haveSelected();

    //test if have a polygon in a position
    bool havePolygon(edk::uint32 position);
    //get the polygon in a position
    edk::shape::Polygon2D getPolygon(edk::uint32 position);
    bool getPolygon(edk::uint32 position,edk::shape::Polygon2D* dest);

    //DELETE
    //clean the polygons
    void cleanPolygons();
    //delete the polygon
    bool removePolygon(edk::uint32 position);
    //free de selected
    void freeSelected();

    //SELECTED
    bool selectPolygon(edk::uint32 position);
    //set the position of a vertex
    bool selectedSetVertexPosition(edk::uint32 vertex,edk::vec2f32 position);
    bool selectedSetVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y);
    //set the color of a vertex
    bool selectedSetVertexColor(edk::uint32 vertex,edk::color4f32 color);
    bool selectedSetVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b);
    bool selectedSetVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    //Set polygon color
    bool selectedSetPolygonColor(edk::color4f32 color);
    bool selectedSetPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b);
    bool selectedSetPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    //set the UVMap of the vertex
    bool selectedSetVertexUV(edk::uint32 vertex,edk::vec2f32 uv);
    bool selectedSetVertexUV(edk::uint32 vertex,edk::float32 x,edk::float32 y);
    //Set the polygonFrames setting in the vertexs
    bool selectedSetPolygonUVFrames(edk::vec2ui32 frames);
    bool selectedSetPolygonUVFrames(edk::uint32 x,edk::uint32 y);
    bool selectedSetPolygonUVFramesX(edk::uint32 x);
    bool selectedSetPolygonUVFramesY(edk::uint32 y);
    //Set the polygon frame
    bool selectedSetPolygonUVFrame(edk::vec2ui32 frame);
    bool selectedSetPolygonUVFrame(edk::uint32 x,edk::uint32 y);
    bool selectedSetPolygonUVFramePosition(edk::uint32 position);
    bool selectedSetPolygonUVFrameX(edk::uint32 x);
    bool selectedSetPolygonUVFrameY(edk::uint32 y);
    bool selectedUsePolygonUVFrame(edk::vec2ui32 frame);
    bool selectedUsePolygonUVFrame(edk::uint32 x,edk::uint32 y);
    bool selectedUsePolygonUVFramePosition(edk::uint32 position);
    bool selectedUsePolygonUVFrameX(edk::uint32 x);
    bool selectedUsePolygonUVFrameY(edk::uint32 y);
    //Set physics
    bool selectedSetDensity(edk::float32 density);
    bool selectedSetFriction(edk::float32 friction);
    bool selectedSetRestitution(edk::float32 restitution);
    //set transform
    bool selectedSetTranslate(edk::vec2f32 translate);
    bool selectedSetTranslate(edk::float32 translate);
    bool selectedSetTranslate(edk::float32 x,edk::float32 y);
    bool selectedSetScale(edk::size2f32 scale);
    bool selectedSetScale(edk::float32 scale);
    bool selectedSetScale(edk::float32 width,edk::float32 height);
    bool selectedSetAngle(edk::float32 angle);

    //CLEANS
    //remove the UV of one vertex
    bool selectedRemoveVertexUV(edk::uint32 vertex);
    //remove the UV from the polygon
    bool selectedRemovePolygonUV();
    //clean the UV animation in polygons
    bool selectedCleanPolygonUVAnimation();
    //return the vertexCount
    edk::uint32 selectedGetVertexCount();
    //return if the vertex have UV
    edk::uint8 selectedGetVertexType(edk::uint32 pos);
    //return the vertex
    edk::vec2f32 selectedGetVertexPosition(edk::uint32 pos);
    //return the vertex color
    edk::color4f32 selectedGetVertexColor(edk::uint32 pos);
    //return the vertex UV
    edk::vec2f32 selectedGetVertexUV(edk::uint32 pos);
    //return the frames
    edk::vec2ui32 selectedGetFrames();
    edk::uint32 selectedGetFramesPosition();
    //return the frameUsed
    edk::vec2ui32 selectedGetFrameUsed();
    edk::uint32 selectedGetFramePositionUsed();
    //get Transate
    edk::vec2f32 selectedGetTranslate();
    //get scale
    edk::size2f32 selectedGetScale();
    //get angle
    edk::float32 selectedGetAngle();
    //return if is a circle
    bool selectedIsCircle();
    //return if is a line
    bool selectedIsLine();
    //return the collisionID
    edk::uint8 selectedGetCollisionID();
    //return the circle radius
    edk::float32 selectedGetCircleRadius();
    //get Physics
    edk::float32 selectedGetDensity();
    edk::float32 selectedGetFriction();
    edk::float32 selectedGetRestitution();
    //draw the selectedPolygon
    bool selectedDrawPolygon();
    bool selectedDrawWirePolygon();
    bool selectedDrawVertexs(edk::color3f32 color = edk::color3f32(1,1,1));

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::shape::Polygon2DList* list);


    //DRAW
    //print the mesh
    virtual void printPolygons();
    virtual bool printPolygon(edk::uint32 polygon);
    //draw the mesh
    virtual void drawPolygons();
    virtual bool drawPolygon(edk::uint32 polygon);
    //draw the polygons in wireframe
    virtual void drawWirePolygons();
    virtual bool drawWirePolygon(edk::uint32 polygon);
    virtual void drawVertexs(edk::color3f32 color = edk::color3f32(1,1,1));
    virtual bool drawPolygonVertexs(edk::uint32 polygon,edk::color3f32 color = edk::color3f32(1,1,1));

    //Set to cant delete the polygon
    void cantDeleteList();
protected:
    //list of polygons
    edk::vector::Stack<edk::shape::Polygon2D*> polygons;
    //mesh selected
    edk::shape::Polygon2D* selected;
private:
    bool canDeleteList;

    //Operator
    edk::shape::Polygon2DList operator=(edk::shape::Polygon2DList list){
        //delete the polygons
        this->cleanPolygons();edkEnd();
        //read the polygons
        register edk::uint32 size = list.polygons.size();edkEnd();
        edk::uint32 select=0u;edkEnd();
        edk::shape::Polygon2D* temp = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp=list.polygons.get(i);edkEnd();
            if(temp){
                if(temp==list.selected){
                    select=i;edkEnd();
                }
                this->addPolygon(*temp);edkEnd();
            }
        }
        this->selectPolygon(select);edkEnd();
        list.cantDeleteList();edkEnd();
        this->cantDeleteList();edkEnd();
        return list;edkEnd();
    }
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // POLYGON2DLIST_H
