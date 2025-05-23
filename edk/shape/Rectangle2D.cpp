#include "Rectangle2D.h"

/*
Library Rectangle2D - Draw a 2D Rectangle in EDK Game Engine
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
#pragma message "            Inside Rectangle2D.cpp"
#endif

edk::shape::Rectangle2D::Rectangle2D::Rectangle2D(){
    this->classThis=NULL;
    this->Constructor();
}

edk::shape::Rectangle2D::~Rectangle2D(){
    this->Destructor();
}

void edk::shape::Rectangle2D::Constructor(){
    edk::shape::Polygon2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->type = edk::shape::typeRectangle2D;
        this->polygonColor.a=1.f;
        //create the polygon
        this->createPolygon();
    }
}
void edk::shape::Rectangle2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //delete the polygon
        edk::shape::Polygon2D::deletePolygon();
    }
    edk::shape::Polygon2D::Destructor();
}

//createPolygon
bool edk::shape::Rectangle2D::createPolygon(){
    bool ret = false;
    //create a polygon with 2 vertex

    //delete the polygon
    edk::shape::Polygon2D::deletePolygon();
    if(this->vertexs.createArray(2u)){
        if(this->vertexsOriginal.createArray(2u)){
            //create all the vertexs
            edk::shape::Vertex2DWithUV* temp=NULL;
            this->vertexs.set(0u,new edk::shape::Vertex2DWithUV());
            if(this->vertexs.get(0u)){
                //Set alpha 1
                this->vertexs.get(0u)->color = this->polygonColor;
                //set the position
                this->vertexs.get(0u)->position = edk::vec2f32(0,1);
                temp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(0u);
                temp->setUV((edk::float32)0,(edk::float32)0);
            }
            this->vertexsOriginal.set(0u,new edk::shape::Vertex2DWithUV());
            if(this->vertexsOriginal.get(0u)){
                //Set alpha 1
                this->vertexsOriginal.get(0u)->color = this->polygonColor;
                //set the position
                this->vertexsOriginal.get(0u)->position = edk::vec2f32(0,1);
                temp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(0u);
                temp->setUV((edk::float32)0,(edk::float32)0);
            }
            this->vertexs.set(1u,new edk::shape::Vertex2DWithUV());
            if(this->vertexs.get(1u)){
                //Set alpha 1
                this->vertexs.get(1u)->color = this->polygonColor;
                //set the position
                this->vertexs.get(1u)->position = edk::vec2f32(1,0);
                temp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(1u);
                temp->setUV((edk::float32)1,(edk::float32)1);
            }
            this->vertexsOriginal.set(1u,new edk::shape::Vertex2DWithUV());
            if(this->vertexsOriginal.get(1u)){
                //Set alpha 1
                this->vertexsOriginal.get(1u)->color = this->polygonColor;
                //set the position
                this->vertexsOriginal.get(1u)->position = edk::vec2f32(1,0);
                temp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(1u);
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
            edk::vec2f32 position;
            edk::color4f32 color;
            edk::vec2f32 uv;
            edk::shape::Vertex2DWithUV* temp=NULL;
            temp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(0u);
            if(temp){
                position = temp->position;
                color = temp->color;
                uv = temp->getUV();

                //set the vertex position, color and uv
                this->setVertexPosition(0u,position);
                this->setVertexColor(0u,color);
                this->setVertexUV(0u,uv);
            }

            temp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(1u);
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
bool edk::shape::Rectangle2D::createVBO(edk::uint32 vertexCount,edk::GU::VBOType type){
    return edk::shape::Polygon2D::createVBO(vertexCount*2u,type);
}
//setters to VBO
bool edk::shape::Rectangle2D::setVBOVertexPosition(edk::uint32 vertex,edk::vec2f32 position){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon2D::setVBOVertexPosition(0u,edk::vec2f32(position.x,position.y));
        edk::shape::Polygon2D::setVBOVertexPositionX(1u,position.x);
        edk::shape::Polygon2D::setVBOVertexPositionY(3u,position.y);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon2D::setVBOVertexPositionY(1u,position.y);
        edk::shape::Polygon2D::setVBOVertexPosition(2u,edk::vec2f32(position.x,position.y));
        edk::shape::Polygon2D::setVBOVertexPositionX(3u,position.x);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Rectangle2D::setVBOVertexNormal(edk::uint32 vertex,edk::vec3f32 normal){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon2D::setVBOVertexNormal(0u,normal);
        edk::shape::Polygon2D::setVBOVertexNormal(2u,normal);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon2D::setVBOVertexNormal(2u,normal);
        edk::shape::Polygon2D::setVBOVertexNormal(3u,normal);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Rectangle2D::setVBOVertexColor(edk::uint32 vertex,edk::color4f32 color){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon2D::setVBOVertexColor(0u,color);
        edk::shape::Polygon2D::setVBOVertexColor(2u,color);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon2D::setVBOVertexColor(1u,color);
        edk::shape::Polygon2D::setVBOVertexColor(3u,color);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Rectangle2D::setVBOVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon2D::setVBOVertexUV(0u,edk::vec2f32(uv.x,uv.y));
        edk::shape::Polygon2D::setVBOVertexU(1u,uv.x);
        edk::shape::Polygon2D::setVBOVertexV(3u,uv.y);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon2D::setVBOVertexV(1u,uv.y);
        edk::shape::Polygon2D::setVBOVertexUV(2u,edk::vec2f32(uv.x,uv.y));
        edk::shape::Polygon2D::setVBOVertexU(3u,uv.x);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Rectangle2D::setVBOVertexU(edk::uint32 vertex,edk::float32 u){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon2D::setVBOVertexU(0u,u);
        edk::shape::Polygon2D::setVBOVertexU(1u,u);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon2D::setVBOVertexU(2u,u);
        edk::shape::Polygon2D::setVBOVertexU(3u,u);
        ret=true;
        break;
    }
    return ret;
}
bool edk::shape::Rectangle2D::setVBOVertexV(edk::uint32 vertex,edk::float32 v){
    bool ret=false;
    //set the vertexes
    switch(vertex){
    case 0u:
        edk::shape::Polygon2D::setVBOVertexV(0u,v);
        edk::shape::Polygon2D::setVBOVertexV(3u,v);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon2D::setVBOVertexV(1u,v);
        edk::shape::Polygon2D::setVBOVertexV(2u,v);
        ret=true;
        break;
    }
    return ret;
}
//updafe the UV into the VBO
bool edk::shape::Rectangle2D::updateVBOUV(){
    if(this->vertexs.size()>1u){
        edk::shape::Vertex2DWithUV* vTemp0 = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(0u);
        edk::shape::Vertex2DWithUV* vTemp1 = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(1u);
        if(vTemp0 && vTemp1){
            edk::vec2f32 uv1 = edk::vec2f32(0.f,0.f);
            edk::vec2f32 uv2 = edk::vec2f32(0.f,0.f);
            if(vTemp0->getType() != EDK_SHAPE_NOUV && vTemp1->getType() != EDK_SHAPE_NOUV){
                uv1 = vTemp0->getUV();
                uv2 = vTemp1->getUV();

            }
            edk::shape::Polygon2D::setVBOVertexUV(0u,edk::vec2f32(uv1.x,uv1.y));
            edk::shape::Polygon2D::setVBOVertexUV(1u,edk::vec2f32(uv1.x,uv2.y));
            edk::shape::Polygon2D::setVBOVertexUV(2u,edk::vec2f32(uv2.x,uv2.y));
            edk::shape::Polygon2D::setVBOVertexUV(3u,edk::vec2f32(uv2.x,uv1.y));

            return true;
        }
    }
    return false;
}
bool edk::shape::Rectangle2D::updateVBOValues(){
    if(this->vertexs.size()>1u){
        edk::shape::Vertex2DWithUV* vTemp0 = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(0u);
        edk::shape::Vertex2DWithUV* vTemp1 = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(1u);
        if(vTemp0 && vTemp1){
            edk::vec2f32 uv1 = edk::vec2f32(0.f,0.f);
            edk::vec2f32 uv2 = edk::vec2f32(0.f,0.f);
            if(vTemp0->getType() != EDK_SHAPE_NOUV && vTemp1->getType() != EDK_SHAPE_NOUV){
                uv1 = vTemp0->getUV();
                uv2 = vTemp1->getUV();
            }
            edk::shape::Polygon2D::setVBOVertexUV(0u,edk::vec2f32(uv1.x,uv1.y));
            edk::shape::Polygon2D::setVBOVertexUV(1u,edk::vec2f32(uv1.x,uv2.y));
            edk::shape::Polygon2D::setVBOVertexUV(2u,edk::vec2f32(uv2.x,uv2.y));
            edk::shape::Polygon2D::setVBOVertexUV(3u,edk::vec2f32(uv2.x,uv1.y));
            edk::vec2f32 position1 = vTemp0->position;
            edk::vec2f32 position2 = vTemp1->position;
            edk::shape::Polygon2D::setVBOVertexPosition(0u,edk::vec2f32(position1.x,position1.y));
            edk::shape::Polygon2D::setVBOVertexPosition(1u,edk::vec2f32(position1.x,position2.y));
            edk::shape::Polygon2D::setVBOVertexPosition(2u,edk::vec2f32(position2.x,position2.y));
            edk::shape::Polygon2D::setVBOVertexPosition(3u,edk::vec2f32(position2.x,position1.y));
            edk::color4f32 color1 = vTemp0->color;
            edk::color4f32 color2 = vTemp1->color;
            edk::shape::Polygon2D::setVBOVertexColor(0u,color1);
            edk::shape::Polygon2D::setVBOVertexColor(1u,color2);
            edk::shape::Polygon2D::setVBOVertexColor(2u,color1);
            edk::shape::Polygon2D::setVBOVertexColor(3u,color2);
        }
    }
    return false;
}

//DRAW
void edk::shape::Rectangle2D::draw_NULL(edk::uint32 mode){
    edk::GU::guBegin(mode);
    if(this->vertexs.getNoIF(0u)->getType() != EDK_SHAPE_NOUV
            &&
            this->vertexs.getNoIF(1u)->getType() != EDK_SHAPE_NOUV
            ){
        edk::shape::Vertex2DWithUV* vTemp0 = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(0u);
        edk::shape::Vertex2DWithUV* vTemp1 = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(1u);

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
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x, this->vertexs.getNoIF(0u)->position.y, 0.0f);

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp1->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp0->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x, this->vertexs.getNoIF(1u)->position.y, 0.0f);

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
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x, this->vertexs.getNoIF(1u)->position.y, 0.0f);

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp0->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp1->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x, this->vertexs.getNoIF(0u)->position.y, 0.0f);
    }
    else{

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(0.f, 1.f);
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 1.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x, this->vertexs.getNoIF(0u)->position.y, 0.0f);

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(0.f, 0.f);
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 0.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x, this->vertexs.getNoIF(1u)->position.y, 0.0f);

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
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x, this->vertexs.getNoIF(1u)->position.y, 0.0f);

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 1.f);
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 1.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x, this->vertexs.getNoIF(0u)->position.y, 0.0f);
    }
    edk::GU::guEnd();
}
//DRAW UPDATE
void edk::shape::Rectangle2D::drawUpdate_NULL(edk::uint32 mode){
    edk::GU::guBegin(mode);
    if(this->vertexs.getNoIF(0u)->getType() != EDK_SHAPE_NOUV
            &&
            this->vertexs.getNoIF(1u)->getType() != EDK_SHAPE_NOUV
            ){
        edk::shape::Vertex2DWithUV* vTemp0 = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(0u);
        edk::shape::Vertex2DWithUV* vTemp1 = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(1u);

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
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x, this->vertexs.getNoIF(0u)->position.y, 0.0f);

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp1->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp0->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x, this->vertexs.getNoIF(1u)->position.y, 0.0f);

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
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x, this->vertexs.getNoIF(1u)->position.y, 0.0f);

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp0->getUVY());
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp1->getUVY());
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x, this->vertexs.getNoIF(0u)->position.y, 0.0f);
    }
    else{

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(0.f, 1.f);
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 1.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x, this->vertexs.getNoIF(0u)->position.y, 0.0f);

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        //edk::GU::guVertexTex2f32(0.f, 0.f);
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 0.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(0u)->position.x, this->vertexs.getNoIF(1u)->position.y, 0.0f);

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
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x, this->vertexs.getNoIF(1u)->position.y, 0.0f);

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 1.f);
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 1.f);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.getNoIF(1u)->position.x, this->vertexs.getNoIF(0u)->position.y, 0.0f);
    }
    edk::GU::guEnd();
    //change the drawFunction
    this->setVBOFunctionNULL();
}

//Virtual Functions
bool edk::shape::Rectangle2D::createPolygon(edk::uint32 vertexCount){
    //set the function to do nothing but return true to think he create
    if(vertexCount){
        return true;
    }
    return false;
}
void edk::shape::Rectangle2D::deletePolygon(){
    //clean the vertex removind your UV
    this->removePolygonUV();
}

//set the pivo to the center of the rectangle
void edk::shape::Rectangle2D::setPivoToCenter(){
    //get the size
    if(this->vertexs.get(0u)&&this->vertexs.get(1u)){
        edk::size2f32 size(this->vertexs.getNoIF(1u)->position.x-this->vertexs.getNoIF(0u)->position.x,
                           this->vertexs.getNoIF(1u)->position.y-this->vertexs.getNoIF(0u)->position.y
                           );
        this->vertexs.getNoIF(0u)->position = edk::vec2f32(size.width * -0.5f,size.height * -0.5f);
        this->vertexs.getNoIF(1u)->position = edk::vec2f32(size.width *  0.5f,size.height *  0.5f);
    }
    if(this->vertexsOriginal.get(0u)&&this->vertexsOriginal.get(1u)){
        edk::size2f32 size(this->vertexsOriginal.getNoIF(1u)->position.x-this->vertexsOriginal.getNoIF(0u)->position.x,
                           this->vertexsOriginal.getNoIF(1u)->position.y-this->vertexsOriginal.getNoIF(0u)->position.y
                           );
        this->vertexsOriginal.getNoIF(0u)->position = edk::vec2f32(size.width * -0.5f,size.height * -0.5f);
        this->vertexsOriginal.getNoIF(1u)->position = edk::vec2f32(size.width *  0.5f,size.height *  0.5f);
    }


    //set the VBO position, color and UV

    edk::vec2f32 position;
    edk::color4f32 color;
    edk::vec2f32 uv;
    edk::shape::Vertex2DWithUV* temp=NULL;

    temp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(0u);
    if(temp){
        position = temp->position;
        color = temp->color;
        uv = temp->getUV();

        //set the vertex position, color and uv
        this->setVertexPosition(0u,position);
        this->setVertexColor(0u,color);
        this->setVertexUV(0u,uv);
    }

    temp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(1u);
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
void edk::shape::Rectangle2D::print(){
    //
    printf("\nRectangle");fflush(stdout);
    edk::shape::Polygon2D::print();
}

//Draw the rectangle
void edk::shape::Rectangle2D::draw(){
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

        edk::GU::guTranslate2f32(this->translate);
        edk::GU::guRotateZf32(this->angle);
        edk::GU::guScale2f32(this->scale);

        //drawVBO
        (this->*vboDraw)(GU_QUADS);

        edk::GU::guPopMatrix();
    }
}
//Draw the rectangle with lights
bool edk::shape::Rectangle2D::drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],bool lightIsOn[][EDK_LIGHT_LIMIT]){
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

            edk::GU::guTranslate2f32(this->translate);
            edk::GU::guRotateZf32(this->angle);
            edk::GU::guScale2f32(this->scale);

            edk::float32 lightPosition[4u];
            edk::float32 lightDirection[4u];
            edk::vec2f32 temp;

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

                    //rotate
                    temp = edk::Math::rotatePlus(edk::vec2f32(lightPosition[0u],lightPosition[1u])
                            ,this->angle*-1.f
                            );
                    lightPosition[0u] = temp.x;
                    lightPosition[1u] = temp.y;

                    temp = edk::Math::rotatePlus(edk::vec2f32(lightDirection[0u],lightDirection[1u])
                            ,this->angle*-1.f
                            );
                    lightDirection[0u] = temp.x;
                    lightDirection[1u] = temp.y;

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
void edk::shape::Rectangle2D::drawWire(){
    //draw the vertexs
    if(this->vertexs.size()>=2u){
        //draw the first vertex
        edk::GU::guColor4f32(this->vertexs.getNoIF(0u)->color.r,
                             this->vertexs.getNoIF(0u)->color.g,
                             this->vertexs.getNoIF(0u)->color.b,
                             this->vertexs.getNoIF(0u)->color.a
                             );
        edk::GU::guPushMatrix();

        edk::GU::guTranslate2f32(this->translate);
        edk::GU::guRotateZf32(this->angle);
        edk::GU::guScale2f32(this->scale);
        //drawVBO
        (this->*vboDraw)(GU_LINE_LOOP);
        edk::GU::guPopMatrix();
    }
}

bool edk::shape::Rectangle2D::cloneFrom(edk::shape::Polygon2D* poly){
    //first remove the UV from the polygon
    this->deletePolygon();
    if(poly){
        return edk::shape::Polygon2D::cloneFrom(poly);
    }
    return false;
}
