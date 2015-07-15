#include "Joint2D.h"

/*
Library Joint2D - Physics joints used in the PhysicsObjects
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

edk::physics2D::Joint2D::Joint2D(bool collide)
{
    this->objectA=NULL;
    this->objectB=NULL;
    this->collide = collide;
    this->type = EDK_JOINT;
}

edk::physics2D::Joint2D::~Joint2D(){
}

//draw the joint in debug mode
void edk::physics2D::Joint2D::draw(edk::size2f32,edk::color3f32){
    //
}

//return the joint type
edk::uint8 edk::physics2D::Joint2D::getType(){
    return this->type;
}
//get Collide
bool edk::physics2D::Joint2D::getCollide(){
    return this->collide;
}
