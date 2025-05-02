#ifndef EDK_SHAPE_POLYGON3D_H
#define EDK_SHAPE_POLYGON3D_H

/*
Library Polygon3D - Draw a 3D Polygon in EDK Game Engine
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
#pragma message "Inside Polygon3D"
#endif

//Include EDK
#pragma once
#include "Polygon2D.h"
#include "Vertex3D.h"
#include "../TypeCube.h"
#include "../vector/Array.h"
#include "../animation/Interpolation1DGroup.h"
#include "../vector/Matrix.h"
#include "../Math.h"
#include "../xml/XML.h"
#include "../light/Light.h"

#ifdef printMessages
#pragma message "    Compiling Polygon3D"
#endif

//█■█■█■█■█■█■█■█■█■█■█■█■█■█■█■█

namespace edk{
namespace shape{

//minimum vertex countin the polygon. 2 vertex is one line
#define minimumVertex 2u
//polygon type
enum EDKpolygon3DType{
    typePolygon3D = 1u,
    typeLine3D,
    typeCube3D,
    typeTriangle3D,
    typeCircle3D,
    typeQuadrangle3D,

    typePolygon3DSize
};

class Polygon3D{
public:
    Polygon3D();
    Polygon3D(edk::uint32 vertexCount);
    virtual ~Polygon3D();

    void Constructor();
    void Constructor(edk::uint32 vertexCount);
    void Destructor();

    void clean();

    //create the polygon
    virtual bool createPolygon(edk::uint32 vertexCount);
    virtual bool createPolygonMatrixOlny(edk::uint32 vertexCount);
    virtual bool createPolygonWithMatrix(edk::uint32 vertexCount);

    //test if the polygon is Counterclockwise
    bool isCounterclockwise();

    //invert the sense
    bool invertVertexSense();
    bool changeVertexSense(bool counterClockWise);
    bool setClockWise();
    bool setCounterClockWise();

    //VBO
    void setUseVBO(bool use);
    void useVBO();
    void dontUseVBO();

    //SETTERS
    bool cloneVertexFrom(edk::uint32 vertex,edk::shape::Vertex3D* vert);
    //set the position of a vertex
    bool setVertexPosition(edk::uint32 vertex,edk::vec3f32 position);
    bool setVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y,edk::float32 z);
    //set the color of a vertex
    bool setVertexColor(edk::uint32 vertex,edk::color4f32 color);
    bool setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b);
    bool setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    //Set polygon color
    bool setPolygonColor(edk::color4f32 color);
    bool setPolygonColor(edk::color3f32 color);
    bool setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b);
    bool setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    bool setPolygonColorR(edk::float32 r);
    bool setPolygonColorG(edk::float32 g);
    bool setPolygonColorB(edk::float32 b);
    bool setPolygonColorA(edk::float32 a);
    //set the UVMap of the vertex
    bool setVertexUV(edk::uint32 vertex,edk::vec2f32 uv);
    bool setVertexUV(edk::uint32 vertex,edk::float32 x,edk::float32 y);
    //Set the polygonFrames setting in the vertexs
    bool setPolygonUVFrames(edk::vec2ui32 frames);
    bool setPolygonUVFrames(edk::uint32 x,edk::uint32 y);
    bool setPolygonUVFramesX(edk::uint32 x);
    bool setPolygonUVFramesY(edk::uint32 y);
    //Set the polygon frame
    void usePolygonUVFrame(edk::vec2ui32 frame);
    void usePolygonUVFramePosition(edk::uint32 position);
    void usePolygonUVFrameX(edk::uint32 x);
    void usePolygonUVFrameY(edk::uint32 y);
    //Set polygon normal
    bool setVertexNormal(edk::uint32 vertex,edk::vec3f32 normal);
    bool setVertexNormal(edk::uint32 vertex,edk::float32 x,edk::float32 y,edk::float32 z);

    //Calculate the normal of the polygon
    bool updateNormal();
    void setNormalFlat(edk::shape::Vector3D normal);

    //clean the transformation
    void cleanTransform();
    //Set the position of the polygon
    void setTranslate(edk::vec3f32 translate);
    void setTranslate(edk::float32 translate);
    void setTranslate(edk::float32 x,edk::float32 y,edk::float32 z);
    //set the scale
    void setScale(edk::size3f32 scale);
    void setScale(edk::float32 scale);
    void setScale(edk::float32 width,edk::float32 height,edk::float32 length);
    //set the angle
    void setAngle(edk::float32 angle);
    //set physics
    void setDensity(edk::float32 density);
    void setFriction(edk::float32 friction);
    void setRestitution(edk::float32 restitution);

    //function to calculate boundingBox
    bool calculateBoundingBox(edk::cubef32* cube,edk::vector::Matrixf32<4u,4u>* transformMat);
    edk::cubef32 generateBoundingBox(edk::vector::Matrixf32<4u,4u>* transformMat);
    bool calculateBoundingPoint(edk::vec3f32* point,edk::vector::Matrixf32<4u,4u>* transformMat);
    edk::vec3f32 generateBoundingPoint(edk::vector::Matrixf32<4u,4u>* transformMat);
    bool getWorldPolygonClone(edk::shape::Polygon3D* dest,edk::vector::Matrixf32<4u,4u>* transformMat);
    bool getWorldPolygonCopy(edk::shape::Polygon3D* dest,edk::vector::Matrixf32<4u,4u>* transformMat);

    //delete the polygonVertex
    virtual void deletePolygon();
    //remove the UV of one vertex
    bool removeVertexUV(edk::uint32 vertex);
    //remove the UV from the polygon
    void removePolygonUV();
    //clean the UV animation in polygons
    void cleanPolygonUVAnimation();

    //ANIMATION
    //create a new animationFrames
    bool framesCreateAnimation();
    //set one animation to the polygon
    bool framesSetAnimation(edk::animation::Interpolation1DGroup* anim);
    //return the animationPointer
    edk::animation::Interpolation1DGroup* framesGetAnimation();
    //remove the animationGroup
    void framesRemoveAnimation();
    //return true if have an animation
    bool framesHaveAnimation();
    //return true if this polygon create the animation
    bool framesIsAnimationCreator();
    /*
        //Animation Controls
        bool framesPlayForward();
        bool framesPlayForwardIn(edk::float32 second);
        bool framesPlayRewind();
        bool framesPlayRewindIn(edk::float32 second);
        bool framesPause();
        bool framesStop();
        bool framesSetLoop(bool loop);
        bool framesLoopOn();
        bool framesLoopOff();
        //AnimationNames
        */

    //GETERS
    //return the vertexCount
    edk::uint32 getVertexCount();
    //return if the vertex have UV
    edk::uint8 getVertexType(edk::uint32 pos);
    //return the vertex
    edk::shape::Vertex3D* getVertexPointerInPosition(edk::uint32 pos);
    //return the vertex position
    edk::vec3f32 getVertexPosition(edk::uint32 pos);
    //return the vertex with all transformations
    edk::vec3f32 getVertexPositionTransformed(edk::uint32 pos);
    //return the vertex color
    edk::color4f32 getVertexColor(edk::uint32 pos);
    //return the vertex normal
    edk::vec3f32 getVertexNormal(edk::uint32 pos);
    //return the vertex UV
    edk::vec2f32 getVertexUV(edk::uint32 pos);
    //return the frames
    edk::vec2ui32 getFrames();
    edk::uint32 getFramesPosition();
    //return the frameUseds
    edk::vec2ui32 getFrameUsed();
    edk::uint32 getFramePositionUsed();
    //return the morphCount
    edk::uint32 getMorphCount();

    //return the transform
    edk::vec3f32 getTranslate();
    virtual edk::size3f32 getScale();
    virtual edk::float32 getAngle();
    //return true if is transforming
    bool isTransforming();
    //get Physics
    edk::float32 getDensity();
    edk::float32 getFriction();
    edk::float32 getRestitution();

    //return true if the polygon is a circle
    virtual bool isCircle();
    //return the circleRadius only if is a circle
    edk::float32 getCircleRadius();
    //return true if it's a Rectangle
    virtual bool isRect();
    //return true if it's lines
    virtual bool isLine();
    //get line ID
    edk::uint8 getCollisionID();

    //functions for the vertexes animations
    virtual edk::uint32 newPolygonMorph(edk::float32 percent,bool* success=&edk::shape::Polygon3D::successTemplate);
    virtual bool havePolygonMorph(edk::uint32 positionMorph);
    virtual bool deletePolygonMorph(edk::uint32 positionMorph);
    virtual void cleanPolygonMorph();
    virtual void deleteAllPolygonMorph();
    virtual edk::uint32 getPolygonMorphSize();
    //morph setters
    //set the position of a vertex
    bool setPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 vertex,edk::vec3f32 position);
    bool setPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 x,edk::float32 y,edk::float32 z);
    //set the color of a vertex
    bool setPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 vertex,edk::color4f32 color);
    bool setPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b);
    bool setPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    //Set polygon color
    bool setPolygonMorphColor(edk::uint32 positionMorph,edk::color4f32 color);
    bool setPolygonMorphColor(edk::uint32 positionMorph,edk::color3f32 color);
    bool setPolygonMorphColor(edk::uint32 positionMorph,edk::float32 r,edk::float32 g,edk::float32 b);
    bool setPolygonMorphColor(edk::uint32 positionMorph,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    bool setPolygonMorphColorR(edk::uint32 positionMorph,edk::float32 r);
    bool setPolygonMorphColorG(edk::uint32 positionMorph,edk::float32 g);
    bool setPolygonMorphColorB(edk::uint32 positionMorph,edk::float32 b);
    bool setPolygonMorphColorA(edk::uint32 positionMorph,edk::float32 a);
    //set the UVMap of the vertex
    bool setPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 vertex,edk::vec2f32 uv);
    bool setPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 x,edk::float32 y);
    //Set the polygonFrames setting in the vertexs
    bool setPolygonMorphUVFrames(edk::uint32 positionMorph,edk::vec2ui32 frames);
    bool setPolygonMorphUVFrames(edk::uint32 positionMorph,edk::uint32 x,edk::uint32 y);
    bool setPolygonMorphUVFramesX(edk::uint32 positionMorph,edk::uint32 x);
    bool setPolygonMorphUVFramesY(edk::uint32 positionMorph,edk::uint32 y);
    //Set the polygon frame
    bool usePolygonMorphUVFrame(edk::uint32 positionMorph,edk::vec2ui32 frame);
    bool usePolygonMorphUVFramePosition(edk::uint32 positionMorph,edk::uint32 position);
    bool usePolygonMorphUVFrameX(edk::uint32 positionMorph,edk::uint32 x);
    bool usePolygonMorphUVFrameY(edk::uint32 positionMorph,edk::uint32 y);
    //morph getters
    virtual edk::float32 getPolygonMorphPercent(edk::uint32 positionMorph);
    //return the vertexCount
    edk::uint32 getPolygonMorphVertexCount();
    //return if the vertex have UV
    edk::uint8 getPolygonMorphVertexType(edk::uint32 positionMorph);
    //return the vertex
    edk::vec3f32 getPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 positionVertex);
    //return the vertex with all transformations
    edk::vec3f32 getPolygonMorphVertexPositionTransformed(edk::uint32 positionMorph,edk::uint32 positionVertex);
    //return the vertex color
    edk::color4f32 getPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 positionVertex);
    //return the vertex UV
    edk::vec2f32 getPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 positionVertex);
    //return the frames
    edk::vec2ui32 getPolygonMorphFrames(edk::uint32 positionMorph);

    edk::cubef32 getCube();

    //print the polygon
    virtual void print();
    //Draw the polygon
    virtual void draw();
    //Draw the polygons with lines
    virtual void drawWire();
    //Draw the polygons with lines without using matrices
    virtual void drawWireWorld();
    //Draw the polygons with normals without using matrices
    virtual void drawNormals();
    virtual void drawNormalsWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
    //draw vertexs
    virtual void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1));
    virtual void drawPolygonVertexsWorld(edk::color4f32 color=edk::color4f32(1,1,1,1));
    //Draw the polygon with matrix
    virtual void drawWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp);
    //Draw the polygons with lines with matrix
    virtual void drawWireWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp);
    //Draw the polygons with lines without using matrices with matrix
    virtual void drawWireWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp);
    //draw vertexs with matrix
    virtual void drawPolygonVertexsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1));
    virtual void drawPolygonVertexsWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1));

    //Write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 polygonID);
    //read from XML
    bool readFromXML(edk::XML* xml,edk::uint32 polygonID);

    virtual bool cloneFrom(edk::shape::Polygon3D* poly);

    //boolean to save if the polygon is draw with smooth
    bool smooth;
