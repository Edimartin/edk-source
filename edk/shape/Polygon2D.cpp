#include "Polygon2D.h"

/*
Library Polygon2D - Draw a 2D Polygon in EDK Game Engine
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
#warning "            Inside Polygon2D.cpp"
#endif

edk::shape::Polygon2D::Polygon2D(){
    this->angle=0.f;
    this->radius = 1.f;
    //init the polygonCOlor
    this->polygonColor = edk::color4f32(1,1,1,1);
    this->canDeletePolygon=false;
    //set frames to 1
    this->frames = edk::vec2ui32(1u,1u);
    this->framesSize = this->frames.x*this->frames.y;
    this->animationFrame=NULL;
    this->createAnimationFrames=false;

    //Physics parameters
    this->density=1.f;
    this->friction=0.0f;
    this->restitution=0.0f;

    this->polygonLine = this->polygonCircle=false;
    this->collisionID=collisionAways;

    this->frameUsing=edk::vec2ui32(0u,0u);
    this->testTransform();
}
edk::shape::Polygon2D::Polygon2D(edk::uint32 vertexCount){
    this->angle=0.f;
    this->radius = 1.f;
    //
    this->polygonColor = edk::color4f32(0,0,0,1);
    this->canDeletePolygon=false;
    //create the vertex
    this->createPolygon(vertexCount);
    //set frames to 1
    this->frames = edk::vec2ui32(1u,1u);
    this->createAnimationFrames=false;

    this->frameUsing=edk::vec2ui32(0u,0u);
    this->testTransform();
}

edk::shape::Polygon2D::~Polygon2D(){
    //test if can delete the polygon
    if(this->canDeletePolygon){
        //destroy the polygon
        this->deletePolygon();
    }
    else{
        //set the shape to cant delete the vector
        this->vertexs.cantDeleteVector();
    }
    //else set canDeletePolygon to true
    this->canDeletePolygon=true;
}

//PROTECTED
//set the vertexFrames animation
bool edk::shape::Polygon2D::setVertexUVFrames(edk::uint32 vertex,edk::vec2ui32 frames){
    //load the polygon
    edk::shape::Vertex2DAnimatedUV* vTemp = (edk::shape::Vertex2DAnimatedUV*)this->getVertexPointer(vertex);
    if(vTemp){
        //test if the vertex is not the AnimatedUV
        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV
                ){
            //then delete the vTemp and create another with AnimatedUV
            edk::shape::Vertex2DAnimatedUV* uvTemp = new edk::shape::Vertex2DAnimatedUV();
            if(uvTemp){
                //copy the vTemp content to uvTemp
                uvTemp->position = vTemp->position;
                uvTemp->color = vTemp->color;
                //test if have UV
                if(vTemp->getType()==EDK_SHAPE_UV){
                    //copy the UV
                    uvTemp->setUV(vTemp->getUV());
                }

                //delete the vTemp
                delete vTemp;
                //set vTemp the uvTemp
                vTemp=uvTemp;
                //set the vertex on the array
                this->vertexs.set(vertex,(edk::shape::Vertex2D*)vTemp);
                //clean uvTemp
                uvTemp=NULL;
            }
            else{
                //else return false
                return false;
            }
        }
        //set the frames
        vTemp->setUVFrames(frames);
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
        if(vertexs[i])
            vertexs[i]->draw();
    }
}
void edk::shape::Polygon2D::drawVertexsWithColor(edk::color4f32 color){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs[i])
            vertexs[i]->drawWithColor(color);
    }
}
//update framesSize
void edk::shape::Polygon2D::updateFramesSize(){
    //
    this->framesSize = this->frames.x * this->frames.y;
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
        this->transforming=true;
    }
    this->transforming=false;
}

//PUBLIC
//load the vertex
edk::shape::Vertex2D* edk::shape::Polygon2D::getVertexPointer(edk::uint32 vertex){
    //test if have the vertex
    if(vertex<this->getVertexCount()){
        //then return the vertex
        return this->vertexs[vertex];
    }
    //else return NULL
    return NULL;
}

//create the polygon
bool edk::shape::Polygon2D::createPolygon(edk::uint32 vertexCount){
    //delete the polygon
    this->deletePolygon();
    //test the vertexCount
    if(vertexCount >= minimumVertex){
        //create the array
        if(this->vertexs.createArray(vertexCount)){
            //create all the vertexs
            for(edk::uint32 i =0u;i<vertexCount;i++){
                //
                this->vertexs.set(i,new edk::shape::Vertex2D());
                //Set alpha 1
                if(this->vertexs[i]){
                    //set the vertex
                    this->vertexs[i]->color = this->polygonColor;
                }
            }
            //set can delete the polygon in the future
            this->canDeletePolygon=true;
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
        edk::float32 angle1 = edk::Math::getAngle2f(this->vertexs[1u]->position - this->vertexs[0u]->position);
        edk::float32 angle2;
        edk::float32 angleTemp;
        for(register edk::uint32 i=2u;i<this->vertexs.size();i++){
            //get the next angle
            angle2 = edk::Math::getAngle2f(this->vertexs[i]->position - this->vertexs[0u]->position);
            angleTemp = angle2 - angle1;
            if(angleTemp>180.f || (angleTemp<0.f && angleTemp>-180.f)){
                //it's not counterClockwise
                return false;
            }
            angle1=angle2;
        }
        return true;
    }
    return false;
}

//SETTERS
//set the position of a vertex
bool edk::shape::Polygon2D::setVertexPosition(edk::uint32 vertex,edk::vec2f32 position){
    //load the polygon
    edk::shape::Vertex2D* vTemp = this->getVertexPointer(vertex);
    if(vTemp){
        //then set the position of the vertex
        vTemp->position = edk::vec2f32(position);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //
    return this->setVertexPosition(vertex,edk::vec2f32(x,y));
}
//set the color of a vertex
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::color4f32 color){
    //load the polygon
    edk::shape::Vertex2D* vTemp = this->getVertexPointer(vertex);
    if(vTemp){
        //then set the position of the vertex
        vTemp->color = edk::color4f32(color);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return this->setVertexColor(vertex,edk::color4f32(r,g,b,1.0f));
}
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setVertexColor(vertex,edk::color4f32(r,g,b,a));
}
//Set polygon color
bool edk::shape::Polygon2D::setPolygonColor(edk::color4f32 color){
    //first set the polygonColor
    this->polygonColor = edk::color4f32(color);
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs[i]->color = this->polygonColor;
        }
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonColor(edk::color3f32 color){
    return this->setPolygonColor(edk::color4f32 (color.r,color.g,color.b,1.f));
}
bool edk::shape::Polygon2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,1.f));
}
bool edk::shape::Polygon2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,a));
}
//set the UVMap of the vertex
bool edk::shape::Polygon2D::setVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
    this->frameUsing=edk::vec2ui32(0u,0u);
    //load the polygon
    edk::shape::Vertex2DWithUV* vTemp = (edk::shape::Vertex2DWithUV*)this->getVertexPointer(vertex);
    if(vTemp){
        //test what type of vertex it is
        if(vTemp->getType() == EDK_SHAPE_NOUV){
            //then delete the vTemp and create another with UV
            edk::shape::Vertex2DWithUV* uvTemp = new edk::shape::Vertex2DWithUV();
            if(uvTemp){
                //copy the vTemp content to uvTemp
                uvTemp->position = vTemp->position;
                uvTemp->color = vTemp->color;

                //delete the vTemp
                delete vTemp;
                //set vTemp the uvTemp
                vTemp=uvTemp;
                //set the vertex on the array
                this->vertexs.set(vertex,(edk::shape::Vertex2D*)vTemp);
                //clean uvTemp
                uvTemp=NULL;
            }
            else{
                //else return false
                return false;
            }
        }
        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV){
            edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;
            vTemp2->setUV(uv);
            return true;
        }
        //set the uv
        vTemp->setUV(uv);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setVertexUV(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //
    return this->setVertexUV(vertex,edk::vec2f32(x,y));
}
//Set the polygonFrames
bool edk::shape::Polygon2D::setPolygonUVFrames(edk::vec2ui32 frames){
    this->frameUsing=edk::vec2ui32(0u,0u);
    //test the frames
    if(frames.x && frames.y){
        //save the frames
        this->frames=frames;
        //set the frames on vertex
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //
            this->setVertexUVFrames(i,frames);
        }
        this->updateFramesSize();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonUVFrames(edk::uint32 x,edk::uint32 y){
    //
    return this->setPolygonUVFrames(edk::vec2ui32(x,y));
}
bool edk::shape::Polygon2D::setPolygonUVFramesX(edk::uint32 x){
    //
    if(x){
        this->frames.x=x;
    }
    return this->setPolygonUVFrames(edk::vec2ui32(x,
                                                  this->frames.y
                                                  )
                                    );
}
bool edk::shape::Polygon2D::setPolygonUVFramesY(edk::uint32 y){
    //
    if(y) this->frames.y=y;
    return this->setPolygonUVFrames(edk::vec2ui32(this->frames.x,
                                                  y
                                                  )
                                    );
}
//Set the polygon frame
void edk::shape::Polygon2D::usePolygonUVFrame(edk::vec2ui32 frame){
    this->frameUsing=edk::vec2ui32(0u,0u);
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];
        if(temp){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                //then set the frame
                temp->useUVFrame(frame);
                this->frameUsing=frame;
            }
        }
    }
}
void edk::shape::Polygon2D::usePolygonUVFramePosition(edk::uint32 position){
    //test if the framesX is not zero
    if(this->frames.x && this->frames.y){
        //make the UV positions
        edk::vec2ui32 UVPosition(position%this->frames.x,position/this->frames.x);
        //set the frame in AllVertexs
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //load the vertex
            edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];
            if(temp){
                //test if temp have frames
                if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                    //then set the position
                    temp->useUVFrame(UVPosition);
                    this->frameUsing=UVPosition;
                }
            }
        }
    }
}
void edk::shape::Polygon2D::usePolygonUVFrameX(edk::uint32 x){
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];
        if(temp){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                //then set the frame
                temp->useUVFrameX(x);
                this->frameUsing.x = x;
            }
        }
    }
}
void edk::shape::Polygon2D::usePolygonUVFrameY(edk::uint32 y){
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];
        if(temp){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                //then set the frame
                temp->useUVFrameY(y);
                this->frameUsing.x = y;
            }
        }
    }
}

//clean the transformation
void edk::shape::Polygon2D::cleanTransform(){
    this->translate = edk::vec2f32(0,0);
    this->scale=edk::size2f32(1,1);
    this->angle = 0u;
    this->testTransform();
}
//Set the position of the polygon
void edk::shape::Polygon2D::setTranslate(edk::vec2f32 translate){
    this->translate = translate;
    this->testTransform();
}
void edk::shape::Polygon2D::setTranslate(edk::float32 translate){
    this->translate = translate;
    this->testTransform();
}
void edk::shape::Polygon2D::setTranslate(edk::float32 x,edk::float32 y){
    this->setTranslate(edk::vec2f32 (x,y));
}
//set the scale
void edk::shape::Polygon2D::setScale(edk::size2f32 scale){
    this->scale=scale;
    this->testTransform();
}
void edk::shape::Polygon2D::setScale(edk::float32 scale){
    this->scale=scale;
    this->testTransform();
}
void edk::shape::Polygon2D::setScale(edk::float32 width,edk::float32 height){
    this->setScale(edk::size2f32 (width,height));
}
//set the angle
void edk::shape::Polygon2D::setAngle(edk::float32 angle){
    this->angle=angle;
    this->testTransform();
}
//set physics
void edk::shape::Polygon2D::setDensity(edk::float32 density){
    this->density=density;
}
void edk::shape::Polygon2D::setFriction(edk::float32 friction){
    this->friction=friction;
}
void edk::shape::Polygon2D::setRestitution(edk::float32 restitution){
    this->restitution=restitution;
}

//delete the polygonVertex
void edk::shape::Polygon2D::deletePolygon(){
    if(this->canDeletePolygon){
        //remove the animation
        this->framesRemoveAnimation();
        edk::uint32 size = this->getVertexCount();
        for(edk::uint32 i=0u;i<size;i++){
            //
            if(this->vertexs[i]) delete this->vertexs[i];
        }
        this->vertexs.deleteArray();
        this->canDeletePolygon=false;
    }
}
//remove the UV of one vertex
bool edk::shape::Polygon2D::removeVertexUV(edk::uint32 vertex){
    this->frameUsing=edk::vec2ui32(0u,0u);
    //find the vertex
    edk::shape::Vertex2DWithUV* uvTemp = (edk::shape::Vertex2DWithUV*)this->getVertexPointer(vertex);
    if(uvTemp){
        //test the ID of the vertex
        if(uvTemp->getType() == EDK_SHAPE_UV
                ||
                uvTemp->getType() == EDK_SHAPE_ANIMATED_UV
                ){
            //then create another vertex
            edk::shape::Vertex2D* vTemp = new edk::shape::Vertex2D();
            if(vTemp){
                //copy the uvTemp to vTemp
                vTemp->position = uvTemp->position;
                vTemp->color = uvTemp->color;

                //set the new vertex to the position
                this->vertexs.set(vertex,vTemp);
                //delete the uvTemp
                delete uvTemp;
                //clean uvTemp
                uvTemp=NULL;
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
        this->edk::shape::Polygon2D::removeVertexUV(i);
    }
}
//clean the UV animation in polygons
void edk::shape::Polygon2D::cleanPolygonUVAnimation(){
    //
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[i];
        if(temp){
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV){
                //
                temp->cleanUVAnimation();
            }
        }
    }
}
//ANIMATION
//create a new animationFrames
bool edk::shape::Polygon2D::framesCreateAnimation(){
    //remove the last animationFrames
    this->framesRemoveAnimation();
    //create a new animationFrames and set it
    edk::animation::Interpolation1DGroup* temp=NULL;
    if(this->framesSetAnimation( (temp = new edk::animation::Interpolation1DGroup) )){
        //return true
        return this->createAnimationFrames=true;
    }
    //else delete temp if exist
    if(temp){
        //
        delete temp;
    }
    //else return false
    return this->createAnimationFrames=false;
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
        this->framesRemoveAnimation();

        //set the anim
        anim->retainObject((edk::animation::InterpolationGroup**)&this->animationFrame);
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
    return this->animationFrame;
}
//remove the animationGroup
void edk::shape::Polygon2D::framesRemoveAnimation(){
    this->createAnimationFrames=false;
    //test if have an animation
    if(this->framesHaveAnimation()){
        //remove the animation
        this->animationFrame->releaseObject((edk::animation::InterpolationGroup**)&this->animationFrame);
    }
    this->animationFrame=NULL;
}
//return true if have an animation
bool edk::shape::Polygon2D::framesHaveAnimation(){
    //
    return (this->animationFrame!=NULL);
}
//return true if this polygon create the animation
bool edk::shape::Polygon2D::framesIsAnimationCreator(){
    //
    return this->createAnimationFrames;
}


//return the vertexCount
edk::uint32 edk::shape::Polygon2D::getVertexCount(){
    //
    return this->vertexs.size();
}
//return if the vertex have UV
edk::uint8 edk::shape::Polygon2D::getVertexType(edk::uint32 pos){
    //test if have the polygon
    if(pos<this->getVertexCount()){
        if(this->vertexs[pos]){
            return this->vertexs[pos]->getType();
        }
    }
    //else retun false
    return 0u;
}
//return the vertex
edk::vec2f32 edk::shape::Polygon2D::getVertexPosition(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs[pos]){
            //return the vertex
            return edk::vec2f32(this->vertexs[pos]->position.x,this->vertexs[pos]->position.y);
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);
}
//return the vertex color
edk::color4f32 edk::shape::Polygon2D::getVertexColor(edk::uint32 pos){

    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs[pos]){
            //return the vertex
            return edk::color4f32(this->vertexs[pos]->color.r,this->vertexs[pos]->color.g,this->vertexs[pos]->color.b,
                                  this->vertexs[pos]->color.a);
        }
    }
    //else return a zero vertex
    return edk::color4f32(0,0,0,0);
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon2D::getVertexUV(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        //get a temp
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs[pos];
        if(temp){
            //test if the vertex have the UV
            switch(temp->getType()){
            //
            case EDK_SHAPE_UV:
                //
                return edk::vec2f32(temp->getUV().x,temp->getUV().y);
                break;
            case EDK_SHAPE_ANIMATED_UV:
                //
                return edk::vec2f32(temp->getSaved().x,temp->getSaved().y);
                break;
            }
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);
}
//return the frames
edk::vec2ui32 edk::shape::Polygon2D::getFrames(){
    //
    return this->frames;
}
//return the frameUseds
edk::vec2ui32 edk::shape::Polygon2D::getFrameUsed(){
    return this->frameUsing;
}
edk::uint32 edk::shape::Polygon2D::getFramePositionUsed(){
    if(this->frames.x && this->frames.y){
        edk::uint32 yTemp = this->frameUsing.y;
        if(yTemp){
            yTemp--;
            return (this->frameUsing.y * yTemp) + this->frameUsing.x;
        }
        else{
            return this->frameUsing.x;
        }
    }
    return 0u;
}
//return the transform
edk::vec2f32 edk::shape::Polygon2D::getTranslate(){
    return this->translate;
}
edk::size2f32 edk::shape::Polygon2D::getScale(){
    return this->scale;
}
edk::float32 edk::shape::Polygon2D::getAngle(){
    return this->angle;
}
//return true if is transforming
bool edk::shape::Polygon2D::isTransforming(){
    return this->transforming;
}
//get Physics
edk::float32 edk::shape::Polygon2D::getDensity(){
    return this->density;
}
edk::float32 edk::shape::Polygon2D::getFriction(){
    return this->friction;
}
edk::float32 edk::shape::Polygon2D::getRestitution(){
    return this->restitution;
}

//return true if the polygon is a circle
bool edk::shape::Polygon2D::isCircle(){
    return this->polygonCircle;
}
//return the circleRadius only if is a circle
edk::float32 edk::shape::Polygon2D::getCircleRadius(){
    return this->radius;
}
//return true if it's a Rectangle
bool edk::shape::Polygon2D::isRect(){
    return false;
}
//return true if it's lines
bool edk::shape::Polygon2D::isLine(){
    return this->polygonLine;
}
//get line ID
edk::uint8 edk::shape::Polygon2D::getCollisionID(){
    return this->collisionID;
}

//Set to cant delete the polygon
void edk::shape::Polygon2D::cantDeletePolygon(){
    //
    this->canDeletePolygon=false;
}

//print the polygon
void edk::shape::Polygon2D::print(){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs[i]) vertexs[i]->print(i);
    }
}
//Draw the polygon
void edk::shape::Polygon2D::draw(){
    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->translate);
    edk::GU::guRotateZf32(this->angle);
    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_POLYGON);
    this->drawVertexs();
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
//Draw the polygon with lines
void edk::shape::Polygon2D::drawWire(){
    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->translate);
    edk::GU::guRotateZf32(this->angle);
    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_LINE_LOOP);
    this->drawVertexs();
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
//draw vertexs
void edk::shape::Polygon2D::drawPolygonVertexs(edk::color4f32 color){
    edk::GU::guBegin(GL_POINTS);
    //edk::GU::guBegin(GU_LINE_LOOP);
    this->drawVertexsWithColor(color);
    edk::GU::guEnd();
}

//Write to XML
bool edk::shape::Polygon2D::writeToXML(edk::XML* xml,edk::uint32 polygonID){
    if(xml){
        bool ret=false;
        //create the ID string
        edk::char8* id = edk::String::int32ToStr(polygonID);
        if(id){
            edk::char8* name = edk::String::strCat((edk::char8*)"polygon_",id);
            if(name){
                //create the polygon
                if(xml->addSelectedNextChild(name)){
                    //select the name
                    if(xml->selectChild(name)){
                        ret=true;
                        edk::char8* temp = NULL;
                        //test if it's circle
                        if(this->polygonCircle){
                            //set the string
                            xml->setSelectedString("circle");
                            temp = edk::String::float32ToStr(this->getCircleRadius());
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"radius",temp);
                                delete[] temp;
                            }
                        }
                        else if(this->polygonLine){
                            //set the string
                            xml->setSelectedString("line");
                            temp = edk::String::int32ToStr(this->getCollisionID());
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"collisionID",temp);
                                delete[] temp;
                            }
                        }
                        else{
                            //set the string
                            xml->setSelectedString("polygon");
                        }

                        edk::uint32 size = this->getVertexCount();
                        //save the vertexs
                        temp=edk::String::int32ToStr(size);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"vCount",temp);
                            delete[] temp;
                        }
                        //Write Vertexs
                        for(edk::uint32 i=0u;i<size;i++){
                            edk::shape::Vertex2DAnimatedUV* polyTemp = (edk::shape::Vertex2DAnimatedUV*)vertexs[i];
                            if(polyTemp){
                                polyTemp->writeToXML(i,xml);
                            }
                        }
                        if(xml->addSelectedNextChild("uvFrames")){
                            if(xml->selectChild("uvFrames")){
                                //write UVFrames
                                temp = edk::String::float32ToStr(this->getFrames().x);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"framesX",temp);
                                    delete[] temp;
                                }
                                temp = edk::String::float32ToStr(this->getFrames().y);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"framesY",temp);
                                    delete[] temp;
                                }
                                //write selected
                                temp = edk::String::float32ToStr(this->frameUsing.x);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"frameUsingX",temp);
                                    delete[] temp;
                                }
                                temp = edk::String::float32ToStr(this->frameUsing.y);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"frameUsingY",temp);
                                    delete[] temp;
                                }
                                xml->selectFather();
                            }
                        }
                        //write transformations
                        if(xml->addSelectedNextChild("transformation")){
                            if(xml->selectChild("transformation")){
                                temp = edk::String::float32ToStr(this->getTranslate().x);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"translateX",temp);
                                    delete[] temp;
                                }
                                temp = edk::String::float32ToStr(this->getTranslate().y);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"translateY",temp);
                                    delete[] temp;
                                }
                                temp = edk::String::float32ToStr(this->getScale().width);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"scaleW",temp);
                                    delete[] temp;
                                }
                                temp = edk::String::float32ToStr(this->getScale().height);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"scaleH",temp);
                                    delete[] temp;
                                }
                                temp = edk::String::float32ToStr(this->getAngle());
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"angle",temp);
                                    delete[] temp;
                                }
                                xml->selectFather();
                            }
                        }
                        //write physics
                        if(xml->addSelectedNextChild("physics")){
                            if(xml->selectChild("physics")){
                                temp = edk::String::float32ToStr(this->getDensity());
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"density",temp);
                                    delete[] temp;
                                }
                                temp = edk::String::float32ToStr(this->getFriction());
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"friction",temp);
                                    delete[] temp;
                                }
                                temp = edk::String::float32ToStr(this->getRestitution());
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"restitution",temp);
                                    delete[] temp;
                                }
                                xml->selectFather();
                            }
                        }
                        //UV animations
                        if(this->animationFrame){
                            this->animationFrame->writeToXML(xml,0u);
                        }
                        xml->selectFather();
                    }
                }
                delete[] name;
            }
            delete[] id;
        }
        return ret;
    }
    return false;
}
//read from XML
bool edk::shape::Polygon2D::readFromXML(edk::XML* xml,edk::uint32 polygonID){
    if(xml){
        bool ret=false;
        //create the ID string
        edk::char8* id = edk::String::int32ToStr(polygonID);
        if(id){
            edk::char8* name = edk::String::strCat((edk::char8*)"polygon_",id);
            if(name){
                //create the polygon
                //select the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;
                    //load the polygonType
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                    if(temp){
                        //teste the type
                        if(edk::String::strCompare(temp,"circle")){
                            this->polygonCircle = true;
                            this->polygonLine = false;
                            this->radius = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("radius"));
                        }
                        else if(edk::String::strCompare(temp,"line")){
                            this->polygonLine = true;
                            this->polygonCircle = false;
                            this->collisionID = edk::String::strToInt32(xml->getSelectedAttributeValueByName("collisionID"));
                        }
                        else if(edk::String::strCompare(temp,"polygon")){
                            //
                        }
                        delete[] temp;
                    }

                    //read the vertex count
                    edk::uint32 size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("vCount"));
                    if(size){
                        this->createPolygon(size);
                        //read the vertexs
                        for(edk::uint32 i=0u;i<size;i++){
                            //read the vertex type
                            edk::uint8 type = edk::shape::Vertex2D::readTypeFromXML(i,xml);
                            switch(type){
                            case EDK_SHAPE_ANIMATED_UV:
                            case EDK_SHAPE_UV:
                            {
                                edk::shape::Vertex2DAnimatedUV temp;
                                if(temp.readFromXML(i,xml)){
                                    //set the data
                                    this->setVertexPosition(i,temp.position);
                                    this->setVertexColor(i,temp.color);
                                    this->setVertexUV(i,temp.getSaved());
                                }
                                break;
                            }
                            case EDK_SHAPE_NOUV:
                            {
                                edk::shape::Vertex2D temp;
                                if(temp.readFromXML(i,xml)){
                                    //set the data
                                    this->setVertexPosition(i,temp.position);
                                    this->setVertexColor(i,temp.color);
                                }
                                break;
                            }
                            }
                        }



                        //read uvFrames
                        if(xml->selectChild("uvFrames")){
                            //write UVFrames
                            edk::uint32 uvFrameX = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("framesX"));
                            edk::uint32 uvFrameY = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("framesY"));
                            //set uvFrames
                            this->setPolygonUVFrames(edk::vec2ui32(uvFrameX,uvFrameY));

                            //set using the frame ID
                            this->frameUsing.x = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("frameUsingX"));
                            this->frameUsing.y = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("frameUsingY"));

                            //set the frameUsing
                            this->usePolygonUVFrame(this->frameUsing);

                            xml->selectFather();
                        }

                        //read transformation
                        if(xml->selectChild("transformation")){
                            this->translate.x = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("translateX"));
                            this->translate.y = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("translateY"));
                            this->scale.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleW"));
                            this->scale.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleH"));
                            this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));
                            this->testTransform();
                            xml->selectFather();
                        }

                        //read physics
                        if(xml->selectChild("physics")){
                            this->density = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("density"));
                            this->friction = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("friction"));
                            this->restitution = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("restitution"));
                            xml->selectFather();
                        }

                        this->framesCreateAnimation();
                        //UV animations
                        if(this->animationFrame){
                            if(this->animationFrame->readFromXML(xml,0u)){
                                //set play
                                this->animationFrame->playForward();
                            }
                            else{
                                //delete the frame
                                this->framesRemoveAnimation();
                            }
                        }
                        ret=true;
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

bool edk::shape::Polygon2D::cloneFrom(edk::shape::Polygon2D* poly){
    //first delete the vertexs
    this->deletePolygon();
    if(poly){
        //then create a new polygon
        if(this->createPolygon(poly->getVertexCount())){
            //then copy the vertex
            for(edk::uint32 i=0u;i<this->getVertexCount();i++){
                //copy the vertex
                edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)vertexs[i];
                if(temp){
                    //this->setVertexPosition(i,poly->getVertexPosition(i));
                    temp->position = poly->getVertexPosition(i);
                    //this->setVertexColor(i,poly->getVertexColor(i));
                    temp->color = poly->getVertexColor(i);
                    //copy the frames
                    //this->setVertexUVFrames(i,poly->getFrames());
                    //get vertexType
                    switch(poly->getVertexType(i)){
                        //
                        case EDK_SHAPE_ANIMATED_UV:
                            //
                            this->setVertexUV(i,poly->getVertexUV(i));
                            this->setVertexUVFrames(i,poly->getFrames());
                            break;
                        case EDK_SHAPE_UV:
                            //
                            this->setVertexUV(i,poly->getVertexUV(i));
                            break;
                    };
                }
            }
        }
        //set the polygonFrames
        this->setPolygonUVFrames(poly->getFrames());
        this->usePolygonUVFrame(poly->frameUsing);
        //set the transformations
        this->setTranslate(poly->getTranslate());
        this->setScale(poly->getScale());
        this->setAngle(poly->getAngle());
        //set physics
        this->setDensity(poly->getDensity());
        this->setFriction(poly->getFriction());
        this->setRestitution(poly->getRestitution());
        //
        this->polygonCircle = poly->polygonCircle;
        this->radius=poly->radius;
        this->polygonLine = poly->polygonLine;
        this->collisionID = poly->collisionID;
        //set the animation
        this->framesSetAnimation(poly->framesGetAnimation());
        this->createAnimationFrames = poly->createAnimationFrames;
        return true;
    }
    return false;
}
