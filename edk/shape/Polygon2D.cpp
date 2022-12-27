#include "Polygon2D.h"

/*
Library Polygon2D - Draw a 2D Polygon in EDK Game Engine
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
#warning "            Inside Polygon2D.cpp"
#endif

edk::shape::Polygon2D::Polygon2D(){
    this->type = edk::shape::polygon2D;edkEnd();
    this->angle=0.f;edkEnd();
    this->radius = 1.f;edkEnd();
    //init the polygonCOlor
    this->polygonColor = edk::color4f32(1,1,1,1);edkEnd();
    this->canDeletePolygon=false;edkEnd();
    //set frames to 1
    this->frames = edk::vec2ui32(1u,1u);edkEnd();
    this->framesSize = this->frames.x*this->frames.y;edkEnd();
    this->animationFrame=NULL;edkEnd();
    this->createAnimationFrames=false;edkEnd();

    //Physics parameters
    this->density=1.f;edkEnd();
    this->friction=0.0f;edkEnd();
    this->restitution=0.0f;edkEnd();

    this->polygonLine = this->polygonCircle=false;edkEnd();
    this->collisionID=collisionAways;edkEnd();

    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    this->matrixPosition.createMatrix(1u,3u);edkEnd();
    this->testTransform();edkEnd();
}
edk::shape::Polygon2D::Polygon2D(edk::uint32 vertexCount){
    this->angle=0.f;edkEnd();
    this->radius = 1.f;edkEnd();
    //
    this->polygonColor = edk::color4f32(0,0,0,1);edkEnd();
    this->canDeletePolygon=false;edkEnd();
    //create the vertex
    this->createPolygon(vertexCount);edkEnd();
    //set frames to 1
    this->frames = edk::vec2ui32(1u,1u);edkEnd();
    this->createAnimationFrames=false;edkEnd();

    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    this->testTransform();edkEnd();
}

edk::shape::Polygon2D::~Polygon2D(){
    //test if can delete the polygon
    if(this->canDeletePolygon){
        //destroy the polygon
        this->deletePolygon();edkEnd();
    }
    else{
        //set the shape to cant delete the vector
        this->vertexs.cantDeleteVector();edkEnd();
    }
    //else set canDeletePolygon to true
    this->canDeletePolygon=true;edkEnd();
}

//PROTECTED
//set the vertexFrames animation
bool edk::shape::Polygon2D::setVertexUVFrames(edk::uint32 vertex,edk::vec2ui32 frames){
    //load the polygon
    edk::shape::Vertex2DAnimatedUV* vTemp = (edk::shape::Vertex2DAnimatedUV*)this->getVertexPointer(vertex);edkEnd();
    if(vTemp){
        //test if the vertex is not the AnimatedUV
        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV){
            //then delete the vTemp and create another with AnimatedUV
            edk::shape::Vertex2DAnimatedUV* uvTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
            if(uvTemp){
                //copy the vTemp content to uvTemp
                uvTemp->position = vTemp->position;edkEnd();
                uvTemp->color = vTemp->color;edkEnd();
                //test if have UV
                if(vTemp->getType()==EDK_SHAPE_UV){
                    //copy the UV
                    uvTemp->setUV(vTemp->getUV());edkEnd();
                }

                //delete the vTemp
                delete vTemp;edkEnd();
                //set vTemp the uvTemp
                vTemp=uvTemp;edkEnd();
                //set the vertex on the array
                this->vertexs.set(vertex,(edk::shape::Vertex2D*)vTemp);edkEnd();
                //clean uvTemp
                uvTemp=NULL;edkEnd();
            }
            else{
                //else return false
                return false;
            }
        }
        //set the frames
        vTemp->setUVFrames(frames);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
//Draw the polygon
void edk::shape::Polygon2D::drawVertexs(){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs[i]){
            vertexs[i]->draw();edkEnd();
        }
    }
}
void edk::shape::Polygon2D::drawVertexsWithColor(edk::color4f32 color){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs[i]){
            vertexs[i]->drawWithColor(color);edkEnd();
        }
    }
}
//update framesSize
void edk::shape::Polygon2D::updateFramesSize(){
    //
    this->framesSize = this->frames.x * this->frames.y;edkEnd();
}
//test if is tranforming the polygon
void edk::shape::Polygon2D::testTransform(){
    if(this->translate.x!=0.f
            &&
            this->translate.y!=0.f
            &&
            this->angle
            &&
            this->scale.width!=1.f
            &&
            this->scale.height!=1.f
            ){
        //
        this->transforming=true;edkEnd();
    }
    this->transforming=false;edkEnd();
}

//PUBLIC
//load the vertex
edk::shape::Vertex2D* edk::shape::Polygon2D::getVertexPointer(edk::uint32 vertex){
    //test if have the vertex
    if(vertex<this->getVertexCount()){
        //then return the vertex
        return this->vertexs[vertex];edkEnd();
    }
    //else return NULL
    return NULL;
}

//create the polygon
bool edk::shape::Polygon2D::createPolygon(edk::uint32 vertexCount){
    //delete the polygon
    this->deletePolygon();edkEnd();
    //test the vertexCount
    if(vertexCount >= minimumVertex){
        //create the array
        if(this->vertexs.createArray(vertexCount)){
            //create all the vertexs
            for(edk::uint32 i =0u;i<vertexCount;i++){
                //
                this->vertexs.set(i,new edk::shape::Vertex2D());edkEnd();
                //Set alpha 1
                if(this->vertexs[i]){
                    //set the vertex
                    this->vertexs[i]->color = this->polygonColor;edkEnd();
                }
            }
            //set can delete the polygon in the future
            this->canDeletePolygon=true;edkEnd();
            //then return true
            return true;
        }
    }
    return false;
}

//test if the polygon is Counterclockwise
bool edk::shape::Polygon2D::isCounterclockwise(){
    //test the polygon size
    if(this->getVertexCount()>=3){
        //test the vertex angles
        edk::float32 angle1 = edk::Math::getAngle(this->vertexs[1u]->position - this->vertexs[0u]->position);edkEnd();
        edk::float32 angle2;edkEnd();
        edk::float32 angleTemp;edkEnd();
        for(register edk::uint32 i=2u;i<this->vertexs.size();i++){
            //get the next angle
            angle2 = edk::Math::getAngle(this->vertexs[i]->position - this->vertexs[0u]->position);edkEnd();
            angleTemp = angle2 - angle1;edkEnd();
            if(angleTemp>180.f || (angleTemp<0.f && angleTemp>-180.f)){
                //it's not counterClockwise
                return false;
            }
            angle1=angle2;edkEnd();
        }
        return true;
    }
    return false;
}

//SETTERS
//set the position of a vertex
bool edk::shape::Polygon2D::setVertexPosition(edk::uint32 vertex,edk::vec2f32 position){
    //load the polygon
    edk::shape::Vertex2D* vTemp = this->getVertexPointer(vertex);edkEnd();
    if(vTemp){
        //then set the position of the vertex
        vTemp->position = edk::vec2f32(position);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //
    return this->setVertexPosition(vertex,edk::vec2f32(x,y));edkEnd();
}
//set the color of a vertex
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::color4f32 color){
    //load the polygon
    edk::shape::Vertex2D* vTemp = this->getVertexPointer(vertex);edkEnd();
    if(vTemp){
        //then set the position of the vertex
        vTemp->color = edk::color4f32(color);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return this->setVertexColor(vertex,edk::color4f32(r,g,b,1.0f));edkEnd();
}
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setVertexColor(vertex,edk::color4f32(r,g,b,a));edkEnd();
}
//Set polygon color
bool edk::shape::Polygon2D::setPolygonColor(edk::color4f32 color){
    //first set the polygonColor
    this->polygonColor = edk::color4f32(color);edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs[i]->color = this->polygonColor;edkEnd();
        }
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonColor(edk::color3f32 color){
    return this->setPolygonColor(edk::color4f32 (color.r,color.g,color.b,1.f));edkEnd();
}
bool edk::shape::Polygon2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,1.f));edkEnd();
}
bool edk::shape::Polygon2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,a));edkEnd();
}
bool edk::shape::Polygon2D::setPolygonColorR(edk::float32 r){
    //first set the polygonColor
    this->polygonColor.r = r;edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs[i]->color.r = this->polygonColor.r;edkEnd();
        }
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonColorG(edk::float32 g){
    //first set the polygonColor
    this->polygonColor.g = g;edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs[i]->color.g = this->polygonColor.g;edkEnd();
        }
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonColorB(edk::float32 b){
    //first set the polygonColor
    this->polygonColor.b = b;edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs[i]->color.b = this->polygonColor.b;edkEnd();
        }
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonColorA(edk::float32 a){
    //first set the polygonColor
    this->polygonColor.a = a;edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs[i]->color.a = this->polygonColor.a;edkEnd();
        }
        //then return true
        return true;
    }
    //else return false
    return false;
}
//set the UVMap of the vertex
bool edk::shape::Polygon2D::setVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    //load the polygon
    edk::shape::Vertex2DWithUV* vTemp = (edk::shape::Vertex2DWithUV*)this->getVertexPointer(vertex);edkEnd();
    if(vTemp){
        //test what type of vertex it is
        if(vTemp->getType() == EDK_SHAPE_NOUV){
            //then delete the vTemp and create another with UV
            edk::shape::Vertex2DWithUV* uvTemp = new edk::shape::Vertex2DWithUV();edkEnd();
            if(uvTemp){
                //copy the vTemp content to uvTemp
                uvTemp->position = vTemp->position;edkEnd();
                uvTemp->color = vTemp->color;edkEnd();

                //delete the vTemp
                delete vTemp;edkEnd();
                //set vTemp the uvTemp
                vTemp=uvTemp;edkEnd();
                //set the vertex on the array
                this->vertexs.set(vertex,(edk::shape::Vertex2D*)vTemp);edkEnd();
                //clean uvTemp
                uvTemp=NULL;edkEnd();
            }
            else{
                //else return false
                return false;
            }
        }
        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
            edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
            vTemp2->setUV(uv);edkEnd();
            return true;
        }
        //set the uv
        vTemp->setUV(uv);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setVertexUV(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //
    return this->setVertexUV(vertex,edk::vec2f32(x,y));edkEnd();
}
//Set the polygonFrames
bool edk::shape::Polygon2D::setPolygonUVFrames(edk::vec2ui32 frames){
    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    //test the frames
    if(frames.x && frames.y){
        //save the frames
        this->frames=frames;edkEnd();
        //set the frames on vertex
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //
            this->setVertexUVFrames(i,frames);edkEnd();
        }
        this->updateFramesSize();edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonUVFrames(edk::uint32 x,edk::uint32 y){
    //
    return this->setPolygonUVFrames(edk::vec2ui32(x,y));edkEnd();
}
bool edk::shape::Polygon2D::setPolygonUVFramesX(edk::uint32 x){
    //
    if(x){
        this->frames.x=x;edkEnd();
    }
    return this->setPolygonUVFrames(edk::vec2ui32(x,
                                                  this->frames.y
                                                  )
                                    );edkEnd();
}
bool edk::shape::Polygon2D::setPolygonUVFramesY(edk::uint32 y){
    //
    if(y){
        this->frames.y=y;edkEnd();
    }
    return this->setPolygonUVFrames(edk::vec2ui32(this->frames.x,
                                                  y
                                                  )
                                    );edkEnd();
}
//Set the polygon frame
void edk::shape::Polygon2D::usePolygonUVFrame(edk::vec2ui32 frame){
    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];edkEnd();
        if(temp){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                //then set the frame
                temp->useUVFrame(frame);edkEnd();
                this->frameUsing=frame;edkEnd();
            }
        }
    }
}
void edk::shape::Polygon2D::usePolygonUVFramePosition(edk::uint32 position){
    //test if the framesX is not zero
    if(this->frames.x && this->frames.y){
        //make the UV positions
        edk::vec2ui32 UVPosition(position%this->frames.x,position/this->frames.x);edkEnd();
        //set the frame in AllVertexs
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //load the vertex
            edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];edkEnd();
            if(temp){
                //test if temp have frames
                if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                    //then set the position
                    temp->useUVFrame(UVPosition);edkEnd();
                    this->frameUsing=UVPosition;edkEnd();
                }
            }
        }
    }
}
void edk::shape::Polygon2D::usePolygonUVFrameX(edk::uint32 x){
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];edkEnd();
        if(temp){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                //then set the frame
                temp->useUVFrameX(x);edkEnd();
                this->frameUsing.x = x;edkEnd();
            }
        }
    }
}
void edk::shape::Polygon2D::usePolygonUVFrameY(edk::uint32 y){
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];edkEnd();
        if(temp){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                //then set the frame
                temp->useUVFrameY(y);edkEnd();
                this->frameUsing.x = y;edkEnd();
            }
        }
    }
}

//clean the transformation
void edk::shape::Polygon2D::cleanTransform(){
    this->translate = edk::vec2f32(0,0);edkEnd();
    this->scale=edk::size2f32(1,1);edkEnd();
    this->angle = 0u;edkEnd();
    this->testTransform();edkEnd();
}
//Set the position of the polygon
void edk::shape::Polygon2D::setTranslate(edk::vec2f32 translate){
    this->translate = translate;edkEnd();
    this->testTransform();edkEnd();
}
void edk::shape::Polygon2D::setTranslate(edk::float32 translate){
    this->translate = translate;edkEnd();
    this->testTransform();edkEnd();
}
void edk::shape::Polygon2D::setTranslate(edk::float32 x,edk::float32 y){
    this->setTranslate(edk::vec2f32 (x,y));edkEnd();
}
//set the scale
void edk::shape::Polygon2D::setScale(edk::size2f32 scale){
    this->scale=scale;edkEnd();
    this->testTransform();edkEnd();
}
void edk::shape::Polygon2D::setScale(edk::float32 scale){
    this->scale=scale;edkEnd();
    this->testTransform();edkEnd();
}
void edk::shape::Polygon2D::setScale(edk::float32 width,edk::float32 height){
    this->setScale(edk::size2f32 (width,height));edkEnd();
}
//set the angle
void edk::shape::Polygon2D::setAngle(edk::float32 angle){
    this->angle=angle;edkEnd();
    this->testTransform();edkEnd();
}
//set physics
void edk::shape::Polygon2D::setDensity(edk::float32 density){
    this->density=density;edkEnd();
}
void edk::shape::Polygon2D::setFriction(edk::float32 friction){
    this->friction=friction;edkEnd();
}
void edk::shape::Polygon2D::setRestitution(edk::float32 restitution){
    this->restitution=restitution;edkEnd();
}

//function to calculate boundingBox
bool edk::shape::Polygon2D::calculateBoundingBox(edk::rectf32* rectangle,edk::vector::Matrix<edk::float32,3,3>* transformMat){
    if(transformMat && rectangle && this->getVertexCount()){
        //generate the boundingBox
        edk::rectf32 temp = this->generateBoundingBox(transformMat);edkEnd();

        if(rectangle->origin.x>temp.origin.x){
            rectangle->origin.x=temp.origin.x;edkEnd();
        }
        if(rectangle->origin.y>temp.origin.y){
            rectangle->origin.y=temp.origin.y;edkEnd();
        }
        if(rectangle->size.width<temp.size.width){
            rectangle->size.width=temp.size.width;edkEnd();
        }
        if(rectangle->size.height<temp.size.height){
            rectangle->size.height=temp.size.height;edkEnd();
        }

        return true;
    }
    return false;
}
edk::rectf32 edk::shape::Polygon2D::generateBoundingBox(edk::vector::Matrix<edk::float32,3,3>* transformMat){
    edk::rectf32 ret;edkEnd();

    edk::uint32 size = this->getVertexCount();edkEnd();
    if(size){
        //first copy the matrix
        if(this->matrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->translate,&this->matrixTranslate);edkEnd();
            edk::Math::generateRotateMatrix(this->angle,&this->matrixRotate);edkEnd();
            edk::Math::generateScaleMatrix(this->scale,&this->matrixScale);edkEnd();

            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);edkEnd();

            //transform all the vertices
            if(this->matrixPosition.haveMatrix()){
                //transform the first vertex
                if(vertexs.get(0u)){
                    edk::vec2f32 vexPosition;edkEnd();
                    //
                    this->matrixPosition.set(0u,0u,vertexs.get(0u)->position.x);edkEnd();
                    this->matrixPosition.set(0u,1u,vertexs.get(0u)->position.y);edkEnd();
                    this->matrixPosition.set(0u,2u,1.f);edkEnd();

                    //multiply the matrix
                    this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                    ret.origin.x = this->matrixPosition.get(0u,0u);edkEnd();
                    ret.origin.y = this->matrixPosition.get(0u,1u);edkEnd();
                    ret.size.width = ret.origin.x;edkEnd();
                    ret.size.height = ret.origin.y;edkEnd();
                    if(size==2u){
                        //process the rectangle or line
                        if(vertexs.get(1u)){
                            //V0x1
                            this->matrixPosition.set(0u,0u,vertexs.get(0u)->position.x);edkEnd();
                            this->matrixPosition.set(0u,1u,vertexs.get(1u)->position.y);edkEnd();
                            this->matrixPosition.set(0u,2u,1.f);edkEnd();

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                            vexPosition.x = this->matrixPosition.get(0u,0u);edkEnd();
                            vexPosition.y = this->matrixPosition.get(0u,1u);edkEnd();

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;edkEnd();
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;edkEnd();
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;edkEnd();
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;edkEnd();
                            }

                            //V1x0
                            this->matrixPosition.set(0u,0u,vertexs.get(1u)->position.x);edkEnd();
                            this->matrixPosition.set(0u,1u,vertexs.get(0u)->position.y);edkEnd();
                            this->matrixPosition.set(0u,2u,1.f);edkEnd();

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                            vexPosition.x = this->matrixPosition.get(0u,0u);edkEnd();
                            vexPosition.y = this->matrixPosition.get(0u,1u);edkEnd();

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;edkEnd();
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;edkEnd();
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;edkEnd();
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;edkEnd();
                            }

                            //V1x1
                            this->matrixPosition.set(0u,0u,vertexs.get(1u)->position.x);edkEnd();
                            this->matrixPosition.set(0u,1u,vertexs.get(1u)->position.y);edkEnd();
                            this->matrixPosition.set(0u,2u,1.f);edkEnd();

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                            vexPosition.x = this->matrixPosition.get(0u,0u);edkEnd();
                            vexPosition.y = this->matrixPosition.get(0u,1u);edkEnd();

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;edkEnd();
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;edkEnd();
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;edkEnd();
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;edkEnd();
                            }
                        }
                    }
                    else{
                        for(edk::uint32 i=0u;i<size;i++){
                            if(vertexs.get(i)){
                                this->matrixPosition.set(0u,0u,vertexs.get(i)->position.x);edkEnd();
                                this->matrixPosition.set(0u,1u,vertexs.get(i)->position.y);edkEnd();
                                this->matrixPosition.set(0u,2u,1.f);edkEnd();

                                //multiply the matrix
                                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                                vexPosition.x = this->matrixPosition.get(0u,0u);edkEnd();
                                vexPosition.y = this->matrixPosition.get(0u,1u);edkEnd();

                                if(ret.origin.x > vexPosition.x){
                                    ret.origin.x = vexPosition.x;edkEnd();
                                }
                                if(ret.origin.y > vexPosition.y){
                                    ret.origin.y = vexPosition.y;edkEnd();
                                }
                                if(ret.size.width < vexPosition.x){
                                    ret.size.width = vexPosition.x;edkEnd();
                                }
                                if(ret.size.height < vexPosition.y){
                                    ret.size.height = vexPosition.y;edkEnd();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}

//delete the polygonVertex
void edk::shape::Polygon2D::deletePolygon(){
    if(this->canDeletePolygon){
        //remove the animation
        this->framesRemoveAnimation();edkEnd();
        edk::uint32 size = this->getVertexCount();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            if(this->vertexs[i]){
                delete this->vertexs[i];edkEnd();
            }
        }
        this->vertexs.deleteArray();edkEnd();
        this->canDeletePolygon=false;edkEnd();
    }
}
//remove the UV of one vertex
bool edk::shape::Polygon2D::removeVertexUV(edk::uint32 vertex){
    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    //find the vertex
    edk::shape::Vertex2DWithUV* uvTemp = (edk::shape::Vertex2DWithUV*)this->getVertexPointer(vertex);edkEnd();
    if(uvTemp){
        //test the ID of the vertex
        if(uvTemp->getType() == EDK_SHAPE_UV
                ||
                uvTemp->getType() == EDK_SHAPE_ANIMATED_UV
                ){
            //then create another vertex
            edk::shape::Vertex2D* vTemp = new edk::shape::Vertex2D();edkEnd();
            if(vTemp){
                //copy the uvTemp to vTemp
                vTemp->position = uvTemp->position;edkEnd();
                vTemp->color = uvTemp->color;edkEnd();

                //set the new vertex to the position
                this->vertexs.set(vertex,vTemp);edkEnd();
                //delete the uvTemp
                delete uvTemp;edkEnd();
                //clean uvTemp
                uvTemp=NULL;edkEnd();
                //return true
                return true;
            }
        }
    }
    //else return false
    return false;
}
//remove the UV from the polygon
void edk::shape::Polygon2D::removePolygonUV(){
    //
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //
        this->edk::shape::Polygon2D::removeVertexUV(i);edkEnd();
    }
}
//clean the UV animation in polygons
void edk::shape::Polygon2D::cleanPolygonUVAnimation(){
    //
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];edkEnd();
        if(temp){
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                //
                temp->cleanUVAnimation();edkEnd();
            }
        }
    }
}
//ANIMATION
//create a new animationFrames
bool edk::shape::Polygon2D::framesCreateAnimation(){
    //remove the last animationFrames
    this->framesRemoveAnimation();edkEnd();
    //create a new animationFrames and set it
    edk::animation::Interpolation1DGroup* temp=NULL;edkEnd();
    if(this->framesSetAnimation( (temp = new edk::animation::Interpolation1DGroup) )){
        //return true
        return this->createAnimationFrames=true;edkEnd();
    }
    //else delete temp if exist
    if(temp){
        //
        delete temp;edkEnd();
    }
    //else return false
    return this->createAnimationFrames=false;edkEnd();
}
bool edk::shape::Polygon2D::framesSetAnimation(edk::animation::Interpolation1DGroup* anim){
    //test the anim
    if(anim){
        //test if the anim is iqual the animationFrame
        if(this->animationFrame == anim){
            //then return true
            return true;
        }
        //else remove the last animation
        this->framesRemoveAnimation();edkEnd();

        //set the anim
        anim->retainObject((edk::animation::InterpolationGroup**)&this->animationFrame);edkEnd();
        //test if have the new animation
        if(this->animationFrame){
            //return true
            return true;
        }
    }
    //else return false;
    return false;
}
//return the animationPointer
edk::animation::Interpolation1DGroup* edk::shape::Polygon2D::framesGetAnimation(){
    //
    return this->animationFrame;edkEnd();
}
//remove the animationGroup
void edk::shape::Polygon2D::framesRemoveAnimation(){
    this->createAnimationFrames=false;edkEnd();
    //test if have an animation
    if(this->framesHaveAnimation()){
        //remove the animation
        this->animationFrame->releaseObject((edk::animation::InterpolationGroup**)&this->animationFrame);edkEnd();
    }
    this->animationFrame=NULL;edkEnd();
}
//return true if have an animation
bool edk::shape::Polygon2D::framesHaveAnimation(){
    //
    return (this->animationFrame!=NULL);edkEnd();
}
//return true if this polygon create the animation
bool edk::shape::Polygon2D::framesIsAnimationCreator(){
    //
    return this->createAnimationFrames;edkEnd();
}


//return the vertexCount
edk::uint32 edk::shape::Polygon2D::getVertexCount(){
    //
    return this->vertexs.size();edkEnd();
}
//return if the vertex have UV
edk::uint8 edk::shape::Polygon2D::getVertexType(edk::uint32 pos){
    //test if have the polygon
    if(pos<this->getVertexCount()){
        if(this->vertexs[pos]){
            return this->vertexs[pos]->getType();edkEnd();
        }
    }
    //else retun false
    return 0u;edkEnd();
}
//return the vertex
edk::vec2f32 edk::shape::Polygon2D::getVertexPosition(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs[pos]){
            //return the vertex
            return edk::vec2f32(this->vertexs[pos]->position.x,this->vertexs[pos]->position.y);edkEnd();
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);edkEnd();
}
//return the vertex with all transformations
edk::vec2f32 edk::shape::Polygon2D::getVertexPositionTransformed(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs[pos]){
            //apply the transformations
            edk::vec2f32 ret;edkEnd();
            //scale
            ret.x = this->vertexs[pos]->position.x * this->scale.width;edkEnd();
            ret.y = this->vertexs[pos]->position.y * this->scale.height;edkEnd();
            //rotate
            ret = edk::Math::rotatePlus(ret,this->angle);edkEnd();
            //translate
            ret.x += this->translate.x;edkEnd();
            ret.y += this->translate.y;edkEnd();
            //return the vertex
            return ret;
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);edkEnd();
}
//return the vertex color
edk::color4f32 edk::shape::Polygon2D::getVertexColor(edk::uint32 pos){

    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs[pos]){
            //return the vertex
            return edk::color4f32(this->vertexs[pos]->color.r,this->vertexs[pos]->color.g,this->vertexs[pos]->color.b,
                                  this->vertexs[pos]->color.a);edkEnd();
        }
    }
    //else return a zero vertex
    return edk::color4f32(0,0,0,0);edkEnd();
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon2D::getVertexUV(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        //get a temp
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[pos];edkEnd();
        if(temp){
            //test if the vertex have the UV
            switch(temp->getType()){
            //
            case EDK_SHAPE_UV:
                //
                return edk::vec2f32(temp->getUV().x,temp->getUV().y);edkEnd();
                break;
            case EDK_SHAPE_ANIMATED_UV:
                //
                return edk::vec2f32(temp->getSaved().x,temp->getSaved().y);edkEnd();
                break;
            }
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);edkEnd();
}
//return the frames
edk::vec2ui32 edk::shape::Polygon2D::getFrames(){
    //
    return this->frames;edkEnd();
}
edk::uint32 edk::shape::Polygon2D::getFramesPosition(){
    return this->framesSize;edkEnd();
}
//return the frameUseds
edk::vec2ui32 edk::shape::Polygon2D::getFrameUsed(){
    return this->frameUsing;edkEnd();
}
edk::uint32 edk::shape::Polygon2D::getFramePositionUsed(){
    if(this->frames.x && this->frames.y){
        return (this->frames.x * this->frameUsing.y) + this->frameUsing.x;edkEnd();
    }
    return 0u;edkEnd();
}
//return the transform
edk::vec2f32 edk::shape::Polygon2D::getTranslate(){
    return this->translate;edkEnd();
}
edk::size2f32 edk::shape::Polygon2D::getScale(){
    return this->scale;edkEnd();
}
edk::float32 edk::shape::Polygon2D::getAngle(){
    return this->angle;edkEnd();
}
//return true if is transforming
bool edk::shape::Polygon2D::isTransforming(){
    return this->transforming;edkEnd();
}
//get Physics
edk::float32 edk::shape::Polygon2D::getDensity(){
    return this->density;edkEnd();
}
edk::float32 edk::shape::Polygon2D::getFriction(){
    return this->friction;edkEnd();
}
edk::float32 edk::shape::Polygon2D::getRestitution(){
    return this->restitution;edkEnd();
}

//return true if the polygon is a circle
bool edk::shape::Polygon2D::isCircle(){
    if(this->type == edk::shape::circle2D){
        return true;
    }
    return false;
    //return this->polygonCircle;edkEnd();
}
//return the circleRadius only if is a circle
edk::float32 edk::shape::Polygon2D::getCircleRadius(){
    if(this->type == edk::shape::circle2D){
        return this->radius;edkEnd();
    }
    return 0.f;
}
//return true if it's a Rectangle
bool edk::shape::Polygon2D::isRect(){
    if(this->type == edk::shape::rectangle2D){
        return true;
    }
    return false;
}
//return true if it's lines
bool edk::shape::Polygon2D::isLine(){
    if(this->type == edk::shape::line2D){
        return true;
    }
    return false;
    //return this->polygonLine;edkEnd();
}
//get line ID
edk::uint8 edk::shape::Polygon2D::getCollisionID(){
    return this->collisionID;edkEnd();
}

//Set to cant delete the polygon
void edk::shape::Polygon2D::cantDeletePolygon(){
    //
    this->canDeletePolygon=false;edkEnd();
    //set matrices can't delete the matrix and vector
    this->matrixPosition.cantDeleteVector();edkEnd();
    this->matrixTranslate.cantDeleteMatrix();edkEnd();
    this->matrixRotate.cantDeleteMatrix();edkEnd();
    this->matrixScale.cantDeleteMatrix();edkEnd();
    this->matrixTransform.cantDeleteMatrix();edkEnd();
}

//print the polygon
void edk::shape::Polygon2D::print(){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs[i]){
            vertexs[i]->print(i);edkEnd();
        }
    }
}
//Draw the polygon
void edk::shape::Polygon2D::draw(){
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    edk::GU::guBegin(GU_POLYGON);edkEnd();
    this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
//Draw the polygon with lines
void edk::shape::Polygon2D::drawWire(){
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
//draw vertexs
void edk::shape::Polygon2D::drawPolygonVertexs(edk::color4f32 color){
    edk::GU::guBegin(GL_POINTS);edkEnd();
    //edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    this->drawVertexsWithColor(color);edkEnd();
    edk::GU::guEnd();edkEnd();
}

//Write to XML
bool edk::shape::Polygon2D::writeToXML(edk::XML* xml,edk::uint32 polygonID){
    if(xml){
        bool ret=false;edkEnd();
        //create the ID string
        edk::char8* id = edk::String::int32ToStr(polygonID);edkEnd();
        if(id){
            edk::char8* name = edk::String::strCat((edk::char8*)"polygon_",id);edkEnd();
            if(name){
                //create the polygon
                if(xml->addSelectedNextChild(name)){
                    //select the name
                    if(xml->selectChild(name)){
                        ret=true;edkEnd();
                        edk::char8* temp = NULL;edkEnd();
                        //test if it's circle
                        if(this->polygonCircle || this->type==edk::shape::circle2D){
                            //set the string
                            xml->setSelectedString("circle");edkEnd();
                            temp = edk::String::float32ToStr(this->getCircleRadius());edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"radius",temp);edkEnd();
                                delete[] temp;edkEnd();
                            }
                        }
                        else if(this->polygonLine || this->type==edk::shape::line2D){
                            //set the string
                            xml->setSelectedString("line");edkEnd();
                            temp = edk::String::int32ToStr(this->getCollisionID());edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"collisionID",temp);edkEnd();
                                delete[] temp;edkEnd();
                            }
                        }
                        else if(this->type==edk::shape::rectangle2D){
                            //set the string
                            xml->setSelectedString("rectangle");edkEnd();
                        }
                        else{
                            //set the string
                            xml->setSelectedString("polygon");edkEnd();
                        }

                        edk::uint32 size = this->getVertexCount();edkEnd();
                        //save the vertexs
                        temp=edk::String::int32ToStr(size);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"vCount",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //Write Vertexs
                        for(edk::uint32 i=0u;i<size;i++){
                            edk::shape::Vertex2DAnimatedUV* polyTemp = (edk::shape::Vertex2DAnimatedUV*)vertexs[i];edkEnd();
                            if(polyTemp){
                                polyTemp->writeToXML(i,xml);edkEnd();
                            }
                        }
                        if(xml->addSelectedNextChild("uvFrames")){
                            if(xml->selectChild("uvFrames")){
                                //write UVFrames
                                temp = edk::String::float32ToStr(this->getFrames().x);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"framesX",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getFrames().y);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"framesY",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                //write selected
                                temp = edk::String::float32ToStr(this->frameUsing.x);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"frameUsingX",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->frameUsing.y);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"frameUsingY",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        //write transformations
                        if(xml->addSelectedNextChild("transformation")){
                            if(xml->selectChild("transformation")){
                                temp = edk::String::float32ToStr(this->getTranslate().x);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"translateX",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getTranslate().y);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"translateY",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getScale().width);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"scaleW",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getScale().height);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"scaleH",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getAngle());edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"angle",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        //write physics
                        if(xml->addSelectedNextChild("physics")){
                            if(xml->selectChild("physics")){
                                temp = edk::String::float32ToStr(this->getDensity());edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"density",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getFriction());edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"friction",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getRestitution());edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"restitution",temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        //UV animations
                        if(this->animationFrame){
                            this->animationFrame->writeToXML(xml,0u);edkEnd();
                        }
                        xml->selectFather();edkEnd();
                    }
                }
                delete[] name;edkEnd();
            }
            delete[] id;edkEnd();
        }
        return ret;
    }
    return false;
}
//read from XML
bool edk::shape::Polygon2D::readFromXML(edk::XML* xml,edk::uint32 polygonID){
    if(xml){
        bool ret=false;edkEnd();
        //create the ID string
        edk::char8* id = edk::String::int32ToStr(polygonID);edkEnd();
        if(id){
            edk::char8* name = edk::String::strCat((edk::char8*)"polygon_",id);edkEnd();
            if(name){
                //create the polygon
                //select the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;edkEnd();
                    //load the polygonType
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                    if(temp){
                        //teste the type
                        if(edk::String::strCompare(temp,"circle")){
                            this->polygonCircle = true;edkEnd();
                            this->polygonLine = false;edkEnd();
                            this->radius = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("radius"));edkEnd();
                            this->collisionID = 0u;edkEnd();
                            this->type = edk::shape::circle2D;edkEnd();
                        }
                        else if(edk::String::strCompare(temp,"line")){
                            this->polygonLine = true;edkEnd();
                            this->polygonCircle = false;edkEnd();
                            this->radius = 0.f;edkEnd();
                            this->collisionID = edk::String::strToInt32(xml->getSelectedAttributeValueByName("collisionID"));edkEnd();
                            this->type = edk::shape::line2D;edkEnd();
                        }
                        else if(edk::String::strCompare(temp,"rectangle")){
                            this->polygonLine = false;edkEnd();
                            this->polygonCircle = false;edkEnd();
                            this->radius = 0.f;edkEnd();
                            this->collisionID = 0u;edkEnd();
                            this->type = edk::shape::rectangle2D;edkEnd();
                        }
                        else if(edk::String::strCompare(temp,"polygon")){
                            //
                            this->type = edk::shape::polygon2D;edkEnd();
                        }
                        delete[] temp;edkEnd();
                    }

                    //read the vertex count
                    edk::uint32 size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("vCount"));edkEnd();
                    if(size){
                        this->createPolygon(size);edkEnd();
                        //read the vertexs
                        for(edk::uint32 i=0u;i<size;i++){
                            //read the vertex type
                            edk::uint8 type = edk::shape::Vertex2D::readTypeFromXML(i,xml);edkEnd();
                            switch(type){
                            case EDK_SHAPE_ANIMATED_UV:
                            case EDK_SHAPE_UV:
                            {
                                edk::shape::Vertex2DAnimatedUV temp;edkEnd();
                                if(temp.readFromXML(i,xml)){
                                    //set the data
                                    this->setVertexPosition(i,temp.position);edkEnd();
                                    this->setVertexColor(i,temp.color);edkEnd();
                                    this->setVertexUV(i,temp.getSaved());edkEnd();
                                }
                                break;
                            }
                            case EDK_SHAPE_NOUV:
                            {
                                edk::shape::Vertex2D temp;edkEnd();
                                if(temp.readFromXML(i,xml)){
                                    //set the data
                                    this->setVertexPosition(i,temp.position);edkEnd();
                                    this->setVertexColor(i,temp.color);edkEnd();
                                }
                                break;
                            }
                            }
                        }



                        //read uvFrames
                        if(xml->selectChild("uvFrames")){
                            //write UVFrames
                            edk::uint32 uvFrameX = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("framesX"));edkEnd();
                            edk::uint32 uvFrameY = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("framesY"));edkEnd();
                            //set uvFrames
                            this->setPolygonUVFrames(edk::vec2ui32(uvFrameX,uvFrameY));edkEnd();

                            //set using the frame ID
                            this->frameUsing.x = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("frameUsingX"));edkEnd();
                            this->frameUsing.y = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("frameUsingY"));edkEnd();

                            //set the frameUsing
                            this->usePolygonUVFrame(this->frameUsing);edkEnd();

                            xml->selectFather();edkEnd();
                        }

                        //read transformation
                        if(xml->selectChild("transformation")){
                            this->translate.x = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("translateX"));edkEnd();
                            this->translate.y = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("translateY"));edkEnd();
                            this->scale.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleW"));edkEnd();
                            this->scale.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleH"));edkEnd();
                            this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));edkEnd();
                            this->testTransform();edkEnd();
                            xml->selectFather();edkEnd();
                        }

                        //read physics
                        if(xml->selectChild("physics")){
                            this->density = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("density"));edkEnd();
                            this->friction = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("friction"));edkEnd();
                            this->restitution = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("restitution"));edkEnd();
                            xml->selectFather();edkEnd();
                        }

                        this->framesCreateAnimation();edkEnd();
                        //UV animations
                        if(this->animationFrame){
                            if(this->animationFrame->readFromXML(xml,0u)){
                                //set play
                                this->animationFrame->playForward();edkEnd();
                            }
                            else{
                                //delete the frame
                                this->framesRemoveAnimation();edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] id;edkEnd();
        }
        return ret;
    }
    return false;
}

bool edk::shape::Polygon2D::cloneFrom(edk::shape::Polygon2D* poly){
    //first delete the vertexs
    this->deletePolygon();edkEnd();
    if(poly){
        //then create a new polygon
        if(this->createPolygon(poly->getVertexCount())){
            //then copy the vertex
            for(edk::uint32 i=0u;i<this->getVertexCount();i++){
                //copy the vertex
                edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)vertexs[i];edkEnd();
                if(temp){
                    //this->setVertexPosition(i,poly->getVertexPosition(i));edkEnd();
                    temp->position = poly->getVertexPosition(i);edkEnd();
                    //this->setVertexColor(i,poly->getVertexColor(i));edkEnd();
                    temp->color = poly->getVertexColor(i);edkEnd();
                    //copy the frames
                    //this->setVertexUVFrames(i,poly->getFrames());edkEnd();
                    //get vertexType
                    switch(poly->getVertexType(i)){
                    //
                    case EDK_SHAPE_ANIMATED_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));edkEnd();
                        this->setVertexUVFrames(i,poly->getFrames());edkEnd();
                        break;
                    case EDK_SHAPE_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));edkEnd();
                        break;
                    };
                }
            }
        }
        //set the polygonFrames
        this->setPolygonUVFrames(poly->getFrames());edkEnd();
        this->usePolygonUVFrame(poly->frameUsing);edkEnd();
        //set the transformations
        this->setTranslate(poly->getTranslate());edkEnd();
        this->setScale(poly->getScale());edkEnd();
        this->setAngle(poly->getAngle());edkEnd();
        //set physics
        this->setDensity(poly->getDensity());edkEnd();
        this->setFriction(poly->getFriction());edkEnd();
        this->setRestitution(poly->getRestitution());edkEnd();
        //
        this->type = poly->type;edkEnd();
        this->polygonCircle = poly->polygonCircle;edkEnd();
        this->radius=poly->radius;edkEnd();
        this->polygonLine = poly->polygonLine;edkEnd();
        this->collisionID = poly->collisionID;edkEnd();
        //set the animation
        this->framesSetAnimation(poly->framesGetAnimation());edkEnd();
        this->createAnimationFrames = poly->createAnimationFrames;edkEnd();
        //copy the matrices
        this->matrixTranslate.cloneFrom(&poly->matrixTranslate);edkEnd();
        this->matrixRotate.cloneFrom(&poly->matrixRotate);edkEnd();
        this->matrixScale.cloneFrom(&poly->matrixScale);edkEnd();
        this->matrixTransform.cloneFrom(&poly->matrixTransform);edkEnd();
        //
        return true;
    }
    return false;
}
