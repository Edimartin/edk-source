#ifndef EDK_SHAPE_POLYGON3D_H
#define EDK_SHAPE_POLYGON3D_H

/*
Library Polygon3D - Draw a 2D Polygon in EDK Game Engine
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
    bool setVertex(edk::uint32 position,edk::shape::Vertex3D* vertex,edk::uint32 vertexID);
    bool setNormal(edk::uint32 position,edk::shape::Vector3D* normal,edk::uint32 normalID);
    bool setUV(edk::uint32 position,edk::shape::UV2D* uv,edk::uint32 uvID);

    //Set polygon color
    bool setPolygonColor(edk::color4f32 color);
    bool setPolygonColor(edk::color3f32 color);
    bool setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b);
    bool setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

    //Calculate the normal of the polygon
    bool updateNormal();
    void setNormalFlat(edk::shape::Vector3D normal);

    //print the polygon
    virtual bool print();
    //draw the polygon
    virtual void draw();
    //Draw the polygon with lines
    virtual void drawWire();
    virtual void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
    //draw vertexs
    virtual void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1));

    virtual void drawPolygonNormals();
    virtual void drawPolygonNormalsWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));

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
    edk::shape::Vector3D center;
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
    //update the center position
    void updateCenterPosition();
    //Only Vertex
    class PolygonVertex{
    public:
        PolygonVertex(edk::shape::Vertex3D* vertex,edk::uint32 vertexID){
            this->vertex = vertex;
            this->vertexID=vertexID;
        }
        virtual ~PolygonVertex(){}
        virtual void draw(){
            this->vertex->drawVertex();
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            normal.drawNormal();
            this->vertex->drawVertex();
        }
        virtual void drawWithoutNormal(){
            this->vertex->drawVertex();
        }
        void drawVertex(){
            this->vertex->drawVertex();
        }
        void drawWithColor(edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);
        }
        virtual void drawNormal(){}
        virtual void drawNormalWithColor(edk::color4f32){}
        virtual void drawNormalPosition(edk::vec3f32){}
        virtual void drawNormalPositionWithColor(edk::vec3f32,edk::color4f32){}
        virtual void print(){
            this->vertex->printVertex();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertex;
        }
        edk::shape::Polygon3D::PolygonVertex operator=(edk::shape::Polygon3D::PolygonVertex vert){
            this->vertex = vert.vertex;
            this->vertexID = vert.vertexID;
            return vert;
        }
        edk::shape::Vertex3D* vertex;
        edk::uint32 vertexID;
    };
    //Vertex With UV
    class PolygonVertexWithUV : public edk::shape::Polygon3D::PolygonVertex{
    public:
        PolygonVertexWithUV(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,
                            edk::shape::UV2D* uv,edk::uint32 uvID
                            )
            :edk::shape::Polygon3D::PolygonVertex(vertex,vertexID)
        {
            this->uv = uv;
            this->uvID = uvID;
        }
        virtual ~PolygonVertexWithUV(){}
        virtual void draw(){
            this->uv->drawUV();
            this->vertex->drawVertex();
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            this->uv->drawUV();
            normal.drawNormal();
            this->vertex->drawVertex();
        }
        virtual void drawWithoutNormal(){
            this->uv->drawUV();
            this->vertex->drawVertex();
        }
        virtual void drawNormal(){}
        virtual void drawNormalWithColor(edk::color4f32){}
        virtual void drawNormalPosition(edk::vec3f32){}
        virtual void drawNormalPositionWithColor(edk::vec3f32,edk::color4f32){}
        virtual void print(){
            this->vertex->printVertex();
            this->uv->printUV();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertexWithUV;
        }
        edk::shape::Polygon3D::PolygonVertexWithUV operator=(edk::shape::Polygon3D::PolygonVertexWithUV vert){
            this->vertex = vert.vertex;
            this->vertexID = vert.vertexID;
            this->uv = vert.uv;
            this->uvID = vert.uvID;
            return vert;
        }
        edk::shape::UV2D* uv;
        edk::uint32 uvID;
    };
    //Vertex With Normal
    class PolygonVertexWithNormal : public edk::shape::Polygon3D::PolygonVertex{
    public:
        PolygonVertexWithNormal(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,
                                edk::shape::Vector3D* normal,edk::uint32 normalID
                                )
            :edk::shape::Polygon3D::PolygonVertex(vertex,vertexID)
        {
            this->normal = normal;
            this->normalID = normalID;
        }
        virtual ~PolygonVertexWithNormal(){}
        virtual void draw(){
            this->normal->drawNormal();
            this->vertex->drawVertex();
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            normal.drawNormal();
            this->vertex->drawVertex();
        }
        virtual void drawWithoutNormal(){
            this->vertex->drawVertex();
        }
        virtual void drawNormal(){
            this->vertex->drawVertex();
            this->normal->drawVertexPosition(edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));
        }
        virtual void drawNormalWithColor(edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);
            this->normal->drawVertexPosition(edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));
        }
        virtual void drawNormalPosition(edk::vec3f32 position){
            this->vertex->drawVertex();
            this->vertex->drawVertexPosition(position);
        }
        virtual void drawNormalPositionWithColor(edk::vec3f32 position,edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);
            this->vertex->drawVertexPosition(position);
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
            this->vertexID = vert.vertexID;
            this->normal = vert.normal;
            this->normalID = vert.normalID;
            return vert;
        }
        edk::shape::Vector3D* normal;
        edk::uint32 normalID;
    };
    //Vertex With UV and Normal
    class PolygonVertexWithUVNormal: public edk::shape::Polygon3D::PolygonVertexWithNormal{
    public:
        PolygonVertexWithUVNormal(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,
                                  edk::shape::UV2D* uv,edk::uint32 uvID,
                                  edk::shape::Vector3D* normal,edk::uint32 normalID
                                  )
            :edk::shape::Polygon3D::PolygonVertexWithNormal(vertex,vertexID
                                                            ,normal,normalID
                                                            )
        {
            this->uv = uv;
            this->uvID = uvID;
        }
        virtual ~PolygonVertexWithUVNormal(){}
        virtual void draw(){
            this->uv->drawUV();
            this->normal->drawNormal();
            this->vertex->drawVertex();
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            this->uv->drawUV();
            normal.drawNormal();
            this->vertex->drawVertex();
        }
        virtual void drawWithoutNormal(){
            this->uv->drawUV();
            this->vertex->drawVertex();
        }
        virtual void drawNormal(){
            this->vertex->drawVertex();
            this->normal->drawVertexPosition(edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));
        }
        virtual void drawNormalWithColor(edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);
            this->normal->drawVertexPosition(edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));
        }
        virtual void drawNormalPosition(edk::vec3f32 position){
            this->vertex->drawVertex();
            this->vertex->drawVertexPosition(position);
        }
        virtual void drawNormalPositionWithColor(edk::vec3f32 position,edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);
            this->vertex->drawVertexPosition(position);
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
            this->vertexID = vert.vertexID;
            this->uv = vert.uv;
            this->uvID = vert.uvID;
            this->normal = vert.normal;
            this->normalID = vert.normalID;
            return vert;
        }
        edk::shape::UV2D* uv;
        edk::uint32 uvID;
    };
    edk::shape::Polygon3D operator=(edk::shape::Polygon3D list){
        return list;
    }
};

}//end namespace shape
}//end namespace edk


#endif // POLYGON3D_H

