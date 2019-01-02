#ifndef LUT_H
#define LUT_H

/*
Library C++ LUT - Create, save and load LUT (Look Up Table) 3D
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
#warning "Inside TypeColor"
#endif

#pragma once
#include "../TypeColor.h"
#include "../TypeSize2.h"
#include <stdio.h>
#include "edk/Math.h"
#include "edk/File.h"
#include "edk/Image2D.h"

#ifdef printMessages
#warning "    Compiling TypeColor"
#endif


namespace edk{
class LUT3D{
public:
    LUT3D();
    virtual ~LUT3D();

    //create a new table
    bool newTable(edk::uint16 size);
    //delete the table
    bool deleteTable();
    //clean the table values
    bool cleanTable();
    //print the table for debug
    bool printTable();

    //return the size of the table. As a cube it only need return one value
    edk::uint16 getSize();
    //return the vector size
    edk::uint32 getVectorSize();
    //return the size of the image in pixels
    edk::size2ui32 getImageSize();
    edk::uint32 getImageWidth();
    edk::uint32 getImageHeight();

    //save the table into a .cube file
    bool saveTo(edk::char8* fileName);
    bool saveTo(const edk::char8* fileName);
    //load from file
//    bool loadFrom(edk::char8* fileName);
//    bool loadFrom(const edk::char8* fileName);
    //save to an image file
    bool saveToImage(edk::char8* fileName);
    bool saveToImage(const edk::char8* fileName);
    //load from an imageFile
    bool loadFromImage(edk::uint16 size,edk::char8* fileName);
    bool loadFromImage(edk::uint16 size,const edk::char8* fileName);
private:
    edk::color3ui8*** cube;
    edk::uint16 size;
    edk::size2ui32 imageSize;
    //calculate the imageSize
    edk::size2ui32 calcImageSize(edk::uint16 size);
};
}//end namespace edk

#endif // LUT_H
