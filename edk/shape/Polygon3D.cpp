#include "Polygon3D.h"

/*
Library Polygon3D - Draw a 2D Polygon in EDK Game Engine
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


//save one vertex in the memory to be used in create polygon to not crash the software
edk::shape::Vertex3D edk::shape::Polygon3D::staticVertex(0.f,0.f,0.f);

edk::shape::Vector3D edk::shape::Polygon3D::staticNormal(0.f,0.f,1.f);
edk::shape::UV2D edk::shape::Polygon3D::staticUV(0.f,0.f);


edk::shape::Polygon3D::Polygon3D(){
    //
    this->smooth=true;edkEnd();
}
edk::shape::Polygon3D::~Polygon3D(){
    //
    this->deletePolygon();edkEnd();
}
//update the center position
void edk::shape::Polygon3D::updateCenterPosition(){
    edk::uint32 size = this->vertexs.size();edkEnd();
    if(size){
        edk::shape::Vertex3D min,max;edkEnd();
        edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
            vertex = this->vertexs.get(0u);edkEnd();
            if(vertex){
                    min.x = vertex->vertex->x;edkEnd();
                    min.y = vertex->vertex->y;edkEnd();
                    min.z = vertex->vertex->z;edkEnd();

                    max.x = vertex->vertex->x;edkEnd();
                    max.y = vertex->vertex->y;edkEnd();
                    max.z = vertex->vertex->z;edkEnd();
            }
        for(edk::uint32 i=1u;i<size;i++){
            vertex = this->vertexs.get(i);edkEnd();
            if(vertex){
                if(vertex->vertex->x < min.x){
                    min.x = vertex->vertex->x;edkEnd();
                }
                if(vertex->vertex->y < min.y){
                    min.y = vertex->vertex->y;edkEnd();
                }
                if(vertex->vertex->z < min.z){
                    min.z = vertex->vertex->z;edkEnd();
                }

                if(vertex->vertex->x > max.x){
                    max.x = vertex->vertex->x;edkEnd();
                }
                if(vertex->vertex->y > max.y){
                    max.y = vertex->vertex->y;edkEnd();
                }
                if(vertex->vertex->z > max.z){
                    max.z = vertex->vertex->z;edkEnd();
                }
            }
        }
        //then update the center
        this->center.x = min.x + ((max.x - min.x)*0.5f);edkEnd();
        this->center.y = min.y + ((max.y - min.y)*0.5f);edkEnd();
        this->center.z = min.z + ((max.z - min.z)*0.5f);edkEnd();
    }
}

//draw the vertezes
bool edk::shape::Polygon3D::drawVertexs(){
    edk::uint32 size = this->vertexs.size();edkEnd();
    if(size){
        edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
        if(this->smooth){
            for(edk::uint32 i=0u;i<size;i++){
                vertex = this->vertexs.get(i);edkEnd();
                if(vertex){
                    vertex->draw();edkEnd();
                }
            }
        }
        else{
            this->normal.drawNormal();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                vertex = this->vertexs.get(i);edkEnd();
                if(vertex){
                    vertex->drawWithoutNormal();edkEnd();
                }
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon3D::drawVertexsOnly(){
    edk::uint32 size = this->vertexs.size();edkEnd();
    if(size){
        edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            vertex = this->vertexs.get(i);edkEnd();
            if(vertex){
                vertex->drawVertex();edkEnd();
            }
        }
        return true;
    }
    return false;
}
//draw the vertezes
bool edk::shape::Polygon3D::drawVertexsWithColor(edk::color4f32 color){
    edk::uint32 size = this->vertexs.size();edkEnd();
    if(size){
        edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            vertex = this->vertexs.get(i);edkEnd();
            if(vertex){
                vertex->drawWithColor(color);edkEnd();
            }
        }
        return true;
    }
    return false;
}

//create the polygon
bool edk::shape::Polygon3D::createPolygon(edk::uint32 vertexCount){
    this->deletePolygon();edkEnd();

    //test the vertexCount
    if(vertexCount>2u){
        //create the vertexs in the array
        if(this->vertexs.createArray(vertexCount)){
            bool haveVertex = true;edkEnd();
            edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
            //alloc the vertexes and put it into the array
            for(edk::uint32 i=0u;i<vertexCount;i++){
                if(haveVertex){
                    this->vertexs.set(i,(vertex=new edk::shape::Polygon3D::PolygonVertex(&edk::shape::Polygon3D::staticVertex,0u)));edkEnd();
                    if(!vertex){
                        haveVertex = false;edkEnd();
                        this->vertexs.set(i,NULL);edkEnd();
                    }
                }
                else{
                    this->vertexs.set(i,NULL);edkEnd();
                }
            }
            //
            if(haveVertex){
                return true;
            }
        }
    }
    //else delete the vertexes
    this->deletePolygon();edkEnd();
    return false;
}
void edk::shape::Polygon3D::deletePolygon(){
    edk::uint32 size = this->vertexs.size();edkEnd();
    edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        vertex = this->vertexs.get(i);edkEnd();
        if(vertex){
            delete vertex;edkEnd();
        }
    }
    this->vertexs.deleteArray();edkEnd();
}

//Set the vertexes
bool edk::shape::Polygon3D::setVertex(edk::uint32 position,edk::shape::Vertex3D* vertex,edk::uint32 vertexID){
    //test if have the vertex and position
    if(position<this->vertexs.size() && vertex){
        //get the vertex in position
        edk::shape::Polygon3D::PolygonVertex* vert = this->vertexs.get(position);edkEnd();
        if(vert){
            vert->vertex = vertex;edkEnd();
            vert->vertexID = vertexID;edkEnd();
        }

        //update the center position
        this->updateCenterPosition();edkEnd();

        return true;
    }
    return false;
}
bool edk::shape::Polygon3D::setNormal(edk::uint32 position,edk::shape::Vector3D* normal,edk::uint32 normalID){
    //test if have the vertex and position
    if(position<this->vertexs.size() && normal){
        //test the vertex type
        switch(this->vertexs.getNoIF(position)->getType()){
        case edk::shape::Polygon3D::typeVertex:
        {
            //delete the vertex and create a vertex with normal
            edk::shape::Polygon3D::PolygonVertex* vert = this->vertexs.get(position);edkEnd();
            edk::shape::Vertex3D* vertex = vert->vertex;edkEnd();
            edk::uint32 vertexID = vert->vertexID;edkEnd();
            delete vert;edkEnd();
            edk::shape::Polygon3D::PolygonVertexWithNormal* vert2 =
                    new edk::shape::Polygon3D::PolygonVertexWithNormal (vertex,vertexID,normal,0u);edkEnd();
            if(vert2){
                this->vertexs.set(position,(edk::shape::Polygon3D::PolygonVertex*)vert2);edkEnd();
            }
            else{
                this->vertexs.set(position,NULL);edkEnd();
                return false;
            }
        }
            break;
        case edk::shape::Polygon3D::typeVertexWithNormal:
        {
            edk::shape::Polygon3D::PolygonVertexWithNormal* vert = (edk::shape::Polygon3D::PolygonVertexWithNormal*)
                    this->vertexs.get(position);edkEnd();
            vert->normal = normal;edkEnd();
            vert->normalID = normalID;edkEnd();
        }
            break;
        case edk::shape::Polygon3D::typeVertexWithUV:
        {
            edk::shape::Polygon3D::PolygonVertexWithUV* vert =
                    (edk::shape::Polygon3D::PolygonVertexWithUV*)this->vertexs.get(position);edkEnd();
            edk::shape::Vertex3D* vertex = vert->vertex;edkEnd();
            edk::uint32 vertexID = vert->vertexID;edkEnd();
            edk::shape::UV2D* uv = vert->uv;edkEnd();
            edk::uint32 uvID = vert->uvID;edkEnd();
            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert2 =
                    new edk::shape::Polygon3D::PolygonVertexWithUVNormal(vertex,vertexID,uv,uvID,normal,0u);edkEnd();
            if(vert2){
                this->vertexs.set(position,(edk::shape::Polygon3D::PolygonVertex*)vert2);edkEnd();
            }
            else{
                this->vertexs.set(position,NULL);edkEnd();
                return false;
            }
        }
            break;
        case edk::shape::Polygon3D::typeVertexWithUVNormal:
        {
            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert = (edk::shape::Polygon3D::PolygonVertexWithUVNormal*)
                    this->vertexs.get(position);edkEnd();
            vert->normal = normal;edkEnd();
            vert->normalID = normalID;edkEnd();
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
        switch(this->vertexs.getNoIF(position)->getType()){
        case edk::shape::Polygon3D::typeVertex:
        {
            //delete the vertex and create a vertex with normal
            edk::shape::Polygon3D::PolygonVertex* vert = this->vertexs.get(position);edkEnd();
            edk::shape::Vertex3D* vertex = vert->vertex;edkEnd();
            edk::uint32 vertexID = vert->vertexID;edkEnd();
            delete vert;edkEnd();
            edk::shape::Polygon3D::PolygonVertexWithUV* vert2 =
                    new edk::shape::Polygon3D::PolygonVertexWithUV (vertex,vertexID,&edk::shape::Polygon3D::staticUV,0u);edkEnd();
            if(vert2){
                this->vertexs.set(position,(edk::shape::Polygon3D::PolygonVertex*)vert2);edkEnd();
            }
            else{
                this->vertexs.set(position,NULL);edkEnd();
                return false;
            }
        }
            break;
        case edk::shape::Polygon3D::typeVertexWithUV:
        {
            edk::shape::Polygon3D::PolygonVertexWithUV* vert = (edk::shape::Polygon3D::PolygonVertexWithUV*)
                    this->vertexs.get(position);edkEnd();
            vert->uv = uv;edkEnd();
            vert->uvID = uvID;edkEnd();
        }
            break;
        case edk::shape::Polygon3D::typeVertexWithNormal:
        {
            edk::shape::Polygon3D::PolygonVertexWithNormal* vert =
                    (edk::shape::Polygon3D::PolygonVertexWithNormal*)this->vertexs.get(position);edkEnd();
            edk::shape::Vertex3D* vertex = vert->vertex;edkEnd();
            edk::uint32 vertexID = vert->vertexID;edkEnd();
            edk::shape::Vector3D* normal = vert->normal;edkEnd();
            edk::uint32 normalID = vert->normalID;edkEnd();
            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert2 =
                    new edk::shape::Polygon3D::PolygonVertexWithUVNormal(vertex,vertexID,&this->staticUV,0u,normal,normalID);edkEnd();
            if(vert2){
                this->vertexs.set(position,(edk::shape::Polygon3D::PolygonVertex*)vert2);edkEnd();
            }
            else{
                this->vertexs.set(position,NULL);edkEnd();
                return false;
            }
        }
            break;
        case edk::shape::Polygon3D::typeVertexWithUVNormal:
        {
            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert = (edk::shape::Polygon3D::PolygonVertexWithUVNormal*)
                    this->vertexs.get(position);edkEnd();
            vert->uv = uv;edkEnd();
            vert->uvID = uvID;edkEnd();
        }
            break;
        }
        return true;
    }
    return false;
}

//Set polygon color
bool edk::shape::Polygon3D::setPolygonColor(edk::color4f32 color){
    edk::uint32 size = this->vertexs.size();edkEnd();
    if(size){
        edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            vertex = this->vertexs.get(i);edkEnd();
            if(vertex){
                vertex->vertex->r = color.r;edkEnd();
                vertex->vertex->g = color.g;edkEnd();
                vertex->vertex->b = color.b;edkEnd();
                vertex->vertex->a = color.a;edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon3D::setPolygonColor(edk::color3f32 color){
    return this->setPolygonColor(edk::color4f32 (color.r,color.g,color.b,1.f));edkEnd();
}
bool edk::shape::Polygon3D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,1.f));edkEnd();
}
bool edk::shape::Polygon3D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,a));edkEnd();
}

//Calculate the normal of the polygon
bool edk::shape::Polygon3D::updateNormal(){
    //test if have the vertexes
    if(this->vertexs.size()>2u){
        //get the vertexes
        edk::shape::Polygon3D::PolygonVertex* v1,*v2,*v3;edkEnd();
        v1 = this->vertexs.get(0u);edkEnd();
        v2 = this->vertexs.get(1u);edkEnd();
        v3 = this->vertexs.get(2u);edkEnd();

        if(v1 && v2 && v3){
            this->normal = edk::Math::crossProduct(v2->vertex->x - v1->vertex->x,
                                                   v2->vertex->y - v1->vertex->y,
                                                   v2->vertex->z - v1->vertex->z,
                                                   v3->vertex->x - v1->vertex->x,
                                                   v3->vertex->y - v1->vertex->y,
                                                   v3->vertex->z - v1->vertex->z
                                                   );edkEnd();
            this->normal = edk::Math::normalise(this->normal.x,this->normal.y,this->normal.z);edkEnd();
            //
            return true;
        }
    }
    return false;
}
void edk::shape::Polygon3D::setNormalFlat(edk::shape::Vector3D normal){
    this->normal = normal;edkEnd();
}

//print the polygon
bool edk::shape::Polygon3D::print(){
    edk::uint32 size = this->vertexs.size();edkEnd();
    if(size){
        this->normal.printNormal();edkEnd();
        edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            vertex = this->vertexs.get(i);edkEnd();
            if(vertex){
                vertex->print();edkEnd();
            }
        }
        return true;
    }
    return false;
}
//draw the polygon
void edk::shape::Polygon3D::draw(){
    //edk::GU::guPushMatrix();edkEnd();
    //    edk::GU::guTranslate2f32(this->translate);edkEnd();
    //    edk::GU::guRotateZf32(this->angle);edkEnd();
    //    edk::GU::guScale2f32(this->scale);edkEnd();
    edk::GU::guBegin(GU_POLYGON);edkEnd();
    this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
    //edk::GU::guPopMatrix();edkEnd();
}
//Draw the polygon with lines
void edk::shape::Polygon3D::drawWire(){
    edk::GU::guPushMatrix();edkEnd();
    //    edk::GU::guTranslate2f32(this->translate);edkEnd();
    //    edk::GU::guRotateZf32(this->angle);edkEnd();
    //    edk::GU::guScale2f32(this->scale);edkEnd();
    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    this->drawVertexsOnly();edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Polygon3D::drawWireWithColor(edk::color4f32 color){
    edk::GU::guPushMatrix();edkEnd();
    //    edk::GU::guTranslate2f32(this->translate);edkEnd();
    //    edk::GU::guRotateZf32(this->angle);edkEnd();
    //    edk::GU::guScale2f32(this->scale);edkEnd();
    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    this->drawVertexsWithColor(color);edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
//draw vertexs
void edk::shape::Polygon3D::drawPolygonVertexs(edk::color4f32 color){
    edk::GU::guPushMatrix();edkEnd();
    //    edk::GU::guTranslate2f32(this->translate);edkEnd();
    //    edk::GU::guRotateZf32(this->angle);edkEnd();
    //    edk::GU::guScale2f32(this->scale);edkEnd();
    edk::GU::guBegin(GU_POINTS);edkEnd();
    this->drawVertexsWithColor(color);edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}

void edk::shape::Polygon3D::drawPolygonNormals(){
    edk::uint32 size = this->vertexs.size();edkEnd();
    if(size){
        edk::GU::guPushMatrix();edkEnd();
        //    edk::GU::guTranslate2f32(this->translate);edkEnd();
        //    edk::GU::guRotateZf32(this->angle);edkEnd();
        //    edk::GU::guScale2f32(this->scale);edkEnd();
        edk::GU::guBegin(GU_LINES);edkEnd();
        edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
        if(this->smooth){
            for(edk::uint32 i=0u;i<size;i++){
                vertex = this->vertexs.get(i);edkEnd();
                if(vertex){
                    vertex->drawNormal();edkEnd();
                }
            }
        }
        else{
            vertex = this->vertexs.get(0u);edkEnd();
            if(vertex){
                //set the color of the vertex
                edk::GU::guColor4f32(vertex->vertex->r,
                                     vertex->vertex->g,
                                     vertex->vertex->b,
                                     vertex->vertex->a
                                     );edkEnd();
                this->center.drawVertex();edkEnd();
                this->center.drawVertexPosition(edk::vec3f32(this->normal.x,this->normal.y,this->normal.z));edkEnd();
            }
        }
        edk::GU::guEnd();edkEnd();
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::shape::Polygon3D::drawPolygonNormalsWithColor(edk::color4f32 color){
    edk::uint32 size = this->vertexs.size();edkEnd();
    if(size){
        edk::GU::guPushMatrix();edkEnd();
        //    edk::GU::guTranslate2f32(this->translate);edkEnd();
        //    edk::GU::guRotateZf32(this->angle);edkEnd();
        //    edk::GU::guScale2f32(this->scale);edkEnd();
        edk::GU::guBegin(GU_LINES);edkEnd();
        edk::shape::Polygon3D::PolygonVertex* vertex;edkEnd();
        if(this->smooth){
            for(edk::uint32 i=0u;i<size;i++){
                vertex = this->vertexs.get(i);edkEnd();
                if(vertex){
                    vertex->drawNormalWithColor(color);edkEnd();
                }
            }
        }
        else{
            //set the color of the vertex
            edk::GU::guColor4f32(color.r,
                                 color.g,
                                 color.b,
                                 color.a
                                 );edkEnd();
            this->center.drawVertex();edkEnd();
            this->center.drawVertexPosition(edk::vec3f32(this->normal.x,this->normal.y,this->normal.z));edkEnd();
        }
        edk::GU::guEnd();edkEnd();
        edk::GU::guPopMatrix();edkEnd();
    }
}

bool edk::shape::Polygon3D::cloneFrom(edk::shape::Polygon3D* poly){
    this->deletePolygon();edkEnd();
    if(poly){
        edk::uint32 size = poly->vertexs.size();edkEnd();
        if(size){
            if(this->vertexs.createArray(size)){
                bool haveVertex=true;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(haveVertex){
                        //get the polygonVertex
                        switch(poly->vertexs.getNoIF(i)->getType()){
                        case edk::shape::Polygon3D::typeVertex:
                        {
                            edk::shape::Polygon3D::PolygonVertex* vert = poly->vertexs.get(i);edkEnd();
                            if(vert){
                                edk::shape::Polygon3D::PolygonVertex* vert2 =
                                        new edk::shape::Polygon3D::PolygonVertex(vert->vertex,vert->vertexID);edkEnd();
                                if(vert2){
                                    //add the vertex in to the stack
                                    if(!this->vertexs.set(i,vert2)){
                                        delete vert2;edkEnd();
                                        haveVertex=false;edkEnd();
                                        this->vertexs.set(i,NULL);edkEnd();
                                    }
                                }
                                else{
                                    haveVertex=false;edkEnd();
                                    this->vertexs.set(i,NULL);edkEnd();
                                }
                            }
                            else{
                                haveVertex=false;edkEnd();
                                this->vertexs.set(i,NULL);edkEnd();
                            }
                        }
                            break;
                        case edk::shape::Polygon3D::typeVertexWithNormal:
                        {
                            edk::shape::Polygon3D::PolygonVertexWithNormal* vert =
                                    (edk::shape::Polygon3D::PolygonVertexWithNormal*)poly->vertexs.get(i);edkEnd();
                            if(vert){
                                edk::shape::Polygon3D::PolygonVertexWithNormal* vert2 =
                                        new edk::shape::Polygon3D::PolygonVertexWithNormal(vert->vertex,vert->vertexID,
                                                                                           vert->normal,vert->normalID
                                                                                           );edkEnd();
                                if(vert2){
                                    //add the vertex in to the stack
                                    if(!this->vertexs.set(i,vert2)){
                                        delete vert2;edkEnd();
                                        haveVertex=false;edkEnd();
                                        this->vertexs.set(i,NULL);edkEnd();
                                    }
                                }
                                else{
                                    haveVertex=false;edkEnd();
                                    this->vertexs.set(i,NULL);edkEnd();
                                }
                            }
                            else{
                                haveVertex=false;edkEnd();
                                this->vertexs.set(i,NULL);edkEnd();
                            }
                        }
                            break;
                        case edk::shape::Polygon3D::typeVertexWithUV:
                        {
                            edk::shape::Polygon3D::PolygonVertexWithUV* vert =
                                    (edk::shape::Polygon3D::PolygonVertexWithUV*)poly->vertexs.get(i);edkEnd();
                            if(vert){
                                edk::shape::Polygon3D::PolygonVertexWithUV* vert2 =
                                        new edk::shape::Polygon3D::PolygonVertexWithUV(vert->vertex,vert->vertexID,
                                                                                       vert->uv,vert->uvID
                                                                                       );edkEnd();
                                if(vert2){
                                    //add the vertex in to the stack
                                    if(!this->vertexs.set(i,vert2)){
                                        delete vert2;edkEnd();
                                        haveVertex=false;edkEnd();
                                        this->vertexs.set(i,NULL);edkEnd();
                                    }
                                }
                                else{
                                    haveVertex=false;edkEnd();
                                    this->vertexs.set(i,NULL);edkEnd();
                                }
                            }
                            else{
                                haveVertex=false;edkEnd();
                                this->vertexs.set(i,NULL);edkEnd();
                            }
                        }
                            break;
                        case edk::shape::Polygon3D::typeVertexWithUVNormal:
                        {
                            edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert =
                                    (edk::shape::Polygon3D::PolygonVertexWithUVNormal*)poly->vertexs.get(i);edkEnd();
                            if(vert){
                                edk::shape::Polygon3D::PolygonVertexWithUVNormal* vert2 =
                                        new edk::shape::Polygon3D::PolygonVertexWithUVNormal(vert->vertex,vert->vertexID,
                                                                                             vert->uv,vert->uvID,
                                                                                             vert->normal,vert->normalID
                                                                                             );edkEnd();
                                if(vert2){
                                    //add the vertex in to the stack
                                    if(!this->vertexs.set(i,vert2)){
                                        delete vert2;edkEnd();
                                        haveVertex=false;edkEnd();
                                        this->vertexs.set(i,NULL);edkEnd();
                                    }
                                }
                                else{
                                    haveVertex=false;edkEnd();
                                    this->vertexs.set(i,NULL);edkEnd();
                                }
                            }
                            else{
                                haveVertex=false;edkEnd();
                                this->vertexs.set(i,NULL);edkEnd();
                            }
                        }
                            break;
                        }

                    }
                    else{
                        this->vertexs.set(i,NULL);edkEnd();
                    }
                }
                if(haveVertex){
                    this->smooth = poly->smooth;edkEnd();
                    this->normal = poly->normal;edkEnd();
                    return true;
                }
                else{
                    this->deletePolygon();edkEnd();
                }
            }
        }
    }
    return false;
}
