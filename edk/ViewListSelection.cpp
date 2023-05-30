#include "ViewListSelection.h"

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
#pragma message "            Inside ViewListSelection.cpp"
#endif

edk::ViewListSelection::ListCell::ListCell(edk::uint32* lineSize){
    //
    this->showing = false;edkEnd();
    if(lineSize){
        this->lineSize = lineSize;edkEnd();
    }
    else{
        this->lineSize = &this->sizeTemp;edkEnd();
    }
    this->drawColor = this->backgroundColor;edkEnd();
    this->backgroundColorShowing = edk::color4f32(0.75f,0.75f,1.0f,1.f);edkEnd();
    this->id = 0u;edkEnd();

    //text color
    this->textColor = edk::color4f32(0.0f,0.0f,0.0f,1.f);edkEnd();
    //text color selecting
    this->textColorSelecting = edk::color4f32(0.5f,0.5f,0.5f,1.f);edkEnd();

    this->showing=true;
    this->selecting=true;
    //set if the cell are selected
    this->selected=false;

    //set the text to black color
    this->text.setColor(0.f,0.f,0.f,1.f);edkEnd();
}
edk::ViewListSelection::ListCell::~ListCell(){
    this->lineSize = &this->sizeTemp;edkEnd();
    this->cleanText();edkEnd();
}

//draw the rectangle
void edk::ViewListSelection::ListCell::drawRect(){
    //draw a rectangle in the text position and size
    edk::GU::guBegin(GU_QUADS);edkEnd();
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f),(this->text.getPositionY()-0.5f));edkEnd();
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f)+*this->lineSize,(this->text.getPositionY()-0.5f));edkEnd();
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f)+*this->lineSize,(this->text.getPositionY()-0.5f)+1);edkEnd();
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f),(this->text.getPositionY()-0.5f)+1);edkEnd();
    edk::GU::guEnd();edkEnd();
}
void edk::ViewListSelection::ListCell::drawLines(){
    //draw a wired rectangle in the text position and size
    edk::GU::guBegin(GU_LINE_STRIP);edkEnd();
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f),(this->text.getPositionY()-0.5f));edkEnd();
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f)+*this->lineSize,(this->text.getPositionY()-0.5f));edkEnd();
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f)+*this->lineSize,(this->text.getPositionY()-0.5f)+1);edkEnd();
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f),(this->text.getPositionY()-0.5f)+1);edkEnd();
    edk::GU::guEnd();edkEnd();
}

//create the text
bool edk::ViewListSelection::ListCell::createText(edk::char8* text){
    //
    if(this->text.createStringMap(text)){
        this->sizeTemp = (edk::float32)this->text.getMapSizeWidth();edkEnd();
        return true;
    }
    return false;
}
//delete the text
void edk::ViewListSelection::ListCell::cleanText(){
    this->text.deleteMap();edkEnd();
    this->showing = false;edkEnd();
    this->sizeTemp=0.f;edkEnd();
}
//get textSize
edk::uint32 edk::ViewListSelection::ListCell::getTextWidth(){
    return this->sizeTemp;edkEnd();
}
//show the cell
bool edk::ViewListSelection::ListCell::show(){
    this->showing = !this->showing;edkEnd();
    if(this->showing){
        this->drawColor = this->backgroundColorShowing;edkEnd();
        return true;
    }
    this->drawColor = this->backgroundColor;edkEnd();
    return false;
}
void edk::ViewListSelection::ListCell::setShow(bool set){
    this->showing = set;edkEnd();
    if(this->showing){
        this->drawColor = this->backgroundColorShowing;edkEnd();
    }
    else{
        this->drawColor = this->backgroundColor;edkEnd();
    }
}

