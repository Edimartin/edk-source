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
}
edk::ViewListSelection::ListCell::~ListCell(){
    this->lineSize = &this->sizeTemp;
    this->cleanText();
}

//draw the rectangle
void edk::ViewListSelection::ListCell::drawRect(){
    //draw a rectangle in the text position and size
    edk::GU::guColor4f32(this->drawColor);
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
//return true if the cell is celected;
bool edk::ViewListSelection::ListCell::isSelected(){
    return this->selected;
}
//draw the cell
void edk::ViewListSelection::ListCell::draw(){
    this->drawRect();
    this->text.draw();
}
//draw for selection
void edk::ViewListSelection::ListCell::drawSelection(){
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
        }
    }
}

//Events
void edk::ViewListSelection::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    if(button == edk::mouse::left){
        this->testSelection(point);
    }
}

void edk::ViewListSelection::update(edk::WindowEvents*){
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

//add a cell
bool edk::ViewListSelection::addCell(const char* name,edk::color4f32 cellColor){
    return this->addCell((edk::char8*) name,cellColor);
}
bool edk::ViewListSelection::addCell(edk::char8* name,edk::color4f32 cellColor){
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
                    return true;
                }
            }
            //else delete the cell
            delete cell;
        }
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

//draw the GU scene
void edk::ViewListSelection::drawScene(edk::rectf32 outsideViewOrigin){
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
void edk::ViewListSelection::selectObject(edk::uint32 object,edk::uint32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* names){
    //select the object
    if(names[0u].size() && !object){
        edk::uint32 position = names[0u][0u];
        printf("\nSelect List == %u"
               ,position
               );fflush(stdout);
        edk::ViewListSelection::ListCell* cell = this->cells[position];
        if(cell) cell->select();
    }
    else{
        printf("\nSelect List == Nothing");fflush(stdout);
    }
}
