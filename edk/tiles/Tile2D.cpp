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

edk::tiles::Tile2D::Tile2D(){
    //create the polygon
    edk::shape::Quadrangle2D rect;
    this->middle = edk::vec2f32(0,0);
    //Set the color to white
    rect.setPolygonColor(1,1,1,1);
    //Set all the quadrangle vertexs
    //    rect.setVertexPosition(0u,0,0);
    //    rect.setVertexPosition(1u,0,1);
    //    rect.setVertexPosition(2u,1,1);
    //    rect.setVertexPosition(3u,1,0);
    rect.setVertexPosition(0u,-0.5,-0.5);
    rect.setVertexPosition(1u,0.5,-0.5);
    rect.setVertexPosition(2u,0.5,0.5);
    rect.setVertexPosition(3u,-0.5,0.5);
    //set the UV'S
    rect.setVertexUV(0u,0,1);
    rect.setVertexUV(1u,1,1);
    rect.setVertexUV(2u,1,0);
    rect.setVertexUV(3u,0,0);
    //Use a rectPolygon to the mesh
    this->mesh.addPolygon(rect);
    this->mesh.selectPolygon(0u);
    //add the mesh
    this->obj.addMesh(&this->mesh);

    this->obj.selectMesh(0u);

    this->objPhys=NULL;
    this->addedPhysicsPolygon=false;
}
edk::tiles::Tile2D::~Tile2D(){
    //
    this->obj.removeAllMesh();
    this->deletePhysics();
    this->mesh.cleanTextures();
    this->startDraw.clean();
    this->endDraw.clean();
}

//return the type of the tile to the tileSet know witch tile is before delete it
edk::tiles::tile2DType edk::tiles::Tile2D::getType(){
    return edk::tiles::tile2DTypeNormal;
}

//select or create the animation for the polygon zero
void edk::tiles::Tile2D::selectAnimation(){
    if(!this->mesh.selectAnimationFramesFromPolygon(0u)){
        //create a new animation
        this->mesh.setAnimationFramesToPolygon(0u);
        this->mesh.selectAnimationFramesFromPolygon(0u);
    }
}

//set the Tile Position
void edk::tiles::Tile2D::setPosition(edk::vec2f32 position){
    //
    this->obj.position = position;
}
void edk::tiles::Tile2D::setPosition(edk::float32 posX,edk::float32 posY){
    //
    return this->setPosition(edk::vec2f32(posX,posY));
}
//set the color of the tile
void edk::tiles::Tile2D::setColor(edk::color4f32 color){
    this->mesh.selectedSetPolygonColor(color);
}
void edk::tiles::Tile2D::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setColor(edk::color4f32(r,g,b,a));
}
//set the material color
void edk::tiles::Tile2D::setAmbient(edk::color4f32 color){
    this->mesh.material.setAmbient(color);
}
void edk::tiles::Tile2D::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setAmbient(edk::color4f32(r,g,b,a));
}
void edk::tiles::Tile2D::setDiffuse(edk::color4f32 color){
    this->mesh.material.setDiffuse(color);
}
void edk::tiles::Tile2D::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setDiffuse(edk::color4f32(r,g,b,a));
}
void edk::tiles::Tile2D::setSpecular(edk::color4f32 color){
    this->mesh.material.setSpecular(color);
}
void edk::tiles::Tile2D::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setSpecular(edk::color4f32(r,g,b,a));
}
void edk::tiles::Tile2D::setEmission(edk::color4f32 color){
    this->mesh.material.setEmission(color);
}
void edk::tiles::Tile2D::setEmission(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setEmission(edk::color4f32(r,g,b,a));
}
void edk::tiles::Tile2D::setShininess(edk::float32 shininess){
    return this->setShininess(shininess);
}


//set the rectangle of the tile
void edk::tiles::Tile2D::setRect(edk::rectf32 rect){
    this->obj.position = rect.origin;
    this->obj.size = rect.size;
}
void edk::tiles::Tile2D::setRect(edk::vec2f32 position, edk::size2f32 size){
    return this->setRect(edk::rectf32(position.x,position.y,size.width,size.height));
}
void edk::tiles::Tile2D::setRect(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY){
    return this->setRect(edk::vec2f32(posX,posY), edk::size2f32( sizeX,sizeY));
}

