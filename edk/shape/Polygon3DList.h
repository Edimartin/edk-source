#ifndef EDK_SHAPE_POLYGON3DLIST_H
#define EDK_SHAPE_POLYGON3DLIST_H

/*
Library Polygon3DList - Manage 3D Polygons in EDK Game Engine
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
#pragma message "Inside Polygon3DList"
#endif

#pragma once
#include "Polygon3D.h"
#include "../vector/Stack.h"
#include "Polygon3D.h"
#include "Cube3D.h"
#include "Circle3D.h"
#include "Lines3D.h"
#include "../material/Material.h"
//Animation
#include "../animation/Interpolation3DGroup.h"

#ifdef printMessages
#pragma message "    Compiling Polygon3DList"
#endif

namespace edk{
namespace shape{
class Polygon3DList{
public:
    Polygon3DList();
    virtual ~Polygon3DList();

    void Constructor();
    void Destructor();

    //Set polygons color
    bool setPolygonsColor(edk::color4f32 color);
    bool setPolygonsColor(edk::color3f32 color);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    bool setPolygonsColorR(edk::float32 r);
    bool setPolygonsColorG(edk::float32 g);
    bool setPolygonsColorB(edk::float32 b);
    bool setPolygonsColorA(edk::float32 a);
    //set polygons smooth
    bool setPolygonsSmooth(bool smooth);
    bool setPolygonsSmoothOn();
    bool setPolygonsSmoothOff();
    //update polygons normals
    bool updatePolygonsNormals();

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
    bool calculateBoundingBox(edk::cubef32* rectangle,edk::vector::Matrixf32<4u,4u>* transformMat);
    edk::cubef32 generateBoundingBox(edk::vector::Matrixf32<4u,4u>* transformMat);
    bool calculateBoundingPoint(edk::vec3f32 point,edk::vec3f32* dest,edk::vector::Matrixf32<4u,4u>* transformMat);
    edk::vec3f32 generateBoundingPoint(edk::vec3f32 point,edk::vector::Matrixf32<4u,4u>* transformMat);
    //function to calculate boundingBox from polygon positions
    bool calculateBoundingBoxFromPolygons(edk::cubef32* rectangle,
                                          edk::vector::Matrixf32<4u,4u>* transformMat,
                                          edk::uint32 lenght,
                                          edk::uint32* positions
                                          );
    edk::cubef32 generateBoundingBoxFromPolygons(edk::vector::Matrixf32<4u,4u>* transformMat,
                                                 edk::uint32 lenght,
                                                 edk::uint32* positions
                                                 );
    bool getWorldPolygon(edk::shape::Polygon3D* dest,edk::uint32 polygonPosition,edk::vector::Matrixf32<4u,4u>* transformMat);

    //generate world polygons from list into another list
    bool generateWorldPolygons(edk::shape::Polygon3DList* dest,
                               edk::vector::Matrixf32<4u,4u>* transformMat
                               );
    bool generateWorldPolygons(edk::shape::Polygon3DList* dest,
                               edk::vector::Matrixf32<4u,4u>* transformMat,
                               edk::uint32 lenght,
                               edk::uint32* positions
                               );

    //ADD
    //add a polygon to the mesh
    virtual edk::uint32 addPolygon(edk::shape::Polygon3D polygon);
    //GETERS
    //return the polygonSize
    edk::uint32 getPolygonSize();
    //return true if have a polygon selected
    bool haveSelected();

    //test if have a polygon in a position
    bool havePolygon(edk::uint32 position);
    //get the polygon in a position
    edk::shape::Polygon3D getPolygon(edk::uint32 position);
    bool getPolygon(edk::uint32 position,edk::shape::Polygon3D* dest);

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
    bool selectedSetVertexPosition(edk::uint32 vertex,edk::vec3f32 position);
    bool selectedSetVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y,edk::float32 z);
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
    bool selectedSetTranslate(edk::vec3f32 translate);
    bool selectedSetTranslate(edk::float32 translate);
    bool selectedSetTranslate(edk::float32 x,edk::float32 y,edk::float32 z);
    bool selectedSetScale(edk::size3f32 scale);
    bool selectedSetScale(edk::float32 scale);
    bool selectedSetScale(edk::float32 width,edk::float32 height,edk::float32 length);
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
    edk::vec3f32 selectedGetVertexPosition(edk::uint32 pos);
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
    edk::vec3f32 selectedGetTranslate();
    //get scale
    edk::size3f32 selectedGetScale();
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

    //VBO
    void setUseVBO(bool use);
    void useVBO();
    void dontUseVBO();
    //convert the mesh to the VBO
    bool generateVBO();
    bool generateVBOWire();

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::shape::Polygon3DList* list);


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
    //draw the polygons normals
    virtual void drawNormals();
    virtual void drawNormalsWithColor(edk::color3f32 color = edk::color3f32(1,1,1));
    //draw the polygons in wireframe in world points
    virtual void drawWirePolygonsWorld();
    virtual bool drawWirePolygonWorld(edk::uint32 polygon);
    virtual void drawVertexsWorld(edk::color3f32 color = edk::color3f32(1,1,1));
    virtual bool drawPolygonVertexsWorld(edk::uint32 polygon,edk::color3f32 color = edk::color3f32(1,1,1));

    //draw the mesh with matrix
    virtual void drawPolygonsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp);
    virtual bool drawPolygonWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::uint32 polygon);
    //draw the polygons in wireframe with matrix
    virtual void drawWirePolygonsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp);
    virtual bool drawWirePolygonWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::uint32 polygon);
    virtual void drawVertexsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::color3f32 color = edk::color3f32(1,1,1));
    virtual bool drawPolygonVertexsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::uint32 polygon,edk::color3f32 color = edk::color3f32(1,1,1));
    //draw the polygons in wireframe in world points with matrix
    virtual void drawWirePolygonsWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp);
    virtual bool drawWirePolygonWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::uint32 polygon);
    virtual void drawVertexsWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::color3f32 color = edk::color3f32(1,1,1));
    virtual bool drawPolygonVertexsWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::uint32 polygon,edk::color3f32 color = edk::color3f32(1,1,1));

    //VBO
    virtual void drawVBOPolygons();
    virtual void drawVBOWirePolygons();

protected:
    edk::vector::Array<edk::shape::Vertex3D*> vertexs;
    edk::vector::Array<edk::shape::Vertex3D*> vertexsWire;
    edk::vector::Array<edk::shape::Vertex3D*> vertexsWithMatrix;
    //VBO
    edk::uint32 vbo;
    edk::uint32 vboWithMatrix;
    edk::uint32 vboWire;
    edk::GU::VBOType vboType;
    edk::GU::VBOType vboWithMatrixType;
    edk::GU::VBOType vboWireType;
    //array for the vbo
    edk::vector::Array<edk::float32> vertexBuffer;
    edk::vector::Array<edk::float32> vertexBufferWithMatrix;
    edk::vector::Array<edk::float32> vertexBufferWire;
    //vbo vertexes size
    edk::uint32 vboCount;
    edk::uint32 vboWireCount;
    edk::uint32 vboWithMatrixCount;
    //save if can use VBO in the polygon
    bool canUseVBO;

    //return the vertexCount
    edk::uint32 getVertexCount();
    void cleanVertexes();
    edk::uint32 getVertexCountWithMatrix();
    void cleanVertexesWithMatrix();
    edk::uint32 getVertexCountWire();
    void cleanVertexesWire();
    //function to create the VBO
    virtual bool createVBO(edk::uint32 vertexCount,edk::GU::VBOType type);
    virtual bool createVBOWithMatrix(edk::uint32 vertexCount,edk::GU::VBOType type);
    virtual bool createVBOWire(edk::uint32 vertexCount,edk::GU::VBOType type);
    //run the GU function to update the VBO
    bool updateVBO();
    bool updateVBOWithMatrix();
    bool updateVBOValuesWithMatrices(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp);
    bool updateVBOWire();
    //change the type of the VBO
    bool changeVBO(edk::GU::VBOType type);
    bool changeVBOWithMatrix(edk::GU::VBOType type);
    bool changeVBOWire(edk::GU::VBOType type);
    void deleteVBO();
    void deleteVBOWithMatrix();
    void deleteVBOWire();
    bool haveVBO();
    bool haveVBOWithMatrix();
    bool haveVBOWire();
    //set the vboFunction pointers
    bool updateVBOFunctions();
    bool updateVBOFunctionsWithMatrix();
    bool updateVBOWireFunctions();
    bool setAutomaticallyVBOFunctions();
    bool setAutomaticallyVBOFunctionsWithMatrix();
    bool setAutomaticallyVBOWireFunctions();
    void setVBOFunctionUpdateNULL();
    void setVBOWithMatrixFunctionUpdateNULL();
    void setVBOWireFunctionUpdateNULL();
    void setVBOFunctionNULL();
    void setVBOWithMatrixFunctionNULL();
    void setVBOWireFunctionNULL();
    //setters to VBO
    virtual bool setVBOVertexPosition(edk::uint32 vertex,edk::vec3f32 position);
    virtual bool setVBOVertexPositionX(edk::uint32 vertex,edk::float32 x);
    virtual bool setVBOVertexPositionY(edk::uint32 vertex,edk::float32 y);
    virtual bool setVBOVertexPositionZ(edk::uint32 vertex,edk::float32 z);
    virtual bool setVBOVertexNormal(edk::uint32 vertex,edk::vec3f32 normal);
    virtual bool setVBOVertexNormalX(edk::uint32 vertex,edk::float32 x);
    virtual bool setVBOVertexNormalY(edk::uint32 vertex,edk::float32 y);
    virtual bool setVBOVertexNormalZ(edk::uint32 vertex,edk::float32 z);
    virtual bool setVBOVertexColor(edk::uint32 vertex,edk::color4f32 color);
    virtual bool setVBOPolygonColor(edk::color4f32 color);
    virtual bool setVBOPolygonNormal(edk::vec3f32 normal);
    virtual bool setVBOPolygonColorR(edk::float32 r);
    virtual bool setVBOPolygonColorG(edk::float32 g);
    virtual bool setVBOPolygonColorB(edk::float32 b);
    virtual bool setVBOPolygonColorA(edk::float32 a);
    virtual bool setVBOVertexUV(edk::uint32 vertex,edk::vec2f32 uv);
    virtual bool setVBOVertexU(edk::uint32 vertex,edk::float32 u);
    virtual bool setVBOVertexV(edk::uint32 vertex,edk::float32 v);
    //With Matrix
    virtual bool setVBOVertexPositionWithMatrix(edk::uint32 vertex,edk::vec3f32 position);
    virtual bool setVBOVertexPositionXWithMatrix(edk::uint32 vertex,edk::float32 x);
    virtual bool setVBOVertexPositionYWithMatrix(edk::uint32 vertex,edk::float32 y);
    virtual bool setVBOVertexPositionZWithMatrix(edk::uint32 vertex,edk::float32 z);
    virtual bool setVBOVertexNormalWithMatrix(edk::uint32 vertex,edk::vec3f32 normal);
    virtual bool setVBOVertexNormalXWithMatrix(edk::uint32 vertex,edk::float32 x);
    virtual bool setVBOVertexNormalYWithMatrix(edk::uint32 vertex,edk::float32 y);
    virtual bool setVBOVertexNormalZWithMatrix(edk::uint32 vertex,edk::float32 z);
    virtual bool setVBOVertexColorWithMatrix(edk::uint32 vertex,edk::color4f32 color);
    virtual bool setVBOPolygonColorWithMatrix(edk::color4f32 color);
    virtual bool setVBOPolygonNormalWithMatrix(edk::vec3f32 normal);
    virtual bool setVBOPolygonColorRWithMatrix(edk::float32 r);
    virtual bool setVBOPolygonColorGWithMatrix(edk::float32 g);
    virtual bool setVBOPolygonColorBWithMatrix(edk::float32 b);
    virtual bool setVBOPolygonColorAWithMatrix(edk::float32 a);
    virtual bool setVBOVertexUVWithMatrix(edk::uint32 vertex,edk::vec2f32 uv);
    virtual bool setVBOVertexUWithMatrix(edk::uint32 vertex,edk::float32 u);
    virtual bool setVBOVertexVWithMatrix(edk::uint32 vertex,edk::float32 v);
    //updafe the UV into the VBO
    virtual bool updateVBOUV();
    virtual bool updateVBOUVWithMatrix();
    virtual bool updateVBOWireValues();
    virtual bool updateVBOValues();
    virtual bool updateVBOValuesWithMatrices();
    //print the VBO
    virtual bool printVBO();

    //function pointers
    //PRINT
    void (edk::shape::Polygon3DList::*vboPrint)();
    //DRAW
    void (edk::shape::Polygon3DList::*vboDraw)(edk::uint32);
    void (edk::shape::Polygon3DList::*vboDrawWithMatrix)(edk::uint32);
    //DRAW WIRE
    void (edk::shape::Polygon3DList::*vboDrawWire)(edk::uint32);

    //draw functions
    //PRINT
    void print_NULL();
    void print_XY();
    void print_XYZ();
    void print_XY_NxNyNz();
    void print_XYZ_NxNyNz();
    void print_XY_RGB();
    void print_XYZ_RGB();
    void print_XY_RGBA();
    void print_XYZ_RGBA();
    void print_XY_RGB_NxNyNz();
    void print_XYZ_RGB_NxNyNz();
    void print_XY_RGBA_NxNyNz();
    void print_XYZ_RGBA_NxNyNz();
    void print_XY_RGB_NxNyNz_UVxUVy();
    void print_XYZ_RGB_NxNyNz_UVxUVy();
    void print_XY_RGBA_NxNyNz_UVxUVy();
    void print_XYZ_RGBA_NxNyNz_UVxUVy();
    //DRAW
    virtual void draw_NULL(edk::uint32 mode);
    void draw_XY(edk::uint32 mode);
    void draw_XYZ(edk::uint32 mode);
    void draw_XY_NxNyNz(edk::uint32 mode);
    void draw_XYZ_NxNyNz(edk::uint32 mode);
    void draw_XY_RGB(edk::uint32 mode);
    void draw_XYZ_RGB(edk::uint32 mode);
    void draw_XY_RGBA(edk::uint32 mode);
    void draw_XYZ_RGBA(edk::uint32 mode);
    void draw_XY_RGB_NxNyNz(edk::uint32 mode);
    void draw_XYZ_RGB_NxNyNz(edk::uint32 mode);
    void draw_XY_RGBA_NxNyNz(edk::uint32 mode);
    void draw_XYZ_RGBA_NxNyNz(edk::uint32 mode);
    void draw_XY_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void draw_XYZ_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void draw_XY_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    void draw_XYZ_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    //DRAW UPDATE
    virtual void drawUpdate_NULL(edk::uint32 mode);
    void drawUpdate_XY(edk::uint32 mode);
    void drawUpdate_XYZ(edk::uint32 mode);
    void drawUpdate_XY_NxNyNz(edk::uint32 mode);
    void drawUpdate_XYZ_NxNyNz(edk::uint32 mode);
    void drawUpdate_XY_RGB(edk::uint32 mode);
    void drawUpdate_XYZ_RGB(edk::uint32 mode);
    void drawUpdate_XY_RGBA(edk::uint32 mode);
    void drawUpdate_XYZ_RGBA(edk::uint32 mode);
    void drawUpdate_XY_RGB_NxNyNz(edk::uint32 mode);
    void drawUpdate_XYZ_RGB_NxNyNz(edk::uint32 mode);
    void drawUpdate_XY_RGBA_NxNyNz(edk::uint32 mode);
    void drawUpdate_XYZ_RGBA_NxNyNz(edk::uint32 mode);
    void drawUpdate_XY_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawUpdate_XYZ_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawUpdate_XY_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawUpdate_XYZ_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    //DRAW WITH MATRIX
    virtual void drawWithMatrix_NULL(edk::uint32 mode);
    void drawWithMatrix_XY(edk::uint32 mode);
    void drawWithMatrix_XYZ(edk::uint32 mode);
    void drawWithMatrix_XY_NxNyNz(edk::uint32 mode);
    void drawWithMatrix_XYZ_NxNyNz(edk::uint32 mode);
    void drawWithMatrix_XY_RGB(edk::uint32 mode);
    void drawWithMatrix_XYZ_RGB(edk::uint32 mode);
    void drawWithMatrix_XY_RGBA(edk::uint32 mode);
    void drawWithMatrix_XYZ_RGBA(edk::uint32 mode);
    void drawWithMatrix_XY_RGB_NxNyNz(edk::uint32 mode);
    void drawWithMatrix_XYZ_RGB_NxNyNz(edk::uint32 mode);
    void drawWithMatrix_XY_RGBA_NxNyNz(edk::uint32 mode);
    void drawWithMatrix_XYZ_RGBA_NxNyNz(edk::uint32 mode);
    void drawWithMatrix_XY_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWithMatrix_XYZ_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWithMatrix_XY_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWithMatrix_XYZ_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    //DRAW UPDATE WITH MATRIX
    virtual void drawUpdateWithMatrix_NULL(edk::uint32 mode);
    void drawUpdateWithMatrix_XY(edk::uint32 mode);
    void drawUpdateWithMatrix_XYZ(edk::uint32 mode);
    void drawUpdateWithMatrix_XY_NxNyNz(edk::uint32 mode);
    void drawUpdateWithMatrix_XYZ_NxNyNz(edk::uint32 mode);
    void drawUpdateWithMatrix_XY_RGB(edk::uint32 mode);
    void drawUpdateWithMatrix_XYZ_RGB(edk::uint32 mode);
    void drawUpdateWithMatrix_XY_RGBA(edk::uint32 mode);
    void drawUpdateWithMatrix_XYZ_RGBA(edk::uint32 mode);
    void drawUpdateWithMatrix_XY_RGB_NxNyNz(edk::uint32 mode);
    void drawUpdateWithMatrix_XYZ_RGB_NxNyNz(edk::uint32 mode);
    void drawUpdateWithMatrix_XY_RGBA_NxNyNz(edk::uint32 mode);
    void drawUpdateWithMatrix_XYZ_RGBA_NxNyNz(edk::uint32 mode);
    void drawUpdateWithMatrix_XY_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawUpdateWithMatrix_XYZ_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawUpdateWithMatrix_XY_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawUpdateWithMatrix_XYZ_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    //DRAWWire
    virtual void drawWire_NULL(edk::uint32 mode);
    void drawWire_XY(edk::uint32 mode);
    void drawWire_XYZ(edk::uint32 mode);
    void drawWire_XY_NxNyNz(edk::uint32 mode);
    void drawWire_XYZ_NxNyNz(edk::uint32 mode);
    void drawWire_XY_RGB(edk::uint32 mode);
    void drawWire_XYZ_RGB(edk::uint32 mode);
    void drawWire_XY_RGBA(edk::uint32 mode);
    void drawWire_XYZ_RGBA(edk::uint32 mode);
    void drawWire_XY_RGB_NxNyNz(edk::uint32 mode);
    void drawWire_XYZ_RGB_NxNyNz(edk::uint32 mode);
    void drawWire_XY_RGBA_NxNyNz(edk::uint32 mode);
    void drawWire_XYZ_RGBA_NxNyNz(edk::uint32 mode);
    void drawWire_XY_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWire_XYZ_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWire_XY_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWire_XYZ_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    //DRAWWire UPDATE
    virtual void drawWireUpdate_NULL(edk::uint32 mode);
    void drawWireUpdate_XY(edk::uint32 mode);
    void drawWireUpdate_XYZ(edk::uint32 mode);
    void drawWireUpdate_XY_NxNyNz(edk::uint32 mode);
    void drawWireUpdate_XYZ_NxNyNz(edk::uint32 mode);
    void drawWireUpdate_XY_RGB(edk::uint32 mode);
    void drawWireUpdate_XYZ_RGB(edk::uint32 mode);
    void drawWireUpdate_XY_RGBA(edk::uint32 mode);
    void drawWireUpdate_XYZ_RGBA(edk::uint32 mode);
    void drawWireUpdate_XY_RGB_NxNyNz(edk::uint32 mode);
    void drawWireUpdate_XYZ_RGB_NxNyNz(edk::uint32 mode);
    void drawWireUpdate_XY_RGBA_NxNyNz(edk::uint32 mode);
    void drawWireUpdate_XYZ_RGBA_NxNyNz(edk::uint32 mode);
    void drawWireUpdate_XY_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWireUpdate_XYZ_RGB_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWireUpdate_XY_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);
    void drawWireUpdate_XYZ_RGBA_NxNyNz_UVxUVy(edk::uint32 mode);

    //list of polygons
    class StackPolygons3D: public edk::vector::Stack<edk::shape::Polygon3D*> {
    public:
        StackPolygons3D(){
            this->setMatrices(NULL,NULL);
        }
        ~StackPolygons3D(){}
        void drawElement(edk::shape::Polygon3D* value){
            value->drawWithMatrix(this->matrix,this->matrixTemp);
        }
        bool draw(){
            return edk::vector::Stack<edk::shape::Polygon3D*>::draw();
        }
        bool setMatrices(edk::vector::Matrixf32<4u,4u>* matrix,
                         edk::vector::Matrixf32<4u,4u>* matrixTemp
                         ){
            if(this->matrix&& this->matrixTemp){
                this->matrix=matrix;
                this->matrixTemp=matrixTemp;
                return true;
            }
            this->matrix=NULL;this->matrixTemp=NULL;
            return false;
        }
        edk::shape::Polygon3D* getPolygon(edk::uint32 position){
            return this->get(position);
        }
    private:
        edk::vector::Matrixf32<4u,4u>* matrix;
        edk::vector::Matrixf32<4u,4u>* matrixTemp;
    }polygons;
    edk::shape::Cube3D tempP;
    //mesh selected
    edk::shape::Polygon3D* selected;
private:
    static edk::material::Material whiteMaterial;

    //Operator
    edk::shape::Polygon3DList operator=(edk::shape::Polygon3DList list){
        //delete the polygons
        this->cleanPolygons();
        //read the polygons
#if defined(edkCPPversion17)
        edk::uint32 size = list.polygons.size();
#else
        register edk::uint32 size = list.polygons.size();
#endif
        edk::uint32 select=0u;
        edk::shape::Polygon3D* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp=list.polygons.get(i);
            if(temp){
                if(temp==list.selected){
                    select=i;
                }
                this->addPolygon(*temp);
            }
        }
        this->selectPolygon(select);
        return list;
    }
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // POLYGON3DLIST_H