//return true if the cell is showing
bool edk::ViewListSelection::ListCell::isShowing(){
    return this->showing;edkEnd();
}
//canSelect the cell
bool edk::ViewListSelection::ListCell::canSelect(){
    this->selecting = !this->selecting;edkEnd();
    if(this->selecting){
        this->text.setColor(this->textColor);edkEnd();
        return true;
    }
    this->text.setColor(this->textColorSelecting);edkEnd();
    return false;
}
void edk::ViewListSelection::ListCell::setCanSelect(bool set){
    this->selecting = set;edkEnd();
    if(this->selecting){
        this->text.setColor(this->textColor);edkEnd();
    }
    else{
        this->text.setColor(this->textColorSelecting);edkEnd();
    }
}
//return true if the cell can select
bool edk::ViewListSelection::ListCell::isSelecting(){
    return this->selecting;edkEnd();
}
//select the cell in the list
bool edk::ViewListSelection::ListCell::isSelectedCell(){
    return this->selected;
}
bool edk::ViewListSelection::ListCell::selectCell(){
    bool ret = !this->selected;
    this->setSelectCell(true);
    return ret;
}
bool edk::ViewListSelection::ListCell::unSelectCell(){
    bool ret = this->selected;
    this->setSelectCell(false);
    return ret;
}
void edk::ViewListSelection::ListCell::setSelectCell(bool selected){
    this->selected=selected;edkEnd();
}
//draw the cell
void edk::ViewListSelection::ListCell::draw(){
    edk::GU::guColor4f32(this->drawColor);edkEnd();
    this->drawRect();edkEnd();
    this->text.draw();edkEnd();
}
//draw for selection
void edk::ViewListSelection::ListCell::drawSelection(){
    edk::GU::guColor4f32(1,1,1,1);edkEnd();
    this->drawRect();edkEnd();
}
//draw in wireMode
void edk::ViewListSelection::ListCell::drawWire(){
    edk::GU::guColor4f32(0,0,0,1);edkEnd();
    this->drawLines();edkEnd();
}
//set position
void edk::ViewListSelection::ListCell::setPosition(edk::float32 y){
    this->text.setPosition(0.f,y);edkEnd();
}

edk::ViewListSelection::ViewListSelection(){
    //cameraSize
    this->cameraWidth=1u;edkEnd();
    this->cameraHeight=1u;edkEnd();
    this->moveScroll = 0.1f;edkEnd();
    this->clicked = NULL;edkEnd();
    this->clickedPosition=0u;
}
edk::ViewListSelection::~ViewListSelection(){
    //
    this->cleanCells();edkEnd();
}

//update the cells position
void edk::ViewListSelection::updateCellPosition(){
    //clean all the cells
    edk::uint32 size = this->cells.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //move the cell to the position in the world
        this->cells.get(i)->setPosition(i*-1.f);edkEnd();
    }
}
//test the scroll
void edk::ViewListSelection::testScroll(){
    //test if need have scroll
    if(this->cells.getSize()>this->cameraHeight){
        if(!this->getCount()){
            //add the scroll
            this->addSubview(&this->scroll);edkEnd();
        }

        //set the insideSize
        if(this->cells.size()){
            this->scroll.setForegroundSize(1.f,(edk::float32)this->cameraHeight / (edk::float32)this->cells.size());edkEnd();
        }
        else{
            this->scroll.setForegroundSize(1.f,1.f);edkEnd();
        }
    }
    else{
        //remove the view
        if(this->getCount()){
            //remove the subview
            this->removeSubview(&this->scroll);edkEnd();
            this->scroll.setPercentY(0.f);edkEnd();
        }
    }
}

//Events
void edk::ViewListSelection::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    if(button){
        this->testSelection(point);edkEnd();
        //save the mouseButton
        this->mouseButtonsNew.add(button);edkEnd();
        if(button == edk::mouse::left){
            this->clickLeft = true;edkEnd();
        }
    }
}
//Mouse go Inside Outside
void edk::ViewListSelection::eventMouseEntryInsideView(edk::vec2f32){
    //
}
void edk::ViewListSelection::eventMouseLeftView(edk::vec2f32){
    //
}

