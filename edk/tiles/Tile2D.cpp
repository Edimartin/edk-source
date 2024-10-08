#include "Tile2D.h"

/*
Library Tile2D - Draw 2D Tile in EDK Game Engine
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



#define edkTileSizeIncrement (1.01f)

edk::tiles::Tile2D::Tile2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::tiles::Tile2D::~Tile2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        this->obj.removeAllMesh();edkEnd();
        this->deletePhysics();edkEnd();
        this->mesh.cleanTextures();edkEnd();
        this->treeDraw.clean();edkEnd();
    }
}

void edk::tiles::Tile2D::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;

        this->obj.Constructor();edkEnd();
        this->mesh.Constructor();edkEnd();
        this->treeDraw.Constructor();edkEnd();

        //create the polygon
        edk::shape::Quadrangle2D rect;edkEnd();
        this->middle = edk::vec2f32(0,0);edkEnd();
        //Set the color to white
        rect.setPolygonColor(1,1,1,1);edkEnd();
        //Set all the quadrangle vertexs
        //    rect.setVertexPosition(0u,0,0);edkEnd();
        //    rect.setVertexPosition(1u,0,1);edkEnd();
        //    rect.setVertexPosition(2u,1,1);edkEnd();
        //    rect.setVertexPosition(3u,1,0);edkEnd();
        rect.setVertexPosition(0u,-0.5,-0.5);edkEnd();
        rect.setVertexPosition(1u,0.5,-0.5);edkEnd();
        rect.setVertexPosition(2u,0.5,0.5);edkEnd();
        rect.setVertexPosition(3u,-0.5,0.5);edkEnd();
        //set the UV'S
        rect.setVertexUV(0u,0,1);edkEnd();
        rect.setVertexUV(1u,1,1);edkEnd();
        rect.setVertexUV(2u,1,0);edkEnd();
        rect.setVertexUV(3u,0,0);edkEnd();
        //Use a rectPolygon to the mesh
        this->mesh.addPolygon(rect);edkEnd();
        this->mesh.selectPolygon(0u);edkEnd();
        //add the mesh
        this->obj.addMesh(&this->mesh);edkEnd();

        this->obj.selectMesh(0u);edkEnd();

        this->objPhys=NULL;edkEnd();
        this->addedPhysicsPolygon=false;edkEnd();
    }
}

//return the type of the tile to the tileSet know witch tile is before delete it
edk::tiles::tile2DType edk::tiles::Tile2D::getType(){
    return edk::tiles::tile2DTypeNormal;edkEnd();
}

//select or create the animation for the polygon zero
void edk::tiles::Tile2D::selectAnimation(){
    if(!this->mesh.selectAnimationFramesFromPolygon(0u)){
        //create a new animation
        this->mesh.setAnimationFramesToPolygon(0u);edkEnd();
        this->mesh.selectAnimationFramesFromPolygon(0u);edkEnd();
    }
}

//set the Tile Position
void edk::tiles::Tile2D::setPosition(edk::vec2f32 position){
    //
    this->obj.position = position;edkEnd();
}
void edk::tiles::Tile2D::setPosition(edk::float32 posX,edk::float32 posY){
    //
    return this->setPosition(edk::vec2f32(posX,posY));edkEnd();
}
//set the color of the tile
void edk::tiles::Tile2D::setColor(edk::color4f32 color){
    this->mesh.selectedSetPolygonColor(color);edkEnd();
}
void edk::tiles::Tile2D::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setColor(edk::color4f32(r,g,b,a));edkEnd();
}
//set the material color
void edk::tiles::Tile2D::setAmbient(edk::color4f32 color){
    this->mesh.material.setAmbient(color);edkEnd();
}
void edk::tiles::Tile2D::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setAmbient(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::tiles::Tile2D::setDiffuse(edk::color4f32 color){
    this->mesh.material.setDiffuse(color);edkEnd();
}
void edk::tiles::Tile2D::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setDiffuse(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::tiles::Tile2D::setSpecular(edk::color4f32 color){
    this->mesh.material.setSpecular(color);edkEnd();
}
void edk::tiles::Tile2D::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setSpecular(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::tiles::Tile2D::setEmission(edk::color4f32 color){
    this->mesh.material.setEmission(color);edkEnd();
}
void edk::tiles::Tile2D::setEmission(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setEmission(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::tiles::Tile2D::setShininess(edk::float32 shininess){
    return this->setShininess(shininess);edkEnd();
}


//set the rectangle of the tile
void edk::tiles::Tile2D::setRect(edk::rectf32 rect){
    this->obj.position = rect.origin;edkEnd();
    this->obj.size = rect.size/*+0.1f*/;edkEnd();
}
void edk::tiles::Tile2D::setRect(edk::vec2f32 position, edk::size2f32 size){
    return this->setRect(edk::rectf32(position.x,position.y,size.width,size.height));edkEnd();
}
void edk::tiles::Tile2D::setRect(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY){
    return this->setRect(edk::vec2f32(posX,posY), edk::size2f32( sizeX,sizeY));edkEnd();
}