//Set the UV map for the tile
void edk::tiles::Tile2D::setRectUV(edk::rectf32 rect){
    //set the UV on the polygon

    //    this->rect.setVertexPosition(0u,0,0);
    this->mesh.selectedSetVertexUV(0u,rect.origin.x,rect.origin.y);
    //    this->rect.setVertexPosition(1u,0,1);
    this->mesh.selectedSetVertexUV(1u,rect.origin.x,rect.size.height);
    //    this->rect.setVertexPosition(2u,1,1);
    this->mesh.selectedSetVertexUV(2u,rect.size.width,rect.size.height);
    //    this->rect.setVertexPosition(3u,1,0);
    this->mesh.selectedSetVertexUV(3u,rect.size.width,rect.origin.y);
}
void edk::tiles::Tile2D::setRectUV(edk::vec2f32 position, edk::size2f32 size){
    return this->setRectUV(edk::rectf32(position.x,position.y,size.width,size.height));
}
void edk::tiles::Tile2D::setRectUV(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY){
    return this->setRectUV(edk::vec2f32( posX,posY ), edk::size2f32(sizeX,sizeY));
}

//set the rectangle of the tile
void edk::tiles::Tile2D::setFrame(edk::rectf32 frame){
    this->obj.size = frame.size;
    this->obj.position.x = frame.origin.x - (frame.size.width*0.5);
    this->obj.position.y = frame.origin.y - (frame.size.height*0.5);
}
void edk::tiles::Tile2D::setFrame(edk::vec2f32 position, edk::size2f32 size){
    return this->setFrame(edk::rectf32(position.x,position.y,size.width,size.height));
}
void edk::tiles::Tile2D::setFrame(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY){
    return this->setFrame(edk::vec2f32(posX,posY), edk::size2f32( sizeX,sizeY));
}

//Set the frame UV cut
void edk::tiles::Tile2D::setFramesUV(edk::vec2ui32 frames){
    this->mesh.selectedSetPolygonUVFrames(frames);
}
void edk::tiles::Tile2D::setFramesUV(edk::uint32 x,edk::uint32 y){
    this->mesh.selectedSetPolygonUVFrames(x,y);
}
//select frameUV
void edk::tiles::Tile2D::useFrameUV(edk::vec2ui32 frame){
    this->mesh.selectedUsePolygonUVFrame(frame);
}
void edk::tiles::Tile2D::useFrameUV(edk::uint32 x,edk::uint32 y){
    this->useFrameUV(edk::vec2ui32(x,y));
}
void edk::tiles::Tile2D::useFrameUVinPosition(edk::uint32 position){
    this->mesh.selectedUsePolygonUVFramePosition(position);
}

//Set the tileImage
bool edk::tiles::Tile2D::loadImage(const edk::char8* name,edk::uint32 filter){
    //
    return this->loadImage((edk::char8*) name,filter);
}
bool edk::tiles::Tile2D::loadImage(edk::char8* name,edk::uint32 filter){
    //test the name
    if(name){
        return this->mesh.material.loadTexture(name,0u,filter);
    }
    //else return false
    return false;
}
//set the tileImage from memory
bool edk::tiles::Tile2D::loadImageFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    return this->loadImageFromMemory(name,image,size,filter);
}
bool edk::tiles::Tile2D::loadImageFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    //test the name
    if(name){
        return this->mesh.material.loadTextureFromMemory(name,image,size,0u,filter);
    }
    //else return false
    return false;
}
//set the tileImage from the pack
bool edk::tiles::Tile2D::loadImageFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadImageFromPack(pack,(edk::char8*) name,filter);
}
bool edk::tiles::Tile2D::loadImageFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    //test the name
    if(name && pack){
        return this->mesh.material.loadTextureFromPack(pack,name,0u,filter);
    }
    //else return false
    return false;
}

//Get the size of the Tile
edk::size2f32 edk::tiles::Tile2D::getSize(){
    return this->obj.size;
}
edk::float32 edk::tiles::Tile2D::getWidth(){
    return this->obj.size.width;
}
edk::float32 edk::tiles::Tile2D::getHeight(){
    return this->obj.size.height;
}
edk::vec2f32 edk::tiles::Tile2D::getPosition(){
    return this->obj.position;
}
edk::float32 edk::tiles::Tile2D::getPositionX(){
    return this->obj.position.x;
}
edk::float32 edk::tiles::Tile2D::getPositionY(){
    return this->obj.position.y;
}

