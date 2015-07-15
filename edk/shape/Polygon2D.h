#ifndef EDK_SHAPE_POLYGON_H
#define EDK_SHAPE_POLYGON_H

/*
Library Polygon2D - Draw a 2D Polygon in EDK Game Engine
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
#include "Vertex2D.h"
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

//CollisionID
enum collisionCode{
    collisionAways = 0x00,
    collisionUP = 0x0F,
    collisionDOWN = 0xF0,
};

class Polygon2D{
    public:
        Polygon2D();
        Polygon2D(edk::uint32 vertexCount);
        virtual ~Polygon2D();

        //create the polygon
        virtual bool createPolygon(edk::uint32 vertexCount);

        //test if the polygon is Counterclockwise
        bool isCounterclockwise();

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
        void setTranslate(edk::float32 x,edk::float32 y);
        //set the scale
        void setScale(edk::size2f32 scale);
        void setScale(edk::float32 width,edk::float32 height);
        //set the angle
        void setAngle(edk::float32 angle);
        //set physics
        void setDensity(edk::float32 density);
        void setFriction(edk::float32 friction);
        void setRestitution(edk::float32 restitution);

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
        //return the vertex color
        edk::color4f32 getVertexColor(edk::uint32 pos);
        //return the vertex UV
        edk::vec2f32 getVertexUV(edk::uint32 pos);
        //return the frames
        edk::vec2ui32 getFrames();

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

        //Set to cant delete the polygon
        void cantDeletePolygon();

        //print the polygon
        virtual void print();
        //Draw the polygon
        virtual void draw();
        //Draw the polygon with lights
        virtual bool drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],bool lightIsOn[][EDK_LIGHT_LIMIT]);
        //Draw the polygon with lines
        virtual void drawWire();

        //Write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 polygonID);
        //read from XML
        bool readFromXML(edk::XML* xml,edk::uint32 polygonID);

        //Operator =
        edk::shape::Polygon2D operator=(edk::shape::Polygon2D poly){
            //first delete the vertexs
            this->deletePolygon();
            //then create a new polygon
            if(this->createPolygon(poly.getVertexCount())){
                //then copy the vertex
                for(edk::uint32 i=0u;i<this->getVertexCount();i++){
                    //copy the vertex
                    edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)vertexs[i];
                    if(temp){
                        //this->setVertexPosition(i,poly.getVertexPosition(i));
                        temp->position = poly.getVertexPosition(i);
                        //this->setVertexColor(i,poly.getVertexColor(i));
                        temp->color = poly.getVertexColor(i);
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
            this->polygonCircle = poly.polygonCircle;
            this->radius=poly.radius;
            this->polygonLine = poly.polygonLine;
            this->collisionID = poly.collisionID;
            //set the animation
            this->framesSetAnimation(poly.framesGetAnimation());
            this->createAnimationFrames = poly.createAnimationFrames;
            //cant delete the polygon
            poly.cantDeletePolygon();
            //return the polygon
            return poly;
        }
    protected:
        edk::vector::Array<edk::shape::Vertex2D*> vertexs;
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
        //update framesSize
        void updateFramesSize();
        //test if is tranforming the polygon
        void testTransform();

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
    private:
        //load the vertex
        edk::shape::Vertex2D* getVertexPointer(edk::uint32 vertex);
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
};

}//end namespace shape
}//end namespace edk

#endif // POLYGON_H
