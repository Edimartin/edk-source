#include "Contact2D.h"

/*
Library Contact2D - Physics Contacts used in the World2D
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

edk::physics2D::Contact2D::Contact2D(edk::classID pointer){
    //
    this->contactPointer=pointer;
    this->objectA=NULL;
    this->objectB=NULL;
    this->shapeA=0u;
    this->shapeB=0u;
    this->velocityA=0.f;
    this->velocityB=0.f;
    this->points = 0u;
    this->enabled = true;
}
edk::uint8 edk::physics2D::Contact2D::getMaxPoints(){
    return EDK_MAX_CONTACTS_POINTS;
}

//return the contactPointer
edk::classID edk::physics2D::Contact2D::getContactPointer(){
    return this->contactPointer;
}

//disable the contact
void edk::physics2D::Contact2D::disableContact(){
    this->enabled=false;
}
void edk::physics2D::Contact2D::enableContact(){
    this->enabled=true;
}
void edk::physics2D::Contact2D::setEnabled(bool enabled){
    this->enabled=enabled;
}
bool edk::physics2D::Contact2D::isEnabled(){
    return this->enabled;
}
