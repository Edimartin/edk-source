#include "ViewListSelection.h"

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
#warning "            Inside ViewListSelection.cpp"
#endif

edk::ViewListSelection::ListCell::ListCell(edk::uint32* lineSize){
    //
    this->selected = false;
    if(lineSize)
        this->lineSize = lineSize;
    else
        this->lineSize = &this->sizeTemp;
    this->drawColor = this->backgroundColor;
    this->backgroundColorSelected = edk::color4f32(0.75f,0.75f,1.0f,1.f);
    this->id = 0u;
}
edk::ViewListSelection::ListCell::~ListCell(){
    this->lineSize = &this->sizeTemp;
    this->cleanText();
}

//draw the rectangle
void edk::ViewListSelection::ListCell::drawRect(){
    //draw a rectangle in the text position and size
    edk::GU::guBegin(GU_QUADS);
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f),(this->text.getPositionY()-0.5f));
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f)+*this->lineSize,(this->text.getPositionY()-0.5f));
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f)+*this->lineSize,(this->text.getPositionY()-0.5f)+1);
    edk::GU::guVertex2f32((this->text.getPositionX()-0.5f),(this->text.getPositionY()-0.5f)+1);
    edk::GU::guEnd();
}

//create the text
bool edk::ViewListSelection::ListCell::createText(edk::char8* text){
    //
    if(this->text.createStringMap(text)){
        this->sizeTemp = (edk::float32)this->text.getMapSizeWidth();
        return true;
    }
    return false;
}
//delete the text
void edk::ViewListSelection::ListCell::cleanText(){
    this->text.deleteMap();
    this->selected = false;
    this->sizeTemp=0.f;
}
//get textSize
edk::uint32 edk::ViewListSelection::ListCell::getTextWidth(){
    return this->sizeTemp;
}
//select the cell
bool edk::ViewListSelection::ListCell::select(){
    this->selected = !this->selected;
    if(this->selected){
        this->drawColor = this->backgroundColorSelected;
        return true;
    }
    this->drawColor = this->backgroundColor;
    return false;
}
void edk::ViewListSelection::ListCell::setSelect(bool set){
    this->selected = set;
}

//return true if the cell is celected;
bool edk::ViewListSelection::ListCell::isSelected(){
    return this->selected;
}
//draw the cell
void edk::ViewListSelection::ListCell::draw(){
    edk::GU::guColor4f32(this->drawColor);
    this->drawRect();
    this->text.draw();
}
//draw for selection
void edk::ViewListSelection::ListCell::drawSelection(){
    edk::GU::guColor4f32(1,1,1,1);
    this->drawRect();
}
//set position
void edk::ViewListSelection::ListCell::setPosition(edk::float32 y){
    this->text.setPosition(0.f,y);
}

edk::ViewListSelection::ViewListSelection(){
    //cameraSize
    this->cameraWidth=1u;
    this->cameraHeight=1u;
    this->moveScroll = 0.1f;
}
edk::ViewListSelection::~ViewListSelection(){
    //
    this->cleanCells();
}

//update the cells position
void edk::ViewListSelection::updateCellPosition(){
    //clean all the cells
    edk::uint32 size = this->cells.size();
    for(edk::uint32 i=0u;i<size;i++){
        //move the cell to the position in the world
        this->cells[i]->setPosition(i*-1.f);
    }
}
//test the scroll
void edk::ViewListSelection::testScroll(){
    //test if need have scroll
    if(this->cells.getSize()>this->cameraHeight){
        if(!this->getCount()){
            //add the scroll
            this->addSubview(&this->scroll);
        }

        //set the insideSize
        if(this->cells.size()){
            this->scroll.setForegroundSize(1.f,(edk::float32)this->cameraHeight / (edk::float32)this->cells.size());
        }
        else{
            this->scroll.setForegroundSize(1.f,1.f);
        }
    }
    else{
        //remove the view
        if(this->getCount()){
            //remove the subview
            this->removeSubview(&this->scroll);
            this->scroll.setPercentY(0.f);
        }
    }
}

//Events
void edk::ViewListSelection::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    if(button == edk::mouse::left){
        this->testSelection(point);
    }
    fflush(stdout);
}
//Mouse go Inside Outside
void edk::ViewListSelection::eventMouseEntryInsideView(edk::vec2f32){
    //
}
void edk::ViewListSelection::eventMouseLeftView(edk::vec2f32){
    //
}

void edk::ViewListSelection::update(edk::WindowEvents* events){
    if(this->saveFrame!=this->frame){
        this->saveFrame=this->frame;
        //update the scroll
        this->scroll.frame = edk::rectf32(this->frame.size.width - 20.f,
                                          0.f,
                                          20.f,
                                          this->frame.size.height
                                          );
    }
    this->camera.setRect(-0.5f,-0.5f,this->cameraWidth,this->cameraHeight);
    this->camera.position.y-=(this->camera.getSize().height-1.f);
    //move the percent
    this->camera.position.y-= (this->cells.size() - this->camera.getSize().height) * this->scroll.getPercentY();

    //move the mouseScroll
    //if(this->pointInside(edk::vec2f32(events->mousePos.x,events->mousePos.y))){
    if(this->isMouseInside()){
        this->scroll.setPercentY(this->scroll.getPercentY() + (events->mouseScrollWheel * this->moveScroll * -1));
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
            this->moveScroll = moveScroll;
            return true;
        }
        else{
            this->moveScroll = 1.f;
        }
    }
    else{
        this->moveScroll = 0.f;
    }
    return false;
}