//Set the UV map for the tile
void edk::tiles::Tile2D::setRectUV(edk::rectf32 rect){
    //set the UV on the polygon

    //    this->rect.setVertexPosition(0u,0,0);edkEnd();
    this->mesh.selectedSetVertexUV(0u,rect.origin.x,rect.origin.y);edkEnd();
    //    this->rect.setVertexPosition(1u,0,1);edkEnd();
    this->mesh.selectedSetVertexUV(1u,rect.origin.x,rect.size.height);edkEnd();
    //    this->rect.setVertexPosition(2u,1,1);edkEnd();
    this->mesh.selectedSetVertexUV(2u,rect.size.width,rect.size.height);edkEnd();
    //    this->rect.setVertexPosition(3u,1,0);edkEnd();
    this->mesh.selectedSetVertexUV(3u,rect.size.width,rect.origin.y);edkEnd();
}
void edk::tiles::Tile2D::setRectUV(edk::vec2f32 position, edk::size2f32 size){
    return this->setRectUV(edk::rectf32(position.x,position.y,size.width,size.height));edkEnd();
}
void edk::tiles::Tile2D::setRectUV(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY){
    return this->setRectUV(edk::vec2f32( posX,posY ), edk::size2f32(sizeX,sizeY));edkEnd();
}

//set the rectangle of the tile
void edk::tiles::Tile2D::setFrame(edk::rectf32 frame){
    this->obj.size = frame.size/*+0.1f*/;edkEnd();
    this->obj.position.x = frame.origin.x - (frame.size.width*0.5);edkEnd();
    this->obj.position.y = frame.origin.y - (frame.size.height*0.5);edkEnd();
}
void edk::tiles::Tile2D::setFrame(edk::vec2f32 position, edk::size2f32 size){
    return this->setFrame(edk::rectf32(position.x,position.y,size.width,size.height));edkEnd();
}
void edk::tiles::Tile2D::setFrame(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY){
    return this->setFrame(edk::vec2f32(posX,posY), edk::size2f32( sizeX,sizeY));edkEnd();
}

//Set the frame UV cut
void edk::tiles::Tile2D::setFramesUV(edk::vec2ui32 frames){
    this->mesh.selectedSetPolygonUVFrames(frames);edkEnd();
}
void edk::tiles::Tile2D::setFramesUV(edk::uint32 x,edk::uint32 y){
    this->mesh.selectedSetPolygonUVFrames(x,y);edkEnd();
}
//select frameUV
void edk::tiles::Tile2D::useFrameUV(edk::vec2ui32 frame){
    this->mesh.selectedUsePolygonUVFrame(frame);edkEnd();
}
void edk::tiles::Tile2D::useFrameUV(edk::uint32 x,edk::uint32 y){
    this->useFrameUV(edk::vec2ui32(x,y));edkEnd();
}
void edk::tiles::Tile2D::useFrameUVinPosition(edk::uint32 position){
    this->mesh.selectedUsePolygonUVFramePosition(position);edkEnd();
}

