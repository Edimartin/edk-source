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
#include "../TypeVec2.h"
#include "../TypeVec3.h"
#include "../TypeColor.h"
#include "../TypeDefines.h"
#include "../vector/Matrix.h"
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
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    Vector3D(edk::float32 x,edk::float32 y,edk::float32 z){
        this->classThis=NULL;edkEnd();
        this->Constructor(x,y,z);edkEnd();
    }
    virtual ~Vector3D(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Constructor(edk::float32 x,edk::float32 y,edk::float32 z,bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->x=x;edkEnd();
            this->y=y;edkEnd();
            this->z=z;edkEnd();
        }
    }
    //functions to draw the vector as
    //VERTEX
    virtual void drawVertex(){
        //draw the vertex
        edk::GU::guVertex3f32(this->x, this->y,this->z);edkEnd();
    }
    virtual void drawVertexWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp){
        //draw the vertex
        matrixTemp->setIdentity(1.f,0.f);
        matrixTemp->set(0u,0u,this->x);edkEnd();
        matrixTemp->set(0u,1u,this->y);edkEnd();
        matrixTemp->set(0u,2u,this->z);edkEnd();
        //multiply the matrix
        matrixTemp->multiplyMatrixWithThis(matrix);edkEnd();
        this->temp.x = matrixTemp->get(0u,0u);edkEnd();
        this->temp.y = matrixTemp->get(0u,1u);edkEnd();
        this->temp.z = matrixTemp->get(0u,2u);edkEnd();
        edk::GU::guVertex3f32(this->temp.x, this->temp.y,this->temp.z);edkEnd();
    }
    virtual void drawVertexPosition(edk::vec3f32 position){
        //draw the vertex
        edk::GU::guVertex3f32(this->x+position.x, this->y+position.y,this->z+position.z);edkEnd();
    }
    virtual void drawVertexPositionWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,edk::vector::Matrixf32<4u,4u>* matrixTemp,edk::vec3f32 position){
        //draw the vertex
        matrixTemp->setIdentity(1.f,0.f);
        matrixTemp->set(0u,0u,this->x+position.x);edkEnd();
        matrixTemp->set(0u,1u,this->y+position.y);edkEnd();
        matrixTemp->set(0u,2u,this->z+position.z);edkEnd();
        //multiply the matrix
        matrixTemp->multiplyMatrixWithThis(matrix);edkEnd();
        this->temp.x = matrixTemp->get(0u,0u);edkEnd();
        this->temp.y = matrixTemp->get(0u,1u);edkEnd();
        this->temp.z = matrixTemp->get(0u,2u);edkEnd();
        edk::GU::guVertex3f32(this->temp.x, this->temp.y,this->temp.z);edkEnd();
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
    inline bool operator==(edk::shape::Vector3D vertex){
        if(this->x==vertex.x && this->y==vertex.y && this->z==vertex.z
                ){
            return true;
        }
        return false;
    }
    inline bool operator!=(edk::shape::Vector3D vertex){
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
    void drawNormalWithMatrix(edk::vector::Matrixf32<4u,4u>*,edk::vector::Matrixf32<4u,4u>*){
        //draw the normal
        edk::GU::guVertexNormal3f32(this->x, this->y,this->z);edkEnd();
    }
    void printNormal(){
        printf("\nNormal %.2f %.2f %.2f",
               this->x,this->y,this->z
               );edkEnd();
    }
private:
    edk::vec3f32 temp;
private:
    edk::classID classThis;
};

class UV3D{
public:
    UV3D(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    UV3D(edk::vec2f32 uv){
        this->classThis=NULL;edkEnd();
        this->Constructor(uv,false);edkEnd();
    }
    UV3D(edk::float32 uv){
        this->classThis=NULL;edkEnd();
        this->Constructor(uv,false);edkEnd();
    }
    UV3D(edk::float32 u,edk::float32 v){
        this->classThis=NULL;edkEnd();
        this->Constructor(u,v,false);edkEnd();
    }
    virtual ~UV3D(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->u=this->v=0.f;edkEnd();
        }
    }
    void Constructor(edk::vec2f32 uv,bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->u=uv.x;edkEnd();
            this->v=uv.y;edkEnd();
        }
    }
    void Constructor(edk::float32 uv,bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->u=uv;edkEnd();
            this->v=uv;edkEnd();
        }
    }
    void Constructor(edk::float32 u,edk::float32 v,bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->u=u;edkEnd();
            this->v=v;edkEnd();
        }
    }
    edk::shape::UV3D operator=(edk::shape::UV3D uv){
        this->u=uv.u;edkEnd();
        this->v=uv.v;edkEnd();
        return uv;edkEnd();
    }
    edk::shape::UV3D* operator=(edk::shape::UV3D* uv){
        this->u=uv->u;edkEnd();
        this->v=uv->v;edkEnd();
        return uv;edkEnd();
    }
    inline bool operator==(edk::shape::UV3D uv){
        if(this->u==uv.u && this->v==uv.v){
            return true;
        }
        return false;
    }
    inline bool operator!=(edk::shape::UV3D uv){
        if(this->u!=uv.u || this->v!=uv.v){
            return true;
        }
        return false;
    }
    void drawUV(){
        //draw the UV
        edk::GU::guVertexTex2f32(this->u,this->v);edkEnd();
    }
    void printUV(){
        printf("\nUV %.2f %.2f"
               ,this->u
               ,this->v
               );fflush(stdout);edkEnd();
    }
    edk::float32 u,v;
