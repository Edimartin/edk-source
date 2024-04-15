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
#pragma message "Inside Polygon"
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
#pragma message "    Compiling Polygon"
#endif

namespace edk{
namespace shape{

//minimum vertex countin the polygon. 2 vertex is one line
#define minimumVertex 2u

class Polygon3D{
public:
    Polygon3D();
    virtual ~Polygon3D();

    void Constructor(bool runFather=true);

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
    virtual void drawWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    //Draw the polygon with lines
    virtual void drawWire();
    virtual void drawWireWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
    virtual void drawWithWireWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1));
    //draw vertexs
    virtual void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1));
    virtual void drawPolygonVertexsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1));

    virtual void drawPolygonNormals();
    virtual void drawPolygonNormalsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual void drawPolygonNormalsWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
    virtual void drawPolygonNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1));

    bool cloneFrom(edk::shape::Polygon3D* poly);

    //boolean to save if the polygon is draw with smooth
    bool smooth;
protected:
    //Draw the polygon
    virtual bool drawVertexs();
    virtual bool drawVertexsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual bool drawVertexsOnly();
    virtual bool drawVertexsOnlyWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual bool drawVertexsWithColor(edk::color4f32 color);
    virtual bool drawVertexsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color);
private:
    //save one vertex in the memory to be used in create polygon to not crash the software
    static edk::shape::Vertex3D staticVertex;
    static edk::shape::Vector3D staticNormal;
    static edk::shape::UV2D staticUV;
    static bool templateConstructNeed;
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
            this->classThis=NULL;edkEnd();
            this->Constructor(vertex,vertexID,false);edkEnd();
        }
        virtual ~PolygonVertex(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,bool runFather=true){
            if(runFather){edkEnd();}
            if(this->classThis!=this){
                this->classThis=this;
                this->vertex = vertex;edkEnd();
                this->vertexID=vertexID;edkEnd();
            }
        }

        virtual void draw(){
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            normal.drawNormal();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithMatrixWithNormal(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Vector3D normal){
            if(matrix){
                normal.drawNormalWithMatrix(matrix,matrixTemp);edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawWithoutNormal(){
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithoutNormalWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
        }
        void drawVertex(){
            this->vertex->drawVertex();edkEnd();
        }
        void drawVertexWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        void drawWithColor(edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);edkEnd();
        }
        void drawWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color){
            if(matrix){
                this->vertex->drawVertexWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
            }
        }
        virtual void drawNormal(){}
        virtual void drawNormalWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>*,edk::vector::Matrix<edk::float32,4u,4u>*){}
        virtual void drawNormalWithColor(edk::color4f32){}
        virtual void drawNormalWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>*,edk::vector::Matrix<edk::float32,4u,4u>*,edk::color4f32){}
        virtual void drawNormalPosition(edk::vec3f32){}
        virtual void drawNormalPositionWithMatrix(edk::vector::Matrix<edk::float32,3u,3u>*,edk::vec3f32,edk::vector::Matrix<edk::float32,3u,3u>*){}
        virtual void drawNormalPositionWithColor(edk::vec3f32,edk::color4f32){}
        virtual void drawNormalPositionWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>*,edk::vector::Matrix<edk::float32,4u,4u>*,edk::vec3f32,edk::color4f32){}
        virtual void print(){
            this->vertex->printVertex();edkEnd();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertex;edkEnd();
        }
        edk::shape::Polygon3D::PolygonVertex operator=(edk::shape::Polygon3D::PolygonVertex vert){
            this->vertex = vert.vertex;edkEnd();
            this->vertexID = vert.vertexID;edkEnd();
            return vert;edkEnd();
        }
        edk::shape::Vertex3D* vertex;
        edk::uint32 vertexID;
    private:
        edk::classID classThis;
    };
    //Vertex With UV
    class PolygonVertexWithUV : public edk::shape::Polygon3D::PolygonVertex{
    public:
        PolygonVertexWithUV(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,
                            edk::shape::UV2D* uv,edk::uint32 uvID
                            )
            :edk::shape::Polygon3D::PolygonVertex(vertex,vertexID)
        {
            this->classThis=NULL;edkEnd();
            this->Constructor(vertex,vertexID,uv,uvID,false);edkEnd();
        }
        virtual ~PolygonVertexWithUV(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,
                         edk::shape::UV2D* uv,edk::uint32 uvID,
                         bool runFather=true){
            if(runFather){
                edk::shape::Polygon3D::PolygonVertex::Constructor(vertex,vertexID);edkEnd();
            }
            if(this->classThis!=this){
                this->classThis=this;
                this->uv = uv;edkEnd();
                this->uvID = uvID;edkEnd();
            }
        }

        virtual void draw(){
            this->uv->drawUV();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->uv->drawUV();edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            this->uv->drawUV();edkEnd();
            normal.drawNormal();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithMatrixWithNormal(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Vector3D normal){
            if(matrix){
                this->uv->drawUV();edkEnd();
                normal.drawNormalWithMatrix(matrix,matrixTemp);edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawWithoutNormal(){
            this->uv->drawUV();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithoutNormalWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->uv->drawUV();edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawNormal(){}
        virtual void drawNormalWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>*,edk::vector::Matrix<edk::float32,4u,4u>*){}
        virtual void drawNormalWithColor(edk::color4f32){}
        virtual void drawNormalWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>*,edk::vector::Matrix<edk::float32,4u,4u>*,edk::color4f32){}
        virtual void drawNormalPosition(edk::vec3f32){}
        virtual void drawNormalPositionWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>*,edk::vector::Matrix<edk::float32,4u,4u>*,edk::vec3f32){}
        virtual void drawNormalPositionWithColor(edk::vec3f32,edk::color4f32){}
        virtual void drawNormalPositionWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>*,edk::vector::Matrix<edk::float32,4u,4u>*,edk::vec3f32,edk::color4f32){}
        virtual void print(){
            this->vertex->printVertex();edkEnd();
            this->uv->printUV();edkEnd();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertexWithUV;edkEnd();
        }
        edk::shape::Polygon3D::PolygonVertexWithUV operator=(edk::shape::Polygon3D::PolygonVertexWithUV vert){
            this->vertex = vert.vertex;edkEnd();
            this->vertexID = vert.vertexID;edkEnd();
            this->uv = vert.uv;edkEnd();
            this->uvID = vert.uvID;edkEnd();
            return vert;edkEnd();
        }
        edk::shape::UV2D* uv;
        edk::uint32 uvID;
    private:
        edk::classID classThis;
    };
    //Vertex With Normal
    class PolygonVertexWithNormal : public edk::shape::Polygon3D::PolygonVertex{
    public:
        PolygonVertexWithNormal(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,
                                edk::shape::Vector3D* normal,edk::uint32 normalID
                                )
            :edk::shape::Polygon3D::PolygonVertex(vertex,vertexID)
        {
            this->classThis=NULL;edkEnd();
            this->Constructor(vertex,vertexID,normal,normalID,false);edkEnd();
        }
        virtual ~PolygonVertexWithNormal(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,
                         edk::shape::Vector3D* normal,edk::uint32 normalID,
                         bool runFather=true){
            if(runFather){
                edk::shape::Polygon3D::PolygonVertex::Constructor(vertex,vertexID);edkEnd();
            }
            if(this->classThis!=this){
                this->classThis=this;
                this->normal = normal;edkEnd();
                this->normalID = normalID;edkEnd();
            }
        }

        virtual void draw(){
            this->normal->drawNormal();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->normal->drawNormalWithMatrix(matrix,matrixTemp);edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            normal.drawNormal();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithMatrixWithNormal(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Vector3D normal){
            if(matrix){
                normal.drawNormalWithMatrix(matrix,matrixTemp);edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawWithoutNormal(){
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithoutNormalWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawNormal(){
            this->vertex->drawVertex();edkEnd();
            this->normal->drawVertexPosition(edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));edkEnd();
        }
        virtual void drawNormalWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
                this->normal->drawVertexPositionWithMatrix(matrix,matrixTemp,edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));edkEnd();
            }
        }
        virtual void drawNormalWithColor(edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);edkEnd();
            this->normal->drawVertexPosition(edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));edkEnd();
        }
        virtual void drawNormalWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color){
            if(matrix){
                this->vertex->drawVertexWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
                this->normal->drawVertexPositionWithMatrix(matrix,matrixTemp,edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));edkEnd();
            }
        }
        virtual void drawNormalPosition(edk::vec3f32 position){
            this->vertex->drawVertex();edkEnd();
            this->vertex->drawVertexPosition(position);edkEnd();
        }
        virtual void drawNormalPositionWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::vec3f32 position){
            if(matrix){
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
                this->vertex->drawVertexPositionWithMatrix(matrix,matrixTemp,position);edkEnd();
            }
        }
        virtual void drawNormalPositionWithColor(edk::vec3f32 position,edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);edkEnd();
            this->vertex->drawVertexPosition(position);edkEnd();
        }
        virtual void drawNormalPositionWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::vec3f32 position,edk::color4f32 color){
            if(matrix){
                this->vertex->drawVertexWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
                this->vertex->drawVertexPositionWithMatrix(matrix,matrixTemp,position);edkEnd();
            }
        }
        virtual void print(){
            this->vertex->printVertex();edkEnd();
            this->normal->printNormal();edkEnd();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertexWithNormal;edkEnd();
        }
        edk::shape::Polygon3D::PolygonVertexWithNormal operator=(edk::shape::Polygon3D::PolygonVertexWithNormal vert){
            this->vertex = vert.vertex;edkEnd();
            this->vertexID = vert.vertexID;edkEnd();
            this->normal = vert.normal;edkEnd();
            this->normalID = vert.normalID;edkEnd();
            return vert;edkEnd();
        }
        edk::shape::Vector3D* normal;
        edk::uint32 normalID;
    private:
        edk::classID classThis;
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
            this->classThis=NULL;edkEnd();
            this->Constructor(vertex,vertexID,
                              uv,uvID,
                              normal,normalID,
                              false);edkEnd();
        }
        virtual ~PolygonVertexWithUVNormal(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(edk::shape::Vertex3D* vertex,edk::uint32 vertexID,
                         edk::shape::UV2D* uv,edk::uint32 uvID,
                         edk::shape::Vector3D* normal,edk::uint32 normalID
                         ,bool runFather=true){
            if(runFather){
                edk::shape::Polygon3D::PolygonVertexWithNormal::Constructor(vertex,vertexID,normal,normalID);edkEnd();
            }
            if(this->classThis!=this){
                this->classThis=this;
                this->uv = uv;edkEnd();
                this->uvID = uvID;edkEnd();
            }
        }

        virtual void draw(){
            this->uv->drawUV();edkEnd();
            this->normal->drawNormal();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->uv->drawUV();edkEnd();
                this->normal->drawNormalWithMatrix(matrix,matrixTemp);edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawWithNormal(edk::shape::Vector3D normal){
            this->uv->drawUV();edkEnd();
            normal.drawNormal();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithMatrixWithNormal(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Vector3D normal){
            if(matrix){
                this->uv->drawUV();edkEnd();
                normal.drawNormalWithMatrix(matrix,matrixTemp);edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawWithoutNormal(){
            this->uv->drawUV();edkEnd();
            this->vertex->drawVertex();edkEnd();
        }
        virtual void drawWithoutNormalWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->uv->drawUV();edkEnd();
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
            }
        }
        virtual void drawNormal(){
            this->vertex->drawVertex();edkEnd();
            this->normal->drawVertexPosition(edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));edkEnd();
        }
        virtual void drawNormalWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->vertex->drawVertexWithMatrix(matrix,matrixTemp);edkEnd();
                this->normal->drawVertexPositionWithMatrix(matrix,matrixTemp,edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));edkEnd();
            }
        }
        virtual void drawNormalWithColor(edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);edkEnd();
            this->normal->drawVertexPosition(edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));edkEnd();
        }
        virtual void drawNormalWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color){
            if(matrix){
                this->vertex->drawVertexWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
                this->normal->drawVertexPositionWithMatrix(matrix,matrixTemp,edk::vec3f32(this->vertex->x,this->vertex->y,this->vertex->z));edkEnd();
            }
        }
        virtual void drawNormalPosition(edk::vec3f32 position){
            this->vertex->drawVertex();edkEnd();
            this->vertex->drawVertexPosition(position);edkEnd();
        }
        virtual void drawNormalPositionWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::vec3f32 position){
            if(matrix){
                this->vertex->drawVertexWithMatrix(matrixTemp,matrixTemp);edkEnd();
                this->vertex->drawVertexPositionWithMatrix(matrix,matrixTemp,position);edkEnd();
            }
        }
        virtual void drawNormalPositionWithColor(edk::vec3f32 position,edk::color4f32 color){
            this->vertex->drawVertexWithColor(color);edkEnd();
            this->vertex->drawVertexPosition(position);edkEnd();
        }
        virtual void drawNormalPositionWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::vec3f32 position,edk::color4f32 color){
            if(matrix){
            }
            this->vertex->drawVertexWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
            this->vertex->drawVertexPositionWithMatrix(matrix,matrixTemp,position);edkEnd();
        }
        virtual void print(){
            this->vertex->printVertex();edkEnd();
            this->normal->printNormal();edkEnd();
            this->uv->printUV();edkEnd();
        }
        virtual edk::shape::Polygon3D::VertexType getType(){
            return edk::shape::Polygon3D::typeVertexWithUVNormal;edkEnd();
        }
        edk::shape::Polygon3D::PolygonVertexWithUVNormal operator=(edk::shape::Polygon3D::PolygonVertexWithUVNormal vert){
            this->vertex = vert.vertex;edkEnd();
            this->vertexID = vert.vertexID;edkEnd();
            this->uv = vert.uv;edkEnd();
            this->uvID = vert.uvID;edkEnd();
            this->normal = vert.normal;edkEnd();
            this->normalID = vert.normalID;edkEnd();
            return vert;edkEnd();
        }
        edk::shape::UV2D* uv;
        edk::uint32 uvID;
    private:
        edk::classID classThis;
    };
    edk::shape::Polygon3D operator=(edk::shape::Polygon3D list){
        return list;edkEnd();
    }
private:
    edk::classID classThis;
};

}//end namespace shape
}//end namespace edk


#endif // POLYGON3D_H