//Set the tileImage
bool edk::tiles::Tile2D::loadImage(const edk::char8* name,edk::uint32 filter){
    //
    return this->loadImage((edk::char8*) name,filter);edkEnd();
}
bool edk::tiles::Tile2D::loadImage(edk::char8* name,edk::uint32 filter){
    //test the name
    if(name){
        return this->mesh.material.loadTexture(name,0u,filter);edkEnd();
    }
    //else return false
    return false;
}
//set the tileImage from memory
bool edk::tiles::Tile2D::loadImageFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    return this->loadImageFromMemory(name,image,size,filter);edkEnd();
}
bool edk::tiles::Tile2D::loadImageFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    //test the name
    if(name){
        return this->mesh.material.loadTextureFromMemory(name,image,size,0u,filter);edkEnd();
    }
    //else return false
    return false;
}
//set the tileImage from the pack
bool edk::tiles::Tile2D::loadImageFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadImageFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::tiles::Tile2D::loadImageFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    //test the name
    if(name && pack){
        return this->mesh.material.loadTextureFromPack(pack,name,0u,filter);edkEnd();
    }
    //else return false
    return false;
}

//Get the size of the Tile
edk::size2f32 edk::tiles::Tile2D::getSize(){
    return this->obj.size/*-0.1f*/;edkEnd();
}
edk::float32 edk::tiles::Tile2D::getWidth(){
    return this->obj.size.width/*-0.1f*/;edkEnd();
}
edk::float32 edk::tiles::Tile2D::getHeight(){
    return this->obj.size.height/*-0.1f*/;edkEnd();
}
edk::vec2f32 edk::tiles::Tile2D::getPosition(){
    return this->obj.position;edkEnd();
}
edk::float32 edk::tiles::Tile2D::getPositionX(){
    return this->obj.position.x;edkEnd();
}
edk::float32 edk::tiles::Tile2D::getPositionY(){
    return this->obj.position.y;edkEnd();
}

//callback to start and end draw tile
bool edk::tiles::Tile2D::addDrawCallback(edk::tiles::DrawTile2DCallback* callback){
    if(callback){
        return this->treeDraw.add(callback);edkEnd();
    }
    return false;
}
bool edk::tiles::Tile2D::removeDrawCallback(edk::tiles::DrawTile2DCallback* callback){
    return this->treeDraw.remove(callback);edkEnd();
}
void edk::tiles::Tile2D::runStartDraw(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition){
    this->treeDraw.runStart(id,position,worldPosition);edkEnd();
}
void edk::tiles::Tile2D::runEndDraw(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition){
    this->treeDraw.runEnd(id,position,worldPosition);edkEnd();
}

