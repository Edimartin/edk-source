#ifndef EDK_SHAPE_VERTEX2D_H
#define EDK_SHAPE_VERTEX2D_H

/*
Library vertex2D - Draw a 2D vertex in EDK Game Engine
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
#pragma message "Inside Vertex2D"
#endif

#pragma once
#include <stdio.h>
#include "../TypeVec2.h"
#include "../TypeColor.h"
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../xml/XML.h"

#ifdef printMessages
#pragma message "    Compiling Vertex2D"
#endif

namespace edk{
namespace shape{

//type of the vertex
//EDK_SHAPE_ANIMATED_UV
//EDK_SHAPE_UV
//EDK_SHAPE_NOUV

class UV2D{
public:
    UV2D(){
        this->classThis=NULL;
        this->Constructor();
    }
    UV2D(edk::vec2f32 uv){
        this->classThis=NULL;
        this->Constructor(uv);
    }
    UV2D(edk::float32 uv){
        this->classThis=NULL;
        this->Constructor(uv);
    }
    UV2D(edk::float32 u,edk::float32 v){
        this->classThis=NULL;
        this->Constructor(u,v);
    }
    virtual ~UV2D(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            this->u=this->v=0.f;
        }
    }
    void Constructor(edk::vec2f32 uv){
        if(this->classThis!=this){
            this->classThis=this;
            this->u=uv.x;
            this->v=uv.y;
        }
    }
    void Constructor(edk::float32 uv){
        if(this->classThis!=this){
            this->classThis=this;
            this->u=uv;
            this->v=uv;
        }
    }
    void Constructor(edk::float32 u,edk::float32 v){
        if(this->classThis!=this){
            this->classThis=this;
            this->u=u;
            this->v=v;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }
    edk::shape::UV2D operator=(edk::shape::UV2D uv){
        this->u=uv.u;
        this->v=uv.v;
        return uv;
    }
    edk::shape::UV2D* operator=(edk::shape::UV2D* uv){
        this->u=uv->u;
        this->v=uv->v;
        return uv;
    }
    inline bool operator==(edk::shape::UV2D uv){
        if(this->u==uv.u && this->v==uv.v){
            return true;
        }
        return false;
    }
    inline bool operator!=(edk::shape::UV2D uv){
        if(this->u!=uv.u || this->v!=uv.v){
            return true;
        }
        return false;
    }
    void drawUV(){
        //draw the UV
        edk::GU::guVertexTex2f32(this->u,this->v);
    }
    void printUV(){
        printf("\nUV %.2f %.2f"
               ,this->u
               ,this->v
               );fflush(stdout);
    }
    edk::float32 u,v;
private:
    edk::classID classThis;
};
class Vertex2D{
public:
    Vertex2D(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~Vertex2D(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            this->color.a=1u;
            this->type = EDK_SHAPE_NOUV;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

    //position
    edk::vec2f32 position;
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
        edk::GU::guVertexNormal3f32(0.f, 0.f,1.f);

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, 0.0f);
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
        edk::GU::guVertexNormal3f32(0.f, 0.f,1.f);

        //draw the vertex
        edk::GU::guVertex3f32( this->position.x, this->position.y, 0.0f);
    }
    //print function
    virtual void print(){
        //
        printf("\nVector position(%.2f %.2f) Color (%.2f %.2f %.2f %.2f)"
               ,this->position.x
               ,this->position.y

               ,this->color.r
               ,this->color.g
               ,this->color.b
               ,this->color.a
               );fflush(stdout);
    }
    virtual void print(edk::uint32 vertex){
        //
        printf("\nVector [%u] position(%.2f %.2f) Color (%.2f %.2f %.2f %.2f)"
               ,vertex
               ,this->position.x
               ,this->position.y

               ,this->color.r
               ,this->color.g
               ,this->color.b
               ,this->color.a
               );fflush(stdout);
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
                                free(temp);
                            }
                            temp = edk::String::float32ToStr(this->position.x);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"x",temp);
                                free(temp);
                            }
                            temp = edk::String::float32ToStr(this->position.y);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"y",temp);
                                free(temp);
                            }
                            temp = edk::String::float32ToStr(this->color.r);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"r",temp);
                                free(temp);
                            }
                            temp = edk::String::float32ToStr(this->color.g);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"g",temp);
                                free(temp);
                            }
                            temp = edk::String::float32ToStr(this->color.b);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"b",temp);
                                free(temp);
                            }
                            temp = edk::String::float32ToStr(this->color.a);
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"a",temp);
                                free(temp);
                            }
                            //
                            xml->selectFather();
                        }
                    }
                    free(name);
                }
                free(id);
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
                            //free(temp);
                            //test if the type is the same
                            //if(typeTemp==this->getType()){
                            if((temp = xml->getSelectedAttributeValueByName("x"))){
                                //read the value
                                this->position.x = edk::String::strToFloat32(temp);
                                //free(temp);
                            }
                            if((temp = xml->getSelectedAttributeValueByName("y"))){
                                //read the value
                                this->position.y = edk::String::strToFloat32(temp);
                                //free(temp);
                            }
                            if((temp = xml->getSelectedAttributeValueByName("r"))){
                                //read the value
                                this->color.r = edk::String::strToFloat32(temp);
                                //free(temp);
                            }
                            if((temp = xml->getSelectedAttributeValueByName("g"))){
                                //read the value
                                this->color.g = edk::String::strToFloat32(temp);
                                //free(temp);
                            }
                            if((temp = xml->getSelectedAttributeValueByName("b"))){
                                //read the value
                                this->color.b = edk::String::strToFloat32(temp);
                                //free(temp);
                            }
                            if((temp = xml->getSelectedAttributeValueByName("a"))){
                                //read the value
                                this->color.a = edk::String::strToFloat32(temp);
                                //free(temp);
                            }
                            ret=true;
                            //}
                        }
                        xml->selectFather();
                    }
                    free(name);
                }
                free(id);
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
                    free(name);
                }
                free(id);
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
    edk::shape::Vertex2D operator=(edk::shape::Vertex2D vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        return vertex;
    }
protected:
    edk::uint8 type;
private:
    edk::classID classThis;
};

//Add the UV to the vertex
class Vertex2DWithUV: public edk::shape::Vertex2D{
public:
    Vertex2DWithUV(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~Vertex2DWithUV(){
        this->Destructor();
    }

    void Constructor(){
        edk::shape::Vertex2D::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->type = EDK_SHAPE_UV;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
        edk::shape::Vertex2D::Destructor();
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
        edk::shape::Vertex2D::drawWithColor(color);
    }
    //draw function
    virtual void draw(){
        //Add the UV
        edk::GU::guVertexTex2f32(this->uv.x,this->uv.y);
        //glMultiTexCoord2f(GL_TEXTURE0,this->uv.x,this->uv.y);
        //draw the vector2D
        edk::shape::Vertex2D::draw();
    }
    //print function
    virtual void print(){
        edk::shape::Vertex2D::print();
        //add the UV to the print
        printf("UV(%.2f %.2f)"
               ,this->uv.x
               ,this->uv.y
               );
    }
    virtual void print(edk::uint32 vertex){
        edk::shape::Vertex2D::print(vertex);
        //add the UV to the print
        printf("\nUV(%.2f %.2f)"
               ,this->uv.x
               ,this->uv.y
               );
    }
    virtual bool writeToXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex2D::writeToXML(vertex,xml)){
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
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->uv.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvY",temp);
                            free(temp);
                        }
                        //
                        xml->selectFather();
                    }
                    free(name);
                }
                free(id);
            }
            return true;
        }
        return false;
    }
    virtual bool readFromXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex2D::readFromXML(vertex,xml)){
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
                            //free(temp);
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvY"))){
                            //read the value
                            this->uv.y = edk::String::strToFloat32(temp);
                            //free(temp);
                        }
                        xml->selectFather();
                    }
                    free(name);
                }
                free(id);
            }
            return true;
        }
        return false;
    }

    //OPERATORS
    edk::shape::Vertex2DWithUV operator=(edk::shape::Vertex2D vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        return edk::shape::Vertex2DWithUV();
    }
    edk::shape::Vertex2DWithUV operator=(edk::shape::Vertex2DWithUV vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        this->uv=uv;
        return vertex;
    }
protected:
private:
    //uvMap is private because the Vertex2DUVAnimated modify the setUV
    edk::vec2f32 uv;
private:
    edk::classID classThis;
};

class Vertex2DAnimatedUV: public edk::shape::Vertex2DWithUV{
    //
public:
    Vertex2DAnimatedUV(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~Vertex2DAnimatedUV(){
        this->Destructor();
    }

    void Constructor(){
        edk::shape::Vertex2DWithUV::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->type = EDK_SHAPE_ANIMATED_UV;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
        edk::shape::Vertex2DWithUV::Destructor();
    }

    //SETERS
    //Set the UV and the uvSaved
    void setUV(edk::vec2f32 uv){
        //
        edk::shape::Vertex2DWithUV::setUV(uv);
        this->uvSaved= uv;
    }
    void setUV(edk::float32 x,edk::float32 y){
        //
        edk::shape::Vertex2DWithUV::setUV(x,y);
        this->setUV(edk::vec2f32(x,y));
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
        //this->uv=this->uvSaved;
        this->setUV(this->uvSaved);
    }
    //set the animationFrames
    bool setUVFrames(edk::vec2ui32 frames){
        //test if the frames are true
        if(frames.x && frames.y){
            //set the frames for the UV position
            this->uvMultiply.x = /*this->uvSaved.x*/1.f/(edk::float32)frames.x;
            this->uvMultiply.y = /*this->uvSaved.y*/1.f/(edk::float32)frames.y;
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
        edk::shape::Vertex2DWithUV::setUV( this->uvMultiply.x * frame.x + this->uvSaved.x*this->uvMultiply.x
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
        edk::shape::Vertex2DWithUV::setUVX(this->uvMultiply.x * x + this->uvSaved.x*this->uvMultiply.x);
    }
    void useUVFrameY(edk::uint32 y){
        //
        //this->uv.y = this->uvMultiply.y * (y+1u);
        edk::shape::Vertex2DWithUV::setUVY(this->uvMultiply.y * y + this->uvSaved.y*this->uvMultiply.y);
    }

    //draw function
    virtual void drawWithColor(edk::color4f32 color = edk::color4f32(1,1,1,1)){
        //draw the vector2D
        edk::shape::Vertex2DWithUV::drawWithColor(color);
    }
    //draw function
    virtual void draw(){
        //draw the vector2D
        edk::shape::Vertex2DWithUV::draw();
    }
    //print function
    virtual void print(){
        //
        edk::shape::Vertex2DWithUV::print();  printf(" multiply(%.2f %.2f)"
                                                     ,this->uvMultiply.x
                                                     ,this->uvMultiply.y
                                                     );fflush(stdout);
    }
    virtual void print(edk::uint32 vertex){
        //
        edk::shape::Vertex2DWithUV::print(vertex); printf(" multiply(%.2f %.2f)"
                                                          ,this->uvMultiply.x
                                                          ,this->uvMultiply.y
                                                          );fflush(stdout);
    }
    virtual bool writeToXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex2DWithUV::writeToXML(vertex,xml)){
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
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->uvMultiply.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvMY",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->uvSaved.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvSX",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->uvSaved.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"uvSY",temp);
                            free(temp);
                        }
                        //
                        xml->selectFather();
                    }
                    free(name);
                }
                free(id);
            }
            return true;
        }
        return false;
    }
    virtual bool readFromXML(edk::uint32 vertex,edk::XML* xml){
        if(edk::shape::Vertex2DWithUV::readFromXML(vertex,xml)){
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
                            //free(temp);
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvMY"))){
                            //read the value
                            this->uvMultiply.y = edk::String::strToFloat32(temp);
                            //free(temp);
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvSX"))){
                            //read the value
                            this->uvSaved.x = edk::String::strToFloat32(temp);
                            //free(temp);
                        }
                        if((temp = xml->getSelectedAttributeValueByName("uvSY"))){
                            //read the value
                            this->uvSaved.y = edk::String::strToFloat32(temp);
                            //free(temp);
                        }
                        xml->selectFather();
                    }
                    free(name);
                }
                free(id);
            }
            return true;
        }
        return false;
    }

    //OPERATORS
    edk::shape::Vertex2DAnimatedUV operator=(edk::shape::Vertex2D vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        return edk::shape::Vertex2DAnimatedUV();
    }
    edk::shape::Vertex2DAnimatedUV operator=(edk::shape::Vertex2DWithUV vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        edk::shape::Vertex2DWithUV::setUV(vertex.getUV());
        //return vertex;
        return edk::shape::Vertex2DAnimatedUV();
    }
    edk::shape::Vertex2DAnimatedUV operator=(edk::shape::Vertex2DAnimatedUV vertex){
        //
        this->position=vertex.position;
        this->color=vertex.color;
        edk::shape::Vertex2DWithUV::setUV(vertex.getUV());
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
private:
    edk::classID classThis;
};

}//end namespace shape
}//end namespace edk

#endif // VERTEX2D_H
