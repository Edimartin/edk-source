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
    this->type = edk::shape::rectangle2D;edkEnd();
    this->polygonColor.a=1.f;edkEnd();
    //create the polygon
    this->createPolygon();edkEnd();
}

edk::shape::Rectangle2D::~Rectangle2D()
{
    //delete the polygon
    edk::shape::Polygon2D::deletePolygon();edkEnd();
}
//createPolygon
bool edk::shape::Rectangle2D::createPolygon(){
    //create a polygon with 2 vertex

    //delete the polygon
    edk::shape::Polygon2D::deletePolygon();edkEnd();
    if(this->vertexs.createArray(2u)){
        if(this->vertexsOriginal.createArray(2u)){
            //create all the vertexs
            edk::shape::Vertex2DWithUV* temp=NULL;edkEnd();
            this->vertexs.set(0u,new edk::shape::Vertex2DWithUV());edkEnd();
            if(this->vertexs.get(0u)){
                //Set alpha 1
                this->vertexs.get(0u)->color = this->polygonColor;edkEnd();
                //set the position
                this->vertexs.get(0u)->position = edk::vec2f32(0,1);edkEnd();
                temp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(0u);edkEnd();
                temp->setUV((edk::float32)0,(edk::float32)0);edkEnd();
            }
            this->vertexsOriginal.set(0u,new edk::shape::Vertex2DWithUV());edkEnd();
            if(this->vertexsOriginal.get(0u)){
                //Set alpha 1
                this->vertexsOriginal.get(0u)->color = this->polygonColor;edkEnd();
                //set the position
                this->vertexsOriginal.get(0u)->position = edk::vec2f32(0,1);edkEnd();
                temp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(0u);edkEnd();
                temp->setUV((edk::float32)0,(edk::float32)0);edkEnd();
            }
            this->vertexs.set(1u,new edk::shape::Vertex2DWithUV());edkEnd();
            if(this->vertexs.get(1u)){
                //Set alpha 1
                this->vertexs.get(1u)->color = this->polygonColor;edkEnd();
                //set the position
                this->vertexs.get(1u)->position = edk::vec2f32(1,0);edkEnd();
                temp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(1u);edkEnd();
                temp->setUV((edk::float32)1,(edk::float32)1);edkEnd();
            }
            this->vertexsOriginal.set(1u,new edk::shape::Vertex2DWithUV());edkEnd();
            if(this->vertexsOriginal.get(1u)){
                //Set alpha 1
                this->vertexsOriginal.get(1u)->color = this->polygonColor;edkEnd();
                //set the position
                this->vertexsOriginal.get(1u)->position = edk::vec2f32(1,0);edkEnd();
                temp = (edk::shape::Vertex2DWithUV*)this->vertexsOriginal.get(1u);edkEnd();
                temp->setUV((edk::float32)1,(edk::float32)1);edkEnd();
            }
            //set can delete the polygon
            this->canDeletePolygon=true;edkEnd();
            //then return true
            return true;
        }
        else{
            this->vertexs.deleteArray();
        }
    }
    //else return false
    return false;
}

//function to create the VBO
bool edk::shape::Rectangle2D::createVBO(edk::uint32 vertexCount,edk::shape::EDKVBOType type){
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
        edk::shape::Polygon2D::setVBOVertexColor(2u,color);
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
        edk::shape::Polygon2D::setVBOVertexPosition(0u,edk::vec2f32(uv.x,uv.y));
        edk::shape::Polygon2D::setVBOVertexPositionX(1u,uv.x);
        edk::shape::Polygon2D::setVBOVertexPositionY(3u,uv.y);
        ret=true;
        break;
    case 1u:
        edk::shape::Polygon2D::setVBOVertexPositionY(1u,uv.y);
        edk::shape::Polygon2D::setVBOVertexPosition(2u,edk::vec2f32(uv.x,uv.y));
        edk::shape::Polygon2D::setVBOVertexPositionX(3u,uv.x);
        ret=true;
        break;
    }
    return ret;
}

