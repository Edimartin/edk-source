#include "Cube3D.h"

/*
Library Cube3D - Draw a 3D Cube in EDK Game Engine
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
#pragma message "            Inside Cube3D.cpp"
#endif

edk::shape::Cube3D::Cube3D::Cube3D(){
    this->classThis=NULL;
    this->Constructor();
}

edk::shape::Cube3D::~Cube3D(){
    this->Destructor();
}

void edk::shape::Cube3D::Constructor(){
    edk::shape::Polygon3D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->type = edk::shape::typeCube3D;
        this->polygonColor.a=1.f;
        //create the polygon
        this->createPolygon();
    }
}
void edk::shape::Cube3D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //delete the polygon
        edk::shape::Polygon3D::deletePolygon();
    }
    edk::shape::Polygon3D::Destructor();
}

//createPolygon
bool edk::shape::Cube3D::createPolygon(){
    bool ret = false;
    //create a polygon with 2 vertex

    //delete the polygon
    edk::shape::Polygon3D::deletePolygon();
    if(this->vertexs.createArray(2u)){
        if(this->vertexsOriginal.createArray(2u)){
            //create all the vertexs
            edk::shape::Vertex3DWithUV* temp=NULL;
            this->vertexs.set(0u,new edk::shape::Vertex3DWithUV());
            if(this->vertexs.get(0u)){
                //Set alpha 1
                this->vertexs.get(0u)->color = this->polygonColor;
                //set the position
                this->vertexs.get(0u)->position = edk::vec3f32(0,1,0);
                temp = (edk::shape::Vertex3DWithUV*)this->vertexs.get(0u);
                temp->setUV((edk::float32)0,(edk::float32)0);
            }
            this->vertexsOriginal.set(0u,new edk::shape::Vertex3DWithUV());
            if(this->vertexsOriginal.get(0u)){
                //Set alpha 1
                this->vertexsOriginal.get(0u)->color = this->polygonColor;
                //set the position
                this->vertexsOriginal.get(0u)->position = edk::vec3f32(0,1,0);
                temp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(0u);
                temp->setUV((edk::float32)0,(edk::float32)0);
            }
            this->vertexs.set(1u,new edk::shape::Vertex3DWithUV());
            if(this->vertexs.get(1u)){
                //Set alpha 1
                this->vertexs.get(1u)->color = this->polygonColor;
                //set the position
                this->vertexs.get(1u)->position = edk::vec3f32(1,0,0);
                temp = (edk::shape::Vertex3DWithUV*)this->vertexs.get(1u);
                temp->setUV((edk::float32)1,(edk::float32)1);
            }
            this->vertexsOriginal.set(1u,new edk::shape::Vertex3DWithUV());
            if(this->vertexsOriginal.get(1u)){
                //Set alpha 1
                this->vertexsOriginal.get(1u)->color = this->polygonColor;
                //set the position
                this->vertexsOriginal.get(1u)->position = edk::vec3f32(1,0,0);
                temp = (edk::shape::Vertex3DWithUV*)this->vertexsOriginal.get(1u);
                temp->setUV((edk::float32)1,(edk::float32)1);
            }
            //then return true
            ret = true;
        }
        else{
            this->vertexs.deleteArray();
        }
    }

    //create the VBO.
    if(ret){
        if(this->createVBO(2u,edk::GU::vbo_XYZ_RGBA)){
            //set the VBO position, color and UV
            edk::vec3f32 position;
            edk::color4f32 color;
            edk::vec2f32 uv;
            edk::shape::Vertex3DWithUV* temp=NULL;
            temp = (edk::shape::Vertex3DWithUV*)this->vertexs.get(0u);
            if(temp){
                position = temp->position;
                color = temp->color;
                uv = temp->getUV();

                //set the vertex position, color and uv
                this->setVertexPosition(0u,position);
                this->setVertexColor(0u,color);
                this->setVertexUV(0u,uv);
            }

            temp = (edk::shape::Vertex3DWithUV*)this->vertexs.get(1u);
            if(temp){
                position = temp->position;
                color = temp->color;
                uv = temp->getUV();

                //set the vertex position, color and uv
                this->setVertexPosition(1u,position);
                this->setVertexColor(1u,color);
                this->setVertexUV(1u,uv);
            }
        }
    }

    //
    return ret;
}

//function to create the VBO
bool edk::shape::Cube3D::createVBO(edk::uint32 vertexCount,edk::GU::VBOType type){
    return edk::shape::Polygon3D::createVBO(vertexCount*2u,type);
}
//setters to VBO
bool edk::shape::Cube3D::setVBOVertexPosition(edk::uint32 vertex,edk::vec3f32 position){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon3D::setVBOVertexPosition(0u,edk::vec3f32(position.x,position.y,position.z));
        edk::shape::Polygon3D::setVBOVertexPositionX(1u,position.x);
        edk::shape::Polygon3D::setVBOVertexPositionY(3u,position.y);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon3D::setVBOVertexPositionY(1u,position.y);
        edk::shape::Polygon3D::setVBOVertexPosition(2u,edk::vec3f32(position.x,position.y,position.z));
        edk::shape::Polygon3D::setVBOVertexPositionX(3u,position.x);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Cube3D::setVBOVertexNormal(edk::uint32 vertex,edk::vec3f32 normal){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon3D::setVBOVertexNormal(0u,normal);
        edk::shape::Polygon3D::setVBOVertexNormal(2u,normal);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon3D::setVBOVertexNormal(2u,normal);
        edk::shape::Polygon3D::setVBOVertexNormal(3u,normal);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Cube3D::setVBOVertexColor(edk::uint32 vertex,edk::color4f32 color){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon3D::setVBOVertexColor(0u,color);
        edk::shape::Polygon3D::setVBOVertexColor(2u,color);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon3D::setVBOVertexColor(1u,color);
        edk::shape::Polygon3D::setVBOVertexColor(3u,color);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Cube3D::setVBOVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon3D::setVBOVertexUV(0u,edk::vec2f32(uv.x,uv.y));
        edk::shape::Polygon3D::setVBOVertexU(1u,uv.x);
        edk::shape::Polygon3D::setVBOVertexV(3u,uv.y);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon3D::setVBOVertexV(1u,uv.y);
        edk::shape::Polygon3D::setVBOVertexUV(2u,edk::vec2f32(uv.x,uv.y));
        edk::shape::Polygon3D::setVBOVertexU(3u,uv.x);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Cube3D::setVBOVertexU(edk::uint32 vertex,edk::float32 u){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon3D::setVBOVertexU(0u,u);
        edk::shape::Polygon3D::setVBOVertexU(1u,u);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon3D::setVBOVertexU(2u,u);
        edk::shape::Polygon3D::setVBOVertexU(3u,u);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Cube3D::setVBOVertexV(edk::uint32 vertex,edk::float32 v){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon3D::setVBOVertexV(0u,v);
        edk::shape::Polygon3D::setVBOVertexV(3u,v);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon3D::setVBOVertexV(1u,v);
        edk::shape::Polygon3D::setVBOVertexV(2u,v);
        ret=true;
        break;
    }
    return ret;
}
//updafe the UV into the VBO
bool edk::shape::Cube3D::updateVBOUV(){
    if(this->vertexs.size()>1u){
        edk::shape::Vertex3DWithUV* vTemp0 = (edk::shape::Vertex3DWithUV*)this->vertexs.getNoIF(0u);
        edk::shape::Vertex3DWithUV* vTemp1 = (edk::shape::Vertex3DWithUV*)this->vertexs.getNoIF(1u);
        if(vTemp0 && vTemp1){
            edk::vec2f32 uv1 = edk::vec2f32(0.f,0.f);
            edk::vec2f32 uv2 = edk::vec2f32(0.f,0.f);
            if(vTemp0->getType() != EDK_SHAPE_NOUV && vTemp1->getType() != EDK_SHAPE_NOUV){
                uv1 = vTemp0->getUV();
                uv2 = vTemp1->getUV();

            }
            edk::shape::Polygon3D::setVBOVertexUV(0u,edk::vec2f32(uv1.x,uv1.y));
            edk::shape::Polygon3D::setVBOVertexUV(1u,edk::vec2f32(uv1.x,uv2.y));
            edk::shape::Polygon3D::setVBOVertexUV(2u,edk::vec2f32(uv2.x,uv2.y));
            edk::shape::Polygon3D::setVBOVertexUV(3u,edk::vec2f32(uv2.x,uv1.y));

            return true;
        }
    }
    return false;
}
bool edk::shape::Cube3D::updateVBOValues(){
    if(this->vertexs.size()>1u){
        edk::shape::Vertex3DWithUV* vTemp0 = (edk::shape::Vertex3DWithUV*)this->vertexs.getNoIF(0u);
        edk::shape::Vertex3DWithUV* vTemp1 = (edk::shape::Vertex3DWithUV*)this->vertexs.getNoIF(1u);
        if(vTemp0 && vTemp1){
            edk::vec2f32 uv1 = edk::vec2f32(0.f,0.f);
            edk::vec2f32 uv2 = edk::vec2f32(0.f,0.f);
            if(vTemp0->getType() != EDK_SHAPE_NOUV && vTemp1->getType() != EDK_SHAPE_NOUV){
                uv1 = vTemp0->getUV();
                uv2 = vTemp1->getUV();
            }
            edk::shape::Polygon3D::setVBOVertexUV(0u,edk::vec2f32(uv1.x,uv1.y));
            edk::shape::Polygon3D::setVBOVertexUV(1u,edk::vec2f32(uv1.x,uv2.y));
            edk::shape::Polygon3D::setVBOVertexUV(2u,edk::vec2f32(uv2.x,uv2.y));
            edk::shape::Polygon3D::setVBOVertexUV(3u,edk::vec2f32(uv2.x,uv1.y));
            edk::vec3f32 position1 = vTemp0->position;
            edk::vec3f32 position2 = vTemp1->position;
            edk::shape::Polygon3D::setVBOVertexPosition(0u,edk::vec3f32(position1.x,position1.y,position1.z));
            edk::shape::Polygon3D::setVBOVertexPosition(1u,edk::vec3f32(position1.x,position2.y,position2.z));
            edk::shape::Polygon3D::setVBOVertexPosition(2u,edk::vec3f32(position2.x,position2.y,position2.z));
            edk::shape::Polygon3D::setVBOVertexPosition(3u,edk::vec3f32(position2.x,position1.y,position1.z));
            edk::color4f32 color1 = vTemp0->color;
            edk::color4f32 color2 = vTemp1->color;
            edk::shape::Polygon3D::setVBOVertexColor(0u,color1);
            edk::shape::Polygon3D::setVBOVertexColor(1u,color2);
            edk::shape::Polygon3D::setVBOVertexColor(2u,color1);
            edk::shape::Polygon3D::setVBOVertexColor(3u,color2);
        }
    }
    return false;
}

//DRAW
void edk::shape::Cube3D::draw_NULL(edk::uint32 mode){
    edk::GU::guBegin(mode);
    if(this->vertexs.getNoIF(0u)->getType() != EDK_SHAPE_NOUV
            &&
            this->vertexs.getNoIF(1u)->getType() != EDK_SHAPE_NOUV
            ){
        edk::shape::Vertex3DWithUV* vTemp0 = (edk::shape::Vertex3DWithUV*)this->vertexs.getNoIF(0u);
        edk::shape::Vertex3DWithUV* vTemp1 = (edk::shape::Vertex3DWithUV*)this->vertexs.getNoIF(1u);

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(1u)->color.r,
                             this->vertexs.getNoIF(1u)->color.g,
                             this->vertexs.getNoIF(1u)->color.b,
                             this->vertexs.getNoIF(1u)->color.a
                             );

        //draw the normal
        edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp0->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp1->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x,
                               this->vertexs.getNoIF(0u)->position.y,
                               this->vertexs.getNoIF(0u)->position.z
                               );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp1->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp0->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x,
                               this->vertexs.getNoIF(1u)->position.y,
                               this->vertexs.getNoIF(1u)->position.z
                               );

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(1u)->color.r,
                             this->vertexs.getNoIF(1u)->color.g,
                             this->vertexs.getNoIF(1u)->color.b,
                             this->vertexs.getNoIF(1u)->color.a
                             );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp1->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp0->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x,
                               this->vertexs.getNoIF(1u)->position.y,
                               this->vertexs.getNoIF(1u)->position.z
                               );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp0->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp1->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x,
                               this->vertexs.getNoIF(0u)->position.y,
                               this->vertexs.getNoIF(0u)->position.z
                               );
    }
    else{

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(0.f, 1.f);
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 1.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x,
                               this->vertexs.getNoIF(0u)->position.y,
                               this->vertexs.getNoIF(0u)->position.z
                               );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(0.f, 0.f);
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 0.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x,
                               this->vertexs.getNoIF(1u)->position.y,
                               this->vertexs.getNoIF(1u)->position.z
                               );

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(1u)->color.r,
                             this->vertexs.getNoIF(1u)->color.g,
                             this->vertexs.getNoIF(1u)->color.b,
                             this->vertexs.getNoIF(1u)->color.a
                             );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 0.f);
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 0.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x,
                               this->vertexs.getNoIF(1u)->position.y,
                               this->vertexs.getNoIF(1u)->position.z
                               );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 1.f);
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 1.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x,
                               this->vertexs.getNoIF(0u)->position.y,
                               this->vertexs.getNoIF(0u)->position.z
                               );
    }
    edk::GU::guEnd();
}
//DRAW UPDATE
void edk::shape::Cube3D::drawUpdate_NULL(edk::uint32 mode){
    edk::GU::guBegin(mode);
    if(this->vertexs.getNoIF(0u)->getType() != EDK_SHAPE_NOUV
            &&
            this->vertexs.getNoIF(1u)->getType() != EDK_SHAPE_NOUV
            ){
        edk::shape::Vertex3DWithUV* vTemp0 = (edk::shape::Vertex3DWithUV*)this->vertexs.getNoIF(0u);
        edk::shape::Vertex3DWithUV* vTemp1 = (edk::shape::Vertex3DWithUV*)this->vertexs.getNoIF(1u);

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(1u)->color.r,
                             this->vertexs.getNoIF(1u)->color.g,
                             this->vertexs.getNoIF(1u)->color.b,
                             this->vertexs.getNoIF(1u)->color.a
                             );

        //draw the normal
        edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp0->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp1->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x,
                               this->vertexs.getNoIF(0u)->position.y,
                               this->vertexs.getNoIF(0u)->position.z
                               );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp1->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp0->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x,
                               this->vertexs.getNoIF(1u)->position.y,
                               this->vertexs.getNoIF(1u)->position.z
                               );

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(1u)->color.r,
                             this->vertexs.getNoIF(1u)->color.g,
                             this->vertexs.getNoIF(1u)->color.b,
                             this->vertexs.getNoIF(1u)->color.a
                             );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp1->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp0->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x,
                               this->vertexs.getNoIF(1u)->position.y,
                               this->vertexs.getNoIF(1u)->position.z
                               );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp0->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp1->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x,
                               this->vertexs.getNoIF(0u)->position.y,
                               this->vertexs.getNoIF(0u)->position.z
                               );
    }
    else{

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(0.f, 1.f);
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 1.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x,
                               this->vertexs.getNoIF(0u)->position.y,
                               this->vertexs.getNoIF(0u)->position.z
                               );

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        //edk::GU::guVertexTex2f32(0.f, 0.f);
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 0.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x,
                               this->vertexs.getNoIF(1u)->position.y,
                               this->vertexs.getNoIF(1u)->position.z
                               );

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(1u)->color.r,
                             this->vertexs.getNoIF(1u)->color.g,
                             this->vertexs.getNoIF(1u)->color.b,
                             this->vertexs.getNoIF(1u)->color.a
                             );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 0.f);
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 0.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x,
                               this->vertexs.getNoIF(1u)->position.y,
                               this->vertexs.getNoIF(1u)->position.z
                               );

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 1.f);
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 1.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x,
                               this->vertexs.getNoIF(0u)->position.y,
                               this->vertexs.getNoIF(0u)->position.z
                               );
    }
    edk::GU::guEnd();
    //change the drawFunction
    this->setVBOFunctionNULL();
}

//Virtual Functions
bool edk::shape::Cube3D::createPolygon(edk::uint32 vertexCount){
    //set the function to do nothing but return true to think he create
    if(vertexCount){
        return true;
    }
    return false;
}
void edk::shape::Cube3D::deletePolygon(){
    //clean the vertex removind your UV
    this->removePolygonUV();
}

//set the pivo to the center of the rectangle
void edk::shape::Cube3D::setPivoToCenter(){
    //get the size
    if(this->vertexs.get(0u)&&this->vertexs.get(1u)){
        edk::size3f32 size(this->vertexs.getNoIF(1u)->position.x-this->vertexs.getNoIF(0u)->position.x,
                           this->vertexs.getNoIF(1u)->position.y-this->vertexs.getNoIF(0u)->position.y,
                           this->vertexs.getNoIF(1u)->position.z-this->vertexs.getNoIF(0u)->position.z
                           );
        this->vertexs.getNoIF(0u)->position = edk::vec3f32(size.width * -0.5f,size.height * -0.5f,size.length * -0.5f);
        this->vertexs.getNoIF(1u)->position = edk::vec3f32(size.width *  0.5f,size.height *  0.5f,size.length *  0.5f);
    }
    if(this->vertexsOriginal.get(0u)&&this->vertexsOriginal.get(1u)){
        edk::size3f32 size(this->vertexsOriginal.getNoIF(1u)->position.x-this->vertexsOriginal.getNoIF(0u)->position.x,
                           this->vertexsOriginal.getNoIF(1u)->position.y-this->vertexsOriginal.getNoIF(0u)->position.y,
                           this->vertexsOriginal.getNoIF(1u)->position.z-this->vertexsOriginal.getNoIF(0u)->position.z
                           );
        this->vertexsOriginal.getNoIF(0u)->position = edk::vec3f32(size.width * -0.5f,size.height * -0.5f,size.length * -0.5f);
        this->vertexsOriginal.getNoIF(1u)->position = edk::vec3f32(size.width *  0.5f,size.height *  0.5f,size.length *  0.5f);
    }


    //set the VBO position, color and UV

    edk::vec3f32 position;
    edk::color4f32 color;
    edk::vec2f32 uv;
    edk::shape::Vertex3DWithUV* temp=NULL;

    temp = (edk::shape::Vertex3DWithUV*)this->vertexs.get(0u);
    if(temp){
        position = temp->position;
        color = temp->color;
        uv = temp->getUV();

        //set the vertex position, color and uv
        this->setVertexPosition(0u,position);
        this->setVertexColor(0u,color);
        this->setVertexUV(0u,uv);
    }

    temp = (edk::shape::Vertex3DWithUV*)this->vertexs.get(1u);
    if(temp){
        position = temp->position;
        color = temp->color;
        uv = temp->getUV();

        //set the vertex position, color and uv
        this->setVertexPosition(1u,position);
        this->setVertexColor(1u,color);
        this->setVertexUV(1u,uv);
    }
}

//print the rectangle
void edk::shape::Cube3D::print(){
    //
    printf("\nRectangle");fflush(stdout);
    edk::shape::Polygon3D::print();
}

//Draw the rectangle
void edk::shape::Cube3D::draw(){
    //
    //draw the vertexs
    if(this->vertexs.size()>=2u){
        //draw the first vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(0u)->color.r,
                             this->vertexs.getNoIF(0u)->color.g,
                             this->vertexs.getNoIF(0u)->color.b,
                             this->vertexs.getNoIF(0u)->color.a
                             );

        edk::GU::guPushMatrix();

        edk::GU::guTranslate3f32(this->translate);
        edk::GU::guRotateZf32(this->angle);
        edk::GU::guScale3f32(this->scale);

        //drawVBO
        (this->*vboDraw)(GU_QUADS);

        edk::GU::guPopMatrix();
    }
}
//Draw the rectangle with lights
bool edk::shape::Cube3D::drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(lightPositions && lightDirections && lightIsOn){
        //
        //draw the vertexs
        if(this->vertexs.size()>=2u){
            //draw the first vertex
            edk::GU::guColor4f32(this->vertexs.getNoIF(0u)->color.r,
                                 this->vertexs.getNoIF(0u)->color.g,
                                 this->vertexs.getNoIF(0u)->color.b,
                                 this->vertexs.getNoIF(0u)->color.a
                                 );

            edk::GU::guPushMatrix();

            edk::GU::guTranslate3f32(this->translate);
            edk::GU::guRotateZf32(this->angle);
            edk::GU::guScale3f32(this->scale);

            edk::float32 lightPosition[4u];
            edk::float32 lightDirection[4u];
            edk::vec3f32 temp;

            //translate the lights
            for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
                if(*lightIsOn[i]){
                    //translate the light and direction
                    lightPosition[0u] = *lightPositions[i][0u] - this->translate.x;
                    lightPosition[1u] = *lightPositions[i][1u] - this->translate.x;
                    lightPosition[2u] = *lightPositions[i][2u];
                    lightPosition[3u] = *lightPositions[i][3u];
                    //
                    lightDirection[0u] = *lightDirections[i][0u] - this->translate.x;
                    lightDirection[1u] = *lightDirections[i][1u] - this->translate.x;
                    lightDirection[2u] = *lightDirections[i][2u];
                    lightDirection[3u] = *lightDirections[i][3u];

                    //scale
                    lightPosition[0u] *= (1.f/this->scale.width);
                    lightPosition[1u] *= (1.f/this->scale.height);

                    lightDirection[0u] *= (1.f/this->scale.width);
                    lightDirection[1u] *= (1.f/this->scale.height);
                    ///TODO IN THE FUTURE
                    /*
                    //rotate
                    temp = edk::Math::rotatePlus(edk::vec2f32(lightPosition[0u],lightPosition[1u])
                            ,this->angle*-1.f
                            );
                    lightPosition[0u] = temp.x;
                    lightPosition[1u] = temp.y;
                    lightPosition[2u] = temp.z;

                    temp = edk::Math::rotatePlus(edk::vec2f32(lightDirection[0u],lightDirection[1u])
                            ,this->angle*-1.f
                            );
                    lightDirection[0u] = temp.x;
                    lightDirection[1u] = temp.y;
                    lightDirection[2u] = temp.z;
*/
                    edk::GU::guLightfv32(GU_LIGHT0+i,GU_POSITION,lightPosition);
                    edk::GU::guLightfv32(GU_LIGHT0+i,GU_SPOT_DIRECTION,lightDirection);
                }
            }



            //drawVBO
            (this->*vboDraw)(GU_QUADS);
            edk::GU::guPopMatrix();
        }
        return true;
    }
    return false;
}
//
void edk::shape::Cube3D::drawWire(){
    //draw the vertexs
    if(this->vertexs.size()>=2u){
        //draw the first vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(0u)->color.r,
                             this->vertexs.getNoIF(0u)->color.g,
                             this->vertexs.getNoIF(0u)->color.b,
                             this->vertexs.getNoIF(0u)->color.a
                             );
        edk::GU::guPushMatrix();

        edk::GU::guTranslate3f32(this->translate);
        edk::GU::guRotateZf32(this->angle);
        edk::GU::guScale3f32(this->scale);
        //drawVBO
        (this->*vboDraw)(GU_LINE_LOOP);
        edk::GU::guPopMatrix();
    }
}

bool edk::shape::Cube3D::cloneFrom(edk::shape::Polygon3D* poly){
    //first remove the UV from the polygon
    this->deletePolygon();
    if(poly){
        return edk::shape::Polygon3D::cloneFrom(poly);
    }
    return false;
}
