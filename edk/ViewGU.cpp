#include "ViewGU.h"

/*
Library C++ viewGU - Render GU elements inside this view in Edk Game Engine
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
#warning "            Inside ViewGU.cpp"
#endif

edk::ViewGU::ViewGU()
{
    //ctor
    this->runSelection=false;
}

edk::ViewGU::~ViewGU()
{
    //dtor
}
//return true if is a GU View
bool edk::ViewGU::isGU(){
    //return true because its a GU View
    return true;
}
//Draw Functions
//draw viewPort
void edk::ViewGU::drawViewport(rectf32 outsideViewOrigin){
    //
    edk::ViewSpriteController::drawViewport(outsideViewOrigin);
}
//draw Camera
void edk::ViewGU::drawCamera(){
    //
    edk::ViewSpriteController::drawCamera();
}
//draw the polygon on the scene
void edk::ViewGU::drawPolygon(rectf32 outsideViewOrigin){
    //
    edk::ViewSpriteController::drawPolygon(outsideViewOrigin);

    //Draw the camera in the future

    //then draw the scene
    this->runDrawScene(outsideViewOrigin);

    this->runSelectionFunction();

    edk::GU::guDisableAllLights();
}
//draw selection camera
void edk::ViewGU::drawSelectionCamera(){
    //
}
//push and pop the selection names
void edk::ViewGU::selectionPushName(edk::uint32 id){
    edk::GU::guPushName(id);
}
void edk::ViewGU::selectionPopName(){
    edk::GU::guPopName();
}
//process the selection
void edk::ViewGU::processHits(edk::uint32 hits, edk::uint32 buffer[]){
    edk::uint32 i, j;
    edk::uint32 names=0u, *ptr=NULL;
    edk::float32 sNear = 0.f;
    edk::float32 sFar = 0.f;
    //stack with names
    edk::vector::Stack<edk::uint32> nameStack;

    if(hits>0){
        ptr = (GLuint *) buffer;
        for (i = 0; i < hits; i++) {  /* for each hit  */
            nameStack.clean();
            names = *ptr;
            ptr++;
            sNear = (edk::float32)*ptr/0x7fffffff;
            ptr++;
            sFar = (edk::float32)*ptr/0x7fffffff;
            ptr++;
            for (j = 0; j < names; j++) {  /* for each name */
                nameStack.pushBack(*ptr);
                ptr++;
            }
            //run the function
            this->selectObject(i,hits,sNear,sFar,&nameStack);
        }
    }
    else{
        this->selectObject(0,hits,0,0,&nameStack);
    }
}
//process the selection
void edk::ViewGU::selectObject(edk::uint32 ,edk::uint32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* ){
    //
}
//run selection function
void edk::ViewGU::runSelectionFunction(){
    //test if need run the selection
    if(this->runSelection){
        //
        this->runSelection=false;

        edk::uint32 buffer[100u];
        edk::GU::guSetSelectionBuffer(100u,buffer);

        edk::GU::guUseMatrix(GU_PROJECTION);
        edk::GU::guLoadIdentity();

        edk::GU::guRenderMode(GU_SELECT);

        edk::GU::guInitNames();

        //set pick buffer
        edk::GU::guPickMatrix((edk::float64)this->selectionPosition.x,(edk::float64)this->selectionPosition.y,
                              this->selectionSize.width,this->selectionSize.height
                              );

        this->drawSelectionCamera();

        edk::GU::guDisable(GU_TEXTURE);
        edk::GU::guDisable(GU_LIGHTING);

        //draw the polygon with UV Map
        edk::GU::guUseMatrix(GU_MODELVIEW);

        this->drawSelectionScene();

        edk::int32 total = edk::GU::guRenderMode(GU_RENDER);
        this->processHits(total,buffer);
    }
}
//get true if go run selection
bool edk::ViewGU::isRunningSelection(){
    return this->runSelection;
}
void edk::ViewGU::runDrawScene(edk::rectf32 outsideViewOrigin){
    this->drawScene(outsideViewOrigin);
}

//load the background
bool edk::ViewGU::loadBackground(const edk::char8* name){
    //
    return this->loadSprite(name);
}
bool edk::ViewGU::loadBackground(edk::char8* name){
    //
    return this->loadSprite(name);
}
//load the sprite from memory
bool edk::ViewGU::loadBackgroundFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size){
    return this->loadBackgroundFromMemory((edk::char8*)name,sprite,size);
}
bool edk::ViewGU::loadBackgroundFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size){
    return this->loadSpriteFromMemory(name,sprite,size);
}
//laod the sprite from pack
bool edk::ViewGU::loadBackgroundFromPack(edk::pack::FilePackage* pack, edk::char8* name){
    return this->loadSpriteFromPack(pack,name);
}
bool edk::ViewGU::loadBackgroundFromPack(edk::pack::FilePackage* pack, const edk::char8* name){
    //
    return this->loadBackgroundFromPack(pack, (edk::char8*) name);
}

//delete the background
void edk::ViewGU::deleteBackground(){
    //
    this->deleteSprite();
}

//test the selection
void edk::ViewGU::testSelection(edk::vec2f32 position,edk::size2f32 size){
    //
    this->runSelection = true;
    this->selectionPosition = edk::vec2f32(position.x + this->rectTemp.origin.x,((position.y*-1)+this->frame.size.height) + this->rectTemp.origin.y);
    this->selectionSize = size;
}
void edk::ViewGU::testSelection(edk::float32 x,edk::float32 y,edk::size2f32 size){
    this->testSelection(edk::vec2f32(x,y),size);
}
void edk::ViewGU::testSelection(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
    this->testSelection(edk::vec2f32(x,y),edk::size2f32(width,height));
}
void edk::ViewGU::testSelection(edk::vec2i32 position,edk::size2f32 size){
    this->runSelection = true;
    this->selectionPosition = edk::vec2f32(position.x + this->rectTemp.origin.x,((position.y*-1)+this->frame.size.height) + this->rectTemp.origin.y);
    this->selectionSize = size;
}
void edk::ViewGU::testSelection(edk::int32 x,edk::int32 y,edk::size2f32 size){
    this->testSelection(edk::vec2i32(x,y),size);
}
void edk::ViewGU::testSelection(edk::int32 x,edk::int32 y,edk::float32 width,edk::float32 height){
    this->testSelection(edk::vec2i32(x,y),edk::size2f32(width,height));
}

//draw the GU scene
void edk::ViewGU::drawScene(edk::rectf32){
    //
}
void edk::ViewGU::drawSelectionScene(){
    //
}

void edk::ViewGU::update(edk::WindowEvents* events){
    //
    edk::View::update(events);
}