//DRAW
void edk::shape::Rectangle2D::draw_NULL(edk::uint32){
    edk::GU::guBegin(GU_QUADS);edkEnd();
    if(this->vertexs.get(0u)->getType() != EDK_SHAPE_NOUV
            &&
            this->vertexs.get(1u)->getType() != EDK_SHAPE_NOUV
            ){
        edk::shape::Vertex2DWithUV* vTemp0 = (edk::shape::Vertex2DWithUV*)this->vertexs.get(0u);edkEnd();
        edk::shape::Vertex2DWithUV* vTemp1 = (edk::shape::Vertex2DWithUV*)this->vertexs.get(1u);edkEnd();

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.get(1u)->color.r,
                             this->vertexs.get(1u)->color.g,
                             this->vertexs.get(1u)->color.b,
                             this->vertexs.get(1u)->color.a
                             );edkEnd();

        //draw the normal
        edk::GU::guVertexNormal3f32(0.f,0.f,1.f);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp0->getUVY());edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp1->getUVY());edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(0u)->position.x, this->vertexs.get(0u)->position.y, 0.0f);edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp1->getUVY());edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp0->getUVY());edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(0u)->position.x, this->vertexs.get(1u)->position.y, 0.0f);edkEnd();

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.get(1u)->color.r,
                             this->vertexs.get(1u)->color.g,
                             this->vertexs.get(1u)->color.b,
                             this->vertexs.get(1u)->color.a
                             );edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp1->getUVY());edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp0->getUVY());edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(1u)->position.x, this->vertexs.get(1u)->position.y, 0.0f);edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp0->getUVY());edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp1->getUVY());edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(1u)->position.x, this->vertexs.get(0u)->position.y, 0.0f);edkEnd();
    }
    else{

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(0.f, 1.f);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 1.f);edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(0u)->position.x, this->vertexs.get(0u)->position.y, 0.0f);edkEnd();

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);edkEnd();
        //draw the textureUV
        //edk::GU::guVertexTex2f32(0.f, 0.f);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 0.f);edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(0u)->position.x, this->vertexs.get(1u)->position.y, 0.0f);edkEnd();

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.get(1u)->color.r,
                             this->vertexs.get(1u)->color.g,
                             this->vertexs.get(1u)->color.b,
                             this->vertexs.get(1u)->color.a
                             );edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 0.f);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 0.f);edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(1u)->position.x, this->vertexs.get(1u)->position.y, 0.0f);edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 1.f);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 1.f);edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(1u)->position.x, this->vertexs.get(0u)->position.y, 0.0f);edkEnd();
    }
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
//DRAW UPDATE
void edk::shape::Rectangle2D::drawUpdate_NULL(edk::uint32){
    edk::GU::guBegin(GU_QUADS);edkEnd();
    if(this->vertexs.get(0u)->getType() != EDK_SHAPE_NOUV
            &&
            this->vertexs.get(1u)->getType() != EDK_SHAPE_NOUV
            ){
        edk::shape::Vertex2DWithUV* vTemp0 = (edk::shape::Vertex2DWithUV*)this->vertexs.get(0u);edkEnd();
        edk::shape::Vertex2DWithUV* vTemp1 = (edk::shape::Vertex2DWithUV*)this->vertexs.get(1u);edkEnd();

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.get(1u)->color.r,
                             this->vertexs.get(1u)->color.g,
                             this->vertexs.get(1u)->color.b,
                             this->vertexs.get(1u)->color.a
                             );edkEnd();

        //draw the normal
        edk::GU::guVertexNormal3f32(0.f,0.f,1.f);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp0->getUVY());edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp1->getUVY());edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(0u)->position.x, this->vertexs.get(0u)->position.y, 0.0f);edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp1->getUVY());edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp0->getUVY());edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(0u)->position.x, this->vertexs.get(1u)->position.y, 0.0f);edkEnd();

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.get(1u)->color.r,
                             this->vertexs.get(1u)->color.g,
                             this->vertexs.get(1u)->color.b,
                             this->vertexs.get(1u)->color.a
                             );edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp1->getUVY());edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp0->getUVY());edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(1u)->position.x, this->vertexs.get(1u)->position.y, 0.0f);edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp0->getUVY());edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp1->getUVY());edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(1u)->position.x, this->vertexs.get(0u)->position.y, 0.0f);edkEnd();
    }
    else{

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(0.f, 1.f);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 1.f);edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(0u)->position.x, this->vertexs.get(0u)->position.y, 0.0f);edkEnd();

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);edkEnd();
        //draw the textureUV
        //edk::GU::guVertexTex2f32(0.f, 0.f);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,0.f, 0.f);edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(0u)->position.x, this->vertexs.get(1u)->position.y, 0.0f);edkEnd();

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs.get(1u)->color.r,
                             this->vertexs.get(1u)->color.g,
                             this->vertexs.get(1u)->color.b,
                             this->vertexs.get(1u)->color.a
                             );edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 0.f);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 0.f);edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(1u)->position.x, this->vertexs.get(1u)->position.y, 0.0f);edkEnd();

        //draw the normal
        //edk::GU::guVertexNormal3f32(0,0,1);edkEnd();
        //draw the textureUV
        edk::GU::guVertexTex2f32(1.f, 1.f);edkEnd();
        //glMultiTexCoord2f(GL_TEXTURE0,1.f, 1.f);edkEnd();
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs.get(1u)->position.x, this->vertexs.get(0u)->position.y, 0.0f);edkEnd();
    }
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
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
    this->removePolygonUV();edkEnd();
}

