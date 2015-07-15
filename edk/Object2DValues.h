#ifndef EDK_OBJECT2DVALUES_H
#define EDK_OBJECT2DVALUES_H

/*
Library Object2DValues - 2D Position angle and size
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
#warning "Inside Object2DValues"
#endif

#pragma once
#include "TypeVec2.h"
#include "TypeSize2.h"

#ifdef printMessages
#warning "    Compiling Object2DValues"
#endif

namespace edk{
class Object2DValues{
public:
    Object2DValues();
    edk::vec2f32 position;
    edk::float32 angle;
    edk::size2f32 size;
    bool fixedRotation;
    void loadIdentityValues();
/*
    //save the values
    void saveValues();
    //clean the saved values
    void cleanSaved();
    //return the saved values
    edk::vec2f32 getSavedPosition();
    edk::float32 getSavedPositionX();
    edk::float32 getSavedPositionY();
    //return the saved size
    edk::size2f32 getSavedSize();
    edk::float32 getSavedSizeWidth();
    edk::float32 getSavedSizeHeight();
    //return the savedAngle
    edk::float32 getSavedAngle();
private:
    //save the atual values
    edk::vec2f32 savePosition;
    edk::float32 saveAngle;
    edk::size2f32 saveSize;
*/
};
}

#endif // OBJECT2DVALUES_H
