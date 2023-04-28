#ifndef VERTEX3D_H
#define VERTEX3D_H

/*
Library vertex3D - Draw a 3D vertex in EDK Game Engine
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
#pragma message "Inside Vertex3D"
#endif

#pragma once
#include <stdio.h>
#include "Vertex2D.h"
#include "../TypeVec3.h"
#include "../TypeColor.h"
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../xml/XML.h"

#ifdef printMessages
#pragma message "    Compiling Vertex3D"
#endif



namespace edk{
namespace shape{

//type of the vertex
//EDK_SHAPE_ANIMATED_UV
//EDK_SHAPE_UV
//EDK_SHAPE_NOUV

class Vector3D: public edk::vec3f32{
public:
    Vector3D(){
    }
    Vector3D(edk::float32 x,edk::float32 y,edk::float32 z){
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
    }
    virtual ~Vector3D(){}
    //functions to draw the vector as
    //VERTEX
    virtual void drawVertex(){
        //draw the vertex
        edk::GU::guVertex3f32(this->x, this->y,this->z);edkEnd();
    }
    virtual void drawVertexPosition(edk::vec3f32 position){
        //draw the vertex
        edk::GU::guVertex3f32(this->x+position.x, this->y+position.y,this->z+position.z);edkEnd();
    }
    virtual void printVertex(){
        printf("\nVertex %.2f %.2f %.2f",
               this->x,this->y,this->z
               );edkEnd();
    }
    //OPERATORS
    edk::shape::Vector3D operator=(edk::shape::Vector3D vertex){
        this->x=vertex.x;edkEnd();
        this->y=vertex.y;edkEnd();
        this->z=vertex.z;edkEnd();
        return vertex;edkEnd();
    }
    edk::vec3f32 operator=(edk::vec3f32 vertex){
        this->x=vertex.x;edkEnd();
        this->y=vertex.y;edkEnd();
        this->z=vertex.z;edkEnd();
        return vertex;edkEnd();
    }
    bool operator==(edk::shape::Vector3D vertex){
        if(this->x==vertex.x && this->y==vertex.y && this->z==vertex.z
                ){
            return true;
        }
        return false;
    }
    bool operator!=(edk::shape::Vector3D vertex){
        if(this->x!=vertex.x || this->y!=vertex.y || this->z!=vertex.z
                ){
            return true;
        }
        return false;
    }
    //NORMAL
    void drawNormal(){
        //draw the normal
        edk::GU::guVertexNormal3f32(this->x, this->y,this->z);edkEnd();
    }
    void printNormal(){
        printf("\nNormal %.2f %.2f %.2f",
               this->x,this->y,this->z
               );edkEnd();
    }
};

class Vertex3D : public edk::shape::Vector3D{
public:
    Vertex3D(){
        this->x=this->y=this->z=0.f;edkEnd();
        this->r=this->g=this->b=this->a=1.f;edkEnd();
    }
    Vertex3D(edk::vec3f32 position){
        this->x=position.x;edkEnd();
        this->y=position.y;edkEnd();
        this->z=position.z;edkEnd();
        this->r=this->g=this->b=this->a=1.f;edkEnd();
    }
    Vertex3D(edk::vec3f32 position,edk::color3f32 color){
        this->x=position.x;edkEnd();
        this->y=position.y;edkEnd();
        this->z=position.z;edkEnd();
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        this->a=1.f;edkEnd();
    }
    Vertex3D(edk::vec3f32 position,edk::color4f32 color){
        this->x=position.x;edkEnd();
        this->y=position.y;edkEnd();
        this->z=position.z;edkEnd();
        this->r=color.r;edkEnd();
        this->g=color.g;edkEnd();
        this->b=color.b;edkEnd();
        this->a=color.a;edkEnd();
    }
    Vertex3D(edk::float32 x,edk::float32 y,edk::float32 z){
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        this->r=this->g=this->b=this->a=1.f;edkEnd();
    }
    Vertex3D(edk::float32 x,edk::float32 y,edk::float32 z,
             edk::float32 r,edk::float32 g,edk::float32 b
             ){
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=1.f;edkEnd();
    }
    Vertex3D(edk::float32 x,edk::float32 y,edk::float32 z,
             edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a
             ){
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        this->z=z;edkEnd();
        this->r=r;edkEnd();
        this->g=g;edkEnd();
        this->b=b;edkEnd();
        this->a=a;edkEnd();
    }
    virtual ~Vertex3D(){}
    //OPERATORS
    edk::shape::Vertex3D operator=(edk::shape::Vertex3D vertex){
        this->x=vertex.x;edkEnd();
        this->y=vertex.y;edkEnd();
        this->z=vertex.z;edkEnd();
        this->r = vertex.r;edkEnd();
        this->g = vertex.g;edkEnd();
        this->b = vertex.b;edkEnd();
        this->a = vertex.a;edkEnd();
        return vertex;edkEnd();
    }
    bool operator==(edk::shape::Vertex3D vertex){
        if(this->x==vertex.x && this->y==vertex.y && this->z==vertex.z
                &&
                this->r==vertex.r && this->g==vertex.g && this->b==vertex.b && this->a==vertex.a
                ){
            return true;
        }
        return false;
    }
    bool operator!=(edk::shape::Vertex3D vertex){
        if(this->x!=vertex.x || this->y!=vertex.y || this->z!=vertex.z
                ||
                this->r!=vertex.r || this->g!=vertex.g || this->b!=vertex.b || this->a!=vertex.a
                ){
            return true;
        }
        return false;
    }
    //VERTEX
    void drawVertex(){
        //set the color of the vertex
        edk::GU::guColor4f32(this->r,
                             this->g,
                             this->b,
                             this->a
                             );edkEnd();
        //draw the vertex
        edk::shape::Vector3D::drawVertex();edkEnd();
    }
    void drawVertexPosition(edk::vec3f32 position){
        //set the color of the vertex
        edk::GU::guColor4f32(this->r,
                             this->g,
                             this->b,
                             this->a
                             );edkEnd();
        //draw the vertex
        edk::shape::Vector3D::drawVertexPosition(position);edkEnd();
    }
    void drawVertexWithColor(edk::color4f32 color){
        //set the color of the vertex
        edk::GU::guColor4f32(color.r,
                             color.g,
                             color.b,
                             color.a
                             );edkEnd();
        //draw the vertex
        edk::shape::Vector3D::drawVertex();edkEnd();
    }
    void drawVertexPositionWithColor(edk::vec3f32 position,edk::color4f32 color){
        //set the color of the vertex
        edk::GU::guColor4f32(color.r,
                             color.g,
                             color.b,
                             color.a
                             );edkEnd();
        //draw the vertex
        edk::shape::Vector3D::drawVertexPosition(position);edkEnd();
    }

    void printVertex(){
        printf("\nColor %.2f %.2f %.2f %.2f",
               this->r,this->g,this->b,this->a
               );edkEnd();
        //print the vertex
        edk::shape::Vector3D::printVertex();edkEnd();
    }
    edk::float32 r,g,b,a;
};

/*
class Vertex3D{
public:
    Vertex3D(){
        //
        this->color.a=1u;edkEnd();
        this->type = EDK_SHAPE_NOUV;edkEnd();
        this->position = 0.f;edkEnd();
        this->normal = 0.f;edkEnd();
    }
    virtual ~Vertex3D(){
        //
    }

    //position
    edk::vec3f32 position;edkEnd();
    //position
    edk::vec3f32 normal;edkEnd();
    //color
    edk::color4f32 color;edkEnd();

    //draw function
    virtual void drawWithColor(edk::color4f32 color = edk::color4f32(1,1,1,1)){
        //Draw

        //set the color of the vertex
        edk::GU::guColor4f32(color.r,
                             color.g,
                             color.b,
                             color.a
                             );edkEnd();

        //draw the normal
        edk::GU::guVertexNormal3f32(this->position.x, this->position.y,1.f);edkEnd();

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, this->position.z);edkEnd();
    }

    //draw function
    virtual void draw(){
        //Draw

        //set the color of the vertex
        edk::GU::guColor4f32(this->color.r,
                             this->color.g,
                             this->color.b,
                             this->color.a
                             );edkEnd();

        //draw the normal
        edk::GU::guVertexNormal3f32(this->position.x, this->position.y,1.f);edkEnd();

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, this->position.z);edkEnd();
    }
    //print function
    virtual void print(){
        //
        printf("\nVector position(%.2f %.2f %.2f) Color (%.2f %.2f %.2f %.2f)"
               ,this->position.x
               ,this->position.y
               ,this->position.z

               ,this->color.r
               ,this->color.g
               ,this->color.b
               ,this->color.a
               );edkEnd();
    }
    virtual void print(edk::uint32 vertex){
        //
        printf("\nVector [%u] position(%.2f %.2f %.2f) Color (%.2f %.2f %.2f %.2f)"
               ,vertex
               ,this->position.x
               ,this->position.y
               ,this->position.z

               ,this->color.r
               ,this->color.g
               ,this->color.b
               ,this->color.a
               );edkEnd();
    }
    virtual bool writeToXML(edk::uint32 vertex,edk::XML* xml){
        if(xml){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);edkEnd();
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);edkEnd();
                if(name){
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            //set attribute
                            edk::char8* temp = NULL;edkEnd();
                            temp = edk::String::int32ToStr((edk::int32)this->getType());edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"type",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->position.x);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"x",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->position.y);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"y",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->position.z);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"z",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->color.r);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"r",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->color.g);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"g",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->color.b);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"b",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->color.a);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"a",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            //
                            xml->selectFather();edkEnd();
                        }
                    }
                    free(name);edkEnd();
                }
                free(id);edkEnd();
            }
            return true;
        }
        return false;
    }
    virtual bool readFromXML(edk::uint32 vertex,edk::XML* xml){
        if(xml){
            bool ret=false;edkEnd();
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);edkEnd();
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;edkEnd();
                        if((temp = xml->getSelectedAttributeValueByName("type"))){
                            //read the type
                            //edk::uint8 typeTemp = (edk::uint8)edk::String::strToInt32(temp);edkEnd();
                            //free(temp);edkEnd();
                            //test if the type is the same
                            //if(typeTemp==this->getType()){
                                if((temp = xml->getSelectedAttributeValueByName("x"))){
                                    //read the value
                                    this->position.x = edk::String::strToFloat32(temp);edkEnd();
                                    //free(temp);edkEnd();
                                }
                                if((temp = xml->getSelectedAttributeValueByName("y"))){
                                    //read the value
                                    this->position.y = edk::String::strToFloat32(temp);edkEnd();
                                    //free(temp);edkEnd();
                                }
                                if((temp = xml->getSelectedAttributeValueByName("z"))){
                                    //read the value
                                    this->position.z = edk::String::strToFloat32(temp);edkEnd();
                                    //free(temp);edkEnd();
                                }
                                if((temp = xml->getSelectedAttributeValueByName("r"))){
                                    //read the value
                                    this->color.r = edk::String::strToFloat32(temp);edkEnd();
                                    //free(temp);edkEnd();
                                }
                                if((temp = xml->getSelectedAttributeValueByName("g"))){
                                    //read the value
                                    this->color.g = edk::String::strToFloat32(temp);edkEnd();
                                    //free(temp);edkEnd();
                                }
                                if((temp = xml->getSelectedAttributeValueByName("b"))){
                                    //read the value
                                    this->color.b = edk::String::strToFloat32(temp);edkEnd();
                                    //free(temp);edkEnd();
                                }
                                if((temp = xml->getSelectedAttributeValueByName("a"))){
                                    //read the value
                                    this->color.a = edk::String::strToFloat32(temp);edkEnd();
                                    //free(temp);edkEnd();
                                }
                                ret=true;edkEnd();
                            //}
                        }
                        xml->selectFather();edkEnd();
                    }
                    free(name);edkEnd();
                }
                free(id);edkEnd();
            }
            return ret;
        }
        return false;
    }
    //read the vertexType from XML
    static edk::uint8 readTypeFromXML(edk::uint32 vertex,edk::XML* xml){
        if(xml){
            edk::uint8 ret=0u;edkEnd();
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);edkEnd();
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;edkEnd();
                        if((temp = xml->getSelectedAttributeValueByName("type"))){
                            ret = edk::String::strToInt32(temp);edkEnd();
                        }
                        xml->selectFather();edkEnd();
                    }
                    free(name);edkEnd();
                }
                free(id);edkEnd();
            }
            return ret;
        }
        return 0u;edkEnd();
    }

    //Just return the type of the vertex
    virtual edk::uint8 getType(){
        //
        return this->type;edkEnd();
    }

    //OPERATORS
    edk::shape::Vertex3D operator=(edk::shape::Vertex3D vertex){
        //
        this->position=vertex.position;edkEnd();
        this->color=vertex.color;edkEnd();
        return vertex;edkEnd();
    }
protected:
    edk::uint8 type;edkEnd();
private:
};

//Add the UV to the vertex
class Vertex3DWithUV: public edk::shape::Vertex3D{
public:
    Vertex3DWithUV(){
        //
        this->type = EDK_SHAPE_UV;edkEnd();
    }
    virtual ~Vertex3DWithUV(){
        //
    }



    //SETERS
    //Set the UV parameter.
    void setUV(edk::vec2f32 uv){
        //
        this->uv= uv;edkEnd();
    }
    void setUV(edk::float32 x,edk::float32 y){
        //
        this->setUV(edk::vec2f32(x,y));edkEnd();
    }
    void setUVX(edk::float32 x){
        //
        this->uv.x= x;edkEnd();
    }
    void setUVY(edk::float32 y){
        //
        this->uv.y= y;edkEnd();
    }

    //GETERS
    edk::vec2f32 getUV(){
        //
        return this->uv;edkEnd();
    }
    edk::float32 getUVX(){
        //
        return this->uv.x;edkEnd();
    }
    edk::float32 getUVY(){
        //
        return this->uv.y;edkEnd();
    }

    //draw function
    virtual void drawWithColor(edk::color4f32 color = edk::color4f32(1,1,1,1)){
        //Add the UV
        edk::GU::guVertexTex2f32(this->uv.x,this->uv.y);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,this->uv.x,this->uv.y);edkEnd();
        //draw the vector2D
        edk::shape::Vertex3D::drawWithColor(color);edkEnd();
    }
    //draw function
    virtual void draw(){
        //Add the UV
        edk::GU::guVertexTex2f32(this->uv.x,this->uv.y);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,this->uv.x,this->uv.y);edkEnd();
        //draw the vector2D
        edk::shape::Vertex3D::draw();edkEnd();
    }
    //print function
    virtual void print(){
        edk::shape::Vertex3D::print();edkEnd();
        //add the UV to the print
        printf("UV(%.2f %.2f)"
               ,this->uv.x
               ,this->uv.y
               );edkEnd();
    }
    virtual void print(edk::uint32 vertex){
        edk::shape::Vertex3D::print(vertex);edkEnd();
        //add the UV to the print
        printf("\nUV(%.2f %.2f)"
               ,this->uv.x
               ,this->uv.y
               );edkEnd();
    }
    virtual bool writeToXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex3D::writeToXML(vertex,xml)){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);edkEnd();
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;edkEnd();
                        temp = edk::String::float32ToStr(this->uv.x);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvX",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->uv.y);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvY",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //
                        xml->selectFather();edkEnd();
                    }
                    free(name);edkEnd();
                }
                free(id);edkEnd();
            }
            return true;
        }
        return false;
    }
    virtual bool readFromXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex3D::readFromXML(vertex,xml)){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);edkEnd();
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;edkEnd();
                        if((temp = xml->getSelectedAttributeValueByName("uvX"))){
                            //read the value
                            this->uv.x = edk::String::strToFloat32(temp);edkEnd();
                            //free(temp);edkEnd();
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvY"))){
                            //read the value
                            this->uv.y = edk::String::strToFloat32(temp);edkEnd();
                            //free(temp);edkEnd();
                        }
                        xml->selectFather();edkEnd();
                    }
                    free(name);edkEnd();
                }
                free(id);edkEnd();
            }
            return true;
        }
        return false;
    }

    //OPERATORS
    edk::shape::Vertex3DWithUV operator=(edk::shape::Vertex3D vertex){
        //
        this->position=vertex.position;edkEnd();
        this->color=vertex.color;edkEnd();
        return edk::shape::Vertex3DWithUV();edkEnd();
    }
    edk::shape::Vertex3DWithUV operator=(edk::shape::Vertex3DWithUV vertex){
        //
        this->position=vertex.position;edkEnd();
        this->color=vertex.color;edkEnd();
        this->uv=uv;edkEnd();
        return vertex;edkEnd();
    }
protected:
private:
    //uvMap is private because the Vertex3DUVAnimated modify the setUV
    edk::vec2f32 uv;edkEnd();
};

class Vertex3DAnimatedUV: public edk::shape::Vertex3DWithUV{
    //
public:
    Vertex3DAnimatedUV(){
        //
        this->type = EDK_SHAPE_ANIMATED_UV;edkEnd();
    }
    virtual ~Vertex3DAnimatedUV(){
        //
    }



    //SETERS
    //Set the UV and the uvSaved
    void setUV(edk::vec2f32 uv){
        //
        edk::shape::Vertex3DWithUV::setUV(uv);edkEnd();
        this->uvSaved= uv;edkEnd();
    }
    void setUV(edk::float32 x,edk::float32 y){
        //
        edk::shape::Vertex3DWithUV::setUV(x,y);edkEnd();
        this->setUV(edk::vec2f32(x,y));edkEnd();
    }

    //GETTERS
    edk::vec2f32 getMultiply(){
        //
        return this->uvMultiply;edkEnd();
    }
    edk::vec2f32 getSaved(){
        //
        return this->uvSaved;edkEnd();
    }

    //Animation
    void cleanUVAnimation(){
        //
        //this->uv=this->uvSaved;edkEnd();
        this->setUV(this->uvSaved);edkEnd();
    }
    //set the animationFrames
    bool setUVFrames(edk::vec2ui32 frames){
        //test if the frames are true
        if(frames.x && frames.y){
            //set the frames for the UV position
            this->uvMultiply.x = 1.f/(edk::float32)frames.x;edkEnd();
            this->uvMultiply.y = 1.f/(edk::float32)frames.y;edkEnd();
            //set the frame
            this->useUVFrame(edk::vec2ui32(0u,0u));edkEnd();
            //return true
            return true;
        }
        //else return false
        return false;
    }
    bool setUVFrames(edk::uint32 x,edk::uint32 y){
        //
        return this->setUVFrames(edk::vec2ui32(x,y));edkEnd();
    }
    //set the uvFrame
    void useUVFrame(edk::vec2ui32 frame){
        //set the uvFrame
        edk::shape::Vertex3DWithUV::setUV( this->uvMultiply.x * frame.x + this->uvSaved.x*this->uvMultiply.x
                                           ,this->uvMultiply.y * frame.y + this->uvSaved.y*this->uvMultiply.y
                                           );edkEnd();
    }
    void useUVFrame(edk::uint32 x,edk::uint32 y){
        //
        this->useUVFrame(edk::vec2ui32(x,y));edkEnd();
    }
    //
    void useUVFrameX(edk::uint32 x){
        //
        //this->uv.x = this->uvMultiply.x * (x+1u);edkEnd();
        edk::shape::Vertex3DWithUV::setUVX(this->uvMultiply.x * x + this->uvSaved.x*this->uvMultiply.x);edkEnd();
    }
    void useUVFrameY(edk::uint32 y){
        //
        //this->uv.y = this->uvMultiply.y * (y+1u);edkEnd();
        edk::shape::Vertex3DWithUV::setUVY(this->uvMultiply.y * y + this->uvSaved.y*this->uvMultiply.y);edkEnd();
    }

    //draw function
    virtual void drawWithColor(edk::color4f32 color = edk::color4f32(1,1,1,1)){
        //draw the vector2D
        edk::shape::Vertex3DWithUV::drawWithColor(color);edkEnd();
    }
    //draw function
    virtual void draw(){
        //draw the vector2D
        edk::shape::Vertex3DWithUV::draw();edkEnd();
    }
    //print function
    virtual void print(){
        //
        edk::shape::Vertex3DWithUV::print();edkEnd(); printf(" multiply(%.2f %.2f)"
                                                    ,this->uvMultiply.x
                                                    ,this->uvMultiply.y
                                                    );edkEnd();
    }
    virtual void print(edk::uint32 vertex){
        //
        edk::shape::Vertex3DWithUV::print(vertex);edkEnd();printf(" multiply(%.2f %.2f)"
                                                         ,this->uvMultiply.x
                                                         ,this->uvMultiply.y
                                                         );edkEnd();
    }
    virtual bool writeToXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex3DWithUV::writeToXML(vertex,xml)){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);edkEnd();
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;edkEnd();
                        temp = edk::String::float32ToStr(this->uvMultiply.x);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvMX",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->uvMultiply.y);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvMY",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->uvSaved.x);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvSX",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->uvSaved.y);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvSY",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //
                        xml->selectFather();edkEnd();
                    }
                    free(name);edkEnd();
                }
                free(id);edkEnd();
            }
            return true;
        }
        return false;
    }
    virtual bool readFromXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex3DWithUV::readFromXML(vertex,xml)){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);edkEnd();
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);edkEnd();
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;edkEnd();
                        if((temp = xml->getSelectedAttributeValueByName("uvMX"))){
                            //read the value
                            this->uvMultiply.x = edk::String::strToFloat32(temp);edkEnd();
                            //free(temp);edkEnd();
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvMY"))){
                            //read the value
                            this->uvMultiply.y = edk::String::strToFloat32(temp);edkEnd();
                            //free(temp);edkEnd();
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvSX"))){
                            //read the value
                            this->uvSaved.x = edk::String::strToFloat32(temp);edkEnd();
                            //free(temp);edkEnd();
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvSY"))){
                            //read the value
                            this->uvSaved.y = edk::String::strToFloat32(temp);edkEnd();
                            //free(temp);edkEnd();
                        }
                        xml->selectFather();edkEnd();
                    }
                    free(name);edkEnd();
                }
                free(id);edkEnd();
            }
            return true;
        }
        return false;
    }

    //OPERATORS
    edk::shape::Vertex3DAnimatedUV operator=(edk::shape::Vertex3D vertex){
        //
        this->position=vertex.position;edkEnd();
        this->color=vertex.color;edkEnd();
        return edk::shape::Vertex3DAnimatedUV();edkEnd();
    }
    edk::shape::Vertex3DAnimatedUV operator=(edk::shape::Vertex3DWithUV vertex){
        //
        this->position=vertex.position;edkEnd();
        this->color=vertex.color;edkEnd();
        edk::shape::Vertex3DWithUV::setUV(vertex.getUV());edkEnd();
        //return vertex;edkEnd();
        return edk::shape::Vertex3DAnimatedUV();edkEnd();
    }
    edk::shape::Vertex3DAnimatedUV operator=(edk::shape::Vertex3DAnimatedUV vertex){
        //
        this->position=vertex.position;edkEnd();
        this->color=vertex.color;edkEnd();
        edk::shape::Vertex3DWithUV::setUV(vertex.getUV());edkEnd();
        this->uvMultiply=vertex.getMultiply();edkEnd();
        this->uvSaved=vertex.getSaved();edkEnd();
        //return vertex;edkEnd();
        return vertex;edkEnd();
    }
protected:
private:
    //multiply vector save the position of the vector in the first frame.
    edk::vec2f32 uvMultiply;edkEnd();

    //save que UVMap to clean the animation
    edk::vec2f32 uvSaved;edkEnd();
};
*/
}//end namespace shape
}//end namespace edk

#endif // VERTEX3D_H