//set the pivo to the center of the rectangle
void edk::shape::Rectangle2D::setPivoToCenter(){
    //get the size
    if(this->vertexs.get(0u)&&this->vertexs.get(1u)){
        edk::size2f32 size(this->vertexs.get(1u)->position.x-this->vertexs.get(0u)->position.x,
                           this->vertexs.get(1u)->position.y-this->vertexs.get(0u)->position.y
                           );edkEnd();
        this->vertexs.get(0u)->position = edk::vec2f32(size.width * -0.5f,size.height * -0.5f);edkEnd();
        this->vertexs.get(1u)->position = edk::vec2f32(size.width *  0.5f,size.height *  0.5f);edkEnd();
    }
    if(this->vertexsOriginal.get(0u)&&this->vertexsOriginal.get(1u)){
        edk::size2f32 size(this->vertexsOriginal.get(1u)->position.x-this->vertexsOriginal.get(0u)->position.x,
                           this->vertexsOriginal.get(1u)->position.y-this->vertexsOriginal.get(0u)->position.y
                           );edkEnd();
        this->vertexsOriginal.get(0u)->position = edk::vec2f32(size.width * -0.5f,size.height * -0.5f);edkEnd();
        this->vertexsOriginal.get(1u)->position = edk::vec2f32(size.width *  0.5f,size.height *  0.5f);edkEnd();
    }
}

//print the rectangle
void edk::shape::Rectangle2D::print(){
    //
    printf("\nRectangle");edkEnd();
    edk::shape::Polygon2D::print();edkEnd();
}