//Add a interpolation to the animation
bool edk::tiles::Tile2D::addFrameInterpolation(edk::float32 second,edk::float32 frame){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationAddInterpolationLine(second,frame);edkEnd();
}
//return the interpolation size
edk::uint32 edk::tiles::Tile2D::getInterpolationSize(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationGetInterpolationSize();edkEnd();
}
//clean frames
bool edk::tiles::Tile2D::cleanFames(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationCleanFrames();edkEnd();
}
//controls
bool edk::tiles::Tile2D::playForward(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPlayForward();edkEnd();
}
bool edk::tiles::Tile2D::playForwardIn(edk::float32 second){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPlayForwardIn(second);edkEnd();
}
bool edk::tiles::Tile2D::playRewind(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPlayRewind();edkEnd();
}
bool edk::tiles::Tile2D::playRewindIn(edk::float32 second){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPlayRewindIn(second);edkEnd();
}
bool edk::tiles::Tile2D::pause(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPause();edkEnd();
}
bool edk::tiles::Tile2D::pauseOn(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPause();edkEnd();
}
bool edk::tiles::Tile2D::pauseOff(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPause();edkEnd();
}
bool edk::tiles::Tile2D::stop(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationStop();edkEnd();
}
//set loop
bool edk::tiles::Tile2D::setLoop(bool loop){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationSetLoop(loop);edkEnd();
}
bool edk::tiles::Tile2D::loopOn(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationLoopOn();edkEnd();
}
bool edk::tiles::Tile2D::loopOff(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationLoopOff();edkEnd();
}
//get the second
edk::float32 edk::tiles::Tile2D::getSecond(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationGetSecond();edkEnd();
}
//return if are playing
bool edk::tiles::Tile2D::isPlaying(){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationIsPlaying();edkEnd();
}
bool edk::tiles::Tile2D::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);edkEnd();
}
bool edk::tiles::Tile2D::isPlayingName(edk::char8* name){
    if(name){
        this->selectAnimation();edkEnd();
        return this->mesh.selectedAnimationIsPlayingName(name);edkEnd();
    }
    return false;
}
bool edk::tiles::Tile2D::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);edkEnd();
}
bool edk::tiles::Tile2D::wasPlayingName(edk::char8* name){
    if(name){
        this->selectAnimation();edkEnd();
        return this->mesh.selectedAnimationWasPlayingName(name);edkEnd();
    }
    return false;
}
//animationNames
bool edk::tiles::Tile2D::addAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
    return this->addAnimationName((edk::char8*) name,start,end);edkEnd();
}
bool edk::tiles::Tile2D::addAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationAddAnimationName(name,start,end);edkEnd();
}
//test if have the animationName
bool edk::tiles::Tile2D::haveAnimationName(const edk::char8* name){
    return this->haveAnimationName((edk::char8*) name);edkEnd();
}
bool edk::tiles::Tile2D::haveAnimationName(edk::char8* name){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationHaveAnimationName(name);edkEnd();
}
//Play the animationName
bool edk::tiles::Tile2D::playNameForward(const edk::char8* name){
    return this->playNameForward((edk::char8*) name);edkEnd();
}
bool edk::tiles::Tile2D::playNameForward(edk::char8* name){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPlayNameForward(name);edkEnd();
}
bool edk::tiles::Tile2D::playNameRewind(const edk::char8* name){
    return this->playNameRewind((edk::char8*) name);edkEnd();
}
bool edk::tiles::Tile2D::playNameRewind(edk::char8* name){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationPlayNameRewind(name);edkEnd();
}
//remove the animationName
bool edk::tiles::Tile2D::removeAnimationName(const edk::char8* name){
    return this->removeAnimationName((edk::char8*) name);edkEnd();
}
bool edk::tiles::Tile2D::removeAnimationName(edk::char8* name){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationRemoveAnimationName(name);edkEnd();
}

//Set one interpolation X as a curve
bool edk::tiles::Tile2D::setCurveX(edk::uint32 position){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationSetCurveX(position);edkEnd();
}
bool edk::tiles::Tile2D::setNotCurveX(edk::uint32 position){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationSetNotCurveX(position);edkEnd();
}
bool edk::tiles::Tile2D::getIsCurveX(edk::uint32 position){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationGetIsCurveX(position);edkEnd();
}
//Set the interpolation curve points
bool edk::tiles::Tile2D::setCurveP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationSetCurveP1X(position,second,x);edkEnd();
}
bool edk::tiles::Tile2D::setCurveP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    this->selectAnimation();edkEnd();
    return this->mesh.selectedAnimationSetCurveP2X(position,second,x);edkEnd();
}

//get mesh pointer
edk::shape::Mesh2D* edk::tiles::Tile2D::getMeshPointer(){
    return &this->mesh;edkEnd();
}

//create a new object physics
bool edk::tiles::Tile2D::setPhysics(edk::TypeObject type){
    this->deletePhysics();edkEnd();
    /*
    edk::shape::Rectangle2D rect;edkEnd();
    rect.setPivoToCenter();edkEnd();
    rect.setScale(1.0f,1.0f);edkEnd();
    rect.setRestitution(0.1f);edkEnd();
    rect.setFriction(0.5);edkEnd();
    */
    switch(type){
    case edk::TypeObject2DStatic:
        this->objPhys = new edk::physics2D::StaticObject2D;edkEnd();
        break;
    case edk::TypeObject2DKinematic:
        this->objPhys = new edk::physics2D::KinematicObject2D;edkEnd();
        break;
    case edk::TypeObject2DDynamic:
        this->objPhys = new edk::physics2D::DynamicObject2D;edkEnd();
        break;
    default:
        break;
    }
    return this->cleanPhysicsPolygons();edkEnd();
}
//add a polygon to the physics Object
bool edk::tiles::Tile2D::addPhysicsPolygon(edk::shape::Polygon2D poly){
    //test if have the object
    if(this->objPhys){
        //test if dont add a polygon yet
        if(this->addedPhysicsPolygon){
            //then clean the mesh
            this->objPhys->physicMesh.cleanPolygons();edkEnd();
        }
        //add thepolygon
        this->objPhys->physicMesh.addPolygon(poly);edkEnd();
        this->addedPhysicsPolygon=false;edkEnd();
        return true;
    }
    return false;
}
bool edk::tiles::Tile2D::cleanPhysicsPolygons(){
    edk::shape::Rectangle2D rect;edkEnd();
    rect.setPivoToCenter();edkEnd();
    rect.setScale(1.01f,1.01f);edkEnd();
    rect.setRestitution(0.1f);edkEnd();
    rect.setFriction(0.5);edkEnd();
    //test if have the object
    if(this->objPhys){
        this->objPhys->physicMesh.cleanPolygons();edkEnd();
        this->objPhys->physicMesh.addPolygon(rect);edkEnd();
        this->addedPhysicsPolygon=true;edkEnd();
        return true;
    }
    return false;
}