private:
    edk::classID classThis;
};
class Vertex3D{
public:
    Vertex3D(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    virtual ~Vertex3D(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->color.a=1u;
            this->normal = edk::vec3f32(0.f,0.f,1.f);
            this->type = EDK_SHAPE_NOUV;
        }
    }

    //position
    edk::vec3f32 position;
    //color
    edk::color4f32 color;
    //normal
    edk::vec3f32 normal;

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
        edk::GU::guVertexNormal3f32(this->normal.x+this->position.z,
                                    this->normal.y+this->position.y,
                                    this->normal.z+this->position.z
                                    );edkEnd();

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, this->position.z);edkEnd();
    }
    virtual void drawNormalWithColor(edk::color4f32 color = edk::color4f32(1,1,1,1)){
        //Draw

        //set the color of the vertex
        edk::GU::guColor4f32(color.r,
                             color.g,
                             color.b,
                             color.a
                             );edkEnd();

        //draw the normal
        edk::GU::guVertex3f32(this->normal.x+this->position.x,
                              this->normal.y+this->position.y,
                              this->normal.z+this->position.z
                              );edkEnd();

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
        edk::GU::guVertexNormal3f32(this->normal.x,
                                    this->normal.y,
                                    this->normal.z
                                    );edkEnd();

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, this->position.z);edkEnd();
    }
    virtual void drawNormal(){
        //Draw

        //set the color of the vertex
        edk::GU::guColor4f32(this->color.r,
                             this->color.g,
                             this->color.b,
                             this->color.a
                             );edkEnd();

        //draw the normal
        edk::GU::guVertex3f32(this->normal.x,
                              this->normal.y,
                              this->normal.z
                              );edkEnd();

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, this->position.z);edkEnd();
    }
    //print function
    virtual void print(){
        //
        printf("\nVector position(%.2f %.2f %.2f) Color (%.2f %.2f %.2f %.2f) Normal(%.2f %.2f %.2f)"
               ,this->position.x
               ,this->position.y
               ,this->position.z

               ,this->color.r
               ,this->color.g
               ,this->color.b
               ,this->color.a

               ,this->normal.x
               ,this->normal.y
               ,this->normal.z
               );fflush(stdout);edkEnd();
    }
    virtual void print(edk::uint32 vertex){
        //
        printf("\nVector [%u] position(%.2f %.2f %.2f) Color (%.2f %.2f %.2f %.2f) normal(%.2f %.2f %.2f)"
               ,vertex
               ,this->position.x
               ,this->position.y
               ,this->position.z

               ,this->color.r
               ,this->color.g
               ,this->color.b
               ,this->color.a

               ,this->normal.x
               ,this->normal.z
               ,this->normal.y
               );fflush(stdout);edkEnd();
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
                            temp = edk::String::float32ToStr(this->normal.x);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"nx",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->normal.y);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"ny",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                            temp = edk::String::float32ToStr(this->normal.z);edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"nz",temp);edkEnd();
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
                            if((temp = xml->getSelectedAttributeValueByName("nx"))){
                                //read the value
                                this->normal.x = edk::String::strToFloat32(temp);edkEnd();
                                //free(temp);edkEnd();
                            }
                            if((temp = xml->getSelectedAttributeValueByName("ny"))){
                                //read the value
                                this->normal.y = edk::String::strToFloat32(temp);edkEnd();
                                //free(temp);edkEnd();
                            }
                            if((temp = xml->getSelectedAttributeValueByName("nz"))){
                                //read the value
                                this->normal.z = edk::String::strToFloat32(temp);edkEnd();
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
    edk::uint8 type;
private:
    edk::classID classThis;
};