//unload the mouseInside
void edk::ViewListSelection::unload(){
    this->mouseInside = false;edkEnd();
    this->scroll.mouseInside = false;edkEnd();
}

void edk::ViewListSelection::update(edk::WindowEvents* events){
    if(this->saveFrame!=this->frame){
        this->saveFrame=this->frame;edkEnd();
        //update the scroll
        this->scroll.frame = edk::rectf32(this->frame.size.width - 20.f,
                                          0.f,
                                          20.f,
                                          this->frame.size.height
                                          );edkEnd();
    }
    this->camera.setRect(-0.5f,-0.5f,this->cameraWidth,this->cameraHeight);edkEnd();
    this->camera.position.y-=(this->camera.getSize().height-1.f);edkEnd();
    //move the percent
    this->camera.position.y-= (this->cells.size() - this->camera.getSize().height) * this->scroll.getPercentY();edkEnd();

    //move the mouseScroll
    //if(this->pointInside(edk::vec2f32(events->mousePos.x,events->mousePos.y))){
    if(this->isMouseInside()){
        this->scroll.setPercentY(this->scroll.getPercentY() + (events->mouseScrollWheel * this->moveScroll * -1));edkEnd();
    }
}

//return true if the mouse is inside
bool edk::ViewListSelection::isMouseInside(){
    if(edk::View::isMouseInside() || this->scroll.isMouseInside()){
        return true;
    }
    return false;
}

//set move scroll percent
bool edk::ViewListSelection::setMoveScrollPercent(edk::float32 moveScroll){
    if(moveScroll>=0.f){
        if(moveScroll<=1.f){
            //
            this->moveScroll = moveScroll;edkEnd();
            return true;
        }
        else{
            this->moveScroll = 1.f;edkEnd();
        }
    }
    else{
        this->moveScroll = 0.f;edkEnd();
    }
    return false;
}

//set camera Size
void edk::ViewListSelection::setCameraSize(edk::size2ui32 size){
    this->setCameraSize(size.width,size.height);edkEnd();
}
void edk::ViewListSelection::setCameraSize(edk::uint32 width,edk::uint32 height){
    this->cameraWidth = 1u;edkEnd();
    this->cameraHeight = 1u;edkEnd();
    if(width){
        this->cameraWidth = width;edkEnd();
    }
    if(height){
        this->cameraHeight= height;edkEnd();
    }
    this->testScroll();edkEnd();
}

//set color
void edk::ViewListSelection::setScrollBackColor(edk::color4f32 color){
    this->scroll.setBackColor(color);edkEnd();
}
void edk::ViewListSelection::setScrollBackColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setScrollBackColor(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::ViewListSelection::setScrollFrontColor(edk::color4f32 color){
    this->scroll.setFrontColor(color);edkEnd();
}
void edk::ViewListSelection::setScrollFrontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setScrollFrontColor(edk::color4f32(r,g,b,a));edkEnd();
}