//set camera Size
void edk::ViewListSelection::setCameraSize(edk::size2ui32 size){
    this->setCameraSize(size.width,size.height);
}
void edk::ViewListSelection::setCameraSize(edk::uint32 width,edk::uint32 height){
    this->cameraWidth = 1u;
    this->cameraHeight = 1u;
    if(width){
        this->cameraWidth = width;
    }
    if(height){
        this->cameraHeight= height;
    }
    this->testScroll();
}

//set color
void edk::ViewListSelection::setScrollBackColor(edk::color4f32 color){
    this->scroll.setBackColor(color);
}
void edk::ViewListSelection::setScrollBackColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setScrollBackColor(edk::color4f32(r,g,b,a));
}
void edk::ViewListSelection::setScrollFrontColor(edk::color4f32 color){
    this->scroll.setFrontColor(color);
}
void edk::ViewListSelection::setScrollFrontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setScrollFrontColor(edk::color4f32(r,g,b,a));
}

//add a cell
bool edk::ViewListSelection::addCell(const char* name,edk::uint32 id,edk::color4f32 cellColor){
    return this->addCell((edk::char8*) name,id,cellColor);
}
bool edk::ViewListSelection::addCell(edk::char8* name,edk::uint32 id,edk::color4f32 cellColor){
    if(name){
        //create the new cell
        edk::ViewListSelection::ListCell* cell = new edk::ViewListSelection::ListCell(&this->cameraWidth);
        if(cell){
            //set the cell text
            if(cell->createText(name)){
                //set the cell color
                cell->backgroundColor = cellColor;
                edk::uint32 size = this->cells.size();
                //add the cell to the stack
                edk::uint32 position = this->cells.pushBack(cell);
                this->testScroll();
                if(this->cells.size()>size){
                    //move the cell to the position
                    cell->setPosition(position*-1.f);
                    cell->id = id;
                    return true;
                }
            }
            //else delete the cell
            delete cell;
        }
    }
    return false;
}
//set cell string
bool edk::ViewListSelection::setCellString(edk::uint32 position,const char* string){
    return this->setCellString(position,(edk::char8*) string);
}
bool edk::ViewListSelection::setCellString(edk::uint32 position,edk::char8* string){
    edk::ViewListSelection::ListCell* cell = this->cells[position];
    if(cell){
        return cell->createText(string);
    }
    return false;
}
//set the cellID
bool edk::ViewListSelection::setCellID(edk::uint32 position,edk::uint32 id){
    edk::ViewListSelection::ListCell* cell = this->cells[position];
    if(cell){
        cell->id = id;
        return true;
    }
    return false;
}
//remove a cell
bool edk::ViewListSelection::removeCell(edk::uint32 position){
    //test if have the cell
    if(position<this->cells.size()){
        //get the cell
        edk::ViewListSelection::ListCell* cell = this->cells[position];
        if(cell){
            //move the the end
            this->cells.bringPositionTo(position,this->cells.size()-1u);
            //popBack
            this->cells.popBack();
            //delete cell
            delete cell;
            //update the cells Position
            this->updateCellPosition();
            this->testScroll();
            return true;
        }
    }
    return false;
}
//clean the cells
void edk::ViewListSelection::cleanCells(){
    //clean all the cells
    edk::uint32 size = this->cells.size();
    edk::ViewListSelection::ListCell* cell;
    for(edk::uint32 i=0u;i<size;i++){
        cell = this->cells[i];
        if(cell){
            delete cell;
        }
    }
    this->cells.clean();
    this->testScroll();
}
//return the cell size
edk::uint32 edk::ViewListSelection::getCellSize(){
    return this->cells.size();
}
//return true if have the cell
bool edk::ViewListSelection::haveCell(edk::uint32 position){
    return (bool)this->cells[position];
}
//return the cell ID
edk::uint32 edk::ViewListSelection::getCellID(edk::uint32 position){
    edk::ViewListSelection::ListCell* cell = this->cells[position];
    if(cell){
        return cell->id;
    }
    return 0u;
}
//test if the cell is selected
bool edk::ViewListSelection::isCellSelected(edk::uint32 position){
    edk::ViewListSelection::ListCell* cell = this->cells[position];
    if(cell){
        return cell->isSelected();
    }
    return false;
}
//set the cell select
bool edk::ViewListSelection::setCellSelect(edk::uint32 position,bool select){
    edk::ViewListSelection::ListCell* cell = this->cells[position];
    if(cell){
        cell->setSelect(select);
        return true;
    }
    return false;
}
//select all cells
void edk::ViewListSelection::selectAllCells(){
    edk::uint32 size = this->cells.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->cells[i]->setSelect(true);
    }
}
void edk::ViewListSelection::deselectAllCells(){
    edk::uint32 size = this->cells.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->cells[i]->setSelect(false);
    }
}

//draw the GU scene
void edk::ViewListSelection::drawScene(edk::rectf32){
    //draw the cells
    edk::uint32 size = this->cells.size();
    for(edk::uint32 i=0u;i<size;i++){
        //draw the cell
        this->cells[i]->draw();
    }
}

void edk::ViewListSelection::drawSelectionScene(){

    //draw the cells
    edk::uint32 size = this->cells.size();
    for(edk::uint32 i=0u;i<size;i++){
        edk::GU::guPushName(i);
        //draw the cell
        this->cells[i]->drawSelection();
        edk::GU::guPopName();
    }
}
//process the selection
void edk::ViewListSelection::selectObject(edk::uint32 object,edk::uint32 size,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* names){
    //select the object
    if(names[0u].size() && !object){
        edk::uint32 position = names[0u][0u];
        edk::ViewListSelection::ListCell* cell = this->cells[position];
        if(cell) cell->select();
    }
    fflush(stdout);
}