//callback to start and end draw tile
bool edk::tiles::Tile2D::addStartDrawCallback(edk::tiles::DrawTile2DCallback* callback){
    if(callback)
        return this->startDraw.add(callback);
    return false;
}
bool edk::tiles::Tile2D::addEndDrawCallback(edk::tiles::DrawTile2DCallback* callback){
    if(callback)
    return this->endDraw.add(callback);
    return false;
}
bool edk::tiles::Tile2D::removeStartDrawCallback(edk::tiles::DrawTile2DCallback* callback){
    return this->startDraw.remove(callback);
}
bool edk::tiles::Tile2D::removeEndDrawCallback(edk::tiles::DrawTile2DCallback* callback){
    return this->endDraw.remove(callback);
}
void edk::tiles::Tile2D::runStartDraw(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition){
    this->startDraw.runStart(id,position,worldPosition);
}
void edk::tiles::Tile2D::runEndDraw(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition){
    this->startDraw.runEnd(id,position,worldPosition);
}

//Add a interpolation to the animation
bool edk::tiles::Tile2D::addFrameInterpolation(edk::float32 second,edk::float32 frame){
    this->selectAnimation();
    return this->mesh.selectedAnimationAddInterpolationLine(second,frame);
}
//return the interpolation size
edk::uint32 edk::tiles::Tile2D::getInterpolationSize(){
    this->selectAnimation();
    return this->mesh.selectedAnimationGetInterpolationSize();
}
//clean frames
bool edk::tiles::Tile2D::cleanFames(){
    this->selectAnimation();
    return this->mesh.selectedAnimationCleanFrames();
}
//controls
bool edk::tiles::Tile2D::playForward(){
    this->selectAnimation();
    return this->mesh.selectedAnimationPlayForward();
}
bool edk::tiles::Tile2D::playForwardIn(edk::float32 second){
    this->selectAnimation();
    return this->mesh.selectedAnimationPlayForwardIn(second);
}
bool edk::tiles::Tile2D::playRewind(){
    this->selectAnimation();
    return this->mesh.selectedAnimationPlayRewind();
}
bool edk::tiles::Tile2D::playRewindIn(edk::float32 second){
    this->selectAnimation();
    return this->mesh.selectedAnimationPlayRewindIn(second);
}
bool edk::tiles::Tile2D::pause(){
    this->selectAnimation();
    return this->mesh.selectedAnimationPause();
}
bool edk::tiles::Tile2D::pauseOn(){
    this->selectAnimation();
    return this->mesh.selectedAnimationPause();
}
bool edk::tiles::Tile2D::pauseOff(){
    this->selectAnimation();
    return this->mesh.selectedAnimationPause();
}
bool edk::tiles::Tile2D::stop(){
    this->selectAnimation();
    return this->mesh.selectedAnimationStop();
}
//set loop
bool edk::tiles::Tile2D::setLoop(bool loop){
    this->selectAnimation();
    return this->mesh.selectedAnimationSetLoop(loop);
}
bool edk::tiles::Tile2D::loopOn(){
    this->selectAnimation();
    return this->mesh.selectedAnimationLoopOn();
}
bool edk::tiles::Tile2D::loopOff(){
    this->selectAnimation();
    return this->mesh.selectedAnimationLoopOff();
}
//get the second
edk::float32 edk::tiles::Tile2D::getSecond(){
    this->selectAnimation();
    return this->mesh.selectedAnimationGetSecond();
}
//return if are playing
bool edk::tiles::Tile2D::isPlaying(){
    this->selectAnimation();
    return this->mesh.selectedAnimationIsPlaying();
}
//animationNames
bool edk::tiles::Tile2D::addAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
    return this->addAnimationName((edk::char8*) name,start,end);
}
bool edk::tiles::Tile2D::addAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    this->selectAnimation();
    return this->mesh.selectedAnimationAddAnimationName(name,start,end);
}
//test if have the animationName
bool edk::tiles::Tile2D::haveAnimationName(const edk::char8* name){
    return this->haveAnimationName((edk::char8*) name);
}
bool edk::tiles::Tile2D::haveAnimationName(edk::char8* name){
    this->selectAnimation();
    return this->mesh.selectedAnimationHaveAnimationName(name);
}
//Play the animationName
bool edk::tiles::Tile2D::playNameForward(const edk::char8* name){
    return this->playNameForward((edk::char8*) name);
}
bool edk::tiles::Tile2D::playNameForward(edk::char8* name){
    this->selectAnimation();
    return this->mesh.selectedAnimationPlayNameForward(name);
}
bool edk::tiles::Tile2D::playNameRewind(const edk::char8* name){
    return this->playNameRewind((edk::char8*) name);
}
bool edk::tiles::Tile2D::playNameRewind(edk::char8* name){
    this->selectAnimation();
    return this->mesh.selectedAnimationPlayNameRewind(name);
}
//remove the animationName
bool edk::tiles::Tile2D::removeAnimationName(const edk::char8* name){
    return this->removeAnimationName((edk::char8*) name);
}
bool edk::tiles::Tile2D::removeAnimationName(edk::char8* name){
    this->selectAnimation();
    return this->mesh.selectedAnimationRemoveAnimationName(name);
}

