#include "RetroViewTileSelect.h"

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

edk::Image2D edk::retro::RetroViewTileSelect::imgBack;
edk::uint32  edk::retro::RetroViewTileSelect::counterBack;
edk::uint32  edk::retro::RetroViewTileSelect::uvBack;
edk::retro::RetroPalettes edk::retro::RetroViewTileSelect::staticPalettes;
edk::uint32 edk::retro::RetroViewTileSelect::counterPalettes=0uL;
edk::retro::RetroTileSet edk::retro::RetroViewTileSelect::staticTiles;
edk::uint32 edk::retro::RetroViewTileSelect::counterTiles=0uL;
edk::retro::RetroTileMap edk::retro::RetroViewTileSelect::staticMap;
edk::uint32 edk::retro::RetroViewTileSelect::counterMap=0uL;

#define EditorBackImage "PixelEditorBackground.image"
#define EditorBackDark  0x55
#define EditorBackLight 0xAA
#define EditorBackground 0x33
#define editorZoomPercent 0.1f
#define editorWaitSelection 0.25f

#define EDK_VIEW_SCROLL_PERCENT 0.975f
#define EDK_VIEW_SCROLL_COLOR 0.5f

edk::retro::RetroViewTileSelect::RetroViewTileSelect(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroViewTileSelect::~RetroViewTileSelect(){
    this->Destructor();
}

void edk::retro::RetroViewTileSelect::Constructor(){
    edk::ViewGU2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->saveMousePressLeft = 0u;
        this->saveMousePressRight = 0u;
        this->saveMousePressMiddle = 0u;

        edk::retro::RetroViewTileSelect::imgBack.Constructor();
        edk::retro::RetroViewTileSelect::counterBack=0u;
        edk::retro::RetroViewTileSelect::uvBack=0u;


        if(!edk::retro::RetroViewTileSelect::counterBack){
            if(edk::retro::RetroViewTileSelect::imgBack.newImage(EditorBackImage,4u,4u,3u,1u)){
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(0u,0u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(1u,0u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(0u,1u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(1u,1u,EditorBackDark,EditorBackDark,EditorBackDark);

                edk::retro::RetroViewTileSelect::imgBack.drawPosition(2u,0u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(3u,0u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(2u,1u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(3u,1u,EditorBackLight,EditorBackLight,EditorBackLight);

                edk::retro::RetroViewTileSelect::imgBack.drawPosition(0u,2u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(1u,2u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(0u,3u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(1u,3u,EditorBackLight,EditorBackLight,EditorBackLight);

                edk::retro::RetroViewTileSelect::imgBack.drawPosition(2u,2u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(3u,2u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(2u,3u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewTileSelect::imgBack.drawPosition(3u,3u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::retro::RetroViewTileSelect::counterBack++;
            }
        }
        else{
            edk::retro::RetroViewTileSelect::counterBack++;
        }

        if(!edk::retro::RetroViewTileSelect::counterPalettes){
            edk::retro::RetroViewTileSelect::staticPalettes.Constructor();
        }
        edk::retro::RetroViewTileSelect::counterPalettes++;
        if(!edk::retro::RetroViewTileSelect::counterTiles){
            edk::retro::RetroViewTileSelect::staticTiles.Constructor();
        }
        edk::retro::RetroViewTileSelect::counterTiles++;
        if(!edk::retro::RetroViewTileSelect::counterMap){
            edk::retro::RetroViewTileSelect::staticMap.Constructor();
        }
        edk::retro::RetroViewTileSelect::counterMap++;

        this->setBackgroundUV(2u);

        this->sizeGrade = 1u;
        this->dontDrawGrade();

        this->saveSizeCamera = this->camera.getSize();
        this->zoomCamera = 1.f;

        this->animSelection.addFirstInterpolationLine(0.f,editorWaitSelection);

        this->saveSizeTiles = 0u;
        this->saveCutsMap = this->cutsMap = 3u;
        this->horizontalMap = false;
        this->zoomCamera = 1.f;
        this->saveSizeCamera = this->camera.getSize();
        this->scrollPrecision=0.f;

        this->saveSelectedID = this->selectedID=0xFFFFFFFF;


        this->setPalettes(NULL);
        this->setTilesSet(NULL);
        this->setMap(NULL);
    }
}
void edk::retro::RetroViewTileSelect::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

        if(edk::retro::RetroViewTileSelect::counterBack){
            edk::retro::RetroViewTileSelect::counterBack--;
            if(!edk::retro::RetroViewTileSelect::counterBack){
                edk::retro::RetroViewTileSelect::imgBack.deleteImage();
            }
        }
        if(edk::retro::RetroViewTileSelect::counterPalettes){
            edk::retro::RetroViewTileSelect::counterPalettes--;
            if(!edk::retro::RetroViewTileSelect::counterPalettes){
                edk::retro::RetroViewTileSelect::staticPalettes.Destructor();
            }
        }
        if(edk::retro::RetroViewTileSelect::counterTiles){
            edk::retro::RetroViewTileSelect::counterTiles--;
            if(!edk::retro::RetroViewTileSelect::counterTiles){
                edk::retro::RetroViewTileSelect::staticTiles.Destructor();
            }
        }
        if(edk::retro::RetroViewTileSelect::counterMap){
            edk::retro::RetroViewTileSelect::counterMap--;
            if(!edk::retro::RetroViewTileSelect::counterMap){
                edk::retro::RetroViewTileSelect::staticMap.Destructor();
            }
        }
    }
    edk::ViewGU2D::Destructor();
}

bool edk::retro::RetroViewTileSelect::setPalettes(edk::retro::RetroPalettes* palettes){
    if(palettes){
        this->palettes=palettes;
        return true;
    }
    this->palettes = &edk::retro::RetroViewTileSelect::staticPalettes;
    return false;
}
bool edk::retro::RetroViewTileSelect::setTilesSet(edk::retro::RetroTileSet* tiles){
    if(tiles){
        this->tiles=tiles;
        return true;
    }
    this->tiles = &edk::retro::RetroViewTileSelect::staticTiles;
    return false;
}
bool edk::retro::RetroViewTileSelect::setMap(edk::retro::RetroTileMap* map){
    if(map){
        this->map=map;
        return true;
    }
    this->map = &edk::retro::RetroViewTileSelect::staticMap;
    return false;
}

void edk::retro::RetroViewTileSelect::runUpdateViewSize(){
    //
    this->updateCamera();

    //update the scroll size
    if(this->horizontalMap){
        //
        this->scroll.frame.origin = edk::vec2f32(0.f,
                                                 this->frame.size.height * EDK_VIEW_SCROLL_PERCENT
                                                 );
        this->scroll.frame.size = edk::size2f32( this->frame.size.width,
                                                 this->frame.size.height - this->scroll.frame.origin.y
                                                 );
    }
    else{
        //
        this->scroll.frame.origin = edk::vec2f32(this->frame.size.width * EDK_VIEW_SCROLL_PERCENT,
                                                 0.f
                                                 );
        this->scroll.frame.size = edk::size2f32(this->frame.size.width - this->scroll.frame.origin.x,
                                                this->frame.size.height
                                                );
    }
}

//load the tiles from an image
bool edk::retro::RetroViewTileSelect::loadTilesFromImage(edk::Image2D* img){
    //
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
                        this->tiles->addTileEqualTest(tempTile);
                    }
                }

                ret = true;
            }
        }
        return ret;
    }
    return false;
}
bool edk::retro::RetroViewTileSelect::loadTilesFromImage(edk::char8* name){
    if(name){
        bool ret = false;
        edk::Image2D img;
        if(img.loadFromFile(name)){
            ret = this->loadTilesFromImage(&img);
            img.clean();
        }
        return ret;
    }
    return false;
}
bool edk::retro::RetroViewTileSelect::loadTilesFromImage(const edk::char8* name){
    return this->loadTilesFromImage((edk::char8*) name);
}

//select a tile
bool edk::retro::RetroViewTileSelect::selectTile(edk::uint32 id){
    if(this->tiles->havePos(id)){
        this->selectedID = id;
        return true;
    }
    this->selectedID=0xFFFFFFFF;
    return false;
}
void edk::retro::RetroViewTileSelect::unselectTile(){
    this->selectedID=0xFFFFFFFF;
}
bool edk::retro::RetroViewTileSelect::haveTileSelected(){
    if(this->tiles->havePos(this->selectedID)){
        return true;
    }
    return false;
}
bool edk::retro::RetroViewTileSelect::haveSelectTile(){
    if(this->saveSelectedID != this->selectedID){
        this->saveSelectedID = this->selectedID;
        return true;
    }
    return false;
}
edk::uint32 edk::retro::RetroViewTileSelect::getSelectedTile(){
    return this->selectedID;
}

//set draw grade
void edk::retro::RetroViewTileSelect::setDrawGrade(bool can){
    this->goDrawGrade = can;
}
void edk::retro::RetroViewTileSelect::canDrawGrade(){
    this->setDrawGrade(true);
}
void edk::retro::RetroViewTileSelect::cantDrawGrade(){
    this->setDrawGrade(false);
}
void edk::retro::RetroViewTileSelect::dontDrawGrade(){
    this->setDrawGrade(false);
}
void edk::retro::RetroViewTileSelect::setDrawPixelGrade(bool can){
    this->goDrawPixelGrade = can;
}
void edk::retro::RetroViewTileSelect::canDrawPixelGrade(){
    this->setDrawPixelGrade(true);
}
void edk::retro::RetroViewTileSelect::cantDrawPixelGrade(){
    this->setDrawPixelGrade(false);
}
void edk::retro::RetroViewTileSelect::dontDrawPixelGrade(){
    this->setDrawPixelGrade(false);
}

//SETTERS
bool edk::retro::RetroViewTileSelect::setBackgroundUV(edk::uint32 uv){
    if(uv>=2u){
        this->uvSize = uv;
        return true;
    }
    this->uvSize = 2u;
    return false;
}
//set the gradeSize
bool edk::retro::RetroViewTileSelect::setGradeSize(edk::size2ui32 size){
    if(size.width && size.height){
        this->sizeGrade = size;
    }
    return false;
}
bool edk::retro::RetroViewTileSelect::setGradeSize(edk::uint32 width,edk::uint32 height){
    return this->setGradeSize(edk::size2ui32(width,height));
}
//set the map cuts
bool edk::retro::RetroViewTileSelect::setMapCuts(edk::uint32 cuts){
    if(cuts){
        this->cutsMap = cuts;
        return true;
    }
    return false;
}
edk::uint32 edk::retro::RetroViewTileSelect::getMapCuts(){
    return this->cutsMap;
}
//set horizontal or vertical
void edk::retro::RetroViewTileSelect::setMapHorizontal(){
    this->horizontalMap = true;
}
void edk::retro::RetroViewTileSelect::setMapVertical(){
    this->horizontalMap = false;
}
bool edk::retro::RetroViewTileSelect::isMapHorizontal(){
    return this->horizontalMap;
}
bool edk::retro::RetroViewTileSelect::isMapVertical(){
    return !this->horizontalMap;
}

//update the camera size
void edk::retro::RetroViewTileSelect::updateCamera(){
    this->camera.setSize(this->frame.size.width,this->frame.size.height);
    this->saveSizeCamera = this->camera.getSize();

    /*
    //calculate the object inside the camera
    edk::rectf32 rect = this->camera.getRectPositionAndSize();
    rect = edk::Math::aspectRatioCorrect(rect,edk::size2f32(this->img.getWidth(),this->img.getHeight()));
    //rect.convertIntoPositionAndSize();
    this->objBack.size.width = rect.size.width;
    this->objBack.size.height = rect.size.height;

    //update the zoom
    this->saveSizeCamera = this->camera.getSize();
    */
    this->updateZoom();

    this->updateField();

}
void edk::retro::RetroViewTileSelect::updateZoom(){
    //calculate the zoom of the camera
    this->camera.setSize(this->saveSizeCamera.width * this->zoomCamera,
                         this->saveSizeCamera.height * this->zoomCamera
                         );
}
void edk::retro::RetroViewTileSelect::updateField(){
    //calculate the rectFull
    edk::float32 lenght;
    edk::float32 tileLenght;
    if(this->horizontalMap){
        //horizontal
        lenght = this->camera.getSize().height*EDK_VIEW_SCROLL_PERCENT;
        tileLenght = lenght/this->cutsMap;
        this->rectFull = edk::rectf32(0.f,0.f,
                                      tileLenght*this->map->getHeight(),lenght
                                      );
        this->scrollPrecision = ((edk::float32)this->map->getSize().height / (edk::float32)this->map->getSize().width)*0.1f;

    }
    else{
        //vertical
        lenght = this->camera.getSize().width*EDK_VIEW_SCROLL_PERCENT;
        tileLenght = lenght/this->cutsMap;
        this->rectFull = edk::rectf32(0.f,0.f,
                                      lenght,tileLenght*this->map->getHeight()
                                      );
        this->scrollPrecision = ((edk::float32)this->map->getSize().width / (edk::float32)this->map->getSize().height)*0.1f;
    }
    this->rectFull.convertIntoPoints();
    //invert Y
    edk::float32 tempChange = this->rectFull.origin.y;
    this->rectFull.origin.y = this->rectFull.size.height;
    this->rectFull.size.height = tempChange;

    //calculate the camera positions start and end
    if(this->horizontalMap){
        //test if the size is bigger
        edk::float32 tempY = ((this->rectFull.size.height - this->rectFull.origin.y)*0.5f)+this->rectFull.origin.y;
        edk::float32 module = this->rectFull.size.width - this->rectFull.origin.x;
        if(module>this->camera.getSize().width){
            this->rectPercentCamera = edk::rectf32(this->rectFull.origin.x + (this->camera.getSize().width*0.5f  ),tempY,
                                                   this->rectFull.size.width - (this->camera.getSize().width*0.5f),tempY
                                                   );
            //update scrollPercent
            module = this->camera.getSize().width / module;
            if(module<0.01f)module=0.01f;
            this->scroll.setForegroundSize(module,1.f);
            this->scroll.setPercentX(this->percentMoveCamera);
        }
        else{
            edk::float32 tempX = ((this->rectFull.size.width-this->rectFull.origin.x)*0.5f)+this->rectFull.origin.x;
            this->rectPercentCamera = edk::rectf32(tempX,tempY,
                                                   tempX,tempY
                                                   );
            //update scrollPercent
            this->scroll.setForegroundSize(1.f,1.f);
        }
    }
    else{
        //
        edk::float32 tempX = ((this->rectFull.size.width - this->rectFull.origin.x)*0.5f)+this->rectFull.origin.x;
        edk::float32 module = edk::Math::module(this->rectFull.size.height - this->rectFull.origin.y);
        if(module>this->camera.getSize().height){
            this->rectPercentCamera = edk::rectf32(tempX,this->rectFull.origin.y - (this->camera.getSize().height*0.5f),
                                                   tempX,this->rectFull.size.height + (this->camera.getSize().height*0.5f)
                                                   );
            //update scrollPercent
            module = this->camera.getSize().height / module;
            if(module<0.01f)module=0.01f;
            this->scroll.setForegroundSize(1.f,module);
            this->scroll.setPercentY(this->percentMoveCamera);
        }
        else{
            edk::float32 tempY = ((this->rectFull.size.height-this->rectFull.origin.y)*0.5f)+this->rectFull.origin.y;
            this->rectPercentCamera = edk::rectf32(tempX,tempY,
                                                   tempX,tempY
                                                   );
            //update scrollPercent
            this->scroll.setForegroundSize(1.f,1.f);
        }
    }
}
//process the selection
void edk::retro::RetroViewTileSelect::selectObject(edk::uint32 /*position*/,
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

void edk::retro::RetroViewTileSelect::resize(edk::rectf32 /*outsideViewOrigin*/){
}
void edk::retro::RetroViewTileSelect::load(edk::rectf32 /*outsideViewOrigin*/){
    this->saveMousePressLeft = 0u;
    this->saveMousePressRight = 0u;
    this->saveMousePressMiddle = 0u;

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
        mesh->material.setTextureFromMemory(&edk::retro::RetroViewTileSelect::imgBack,
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

    this->scroll.setFrontColor(EDK_VIEW_SCROLL_COLOR,
                               EDK_VIEW_SCROLL_COLOR,
                               EDK_VIEW_SCROLL_COLOR,
                               1.f);
    this->addSubview(&this->scroll);
}
void edk::retro::RetroViewTileSelect::unload(){
    this->removeAllSubview();
    this->objBack.clean();
}
//update the view
void edk::retro::RetroViewTileSelect::update(edk::WindowEvents* events){
    //update the view
    edk::View::update(events);

    this->animSelection.updateClockAnimation(events->secondPassed);

    //update the tileMap just to show tiles
    if(this->saveSizeTiles != this->tiles->getSize()
            || this->saveCutsMap != this->cutsMap
            ){
        //need update the tileMap
        this->saveSizeTiles = this->tiles->getSize();

        edk::uint32 width = 0u;
        edk::uint32 height = 0u;
        //create a new map
        if(this->horizontalMap){
            //
            width = this->tiles->getSize() / this->cutsMap;
            if(this->tiles->getSize() % this->cutsMap){
                width++;
            }
            height = this->cutsMap;
        }
        else{
            //
            width = this->cutsMap;
            height = this->tiles->getSize() / this->cutsMap;
            if(this->tiles->getSize() % this->cutsMap){
                height++;
            }
        }

        //
        if(this->map->newMap(width,height)){
            //copy the ids
            edk::uint32 id=0u;
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<width;x++){
                    this->map->setID(x,y,id);
                    id++;
                }
            }
        }

        this->percentMoveCamera=0.f;

        this->updateField();
    }



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
            if(this->isMouseInside() && !this->scroll.isMouseInside()){
                this->saveMousePressLeft=1u;
            }
            break;
        case edk::mouse::right:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            if(this->isMouseInside() && !this->scroll.isMouseInside()){
                this->saveMousePressRight=1u;
            }
            break;
        case edk::mouse::middle:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            if(this->isMouseInside() && !this->scroll.isMouseInside()){
                pressMouseMiddle=true;
                this->saveMousePressMiddle=1u;
            }
            break;
        }
    }
    size = events->mouseHolded.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mouseHolded.get(i)){
        case edk::mouse::left:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            if(this->saveMousePressLeft){
                this->saveMousePressLeft++;
                holdMouseLeft=true;
            }
            break;
        case edk::mouse::right:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            if(this->saveMousePressRight){
                this->saveMousePressRight++;
            }
            break;
        case edk::mouse::middle:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            if(this->saveMousePressMiddle){
                this->saveMousePressMiddle++;
                holdMouseMiddle=true;
            }
            break;
        }
    }
    size = events->mouseRelease.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mouseRelease.get(i)){
        case edk::mouse::left:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            this->saveMousePressLeft=0u;
            break;
        case edk::mouse::right:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            this->saveMousePressRight=0u;
            break;
        case edk::mouse::middle:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            this->saveMousePressMiddle=0u;
            break;
        }
    }
    if(this->saveMousePressLeft)this->saveMousePressLeft--;
    if(this->saveMousePressRight)this->saveMousePressRight--;
    if(this->saveMousePressMiddle)this->saveMousePressMiddle--;

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
                //this->camera.position.x += this->camera.getSize().width * 0.1f * events->mouseScrollWheelHorizontal
                //        * -1.f
                //        ;

                if(this->horizontalMap){
                    this->percentMoveCamera += this->scrollPrecision * events->mouseScrollWheelHorizontal * -1.f;

                    if(this->percentMoveCamera<0.f){
                        this->percentMoveCamera=0.f;
                    }
                    if(this->percentMoveCamera>1.f){
                        this->percentMoveCamera=1.f;
                    }
                    this->scroll.setPercentX(this->percentMoveCamera);
                }
            }
        }
        if(events->mouseScrollWheelVertical){
            if(holdControl){
                /*
                //run the camera zoom
                this->zoomCamera += editorZoomPercent * events->mouseScrollWheelVertical
                        * -1.f
                        ;
                if(this->zoomCamera<0.01f){
                    this->zoomCamera = 0.01f;
                }
                //update the zoom
                this->updateZoom();
                */
            }
            else{
                //this->camera.position.y += this->camera.getSize().height * 0.1f * events->mouseScrollWheelVertical;

                if(!this->horizontalMap){
                    this->percentMoveCamera += this->scrollPrecision * events->mouseScrollWheelVertical * -1;

                    if(this->percentMoveCamera<0.f){
                        this->percentMoveCamera=0.f;
                    }
                    if(this->percentMoveCamera>1.f){
                        this->percentMoveCamera=1.f;
                    }
                    this->scroll.setPercentY(this->percentMoveCamera);
                }
            }
        }
        //process the zoom
        if(pressZoomIn){
            /*
            this->zoomCamera -= editorZoomPercent * 2.f;

            if(this->zoomCamera<0.01f){
                this->zoomCamera = 0.01f;
            }
            //update the zoom
            this->updateZoom();
            */
        }
        if(pressZoomDout){
            /*
            this->zoomCamera += editorZoomPercent * 2.f;
            //update the zoom
            this->updateZoom();
            */
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
                    //this->camera.position.x -= distance.x;
                    //this->camera.position.y += distance.y;
                    //this->updateZoom();
                }
            }
        }
    }


    //test the scroll
    if(this->horizontalMap){
        //
        if(!edk::Math::equal(this->percentMoveCamera,this->scroll.getPercentX())){
            this->percentMoveCamera = this->scroll.getPercentX();
        }
    }
    else{
        if(!edk::Math::equal(this->percentMoveCamera,this->scroll.getPercentY())){
            this->percentMoveCamera = this->scroll.getPercentY();
        }
    }

    //move the camera to the point
    if(this->horizontalMap){
        //X
        this->camera.position.x = ((this->rectPercentCamera.size.width - this->rectPercentCamera.origin.x)
                                   * this->percentMoveCamera)
                + this->rectPercentCamera.origin.x
                ;
        this->camera.position.y=this->rectPercentCamera.origin.y
                + (this->camera.getSize().height*(1.f-EDK_VIEW_SCROLL_PERCENT)*0.5f);
    }
    else{
        //Y
        this->camera.position.y = ((this->rectPercentCamera.size.height - this->rectPercentCamera.origin.y)
                                   * this->percentMoveCamera)
                + this->rectPercentCamera.origin.y
                ;
        this->camera.position.x=this->rectPercentCamera.origin.x
                + (this->camera.getSize().width*(1.f-EDK_VIEW_SCROLL_PERCENT)*0.5f);
    }
}
void edk::retro::RetroViewTileSelect::drawScene(edk::rectf32 /*outsideViewOrigin*/){
    //
    //test if need change the uv
    if(edk::retro::RetroViewTileSelect::uvBack!=this->uvSize){
        edk::retro::RetroViewTileSelect::uvBack=this->uvSize;
        //change the polygon UV
        edk::shape::Mesh2D* mesh = this->objBack.getMesh(0u);
        if(mesh){
            mesh->selectPolygon(0u);
            mesh->selectedSetVertexUV(1u,
                                      edk::retro::RetroViewTileSelect::uvBack*0.5f,
                                      edk::retro::RetroViewTileSelect::uvBack*0.5f
                                      );
        }
    }
    if(this->tiles->size()){
        this->objBack.size = this->camera.getSize();
        this->objBack.position = this->camera.position;
        this->objBack.draw();
        //
        edk::rectf32 rectTile;
        edk::rectf32 rectPixel;


        edk::retro::RetroTile temp;
        edk::uint32 id=0u;
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
                id = this->map->getID(x,y);
                if(this->tiles->havePos(id)){
                    temp = this->tiles->get(id);


                    //draw the tile in the position
                    rectTile = edk::rectf32(((this->rectFull.size.width -  this->rectFull.origin.x)*percentMapX1) + this->rectFull.origin.x,
                                            ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY1) + this->rectFull.origin.y,
                                            ((this->rectFull.size.width -  this->rectFull.origin.x)*percentMapX2) + this->rectFull.origin.x,
                                            ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY2) + this->rectFull.origin.y
                                            );

                    //invert Y
                    //edk::float32 tempChange = rectTile.origin.y;
                    //rectTile.origin.y = rectTile.size.height;
                    //rectTile.size.height = tempChange;

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

        //draw the selected tile
        if(this->haveTileSelected()){
            //
            edk::uint32 sX = this->selectedID % this->cutsMap,
                    sY = this->selectedID / this->cutsMap;
            percentMapX1 = incrementMapX*sX;
            percentMapX2 = percentMapX1 + incrementMapX;
            percentMapY1 = incrementMapY*sY;
            percentMapY2 = percentMapY1 + incrementMapY;
            edk::GU::guLineWidth(4u);
            edk::GU::guColor3f32(0.f,1.f,0.f);
            edk::GU::guBegin(GU_LINE_STRIP);


            rectTile = edk::rectf32(((this->rectFull.size.width -  this->rectFull.origin.x)*percentMapX1) + this->rectFull.origin.x,
                                    ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY1) + this->rectFull.origin.y,
                                    ((this->rectFull.size.width -  this->rectFull.origin.x)*percentMapX2) + this->rectFull.origin.x,
                                    ((this->rectFull.size.height - this->rectFull.origin.y)*percentMapY2) + this->rectFull.origin.y
                                    );

            edk::GU::guVertex2f32(rectTile.origin.x,rectTile.origin.y);
            edk::GU::guVertex2f32(rectTile.size.width,rectTile.origin.y);
            edk::GU::guVertex2f32(rectTile.size.width,rectTile.size.height);
            edk::GU::guVertex2f32(rectTile.origin.x,rectTile.size.height);
            edk::GU::guVertex2f32(rectTile.origin.x,rectTile.origin.y);
            edk::GU::guEnd();
            edk::GU::guLineWidth(1u);
            edkEnd();
        }
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
void edk::retro::RetroViewTileSelect::drawSelectionScene(){
    //

    if(this->tiles->size()){
        this->objBack.size = this->camera.getSize();
        this->objBack.position = this->camera.position;
        this->objBack.draw();
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
