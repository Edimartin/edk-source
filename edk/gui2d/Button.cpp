#include "Button.h"

/*
Button - Button for the GUI 2D library
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

edk::gui2d::Button::Button(){
    //
    this->obj.setBorderSize(0.25f);
}
edk::gui2d::Button::~Button(){
    //clean the meshes
    this->unload();
}
//add the polygons
bool edk::gui2d::Button::addPolygons(){
    //
    return false;
}

//load the button textures and meshes
bool edk::gui2d::Button::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        return true;
    }
    return false;
}
void edk::gui2d::Button::unload(){
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::Button::update(){
    edk::gui2d::ObjectGui2d::update();
}

//set border size
bool edk::gui2d::Button::setBorderSize(edk::float32 size){
    return this->obj.setBorderSize(size);
}

//draw the button
void edk::gui2d::Button::draw(){
    edk::gui2d::ObjectGui2d::draw();
}