//Set one interpolation X as a curve
bool edk::tiles::Tile2D::setCurveX(edk::uint32 position){
    this->selectAnimation();
    return this->mesh.selectedAnimationSetCurveX(position);
}
bool edk::tiles::Tile2D::setNotCurveX(edk::uint32 position){
    this->selectAnimation();
    return this->mesh.selectedAnimationSetNotCurveX(position);
}
bool edk::tiles::Tile2D::getIsCurveX(edk::uint32 position){
    this->selectAnimation();
    return this->mesh.selectedAnimationGetIsCurveX(position);
}
//Set the interpolation curve points
bool edk::tiles::Tile2D::setCurveP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    this->selectAnimation();
    return this->mesh.selectedAnimationSetCurveP1X(position,second,x);
}
bool edk::tiles::Tile2D::setCurveP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    this->selectAnimation();
    return this->mesh.selectedAnimationSetCurveP2X(position,second,x);
}

//get mesh pointer
edk::shape::Mesh2D* edk::tiles::Tile2D::getMeshPointer(){
    return &this->mesh;
}

//create a new object physics
bool edk::tiles::Tile2D::setPhysics(edk::physics::bodyType type){
    this->deletePhysics();
    /*
    edk::shape::Rectangle2D rect;
    rect.setPivoToCenter();
    rect.setScale(1.0f,1.0f);
    rect.setRestitution(0.1f);
    rect.setFriction(0.5);
    */
    switch(type){
    case edk::physics::StaticBody:
        this->objPhys = new edk::physics2D::StaticObject2D;
        break;
    case edk::physics::KinematicBody:
        this->objPhys = new edk::physics2D::KinematicObject2D;
        break;
    case edk::physics::DynamicBody:
        this->objPhys = new edk::physics2D::DynamicObject2D;
        break;
    }
    return this->cleanPhysicsPolygons();
}
//add a polygon to the physics Object
bool edk::tiles::Tile2D::addPhysicsPolygon(edk::shape::Polygon2D poly){
    //test if have the object
    if(this->objPhys){
        //test if dont add a polygon yet
        if(this->addedPhysicsPolygon){
            //then clean the mesh
            this->objPhys->physicMesh.cleanPolygons();
        }
        //add thepolygon
        this->objPhys->physicMesh.addPolygon(poly);
        this->addedPhysicsPolygon=false;
        poly.cantDeletePolygon();
        return true;
    }
    poly.cantDeletePolygon();
    return false;
}
bool edk::tiles::Tile2D::cleanPhysicsPolygons(){
    edk::shape::Rectangle2D rect;
    rect.setPivoToCenter();
    rect.setScale(1.01f,1.01f);
    rect.setRestitution(0.1f);
    rect.setFriction(0.5);
    //test if have the object
    if(this->objPhys){
        this->objPhys->physicMesh.cleanPolygons();
        this->objPhys->physicMesh.addPolygon(rect);
        this->addedPhysicsPolygon=true;
        return true;
    }
    return false;
}

//delete the objectPhysics
void edk::tiles::Tile2D::deletePhysics(){
    if(this->objPhys){
        delete this->objPhys;
    }
    this->addedPhysicsPolygon=false;
    this->objPhys=NULL;
}
//return the physicsObject
edk::physics2D::PhysicObject2D* edk::tiles::Tile2D::getPhysicsObject(){
    return this->objPhys;
}
//return the physicsMesh
edk::physics2D::PhysicsMesh2D* edk::tiles::Tile2D::getPhysicsMeshPointer(){
    if(this->objPhys)
        return &this->objPhys->physicMesh;
    return NULL;
}
//return true if the tile is Physics
bool edk::tiles::Tile2D::isPhysics(){
    if(this->objPhys)
        return true;
    return false;
}

//update the animation
void edk::tiles::Tile2D::updateAnimation(){
    this->mesh.updateFramesAnimations();
}
void edk::tiles::Tile2D::updateAnimation(edk::float32 seconds){
    this->mesh.updateFramesAnimations(seconds);
}

