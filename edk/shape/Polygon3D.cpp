#include "Polygon3D.h"

/*
Library Polygon3D - Draw a 2D Polygon in EDK Game Engine
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


//save one vertex in the memory to be used in create polygon to not crash the software
edk::shape::Vertex3D edk::shape::Polygon3D::staticVertex(0.f,0.f,0.f);

edk::shape::Vector3D edk::shape::Polygon3D::staticNormal(0.f,0.f,1.f);
edk::shape::UV2D edk::shape::Polygon3D::staticUV(0.f,0.f);


edk::shape::Polygon3D::Polygon3D(){
    //
    this->smooth=true;
}
edk::shape::Polygon3D::~Polygon3D(){
    //
    this->deletePolygon();
}
//draw the vertezes
bool edk::shape::Polygon3D::drawVertexs(){
    edk::uint32 size = this->vertexs.size();
    if(size){
        edk::shape::Polygon3D::PolygonVertex* vertex;
        if(this->smooth){
            for(edk::uint32 i=0u;i<size;i++){
                vertex = this->vertexs[i];
                if(vertex){
                    vertex->draw();
                }
            }
        }
        else{
            for(edk::uint32 i=0u;i<size;i++){
                vertex = this->vertexs[i];
                if(vertex){
                    vertex->drawWithNormal(this->normal);
                }
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon3D::drawVertexsOnly(){
    edk::uint32 size = this->vertexs.size();
    if(size){
        edk::shape::Polygon3D::PolygonVertex* vertex;
        for(edk::uint32 i=0u;i<size;i++){
            vertex = this->vertexs[i];
            if(vertex){
                vertex->drawVertex();
            }
        }
        return true;
    }
    return false;
}
//draw the vertezes
bool edk::shape::Polygon3D::drawVertexsWithColor(edk::color4f32 color){
    edk::uint32 size = this->vertexs.size();
    if(size){
        edk::shape::Polygon3D::PolygonVertex* vertex;
        for(edk::uint32 i=0u;i<size;i++){
            vertex = this->vertexs[i];
            if(vertex){
                vertex->drawWithColor(color);
            }
        }
        return true;
    }
    return false;
}

//create the polygon
bool edk::shape::Polygon3D::createPolygon(edk::uint32 vertexCount){
    this->deletePolygon();

    //test the vertexCount
    if(vertexCount>2u){
        //create the vertexs in the array
        if(this->vertexs.createArray(vertexCount)){
            bool haveVertex = true;
            edk::shape::Polygon3D::PolygonVertex* vertex;
            //alloc the vertexes and put it into the array
            for(edk::uint32 i=0u;i<vertexCount;i++){
                if(haveVertex){
                    this->vertexs.set(i,(vertex=new edk::shape::Polygon3D::PolygonVertex(&edk::shape::Polygon3D::staticVertex,0u)));
                    if(!vertex){
                        haveVertex = false;
                        this->vertexs.set(i,NULL);
                    }
                }
                else{
                    this->vertexs.set(i,NULL);
                }
            }
            //
            if(haveVertex) return true;
        }
    }
    //else delete the vertexes
    this->deletePolygon();
    return false;
}
void edk::shape::Polygon3D::deletePolygon(){
    edk::uint32 size = this->vertexs.size();
    edk::shape::Polygon3D::PolygonVertex* vertex;
    for(edk::uint32 i=0u;i<size;i++){
        vertex = this->vertexs[i];
        if(vertex) delete vertex;
    }
    this->vertexs.deleteArray();
}

//Set the vertexes
bool edk::shape::Polygon3D::setVertex(edk::uint32 position,edk::shape::Vertex3D* vertex,edk::uint32 vertexID){
    //test if have the vertex and position
    if(position<this->vertexs.size() && vertex){
        //get the vertex in position
        edk::shape::Polygon3D::PolygonVertex* vert = this->vertexs[position];
        vert->vertex = vertex;
        vert->vertexID = vertexID;
        return true;
    }
    return false;
}
bool edk::shape::Polygon3D::setNormal(edk::uint32 position,edk::shape::Vector3D* normal,edk::uint32 normalID){
    //test if have the vertex and position
    if(position<this->vertexs.size() && normal){
        //test the vertex type
        switch(this->vertexs[position]->getType()){
        case edk::shape::Polygon3D::typeVertex:
        {
            //delete the vertex and create a vertex with normal
            edk::shape::Polygon3D::PolygonVertex* vert = this->vertexs[position];
            edk::shape::Vertex3D* vertex = vert->vertex;
            edk::uint32 vertexID = vert->vertexID;
            delete vert;
            edk::shape::Polygon3D::PolygonVertexWithNormal* vert2 =
                    new edk::shape::Polygon3D::PolygonVertexWithNormal (vertex,vertexID,&edk::shape::Polygon3D::staticNormal,0u);
            if(vert2){
                this->vertexs.set(position,(edk::shape::Polygon3D::PolygonVertex*)vert2);
            }
            else{
                this->vertexs.set(position,NULL);
                return false;
            }
        }
        case edk::shape::Polygon3D::typeVertexWithNormal:
        {
            edk::shape::Polygon3D::PolygonVertexWithNormal* vert = (edk::shape::Polygon3D::PolygonVertexWithNormal*)
                    this->vertexs[position];
            vert->normal = normal;
            vert->normalID = normalID;
        }
            break;
        case edk::shape::Polygon3D::typeVertexWithUV:
        {
            edk::shape::Polygon3D::PolygonVertexWithUV* vert =
                    (edk::shape::Polygon3D::PolygonVertexWithUV*)this->vertexs[position];
            edk::shape::Vertex3D* vertex = vert->vertex;
            edk::uint32 vertexID = vert->vertexID;
            edk::shape::UV2D* uv = vert->uv;
            edk::uint32 uvID = vert->uvID;
            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert2 =
                    new edk::shape::Polygon3D::PolygonVertexWithUVNormal(vertex,vertexID,uv,uvID,&this->staticNormal,0u);
            if(vert2){
                this->vertexs.set(position,(edk::shape::Polygon3D::PolygonVertex*)vert2);
            }
            else{
                this->vertexs.set(position,NULL);
                return false;
            }
        }
        case edk::shape::Polygon3D::typeVertexWithUVNormal:
        {
            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert = (edk::shape::Polygon3D::PolygonVertexWithUVNormal*)
                    this->vertexs[position];
            vert->normal = normal;
            vert->normalID = normalID;
        }
            break;
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon3D::setUV(edk::uint32 position,edk::shape::UV2D* uv,edk::uint32 uvID){
    //test if have the vertex and position
    if(position<this->vertexs.size() && uv){
        //test the vertex type
        switch(this->vertexs[position]->getType()){
        case edk::shape::Polygon3D::typeVertex:
        {
            //delete the vertex and create a vertex with normal
            edk::shape::Polygon3D::PolygonVertex* vert = this->vertexs[position];
            edk::shape::Vertex3D* vertex = vert->vertex;
            edk::uint32 vertexID = vert->vertexID;
            delete vert;
            edk::shape::Polygon3D::PolygonVertexWithUV* vert2 =
                    new edk::shape::Polygon3D::PolygonVertexWithUV (vertex,vertexID,&edk::shape::Polygon3D::staticUV,0u);
            if(vert2){
                this->vertexs.set(position,(edk::shape::Polygon3D::PolygonVertex*)vert2);
            }
            else{
                this->vertexs.set(position,NULL);
                return false;
            }
        }
        case edk::shape::Polygon3D::typeVertexWithUV:
        {
            edk::shape::Polygon3D::PolygonVertexWithUV* vert = (edk::shape::Polygon3D::PolygonVertexWithUV*)
                    this->vertexs[position];
            vert->uv = uv;
            vert->uvID = uvID;
        }
            break;
        case edk::shape::Polygon3D::typeVertexWithNormal:
        {
            edk::shape::Polygon3D::PolygonVertexWithNormal* vert =
                    (edk::shape::Polygon3D::PolygonVertexWithNormal*)this->vertexs[position];
            edk::shape::Vertex3D* vertex = vert->vertex;
            edk::uint32 vertexID = vert->vertexID;
            edk::shape::Vector3D* normal = vert->normal;
            edk::uint32 normalID = vert->normalID;
            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert2 =
                    new edk::shape::Polygon3D::PolygonVertexWithUVNormal(vertex,vertexID,&this->staticUV,0u,normal,normalID);
            if(vert2){
                this->vertexs.set(position,(edk::shape::Polygon3D::PolygonVertex*)vert2);
            }
            else{
                this->vertexs.set(position,NULL);
                return false;
            }
        }
        case edk::shape::Polygon3D::typeVertexWithUVNormal:
        {
            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert = (edk::shape::Polygon3D::PolygonVertexWithUVNormal*)
                    this->vertexs[position];
            vert->uv = uv;
            vert->uvID = uvID;
        }
            break;
        }
        return true;
    }
    return false;
}

//Calculate the normal of the polygon
bool edk::shape::Polygon3D::updateNormal(){
    //test if have the vertexes
    if(this->vertexs.size()>2u){
        //get the vertexes
        edk::shape::Polygon3D::PolygonVertex* v1,*v2,*v3;
        v1 = this->vertexs[0u];
        v2 = this->vertexs[1u];
        v3 = this->vertexs[2u];

        if(v1 && v2 && v3){
            this->normal = edk::Math::crossProduct(v2->vertex->x - v1->vertex->x,
                                                   v2->vertex->y - v1->vertex->y,
                                                   v2->vertex->z - v1->vertex->z,
                                                   v3->vertex->x - v1->vertex->x,
                                                   v3->vertex->y - v1->vertex->y,
                                                   v3->vertex->z - v1->vertex->z
                                                   );
            this->normal = edk::Math::normalise3f(this->normal.x,this->normal.y,this->normal.z);
            //
            return true;
        }
    }
    return false;
}

//print the polygon
bool edk::shape::Polygon3D::print(){
    edk::uint32 size = this->vertexs.size();
    if(size){
        this->normal.printNormal();
        edk::shape::Polygon3D::PolygonVertex* vertex;
        for(edk::uint32 i=0u;i<size;i++){
            vertex = this->vertexs[i];
            if(vertex){
                vertex->print();
            }
        }
        return true;
    }
    return false;
}
//draw the polygon
void edk::shape::Polygon3D::draw(){
    edk::GU::guPushMatrix();
    //    edk::GU::guTranslate2f32(this->translate);
    //    edk::GU::guRotateZf32(this->angle);
    //    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_POLYGON);
    this->drawVertexs();
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
//Draw the polygon with lights
bool edk::shape::Polygon3D::drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(lightPositions && lightDirections && lightIsOn){
        edk::GU::guPushMatrix();

        edk::float32 lightPosition[4u];
        edk::float32 lightDirection[4u];

        //translate the lights
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(*lightIsOn[i]){
                //translate the light and direction
                lightPosition[0u] = *lightPositions[i][0u];
                lightPosition[1u] = *lightPositions[i][1u];
                lightPosition[2u] = *lightPositions[i][2u];
                lightPosition[3u] = *lightPositions[i][3u];
                //
                lightDirection[0u] = *lightDirections[i][0u];
                lightDirection[1u] = *lightDirections[i][1u];
                lightDirection[2u] = *lightDirections[i][2u];
                lightDirection[3u] = *lightDirections[i][3u];


                edk::GU::guLightfv32(GU_LIGHT0+i,GU_POSITION,lightPosition);
                edk::GU::guLightfv32(GU_LIGHT0+i,GU_SPOT_DIRECTION,lightDirection);
            }
        }


        edk::GU::guBegin(GU_POLYGON);
        this->drawVertexs();
        edk::GU::guEnd();
        edk::GU::guPopMatrix();
        return true;
    }
    return false;
}
//Draw the polygon with lines
void edk::shape::Polygon3D::drawWire(){
    edk::GU::guPushMatrix();
    //    edk::GU::guTranslate2f32(this->translate);
    //    edk::GU::guRotateZf32(this->angle);
    //    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_LINE_LOOP);
    this->drawVertexsOnly();
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
void edk::shape::Polygon3D::drawWireWithColor(edk::color4f32 color){
    edk::GU::guPushMatrix();
    //    edk::GU::guTranslate2f32(this->translate);
    //    edk::GU::guRotateZf32(this->angle);
    //    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_LINES);
    this->drawVertexsWithColor(color);
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
//draw vertexs
void edk::shape::Polygon3D::drawPolygonVertexs(edk::color4f32 color){
    edk::GU::guPushMatrix();
    //    edk::GU::guTranslate2f32(this->translate);
    //    edk::GU::guRotateZf32(this->angle);
    //    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_POINTS);
    this->drawVertexsWithColor(color);
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}

bool edk::shape::Polygon3D::cloneFrom(edk::shape::Polygon3D* poly){
    this->deletePolygon();
    if(poly){
        edk::uint32 size = poly->vertexs.size();
        if(size){
            if(this->vertexs.createArray(size)){
                bool haveVertex=true;
                for(edk::uint32 i=0u;i<size;i++){
                    if(haveVertex){
                        //get the polygonVertex
                        switch(poly->vertexs[i]->getType()){
                        case edk::shape::Polygon3D::typeVertex:
                        {
                            edk::shape::Polygon3D::PolygonVertex* vert = poly->vertexs[i];
                            if(vert){
                                edk::shape::Polygon3D::PolygonVertex* vert2 =
                                        new edk::shape::Polygon3D::PolygonVertex(vert->vertex,vert->vertexID);
                                if(vert2){
                                    //add the vertex in to the stack
                                    if(!this->vertexs.set(i,vert2)){
                                        delete vert2;
                                        haveVertex=false;
                                        this->vertexs.set(i,NULL);
                                    }
                                }
                                else{
                                    haveVertex=false;
                                    this->vertexs.set(i,NULL);
                                }
                            }
                            else{
                                haveVertex=false;
                                this->vertexs.set(i,NULL);
                            }
                        }
                            break;
                        case edk::shape::Polygon3D::typeVertexWithNormal:
                        {
                            edk::shape::Polygon3D::PolygonVertexWithNormal* vert =
                                    (edk::shape::Polygon3D::PolygonVertexWithNormal*)poly->vertexs[i];
                            if(vert){
                                edk::shape::Polygon3D::PolygonVertexWithNormal* vert2 =
                                        new edk::shape::Polygon3D::PolygonVertexWithNormal(vert->vertex,vert->vertexID,
                                                                                           vert->normal,vert->normalID
                                                                                           );
                                if(vert2){
                                    //add the vertex in to the stack
                                    if(!this->vertexs.set(i,vert2)){
                                        delete vert2;
                                        haveVertex=false;
                                        this->vertexs.set(i,NULL);
                                    }
                                }
                                else{
                                    haveVertex=false;
                                    this->vertexs.set(i,NULL);
                                }
                            }
                            else{
                                haveVertex=false;
                                this->vertexs.set(i,NULL);
                            }
                        }
                            break;
                        case edk::shape::Polygon3D::typeVertexWithUV:
                        {
                            edk::shape::Polygon3D::PolygonVertexWithUV* vert =
                                    (edk::shape::Polygon3D::PolygonVertexWithUV*)poly->vertexs[i];
                            if(vert){
                                edk::shape::Polygon3D::PolygonVertexWithUV* vert2 =
                                        new edk::shape::Polygon3D::PolygonVertexWithUV(vert->vertex,vert->vertexID,
                                                                                       vert->uv,vert->uvID
                                                                                       );
                                if(vert2){
                                    //add the vertex in to the stack
                                    if(!this->vertexs.set(i,vert2)){
                                        delete vert2;
                                        haveVertex=false;
                                        this->vertexs.set(i,NULL);
                                    }
                                }
                                else{
                                    haveVertex=false;
                                    this->vertexs.set(i,NULL);
                                }
                            }
                            else{
                                haveVertex=false;
                                this->vertexs.set(i,NULL);
                            }
                        }
                            break;
                        case edk::shape::Polygon3D::typeVertexWithUVNormal:
                        {
                            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert =
                                    (edk::shape::Polygon3D::PolygonVertexWithUVNormal*)poly->vertexs[i];
                            if(vert){
                                edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert2 =
                                        new edk::shape::Polygon3D::PolygonVertexWithUVNormal(vert->vertex,vert->vertexID,
                                                                                             vert->uv,vert->uvID,
                                                                                             vert->normal,vert->normalID
                                                                                             );
                                if(vert2){
                                    //add the vertex in to the stack
                                    if(!this->vertexs.set(i,vert2)){
                                        delete vert2;
                                        haveVertex=false;
                                        this->vertexs.set(i,NULL);
                                    }
                                }
                                else{
                                    haveVertex=false;
                                    this->vertexs.set(i,NULL);
                                }
                            }
                            else{
                                haveVertex=false;
                                this->vertexs.set(i,NULL);
                            }
                        }
                            break;
                        }

                    }
                    else{
                        this->vertexs.set(i,NULL);
                    }
                }
                if(haveVertex){
                    this->smooth = poly->smooth;
                    this->normal = poly->normal;
                    return true;
                }
                else{
                    this->deletePolygon();
                }
            }
        }
    }
    return false;
}
