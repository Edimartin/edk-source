#ifndef EDK_SHAPE_POLYGON2DLIST_H
#define EDK_SHAPE_POLYGON2DLIST_H

/*
Library Polygon2DList - Manage 2D Polygons in EDK Game Engine
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
#warning "Inside Polygon2DList"
#endif

#pragma once
#include "Polygon2D.h"
#include "../vector/Stack.h"
#include "Polygon2D.h"
#include "Lines2D.h"
#include "Rectangle2D.h"
#include "Triangle2D.h"
#include "Quadrangle2D.h"
//Animation
#include "../animation/Interpolation2DGroup.h"

#ifdef printMessages
#warning "    Compiling Polygon2DList"
#endif

namespace edk{
namespace shape{
class Polygon2DList{
public:
    Polygon2DList();
    virtual ~Polygon2DList();

    //Set polygons color
    bool setPolygonsColor(edk::color4f32 color);
    bool setPolygonsColor(edk::color3f32 color);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
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

    //ADD
    //add a polygon to the mesh
    virtual edk::uint32 addPolygon(edk::shape::Polygon2D polygon);
    //GETERS
    //return the polygonSize
    edk::uint32 getPolygonSize();
    //return true if have a polygon selected
    bool haveSelected();

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
    bool selectedUsePolygonUVFrame(edk::vec2ui32 frame);
    bool selectedUsePolygonUVFrame(edk::uint32 x,edk::uint32 y);
    bool selectedUsePolygonUVFramePosition(edk::uint32 position);
    bool selectedUsePolygonUVFrameX(edk::uint32 x);
    bool selectedUsePolygonUVFrameY(edk::uint32 y);
    //Set physics
    bool selectedSetDensity(edk::float32 density);
    bool selectedSetFriction(edk::float32 friction);
    bool selectedSetRestitution(edk::float32 restitution);

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

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    //Operator
    edk::shape::Polygon2DList operator=(edk::shape::Polygon2DList list){
        //delete the polygons
        this->cleanPolygons();
        //read the polygons
        register edk::uint32 size = list.polygons.size();
        edk::uint32 select=0u;
        edk::shape::Polygon2D* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            //
            temp=list.polygons[i];
            if(temp){
                if(temp==list.selected){
                    select=i;
                }
                this->addPolygon(*temp);
            }
        }
        this->selectPolygon(select);
        list.cantDeleteList();
        this->cantDeleteList();
        return list;
    }


    //DRAW
    //print the mesh
    virtual void printPolygons();
    //draw the mesh
    virtual void drawPolygons();
    //draw the mesh with lights
    virtual void drawPolygonsWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]
    );
    //draw the polygons in wireframe
    virtual void drawWirePolygons();

    //Set to cant delete the polygon
    void cantDeleteList();
protected:
    //list of polygons
    edk::vector::Stack<edk::shape::Polygon2D*> polygons;
    //mesh selected
    edk::shape::Polygon2D* selected;
private:
    bool canDeleteList;
};
}//end namespace shape
}//end namespace edk

#endif // POLYGON2DLIST_H
