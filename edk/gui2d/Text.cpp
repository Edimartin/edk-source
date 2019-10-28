#include "Text.h"

/*
Text - Simple Text for the GUI 2D library
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
edk::gui2d::Text::Text(){
    edk::gui2d::ObjectGui2d::setBorderSize(0.01f);
}
edk::gui2d::Text::~Text(){
    //
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::Text::getType(){
    return edk::gui2d::gui2dTypeText;
}

//load the button textures and meshes
bool edk::gui2d::Text::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        //set the border size
        return true;
    }
    return false;
}
void edk::gui2d::Text::unload(){
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::Text::update(){
    edk::gui2d::ObjectGui2d::update();
}

//set border size
bool edk::gui2d::Text::setBorderSize(edk::float32){
    return false;
}

//draw the button
void edk::gui2d::Text::draw(){
    this->drawStart();
    if(this->text.haveText() && this->drawText){
        //
        this->text.draw(edk::color4f32(0,0,0,1));
    }
    this->drawEnd();
}
