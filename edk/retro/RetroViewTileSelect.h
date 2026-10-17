#ifndef RETROVIEWTILESELECT_H
#define RETROVIEWTILESELECT_H

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
#pragma message "Inside RetroViewTileSelect"
#endif

#pragma once
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../ViewGU2D.h"
#include "../vector/BinaryTree.h"
#include "../Camera2D.h"
#include "../fonts/FontMap.h"
#include "../pack/FilePackage.h"
#include "../animation/Interpolation1DGroup.h"
#include "../ViewScrollBar.h"
#include "RetroPalette.h"
#include "RetroPalettes.h"
#include "RetroTile.h"
#include "RetroTileSet.h"
#include "RetroTileMap.h"

#ifdef printMessages
#pragma message "    Compiling RetroViewTileSelect"
#endif

namespace edk{
namespace retro{
class RetroViewTileSelect: public edk::ViewGU2D{
public:
    RetroViewTileSelect();
    ~RetroViewTileSelect();

    void Constructor();
    void Destructor();

    bool setPalettes(edk::retro::RetroPalettes* palettes);
    bool setTilesSet(edk::retro::RetroTileSet* tiles);
    bool setMap(edk::retro::RetroTileMap* map);

    void runUpdateViewSize();

    //load the tiles from an image
    bool loadTilesFromImage(edk::Image2D* img);
    bool loadTilesFromImage(edk::char8* name);
    bool loadTilesFromImage(const edk::char8* name);

    //select a tile
    bool selectTile(edk::uint32 id);
    void unselectTile();
    inline void deselectTile(){
        this->unselectTile();
    }
    bool haveTileSelected();
    bool haveSelectTile();
    inline bool didSelectTile(){
        return this->haveSelectTile();
    }
    edk::uint32 getSelectedTile();

    //set draw grade
    void setDrawGrade(bool can);
    void canDrawGrade();
    void cantDrawGrade();
    void dontDrawGrade();
    void setDrawPixelGrade(bool can);
    void canDrawPixelGrade();
    void cantDrawPixelGrade();
    void dontDrawPixelGrade();

    //SETTERS
    bool setBackgroundUV(edk::uint32 uv);
    //set the gradeSize
    bool setGradeSize(edk::size2ui32 size);
    bool setGradeSize(edk::uint32 width,edk::uint32 height);
    //set the map cuts
    bool setMapCuts(edk::uint32 cuts);
    edk::uint32 getMapCuts();
    //set horizontal or vertical
    void setMapHorizontal();
    void setMapVertical();
    bool isMapHorizontal();
    bool isMapVertical();
private:
    //update the camera size
    void updateCamera();
    void updateZoom();
    void updateField();
    //process the selection
    void selectObject(edk::uint32 position,edk::int32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);

    void resize(edk::rectf32 outsideViewOrigin);
    void load(edk::rectf32 outsideViewOrigin);
    void unload();
    //update the view
    void update(edk::WindowEvents* events);
    void drawScene(edk::rectf32 outsideViewOrigin);
    void drawSelectionScene();

    //mouse press
    edk::uint8 saveMousePressLeft,saveMousePressRight,saveMousePressMiddle;

    //View scrollBar in the right
    edk::ViewScrollBar scroll;

    //tile selected
    edk::uint32 selectedID;
    edk::uint32 saveSelectedID;

    //save the camera size to calculate the zoom
    edk::size2f32 saveSizeCamera;
    edk::float32 zoomCamera;
    edk::Object2D posMouse;
    edk::vec2f32 savePosMouse;
    edk::float32 distanceMouse;
    edk::vec2f32 savePosMouseSelect;
    edk::animation::Interpolation1DGroup animSelection;
    //edk::vec2f32 posCamera;
    edk::animation::Interpolation2DGroup animCenterCamera;

    //save the screen to set the camera automatically
    edk::rectf32 saveFrame;
    //
    edk::rectf32 rectImg;
    edk::Object2D objBack;
    edk::uint32 uvSize;
    edk::size2ui32 sizeGrade;
    edk::rectf32 rectFull;
    edk::rectf32 rectPercentCamera;
    edk::float32 percentMoveCamera;
    edk::float32 scrollPrecision;

    static edk::Image2D imgBack;
    static edk::uint32 counterBack;
    static edk::uint32 uvBack;

    //can draw grade
    bool goDrawGrade;
    bool goDrawPixelGrade;

    edk::retro::RetroPalettes* palettes;
    static edk::retro::RetroPalettes staticPalettes;
    static edk::uint32 counterPalettes;

    //TILES
    edk::retro::RetroTileSet* tiles;
    static edk::retro::RetroTileSet staticTiles;
    static edk::uint32 counterTiles;

    //MAP
    edk::retro::RetroTileMap* map;
    static edk::retro::RetroTileMap staticMap;
    static edk::uint32 counterMap;

    edk::uint32 saveSizeTiles;
    edk::uint32 cutsMap;
    edk::uint32 saveCutsMap;
    bool horizontalMap;
private:
    edk::classID classThis;
};
}//end namespace retro
}//end namespace edk

#endif // RETROVIEWTILESELECT_H