protected:
    edk::vector::Array<edk::shape::Vertex3D*> vertexs;
    edk::vector::Array<edk::shape::Vertex3D*> vertexsOriginal;
    edk::vec3f32 temp;
    //normal of the polygon
    edk::shape::Vector3D normal;
    edk::shape::Vector3D center;

    //Polygon VBO
    edk::uint32 vbo;
    edk::uint32 vboWithMatrix;
    edk::GU::VBOType vboType;
    //array for the vbo
    edk::vector::Array<edk::float32> vertexBuffer;
    edk::vector::Array<edk::float32> vertexBufferWithMatrix;
    //vbo vertexes size
    edk::uint32 vboCount;
    //save if can use VBO in the polygon
    bool canUseVBO;

    //function to create the VBO
    virtual bool createVBO(edk::uint32 vertexCount,edk::GU::VBOType type);
    virtual bool createVBOWithMatrix(edk::uint32 vertexCount,edk::GU::VBOType type);
    //run the GU function to update the VBO
    bool updateVBO();
    bool updateVBOWithMatrix();
    bool updateVBOValuesWithMatrices(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp);
    //change the type of the VBO
    bool changeVBO(edk::GU::VBOType type);
    bool changeVBOWithMatrix(edk::GU::VBOType type);
    void deleteVBO();
    void deleteVBOWithMatrix();
    bool haveVBO();
    bool haveVBOWithMatrix();
    //set the vboFunction pointers
    bool updateVBOFunctions();
    bool updateVBOFunctionsWithMatrix();
    bool setAutomaticallyVBOFunctions();
    bool setAutomaticallyVBOFunctionsWithMatrix();
    void setVBOFunctionUpdateNULL();
    void setVBOFunctionNULL();
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
    virtual bool updateVBOValues();
    virtual bool updateVBOValuesWithMatrices();
    //print the VBO
    virtual bool printVBO();

    //save if don't transform the polygon
    bool transforming;
    //Color of the polygon
    edk::color4f32 polygonColor;
    //set the vertexFrames
    bool setVertexUVFrames(edk::uint32 vertex,edk::vec2ui32 frames);
    //Draw the polygon
    virtual void drawVertexs();
    virtual void drawVertexsWithColor(edk::color4f32 color);
    //Draw the normals
    virtual void drawVertexNormals();
    virtual void drawVertexNormalsWithColor(edk::color4f32 color);
    //update framesSize
    void updateFramesSize();
    //test if is tranforming the polygon
    void testTransform();

    //function pointers
    //PRINT
    void (edk::shape::Polygon3D::*vboPrint)();
    //DRAW
    void (edk::shape::Polygon3D::*vboDraw)(edk::uint32);
    void (edk::shape::Polygon3D::*vboDrawWithMatrix)(edk::uint32);

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

    //angle of the polygon
    edk::float32 angle;
    //scale the polygon
    edk::size3f32 scale;
    //polygon translation
    edk::vec3f32 translate;

    bool polygonCircle;
    edk::float32 radius;
    bool polygonLine;
    edk::uint8 collisionID;

    //Physics parameters
    edk::float32 density;
    edk::float32 friction;
    edk::float32 restitution;

    //polygon type
    edk::shape::EDKpolygon3DType type;

    //vertex morphs
    class Polygon3DMorph{
    public:
        Polygon3DMorph(edk::uint32 vertexCount,edk::color4f32 polygonColor){
            this->classThis=NULL;
            this->Constructor(vertexCount,polygonColor);
        }
        virtual ~Polygon3DMorph(){
            this->Destructor();
        }

        void Constructor(edk::uint32 vertexCount,edk::color4f32 polygonColor){
            if(this->classThis!=this){
                this->classThis=this;

                this->vertexs.Constructor();
                this->vertexsOriginal.Constructor();

                this->percent=0.f;
                this->createPolygon(vertexCount,polygonColor);
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->vertexs.deleteArray();
                this->vertexsOriginal.deleteArray();

                this->vertexs.Destructor();
                this->vertexsOriginal.Destructor();
            }
        }

        edk::vector::Array<edk::shape::Vertex3D*> vertexs;
        edk::vector::Array<edk::shape::Vertex3D*> vertexsOriginal;
        edk::float32 percent;

        //delete the polygonVertex
        void deletePolygon(){
            //remove the animation
            edk::uint32 size = this->vertexs.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                if(this->vertexs.get(i)){
                    delete this->vertexs.getNoIF(i);
                }
            }
            this->vertexs.deleteArray();
            size = this->vertexsOriginal.size();
            for(edk::uint32 i=0u;i<size;i++){
                //
                if(this->vertexsOriginal.get(i)){
                    delete this->vertexsOriginal.getNoIF(i);
                }
            }
            this->vertexsOriginal.deleteArray();

        }

        //create the polygon
        bool createPolygon(edk::uint32 vertexCount,edk::color4f32 polygonColor){
            //delete the polygon
            this->deletePolygon();
            //test the vertexCount
            if(vertexCount >= minimumVertex){
                //create the array
                if(this->vertexsOriginal.createArray(vertexCount)){
                    if(this->vertexs.createArray(vertexCount)){
                        //create all the vertexs
                        for(edk::uint32 i =0u;i<vertexCount;i++){
                            //
                            this->vertexs.set(i,new edk::shape::Vertex3D());
                            this->vertexsOriginal.set(i,new edk::shape::Vertex3D());
                            //Set alpha 1
                            if(this->vertexs.get(i)){
                                //set the vertex
                                this->vertexs.getNoIF(i)->color = polygonColor;
                            }
                            if(this->vertexsOriginal.get(i)){
                                //set the vertex
                                this->vertexsOriginal.getNoIF(i)->color = polygonColor;
                            }
                        }
                        //then return true
                        return true;
                    }
                    this->vertexsOriginal.deleteArray();
                }
            }
            return false;
        }



        //SETTERS
        //set the position of a vertex
        bool setVertexPosition(edk::uint32 vertex,edk::vec3f32 position){
            //load the polygon
            edk::shape::Vertex3D* vTemp = this->vertexsOriginal.get(vertex);
            if(vTemp){
                //then set the position of the vertex
                vTemp->position = position;
                //return true
                return true;
            }
            //else return false
            return false;
        }
        //set the color of a vertex
        bool setVertexColor(edk::uint32 vertex,edk::color4f32 color){
            //load the polygon
            edk::shape::Vertex3D* vTemp = this->vertexsOriginal.get(vertex);
            if(vTemp){
                //then set the position of the vertex
                vTemp->color = color;
                //return true
                return true;
            }
            //else return false
            return false;
        }
        //Set polygon color
        bool setPolygonColor(edk::color4f32 color){
            edk::uint32 size = this->vertexsOriginal.size();
            if(size){
                edk::shape::Vertex3D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color = color;
                        //return true
                        return true;
                    }
                }
            }
            //else return false
            return false;
        }
        bool setPolygonColor(edk::color3f32 color){
            edk::uint32 size = this->vertexsOriginal.size();
            if(size){
                edk::shape::Vertex3D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color = color;
                        //return true
                        return true;
                    }
                }
            }
            //else return false
            return false;
        }
        bool setPolygonColorR(edk::float32 r){
            edk::uint32 size = this->vertexsOriginal.size();
            if(size){
                edk::shape::Vertex3D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color.r = r;
                        //return true
                        return true;
                    }
                }
            }
            //else return false
            return false;
        }
        bool setPolygonColorG(edk::float32 g){
            edk::uint32 size = this->vertexsOriginal.size();
            if(size){
                edk::shape::Vertex3D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color.g = g;
                        //return true
                        return true;
                    }
                }
            }
            //else return false
            return false;
        }
        bool setPolygonColorB(edk::float32 b){
            edk::uint32 size = this->vertexsOriginal.size();
            if(size){
                edk::shape::Vertex3D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color.b = b;
                        //return true
                        return true;
                    }
                }
            }
            //else return false
            return false;
        }
        bool setPolygonColorA(edk::float32 a){
            edk::uint32 size = this->vertexsOriginal.size();
            if(size){
                edk::shape::Vertex3D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color.a = a;
                        //return true
                        return true;
                    }
                }
            }
            //else return false
            return false;
        }
        //set the UVMap of the vertex
        bool setVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
            //load the polygon
            edk::shape::Vertex3DWithUV* vTemp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(vertex);
            if(vTemp){
                //test what type of vertex it is
                if(vTemp->getType() == EDK_SHAPE_NOUV){
                    //then delete the vTemp and create another with UV
                    edk::shape::Vertex3DWithUV* uvTemp = new edk::shape::Vertex3DWithUV();
                    if(uvTemp){
                        //copy the vTemp content to uvTemp
                        uvTemp->position = vTemp->position;
                        uvTemp->color = vTemp->color;
                        uvTemp->normal = vTemp->normal;

                        //delete the vTemp
                        delete vTemp;
                        //set vTemp the uvTemp
                        vTemp=uvTemp;
                        //set the vertex on the array
                        this->vertexsOriginal.set(vertex,(edk::shape::Vertex3D*)vTemp);
                        //clean uvTemp
                        uvTemp=NULL;
                    }
                    else{
                        //else return false
                        return false;
                    }
                }
                else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                    edk::shape::Vertex3DAnimatedUV* vTemp2 = (edk::shape::Vertex3DAnimatedUV*)vTemp;
                    vTemp2->setUV(uv);
                    return true;
                }
                //set the uv
                vTemp->setUV(uv);
                //return true
                return true;
            }
            //else return false
            return false;
        }
        //Set the polygonFrames setting in the vertexs
        bool setPolygonUVFrames(edk::vec2ui32 frames){
            //test the frames
            if(frames.x && frames.y){
                edk::shape::Vertex3DWithUV* vTemp = NULL;
                edk::shape::Vertex3DAnimatedUV* uvaTemp = NULL;
                //set the frames on vertex
                for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                    //
                    vTemp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(i);
                    if(vTemp){
                        //test what type of vertex it is
                        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                            //then delete the vTemp and create another with UV
                            uvaTemp = new edk::shape::Vertex3DAnimatedUV();
                            if(uvaTemp){
                                //copy the vTemp content to uvTemp
                                uvaTemp->position = vTemp->position;
                                uvaTemp->color = vTemp->color;
                                uvaTemp->normal = vTemp->normal;

                                if(vTemp->getType() == EDK_SHAPE_UV){
                                    uvaTemp->setUV(vTemp->getUV());
                                }

                                //delete the vTemp
                                delete vTemp;
                                //set vTemp the uvTemp
                                vTemp=uvaTemp;
                                //set the vertex on the array
                                this->vertexsOriginal.set(i,(edk::shape::Vertex3D*)vTemp);
                                //clean uvTemp
                                uvaTemp=NULL;
                            }
                            else{
                                //else return false
                                return false;
                            }
                        }
                        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                            edk::shape::Vertex3DAnimatedUV* vTemp2 = (edk::shape::Vertex3DAnimatedUV*)vTemp;
                            vTemp2->setUVFrames(frames);
                            return true;
                        }
                        //return true
                        return true;
                    }
                }
                //return true
                return true;
            }
            //else return false
            return false;
        }
        bool setPolygonUVFramesX(edk::uint32 x){
            //test the frames
            if(x){
                edk::shape::Vertex3DWithUV* vTemp = NULL;
                edk::shape::Vertex3DAnimatedUV* uvaTemp = NULL;
                //set the frames on vertex
                for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                    //
                    vTemp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(i);
                    if(vTemp){
                        //test what type of vertex it is
                        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                            //then delete the vTemp and create another with UV
                            uvaTemp = new edk::shape::Vertex3DAnimatedUV();
                            if(uvaTemp){
                                //copy the vTemp content to uvTemp
                                uvaTemp->position = vTemp->position;
                                uvaTemp->color = vTemp->color;
                                uvaTemp->normal = vTemp->normal;

                                if(vTemp->getType() == EDK_SHAPE_UV){
                                    uvaTemp->setUV(vTemp->getUV());
                                }

                                //delete the vTemp
                                delete vTemp;
                                //set vTemp the uvTemp
                                vTemp=uvaTemp;
                                //set the vertex on the array
                                this->vertexsOriginal.set(i,(edk::shape::Vertex3D*)vTemp);
                                //clean uvTemp
                                uvaTemp=NULL;
                            }
                            else{
                                //else return false
                                return false;
                            }
                        }
                        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                            edk::shape::Vertex3DAnimatedUV* vTemp2 = (edk::shape::Vertex3DAnimatedUV*)vTemp;
                            vTemp2->setUVFrames(x,vTemp2->getUVFrames().y);
                            return true;
                        }
                        //return true
                        return true;
                    }
                }
                //return true
                return true;
            }
            //else return false
            return false;
        }
        bool setPolygonUVFramesY(edk::uint32 y){
            //test the frames
            if(y){
                edk::shape::Vertex3DWithUV* vTemp = NULL;
                edk::shape::Vertex3DAnimatedUV* uvaTemp = NULL;
                //set the frames on vertex
                for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                    //
                    vTemp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(i);
                    if(vTemp){
                        //test what type of vertex it is
                        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                            //then delete the vTemp and create another with UV
                            uvaTemp = new edk::shape::Vertex3DAnimatedUV();
                            if(uvaTemp){
                                //copy the vTemp content to uvTemp
                                uvaTemp->position = vTemp->position;
                                uvaTemp->color = vTemp->color;
                                uvaTemp->normal = vTemp->normal;

                                if(vTemp->getType() == EDK_SHAPE_UV){
                                    uvaTemp->setUV(vTemp->getUV());
                                }

                                //delete the vTemp
                                delete vTemp;
                                //set vTemp the uvTemp
                                vTemp=uvaTemp;
                                //set the vertex on the array
                                this->vertexsOriginal.set(i,(edk::shape::Vertex3D*)vTemp);
                                //clean uvTemp
                                uvaTemp=NULL;
                            }
                            else{
                                //else return false
                                return false;
                            }
                        }
                        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                            edk::shape::Vertex3DAnimatedUV* vTemp2 = (edk::shape::Vertex3DAnimatedUV*)vTemp;
                            vTemp2->setUVFrames(vTemp2->getUVFrames().x,y);
                            return true;
                        }
                        //return true
                        return true;
                    }
                }
                //return true
                return true;
            }
            //else return false
            return false;
        }
        //Set the polygon frame
        void usePolygonUVFrame(edk::vec2ui32 frame){
            //test the frames
            edk::shape::Vertex3DWithUV* vTemp = NULL;
            edk::shape::Vertex3DAnimatedUV* uvaTemp = NULL;
            //set the frames on vertex
            for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                //
                vTemp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(i);
                if(vTemp){
                    //test what type of vertex it is
                    if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                        //then delete the vTemp and create another with UV
                        uvaTemp = new edk::shape::Vertex3DAnimatedUV();
                        if(uvaTemp){
                            //copy the vTemp content to uvTemp
                            uvaTemp->position = vTemp->position;
                            uvaTemp->color = vTemp->color;
                            uvaTemp->normal = vTemp->normal;

                            if(vTemp->getType() == EDK_SHAPE_UV){
                                uvaTemp->setUV(vTemp->getUV());
                            }

                            //delete the vTemp
                            delete vTemp;
                            //set vTemp the uvTemp
                            vTemp=uvaTemp;
                            //set the vertex on the array
                            this->vertexsOriginal.set(i,(edk::shape::Vertex3D*)vTemp);
                            //clean uvTemp
                            uvaTemp=NULL;
                        }
                    }
                    else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                        edk::shape::Vertex3DAnimatedUV* vTemp2 = (edk::shape::Vertex3DAnimatedUV*)vTemp;
                        vTemp2->useUVFrame(frame);
                    }
                }
            }
        }
        //void usePolygonUVFramePosition(edk::uint32 position);
        void usePolygonUVFrameX(edk::uint32 x){
            edk::shape::Vertex3DWithUV* vTemp = NULL;
            edk::shape::Vertex3DAnimatedUV* uvaTemp = NULL;
            //set the frames on vertex
            for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                //
                vTemp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(i);
                if(vTemp){
                    //test what type of vertex it is
                    if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                        //then delete the vTemp and create another with UV
                        uvaTemp = new edk::shape::Vertex3DAnimatedUV();
                        if(uvaTemp){
                            //copy the vTemp content to uvTemp
                            uvaTemp->position = vTemp->position;
                            uvaTemp->color = vTemp->color;
                            uvaTemp->normal = vTemp->normal;

                            if(vTemp->getType() == EDK_SHAPE_UV){
                                uvaTemp->setUV(vTemp->getUV());
                            }

                            //delete the vTemp
                            delete vTemp;
                            //set vTemp the uvTemp
                            vTemp=uvaTemp;
                            //set the vertex on the array
                            this->vertexsOriginal.set(i,(edk::shape::Vertex3D*)vTemp);
                            //clean uvTemp
                            uvaTemp=NULL;
                        }
                    }
                    else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                        edk::shape::Vertex3DAnimatedUV* vTemp2 = (edk::shape::Vertex3DAnimatedUV*)vTemp;
                        vTemp2->useUVFrameX(x);
                    }
                }
            }
        }
        void usePolygonUVFrameY(edk::uint32 y){
            edk::shape::Vertex3DWithUV* vTemp = NULL;
            edk::shape::Vertex3DAnimatedUV* uvaTemp = NULL;
            //set the frames on vertex
            for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                //
                vTemp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(i);
                if(vTemp){
                    //test what type of vertex it is
                    if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                        //then delete the vTemp and create another with UV
                        uvaTemp = new edk::shape::Vertex3DAnimatedUV();
                        if(uvaTemp){
                            //copy the vTemp content to uvTemp
                            uvaTemp->position = vTemp->position;
                            uvaTemp->color = vTemp->color;
                            uvaTemp->normal = vTemp->normal;

                            if(vTemp->getType() == EDK_SHAPE_UV){
                                uvaTemp->setUV(vTemp->getUV());
                            }

                            //delete the vTemp
                            delete vTemp;
                            //set vTemp the uvTemp
                            vTemp=uvaTemp;
                            //set the vertex on the array
                            this->vertexsOriginal.set(i,(edk::shape::Vertex3D*)vTemp);
                            //clean uvTemp
                            uvaTemp=NULL;
                        }
                    }
                    else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                        edk::shape::Vertex3DAnimatedUV* vTemp2 = (edk::shape::Vertex3DAnimatedUV*)vTemp;
                        vTemp2->useUVFrameX(y);
                    }
                }
            }
        }
        //return the vertexCount
        edk::uint32 getVertexCount(){
            return this->vertexsOriginal.size();
        }
        //return if the vertex have UV
        edk::uint8 getVertexType(edk::uint32 pos){
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex3D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    return temp->getType();
                }
            }
            return 0u;
        }
        //return the vertex
        edk::vec3f32 getVertexPosition(edk::uint32 pos){
            edk::vec3f32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex3D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    ret = temp->position;
                }
            }
            return ret;
        }
        //return the vertex with all transformations
        edk::vec3f32 getVertexPositionTransformed(edk::uint32 pos){
            edk::vec3f32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex3D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    ret = temp->position;
                }
            }
            return ret;
        }
        //return the vertex color
        edk::color4f32 getVertexColor(edk::uint32 pos){
            edk::color4f32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex3D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    ret = temp->color;
                }
            }
            return ret;
        }
        //return the vertex normal
        edk::vec3f32 getVertexNormal(edk::uint32 pos){
            edk::vec3f32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex3D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    ret = temp->normal;
                }
            }
            return ret;
        }
        //return the vertex UV
        edk::vec2f32 getVertexUV(edk::uint32 pos){
            edk::vec2f32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex3D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    if(temp->getType() == EDK_SHAPE_UV){
                        ret = ((edk::shape::Vertex3DWithUV*)temp)->getUV();
                    }
                    else if(temp->getType() == EDK_SHAPE_ANIMATED_UV){
                        ret = ((edk::shape::Vertex3DAnimatedUV*)temp)->getUV();
                    }
                }
            }
            return ret;
        }
        //return the frames
        edk::vec2ui32 getFrames(edk::uint32 pos){
            edk::vec2ui32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex3D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    if(temp->getType() == EDK_SHAPE_ANIMATED_UV){
                        ret = ((edk::shape::Vertex3DAnimatedUV*)temp)->getUVFrames();
                    }
                }
            }
            return ret;
        }

        //calculate the morph
        bool calculateMorph(edk::vector::Array<edk::shape::Vertex3D*>* vertexsResult,
                            edk::float32 percent
                            ){
            return edk::shape::Polygon3D::Polygon3DMorph::calculateMorphStatic(&this->vertexsOriginal,
                                                                               &this->vertexs,
                                                                               vertexsResult,
                                                                               percent
                                                                               );
        }

        //calculate the new vertexes with percent apply
        static bool calculateMorphStatic(edk::vector::Array<edk::shape::Vertex3D*>* vertexsOriginal,
                                         edk::vector::Array<edk::shape::Vertex3D*>* vertexs,
                                         edk::vector::Array<edk::shape::Vertex3D*>* vertexsResult,
                                         edk::float32 percent
                                         ){
            //test all the pointers
            if(vertexsOriginal && vertexs && vertexsResult){
                //test if the vertexes have all the same size
                edk::uint32 size = vertexsOriginal->size();
                if(size == vertexs->size() && size == vertexsResult->size()){
                    edk::shape::Vertex3D* vTemp;
                    edk::shape::Vertex3D* vrTemp;
                    edk::shape::Vertex3D* voTemp;
                    edk::shape::Vertex3DWithUV* uvTemp;
                    edk::shape::Vertex3DWithUV* uvrTemp;
                    edk::shape::Vertex3DWithUV* uvoTemp;
                    edk::shape::Vertex3DAnimatedUV* uvaTemp;
                    edk::shape::Vertex3DAnimatedUV* uvarTemp;
                    edk::shape::Vertex3DAnimatedUV* uvaoTemp;
                    for(edk::uint32 i=0u;i<size;i++){
                        uvTemp=NULL;uvrTemp=NULL;uvoTemp=NULL;
                        uvaTemp=NULL;uvarTemp=NULL;uvaoTemp=NULL;

                        vTemp = vertexs->get(i);
                        vrTemp = vertexsResult->get(i);
                        voTemp = vertexsOriginal->get(i);
                        if(vTemp && vrTemp && voTemp){
                            //first copy the original to the result
                            if(voTemp->getType() == EDK_SHAPE_UV){
                                uvoTemp = (edk::shape::Vertex3DWithUV*)voTemp;
                                //set the vrTemp as with UV
                                uvrTemp = new edk::shape::Vertex3DWithUV;
                                if(uvrTemp){
                                    //copy the values
                                    uvrTemp->position = uvoTemp->position;
                                    uvrTemp->color = uvoTemp->color;
                                    uvrTemp->normal = uvoTemp->normal;
                                    //copy the uv value
                                    uvrTemp->setUV(uvoTemp->getUV());
                                    //delete the last vertex from vrTemp
                                    delete vrTemp;
                                    vrTemp = uvrTemp;
                                    uvrTemp=NULL;
                                    vertexsResult->set(i,vrTemp);
                                }
                                else{
                                    //copy the values
                                    vrTemp->position = voTemp->position;
                                    vrTemp->color = voTemp->color;
                                    vrTemp->normal = voTemp->normal;
                                }
                            }
                            else if(voTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                                uvaoTemp = (edk::shape::Vertex3DAnimatedUV*)voTemp;
                                //set the vrTemp as with UV
                                uvarTemp = new edk::shape::Vertex3DAnimatedUV;
                                if(uvarTemp){
                                    //copy the values
                                    uvarTemp->position = uvaoTemp->position;
                                    uvarTemp->color = uvaoTemp->color;
                                    uvarTemp->normal = uvaoTemp->normal;
                                    //copy the uv value
                                    uvarTemp->setUV(uvaoTemp->getSaved());
                                    uvarTemp->setUV(uvaoTemp->getUV());
                                    uvarTemp->setUVFrames(uvaoTemp->getUVFrames());
                                    //delete the last vertex from vrTemp
                                    delete vrTemp;
                                    vrTemp=uvarTemp;
                                    uvarTemp=NULL;
                                    vertexsResult->set(i,vrTemp);
                                }
                                else{
                                    //copy the values
                                    vrTemp->position = voTemp->position;
                                    vrTemp->color = voTemp->color;
                                    vrTemp->normal = voTemp->normal;
                                }
                            }
                            else{
                                //copy the values
                                vrTemp->position = voTemp->position;
                                vrTemp->color = voTemp->color;
                                vrTemp->normal = voTemp->normal;
                            }

                            //then calculate the percent
                            if(vTemp->getType() == EDK_SHAPE_UV){
                                uvTemp = (edk::shape::Vertex3DWithUV*)vTemp;
                                uvoTemp = (edk::shape::Vertex3DWithUV*)voTemp;
                                //set the vrTemp as with UV
                                uvrTemp = new edk::shape::Vertex3DWithUV;
                                if(uvrTemp){
                                    //copy the values
                                    uvrTemp->position = edk::Math::straightPosition(uvoTemp->position,uvTemp->position,percent);
                                    uvrTemp->color = edk::Math::straightPosition(uvoTemp->color,uvTemp->color,percent);
                                    uvrTemp->normal = edk::Math::straightPosition(uvoTemp->normal,uvTemp->normal,percent);
                                    //copy the uv value
                                    uvrTemp->setUV(edk::Math::straightPosition(uvoTemp->getUV(),uvTemp->getUV(),percent));
                                    //delete the last vertex from vrTemp
                                    delete vrTemp;
                                    vrTemp = uvrTemp;
                                    uvrTemp=NULL;
                                    vertexsResult->set(i,vrTemp);
                                }
                                else{
                                    //copy the values
                                    uvrTemp->position = edk::Math::straightPosition(uvoTemp->position,uvTemp->position,percent);
                                    uvrTemp->color = edk::Math::straightPosition(uvoTemp->color,uvTemp->color,percent);
                                    uvrTemp->normal = edk::Math::straightPosition(uvoTemp->normal,uvTemp->normal,percent);
                                }
                            }
                            else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                                uvaTemp = (edk::shape::Vertex3DAnimatedUV*)vTemp;
                                uvaoTemp = (edk::shape::Vertex3DAnimatedUV*)voTemp;
                                //set the vrTemp as with UV
                                uvarTemp = new edk::shape::Vertex3DAnimatedUV;
                                if(uvarTemp){
                                    //copy the values
                                    uvrTemp->position = edk::Math::straightPosition(uvaoTemp->position,uvaTemp->position,percent);
                                    uvrTemp->color = edk::Math::straightPosition(uvaoTemp->color,uvaTemp->color,percent);
                                    uvrTemp->normal = edk::Math::straightPosition(uvaoTemp->normal,uvaTemp->normal,percent);
                                    //copy the uv value
                                    uvarTemp->setUV(edk::Math::straightPosition(uvaoTemp->getSaved(),uvaTemp->getSaved(),percent));
                                    uvarTemp->setUV(edk::Math::straightPosition(uvaoTemp->getUV(),uvaTemp->getUV(),percent));
                                    uvarTemp->setUVFrames(edk::Math::straightPosition(uvaoTemp->getUVFrames(),uvaTemp->getUVFrames(),percent));
                                    //delete the last vertex from vrTemp
                                    delete vrTemp;
                                    vrTemp=uvarTemp;
                                    uvarTemp=NULL;
                                    vertexsResult->set(i,vrTemp);
                                }
                                else{
                                    //copy the values
                                    uvrTemp->position = edk::Math::straightPosition(uvoTemp->position,uvTemp->position,percent);
                                    uvrTemp->color = edk::Math::straightPosition(uvoTemp->color,uvTemp->color,percent);
                                    uvrTemp->normal = edk::Math::straightPosition(uvoTemp->normal,uvTemp->normal,percent);
                                }
                            }
                            else{
                                //copy the values
                                uvrTemp->position = edk::Math::straightPosition(uvoTemp->position,uvTemp->position,percent);
                                uvrTemp->color = edk::Math::straightPosition(uvoTemp->color,uvTemp->color,percent);
                                uvrTemp->normal = edk::Math::straightPosition(uvoTemp->normal,uvTemp->normal,percent);
                            }
                        }
                    }
                    return true;
                }
            }
            return false;
        }


        //Write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 morphID){
            if(xml){
                bool ret=false;
                //create the ID string
                edk::char8* id = edk::String::int32ToStr(morphID);
                if(id){
                    edk::char8* name = edk::String::strCat((edk::char8*)"morph_",id);
                    if(name){
                        //create the polygon
                        if(xml->addSelectedNextChild(name)){
                            //select the name
                            if(xml->selectChild(name)){
                                ret=true;
                                edk::char8* temp = NULL;
                                edk::uint32 size = 0u;

                                //write the percent
                                xml->addSelectedNextAttribute("percent",this->percent);

                                //write the original
                                temp = edk::String::strCopy("vertexs");
                                if(temp){
                                    xml->addSelectedNextChild(name);
                                    free(temp);
                                }
                                //select the name
                                if(xml->selectChild(name)){
                                    //write the original



                                    size = this->vertexs.size();
                                    //save the vertexs
                                    temp=edk::String::int32ToStr(size);
                                    if(temp){
                                        xml->addSelectedNextAttribute((edk::char8*)"vCount",temp);
                                        free(temp);
                                    }
                                    //Write Vertexs
                                    for(edk::uint32 i=0u;i<size;i++){
                                        edk::shape::Vertex3DAnimatedUV* polyTemp = (edk::shape::Vertex3DAnimatedUV*)vertexs.get(i);
                                        if(polyTemp){
                                            polyTemp->writeToXML(i,xml);
                                        }
                                    }
                                    if(xml->addSelectedNextChild("original")){
                                        if(xml->selectChild("original")){
                                            //write the vertexsOriginal

                                            size = this->vertexsOriginal.size();
                                            //save the vertexs
                                            temp=edk::String::int32ToStr(size);
                                            if(temp){
                                                xml->addSelectedNextAttribute((edk::char8*)"voCount",temp);
                                                free(temp);
                                            }
                                            //Write Vertexs
                                            for(edk::uint32 i=0u;i<size;i++){
                                                edk::shape::Vertex3DAnimatedUV* polyTemp = (edk::shape::Vertex3DAnimatedUV*)vertexsOriginal.get(i);
                                                if(polyTemp){
                                                    polyTemp->writeToXML(i,xml);
                                                }
                                            }

                                            xml->selectFather();
                                        }
                                    }

                                    //select the father
                                    xml->selectFather();
                                }
                                //select the father
                                xml->selectFather();
                            }
                        }
                    }
                }

                return ret;
            }
            return false;
        }
        //read from XML
        bool readFromXML(edk::XML* xml,edk::uint32 morphID){
            if(xml){
                bool ret=false;
                edk::char8* id = edk::String::int32ToStr(morphID);
                if(id){
                    edk::char8* name = edk::String::strCat((edk::char8*)"morph_",id);
                    if(name){
                        //create the polygon
                        //select the name
                        if(xml->selectChild(name)){
                            //read the percent
                            this->percent = xml->getSelectedAttributeValueAsFloat64ByName("percent");
                            //

                            if(xml->selectChild("vertexs")){
                                //read the vertex count
                                edk::uint32 size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("vCount"));
                                if(size){
                                    this->createPolygon(size,edk::color4f32(1.f,1.f,1.f,1.f));
                                    //read the vertexs
                                    for(edk::uint32 i=0u;i<size;i++){
                                        //read the vertex type
                                        edk::uint8 type = edk::shape::Vertex3D::readTypeFromXML(i,xml);
                                        switch(type){
                                        case EDK_SHAPE_ANIMATED_UV:
                                        case EDK_SHAPE_UV:
                                        {
                                            edk::shape::Vertex3DAnimatedUV temp;
                                            if(temp.readFromXML(i,xml)){
                                                //set the data
                                                this->setVertexPosition(i,temp.position);
                                                this->setVertexColor(i,temp.color);
                                                this->setVertexUV(i,temp.getSaved());
                                            }
                                            break;
                                        }
                                        case EDK_SHAPE_NOUV:
                                        {
                                            edk::shape::Vertex3D temp;
                                            if(temp.readFromXML(i,xml)){
                                                //set the data
                                                this->setVertexPosition(i,temp.position);
                                                this->setVertexColor(i,temp.color);
                                            }
                                            break;
                                        }
                                        }
                                    }
                                }

                                if(xml->selectChild("original")){
                                    //
                                    size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("voCount"));
                                    if(size){
                                        edk::shape::Vertex3D* vTemp=NULL;
                                        edk::shape::Vertex3DAnimatedUV* uvaTemp=NULL;
                                        //read the vertexs
                                        for(edk::uint32 i=0u;i<size;i++){
                                            //read the vertex type
                                            edk::uint8 type = edk::shape::Vertex3D::readTypeFromXML(i,xml);
                                            switch(type){
                                            case EDK_SHAPE_ANIMATED_UV:
                                            case EDK_SHAPE_UV:
                                            {
                                                edk::shape::Vertex3DAnimatedUV temp;
                                                vTemp = this->vertexsOriginal.get(i);
                                                uvaTemp = new edk::shape::Vertex3DAnimatedUV;
                                                if(uvaTemp){
                                                    if(temp.readFromXML(i,xml)){
                                                        //set the data
                                                        uvaTemp->position = temp.position;
                                                        uvaTemp->color = temp.color;
                                                        uvaTemp->normal = temp.normal;
                                                        uvaTemp->setUV(temp.getUV());
                                                        uvaTemp->setUVFrames(temp.getUVFrames());

                                                        if(vTemp){
                                                            delete vTemp;
                                                        }
                                                        vTemp=NULL;
                                                    }
                                                    else{
                                                        delete uvaTemp;
                                                    }
                                                }
                                                break;
                                            }
                                            case EDK_SHAPE_NOUV:
                                            {
                                                edk::shape::Vertex3D temp;
                                                vTemp = this->vertexsOriginal.get(i);
                                                if(temp.readFromXML(i,xml) && vTemp){
                                                    //set the data
                                                    vTemp->position = temp.position;
                                                    vTemp->color = temp.color;
                                                    vTemp->normal = temp.normal;
                                                }
                                                break;
                                            }
                                            }
                                        }
                                    }

                                    xml->selectFather();
                                }
                                xml->selectFather();
                            }
                            xml->selectFather();
                        }
                    }
                }
                //
                return ret;
            }
            return false;
        }

        //clone the morph
        bool cloneFrom(edk::shape::Polygon3D::Polygon3DMorph* morph){
            if(morph){
                //copy the percent
                this->percent = morph->percent;

                //create the polygom
                edk::uint32 size = morph->vertexsOriginal.size();
                if(size){
                    //create the polygon
                    if(this->createPolygon(size,edk::color4f32(1.f,1.f,1.f,1.f))){
                        //copy the vertexs
                        edk::shape::Vertex3D* vTemp;
                        edk::shape::Vertex3DWithUV* uvTemp;
                        edk::shape::Vertex3DAnimatedUV* uvaTemp;
                        edk::shape::Vertex3D* vTempMorph;
                        edk::shape::Vertex3DWithUV* uvTempMorph;
                        edk::shape::Vertex3DAnimatedUV* uvaTempMorph;

                        for(edk::uint32 i=0u;i<size;i++){
                            //get the vertexesOriginal
                            vTemp = this->vertexsOriginal.get(i);
                            vTempMorph = morph->vertexsOriginal.get(i);
                            if(vTemp && vTempMorph){
                                //compare the type
                                switch(vTempMorph->getType()){
                                case EDK_SHAPE_ANIMATED_UV:
                                    uvaTempMorph = (edk::shape::Vertex3DAnimatedUV*)vTempMorph;
                                    //create the new vertex
                                    uvaTemp = new edk::shape::Vertex3DAnimatedUV;
                                    if(uvaTemp){
                                        uvaTemp->position = uvaTempMorph->position;
                                        uvaTemp->color = uvaTempMorph->color;
                                        uvaTemp->normal = uvaTempMorph->normal;
                                        uvaTemp->setUV(uvaTempMorph->getUV());
                                        uvaTemp->setUVFrames(uvaTempMorph->getUVFrames());

                                        //set the uvaTemp
                                        if(this->vertexsOriginal.set(i,uvaTemp)){
                                            delete vTemp;
                                        }
                                        else{
                                            delete uvaTemp;
                                        }
                                    }
                                    break;
                                case EDK_SHAPE_UV:
                                    uvTempMorph = (edk::shape::Vertex3DWithUV*)vTempMorph;
                                    //create the new vertex
                                    uvTemp = new edk::shape::Vertex3DWithUV;
                                    if(uvTemp){
                                        uvTemp->position = uvTempMorph->position;
                                        uvTemp->color = uvTempMorph->color;
                                        uvTemp->normal = uvTempMorph->normal;
                                        uvTemp->setUV(uvTempMorph->getUV());

                                        //set the uvaTemp
                                        if(this->vertexsOriginal.set(i,uvTemp)){
                                            delete vTemp;
                                        }
                                        else{
                                            delete uvTemp;
                                        }
                                    }
                                    break;
                                    break;
                                default:
                                    vTemp->position = vTempMorph->position;
                                    vTemp->color = vTempMorph->color;
                                    vTemp->normal = vTempMorph->normal;
                                    break;
                                }
                            }

                            //get the vertexes
                            vTemp = this->vertexs.get(i);
                            vTempMorph = morph->vertexs.get(i);
                            if(vTemp && vTempMorph){
                                //compare the type
                                switch(vTempMorph->getType()){
                                case EDK_SHAPE_ANIMATED_UV:
                                    uvaTempMorph = (edk::shape::Vertex3DAnimatedUV*)vTempMorph;
                                    //create the new vertex
                                    uvaTemp = new edk::shape::Vertex3DAnimatedUV;
                                    if(uvaTemp){
                                        uvaTemp->position = uvaTempMorph->position;
                                        uvaTemp->color = uvaTempMorph->color;
                                        uvaTemp->normal = uvaTempMorph->normal;
                                        uvaTemp->setUV(uvaTempMorph->getUV());
                                        uvaTemp->setUVFrames(uvaTempMorph->getUVFrames());

                                        //set the uvaTemp
                                        if(this->vertexs.set(i,uvaTemp)){
                                            delete vTemp;
                                        }
                                        else{
                                            delete uvaTemp;
                                        }
                                    }
                                    break;
                                case EDK_SHAPE_UV:
                                    uvTempMorph = (edk::shape::Vertex3DWithUV*)vTempMorph;
                                    //create the new vertex
                                    uvTemp = new edk::shape::Vertex3DWithUV;
                                    if(uvTemp){
                                        uvTemp->position = uvTempMorph->position;
                                        uvTemp->color = uvTempMorph->color;
                                        uvTemp->normal = uvTempMorph->normal;
                                        uvTemp->setUV(uvTempMorph->getUV());

                                        //set the uvaTemp
                                        if(this->vertexs.set(i,uvTemp)){
                                            delete vTemp;
                                        }
                                        else{
                                            delete uvTemp;
                                        }
                                    }
                                    break;
                                    break;
                                default:
                                    vTemp->position = vTempMorph->position;
                                    vTemp->color = vTempMorph->color;
                                    vTemp->normal = vTempMorph->normal;
                                    break;
                                }
                            }
                        }
                    }
                }

                return true;
            }
            return false;
        }
    private:
        edk::classID classThis;
    };
    edk::vector::Stack<edk::shape::Polygon3D::Polygon3DMorph*> vertexsMorph;
