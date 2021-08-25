#ifndef LUT_H
#define LUT_H

/*
Library C++ LUT - Create, save and load LUT (Look Up Table) 3D
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
    bool loadFrom(edk::char8* fileName);
    bool loadFrom(const edk::char8* fileName);
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
