#ifndef VIEWLISTSELECTION_H
#define VIEWLISTSELECTION_H

/*
Library C++ ViewListSelection - Show a list of cell's to be selected
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
#warning "Inside ViewListSelection"
#endif

#pragma once
#include "ViewGU2D.h"
#include "ViewScrollBar.h"
#include "fonts/FontMap.h"
#include "vector/Stack.h"
#include "shape/Rectangle2D.h"

#ifdef printMessages
#warning "    Compiling ViewListSelection"
#endif

namespace edk{
class ViewListSelection : public edk::ViewGU2D{
public:
    ViewListSelection();
    ~ViewListSelection();

    //Events
    void eventMousePressed(edk::vec2f32 point,edk::uint32 button);

    void update(edk::WindowEvents* events);

    //set camera Size
    void setCameraSize(edk::size2ui32 size);
    void setCameraSize(edk::uint32 width,edk::uint32 height);

    //add a cell
    bool addCell(const char* name,edk::color4f32 cellColor = edk::color4f32(1,1,1,1));
    bool addCell(edk::char8* name,edk::color4f32 cellColor = edk::color4f32(1,1,1,1));
    //remove a cell
    bool removeCell(edk::uint32 position);
    //clean the cells
    void cleanCells();
    //return the cell size
    edk::uint32 getCellSize();

    //draw the GU scene
    void drawScene(edk::rectf32 outsideViewOrigin);

    void drawSelectionScene();
    //process the selection
    void selectObject(edk::uint32 position,edk::uint32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);
private:
    //cameraSize
    edk::uint32 cameraWidth;
    edk::uint32 cameraHeight;
    //save frame
    edk::rectf32 saveFrame;
    //scrollBar
    edk::ViewScrollBar scroll;

    //update the cells position
    void updateCellPosition();
    //test the scroll
    void testScroll();

    //create a cell
    class ListCell{
    public:
        ListCell(edk::uint32* lineSize=NULL);
        ~ListCell();

        //create the text
        bool createText(edk::char8* text);
        //delete the text
        void cleanText();
        //get textSize
        edk::uint32 getTextWidth();
        //select the cell
        bool select();
        //return true if the cell is celected;
        bool isSelected();
        //draw the cell
        void draw();
        //draw for selection
        void drawSelection();
        //set position
        void setPosition(edk::float32 y);

        //background color
        edk::color4f32 backgroundColor;
        //background color selected
        edk::color4f32 backgroundColorSelected;
    private:
        //color to draw
        edk::color4f32 drawColor;
        //cell text
        edk::fonts::FontMap text;
        bool selected;
        edk::uint32* lineSize;
        edk::uint32 sizeTemp;

        //draw the rectangle
        void drawRect();
    };
    //stack to put the cells
    edk::vector::Stack<edk::ViewListSelection::ListCell*> cells;
};
}

#endif // VIEWLISTSELECTION_H
