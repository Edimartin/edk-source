#ifndef EDK_SHAPE_POLYGON_H
#define EDK_SHAPE_POLYGON_H

/*
Library Polygon2D - Draw a 2D Polygon in EDK Game Engine
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
#pragma message "Inside Polygon2D"
#endif

//Include EDK
#pragma once
#include "Vertex2D.h"
#include "../vector/Array.h"
#include "../animation/Interpolation1DGroup.h"
#include "../vector/Matrix.h"
#include "../Math.h"
#include "../xml/XML.h"
#include "../light/Light.h"

#ifdef printMessages
#pragma message "    Compiling Polygon2D"
#endif

//█■█■█■█■█■█■█■█■█■█■█■█■█■█■█■█

namespace edk{
namespace shape{

//minimum vertex countin the polygon. 2 vertex is one line
#define minimumVertex 2u

//CollisionID
enum collisionCode{
    collisionAways = 0x00,
    collisionUP = 0x0F,
    collisionDOWN = 0xF0,
};
//polygon type
enum EDKpolygon2DType{
    polygon2D = 1u,
    line2D,
    rectangle2D,
    circle2D,

    polygon2DTypeSize
};
//VBO type
enum EDKVBOType{
    vbo_NULL = 0u,
    vbo_XY,
    vbo_XYZ,
    vbo_XY_NxNyNz,
    vbo_XYZ_NxNyNz,
    vbo_XY_RGB,
    vbo_XYZ_RGB,
    vbo_XY_RGBA,
    vbo_XYZ_RGBA,
    vbo_XY_RGB_NxNyNz,
    vbo_XYZ_RGB_NxNyNz,
    vbo_XY_RGBA_NxNyNz,
    vbo_XYZ_RGBA_NxNyNz,
    vbo_XY_RGB_NxNyNz_UVxUVy,
    vbo_XYZ_RGB_NxNyNz_UVxUVy,
    vbo_XY_RGBA_NxNyNz_UVxUVy,
    vbo_XYZ_RGBA_NxNyNz_UVxUVy,

    vbo_Size
};

class Polygon2D{
public:
    Polygon2D();
    Polygon2D(edk::uint32 vertexCount);
    virtual ~Polygon2D();

    void clean();

    //create the polygon
    virtual bool createPolygon(edk::uint32 vertexCount);

    //test if the polygon is Counterclockwise
    bool isCounterclockwise();

    //invert the sense
    bool invertVertexSense();
    bool changeVertexSense(bool counterClockWise);
    bool setClockWise();
    bool setCounterClockWise();

    //SETTERS
    //set the position of a vertex
    bool setVertexPosition(edk::uint32 vertex,edk::vec2f32 position);
    bool setVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y);
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

    //clean the transformation
    void cleanTransform();
    //Set the position of the polygon
    void setTranslate(edk::vec2f32 translate);
    void setTranslate(edk::float32 translate);
    void setTranslate(edk::float32 x,edk::float32 y);
    //set the scale
    void setScale(edk::size2f32 scale);
    void setScale(edk::float32 scale);
    void setScale(edk::float32 width,edk::float32 height);
    //set the angle
    void setAngle(edk::float32 angle);
    //set physics
    void setDensity(edk::float32 density);
    void setFriction(edk::float32 friction);
    void setRestitution(edk::float32 restitution);

    //function to calculate boundingBox
    bool calculateBoundingBox(edk::rectf32* rectangle,edk::vector::Matrix<edk::float32,3,3>* transformMat);
    edk::rectf32 generateBoundingBox(edk::vector::Matrix<edk::float32,3,3>* transformMat);
    bool getWorldPolygon(edk::shape::Polygon2D* dest,edk::vector::Matrix<edk::float32,3,3>* transformMat);

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
    edk::vec2f32 getVertexPosition(edk::uint32 pos);
    //return the vertex with all transformations
    edk::vec2f32 getVertexPositionTransformed(edk::uint32 pos);
    //return the vertex color
    edk::color4f32 getVertexColor(edk::uint32 pos);
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
    edk::vec2f32 getTranslate();
    virtual edk::size2f32 getScale();
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
    virtual edk::uint32 newPolygonMorph(edk::float32 percent,bool* success=&edk::shape::Polygon2D::successTemplate);
    virtual bool havePolygonMorph(edk::uint32 positionMorph);
    virtual bool deletePolygonMorph(edk::uint32 positionMorph);
    virtual void cleanPolygonMorph();
    virtual void deleteAllPolygonMorph();
    virtual edk::uint32 getPolygonMorphSize();
    //morph setters
    //set the position of a vertex
    bool setPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 vertex,edk::vec2f32 position);
    bool setPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 x,edk::float32 y);
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
    edk::vec2f32 getPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 positionVertex);
    //return the vertex with all transformations
    edk::vec2f32 getPolygonMorphVertexPositionTransformed(edk::uint32 positionMorph,edk::uint32 positionVertex);
    //return the vertex color
    edk::color4f32 getPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 positionVertex);
    //return the vertex UV
    edk::vec2f32 getPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 positionVertex);
    //return the frames
    edk::vec2ui32 getPolygonMorphFrames(edk::uint32 positionMorph);

    edk::rectf32 getRect();

    //Set to cant delete the polygon
    void cantDeletePolygon();

    //print the polygon
    virtual void print();
    //Draw the polygon
    virtual void draw();
    //Draw the polygon with lines
    virtual void drawWire();
    //draw vertexs
    virtual void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1));

    //Write to XML
    bool writeToXML(edk::XML* xml,edk::uint32 polygonID);
    //read from XML
    bool readFromXML(edk::XML* xml,edk::uint32 polygonID);

    virtual bool cloneFrom(edk::shape::Polygon2D* poly);
protected:
    edk::vector::Array<edk::shape::Vertex2D*> vertexs;
    edk::vector::Array<edk::shape::Vertex2D*> vertexsOriginal;

    //Polygon VBO
    edk::uint32 vbo;
    edk::shape::EDKVBOType vboType;
    //array for the vbo
    edk::vector::Array<edk::float32> vertexBuffer;
    //vbo vertexes size
    edk::uint32 vboCount;
    //save if can use VBO in the polygon
    bool canUseVBO;

    //function to create the VBO
    virtual bool createVBO(edk::uint32 vertexCount,edk::shape::EDKVBOType type);
    //run the GU function to update the VBO
    bool updateVBO();
    //change the type of the VBO
    bool changeVBO(edk::shape::EDKVBOType type);
    void deleteVBO();
    bool haveVBO();
    //set the vboFunction pointers
    bool updateVBOFunctions();
    bool setAutomaticallyVBOFunctions();
    void setVBOFunctionUpdateNULL();
    void setVBOFunctionNULL();
    //setters to VBO
    virtual bool setVBOVertexPosition(edk::uint32 vertex,edk::vec2f32 position);
    virtual bool setVBOVertexPositionX(edk::uint32 vertex,edk::float32 x);
    virtual bool setVBOVertexPositionY(edk::uint32 vertex,edk::float32 y);
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
    //updafe the UV into the VBO
    virtual bool updateVBOUV();
    virtual bool updateVBOValues();
    //print the VBO
    virtual bool printVBO();

    //save if don't transform the polygon
    bool transforming;
    //Color of the polygon
    edk::color4f32 polygonColor;
    //set the vertexFrames
    bool setVertexUVFrames(edk::uint32 vertex,edk::vec2ui32 frames);
    //set if can delete the polygon
    bool canDeletePolygon;
    //Draw the polygon
    virtual void drawVertexs();
    virtual void drawVertexsWithColor(edk::color4f32 color);
    //update framesSize
    void updateFramesSize();
    //test if is tranforming the polygon
    void testTransform();

    //function pointers
    //PRINT
    void (edk::shape::Polygon2D::*vboPrint)();
    //DRAW
    void (edk::shape::Polygon2D::*vboDraw)(edk::uint32);

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

    //angle of the polygon
    edk::float32 angle;
    //scale the polygon
    edk::size2f32 scale;
    //polygon translation
    edk::vec2f32 translate;

    bool polygonCircle;
    edk::float32 radius;
    bool polygonLine;
    edk::uint8 collisionID;

    //Physics parameters
    edk::float32 density;
    edk::float32 friction;
    edk::float32 restitution;

    //polygon type
    edk::shape::EDKpolygon2DType type;

    //vertex morphs
    class Polygon2DMorph{
    public:
        Polygon2DMorph(edk::uint32 vertexCount,edk::color4f32 polygonColor){
            this->percent=0.f;
            this->createPolygon(vertexCount,polygonColor);
        }
        ~Polygon2DMorph(){
            this->vertexs.deleteArray();
            this->vertexsOriginal.deleteArray();
        }
        edk::vector::Array<edk::shape::Vertex2D*> vertexs;
        edk::vector::Array<edk::shape::Vertex2D*> vertexsOriginal;
        edk::float32 percent;
        //set if can delete the polygon
        bool canDeletePolygon;

        //delete the polygonVertex
        void deletePolygon(){
            if(this->canDeletePolygon){
                //remove the animation
                edk::uint32 size = this->vertexs.size();edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    //
                    if(this->vertexs.get(i)){
                        delete this->vertexs.getNoIF(i);edkEnd();
                    }
                }
                this->vertexs.deleteArray();edkEnd();
                size = this->vertexsOriginal.size();edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    //
                    if(this->vertexsOriginal.get(i)){
                        delete this->vertexsOriginal.getNoIF(i);edkEnd();
                    }
                }
                this->vertexsOriginal.deleteArray();edkEnd();

                this->canDeletePolygon=false;edkEnd();
            }
        }

        //create the polygon
        bool createPolygon(edk::uint32 vertexCount,edk::color4f32 polygonColor){
            //delete the polygon
            this->deletePolygon();edkEnd();
            //test the vertexCount
            if(vertexCount >= minimumVertex){
                //create the array
                if(this->vertexsOriginal.createArray(vertexCount)){
                    if(this->vertexs.createArray(vertexCount)){
                        //create all the vertexs
                        for(edk::uint32 i =0u;i<vertexCount;i++){
                            //
                            this->vertexs.set(i,new edk::shape::Vertex2D());edkEnd();
                            this->vertexsOriginal.set(i,new edk::shape::Vertex2D());edkEnd();
                            //Set alpha 1
                            if(this->vertexs.get(i)){
                                //set the vertex
                                this->vertexs.getNoIF(i)->color = polygonColor;edkEnd();
                            }
                            if(this->vertexsOriginal.get(i)){
                                //set the vertex
                                this->vertexsOriginal.getNoIF(i)->color = polygonColor;edkEnd();
                            }
                        }
                        this->canDeletePolygon=true;edkEnd();
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
        bool setVertexPosition(edk::uint32 vertex,edk::vec2f32 position){
            //load the polygon
            edk::shape::Vertex2D* vTemp = this->vertexsOriginal.get(vertex);edkEnd();
            if(vTemp){
                //then set the position of the vertex
                vTemp->position = position;edkEnd();
                //return true
                return true;
            }
            //else return false
            return false;
        }
        //set the color of a vertex
        bool setVertexColor(edk::uint32 vertex,edk::color4f32 color){
            //load the polygon
            edk::shape::Vertex2D* vTemp = this->vertexsOriginal.get(vertex);edkEnd();
            if(vTemp){
                //then set the position of the vertex
                vTemp->color = color;edkEnd();
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
                edk::shape::Vertex2D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color = color;edkEnd();
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
                edk::shape::Vertex2D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color = color;edkEnd();
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
                edk::shape::Vertex2D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color.r = r;edkEnd();
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
                edk::shape::Vertex2D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color.g = g;edkEnd();
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
                edk::shape::Vertex2D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color.b = b;edkEnd();
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
                edk::shape::Vertex2D* vTemp = NULL;
                for(edk::uint32 i=0u;i<size;i++){
                    //load the polygon
                    vTemp = this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //then set the position of the vertex
                        vTemp->color.a = a;edkEnd();
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
            edk::shape::Vertex2DWithUV* vTemp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(vertex);edkEnd();
            if(vTemp){
                //test what type of vertex it is
                if(vTemp->getType() == EDK_SHAPE_NOUV){
                    //then delete the vTemp and create another with UV
                    edk::shape::Vertex2DWithUV* uvTemp = new edk::shape::Vertex2DWithUV();edkEnd();
                    if(uvTemp){
                        //copy the vTemp content to uvTemp
                        uvTemp->position = vTemp->position;edkEnd();
                        uvTemp->color = vTemp->color;edkEnd();

                        //delete the vTemp
                        delete vTemp;edkEnd();
                        //set vTemp the uvTemp
                        vTemp=uvTemp;edkEnd();
                        //set the vertex on the array
                        this->vertexsOriginal.set(vertex,(edk::shape::Vertex2D*)vTemp);edkEnd();
                        //clean uvTemp
                        uvTemp=NULL;edkEnd();
                    }
                    else{
                        //else return false
                        return false;
                    }
                }
                else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                    edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
                    vTemp2->setUV(uv);edkEnd();
                    return true;
                }
                //set the uv
                vTemp->setUV(uv);edkEnd();
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
                edk::shape::Vertex2DWithUV* vTemp = NULL;
                edk::shape::Vertex2DAnimatedUV* uvaTemp = NULL;
                //set the frames on vertex
                for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                    //
                    vTemp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //test what type of vertex it is
                        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                            //then delete the vTemp and create another with UV
                            uvaTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
                            if(uvaTemp){
                                //copy the vTemp content to uvTemp
                                uvaTemp->position = vTemp->position;edkEnd();
                                uvaTemp->color = vTemp->color;edkEnd();

                                if(vTemp->getType() == EDK_SHAPE_UV){
                                    uvaTemp->setUV(vTemp->getUV());
                                }

                                //delete the vTemp
                                delete vTemp;edkEnd();
                                //set vTemp the uvTemp
                                vTemp=uvaTemp;edkEnd();
                                //set the vertex on the array
                                this->vertexsOriginal.set(i,(edk::shape::Vertex2D*)vTemp);edkEnd();
                                //clean uvTemp
                                uvaTemp=NULL;edkEnd();
                            }
                            else{
                                //else return false
                                return false;
                            }
                        }
                        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                            edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
                            vTemp2->setUVFrames(frames);edkEnd();
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
                edk::shape::Vertex2DWithUV* vTemp = NULL;
                edk::shape::Vertex2DAnimatedUV* uvaTemp = NULL;
                //set the frames on vertex
                for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                    //
                    vTemp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //test what type of vertex it is
                        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                            //then delete the vTemp and create another with UV
                            uvaTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
                            if(uvaTemp){
                                //copy the vTemp content to uvTemp
                                uvaTemp->position = vTemp->position;edkEnd();
                                uvaTemp->color = vTemp->color;edkEnd();

                                if(vTemp->getType() == EDK_SHAPE_UV){
                                    uvaTemp->setUV(vTemp->getUV());
                                }

                                //delete the vTemp
                                delete vTemp;edkEnd();
                                //set vTemp the uvTemp
                                vTemp=uvaTemp;edkEnd();
                                //set the vertex on the array
                                this->vertexsOriginal.set(i,(edk::shape::Vertex2D*)vTemp);edkEnd();
                                //clean uvTemp
                                uvaTemp=NULL;edkEnd();
                            }
                            else{
                                //else return false
                                return false;
                            }
                        }
                        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                            edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
                            vTemp2->setUVFrames(x,vTemp2->getUVFrames().y);edkEnd();
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
                edk::shape::Vertex2DWithUV* vTemp = NULL;
                edk::shape::Vertex2DAnimatedUV* uvaTemp = NULL;
                //set the frames on vertex
                for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                    //
                    vTemp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(i);edkEnd();
                    if(vTemp){
                        //test what type of vertex it is
                        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                            //then delete the vTemp and create another with UV
                            uvaTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
                            if(uvaTemp){
                                //copy the vTemp content to uvTemp
                                uvaTemp->position = vTemp->position;edkEnd();
                                uvaTemp->color = vTemp->color;edkEnd();

                                if(vTemp->getType() == EDK_SHAPE_UV){
                                    uvaTemp->setUV(vTemp->getUV());
                                }

                                //delete the vTemp
                                delete vTemp;edkEnd();
                                //set vTemp the uvTemp
                                vTemp=uvaTemp;edkEnd();
                                //set the vertex on the array
                                this->vertexsOriginal.set(i,(edk::shape::Vertex2D*)vTemp);edkEnd();
                                //clean uvTemp
                                uvaTemp=NULL;edkEnd();
                            }
                            else{
                                //else return false
                                return false;
                            }
                        }
                        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                            edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
                            vTemp2->setUVFrames(vTemp2->getUVFrames().x,y);edkEnd();
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
            edk::shape::Vertex2DWithUV* vTemp = NULL;
            edk::shape::Vertex2DAnimatedUV* uvaTemp = NULL;
            //set the frames on vertex
            for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                //
                vTemp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(i);edkEnd();
                if(vTemp){
                    //test what type of vertex it is
                    if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                        //then delete the vTemp and create another with UV
                        uvaTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
                        if(uvaTemp){
                            //copy the vTemp content to uvTemp
                            uvaTemp->position = vTemp->position;edkEnd();
                            uvaTemp->color = vTemp->color;edkEnd();

                            if(vTemp->getType() == EDK_SHAPE_UV){
                                uvaTemp->setUV(vTemp->getUV());
                            }

                            //delete the vTemp
                            delete vTemp;edkEnd();
                            //set vTemp the uvTemp
                            vTemp=uvaTemp;edkEnd();
                            //set the vertex on the array
                            this->vertexsOriginal.set(i,(edk::shape::Vertex2D*)vTemp);edkEnd();
                            //clean uvTemp
                            uvaTemp=NULL;edkEnd();
                        }
                    }
                    else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                        edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
                        vTemp2->useUVFrame(frame);edkEnd();
                    }
                }
            }
        }
        //void usePolygonUVFramePosition(edk::uint32 position);
        void usePolygonUVFrameX(edk::uint32 x){
            edk::shape::Vertex2DWithUV* vTemp = NULL;
            edk::shape::Vertex2DAnimatedUV* uvaTemp = NULL;
            //set the frames on vertex
            for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                //
                vTemp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(i);edkEnd();
                if(vTemp){
                    //test what type of vertex it is
                    if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                        //then delete the vTemp and create another with UV
                        uvaTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
                        if(uvaTemp){
                            //copy the vTemp content to uvTemp
                            uvaTemp->position = vTemp->position;edkEnd();
                            uvaTemp->color = vTemp->color;edkEnd();

                            if(vTemp->getType() == EDK_SHAPE_UV){
                                uvaTemp->setUV(vTemp->getUV());
                            }

                            //delete the vTemp
                            delete vTemp;edkEnd();
                            //set vTemp the uvTemp
                            vTemp=uvaTemp;edkEnd();
                            //set the vertex on the array
                            this->vertexsOriginal.set(i,(edk::shape::Vertex2D*)vTemp);edkEnd();
                            //clean uvTemp
                            uvaTemp=NULL;edkEnd();
                        }
                    }
                    else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                        edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
                        vTemp2->useUVFrameX(x);edkEnd();
                    }
                }
            }
        }
        void usePolygonUVFrameY(edk::uint32 y){
            edk::shape::Vertex2DWithUV* vTemp = NULL;
            edk::shape::Vertex2DAnimatedUV* uvaTemp = NULL;
            //set the frames on vertex
            for(edk::uint32 i=0u;i<this->vertexs.size();i++){
                //
                vTemp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(i);edkEnd();
                if(vTemp){
                    //test what type of vertex it is
                    if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
                        //then delete the vTemp and create another with UV
                        uvaTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
                        if(uvaTemp){
                            //copy the vTemp content to uvTemp
                            uvaTemp->position = vTemp->position;edkEnd();
                            uvaTemp->color = vTemp->color;edkEnd();

                            if(vTemp->getType() == EDK_SHAPE_UV){
                                uvaTemp->setUV(vTemp->getUV());
                            }

                            //delete the vTemp
                            delete vTemp;edkEnd();
                            //set vTemp the uvTemp
                            vTemp=uvaTemp;edkEnd();
                            //set the vertex on the array
                            this->vertexsOriginal.set(i,(edk::shape::Vertex2D*)vTemp);edkEnd();
                            //clean uvTemp
                            uvaTemp=NULL;edkEnd();
                        }
                    }
                    else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                        edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
                        vTemp2->useUVFrameX(y);edkEnd();
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
                edk::shape::Vertex2D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    return temp->getType();
                }
            }
            return 0u;
        }
        //return the vertex
        edk::vec2f32 getVertexPosition(edk::uint32 pos){
            edk::vec2f32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex2D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    ret = temp->position;
                }
            }
            return ret;
        }
        //return the vertex with all transformations
        edk::vec2f32 getVertexPositionTransformed(edk::uint32 pos){
            edk::vec2f32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex2D* temp = this->vertexsOriginal.get(pos);
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
                edk::shape::Vertex2D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    ret = temp->color;
                }
            }
            return ret;
        }
        //return the vertex UV
        edk::vec2f32 getVertexUV(edk::uint32 pos){
            edk::vec2f32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex2D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    if(temp->getType() == EDK_SHAPE_UV){
                        ret = ((edk::shape::Vertex2DWithUV*)temp)->getUV();
                    }
                    else if(temp->getType() == EDK_SHAPE_ANIMATED_UV){
                        ret = ((edk::shape::Vertex2DAnimatedUV*)temp)->getUV();
                    }
                }
            }
            return ret;
        }
        //return the frames
        edk::vec2ui32 getFrames(edk::uint32 pos){
            edk::vec2ui32 ret;
            if(this->vertexsOriginal.have(pos)){
                edk::shape::Vertex2D* temp = this->vertexsOriginal.get(pos);
                if(temp){
                    if(temp->getType() == EDK_SHAPE_ANIMATED_UV){
                        ret = ((edk::shape::Vertex2DAnimatedUV*)temp)->getUVFrames();
                    }
                }
            }
            return ret;
        }

        //calculate the morph
        bool calculateMorph(edk::vector::Array<edk::shape::Vertex2D*>* vertexsResult,
                            edk::float32 percent
                            ){
            return edk::shape::Polygon2D::Polygon2DMorph::calculateMorphStatic(&this->vertexsOriginal,
                                                                               &this->vertexs,
                                                                               vertexsResult,
                                                                               percent
                                                                               );
        }

        //calculate the new vertexes with percent apply
        static bool calculateMorphStatic(edk::vector::Array<edk::shape::Vertex2D*>* vertexsOriginal,
                                         edk::vector::Array<edk::shape::Vertex2D*>* vertexs,
                                         edk::vector::Array<edk::shape::Vertex2D*>* vertexsResult,
                                         edk::float32 percent
                                         ){
            //test all the pointers
            if(vertexsOriginal && vertexs && vertexsResult){
                //test if the vertexes have all the same size
                edk::uint32 size = vertexsOriginal->size();
                if(size == vertexs->size() && size == vertexsResult->size()){
                    edk::shape::Vertex2D* vTemp;
                    edk::shape::Vertex2D* vrTemp;
                    edk::shape::Vertex2D* voTemp;
                    edk::shape::Vertex2DWithUV* uvTemp;
                    edk::shape::Vertex2DWithUV* uvrTemp;
                    edk::shape::Vertex2DWithUV* uvoTemp;
                    edk::shape::Vertex2DAnimatedUV* uvaTemp;
                    edk::shape::Vertex2DAnimatedUV* uvarTemp;
                    edk::shape::Vertex2DAnimatedUV* uvaoTemp;
                    for(edk::uint32 i=0u;i<size;i++){
                        uvTemp=NULL;uvrTemp=NULL;uvoTemp=NULL;
                        uvaTemp=NULL;uvarTemp=NULL;uvaoTemp=NULL;

                        vTemp = vertexs->get(i);
                        vrTemp = vertexsResult->get(i);
                        voTemp = vertexsOriginal->get(i);
                        if(vTemp && vrTemp && voTemp){
                            //first copy the original to the result
                            if(voTemp->getType() == EDK_SHAPE_UV){
                                uvoTemp = (edk::shape::Vertex2DWithUV*)voTemp;
                                //set the vrTemp as with UV
                                uvrTemp = new edk::shape::Vertex2DWithUV;
                                if(uvrTemp){
                                    //copy the values
                                    uvrTemp->position = uvoTemp->position;
                                    uvrTemp->color = uvoTemp->color;
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
                                }
                            }
                            else if(voTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                                uvaoTemp = (edk::shape::Vertex2DAnimatedUV*)voTemp;
                                //set the vrTemp as with UV
                                uvarTemp = new edk::shape::Vertex2DAnimatedUV;
                                if(uvarTemp){
                                    //copy the values
                                    uvarTemp->position = uvaoTemp->position;
                                    uvarTemp->color = uvaoTemp->color;
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
                                }
                            }
                            else{
                                //copy the values
                                vrTemp->position = voTemp->position;
                                vrTemp->color = voTemp->color;
                            }

                            //then calculate the percent
                            if(vTemp->getType() == EDK_SHAPE_UV){
                                uvTemp = (edk::shape::Vertex2DWithUV*)vTemp;
                                uvoTemp = (edk::shape::Vertex2DWithUV*)voTemp;
                                //set the vrTemp as with UV
                                uvrTemp = new edk::shape::Vertex2DWithUV;
                                if(uvrTemp){
                                    //copy the values
                                    uvrTemp->position = edk::Math::straightPosition(uvoTemp->position,uvTemp->position,percent);
                                    uvrTemp->color = edk::Math::straightPosition(uvoTemp->color,uvTemp->color,percent);
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
                                }
                            }
                            else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
                                uvaTemp = (edk::shape::Vertex2DAnimatedUV*)vTemp;
                                uvaoTemp = (edk::shape::Vertex2DAnimatedUV*)voTemp;
                                //set the vrTemp as with UV
                                uvarTemp = new edk::shape::Vertex2DAnimatedUV;
                                if(uvarTemp){
                                    //copy the values
                                    uvrTemp->position = edk::Math::straightPosition(uvaoTemp->position,uvaTemp->position,percent);
                                    uvrTemp->color = edk::Math::straightPosition(uvaoTemp->color,uvaTemp->color,percent);
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
                                }
                            }
                            else{
                                //copy the values
                                uvrTemp->position = edk::Math::straightPosition(uvoTemp->position,uvTemp->position,percent);
                                uvrTemp->color = edk::Math::straightPosition(uvoTemp->color,uvTemp->color,percent);
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
                bool ret=false;edkEnd();
                //create the ID string
                edk::char8* id = edk::String::int32ToStr(morphID);edkEnd();
                if(id){
                    edk::char8* name = edk::String::strCat((edk::char8*)"morph_",id);edkEnd();
                    if(name){
                        //create the polygon
                        if(xml->addSelectedNextChild(name)){
                            //select the name
                            if(xml->selectChild(name)){
                                ret=true;edkEnd();
                                edk::char8* temp = NULL;edkEnd();
                                edk::uint32 size = 0u;edkEnd();

                                //write the percent
                                xml->addSelectedNextAttribute("percent",this->percent);edkEnd();

                                //write the original
                                temp = edk::String::strCopy("vertexs");edkEnd();
                                if(temp){
                                    xml->addSelectedNextChild(name);edkEnd();
                                    free(temp);edkEnd();
                                }
                                //select the name
                                if(xml->selectChild(name)){
                                    //write the original



                                    size = this->vertexs.size();edkEnd();
                                    //save the vertexs
                                    temp=edk::String::int32ToStr(size);edkEnd();
                                    if(temp){
                                        xml->addSelectedNextAttribute((edk::char8*)"vCount",temp);edkEnd();
                                        free(temp);edkEnd();
                                    }
                                    //Write Vertexs
                                    for(edk::uint32 i=0u;i<size;i++){
                                        edk::shape::Vertex2DAnimatedUV* polyTemp = (edk::shape::Vertex2DAnimatedUV*)vertexs.get(i);edkEnd();
                                        if(polyTemp){
                                            polyTemp->writeToXML(i,xml);edkEnd();
                                        }
                                    }
                                    if(xml->addSelectedNextChild("original")){
                                        if(xml->selectChild("original")){
                                            //write the vertexsOriginal

                                            size = this->vertexsOriginal.size();edkEnd();
                                            //save the vertexs
                                            temp=edk::String::int32ToStr(size);edkEnd();
                                            if(temp){
                                                xml->addSelectedNextAttribute((edk::char8*)"voCount",temp);edkEnd();
                                                free(temp);edkEnd();
                                            }
                                            //Write Vertexs
                                            for(edk::uint32 i=0u;i<size;i++){
                                                edk::shape::Vertex2DAnimatedUV* polyTemp = (edk::shape::Vertex2DAnimatedUV*)vertexsOriginal.get(i);edkEnd();
                                                if(polyTemp){
                                                    polyTemp->writeToXML(i,xml);edkEnd();
                                                }
                                            }

                                            xml->selectFather();edkEnd();
                                        }
                                    }

                                    //select the father
                                    xml->selectFather();edkEnd();
                                }
                                //select the father
                                xml->selectFather();edkEnd();
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
                bool ret=false;edkEnd();
                edk::char8* id = edk::String::int32ToStr(morphID);edkEnd();
                if(id){
                    edk::char8* name = edk::String::strCat((edk::char8*)"morph_",id);edkEnd();
                    if(name){
                        //create the polygon
                        //select the name
                        if(xml->selectChild(name)){
                            //read the percent
                            this->percent = xml->getSelectedAttributeValueAsFloat64ByName("percent");
                            //

                            if(xml->selectChild("vertexs")){
                                //read the vertex count
                                edk::uint32 size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("vCount"));edkEnd();
                                if(size){
                                    this->createPolygon(size,edk::color4f32(1.f,1.f,1.f,1.f));edkEnd();
                                    //read the vertexs
                                    for(edk::uint32 i=0u;i<size;i++){
                                        //read the vertex type
                                        edk::uint8 type = edk::shape::Vertex2D::readTypeFromXML(i,xml);edkEnd();
                                        switch(type){
                                        case EDK_SHAPE_ANIMATED_UV:
                                        case EDK_SHAPE_UV:
                                        {
                                            edk::shape::Vertex2DAnimatedUV temp;edkEnd();
                                            if(temp.readFromXML(i,xml)){
                                                //set the data
                                                this->setVertexPosition(i,temp.position);edkEnd();
                                                this->setVertexColor(i,temp.color);edkEnd();
                                                this->setVertexUV(i,temp.getSaved());edkEnd();
                                            }
                                            break;
                                        }
                                        case EDK_SHAPE_NOUV:
                                        {
                                            edk::shape::Vertex2D temp;edkEnd();
                                            if(temp.readFromXML(i,xml)){
                                                //set the data
                                                this->setVertexPosition(i,temp.position);edkEnd();
                                                this->setVertexColor(i,temp.color);edkEnd();
                                            }
                                            break;
                                        }
                                        }
                                    }
                                }

                                if(xml->selectChild("original")){
                                    //
                                    size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("voCount"));edkEnd();
                                    if(size){
                                        edk::shape::Vertex2D* vTemp=NULL;
                                        edk::shape::Vertex2DAnimatedUV* uvaTemp=NULL;
                                        //read the vertexs
                                        for(edk::uint32 i=0u;i<size;i++){
                                            //read the vertex type
                                            edk::uint8 type = edk::shape::Vertex2D::readTypeFromXML(i,xml);edkEnd();
                                            switch(type){
                                            case EDK_SHAPE_ANIMATED_UV:
                                            case EDK_SHAPE_UV:
                                            {
                                                edk::shape::Vertex2DAnimatedUV temp;edkEnd();
                                                vTemp = this->vertexsOriginal.get(i);
                                                uvaTemp = new edk::shape::Vertex2DAnimatedUV;
                                                if(uvaTemp){
                                                    if(temp.readFromXML(i,xml)){
                                                        //set the data
                                                        uvaTemp->position = temp.position;edkEnd();
                                                        uvaTemp->color = temp.color;edkEnd();
                                                        uvaTemp->setUV(temp.getUV());edkEnd();
                                                        uvaTemp->setUVFrames(temp.getUVFrames());edkEnd();

                                                        if(vTemp){
                                                            delete vTemp;edkEnd();
                                                        }
                                                        vTemp=NULL;edkEnd();
                                                    }
                                                    else{
                                                        delete uvaTemp;edkEnd();
                                                    }
                                                }
                                                break;
                                            }
                                            case EDK_SHAPE_NOUV:
                                            {
                                                edk::shape::Vertex2D temp;edkEnd();
                                                vTemp = this->vertexsOriginal.get(i);edkEnd();
                                                if(temp.readFromXML(i,xml) && vTemp){
                                                    //set the data
                                                    vTemp->position = temp.position;edkEnd();
                                                    vTemp->color = temp.color;edkEnd();
                                                }
                                                break;
                                            }
                                            }
                                        }
                                    }

                                    xml->selectFather();edkEnd();
                                }
                                xml->selectFather();edkEnd();
                            }
                            xml->selectFather();edkEnd();
                        }
                    }
                }
                //
                return ret;
            }
            return false;
        }

        //clone the morph
        bool cloneFrom(edk::shape::Polygon2D::Polygon2DMorph* morph){
            if(morph){
                //copy the percent
                this->percent = morph->percent;edkEnd();

                //create the polygom
                edk::uint32 size = morph->vertexsOriginal.size();edkEnd();
                if(size){
                    //create the polygon
                    if(this->createPolygon(size,edk::color4f32(1.f,1.f,1.f,1.f))){
                        //copy the vertexs
                        edk::shape::Vertex2D* vTemp;
                        edk::shape::Vertex2DWithUV* uvTemp;
                        edk::shape::Vertex2DAnimatedUV* uvaTemp;
                        edk::shape::Vertex2D* vTempMorph;
                        edk::shape::Vertex2DWithUV* uvTempMorph;
                        edk::shape::Vertex2DAnimatedUV* uvaTempMorph;

                        for(edk::uint32 i=0u;i<size;i++){
                            //get the vertexesOriginal
                            vTemp = this->vertexsOriginal.get(i);edkEnd();
                            vTempMorph = morph->vertexsOriginal.get(i);edkEnd();
                            if(vTemp && vTempMorph){
                                //compare the type
                                switch(vTempMorph->getType()){
                                case EDK_SHAPE_ANIMATED_UV:
                                    uvaTempMorph = (edk::shape::Vertex2DAnimatedUV*)vTempMorph;edkEnd();
                                    //create the new vertex
                                    uvaTemp = new edk::shape::Vertex2DAnimatedUV;edkEnd();
                                    if(uvaTemp){
                                        uvaTemp->position = uvaTempMorph->position;edkEnd();
                                        uvaTemp->color = uvaTempMorph->color;edkEnd();
                                        uvaTemp->setUV(uvaTempMorph->getUV());edkEnd();
                                        uvaTemp->setUVFrames(uvaTempMorph->getUVFrames());edkEnd();

                                        //set the uvaTemp
                                        if(this->vertexsOriginal.set(i,uvaTemp)){
                                            delete vTemp;edkEnd();
                                        }
                                        else{
                                            delete uvaTemp;edkEnd();
                                        }
                                    }
                                    break;
                                case EDK_SHAPE_UV:
                                    uvTempMorph = (edk::shape::Vertex2DWithUV*)vTempMorph;edkEnd();
                                    //create the new vertex
                                    uvTemp = new edk::shape::Vertex2DWithUV;edkEnd();
                                    if(uvTemp){
                                        uvTemp->position = uvTempMorph->position;edkEnd();
                                        uvTemp->color = uvTempMorph->color;edkEnd();
                                        uvTemp->setUV(uvTempMorph->getUV());edkEnd();

                                        //set the uvaTemp
                                        if(this->vertexsOriginal.set(i,uvTemp)){
                                            delete vTemp;edkEnd();
                                        }
                                        else{
                                            delete uvTemp;edkEnd();
                                        }
                                    }
                                    break;
                                    break;
                                default:
                                    vTemp->position = vTempMorph->position;edkEnd();
                                    vTemp->color = vTempMorph->color;edkEnd();
                                    break;
                                }
                            }

                            //get the vertexes
                            vTemp = this->vertexs.get(i);edkEnd();
                            vTempMorph = morph->vertexs.get(i);edkEnd();
                            if(vTemp && vTempMorph){
                                //compare the type
                                switch(vTempMorph->getType()){
                                case EDK_SHAPE_ANIMATED_UV:
                                    uvaTempMorph = (edk::shape::Vertex2DAnimatedUV*)vTempMorph;edkEnd();
                                    //create the new vertex
                                    uvaTemp = new edk::shape::Vertex2DAnimatedUV;edkEnd();
                                    if(uvaTemp){
                                        uvaTemp->position = uvaTempMorph->position;edkEnd();
                                        uvaTemp->color = uvaTempMorph->color;edkEnd();
                                        uvaTemp->setUV(uvaTempMorph->getUV());edkEnd();
                                        uvaTemp->setUVFrames(uvaTempMorph->getUVFrames());edkEnd();

                                        //set the uvaTemp
                                        if(this->vertexs.set(i,uvaTemp)){
                                            delete vTemp;edkEnd();
                                        }
                                        else{
                                            delete uvaTemp;edkEnd();
                                        }
                                    }
                                    break;
                                case EDK_SHAPE_UV:
                                    uvTempMorph = (edk::shape::Vertex2DWithUV*)vTempMorph;edkEnd();
                                    //create the new vertex
                                    uvTemp = new edk::shape::Vertex2DWithUV;edkEnd();
                                    if(uvTemp){
                                        uvTemp->position = uvTempMorph->position;edkEnd();
                                        uvTemp->color = uvTempMorph->color;edkEnd();
                                        uvTemp->setUV(uvTempMorph->getUV());edkEnd();

                                        //set the uvaTemp
                                        if(this->vertexs.set(i,uvTemp)){
                                            delete vTemp;edkEnd();
                                        }
                                        else{
                                            delete uvTemp;edkEnd();
                                        }
                                    }
                                    break;
                                    break;
                                default:
                                    vTemp->position = vTempMorph->position;edkEnd();
                                    vTemp->color = vTempMorph->color;edkEnd();
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
    };
    edk::vector::Stack<edk::shape::Polygon2D::Polygon2DMorph*> vertexsMorph;
private:
    //load the vertex
    edk::shape::Vertex2D* getVertexPointer(edk::uint32 vertex);
    edk::shape::Vertex2D* getVertexOriginalPointer(edk::uint32 vertex);
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
    edk::vector::Matrix<edk::float32,3u,3u> matrixTranslate;
    edk::vector::Matrix<edk::float32,3u,3u> matrixRotate;
    edk::vector::Matrix<edk::float32,3u,3u> matrixScale;
    edk::vector::Matrix<edk::float32,3u,3u> matrixTransform;
    edk::vector::MatrixDynamic<edk::float32> matrixPosition;
    //success
    static bool successTemplate;

private:
    //Operator =
    edk::shape::Polygon2D operator=(edk::shape::Polygon2D poly){
        //first delete the vertexs
        this->deletePolygon();edkEnd();
        //then create a new polygon
        if(this->createPolygon(poly.getVertexCount())){
            //then copy the vertex
            for(edk::uint32 i=0u;i<this->getVertexCount();i++){
                //copy the vertex
                edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)vertexs.get(i);edkEnd();
                if(temp){
                    //this->setVertexPosition(i,poly.getVertexPosition(i));edkEnd();
                    temp->position = poly.getVertexPosition(i);edkEnd();
                    //this->setVertexColor(i,poly.getVertexColor(i));edkEnd();
                    temp->color = poly.getVertexColor(i);edkEnd();
                    //copy the frames
                    //this->setVertexUVFrames(i,poly.getFrames());edkEnd();
                    //get vertexType
                    switch(poly.getVertexType(i)){
                    //
                    case EDK_SHAPE_ANIMATED_UV:
                        //
                        this->setVertexUV(i,poly.getVertexUV(i));edkEnd();
                        this->setVertexUVFrames(i,poly.getFrames());edkEnd();
                        break;
                    case EDK_SHAPE_UV:
                        //
                        this->setVertexUV(i,poly.getVertexUV(i));edkEnd();
                        break;
                    };
                }
            }
        }
        //set the polygonFrames
        this->setPolygonUVFrames(poly.getFrames());edkEnd();
        this->usePolygonUVFrame(poly.frameUsing);edkEnd();
        //set the transformations
        this->setTranslate(poly.getTranslate());edkEnd();
        this->setScale(poly.getScale());edkEnd();
        this->setAngle(poly.getAngle());edkEnd();
        //set physics
        this->setDensity(poly.getDensity());edkEnd();
        this->setFriction(poly.getFriction());edkEnd();
        this->setRestitution(poly.getRestitution());edkEnd();
        //
        this->type = poly.type;edkEnd();
        this->polygonCircle = poly.polygonCircle;edkEnd();
        this->radius=poly.radius;edkEnd();
        this->polygonLine = poly.polygonLine;edkEnd();
        this->collisionID = poly.collisionID;edkEnd();
        //set the animation
        this->framesSetAnimation(poly.framesGetAnimation());edkEnd();
        this->createAnimationFrames = poly.createAnimationFrames;edkEnd();
        //cant delete the polygon
        poly.cantDeletePolygon();edkEnd();
        //return the polygon
        return poly;edkEnd();
    }
};

}//end namespace shape
}//end namespace edk

#endif // POLYGON_H