//Draw the rectangle
void edk::shape::Rectangle2D::draw(){
    //
    //draw the vertexs
    if(this->vertexs.size()>=2u){
        //draw the first vertex
        edk::GU::guColor4f32(this->vertexs.get(0u)->color.r,
                             this->vertexs.get(0u)->color.g,
                             this->vertexs.get(0u)->color.b,
                             this->vertexs.get(0u)->color.a
                             );edkEnd();

        edk::GU::guPushMatrix();edkEnd();

        edk::GU::guTranslate2f32(this->translate);edkEnd();
        edk::GU::guRotateZf32(this->angle);edkEnd();
        edk::GU::guScale2f32(this->scale);edkEnd();

        //drawVBO
        (this->*vboDraw)(GU_QUADS);

        edk::GU::guPopMatrix();edkEnd();
    }
}
//Draw the rectangle with lights
bool edk::shape::Rectangle2D::drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(lightPositions && lightDirections && lightIsOn){
        //
        //draw the vertexs
        if(this->vertexs.size()>=2u){
            //draw the first vertex
            edk::GU::guColor4f32(this->vertexs.get(0u)->color.r,
                                 this->vertexs.get(0u)->color.g,
                                 this->vertexs.get(0u)->color.b,
                                 this->vertexs.get(0u)->color.a
                                 );edkEnd();

            edk::GU::guPushMatrix();edkEnd();

            edk::GU::guTranslate2f32(this->translate);edkEnd();
            edk::GU::guRotateZf32(this->angle);edkEnd();
            edk::GU::guScale2f32(this->scale);edkEnd();

            edk::float32 lightPosition[4u];edkEnd();
            edk::float32 lightDirection[4u];edkEnd();
            edk::vec2f32 temp;edkEnd();

            //translate the lights
            for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
                if(*lightIsOn[i]){
                    //translate the light and direction
                    lightPosition[0u] = *lightPositions[i][0u] - this->translate.x;edkEnd();
                    lightPosition[1u] = *lightPositions[i][1u] - this->translate.x;edkEnd();
                    lightPosition[2u] = *lightPositions[i][2u];edkEnd();
                    lightPosition[3u] = *lightPositions[i][3u];edkEnd();
                    //
                    lightDirection[0u] = *lightDirections[i][0u] - this->translate.x;edkEnd();
                    lightDirection[1u] = *lightDirections[i][1u] - this->translate.x;edkEnd();
                    lightDirection[2u] = *lightDirections[i][2u];edkEnd();
                    lightDirection[3u] = *lightDirections[i][3u];edkEnd();

                    //scale
                    lightPosition[0u] *= (1.f/this->scale.width);edkEnd();
                    lightPosition[1u] *= (1.f/this->scale.height);edkEnd();

                    lightDirection[0u] *= (1.f/this->scale.width);edkEnd();
                    lightDirection[1u] *= (1.f/this->scale.height);edkEnd();

                    //rotate
                    temp = edk::Math::rotatePlus(edk::vec2f32(lightPosition[0u],lightPosition[1u])
                            ,this->angle*-1.f
                            );edkEnd();
                    lightPosition[0u] = temp.x;edkEnd();
                    lightPosition[1u] = temp.y;edkEnd();

                    temp = edk::Math::rotatePlus(edk::vec2f32(lightDirection[0u],lightDirection[1u])
                            ,this->angle*-1.f
                            );edkEnd();
                    lightDirection[0u] = temp.x;edkEnd();
                    lightDirection[1u] = temp.y;edkEnd();

                    edk::GU::guLightfv32(GU_LIGHT0+i,GU_POSITION,lightPosition);edkEnd();
                    edk::GU::guLightfv32(GU_LIGHT0+i,GU_SPOT_DIRECTION,lightDirection);edkEnd();
                }
            }



            //drawVBO
            (this->*vboDraw)(GU_QUADS);
            edk::GU::guPopMatrix();edkEnd();
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
        edk::GU::guColor4f32(this->vertexs.get(0u)->color.r,
                             this->vertexs.get(0u)->color.g,
                             this->vertexs.get(0u)->color.b,
                             this->vertexs.get(0u)->color.a
                             );edkEnd();
        edk::GU::guPushMatrix();edkEnd();

        edk::GU::guTranslate2f32(this->translate);edkEnd();
        edk::GU::guRotateZf32(this->angle);edkEnd();
        edk::GU::guScale2f32(this->scale);edkEnd();
        //drawVBO
        (this->*vboDraw)(GU_LINE_LOOP);
        edk::GU::guPopMatrix();edkEnd();
    }
}

bool edk::shape::Rectangle2D::cloneFrom(edk::shape::Polygon2D* poly){
    //first remove the UV from the polygon
    this->deletePolygon();edkEnd();
    if(poly){
        return edk::shape::Polygon2D::cloneFrom(poly);edkEnd();
    }
    return false;
}
