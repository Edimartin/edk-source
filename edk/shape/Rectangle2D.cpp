#include "Rectangle2D.h"

/*
Library Rectangle2D - Draw a 2D Rectangle in EDK Game Engine
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
#warning "            Inside Rectangle2D.cpp"
#endif

edk::shape::Rectangle2D::Rectangle2D::Rectangle2D()
{
    this->polygonColor.a=1.f;
    //create the polygon
    this->createPolygon();
}

edk::shape::Rectangle2D::~Rectangle2D()
{
    //delete the polygon
    edk::shape::Polygon2D::deletePolygon();
}
//createPolygon
bool edk::shape::Rectangle2D::createPolygon(){
    //create a polygon with 2 vertex

    //delete the polygon
    edk::shape::Polygon2D::deletePolygon();
    if(this->vertexs.createArray(2u)){
        //create all the vertexs
        edk::shape::Vertex2DWithUV* temp=NULL;
        this->vertexs.set(0u,new edk::shape::Vertex2DWithUV());
        if(this->vertexs[0u]){
            //Set alpha 1
            this->vertexs[0u]->color = this->polygonColor;
            //set the position
            this->vertexs[0u]->position = edk::vec2f32(0,1);
            temp = (edk::shape::Vertex2DWithUV*)this->vertexs[0u];
            temp->setUV((edk::float32)0,(edk::float32)0);
        }
        this->vertexs.set(1u,new edk::shape::Vertex2DWithUV());
        if(this->vertexs[1u]){
            //Set alpha 1
            this->vertexs[1u]->color = this->polygonColor;
            //set the position
            this->vertexs[1u]->position = edk::vec2f32(1,0);
            temp = (edk::shape::Vertex2DWithUV*)this->vertexs[1u];
            temp->setUV((edk::float32)1,(edk::float32)1);
        }
        //set can delete the polygon
        this->canDeletePolygon=true;
        //then return true
        return true;
    }
    //else return false
    return false;
}

//Virtual Functions
bool edk::shape::Rectangle2D::createPolygon(edk::uint32 vertexCount){
    //set the function to do nothing but return true to think he create
    if(vertexCount)
        return true;
    return false;
}
void edk::shape::Rectangle2D::deletePolygon(){
    //clean the vertex removind your UV
    this->removePolygonUV();
}

//set the pivo to the center of the rectangle
void edk::shape::Rectangle2D::setPivoToCenter(){
    //get the size
    if(this->vertexs[0u]&&this->vertexs[1u]){
        edk::size2f32 size(this->vertexs[1u]->position.x-this->vertexs[0u]->position.x,
                this->vertexs[1u]->position.y-this->vertexs[0u]->position.y
                );
        this->vertexs[0u]->position = edk::vec2f32(size.width * -0.5f,size.height * -0.5f);
        this->vertexs[1u]->position = edk::vec2f32(size.width *  0.5f,size.height *  0.5f);
    }
}

//print the rectangle
void edk::shape::Rectangle2D::print(){
    //
    printf("\nRectangle");
    edk::shape::Polygon2D::print();
}

//Draw the rectangle
void edk::shape::Rectangle2D::draw(){
    //
    //draw the vertexs
    if(this->vertexs.size()>=2u){
        //draw the first vertex
        edk::GU::guColor4f32(this->vertexs[0u]->color.r,
                this->vertexs[0u]->color.g,
                this->vertexs[0u]->color.b,
                this->vertexs[0u]->color.a
                );

        edk::GU::guPushMatrix();

        edk::GU::guTranslate2f32(this->translate);
        edk::GU::guRotateZf32(this->angle);
        edk::GU::guScale2f32(this->scale);

        edk::GU::guBegin(GU_QUADS);
        if(this->vertexs[0u]->getType() != EDK_SHAPE_NOUV
                &&
                this->vertexs[1u]->getType() != EDK_SHAPE_NOUV
                ){
            edk::shape::Vertex2DWithUV* vTemp0 = (edk::shape::Vertex2DWithUV*)this->vertexs[0u];
            edk::shape::Vertex2DWithUV* vTemp1 = (edk::shape::Vertex2DWithUV*)this->vertexs[1u];

            //draw the third vertex
            edk::GU::guColor4f32(this->vertexs[1u]->color.r,
                    this->vertexs[1u]->color.g,
                    this->vertexs[1u]->color.b,
                    this->vertexs[1u]->color.a
                    );

            //draw the normal
            edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
            //draw the textureUV
            edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp0->getUVY());
            //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp1->getUVY());
            //draw the vertex
            edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[0u]->position.y, 0.0f);

            //draw the normal
            //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
            //draw the textureUV
            edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp1->getUVY());
            //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp0->getUVY());
            //draw the vertex
            edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[1u]->position.y, 0.0f);

            //draw the third vertex
            edk::GU::guColor4f32(this->vertexs[1u]->color.r,
                    this->vertexs[1u]->color.g,
                    this->vertexs[1u]->color.b,
                    this->vertexs[1u]->color.a
                    );

            //draw the normal
            //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
            //draw the textureUV
            edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp1->getUVY());
            //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp0->getUVY());
            //draw the vertex
            edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[1u]->position.y, 0.0f);

            //draw the normal
            //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
            //draw the textureUV
            edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp0->getUVY());
            //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp1->getUVY());
            //draw the vertex
            edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[0u]->position.y, 0.0f);
        }
        else{

            //draw the normal
            edk::GU::guVertexNormal3f32(0,0,1);
            //draw the textureUV
            edk::GU::guVertexTex2f32(0.f, 1.f);
            //glMultiTexCoord2f(GL_TEXTURE0,0.f, 1.f);
            //draw the vertex
            edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[0u]->position.y, 0.0f);

            //draw the normal
            edk::GU::guVertexNormal3f32(0,0,1);
            //draw the textureUV
            //edk::GU::guVertexTex2f32(0.f, 0.f);
            //glMultiTexCoord2f(GL_TEXTURE0,0.f, 0.f);
            //draw the vertex
            edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[1u]->position.y, 0.0f);

            //draw the third vertex
            edk::GU::guColor4f32(this->vertexs[1u]->color.r,
                    this->vertexs[1u]->color.g,
                    this->vertexs[1u]->color.b,
                    this->vertexs[1u]->color.a
                    );

            //draw the normal
            //edk::GU::guVertexNormal3f32(0,0,1);
            //draw the textureUV
            edk::GU::guVertexTex2f32(1.f, 0.f);
            //glMultiTexCoord2f(GL_TEXTURE0,1.f, 0.f);
            //draw the vertex
            edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[1u]->position.y, 0.0f);

            //draw the normal
            //edk::GU::guVertexNormal3f32(0,0,1);
            //draw the textureUV
            edk::GU::guVertexTex2f32(1.f, 1.f);
            //glMultiTexCoord2f(GL_TEXTURE0,1.f, 1.f);
            //draw the vertex
            edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[0u]->position.y, 0.0f);
        }
        edk::GU::guEnd();
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
            edk::GU::guColor4f32(this->vertexs[0u]->color.r,
                    this->vertexs[0u]->color.g,
                    this->vertexs[0u]->color.b,
                    this->vertexs[0u]->color.a
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
                    temp = edk::Math::rotatePlus2f(edk::vec2f32(lightPosition[0u],lightPosition[1u])
                            ,this->angle*-1.f
                            );
                    lightPosition[0u] = temp.x;
                    lightPosition[1u] = temp.y;

                    temp = edk::Math::rotatePlus2f(edk::vec2f32(lightDirection[0u],lightDirection[1u])
                            ,this->angle*-1.f
                            );
                    lightDirection[0u] = temp.x;
                    lightDirection[1u] = temp.y;

                    edk::GU::guLightfv32(GU_LIGHT0+i,GU_POSITION,lightPosition);
                    edk::GU::guLightfv32(GU_LIGHT0+i,GU_SPOT_DIRECTION,lightDirection);
                }
            }

            edk::GU::guBegin(GU_QUADS);
            if(this->vertexs[0u]->getType() != EDK_SHAPE_NOUV
                    &&
                    this->vertexs[1u]->getType() != EDK_SHAPE_NOUV
                    ){
                edk::shape::Vertex2DWithUV* vTemp0 = (edk::shape::Vertex2DWithUV*)this->vertexs[0u];
                edk::shape::Vertex2DWithUV* vTemp1 = (edk::shape::Vertex2DWithUV*)this->vertexs[1u];
                //draw the normal
                edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
                //draw the textureUV
                edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp0->getUVY());
                //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp1->getUVY());
                //draw the vertex
                edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[0u]->position.y, 0.0f);

                //draw the normal
                //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
                //draw the textureUV
                edk::GU::guVertexTex2f32(vTemp0->getUVX(), vTemp1->getUVY());
                //glMultiTexCoord2f(GL_TEXTURE0,vTemp0->getUVX(), vTemp0->getUVY());
                //draw the vertex
                edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[1u]->position.y, 0.0f);

                //draw the third vertex
                edk::GU::guColor4f32(this->vertexs[1u]->color.r,
                        this->vertexs[1u]->color.g,
                        this->vertexs[1u]->color.b,
                        this->vertexs[1u]->color.a
                        );

                //draw the normal
                //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
                //draw the textureUV
                edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp1->getUVY());
                //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp0->getUVY());
                //draw the vertex
                edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[1u]->position.y, 0.0f);

                //draw the normal
                //edk::GU::guVertexNormal3f32(0.f,0.f,1.f);
                //draw the textureUV
                edk::GU::guVertexTex2f32(vTemp1->getUVX(), vTemp0->getUVY());
                //glMultiTexCoord2f(GL_TEXTURE0,vTemp1->getUVX(), vTemp1->getUVY());
                //draw the vertex
                edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[0u]->position.y, 0.0f);
            }
            else{

                //draw the normal
                edk::GU::guVertexNormal3f32(0,0,1);
                //draw the textureUV
                edk::GU::guVertexTex2f32(0.f, 1.f);
                //glMultiTexCoord2f(GL_TEXTURE0,0.f, 1.f);
                //draw the vertex
                edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[0u]->position.y, 0.0f);

                //draw the normal
                edk::GU::guVertexNormal3f32(0,0,1);
                //draw the textureUV
                //edk::GU::guVertexTex2f32(0.f, 0.f);
                //glMultiTexCoord2f(GL_TEXTURE0,0.f, 0.f);
                //draw the vertex
                edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[1u]->position.y, 0.0f);

                //draw the third vertex
                edk::GU::guColor4f32(this->vertexs[1u]->color.r,
                        this->vertexs[1u]->color.g,
                        this->vertexs[1u]->color.b,
                        this->vertexs[1u]->color.a
                        );

                //draw the normal
                //edk::GU::guVertexNormal3f32(0,0,1);
                //draw the textureUV
                edk::GU::guVertexTex2f32(1.f, 0.f);
                //glMultiTexCoord2f(GL_TEXTURE0,1.f, 0.f);
                //draw the vertex
                edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[1u]->position.y, 0.0f);

                //draw the normal
                //edk::GU::guVertexNormal3f32(0,0,1);
                //draw the textureUV
                edk::GU::guVertexTex2f32(1.f, 1.f);
                //glMultiTexCoord2f(GL_TEXTURE0,1.f, 1.f);
                //draw the vertex
                edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[0u]->position.y, 0.0f);
            }
            edk::GU::guEnd();
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
        edk::GU::guColor4f32(this->vertexs[0u]->color.r,
                this->vertexs[0u]->color.g,
                this->vertexs[0u]->color.b,
                this->vertexs[0u]->color.a
                );
        edk::GU::guPushMatrix();

        edk::GU::guTranslate2f32(this->translate);
        edk::GU::guRotateZf32(this->angle);
        edk::GU::guScale2f32(this->scale);

        edk::GU::guBegin(GU_LINE_LOOP);

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[0u]->position.y, 0.0f);

        //draw the second vertex
        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs[0u]->position.x, this->vertexs[1u]->position.y, 0.0f);

        //draw the third vertex
        edk::GU::guColor4f32(this->vertexs[1u]->color.r,
                this->vertexs[1u]->color.g,
                this->vertexs[1u]->color.b,
                this->vertexs[1u]->color.a
                );

        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[1u]->position.y, 0.0f);

        //draw the forty vertex
        //draw the normal
        edk::GU::guVertexNormal3f32(0,0,1);
        //draw the vertex
        edk::GU::guVertex3f32( this->vertexs[1u]->position.x, this->vertexs[0u]->position.y, 0.0f);
        edk::GU::guEnd();
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