//add a cell
edk::uint32 edk::ViewListSelection::addCell(const edk::char8* name,edk::uint32 id,edk::color4f32 cellColor){
    return this->addCell((edk::char8*) name,id,cellColor);edkEnd();
}
edk::uint32 edk::ViewListSelection::addCell(edk::char8* name,edk::uint32 id,edk::color4f32 cellColor){
    if(name){
        //create the new cell
        edk::ViewListSelection::ListCell* cell = new edk::ViewListSelection::ListCell(&this->cameraWidth);edkEnd();
        if(cell){
            //set the cell text
            if(cell->createText(name)){
                //set the cell color
                cell->backgroundColor = cellColor;edkEnd();
                cell->setShow(false);edkEnd();
                edk::uint32 size = this->cells.size();edkEnd();
                //add the cell to the stack
                edk::uint32 position = this->cells.pushBack(cell);edkEnd();
                this->testScroll();edkEnd();
                if(this->cells.size()>size){
                    //move the cell to the position
                    cell->setPosition(position*-1.f);edkEnd();
                    cell->id = id;edkEnd();
                    return size;edkEnd();
                }
            }
            //else delete the cell
            delete cell;edkEnd();
        }
    }
    return 0u;edkEnd();
}
//set cell string
bool edk::ViewListSelection::setCellString(edk::uint32 position,const edk::char8* string){
    return this->setCellString(position,(edk::char8*) string);edkEnd();
}
bool edk::ViewListSelection::setCellString(edk::uint32 position,edk::char8* string){
    edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
    if(cell){
        return cell->createText(string);edkEnd();
    }
    return false;
}
//set the cellID
bool edk::ViewListSelection::setCellID(edk::uint32 position,edk::uint32 id){
    edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
    if(cell){
        cell->id = id;edkEnd();
        return true;
    }
    return false;
}
//remove a cell
bool edk::ViewListSelection::removeCell(edk::uint32 position){
    //test if have the cell
    if(position<this->cells.size()){
        //get the cell
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            //move the the end
            this->cells.bringPositionTo(position,this->cells.size()-1u);edkEnd();
            //popBack
            this->cells.popBack();edkEnd();
            //delete cell
            delete cell;edkEnd();
            //update the cells Position
            this->updateCellPosition();edkEnd();
            this->testScroll();edkEnd();
            return true;
        }
    }
    return false;
}
//clean the cells
void edk::ViewListSelection::cleanCells(){
    //clean all the cells
    edk::uint32 size = this->cells.size();edkEnd();
    edk::ViewListSelection::ListCell* cell;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        cell = this->cells.get(i);edkEnd();
        if(cell){
            delete cell;edkEnd();
        }
    }
    this->cells.clean();edkEnd();
    this->testScroll();edkEnd();
}
//return the cell size
edk::uint32 edk::ViewListSelection::getCellSize(){
    return this->cells.size();edkEnd();
}
//return true if have the cell
bool edk::ViewListSelection::haveCell(edk::uint32 position){
    if(position < this->cells.size()){
        return (bool)this->cells.get(position);edkEnd();
    }
    return false;
}
//return the cell ID
edk::uint32 edk::ViewListSelection::getCellID(edk::uint32 position){
    if(position < this->cells.size()){
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            return cell->id;edkEnd();
        }
    }
    return 0u;edkEnd();
}
//test if the cell is showing
bool edk::ViewListSelection::isCellShowing(edk::uint32 position){
    if(position < this->cells.size()){
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            return cell->isShowing();edkEnd();
        }
    }
    return false;
}
//set the cell show
bool edk::ViewListSelection::setCellShow(edk::uint32 position,bool show){
    if(position < this->cells.size()){
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            cell->setShow(show);edkEnd();
            return true;
        }
    }
    return false;
}
//show all cells
void edk::ViewListSelection::showAllCells(){
    edk::uint32 size = this->cells.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->cells.get(i)->setShow(true);edkEnd();
    }
}
void edk::ViewListSelection::hideAllCells(){
    edk::uint32 size = this->cells.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->cells.get(i)->setShow(false);edkEnd();
    }
}
//test if the cell is selecting
bool edk::ViewListSelection::isCellSelecting(edk::uint32 position){
    if(position < this->cells.size()){
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            return cell->isSelecting();
        }
    }
    return false;
}
//set the cell select
bool edk::ViewListSelection::setCellCanSelect(edk::uint32 position,bool select){
    if(position < this->cells.size()){
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            cell->setCanSelect(select);edkEnd();
            return true;
        }
    }
    return false;
}
//select all cells
void edk::ViewListSelection::canSelectAllCells(){
    edk::uint32 size = this->cells.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->cells.get(i)->setCanSelect(true);edkEnd();
    }
}
void edk::ViewListSelection::cantSelectAllCells(){
    edk::uint32 size = this->cells.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->cells.get(i)->setCanSelect(false);edkEnd();
    }
}
//select the cell
bool edk::ViewListSelection::isCellSelected(edk::uint32 position){
    if(position < this->cells.size()){
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            return cell->isSelectedCell();
        }
    }
    return false;
}
bool edk::ViewListSelection::setCellSelected(edk::uint32 position,bool selected){
    if(position < this->cells.size()){
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            cell->setSelectCell(selected);edkEnd();
            return true;
        }
    }
    return false;
}
//select one cell
bool edk::ViewListSelection::selectCell(edk::uint32 position){
    if(position < this->cells.size()){
        edk::ViewListSelection::ListCell* cell = this->cells.get(position);edkEnd();
        if(cell){
            cell->selectCell();edkEnd();
            return true;
        }
    }
    return false;
}
//unselect all cells
void edk::ViewListSelection::unselectAllCells(){
    edk::uint32 size = this->cells.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->cells.get(i)->unSelectCell();edkEnd();
    }
}
//get cell clicked
bool edk::ViewListSelection::haveClickCell(){
    if(this->clicked){
        return true;
    }
    return false;
}
//return the cell click position
edk::uint32 edk::ViewListSelection::getClickPosition(){
    if(this->clicked){
        this->clicked = NULL;edkEnd();
        return this->clickedPosition;edkEnd();
    }
    return 0u;edkEnd();
}
//test if have clicled one button
bool edk::ViewListSelection::haveClickedButton(edk::uint32 button){
    if(this->mouseButtons.haveElement(button)){
        this->mouseButtons.remove(button);edkEnd();
        return true;
    }
    return false;
}
bool edk::ViewListSelection::haveClickedLeftButton(){
    return this->haveClickedButton(edk::mouse::left);edkEnd();
}
bool edk::ViewListSelection::haveClickedRightButton(){
    return this->haveClickedButton(edk::mouse::right);edkEnd();
}
bool edk::ViewListSelection::haveClickedMiddleButton(){
    return this->haveClickedButton(edk::mouse::middle);edkEnd();
}
//clean the mouseButtons
void edk::ViewListSelection::cleanClickedButtons(){
    this->mouseButtons.clean();edkEnd();
}