//Add the UV to the vertex
class Vertex3DWithUV: public edk::shape::Vertex3D{
public:
    Vertex3DWithUV(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    virtual ~Vertex3DWithUV(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::shape::Vertex3D::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->type = EDK_SHAPE_UV;edkEnd();
        }
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
        //draw the vector3D
        edk::shape::Vertex3D::drawWithColor(color);edkEnd();
    }
    //draw function
    virtual void draw(){
        //Add the UV
        edk::GU::guVertexTex2f32(this->uv.x,this->uv.y);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,this->uv.x,this->uv.y);edkEnd();
        //draw the vector3D
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
    edk::vec2f32 uv;
private:
    edk::classID classThis;
};

class Vertex3DAnimatedUV: public edk::shape::Vertex3DWithUV{
    //
public:
    Vertex3DAnimatedUV(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    virtual ~Vertex3DAnimatedUV(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::shape::Vertex3DWithUV::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->type = EDK_SHAPE_ANIMATED_UV;edkEnd();
        }
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
        return this->uvMultiply;
    }
    //get the uvFrames
    edk::vec2ui32 getUVFrames(){
        return edk::vec2ui32((edk::uint32)(1.f/this->uvMultiply.x),
                             (edk::uint32)(1.f/this->uvMultiply.y)
                             );
    }
    edk::vec2f32 getSaved(){
        return this->uvSaved;
    }

    //Animation
    void cleanUVAnimation(){
        //this->uv=this->uvSaved;edkEnd();
        this->setUV(this->uvSaved);edkEnd();
    }
    //set the animationFrames
    bool setUVFrames(edk::vec2ui32 frames){
        //test if the frames are true
        if(frames.x && frames.y){
            //set the frames for the UV position
            this->uvMultiply.x = /*this->uvSaved.x*/1.f/(edk::float32)frames.x;edkEnd();
            this->uvMultiply.y = /*this->uvSaved.y*/1.f/(edk::float32)frames.y;edkEnd();
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
        //draw the vector3D
        edk::shape::Vertex3DWithUV::drawWithColor(color);edkEnd();
    }
    //draw function
    virtual void draw(){
        //draw the vector3D
        edk::shape::Vertex3DWithUV::draw();edkEnd();
    }
    //print function
    virtual void print(){
        //
        edk::shape::Vertex3DWithUV::print();edkEnd(); printf(" multiply(%.2f %.2f)"
                                                             ,this->uvMultiply.x
                                                             ,this->uvMultiply.y
                                                             );fflush(stdout);edkEnd();
    }
    virtual void print(edk::uint32 vertex){
        //
        edk::shape::Vertex3DWithUV::print(vertex);edkEnd();printf(" multiply(%.2f %.2f)"
                                                                  ,this->uvMultiply.x
                                                                  ,this->uvMultiply.y
                                                                  );fflush(stdout);edkEnd();
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
    edk::vec2f32 uvMultiply;

    //save que UVMap to clean the animation
    edk::vec2f32 uvSaved;
private:
    edk::classID classThis;
};

}//end namespace shape
}//end namespace edk

#endif // VERTEX3D_H
