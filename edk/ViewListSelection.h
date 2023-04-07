#ifndef VIEWLISTSELECTION_H
#define VIEWLISTSELECTION_H

/*
Library C++ ViewListSelection - Show a list of cell's to be selected
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
#pragma message "Inside ViewListSelection"
#endif

#pragma once
#include "ViewGU2D.h"
#include "ViewScrollBar.h"
#include "fonts/FontMap.h"
#include "vector/Stack.h"
#include "shape/Rectangle2D.h"

#ifdef printMessages
#pragma message "    Compiling ViewListSelection"
#endif

namespace edk{
class ViewListSelection : public edk::ViewGU2D{
public:
    ViewListSelection();
    ~ViewListSelection();

    //Events
    void eventMousePressed(edk::vec2f32 point,edk::uint32 button);
    //Mouse go Inside Outside
    void eventMouseEntryInsideView(edk::vec2f32 point);
    void eventMouseLeftView(edk::vec2f32 point);

    //unload the mouseInside
    void unload();

    void update(edk::WindowEvents* events);

    //return true if the mouse is inside
    bool isMouseInside();

    //set move scroll percent
    bool setMoveScrollPercent(edk::float32 moveScroll);

    //set camera Size
    void setCameraSize(edk::size2ui32 size);
    void setCameraSize(edk::uint32 width,edk::uint32 height);

    //set color
    void setScrollBackColor(edk::color4f32 color);
    void setScrollBackColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setScrollFrontColor(edk::color4f32 color);
    void setScrollFrontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

    //add a cell
    edk::uint32 addCell(const edk::char8* name,edk::uint32 id=0u,edk::color4f32 cellColor = edk::color4f32(1,1,1,1));
    edk::uint32 addCell(edk::char8* name,edk::uint32 id=0u,edk::color4f32 cellColor = edk::color4f32(1,1,1,1));
    //set cell string
    bool setCellString(edk::uint32 position,const edk::char8* string);
    bool setCellString(edk::uint32 position,edk::char8* string);
    //set the cellID
    bool setCellID(edk::uint32 position,edk::uint32 id);
    //remove a cell
    bool removeCell(edk::uint32 position);
    //clean the cells
    void cleanCells();
    //return the cell size
    edk::uint32 getCellSize();
    //return true if have the cell
    bool haveCell(edk::uint32 position);
    //return the cell ID
    edk::uint32 getCellID(edk::uint32 position);
    //test if the cell is showing
    bool isCellShowing(edk::uint32 position);
    //set the cell show
    bool setCellShow(edk::uint32 position,bool show);
    //show all cells
    void showAllCells();
    void hideAllCells();
    //test if the cell is selecting
    bool isCellSelecting(edk::uint32 position);
    //set the cell select
    bool setCellCanSelect(edk::uint32 position,bool select);
    //select all cells
    void canSelectAllCells();
    void cantSelectAllCells();
    //get cell clicked
    bool haveClickCell();
    //return the cell click position
    edk::uint32 getClickPosition();
    //test if have clicled one button
    bool haveClickedButton(edk::uint32 button);
    bool haveClickedLeftButton();
    bool haveClickedRightButton();
    bool haveClickedMiddleButton();
    //clean the mouseButtons
    void cleanClickedButtons();

    //get the scroll percent
    edk::float32 getScrollPercent();
    bool setScrollPercent(edk::float32 percent);

    //draw the GU scene
    void drawScene(edk::rectf32 outsideViewOrigin);

    void drawSelectionScene();
    //process the selection
    void selectObject(edk::uint32 position,edk::int32 objects,edk::float32 near,edk::float32 far,edk::vector::Stack<edk::uint32>* names);
private:
    //cameraSize
    edk::uint32 cameraWidth;
    edk::uint32 cameraHeight;
    //save frame
    edk::rectf32 saveFrame;
    //scrollBar
    edk::ViewScrollBar scroll;
    //move with the mouseScroll
    edk::float32 moveScroll;
    //mouse buttons clicked
    edk::vector::BinaryTree<edk::uint8> mouseButtons;
    edk::vector::BinaryTree<edk::uint8> mouseButtonsNew;
    bool clickLeft;

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
        //show the cell
        bool show();
        void setShow(bool set);
        //return true if the cell is showing;
        bool isShowing();
        //canSelect the cell
        bool canSelect();
        void setCanSelect(bool set);
        //return true if the cell can select
        bool isSelecting();
        //draw the cell
        void draw();
        //draw for selection
        void drawSelection();
        //set position
        void setPosition(edk::float32 y);

        //background color
        edk::color4f32 backgroundColor;
        //background color showing
        edk::color4f32 backgroundColorShowing;
        //text color
        edk::color4f32 textColor;
        //text color selecting
        edk::color4f32 textColorSelecting;
        //ID
        edk::uint32 id;
    private:
        //color to draw
        edk::color4f32 drawColor;
        //cell text
        edk::fonts::FontMap text;
        bool showing;
        bool selecting;
        edk::uint32* lineSize;
        edk::uint32 sizeTemp;

        //draw the rectangle
        void drawRect();
    };
    //stack to put the cells
    edk::vector::Stack<edk::ViewListSelection::ListCell*> cells;
    //save the last clicked
    edk::ViewListSelection::ListCell* clicked;
    edk::uint32 clickedPosition;
};
}

#endif // VIEWLISTSELECTION_H