//get the scroll percent
edk::float32 edk::ViewListSelection::getScrollPercent(){
    return this->scroll.getPercentY();
}
bool edk::ViewListSelection::setScrollPercent(edk::float32 percent){
    bool ret = true;
    if(percent<0.f){
        percent=0.f;
        ret = false;
    }
    else if(percent>1.f){
        percent=1.f;
        ret = false;
    }
    this->scroll.setPercentY(percent);
    return ret;
}

//draw the GU scene
void edk::ViewListSelection::drawScene(edk::rectf32){
    //draw the cells
    edk::uint32 size = this->cells.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //draw the cell
        this->cells.get(i)->draw();edkEnd();
        if(this->cells.get(i)->isSelectedCell()){
            this->cells.get(i)->drawWire();edkEnd();
        }
    }
}

void edk::ViewListSelection::drawSelectionScene(){

    //draw the cells
    edk::uint32 size = this->cells.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        edk::GU::guPushName(i);edkEnd();
        //draw the cell
        this->cells.get(i)->drawSelection();edkEnd();
        edk::GU::guPopName();edkEnd();
    }
}
//process the selection
void edk::ViewListSelection::selectObject(edk::uint32 object,edk::int32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* names){
    //select the object
    if(names[0u].size() && !object){
        this->clickedPosition = names[0u].get(0u);edkEnd();
        this->clicked = this->cells.get(this->clickedPosition);edkEnd();

        //copy the mouseButtons
        edk::uint32 size = this->mouseButtonsNew.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            this->mouseButtons.add(this->mouseButtonsNew.getElementInPosition(i));edkEnd();
        }

        //test if have clicked the left mouseButton
        if(this->clickLeft){
            //select the cell
            if(this->clicked){
                this->clicked->show();edkEnd();
            }
            this->clickLeft=false;edkEnd();
        }
    }
    this->clickLeft = false;edkEnd();
    this->mouseButtonsNew.clean();edkEnd();
}
