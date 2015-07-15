#include "Line2D.h"

/*
Library Line2D - Draw a 2D line in EDK Game Engine
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
#warning "            Inside Line2D.cpp"
#endif

edk::shape::Line2D::Line2D(){
    //
}
edk::shape::Line2D::Line2D(edk::vec2f32 start,edk::vec2f32 end){
    //
    this->start.position=start;
    this->end.position=end;
}

edk::shape::Line2D::~Line2D(){
    //
}

//print the line
void edk::shape::Line2D::print(){
    //
    printf("\nLine");
}
//Draw the line
void edk::shape::Line2D::draw(){
    //
    this->start.draw();
    this->end.draw();
}