//XML
bool edk::tiles::Tile2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tile_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::char8* temp;
                        //write the object
                        this->obj.writeToXML(xml,0u);

                        //write the physicObject if it have one
                        if(this->objPhys) this->objPhys->writeToXML(xml,0u);
                        //write tileSize
                        temp = edk::String::float32ToStr(this->tileSize.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"tSizeW",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->tileSize.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"tSizeH",temp);
                            delete[] temp;
                        }
                        ret=true;
                        xml->selectFather();
                    }
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::tiles::Tile2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tile_",nameID);
            if(name){
                //read the name
                if(xml->selectChild(name)){
                    this->obj.cleanMeshes();
                    this->mesh.cleanPolygons();
                    //read obj
                    if(this->obj.readFromXML(xml,0u)){
                        //copy the first mesh
                        if(this->obj.getMesh(0u)){
                            //this->mesh = *this->obj.getMesh(0u);
                            this->mesh.cloneFrom(this->obj.getMesh(0u));
                        }
                        //delete all mesh's from XML

                        //                        edk::shape::Mesh2D* meshTemp;
                        //                        edk::uint32 size = this->obj.getMeshSize();
                        /*
                        for(edk::uint32 i=0u;i<size;i++){
                            meshTemp = this->obj.getMesh(i);
                            if(meshTemp)
                                delete meshTemp;
                        }
*/
                        this->obj.removeAllMesh();

                        //set the mesh
                        this->obj.addMesh(&this->mesh);
                    }
                    //read the physicsObject
                    this->objPhys = new edk::physics2D::PhysicObject2D;
                    if(this->objPhys){
                        if(!this->objPhys->readFromXML(xml,0u)){
                            //dont have physicc object
                            delete this->objPhys;
                            this->objPhys=NULL;
                        }
                    }
                    //read the tileSize
                    this->tileSize = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("tSizeW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("tSizeH"))
                                                   );
                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::tiles::Tile2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tile_",nameID);
            if(name){
                //read the name
                if(xml->selectChild(name)){
                    this->obj.cleanMeshes();
                    this->mesh.cleanPolygons();
                    //read obj
                    if(this->obj.readFromXMLFromPack(pack,xml,0u)){
                        //copy the first mesh
                        if(this->obj.getMesh(0u)){
                            //this->mesh = *this->obj.getMesh(0u);
                            this->mesh.cloneFrom(this->obj.getMesh(0u));
                        }
                        //delete all mesh's from XML

                        //                        edk::shape::Mesh2D* meshTemp;
                        //                        edk::uint32 size = this->obj.getMeshSize();
                        /*
                        for(edk::uint32 i=0u;i<size;i++){
                            meshTemp = this->obj.getMesh(i);
                            if(meshTemp)
                                delete meshTemp;
                        }
*/
                        this->obj.removeAllMesh();

                        //set the mesh
                        this->obj.addMesh(&this->mesh);
                    }
                    //read the physicsObject
                    this->objPhys = new edk::physics2D::PhysicObject2D;
                    if(this->objPhys){
                        if(!this->objPhys->readFromXMLFromPack(pack,xml,0u)){
                            //dont have physicc object
                            delete this->objPhys;
                            this->objPhys=NULL;
                        }
                    }
                    //read the tileSize
                    this->tileSize = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("tSizeW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("tSizeH"))
                                                   );
                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}

//Draw the tile
void edk::tiles::Tile2D::draw(edk::float32 angle,edk::size2f32 size){
    this->obj.angle = angle;
    this->tileSize = this->obj.size;
    this->obj.size = size;
    this->obj.draw();
    this->obj.angle = 0.f;
    this->obj.size = this->tileSize;
}
void edk::tiles::Tile2D::drawWithoutMaterial(edk::float32 angle,edk::size2f32 size){
    this->obj.angle = angle;
    this->tileSize = this->obj.size;
    this->obj.size = size;
    this->obj.drawWithoutMaterial();
    this->obj.angle = 0.f;
    this->obj.size = this->tileSize;
}
void edk::tiles::Tile2D::drawWire(edk::float32 angle,edk::size2f32 size){
    this->obj.angle = angle;
    this->tileSize = this->obj.size;
    this->obj.size = size;
    this->obj.drawWire();
    this->obj.angle = 0.f;
    this->obj.size = this->tileSize;
}
void edk::tiles::Tile2D::drawSelection(edk::float32 angle,edk::size2f32 size){
    this->obj.angle = angle;
    this->tileSize = this->obj.size;
    this->obj.size = size;
    this->obj.drawWithoutMaterial();
    this->obj.angle = 0.f;
    this->obj.size = this->tileSize;
}

void edk::tiles::Tile2D::drawPhysic(edk::float32 angle,edk::size2f32 size){
    if(this->objPhys){
        this->objPhys->angle = angle;
        this->tileSize = this->obj.size;
        this->objPhys->size = size;
        this->objPhys->drawWirePhysics();
        this->objPhys->angle = 0.f;
        this->objPhys->size = this->tileSize;
    }
}
