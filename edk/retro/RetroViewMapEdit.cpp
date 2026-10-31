#include "RetroViewMapEdit.h"

/*
Library C++ RetroViewTileSelect - View used to Show and select tiles in EDK
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
#pragma message "            Inside RetroViewTileSelect.cpp"
#endif

edk::Image2D edk::retro::RetroViewMapEdit::imgBack;
edk::uint32  edk::retro::RetroViewMapEdit::counterBack;
edk::uint32  edk::retro::RetroViewMapEdit::uvBack;
edk::retro::RetroPalettes edk::retro::RetroViewMapEdit::staticPalettes;
edk::uint32 edk::retro::RetroViewMapEdit::counterPalettes=0uL;
edk::retro::RetroTileSet edk::retro::RetroViewMapEdit::staticTiles;
edk::uint32 edk::retro::RetroViewMapEdit::counterTiles=0uL;
edk::retro::RetroTileMap edk::retro::RetroViewMapEdit::staticMap;
edk::uint32 edk::retro::RetroViewMapEdit::counterMap=0uL;

edk::retro::RetroTileMapList edk::retro::RetroViewMapEdit::staticMaps;
edk::uint32 edk::retro::RetroViewMapEdit::counterMaps=0uL;

#define EditorBackImage "PixelEditorBackground.image"
#define EditorBackDark  0x55
#define EditorBackLight 0xAA
#define EditorBackground 0x33
#define editorZoomPercent 0.1f
#define editorWaitSelection 0.25f

edk::retro::RetroViewMapEdit::RetroViewMapEdit(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroViewMapEdit::~RetroViewMapEdit(){
    this->Destructor();
}

void edk::retro::RetroViewMapEdit::Constructor(){
    edk::ViewGU2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        edk::retro::RetroViewMapEdit::imgBack.Constructor();
        edk::retro::RetroViewMapEdit::counterBack=0u;
        edk::retro::RetroViewMapEdit::uvBack=0u;


        if(!edk::retro::RetroViewMapEdit::counterBack){
            if(edk::retro::RetroViewMapEdit::imgBack.newImage(EditorBackImage,4u,4u,3u,1u)){
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(0u,0u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(1u,0u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(0u,1u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(1u,1u,EditorBackDark,EditorBackDark,EditorBackDark);

                edk::retro::RetroViewMapEdit::imgBack.drawPosition(2u,0u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(3u,0u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(2u,1u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(3u,1u,EditorBackLight,EditorBackLight,EditorBackLight);

                edk::retro::RetroViewMapEdit::imgBack.drawPosition(0u,2u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(1u,2u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(0u,3u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(1u,3u,EditorBackLight,EditorBackLight,EditorBackLight);

                edk::retro::RetroViewMapEdit::imgBack.drawPosition(2u,2u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(3u,2u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(2u,3u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewMapEdit::imgBack.drawPosition(3u,3u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewMapEdit::counterBack++;
            }
        }
        else{
            edk::retro::RetroViewMapEdit::counterBack++;
        }

        if(!edk::retro::RetroViewMapEdit::counterPalettes){
            edk::retro::RetroViewMapEdit::staticPalettes.Constructor();
        }
        edk::retro::RetroViewMapEdit::counterPalettes++;
        if(!edk::retro::RetroViewMapEdit::counterTiles){
            edk::retro::RetroViewMapEdit::staticTiles.Constructor();
        }
        edk::retro::RetroViewMapEdit::counterTiles++;
        if(!edk::retro::RetroViewMapEdit::counterMap){
            edk::retro::RetroViewMapEdit::staticMap.Constructor();
        }
        edk::retro::RetroViewMapEdit::counterMap++;

        this->setBackgroundUV(2u);

        this->sizeGrade = 1u;
        this->dontDrawGrade();

        this->saveSizeCamera = this->camera.getSize();
        this->zoomCamera = 1.f;

        this->animSelection.addFirstInterpolationLine(0.f,editorWaitSelection);

        this->zoomCamera = 1.f;
        this->saveSizeCamera = this->camera.getSize();
        this->scrollPrecision=0.f;

        this->saveSelectedID = this->selectedID=0xFFFFFFFF;


        this->setPalettes(NULL);
        this->setTilesSet(NULL);
        this->setMapList(NULL);
        this->selectMap(0u);
    }
}
void edk::retro::RetroViewMapEdit::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

        if(edk::retro::RetroViewMapEdit::counterBack){
            edk::retro::RetroViewMapEdit::counterBack--;
            if(!edk::retro::RetroViewMapEdit::counterBack){
                edk::retro::RetroViewMapEdit::imgBack.deleteImage();
            }
        }
        if(edk::retro::RetroViewMapEdit::counterPalettes){
            edk::retro::RetroViewMapEdit::counterPalettes--;
            if(!edk::retro::RetroViewMapEdit::counterPalettes){
                edk::retro::RetroViewMapEdit::staticPalettes.Destructor();
            }
        }
        if(edk::retro::RetroViewMapEdit::counterTiles){
            edk::retro::RetroViewMapEdit::counterTiles--;
            if(!edk::retro::RetroViewMapEdit::counterTiles){
                edk::retro::RetroViewMapEdit::staticTiles.Destructor();
            }
        }
        if(edk::retro::RetroViewMapEdit::counterMap){
            edk::retro::RetroViewMapEdit::counterMap--;
            if(!edk::retro::RetroViewMapEdit::counterMap){
                edk::retro::RetroViewMapEdit::staticMap.Destructor();
            }
        }
    }
    edk::ViewGU2D::Destructor();
}

bool edk::retro::RetroViewMapEdit::setPalettes(edk::retro::RetroPalettes* palettes){
    if(palettes){
        this->palettes=palettes;
        return true;
    }
    this->palettes = &edk::retro::RetroViewMapEdit::staticPalettes;
    return false;
}
bool edk::retro::RetroViewMapEdit::setTilesSet(edk::retro::RetroTileSet* tiles){
    if(tiles){
        this->tiles=tiles;
        return true;
    }
    this->tiles = &edk::retro::RetroViewMapEdit::staticTiles;
    return false;
}
bool edk::retro::RetroViewMapEdit::setMapList(edk::retro::RetroTileMapList* list){
    if(list){
        this->maps=list;
        return true;
    }
    this->maps = &edk::retro::RetroViewMapEdit::staticMaps;
    return false;
}

//select a map to edit
edk::uint32 edk::retro::RetroViewMapEdit::getSizeMaps(){
    return this->maps->size();
}
bool edk::retro::RetroViewMapEdit::selectMap(edk::uint32 position){
    this->map = this->maps->getMap(position);
    if(this->map){
        return true;
    }
    this->map = &edk::retro::RetroViewMapEdit::staticMap;
    return false;
}

void edk::retro::RetroViewMapEdit::runUpdateViewSize(){
    //
    this->updateCamera();
}

//load the tiles from an image
bool edk::retro::RetroViewMapEdit::loadMapFromImage(edk::Image2D* img){
    if(img){
        bool ret=false;
        //test if have the palette
        if(img->havePalette()){
            //copy the new palette
            edk::retro::RetroPalette* palette = this->palettes->newPaletteFromVector(img->getPalette(),
                                                                                     img->getPaletteSize(),
                                                                                     img->getChannels(),
                                                                                     img->getBytesPerChannel()
                                                                                     );
            if(palette){
                //copy the tiles
                edk::uint32 width=img->getWidth(),height=img->getHeight();
                edk::uint32 tilesW = width/8u,tilesH = height/8u;

                edk::retro::RetroTile tempTile;
                tempTile.setPalette(palette);
                edk::uint32 id=0u;
                edk::uint8* vec=NULL;
                edk::uint8 bytesPerColor = img->getBytesPerColor();
                edk::retro::RetroTileSpecs specs;

                //create a new map
                edk::uint32 position = this->maps->createNewMap(this->tiles,tilesW,tilesH);

                if(this->selectMap(position)){
                    edk::char8* str = edk::String::strFileNameNoExtension(img->getName());
                    if(str){
                        this->map->setName(str);
                        free(str);
                    }
                    //create the tiles
                    for(edk::uint32 h=0u;h<tilesH;h++){
                        for(edk::uint32 w=0u;w<tilesW;w++){
                            //load the ids
                            vec = img->getColors();
                            //goto the line
                            vec+=bytesPerColor*(width*h*8u);
                            for(edk::uint32 y=0u;y<8u;y++){
                                //goto the start
                                vec+=(bytesPerColor*8u*w);
                                for(edk::uint32 x=0u;x<8u;x++){
                                    id=0u;
                                    edkMemCpy(&id,vec,bytesPerColor);
                                    tempTile.setPixel(x,y,id);
                                    vec+=bytesPerColor;
                                }
                                //go to the end
                                vec+=bytesPerColor*(width - ((8u*w) + 8u));
                            }
                            //add the tile
                            specs=0u;
                            if(this->tiles->addTileEqualTest(tempTile,&specs)){
                                //set it on the map
                                this->map->setID(w,h,specs.value);
                            }
                            else{
                                //get the tileID
                                this->map->setID(w,h,specs.value);
                            }
                        }
                    }
                    ret = true;
                }
            }
        }
        return ret;
    }
    return false;
}
bool edk::retro::RetroViewMapEdit::loadMapFromImage(edk::char8* name){
    if(name){
        bool ret = false;
        edk::Image2D img;
        if(img.loadFromFile(name)){
            ret = this->loadMapFromImage(&img);
            img.clean();
        }
        return ret;
    }
    return false;
}
bool edk::retro::RetroViewMapEdit::loadMapFromImage(const edk::char8* name){
    return this->loadMapFromImage((edk::char8*) name);
}
//load the tiles from an image with no spec tests
bool edk::retro::RetroViewMapEdit::loadMapFromImageWithSpecs(edk::Image2D* img){
    if(img){
        bool ret=false;
        //test if have the palette
        if(img->havePalette()){
            //copy the new palette
            edk::retro::RetroPalette* palette = this->palettes->newPaletteFromVector(img->getPalette(),
                                                                                     img->getPaletteSize(),
                                                                                     img->getChannels(),
                                                                                     img->getBytesPerChannel()
                                                                                     );
            if(palette){
                //copy the tiles
                edk::uint32 width=img->getWidth(),height=img->getHeight();
                edk::uint32 tilesW = width/8u,tilesH = height/8u;

                edk::retro::RetroTile tempTile;
                tempTile.setPalette(palette);
                edk::uint32 id=0u;
                edk::uint8* vec=NULL;
                edk::uint8 bytesPerColor = img->getBytesPerColor();
                edk::retro::RetroTileSpecs specs;

                //create the map
                this->map->newMap(tilesW,tilesH);
                edk::char8* str = edk::String::strFileNameNoExtension(img->getName());
                if(str){
                    this->map->setName(str);
                    free(str);
                }

                //create the tiles
                for(edk::uint32 h=0u;h<tilesH;h++){
                    for(edk::uint32 w=0u;w<tilesW;w++){
                        //load the ids
                        vec = img->getColors();
                        //goto the line
                        vec+=bytesPerColor*(width*h*8u);
                        for(edk::uint32 y=0u;y<8u;y++){
                            //goto the start
                            vec+=(bytesPerColor*8u*w);
                            for(edk::uint32 x=0u;x<8u;x++){
                                id=0u;
                                edkMemCpy(&id,vec,bytesPerColor);
                                tempTile.setPixel(x,y,id);
                                vec+=bytesPerColor;
                            }
                            //go to the end
                            vec+=bytesPerColor*(width - ((8u*w) + 8u));
                        }
                        //add the tile
                        specs=0u;
                        if(this->tiles->addTileEqualFlipTest(tempTile,&specs)){
                            //set it on the map
                            this->map->setID(w,h,specs.value);
                        }
                        else{
                            //get the tileID
                            this->map->setID(w,h,specs.value);
                            this->map->setFlipH(w,h,specs.flipH);
                            this->map->setFlipV(w,h,specs.flipV);
                        }
                    }
                }
                ret = true;
            }
        }
        return ret;
    }
    return false;
}
bool edk::retro::RetroViewMapEdit::loadMapFromImageWithSpecs(edk::char8* name){
    if(name){
        bool ret = false;
        edk::Image2D img;
        if(img.loadFromFile(name)){
            ret = this->loadMapFromImageWithSpecs(&img);
            img.clean();
        }
        return ret;
    }
    return false;
}
bool edk::retro::RetroViewMapEdit::loadMapFromImageWithSpecs(const edk::char8* name){
    return this->loadMapFromImageWithSpecs((edk::char8*) name);
}

//select a tile
bool edk::retro::RetroViewMapEdit::selectTile(edk::uint32 id){
    if(this->tiles->havePos(id)){
        this->selectedID = id;
        return true;
    }
    this->selectedID=0xFFFFFFFF;
    return false;
}
void edk::retro::RetroViewMapEdit::unselectTile(){
    this->selectedID=0xFFFFFFFF;
}
bool edk::retro::RetroViewMapEdit::haveTileSelected(){
    if(this->tiles->havePos(this->selectedID)){
        return true;
    }
    return false;
}
bool edk::retro::RetroViewMapEdit::haveSelectTile(){
    if(this->saveSelectedID != this->selectedID){
        this->saveSelectedID = this->selectedID;
        return true;
    }
    return false;
}
edk::uint32 edk::retro::RetroViewMapEdit::getSelectedTile(){
    return this->selectedID;
}

edk::uint32 edk::retro::RetroViewMapEdit::getLenghtTiles(){
    return this->tiles->size();
}

//set draw grade
void edk::retro::RetroViewMapEdit::setDrawGrade(bool can){
    this->goDrawGrade = can;
}
void edk::retro::RetroViewMapEdit::canDrawGrade(){
    this->setDrawGrade(true);
}
void edk::retro::RetroViewMapEdit::cantDrawGrade(){
    this->setDrawGrade(false);
}
void edk::retro::RetroViewMapEdit::dontDrawGrade(){
    this->setDrawGrade(false);
}
void edk::retro::RetroViewMapEdit::setDrawPixelGrade(bool can){
    this->goDrawPixelGrade = can;
}
void edk::retro::RetroViewMapEdit::canDrawPixelGrade(){
    this->setDrawPixelGrade(true);
}
void edk::retro::RetroViewMapEdit::cantDrawPixelGrade(){
    this->setDrawPixelGrade(false);
}
void edk::retro::RetroViewMapEdit::dontDrawPixelGrade(){
    this->setDrawPixelGrade(false);
}

//SETTERS
bool edk::retro::RetroViewMapEdit::setBackgroundUV(edk::uint32 uv){
    if(uv>=2u){
        this->uvSize = uv;
        return true;
    }
    this->uvSize = 2u;
    return false;
}
//set the gradeSize
bool edk::retro::RetroViewMapEdit::setGradeSize(edk::size2ui32 size){
    if(size.width && size.height){
        this->sizeGrade = size;
    }
    return false;
}
bool edk::retro::RetroViewMapEdit::setGradeSize(edk::uint32 width,edk::uint32 height){
    return this->setGradeSize(edk::size2ui32(width,height));
}

//update the camera size
void edk::retro::RetroViewMapEdit::updateCamera(){
    this->camera.setSize(this->frame.size.width,this->frame.size.height);
    this->saveSizeCamera = this->camera.getSize();

    if(this->map->getWidth() && this->map->getHeight()){

        this->rectFull.convertIntoPositionAndSize();

        //calculate the object inside the camera
        edk::rectf32 rect = this->camera.getRectPositionAndSize();
        rect = edk::Math::aspectRatioCorrect(rect,edk::size2f32(this->map->getWidth() * 8u,
                                                                this->map->getHeight() * 8u
                                                                )
                                             );
        //rect.convertIntoPositionAndSize();
        this->rectFull.size.width = this->objBack.size.width = rect.size.width;
        this->rectFull.size.height = this->objBack.size.height = rect.size.height;

    }

    //update the zoom
    this->saveSizeCamera = this->camera.getSize();

    this->updateZoom();


    this->rectFull.convertIntoPoints();

    edk::float32 temp = this->rectFull.origin.y;
    this->rectFull.origin.y = this->rectFull.size.height;
    this->rectFull.size.height = temp;
}
void edk::retro::RetroViewMapEdit::updateZoom(){
    //calculate the zoom of the camera
    this->camera.setSize(this->saveSizeCamera.width * this->zoomCamera,
                         this->saveSizeCamera.height * this->zoomCamera
                         );
}
//process the selection
void edk::retro::RetroViewMapEdit::selectObject(edk::uint32 /*position*/,
                                                edk::int32 /*objects*/,
                                                edk::float32 /*near*/,
                                                edk::float32 /*far*/,
                                                edk::vector::Stack<edk::uint32>* names
                                                ){
    edk::uint32 size = names->size();
    if(size==2u){
        //select the tile
        this->selectTile(names->get(1u));
    }
}