//delete the objectPhysics
void edk::tiles::Tile2D::deletePhysics(){
    if(this->objPhys){
        delete this->objPhys;edkEnd();
    }
    this->addedPhysicsPolygon=false;edkEnd();
    this->objPhys=NULL;edkEnd();
}
//return the physicsObject
edk::physics2D::PhysicObject2D* edk::tiles::Tile2D::getPhysicsObject(){
    return this->objPhys;edkEnd();
}
//return the physicsMesh
edk::physics2D::PhysicsMesh2D* edk::tiles::Tile2D::getPhysicsMeshPointer(){
    if(this->objPhys){
        return &this->objPhys->physicMesh;edkEnd();
    }
    return NULL;
}
//return true if the tile is Physics
bool edk::tiles::Tile2D::isPhysics(){
    if(this->objPhys){
        return true;
    }
    return false;
}

//update the animation
void edk::tiles::Tile2D::updateAnimation(){
    this->mesh.updateFramesAnimations();edkEnd();
}
void edk::tiles::Tile2D::updateAnimation(edk::float32 seconds){
    this->mesh.updateFramesAnimations(seconds);edkEnd();
}

//XML
bool edk::tiles::Tile2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tile_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::char8* temp;edkEnd();
                        //write the object
                        this->obj.writeToXML(xml,0u);edkEnd();

                        //write the physicObject if it have one
                        if(this->objPhys){
                            this->objPhys->writeToXML(xml,0u);edkEnd();
                        }
                        //write tileSize
                        temp = edk::String::float32ToStr(this->tileSize.width/*-0.1f*/);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"tSizeW",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->tileSize.height/*-0.1f*/);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"tSizeH",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        ret=true;edkEnd();
                        xml->selectFather();edkEnd();
                    }
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::tiles::Tile2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tile_",nameID);edkEnd();
            if(name){
                //read the name
                if(xml->selectChild(name)){
                    this->obj.cleanMeshes();edkEnd();
                    this->mesh.cleanPolygons();edkEnd();
                    //read obj
                    if(this->obj.readFromXML(xml,0u)){
                        //copy the first mesh
                        if(this->obj.getMesh(0u)){
                            //this->mesh = *this->obj.getMesh(0u);edkEnd();
                            this->mesh.cloneFrom(this->obj.getMesh(0u));edkEnd();
                        }
                        //delete all mesh's from XML

                        //                        edk::shape::Mesh2D* meshTemp;edkEnd();
                        //                        edk::uint32 size = this->obj.getMeshSize();edkEnd();
                        /*
                        for(edk::uint32 i=0u;i<size;i++){
                            meshTemp = this->obj.getMesh(i);edkEnd();
                            if(meshTemp){
                                delete meshTemp;edkEnd();
                                }
                        }
*/
                        this->obj.removeAllMesh();edkEnd();

                        //set the mesh
                        this->obj.addMesh(&this->mesh);edkEnd();
                    }
                    //read the physicsObject
                    this->objPhys = new edk::physics2D::PhysicObject2D;edkEnd();
                    if(this->objPhys){
                        if(!this->objPhys->readFromXML(xml,0u)){
                            //dont have physicc object
                            delete this->objPhys;edkEnd();
                            this->objPhys=NULL;edkEnd();
                        }
                    }
                    //read the tileSize
                    this->tileSize = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("tSizeW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("tSizeH"))
                                                   )/*+0.1f*/;edkEnd();
                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::tiles::Tile2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tile_",nameID);edkEnd();
            if(name){
                //read the name
                if(xml->selectChild(name)){
                    this->obj.cleanMeshes();edkEnd();
                    this->mesh.cleanPolygons();edkEnd();
                    //read obj
                    if(this->obj.readFromXMLFromPack(pack,xml,0u)){
                        //copy the first mesh
                        if(this->obj.getMesh(0u)){
                            //this->mesh = *this->obj.getMesh(0u);edkEnd();
                            this->mesh.cloneFrom(this->obj.getMesh(0u));edkEnd();
                        }
                        //delete all mesh's from XML

                        //                        edk::shape::Mesh2D* meshTemp;edkEnd();
                        //                        edk::uint32 size = this->obj.getMeshSize();edkEnd();
                        /*
                        for(edk::uint32 i=0u;i<size;i++){
                            meshTemp = this->obj.getMesh(i);edkEnd();
                            if(meshTemp){
                                delete meshTemp;edkEnd();
                                }
                        }
*/
                        this->obj.removeAllMesh();edkEnd();

                        //set the mesh
                        this->obj.addMesh(&this->mesh);edkEnd();
                    }
                    //read the physicsObject
                    this->objPhys = new edk::physics2D::PhysicObject2D;edkEnd();
                    if(this->objPhys){
                        if(!this->objPhys->readFromXMLFromPack(pack,xml,0u)){
                            //dont have physicc object
                            delete this->objPhys;edkEnd();
                            this->objPhys=NULL;edkEnd();
                        }
                    }
                    //read the tileSize
                    this->tileSize = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("tSizeW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("tSizeH"))
                                                   )/*+0.1f*/;edkEnd();
                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}

//Draw the tile
void edk::tiles::Tile2D::draw(edk::float32 angle,edk::size2f32 size){
    this->obj.angle = angle;edkEnd();
    this->tileSize = this->obj.size;edkEnd();
    this->obj.size = size*edkTileSizeIncrement;edkEnd();
    this->obj.draw();edkEnd();
    this->obj.angle = 0.f;edkEnd();
    this->obj.size = this->tileSize;edkEnd();
}
void edk::tiles::Tile2D::drawWithoutMaterial(edk::float32 angle,edk::size2f32 size){
    this->obj.angle = angle;edkEnd();
    this->tileSize = this->obj.size;edkEnd();
    this->obj.size = size*edkTileSizeIncrement;edkEnd();
    this->obj.drawWithoutMaterial();edkEnd();
    this->obj.angle = 0.f;edkEnd();
    this->obj.size = this->tileSize;edkEnd();
}
void edk::tiles::Tile2D::drawWire(edk::float32 angle,edk::size2f32 size){
    this->obj.angle = angle;edkEnd();
    this->tileSize = this->obj.size;edkEnd();
    this->obj.size = size;edkEnd();
    this->obj.drawWire();edkEnd();
    this->obj.angle = 0.f;edkEnd();
    this->obj.size = this->tileSize;edkEnd();
}
void edk::tiles::Tile2D::drawSelection(edk::float32 angle,edk::size2f32 size){
    this->obj.angle = angle;edkEnd();
    this->tileSize = this->obj.size;edkEnd();
    this->obj.size = size;edkEnd();
    this->obj.drawWithoutMaterial();edkEnd();
    this->obj.angle = 0.f;edkEnd();
    this->obj.size = this->tileSize;edkEnd();
}

void edk::tiles::Tile2D::drawPhysic(edk::float32 angle,edk::size2f32 size){
    if(this->objPhys){
        this->objPhys->angle = angle;edkEnd();
        this->tileSize = this->obj.size;edkEnd();
        this->objPhys->size = size*edkTileSizeIncrement;edkEnd();
        this->objPhys->drawWirePhysics();edkEnd();
        this->objPhys->angle = 0.f;edkEnd();
        this->objPhys->size = this->tileSize;edkEnd();
    }
}