private:
    //load the vertex
    edk::shape::Vertex3D* getVertexPointer(edk::uint32 vertex);
    edk::shape::Vertex3D* getVertexOriginalPointer(edk::uint32 vertex);
    //Animation frames
    edk::vec2ui32 frames;
    //save all the frames
    edk::uint32 framesSize;
    //save frame using
    edk::vec2ui32 frameUsing;
    //animationPointer
    edk::animation::Interpolation1DGroup* animationFrame;
    //save true if this polygon create the animationFrames
    bool createAnimationFrames;
    //transform matrices
    edk::vector::Matrixf32<4u,4u>  matrixTranslate;
    edk::vector::Matrixf32<4u,4u>  matrixRotate;
    edk::vector::Matrixf32<4u,4u>  matrixScale;
    edk::vector::Matrixf32<4u,4u>  matrixTransform;
    edk::vector::MatrixDynamic<edk::float32> matrixPosition;
    //success
    static bool successTemplate;

private:
    //Operator =
    edk::shape::Polygon3D operator=(edk::shape::Polygon3D poly){
        //first delete the vertexs
        this->deletePolygon();
        //then create a new polygon
        if(this->createPolygon(poly.getVertexCount())){
            //then copy the vertex
            for(edk::uint32 i=0u;i<this->getVertexCount();i++){
                //copy the vertex
                edk::shape::Vertex3DAnimatedUV* temp = (edk::shape::Vertex3DAnimatedUV*)vertexs.get(i);
                if(temp){
                    //this->setVertexPosition(i,poly.getVertexPosition(i));
                    temp->position = poly.getVertexPosition(i);
                    //this->setVertexColor(i,poly.getVertexColor(i));
                    temp->color = poly.getVertexColor(i);
                    temp->normal = poly.getVertexNormal(i);
                    //copy the frames
                    //this->setVertexUVFrames(i,poly.getFrames());
                    //get vertexType
                    switch(poly.getVertexType(i)){
                    //
                    case EDK_SHAPE_ANIMATED_UV:
                        //
                        this->setVertexUV(i,poly.getVertexUV(i));
                        this->setVertexUVFrames(i,poly.getFrames());
                        break;
                    case EDK_SHAPE_UV:
                        //
                        this->setVertexUV(i,poly.getVertexUV(i));
                        break;
                    };
                }
            }
        }
        //set the polygonFrames
        this->setPolygonUVFrames(poly.getFrames());
        this->usePolygonUVFrame(poly.frameUsing);
        //set the transformations
        this->setTranslate(poly.getTranslate());
        this->setScale(poly.getScale());
        this->setAngle(poly.getAngle());
        //set physics
        this->setDensity(poly.getDensity());
        this->setFriction(poly.getFriction());
        this->setRestitution(poly.getRestitution());
        //
        this->type = poly.type;
        this->polygonCircle = poly.polygonCircle;
        this->radius=poly.radius;
        this->polygonLine = poly.polygonLine;
        this->collisionID = poly.collisionID;
        //set the animation
        this->framesSetAnimation(poly.framesGetAnimation());
        this->createAnimationFrames = poly.createAnimationFrames;
        //return the polygon
        return poly;
    }
private:
    edk::classID classThis;
};

}//end namespace shape
}//end namespace edk

#endif // POLYGON_H