void edk::retro::RetroViewMapEdit::resize(edk::rectf32 /*outsideViewOrigin*/){
}
void edk::retro::RetroViewMapEdit::load(edk::rectf32 /*outsideViewOrigin*/){
    this->backgroundColor = edk::color4f32((edk::float32)EditorBackground/0xFF,
                                           (edk::float32)EditorBackground/0xFF,
                                           (edk::float32)EditorBackground/0xFF,
                                           1.f);
    edk::shape::Mesh2D* mesh = NULL;
    mesh = this->objBack.newMesh();
    if(mesh){
        edk::shape::Rectangle2D rect;
        rect.setPivoToCenter();
        mesh->addPolygon(rect);

        edk::GU::guSetTexturesWrap(GU_REPEAT);
        mesh->material.setTextureFromMemory(&edk::retro::RetroViewMapEdit::imgBack,
                                            0u,
                                            GU_NEAREST,
                                            GU_NEAREST
                                            );
        edk::GU::guSetTexturesWrap(0u);
    }

    ////////////////////////////////////////////
    this->setBackgroundUV(4u);
    ////////////////////////////////////////////

    this->zoomCamera = 1.f;

    this->updateCamera();
}
void edk::retro::RetroViewMapEdit::unload(){
    this->objBack.clean();
}
//update the view
void edk::retro::RetroViewMapEdit::update(edk::WindowEvents* events){
    //update the view
    edk::View::update(events);

    this->animSelection.updateClockAnimation(events->secondPassed);



    //process the in
    edk::uint32 size = 0u;

    bool holdControl=false;
    bool pressZoomIn=false;
    bool pressZoomDout=false;
    bool pressMouseMiddle=false;
    bool holdMouseLeft=false;
    bool holdMouseMiddle=false;

    size = events->keyHolded.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->keyHolded.get(i)){
        case edk::key::lControl:
            holdControl=true;
            break;
        case edk::key::rControl:
            holdControl=true;
            break;
        }
    }

    size = events->keyPressed.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->keyPressed.get(i)){
        case edk::key::add:
            pressZoomIn=true;
            break;
        case edk::key::equal:
            pressZoomIn=true;
            break;
        case edk::key::subtract:
            pressZoomDout=true;
            break;
        case edk::key::dash:
            pressZoomDout=true;
            break;
        }
    }
    size = events->keyRelease.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->keyRelease.get(i)){
        case edk::key::add:
            //pressZoomIn=true;
            break;
        case edk::key::equal:
            //pressZoomIn=true;
            break;
        case edk::key::subtract:
            //pressZoomDout=true;
            break;
        case edk::key::dash:
            //pressZoomDout=true;
            break;
        }
    }

    size = events->mousePressed.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mousePressed.get(i)){
        case edk::mouse::left:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            break;
        case edk::mouse::right:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            break;
        case edk::mouse::middle:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            pressMouseMiddle=true;
            break;
        }
    }
    size = events->mouseHolded.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mouseHolded.get(i)){
        case edk::mouse::left:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            holdMouseLeft=true;
            break;
        case edk::mouse::right:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            break;
        case edk::mouse::middle:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            holdMouseMiddle=true;
            break;
        }
    }

    if(this->isMouseInside()){
        //convert the mouse position
        this->posMouse.position = this->positionScreenToWorld(events->mousePosView.x,events->mousePosView.y);

        //distance in the world
        edk::vec2f32 distance = edk::vec2f32(this->savePosMouse.x - this->posMouse.position.x,
                                             this->savePosMouse.y - this->posMouse.position.y
                                             );
        this->distanceMouse = edk::Math::pythagoras(edk::vec2f32(this->savePosMouseSelect.x - this->posMouse.position.x,
                                                                 this->savePosMouseSelect.y - this->posMouse.position.y
                                                                 )
                                                    );

        //move the camera with the scroll
        if(events->mouseScrollWheelHorizontal){
            if(!holdControl){
                this->camera.position.x += this->camera.getSize().width * 0.1f * events->mouseScrollWheelHorizontal
                        * -1.f
                        ;
            }
        }
        if(events->mouseScrollWheelVertical){
            if(holdControl){

                //run the camera zoom
                this->zoomCamera += editorZoomPercent * events->mouseScrollWheelVertical
                        * -1.f
                        ;
                if(this->zoomCamera<0.01f){
                    this->zoomCamera = 0.01f;
                }
                //update the zoom
                this->updateZoom();

            }
            else{
                this->camera.position.y += this->camera.getSize().height * 0.1f * events->mouseScrollWheelVertical;
            }
        }
        //process the zoom
        if(pressZoomIn){
            this->zoomCamera -= editorZoomPercent * 2.f;

            if(this->zoomCamera<0.01f){
                this->zoomCamera = 0.01f;
            }
            //update the zoom
            this->updateZoom();
        }
        if(pressZoomDout){
            this->zoomCamera += editorZoomPercent * 2.f;
            //update the zoom
            this->updateZoom();
        }

        //process the selection
        if(holdMouseLeft){
            //
            if(!this->animSelection.isPlaying()){
                this->testSelection(events->mousePosView.x,events->mousePosView.y,
                                    1.f,
                                    1.f
                                    );
                this->animSelection.playForward();
            }
        }
        if(pressMouseMiddle){
            //
        }
        if(holdMouseMiddle){
            if(events->mouseMoved){
                if(edk::Math::equal(0.f,this->frame.size.width)
                        || edk::Math::equal(0.f,this->frame.size.height)
                        ){
                    distance = edk::vec2f32((((edk::float32)events->mouseMove.x/(this->frame.size.width+0.001f))*this->camera.getSize().width)
                                            ,
                                            (((edk::float32)events->mouseMove.y/(this->frame.size.height+0.001f))*this->camera.getSize().height)
                                            );
                }
                else{
                    distance = edk::vec2f32((((edk::float32)events->mouseMove.x/this->frame.size.width)*this->camera.getSize().width)
                                            ,
                                            (((edk::float32)events->mouseMove.y/this->frame.size.height)*this->camera.getSize().height)
                                            );
                }
                //move the camera into the distance
                if(!this->animCenterCamera.isPlaying()){
                    this->camera.position.x -= distance.x;
                    this->camera.position.y += distance.y;
                    this->updateZoom();
                }
            }
        }
    }
}
void edk::retro::RetroViewMapEdit::drawScene(edk::rectf32 /*outsideViewOrigin*/){
    //
    //test if need change the uv
    if(edk::retro::RetroViewMapEdit::uvBack!=this->uvSize){
        edk::retro::RetroViewMapEdit::uvBack=this->uvSize;
        //change the polygon UV
        edk::shape::Mesh2D* mesh = this->objBack.getMesh(0u);
        if(mesh){
            mesh->selectPolygon(0u);
            mesh->selectedSetVertexUV(1u,
                                      edk::retro::RetroViewMapEdit::uvBack*0.5f,
                                      edk::retro::RetroViewMapEdit::uvBack*0.5f
                                      );
        }
    }
    if(this->map->getWidth() && this->map->getHeight()){
        //this->objBack.size = this->camera.getSize();
        //this->objBack.position = this->camera.position;
        this->objBack.draw();
        //
        edk::rectf32 rectTile;
        edk::rectf32 rectPixel;
        edk::float32 tempChange = 0.f;

        edk::retro::RetroTile temp;
        edk::retro::RetroTileSpecs specs;
        edk::uint32 mapWidth=this->map->getWidth(),mapHeight=this->map->getHeight();
        edk::float32 percentMapX1=0.f,percentMapX2=0.f,
                incrementMapX = 1.f/this->map->getWidth(),
                percentMapY1=0.f,percentMapY2=0.f,
                incrementMapY = 1.f/this->map->getHeight();
        edk::float32 percentPixelX1=0.f,percentPixelX2=0.f,
                incrementPixel = 1.f/8.f,
                percentPixelY1=0.f,percentPixelY2=0.f;

        edk::color4ui8 color;

        edk::GU::guBegin(GU_QUADS);

        percentMapY1 = 0.f;
        percentMapY2 = incrementMapY;
        for(edk::uint32 y=0u;y<mapHeight;y++){
            percentMapX1 = 0.f;
            percentMapX2 = incrementMapX;
            for(edk::uint32 x=0u;x<mapWidth;x++){
                specs = this->map->getSpecs(x,y);
                if(this->tiles->havePos(specs.value)){
                    temp = this->tiles->get(specs.value);


                    //draw the tile in the position
                    rectTile = edk::rectf32(((this->rectFull.size.width -  this->rectFull.origin.x)*percentMapX1) + this->rectFull.origin.x,
                                            ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY1) + this->rectFull.origin.y,
                                            ((this->rectFull.size.width -  this->rectFull.origin.x)*percentMapX2) + this->rectFull.origin.x,
                                            ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY2) + this->rectFull.origin.y
                                            );

                    if(specs.flipH){
                        //invert X
                        tempChange = rectTile.origin.x;
                        rectTile.origin.x = rectTile.size.width;
                        rectTile.size.width = tempChange;
                    }
                    if(specs.flipV){
                        //invert Y
                        tempChange = rectTile.origin.y;
                        rectTile.origin.y = rectTile.size.height;
                        rectTile.size.height = tempChange;
                    }

                    percentPixelY1=0.f;
                    percentPixelY2 = incrementPixel;
                    for(edk::uint32 yp=0u;yp<8u;yp++){
                        percentPixelX1=0.f;
                        percentPixelX2 = incrementPixel;
                        for(edk::uint32 xp=0u;xp<8u;xp++){
                            //
                            rectPixel = edk::rectf32(((rectTile.size.width - rectTile.origin.x)*percentPixelX1) + rectTile.origin.x,
                                                     ((rectTile.size.height - rectTile.origin.y)*percentPixelY1) + rectTile.origin.y,
                                                     ((rectTile.size.width - rectTile.origin.x)*percentPixelX2) + rectTile.origin.x,
                                                     ((rectTile.size.height - rectTile.origin.y)*percentPixelY2) + rectTile.origin.y
                                                     );

                            //get the color
                            color = temp.getPixelColor4ui8(xp,yp);
                            edk::GU::guColor4f32((edk::float32)color.r/255.f,
                                                 (edk::float32)color.g/255.f,
                                                 (edk::float32)color.b/255.f,
                                                 (edk::float32)color.a/255.f
                                                 );
                            //draw the vertexes
                            edk::GU::guVertex2f32(rectPixel.origin.x,rectPixel.origin.y);
                            edk::GU::guVertex2f32(rectPixel.origin.x,rectPixel.size.height);
                            edk::GU::guVertex2f32(rectPixel.size.width,rectPixel.size.height);
                            edk::GU::guVertex2f32(rectPixel.size.width,rectPixel.origin.y);


                            percentPixelX1 = percentPixelX2;
                            percentPixelX2+= incrementPixel;
                        }
                        percentPixelY1 = percentPixelY2;
                        percentPixelY2+= incrementPixel;
                    }
                }
                percentMapX1 = percentMapX2;
                percentMapX2+= incrementMapX;
            }
            percentMapY1 = percentMapY2;
            percentMapY2+= incrementMapY;
        }
        edk::GU::guEnd();


        //draw the lines
        edk::GU::guLineWidth(2u);
        edk::GU::guColor3f32(0.f,0.f,0.f);
        edk::GU::guBegin(GU_LINES);
        percentMapX1 = 0.f;
        for(edk::uint32 x=0u;x<=mapWidth;x++){
            rectTile.origin.x = ((this->rectFull.size.width - this->rectFull.origin.x)*percentMapX1) + this->rectFull.origin.x;
            edk::GU::guVertex2f32(rectTile.origin.x,this->rectFull.origin.y   );
            edk::GU::guVertex2f32(rectTile.origin.x,this->rectFull.size.height);

            percentMapX1+= incrementMapX;
        }
        percentMapY1 = 0.f;
        for(edk::uint32 y=0u;y<=mapHeight;y++){
            rectTile.origin.y = ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY1) + this->rectFull.origin.y;
            edk::GU::guVertex2f32(this->rectFull.origin.x   ,rectTile.origin.y);
            edk::GU::guVertex2f32(this->rectFull.size.width,rectTile.origin.y);

            percentMapY1+= incrementMapY;
        }
        edk::GU::guEnd();
        edk::GU::guLineWidth(1u);

    }

    //
    /*
    //draw the mouse pointer
    if(this->isMouseInside()){
        this->posMouse.drawPivo(this->camera.getSize().height*0.25f,
                                0.f,0.f,0.f);
    }
*/
}
void edk::retro::RetroViewMapEdit::drawSelectionScene(){
    if(this->tiles->size()){
        //
        edk::rectf32 rectTile;
        edk::uint32 id=0u;
        edk::uint32 mapWidth=this->map->getWidth(),mapHeight=this->map->getHeight();
        edk::float32 percentMapX1=0.f,percentMapX2=0.f,
                incrementMapX = 1.f/this->map->getWidth(),
                percentMapY1=0.f,percentMapY2=0.f,
                incrementMapY = 1.f/this->map->getHeight();

        percentMapY1 = 0.f;
        percentMapY2 = incrementMapY;
        edk::GU::guPushName(1u);
        for(edk::uint32 y=0u;y<mapHeight;y++){
            percentMapX1 = 0.f;
            percentMapX2 = incrementMapX;
            for(edk::uint32 x=0u;x<mapWidth;x++){
                id = this->map->getID(x,y);
                if(this->tiles->havePos(id)){
                    edk::GU::guPushName(id);
                    edk::GU::guBegin(GU_QUADS);

                    //draw the tile in the position
                    rectTile = edk::rectf32(((this->rectFull.size.width  - this->rectFull.origin.x)*percentMapX1) + this->rectFull.origin.x,
                                            ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY1) + this->rectFull.origin.y,
                                            ((this->rectFull.size.width  - this->rectFull.origin.x)*percentMapX2) + this->rectFull.origin.x,
                                            ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY2) + this->rectFull.origin.y
                                            );
                    edk::GU::guVertex2f32(rectTile.origin.x  ,rectTile.origin.y);
                    edk::GU::guVertex2f32(rectTile.origin.x  ,rectTile.size.height);
                    edk::GU::guVertex2f32(rectTile.size.width,rectTile.size.height);
                    edk::GU::guVertex2f32(rectTile.size.width,rectTile.origin.y);
                    edk::GU::guEnd();
                    edk::GU::guPopName();
                }
                percentMapX1 = percentMapX2;
                percentMapX2+= incrementMapX;
            }
            percentMapY1 = percentMapY2;
            percentMapY2+= incrementMapY;
        }
        edk::GU::guPopName();
    }
}
