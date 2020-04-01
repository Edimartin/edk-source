#ifndef VERTEX3D_H
#define VERTEX3D_H

/*
Library vertex3D - Draw a 3D vertex in EDK Game Engine
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
#warning "Inside Vertex3D"
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
#warning "    Compiling Vertex3D"
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
        this->x=x;
        this->y=y;
        this->z=z;
    }
    virtual ~Vector3D(){}
    //functions to draw the vector as
    //VERTEX
    virtual void drawVertex(){
        //draw the vertex
        edk::GU::guVertex3f32(this->x, this->y,this->z);
    }
    virtual void printVertex(){
        printf("\nVertex %.2f %.2f %.2f",
               this->x,this->y,this->z
               );
    }
    //OPERATORS
    edk::shape::Vector3D operator=(edk::shape::Vector3D vertex){
        this->x=vertex.x;
        this->y=vertex.y;
        this->z=vertex.z;
        return vertex;
    }
    edk::vec3f32 operator=(edk::vec3f32 vertex){
        this->x=vertex.x;
        this->y=vertex.y;
        this->z=vertex.z;
        return vertex;
    }
    bool operator==(edk::shape::Vector3D vertex){
        if(this->x==vertex.x && this->y==vertex.y && this->z==vertex.z
                )
            return true;
        return false;
    }
    bool operator!=(edk::shape::Vector3D vertex){
        if(this->x!=vertex.x || this->y!=vertex.y || this->z!=vertex.z
                )
            return true;
        return false;
    }
    //NORMAL
    void drawNormal(){
        //draw the normal
        edk::GU::guVertexNormal3f32(this->x, this->y,this->z);
    }
    void printNormal(){
        printf("\nNormal %.2f %.2f %.2f",
               this->x,this->y,this->z
               );
    }
};

class Vertex3D : public edk::shape::Vector3D{
public:
    Vertex3D(){
        this->x=this->y=this->z=0.f;
        this->r=this->g=this->b=this->a=1.f;
    }
    Vertex3D(edk::vec3f32 position){
        this->x=position.x;
        this->y=position.y;
        this->z=position.z;
        this->r=this->g=this->b=this->a=1.f;
    }
    Vertex3D(edk::vec3f32 position,edk::color3f32 color){
        this->x=position.x;
        this->y=position.y;
        this->z=position.z;
        this->r=color.r;
        this->g=color.g;
        this->b=color.b;
        this->a=1.f;
    }
    Vertex3D(edk::vec3f32 position,edk::color4f32 color){
        this->x=position.x;
        this->y=position.y;
        this->z=position.z;
        this->r=color.r;
        this->g=color.g;
        this->b=color.b;
        this->a=color.a;
    }
    Vertex3D(edk::float32 x,edk::float32 y,edk::float32 z){
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=this->g=this->b=this->a=1.f;
    }
    Vertex3D(edk::float32 x,edk::float32 y,edk::float32 z,
             edk::float32 r,edk::float32 g,edk::float32 b
             ){
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
        this->g=g;
        this->b=b;
        this->a=1.f;
    }
    Vertex3D(edk::float32 x,edk::float32 y,edk::float32 z,
             edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a
             ){
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
        this->g=g;
        this->b=b;
        this->a=a;
    }
    virtual ~Vertex3D(){}
    //OPERATORS
    edk::shape::Vertex3D operator=(edk::shape::Vertex3D vertex){
        this->x=vertex.x;
        this->y=vertex.y;
        this->z=vertex.z;
        this->r = vertex.r;
        this->g = vertex.g;
        this->b = vertex.b;
        this->a = vertex.a;
        return vertex;
    }
    bool operator==(edk::shape::Vertex3D vertex){
        if(this->x==vertex.x && this->y==vertex.y && this->z==vertex.z
                &&
                this->r==vertex.r && this->g==vertex.g && this->b==vertex.b && this->a==vertex.a
                )
            return true;
        return false;
    }
    bool operator!=(edk::shape::Vertex3D vertex){
        if(this->x!=vertex.x || this->y!=vertex.y || this->z!=vertex.z
                ||
                this->r!=vertex.r || this->g!=vertex.g || this->b!=vertex.b || this->a!=vertex.a
                )
            return true;
        return false;
    }
    //VERTEX
    void drawVertex(){
        //set the color of the vertex
        edk::GU::guColor4f32(this->r,
                             this->g,
                             this->b,
                             this->a
                             );
        //draw the vertex
        edk::shape::Vector3D::drawVertex();
    }
    void drawVertexWithColor(edk::color4f32 color){
        //set the color of the vertex
        edk::GU::guColor4f32(color.r,
                             color.g,
                             color.b,
                             color.a
                             );
        //draw the vertex
        edk::shape::Vector3D::drawVertex();
    }

    void printVertex(){
        printf("\nColor %.2f %.2f %.2f %.2f",
               this->r,this->g,this->b,this->a
               );
        //print the vertex
        edk::shape::Vector3D::printVertex();
    }
    edk::float32 r,g,b,a;
};

/*
class Vertex3D{
public:
    Vertex3D(){
        //
        this->color.a=1u;
        this->type = EDK_SHAPE_NOUV;
        this->position = 0.f;
        this->normal = 0.f;
    }
    virtual ~Vertex3D(){
        //
    }

    //position
    edk::vec3f32 position;
    //position
    edk::vec3f32 normal;
    //color
    edk::color4f32 color;

    //draw function
    virtual void drawWithColor(edk::color4f32 color = edk::color4f32(1,1,1,1)){
        //Draw

        //set the color of the vertex
        edk::GU::guColor4f32(color.r,
                             color.g,
                             color.b,
                             color.a
                             );

        //draw the normal
        edk::GU::guVertexNormal3f32(this->position.x, this->position.y,1.f);

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, this->position.z);
    }

    //draw function
    virtual void draw(){
        //Draw

        //set the color of the vertex
        edk::GU::guColor4f32(this->color.r,
                             this->color.g,
                             this->color.b,
                             this->color.a
                             );

        //draw the normal
        edk::GU::guVertexNormal3f32(this->position.x, this->position.y,1.f);

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, this->position.z);
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
               );
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
               );
    }
    virtual bool writeToXML(edk::uint32 vertex,edk::XML* xml){
        if(xml){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);
                if(name){
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            //set attribute
                            edk::char8* temp = NULL;
                            temp = edk::String::int32ToStr((edk::int32)this->getType());
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"type",temp);
                                delete[] temp;
                            }
                            temp = edk::String::float32ToStr(this->position.x);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"x",temp);
                                delete[] temp;
                            }
                            temp = edk::String::float32ToStr(this->position.y);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"y",temp);
                                delete[] temp;
                            }
                            temp = edk::String::float32ToStr(this->position.z);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"z",temp);
                                delete[] temp;
                            }
                            temp = edk::String::float32ToStr(this->color.r);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"r",temp);
                                delete[] temp;
                            }
                            temp = edk::String::float32ToStr(this->color.g);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"g",temp);
                                delete[] temp;
                            }
                            temp = edk::String::float32ToStr(this->color.b);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"b",temp);
                                delete[] temp;
                            }
                            temp = edk::String::float32ToStr(this->color.a);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"a",temp);
                                delete[] temp;
                            }
                            //
                            xml->selectFather();
                        }
                    }
                    delete[] name;
                }
                delete[] id;
            }
            return true;
        }
        return false;
    }
    virtual bool readFromXML(edk::uint32 vertex,edk::XML* xml){
        if(xml){
            bool ret=false;
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;
                        if((temp = xml->getSelectedAttributeValueByName("type"))){
                            //read the type
                            //edk::uint8 typeTemp = (edk::uint8)edk::String::strToInt32(temp);
                            //delete[] temp;
                            //test if the type is the same
                            //if(typeTemp==this->getType()){
                                if((temp = xml->getSelectedAttributeValueByName("x"))){
                                    //read the value
                                    this->position.x = edk::String::strToFloat32(temp);
                                    //delete[] temp;
                                }
                                if((temp = xml->getSelectedAttributeValueByName("y"))){
                                    //read the value
                                    this->position.y = edk::String::strToFloat32(temp);
                                    //delete[] temp;
                                }
                                if((temp = xml->getSelectedAttributeValueByName("z"))){
                                    //read the value
                                    this->position.z = edk::String::strToFloat32(temp);
                                    //delete[] temp;
                                }
                                if((temp = xml->getSelectedAttributeValueByName("r"))){
                                    //read the value
                                    this->color.r = edk::String::strToFloat32(temp);
                                    //delete[] temp;
                                }
                                if((temp = xml->getSelectedAttributeValueByName("g"))){
                                    //read the value
                                    this->color.g = edk::String::strToFloat32(temp);
                                    //delete[] temp;
                                }
                                if((temp = xml->getSelectedAttributeValueByName("b"))){
                                    //read the value
                                    this->color.b = edk::String::strToFloat32(temp);
                                    //delete[] temp;
                                }
                                if((temp = xml->getSelectedAttributeValueByName("a"))){
                                    //read the value
                                    this->color.a = edk::String::strToFloat32(temp);
                                    //delete[] temp;
                                }
                                ret=true;
                            //}
                        }
                        xml->selectFather();
                    }
                    delete[] name;
                }
                delete[] id;
            }
            return ret;
        }
        return false;
    }
    //read the vertexType from XML
    static edk::uint8 readTypeFromXML(edk::uint32 vertex,edk::XML* xml){
        if(xml){
            edk::uint8 ret=0u;
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;
                        if((temp = xml->getSelectedAttributeValueByName("type"))){
                            ret = edk::String::strToInt32(temp);
                        }
                        xml->selectFather();
                    }
                    delete[] name;
                }
                delete[] id;
            }
            return ret;
        }
        return 0u;
    }

    //Just return the type of the vertex
    virtual edk::uint8 getType(){
        //
        return this->type;
    }

    //OPERATORS
    edk::shape::Vertex3D operator=(edk::shape::Vertex3D vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        return vertex;
    }
protected:
    edk::uint8 type;
private:
};

//Add the UV to the vertex
class Vertex3DWithUV: public edk::shape::Vertex3D{
public:
    Vertex3DWithUV(){
        //
        this->type = EDK_SHAPE_UV;
    }
    virtual ~Vertex3DWithUV(){
        //
    }



    //SETERS
    //Set the UV parameter.
    void setUV(edk::vec2f32 uv){
        //
        this->uv= uv;
    }
    void setUV(edk::float32 x,edk::float32 y){
        //
        this->setUV(edk::vec2f32(x,y));
    }
    void setUVX(edk::float32 x){
        //
        this->uv.x= x;
    }
    void setUVY(edk::float32 y){
        //
        this->uv.y= y;
    }

    //GETERS
    edk::vec2f32 getUV(){
        //
        return this->uv;
    }
    edk::float32 getUVX(){
        //
        return this->uv.x;
    }
    edk::float32 getUVY(){
        //
        return this->uv.y;
    }

    //draw function
    virtual void drawWithColor(edk::color4f32 color = edk::color4f32(1,1,1,1)){
        //Add the UV
        edk::GU::guVertexTex2f32(this->uv.x,this->uv.y);
        //glMultiTexCoord2f(GL_TEXTURE0,this->uv.x,this->uv.y);
        //draw the vector2D
        edk::shape::Vertex3D::drawWithColor(color);
    }
    //draw function
    virtual void draw(){
        //Add the UV
        edk::GU::guVertexTex2f32(this->uv.x,this->uv.y);
        //glMultiTexCoord2f(GL_TEXTURE0,this->uv.x,this->uv.y);
        //draw the vector2D
        edk::shape::Vertex3D::draw();
    }
    //print function
    virtual void print(){
        edk::shape::Vertex3D::print();
        //add the UV to the print
        printf("UV(%.2f %.2f)"
               ,this->uv.x
               ,this->uv.y
               );
    }
    virtual void print(edk::uint32 vertex){
        edk::shape::Vertex3D::print(vertex);
        //add the UV to the print
        printf("\nUV(%.2f %.2f)"
               ,this->uv.x
               ,this->uv.y
               );
    }
    virtual bool writeToXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex3D::writeToXML(vertex,xml)){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;
                        temp = edk::String::float32ToStr(this->uv.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvX",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->uv.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvY",temp);
                            delete[] temp;
                        }
                        //
                        xml->selectFather();
                    }
                    delete[] name;
                }
                delete[] id;
            }
            return true;
        }
        return false;
    }
    virtual bool readFromXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex3D::readFromXML(vertex,xml)){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;
                        if((temp = xml->getSelectedAttributeValueByName("uvX"))){
                            //read the value
                            this->uv.x = edk::String::strToFloat32(temp);
                            //delete[] temp;
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvY"))){
                            //read the value
                            this->uv.y = edk::String::strToFloat32(temp);
                            //delete[] temp;
                        }
                        xml->selectFather();
                    }
                    delete[] name;
                }
                delete[] id;
            }
            return true;
        }
        return false;
    }

    //OPERATORS
    edk::shape::Vertex3DWithUV operator=(edk::shape::Vertex3D vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        return edk::shape::Vertex3DWithUV();
    }
    edk::shape::Vertex3DWithUV operator=(edk::shape::Vertex3DWithUV vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        this->uv=uv;
        return vertex;
    }
protected:
private:
    //uvMap is private because the Vertex3DUVAnimated modify the setUV
    edk::vec2f32 uv;
};

class Vertex3DAnimatedUV: public edk::shape::Vertex3DWithUV{
    //
public:
    Vertex3DAnimatedUV(){
        //
        this->type = EDK_SHAPE_ANIMATED_UV;
    }
    virtual ~Vertex3DAnimatedUV(){
        //
    }



    //SETERS
    //Set the UV and the uvSaved
    void setUV(edk::vec2f32 uv){
        //
        edk::shape::Vertex3DWithUV::setUV(uv);
        this->uvSaved= uv;
    }
    void setUV(edk::float32 x,edk::float32 y){
        //
        edk::shape::Vertex3DWithUV::setUV(x,y);
        this->setUV(edk::vec2f32(x,y));
    }

    //GETTERS
    edk::vec2f32 getMultiply(){
        //
        return this->uvMultiply;
    }
    edk::vec2f32 getSaved(){
        //
        return this->uvSaved;
    }

    //Animation
    void cleanUVAnimation(){
        //
        //this->uv=this->uvSaved;
        this->setUV(this->uvSaved);
    }
    //set the animationFrames
    bool setUVFrames(edk::vec2ui32 frames){
        //test if the frames are true
        if(frames.x && frames.y){
            //set the frames for the UV position
            this->uvMultiply.x = 1.f/(edk::float32)frames.x;
            this->uvMultiply.y = 1.f/(edk::float32)frames.y;
            //set the frame
            this->useUVFrame(edk::vec2ui32(0u,0u));
            //return true
            return true;
        }
        //else return false
        return false;
    }
    bool setUVFrames(edk::uint32 x,edk::uint32 y){
        //
        return this->setUVFrames(edk::vec2ui32(x,y));
    }
    //set the uvFrame
    void useUVFrame(edk::vec2ui32 frame){
        //set the uvFrame
        edk::shape::Vertex3DWithUV::setUV( this->uvMultiply.x * frame.x + this->uvSaved.x*this->uvMultiply.x
                                           ,this->uvMultiply.y * frame.y + this->uvSaved.y*this->uvMultiply.y
                                           );
    }
    void useUVFrame(edk::uint32 x,edk::uint32 y){
        //
        this->useUVFrame(edk::vec2ui32(x,y));
    }
    //
    void useUVFrameX(edk::uint32 x){
        //
        //this->uv.x = this->uvMultiply.x * (x+1u);
        edk::shape::Vertex3DWithUV::setUVX(this->uvMultiply.x * x + this->uvSaved.x*this->uvMultiply.x);
    }
    void useUVFrameY(edk::uint32 y){
        //
        //this->uv.y = this->uvMultiply.y * (y+1u);
        edk::shape::Vertex3DWithUV::setUVY(this->uvMultiply.y * y + this->uvSaved.y*this->uvMultiply.y);
    }

    //draw function
    virtual void drawWithColor(edk::color4f32 color = edk::color4f32(1,1,1,1)){
        //draw the vector2D
        edk::shape::Vertex3DWithUV::drawWithColor(color);
    }
    //draw function
    virtual void draw(){
        //draw the vector2D
        edk::shape::Vertex3DWithUV::draw();
    }
    //print function
    virtual void print(){
        //
        edk::shape::Vertex3DWithUV::print(); printf(" multiply(%.2f %.2f)"
                                                    ,this->uvMultiply.x
                                                    ,this->uvMultiply.y
                                                    );
    }
    virtual void print(edk::uint32 vertex){
        //
        edk::shape::Vertex3DWithUV::print(vertex);printf(" multiply(%.2f %.2f)"
                                                         ,this->uvMultiply.x
                                                         ,this->uvMultiply.y
                                                         );
    }
    virtual bool writeToXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex3DWithUV::writeToXML(vertex,xml)){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;
                        temp = edk::String::float32ToStr(this->uvMultiply.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvMX",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->uvMultiply.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvMY",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->uvSaved.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvSX",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->uvSaved.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvSY",temp);
                            delete[] temp;
                        }
                        //
                        xml->selectFather();
                    }
                    delete[] name;
                }
                delete[] id;
            }
            return true;
        }
        return false;
    }
    virtual bool readFromXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex3DWithUV::readFromXML(vertex,xml)){
            edk::char8* id = edk::String::int64ToStr((edk::int64)vertex);
            if(id){
                edk::char8* name = edk::String::strCat((edk::char8*)"Vertex_",id);
                if(name){
                    if(xml->selectChild(name)){
                        //set attribute
                        edk::char8* temp = NULL;
                        if((temp = xml->getSelectedAttributeValueByName("uvMX"))){
                            //read the value
                            this->uvMultiply.x = edk::String::strToFloat32(temp);
                            //delete[] temp;
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvMY"))){
                            //read the value
                            this->uvMultiply.y = edk::String::strToFloat32(temp);
                            //delete[] temp;
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvSX"))){
                            //read the value
                            this->uvSaved.x = edk::String::strToFloat32(temp);
                            //delete[] temp;
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvSY"))){
                            //read the value
                            this->uvSaved.y = edk::String::strToFloat32(temp);
                            //delete[] temp;
                        }
                        xml->selectFather();
                    }
                    delete[] name;
                }
                delete[] id;
            }
            return true;
        }
        return false;
    }

    //OPERATORS
    edk::shape::Vertex3DAnimatedUV operator=(edk::shape::Vertex3D vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        return edk::shape::Vertex3DAnimatedUV();
    }
    edk::shape::Vertex3DAnimatedUV operator=(edk::shape::Vertex3DWithUV vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        edk::shape::Vertex3DWithUV::setUV(vertex.getUV());
        //return vertex;
        return edk::shape::Vertex3DAnimatedUV();
    }
    edk::shape::Vertex3DAnimatedUV operator=(edk::shape::Vertex3DAnimatedUV vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        edk::shape::Vertex3DWithUV::setUV(vertex.getUV());
        this->uvMultiply=vertex.getMultiply();
        this->uvSaved=vertex.getSaved();
        //return vertex;
        return vertex;
    }
protected:
private:
    //multiply vector save the position of the vector in the first frame.
    edk::vec2f32 uvMultiply;

    //save que UVMap to clean the animation
    edk::vec2f32 uvSaved;
};
*/
}//end namespace shape
}//end namespace edk

#endif // VERTEX3D_H
