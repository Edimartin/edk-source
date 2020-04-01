#ifndef EDK_SHAPE_POLYGON3D_H
#define EDK_SHAPE_POLYGON3D_H

/*
Library Polygon3D - Draw a 2D Polygon in EDK Game Engine
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
#warning "Inside Polygon"
#endif

//Include EDK
#pragma once
#include "Vertex3D.h"
#include "../vector/Array.h"
#include "../animation/Interpolation1DGroup.h"
#include "../Math.h"
#include "../xml/XML.h"
#include "../light/Light.h"

#ifdef printMessages
#warning "    Compiling Polygon"
#endif

namespace edk{
namespace shape{

//minimum vertex countin the polygon. 2 vertex is one line
#define minimumVertex 2u

class Polygon3D{
public:
    Polygon3D();
    virtual ~Polygon3D();

    //create the polygon
    virtual bool createPolygon(edk::uint32 vertexCount);
    void deletePolygon();

    //Set the vertexes
    bool setVertex(edk::uint32 position,edk::shape::Vertex3D* vertex);
    bool setNormal(edk::uint32 position,edk::shape::Vector3D* normal);
    bool setUV(edk::uint32 position,edk::shape::UV2D* uv);

    //Calculate the normal of the polygon
    bool updateNormal();

    //print the polygon
    virtual bool print();
    //draw the polygon
    virtual void draw();
    //Draw the polygon with lights
    virtual bool drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],bool lightIsOn[][EDK_LIGHT_LIMIT]);
    //Draw the polygon with lines
    virtual void drawWire();
    virtual void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
    //draw vertexs
    virtual void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1));

    bool cloneFrom(edk::shape::Polygon3D* poly);

    //boolean to save if the polygon is draw with smooth
    bool smooth;
protected:
    //Draw the polygon
    virtual bool drawVertexs();
    virtual bool drawVertexsOnly();
    virtual bool drawVertexsWithColor(edk::color4f32 color);
private:
    //save one vertex in the memory to be used in create polygon to not crash the software
    static edk::shape::Vertex3D staticVertex;
    static edk::shape::Vector3D staticNormal;
    static edk::shape::UV2D staticUV;
    //normal of the polygon
    edk::shape::Vector3D normal;
    class PolygonVertex;
    //array with the vertexes
    edk::vector::Array<PolygonVertex*> vertexs;
    //Vertex types to save the vertex in the memory
    enum VertexType{
        typeVertex=1u,
        typeVertexWithUV,
        typeVertexWithNormal,
        typeVertexWithUVNormal,
    };
    //Only Vertex
    class PolygonVertex{
    public:
        PolygonVertex(edk::shape::Vertex3D* vertex){
            this->vertex = vertex;
        }
        virtual ~PolygonVertex(){}
        virtual void draw(){
            this->vertex->drawVertex();
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            this->vertex->drawVertex();
            normal.drawNormal();
        }
        void drawVertex(){
            this->vertex->drawVertex();
        }
        void drawWithColor(edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);
        }
        virtual void print(){
            this->vertex->printVertex();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertex;
        }
        edk::shape::Polygon3D::PolygonVertex operator=(edk::shape::Polygon3D::PolygonVertex vert){
            this->vertex = vert.vertex;
            return vert;
        }
        edk::shape::Vertex3D* vertex;
    };
    //Vertex With UV
    class PolygonVertexWithUV : public edk::shape::Polygon3D::PolygonVertex{
    public:
        PolygonVertexWithUV(edk::shape::Vertex3D* vertex,edk::shape::UV2D* uv)
            :edk::shape::Polygon3D::PolygonVertex(vertex)
        {
            this->uv = uv;
        }
        virtual ~PolygonVertexWithUV(){}
        virtual void draw(){
            this->vertex->drawVertex();
            this->uv->drawUV();
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            this->vertex->drawVertex();
            normal.drawNormal();
            this->uv->drawUV();
        }
        virtual void print(){
            this->vertex->printVertex();
            this->uv->printUV();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertexWithUV;
        }
        edk::shape::Polygon3D::PolygonVertexWithUV operator=(edk::shape::Polygon3D::PolygonVertexWithUV vert){
            this->vertex = vert.vertex;
            this->uv = vert.uv;
            return vert;
        }
        edk::shape::UV2D* uv;
    };
    //Vertex With Normal
    class PolygonVertexWithNormal : public edk::shape::Polygon3D::PolygonVertex{
    public:
        PolygonVertexWithNormal(edk::shape::Vertex3D* vertex,edk::shape::Vector3D* normal)
            :edk::shape::Polygon3D::PolygonVertex(vertex)
        {
            this->normal = normal;
        }
        virtual ~PolygonVertexWithNormal(){}
        virtual void draw(){
            this->vertex->drawVertex();
            this->normal->drawNormal();
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            this->vertex->drawVertex();
            normal.drawNormal();
        }
        virtual void print(){
            this->vertex->printVertex();
            this->normal->printNormal();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertexWithNormal;
        }
        edk::shape::Polygon3D::PolygonVertexWithNormal operator=(edk::shape::Polygon3D::PolygonVertexWithNormal vert){
            this->vertex = vert.vertex;
            this->normal = vert.normal;
            return vert;
        }
        edk::shape::Vector3D* normal;
    };
    //Vertex With UV and Normal
    class PolygonVertexWithUVNormal: public edk::shape::Polygon3D::PolygonVertexWithNormal{
    public:
        PolygonVertexWithUVNormal(edk::shape::Vertex3D* vertex,edk::shape::UV2D* uv,edk::shape::Vector3D* normal)
            :edk::shape::Polygon3D::PolygonVertexWithNormal(vertex,normal)
        {
            this->uv = uv;
        }
        virtual ~PolygonVertexWithUVNormal(){}
        virtual void draw(){
            this->vertex->drawVertex();
            this->normal->drawNormal();
            this->uv->drawUV();
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            this->vertex->drawVertex();
            normal.drawNormal();
            this->uv->drawUV();
        }
        virtual void print(){
            this->vertex->printVertex();
            this->normal->printNormal();
            this->uv->printUV();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertexWithUVNormal;
        }
        edk::shape::Polygon3D::PolygonVertexWithUVNormal operator=(edk::shape::Polygon3D::PolygonVertexWithUVNormal vert){
            this->vertex = vert.vertex;
            this->uv = vert.uv;
            this->normal = vert.normal;
            return vert;
        }
        edk::shape::UV2D* uv;
    };
    edk::shape::Polygon3D operator=(edk::shape::Polygon3D list){
        return list;
    }
};

}//end namespace shape
}//end namespace edk


#endif // POLYGON3D_H

